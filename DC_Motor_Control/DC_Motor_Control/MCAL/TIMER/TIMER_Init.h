/*
 * TIMER_Init.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Dell
 */

#ifndef MCAL_TIMER_TIMER_INIT_H_
#define MCAL_TIMER_TIMER_INIT_H_
#include"TIMER_CONFIG.h"

void M_void_Timer_Init(Timer_Mode T_MODE, Comp_Output_Mode WG_M);

void M_void_Timer_start(PRE_SCALLER Pre_scaller_select);

void M_void_Timer_stop(void);

u8 Timer_u8__GetCounts(void);

void M_void_Timer_Set_Preload(u8 Pre_load);

void M_TIMER0_setDelayTimeMilliSec(u32 Local_DelayTime, Timer_Mode Local_Mode, PRE_SCALLER Local_Prescaller);

void M_TIMER0_FAST_PWM_SET(Comp_Output_Mode PWM_TYPE,FAST_PWM_FREQ PWM_FREQ,u8 Duty_Cycle);

void M_TIMER0_PHASE_PWM_SET(Comp_Output_Mode PWM_TYPE,u32 PWM_FREQ, u8 Duty_Cyle);

void M_void_EnableTIMERInt(Timer_Mode T_MODE);

void M_void_DisableTIMERInt(Timer_Mode T_MODE);

void M_void_setCallBack(Timer_Mode T_MODE,void (*Copy_pvINTFunc)(void));


#endif /* MCAL_TIMER_TIMER_INIT_H_ */
