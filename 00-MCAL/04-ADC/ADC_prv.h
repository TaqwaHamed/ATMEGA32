/*
 * ADC_prv.h
 *
 * Created: 2/4/2023 9:09:14 AM
 *  Author: TAQWA HAMED
 */ 


#ifndef ADC_PRV_H_
#define ADC_PRV_H_

#define ADMUX	*((volatile u8*)0x27)
#define ADCSRA 	*((volatile u8*)0x26)
#define ADCH	*((volatile u8*)0x25)
#define ADCL 	*((volatile u8*)0x24)
#define SFIOR	*( (volatile u8 * const) 0x50 )

#define   ADC_INTERNAL_VCC    (1<<6) | (0<<7)
#define   ADC_INTERNAL_2_56   (1<<6) | (1<<7)
#define   ADC_EXTERNAL_AREF   (0<<6) | (0<<7)

#define ADC_LEFT_ADJUST_ENABLE 	(1 << 5)
#define ADC_RIGHT_ADJUST_ENABLE (0 << 5)

#define ADC_ENABLE				(1 << 7)
#define ADC_DISABEL				(0 << 7)

#define ADC_ENABLE_INTERRUPT    (1 << 3)
#define ADC_DISABLE_INTERRUPT	(0 << 3)

#define ADC_START_CONVERSION     (1<<6)
#define ADC_Interrupt_Flag       4

#define  ADC_pre_2		     	 ( 0b001 )
#define  ADC_pre_4               ( 0b010 )
#define  ADC_pre_8               ( 0b011 )
#define  ADC_pre_16              ( 0b100 )
#define  ADC_pre_32              ( 0b101 )
#define  ADC_pre_64              ( 0b110 )
#define  ADC_pre_128             ( 0b111 )

#define  ADC_ENABLE_AUTO_TRIGGERING   (1<<5)
#define  ADC_DISABLE_AUTO_TRIGGERING  (0<<5)

#define ADC_FREE_RUNNING             	( (0b000)<<5 )
#define ADC_EXTI0						( (0b001)<<5 )
#define ADC_ANALOG_COMPARATOR			( (0b010)<<5 )
#define ADC_TIM0_COMPARE_MATCH			( (0b011)<<5 )
#define ADC_TIM0_OVER_FLOW				( (0b100)<<5 )
#define ADC_TIM1_COMPARE_MATCH_B		( (0b101)<<5 )
#define ADC_TIM1_OVERFLOW				( (0b110)<<5 )
#define ADC_TIM1_ICU                    ( (0b111)<<5 )



#endif /* ADC_PRV_H_ */