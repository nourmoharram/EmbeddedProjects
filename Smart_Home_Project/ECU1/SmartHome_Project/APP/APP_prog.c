/*
 * APP_prog.c
 *
 *  Created on: Mar 16, 2023
 *      Author: LENOVO
 */

#include <Avr/delay.h>
#include "STD_TYPES.h"
#include "APP_priv.h"
#include "APP_types.h"
#include "Port_cfg.h"
#include "Port_int.h"
#include "APP_init.h"
#include "CLCD_Init.h"
#include "KPD_Init.h"
#include "EEPROM_init.h"
#include "RTC_Init.h"
#include "Relay_Int.h"
#include "Buzzer_Int.h"
#include "Dio_int.h"
#include "GIE_init.h"
#include "FINGER_PRINT_Init_v2.h"

/**************************************************************************************************************
 *	Global Variables
 *************************************************************************************************************/
const RTC_CONFIG_TIME TimeArr = {1,31,30} ;
extern const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE];
u8 Global_PasswordCounter = 0;
u8 Set_TimeArr[3] = {9,55,30};

/**************************************************************************************************************
 *	Application Initlization
 *************************************************************************************************************/
void APP_INIT()
{

	/***
	 * 	Initialize section
	 ****/
	Port_Init(PORT_Config_Arr);
	H_LCD_void_Init();
	H_EEPROM_Void_Init();
	_delay_ms(200);
	H_RTC_Void_Init();
	_delay_ms(200);
	Finger_Print_Init();

	/* Initial value will be Low */
    M_Dio_void_setPinValue(DIO_PA6, DIO_LOW);
    H_LCD_void_sendString("####################");
    H_LCD_void_gotoXY(2, 5);
    H_LCD_void_sendString("WELCOME NTI");
    H_LCD_void_gotoXY(3, 2);
    H_LCD_void_sendString("SMART HOME SYSTEM");
    H_LCD_void_gotoXY(4, 0);
    H_LCD_void_sendString("####################");
    _delay_ms(1000);
}

/**************************************************************************************************************
 *	 Start of Algorithm
 *************************************************************************************************************/
void APP_Start()
{
//	H_RTC_Void_SetTime(Set_TimeArr, RTC_PM);
 	u8 KeyPad_Value = 0 ;
	u8 User_Status = 0 ;
	u8 Temp_Holder = 0 ;
	/*
	 * Starting Display
	 */
	H_LCD_void_ClearDisplay();
	APP_WelcomeDisplay();
	/*
	 * Chose option
	 */
	do{
		KeyPad_Value = H_KEYPAD_u8_getPressedKey();
	  }while(KeyPad_Value == NO_PRESSED_KEY);

		/* Check the options*/
		switch(KeyPad_Value)
		{
		case USER_SIGN_UP:	User_Status = 2 ;User_Authentication_SignUp(); break;
		case USER_SIGN_IN:	User_Status = User_Authentication_SignIn();
							break;
		case USER_REST_ID:  User_Status = USER_REST_ID;
							Rest_Password();
							 _delay_ms(200);
							break;
		default: User_Status = OUT_OF_RANGE; break;
		}

	/*
	 * in case of valid Login
	 */
	H_LCD_void_ClearDisplay();
	if (User_Status == VALID_LOGIN)
	{
		H_LCD_void_sendString("VALID_LOGIN");
		Successful_Authentication();
	}
	else if (User_Status == INVALID_LOGIN)
	{
		/* Loop to re-enter data */
		do
		{
		H_LCD_void_gotoXY(1, 0);
		H_LCD_void_sendString("Invalid Login");
		_delay_ms(1000);
		Temp_Holder = Wrong_Authentication();
		H_LCD_void_ClearDisplay();
		if (Temp_Holder == Pass_Ok)
		{
			H_LCD_void_sendString("VALID_LOGIN");
			_delay_ms(2000);
			Successful_Authentication();
			break;
		}
		/*Check if exceeded number of Trials or not */
		if(Global_PasswordCounter == MAX_TRIALS)
		{
			// System stop for 5 min
				SYSTEM_OFF();
		}

		}while(Global_PasswordCounter != MAX_TRIALS);

		/*Clear Global Passowrd counter */
		Global_PasswordCounter = 0 ;
	}
	/* if user chose rest*/
	else if (User_Status == USER_REST_ID)
	{
		/* Password is rested  */
	}

}



/**************************************************************************************************************
 *				Functions
 *************************************************************************************************************/
