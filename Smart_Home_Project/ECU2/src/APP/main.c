/*
 * Port_prg.c
 *
 *  Created on:
 *      Author:
 */

/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    :
*  brief   :
*  details :
*****************************************************************
*
*/
/******************************************
  INCLUDES
*******************************************/
#define F_CPU 16000000UL
#include "APP_int.h"

/******************************************
  Local Data
*******************************************/



/******************************************
  Global Data
*******************************************/
extern  ADC_cfg_type ADC1_config[2];
extern System_cfg_t system_cfg ;

/******************************************
  Local Functions  body
*******************************************/


/******************************************
  Global Functions body
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
void main(){
	/* Initialize All System Moduels */
	
	//Show_Menu_Wifi();
	sytem_init();
	
	_delay_ms(200);
	//H_LCD_void_sendString("hello");
	


	/* Wait for user to login to connect wifi and start system */
	Check_Login_Sucsess();
		



		
	while(1)
	{

		/* Wait for ECU1 Login Sucsess Signal to start Application */
		while(Login_Sucsess_Flag == 1)
		{
			/* Check User Input From Wifi */
			Read_Wifi();
			/*read LM35 and LDR values*/
			getTempAndIntens();
			/* Update fan speed based on User input */
			Adjust_FanSpeed();
			/* Update LED_intens based on User input */
			Adjust_LEDIntensety();
			
			Show_Temperture_Wifi();
			
			Led_Control();
			
			Logout_Request_Handler();
			Motor_Control();
			_delay_ms(150);	
			
		}
	}
}

