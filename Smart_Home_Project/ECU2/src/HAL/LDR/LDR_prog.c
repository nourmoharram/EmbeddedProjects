/*
 * LDR_prog.c
 *
 *  Created on: Mar 15, 2023
 *      Author: ahmed
 */
#include "Error_State.h"
#include "ADC_int.h"
#include "LDR_cfg.h"
#include "LDR_int.h"

ES_t H_LDR_enu_getIntensity(ADC_cfg_type* copy_LDR_cfg,u32* copy_intensity){
	ES_t Local_enuErrorState = ES_NOK ;
	u8 digital_val;
	if(copy_intensity != NULL && copy_LDR_cfg != NULL){
		M_ADC_enu_init(*copy_LDR_cfg);
		M_ADC_enu_getDigitalValueSynchNonBlocking(copy_LDR_cfg,&digital_val);
		*copy_intensity = digital_val;
		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState ;
}
