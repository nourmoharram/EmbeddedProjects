/*
 * GIE_init.h
 *
 *  Created on: Feb 24, 2023
 *      Author: LENOVO
 */

#ifndef GIE_GIE_INIT_H_
#define GIE_GIE_INIT_H_

#include "STD_TYPES.h"

void M_GIE_Void_Enable();
void M_GIE_Void_Disable();



//-----------------Interrupt-------------------
#define EXTI_MCUCR	(*((volatile u8*)0x55))
#define MCUCR_ISC11 3
#define MCUCR_ISC10 2
#define MCUCR_ISC01 1
#define MCUCR_ISC00 0
#define EXTI_MCUCSR	(*((volatile u8*)0x54))


#define EXTI_GICR (*((volatile u8*)0x5B))
#define GICR_INT0 6
#define GICR_INT1 7
#define GICR_INT2 5

#define EXTI_GIFR (*((volatile u8*)0x5A))
#define GIFR_INTF	1 7
#define GIFR_INTF0 6
#define GIFR_INTF2 5

#define GLI_SREG (*((volatile u8*)0x5F))
#define SREG_GIE 7


//---------------Interrupt of DIO------------

#endif /* GIE_GIE_INIT_H_ */
