/*
 * adjust_system.c
 *
 *  Created on: Mar 16, 2023
 *      Author: ahmed
 */

/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
#include "Error_State.h"
#include "APP_int.h"

/******************************************
  Global Functions body
*******************************************/

/******************************************
  syntax :

  Description :

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :
  parameters (out) : none
  Return Value     : void
******************************************/
void Adjust_FanSpeed(){

	/* Check That user input changed from privious  command or not  */
	if (Motor_State_Flag_Privious_Reading != Motor_State_Flag){
		switch(Motor_State_Flag)
		{
			case Motor_State_OFF: MOTOR_ON(MOTOR_CW , 0);
								  Motor_State_Flag_Privious_Reading = Motor_State_OFF;
								  Wifi_Send_Data2(" Fan Turned OFF ");
								  break;

			case Motor_State_HighSpeed: MOTOR_ON(MOTOR_CW , 80);
										Motor_State_Flag_Privious_Reading = Motor_State_HighSpeed;
										Wifi_Send_Data2(" Fan Turned ON at 80% Speed ");
										break;

			case Motor_State_LowSpeed:  MOTOR_ON(MOTOR_CW , 50);
										Motor_State_Flag_Privious_Reading = Motor_State_LowSpeed;
										Wifi_Send_Data2(" Fan Turned ON at 50% Speed ");
										break;
			
			case Motor_State_Auto: Wifi_Send_Data2(" Auto Fan");
									Motor_State_Flag_Privious_Reading = Motor_State_Auto;
									break;
		}
	}
	


}

void Adjust_LEDIntensety(){
	/* Check That user input changed from previous  command or not  */
	if ((LED_State_Flag == LED_State_OFF) && (LED_State_Flag != LED_previous_State_Flag))
	{
			M_TIMER1_void_Stop();
			Wifi_Send_Data2(" LED OFF ");
			LED_previous_State_Flag = LED_State_OFF;
	}
	
	 else if(LED_State_Flag == LED_State_Auto && (LED_State_Flag != LED_previous_State_Flag))
	 {
		  Wifi_Send_Data2(" LED Auto");
			LED_previous_State_Flag = LED_State_Auto;

	 }
}



void Led_Control()
{
	if(LED_State_Flag == LED_State_Auto )
	{
		//Intens_Changed_Flag=0;
	//u8 Intensity_percent = current_intens *100;;
	//
	//Intensity_percent /= 600;
	//if(Intensity_percent >= 100)
	//{
	//	Intensity_percent = 100;
	//}
	//u8 LED_PWM =  100- Intensity_percent;
		
		if(current_intens>=0 && current_intens<50){
			M_TIMER1_void_Stop();
			//Wifi_Send_Data2(" LE Auto 100% ");
		}
		else if(current_intens>=50 && current_intens<100){
			H_LED_void_set_Intensity(40);
			//Wifi_Send_Data2(" LE Auto 40% ");
		}
		else if(current_intens>=100){
			H_LED_void_set_Intensity(100);
			//Wifi_Send_Data2(" LE Auto OFF ");
		}
		else{

			}
			
	}
}


void Motor_Control()
{
		 if( Motor_State_Flag == Motor_State_Auto){

				 if(current_temp>=0 && current_temp<10){
					 MOTOR_OFF();
					 //Wifi_Send_Data2(" Auto Fan: Temp < 10, Fan off ");
				 }
				 else if(current_temp>=10 && current_temp<27){
					 MOTOR_ON(MOTOR_CW , 50);
					 //Wifi_Send_Data2(" Auto Fan: Temp < 27 , Fan Low speed ");
				 }
				 else if(current_temp>=27 && current_temp<=45){
					 MOTOR_ON(MOTOR_CW , 80);
					// Wifi_Send_Data2(" Auto Fan: Temp > 27 , Fan High speed ");

				 }
				 else{

				 }

			 }

		 
}