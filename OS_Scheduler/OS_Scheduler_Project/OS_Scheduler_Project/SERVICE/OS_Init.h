/*
 * OS_Init.h
 *
 *  Created on: Mar 5, 2023
 *      Author: Dell
 */

#ifndef SERVICE_OS_INIT_H_
#define SERVICE_OS_INIT_H_
#include "../SERVICE/OS_Types.h"
#include"OS_Private.h"
void OS_Init(void);

void OS_Create_Task(Task_Config *Ptr_to_task);
void Schedular_Start(void);

void OS_Start(void);

void OS_Delay(u8 Priority,u32 Delay_Ticks);

void OS_Susbend(u8 priority);

void OS_Resume(u8 priority);

void OS_Delete(u8 priority);
#endif /* SERVICE_OS_INIT_H_ */
