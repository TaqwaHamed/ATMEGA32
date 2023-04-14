/*
 * SW.c
 *
 * Created: 1/18/2023 1:07:48 PM
 *  Author: TAQWA HAMED
 */ 

#include "../../04-LIB/STD_TYPES.h"
#include "../../00-MCAL/01-DIO/DIO.h"
#include "SW.h"
#include "SW_cfg.h"
#include "avr/delay.h"




extern SW_tstrSwCfg_t SW_strSwCfg[MAX_SW_NUMBER];

SW_tenuErrorStatus SW_enuRead(u8 Cpy_u8SwNumber,u8 * Add_pu8SWValue)
{
	SW_tenuErrorStatus Loc_u8State=  SW_enuOK ;
	u8 LOC_u8PinValue = 0;
	if (Cpy_u8SwNumber<=MAX_SW_NUMBER)
	{
		if(SW_strSwCfg[Cpy_u8SwNumber-1].Type==SW_PULL_UP)
		{
			DIO_enuGetPin(SW_strSwCfg[Cpy_u8SwNumber-1].SW_Pin,&LOC_u8PinValue);
			_delay_ms(300);
				DIO_enuGetPin(SW_strSwCfg[Cpy_u8SwNumber-1].SW_Pin,&LOC_u8PinValue);
			if (LOC_u8PinValue == DIO_LOW)
			{
					*Add_pu8SWValue = PRESSED;
			}
			else
			{
				*Add_pu8SWValue = NOT_PRESSED;
			}
		}
		else if (SW_strSwCfg[Cpy_u8SwNumber-1].Type==SW_PULL_DOWN)
		{
			DIO_enuGetPin(SW_strSwCfg[Cpy_u8SwNumber-1].SW_Pin,&LOC_u8PinValue);
			_delay_ms(300);
			DIO_enuGetPin(SW_strSwCfg[Cpy_u8SwNumber-1].SW_Pin,&LOC_u8PinValue);
			if (LOC_u8PinValue == DIO_HIGH)
			{
				*Add_pu8SWValue = PRESSED;
			}
			else
			{
				*Add_pu8SWValue = NOT_PRESSED;
			}
		}
		else
		{
			Loc_u8State=  SW_enuNOK ;
		}
	}
	else
	{
		Loc_u8State=  SW_enuNOK ;
	}
	
	
	return Loc_u8State;
}

