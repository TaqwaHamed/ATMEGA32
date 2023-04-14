/*
 * TIMER0.c
 *
 * Created: 2/28/2023 1:41:24 PM
 *  Author: TAQWA HAMED
 */ 

 #include "../../04-LIB/STD_TYPES.h"
 #include "TIMER0.h"
 #include "TIMER0_cfg.h"
 #include "TIMER0_prv.h"



/*********** Timer0 Overflow ISR ************************/
void __vector_11(void)__attribute__((signal)) ;

void (*TIMER0_OVF_CALLBACK)(void) = NULL ;
/**********************************************************/




/****************TIMER0 COMP ISR *************************/
void __vector_10(void)__attribute__((signal));

void (*TIMER0_COMP_CALLBACK)(void) = NULL;
/*********************************************************/
u8 Prescaler_value=0;
u16 NumberOfOverFlows = 0;
void TMR0_voidInitPreCompile(void)
{
	
	#if TIMER0_MODE_OPERATION == COMPARE_MATCH
	TCCR0 = COMPARE_MATCH;
	#elif TIMER0_MODE_OPERATION == NORMAL
	TCCR0= TIMER0_NORMAL_MODE;
	#elif TIMER0_MODE_OPERATION == TIMER0_PWM_PHASE_MODE
	TCCR0=TIMER0_PWM_PHASE_MODE;
	#elif TIMER0_MODE_OPERATION == TIMER0_FAST_PWM_MODE
	TCCR0=TIMER0_FAST_PWM_MODE;
	#else
	#error "Wrong Timer Mode"
	#endif

	#ifndef TIMER0_COMPARE_MATCH_INTERRUPT
	#if TIMER0_OVERFLOW_INTERRUPT == ENABLE
	TIMSK=(0b1<<0);
	#elif TIMER0_OVERFLOW_INTERRUPT == DISABLE
	TIMSK=(0b0<<0);
	#else
	#error "Wrong Timer Interrupt configurations"
	#endif
	#endif

	#ifndef TIMER0_OVERFLOW_INTERRUPT
	#if TIMER0_COMPARE_MATCH_INTERRUPT == ENABLE
	TIMSK=(0b1<<1);
	#elif TIMER0_COMPARE_MATCH_INTERRUPT == DISABLE
	TIMSK=(0b0<<1);
	#else
	#error "Wrong Timer Interrupt configurations"
	#endif
	#endif

	#if TIMER0_ENABLE_DISABLE == ENABLE
	TCCR0 |= TIMER0_CLK_PRESCALLER;
	#elif TIMER0_ENABLE_DISABLE == DISABLE
	TCCR0 &=~(0b111);
	#else
	#error "Wrong Timer0 Configurations"
	#endif

}


TMR0_enuErrorStatus TMR0_voidInitPostCompile(TMR0Config_t *Copy_strTimerConfig)
{
	TMR0_enuErrorStatus LOC_u8ErrorState=TIM0_enuNOK;
	
	TCCR0=Copy_strTimerConfig->TIMER0_Mode | Copy_strTimerConfig->TIMER0_COMPARE_OUTPUT;
	TIMSK=Copy_strTimerConfig->TIMER0_COMP_INTERRUPT | Copy_strTimerConfig->TIMER0_OVF_Interrupt;
	Prescaler_value= Copy_strTimerConfig->TIMER0_CLOCK_SELECT;
	 if (Copy_strTimerConfig->COMP_CALLBACK != NULL)
	 {
		 TIMER0_COMP_CALLBACK=Copy_strTimerConfig->COMP_CALLBACK;
	 }
	 else
	 {
		LOC_u8ErrorState=TIM0_enuNullPtr; 
	 }
	 
	 if (Copy_strTimerConfig->OVF_CALLBACK !=NULL)
	 {
		 TIMER0_OVF_CALLBACK=Copy_strTimerConfig->OVF_CALLBACK;
	 }
	 else
	 {
		LOC_u8ErrorState=TIM0_enuNullPtr; 
	 }
	 
	 
	 return LOC_u8ErrorState;
}


TMR0_enuErrorStatus TMR0_enuSetTickTimeMS(u8 Copy_u8ClkPrescaler, u16 Copy_u16TickTime)
{
	TMR0_enuErrorStatus LOC_u8ErrorState=TIM0_enuNOK;
	f32 TimerTickTime = 0;
	f32 TimerOverFlowTime =0;
	TimerTickTime = (Copy_u8ClkPrescaler / 8000000.0 )*1000.0;
	
	TimerOverFlowTime= TimerTickTime * TOP;
	NumberOfOverFlows = Copy_u16TickTime/TimerOverFlowTime;

	return TIM0_enuNOK;
}


TMR0_enuErrorStatus TMR0_enuStart(void)
{
	TMR0_enuErrorStatus LOC_u8ErrorState=TIM0_enuNOK;
		
		if (Prescaler_value<=MAX_CLK_VALUE)
		{
			TCCR0 &= ~ ( 0b111);
			TCCR0 |= Prescaler_value;
			LOC_u8ErrorState=TIM0_enuOK;
		}
		else
		{
			LOC_u8ErrorState=TIM0_enuWrongCLK;
		}
		
	return LOC_u8ErrorState;
}

TMR0_enuErrorStatus TMR0_FastPwm(f32 duty,  u8 pulse)
{
	TMR0_enuErrorStatus LOC_u8ErrorState=TIM0_enuNOK;
	
		switch(pulse)
		{
			case INVERTED:
			TCCR0 &=~(0b11 << 4);
			TCCR0 |= (0b1 << 4) | ( 0b1 << 5);
			OCR0 = TOP-(TOP* (duty/100))-1;
			break;

			case NON_INVERTED:
			TCCR0 &=~(0b11 << 4);
			TCCR0 |= ( 0b1 << 5);
			OCR0 = (TOP-duty*TOP)-1;
			break;

			default : LOC_u8ErrorState=TIM0_enuNOK;
			break;

		}
	
return LOC_u8ErrorState;

}


TMR0_enuErrorStatus TMR0_PhaseCorrectPwm(f32 duty, u8 pulse)
{
	TMR0_enuErrorStatus LOC_u8ErrorState=TIM0_enuNOK;
	
		switch(pulse)
		{
			case INVERTED :
			TCCR0 &=~(0b11 << 4);
			TCCR0 |= (0b1 << 4) | ( 0b1 << 5);
			OCR0 = ((TOP-1)-(duty*(TOP-1)/100));
			break;

			case NON_INVERTED :
			TCCR0 &=~(0b11 << 4);
			TCCR0 |= ( 0b1 << 5);
			OCR0 = (duty*(TOP-1))/100;
			break;

			default : LOC_u8ErrorState=TIM0_enuNOK;
			break;
		}
		
 return LOC_u8ErrorState;
}

void TMR0_voidSetPreLoadValue(u8 Copy_u8CTCValue)
{
	OCR0= Copy_u8CTCValue;
}
volatile u16 OverFlowCounts = 0;

void __vector_11(void)
{
	if (OverFlowCounts < NumberOfOverFlows)
	{
		OverFlowCounts++;
	}
	else
	{
		OverFlowCounts=0;
		if(TIMER0_OVF_CALLBACK != NULL)
		{
			TIMER0_OVF_CALLBACK();
		}
		
	}
	
}
void __vector_10(void)
{
	if (TIMER0_COMP_CALLBACK != NULL)
	{
		TIMER0_COMP_CALLBACK();
	}
}


