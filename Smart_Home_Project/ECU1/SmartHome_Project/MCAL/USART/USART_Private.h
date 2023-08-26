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

//----------------Start of USART--------------------

/*Data register used to write data by writing to it or used to receive data in it by reading from it*/
#define UDR                   *((volatile u8*)0x2c)

/*USART Control and status register A - UCSRA*/
#define UCSRA                 *((volatile u8*)0x2b)
#define UCSRA_RXC             7  /*receive complete flag is set when receive is complete*/
#define UCSRA_TXC             6  /*transmit flag is set when transmit is complete*/
#define UCSRA_UDRE            5  /*data register empty flag is set if the register is empty and ready to send data */
#define UCSRA_FE              4  /*the flag is set when a frame error occurred - set this bit to zero*/
#define UCSRA_DOR             3  /*the flag is set when a data over run is detected - set this bit to zero*/
#define UCSRA_PE              2  /*the flag is set when a parity error occurred - set this bit to zero*/
#define UCSRA_U2X             1  /*setting this bit will double the speed of the transfer rate*/
#define UCSRA_MPCM            0  /*multi processor mode for synchronous operation*/


/*USART Control and status register B - UCSRB*/
#define UCSRB                *((volatile u8*)0x2a)
#define UCSRB_RXCIE          7 /*receive interrupt enable*/
#define UCSRB_TXCIE          6 /*transmit interrupt enable*/
#define UCSRB_UDRIE          5 /*data register empty interrupt enable*/
#define UCSRB_RXEN           4 /*set the bit to 1 to enable receiver*/
#define UCSRB_TXEN           3 /*set this bit to 1 to enable transmitter*/
#define UCSRB_UCSZ2          2 /*used for the word size with the other two bits in UCSRC*/
#define UCSRB_RXB8           1 /*used for the ninth data bit in receiving*/
#define UCSRB_TXB8           0 /*used for the ninth data bit in transmitting*/


/*USART Control and status register C - UCSRC*/
#define UCSRC                *((volatile u8*)0x40)
#define UCSRC_URSEL          7 /*if set to 1 will select UCSRC Register to write on it - if Set to 0 will select UBBRH register to write on it since they share the same address*/
#define UCSRC_UMSEL          6 /*mode select if 1 -> Synchronous & if 0-> Asynchronous*/
#define UCSRC_UPM1           5 /*used to select parity mode*/
#define UCSRC_UPM0           4 /*used to select parity mode*/
#define UCSRC_USBS           3 /*used to select stop bit 0->for 1 bit and 1-> for 2 bits*/
#define UCSRC_UCSZ1          2 /*used for character size*/
#define UCSRC_UCSZ0          1 /*used for character size*/
#define UCSRC_UCPOL          0 /*clock polarity used for synchronous only*/

/*Baud rate registers*/
#define UBBRL                *((volatile u8*)0x29)
#define UBBRH                *((volatile u8*)0x40)
#define UBBRH_UMSEL          6 /*mode select if 1 -> Synchronous & if 0-> Asynchronous*/

//-----------------End of USART---------------------

#endif /* MCAL_USART_USART_PRIVATE_H_ */
