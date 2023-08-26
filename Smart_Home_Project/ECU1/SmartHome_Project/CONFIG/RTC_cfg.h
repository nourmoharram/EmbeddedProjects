/*
 * RTC_cfg.h
 *
 *  Created on: Mar 12, 2023
 *      Author: LENOVO
 */

#ifndef RTC_CFG_H_
#define RTC_CFG_H_

#include "STD_TYPES.h"


typedef struct{

	u8 RTC_Hours;
	u8 RTC_Minutes;
	u8 RTC_Seconed;
	u8 RTC_DayTime;

}RTC_CONFIG_TIME;

typedef struct{

	u8 RTC_Day;
	u8 RTC_Month;
	u8 RTC_Year;
}RTC_CONFIG_DATE;


#endif /* RTC_CFG_H_ */
