/*
 * main_Finger_Print_v2.c
 *
 *  Created on: Mar 17, 2023
 *      Author: Dell
 */
/*
 * main_Finger_Print_v1.c
 *
 *  Created on: Mar 16, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"CLCD/CLCD_Init.h"
#include"FINGER_PRINT_CONFIG.h"
#include"FINGER_PRINT/FINGER_PRINT_Init.h"
#include<util/delay.h>

int main(void)
{
	H_LCD_void_Init();
	Finger_Print_Init();
	//Finger_Print_Enroll(0x01);
	//Finger_Print_Empty_Templates();

	//Finger_Print_Start(FB_Enrollement,Nour_Template);
//	_delay_ms(1000);
//	Finger_Print_Start(FB_Enrollement,Zedan_Template);
	//_delay_ms(1000);

	//Finger_Print_Start(FB_Enrollement,Nomrosi_Template);
//	_delay_ms(1000);

	//Finger_Print_Start(FB_Enrollement,Abo_7med_Template);
	//_delay_ms(1000);

	//Finger_Print_Enroll(Alaa_Template);
	while(1)
	{
		//Finger_Print_Match();
		//_delay_ms(3000);
	}

}


