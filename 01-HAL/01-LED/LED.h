/*
 * LED.h
 *
 * Created: 1/17/2023 9:05:44 PM
 *  Author: totoh
 */ 


#ifndef LED_H_
#define LED_H_


typedef enum{

	LED_enuNOK = 0,
	LED_enuOK ,
	LED_enuNullPtr
	
}LED_tenuErrorStatus;





LED_tenuErrorStatus LED_enuON(u8 Cpy_u8LedNumber);


LED_tenuErrorStatus LED_enuOFF(u8 Cpy_u8LedNumber);
















#endif /* LED_H_ */