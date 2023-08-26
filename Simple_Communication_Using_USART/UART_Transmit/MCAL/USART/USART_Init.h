/*
 * USART_Init.h
 *
 *  Created on: Mar 4, 2023
 *      Author: Dell
 */

#ifndef MCAL_USART_USART_INIT_H_
#define MCAL_USART_USART_INIT_H_

#include "USART_Types.h"
#include "USART_CONFIG.h"

void UART_Init(UART_CONFIG *Ptr_Copy_UART);


void UART_SendByte(u8 Copy_UART);


void UART_SendString(u8 *Ptr_To_String);


u8 UART_RecieveByteSynchNonBlocking(void);

void UART_RecieveByteASynchCallback(void);


#endif /* MCAL_USART_USART_INIT_H_ */
