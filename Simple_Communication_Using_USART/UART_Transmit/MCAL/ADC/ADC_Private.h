/*
 * ADC_Private.h
 *
 *  Created on: Feb 26, 2023
 *      Author: Dell
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define MAX_DELAY     50000


#define ADMUX_VOLTAGE_REF_CLEAR_MASK      0x3F

#define ADMUX_ADLAR_CLEAR                 0xDF
#define ADMUX_MUX_CLEAR                   0xE0

#define ADCSRA_ADC_ENABLE_MASK_CLEAR      0x7F
#define ADCSRA_ADC_ENABLE_MASK_SET        0x80

#define ADC_Interrupt_Clear_Mask          0xF7
#define ADC_Interrupt_Set_Mask            0x08

#define ADCSRA_ADC_START_CONV_CLEAR       0xBF
#define ADCSRA_ADC_START_CONV_SET         0x40

#define SFIOR_ADC_FREE_RUNNING_MODE_CLEAR  0x1F
#define SFIOR_ADC_FREE_RUNNING_MODE_SET    0x00

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
