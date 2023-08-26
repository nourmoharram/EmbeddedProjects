/*
 * main.c
 *
 *  Created on:
 *      Author:Nour alaa eldin
 */
#include"STD_TYPES.h"
#include"CLCD/CLCD_Init.h"
#include"KPD/KPD_Init.h"
#include"APP.h"
static u8 APP_FLAG=1;

int main(void)
{
	APPLICATION_Init();

	while(1)
	{


		u8 Command='\0';
		while(APP_FLAG==1)
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
			APP_FLAG=0;
		}
		while(APP_FLAG==0)
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
				APP_FLAG=1;
			}
			else if(Command=='0')
			{
				APPLICATION_Stop();
				APP_FLAG=1;
			}
		}


	}

}
