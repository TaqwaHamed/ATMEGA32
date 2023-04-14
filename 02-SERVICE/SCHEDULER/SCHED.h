/*
 * SCHED.h
 *
 * Created: 3/20/2023 11:19:20 AM
 *  Author: TAQWA HAMED
 */ 


#ifndef SCHED_H_
#define SCHED_H_

typedef struct
{
	void(*func)(void);
	u16 periodicity;
	u16 first_delay;

} TASK ;

#define MAX_NUM_TASKS			4



void Create_Task(void(*fun)(void) , u8 priority , u16 periodicity,u16 firstdelay);

void Init_Scheduler(void);

void Start_Scheduler(void);

static void voidScheduler(void);



#endif /* SCHED_H_ */