LOGIN_STATE User_Authentication_SignIn()
{
	/*
	 * Local Variables
	 */
	u8 checkTemp = 0 ;
	u8 Local_PassWordArr[4] = {0};
	u8 Local_ID = 0 ;
	/*
	 * Scan the finger print
	 * each finger print will have ID
	 */

	Local_ID=Finger_Print_Match();

	/* Check ID*/
	if(Local_ID!=0)	// Correct finger print
	{
		H_LCD_void_ClearDisplay();
		H_LCD_void_sendString("Welcome ");
		H_LCD_void_sendData(Local_ID+'0');
		_delay_ms(2000);
	}
	else	// INCCORECT Finger Print
	{
		H_LCD_void_ClearDisplay();
		H_LCD_void_sendString("No matching Found");
		return INVALID_LOGIN;
	}

	/* Enter Password */
	H_LCD_void_ClearDisplay();
	H_LCD_void_sendString("Enter Password:");
	H_LCD_void_gotoXY(2, 0);
	KeyPad_EnterPassWord(Local_PassWordArr);

	/*Call check password */
	H_LCD_void_ClearDisplay();
	checkTemp = Check_Password(Local_PassWordArr,1);

	/*if return call check password is correct then return valid else return IN VALID */
	if(checkTemp == CORRECT_PASS)
	{
		return VALID_LOGIN;
	}
	else
	{
		return INVALID_LOGIN;
	}
}

void User_Authentication_SignUp()
{
	/*
	 * Local Variables
	 */
	u8 Local_PassWordArr[4] = {0};
	u8 User_ID = 0;
	u8 Local_Counter = 1;
	u8 Temp_Check = 0;
	H_LCD_void_ClearDisplay();
	/* Must Enter a valid Password to continue */
	H_LCD_void_gotoXY(1, 0);
	H_LCD_void_sendString("Singing nUp: ");
	H_LCD_void_gotoXY(2, 0);
	H_LCD_void_sendString("Enter Valid Password ");
	H_LCD_void_gotoXY(3, 1);

	/* Enter Password*/
	KeyPad_EnterPassWord(Local_PassWordArr);

	/* Search for Password*/
	do{
		Temp_Check = Check_Password(Local_PassWordArr, Local_Counter);
		H_LCD_void_sendString(".");
		_delay_ms(1000);
		if (Temp_Check == CORRECT_PASS)
		{
			Temp_Check = NUMBER_OF_USERS+1 ;
			Local_Counter = 0 ;
			break;
		}
		Local_Counter ++ ;
	}while(Local_Counter <= NUMBER_OF_USERS);

	/* if Password not found exit the function*/
	H_LCD_void_ClearDisplay();
	if (Local_Counter != 0)
	{
		H_LCD_void_sendString("Password Not Found");
		_delay_ms(1000);
		return;
	}


	H_LCD_void_gotoXY(1, 0);
	H_LCD_void_sendString("Adding New User...");
	/* Take the next ID*/
	_delay_ms(1000);
	H_EEPROM_Void_ReadByte(EEPROM_USER_ID, &User_ID);
	_delay_ms(200);

	/*Scan finger print  */
	Finger_Print_Enroll(User_ID);

	H_LCD_void_ClearDisplay();
	H_LCD_void_sendString("Enter Personal Pass: ");

	/*Enter Password */
	H_LCD_void_gotoXY(2, 0);
	KeyPad_EnterPassWord(Local_PassWordArr);

	/*Save to EEPROM*/
	H_LCD_void_ClearDisplay();
	Save_NewPassword(Local_PassWordArr,User_ID);

	/*Saving data animation*/
//	H_LCD_void_sendString("Saving data");
//	Local_Counter = 0;
//	while(Local_Counter != 4)
//	{
//		H_LCD_void_sendString(".");
//		_delay_ms(500);
//		Local_Counter ++ ;
//	}
	H_LCD_void_ClearDisplay();
}

void Successful_Authentication(void)
{
	/*Open Relay and send signal to ECU2 */
    H_Relay_Void_WorkOn(Relay_1);
    M_Dio_void_setPinValue(DIO_PA6, DIO_HIGH);
	H_LCD_void_gotoXY(1,0);
    H_LCD_void_sendString("Welcome to your House");
    H_LCD_void_gotoXY(2,0);
    H_LCD_void_sendString("Last Login was:");
    H_LCD_void_gotoXY(3,0);
    Display_LastLogin();	// Show Last Login
    _delay_ms(3000);
    H_LCD_void_ClearDisplay();
    Time_Processing();
	/* Open door for 5 sec then relay of and DIO PIN low*/
    _delay_ms(5000);
    H_Relay_Void_WorkOff(Relay_1);
    H_LCD_void_ClearDisplay();
    M_Dio_void_setPinValue(DIO_PA6, DIO_LOW);

}

