/*
 * TIMER0_priv.h
 *
 *  Created on: Feb 25, 2023
 *      Author: ahmed57
 */

#ifndef TIMER0_TIMER0_PRIV_H_
#define TIMER0_TIMER0_PRIV_H_

static void(*Timer0_CallBack_Arr[2])(void) = {NULL,NULL};
/* TIMER0 register */
#define TIMER0_OCR0_REG				(*((volatile u8*)0X5C))		//Output Compare Register
#define TIMER0_TIMSK_REG			(*((volatile u8*)0X59))		//Timer/Counter Interrupt Mask
#define TIMER0_TIFR_REG				(*((volatile u8*)0X58))		//Timer/Counter Interrupt Flag
#define TIMER0_TCCR0_REG			(*((volatile u8*)0X53))  	//Timer/Counter Control Register – TCCR0
#define TIMER0_TCNT0_REG			(*((volatile u8*)0X52))		//Timer/Counter Register –TCNT0


#endif /* TIMER0_TIMER0_PRIV_H_ */
