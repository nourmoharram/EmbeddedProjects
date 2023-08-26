/*
 * APP.c
 *
 *  Created on: Mar 6, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"PORT/Port_int.h"
#include"LM_35_Sensor/LM35_Init.h"
#include"CLCD/CLCD_Init.h"
#include"DC_MOTOR/DC_MOTOR_Types.h"
#include"DC_MOTOR/DC_MOTOR_Init.h"
#include<util/delay.h>


extern const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE];

void APP_Init(void)
{
	Port_Init(PORT_Config_Arr);
	H_LCD_void_Init();
	H_Temprature_void_Init();
}

void APP_Start(void)
{
	u16 Temp_value=0;
	Temp_value=H_Temprature_u16_Read();
	if(Temp_value<25)
	{
		H_LCD_void_ClearDisplay();
		H_LCD_void_sendString("Temperature:");
		H_LCD_void_sendIntNum(Temp_value);
		H_DC_MOTOR_STOP();
		H_LCD_void_gotoXY(2,0);
		H_LCD_void_sendString("Fan OFF");
	}
	else if(Temp_value>25 && Temp_value <35)
	{
		H_LCD_void_ClearDisplay();
		H_LCD_void_sendString("Temperature:");
		H_LCD_void_sendIntNum(Temp_value);
		H_DC_MOTOR_START(500,50,FORWARD_DIRECTION);
		H_LCD_void_gotoXY(2,0);
		H_LCD_void_sendString("FAN ON:DUTY 50%");
	}
	else if(Temp_value>35)
	{
		H_LCD_void_ClearDisplay();
		H_LCD_void_sendString("Temperature:");
		H_LCD_void_sendIntNum(Temp_value);
		H_DC_MOTOR_START(100,80,FORWARD_DIRECTION);
		H_LCD_void_gotoXY(2,0);
		H_LCD_void_sendString("FAN ON:DUTY 80%");
	}

}

