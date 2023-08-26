/*
 * Motor_prg.c
 *
 * Created: 3/4/2023 1:34:10 AM
 *  Author: ahmed57
 */ 
#include "Motor_int.h"
#include "Motor_cfg.h"
#include "BIT_MATH.h"
#include "TIMER0_int.h"
#include "Dio_int.h"

#define MOTOR_FREQUENCY		15600
void MOTOR_Enable();

void MOTOR_ON(MOTOR_DIR MorotDirection, u8 DutyCycle)
{
	M_vTIMER0_SetPhaseCorrectPWM( MOTOR_FREQUENCY , DutyCycle , TIMER0_PWM_PHASECORRECT_NonInverted_MODE);
	M_Dio_void_setPinValue(MOTOR_EN_PIN, 1);
	M_Dio_void_setPinValue(MOTOR_DIR_PIN, MorotDirection);
	
}

void MOTOR_OFF()
{
	M_Dio_void_setPinValue(MOTOR_EN_PIN, 0);
}
