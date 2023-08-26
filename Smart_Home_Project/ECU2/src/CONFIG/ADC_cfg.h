/*
 * ADC_cfg.h
 *
 *  Created on: Mar 3, 2023
 *      Author: ahmed
 */

#ifndef SRC_CONFIG_ADC_CFG_H_
#define SRC_CONFIG_ADC_CFG_H_
#include "ADC_Types.h"
typedef struct{
	ADC_PRES_TYPE ADC_PRES;
	ADC_CHNL_TYPE INIT_CHNL;
	ADC_MODE_TYPE INIT_MODE;
	ADC_INT_MODE INIT_INT_MODE;
	ADC_TRIG_SRC_TYPE INIT_TRIG_SRC;
	ADC_VREF_TYPE ADC_VREF;
	ADC_ADJ_TYPE ADC_ADJ;
}ADC_cfg_type;

#endif /* SRC_CONFIG_ADC_CFG_H_ */
