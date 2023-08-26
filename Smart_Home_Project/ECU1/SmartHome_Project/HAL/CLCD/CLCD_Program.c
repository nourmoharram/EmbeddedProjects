/*
 * CLCD_Program.c
 *
 *  Created on: Feb 19, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO/Dio_int.h"
#include"CLCD_CFG.h"
#include"CLCD_Private.h"
#include"CLCD_Types.h"
#include"CLCD_Init.h"
#include<util/delay.h>


/******************************************
  syntax : static void H_LCD_void_latchByte(u8 copy_u8Byte);

  Description : latch the data / commands to LCD pins

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : void
******************************************/
static void H_LCD_void_latchByte(u8 copy_u8Byte)
{
#if(LCD_MODE == _4_BIT_MODE)
	//enable = zero
	M_Dio_void_setPinValue(CLCD_EN_PIN,DIO_LOW);

	M_Dio_void_setPinValue(CLCD_D4,GET_BIT(copy_u8Byte,4));
	M_Dio_void_setPinValue(CLCD_D5,GET_BIT(copy_u8Byte,5));
	M_Dio_void_setPinValue(CLCD_D6,GET_BIT(copy_u8Byte,6));
	M_Dio_void_setPinValue(CLCD_D7,GET_BIT(copy_u8Byte,7));

	M_Dio_void_setPinValue(CLCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	M_Dio_void_setPinValue(CLCD_EN_PIN,DIO_LOW);

	M_Dio_void_setPinValue(CLCD_D4,GET_BIT(copy_u8Byte,0));
	M_Dio_void_setPinValue(CLCD_D5,GET_BIT(copy_u8Byte,1));
	M_Dio_void_setPinValue(CLCD_D6,GET_BIT(copy_u8Byte,2));
	M_Dio_void_setPinValue(CLCD_D7,GET_BIT(copy_u8Byte,3));

	M_Dio_void_setPinValue(CLCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	M_Dio_void_setPinValue(CLCD_EN_PIN,DIO_LOW);
	_delay_ms(30);
#elif(LCD_MODE == _8_BIT_MODE)
	//enable low
	M_Dio_void_setPinValue(CLCD_EN_PIN,DIO_LOW);

	M_Dio_void_setPinValue(CLCD_D0,GET_BIT(copy_u8Byte,0));
	M_Dio_void_setPinValue(CLCD_D1,GET_BIT(copy_u8Byte,1));
	M_Dio_void_setPinValue(CLCD_D2,GET_BIT(copy_u8Byte,2));
	M_Dio_void_setPinValue(CLCD_D3,GET_BIT(copy_u8Byte,3));
	M_Dio_void_setPinValue(CLCD_D4,GET_BIT(copy_u8Byte,4));
	M_Dio_void_setPinValue(CLCD_D5,GET_BIT(copy_u8Byte,5));
	M_Dio_void_setPinValue(CLCD_D6,GET_BIT(copy_u8Byte,6));
	M_Dio_void_setPinValue(CLCD_D7,GET_BIT(copy_u8Byte,7));

	M_Dio_void_setPinValue(CLCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	M_Dio_void_setPinValue(CLCD_EN_PIN,DIO_LOW);
	_delay_ms(30);

#endif

}

/******************************************
  syntax : void H_LCD_void_Init(void);

  Description : Init LCD

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_LCD_void_Init(void)
{
	_delay_ms(150);
	M_Dio_void_setPinValue(CLCD_RS_PIN,DIO_LOW);
	/*Function set*/
#if(LCD_MODE == _4_BIT_MODE)
	H_LCD_void_sendCommand(CLCD_FUNCTION_SET_1);
	_delay_ms(5);
	H_LCD_void_sendCommand(CLCD_FUNCTION_SET_2);
	_delay_ms(5);

	/*Display ON/OFF*/
	H_LCD_void_sendCommand(CLCD_DISPLAY);
	_delay_ms(5);
	/*Display clear*/
	H_LCD_void_sendCommand(CLCD_CLEAR);
	_delay_ms(5);
	H_LCD_void_sendCommand(CLCD_ENTRY_MODE_SET);
#elif(LCD_MODE== _8_BIT_MODE)
	/*Function set command: 2lines and 5*8 font size*/
	H_LCD_void_sendCommand(0b00111000);

	/*Display on off control display enable,disable cursor and no blink cursor*/
	H_LCD_void_sendCommand(0b00001100);

	/*clear display*/
	H_LCD_void_sendCommand(0b00000001);

#endif

}
/******************************************
  syntax : void H_LCD_void_sendData(u8 copy_u8data );

  Description : Send data to LCD

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_LCD_void_sendData(u8 copy_u8data )
{
	/*SET RS TO ZERO*/
	M_Dio_void_setPinValue(CLCD_RS_PIN,DIO_HIGH);
	/*Write command*/
	H_LCD_void_latchByte(copy_u8data);

}
/******************************************
  syntax :void H_LCD_void_sendCommand(u8 copy_u8command)


  Description : Send commands to LCD pins

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_LCD_void_sendCommand(u8 copy_u8command)
{
	/*SET RS TO ZERO*/
	M_Dio_void_setPinValue(CLCD_RS_PIN,DIO_LOW);
	/*Write command*/
	H_LCD_void_latchByte(copy_u8command);

}
/******************************************
  syntax : void H_LCD_void_sendString(const s8 * pstr)


  Description : Send string to LCD

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_LCD_void_sendString(const char * pstr)
{
	u8 counter;
	for(counter=0;pstr[counter]!=0;counter++)
	{
		H_LCD_void_sendData(pstr[counter]);
	}
}
/******************************************
  syntax : void H_LCD_void_sendIntNum(s32 copy_s32Num)

  Description : Send Number to LCD

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : void
******************************************/
/*
void H_LCD_void_sendIntNum(u32 *copy_s32Num)
{
	u8 Local_u8Counter;

	for(Local_u8Counter=0;copy_s32Num[Local_u8Counter]!=0;Local_u8Counter++)
	{
		CLCD_voidSendData(copy_s32Num[Local_u8Counter]+'0');
	}


	//H_LCD_void_sendData(copy_s32Num+'0');

}
*/
void H_LCD_void_sendIntNum(s32 copy_s32Num)
{
	/* Local Variable to save the numbers digits*/
	s32 Local_Variable[8] = {0} ;
	u8 Local_Counter = 0 ;

	/* Check if the number is negative */
	if (copy_s32Num < 0)
	{
	/*Remove Negative Sign from number*/
	copy_s32Num = copy_s32Num * -1 ;
	/*Send Negative Sign */
	H_LCD_void_sendData('-');
	}
	/* While loop to split the Numbers and save it in Local_Variable*/
	while (copy_s32Num != 0)
	{
	Local_Variable[Local_Counter] = copy_s32Num % 10 ;
	copy_s32Num = copy_s32Num / 10 ;
	Local_Counter ++ ;

	}
	/* For loop to send the numbers using SendData*/
	for (Local_Counter --; Local_Counter < '0' ; Local_Counter--)
	{
		 H_LCD_void_sendData('0' + Local_Variable[Local_Counter]);
	}
}
/******************************************
  syntax : void H_LCD_void_gotoXY(u8 copy_u8Row,u8 copy_u8Col)

  Description : Display at specific position on LCD

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_LCD_void_gotoXY(u8 copy_u8Row,u8 copy_u8Col)
{
	u8 Local_u8Address;
	if(copy_u8Row == 1)
	{
		Local_u8Address = copy_u8Col;
	}
	else if(copy_u8Row == 2)
	{
		Local_u8Address = copy_u8Col + 0x40;
	}
	else if(copy_u8Row == 3)
	{
		Local_u8Address = copy_u8Col + 0x14;
	}
	else if(copy_u8Row == 4)
	{
		Local_u8Address = copy_u8Col + 0x54;
	}
	else
	{

	}
	//128 Is added to the address to set the most significant bit by 1 according to DDRAM address instruction
	H_LCD_void_sendCommand(Local_u8Address+128);
}
/******************************************
  syntax : void H_LCD_void_creatCustomChar (const u8 * ArrPattern,u8 copy_u8charCode)


  Description : Create custom char

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_LCD_void_creatCustomChar (const u8 * ArrPattern,u8 copy_u8charCode)
{
	u8 Local_counter=0;
	/*first calculate CGRAM address since each block of address is 8bytes*/
	u8 Local_u8CGramaddress=0;
	Local_u8CGramaddress = copy_u8charCode*8;
	/*Access CGRAM block using function Send command by setting bit 6 and clearing bit7*/
	H_LCD_void_sendCommand(Local_u8CGramaddress+64);
	/*write the pattern to the CG ram */
	for(Local_counter=0;Local_counter<8;Local_counter++) /*<8 since there are 8 memory locations only for cgram (64bytes)*/
	{
		H_LCD_void_sendData(ArrPattern[Local_counter]);
	}
	H_LCD_void_gotoXY(1,0);
	H_LCD_void_sendData(copy_u8charCode);

}
/******************************************
  syntax : void H_LCD_void_displayCustomChar (u8 copy_u8charCode)

  Description : Display custom char
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_LCD_void_displayCustomChar (u8 copy_u8charCode)
{
	/*give the custom char number to send data*/
	H_LCD_void_sendData(copy_u8charCode);
}
/******************************************
  syntax : void H_LCD_void_ClearDisplay(void)

  Description : Clear the display of LCD

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_LCD_void_ClearDisplay(void)
{
	H_LCD_void_sendCommand(CLCD_CLEAR);
}
