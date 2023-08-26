/*
 * PB_Init.h
 *
 *  Created on: Feb 18, 2023
 *      Author: Dell
 */

#ifndef HAL_PUSH_BUTTON_PB_INIT_H_
#define HAL_PUSH_BUTTON_PB_INIT_H_

#define PUSH_BUTTON_1     0
#define PUSH_BUTTON_2     1
#define PUSH_BUTTON_3     2
#define PUSH_BUTTON_4     3

#include"PB_Types.h"

PB_State H_readPB(PB_ID PushBID,PB_ActiveType Mode);

#endif /* HAL_PUSH_BUTTON_PB_INIT_H_ */
