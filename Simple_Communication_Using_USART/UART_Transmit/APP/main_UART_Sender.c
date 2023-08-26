/*
 * main_UART.c
 *
 *  Created on: Mar 4, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"PORT/Port_int.h"
#include"KPD/KPD_Init.h"
#include"USART_CONFIG.h"
#include"USART/USART_Types.h"
#include"USART/USART_Init.h"
#include<util/delay.h>
extern const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE];
UART_CONFIG ARR_UART_CFG_3={Baud_16MHz_9600,Word_Size_8,Disabled,One_Stop_bit};


int main(void)
{
	u8 Local_variable='8';
	char str[]="HI From MC1";
	u8 Clear='\0';
	Port_Init(PORT_Config_Arr);
	UART_Init(&ARR_UART_CFG_3);
	//UART_SendString(str);
	//_delay_ms(1000);
	//UART_SendByte(Clear);
	while(1)
	{
		Local_variable=H_KEYPAD_u8_getPressedKey();
		UART_SendByte(Local_variable);
	}
}





