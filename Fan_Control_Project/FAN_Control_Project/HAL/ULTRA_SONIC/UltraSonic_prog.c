/*
 * UltraSonic_prog.c
 *
 *  Created on: Mar 1, 2023
 *      Author: LENOVO
 */

#include "avr/delay.h"
#include "Mcu_HW.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO/Dio_int.h"
#include"TIMER1/TIMER_1_Types.h"
#include"TIMER1/TIMER_1_Init.h"
#include"CLCD/CLCD_Init.h"
#include"ULTRA_SONIC/UtraSonic_priv.h"
#include"ULTRA_SONIC_CONFIG.h"
#include"ULTRA_SONIC/UtraSonic_types.h"
#include"ULTRA_SONIC/UtraSonic_init.h"
#include<util/delay.h>


static volatile u16 Reading_1=0;
static volatile u16 Reading_2=0;
static volatile u16 Reading_3=0;
static volatile u16 Distance=0;
static volatile u8 No_of_overflows=0;

void H_UltraSonic_Void_Init()
{
	H_LCD_void_Init();

	M_TIMER1_void_Init(TIMER_1_NM,TIMER_1_NWG);
	M_TIMER1_void_Start(TIMER1_CLK_8);
	/*Trigger the ULTRA SONIC*/
	M_Dio_void_setPinValue(TRIGGER_PIN_OUT,DIO_HIGH);
	_delay_us(10);
	M_Dio_void_setPinValue(TRIGGER_PIN_OUT,DIO_LOW);

}
void H_ULTRASONIC_Get_Readings(void)
{
	M_TIMER1_void_ICU_Enable();
	while((GET_BIT(TIFR,TIFR_ICF1))==0);
	M_TIMER1_u8_Reset_flag(TIMER1_ICU);
	Reading_1 = M_TIMER1_void_ICU_Reading();
	M_TIMER1_void_ICU_TriggerSelect(ICU_FALLING);

	while((GET_BIT(TIFR,TIFR_TOV1))==1)
	{
		No_of_overflows++;
		M_TIMER1_u8_Reset_flag(TIMER1_OVF);
	}
	while((GET_BIT(TIFR,TIFR_ICF1))==0);
	M_TIMER1_u8_Reset_flag(TIMER1_ICU);
	Reading_2= M_TIMER1_void_ICU_Reading();
	M_TIMER1_void_ICU_TriggerSelect(ICU_RISING);



}
u16 H_UltraSonic_U16_ReadDistance()
{
	H_LCD_void_gotoXY(1,0);
	H_LCD_void_sendIntNum(No_of_overflows);
	H_LCD_void_gotoXY(1,6);
	H_LCD_void_sendIntNum(Reading_1);
	H_LCD_void_gotoXY(2,0);
	H_LCD_void_sendIntNum(Reading_2);

	u32 time=0;
	if(No_of_overflows>0)
	{
		time = (65535-Reading_1);
		No_of_overflows--;
		time += ((u32)No_of_overflows*65535);
		time += Reading_2;
	}
	else
	{
		time = Reading_2-Reading_1;
	}
	Reading_3= time /2;
	Distance = ((f32)SPEED_OF_SOUND/1000000)*(Reading_3);
	H_LCD_void_gotoXY(2,6);
	H_LCD_void_sendIntNum(Distance);
	M_TIMER1_void_Stop();

	return Distance;
}

