/*
 * TWI_prog.c
 *
 *  Created on: Mar 8, 2023
 *      Author: LENOVO
 */

#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "TWI_cfg.h"
#include "TWI_priv.h"
#include "TWI_types.h"
#include "Dio_int.h"
#include "TWI_init.h"

void M_TWI_Void_InitMaster(TWI_SCL_FREQUANCY Copy_Frequancy)
{
//	u8 Local_Check = 0 ;

	/* CLEAR prescaller */
	TWI_TWSR &= TWI_CLR_PRESCALLER ;
	/* Set Prescaller to 1*/
	TWI_TWSR |= 0x00 ;



		TWI_TWBR = Copy_Frequancy ; //TWI_SCL_400KHZ ;

	/* Enable TWI and Interrupt*/
	TWI_TWCR |= TWI_INIT_MASK;
}


TWI_STATUS M_TWI_Void_SendStartCondition()
{
	/* Enable Interrupt, TWI, Start Condition*/
	TWI_TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWSTA)|(1<<TWCR_TWEN) ;

	/* Wait until interrupt flag raised again !(TWI_TWCR & (1<<TWCR_TWINT))*/
	while(GET_BIT(TWI_TWCR,TWCR_TWINT) == 0);

	/* Wait until the TWI start ACK is complete */

	return M_TWI_U8_GetStatus() ;
}


void M_TWI_Void_SetSlaveAddress(u8 Copy_SlaveAddress)
{
	TWI_TWAR = Copy_SlaveAddress ;
}

TWI_STATUS M_TWI_Void_SendByte(u8 Copy_DataByte)
{
	/* Send Data to register*/
	TWI_TWDR = Copy_DataByte ;

	/* Clear interrupt flag To run the start condition and enable the TWEN PIN*/
	TWI_TWCR = (1<< TWCR_TWINT) | (1<< TWCR_TWEN) ;	//(1<< TWCR_TWINT) | (1<< TWCR_TWEN) ;

	/* Wait till complete TWDR byte transmitted */
	while (!(TWI_TWCR & (1<<TWCR_TWINT)));

	return M_TWI_U8_GetStatus() ;
}

void M_TWI_Void_RecevieWithACK(u8 *PTR_RecevedData)
{
	/* Clear interrupt flag To run the start condition and enable the TWEN PIN*/
	TWI_TWCR |= TWI_RECEIVE_WITH_ACK_MASK ;		//

	/* Wait till complete TWDR byte transmitted */
	while (!(TWI_TWCR & (1<<TWCR_TWINT)));

//	Save the Received data
	*PTR_RecevedData = TWI_TWDR ;
}

void M_TWI_Void_RecevieWitNACK(u8 *PTR_RecevedData)
{
//	M_Dio_void_setPinValue(DIO_PC0, DIO_HIGH);
	CLR_BIT(TWI_TWCR,TWCR_TWEA);
	/* Clear interrupt flag To run the start condition and enable the TWEN PIN*/
	TWI_TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	/* Wait till complete TWDR byte transmitted */
	while (!(TWI_TWCR & (1<<TWCR_TWINT)));

//	Save the Received data
	*PTR_RecevedData = TWI_TWDR ;
}


void M_TWI_Void_GetStatus(u8* status)
{
	*status = (TWI_TWSR & TWI_STATUS_MASK);
}

u8 M_TWI_U8_GetStatus()
{
	return (TWI_TWSR & TWI_STATUS_MASK);
}


void M_TWI_Void_SendStopCondition()
{
	/* Stop condition */
	TWI_TWCR |= TWI_STOP_MASK ;
}



