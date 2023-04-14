/*
 * LED_cfg.c
 *
 * Created: 1/17/2023 9:38:51 PM
 *  Author: totoh
 */ 


#include "../../04-LIB/STD_TYPES.h"
#include "../../00-MCAL/01-DIO/DIO.h"
#include "../../00-MCAL/01-DIO/DIO_prv.h"
#include "LED_cfg.h"


LED_tstrLedCfg_t LED_strLedCfg[MAX_LED_NUMBER] = {
	/*LED1*/{LED_ACTIVE_HIGH, DIO_enuPin0 },
	/*LED2*/{LED_ACTIVE_HIGH, DIO_enuPin17 },
	/*LED3*/{LED_ACTIVE_HIGH, DIO_enuPin18 },
	/*LED4*/{LED_ACTIVE_HIGH, DIO_enuPin19},
	/*LED5*/{LED_ACTIVE_HIGH, DIO_enuPin20 },
	/*LED6*/{LED_ACTIVE_HIGH ,DIO_enuPin21 },
	/*LED7*/{LED_ACTIVE_HIGH ,DIO_enuPin21 },
	/*LED8*/{LED_ACTIVE_HIGH, DIO_enuPin22 },
	/*LED9*/{LED_ACTIVE_HIGH, DIO_enuPin23 },
	/*LED10*/{LED_ACTIVE_HIGH, DIO_enuPin24 }
		
};