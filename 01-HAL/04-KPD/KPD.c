/*
 * KPD.c
 *
 * Created: 1/28/2023 6:07:00 PM
 *  Author: TAQWA HAMED
 */ 

#include "../../04-LIB/STD_TYPES.h"
#include "../../04-LIB/BIT_MATH.h"
#include "../../04-LIB/DELAY/DELAY.h"
#include "../../00-MCAL/01-DIO/DIO.h"
#include "KPD.h"
#include "KPD_cfg.h"
#include "KPD_priv.h"


void KeyPadInt(void)
{
	
	DIO_enuWritePin_Value(KPD_ROW_1pin,DIO_HIGH);
	DIO_enuWritePin_Value(KPD_ROW_2pin,DIO_HIGH);
	DIO_enuWritePin_Value(KPD_ROW_3pin,DIO_HIGH);
	DIO_enuWritePin_Value(KPD_ROW_4pin,DIO_HIGH);

	DIO_enuWritePin_Value(KPD_COL_1pin,DIO_HIGH);
	DIO_enuWritePin_Value(KPD_COL_2pin,DIO_HIGH);
	DIO_enuWritePin_Value(KPD_COL_3pin,DIO_HIGH);
	DIO_enuWritePin_Value(KPD_COL_4pin,DIO_HIGH);
	
}

KPD_tenuErrorStatus KeyPadGetPressed(u8 *copy_pu8KeyValue )
{
  KPD_tenuErrorStatus Loc_u8State= KPD_enuOK;

	if (copy_pu8KeyValue!=NULL)
	{
	u8 rowpin[]=  {KPD_ROW_1pin,KPD_ROW_2pin,KPD_ROW_3pin,KPD_ROW_4pin};
	u8 colpin[]=  {KPD_COL_1pin,KPD_COL_2pin,KPD_COL_3pin,KPD_COL_4pin};
	
	u8 Loc_u8col,Loc_u8row,Loc_u8pinval;
    for (Loc_u8col=0;Loc_u8col<COL_ROW_NUM;Loc_u8col++)
    {
		DIO_enuWritePin_Value(colpin[Loc_u8col],DIO_LOW);
		for (Loc_u8row=0;Loc_u8row<COL_ROW_NUM;Loc_u8row++)
		{
			DIO_enuGetPin(rowpin[Loc_u8row],&Loc_u8pinval);
			if (Loc_u8pinval==0)
			{
				delay(30);
				DIO_enuGetPin(rowpin[Loc_u8row],&Loc_u8pinval);
				if(Loc_u8pinval==0)
				{
					*copy_pu8KeyValue=KPD_U8Buttons[Loc_u8row][Loc_u8col];
				}
				
				DIO_enuGetPin(rowpin[Loc_u8row],&Loc_u8pinval);
				while(Loc_u8pinval==0)
				{
					DIO_enuGetPin(rowpin[Loc_u8row],&Loc_u8pinval);
				}
				break;
			}
			
		}
				DIO_enuWritePin_Value(colpin[Loc_u8col],DIO_HIGH);

    }
  }
  else
  {
	  Loc_u8State= KPD_enuNOK;
  }
  
	return Loc_u8State;
}
