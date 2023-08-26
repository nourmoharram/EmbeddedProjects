/*
 * main.c
 *
 *  Created on: MAR 7, 2023
 *      Author: Nour alaa
 */
#include"APP.h"
#include<util/delay.h>



int main(void)
{
	APP_Init();
	while(1)
	{
		APP_Start();
		_delay_ms(5000);
	}
}

