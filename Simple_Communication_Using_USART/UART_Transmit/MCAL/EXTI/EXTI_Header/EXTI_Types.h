/*
 * EXTI_Types.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Dell
 */

#ifndef MCAL_EXTI_EXTI_HEADER_EXTI_TYPES_H_
#define MCAL_EXTI_EXTI_HEADER_EXTI_TYPES_H_

typedef enum
{
	EXTI0,
	EXTI1,
	EXTI2,
}EXT_ID;

typedef enum
{
	Low_level,
	On_change,
	Falling_edge,
	Rising_edge
}EXTI_Triggers;

typedef enum
{
	NULL_POINTER,
	OUT_OF_RANGE_VALUE,
	NO_ERROR,

}Error_Status_Enum;
#endif /* MCAL_EXTI_EXTI_HEADER_EXTI_TYPES_H_ */
