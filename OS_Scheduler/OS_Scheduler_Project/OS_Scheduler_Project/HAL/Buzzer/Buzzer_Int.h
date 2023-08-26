/*
 * Buzzer_Int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP lolo
 */

#ifndef HAL_BUZZER_BUZZER_INT_H_
#define HAL_BUZZER_BUZZER_INT_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Buzzer_Cfg.h"
#include "Buzzer_Types.h"
/******************************************
   GLOBAL FUNCTIONS PROTOTYPES
*******************************************/

/******************************************
  syntax : void H_BUZZER_Void_TurnOn(void);


  Description : Write the pin value of buzzer high value

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  Non
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_BUZZER_Void_TurnOn(void);

/******************************************
  syntax : void H_BUZZER_Void_TurnOff(void);


  Description : Write the pin value of buzzer Low value

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  Non
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_BUZZER_Void_TurnOff(void);


#endif /* HAL_BUZZER_BUZZER_INT_H_ */
