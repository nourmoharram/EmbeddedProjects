/*
 * UltraSonic_prog.c
 *
 *  Created on: Mar 1, 2023
 *      Author: LENOVO
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO/Dio_int.h"
#include"TIMER1/TIMER_1_Init.h"
#include"TIMER_1_CONFIG.h"
#include"UtraSonic_init.h"
#include<util/delay.h>

volatile static u8 Edge_Count = 0;
volatile static u16 Echo_time = 0;
void Ultrasonic_init(void)
{
	ICU_ConfigType ICU_CFG1= {TIMER1_CLK_8,ICU_RISING};
	ICU_Init(&ICU_CFG1);

	ICU_Set_CallBack(Ultrasonic_edgeProcessing);

	//set trigger pin to output
}
void Ultra_Sonic_Trigger(void)
{
	/*send trigger pulse for Ultrasonic pin D0*/
	M_Dio_void_setPinValue(DIO_PD0,DIO_HIGH);
	_delay_us(10);
	M_Dio_void_setPinValue(DIO_PD0,DIO_LOW);
}
u16 Ultrasonic_readDistance(void)
{
	Ultra_Sonic_Trigger();

	//return (0.017*Echo_time);
	return (0.0085*Echo_time);
}

void Ultrasonic_edgeProcessing(void)
{
	Edge_Count++;
	if(Edge_Count==1)
	{
		ICU_Clear_timer_value();

		ICU_Set_Edge_detection(ICU_FALLING);
	}
	else if(Edge_Count==2)
	{
		Echo_time=ICU_Get_Captured_value();

		ICU_Set_Edge_detection(ICU_RISING);

		Edge_Count=0;
	}
}

