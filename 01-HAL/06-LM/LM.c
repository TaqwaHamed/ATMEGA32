/*
 * LM.c
 *
 * Created: 2/7/2023 8:53:56 PM
 *  Author: TAQWA HAMED
 */ 

#include "../../04-LIB/STD_TYPES.h"
#include "../../00-MCAL/04-ADC/ADC.h"
#include "LM.h"
#include "LM_cfg.h"
#include "LM_prv.h"



f32 LM_f32CalcTemp(u8 Copy_u8ChannelNumber)
{
	
	f32 Loc_u32temp=0;
	u16 Loc_u16ADCres=0;
	f32 Loc_u32Analog_res=0;
	
		ADC_enuread(ADC_0,&Loc_u16ADCres);
		Loc_u32Analog_res=(f32)(Loc_u16ADCres*MAX_VOLTAGE)/(f32)RESOLUTION;
		Loc_u32temp=MAP(Loc_u32Analog_res, 0, 5, 0, 500);
		
	return Loc_u32temp;
}

 static u16 MAP(f32 Copy_f32Value, f32 Copy_f32INStart, f32 Copy_f32INEnd, f32 Copy_f32OutStart, f32 Copy_f3OutEnd)
{
	return ((Copy_f32Value - Copy_f32INStart ) * (Copy_f3OutEnd - Copy_f32OutStart )/(Copy_f32INEnd -Copy_f32INStart ) +Copy_f32OutStart);
}







