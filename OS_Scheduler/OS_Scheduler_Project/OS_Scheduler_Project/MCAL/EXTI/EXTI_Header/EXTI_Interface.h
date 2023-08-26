/*
 * EXTI_Interface.h
 *
 *  Created on: Oct 23, 2022
 *      Author: Dell
 */

#ifndef MCAL_EXTI_EXTI_HEADER_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_HEADER_EXTI_INTERFACE_H_





void Enable_Int(const EXT_I * ConfigArr);

void Disable_Int(const EXT_I * ConfigArr);

u8 EXTI_u8INTSetCallBack(const EXT_I * ConfigArr,void (*Copy_pvINTFunc)(void));


#endif /* MCAL_EXTI_EXTI_HEADER_EXTI_INTERFACE_H_ */
