/*
 * sheduler.h
 *
 *  Created on: Nov 21, 2021
 *      Author: Win10
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

typedef struct {
	 void (*pTask)(void);
	 int Delay;
	 int Period;
	 int Runtime;
	 int TaskID;

} sTask;
#define SCH_MAX_TASKS 5
sTask SCH_Tasks[SCH_MAX_TASKS];

//void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatcher(void);
void SCH_Add_Task(void (*pFunction)(), int Delay, int Period);
void SCH_Reallocate(void);
void SCH_Delete(int index);
#endif /* INC_SCHEDULER_H_ */
