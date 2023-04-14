/*
 * DELAY.c
 *
 * Created: 1/20/2023 12:10:57 AM
 *  Author: TAQWA HAMED
 */ 




#include "../STD_TYPES.h"
#include "DELAY.h"


void delay(u32 ms)
{
	volatile u32 i = 0;
	for ( i = 0; i<(F_CPU/62000)*ms; i++)        // 62 clock cycle
	{
		asm("NOP");
	}
	
}