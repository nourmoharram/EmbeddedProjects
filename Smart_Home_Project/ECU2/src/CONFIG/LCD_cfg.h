/*
 * LCD_cfg.h
 *
 *  Created on: Feb 19, 2023
 *      Author: ahmed57
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "Port_types.h"
#include "Port_cfg.h"

const Port_ConfigType LCD_Config_Arr[6];

#define LCD_RS_PIN		        DIO_PA3
#define LCD_EN_PIN		        DIO_PA2
#define LCD_D4_PIN		        DIO_PB0
#define LCD_D5_PIN		        DIO_PB1
#define LCD_D6_PIN		        DIO_PB2
#define LCD_D7_PIN		        DIO_PB4

#define LCD_MODE		        FOUR_BIT_MODE
#define LCD_FUN_SET_MODE		LCD_FUN_SET_4BIT_MODE


#endif /* LCD_CFG_H_ */
