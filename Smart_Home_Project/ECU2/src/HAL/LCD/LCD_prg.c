/*
 * LCD_prg.c
 *
 *  Created on: Feb 19, 2023
 *      Author: ahmed57
 */

#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"
#include "Dio_int.h"
#include "LCD_types.h"
#include "LCD_priv.h"
#include "LCD_cfg.h"
#include "LCD_int.h"
#include <avr/delay.h>
#include "BIT_MATH.h"

static void H_LCD_void_latchByte(u8 copy_u8Byte)
{

#if (LCD_MODE == FOUR_BIT_MODE)


	/* Step1: write your data or command */
	/* Send upper nibble */
	M_Dio_void_setPinValue(LCD_D4_PIN, GET_BIT(copy_u8Byte, 4));
	M_Dio_void_setPinValue(LCD_D5_PIN, GET_BIT(copy_u8Byte, 5));
	M_Dio_void_setPinValue(LCD_D6_PIN, GET_BIT(copy_u8Byte, 6));
	M_Dio_void_setPinValue(LCD_D7_PIN, GET_BIT(copy_u8Byte, 7));

	/* Step2: Enable LCD */
	M_Dio_void_setPinValue(LCD_EN_PIN, DIO_HIGH);
	_delay_ms(1);
	/* Step3: disable LCD */
	M_Dio_void_setPinValue(LCD_EN_PIN, DIO_LOW);
	_delay_ms(3);

	/* Step4: Send lower nibble */
	M_Dio_void_setPinValue(LCD_D4_PIN, GET_BIT(copy_u8Byte, 0));
	M_Dio_void_setPinValue(LCD_D5_PIN, GET_BIT(copy_u8Byte, 1));
	M_Dio_void_setPinValue(LCD_D6_PIN, GET_BIT(copy_u8Byte, 2));
	M_Dio_void_setPinValue(LCD_D7_PIN, GET_BIT(copy_u8Byte, 3));

	/* Step5: Enable LCD */
	M_Dio_void_setPinValue(LCD_EN_PIN, DIO_HIGH);
	_delay_ms(1);
	/* Step6: disable LCD */
	M_Dio_void_setPinValue(LCD_EN_PIN, DIO_LOW);
	_delay_ms(3);

	/*
    // Get the 4 least significant bits
	u8 num_least_bits = num & 0x0F;

    // Get the 4 most significant bits
	u8 num_most_bits = (num & 0xF0) >> 4;

	// Read PortB
	u8 PORTB_Bits = M_Dio_en_getPortValue(DIO_PORTB);

	// Get the 4 most significant bits of the port
	u8 PORTB_most_bits = (PORTB_Bits & 0XF0);

	u8 PORTB_FINAL_DATA = (PORTB_most_bits | num_most_bits);


	M_Dio_void_setPortValue( DIO_PORTB ,PORTB_FINAL_DATA);
*/

#elif (LCD_MODE == EIGHT_BIT_MODE)

	/* Step1: write your data or command */
	M_Dio_void_setPinValue(LCD_D0_PIN, GET_BIT(copy_u8Byte, 0));
	M_Dio_void_setPinValue(LCD_D1_PIN, GET_BIT(copy_u8Byte, 1));
	M_Dio_void_setPinValue(LCD_D2_PIN, GET_BIT(copy_u8Byte, 2));
	M_Dio_void_setPinValue(LCD_D3_PIN, GET_BIT(copy_u8Byte, 3));
	M_Dio_void_setPinValue(LCD_D4_PIN, GET_BIT(copy_u8Byte, 4));
	M_Dio_void_setPinValue(LCD_D5_PIN, GET_BIT(copy_u8Byte, 5));
	M_Dio_void_setPinValue(LCD_D6_PIN, GET_BIT(copy_u8Byte, 6));
	M_Dio_void_setPinValue(LCD_D7_PIN, GET_BIT(copy_u8Byte, 7));

	/* Step2: Enable LCD */
	M_Dio_void_setPinValue(LCD_EN_PIN, DIO_HIGH);
	_delay_ms(1);
	/* Step3: disable LCD */
	M_Dio_void_setPinValue(LCD_EN_PIN, DIO_LOW);
	_delay_ms(3);

#endif

}

void H_LCD_void_sendCommand(u8 copy_u8command)
{

	M_Dio_void_setPinValue(LCD_RS_PIN, DIO_LOW);
	H_LCD_void_latchByte(copy_u8command);


}

void H_LCD_void_sendData(u8 copy_u8data ){

	M_Dio_void_setPinValue(LCD_RS_PIN, DIO_HIGH);

	H_LCD_void_latchByte(copy_u8data);

}

