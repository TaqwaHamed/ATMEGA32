/*
 * US.c
 *
 * Created: 3/15/2023 2:39:09 PM
 *  Author: TAQWA HAMED
 */ 


#include "../../04-LIB/STD_TYPES.h"
#include "../../00-MCAL/06-TIMER1/TIMER1.h"
#include "../../00-MCAL/01-DIO/DIO.h"
#include "US.h"
#include "US_cfg.h"




void UltSonic_voidTriger(void)
{
	
	DIO_enuSetPin(TRIGGER_PIN);
	_delay_us(10);
	DIO_enuClearPin(TRIGGER_PIN);
	
	
}


f32 UltSonic_GetDistancecm(void)
{
	f32 time=0;
	ICU_voidCaptureFREQ_DUTY(&time);
	return (342*100.0*(time/1000.0));
	
	
}