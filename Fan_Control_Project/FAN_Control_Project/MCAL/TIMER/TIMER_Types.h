/*
 * TIMER_Types.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Dell
 */

#ifndef MCAL_TIMER_TIMER_TYPES_H_
#define MCAL_TIMER_TIMER_TYPES_H_

typedef enum
{
	Normal_Mode,
	CTC_Mode,
	Fast_PWM,
	Phase_Correct_PWM,
}Timer_Mode;

typedef enum
{
	Normal_Port,
	Toggle_OC0,
	Clear_OC0,
	Set_OC0,
	Inverting_Mode,
	Non_Invering_Mode,
}Comp_Output_Mode;

typedef enum
{
	No_CLK,
	NO_PRESCALLING,
	CLK_8,
	CLK_64,
	CLK_256,
	CLK_1024,
	Ext_CLK_Falling,
	Ext_CLK_Raising
}PRE_SCALLER;

typedef enum
{
	Over_flow_event,
	Compare_match_event,
}Interrupt_Event;


#endif /* MCAL_TIMER_TIMER_TYPES_H_ */
