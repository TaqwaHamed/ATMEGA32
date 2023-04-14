/*
 * LDR.c
 *
 * Created: 2/7/2023 8:52:38 PM
 *  Author: TAQWA HAMED
 */ 


#include "../../04-LIB/STD_TYPES.h"
#include "../../00-MCAL/04-ADC/ADC.h"
#include "LDR.h"
#include "LDR_cfg.h"
#include "LDR_prv.h"


u8 LDR_SNESOR_u8Read(u8 Copy_u8ChannelNumber)
{
	u16 Local_u16ADCValue = 0;
	f32 Local_f32AnalogVolt= 0;
	u8 Local_u8INT =0;
	ADC_enuread(Copy_u8ChannelNumber,&Local_u16ADCValue);
	Local_f32AnalogVolt = (Local_u16ADCValue * 5)/1024.0;
	//f64 RLDR = ((u64)Known_Res*VCC)/(VCC-Local_f32AnalogVolt);
	Local_u8INT=MAP(Local_f32AnalogVolt,0,5,100,0);
	return Local_u8INT;
}

static f32 MAP(f32 Copy_f32Value, f32 Copy_f32INStart, f32 Copy_f32INEnd, f32 Copy_f32OutStart, f32 Copy_f3OutEnd)
{
	return ((Copy_f32Value - Copy_f32INStart ) * (Copy_f3OutEnd - Copy_f32OutStart )/(Copy_f32INEnd -Copy_f32INStart ) +Copy_f32OutStart);
}

