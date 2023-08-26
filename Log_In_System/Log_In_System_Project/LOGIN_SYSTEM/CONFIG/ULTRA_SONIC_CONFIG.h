/*
 * ULTRA_SONIC_CONFIG.h
 *
 *  Created on: Mar 1, 2023
 *      Author: Dell
 */

#ifndef CONFIG_ULTRA_SONIC_CONFIG_H_
#define CONFIG_ULTRA_SONIC_CONFIG_H_
#define TRIGGER_PIN_OUT      DIO_PD0
#define ECHO_PIN_IN          DIO_PD6

#include"TIMER1/TIMER_1_Types.h"

#define FAILLING_EDGE         0
#define RISING_EDGE           1

#define SPEED_OF_SOUND        34300


#endif /* CONFIG_ULTRA_SONIC_CONFIG_H_ */
