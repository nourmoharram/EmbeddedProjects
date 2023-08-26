/*
 * EEPROM_init.h
 *
 *  Created on: Mar 10, 2023
 *      Author: LENOVO
 */

#ifndef EEPROM_24C08_EEPROM_INIT_H_
#define EEPROM_24C08_EEPROM_INIT_H_

#include "ERR_STATUS.h"

/******************************************
  syntax : void H_EEPROM_Void_Init();


  Description : Initlize

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : NONE
  parameters (out) : NONE
  Return Value     : void
******************************************/
void H_EEPROM_Void_Init();
/******************************************
  syntax : void H_EEPROM_Void_Init();


  Description : Write Byte to eeprom

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : u16 Copy_ByteAddress, u8 DataByte
  parameters (out) : Error status
  Return Value     : ES_t
******************************************/
ES_t H_EEPROM_Void_WriteByte(u16 Copy_ByteAddress, u8 DataByte);
/******************************************
  syntax : void H_EEPROM_Void_Init();


  Description : Read Byte to eeprom

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : u16 Copy_ByteAddress, u8 *PTR_Byte
  parameters (out) : Error status
  Return Value     : ES_t
******************************************/
ES_t H_EEPROM_Void_ReadByte(u16 Copy_ByteAddress, u8 *PTR_Byte);

#endif /* EEPROM_24C08_EEPROM_INIT_H_ */
