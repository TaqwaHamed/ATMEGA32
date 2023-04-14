/*
 * SSG.h
 *
 * Created: 1/20/2023 2:55:24 PM
 *  Author: totoh
 */ 


#ifndef SSG_H_
#define SSG_H_


typedef enum{

	SSG_enuNOK = 0,
	SSG_enuOK ,
	SSG_enuNullPtr
	
}SSG_tenuErrorStatus;





SSG_tenuErrorStatus SSG_enuDisplay(u8 Cpy_u8SsgNumber,u8 Cpy_u8SsgDispNum);








#endif /* SSG_H_ */