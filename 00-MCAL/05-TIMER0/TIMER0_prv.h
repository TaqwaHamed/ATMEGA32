/*
 * TIMER0_prv.h
 *
 * Created: 2/28/2023 12:55:55 PM
 *  Author: TAQWA HAMED
 */ 


#ifndef TIMER0_PRV_H_
#define TIMER0_PRV_H_

/*************************************** REGISTERS DEFINITION **************************************************/
#define TCNT0				*( (volatile u8 * const) 0x52)
#define TCCR0				*( (volatile u8 * const) 0x53)
#define OCR0                *( (volatile u8 * const) 0x5C)
#define TIMSK               *( (volatile u8 * const) 0x59)
#define TIFR                *( (volatile u8 * const) 0x58)

/*************************************** REGISTERS BITS ********************************************************/

#define	CS00				(0)
#define	CS01				(1)
#define CS02				(2)
#define WGM00				(3)
#define COM00				(4)
#define COM01				(5)
#define WGM01				(6)
#define FOC0				(7)

#define TOIE0				(0)
#define OCIE0				(1)

#define MAX_CLK_VALUE        7
#define ENABLE	1
#define DISABLE	0

#define COMPARE_MATCH   1
#define NORMAL	        0

#define TOP     256
/************** TIMER0 Pre-scaler options ******************/
#define TIM0_NO_CLK				(0b000)
#define TIM0_CLK				(0b001)
#define TIM0_CLK_8				(0b010)
#define TIM0_CLK_64				(0b011)
#define TIM0_CLK_256			(0b100)
#define TIM0_CLK_1024			(0b101)
#define TIM0_EXTERNAL_FALLING	(0b110)
#define TIM0_EXTERNAL_RISING	(0b111)
/***********************************************************/



#endif /* TIMER0_PRV_H_ */