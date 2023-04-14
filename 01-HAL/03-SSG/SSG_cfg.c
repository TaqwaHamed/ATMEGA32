/*
 * SSG_cfg.c
 *
 * Created: 1/20/2023 2:56:11 PM
 *  Author: TAQWA HAMED
 */ 

#include "../../04-LIB/STD_TYPES.h"
#include "../../00-MCAL/01-DIO/DIO.h"
#include "../../00-MCAL/01-DIO/DIO_prv.h"
#include "SSG_cfg.h"






SSG_tstrSsgCfg_t SSG_strSsgCfg[MAX_SSG_NUMBER] = {
	/*SSG1*/{SSG_COMMON_CATHODE, DIO_enuPin24, DIO_enuPin25, DIO_enuPin26, DIO_enuPin27, DIO_enuPin28, DIO_enuPin29, DIO_enuPin30, DIO_enuPin31 },
	/*SSG2*/{SSG_COMMON_CATHODE, DIO_enuPin16, DIO_enuPin17, DIO_enuPin18, DIO_enuPin19, DIO_enuPin20, DIO_enuPin21, DIO_enuPin22, DIO_enuPin23 }
	
	
};