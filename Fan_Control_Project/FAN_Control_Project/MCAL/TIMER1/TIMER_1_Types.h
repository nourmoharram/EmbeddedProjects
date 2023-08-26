/*
 * TIMER_1_Types.h
 *
 *  Created on: Mar 2, 2023
 *      Author: Dell
 */

#ifndef MCAL_TIMER1_TIMER_1_TYPES_H_
#define MCAL_TIMER1_TIMER_1_TYPES_H_

typedef enum
{
	TIMER_1_NM
}TIMER_1_MD;

typedef enum
{
	TIMER_1_NWG
}TIMER_1_WG;

typedef enum
{
	ICU_FALLING,
	ICU_RISING
}ICU_Trigger;

typedef enum{

	TIMER1_NO_CLK_SOURCE,
	TIMER1_CLK_1,
	TIMER1_CLK_8,
	TIMER1_CLK_64,
	TIMER1_CLK_256,
	TIMER1_CLK_1024


}TIMER1_PRESCALER;

typedef enum{
	TIMER1_ICU,
	TIMER1_OCMA,
	TIMER1_OCMB,
	TIMER1_OVF

}TIMER1_INTERRUPT_TYPE;
#endif /* MCAL_TIMER1_TIMER_1_TYPES_H_ */
