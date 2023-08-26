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
	VCC_5V=0x40,
	VREF_2_5_V=0xC0,
}Voltage_Ref;

typedef enum
{
	Right_Adjust=0x00,
	Left_Adjust=0x20,
}Adjust_type;

typedef enum
{
	ADC0=0x00,
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
	DIV_BY_2_0,
	DIV_BY_2,
	DIV_BY_4,
	DIV_BY_8,
	DIV_BY_16,
	DIV_BY_32,
	DIV_BY_64,
	DIV_BY_128=0x07,
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
	DISABLE,
	ENABLE,
}ADC_Start;

typedef enum
{
	Valid,
	Not_Valid,
}Error_States_ADC;
typedef enum
{
	Interrupt_Enable,
	Interrupt_Disable,
}Interrupt_Status;
typedef enum
{
	AUTO_Trigger_Enable,
	AUTO_Trigger_Disable,
}Trigger_status;
#endif /* MCAL_ADC_ADC_TYPES_H_ */
