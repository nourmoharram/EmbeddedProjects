/*
 * ADC_priv.h
 *
 *  Created on: Mar 3, 2023
 *      Author: ahmed
 */

#ifndef SRC_MCAL_ADC_ADC_PRIV_H_
#define SRC_MCAL_ADC_ADC_PRIV_H_

/* Bit field of ADMUX REG */
typedef struct{

	volatile u8 MUX_BITS		       : 5;
	volatile u8 ADLAR_BITS          : 1;
	volatile u8 REFS_BITS           : 2;

}ADC_ADMUX;


volatile static   ADC_ADMUX *PtrADMUX = (volatile ADC_ADMUX *)0X27;

/* Bit field of ADCSRA REG */
typedef struct{

	volatile u8 ADPS_BITS	       : 3;
	volatile u8 ADIE_BITS           : 1;
	volatile u8 ADIF_BITS           : 1;
	volatile u8 ADATE_BITS          : 1;
	volatile u8 ADSC_BITS           : 1;
	volatile u8 ADEN_BITS           : 1;

}ADC_ADCSRA;


volatile static   ADC_ADCSRA *PtrADCSRA = (volatile ADC_ADCSRA *)0X26;



/* Bit field of ADCSRA REG */
typedef struct{

	volatile u8 		       : 5;
	volatile u8 ADTS_BITS          : 3;


}ADC_SFIOR;


volatile static   ADC_SFIOR *PtrSFIOR = (volatile ADC_SFIOR *)0X50;


#define ADCH_reg			(*((volatile u8*)0x25))
#define ADCL_reg			(*((volatile u8*)0x24))


#endif /* SRC_MCAL_ADC_ADC_PRIV_H_ */
