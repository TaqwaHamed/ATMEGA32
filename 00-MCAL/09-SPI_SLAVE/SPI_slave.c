/*
 * SPI.c
 *
 * Created: 4/1/2023 8:55:40 PM
 *  Author: TAQWA HAMED
 */ 


#include "../../04-LIB/STD_TYPES.h"
#include "../../04-LIB/BIT_MATH.h"
#include "SPI_slave.h"
#include "SPISlave_prv.h"

SPI_SLAVE_enuErrorStatus SPI_enuSetSlaveConfigs(const SPI_SlaveConfigs_t * Copy_strSpiConfigurations)
{
	SPI_SLAVE_enuErrorStatus LOC_ErrorStatus=SPI_enuNOK;
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
		SPCR |= Copy_strSpiConfigurations->Spi_State;
		
	}
	
	return LOC_ErrorStatus;
}
SPI_SLAVE_enuErrorStatus SPI_enuSlave_TransRec(u8 Copy_u8Data, u8 *Copy_u8SlaveData)
{
	
	SPI_SLAVE_enuErrorStatus LOC_ErrorStatus=SPI_enuNOK;
	SPDR = Copy_u8Data;
	while( GET_BIT(SPSR,SPIF) ==0);
	*Copy_u8SlaveData=SPDR;  // return slave data
	return LOC_ErrorStatus;
}