/*
 * LED_int.h
 *
 *  Created on: Feb 18, 2023
 *      Author: ahmed
 */

#ifndef LED_LED_INT_H_
#define LED_LED_INT_H_
/******************************************
  INCLUDES
*******************************************/
/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
#define LED_RED		0
#define LED_BLUE	1
#define LED_GREEN	2
#define LED_YELLOW	3

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
void H_LED_void_turnOn(u8 ledID);

/******************************************
  syntax : Dio_LevelType M_Dio_en_getPinValue(Dio_ChannelType ChannelId);

  Description : read the pin state

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : Dio_HIGH or DIO_LOW
******************************************/
void H_LED_void_turnOff(u8 ledID);

/******************************************
  syntax : Dio_LevelType M_Dio_en_getPinValue(Dio_ChannelType ChannelId);

  Description : read the pin state

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : Dio_HIGH or DIO_LOW
******************************************/
void H_LED_void_toggle(u8 ledID);

void H_LED_void_set_Intensity(u16 copy_Intensity);


#endif /* LED_LED_INT_H_ */
