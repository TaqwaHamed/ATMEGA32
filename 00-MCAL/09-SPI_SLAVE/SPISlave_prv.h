/*
 * SPISlave_prv.h
 *
 * Created: 4/1/2023 9:44:57 PM
 *  Author: TAQWA HAMED
 */ 


#ifndef SPISLAVE_PRV_H_
#define SPISLAVE_PRV_H_


#define SPCR		*( (volatile u8 * const) 0x2D )
#define SPIE		7
#define SPE			6
#define DORD		5
#define MSTR		4
#define CPOL		3
#define CPHA		2
#define SPR1		1
#define SPR0		0


#define SPSR		*( (volatile u8 * const) 0x2E )
#define SPIF		7
#define WCOL		6
#define SPDR		*( (volatile u8 * const) 0x2F )


#endif /* SPISLAVE_PRV_H_ */