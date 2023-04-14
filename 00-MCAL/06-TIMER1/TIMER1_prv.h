/*
 * TIMER1_prv.h
 *
 * Created: 3/11/2023 8:14:00 PM
 *  Author: TAQWA HAMED
 */ 


#ifndef TIMER1_PRV_H_
#define TIMER1_PRV_H_


#define TCNT1 					*((volatile u16 *const )0x4C)
#define TCCR1A					*((volatile u8 *const )0x4F)
#define TCCR1B					*((volatile u8 *const )0x4E)
#define OCRA					*((volatile u16 *const )0x4A)
#define OCRB					*((volatile u16 *const )0x48)
#define ICR1					*((volatile u16 *const )0x46)
#define TIMSK               *( (volatile u8 * const) 0x59)
#define TIFR                *( (volatile u8 * const) 0x58)



#endif /* TIMER1_PRV_H_ */