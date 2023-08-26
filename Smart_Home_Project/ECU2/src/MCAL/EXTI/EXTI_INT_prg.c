/*
 * EXTI_INT_prg.c
 *
 *  Created on: Feb 24, 2023
 *      Author: ahmed57
 */

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "BIT_MATH.h"
//#include "Mcu_HW.h"
#include "EXTI_INT_priv.h"
#include "EXTI_INT_types.h"
#include "EXTI_INT_cfg.h"
#include "EXTI_INT_int.h"
#include <avr/interrupt.h>

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
//static void(*CallBack_Arr[3])(void) = {NULL, NULL, NULL};
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void M_vEXTI_INT_Enable(EXTI_CONFIG_t	EXTI_Arr[]){

	//u8 EXTI_Arr_Len;
	//EXTI_Arr_Len = (sizeof(EXTI_Arr) / sizeof (EXTI_CONFIG_t));

	EXTI_ID  ID;
    EXTI_SenseType_t  INT_Sense;

	for (int i =0; i < EXTI_INT_ArrConfig_Size; i++ )
	{
		ID = EXTI_Arr[i].INT_ID;
		INT_Sense = EXTI_Arr[i].INT_SENSE;

		switch(ID)
		{
			case EXTI_INT0: APPLY_MASK(EXTI_MCUCR_REG, EXTI_INT0_MCUCR_ISC_MASK);
							SET_BITS(EXTI_MCUCR_REG, INT_Sense, EXTI_INT0_MCUCR_ISC_POS);
							SET_BIT(EXTI_GICR_REG, EXTI_INT0_GICR_POS);
							break;

			case EXTI_INT1: APPLY_MASK(EXTI_MCUCR_REG, EXTI_INT1_MCUCR_ISC_MASK);
							SET_BITS(EXTI_MCUCR_REG, INT_Sense, EXTI_INT1_MCUCR_ISC_POS);
							SET_BIT(EXTI_GICR_REG, EXTI_INT1_GICR_POS);
							break;

			case EXTI_INT2: if(INT_Sense == EXTI_Sense_Falling_Edge)
							{
								CLR_BIT(EXTI_MCUCSR_REG, EXTI_INT2_MCUCSR_ISC_POS);
							}
							else if(INT_Sense == EXTI_Sense_Rising_Edge)
							{
								SET_BIT(EXTI_MCUCSR_REG, EXTI_INT2_MCUCSR_ISC_POS);
							}
							SET_BIT(EXTI_GICR_REG, EXTI_INT2_GICR_POS);
							break;

		}

	}

}


/*********************************************************/
/*********************************************************/
void M_vEXTI_INT_Disable(EXTI_CONFIG_t	EXTI_INT){

	EXTI_ID  ID = EXTI_INT.INT_ID;
    EXTI_SenseType_t  INT_Sense = EXTI_INT.INT_SENSE;


		switch(ID)
		{
			case EXTI_INT0:
							CLR_BIT(EXTI_GICR_REG, EXTI_INT0_GICR_POS);
							break;

			case EXTI_INT1:

							CLR_BIT(EXTI_GICR_REG, EXTI_INT1_GICR_POS);
							break;

			case EXTI_INT2:

							CLR_BIT(EXTI_GICR_REG, EXTI_INT2_GICR_POS);
							break;

		}

	}


/*********************************************************/
/*********************************************************/
void M_vEXTI_SetCallBack(void (*Ptrf)(void), EXTI_ID  ID)
{

	if (Ptrf != NULL)
	{
		CallBack_Arr[ID] = Ptrf;
	}
}


/*********************************************************/
/*********************************************************/
ISR(INT0_vect)
{
	if(CallBack_Arr[0] != NULL)
	{
		CallBack_Arr[0]();
	}
}


/*********************************************************/
/*********************************************************/
ISR(INT1_vect)
{
	if(CallBack_Arr[1] != NULL)
	{
		CallBack_Arr[1]();
	}
}


/*********************************************************/
/*********************************************************/
ISR(INT2_vect)
{
	if(CallBack_Arr[2] != NULL)
	{
		CallBack_Arr[2]();
	}
}



/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
