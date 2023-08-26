/*
 * WIFI_send_receive.c
 *
 *  Created on: Mar 16, 2023
 *      Author: ahmed
 */


/******************************************
  INCLUDES
*******************************************/
#include "APP_int.h"

void Read_Wifi(void)
{
	/* Check Inputs for Logout_Request_Flag */
	if (Wifi_Wait_Data(Logout_Requested))		Logout_Request_Flag = Logout_Requested ;

	/* Check Inputs for Motor State Flag */
	if (Wifi_Wait_Data(Motor_State_OFF))		Motor_State_Flag = Motor_State_OFF ;
	if (Wifi_Wait_Data(Motor_State_HighSpeed))	Motor_State_Flag = Motor_State_HighSpeed;
	if (Wifi_Wait_Data(Motor_State_LowSpeed))	Motor_State_Flag = Motor_State_LowSpeed ;
	if (Wifi_Wait_Data(Motor_State_Auto))		Motor_State_Flag = Motor_State_Auto ;

	/* Check Inputs for LED_State_Flag */
	if (Wifi_Wait_Data(LED_State_OFF))			LED_State_Flag = LED_State_OFF ;
	if (Wifi_Wait_Data(LED_State_Auto))			LED_State_Flag = LED_State_Auto ;

	/* Check Inputs for Temperature_Request_Flag */
	if (Wifi_Wait_Data(Temperature_Requested))  Temperature_Request_Flag = Temperature_Requested ;
	Wifi_Buffer_Reset();
}


/* Send temperture to user if Temperture requested flag is set */
void Show_Temperture_Wifi()
{
	if(Temperature_Request_Flag == Temperature_Requested )
	{
		//current_temp
		char Temperature_buffer[20];
		sprintf(Temperature_buffer, "Temperature= %ldC\r\n",current_temp);
		
		Wifi_Send_Data2(Temperature_buffer);
		Temperature_Request_Flag = 0;
	}
	
}


/* Show Menu to user */
void Show_Menu_Wifi()
{
	
Wifi_Send_Data2("\nWelcom Ahmed:\n a: Motor OFF,\n b: Motor High speed,\n c: Motor Low Speed,\n d: Motor Auto,\n e: LED OFF,\n f: LED Auto,\n g: Show Temperature\n, z: Logout");
	
}