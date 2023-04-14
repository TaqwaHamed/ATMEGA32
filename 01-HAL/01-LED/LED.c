/*
 * LED.c
 *
 * Created: 1/17/2023 9:05:15 PM
 *  Author: totoh
 */ 

#include "../../04-LIB/STD_TYPES.h"
#include "../../00-MCAL/01-DIO/DIO.h"
#include "LED.h"
#include "LED_cfg.h"




extern LED_tstrLedCfg_t LED_strLedCfg[MAX_LED_NUMBER];


LED_tenuErrorStatus LED_enuON(u8 Cpy_u8LedNumber)
{
	LED_tenuErrorStatus state=  LED_enuOK ;
	
	if(Cpy_u8LedNumber<=MAX_LED_NUMBER)
	{
		if(LED_strLedCfg[Cpy_u8LedNumber-1].LED_Type==LED_ACTIVE_HIGH)
		{
			DIO_enuSetPin(LED_strLedCfg[Cpy_u8LedNumber-1].LED_Pin);
		}
		else if(LED_strLedCfg[Cpy_u8LedNumber-1].LED_Type==LED_ACTIVE_LOW)
		{
			DIO_enuClearPin(LED_strLedCfg[Cpy_u8LedNumber-1].LED_Pin);
			
		}
		else
		{
			state=  LED_enuNOK ;
		}
		
	
	
	}
	else
	{
	state=  LED_enuNOK ;	
		
	}
	
	return state;
}


LED_tenuErrorStatus LED_enuOFF(u8 Cpy_u8LedNumber)
{
	LED_tenuErrorStatus state=  LED_enuOK ;
	
	if(Cpy_u8LedNumber<=MAX_LED_NUMBER)
	{
		if(LED_strLedCfg[Cpy_u8LedNumber-1].LED_Type==LED_ACTIVE_HIGH)
		{
			DIO_enuClearPin(LED_strLedCfg[Cpy_u8LedNumber-1].LED_Pin);
			
		}
		else if(LED_strLedCfg[Cpy_u8LedNumber-1].LED_Type==LED_ACTIVE_LOW)
		{
			DIO_enuSetPin(LED_strLedCfg[Cpy_u8LedNumber-1].LED_Pin);
			
		}
		else
		{
			state=  LED_enuNOK ;
		}
		
		
		
		
		
	}
	else
	{
		state=  LED_enuNOK ;
		
	}
	
	return state;
	
}


