/*
 * Relay_Int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: HP lolo
 */

#ifndef HAL_RELAY_RELAY_INT_H_
#define HAL_RELAY_RELAY_INT_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Relay_Cfg.h"
#include "Relay_Types.h"

/******************************************
   GLOBAL FUNCTIONS PROTOTYPES
*******************************************/

/******************************************
  syntax : void H_Relay_Void_WorkOn(Realy_Type relay);


  Description : Write the pin value of relay high value
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  relay num
  parameters (out) :  Non
  Return Value     : void
******************************************/

void H_Relay_Void_WorkOn(Realy_Type relay);
/******************************************
  syntax : void H_Relay_Void_WorkOff(Realy_Type relay);


  Description : Write the pin value of relay low value
  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  relay Num
  parameters (out) :  Non
  Return Value     : void
******************************************/
void H_Relay_Void_WorkOff(Realy_Type relay);

#endif /* HAL_RELAY_RELAY_INT_H_ */
