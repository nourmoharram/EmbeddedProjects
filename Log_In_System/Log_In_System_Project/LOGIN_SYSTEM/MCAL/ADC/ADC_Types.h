/*
 * ADC_Types.h
 *
 *  Created on: Feb 26, 2023
 *      Author: Dell
 */

#ifndef MCAL_ADC_ADC_TYPES_H_
#define MCAL_ADC_ADC_TYPES_H_

typedef enum
{
	VCC_5V,
	VREF_2_5_V,
}Voltage_Ref;

typedef enum
{
	Right_Adjust,
	Left_Adjust,
}Adjust_type;

typedef enum
{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
}Analog_Channel_Select;
typedef enum
{
	DIV_BY_2,
	DIV_BY_4,
	DIV_BY_8,
	DIV_BY_16,
	DIV_BY_32,
	DIV_BY_64,
	DIV_BY_128,
}ADC_Pre_Scaller;

typedef enum
{
	Free_Runnin_Mode,
	Analog_Comparator,
	EXTI,
	TIMER0_CTC,
	TIMER0_OV,
	TIMCER1_CTC_B,
	TIMER1_OV,
	TIMER1_ICU,
}Trigger_type;

typedef enum
{
	ENABLE,
	DISABLE
}ADC_Start;

typedef enum
{
	Valid,
	Not_Valid,
}Error_States_ADC;
#endif /* MCAL_ADC_ADC_TYPES_H_ */
