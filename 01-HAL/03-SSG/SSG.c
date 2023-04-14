/*
 * SSG.c
 *
 * Created: 1/20/2023 2:55:02 PM
 *  Author: TAQWA HAMED
 */ 


#include "../../04-LIB/STD_TYPES.h"
#include "../../04-LIB/BIT_MATH.h"
#include "../../00-MCAL/01-DIO/DIO.h"
#include "SSG.h"
#include "SSG_cfg.h"
#include "SSG_prv.h"

extern SSG_tstrSsgCfg_t SSG_strSsgCfg[MAX_SSG_NUMBER] ;
SSG_tenuErrorStatus SSG_enuDisplay(u8 Cpy_u8SsgNumber,u8 Cpy_u8SsgDispNum)
{
	
	SSG_tenuErrorStatus Loc_u8State= SSG_enuOK;
	
	
	if (Cpy_u8SsgNumber<=MAX_SSG_NUMBER || Cpy_u8SsgDispNum <= 9)
	{
		
		if(SSG_strSsgCfg[Cpy_u8SsgNumber-1].SSG_Type==SSG_COMMON_CATHODE)
		{
			DIO_enuWritePin_Value(SSG_strSsgCfg[Cpy_u8SsgNumber-1].SSG_LED1,GET_BIT(SSG_U8LocLOOKUPTable[Cpy_u8SsgDispNum],0));
			DIO_enuWritePin_Value(SSG_strSsgCfg[Cpy_u8SsgNumber-1].SSG_LED2,GET_BIT(SSG_U8LocLOOKUPTable[Cpy_u8SsgDispNum],1));
			DIO_enuWritePin_Value(SSG_strSsgCfg[Cpy_u8SsgNumber-1].SSG_LED3,GET_BIT(SSG_U8LocLOOKUPTable[Cpy_u8SsgDispNum],2));
			DIO_enuWritePin_Value(SSG_strSsgCfg[Cpy_u8SsgNumber-1].SSG_LED4,GET_BIT(SSG_U8LocLOOKUPTable[Cpy_u8SsgDispNum],3));
			DIO_enuWritePin_Value(SSG_strSsgCfg[Cpy_u8SsgNumber-1].SSG_LED5,GET_BIT(SSG_U8LocLOOKUPTable[Cpy_u8SsgDispNum],4));
			DIO_enuWritePin_Value(SSG_strSsgCfg[Cpy_u8SsgNumber-1].SSG_LED6,GET_BIT(SSG_U8LocLOOKUPTable[Cpy_u8SsgDispNum],5));
			DIO_enuWritePin_Value(SSG_strSsgCfg[Cpy_u8SsgNumber-1].SSG_LED7,GET_BIT(SSG_U8LocLOOKUPTable[Cpy_u8SsgDispNum],6));
		}
		else if(SSG_strSsgCfg[Cpy_u8SsgNumber-1].SSG_Type==SSG_COMMON_ANODE)
		{
			DIO_enuWritePin_Value(SSG_strSsgCfg[Cpy_u8SsgNumber-1].SSG_LED1,!GET_BIT(SSG_U8LocLOOKUPTable[Cpy_u8SsgDispNum],0));
			DIO_enuWritePin_Value(SSG_strSsgCfg[Cpy_u8SsgNumber-1].SSG_LED2,!GET_BIT(SSG_U8LocLOOKUPTable[Cpy_u8SsgDispNum],1));
			DIO_enuWritePin_Value(SSG_strSsgCfg[Cpy_u8SsgNumber-1].SSG_LED3,!GET_BIT(SSG_U8LocLOOKUPTable[Cpy_u8SsgDispNum],2));
			DIO_enuWritePin_Value(SSG_strSsgCfg[Cpy_u8SsgNumber-1].SSG_LED4,!GET_BIT(SSG_U8LocLOOKUPTable[Cpy_u8SsgDispNum],3));
			DIO_enuWritePin_Value(SSG_strSsgCfg[Cpy_u8SsgNumber-1].SSG_LED5,!GET_BIT(SSG_U8LocLOOKUPTable[Cpy_u8SsgDispNum],4));
			DIO_enuWritePin_Value(SSG_strSsgCfg[Cpy_u8SsgNumber-1].SSG_LED6,!GET_BIT(SSG_U8LocLOOKUPTable[Cpy_u8SsgDispNum],5));
			DIO_enuWritePin_Value(SSG_strSsgCfg[Cpy_u8SsgNumber-1].SSG_LED7,!GET_BIT(SSG_U8LocLOOKUPTable[Cpy_u8SsgDispNum],6));
		}
		else
		{
			Loc_u8State=  SSG_enuNOK ;
		}
		
	}
	else
	{
		Loc_u8State=  SSG_enuNOK ;
		
	}
	
	
	return Loc_u8State;
}