/*
 * SPI.c
 *
 * Created: 4/1/2023 8:55:40 PM
 *  Author: TAQWA HAMED
 */ 


#include "../../04-LIB/STD_TYPES.h"
#include "../../04-LIB/BIT_MATH.h"
#include "SPI.h"
#include "../01-DIO/DIO.h"
#include "SPI_prv.h"



SPI_MASTER_enuErrorStatus SPI_enuSetMasterConfigs( SPI_MasterConfigs_t * Copy_strSpiConfigurations)
{
	SPI_MASTER_enuErrorStatus LOC_ErrorStatus=SPI_enuNOK;
		if (Copy_strSpiConfigurations==NULL)
		{
			LOC_ErrorStatus=SPI_enuNullPtr;
		}
		else
		{
			SPCR = 0x00;
			SPSR = 0x00;
			
			CLR_BIT(SPCR , SPE);
			SPCR |= Copy_strSpiConfigurations->Mode |Copy_strSpiConfigurations->Spi_ClockPhase | Copy_strSpiConfigurations->Spi_ClockPolarity | Copy_strSpiConfigurations->Spi_DataOrder | Copy_strSpiConfigurations->Spi_Interrupt;
			SPCR |= ( Copy_strSpiConfigurations->Spi_Speed );
			SPSR |=	GET_BIT(Copy_strSpiConfigurations->Spi_Speed , 2) ; 
			SPCR |= Copy_strSpiConfigurations->Spi_State;
			
		}
	
	
	
	return LOC_ErrorStatus;
}



SPI_MASTER_enuErrorStatus SPI_enuMaster_TransRec(u8 Copy_u8Data ,u8 *Copy_u8SlaveData)
{
	
	SPI_MASTER_enuErrorStatus LOC_ErrorStatus=SPI_enuNOK;
   
	DIO_enuClearPin(12);
	SPDR = Copy_u8Data;
	while( GET_BIT(SPSR,SPIF) ==0);
	 DIO_enuSetPin(12);
	*Copy_u8SlaveData=SPDR;  // return slave data
	return LOC_ErrorStatus;
}