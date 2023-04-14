/*
 * ADC.h
 *
 * Created: 2/4/2023 9:08:50 AM
 *  Author: TAQWA HAMED
 */ 


#ifndef ADC_H_
#define ADC_H_

typedef enum{

	ADC_enuNOK = 0,
	ADC_enuOK ,
	ADC_enuNullPtr,
	ADC_enuErrorChainBusy
	
	
}ADC_tenuErrorStatus;
typedef enum
{
	ADC_enuChainBusy = 0,
	ADC_enuChainReady,
}ADC_tenuChainState;

typedef struct
{
	u8 chainLength;
	u8 *chainChannels;
	u16 *chainResults;
	void (*EOJ) (void);
}ADC_strChain_t;

void ADC_VoidInit (void);
ADC_tenuErrorStatus ADC_enuread (u8 Copy_u8Channel_Id, u16 * Add_pu16ADCRead);
ADC_tenuErrorStatus ADC_enuStartConversionAsync(ADC_strChain_t *cpy_strChain);
ADC_tenuErrorStatus ADC_enuSetADCCallBack(void (*CALLBACK) (void));


#define ADC_0					(0b00000)
#define ADC_1					(0b00001)
#define ADC_2					(0b00010)
#define ADC_3					(0b00011)
#define ADC_4					(0b00100)
#define ADC_5					(0b00101)
#define ADC_6					(0b00110)
#define ADC_7					(0b00111)
#define  ADC_VCC                 5



#endif /* ADC_H_ */