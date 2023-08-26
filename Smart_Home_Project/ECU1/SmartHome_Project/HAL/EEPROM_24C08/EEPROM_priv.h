/*
 * EEPROM_priv.h
 *
 *  Created on: Mar 10, 2023
 *      Author: LENOVO
 */

#ifndef EEPROM_24C08_EEPROM_PRIV_H_
#define EEPROM_24C08_EEPROM_PRIV_H_

#define EEPROM_SLA_4MSB	0xA0	// 1010 0000
#define EEPROM_SLA_W	0xFE	// 1111	1110	It will be anded with SLA
#define EEPROM_SLA_R	0x01	// 0000 0001	It will be ORED with SLA

#define EN_DEBUGING		1
#define DIS_DEBUGING	0
#define DEBUG	DIS_DEBUGING

#endif /* EEPROM_24C08_EEPROM_PRIV_H_ */
