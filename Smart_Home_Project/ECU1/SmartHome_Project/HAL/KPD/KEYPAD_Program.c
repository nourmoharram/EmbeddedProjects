/*
 * KEYPAD_Program.c
 *
 *  Created on: Feb 23, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"Dio_int.h"
#include"KPD_Private.h"
#include"KPD_CFG.h"
#include"KPD_Types.h"
#include"KPD_Init.h"
#include"CLCD_Init.h"
#include<util/delay.h>

/*Pre-Build Configuration for the KEYPAD Mode*/
#if(KPD_MODE == Calculator)
	static u8 KPD_KEYS_CALC[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
#elif(KPD_MODE == Normal)
	static s32 KPD_KEYS_NORM[4][4]= {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
#endif

u8 ROWS_ARR[4]={KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN};

u8 COLS_ARR[4]={KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN};
/******************************************
  syntax :u8 H_KEYPAD_u8_getPressedKey(void)


  Description : Scan the putton pressed from keypad

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : void
******************************************/
u8 H_KEYPAD_u8_getPressedKey(void)
{
	u8 Local_Pressed_key=NO_PRESSED_KEY;
	u8 ROW_Index;
	u8 COL_Index;
	for(ROW_Index=0;ROW_Index<4;ROW_Index++)
	{
		M_Dio_void_setPinValue(ROWS_ARR[0], DIO_HIGH);
		M_Dio_void_setPinValue(ROWS_ARR[1], DIO_HIGH);
		M_Dio_void_setPinValue(ROWS_ARR[2], DIO_HIGH);
		M_Dio_void_setPinValue(ROWS_ARR[3], DIO_HIGH);

		M_Dio_void_setPinValue(ROWS_ARR[ROW_Index],DIO_LOW);
		for(COL_Index=0;COL_Index<4;COL_Index++)
		{
			if((M_Dio_en_getPinValue(COLS_ARR[COL_Index]))==DIO_LOW)
			{
				_delay_ms(50);
				while(M_Dio_en_getPinValue(COLS_ARR[COL_Index])==DIO_LOW);
				Local_Pressed_key= KPD_KEYS_CALC[ROW_Index][COL_Index];
				//M_Dio_void_setPinValue(DIO_PB7,DIO_HIGH);
				//_delay_ms(50);
				//M_Dio_void_setPinValue(DIO_PB7,DIO_LOW);
				return Local_Pressed_key;
			}
		}
	}
	return Local_Pressed_key;
}

