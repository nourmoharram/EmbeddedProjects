/*
 * APP_init.h
 *
 *  Created on: Mar 16, 2023
 *      Author: LENOVO
 */

#ifndef APP_INIT_H_
#define APP_INIT_H_
#include "STD_TYPES.h"
#include "APP_types.h"

void APP_INIT();
void APP_Start();
void Close_System();
/*
 */
void APP_WelcomeDisplay();
LOGIN_STATE User_Authentication_SignIn();						 //
void User_Authentication_SignUp();								//
PASS_STATE Check_Password(u8 *Copy_Password, u8 Copy_ID);		//
void Save_NewPassword(u8 *Copy_NewPassword, u8 Copy_ID);
void KeyPad_EnterPassWord(u8 *Copy_PasswordArr);				//
/*
 *
 */
void SYSTEM_OFF(void);								  //
void Time_Processing(void);							 //
void Successful_Authentication(void);				//
void Display_LastLogin(void);						//
Pass_State Wrong_Authentication(void);			   //
void Rest_Password();
#endif /* APP_INIT_H_ */
