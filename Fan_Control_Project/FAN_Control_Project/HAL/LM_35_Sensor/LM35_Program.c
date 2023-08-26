/*
 * LM35_Program.c
 *
 *  Created on: Mar 3, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"PORT/Port_int.h"
#include"CLCD/CLCD_Init.h"
#include"ADC_CONFIG.h"
#include"ADC/ADC_Init.h"
#include"LM35_Init.h"
#include"GIE/GIE_Interface.h"
#include<util/delay.h>



ADC_ConfigType ADC_OBJECT={VCC_5V,DIV_BY_8,Right_Adjust,ADC0,AUTO_Trigger_Enable,Free_Runnin_Mode};
void H_Temprature_void_Init(void)
{
	ADC_Init(&ADC_OBJECT);


}
u16 H_Temprature_u16_Read(void)
{
	u16 Return_value=0;
	u16 Temp_value=0;
	Return_value=ADC_getDigitalValueSynchNonBlocking(ADC0,ENABLE);
	Temp_value=(((Return_value*5)/10)-1);
	return Temp_value;
}
