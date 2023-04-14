/*
 * UART_MANGER.h
 *
 * Created: 3/25/2023 4:03:15 PM
 *  Author: TAQWA HAMED
 */ 


#ifndef UART_MANGER_H_
#define UART_MANGER_H_

typedef enum
{
	SYNC_READ,
	SYNC_WRITE,
	ASYNC_READ,
	ASYNC_WRITE

}UART_MANAGER_enutype;

typedef struct{
	UART_MANAGER_enutype type;
	u8 *data;
	u8 Length;
	void (*JOB_CALLBACK )(void);
	
}UART_MANAGER_t;

#define MAX_NUM_JOBS  ((u8)5)
UART_tenuErrorStatus UART_Mgr_ADD_JOB(UART_MANAGER_t* copy_strp_UART);
UART_tenuErrorStatus UART_Mgr_enumStart(void);

#endif /* UART_MANGER_H_ */