/*
 * OS_Init.h
 *
 *  Created on: Mar 5, 2023
 *      Author: Dell
 */

#ifndef OS_OS_INIT_H_
#define OS_OS_INIT_H_
#include"OS_Types.h"

void OS_Init(void);

void OS_Create_Task(Task_Config *Ptr_to_task);
void Schedular_Start(void);

void OS_Start(void);

#endif /* OS_OS_INIT_H_ */
