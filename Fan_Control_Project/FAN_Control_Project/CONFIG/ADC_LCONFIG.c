/*
 * ADC_LCONFIG.c
 *
 *  Created on: Mar 3, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"ADC/ADC_Types.h"
#include"ADC/ADC_Private.h"
#include"ADC_CONFIG.h"




const ADC_ConfigType ArrayofADC_Config_1[1]={{VCC_5V,DIV_BY_128,Right_Adjust,ADC0,Interrupt_Enable}};

const ADC_ConfigType ArrayofADC_Config_2[1]={{VCC_5V,DIV_BY_128,Left_Adjust,ADC0,Interrupt_Enable}};
