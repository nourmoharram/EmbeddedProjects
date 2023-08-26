/*
 * LM35_Program.c
 *
 *  Created on: Mar 3, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"ADC_CONFIG.h"
#include"ADC/ADC_Init.h"
#include"LM35_Init.h"

extern const ADC_ConfigType ArrayofADC_Config_1[1];

void H_Temprature_void_Init(void)
{
	ADC_Init(ArrayofADC_Config_1);
}

u16 H_Temprature_u16_Read(void)
{
	u16 Temp_value;
	u16 return_value;
	return_value= ADC_getDigitalValueSynchNonBlocking(ArrayofADC_Config_1);
	Temp_value=((return_value*5)/10);

	return Temp_value;
}

//ADC=500    600 700

