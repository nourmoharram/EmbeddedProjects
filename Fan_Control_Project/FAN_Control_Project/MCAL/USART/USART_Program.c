/*
 * USART_Program.c
 *
 *  Created on: Mar 4, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"Mcu_HW.h"
#include"USART_Private.h"
#include"USART_CONFIG.h"
#include"USART_Types.h"
#include"USART_Init.h"

//const UART_CONFIG ARR_UART_CFG_1[1]={{Baud_9600,Word_Size_8,Disabled,One_Stop_bit}};

void UART_Init(UART_CONFIG *Ptr_Copy_UART)
{
	UCSRC = 0b10000110;

	UBBRL = 51;
	//	UBBRH = Ptr_Copy_UART->Baud_NO >>8;


	/*Enable Transmitter*/
	SET_BIT(UCSRB,UCSRB_TXEN);
}


void UART_SendByte(u8 Copy_UART)
{

	//u8 counter=0;
	/*WAIT until transmit buffer is empty*/
	while((GET_BIT(UCSRA,UCSRA_UDRE))==0);
	UDR= Copy_UART;
	//while((GET_BIT(UCSRA,UCSRA_TXC))==0);
	//CLR_BIT(UCSRA,UCSRA_TXC);
}


void UART_SendString(UART_CONFIG Copy_UART,u8 *Ptr_To_String)
{

}
u8 UART_RecieveByteSynchNonBlocking(void)
{

	//u8 counter=0;
	/*wait until receive is complete*/
	while((GET_BIT(UCSRA,UCSRA_RXC))==0);
	return UDR;
}
void UART_RecieveByteASynchCallback(void)
{

}

