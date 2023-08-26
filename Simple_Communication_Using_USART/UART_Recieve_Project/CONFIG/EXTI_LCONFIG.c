/*
 * EXTI_LCONFIG.c
 *
 *  Created on: Feb 24, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"EXTI_CONFIG.h"

EXT_I ARR_OF_Interrupts[3]={{EXTI0,On_change},{EXTI1,Rising_edge},{EXTI2,Falling_edge}};

