/*
 * wifi_int.h
 *
 * Created: 3/11/2023 2:40:30 PM
 *  Author: ahmed57
 */ 


#ifndef WIFI_INT_H_
#define WIFI_INT_H_

#include "STD_TYPES.h"


void wifi_connect();
void Wifi_Buffer_Reset();
void Wifi_Response_Reciver_UART_CallBack();
void Check_Wifi_Respones(u8 *Wifi_Response , u8 *Error_Message);
u8 Wifi_Wait_Respones(u8 *Wifi_Response);
u8 Wifi_Wait_Data(u8 Wifi_Data);
void Wifi_Send_Data(u8 Data);
void Wifi_Send_Data2(u8 *Data);


#endif /* WIFI_INT_H_ */
