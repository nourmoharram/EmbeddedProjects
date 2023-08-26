/*
 * TIMER_1_Private.h
 *
 *  Created on: Mar 2, 2023
 *      Author: Dell
 */

#ifndef MCAL_TIMER1_TIMER_1_PRIVATE_H_
#define MCAL_TIMER1_TIMER_1_PRIVATE_H_

#define TIMER1_CLEAR_MODE			0x0F
#define TIMER1_CLEAR_PRESCALER		0xF8


#define TIMER1_NORMAL_MODE_MASK		0x00
#define TIMER1_TOGGLE_MODE_MASK		0x40

#define TIMER1_SET_BIT_WG			4

#define TOP_VALUE                   65535


/*Timer 1 registers*/


#define TIMSK           *((volatile u8*)0x59) //timer mask register
#define TIMSK_TICIE1    5                     //Input capture interrupt enable
#define TIMSK_TOIE0     0                     //Timer0 overflow interrupt enable
#define TIMSK_OCIE0     1                     //Timer0 compare match interrupt enable*/
#define TIMSK_TOIE1     2                     //Timer1 Over flow interrupt enable*/


#define TCCR1A          *((volatile u8*)0x4f) //Timer Control Register
#define TCCR1A_COM1A1   7                     //channelA compare match output mode bit1
#define TCCR1A_COM1A0   6                     //channelA compare match output mode bit0
#define TCCR1A_WGM11    1                     //Wave form generation mode bit1
#define TCCR1A_WGM10    0                     //wave form generation mode bit0

#define TCCR1B          *((volatile u16*)0x4e) //Timer1 control register B
#define TCCR1B_ICES1    6                      //Input capture edge selection
#define TCCR1B_WGM13    4                      //Waveform generation mode bit3
#define TCCR1B_WGM12    3                      //Waveform generation mode bit 2
#define TCCR1B_CS12     2                      //prescaller bit2
#define TCCR1B_CS11     1                      //prescaller bit1
#define TCCR1B_CS10     0                      //Prescaller bit0

#define OCR1A           *((volatile u16*)0x4a) //channelA output compare match register

#define ICR1            *((volatile u16*)0x46) //Input capture register

#define TCNT1           *((volatile u16*)0x4c) //Timer1 register

#define TIFR           *((volatile u8*)0x58)  // Interrupt flag register
#define TIFR_TOV1      2                        //TIMER1 over flow flag
#define TIFR_ICF1      5                         //ICU flag bit
#endif /* MCAL_TIMER1_TIMER_1_PRIVATE_H_ */
