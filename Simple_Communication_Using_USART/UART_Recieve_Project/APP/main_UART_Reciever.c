/*
 * main_UART.c
 *
 *  Created on: Mar 4, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"PORT/Port_int.h"
#include"CLCD/CLCD_Init.h"
#include"GIE/GIE_Interface.h"
#include"USART_CONFIG.h"
#include"USART/USART_Types.h"
#include"USART/USART_Init.h"
#include<util/delay.h>
extern const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE];
UART_CONFIG ARR_UART_CFG_3={Baud_16MHz_9600,Word_Size_8,Disabled,One_Stop_bit};

void Display_Received_data(void);
int main(void)
{
	Port_Init(PORT_Config_Arr);
	H_LCD_void_Init();
	UART_Init(&ARR_UART_CFG_3);
	UART_SetCallBack(Display_Received_data);
	GIE_voidEnable();


	while(1)
	{

	}
}

void Display_Received_data(void)
{
	u8 Received_Data=0;
	Received_Data=UART_RecieveByteASynchCallback();
	if(Received_Data!='\0' && Received_Data != 'A')
	{
		H_LCD_void_sendData(Received_Data);
	}
	else if(Received_Data=='A')
	{
		H_LCD_void_ClearDisplay();
	}
	else
	{
		//H_LCD_void_ClearDisplay();
	}
}

