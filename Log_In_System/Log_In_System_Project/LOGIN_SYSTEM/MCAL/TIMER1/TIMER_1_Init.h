/*
 * TIMER_1_Init.h
 *
 *  Created on: Mar 2, 2023
 *      Author: Dell
 */

#ifndef MCAL_TIMER1_TIMER_1_INIT_H_
#define MCAL_TIMER1_TIMER_1_INIT_H_

#include"TIMER_1_Types.h"
typedef struct
{
	TIMER1_PRESCALER Pre_scaller;
	ICU_Trigger Trigger_edge;
}ICU_ConfigType;

/*used to initialize time1 to use ICU*/
void ICU_Init(const ICU_ConfigType *Ptr_Config);

/*used to set the required edge for capture*/
void ICU_Set_Edge_detection(const ICU_Trigger EDGE_TYPE);
/*get the capture value*/
u16 ICU_Get_Captured_value(void);
/*Clear timer1 value to start count from zero*/
void ICU_Clear_timer_value(void);
/*function to disable timer1 to stop icu*/
void ICU_Disable(void);
/*SET Call back function*/
void ICU_Set_CallBack(void (*ptr_to_func)(void));

#endif /* MCAL_TIMER1_TIMER_1_INIT_H_ */
