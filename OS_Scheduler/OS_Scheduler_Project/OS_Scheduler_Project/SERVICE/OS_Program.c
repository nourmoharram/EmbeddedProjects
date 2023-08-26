/*
 * OS_Program.c
 *
 *  Created on: Mar 5, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"GIE/GIE_Interface.h"
#include"TIMER/TIMER_Types.h"
#include"TIMER/TIMER_Init.h"
#include"OS_CONFIG.h"
#include"LED/LED_Init.h"
#include "../SERVICE/OS_Init.h"
#include "../SERVICE/OS_Private.h"
#include "../SERVICE/OS_Types.h"

static u8 index=0;
static Task_Config Task_Arr[NUMBER_OF_TASKS];
//volatile static u16 Timer_Counter=0;
void OS_Init(void)
{
	M_void_Timer_Init(Normal_Mode,Normal_Port);
	M_void_EnableTIMERInt(Normal_Mode);
	M_void_setCallBack(Normal_Mode,Schedular_Start);
	GIE_voidEnable();
}

void OS_Create_Task(Task_Config *Ptr_to_task)
{
	if(index<NUMBER_OF_TASKS)
	{
		index=(Ptr_to_task->Task_Priority)-1;
		Task_Arr[index].Task_Periodicty= Ptr_to_task->Task_Periodicty;
		Task_Arr[index].Task_Handler=Ptr_to_task->Task_Handler;
		Task_Arr[index].First_Delay=Ptr_to_task->First_Delay;
		Task_Arr[index].Task_State=Ptr_to_task->Task_State;
	}
}
/*Tasks priority from highest to lowest : 0 -> 4*/
void Schedular_Start(void)
{

	u8 i;

	for (i = 0; i < NUMBER_OF_TASKS; i++)
	{
		/*modifications*/
		if(Task_Arr[i].Delay_Time==0)
		{
			Task_Arr[i].Task_State=Ready;
		}
		else
		{
			Task_Arr[i].Delay_Time--;
		}

		/*Old implementation*/
		if(Task_Arr[i].Task_Periodicty != 0) //at first start of OS all tasks come together to be executed according to their priority
		{

				if(Task_Arr[i].Task_State==Ready)   //check task status
				{
					if(Task_Arr[i].First_Delay!=0)  //check first delay 
					{
						Task_Arr[i].First_Delay--;
						if(Task_Arr[i].First_Delay == 0) //if first delay finished call the task handler
						{
							//H_LCD_void_sendString("Scheduler");

							Task_Arr[i].Task_Handler(); 
							Task_Arr[i].First_Delay=Task_Arr[i].Task_Periodicty; /*assign the task periodicty to first delay 
																					in order to come in its specific time*/
						}
					}

				}
		}
	}
}

void OS_Start(void)
{
	M_TIMER0_setDelayTimeMilliSec(20,Normal_Mode,CLK_1024); //tick time = 20 ms

}



void OS_Susbend(u8 priority)
{
	if(priority<NUMBER_OF_TASKS)
	{
		Task_Arr[priority-1].Task_State=Susbend;

	}
}

void OS_Resume(u8 priority)
{
	if(priority<NUMBER_OF_TASKS)
	{
		if(Task_Arr[priority-1].Task_State==Susbend)
		{
			Task_Arr[priority-1].Task_State=Ready;
		}
	}

}

void OS_Delete(u8 priority)
{
	if(priority<NUMBER_OF_TASKS)
	{
		Task_Arr[priority-1].Task_Periodicty=0;
		Task_Arr[priority-1].Task_Handler=NULL;
		Task_Arr[priority-1].Task_State=Delete;
	}

}
void OS_Delay(u8 Priority,u32 Delay_Ticks)
{
	Task_Arr[Priority-1].Delay_Time=Delay_Ticks;
	Task_Arr[Priority-1].Task_State=Susbend;

}
