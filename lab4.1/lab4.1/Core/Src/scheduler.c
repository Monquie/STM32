  /*
 * sheduler.c
 *
 *  Created on: Nov 21, 2021
 *      Author: Win10
 */
#include "scheduler.h"

static int sizeArray=0;

void SCH_Update(void){
	if(SCH_Tasks[0].Delay == 0)
		{
			SCH_Tasks[0].Runtime++;
		}
	else
		SCH_Tasks[0].Delay--;

}
void SCH_Add_Task(void (*pFunction)(), int Delay, int Period){

	if (sizeArray==0){
		SCH_Tasks[0].pTask = pFunction;
		SCH_Tasks[0].Delay = Delay;
		SCH_Tasks[0].Period = Period;
		SCH_Tasks[0].Runtime = 0;
		sizeArray++;
		return;
	}
	else{
		sizeArray++;
		int i=-1;
		while ((SCH_Tasks[i].pTask != 0x0000)&&(i <SCH_MAX_TASKS)){
			i++;
			Delay= Delay-SCH_Tasks[i].Delay;//500
			if (SCH_Tasks[i+1].pTask != 0x0000 && SCH_Tasks[i+1].Delay > Delay){
				for (int j= i+1; j<SCH_MAX_TASKS;j++){
					SCH_Tasks[j].pTask = SCH_Tasks[j+1].pTask ;
					SCH_Tasks[j].Delay = SCH_Tasks[j+1].Delay;
					SCH_Tasks[j].Period =SCH_Tasks[j+1].Period;
					SCH_Tasks[j].Runtime = SCH_Tasks[j+1].Runtime;
				}
				SCH_Tasks[i+1].pTask = pFunction;
				SCH_Tasks[i+1].Delay = Delay;
				SCH_Tasks[i+1].Period = Period;
				SCH_Tasks[i+1].Runtime = 0;

				SCH_Tasks[i +2].Delay = SCH_Tasks[i+2].Delay-SCH_Tasks[i+1].Delay;
				return;
			}
		}
		SCH_Tasks[i].pTask = pFunction;
		SCH_Tasks[i].Delay = Delay;
		SCH_Tasks[i].Period = Period;
		SCH_Tasks[i].Runtime = 0;
		return;
	}
}

void SCH_Dispatcher(void){
	while (SCH_Tasks[0].Runtime>0 || SCH_Tasks[0].Delay==0)
	{
		(*SCH_Tasks[0].pTask)();
		SCH_Tasks[0].Runtime-=1;
		if(SCH_Tasks[0].Period==0){
			SCH_Delete(0);
			SCH_Reallocate();
		}
		else{
			SCH_Add_Task(SCH_Tasks[0].pTask,SCH_Tasks[0].Period,SCH_Tasks[0].Period);
			SCH_Delete(0);
			SCH_Reallocate();
		}
	}


}
void SCH_Reallocate(){
	for(int i=0;i<SCH_MAX_TASKS-1;i++){
		SCH_Tasks[i].pTask= SCH_Tasks[i+1].pTask;
		SCH_Tasks[i].Delay= SCH_Tasks[i+1].Delay;
		SCH_Tasks[i].Period= SCH_Tasks[i+1].Period;
		SCH_Tasks[i].Runtime= SCH_Tasks[i+1].Runtime;
	}
}
void SCH_Delete(int index){
	sizeArray--;
	SCH_Tasks[index].pTask= 0x0000;
	SCH_Tasks[index].Delay= 0;
	SCH_Tasks[index].Period= 0;
	SCH_Tasks[index].Runtime= 0;
}
