/*
 * LED_CFG.h
 *
 *  Created on: Feb 18, 2023
 *      Author: Dell
 */

#ifndef CONFIG_LED_CFG_H_
#define CONFIG_LED_CFG_H_

/*Please configure pins of leds from data sheet
 * LED_PIN Ex: DIO_PB7
 * Please config direction ( LED_FORWARD_DIR & LED_REVERSE_DIR )
 * */
#define LED_RED_PIN           DIO_PA0

#define LED_RED_DIR           LED_FORWARD_DIR

#define LED_GREEN_PIN         DIO_PA2

#define LED_GREEN_DIR         LED_FORWARD_DIR

#define LED_BLUE_PIN          DIO_PA1

#define LED_BLUE_DIR          LED_FORWARD_DIR

#define LED_YELLOW_PIN        DIO_PA6

#define LED_YELLOW_DIR        LED_FORWARD_DIR
#endif /* CONFIG_LED_CFG_H_ */
