/*
 * APP.c
 *
 *  Created on: Mar 4, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"PORT/Port_int.h"
#include"DIO/Dio_int.h"
#include"LED/LED_Init.h"
#include"ULTRA_SONIC/UtraSonic_init.h"
#include"KPD/KPD_Init.h"
#include"CLCD/CLCD_Init.h"
#include"TIMER/TIMER_Types.h"
#include"TIMER/TIMER_Init.h"
#include"GIE/GIE_Interface.h"

static u8 Timer_flag=0;

extern const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE];
const u8 Original_Pass[4]={'1','2','3','4'};
void Delay(void);
u8 Password_validate(void);

u8 Start_Process(void);
/*function initialize the required peripherals and H/W devices*/
void APPLICATION_Init(void)
{
	Port_Init(PORT_Config_Arr);
	H_LCD_void_Init();
	Ultrasonic_init();
	M_void_setCallBack(Normal_Mode,Delay);
	M_void_Timer_Init(Normal_Mode,Normal_Port);
	M_void_EnableTIMERInt(Normal_Mode);
	GIE_voidEnable();
}

void APPLICATION_Start(void)
{

	u16 Detected_range=0;

	while(Detected_range<=15)
	{
		Detected_range = Ultrasonic_readDistance();
		if(Detected_range>0 && Detected_range <=15)
		{
			H_LCD_void_sendString("The Range is:");
			//H_LCD_void_gotoXY(2,0);
			H_LCD_void_sendIntNum(Detected_range);
			M_TIMER0_setDelayTimeMilliSec(3,Normal_Mode,CLK_1024);
			while(Timer_flag==0);
			Timer_flag=0;
			H_LCD_void_ClearDisplay();

			/*Display Authentication message*/
			H_LCD_void_sendString("Welcome to");
			H_LCD_void_gotoXY(2,0);
			H_LCD_void_sendString("Login System");
			M_TIMER0_setDelayTimeMilliSec(3,Normal_Mode,CLK_1024);
			while(Timer_flag==0);
			Timer_flag=0;
			H_LCD_void_ClearDisplay();
			Password_validate();
			Start_Process();
		}
	}

}
u8 Start_Process(void)
{
	u8 Local_return_value=0;
	u8 Led_command_flag=0;
	u8 Led_command=0;
	H_LCD_void_ClearDisplay();
	H_LCD_void_sendString("Welcome");
	H_LCD_void_gotoXY(2,0);
	H_LCD_void_sendString("Nour");
	M_TIMER0_setDelayTimeMilliSec(2,Normal_Mode,CLK_1024);
	while(Timer_flag==0);
	Timer_flag=0;

	while(Led_command_flag==0)
	{
		H_LCD_void_ClearDisplay();

		M_Dio_void_setPinValue(DIO_PA0,DIO_HIGH);
		H_LCD_void_ClearDisplay();
		H_LCD_void_sendString("1-Led On");
		H_LCD_void_gotoXY(2,0);
		H_LCD_void_sendString("2-Led Off");
		M_TIMER0_setDelayTimeMilliSec(1,Normal_Mode,CLK_1024);
		while(Timer_flag==0);
		Timer_flag=0;
		do{
			Led_command=H_KEYPAD_u8_getPressedKey();
		   }while(Led_command=='\0');
		if(Led_command=='1')
		{
			H_LED_void_Turn_on(LED_RED);
			H_LED_void_Turn_on(LED_GREEN);
			H_LED_void_Turn_on(LED_BLUE);
		}
		else if(Led_command=='2')
		{
			H_LED_void_Turn_off(LED_RED);
			H_LED_void_Turn_off(LED_GREEN);
			H_LED_void_Turn_off(LED_BLUE);
		}
		else
		{
			M_Dio_void_setPinValue(DIO_PA0,DIO_LOW);
			H_LCD_void_ClearDisplay();
			Led_command_flag=1;
			break;
		}
		H_LCD_void_ClearDisplay();
		H_LCD_void_sendString("To exit");
		H_LCD_void_gotoXY(2,0);
		H_LCD_void_sendString("Press any button");
	}
	return Local_return_value;
}
u8 Password_validate(void)
{
	u8 Number_of_trials=3;
	u8 Password_flag=0;
	u8 KPD_flag=0;
	u8 Pass[4]={0};
	u8 i=0;
	u8 Compare_flag=0;
	while(Password_flag<Number_of_trials)
	{
		/*ASK user to enter password*/
		H_LCD_void_ClearDisplay();
		H_LCD_void_sendString("Enter Password");
		H_LCD_void_gotoXY(2,0);
		H_LCD_void_sendData(':');
		while(KPD_flag<4)
		{
		 do{
			Pass[i]=H_KEYPAD_u8_getPressedKey();
			}while(Pass[i]=='\0');
		 H_LCD_void_sendData(Pass[i]);
			i++;
			KPD_flag++;
		}
		M_TIMER0_setDelayTimeMilliSec(1,Normal_Mode,CLK_1024);
		while(Timer_flag==0);
		Timer_flag=0;
		H_LCD_void_ClearDisplay();
		H_LCD_void_sendString("Checking");
		H_LCD_void_gotoXY(2,0);
		H_LCD_void_sendString("Password...");
		M_TIMER0_setDelayTimeMilliSec(3,Normal_Mode,CLK_1024);
		while(Timer_flag==0);
		Timer_flag=0;
		for(i=0;i<4;i++)
		{
			if(Pass[i]==Original_Pass[i])
			{
				i++;
			}
			else
			{
				Compare_flag++;
			}
		}
		if(Compare_flag==0)
		{
			break;
			//return Password_flag;
		}
		else if(Compare_flag !=0)
		{
			Password_flag++;
			if(Password_flag==3)
			{
				H_LCD_void_ClearDisplay();
				H_LCD_void_sendString("System Locked");
				M_TIMER0_setDelayTimeMilliSec(120,Normal_Mode,CLK_1024);
				while(Timer_flag==0);
				Timer_flag=0;
				Password_flag=0;
				Compare_flag=0;
				KPD_flag=0;
				i=0;
			}
			else
			{
				H_LCD_void_ClearDisplay();
				H_LCD_void_sendString("Wrong Password");
				H_LCD_void_gotoXY(2,0);
				H_LCD_void_sendString("Pls.Try Again");
				M_TIMER0_setDelayTimeMilliSec(2,Normal_Mode,CLK_1024);
				while(Timer_flag==0);
				Timer_flag=0;
				Compare_flag=0;
				KPD_flag=0;
				i=0;
			}

		}
	}
	return Password_flag;
}
void Delay(void)
{
	M_void_Timer_stop();
	Timer_flag=1;
}
