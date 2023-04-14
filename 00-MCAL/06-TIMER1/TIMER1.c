/*
 * TIMER1.c
 *
 * Created: 3/11/2023 8:13:14 PM
 *  Author: TAQWA HAMED
 */ 

#include "../../04-LIB/STD_TYPES.h"
#include "TIMER1.h"
#include "TIMER1_prv.h"

static PWM_tenuChannel_Number PWM_Channel = PWM_CHANNEL_A;
static TOP=0;






void ICU_voidCapture_Time(Edge_Select Copy_enuEdge, f32 *Copy_ptrTime)
{
	
	u16 LOC_ICUStart=0;
	u16 LOC_ICUEnd=0;
	f32 TimerTickTime = 0;
	TCCR1A=0;
	
	TIFR|= 1<<5;         /* clear input capture flag */
	TCCR1B= ( (Copy_enuEdge<<6) | TIM1_CLK_8);
	
	while(((TIFR>>5) &1) ==0);  /* monitor for capture*/
	LOC_ICUStart=ICR1;
	TIFR|= 1<<5;         /* clear input capture flag */
	
	while(((TIFR>>5) &1) ==0);  /* monitor for next capture*/
	
	LOC_ICUEnd=ICR1;
	
	*Copy_ptrTime=(LOC_ICUEnd-LOC_ICUStart)*(8/8000000.0)*1000;
	
}



void ICU_voidCaptureFREQ_DUTY(f32 *Copy_ptrTime)
{
	
	u16 LOC_ICUStart=0;
	u16 LOC_ICUFalling=0;
	u16 LOC_ICUEnd=0;
	f32 TimerTickTime = 0;
	TCCR1A=0;
	
	TIFR|= 1<<5;         /* clear input capture flag */
	TCCR1B= ( (ICU_RISING_EDGE<<6) | TIM1_CLK_8);
	
	while(((TIFR>>5) &1) ==0);  /* monitor for capture*/
	LOC_ICUStart=ICR1;
	TIFR|= 1<<5;         /* clear input capture flag */
	
	TCCR1B= (( ICU_FALLING_EDGE<<6)| TIM1_CLK_8);
	while(((TIFR>>5) &1) ==0);  /* monitor for next capture*/
	LOC_ICUFalling=ICR1;
	TIFR|= 1<<5;         /* clear input capture flag */
	
	TCCR1B= ( (ICU_RISING_EDGE<<6) | TIM1_CLK_8);
	while(((TIFR>>5) &1) ==0);  /* monitor for capture*/
	LOC_ICUEnd=ICR1;
	
	*Copy_ptrTime=(LOC_ICUFalling-LOC_ICUStart)*(8/8000000.0)*1000;
	
}

TMR1_enuErrorStatus TMR1_enuConfigPWM(TIMER1_tenuPWM_Configs * Copy_ptrPwmmConfigurations )
{
	TMR1_enuErrorStatus l_ErrorState = TIM1_enuOK;
	if (Copy_ptrPwmmConfigurations != NULL)
	{
		
		TCCR1A &=~(0b11);
		/* WGM01 WGM00  are the first two bits in the TMR2_PWM_Mode  --> to read the first two bits we need to & with ones 0b0011 = 0x03 */
		TCCR1A |= ( (Copy_ptrPwmmConfigurations->TMR1_PWM_Mode) & 0x03);
	
		TCCR1B &=~(0b11 << 3);
		/* WGM13 WGM12  are the second two bits in the TMR2_PWM_Mode  --> to read the second two bits we need to & with ones 0b1100 = 0x0C */
		TCCR1B |= ( ( (Copy_ptrPwmmConfigurations->TMR1_PWM_Mode) & 0x0C) << 3);
	
		switch(Copy_ptrPwmmConfigurations->TMR1_PWM_Mode)
		{
			case TIMER1_PWM_PHASE_FREQ_ICR1_MODE:
			case TIMER1_PWM_PHASE_ICR1_MODE		:
			case TIMER1_PWM_FAST_ICR1_MODE		:
				ICR1 = Copy_ptrPwmmConfigurations->TopPreloadValue;
				TOP=Copy_ptrPwmmConfigurations->TopPreloadValue;
				break;
			case TIMER1_PWM_PHASE_FREQ_OCRA_MODE:
			case TIMER1_PWM_PHASE_OCRA_MODE		:
			case TIMER1_PWM_FAST_OCRA_MODE		:
				OCRA = Copy_ptrPwmmConfigurations->TopPreloadValue;
				break;
			default: 
				l_ErrorState = TIM1_enuNOK;
		}
		/* Select the channel to out the PWM Wave */
		PWM_Channel = Copy_ptrPwmmConfigurations->ChannelNumber;
		/* Configure the clock to start the timer */
		TCCR1B &=~(0b111);
		TCCR1B |= Copy_ptrPwmmConfigurations->PWM_CLK_PRE_SCALER;
		
	}
	else
	{
		l_ErrorState = TIM1_enuNullPtr;
	}
	return l_ErrorState;
}

 void TMR1_voidGenerateFastPwm(f32 Copy_f32DutyCycle,  u8 Copy_u8PulseType)
 {
	 switch(Copy_u8PulseType)
	 {
		 case INVERTED:
		 if (PWM_Channel == PWM_CHANNEL_A)
		 {
			  TCCR1A &=~(0b11 << 6);
			  TCCR1A |= (0b11 << 6);
			  OCRA = TOP-(TOP* (Copy_f32DutyCycle/100))-1;
		 }
		 else if(PWM_Channel == PWM_CHANNEL_B)
		 {
			 TCCR1A &=~(0b11 << 4);
			 TCCR1A |= (0b11 << 4);
			 OCRB = TOP-(TOP* (Copy_f32DutyCycle/100))-1;
		 }
		
		 break;

		 case NON_INVERTED:
		 if (PWM_Channel == PWM_CHANNEL_A)
		 {
			  TCCR1A &=~(0b11 << 6);
			  TCCR1A |= ( 0b10 << 6);
			  OCRA = (TOP-Copy_f32DutyCycle*TOP)-1;
		 }
		 else if (PWM_Channel == PWM_CHANNEL_B)
		 {
			 TCCR1A &=~(0b11 << 4);
			 TCCR1A |= ( 0b10 << 4);
			 OCRA = (TOP-Copy_f32DutyCycle*TOP)-1;
		 }
		
		 break;
	 }
	 
 }