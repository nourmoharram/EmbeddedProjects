/*
 * BIT_MATH.h
 *
 *  Created on: Jan 30, 2023
 *      Author: aya_enan
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg, bit)  (reg |= (1 << (bit)))// reg = reg | (1<< bit)
#define CLR_BIT(reg, bit)  (reg &= ~(1<< bit))
#define TOG_BIT(reg,bit)   (reg ^= (1 << (bit)))
#define GET_BIT(reg,bit)   ((reg >> bit)& 1 )

#define SET_BITS(reg, value, bit)	(reg |= value << (bit))


#define PORT_MASK_VALUE 0xFF

#define CLEAR_PORT(REGISTER)    (REGISTER &= ~PORT_MASK_VALUE)
#define SET_PORT(REGISTER)      (REGISTER |= PORT_MASK_VALUE)
#define TOGGLE_PORT(REGISTER)   (REGISTER ^= PORT_MASK_VALUE)
#define GET_PORT(REGISTER)  	(REGISTER = PORT_MASK_VALUE)

#define APPLY_MASK(REGISTER, MASK)  (REGISTER &= MASK)
#define SET_REG(REGISTER, MASK)		(REGISTER |= MASK)

#endif /* BIT_MATH_H_ */
