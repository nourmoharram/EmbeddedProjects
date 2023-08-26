/*
 * ADC_CONFIG.h
 *
 *  Created on: Feb 26, 2023
 *      Author: Dell
 */

#ifndef CONFIG_ADC_CONFIG_H_
#define CONFIG_ADC_CONFIG_H_

#include"ADC/ADC_Types.h"
typedef struct{
	Voltage_Ref Voltage_Ref_Value;
	ADC_Pre_Scaller Pre_Scaller;
	Adjust_type AdjustType;
	Analog_Channel_Select Channel;
	Trigger_status Trigger;
	Trigger_type Trigger_Type;
}ADC_ConfigType;

#endif /* CONFIG_ADC_CONFIG_H_ */
