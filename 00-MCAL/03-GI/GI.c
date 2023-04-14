/*
 * GI.c
 *
 * Created: 1/28/2023 5:29:27 PM
 *  Author: totoh
 */ 

#include "../../04-LIB/STD_TYPES.h"
#include "../../04-LIB/BIT_MATH.h"
#include "GI.h"
#include "GI_prv.h"

void GIE_voidEnable(void)
{
	SET_BIT( SREG , GIE );
}

void GIE_voidDisable(void)
{
	CLR_BIT( SREG , GIE );
}