void Time_Processing(void)
{
	u8 Local_Counter = 0;
	u8 Local_AddressCounter = 0;
	u8 DateArray[3] = {H_RTC_Void_GetDate().RTC_Day,H_RTC_Void_GetDate().RTC_Month,H_RTC_Void_GetDate().RTC_Year};
	u8 TimeArry[4] = {H_RTC_Void_GetTime().RTC_Hours,H_RTC_Void_GetTime().RTC_Minutes, H_RTC_Void_GetTime().RTC_Seconed,H_RTC_Void_GetTime().RTC_DayTime};

	/*Display Date */
	H_LCD_void_gotoXY(2, 0);
	H_LCD_void_sendString("Today is: ");
	Local_AddressCounter = DATE_FIRST_ADDRESS ;
	for(Local_Counter = 0; Local_Counter < 3; Local_Counter++)
	{
		H_LCD_void_sendIntNum((u16)DateArray[Local_Counter]);
//		Save the date into the eeprom
		H_EEPROM_Void_WriteByte(Local_AddressCounter, DateArray[Local_Counter]) ;
		H_LCD_void_sendData('/');
		_delay_ms(200);
		Local_AddressCounter ++ ;
	}

	/*Display Time */
	H_LCD_void_gotoXY(3, 0);
	H_LCD_void_sendString("Time is: ");
	Local_AddressCounter = TIME_FIRST_ADDRESS ;
	for(Local_Counter = 0; Local_Counter < 4; Local_Counter++)
	{
		if(Local_Counter != 3)
		{
		H_LCD_void_sendIntNum((u16)TimeArry[Local_Counter]);
		H_LCD_void_sendData(':');
		}
//		Save the date into the eeprom
		H_EEPROM_Void_WriteByte(Local_AddressCounter, TimeArry[Local_Counter]) ;

		_delay_ms(200);
		Local_AddressCounter ++ ;
	}
	/* Check PM/AM */
	if(H_RTC_Void_GetTime().RTC_DayTime == RTC_AM)
	{
		H_LCD_void_sendString(" AM");
	}
	else if(H_RTC_Void_GetTime().RTC_DayTime == RTC_PM)
	{
		H_LCD_void_sendString(" PM");
	}
}

void Display_LastLogin(void)
{
	u8 datat;
	u8 AddressCounter = 0;
	H_LCD_void_gotoXY(3,0);
	_delay_ms(200);

	/* Display Date */
	H_LCD_void_gotoXY(3,0);
	for(AddressCounter = 24; AddressCounter <= 26; AddressCounter++)
	{
		H_EEPROM_Void_ReadByte(AddressCounter, &datat);
		H_LCD_void_sendIntNum((u16)datat);
		H_LCD_void_sendData('/');
		_delay_ms(200);
	}

	/* Display Time */
	H_LCD_void_gotoXY(4,0);
	for(AddressCounter = 20; AddressCounter < 23; AddressCounter++)
	{
		H_EEPROM_Void_ReadByte(AddressCounter, &datat);
		H_LCD_void_sendIntNum((u16)datat);
		H_LCD_void_sendData(':');
		_delay_ms(200);
	}
	H_EEPROM_Void_ReadByte(23, &datat);
	if (datat == RTC_PM)
	{
		H_LCD_void_sendString(" PM");
	}
	else
	{
		H_LCD_void_sendString(" AM");
	}
}

void SYSTEM_OFF(void)
{
	u8 counter = 0 ;
	H_LCD_void_sendString("System Stop");
	H_BUZZER_Void_TurnOn();
	do
	{
		H_BUZZER_Void_TurnOn();
		_delay_ms(250);
		H_BUZZER_Void_TurnOff();
		_delay_ms(250);
		H_BUZZER_Void_TurnOn();
		_delay_ms(800);
		H_BUZZER_Void_TurnOff();
		_delay_ms(250);
		counter ++ ;

	}while (counter != 10);
	H_BUZZER_Void_TurnOff();
//	_delay_ms(5000);
	H_LCD_void_ClearDisplay();
	M_GIE_Void_Disable();
}

Pass_State Wrong_Authentication(void)
{
	Login_State Pass = Pass_Ok;
	u8 Local_Holder=0;

	/*Increment global counter */
	Global_PasswordCounter ++ ;
	H_LCD_void_gotoXY(2,0);
    H_LCD_void_sendString("Re-enter ur data");
    _delay_ms(1000);
    Local_Holder = User_Authentication_SignIn();

    H_LCD_void_ClearDisplay();
	if(Local_Holder== Login_Ok)
	{
	    Pass = Login_Ok;
	}
	if(Local_Holder== Login_Nok)
	{
		 Pass = Login_Nok;
	}
	return Pass;
}

