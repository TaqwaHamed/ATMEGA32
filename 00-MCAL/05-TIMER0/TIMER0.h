/*
 * TIMER0.h
 *
 * Created: 2/28/2023 12:49:57 PM
 *  Author: TAQWA HAMED
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

typedef enum{
	TIM0_enuNOK = 0,
	TIM0_enuOK ,
	TIM0_enuNullPtr,
	TIM0_enuWrongCLK
	
}TMR0_enuErrorStatus;

typedef enum{
	
	 TIMER0_NORMAL_MODE			=(0b0<<3)|(0b0<<6),
	 TIMER0_CTC_MODE		    =(0b1<<3)|(0b0<<6),
	 TIMER0_PWM_PHASE_MODE		=(0b0<<3)|(0b1<<6),
	 TIMER0_FAST_PWM_MODE		=(0b1<<3)|(0b1<<6)
	
}TIMER0_tenuTIM_Mode;
	
typedef enum{
	
	TIM0_NO_CLK				=(0b000),
   	TIM0_CLK				=(0b001),
   	TIM0_CLK_8				=(0b010),
   	TIM0_CLK_64				=(0b011),
   	TIM0_CLK_256			=(0b100),
   	TIM0_CLK_1024			=(0b101),
   	TIM0_EXTERNAL_FALLING	=(0b110),
   	TIM0_EXTERNAL_RISING	=(0b111)
}TIMER0_tenuTIM_CLOCK;

typedef enum{
	
	TIMER0_OVF_ENABLE_INTERRUPT		=(0b1<<0),
	TIMER0_OVF_DISABLE_INTERRUPT	=(0b0<<0)
	
	
}TIMER0_tenuTIM_OVF_Interrupt;

typedef enum{
	
	TIMER0_COMP_ENABLE_INTERRUPT		=(0b1<<1),
	TIMER0_COMP_DISABLE_INTERRUPT		=(0b0<<1)
}TIMER0_tenuTIM_COMP_INTERRUPT;
	
typedef enum{
	
	OC0_DISCONNECTED		=(0b00<<4),
	TOGGLE_OC0				=(0b01<<4),
	CLEAR_OC0				=(0b10<<4),
	SET_OC0					=(0b11<<4)
}TIMER0_tenuTIM_COMPARE_OUTPUT;


typedef struct{
	TIMER0_tenuTIM_Mode TIMER0_Mode						;
	TIMER0_tenuTIM_CLOCK TIMER0_CLOCK_SELECT		    ;
	TIMER0_tenuTIM_OVF_Interrupt TIMER0_OVF_Interrupt   ;
	TIMER0_tenuTIM_COMP_INTERRUPT TIMER0_COMP_INTERRUPT ;
	TIMER0_tenuTIM_COMPARE_OUTPUT TIMER0_COMPARE_OUTPUT	;
	void (*OVF_CALLBACK  )(void)		                ;
	void (*COMP_CALLBACK )(void)						;
}TMR0Config_t;

#define INVERTED       1
#define NON_INVERTED   2

void TMR0_voidInitPreCompile(void);
TMR0_enuErrorStatus TMR0_voidInitPostCompile(TMR0Config_t *Copy_strTimerConfig);
TMR0_enuErrorStatus TMR0_enuSetTickTimeMS(u8 Copy_u8ClkPrescaler, u16 Copy_u16TickTime);
TMR0_enuErrorStatus TMR0_enuStart(void);
TMR0_enuErrorStatus TMR0_FastPwm(f32 duty,  u8 pulse);
TMR0_enuErrorStatus TMR0_PhaseCorrectPwm(f32 duty, u8 pulse);
void TMR0_voidSetPreLoadValue(u8 Copy_u8CTCValue);

#endif /* TIMER0_H_ */