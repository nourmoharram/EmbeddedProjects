/*
 * Motor_int.h
 *
 * Created: 3/4/2023 1:34:30 AM
 *  Author: ahmed57
 */ 


#ifndef MOTOR_INT_H_
#define MOTOR_INT_H_

#include "Motor_types.h"
#include "STD_TYPES.h"

void MOTOR_Enable();
void MOTOR_ON(MOTOR_DIR MorotDirection, u8 DutyCycle);
void MOTOR_OFF();



#endif /* MOTOR_INT_H_ */