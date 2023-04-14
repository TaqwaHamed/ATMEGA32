/*
 * EXTI.c
 *
 * Created: 1/27/2023 12:40:24 PM
 *  Author: TAQWA HAMED
 */ 


#include "../../04-LIB/STD_TYPES.h"
#include "../../04-LIB/BIT_MATH.h"
#include "EXTI.h"
#include "EXTI_prv.h"
#include "EXTI_cfg.h"


void (*arrp_callbacks[3]) (void)={NULL};
void __vector_1(void)__attribute__((signal));      // attribute>> like volatile , to force compiler not to optomize it,because it called by hardware
void __vector_2(void)__attribute__((signal));
void __vector_3(void)__attribute__((signal));

void EXTI_voidInit(void)
{
	
#if EXTI_LINE==EXTI_LINE0
	SET_BIT(GICR, INT0);
	#if EXTI_SENSE == EXTI_RISING_EDGE
	SET_BIT(MCUCR, ISC00);
	SET_BIT(MCUCR, ISC01);
	#elif EXTI_SENSE == EXTI_FALLING_EDGE
	SET_BIT(MCUCR, ISC01);
	CLR_BIT(MCUCR, ISC00);
	#elif EXTI_SENSE == EXTI_ON_CHANGE
	SET_BIT(MCUCR, ISC00);
	CLR_BIT(MCUCR, ISC01);
	#elif EXTI_SENSE == EXTI_LOW_LEVEL
	CLR_BIT(MCUCR, ISC00);
	CLR_BIT(MCUCR, ISC01);
	
	#else
		#error "Wrong External Interrupt Line0 Sense Edge"
    #endif


#elif EXTI_LINE==EXTI_LINE1
	SET_BIT(GICR, INT1);
		#if EXTI_SENSE == EXTI_RISING_EDGE
		SET_BIT(MCUCR, ISC10);
		SET_BIT(MCUCR, ISC11);
		#elif EXTI_SENSE == EXTI_FALLING_EDGE
		SET_BIT(MCUCR, ISC11);
		CLR_BIT(MCUCR, ISC10);
		#elif EXTI_SENSE == EXTI_ON_CHANGE
		SET_BIT(MCUCR, ISC10);
		CLR_BIT(MCUCR, ISC11);
		#elif EXTI_SENSE == EXTI_LOW_LEVEL
		CLR_BIT(MCUCR, ISC10);
		CLR_BIT(MCUCR, ISC11);
		
		#else
		#error "Wrong External Interrupt Line1 Sense Edge"
        #endif
		
#elif EXTI_LINE==EXTI_LINE2
	SET_BIT(GICR, INT2);
	#if EXTI_SENSE == EXTI_RISING_EDGE
	SET_BIT(MCUCR, ISC2);
	#elif EXTI_SENSE == EXTI_FALLING_EDGE
	CLR_BIT(MCUCR, ISC2);
	
	#else
	#error "Wrong External Interrupt Line2 Sense Edge"
    #endif

#else
	#error

#endif
	
	
	
}




void EXTI_voidEnable(const EXTI_tstrConfig_t * Configurations)
{
	if (Configurations->LINE == LINE0)
	{
		SET_BIT(GICR, INT0);
		switch(Configurations->SENSE)
		{
			case RISING_EDGE:
			SET_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
			case FALLING_EDGE:
			SET_BIT(MCUCR, ISC01);
			CLR_BIT(MCUCR, ISC00);
			break;
			case ON_CHANGE:
			SET_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
			break;
			case LOW_LEVEL:
			CLR_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
			break;
		}
		
	}
	else if (Configurations->LINE ==LINE1)
	{
		SET_BIT(GICR, INT1);
		switch(Configurations->SENSE)
		{
			case RISING_EDGE:
			SET_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
			break;
			case FALLING_EDGE:
			SET_BIT(MCUCR, ISC11);
			CLR_BIT(MCUCR, ISC10);
			break;
			case ON_CHANGE:
			SET_BIT(MCUCR, ISC10);
			CLR_BIT(MCUCR, ISC11);
			break;
			case LOW_LEVEL:
			CLR_BIT(MCUCR, ISC10);
			CLR_BIT(MCUCR, ISC11);
			break;
		}
	}
	else if (Configurations->LINE ==LINE2)
	{
		SET_BIT(GICR, INT2);
		switch(Configurations->SENSE)
		{
			case RISING_EDGE:
			SET_BIT(MCUCSR, ISC2);
			break;
			case FALLING_EDGE:
			CLR_BIT(MCUCSR, ISC2);
			break;
			
		}
	}
	else
	{
		
	}
	
	
}




void EXTI_voidDisable(EXTI_tenuEi_Line Copy_enumLine)
{
	switch(Copy_enumLine)
	{
	case LINE0:
	CLR_BIT(GICR, INT0);
	break;	
	
	case LINE1:
	CLR_BIT(GICR, INT1);
	break;
	
	case LINE2:
	CLR_BIT(GICR, INT2);
	break;
		
	}
	
}



void EXTI_voidSetCALLBACK(EXTI_tenuEi_Line Copy_enumLine, void(*CALLBACK)(void))
{
	if (Copy_enumLine<3)
	{
		if (CALLBACK!=NULL)
		{
			
			arrp_callbacks[Copy_enumLine] = CALLBACK;
			
		}
		else
		{
			
		}
	}
	else
	{
		
	}
	
	
	
	
	
}

void __vector_1(void)
{
	if (arrp_callbacks[LINE0] != NULL)
	{
		arrp_callbacks[LINE0]();
	}
}



void __vector_2(void)
{
	if (arrp_callbacks[LINE1] != NULL)
	{
		arrp_callbacks[LINE1]();
	}
}


void __vector_3(void)
{
	if (arrp_callbacks[LINE2] != NULL)
	{
		arrp_callbacks[LINE2]();
	}
}