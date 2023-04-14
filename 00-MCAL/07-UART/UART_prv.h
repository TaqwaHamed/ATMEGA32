/*
 * UART_prv.h
 *
 * Created: 3/18/2023 8:20:28 PM
 *  Author: TAQWA HAMED
 */ 


#ifndef UART_PRV_H_
#define UART_PRV_H_

#define F_CPU  8000000
#define UBRRL		*( (volatile u8 * const ) 0x29 )
#define UDR			*( (volatile u8 * const ) 0x2C )
#define UBRRH		*( (volatile u8 * const ) 0x40 )
#define UCSRC		*( (volatile u8 * const ) 0x40 )

#define UCSRA		*( (volatile u8 * const  ) 0x2B )
#define UCSRB		*( (volatile u8 * const  ) 0x2A )



#endif /* UART_PRV_H_ */