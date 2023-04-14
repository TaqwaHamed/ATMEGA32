/*
 * SSG_cfg.h
 *
 * Created: 1/20/2023 2:55:48 PM
 *  Author: totoh
 */ 


#ifndef SSG_CFG_H_
#define SSG_CFG_H_

#define SSG_COMMON_CATHODE   0
#define SSG_COMMON_ANODE     1


typedef struct{
	u8 SSG_Type;
	u8 SSG_LED1;
	u8 SSG_LED2;
	u8 SSG_LED3;
	u8 SSG_LED4;
	u8 SSG_LED5;
	u8 SSG_LED6;
	u8 SSG_LED7;
	u8 SSG_LED8;
	
	
}SSG_tstrSsgCfg_t;

//Number of SSGs connected to the system
#define MAX_SSG_NUMBER		3




#endif /* SSG_CFG_H_ */