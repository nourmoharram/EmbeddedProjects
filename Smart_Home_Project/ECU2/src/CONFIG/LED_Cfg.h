/*
 * LED_cfg.h
 *
 *  Created on: Feb 18, 2023
 *      Author: ahmed
 */

#ifndef LED_CFG_H_
#define LED_CFG_H_

/******************************************
  INCLUDES
*******************************************/

/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
/*please  configure pins of the leds
 * LED pin to be for example:DIO_PB7
 *
 * please configure direction
 * LED_FORWAROD_DIR
 * LED_BACKWAROD_DIR */

#define LED_RED_PIN				DIO_PB7
#define LED_RED_DIRECTION		LED_FORWARD_DIR

#define LED_GREEN_PIN			DIO_PA4
#define LED_GREEN_DIRECTION		LED_FORWARD_DIR

#define LED_BLUE_PIN			DIO_PA5
#define LED_BLUE_DIRECTION		LED_FORWARD_DIR

#define LED_YELLOW_PIN			DIO_PA6
#define LED_YELLOW_DIRECTION	LED_FORWARD_DIR

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

#endif /* LED_CFG_H_ */
