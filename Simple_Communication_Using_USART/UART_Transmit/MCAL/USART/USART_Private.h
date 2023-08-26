/*
 * USART_Private.h
 *
 *  Created on: Mar 4, 2023
 *      Author: Dell
 */

#ifndef MCAL_USART_USART_PRIVATE_H_
#define MCAL_USART_USART_PRIVATE_H_

#define MAX_DELAY      50000


#define UCSRC_URSEL_REGSELECT_CLEAR   0x7F
#define UCSRC_URSEL_REGSELECT_SET     0x80

#define UCSRC_UCPOL_CLEAR_MASK        0xFE

#define UCSRC_UMSEL_ASYNCH_MASK_Clear  0xBF

#define PARITYBITS_MASK_CLEAR          0xCF
#define PARITYBITS_EVEN_MASK_SET       0x20
#define PARITYBITS_ODD_MASK_SET        0x30

#define STOP_BIT_CLEAR_1bit_MASK       0xF7
#define STOP_BIT_2bit_SET_MASK         0x08
#endif /* MCAL_USART_USART_PRIVATE_H_ */
