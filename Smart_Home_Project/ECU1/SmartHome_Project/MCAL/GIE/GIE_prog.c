/*
 * GIE_prog.c
 *
 *  Created on: Feb 24, 2023
 *      Author: LENOVO
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_init.h"

void M_GIE_Void_Enable()
{
	SET_BIT(GLI_SREG, SREG_GIE);
}
void M_GIE_Void_Disable()
{
	CLR_BIT(GLI_SREG, SREG_GIE);
}
