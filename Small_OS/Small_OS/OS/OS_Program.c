/*
 * OS_Program.c
 *
 *  Created on: Mar 5, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"PORT/Port_int.h"
#include"GIE/GIE_Interface.h"
#include"TIMER/TIMER_Types.h"
#include"TIMER/TIMER_Init.h"
#include"OS_CONFIG.h"
#include"OS_Init.h"
#include"OS_Private.h"
#include"OS_Types.h"
#include"LED/LED_Init.h"
static Task_Config Task_Arr[3]={{0,0,0}};
extern const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE];
//static u32 Timer_Counter=0;
void OS_Init(void)
{
	Port_Init(PORT_Config_Arr);
	M_void_Timer_Init(Normal_Mode,Normal_Port);
	M_void_EnableTIMERInt(Normal_Mode);
	M_void_setCallBack(Normal_Mode,Schedular_Start);
	GIE_voidEnable();
}

void OS_Create_Task(Task_Config *Ptr_to_task)
{
	u8 index=0;
	index=Ptr_to_task->Task_Priority;
	Task_Arr[index].Task_Periodicty= Ptr_to_task->Task_Periodicty;
	Task_Arr[index].ptrToFunc=Ptr_to_task->ptrToFunc;
}
void Schedular_Start(void)
{
	//H_LED_void_Toggle(LED_RED);

	static u16 Timer_counter=0;
	u8 flag_counter=0;
	Timer_counter+=TICKS;
	for(u8 i=0;i<3;i++)
	{
		if(Timer_counter % (Task_Arr[i].Task_Periodicty)==0)
		{
			if(Task_Arr[i].ptrToFunc != NULL)
			{
				Task_Arr[i].ptrToFunc();
				flag_counter++;
			}
		}
	}
	if(flag_counter==3)
	{
		Timer_counter=0;
	}

}

void OS_Start(void)
{
	M_TIMER0_setDelayTimeMilliSec(500,Normal_Mode,CLK_8);

}
