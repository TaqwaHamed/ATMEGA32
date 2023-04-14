/*
 * UART_MANGER.c
 *
 * Created: 3/25/2023 4:02:38 PM
 *  Author: TAQWA HAMED
 */ 


 #include "../../04-LIB/STD_TYPES.h"
 #include "../../04-LIB/BIT_MATH.h"
 #include "UART.h"
 #include "UART_MANGER.h"
 

 static UART_MANAGER_t * UART_ARR[MAX_NUM_JOBS]={NULL};
 
UART_tenuErrorStatus UART_Mgr_ADD_JOB(UART_MANAGER_t* copy_strp_UART)
{
	UART_tenuErrorStatus LOC_ErrorState=UART_enuNOK;
	static LOC_CurrentJob_Index=0;
	if (copy_strp_UART==NULL)
	{
		LOC_ErrorState=UART_enuNullPtr;
	}
	else
	{
		if (LOC_CurrentJob_Index<MAX_NUM_JOBS)
		{
			if (copy_strp_UART->data != NULL)
			{
				UART_ARR[LOC_CurrentJob_Index]=copy_strp_UART;
				LOC_CurrentJob_Index++;
				LOC_ErrorState=UART_enuOK;
			}
			else
			{
				LOC_ErrorState=UART_enuNullPtr;
			}
			
		}
		else
		{
			LOC_ErrorState=UART_enuNOK;
		}
		
	}
	
	return LOC_ErrorState;
	
}

UART_tenuErrorStatus UART_Mgr_enumStart(void)
{
	UART_tenuErrorStatus LOC_ErrorState=UART_enuNOK;
//	static volatile u8 CurrentDataIndex = 0;
	u8 LoopIterator = 0;
	
	for (LoopIterator = 0; LoopIterator < MAX_NUM_JOBS; LoopIterator++)
	{
		
			if ( UART_ARR[LoopIterator]->type == SYNC_WRITE)
			{
				UART_enuSendstreamSynch(UART_ARR[LoopIterator]->data);
				
			}
			else if (UART_ARR[LoopIterator]->type == SYNC_READ)
			{
				UART_enuRecievestreamSynch(UART_ARR[LoopIterator]->data);
				
			}
			else if (UART_ARR[LoopIterator]->type == ASYNC_WRITE)
			{
				UART_enuSendstreamSynch(UART_ARR[LoopIterator]->data);
				if (UART_ARR[LoopIterator]->JOB_CALLBACK != NULL)
				{
					UART_ARR[LoopIterator]->JOB_CALLBACK();
				}
				
			}
			else if (UART_ARR[LoopIterator]->type == ASYNC_READ)
			{
				UART_enuRecievestreamSynch(UART_ARR[LoopIterator]->data);
				if (UART_ARR[LoopIterator]->JOB_CALLBACK != NULL)
				{
					UART_ARR[LoopIterator]->JOB_CALLBACK();
				}
				
			}
		}
	
	
	return LOC_ErrorState;
}