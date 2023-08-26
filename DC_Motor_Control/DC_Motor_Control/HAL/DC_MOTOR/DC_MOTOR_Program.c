/*
 * DC_MOTOR_Program.c
 *
 *  Created on: Mar 5, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"TIMER_CONFIG.h"
#include"TIMER/TIMER_Types.h"
#include"TIMER/TIMER_Init.h"
#include"DIO/Dio_int.h"
#include"DC_MOTOR_Private.h"
#include"DC_MOTOR_Types.h"
#include"DC_MOTOR_Init.h"

void H_DC_MOTOR_START(u32 PWM_FREQ,u8 DUTY_CYCLE,DC_M_DIR MOTOR_DIRECTION)
{
	M_void_Timer_Init(Phase_Correct_PWM,Non_Invering_Mode);

	M_TIMER0_PHASE_PWM_SET(Non_Invering_Mode,PWM_FREQ,DUTY_CYCLE);
	switch(MOTOR_DIRECTION)
	{
	case FORWARD_DIRECTION:
		M_Dio_void_setPinValue(DIO_PD0,DIO_HIGH);
		M_Dio_void_setPinValue(DIO_PD1,DIO_LOW);
		break;
	case BACKWARD_DIRECTION:
		M_Dio_void_setPinValue(DIO_PD0,DIO_LOW);
		M_Dio_void_setPinValue(DIO_PD1,DIO_HIGH);
		break;
	default:
		break;
	}
}
void H_DC_MOTOR_STOP(void)
{
	M_void_Timer_Init(Phase_Correct_PWM,Normal_Port);
	M_void_Timer_stop();
}

