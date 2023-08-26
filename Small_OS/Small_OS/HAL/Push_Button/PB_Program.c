/*
 * PB_Program.c
 *
 *  Created on: Feb 18, 2023
 *      Author: Dell
 */


#include"STD_TYPES.h"
#include"DIO/Dio_int.h"
#include<util/delay.h>
#include"PB_Private.h"
#include"PB_Types.h"
#include"PB_CFG.h"
#include"PB_Init.h"

PB_State H_readPB(PB_ID PushBID,PB_ActiveType Mode)
{
	PB_State Button_state=PB_RELEASED;
	Dio_LevelType Local_pin_value;
	switch(PushBID)
	{
	case PB_ID1:
#if(Mode == PB_ACTIVE_LOW)
		Local_pin_value=M_Dio_en_getPinValue(PB_SW1);
		if(Local_pin_value==PB_PRESSED_ACTL)
		{
			_delay_ms(50);
			while(Local_pin_value==PB_PRESSED_ACTL)
			{
				Local_pin_value=M_Dio_en_getPinValue(PB_SW1);
			}
			Button_state=PB_PRESSED;
		}
#elif(Mode== PB_ACTIVE_HIGH)
	Local_pin_value= M_Dio_en_getPinValue(PB_SW1);
	if(Local_pin_value==PB_PRESSED_ACTH)
	{
		while(Local_pin_value==PB_PRESSED_ACTH)
		{
			Local_pin_value=M_Dio_en_getPinValue(PB_SW1);
		}
		Button_state=PB_PRESSED;
	}
#else
#error("Wrong Activation Mode")
#endif
	break;
	case PB_ID2:
#if(Mode == PB_ACTIVE_LOW)
			Local_pin_value=M_Dio_en_getPinValue(PB_SW2);
			if(Local_pin_value==PB_PRESSED_ACTL)
			{
				while(Local_pin_value==PB_PRESSED_ACTL)
				{
					Local_pin_value=M_Dio_en_getPinValue(PB_SW2);
				}
				Button_state=PB_PRESSED;
			}
#elif(Mode== PB_ACTIVE_HIGH)
		Local_pin_value= M_Dio_en_getPinValue(PB_SW2);
		if(Local_pin_value==PB_PRESSED_ACTH)
		{
			while(Local_pin_value==PB_PRESSED_ACTH)
			{
				Local_pin_value=M_Dio_en_getPinValue(PB_SW2);
			}
			Button_state=PB_PRESSED;
		}

#else
#error("Wrong Activation Mode")
#endif
		break;
		case PB_ID3:
#if(Mode == PB_ACTIVE_LOW)
		Local_pin_value=M_Dio_en_getPinValue(PB_SW3);
		if(Local_pin_value==PB_PRESSED_ACTL)
		{
			while(Local_pin_value==PB_PRESSED_ACTL)
			{
				Local_pin_value=M_Dio_en_getPinValue(PB_SW3);
			}
			Button_state=PB_PRESSED;
		}
#elif(Mode== PB_ACTIVE_HIGH)
	Local_pin_value= M_Dio_en_getPinValue(PB_SW3);
	if(Local_pin_value==PB_PRESSED_ACTH)
	{
		while(Local_pin_value==PB_PRESSED_ACTH)
		{
			Local_pin_value=M_Dio_en_getPinValue(PB_SW3);
		}

		Button_state=PB_PRESSED;
	}

#else
#error("Wrong Activation Mode")
#endif
	break;
	case PB_ID4:
#if(Mode == PB_ACTIVE_LOW)
		Local_pin_value=M_Dio_en_getPinValue(PB_SW4);
		if(Local_pin_value==PB_PRESSED_ACTL)
		{
			while(Local_pin_value==PB_PRESSED_ACTL)
			{
				Local_pin_value=M_Dio_en_getPinValue(PB_SW4);
			}
			Button_state=PB_PRESSED;
		}
#elif(Mode== PB_ACTIVE_HIGH)
	Local_pin_value= M_Dio_en_getPinValue(PB_SW4);
	if(Local_pin_value==PB_PRESSED_ACTH)
	{
		while(Local_pin_value==PB_PRESSED_ACTH)
		{
			Local_pin_value=M_Dio_en_getPinValue(PB_SW4);
		}
		Button_state=PB_PRESSED;
	}
	}
#else
#error("Wrong Activation Mode")
#endif
	break;
	}
	return Button_state;
}


