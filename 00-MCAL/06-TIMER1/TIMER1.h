/*
 * TIMER1.h
 *
 * Created: 3/11/2023 8:13:36 PM
 *  Author: TAQWA HAMED
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_


typedef enum
{
	ICU_FALLING_EDGE,
	ICU_RISING_EDGE
	
}Edge_Select;

typedef enum{
	
	TIM1_NO_CLK				=(0b000),
	TIM1_CLK				=(0b001),
	TIM1_CLK_8				=(0b010),
	TIM1_CLK_64				=(0b011),
	TIM1_CLK_256			=(0b100),
	TIM1_CLK_1024			=(0b101),
	TIM1_EXTERNAL_FALLING	=(0b110),
	TIM1_EXTERNAL_RISING	=(0b111)
}TIMER1_tenuTIM_CLOCK;

typedef enum{
	TIM1_enuNOK = 0,
	TIM1_enuOK ,
	TIM1_enuNullPtr,
	TIM1_enuWrongCLK
	
}TMR1_enuErrorStatus;

typedef enum{
	TIMER1_PWM_PHASE_8_BIT_MODE			=0b0001,
	TIMER1_PWM_PHASE_9_BIT_MODE			=0b0010,
	TIMER1_PWM_PHASE_10_BIT_MODE		=0b0011,
	TIMER1_PWM_FAST_8_BIT_MODE			=0b0101,
	TIMER1_PWM_FAST_9_BIT_MODE			=0b0110,
	TIMER1_PWM_FAST_10_BIT_MODE			=0b0111,
	TIMER1_PWM_PHASE_FREQ_ICR1_MODE		=0b1000,
	TIMER1_PWM_PHASE_FREQ_OCRA_MODE		=0b1001,
	TIMER1_PWM_PHASE_ICR1_MODE			=0b1010,
	TIMER1_PWM_PHASE_OCRA_MODE			=0b1011,
	TIMER1_PWM_FAST_ICR1_MODE			=0b1110,
	TIMER1_PWM_FAST_OCRA_MODE			=0b1111
	
}TIMER1_tenuPWM_Modes;

typedef enum{
	PWM_CHANNEL_A,
	PWM_CHANNEL_B
}PWM_tenuChannel_Number;
typedef struct{
	TIMER1_tenuPWM_Modes TMR1_PWM_Mode;
	TIMER1_tenuTIM_CLOCK PWM_CLK_PRE_SCALER;
	PWM_tenuChannel_Number ChannelNumber;
	u16 TopPreloadValue;
}TIMER1_tenuPWM_Configs;

#define INVERTED  0
#define NON_INVERTED  1

TMR1_enuErrorStatus TMR1_enuConfigPWM(TIMER1_tenuPWM_Configs * Copy_ptrPwmmConfigurations );
void ICU_voidCapture_Time(Edge_Select Copy_enuEdge, f32 *Copy_ptrTime);
void ICU_voidCaptureFREQ_DUTY( f32 *Copy_ptrTime);



#endif /* TIMER1_H_ */