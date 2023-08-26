/*
 * USART_CONFIG.h
 *
 *  Created on: Mar 4, 2023
 *      Author: Dell
 */

#ifndef CONFIG_USART_CONFIG_H_
#define CONFIG_USART_CONFIG_H_

#include"USART/USART_Types.h"

typedef struct
{
	Baud_Rates Baud_NO;
	Word_Length Word_size;
	ParityBits Parity_type;
	Stop_Bits Stop_bits_no;
}UART_CONFIG;

#endif /* CONFIG_USART_CONFIG_H_ */
