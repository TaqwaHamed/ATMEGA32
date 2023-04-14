/*
 * ADC_cfg.h
 *
 * Created: 2/4/2023 9:09:30 AM
 *  Author: TAQWA HAMED
 */ 


#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/*
  	ADC_INTERNAL_VCC
	ADC_INTERNAL_2_56
	ADC_EXTERNAL_AREF
 */
#define ADC_REFERNECE_VOLTAGE 		ADC_INTERNAL_VCC

/*	ADC_RIGHT_ADJUST_ENABLE
	ADC_LEFT_ADJUST_ENABLE
*/

#define ADLAR					ADC_LEFT_ADJUST_ENABLE

/*
  ADC_ENABLE
  ADC_DISABEL
 */
#define ADC_STATE			ADC_ENABLE

/*
   ADC_ENABLE_INTERRUPT
   ADC_DISABLE_INTERRUPT
 */

#define ADC_INTERRUPT		ADC_ENABLE_INTERRUPT

 /*
     ADC_pre_2						
     ADC_pre_4                       
     ADC_pre_8                       
     ADC_pre_16                      
     ADC_pre_32                      
     ADC_pre_64                      
     ADC_pre_128                     

 */
#define ADC_prescaller  	ADC_pre_16

 /* Options
 	 	 	 	 * ADC_ENABLE_AUTO_TRIGGERING
 	 	 	 	 * ADC_DISABLE_AUTO_TRIGGERING
 */

#define ADC_AUTO_TRIGGER			ADC_ENABLE_AUTO_TRIGGERING

#if ADC_AUTO_TRIGGER == ADC_ENABLE_AUTO_TRIGGERING

/*
 * Options
				 * ADC_FREE_RUNNING
				 * ADC_EXTI0
				 * ADC_ANALOG_COMPARATOR
				 * ADC_TIM0_COMPARE_MATCH
				 * ADC_TIM0_OVER_FLOW
				 * ADC_TIM1_COMPARE_MATCH_B
				 * ADC_TIM1_OVERFLOW
				 * ADC_TIM1_ICU
*/
#define ADC_AUTO_TRIGGER_SOURCE		ADC_FREE_RUNNING
#endif


#endif /* ADC_CFG_H_ */