/*
 * EXTI_Program.c
 *
 *  Created on: Oct 23, 2022
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"EXTI_Private.h"
#include"EXTI_CONFIG.h"
#include"EXTI_Types.h"
#include"EXTI_Interface.h"
#include"Mcu_HW.h"
#include<avr/interrupt.h>

/*Create Global pointer to function to hold INT0 ISR Address*/
/*
static void (*EXTI_pvINT0Func)(void)=NULL; //return type-function name - arguments type
static void (*EXTI_pvINT1Func)(void)=NULL; //return type-function name - arguments type
static void (*EXTI_pvINT2Func)(void)=NULL; //return type-function name - arguments type
 */
static void (*EXTI_ARRCALLBACK2FUNC[3])(void) ={NULL_POINTER,NULL_POINTER,NULL_POINTER};


void Enable_Int(const EXT_I * ConfigArr)
{
	u8 Local_u8Counter;
	for(Local_u8Counter=0;Local_u8Counter<3;Local_u8Counter++)
	{
		switch(ConfigArr[Local_u8Counter].Interrupt_ID)
		{
		case EXTI0:
			switch(ConfigArr[Local_u8Counter].Trigger_value)
			{
			case Low_level:
				/*set sense control for INT0 To Low level*/
				CLR_BIT(MCUCR,MCUCR_ISC01);
				CLR_BIT(MCUCR,MCUCR_ISC00);
				break;
			case On_change:
				/*set sense control for INT0 To On change*/
				CLR_BIT(MCUCR,MCUCR_ISC01);
				SET_BIT(MCUCR,MCUCR_ISC00);
				break;
			case Falling_edge:
				break;
			case Rising_edge:
				break;
			default:
				break;
			}
			/*PeripheraL Interrupt enable for INT0  FROM GICR REGISTER ENABLE BIT6*/
			SET_BIT(GICR,GICR_INT0);
			break;
			case EXTI1:
				switch(ConfigArr[Local_u8Counter].Trigger_value)
				{
				case Low_level:
					/*set sense control for INT0 To falling edge*/
					SET_BIT(MCUCR,MCUCR_ISC01);
					CLR_BIT(MCUCR,MCUCR_ISC00);
					break;
				case On_change:
					/*set sense control for INT0 To On change*/
					CLR_BIT(MCUCR,MCUCR_ISC01);
					SET_BIT(MCUCR,MCUCR_ISC00);
					break;
				case Falling_edge:
					/*set sense control for INT0 To falling edge*/
					SET_BIT(MCUCR,MCUCR_ISC01);
					CLR_BIT(MCUCR,MCUCR_ISC00);
					break;
				case Rising_edge:
					/*set sense control for INT0 To Rising edge*/
					SET_BIT(MCUCR,MCUCR_ISC01);
					SET_BIT(MCUCR,MCUCR_ISC00);
					break;
				default:
					break;
				}
				/*PeripheraL Interrupt enable for INT0  FROM GICR REGISTER ENABLE BIT7*/
				SET_BIT(GICR,GICR_INT1);
				break;
				case EXTI2:
					switch(ConfigArr[Local_u8Counter].Trigger_value)
					{
					case Low_level:
						/*set sense control for INT0 To falling edge*/
						SET_BIT(MCUCR,MCUCR_ISC01);
						CLR_BIT(MCUCR,MCUCR_ISC00);
						break;
					case On_change:
						/*set sense control for INT0 To On change*/
						CLR_BIT(MCUCR,MCUCR_ISC01);
						SET_BIT(MCUCR,MCUCR_ISC00);
						break;
					case Falling_edge:
						break;
					case Rising_edge:
						break;
					default:
						break;
					}
					/*PeripheraL Interrupt enable for INT0  FROM GICR REGISTER ENABLE BIT5*/
					SET_BIT(GICR,GICR_INT2);
					break;
		}
	}

}

void Disable_Int(const EXT_I * ConfigArr)
{
	switch(ConfigArr->Interrupt_ID)
	{
	case EXTI0:
		/*PeripheraL Interrupt enable for INT0  FROM GICR REGISTER DISABLE BIT6*/
		CLR_BIT(GICR,GICR_INT0);
		break;
	case EXTI1:
		/*PeripheraL Interrupt enable for INT0  FROM GICR REGISTER DISABLE BIT7*/
		CLR_BIT(GICR,GICR_INT1);
		break;
	case EXTI2:
		/*PeripheraL Interrupt enable for INT0  FROM GICR REGISTER DISABLE BIT5*/
		CLR_BIT(GICR,GICR_INT2);
		break;
	}
}
u8 EXTI_u8INTSetCallBack(const EXT_I * ConfigArr,void (*Copy_pvINTFunc)(void))
{
	u8 Local_u8ErrorStatus=NO_ERROR;
	u8 Local_u8counter;
	for(Local_u8counter=0;Local_u8counter<3;Local_u8counter++)
	{
		switch(ConfigArr[Local_u8counter].Interrupt_ID)
		{
		case EXTI0:
			if(Copy_pvINTFunc != NULL)
			{
				EXTI_ARRCALLBACK2FUNC[Local_u8counter]=Copy_pvINTFunc;
			}
			else
			{
				Local_u8ErrorStatus = NULL_POINTER;
			}
			break;
		case EXTI1:
			if(Copy_pvINTFunc != NULL)
			{
				EXTI_ARRCALLBACK2FUNC[Local_u8counter]=Copy_pvINTFunc;
			}
			else
			{
				Local_u8ErrorStatus = NULL_POINTER;
			}
			break;
		case EXTI2:
			if(Copy_pvINTFunc != NULL)
			{
				EXTI_ARRCALLBACK2FUNC[Local_u8counter]=Copy_pvINTFunc;
			}
			else
			{
				Local_u8ErrorStatus = NULL_POINTER;
			}
			break;
		}
	}

	return Local_u8ErrorStatus;
}

ISR(INT0_vect)
{
	if(EXTI_ARRCALLBACK2FUNC[0] != NULL)
		{
		EXTI_ARRCALLBACK2FUNC[0]();
		}
		else
		{
			/*Stop*/
		}
}
ISR(INT1_vect)
{

}
ISR(INT2_vect)
{

}


