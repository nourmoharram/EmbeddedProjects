/*
 * PB_CFG.h
 *
 *  Created on: Feb 18, 2023
 *      Author: Dell
 */

#ifndef CONFIG_PB_CFG_H_
#define CONFIG_PB_CFG_H_

/*Please configure pins of PushButtons from data sheet
 * PushButton Ex: DIO_PD7
 * Please config Mode (Active_Low or Active_High)
 * */

#define PB_SW1         DIO_PD7
#define PB_SW1_MODE    ACTIVE_LOW

#define PB_SW2         DIO_PD6
#define PB_SW2_MODE    ACTIVE_LOW

#define PB_SW3         DIO_PD5
#define PB_SW3_MODE    ACTIVE_LOW

#define PB_SW4         		DIO_PD3
#define PB_SW4_MODE         ACTIVE_LOW
#endif /* CONFIG_PB_CFG_H_ */
