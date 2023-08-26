/*
 * USART_Types.h
 *
 *  Created on: Mar 4, 2023
 *      Author: Dell
 */

#ifndef MCAL_USART_USART_TYPES_H_
#define MCAL_USART_USART_TYPES_H_

typedef enum
{
	Baud_16MHz_2400=416,
	Baud_16MHz_4800=207,
	Baud_16MHz_9600=103,
	Baud_16MHz_57600=16,
	Baud_8MHZ_2400=207,
	Baud_8MHZ_4800=103,
	Baud_8MHz_9600=51,

}Baud_Rates;

typedef enum
{
   Word_Size_5,
   Word_Size_6,
   Word_Size_7,
   Word_Size_8,
   Word_Size_9,
}Word_Length;

typedef enum
{
	Disabled,
	Enabled_Even_Parity,
	Enabled_Odd_Parity,

}ParityBits;
typedef enum
{
	One_Stop_bit,
	Two_Stop_Bit,
}Stop_Bits;


#endif /* MCAL_USART_USART_TYPES_H_ */
