/*
 * TIMER_Private.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Dell
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_
/*For timer mode select*/
#define CLEAR_TIMER_MODE_REG         0xD7
#define SET_NORMAL_MODE_MASK         0x00
#define SET_PWM_PHASE_MODE_MASK      0x40
#define SET_CTC_MODE_MASK            0x08
#define SET_FAST_MODE_MASK           0x48

/*for wave generation mode*/
#define CLEAR_WAVEG_MASK            0xCF
#define NORMAL_PORT_MASK            0x00
#define TOGGLE_PORT_MASK            0x10
#define CLEAR_PORT_MASK             0x20
#define SET_PORT_MASK               0x30
#define NON_INVERTING_FAST_MASK     0x20
#define INVERTING_FAST_MASK         0x30
#define NON_INVERTING_PHASE_MASK    0x20
#define INVERTING_PHASE_MASK        0x30
/*pre-scaller select*/
#define CLEAR_PRESCALLER_MASK       0xF8
#define NO_CLK_SOURCE               0x00
#define NO_CLK_PRESCALLER           0x01
#define CLK_8_PRESCALLER            0x02
#define CLK_64_PRESCALLER           0x03
#define CLK_256_PRESCALLER          0x04
#define CLK_1024_PRESCALLER         0x05
/*Interrupt flags*/
#define NORMAL_MODE_INTERRUPT_CLEAR 0xFE
#define NORMAL_MODE_INTERRUPT_SET   0x01
#define CTC_MODE_INTERRUPT_CLEAR    0xFD
#define CTC_MODE_INTERRUPT_SET      0x02
#define NORMAL_MODE_INTERRUPT_RESET 0x00
#define CTC_MODE_INTERRUPT_RESET    0x00
#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
