/*
 * RTC_Init.h
 *
 *  Created on: Mar 12, 2023
 *      Author: LENOVO
 */

#ifndef RTC_RTC_INIT_H_
#define RTC_RTC_INIT_H_

#include "RTC_cfg.h"

typedef enum{
	RTC_AM = 40,
	RTC_PM = 60

}RTC_DayTime;

/******************************************
  syntax : void H_RTC_Void_Init();

  Description : Initliaze function

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : NONE
  parameters (out) :  NONE
  Return Value     : void
******************************************/
void H_RTC_Void_Init();
/******************************************
  syntax : void H_RTC_Void_SetTime(RTC_CONFIG_TIME *Copy_TimeConfig, u8 Copy_DayTime);


  Description : Set Time

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : *Copy_TimeConfig , u8 Copy_DayTime
  parameters (out) : NONE
  Return Value     : void
******************************************/
void H_RTC_Void_SetTime(RTC_CONFIG_TIME *Copy_TimeConfig, u8 Copy_DayTime);
/******************************************
  syntax : RTC_CONFIG_TIME H_RTC_Void_GetTime();


  Description : Get Time

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : NONE
  parameters (out) : TIME
  Return Value     : RTC_CONFIG_TIME
******************************************/
RTC_CONFIG_TIME H_RTC_Void_GetTime();
/******************************************
  syntax : void H_RTC_Void_SetDate(RTC_CONFIG_DATE *Copy_DateConfig);



  Description : Set Date

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : *Copy_DateConfig
  parameters (out) : NONE
  Return Value     : void
******************************************/
void H_RTC_Void_SetDate(RTC_CONFIG_DATE *Copy_DateConfig);
/******************************************
  syntax : RTC_CONFIG_DATE H_RTC_Void_GetDate();

  Description : Get Date

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : NONE
  parameters (out) : Date
  Return Value     : RTC_CONFIG_DATE
******************************************/
RTC_CONFIG_DATE H_RTC_Void_GetDate();
/******************************************
  syntax : u8 H_RTC_DEC_TO_BCD(u8 Copy_Number);

  Description : Convert from DECEMIAL TO BCD

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : *Copy_Number
  parameters (out) : BCD Number
  Return Value     : u8
******************************************/
u8 H_RTC_DEC_TO_BCD(u8 Copy_Number);
/******************************************
  syntax : u8 H_RTC_DEC_TO_BCD(u8 Copy_Number);

  Description : Convert from  BCD TO DECEMIAL

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : *Copy_Number
  parameters (out) : DEC Number
  Return Value     : u8
******************************************/
u8 H_RTC_BCD_TO_DEC(u8 Copy_Number);

#endif /* RTC_RTC_INIT_H_ */
