/*
 * TWI_priv.h
 *
 *  Created on: Mar 8, 2023
 *      Author: LENOVO
 */

#ifndef TWI_TWI_PRIV_H_
#define TWI_TWI_PRIV_H_


#define TWI_CLR_PRESCALLER			0xF8

#define TWI_INIT_MASK				0x84
#define TWI_START_MASK				0xA4

#define TWI_SEND_BYTE_MASK			0x84	//
#define TWI_RECEIVE_WITH_ACK_MASK	0xC4
#define TWI_STOP_MASK				0x94
#define	TWI_STATUS_MASK				0xF8


//----------------TWI------------------
#define TWI_TWBR *((volatile u8*)0x20)

#define TWI_TWCR *((volatile u8*)0x56)
#define TWCR_TWINT	7		//  Interrupt Flag
#define TWCR_TWEA	6		// Enable Acknowledge Bit
#define TWCR_TWSTA	5		//  START Condition Bit
#define TWCR_TWSTO	4		//  STOP Condition Bit
#define TWCR_TWWC	3		//  Write Collision Flag
#define TWCR_TWEN	2		// TWI Enable Bit
#define TWCR_TWIE	0		//  TWI Interrupt Enable

#define TWI_TWSR *((volatile u8*)0x21)
#define TWSR_TWPS0	0
#define TWSR_TWPS1	1
#define TWSR_TWS3	3
#define TWSR_TWS4	4
#define TWSR_TWS5	5
#define TWSR_TWS6	6
#define TWSR_TWS7	7


#define TWI_TWDR *((volatile u8*)0x23)	// data (Appear in the bus)
#define TWDR_BIT0   0
#define TWI_TWAR *((volatile u8*)0x22)	// address
#define TWAR_TWGCE 0	//General Call Recognition Enable Bit

//---------------End of TWI------------

#endif /* TWI_TWI_PRIV_H_ */
