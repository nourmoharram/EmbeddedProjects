/*
 * GIE_Program.c
 *
 *  Created on: Oct 23, 2022
 *      Author: Dell
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"../Mcu_HW.h"

void GIE_voidEnable(void)
{
	//Enable GIE for External interrupt
	SET_BIT(SREG,SREG_I);
}
void GIE_voidDisable(void)
{
	//Disable GIE for external Interrupt
	CLR_BIT(SREG,SREG_I);
}
