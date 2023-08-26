/*
 * OS_CONFIG.h
 *
 *  Created on: Mar 5, 2023
 *      Author: Dell
 */

#ifndef CONFIG_OS_CONFIG_H_
#define CONFIG_OS_CONFIG_H_
#include"OS_Types.h"
typedef struct
{
	Periodicity Task_Periodicty;
	Priority    Task_Priority;
	void (*ptrToFunc)(void);
}Task_Config;

#endif /* CONFIG_OS_CONFIG_H_ */
