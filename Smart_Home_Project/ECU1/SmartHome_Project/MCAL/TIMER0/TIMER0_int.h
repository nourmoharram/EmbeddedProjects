/*
* * TIMER0_int.h
 *
 *  Created on: Feb 24, 2023
 *      Author: LENOVO
 */

#ifndef TIMER0_TIMER0_INT_H_
#define TIMER0_TIMER0_INT_H_

#include "STD_TYPES.h"
#include "TIMER0_types.h"


void M_TIMER0_Void_Init(TIMER0_MODE_TYPE Local_Mode,TIMER0_WG_TYPE Local_WG_Type);
void M_TIMER0_Void_Start(TIMER0_PRESCALLER_SELECT Local_PrescallerSelect);
void M_TIMER0_Void_Stop();
u8 M_TIMER0_Void_GetCount(TIMER0_MODE_TYPE Local_Mode);

void M_TIMER0_setDelayTimeMilliSec(u32 Local_DelayTime, TIMER0_MODE_TYPE Local_Mode, TIMER0_PRESCALLER_SELECT Local_Prescaller);
void M_TIMER0_EnableInt(TIMER0_INTERRUPT_TYPE Local_InterruptType);
void M_TIMER0_DisableInt();
void M_TIMER0_setCallBack(TIMER0_INTERRUPT_TYPE Local_InterruptType ,void(*Local_CallBackFunc)(void));





#endif /* TIMER0_TIMER0_INT_H_ */
