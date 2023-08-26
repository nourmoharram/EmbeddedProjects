/*
 * LCD_priv.h
 *
 *  Created on: Feb 19, 2023
 *      Author: ahmed57
 */

#ifndef LCD_LCD_PRIV_H_
#define LCD_LCD_PRIV_H_

	#define LCD_CLEAR_DISPLAY		                 0X01		// 0b01
	#define LCD_RETURN_HOME			                 0X02		// 0b010
	#define LCD_ENTRY_MODE			                 0X06		// 0b0100
	#define LCD_DISPLAY_ON_OFF		                 0X0F		// 0b01000
	#define LCD_CURSOR_DISP_SHIFT	                 0X10		// 0b010000
	#define LCD_FUN_SET_4BIT_MODE_1LINE_5X7          0X20		// 0b0100000
	#define LCD_FUN_SET_4BIT_MODE_2LINE_5X7	         0x28		// 0b0100000
	#define LCD_FUN_SET_4BIT_MODE_2LINE_5X10	     0X2C		// 0b0100000

	#define LCD_FUN_SET_8BIT_MODE_1LINE_5X7          0X30		// 0b0100000

	#define LCD_SET_CGRAM_ADDR		                 0X40		// 0b01000000
	#define LCD_SET_DDRAM_ADDR		                 0X80		// 0b010000000


	#define LCD_Busy_flag			                		// 0b0100000000
	#define WRITE_DATA_TO_CG__DD	                		// 0b01000000000
	#define READ_DATA_TO_CG__DD		                		// 0b01100000000

	#define LCD_FUN_SET_4BIT_MODE         			0x32
	#define LCD_4BIT_2LINE_5X7           			0x28
	#define LCD_DISPLAY_ON_CURSOR_OFF				0x0c
	#define LCD_DISPLAY_ON_CURSOR_ON				0x0E
	#define LCD_DISPLAY_ON_CURSOR_BLINKING			0x0F
	#define LCD_INCREMENT_CURSOR_SHIFT_TO_RIGHT     0x06

	#define LCD_CGRAM_START_ADDRESS					0x40

    #define LCD_SEND_CURSOR_BEGINING_LINE1		    0X80
    #define LCD_SEND_CURSOR_BEGINING_LINE2		    0XC0
    #define LCD_SEND_CURSOR_BEGINING_LINE3		    0x94
    #define LCD_SEND_CURSOR_BEGINING_LINE4		    0xD4

	#define LCD_SHIF_CURSOR_RIGHT					0X14
	#define LCD_SHIF_CURSOR_LEFT					0X18



/*  In 8 bit mode: it breaks the 8 bit (data/command) into 8
	indivual bits and sends them over the 8 pins.
   In 4 bit mode: it breaks the 8 bit (data/command) into two
halves(each half is 4 bits and send them over the 4 pins)
each half at a time Note : high order half is sent before the
low order one.
 This static function is called by both the functions
sendData and sendCommand.
*/

static void H_LCD_void_latchByte(u8 copy_u8Byte);

#endif /* LCD_LCD_PRIV_H_ */
