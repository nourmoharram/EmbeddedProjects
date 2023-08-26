/*
 * main.h
 *
 *  Created on: Mar 16, 2023
 *      Author: ahmed
 */

#ifndef SRC_APP_APP_INT_H_
#define SRC_APP_APP_INT_H_

/******************************************
  INCLUDES
*******************************************/
//#define F_CPU 16000000UL
#include "STD_TYPES.h"
#include "AVR/delay.h"
#include "interrupt.h"
#include "GLOBAL_INT_int.h"
#include "Port_int.h"
#include "Dio_int.h"
#include "LED_Cfg.h"
#include "LED_Int.h"
#include "LCD_int.h"
#include "TIMER0_int.h"
#include "TIMER0_cfg.h"
#include "Motor_int.h"
#include "ADC_int.h"
#include "ADC_cfg.h"
#include "LM35_int.h"
#include "LDR_int.h"
#include "system_init_cfg.h"
/* ahmed */
#include <stdbool.h>				/* Include standard boolean library */
#include <string.h>					/* Include string library */
#include <stdio.h>					/* Include standard IO library */
#include <stdlib.h>					/* Include standard library */

#include "UART_int.h"
#include "wifi_int.h"
#include "EXTI_INT_cfg.h"
#include "EXTI_INT_int.h"
#include "TIMER_1_Init.h"
/******************************************
  GLOBAL DATA PROTOTYPES
*******************************************/
u8 Login_Flag;
u8 Temp_Changed_Flag;
u8 Intens_Changed_Flag;

u32 previous_temp;
u32 current_temp;
u32 previous_intens;
u32 current_intens;
/******************************************
   GLOBAL FUNCTIONS PROTOTYPES
*******************************************/



/************************************************/
/************************************************/
/*   START OF WiFI_Send_Recive section           */
/************************************************/
/************************************************/

/* Logout_Request_Flag Values */
#define Logout_Requested		'z'

/************************************************/
/************************************************/
/* Motor_State_Flag Values */
#define Motor_State_OFF			'a'
#define Motor_State_HighSpeed	'b'
#define Motor_State_LowSpeed	'c'
#define Motor_State_Auto	    'd'

/************************************************/
/************************************************/
/* LED_State_Flag Values */
#define LED_State_OFF		'e'
#define LED_State_Auto	    'f'

/************************************************/
/************************************************/
/*  Temperature_Request_Flag  Values */
#define Temperature_Requested		'g'

/************************************************/
		/* Flags Definitions  */
/************************************************/

/* Ecu1 Login_Sucsess_Flag set this flag to 1 by EC1_Login_Sucsess_Signal function */
u8 Login_Sucsess_Flag;

/* If user enterd (9) Logout flag set to 1
   Default Flag = 0
 */
u8 Logout_Request_Flag;

/* Motor Flag is set when received the following inputs from Wifi */
/*
   Default Flag = 0
   input (0) -> Motor OFF
   input (1) -> Motor ON with HIGH SPEED 70% Duty cycle
   input (2) -> Motor ON with LOW SPEED 30% Duty Cycle
   input (3) -> Auto Mode based on Temperature sensor reading
 */
 u8 Motor_State_Flag;
 u8 Motor_State_Flag_Privious_Reading;
/* LED Flag is set when received the following inputs from Wifi */
/*
   Default Flag = 4
   input (4) -> LED OFF
   input (5) -> LED ON - Auto mode
 */
 u8 LED_State_Flag;
 u8 LED_previous_State_Flag;

/* If user enterd (6) Temp flag set to 6
   Default to 0
 */
u8 Temperature_Request_Flag;
/* Read User enterd data through wifi */
void Read_Wifi(void);

/************************************************/
/************************************************/
/*  END OF WiFI_Send_Recive section                     */
/************************************************/
/************************************************/
/******************************************
   GLOBAL FUNCTIONS PROTOTYPES
*******************************************/

/******************************************
  syntax :

  Description :

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  :
  parameters (out) : none
  Return Value     : void
******************************************/
ES_t sytem_init();

/******************************************
  syntax :

  Description :

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  :
  parameters (out) : none
  Return Value     : void
******************************************/
ES_t getTempAndIntens();
/******************************************
  syntax :

  Description :

  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  :
  parameters (out) : none
  Return Value     : void
******************************************/
void Adjust_FanSpeed();
/******************************************
  syntax :
  Description :
  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  :
  parameters (out) : none
  Return Value     : void
******************************************/
void Adjust_LEDIntensety();



/******************************************
  syntax :
  Description :
  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  :
  parameters (out) : none
  Return Value     : void
******************************************/
void ECU1_Login_Sucsess_Signal();
/******************************************
  syntax :
  Description :
  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  :
  parameters (out) : none
  Return Value     : void
******************************************/
void Show_Temperture_Wifi();

/******************************************
  syntax :
  Description :
  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  :
  parameters (out) : none
  Return Value     : void
******************************************/
void Led_Control();


/******************************************
  syntax :
  Description :
  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  :
  parameters (out) : none
  Return Value     : void
******************************************/
void Check_Login_Sucsess();

/******************************************
  syntax :
  Description :
  Synch/Asynch     : Synchronous
  Reentrance       : Reentrant
  parameters (in)  :
  parameters (out) : none
  Return Value     : void
******************************************/
void Logout_Request_Handler();

void Motor_Control();


#endif /* SRC_APP_APP_INT_H_ */
