/*
 * LED_cfg.h
 *
 * Created: 1/17/2023 9:06:18 PM
 *  Author: TAQWA HAMED
 */ 


#ifndef LED_CFG_H_
#define LED_CFG_H_


#define LED_ACTIVE_HIGH   0
#define LED_ACTIVE_LOW    1


typedef struct{
	u8 LED_Type;
	u8 LED_Pin;
}LED_tstrLedCfg_t;

//Number of LEDs connected to the system
#define MAX_LED_NUMBER		10




#endif /* LED_CFG_H_ */