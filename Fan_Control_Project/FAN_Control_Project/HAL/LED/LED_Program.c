/*
 * LED_Program.c
 *
 *  Created on: Feb 18, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"DIO/Dio_int.h"

#include"LED_Private.h"
#include"LED_CFG.h"
#include"LED_Init.h"


void H_LED_void_Turn_on(u8 ledID)
{
	switch(ledID)
	{
	case LED_RED:
#if(LED_RED_DIR == LED_FORWARD_DIR)
		M_Dio_void_setPinValue(LED_RED_PIN,DIO_HIGH);
#elif(LED_RED_DIR == LED_REVERSE_DIR)
		M_Dio_void_setPinValue(LED_RED_PIN,DIO_LOW);
#else
#error("Wrong Led direction")
#endif
		break;
	case LED_GREEN:
#if(LED_GREEN_DIR == LED_FORWARD_DIR)
		M_Dio_void_setPinValue(LED_GREEN_PIN,DIO_HIGH);
#elif(LED_GREEN_DIR == LED_REVERSE_DIR)
		M_Dio_void_setPinValue(LED_GREEN_PIN,DIO_LOW);
#else
#error("Wrong Led direction")
#endif
		break;
	case LED_BLUE:
#if(LED_BLUE_DIR == LED_FORWARD_DIR)
		M_Dio_void_setPinValue(LED_BLUE_PIN,DIO_HIGH);
#elif(LED_BLUE_DIR == LED_REVERSE_DIR)
		M_Dio_void_setPinValue(LED_BLUE_PIN,DIO_LOW);
#else
#error("Wrong Led direction")
#endif
		break;
	case LED_YELLOW:
#if(LED_YELLOW_DIR == LED_FORWARD_DIR)
		M_Dio_void_setPinValue(LED_YELLOW_PIN,DIO_HIGH);
#elif(LED_YELLOW_DIR == LED_REVERSE_DIR)
		M_Dio_void_setPinValue(LED_YELLOW_PIN,DIO_LOW);
#else
#error("Wrong Led direction")
#endif
		break;

	}
}
void H_LED_void_Turn_off(u8 ledID)
{
	switch(ledID)
		{
		case LED_RED:
#if(LED_RED_DIR == LED_FORWARD_DIR)
		M_Dio_void_setPinValue(LED_RED_PIN,DIO_LOW);
#elif(LED_RED_DIR == LED_REVERSE_DIR)
		M_Dio_void_setPinValue(LED_RED_PIN,DIO_HIGH);
#else
#error("Wrong Led direction")
#endif
		break;
		case LED_GREEN:
#if(LED_GREEN_DIR == LED_FORWARD_DIR)
		M_Dio_void_setPinValue(LED_GREEN_PIN,DIO_LOW);
#elif(LED_GREEN_DIR == LED_REVERSE_DIR)
		M_Dio_void_setPinValue(LED_GREEN_PIN,DIO_HIGH);
#else
#error("Wrong Led direction")
#endif
		break;
		case LED_BLUE:
#if(LED_BLUE_DIR == LED_FORWARD_DIR)
		M_Dio_void_setPinValue(LED_BLUE_PIN,DIO_LOW);
#elif(LED_BLUE_DIR == LED_REVERSE_DIR)
		M_Dio_void_setPinValue(LED_BLUE_PIN,DIO_HIGH);
#else
#error("Wrong Led direction")
#endif
		break;
		case LED_YELLOW:
#if(LED_YELLOW_DIR == LED_FORWARD_DIR)
		M_Dio_void_setPinValue(LED_YELLOW_PIN,DIO_LOW);
#elif(LED_YELLOW_DIR == LED_REVERSE_DIR)
		M_Dio_void_setPinValue(LED_YELLOW_PIN,DIO_HIGH);
#else
#error("Wrong Led direction")
#endif
		break;

		}
}

void H_LED_void_Toggle(u8 ledID)
{
	switch(ledID)
	{
		case LED_RED:
			M_Dio_void_togglePinValue(LED_RED_PIN);
		break;
		case LED_GREEN:
			M_Dio_void_togglePinValue(LED_GREEN_PIN);
		break;
		case LED_BLUE:
			M_Dio_void_togglePinValue(LED_BLUE_PIN);
		break;
		case LED_YELLOW:
			M_Dio_void_togglePinValue(LED_YELLOW_PIN);
		break;

	}
}
