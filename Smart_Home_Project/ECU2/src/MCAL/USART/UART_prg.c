/*
 * UART_prg.c
 *
 * Created: 3/4/2023 8:56:16 AM
 *  Author: ahmed57
 */ 

#include "UART_priv.h"
#include "UART_int.h"
#include "BIT_MATH.h"
#include <avr/interrupt.h>
#include <util/delay.h>

static void(*UART_CallBack)(void) = NULL;


void UART_Init(UART_Config_t  UART_CONFIG)
{
		
	/* Set baud rate  */
	//PtrUBRRL->UBRRL_BIT = UART_CONFIG.BuadRate;
	PtrUBRRL->UBRRL_BIT =8;


	/* Select parity mode */
	//PtrUCSRC->UPM_BIT = UART_CONFIG.PairtyMode;
	
	/* select stop bits */
	//PtrUCSRC->USBS_BIT = UART_CONFIG.StopBitNum;
	
	/* select word size "not more than 8bits "*/
	
	//PtrUCSRC->UCSZ_BIT = UART_CONFIG.WordSize;
	
	UART_UCSRC_REG = 0X86;

	
	//PtrUBRRH->UBRRH_BIT =0;
	
	/* Enable Tx  */
	PtrUCSRB->TXEN_BIT = Enable;
	
	/* Enable Rx  */
	PtrUCSRB->RXEN_BIT = Enable;
    PtrUCSRB->RXCIE_BIT = Enable;
}

void UART_sendByte( u8 Data)
{
	
	/* Enable Tx  */
	PtrUCSRB->TXEN_BIT = Enable;
	
	while(PtrUCSRA->UDRE_BIT == 0);
	
	/* write data to UDR register  */
	PtrUDR->UDR_REG = Data;
}

void UART_sendString(u8 *String)
{
	while(*String != '\0')
	{
		PtrUDR->UDR_REG =*String;
		/* wait until UDR reg is ready to write new data  */
		while(PtrUCSRA->UDRE_BIT == 0);
		
		String++;
	}
	
	//PtrUDR->UDR_REG = '\0';
}


void UART_receiveByteSynchNonBlocking(u8 *data)
{
	/*
	while(PtrUCSRA->RXC_BIT == 0 && Time_Out2 > 0)
	{
		Time_Out2--;
	}
	*/
	while(PtrUCSRA->RXC_BIT == 0);

	*data = PtrUDR->UDR_REG;
}

volatile u8 Time_Out3 = 200;


u8 UART_receiveByteSynchNonBlocking2()
{

	while(PtrUCSRA->RXC_BIT == 0 && Time_Out3 > 0)
	{
		Time_Out3--;
		_delay_us(5);
	}

	return UART_UDR_REG;
}


/**************************************************/
void UART_Set_CallBack(void (*PtrFun)(void))
{
	if(PtrFun != NULL)
	{
		UART_CallBack = PtrFun;
	}
}


/******************************/
ISR(USART_RXC_vect)
{
		
	if(UART_CallBack != NULL)
	{
		UART_CallBack();
	}
	
}

