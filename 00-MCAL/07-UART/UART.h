/*
 * UART.h
 *
 * Created: 3/18/2023 8:19:52 PM
 *  Author: TAQWA HAMED
 */ 


#ifndef UART_H_
#define UART_H_
typedef enum{

	UART_enuNOK = 0,
	UART_enuOK ,
	UART_enuNullPtr
	
}UART_tenuErrorStatus;

typedef enum
{
	SYNC=(1<<6),
	ASYNC =(0<<6)
	
}UART_enutype;

typedef enum{
	TXC_ENABLE=(1<<6),
	TXC_DISABLE=(0<<6),
}TRANSMIT_INT;

typedef enum{
	RXC_ENABLE=(1<<7),
	RXC_DISABLE=(0<<7),
}RECIEVE_INT;

typedef enum{
	UDRE_ENABLE= (1<<5),
	UDRE_DISABLE=(0<<5),
}BUFFER_EMPTY_INT;

typedef enum{
	FIVE_BITS	= (0b00 << 1),
	SIX_BITS	= (0b01 << 1),
	SEVEN_BITS	= (0b10 << 1),
	EIGHT_BITS	= (0b11 << 1),
	NINE_BITS	= (0b111 << 1)
}CHAR_SIZE;

typedef enum{
	NO_PARITY    = (0b00<<4)	,
	EVEN_PARITY	 = (0b10<<4)	,
	ODD_PARITY   = (0b11<<4)
}PARITY_OPTIONS;

typedef enum{
	NORMAL_SPEED=(0<<1),
	DOUBLE_SPEED=(1<<1)
}UART_SPPED;

typedef enum{
	ONE_STOP = ( 0 << 3),
	TWO_STOP = ( 1 << 3)
}STOP_BITS;

typedef enum{
	TX_ENABLE=(1<<3),
	TX_DISABLE=(0<<3)
}TRANSMITER;

typedef enum{
	RX_ENABLE=(1<<4),
	RX_DISABLE=(0<<4)
}RECIEVER;
typedef struct{
	UART_enutype type;
	CHAR_SIZE data_Length;
	PARITY_OPTIONS parity;
	STOP_BITS stop;
	UART_SPPED speed;
	TRANSMITER TX;
	RECIEVER RX ;
	TRANSMIT_INT TXC_INT;
	RECIEVE_INT RXC_INT;
	BUFFER_EMPTY_INT UDRE_INT;
	void (*UART_CALLBACK[3] )(void);
}UART_t;

typedef enum{
	TX_CALL,
	RX_CALL,
	UDRE_CALL
}INT_REQ_CallBack;
typedef enum
{
	UART_enuBusy = 0,
	UART_enuReady,
}UART_tenuState;

void UART_voidSetConfigurations(UART_t *Copy_structConfigurations);
void UART_voidSetBaudrate( u32 Copy_u32BaudRate);
UART_tenuErrorStatus UART_enuSendByteSynch(u8 Cpy_u8Data);
UART_tenuErrorStatus UART_enuSendstreamSynch(u8 *Cpy_u8Data);

UART_tenuErrorStatus UART_enuRecieveByteSynch(u8 *Cpy_pu8Data);
UART_tenuErrorStatus UART_enuRecievestreamSynch(u8 *Cpy_u8Data);

UART_tenuErrorStatus UART_enuSendByteAsynch(u8 Cpy_u8Data,void (*TX_CALLBACK)(void));
UART_tenuErrorStatus UART_enuRecieveByteAsynch(u8 *Cpy_pu8Data,void (*RX_CALLBACK)(void));






#endif /* UART_H_ */