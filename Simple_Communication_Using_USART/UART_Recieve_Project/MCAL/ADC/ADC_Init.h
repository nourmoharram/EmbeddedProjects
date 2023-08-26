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
Error_States_ADC ADC_Init(ADC_ConfigType *Ptr_to_ADC);

u16 ADC_getDigitalValueSynchNonBlocking(ADC_ConfigType *Ptr_to_ADC);

u16 ADC_getDigitalValueAsynchCallBack(ADC_ConfigType *Ptr_to_ADC);

u16 ADC_Get_Value_Reading(void);
void ADC_Interrupt_Enable(void);
void ADC_Interrupt_Disable(void);

u8 ADC_u8INTSetCallBack(void (*Copy_pvINTFunc)(void));
#endif /* MCAL_ADC_ADC_INIT_H_ */
