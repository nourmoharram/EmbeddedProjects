/*
 * SSD_CFG.h
 *
 *  Created on: Feb 18, 2023
 *      Author: Dell
 */

#ifndef CONFIG_SSD_CFG_H_
#define CONFIG_SSD_CFG_H_

/*
 * Please choose the SSD Pins to represent the number*/
#define SSD_A_PIN         DIO_PB0
#define SSD_B_PIN         DIO_PB1
#define SSD_C_PIN         DIO_PB2
#define SSD_D_PIN         DIO_PB4
/*enables for SSD circuits*/
#define SSD_DIG1_EN       DIO_PA3
#define SSD_DIG2_EN       DIO_PA2
#define SSD_DIG3_EN       DIO_PB5
#define SSD_DIG4_EN       DIO_PB6
/*SS Display time*/
#define SSD_DISPLAY_TIME         250 /*1000 msec = 1 sec*/
#endif /* CONFIG_SSD_CFG_H_ */
