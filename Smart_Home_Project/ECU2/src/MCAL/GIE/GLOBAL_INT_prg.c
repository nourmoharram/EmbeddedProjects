/*
 * GLOBAL_INT_prg.c
 *
 *  Created on: Feb 24, 2023
 *      Author: ahmed57
 */

//#include "Mcu_HW.h"
#include "BIT_MATH.h"
#include "GLOBAL_INT_priv.h"
#include "GLOBAL_INT_int.h"

void M_vEnable_Global_Interrupts()
{
	SET_BIT(GLOBAL_INT_SREG, 7);
}
void M_vDisable_Global_Interrupts()
{
	CLR_BIT(GLOBAL_INT_SREG, 7);
}
