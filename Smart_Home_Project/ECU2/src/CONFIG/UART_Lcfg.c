/*
 * UART_Lcfg.c
 *
 * Created: 3/4/2023 8:56:39 AM
 *  Author: ahmed57
 */ 

#include "UART_cfg.h"

const UART_Config_t UART_CONFIG2 = {Baud_9600,
									Word_Size_8BIT,
									Even_Parity,
									Stop_2BIT};
									
									
const UART_Port_Config UART_PORT_Config[2] ={
	{PORT_PD0,
	PORT_PIN_LEVEL_LOW,
	PORT_PINDIR_INPUT,
	PORT_PIN_IN_ATTATCH_FLOATING},
	
	{PORT_PD1,
	PORT_PIN_LEVEL_LOW,
	PORT_PINDIR_OUTPUT,
	PORT_PIN_IN_ATTATCH_FLOATING}
	
									};