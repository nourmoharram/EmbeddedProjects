/*
 * main.c
 *
 *  Created on: Mar 16, 2023
 *      Author: LENOVO
 */
//#include <avr/delay.h>
//#include "Port_int.h"
//#include "CLCD_CFG.h"
//#include "CLCD_Init.h"
//#include "KPD_Init.h"
//#include "RTC_Init.h"
//#include "RTC_cfg.h"
#include "APP_init.h"
//#include "EEPROM_init.h"

void main()
{
	APP_INIT();



	while(1)
	{
		APP_Start();
	}

}

/*
 	u8 KeyPad_Value = 0 ;
	u8 User_Status = 0 ;
	APP_WelcomeDisplay();
	H_LCD_void_gotoXY(2, 0);
	H_LCD_void_sendString("Choose Option:");
	H_LCD_void_gotoXY(3, 0);
	H_LCD_void_sendString("1-SignIn | 2-SingUp");

	do{
		KeyPad_Value = H_KEYPAD_u8_getPressedKey();
	  }while(KeyPad_Value == NO_PRESSED_KEY);

	if(KeyPad_Value == '2')
	{
		User_Authentication_SignUp();
	}
	else if(KeyPad_Value == '1')
	{
		User_Status = User_Authentication_SignIn();

	}

	if (User_Status == VALID_LOGIN)
	{
		H_LCD_void_sendString("VALID_LOGIN");
	}



 * */

