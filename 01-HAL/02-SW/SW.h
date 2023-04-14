/*
 * SW.h
 *
 * Created: 1/18/2023 1:08:05 PM
 *  Author: totoh
 */ 


#ifndef SW_H_
#define SW_H_

typedef enum{

	SW_enuNOK = 0,
	SW_enuOK ,
	SW_enuNullPtr
	
}SW_tenuErrorStatus;




// CHECK THE READ OF SWITCH IS ONE OF THE FOLLOWING MACROS
#define  PRESSED       ((u8)1)
#define  NOT_PRESSED   ((u8)0)


SW_tenuErrorStatus SW_enuRead(u8 Cpy_u8SwNumber,u8 * Add_pu8SWValue);





#endif /* SW_H_ */