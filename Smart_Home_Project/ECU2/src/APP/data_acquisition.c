/*
 * data_acquisition.c
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
  Global Data
*******************************************/
extern  ADC_cfg_type ADC1_config[2];
u32 previous_temp;
u32 previous_intens;

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

ES_t getTempAndIntens(){
	ES_t Local_enuErrorState = ES_NOK;
	H_LM35_enu_getTemp(&ADC1_config[1], &current_temp);
	H_LDR_enu_getIntensity(ADC1_config, &current_intens);
	/*check if temperature changed to another range*/
	if(current_temp>=0 && current_temp<=45){

		if(
			((current_temp >=10 && current_temp <=27)&&((previous_temp >27 && previous_temp <=45)))
			|| ((previous_temp >=10 && previous_temp <=27)&&((current_temp >27 && current_temp <=45)))
			){
			Temp_Changed_Flag =1;
			previous_temp = current_temp;
			Local_enuErrorState = ES_OK;
		}
		else {
		}
		previous_temp = current_temp;
		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	/*check if intensity changed to another range*/
	if (current_intens >=0 && current_intens <=1000){
		if(
		((current_intens >=100 && current_intens <=230)&&((previous_intens >230&& previous_intens <=600)))
		|| ((previous_intens >=230&& previous_intens <=600)&&((current_intens >100 && current_intens <=230)))
		){
			Intens_Changed_Flag = 1;
			previous_intens = current_intens;
			Local_enuErrorState = ES_OK;
		}
		else {
			previous_intens = current_intens;
			Local_enuErrorState = ES_OK;
		}
	}
	else{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	
	H_LCD_void_gotoXY(1, 0);
	H_LCD_void_sendString("TEMP:");
	H_LCD_void_sendIntNum(current_temp);
	H_LCD_void_gotoXY(2, 0);
	H_LCD_void_sendString("INTENS:");
	if(current_intens)
	{
		H_LCD_void_gotoXY(2, 9);
		H_LCD_void_sendData(' ');
	}
	H_LCD_void_gotoXY(2, 7);	
	H_LCD_void_sendIntNum(current_intens);
	return Local_enuErrorState;
}

