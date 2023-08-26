/*
 * main.c
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */
#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include"Port_int.h"
#include"LED_Init.h"
#include"CLCD_Init.h"
#include"Buzzer_Int.h"
#include"LM35_Init.h"
#include"Relay_Int.h"
#include "OS_Init.h"
#include "OS_Types.h"
#include"Dio_int.h"
#include<util/delay.h>

extern const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE];

/*
 * Task1 LCD periodcity 260msec
 * task2 bazzer periodcity 1000msec
 * task3 ledstring periodicity 20 msec
 * task 4 relay with prediocity 600 msec
 * */



void Task_1(void);
void Task_2(void);
void Task_3(void);
void Task_4(void);
void Task_5(void
/*typedef struct
{
	States Task_State;
	u16 Task_Periodicty;
	u16    Task_Priority;
	u16 First_Delay;
	u32 Delay_Time;
	void (*Task_Handler)(void);
}Task_Config;
*/
Task_Config Task1 ={Ready,13,1,1,0,Task_1}; //lcd 260ms = 13 * 20 ms "Tick time"
Task_Config Task2 ={Ready,50,2,50,0,Task_2}; //buzzer 1000ms
Task_Config Task3 ={Ready,30,3,1,0,Task_3}; //led 600 ms
Task_Config Task4 ={Ready,40,4,1,0,Task_4}; //relay  800 ms
Task_Config Task5 ={Ready,100,5,1,0,Task_5}; //temp  2000ms
int main(void)
{

	Port_Init(PORT_Config_Arr);
	H_LCD_void_Init();
	H_Temprature_void_Init();


	OS_Init();
	OS_Create_Task(&Task1);
	OS_Create_Task(&Task2);
	OS_Create_Task(&Task3);
	OS_Create_Task(&Task4);
	OS_Create_Task(&Task5);
	OS_Start();


	while(1)
	{


	}
}

void Task_1(void)
{
	static u8 x=1;
	static u8 y=0;
	H_LCD_void_gotoXY(x,y);
	H_LCD_void_sendString("Nour");
	y+=4;
	if(y>19)
	{
		x++;
		y=0;
		if(x==4)
		{
			x=1;
			y=0;
			H_LCD_void_ClearDisplay();

		}
	}
}
void Task_2(void)
{
	static u8 i=0;
	i++;
	if(i==10)
	{
		M_Dio_void_togglePinValue(DIO_PB5);
		i=0;
	}
	//ENABLE
	M_Dio_void_setPinValue(DIO_PB6,DIO_HIGH);

	M_Dio_void_setPinValue(DIO_PB3,DIO_HIGH);
	H_BUZZER_Void_TurnOn();
	_delay_ms(10);
	H_BUZZER_Void_TurnOn();
}
void Task_3(void)
{

	H_LED_void_Toggle(LED_BLUE);
	H_LED_void_Toggle(LED_GREEN);
	H_LED_void_Toggle(LED_YELLOW);


}
void Task_4(void)
{
	static u8 Flag_Relay=0;
	static u8 counter=0;
	if(Flag_Relay==1)
	{
		H_Relay_Void_WorkOff(Relay_1);
		H_Relay_Void_WorkOn(Relay_2);
		counter++;
		if(counter==5)
		{
			Flag_Relay=0;
			counter=0;

		}
	}
	if(Flag_Relay==0)
	{
		H_Relay_Void_WorkOn(Relay_1);
		H_Relay_Void_WorkOff(Relay_2);
		counter++;
		if(counter==5)
		{
			Flag_Relay=1;
			counter=0;

		}

	}
}
void Task_5(void)
{
	 u16 Temp_value;
	Temp_value=H_Temprature_u16_Read();
	Temp_value/=19;
	H_LCD_void_gotoXY(4,0);
	H_LCD_void_sendString("Temperature:");
	H_LCD_void_sendIntNum(Temp_value);

}
