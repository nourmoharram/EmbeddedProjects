/*
 * EEPROM_prog.c
 *
 *  Created on: Mar 10, 2023
 *      Author: LENOVO
 */

#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_STATUS.h"

#include "EEPROM_priv.h"
#include "EEPROM_init.h"
#include "TWI_init.h"

void H_EEPROM_Void_Init()
{
	M_TWI_Void_InitMaster(TWI_SCL_400KHZ);
}

ES_t H_EEPROM_Void_WriteByte(u16 Copy_ByteAddress, u8 Copy_DataByte)
{
	/**
	 * Send START condition
	 **/
	M_TWI_Void_SendStartCondition();
	if (M_TWI_U8_GetStatus() != TWI_STATUS_START )
	{
		return EEPROM_NOT_OK;
	}
		/**
		 * Send SLA+W :	1010 0000
		 * */

	/* Send EEPROM address*/
	M_TWI_Void_SendByte(((EEPROM_SLA_4MSB )| (Copy_ByteAddress>>8)) & (EEPROM_SLA_W ));
#if DEBUG
	if((u16)M_TWI_U8_GetStatus()  != TWI_STATUS_SLA_ACK)
	{
		return EEPROM_NOT_OK ;
	}
#endif
	/**
	 *  Send rest of the address:
	 * */

	M_TWI_Void_SendByte((u8)Copy_ByteAddress);
#if DEBUG
	if((u16)M_TWI_U8_GetStatus() != TWI_STATUS_DATA_SENT_ACK)
	{
		return EEPROM_NOT_OK ;

	}
#endif
	/***
	 * Send The data
	 */
	M_TWI_Void_SendByte(Copy_DataByte);
#if DEBUG
	if((u16)M_TWI_U8_GetStatus() != TWI_STATUS_DATA_SENT_ACK)
	{
		return EEPROM_NOT_OK ;
	}
#endif
	/**
	 * STOP Condition
	 *
	 */

	M_TWI_Void_SendStopCondition();

	return EEPROM_OK ;
}



/*
 * Start New function
 *
 * */


ES_t H_EEPROM_Void_ReadByte(u16 Copy_ByteAddress, u8 *PTR_Byte)
{
	/**
	 * Send START condition
	 **/
	M_TWI_Void_SendStartCondition();
	if (M_TWI_U8_GetStatus() != TWI_STATUS_START )
	{
		return EEPROM_NOT_OK;
	}

		/**
		 * Send SLA+W :	1010 0000
		 * */
	/* Send EEPROM address*/
	M_TWI_Void_SendByte( ((EEPROM_SLA_4MSB )| (Copy_ByteAddress>>8)) & (EEPROM_SLA_W ));
	if(M_TWI_U8_GetStatus()  != TWI_STATUS_SLA_ACK)
	{
		return EEPROM_NOT_OK ;
	}

	/**
	 *  Send rest of the address:
	 * */
	M_TWI_Void_SendByte((u8)Copy_ByteAddress);
	if(M_TWI_U8_GetStatus() != TWI_STATUS_DATA_SENT_ACK)
	{
		return EEPROM_NOT_OK ;
	}
	/**
	 * Send Repeated START condition
	 **/
	M_TWI_Void_SendStartCondition();
	if (M_TWI_U8_GetStatus() != TWI_STATUS_REP_START )
	{
		return EEPROM_NOT_OK;
	}
	/****
	 * Send EEPROM address
	 ****/
	M_TWI_Void_SendByte( ((EEPROM_SLA_4MSB )| (Copy_ByteAddress>>8)) | (EEPROM_SLA_R ));
	if(M_TWI_U8_GetStatus()  != TWI_STATUS_SLA_ACK_R)
	{
		return EEPROM_NOT_OK ;
	}

	M_TWI_Void_RecevieWitNACK(PTR_Byte);

	M_TWI_Void_SendStopCondition();

	return EEPROM_OK ;
}
