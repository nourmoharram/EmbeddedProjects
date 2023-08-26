/*
 * TIMER0_priv.h
 *
 *  Created on: Feb 24, 2023
 *      Author: LENOVO
 */

#ifndef TIMER0_TIMER0_PRIV_H_
#define TIMER0_TIMER0_PRIV_H_

#define TIMER0_CLEAR_MODE_MASK			0xD7

#define TIMER0_CLEAR_PRESCALLER_MASK	0xF8

#define TIMER0_NORMAL_MODE_MASK			0x00
#define TIMER0_PWM_PHASE_MODE_MASK		0x40
#define TIMER0_CTC_MODE_MASK			0x08
#define TIMER0_PWM_FAST_MASK			0x48

#define TIMER0_WG_NORMAL_MASK			0x00
#define TIMER0_WG_TOGGLE_MASK			0x10
#define TIMER0_WG_CLEAR_MASK			0x20
#define TIMER0_WG_SET_MASK				0x30
#define TIMER0_WG_NON_INVERTING_MASK	0x20
#define TIMER0_WG_INVERTING_MASK		0x30

/* Prescaller */
/*
#define NO_CLK_PRESCALLER_MASK			0xF8
#define CLK_NO_PRESCALLER_MASK			0x00
#define CLK_8_PRESCALLER_MASK			0x02
#define CLK_64_PRESCALLER_MASK			0x03
#define CLK_256_PRESCALLER_MASK			0x04
#define CLK_1024_PRESCALLER_MASK		0x05
*/

/* Pointer to function array size */

#define TIMER0_ARR_SIZE					2


//----------------TIMER0------------------
#define TIMER0_TCCR0 (*((volatile u8*)0x53))
#define TCCR0_FOC0	7
#define TCCR0_WGM00	6
#define TCCR0_COM00	5
#define TCCR0_COM01	4
#define TCCR0_WGM01	3
#define TCCR0_CS02	2
#define TCCR0_CS01	1
#define TCCR0_CS00	0

	/* Counter Register	 */

#define TIMER0_TCNT0 (*((volatile u8*) 0x52))

	/* Output compair Register	 */
#define TIMER0_OCR0	 (*((volatile u8*) 0x5C))

	/* Interrupt Mask Register	 */
#define TIMER0_TIMSK (*((volatile u8*)0x59))
#define TIMSK_OCIE0 1
#define TIMSK_TOIE0 0

#define TIMER0_TIFR (*((volatile u8*) 0x58))
#define TIFR_OCF0 1
#define TIFR_TOV0 0
//---------------End of TIMER0------------


#endif /* TIMER0_TIMER0_PRIV_H_ */
