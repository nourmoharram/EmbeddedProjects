/*
 * ADC_prg.c
 *
 *  Created on: Mar 3, 2023
 *      Author: ahmed
 */

#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "Error_State.h"
#include "LCD_int.h"
#include "ADC_priv.h"
#include "ADC_Types.h"
#include "ADC_cfg.h"
#include "ADC_int.h"
ES_t (*ADCpfunAppFun)(void*) = NULL;
void * ADCpvidAppParameter = NULL;


volatile u8 timeout_flag =0;
ES_t M_ADC_enu_init(ADC_cfg_type copy_ADCcfg){
	ES_t Local_enuErrorState=ES_OK;
	/*prescaler*/
	ADC_PRES_TYPE ADC_PS = copy_ADCcfg.ADC_PRES;
	switch(ADC_PS){
	case PRES_1:
		PtrADCSRA->ADPS_BITS = 0;
		break;
	case PRES_2:
		PtrADCSRA->ADPS_BITS =1;
		break;
	case PRES_4 :
		PtrADCSRA->ADPS_BITS = 2;
		break;
	case PRES_8:
		PtrADCSRA->ADPS_BITS = 3;
		break;
	case PRES_16:
		PtrADCSRA->ADPS_BITS =4;
		break;
	case PRES_32:
		PtrADCSRA->ADPS_BITS = 5;
		break;
	case PRES_64:
		PtrADCSRA->ADPS_BITS =6;
		break;
	case PRES_128:
		PtrADCSRA->ADPS_BITS = 7;
		break;
	default:
		Local_enuErrorState = ES_OUT_OF_RANGE;
		break;
	}

	/*channel selection*/
	if(copy_ADCcfg.INIT_CHNL<=31 && copy_ADCcfg.INIT_CHNL>=0){
		PtrADMUX->MUX_BITS = copy_ADCcfg.INIT_CHNL;
		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	/*auto trigger*/
	ADC_MODE_TYPE ADC_MODE= copy_ADCcfg.INIT_MODE;
	switch (ADC_MODE) {
		case SINGLE_CONV:
			PtrADCSRA->ADATE_BITS=0;
			break;
		case AUTOTRIGGERED:
			PtrADCSRA->ADATE_BITS=1;
			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
			break;
	}

	/*auto trigger source*/
	if(copy_ADCcfg.INIT_TRIG_SRC == FREE_RUNINNG ||copy_ADCcfg.INIT_TRIG_SRC ==EXT0 || copy_ADCcfg.INIT_TRIG_SRC ==TIM0_OVF){
		PtrSFIOR->ADTS_BITS = copy_ADCcfg.INIT_TRIG_SRC;
	}
	else{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	/*conversion complete interrupt*/
	if(copy_ADCcfg.INIT_INT_MODE==POLLING || copy_ADCcfg.INIT_INT_MODE== ENABLED){

		PtrADCSRA->ADIE_BITS=copy_ADCcfg.INIT_INT_MODE;
	}
	else{
		Local_enuErrorState = ES_NOK;
	}
	/*Vref*/
	if(copy_ADCcfg.ADC_VREF==AREF_REF || copy_ADCcfg.ADC_VREF==AVCC_REF || copy_ADCcfg.ADC_VREF==INTERNAL_REF){
		PtrADMUX->REFS_BITS=copy_ADCcfg.ADC_VREF;
	}
	else{
		Local_enuErrorState = ES_NOK;
	}
	/*data adjustment*/
	if(copy_ADCcfg.ADC_ADJ == LEFT_ADJ || copy_ADCcfg.ADC_ADJ == RIGHT_ADJ){
		PtrADMUX->ADLAR_BITS = copy_ADCcfg.ADC_ADJ;
	}
	else{
		Local_enuErrorState = ES_NOK;
	}
	/*enable ADC*/
	PtrADCSRA->ADEN_BITS =1;

	return Local_enuErrorState;
}

ES_t M_ADC_enu_getDigitalValueSynchNonBlocking(ADC_cfg_type* copy_ADCcfg, u8* voltage){
	ES_t Local_enuErroState = ES_OK;
	u16 digital_data=0;
	/*start conversion*/
	M_ADC_enu_startConversion();
		/*poling on ADIF*/
	while(!(PtrADCSRA->ADIF_BITS)){}
		/*read the result*/
		if(voltage != NULL){
			if(!copy_ADCcfg->ADC_ADJ){
				digital_data = ADCL_reg;
				digital_data |= (ADCH_reg<<8);
			}
			else if(copy_ADCcfg->ADC_ADJ){
				digital_data = (ADCL_reg>>6);
				digital_data |= (ADCH_reg<<2);
			}
			else{
				Local_enuErroState = ES_OUT_OF_RANGE;
			}
		}
		else {
			Local_enuErroState = ES_NULL_POINTER;
		}
		/*convert digital value to voltage*/
		*voltage = digital_data;/*5.00/1024.00;*/
		/*clear ADIF*/
		PtrADCSRA-> ADIF_BITS = 1;

	return Local_enuErroState;
}

ES_t M_ADC_enu_startConversion(){
	ES_t Local_enuErrorState = ES_OK;
	PtrADCSRA->ADSC_BITS =1;
	return Local_enuErrorState;
}


ES_t M_ADC_enu_getDigitalValueAsynchCallBack( float* voltage){
	ES_t Local_enuErroState = ES_OK;
	u16 digital_data=0;
	/*start conversion
	M_ADC_enu_startConversion();*/
	/*read the result*/
	if(voltage != NULL){
		if(!PtrADMUX->ADLAR_BITS){
			digital_data = ADCL_reg;
			digital_data |= (ADCH_reg<<8);
		}
		else if(PtrADMUX->ADLAR_BITS){
			digital_data = (ADCL_reg>>6);
			digital_data |= (ADCH_reg<<2);
		}
		else{
			Local_enuErroState = ES_OUT_OF_RANGE;
		}
		/*convert digital value to voltage*/
				*voltage = 100*digital_data*5.00/1024.00;
				H_LCD_void_gotoXY(1, 1);
				H_LCD_void_sendIntNum((s32)*voltage);
	}
	else{
		Local_enuErroState = ES_NULL_POINTER;
	}
	return Local_enuErroState;
}

ES_t M_ADC_enu_setCallBack(ES_t (*Copy_ADCpfunAppFun)(void*), void * Copy_ADCpvidAppParameter){
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_ADCpfunAppFun != NULL){
		ADCpfunAppFun = Copy_ADCpfunAppFun;
		ADCpvidAppParameter = Copy_ADCpvidAppParameter;
		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState =ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}

ES_t M_ADC_enu_selectChannel(ADC_CHNL_TYPE copy_ADC_chnl){
	ES_t Local_enuErrorState = ES_NOK;
	/*channel selection*/
	if(copy_ADC_chnl<=31 && copy_ADC_chnl>=0){
		PtrADMUX->MUX_BITS = copy_ADC_chnl;
		Local_enuErrorState = ES_OK;
	}
	else{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}


ISR(ADC_vect){
	if(ADCpfunAppFun != NULL){
		ADCpfunAppFun(ADCpvidAppParameter);
	}
	PtrADCSRA->ADIF_BITS=1;
}

