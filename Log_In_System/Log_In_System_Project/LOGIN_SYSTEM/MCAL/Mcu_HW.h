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

#define PORTA_REG  (*((volatile u8*)0x3B))
#define DDRA_REG  (*((volatile u8*)0x3A))
#define PINA_REG  (*((volatile u8*)0x39))

#define PORTB_REG  (*((volatile u8*)0x38))
#define DDRB_REG  (*((volatile u8*)0x37))
#define PINB_REG  (*((volatile u8*)0x36))

#define PORTC_REG  (*((volatile u8*)0x35))
#define DDRC_REG  (*((volatile u8*)0x34))
#define PINC_REG  (*((volatile u8*)0x33))

#define PORTD_REG  (*((volatile u8*)0x32))
#define DDRD_REG  (*((volatile u8*)0x31))
#define PIND_REG  (*((volatile u8*)0x30))

//------------------ END of DIO------------
//-------------Start of GIE--------------

#define SREG          *((volatile u8*)0x5f)
#define SREG_I        7
//-------------End of GIE----------------
//-------------Start of EXTI-------------
#define GICR           *((volatile u8*)0x5B)
#define GICR_INT1       7
#define GICR_INT0       6
#define GICR_INT2       5

#define GIFR           *((volatile u8*)0x5A)

#define MCUCR          *((volatile u8*)0x55)
#define MCUCR_ISC11      3
#define MCUCR_ISC10      2
#define MCUCR_ISC01      1
#define MCUCR_ISC00      0

#define MCUSR          *((volatile u8*)0x54)
#define MCUSR_INT2       6
//-------------End of EXTI---------------

//-------------Start of TIMER0------------
#define TCCR0           *((volatile u8*)0x53) //TIMER 0 CONTROL REGISTER
#define TCCR0_WGM00     6                    // Wave form generation mode bit0
#define TCCR0_WGM01     3                    //wave form generation mode bit1
#define TCCR0_CS02      2                    // prescaller bit2
#define TCCR0_CS01      1                    // prescaller bit1
#define TCCR0_CS00      0                    // prescaller bit0
#define TCCR0_COM00     4
#define TCCR0_COM01     5
#define OCR0           *((volatile u8*)0x5c) //output compare register 0

#define TIMSK          *((volatile u8*)0x59)  // timer mask interrupt
#define TIMSK_OCIE0    1                      //output compare interrupt enable
#define TIMSK_TOIE0    0
#define TIFR           *((volatile u8*)0x58)  // Interrupt flag register
#define TIFR_TOV0      0

#define TCNT0		 *((volatile u8*)0x52) //Timer counter


//-------------End of TIMER--------------
//-------------Start of TIMER1-----------
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
//----------------End of TIMER1-----------------------
//----------------Start of ADC-----------------------

#define ADMUX     			*((volatile u8*)0x27) //ADC MULTIPLIXER SELECTION REGISTER
#define ADMUX_REFS1        	7           //REFERENCE SELECTION BIT1
#define ADMUX_REFS0       	6           //reference selection bit0
#define ADMUX_ADLAR        	5           //ADC left adjust result

#define ADMUX_MUX0        	0           //ADC left adjust result
#define ADMUX_MUX1        	1           //ADC left adjust result
#define ADMUX_MUX2        	2           //ADC left adjust result
#define ADMUX_MUX3        	3           //ADC left adjust result
#define ADMUX_MUX4        	4           //ADC left adjust result


#define ADCSRA    			*((volatile u8*)0x26)  //ADC control and status register A

#define ADCSRA_ADEN        	7            //ADC ENABLE
#define ADCSRA_ADSC        	6            ///START CONVERSION
#define ADCSRA_ADATE       	5            //AUTO TRIGER ENABLE
#define ADCSRA_ADIF        	4            // INTERRUPT FLAG
#define ADCSRA_ADIE        	3            // INTERRUPT ENABLE
#define ADCSRA_ADPS2       	2            //PRESCALLER BIT2
#define ADCSRA_ADPS1       	1            //PRESCALLER BIT1
#define ADCSRA_ADPS0       	0            //PRESCALLER BIT0


#define ADCH      			*((volatile u8*)0x25)  //ADC high register

#define ADCL      			*((volatile u16*)0x24)  //ADC Low register
//----------------End of ADC-------------------------
/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/
#endif /* MCU_HW_H_ */
