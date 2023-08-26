/*

 * Relay_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP lolo
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Dio_int.h"
#include "Port_int.h"
#include "Relay_Types.h"
#include "Relay_Cfg.h"
#include "Relay_Int.h"
#include "Relay_Priv.h"

void H_Relay_Void_WorkOn(Realy_Type relay)
{
	switch(relay)
	{
	case Relay_1:
		M_Dio_void_setPinValue(RELAY_1_PIN, DIO_HIGH);
	break;
	case Relay_2:
		M_Dio_void_setPinValue(RELAY_2_PIN, DIO_HIGH);
	break;
	}
}

void H_Relay_Void_WorkOff(Realy_Type relay)
{
	switch(relay)
	{
	case Relay_1:
		M_Dio_void_setPinValue(RELAY_1_PIN, DIO_LOW);
	break;
	case Relay_2:
		M_Dio_void_setPinValue(RELAY_2_PIN, DIO_LOW);
	break;
	}
}
