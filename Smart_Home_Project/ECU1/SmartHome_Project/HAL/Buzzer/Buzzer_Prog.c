/*

 * Buzzer_Prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP lolo
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Dio_int.h"
#include "Port_int.h"
#include "Buzzer_Cfg.h"
#include "Buzzer_Int.h"
#include "Buzzer_Types.h"
#include "Buzzer_Priv.h"

void H_BUZZER_Void_TurnOn(void)
{
	M_Dio_void_setPinValue(BUZZER_1_PIN, DIO_HIGH);
}
void H_BUZZER_Void_TurnOff(void)
{
	M_Dio_void_setPinValue(BUZZER_1_PIN, DIO_LOW);
}


