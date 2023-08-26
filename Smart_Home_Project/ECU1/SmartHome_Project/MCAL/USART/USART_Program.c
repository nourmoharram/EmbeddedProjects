/*
 * USART_Program.c
 *
 *  Created on: Mar 4, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"USART_Private.h"
#include"USART_CONFIG.h"
#include"USART_Types.h"
#include"USART_Init.h"
#include<util/delay.h>

static void (*USART_PTR_FUNC)(void) =NULL;

void UART_Init(UART_CONFIG *Ptr_Copy_UART)
{
	/*u8 variable to carry the values of UCSRC Register*/
	u8 Local_UCSRC=0;

	/*Select Asynchronous mode*/
	Local_UCSRC &= UCSRC_UMSEL_ASYNCH_MASK_Clear;
	/*Clear UCPOL bit in UCSRC*/
	Local_UCSRC &= UCSRC_UCPOL_CLEAR_MASK;
	switch(Ptr_Copy_UART->Baud_NO)
	{
	case Baud_16MHz_2400:
		//UBBRL=Baud_16MHz_2400;
		break;
	case Baud_16MHz_4800:
		UBBRL= Baud_16MHz_4800;
		break;
	case Baud_16MHz_9600:
		//UBBRL=Baud_16MHz_9600;
		UBBRL =8;
		break;
	case Baud_16MHz_57600:
		UBBRL= 16;
		break;
	default:
		break;
	}
	switch(Ptr_Copy_UART->Word_size)
	{
	case Word_Size_5:
		CLR_BIT(Local_UCSRC,UCSRC_UCSZ0);
		CLR_BIT(Local_UCSRC,UCSRC_UCSZ1);
		CLR_BIT(UCSRB,UCSRB_UCSZ2);
		break;
	case Word_Size_6:
		SET_BIT(Local_UCSRC,UCSRC_UCSZ0);
		CLR_BIT(Local_UCSRC,UCSRC_UCSZ1);
		CLR_BIT(UCSRB,UCSRB_UCSZ2);
		break;
	case Word_Size_7:
		CLR_BIT(Local_UCSRC,UCSRC_UCSZ0);
		SET_BIT(Local_UCSRC,UCSRC_UCSZ1);
		CLR_BIT(UCSRB,UCSRB_UCSZ2);
		break;
	case Word_Size_8:
		SET_BIT(Local_UCSRC,UCSRC_UCSZ0);
		SET_BIT(Local_UCSRC,UCSRC_UCSZ1);
		CLR_BIT(UCSRB,UCSRB_UCSZ2);
		break;
	case Word_Size_9:
		SET_BIT(Local_UCSRC,UCSRC_UCSZ0);
		SET_BIT(Local_UCSRC,UCSRC_UCSZ1);
		SET_BIT(UCSRB,UCSRB_UCSZ2);
		break;
	default:
		break;
	}
	switch(Ptr_Copy_UART->Parity_type)
	{
	case Disabled:
		Local_UCSRC &= PARITYBITS_MASK_CLEAR;
		break;
	case Enabled_Even_Parity:
		Local_UCSRC &= PARITYBITS_MASK_CLEAR;
		Local_UCSRC |= PARITYBITS_EVEN_MASK_SET;
		break;
	case Enabled_Odd_Parity:
		Local_UCSRC &= PARITYBITS_MASK_CLEAR;
		Local_UCSRC |= PARITYBITS_ODD_MASK_SET;
		break;
	default:
		break;
	}
	switch(Ptr_Copy_UART->Stop_bits_no)
	{
	case One_Stop_bit:
		Local_UCSRC &= STOP_BIT_CLEAR_1bit_MASK;
		break;
	case Two_Stop_Bit:
		Local_UCSRC &= STOP_BIT_CLEAR_1bit_MASK;
		Local_UCSRC |= STOP_BIT_2bit_SET_MASK;
		break;
	default:
		break;
	}
	/*Set the selection bit to select UCSRC Register*/
	Local_UCSRC &= UCSRC_URSEL_REGSELECT_CLEAR;
	Local_UCSRC |= UCSRC_URSEL_REGSELECT_SET;
	/*Set the UCSRC Register with the Local register*/
	UCSRC = Local_UCSRC;
	//UCSRC = 0b10000110;

	//UBBRL = 51;
	//	UBBRH = Ptr_Copy_UART->Baud_NO >>8;


	/*Enable Transmitter*/
	SET_BIT(UCSRB,UCSRB_TXEN);
	/*Enable Receive interrupt*/
	SET_BIT(UCSRB,UCSRB_RXCIE);
	/*Enable receiver*/
	SET_BIT(UCSRB,UCSRB_RXEN);
}


void UART_SendByte(u8 Copy_UART)
{

	//u8 counter=0;
	/*WAIT until transmit buffer is empty*/
	while((GET_BIT(UCSRA,UCSRA_UDRE))==0);
	UDR= Copy_UART;

}


void UART_SendString(u8 *Ptr_To_String)
{
	u8 i=0;
	for(i=0;Ptr_To_String[i] != '\0';i++)
	{
		//_delay_ms(500);
		UART_SendByte(Ptr_To_String[i]);
	}

}
u8 UART_RecieveByteSynchNonBlocking(void)
{

	u8 counter=0;
	/*wait until receive is complete*/
	while((GET_BIT(UCSRA,UCSRA_RXC))==0 && counter <MAX_DELAY)
	{
		counter++;
	}
	return UDR;
}
u8 UART_RecieveByteASynchCallback(void)
{
	return UDR;

}

u8 UART_SetCallBack(void (*Copy_pvINTFunc)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_pvINTFunc != NULL)
	{
		USART_PTR_FUNC=Copy_pvINTFunc;
	}

	return Local_u8ErrorStatus;
}
void __vector_13 (void)  __attribute__((signal));
void __vector_13 (void)
{

	if(USART_PTR_FUNC != NULL)
	{
		USART_PTR_FUNC();
	}
	else
	{
		/*Stop*/
	}
}

