/*
 * SCHED.c
 *
 * Created: 3/20/2023 11:19:47 AM
 *  Author: TAQWA HAMED
 */ 


#include "../../04-LIB/STD_TYPES.h"
#include "../../00-MCAL/05-TIMER0/TIMER0.h"
#include "SCHED.h"

TASK tasks[MAX_NUM_TASKS]={{0}};
	
	void Init_Scheduler(void)
	{
		/*
		CTC Mode
		CLK_Pre = 64
		CTC Reg = 125
		*/
		TMR0Config_t Timer ;
		Timer.TIMER0_Mode = TIMER0_CTC_MODE;
		Timer.TIMER0_CLOCK_SELECT = TIM0_CLK_64;
		Timer.TIMER0_COMP_INTERRUPT = TIMER0_COMP_ENABLE_INTERRUPT;
		Timer.COMP_CALLBACK =voidScheduler ;
		TMR0_voidInitPostCompile(&Timer);
		TMR0_voidSetPreLoadValue(125);
		//TMR0_enuSetTickTimeMS(64,1);
		
	}
	
	
	void Create_Task(void(*fun)(void) , u8 priority , u16 periodicity,u16 firstdelay)
	{
		
		tasks[priority].func=fun;
		tasks[priority].periodicity=periodicity;
		tasks[priority].first_delay=firstdelay;
		
	}
	
	static void voidScheduler(void)
	{
		
		u8 task_num;
		
		for (task_num=0; task_num <MAX_NUM_TASKS; task_num++)
		{
			if (tasks[task_num].first_delay==0)
			{
				
				if (tasks[task_num].func!= NULL)
				{
					tasks[task_num].func();
					tasks[task_num].first_delay=tasks[task_num].periodicity-1;
				}
				
			}
			else
			{
				tasks[task_num].first_delay--;
			}
			
		}
		
		
		
	}
	
	
	void Start_Scheduler(void)
	{
		TMR0_enuStart();
		
	}
	

	
	