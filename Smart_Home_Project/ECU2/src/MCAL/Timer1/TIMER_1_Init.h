/*
 * TIMER_1_Init.h
 *
 *  Created on: Mar 2, 2023
 *      Author: Dell
 */

#ifndef MCAL_TIMER1_TIMER_1_INIT_H_
#define MCAL_TIMER1_TIMER_1_INIT_H_

#include "TIMER_1_Types.h"

void M_TIMER1_void_Init(TIMER_1_MD Local_Mode,TIMER_1_WG Local_WG);

void M_TIMER1_void_Start(TIMER1_PRESCALER Local_Prescaller);

void M_TIMER1_void_FastPWM(u16 Duty_Cycle);
void M_TIMER1_void_Stop(void);
void M_TIMER1_void_ICU_Enable(void);

void M_TIMER1_void_ICU_TriggerSelect(ICU_Trigger Local_Trigger);

void M_TIMER1_void_ICU_INTERRUPTDIS(void);

u16 M_TIMER1_void_ICU_Reading(void);

void M_TIMER1_void_ICU_SetCallBack(void);

u8 M_TIMER1_u8_Reset_flag(TIMER1_INTERRUPT_TYPE Local_type);
#endif /* MCAL_TIMER1_TIMER_1_INIT_H_ */
