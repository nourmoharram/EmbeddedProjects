/*
 * TWI_init.h
 *
 *  Created on: Mar 8, 2023
 *      Author: LENOVO
 */

#ifndef TWI_TWI_INIT_H_
#define TWI_TWI_INIT_H_


#include "TWI_types.h"
#include "STD_TYPES.h"

/******************************************
  syntax : void M_TWI_Void_InitMaster(TWI_SCL_FREQUANCY Copy_Frequancy);


  Description : Initlize

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : Copy_Frequancy
  parameters (out) : NONE
  Return Value     : void
******************************************/
void M_TWI_Void_InitMaster(TWI_SCL_FREQUANCY Copy_Frequancy);
/******************************************
  syntax : TWI_STATUS M_TWI_Void_SendStartCondition();

  Description : Send Start Condition

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : NONE
  parameters (out) : Status
  Return Value     : TWI_STATUS
******************************************/
TWI_STATUS M_TWI_Void_SendStartCondition();
/******************************************
  syntax : TWI_STATUS M_TWI_Void_SendByte(u8 Copy_DataByte);


  Description : Send Byte

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : Copy_DataByte
  parameters (out) : Status
  Return Value     : TWI_STATUS
******************************************/
TWI_STATUS M_TWI_Void_SendByte(u8 Copy_DataByte);
/******************************************
  syntax : void M_TWI_Void_SetSlaveAddress(u8 Copy_SlaveAddress);

  Description : Set Slave Address

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : Copy_SlaveAddress
  parameters (out) : NONE
  Return Value     : void
******************************************/
void M_TWI_Void_SetSlaveAddress(u8 Copy_SlaveAddress);
/******************************************
  syntax : void M_TWI_Void_RecevieWithACK(u8 *PTR_RecevedData);


  Description : Recevie With ACK

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : u8 *PTR_RecevedData
  parameters (out) : NONE
  Return Value     : void
******************************************/
void M_TWI_Void_RecevieWithACK(u8 *PTR_RecevedData);
/******************************************
  syntax : void M_TWI_Void_RecevieWitNACK(u8 *PTR_RecevedData);


  Description : Recevie With NOT ACK

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : u8 *PTR_RecevedData
  parameters (out) : NONE
  Return Value     : void
******************************************/
void M_TWI_Void_RecevieWitNACK(u8 *PTR_RecevedData);
/******************************************
  syntax : void M_TWI_Void_GetStatus(u8* status);

  Description : Get Status

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : * status
  parameters (out) : NONE
  Return Value     : void
******************************************/
void M_TWI_Void_GetStatus(u8* status);
/******************************************
  syntax : u8 M_TWI_U8_GetStatus();


  Description : Get Status

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : NONE
  parameters (out) : NONE
  Return Value     : Status
******************************************/
u8 M_TWI_U8_GetStatus();
/******************************************
  syntax : void M_TWI_Void_SendStopCondition();


  Description : M_TWI_Void_SendStopCondition

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : NONE
  parameters (out) : NONE
  Return Value     : Status
******************************************/
void M_TWI_Void_SendStopCondition();

#endif /* TWI_TWI_INIT_H_ */
