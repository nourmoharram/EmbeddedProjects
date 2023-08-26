/*
 * LED_Init.h
 *
 *  Created on: Feb 18, 2023
 *      Author: Dell
 */

#ifndef HAL_LED_LED_INIT_H_
#define HAL_LED_LED_INIT_H_


#define LED_RED    0
#define LED_BLUE   1
#define LED_GREEN  2
#define LED_YELLOW 3
void H_LED_void_Turn_on(u8 ledID);
void H_LED_void_Turn_off(u8 ledID);

void H_LED_void_Toggle(u8 ledID);


#endif /* HAL_LED_LED_INIT_H_ */
