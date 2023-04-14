/*
 * LDR.h
 *
 * Created: 2/7/2023 8:52:57 PM
 *  Author: TAQWA HAMED
 */ 


#ifndef LDR_H_
#define LDR_H_

// FIRST make sure that you configure LDR pin as an input

/**
 *@Function Name 	:	LDR_SNESOR_u8Read
 *@description		:	This Function is used to read the value of LDR sensor
 *@param[in]		: 	Copy_u8ChannelNumber >> the ADC channel
 *@param[out]		: 	the value of LDR sensor
 */
u8 LDR_SNESOR_u8Read(u8 Copy_u8ChannelNumber);



#endif /* LDR_H_ */