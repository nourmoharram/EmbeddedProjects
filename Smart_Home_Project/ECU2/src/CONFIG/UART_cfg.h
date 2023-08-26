/*
 * UART_cfg.h
 *
 * Created: 3/4/2023 8:56:53 AM
 *  Author: ahmed57
 */ 


#ifndef UART_CFG_H_
#define UART_CFG_H_

#include "Port_Types.h"
#include "Port_cfg.h"
#include "UART_types.h"

/* set time out for non blocking functions */
static volatile u32 Time_Out2 = 200;


typedef struct{
	
	UART_BaudeRate_Select_t  BuadRate;
	UART_Word_Size			 WordSize;
	UART_Parity_Mode_Select  PairtyMode;
	UART_Stop_Bit_Select	 StopBitNum;

}UART_Config_t;



/* Pin Configuration */
typedef struct {
	Port_PinType             Port_PinNumber; //PA0 or PA1...etc
	Port_LevelType           Port_PinLevelValue;// initial value of pin
	Port_PinDirectionType    Port_PinDirection; // input or output
	Port_InternalAttachType  Port_PinInternalAttach;//pull up or floating

}UART_Port_Config;



#endif /* UART_CFG_H_ */