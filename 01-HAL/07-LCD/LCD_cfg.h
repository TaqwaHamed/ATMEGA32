/*
 * LCD_cfg.h
 *
 * Created: 2/10/2023 12:57:10 PM
 *  Author: TAQWA HAMED
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_


#define EIGHT_BIT	0
#define FOUR_BIT	1

#define LOW_NIBBLE	0
#define HIGH_NIBBLE	1

/*	
   select LCD_MODE:
   	EIGHT_BIT
	FOUR_BIT   	
*/
#define LCD_MODE		EIGHT_BIT

#if LCD_MODE==FOUR_BIT
/*	
   select :
   	LOW_NIBBLE
	HIGH_NIBBLE   	
*/
#define NIBBLE  LOW_NIBBLE

#endif

#define LCD_BLOCK_SIZE   8

	
#define LCD_RS_PIN       DIO_enuPin21
#define LCD_RW_PIN       DIO_enuPin22
#define LCD_EN_PIN       DIO_enuPin23
#define LCD_D0_PIN       DIO_enuPin24
#define LCD_D1_PIN       DIO_enuPin25
#define LCD_D2_PIN       DIO_enuPin26
#define LCD_D3_PIN       DIO_enuPin27
#define LCD_D4_PIN       DIO_enuPin28
#define LCD_D5_PIN       DIO_enuPin29
#define LCD_D6_PIN       DIO_enuPin30
#define LCD_D7_PIN       DIO_enuPin31





#endif /* LCD_CFG_H_ */