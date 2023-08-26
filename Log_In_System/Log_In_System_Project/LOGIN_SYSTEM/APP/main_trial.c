/*
 * main.c
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"Port_cfg.h"
#include"PORT/Port_int.h"
#include"GIE/GIE_Interface.h"
#include"ULTRA_SONIC/UtraSonic_init.h"
#include"CLCD/CLCD_Init.h"
#include<util/delay.h>
extern const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE];

int main(void)
{
	u16 distance=0;

	Port_Init(PORT_Config_Arr);
	H_LCD_void_Init();
	GIE_voidEnable();
	Ultrasonic_init();
	while(1)
	{
		distance = Ultrasonic_readDistance();
		//distance /= 10;
		H_LCD_void_sendIntNum(distance);
		_delay_ms(100);
		H_LCD_void_ClearDisplay();

	}

}
