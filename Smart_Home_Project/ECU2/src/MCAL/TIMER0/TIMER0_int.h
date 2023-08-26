/*
 * TIMER0_int.h
 *
 *  Created on: Feb 25, 2023
 *      Author: ahmed57
 */

#ifndef TIMER0_TIMER0_INT_H_
#define TIMER0_TIMER0_INT_H_

#include "TIMER0_cfg.h"
#include "TIMER0_types.h"

/* Function Prototypes  */

void M_vTIMER0_Init(TIMER0_MODES_t TIMER0_MODE, u8 OC0_MODE);
void M_vTIMER0_Start(TIMER0_Prescaler_t	CLK_Src_Prescaler);
void M_vTIMER0_Stop(void);
void M_vTIMER0_GetCounts(void);
u32  M_vTIMER0_SetDelayTimeMilliSec(u32 millisec , TIMER0_Prescaler_t  Prescaler, TIMER0_MODES_t MODE);
void M_vTIMER0_EnableInt(TIMER0_INT_TYPES_t  TIMER0_INT);
void M_vTIMER0_DisableInt(TIMER0_INT_TYPES_t  TIMER0_INT);
void M_vTIMER0_SetCallBack(void(*PtrFun)(void), TIMER0_INT_TYPES_t INT_ID );
void M_vTIMER0_SetFastPWM(u32 Frequency, u8 Duty_Cycle, TIMER0_PWM_FAST_OC0_MODES_t FAST_PWM_MODE);
void M_vTIMER0_SetPhaseCorrectPWM(u32 Frequency, u8 Duty_Cycle, TIMER0_PWM_PHASECORRECT_OC0_MODES_t PWM_PHASECORRECT_MODE);







#endif /* TIMER0_TIMER0_INT_H_ */
