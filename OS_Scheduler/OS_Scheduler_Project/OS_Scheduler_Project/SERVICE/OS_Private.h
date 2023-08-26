/*
 * OS_Private.h
 *
 *  Created on: Mar 5, 2023
 *      Author: Dell
 */

#ifndef SERVICE_OS_PRIVATE_H_
#define SERVICE_OS_PRIVATE_H_
#include "../SERVICE/OS_Types.h"

#define TICKS                   500
#define NUMBER_OF_TASKS          5
typedef struct
{
	States Task_State;
	u16 Task_Periodicty;
	u16    Task_Priority;
	u16 First_Delay;
	u32 Delay_Time;
	void (*Task_Handler)(void);
}Task_Config;

#endif /* SERVICE_OS_PRIVATE_H_ */
