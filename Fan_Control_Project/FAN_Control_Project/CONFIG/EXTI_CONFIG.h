/*
 * EXTI_CONFIG.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Dell
 */

#ifndef CONFIG_EXTI_CONFIG_H_
#define CONFIG_EXTI_CONFIG_H_

#include"STD_TYPES.h"
#include"../MCAL/EXTI/EXTI_Header/EXTI_Types.h"
/*Options"
 * 1-LOW_LEVEL
 * 2-ON_CHANGE
 * 3-FALLING_EDGE
 * 4-RISING_EDGE*/
#define INT0_SENSE        RISING_EDGE

/*1-ENABLE
 * 2-DISABLE
 */
#define INT0_INITIAL_STATE   ENABLE



typedef struct
{
	EXT_ID Interrupt_ID;
	EXTI_Triggers Trigger_value;
}EXT_I;

#endif /* CONFIG_EXTI_CONFIG_H_ */
