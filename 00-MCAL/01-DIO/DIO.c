#include "../../04-LIB/STD_TYPES.h"
#include "../../04-LIB/BIT_MATH.h"

#include "DIO.h"
#include "DIO_cfg.h"
#include "DIO_prv.h"


DIO_tenuErrorStatus DIO_enuInit(void){
	
	u8 i = 0;
	u8 Loc_u8PortNumber = 0;
	u8 Loc_u8PinNumber = 0;
	DIO_tenuErrorStatus LOC_ErrorState = DIO_enuOK;
	
	for (i=0;i<DIO_enuNumberOfPins;i++){
		Loc_u8PortNumber = i/8;
		Loc_u8PinNumber = i%8;
		if (DIO_strPinCfg[i].DIO_PinDirection <= DIO_DIR_OUTPUT && DIO_strPinCfg[i].DIO_InputStatus <= DIO_INPUT_PULLDOWN )
		{
			switch (Loc_u8PortNumber){
				case(DIO_PORTA):
				if(DIO_strPinCfg[i].DIO_PinDirection == DIO_DIR_OUTPUT){
					SET_BIT(DDRA_REG,Loc_u8PinNumber);
				}
				else{
					CLR_BIT(DDRA_REG,Loc_u8PinNumber);
					if(DIO_strPinCfg[i].DIO_InputStatus ==DIO_INPUT_PULLUP){
						SET_BIT(PORTA_REG,Loc_u8PinNumber);
					}
					else{
						CLR_BIT(PORTA_REG,Loc_u8PinNumber);
					}
				}
				break;
				
				case(DIO_PORTB):
				if(DIO_strPinCfg[i].DIO_PinDirection == DIO_DIR_OUTPUT){
					SET_BIT(DDRB_REG,Loc_u8PinNumber);
				}
				else{
					CLR_BIT(DDRB_REG,Loc_u8PinNumber);
					if(DIO_strPinCfg[i].DIO_InputStatus ==DIO_INPUT_PULLUP){
						SET_BIT(PORTB_REG,Loc_u8PinNumber);
					}
					else{
						CLR_BIT(PORTB_REG,Loc_u8PinNumber);
					}
				}
				break;
				
				case(DIO_PORTC):
				if(DIO_strPinCfg[i].DIO_PinDirection == DIO_DIR_OUTPUT){
					SET_BIT(DDRC_REG,Loc_u8PinNumber);
				}
				else{
					CLR_BIT(DDRC_REG,Loc_u8PinNumber);
					if(DIO_strPinCfg[i].DIO_InputStatus ==DIO_INPUT_PULLUP){
						SET_BIT(PORTC_REG,Loc_u8PinNumber);
					}
					else{
						CLR_BIT(PORTC_REG,Loc_u8PinNumber);
					}
				}
				break;
				
				case(DIO_PORTD):
				if(DIO_strPinCfg[i].DIO_PinDirection == DIO_DIR_OUTPUT){
					SET_BIT(DDRD_REG,Loc_u8PinNumber);
				}
				else{
					CLR_BIT(DDRD_REG,Loc_u8PinNumber);
					if(DIO_strPinCfg[i].DIO_InputStatus ==DIO_INPUT_PULLUP){
						SET_BIT(PORTD_REG,Loc_u8PinNumber);
					}
					else{
						CLR_BIT(PORTD_REG,Loc_u8PinNumber);
					}
				}
				break;
			}
			
		}
		else
		{
			LOC_ErrorState = DIO_enuNotOK;
		}

	}
	return LOC_ErrorState;
}


DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPins Cpy_u8PinNumber)
{
	DIO_tenuErrorStatus Loc_u8State= DIO_enuOK;
	
	u8 Loc_u8PortNumber=0;
	u8 Loc_u8PinNumber=0;
	
	if(Cpy_u8PinNumber<DIO_enuNumberOfPins)
	{
		Loc_u8PortNumber = Cpy_u8PinNumber/8;
		Loc_u8PinNumber = Cpy_u8PinNumber%8;
		
		switch (Loc_u8PortNumber){
			
			case DIO_PORTA:
			SET_BIT(PORTA_REG,Loc_u8PinNumber);
			break;
			
			case DIO_PORTB:
			SET_BIT(PORTB_REG,Loc_u8PinNumber);
			break;
			
			
			case DIO_PORTC:
			SET_BIT(PORTC_REG,Loc_u8PinNumber);
			
			break;
			
			case DIO_PORTD:
			SET_BIT(PORTD_REG,Loc_u8PinNumber);
			break;
			
			
		}
		
	}
	else
	{
		Loc_u8State= DIO_enuNotOK;
	}
	return Loc_u8State;
}



DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPins Cpy_u8PinNumber)
{
	DIO_tenuErrorStatus Loc_u8State= DIO_enuOK;
	
	u8 Loc_u8PortNumber=0;
	u8 Loc_u8PinNumber=0;
	
	if(Cpy_u8PinNumber<DIO_enuNumberOfPins)
	{
		Loc_u8PortNumber = Cpy_u8PinNumber/8;
		Loc_u8PinNumber = Cpy_u8PinNumber%8;
		
		switch (Loc_u8PortNumber){
			
			case DIO_PORTA:
			CLR_BIT(PORTA_REG,Loc_u8PinNumber);
			break;
			
			case DIO_PORTB:
			CLR_BIT(PORTB_REG,Loc_u8PinNumber);
			break;
			
			
			case DIO_PORTC:
			CLR_BIT(PORTC_REG,Loc_u8PinNumber);
			
			break;
			
			case DIO_PORTD:
			CLR_BIT(PORTD_REG,Loc_u8PinNumber);
			break;
			
			
		}
	}
	else
	{
		Loc_u8State= DIO_enuNotOK;
		
	}
	
	return Loc_u8State;
}


DIO_tenuErrorStatus DIO_enuGetPin(DIO_tenuPins Cpy_u8PinNumber,u8 * Add_pu8PinValue)
{
	DIO_tenuErrorStatus Loc_u8State= DIO_enuOK;
	u8 Loc_u8PortNumber=0;
	u8 Loc_u8PinNumber=0;
	
	if(Add_pu8PinValue!=NULL)
	{
		if(Cpy_u8PinNumber<DIO_enuNumberOfPins)
		{
			
			Loc_u8PortNumber = Cpy_u8PinNumber/8;
			Loc_u8PinNumber = Cpy_u8PinNumber%8;
			
			switch (Loc_u8PortNumber){
				
				case DIO_PORTA:
				*Add_pu8PinValue=GET_BIT(PINA_REG,Loc_u8PinNumber);
				break;
				
				case DIO_PORTB:
				*Add_pu8PinValue=GET_BIT(PINB_REG,Loc_u8PinNumber);
				break;
				
				
				case DIO_PORTC:
				*Add_pu8PinValue=GET_BIT(PINC_REG,Loc_u8PinNumber);
				
				break;
				
				case DIO_PORTD:
				*Add_pu8PinValue=GET_BIT(PIND_REG,Loc_u8PinNumber);
				break;
				
				
			}
		}
		else
		{
			Loc_u8State= DIO_enuNotOK;
		}
	}
	else
	{
		Loc_u8State=DIO_enuNullPtr;
	}
	return Loc_u8State;
}


DIO_tenuErrorStatus DIO_enuWritePin_Value(DIO_tenuPins Cpy_u8PinNumber,u8 Cpyu8PinValue)
{
	DIO_tenuErrorStatus Loc_u8State= DIO_enuOK;
	
	u8 Loc_u8PortNumber=0;
	u8 Loc_u8PinNumber=0;
	
	
	if (Cpy_u8PinNumber<DIO_enuNumberOfPins)
	{
		
		Loc_u8PortNumber = Cpy_u8PinNumber/8;
		Loc_u8PinNumber = Cpy_u8PinNumber%8;
		
		switch (Loc_u8PortNumber){
			
			case DIO_PORTA:
			if (Cpyu8PinValue==DIO_HIGH)
			{
				SET_BIT(PORTA_REG,Loc_u8PinNumber);
			}
			else if (Cpyu8PinValue==DIO_LOW)
			{
				CLR_BIT(PORTA_REG,Loc_u8PinNumber);
			}
			else
			{
				Loc_u8State=DIO_enuNotOK;
			}
			
			break;
			
			case DIO_PORTB:
			if (Cpyu8PinValue==DIO_HIGH)
			{
				SET_BIT(PORTB_REG,Loc_u8PinNumber);
			}
			else if (Cpyu8PinValue==DIO_LOW)
			{
				CLR_BIT(PORTB_REG,Loc_u8PinNumber);
			}
			else
			{
				Loc_u8State=DIO_enuNotOK;
			}
			
			break;
			
			
			case DIO_PORTC:
			if (Cpyu8PinValue==DIO_HIGH)
			{
				SET_BIT(PORTC_REG,Loc_u8PinNumber);
			}
			else if (Cpyu8PinValue==DIO_LOW)
			{
				CLR_BIT(PORTC_REG,Loc_u8PinNumber);
			}
			else
			{
				Loc_u8State=DIO_enuNotOK;
			}
			
			
			break;
			
			case DIO_PORTD:
			if (Cpyu8PinValue==DIO_HIGH)
			{
				SET_BIT(PORTD_REG,Loc_u8PinNumber);
			}
			else if (Cpyu8PinValue==DIO_LOW)
			{
				CLR_BIT(PORTD_REG,Loc_u8PinNumber);
			}
			else
			{
				Loc_u8State=DIO_enuNotOK;
			}
			
			break;
			
			
		}
	}

	else
	{
		
		Loc_u8State=DIO_enuNotOK;
		
	}
	
	return Loc_u8State;
	
	
	
}