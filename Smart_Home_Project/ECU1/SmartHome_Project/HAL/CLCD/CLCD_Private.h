/*
 * CLCD_Private.h
 *
 *  Created on: Feb 19, 2023
 *      Author: Dell
 */

#ifndef HAL_CLCD_CLCD_PRIVATE_H_
#define HAL_CLCD_CLCD_PRIVATE_H_

#define CLCD_CLEAR			   0x01
#define CLCD_RETURN_HOME 	   0x02
#define CLCD_ENTRY_MODE_SET    0x06
#define CLCD_DISPLAY		   0x0c
#define CLCD_FUNCTION_SET_1    0x02
#define CLCD_FUNCTION_SET_2	   0x28
#define CURSOR_DIS_SHIFT       0x10

static void H_LCD_void_latchByte(u8 copy_u8Byte);


#endif /* HAL_CLCD_CLCD_PRIVATE_H_ */
