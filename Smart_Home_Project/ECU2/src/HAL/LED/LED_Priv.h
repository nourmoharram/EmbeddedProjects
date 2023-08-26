/*
 * LED_priv.h
 *
 *  Created on: Feb 18, 2023
 *      Author: ahmed
 */

#ifndef LED_LED_PRIV_H_
#define LED_LED_PRIV_H_

/******************************************
  INCLUDES
*******************************************/

/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
#define LED_FORWARD_DIR		1
#define LED_BACKWARD_DIR	0

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL DATA TYPES AND STRUCTURES
*******************************************/



/******************************************
   GLOBAL FUNCTIONS PROTOTYPES
*******************************************/

/******************************************
  syntax : Dio_LevelType M_Dio_en_getPinValue(Dio_ChannelType ChannelId);

  Description : read the pin state

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : Dio_HIGH or DIO_LOW
******************************************/


#endif /* LED_LED_PRIV_H_ */
