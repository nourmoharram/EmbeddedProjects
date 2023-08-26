/*
 * LM35_prog.c
 *
 *  Created on: Mar 15, 2023
 *      Author: ahmed
 */
#include "Error_State.h"
#include "ADC_int.h"
#include "LM35_int.h"

ES_t H_LM35_enu_getTemp(ADC_cfg_type* copy_LM35_cfg, u32* copy_temp){
	ES_t Local_enuErrorState = ES_NOK;
	u8 digital_val;
	if(copy_LM35_cfg != NULL && copy_temp != NULL){
		M_ADC_enu_init(*copy_LM35_cfg);
		M_ADC_enu_getDigitalValueSynchNonBlocking(copy_LM35_cfg, &digital_val);
		//*copy_temp = (digital_val*5/1024)*100;
		*copy_temp = (digital_val*4.88)/10;
		Local_enuErrorState = ES_OK;
	}
	else {
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
