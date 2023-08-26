/*
 * main.c
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */
#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include"LED/LED_Init.h"
#include"Push_Button/PB_Init.h"
#include"OS_CONFIG.h"
#include"OS_Types.h"
#include"OS_Init.h"

void Task_1(void);
void Task_2(void);
void Task_3(void);
Task_Config Task1={Five_hundred_ms,one,Task_1};
Task_Config Task2={one_thousand_ms,two,Task_2};
Task_Config Task3={three_thousand_ms,three,Task_3};

int main(void)
{
	OS_Create_Task(&Task1);
	OS_Create_Task(&Task2);
	OS_Create_Task(&Task3);
	OS_Init();
	OS_Start();


	while(1)
	{

		//Task_1();
		//Task_2();
		//Task_3();
	}
}
void Task_1(void)
{
	H_LED_void_Toggle(LED_RED);
}
void Task_2(void)
{
	PB_State PB_status;
	PB_status=H_readPB(PB_ID1,PB_ACTIVE_LOW);
	if(PB_status==PB_PRESSED)
	{
		H_LED_void_Toggle(LED_BLUE);
	}
}
void Task_3(void)
{
	H_LED_void_Toggle(LED_GREEN);
}
