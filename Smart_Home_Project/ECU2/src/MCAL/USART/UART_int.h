/*
 * UART_int.h
 *
 * Created: 3/4/2023 8:55:24 AM
 *  Author: ahmed57
 */ 


#ifndef UART_INT_H_
#define UART_INT_H_

#include "STD_TYPES.h"
#include "UART_cfg.h"


#define UART_BUFFER_SIZE 60
static volatile char Rx_Buffer_UART[UART_BUFFER_SIZE + 1];
 
static volatile u8 RX_Wr_Index_UART =0;
static volatile u8 RX_Rd_Index_UART =0;

static volatile u8 RX_Counter_UART =0; //a total count of characters in the buff
static volatile u8 RX_Buffer_Overflow_UART; // This flag is set on USART Receiver

void UART_Init(UART_Config_t  UART_CONFIG);

void UART_sendByte( u8 Data);

void UART_sendString(u8 *String);

void UART_receiveByteSynchNonBlocking(u8 *data);
u8 UART_receiveByteSynchNonBlocking2();

u8 UART_receiveStringWifi(u8 *data);

u8 UART_receiveByteAsynchCallBack();

void UART_Set_CallBack(void (*PtrFun)(void));

char M_UART_u8_receiveByteASynchNonBlocking(void) ;

#endif /* UART_INT_H_ */
