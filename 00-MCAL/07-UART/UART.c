/*
 * UART.c
 *
 * Created: 3/18/2023 8:19:27 PM
 *  Author: TAQWA HAMED
 */ 

 #include "../../04-LIB/STD_TYPES.h"
  #include "../../04-LIB/BIT_MATH.h"
  
 #include "UART.h"
 #include "UART_prv.h"

void __vector_13(void)__attribute__((signal));
void __vector_15(void)__attribute__((signal));

static UART_t *USART_Configs ; 
static void (*TX_CALL_BACK)(void)    = NULL;   
static void (*RX_CALL_BACK)(void)    = NULL;  
static void (*UDRE_CALL_BACK)(void)  = NULL; 
volatile UART_tenuState UART_enustate = UART_enuReady;
static *pu8Data=NULL;

  

void UART_voidSetConfigurations(UART_t *Copy_structConfigurations)
{
	USART_Configs= Copy_structConfigurations;
	
 UCSRC =Copy_structConfigurations->type | Copy_structConfigurations->parity |Copy_structConfigurations->stop |Copy_structConfigurations->data_Length;
 UCSRB =Copy_structConfigurations->RXC_INT |Copy_structConfigurations->TXC_INT |Copy_structConfigurations->UDRE_INT |Copy_structConfigurations->RX | Copy_structConfigurations->TX;
 UCSRA =Copy_structConfigurations->speed;
 TX_CALL_BACK = Copy_structConfigurations->UART_CALLBACK[TX_CALL];
 RX_CALL_BACK = Copy_structConfigurations->UART_CALLBACK[RX_CALL];
 UDRE_CALL_BACK = Copy_structConfigurations->UART_CALLBACK[UDRE_CALL];
 }

void UART_voidSetBaudrate( u32 Copy_u32BaudRate)
{
	
	u32 UBRR_VAL = 0;
	if (USART_Configs->type == SYNC)  // USe the Global Variable to Know the user Configurations
	{
		UBRR_VAL = ( F_CPU / (2*Copy_u32BaudRate ) ) - 1;
	}
	else if ( USART_Configs->type == ASYNC && USART_Configs->speed == NORMAL_SPEED )
	{
		UBRR_VAL = ( F_CPU / (16*Copy_u32BaudRate ) ) - 1;
	}
	else if ( USART_Configs->type == ASYNC && USART_Configs->speed == DOUBLE_SPEED )
	{
		UBRR_VAL = ( F_CPU / (8*Copy_u32BaudRate ) ) - 1;
	}
	UBRRH = (u8)( UBRR_VAL >> 8); // I need The second 8 Bits to be Written in UBRRH
	UBRRL = (u8) UBRR_VAL; // Write the First 8 bits
	
}



UART_tenuErrorStatus UART_enuSendByteSynch(u8 Cpy_u8Data)
{
	UART_tenuErrorStatus LOC_u8state=UART_enuNOK;
	while(GET_BIT(UCSRA,5)==0);
	UDR=Cpy_u8Data;
	return LOC_u8state;
}


UART_tenuErrorStatus UART_enuRecieveByteSynch(u8 *Cpy_pu8Data)
{
	UART_tenuErrorStatus LOC_u8state=UART_enuNOK;
	while(GET_BIT(UCSRA,7)==0);
	*Cpy_pu8Data=UDR;
	return LOC_u8state;
	
}


UART_tenuErrorStatus UART_enuSendstreamSynch(u8 *Cpy_u8Data)
{
	u8 iterator = 0;
	while(Cpy_u8Data[iterator]!='\0') 
	{
		UART_enuSendByteSynch(Cpy_u8Data[iterator]); 
		iterator++;
	}
	
}


UART_tenuErrorStatus UART_enuRecievestreamSynch(u8 *Cpy_u8Data)
{
	
	u8 i = 0,Read_char=0;
	//   13  >> ENTER ASCI
	while( Read_char!= 13) 
	{
		 UART_enuRecieveByteSynch(&Read_char);
		Cpy_u8Data[i++]=Read_char;
	}
	// END of string
	Cpy_u8Data[i]='\0';
	
}


UART_tenuErrorStatus UART_enuSendByteAsynch(u8 Cpy_u8Data,void (*TX_CALLBACK)(void))
{
	if ( UART_enustate == UART_enuReady)
	{
		if ( TX_CALLBACK != NULL )
		{
		TX_CALL_BACK=TX_CALLBACK;
		}
		else
		{
		
		}
	
		UDR=Cpy_u8Data;
		UART_enustate = UART_enuBusy;
	}
	
	
}

UART_tenuErrorStatus UART_enuRecieveByteAsynch(u8 *Cpy_pu8Data,void (*RX_CALLBACK)(void))
{
	if ( UART_enustate == UART_enuReady)
	{
		if ( RX_CALLBACK != NULL )
		{
			RX_CALL_BACK=RX_CALLBACK;
		}
		else
		{
			
		}
		pu8Data=Cpy_pu8Data;
		UART_enustate = UART_enuBusy;
	}
	
}


void __vector_15(void)
{
	if (TX_CALL_BACK)
	{
		TX_CALL_BACK();
	}
	
	UART_enustate = UART_enuReady;
	
}

void __vector_13(void)
{
	*pu8Data=UDR;
	if (RX_CALL_BACK)
	{
		RX_CALL_BACK();
	}
	
	UART_enustate = UART_enuReady;
	
}