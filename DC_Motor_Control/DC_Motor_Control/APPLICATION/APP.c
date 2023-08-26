/*
 * APP.c
 *
 *  Created on: Mar 6, 2023
 *      Author: Dell
 */
#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include"PORT/Port_int.h"
#include"DIO/Dio_int.h"
#include"DC_MOTOR/DC_MOTOR_Types.h"
#include"DC_MOTOR/DC_MOTOR_Init.h"
#include"CLCD_CFG.h"
#include"CLCD/CLCD_Init.h"
#include"KPD_CFG.h"
#include"KPD/KPD_Init.h"
#include"APP.h"
#include<util/delay.h>

extern const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE];


void APPLICATION_Init(void)
{
	Port_Init(PORT_Config_Arr);
	H_LCD_void_Init();

}
/*
void APPLICATION_Start(void)
{

	u8 Command='\0';
	if(APP_FLAG==0)
	{
		H_LCD_void_ClearDisplay();
		H_LCD_void_sendString("To Restart");
		H_LCD_void_gotoXY(2,0);
		H_LCD_void_sendString("Enter 5");
		H_LCD_void_gotoXY(3,0);
		H_LCD_void_sendString("To Exit");
		H_LCD_void_gotoXY(4,0);
		H_LCD_void_sendString("Enter 0");
		do
		{
			Command=H_KEYPAD_u8_getPressedKey();

		}while((Command!='5' || Command != '0') && (Command =='\0'));
		H_LCD_void_sendData(Command);
		if(Command=='5')
		{
			APPLICATION_Core();
		}
		else if(Command=='0')
		{
			APPLICATION_Stop();
		}
	}
	else if(APP_FLAG==1)
	{
		H_LCD_void_ClearDisplay();
		H_LCD_void_sendString("To Start");
		H_LCD_void_gotoXY(2,0);
		H_LCD_void_sendString("Enter 1");
		do
		{
			Command=H_KEYPAD_u8_getPressedKey();

		}while(Command !='1');
		H_LCD_void_sendData(Command);
		APPLICATION_Core();
	}
}
	*/

void APPLICATION_Core(void)
{
	 u8 Duty_Cycle=0;
	 u8 Direction=0;
	 u32 PWM_FREQ=0;


	H_LCD_void_ClearDisplay();
	u8 Pressed_key='\0';
	u8 Pressed_key_int=0;
	/*Select Duty cycle*/
	H_LCD_void_sendString("Please Enter");
	H_LCD_void_gotoXY(2,0);
	H_LCD_void_sendString("The Duty Cycle");
	_delay_ms(200);
	H_LCD_void_ClearDisplay();
	H_LCD_void_sendString("Duty Cycle:");
	H_LCD_void_gotoXY(2,0);
	Duty_Cycle=0;
	do
	{
		Pressed_key=H_KEYPAD_u8_getPressedKey();
		if(Pressed_key != '\0' && Pressed_key != '=')
		{
			H_LCD_void_sendData(Pressed_key);
			Pressed_key_int= Pressed_key -'0';
			Duty_Cycle=Duty_Cycle*10+Pressed_key_int;
		}
	}while(Pressed_key != '=');
	Pressed_key='\0';
	Pressed_key_int=0;
	_delay_ms(200);
//	H_LCD_void_ClearDisplay();
	//H_LCD_void_sendIntNum(Duty_Cycle);
	//_delay_ms(3000);

	H_LCD_void_ClearDisplay();
	/*Select the frequency*/
	H_LCD_void_sendString("Please Enter");
	H_LCD_void_gotoXY(2,0);
	H_LCD_void_sendString("The Frequency");
	_delay_ms(200);
	H_LCD_void_ClearDisplay();
	H_LCD_void_sendString("Frequency:");
	H_LCD_void_gotoXY(2,0);
	PWM_FREQ=0;
	do
	{
		Pressed_key=H_KEYPAD_u8_getPressedKey();
		if(Pressed_key != '\0' && Pressed_key != '=')
		{
			H_LCD_void_sendData(Pressed_key);
			Pressed_key_int= Pressed_key -'0';
			PWM_FREQ=PWM_FREQ*10+Pressed_key_int;
		}
	}while(Pressed_key != '=');

	_delay_ms(200);
	Pressed_key='\0';
	Pressed_key_int=0;
	//H_LCD_void_ClearDisplay();
//	H_LCD_void_sendIntNum(PWM_FREQ);
	//_delay_ms(3000);

	H_LCD_void_ClearDisplay();
	/*Select Direction*/
	H_LCD_void_sendString("Select Direction");
	H_LCD_void_gotoXY(2,0);
	H_LCD_void_sendString("Of rotation");
	_delay_ms(200);
	H_LCD_void_ClearDisplay();
	H_LCD_void_sendString("Forward...1");
	H_LCD_void_gotoXY(2,0);
	H_LCD_void_sendString("Reverse...2");
	H_LCD_void_gotoXY(3,0);
	Direction=0;
	do
	{
		Pressed_key=H_KEYPAD_u8_getPressedKey();
		if(Pressed_key != '\0' && Pressed_key != '=')
		{
			H_LCD_void_sendData(Pressed_key);
			Pressed_key_int= Pressed_key -'0';
			Direction=Pressed_key_int;
		}

	}while(Pressed_key != '=');

	_delay_ms(200);
	Pressed_key='\0';
	Pressed_key_int=0;
//	H_LCD_void_ClearDisplay();
	//H_LCD_void_sendIntNum(Duty_Cycle);
//	H_LCD_void_ClearDisplay();
	//H_DC_MOTOR_START(0,0,Direction);

	/*Represent Collected data*/
	H_LCD_void_ClearDisplay();
	H_LCD_void_sendString("Duty=");
	H_LCD_void_gotoXY(1,6);
	H_LCD_void_sendIntNum(Duty_Cycle);
	H_LCD_void_gotoXY(2,0);
	H_LCD_void_sendString("Freq=");
	H_LCD_void_gotoXY(2,6);
	H_LCD_void_sendIntNum(PWM_FREQ);
	H_LCD_void_gotoXY(3,0);
	H_LCD_void_sendString("DIR=");
	H_LCD_void_gotoXY(3,6);
	H_LCD_void_sendIntNum(Direction);

	H_DC_MOTOR_START(PWM_FREQ,Duty_Cycle,Direction);

	H_LCD_void_ClearDisplay();
	_delay_ms(500);
}

void APPLICATION_Stop(void)
{
	H_LCD_void_ClearDisplay();
	H_LCD_void_sendString("APPLICATION");
	H_LCD_void_gotoXY(2,0);
	H_LCD_void_sendString("Stopped!");
	H_DC_MOTOR_START(0,0,0);
	M_Dio_void_setPinValue(DIO_PB3,DIO_LOW);
	H_DC_MOTOR_STOP();
}
