/*
 * Port_Lcfg.c
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */

/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : Port_Lcfg.c
*  Module   : PORT
*  breif    : Config file for PORT Driver
*
*****************************************************************
*/
/******************************************
  INCLUDES
*******************************************/
#include "Std_Types.h"
#include "Port_Types.h"
#include "Port_Cfg.h"


/******************************************
  Local Macros / Functions
*******************************************/


/******************************************
  Local Data
*******************************************/

/******************************************
  Global Data
*******************************************/

const Port_ConfigType PORT_Config_Arr[]= {

											   /*UART*/
											   {PORT_PD0,
											   	PORT_PIN_LEVEL_LOW,
											   	PORT_PINDIR_INPUT,
											   	PORT_PIN_IN_ATTATCH_FLOATING},
											   	{PORT_PD1,
											   	PORT_PIN_LEVEL_LOW,
											   	PORT_PINDIR_OUTPUT,
											   	PORT_PIN_IN_ATTATCH_FLOATING},

												/*timer0*/
									           {PORT_PB3,
									           	PORT_PIN_LEVEL_LOW,
									           	PORT_PINDIR_OUTPUT,
									           	PORT_PIN_IN_ATTATCH_FLOATING},
												   
												/*timer1*/
												{PORT_PD5,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												
												/*motor*/
												{PORT_PB3,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PB5,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PB6,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},

												/*LDR*/
												{PORT_PA0,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_INPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},

												/*LM35*/
												{PORT_PA1,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_INPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},

												/*LEDS*/
												{PORT_PB7,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PA4,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PA5,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PA6,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},

												/*LCD*/
												{PORT_PA2,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PA3 ,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PB0,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PB1,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PB2,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
												{PORT_PB4,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_OUTPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},

												/*EXTI*/
												{PORT_PD2,
												PORT_PIN_LEVEL_LOW,
												PORT_PINDIR_INPUT,
												PORT_PIN_IN_ATTATCH_FLOATING},
			
																				};




/* Pushbutton Pins */
/*
{PORT_PD3,
 PORT_PIN_LEVEL_LOW,
	PORT_PINDIR_INPUT,
   PORT_PIN_IN_ATTATCH_PULLUP},

{PORT_PD5,
 PORT_PIN_LEVEL_LOW,
	PORT_PINDIR_INPUT,
PORT_PIN_IN_ATTATCH_PULLUP},

{PORT_PD6,
 PORT_PIN_LEVEL_LOW,
	PORT_PINDIR_INPUT,
PORT_PIN_IN_ATTATCH_PULLUP},

{PORT_PD7,
 PORT_PIN_LEVEL_LOW,
   PORT_PINDIR_INPUT,
PORT_PIN_IN_ATTATCH_PULLUP},

*/

/* LCD Pins */
/*

											   */
