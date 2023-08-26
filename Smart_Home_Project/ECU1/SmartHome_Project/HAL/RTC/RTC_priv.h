/*
 * RTC_priv.h
 *
 *  Created on: Mar 12, 2023
 *      Author: LENOVO
 */

#ifndef RTC_RTC_PRIV_H_
#define RTC_RTC_PRIV_H_

#define RTC_ADDRESS_W	0xD0
#define RTC_ADDRESS_R	0xD1

#define RTC_TIME_ADDRESS	0x00
#define RTC_DATE_ADDRESS	0x04

#define RTC_PM_MASK		0x60
#define RTC_AM_MASK		0x40

#define RTC_ONES_MASK	0x0F
#define RTC_TENS_MASK	0x70

#define RTC_ONES_BCD_MASK 	0x0F
#define RTC_TENS_BCD_MASK	0xF0




#endif /* RTC_RTC_PRIV_H_ */
