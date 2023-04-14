/*
 * SW_cfg.c
 *
 * Created: 1/18/2023 1:08:43 PM
 *  Author: totoh
 */ 


#include "../../04-LIB/STD_TYPES.h"
#include "../../00-MCAL/01-DIO/DIO.h"
#include "../../00-MCAL/01-DIO/DIO_prv.h"
#include "SW_cfg.h"




SW_tstrSwCfg_t SW_strSwCfg[MAX_SW_NUMBER] = {
	/*SW1*/{ DIO_enuPin2 , SW_PULL_UP},
	/*SW2*/{ DIO_enuPin4 , SW_PULL_UP},
	/*SW3*/{ DIO_enuPin6 , SW_PULL_UP},
	/*SW4*/{ DIO_enuPin5 , SW_PULL_UP}
	
	
};