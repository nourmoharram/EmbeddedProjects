/*
 * RTC_prog.c
 *
 *  Created on: Mar 12, 2023
 *      Author: LENOVO
 */
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RTC_cfg.h"
#include "RTC_Init.h"
#include "RTC_priv.h"
#include "TWI_init.h"
#include "RTC_types.h"

void H_RTC_Void_Init()
{
	M_TWI_Void_InitMaster(TWI_SCL_100KHZ);
}

void H_RTC_Void_SetTime(RTC_CONFIG_TIME *Copy_TimeConfig, u8 Copy_DayTime)
{
	u8 Temp_Hours = Copy_TimeConfig->RTC_Hours ;

	/* Send Start Condition*/
	M_TWI_Void_SendStartCondition();
	/* Send RTC Address with read*/
	M_TWI_Void_SendByte(RTC_ADDRESS_W);
	/* Send Date address */
	M_TWI_Void_SendByte(RTC_TIME_ADDRESS);
	/* Send Time */
	M_TWI_Void_SendByte(H_RTC_DEC_TO_BCD(Copy_TimeConfig->RTC_Seconed));

	M_TWI_Void_SendByte(H_RTC_DEC_TO_BCD(Copy_TimeConfig->RTC_Minutes));

	if (Copy_DayTime == RTC_PM)
	{
		Temp_Hours |= RTC_PM_MASK ;
	}
	else if(Copy_DayTime == RTC_AM)
	{
		Temp_Hours |= RTC_AM_MASK ;
	}

	M_TWI_Void_SendByte(Temp_Hours);

	M_TWI_Void_SendStopCondition();
}

RTC_CONFIG_TIME H_RTC_Void_GetTime()
{
	RTC_CONFIG_TIME Time;
	u8 Temp_Holder ;
	u8 Temp_DayTime;
	/* Send Start Condition*/
	M_TWI_Void_SendStartCondition();
	/* Send RTC Address with read*/
	M_TWI_Void_SendByte(RTC_ADDRESS_W);
	/* Send Date address */
	M_TWI_Void_SendByte(RTC_TIME_ADDRESS);
	/* Send Repeated Start Condition*/
	M_TWI_Void_SendStartCondition();
	/* Send RTC Address with read*/
	M_TWI_Void_SendByte(RTC_ADDRESS_R);

	/*
	 *  Read Seconed
	 * */
	M_TWI_Void_RecevieWithACK(&Temp_Holder);
	H_RTC_BCD_TO_DEC(Temp_Holder);
	Time.RTC_Seconed= H_RTC_BCD_TO_DEC(Temp_Holder);
	/*
	 *  Read Min
	 * */
	M_TWI_Void_RecevieWithACK(&Temp_Holder);
	H_RTC_BCD_TO_DEC(Temp_Holder);
	Time.RTC_Minutes = H_RTC_BCD_TO_DEC(Temp_Holder);
	/*
	 *  Read Hour
	 * */
	M_TWI_Void_RecevieWitNACK(&Temp_Holder);

	Temp_DayTime = Temp_Holder & 0xF0 ;
	Time.RTC_DayTime = H_RTC_BCD_TO_DEC(Temp_DayTime);

	Temp_Holder &= 0x0F;
	Time.RTC_Hours = H_RTC_BCD_TO_DEC(Temp_Holder);

	/*
	 *  Send stop
	 * */
	M_TWI_Void_SendStopCondition();

	return Time ;
}


void H_RTC_Void_SetDate(RTC_CONFIG_DATE *Copy_DateConfig)
{
	/* Send Start Condition*/
	M_TWI_Void_SendStartCondition();

	/* Send RTC Address with read*/
	M_TWI_Void_SendByte(RTC_ADDRESS_W);

	/* Send Date address */
	M_TWI_Void_SendByte(RTC_DATE_ADDRESS);

	/* Send Date for the day */
	M_TWI_Void_SendByte(H_RTC_DEC_TO_BCD(Copy_DateConfig->RTC_Day));

	M_TWI_Void_SendByte(H_RTC_DEC_TO_BCD(Copy_DateConfig->RTC_Month));

	M_TWI_Void_SendByte(H_RTC_DEC_TO_BCD(Copy_DateConfig->RTC_Year));

	M_TWI_Void_SendStopCondition();
}


RTC_CONFIG_DATE H_RTC_Void_GetDate()
{
	RTC_CONFIG_DATE Date;
	u8 Holder ;

	/* Send Start Condition*/
	M_TWI_Void_SendStartCondition();
	/* Send RTC Address with read*/
	M_TWI_Void_SendByte(RTC_ADDRESS_W);
	/* Send Date address */
	M_TWI_Void_SendByte(RTC_DATE_ADDRESS);
	/* Send Repeated Start Condition*/
	M_TWI_Void_SendStartCondition();
	/* Send RTC Address with read*/
	M_TWI_Void_SendByte(RTC_ADDRESS_R);
	/*
	 *  Read Day
	 * */
	M_TWI_Void_RecevieWithACK(&Holder);
	H_RTC_BCD_TO_DEC(Holder);
	Date.RTC_Day= H_RTC_BCD_TO_DEC(Holder);
	/*
	 * Read Months
	 * */
	M_TWI_Void_RecevieWithACK(&Holder);
	H_RTC_BCD_TO_DEC(Holder);
	Date.RTC_Month= H_RTC_BCD_TO_DEC(Holder);
	/*
	 * Read Years
	 * */
	M_TWI_Void_RecevieWitNACK(&Holder);
	H_RTC_BCD_TO_DEC(Holder);
	Date.RTC_Year= H_RTC_BCD_TO_DEC(Holder);

	/*
	 * STOP TWI
	 */
	M_TWI_Void_SendStopCondition();

return Date;
}

u8 H_RTC_DEC_TO_BCD(u8 Copy_Number)
{
	u8 Temp_Ones = 0 ;
	u8 Temp_Tens = 0 ;

Temp_Ones = Copy_Number % 10;

Temp_Tens = Copy_Number / 10;

Temp_Ones &= RTC_ONES_MASK ;

Temp_Tens =  (Temp_Tens <<4) & RTC_TENS_MASK;

return Temp_Ones | Temp_Tens;
}

u8 H_RTC_BCD_TO_DEC(u8 Copy_Number)
{
	u8 Temp_Ones = 0 ;
	u8 Temp_Tens = 0 ;

	Temp_Ones = Copy_Number & RTC_ONES_BCD_MASK;

	Temp_Tens= Copy_Number & RTC_TENS_BCD_MASK;

	Temp_Tens = ((Temp_Tens>>4) * 10) ;
//	H_LCD_void_sendIntNum((Temp_Ones + Temp_Tens));
	return (Temp_Ones + Temp_Tens);
}
