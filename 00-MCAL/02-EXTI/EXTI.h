/*
 * EXTI.h
 *
 * Created: 1/27/2023 12:40:04 PM
 *  Author: TAQWA HAMED
 */ 


#ifndef EXTI_H_
#define EXTI_H_



//  Enum of the available External Interrupt Lines
typedef enum{
	LINE0,
	LINE1,
	LINE2
}EXTI_tenuEi_Line;


// Enum of the Possible edge sensing
typedef enum{
	RISING_EDGE,
	FALLING_EDGE,
	ON_CHANGE,
	LOW_LEVEL
}EXTI_tenuEi_SenseMode;


// Enum of the Configurations of the EXTI Peripheral
typedef struct{
	EXTI_tenuEi_Line LINE;
	EXTI_tenuEi_SenseMode SENSE;
}EXTI_tstrConfig_t;

/**
 *@Function Name 	:	EXTI_voidInit
 *@description		:	This Function is used to set the configurations of the External Interrupt
 *@description		:	The Function is based on pre-build Configurations
 *@param[in]		: 	void
 *@param[out]		: 	void
 */
void EXTI_voidInit(void);
/**
 *@Function Name 	:	EXTI_voidEnable
 *@description		:	This Function is used to set the configurations of the External Interrupt
 *@description		:	The Function is based on Run-time Configurations
 *@param[in]		: 	EXTI_Config * Configurations  : pointer to struct that contains the Line number and the sense edge
 *@param[out]		: 	void
 */
void EXTI_voidEnable(const EXTI_tstrConfig_t * Configurations);
/**
 *@Function Name 	:	EXTI_voidDisable
 *@description		:	This Function is used to Disable specific External Interrupt Line
 *@param[in]		: 	Copy_enumLine  :  External Interrupt Line number
 *@param[out]		: 	void
 */
void EXTI_voidDisable(EXTI_tenuEi_Line Copy_enumLine);
/**
 *@Function Name 	:	EXTI_voidSetCALLBACK
 *@description		:	This Function is used to set the Call back function of the External Interrupt Line
 *@param[in]		: 	Copy_enumLine : External Interrupt Line number
 *@param[in]		: 	void(*CALLBACK)(void) : Pointer to function
 *@param[out]		: 	void
 */
void EXTI_voidSetCALLBACK(EXTI_tenuEi_Line Copy_enumLine, void(*CALLBACK)(void));


















#endif /* EXTI_H_ */