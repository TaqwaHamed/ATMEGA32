/*
 * SERVO_MOTOR.c
 *
 * Created: 3/15/2023 2:14:42 PM
 *  Author: TAQWA HAMED
 */ 



#include "../../04-LIB/STD_TYPES.h"
#include "../../00-MCAL/06-TIMER1/TIMER1.h"





void Servo_enuInit(void)
{
		TIMER1_tenuPWM_Configs Servo_Timer ;
		Servo_Timer.TMR1_PWM_Mode=TIMER1_PWM_FAST_ICR1_MODE;
		Servo_Timer.ChannelNumber=PWM_CHANNEL_A;
		Servo_Timer.PWM_CLK_PRE_SCALER = TIM1_CLK_64;
		Servo_Timer.TopPreloadValue = 2500;
		TMR1_enuConfigPWM(&Servo_Timer);
		
}

void SERVO_voidMoveAngle(u8 Copy_u8Degree)
{
	
f32 Local_f32DutyCycle = 0;
switch(Copy_u8Degree)
{
	case 0 	 : Local_f32DutyCycle = 3; break;
	case 90  : Local_f32DutyCycle = 7.5; break;
	case 180 : Local_f32DutyCycle = 12; break;
}

 //TMR0_FastPwm(Local_f32DutyCycle,  INVERTED);

}


