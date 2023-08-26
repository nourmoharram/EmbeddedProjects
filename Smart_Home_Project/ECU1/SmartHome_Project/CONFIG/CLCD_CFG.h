/*
 * CLCD_CFG.h
 *
 *  Created on: Feb 19, 2023
 *      Author: Dell
 */

#ifndef CONFIG_CLCD_CFG_H_
#define CONFIG_CLCD_CFG_H_

#define CLCD_DATA_PORT          DIO_PORTD
#define CLCD_D4                 DIO_PB0
#define CLCD_D5                 DIO_PB1
#define CLCD_D6                 DIO_PB2
#define CLCD_D7                 DIO_PB4

#define CLCD_RS_PIN             DIO_PA3
#define CLCD_EN_PIN             DIO_PA2
/*Two modes for Initializations
 * _4_BIT_MODE
 * _8_BIT_MODE*/
#define LCD_MODE                _4_BIT_MODE

u8 Pattern_1[8];

u8 Pattern_2[8];

u8 Pattern_3[8];

u8 Pattern_4[8];

u8 SmilyChar[8];
#endif /* CONFIG_CLCD_CFG_H_ */
