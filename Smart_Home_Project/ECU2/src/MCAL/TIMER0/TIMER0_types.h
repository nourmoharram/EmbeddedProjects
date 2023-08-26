/*
 * TIMER0_types.h
 *
 *  Created on: Feb 25, 2023
 *      Author: ahmed57
 */

#ifndef TIMER0_TIMER0_TYPES_H_
#define TIMER0_TIMER0_TYPES_H_

#include "STD_TYPES.h"

#define TIMER0_CS_MASK		0XF8
#define TIMER0_WGM_MASK		0XB7
#define TIMER0_COM_MASK		0XCF
#define TIMER0_FOC_MASK		0X7F

#define TIMER0_TIMSK_REG_OCIE0_POS		1
#define TIMER0_TIMSK_REG_TOIE0_POS		0


typedef enum{

    TIMER0_NORMAL_MODE 			    = (u8) 0X00,
    TIMER0_PWM_PhaseCorrect_MODE    = (u8) 0x40,
    TIMER0_CTC_MODE                 = (u8) 0X08,
	TIMER0_PWM_FAST_MODE		    = (u8) 0X48
}TIMER0_MODES_t;


/*  Compare Output Mode, non-PWM  */
typedef enum{

	TIMER0_NON_PWM_NORMAL_MODE  				= (u8) 0X00,
	TIMER0_NON_PWM_TOGGLE_ON_COMPARE_MODE	 	= (u8) 0X10,
	TIMER0_NON_PWM_CLEAR_ON_COMPARE_MATCH_MODE  = (u8) 0X20,
	TIMER0_NON_PWM_SET_ON_COMPARE_MATHC_MODE    = (u8) 0X30

}TIMER0_NON_PWM_OC0_MODES_t;

/* Compare Output Mode, Fast PWM */
typedef enum{

	TIMER0_PWM_FAST_NORMAL_MODE  				 = (u8) 0X00,		//Normal port operation, OC0 disconnected
	TIMER0_PWM_FAST_OC0_RESERVED			 	 = (u8) 0X10,
	TIMER0_PWM_FAST_NonInverted_MODE             = (u8) 0X20,		//Clear OC0 on compare match, set OC0 at TOP (non-inverted pwm)
	TIMER0_PWM_FAST_Inverted_MODE                = (u8) 0X30			//Set OC0 on compare match, clear OC0 at TOP (inverted-pwm)

}TIMER0_PWM_FAST_OC0_MODES_t;


typedef enum{

	TIMER0_PWM_PHASECORRECT_NORMAL_MODE  				 = (u8) 0X00,		//Normal port operation, OC0 disconnected
	TIMER0_PWM_PHASECORRECT_OC0_RESERVED			 	 = (u8) 0X10,
	TIMER0_PWM_PHASECORRECT_NonInverted_MODE  			 = (u8) 0X20,		//Clear OC0 on compare match when up-counting. Set OC0 on comparematch when downcounting
	TIMER0_PWM_PHASECORRECT_Inverted_MODE    			 = (u8) 0X30			//Set OC0 on compare match when up-counting. Clear OC0 on comparematch when downcounting.

}TIMER0_PWM_PHASECORRECT_OC0_MODES_t ;


typedef enum{

	TIMER0_NO_CLK		                = (u8) 0X00,
	TIMER0_CLK_NO_PRESCALING            = (u8) 0X01,
	TIMER0_CLK_PRESCALER8	            = (u8) 0X02,
	TIMER0_CLK_PRESCALER64	            = (u8) 0X03,
	TIMER0_CLK_PRESCALER256	            = (u8) 0X04,
	TIMER0_CLK_PRESCALER1024	        = (u8) 0X05,
	TIMER0_EXTERNAL_CLK_FALLING_EDGE	= (u8) 0X06,			// External clock source on T0 pin. Clock on falling edge
	TIMER0_EXTERNAL_CLK_RISING_EDGE	    = (u8) 0X07			// External clock source on T0 pin. Clock on rising edge

}TIMER0_CLK_SELECT_t;


typedef enum{

	NO_PRESCALING            = 1,
	PRESCALER8	             = 8,
	PRESCALER64	             = 64,
	PRESCALER256	         = 256,
	PRESCALER1024	         = 1024,


}TIMER0_Prescaler_t;


typedef enum{
	TIMER0_OVERFLOW_INT = 0,
	TIMER0_OC0_INT 		= 1

}TIMER0_INT_TYPES_t;


/*
typedef enum{

	TIMER0_OVERFLOW_INT_Disable = 0,
	TIMER0_OVERFLOW_INT_Enable  = 1,

}TIMER0_OVERFLOW_INT;

typedef enum{

	TIMER0_OC0_INT_Disable = 0,
	TIMER0_OC0_INT_Enable  = 1,

}TIMER0_OC0_INT;

*/



#endif /* TIMER0_TIMER0_TYPES_H_ */