void H_LCD_void_sendString( char  * pstr)
{
	int i;
	for(i=0;pstr[i]!=0;i++)  /* send each char of string till the NULL */
	{
		H_LCD_void_sendData (pstr[i]);  /* call LCD data write */

	}



}
void H_LCD_void_sendIntNum(s32 copy_s32Num)
{

	u16 num_string[20];

	if(copy_s32Num > 0)
	{
		itoa(copy_s32Num, num_string, 10);
		H_LCD_void_sendString(num_string);
	}

	else if(copy_s32Num < 0)
	{
		H_LCD_void_sendData ('-');
		copy_s32Num *= -1;
		itoa(copy_s32Num, num_string, 10);
		H_LCD_void_sendString(num_string);
	}




	/*

	u8 num;
	u8 num_asci;

	if(copy_s32Num > 0)
	{
		while(copy_s32Num > 0)
		{
			num = copy_s32Num % 10;
			num_asci = '0' + num;
			H_LCD_void_sendData (num_asci);
			copy_s32Num /= 10;


		}
	}
	else if(copy_s32Num < 0)
	{
		H_LCD_void_sendData ('-');
		copy_s32Num *= -1;

		while(copy_s32Num > 0)
		{
			num = copy_s32Num % 10;
			num_asci = '0' + num;
			H_LCD_void_sendData (num_asci);
			copy_s32Num /= 10;
		}

	}


	*/
}


void H_LCD_void_gotoXY(u8 copy_u8Row,u8 copy_u8Col)
{

	switch(copy_u8Row)
	{

		case 1:	H_LCD_void_sendCommand(LCD_SEND_CURSOR_BEGINING_LINE1);
				for(int i =0; i<copy_u8Col; i++)
				{
					H_LCD_void_sendCommand(LCD_SHIF_CURSOR_RIGHT);
				}
				break;

		case 2:	H_LCD_void_sendCommand(LCD_SEND_CURSOR_BEGINING_LINE2);
				for(int i =0; i<copy_u8Col; i++)
				{
					H_LCD_void_sendCommand(LCD_SHIF_CURSOR_RIGHT);
				}
				break;

		case 3:	H_LCD_void_sendCommand(LCD_SEND_CURSOR_BEGINING_LINE3);
				for(int i =0; i<copy_u8Col; i++)
				{
					H_LCD_void_sendCommand(LCD_SHIF_CURSOR_RIGHT);
				}
				break;

		case 4:	H_LCD_void_sendCommand(LCD_SEND_CURSOR_BEGINING_LINE4);
				for(int i =0; i<copy_u8Col; i++)
				{
					H_LCD_void_sendCommand(LCD_SHIF_CURSOR_RIGHT);
				}
				break;

	}


}
void H_LCD_void_creatCustomChar (const u8 * ArrPattern,u8 copy_u8charCode)
{

	u8 i;

	if(copy_u8charCode < 8)
	{
		/* select the CGRAM address to store the custom character   */
		H_LCD_void_sendCommand(LCD_CGRAM_START_ADDRESS + (copy_u8charCode * 8));

		/* store the custom character patterin into CGRAM   */
		for(i =0; i<8; i++)
		{
			H_LCD_void_sendData(ArrPattern[i]);
		}

	}

	/* Return to DDRAM address 0x00 */
	//H_LCD_void_sendCommand(LCD_SET_DDRAM_ADDR);

}
void H_LCD_void_displayCustomChar(u8 copy_u8charCode)
{

	/* Set DDRAM address where the custom character will be displayed  */
	//H_LCD_void_sendCommand(LCD_SET_DDRAM_ADDR + copy_u8charCode );

	/* Send the data to be displayed on LCD  */
	H_LCD_void_sendData(copy_u8charCode);
}

void H_LCD_void_Clear_Display()
{

	H_LCD_void_sendCommand(LCD_CLEAR_DISPLAY);
	H_LCD_void_sendCommand(LCD_SEND_CURSOR_BEGINING_LINE1);

}


void H_LCD_void_Init(void)
{

	/* LCD Power ON delay  */
	_delay_ms(40);

	/* Send for 4 bit initialization of LCD  */
	H_LCD_void_sendCommand(0x33);
	H_LCD_void_sendCommand(LCD_FUN_SET_MODE);

	/* 2 line, 5*7 matrix in 4-bit mode */
	H_LCD_void_sendCommand(LCD_4BIT_2LINE_5X7);

	/* Display on cursor ON */
	H_LCD_void_sendCommand(LCD_DISPLAY_ON_CURSOR_BLINKING);

	/* Increment cursor (shift cursor to right) */
	H_LCD_void_sendCommand(LCD_INCREMENT_CURSOR_SHIFT_TO_RIGHT);

	/* Clear display screen */
	H_LCD_void_sendCommand(LCD_CLEAR_DISPLAY);


}