void APP_WelcomeDisplay()
{
	H_LCD_void_gotoXY(1, 0);
	H_LCD_void_sendString("#Smart Home System#");
	H_LCD_void_gotoXY(2, 0);
	H_LCD_void_sendString("Chose Option:");
	H_LCD_void_gotoXY(3, 0);
	H_LCD_void_sendString("1-SignIn | 2-SingUp");
	H_LCD_void_gotoXY(4, 0);
	H_LCD_void_sendString("3-Factory Rest");
}

PASS_STATE Check_Password(u8 *Copy_Password, u8 Copy_ID)
{
	u8 Local_Counter = 0;
	u8 AddressCounter = 0 ;
	u8 Temp_Holder = 0;

	switch(Copy_ID)
	{
	case 1:
		AddressCounter = 0 ;
		H_LCD_void_sendString("ID_1");
		break;
	case 2:
		AddressCounter = 4 ;
		H_LCD_void_sendString("ID_2");
		break;
	default:
		H_LCD_void_sendString("ID Not found"); return INCORRECT_PASS ;break;
	}

	for(Local_Counter = 0; Local_Counter < 4; Local_Counter++)
	{
		_delay_ms(200);
		H_EEPROM_Void_ReadByte(AddressCounter, &Temp_Holder);

		/*If there is incorrect number  */
		if(Temp_Holder != Copy_Password[Local_Counter])
		{
			return INCORRECT_PASS ;
		}
		AddressCounter ++ ;
	}
	AddressCounter = 0 ;
	return CORRECT_PASS ;
}

void KeyPad_EnterPassWord(u8 *Copy_PasswordArr)
{
	u8 Local_Counter = 0 ;
	u8 KPD_Value = 0;

	/*
	 * Enter Password
	 */
	do{
		KPD_Value = H_KEYPAD_u8_getPressedKey() ;
		if( KPD_Value != '\0')
		{
			Copy_PasswordArr[Local_Counter] = KPD_Value;
			H_LCD_void_sendData(Copy_PasswordArr[Local_Counter]);
			Local_Counter ++ ;
		}

	}while(Local_Counter != 4);
}

void Save_NewPassword(u8 *Copy_NewPassword, u8 Copy_ID)
{
	u8 AddressCounter = 0 ;
	u8 LocalCounter = 0;

		/*Check ID number */
	switch(Copy_ID)
	{
		case 1:
			AddressCounter = 0 ;
			H_LCD_void_sendString("ID_1 ");
			break ;
		case 2:
			AddressCounter = 4 ;
			H_LCD_void_sendString("ID_2 ");
		break ;
	}

		if(Copy_ID <= 2)
		{
		/*Enter the array to the eeprom */
		H_LCD_void_sendString("Saving data");
		for(LocalCounter = 0 ; LocalCounter < 4 ; LocalCounter ++)
		{
		_delay_ms(200);
		H_EEPROM_Void_WriteByte(AddressCounter, Copy_NewPassword[LocalCounter]);
		H_LCD_void_sendString(".");
		AddressCounter ++ ;
		}

		/*Increment the User ID */
		Copy_ID += 1 ;
		_delay_ms(200);
		H_EEPROM_Void_WriteByte(EEPROM_USER_ID,Copy_ID);
		}
		else /* Exceeded the max number of users */
		{
			H_LCD_void_sendString("Exceeded Max Number");
			_delay_ms(2000);
			H_LCD_void_ClearDisplay();
		}

}

u8 GloblaLogAddreses = 0 ;

//void Save_LogData()
//{
//	u8 DateArray[3] = {H_RTC_Void_GetDate().RTC_Day,H_RTC_Void_GetDate().RTC_Month,H_RTC_Void_GetDate().RTC_Year};
//	u8 TimeArry[4] = {H_RTC_Void_GetTime().RTC_Hours,H_RTC_Void_GetTime().RTC_Minutes, H_RTC_Void_GetTime().RTC_Seconed,H_RTC_Void_GetTime().RTC_DayTime};
//
//
//
//}

void Rest_Password()
{
	u8 RestPassword[4] = {'1','2','3','4'};
	u8 ID = 1 ;
	H_LCD_void_ClearDisplay();
	Save_NewPassword(RestPassword, ID);
	_delay_ms(200);
	H_EEPROM_Void_WriteByte(EEPROM_USER_ID, 1);
	_delay_ms(200);
	H_LCD_void_ClearDisplay();

	H_LCD_void_sendString("Rest Password");
	_delay_ms(1000);
}
