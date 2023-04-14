/*
 * SPI.h
 *
 * Created: 4/1/2023 8:55:57 PM
 *  Author: TAQWA HAMED
 */ 


#ifndef SPI_slave_H_
#define SPI_slave_H_

typedef enum{
	SPI_enuNOK = 0,
	SPI_enuOK ,
	SPI_enuNullPtr
	
}SPI_SLAVE_enuErrorStatus;

typedef enum{
	SPI_MASTER = ( 0b1 << 4) ,
	SPI_SLAVE  = ( 0b0 << 4)
}SPI_Mode_t;


typedef enum{
	SPI_LEADING_RISING  = ( 0b0 << 3),
	SPI_LEADING_FALLING = ( 0b1 << 3)
}SPI_CPOL_t;

typedef enum{
	SPI_LEADING_SAMPLE  = ( 0b0 << 2),
	SPI_LEADING_SETUP   = ( 0b1 << 2)
}SPI_CPHA_t;

typedef enum{
	SPI_MSB_FIRST = ( 0b0 << 5 ),
	SPI_LSB_FIRST = ( 0b1 << 5)
}SPI_DataOrder_t;

typedef enum{
	SPI_ENABLE_INTERRUPT  = (0b1 << 7),
	SPI_DISABLE_INTERRUPT = (0b0 << 7)
}SPI_Interrupt_t;

typedef enum{
	SPI_ENABLE  = (0b1 << 6),
	SPI_DISABLE = (0b0 << 6)
}SPI_EN_t;

typedef struct{
	SPI_Mode_t 		Mode;
	SPI_CPOL_t		Spi_ClockPolarity;
	SPI_CPHA_t		Spi_ClockPhase	 ;
	SPI_DataOrder_t	Spi_DataOrder	 ;
	SPI_Interrupt_t Spi_Interrupt	 ;
	SPI_EN_t		Spi_State	     ;
}SPI_SlaveConfigs_t;


SPI_SLAVE_enuErrorStatus SPI_enuSetSlaveConfigs(const SPI_SlaveConfigs_t * Copy_strSpiConfigurations);
SPI_SLAVE_enuErrorStatus SPI_enuSlave_TransRec(u8 Copy_u8Data, u8 *Copy_u8SlaveData);



#endif /* SPI_slave_H_ */