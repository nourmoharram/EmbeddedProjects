/*
 * PB_Types.h
 *
 *  Created on: Feb 18, 2023
 *      Author: Dell
 */

#ifndef HAL_PUSH_BUTTON_PB_TYPES_H_
#define HAL_PUSH_BUTTON_PB_TYPES_H_

typedef enum
{
	PB_ID1,
	PB_ID2,
	PB_ID3,
	PB_ID4
}PB_ID;

typedef enum
{
	PB_ACTIVE_LOW,
	PB_ACTIVE_HIGH,
}PB_ActiveType;

typedef enum
{
	PB_PRESSED,
	PB_RELEASED
}PB_State;


#endif /* HAL_PUSH_BUTTON_PB_TYPES_H_ */
