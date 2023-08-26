/*
 * ADC_Init.h
 *
 *  Created on: Feb 26, 2023
 *      Author: Dell
 */

#ifndef MCAL_ADC_ADC_INIT_H_
#define MCAL_ADC_ADC_INIT_H_
#include"ADC_Types.h"
#include"ADC_CONFIG.h"
void ADC_Init(ADC_ConfigType *Ptr_to_ADC);

u16 ADC_getDigitalValueSynchNonBlocking(Analog_Channel_Select Channel,ADC_Start ADC_Status);

void ADC_getDigitalValueAsynchCallBack(Analog_Channel_Select Channel,ADC_Start ADC_Status,Interrupt_Status Interrupt_status);

u16 ADC_Get_Value_Reading(void);
void ADC_Interrupt_Enable(void);
void ADC_Interrupt_Disable(void);

void ADC_u8INTSetCallBack(void (*Copy_pvINTFunc)(void));
#endif /* MCAL_ADC_ADC_INIT_H_ */
