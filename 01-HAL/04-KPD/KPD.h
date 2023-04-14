/*
 * KPD.h
 *
 * Created: 1/28/2023 6:06:25 PM
 *  Author: TAQWA HAMED
 */ 


#ifndef KPD_H_
#define KPD_H_


typedef enum{

	KPD_enuNOK = 0,
	KPD_enuOK ,
	KPD_enuNullPtr
	
}KPD_tenuErrorStatus;


void KeyPadInt(void);
KPD_tenuErrorStatus KeyPadGetPressed(u8 *copy_pu8KeyValue );




#endif /* KPD_H_ */