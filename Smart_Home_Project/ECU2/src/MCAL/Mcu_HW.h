/*
 * Mcu_HW.h
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */
/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : Mcu_HW.h
*
*  breif    : this file contains all registers addresses
*
*****************************************************************
*/
#ifndef MCU_HW_H_
#define MCU_HW_H_
/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
//-------------------DIO-------------------
//------------------ END of DIO------------


#define PORTA_REG 		(*((volatile u8*)0x3B))
#define DDRA_REG  		(*((volatile u8*)0x3A))
#define PINA_REG		(*((volatile u8*)0x39))

#define PORTB_REG		(*((volatile u8*)0x38))
#define DDRB_REG		(*((volatile u8*)0x37))
#define PINB_REG		(*((volatile u8*)0x36))

#define PORTC_REG		(*((volatile u8*)0x35))
#define DDRC_REG		(*((volatile u8*)0x34))
#define PINC_REG		(*((volatile u8*)0x33))

#define PORTD_REG		(*((volatile u8*)0x32))
#define DDRD_REG		(*((volatile u8*)0x31))
#define PIND_REG		(*((volatile u8*)0x30))


#define MCUCR			(*((volatile u8*)0x55))
#define MCUCSR			(*((volatile u8*)0x54))
#define GICR			(*((volatile u8*)0x5B))
#define GIFR			(*((volatile u8*)0x5A))

#define TCCR0			(*((volatile u8*)0x53))
#define TCNT0			(*((volatile u8*)0x52))
#define OCR0			(*((volatile u8*)0x5C))
#define TIMSKR			(*((volatile u8*)0x59))
#define TIFR			(*((volatile u8*)0x58))

#define	TCCR1A			(*((volatile u8*)0x4F))
#define TCCR1B          (*((volatile u8*)0x4E))
#define TCNT1H          (*((volatile u8*)0x4D))
#define TCNT1L          (*((volatile u8*)0x4C))
#define OCR1AH          (*((volatile u8*)0x4B))
#define OCR1AL          (*((volatile u8*)0x4A))
#define OCR1BH          (*((volatile u8*)0x49))
#define OCR1BL          (*((volatile u8*)0x48))
#define ICR1H           (*((volatile u8*)0x47))
#define ICR1L           (*((volatile u8*)0x46))






/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/
#endif /* MCU_HW_H_ */
