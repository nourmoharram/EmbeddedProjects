/*
 * LED_prog.c
 *
 *  Created on: Feb 18, 2023
 *      Author: ahmed
 */
/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mcu_HW.h"
#include "Dio_int.h"
#include "TIMER_1_Types.h"
#include "TIMER_1_Init.h"
#include "LED_priv.h"
#include "LED_cfg.h"
#include "LED_int.h"



/******************************************
  Local Data (static global )
*******************************************/



/******************************************
  Global Data (non static global)
*******************************************/





/******************************************
  Local Functions body
*******************************************/


/******************************************
  Global Functions body
*******************************************/

/******************************************
  syntax : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

  Description : read the pin state

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : Dio_HIGH or DIO_LOW
******************************************/
void H_LED_void_turnOn(u8 ledID){
	switch (ledID){
	case LED_RED :
#if (LED_RED_DIRECTION == LED_FORWARD_DIR)
		M_Dio_void_setPinValue(LED_RED_PIN,DIO_HIGH);
#elif(LED_RED_DIRECTION == LED_BACKWARD_DIR)
		 M_DIO_void_setPinValue(LED_RED_PIN,DIO_LOW);

#else

	#error("Wrong LED direction")

#endif
		break;

	case LED_GREEN:
#if	(LED_GREEN_DIRECTION ==	LED_FORWARD_DIR)
		M_Dio_void_setPinValue(LED_GREEN_PIN,DIO_HIGH);
#elif(LED_GREEN_DIRECTION == LED_BACKWARD_DIR)
		M_DIO_void_setPinValue(LED_GREEN_PIN,DIO_LOW);
#else

	#error("Wrong LED direction")

#endif
		break;
	case LED_BLUE:
#if	(LED_BLUE_DIRECTION ==LED_FORWARD_DIR)
		M_Dio_void_setPinValue(LED_BLUE_PIN,DIO_HIGH);
#elif(LED_BLUE_DIRECTION == LED_BACKWARD_DIR)
		M_DIO_void_setPinValue(LED_BLUE_PIN,DIO_LOW);

#else

	#error("Wrong LED direction")

#endif
		break;

	case LED_YELLOW:
#if	(LED_YELLOW_DIRECTION ==LED_FORWARD_DIR)
		M_Dio_void_setPinValue(LED_YELLOW_PIN,DIO_HIGH);
#elif(LED_YELLOW_DIRECTION == LED_BACKWARD_DIR)
		 M_DIO_void_setPinValue(LED_YELLOW_PIN,DIO_LOW);

#else

	#error("Wrong LED direction")

#endif
		break;
	}

}

/******************************************
  syntax : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

  Description : read the pin state

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : Dio_HIGH or DIO_LOW
******************************************/
void H_LED_void_turnOff(u8 ledID){
	switch (ledID){
	case LED_RED :
#if (LED_RED_DIRECTION == LED_FORWARD_DIR)
		M_Dio_void_setPinValue(LED_RED_PIN,DIO_LOW);
#elif(LED_RED_DIRECTION == LED_BACKWARD_DIR)
		M_Dio_void_setPinValue(LED_RED_PIN,DIO_HIGH);

#else

	#error("Wrong LED direction")

#endif
		break;

	case LED_GREEN:
#if	(LED_GREEN_DIRECTION ==	LED_FORWARD_DIR)
		M_Dio_void_setPinValue(LED_GREEN_PIN,DIO_LOW);
#elif(LED_GREEN_DIRECTION == LED_BACKWARD_DIR)
		 M_Dio_void_setPinValue(LED_GREEN_PIN,DIO_HIGH);
#else

	#error("Wrong LED direction")

#endif
		break;
	case LED_BLUE:
#if	(LED_BLUE_DIRECTION ==LED_FORWARD_DIR)
		M_Dio_void_setPinValue(LED_BLUE_PIN,DIO_LOW);
#elif(LED_BLUE_DIRECTION == LED_BACKWARD_DIR)
		 M_Dio_void_setPinValue(LED_BLUE_PIN,DIO_HIGH);

#else

	#error("Wrong LED direction")

#endif
		break;

	case LED_YELLOW:
#if	(LED_YELLOW_DIRECTION ==LED_FORWARD_DIR)
		M_Dio_void_setPinValue(LED_YELLOW_PIN,DIO_LOW);
#elif(LED_YELLOW_DIRECTION == LED_BACKWARD_DIR)
		 M_Dio_void_setPinValue(LED_YELLOW_PIN,DIO_HIGH);

#else

	#error("Wrong LED direction")

#endif
		break;
	}

}

/******************************************
  syntax : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

  Description : read the pin state

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : Dio_HIGH or DIO_LOW
******************************************/
void H_LED_void_toggle(u8 ledID){
	switch(ledID){
	case LED_RED:
		M_Dio_void_togglePinValue(LED_RED_PIN);
		break;
	case LED_BLUE:
		M_Dio_void_togglePinValue(LED_BLUE_PIN);
			break;
	case LED_GREEN:
		M_Dio_void_togglePinValue(LED_GREEN_PIN);
			break;
	case LED_YELLOW:
		M_Dio_void_togglePinValue(LED_YELLOW_PIN);
			break;
	}

}

void H_LED_void_set_Intensity(u16 copy_Intensity){
	M_TIMER1_void_FastPWM(copy_Intensity);
	M_TIMER1_void_Start(TIMER1_CLK_8);
}
