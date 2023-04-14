/*
 * ADC.c
 *
 * Created: 2/4/2023 9:08:31 AM
 *  Author: TAQWA HAMED
 */ 

#include "../../04-LIB/STD_TYPES.h"
#include "../../04-LIB/BIT_MATH.h"
#include "../01-DIO/DIO.h"
#include "ADC.h"
#include "ADC_cfg.h"
#include "ADC_prv.h"


volatile ADC_strChain_t ADC_strChain = {0, NULL, NULL};
volatile ADC_tenuChainState ADC_enuChainState = ADC_enuChainReady;
volatile u8 ADC_u8ChainSelected = 0;    
volatile void (*ADC_ptrCallBack) (void) = NULL;
volatile u8 ADC_u8CurrentIndex = 0;
void __vector_16(void)__attribute__((signal));



void ADC_VoidInit (void)
{
	ADMUX = 0x00;
	ADCSRA = 0x00;
	ADMUX=ADC_REFERNECE_VOLTAGE|ADLAR;
	ADCSRA=ADC_STATE|ADC_INTERRUPT|ADC_AUTO_TRIGGER|ADC_prescaller;
	if (ADC_AUTO_TRIGGER==ADC_ENABLE_AUTO_TRIGGERING)
	{
			SFIOR &= ~( (0b111)<<5 );
			SFIOR |= ADC_AUTO_TRIGGER_SOURCE;
	}

}


ADC_tenuErrorStatus ADC_enuread (u8 Copy_u8Channel_Id, u16 * Add_pu16ADCRead)
{
	ADC_tenuErrorStatus Loc_u8State= ADC_enuOK;
	if (Copy_u8Channel_Id<=ADC_7)
	{
		ADMUX &=~(0b1111);
		ADMUX|=Copy_u8Channel_Id;
		ADCSRA |= ADC_START_CONVERSION;
		// wait the flag to be set
		while( ( (ADCSRA >> ADC_Interrupt_Flag)& 1) == 0 );
		
		#if ADLAR == ADC_RIGHT_ADJUST_ENABLE
		*Add_pu16ADCRead = ADCL| (ADCH <<8 );

		#elif ADLAR == ADC_LEFT_ADJUST_ENABLE
		*Add_pu16ADCRead = (ADCH << 2);
		#endif
		// clear flag
		ADCSRA|= ADC_Interrupt_Flag;
		
	}
	else
	{
		Loc_u8State= ADC_enuNOK;
	}
	
	
	
  return Loc_u8State;
}



ADC_tenuErrorStatus ADC_enuStartConversionAsync(ADC_strChain_t *cpy_strChain)
{
	ADC_tenuErrorStatus Loc_u8State = ADC_enuNOK;
	if(ADC_enuChainState == ADC_enuChainReady)
	{
		ADC_u8ChainSelected =1;
		ADC_enuChainState = ADC_enuChainBusy;
		// copy all elements from cpy_strChain to a global struct
		ADC_strChain.chainLength = cpy_strChain->chainLength;
		ADC_strChain.chainChannels = cpy_strChain->chainChannels;
		ADC_strChain.chainResults = cpy_strChain->chainResults;
		ADC_strChain.EOJ = cpy_strChain->EOJ;
		//select channel
		ADMUX &=~(0b1111);
		ADMUX|=ADC_strChain.chainChannels[ADC_u8CurrentIndex];
		ADCSRA |= ADC_START_CONVERSION;   
	}
	return Loc_u8State;
}



ADC_tenuErrorStatus ADC_enuSetADCCallBack(void (*CALLBACK) (void))
{
	ADC_tenuErrorStatus Loc_u8State = ADC_enuNOK;
	if(CALLBACK == NULL)
	{
		Loc_u8State = ADC_enuNullPtr;
	}
	else
	{
		ADC_u8ChainSelected = 2;
		ADC_ptrCallBack = CALLBACK;
		Loc_u8State = ADC_enuOK;
	}
	return Loc_u8State;
}








void __vector_16(void)
{
	if(ADC_u8ChainSelected == 0)
	{
		/* default (neither ADC_enuSetADCCallBack or ADC_enuStartConversionAsync called)*/
	}
	else if(ADC_u8ChainSelected == 1)
	{
		/* ADC_enuStartConversionAsync */
		if(ADC_u8CurrentIndex < ADC_strChain.chainLength)
		{
			if(ADLAR == ADC_RIGHT_ADJUST_ENABLE)
			{
				ADC_strChain.chainResults[ADC_u8CurrentIndex] = ADCL| (ADCH <<8 );
			}
			else
			{
				ADC_strChain.chainResults[ADC_u8CurrentIndex] = (ADCH << 2);
			}
			ADC_u8CurrentIndex+=1;
			ADMUX &=~(0b1111);
			ADMUX|=ADC_strChain.chainChannels[ADC_u8CurrentIndex];
			//ADCSRA |= ADC_START_CONVERSION;
		}
		else if(ADC_u8CurrentIndex == ADC_strChain.chainLength)
		{
			ADC_strChain.EOJ();
			ADC_u8CurrentIndex = 0;
			ADC_enuChainState = ADC_enuChainReady;
		}
	}
	else if(ADC_u8ChainSelected == 2)  //ADC_enuSetADCCallBack
	{
		if(ADC_ptrCallBack != NULL)
		{
			ADC_ptrCallBack();
		}
	}

	// clear flag
	ADCSRA|= ADC_Interrupt_Flag;
}