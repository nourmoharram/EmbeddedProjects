/*
 * DC_MOTOR_Init.h
 *
 *  Created on: Mar 5, 2023
 *      Author: Dell
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_INIT_H_
#define HAL_DC_MOTOR_DC_MOTOR_INIT_H_
#include"TIMER_CONFIG.h"
void H_DC_MOTOR_START(u32 PWM_FREQ,u8 DUTY_CYCLE,DC_M_DIR MOTOR_DIRECTION);

void H_DC_MOTOR_STOP(void);

#endif /* HAL_DC_MOTOR_DC_MOTOR_INIT_H_ */
