/*
 * TIMER0_prog.c
 *
 *  Created on: Feb 24, 2023
 *      Author: LENOVO
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "avr/interrupt.h"

#include "TIMER0_priv.h"
#include "TIMER0_types.h"
#include "TIMER0_int.h"


void (*Timer0CallBackFunc[TIMER0_ARR_SIZE])(void) = {NULL} ;

u32 NoOfOverFlow = 0;
static u32 NoOfRemaning = 0;
 u32 Counter_NoOverFlow = 0 ;
static u32 Global_NoComparMatch = 0 ;

void M_TIMER0_Void_Init(TIMER0_MODE_TYPE Local_Mode,TIMER0_WG_TYPE Local_WG_Type)
{

	/*Clear Mode Bits */
	TIMER0_TCCR0 &= TIMER0_CLEAR_MODE_MASK ;

	/*Check the mode type */
	switch(Local_Mode)
	{
	case NORMAL_MODE:
		TIMER0_TCCR0 |= TIMER0_NORMAL_MODE_MASK ;
		break ;
	case PHASE_PWM_MODE:
		TIMER0_TCCR0 |= TIMER0_PWM_PHASE_MODE_MASK ;
		break ;
	case CTC_MODE:
		TIMER0_TCCR0 |= TIMER0_CTC_MODE_MASK ;
		break ;
	case FAST_PWM_MODE:
		TIMER0_TCCR0 |= TIMER0_PWM_FAST_MASK ;
		break ;
	}


	/*Check the wave generation signal */
	TIMER0_TCCR0 &= TIMER0_WG_CLEAR_MASK ;

	/* Check Wave Generation*/
	switch(Local_WG_Type)
	{
		case WG_NORMAL_PORT:
			TIMER0_TCCR0 |= TIMER0_WG_NORMAL_MASK ;
			break;

		case WG_TOGGLE_OC0:
			TIMER0_TCCR0 |= TIMER0_WG_TOGGLE_MASK ;
			break;

		case WG_CLEAR_OC0:
			TIMER0_TCCR0 |= TIMER0_WG_CLEAR_MASK ;
			break;

		case WG_SET_OC0:
			TIMER0_TCCR0 |= TIMER0_WG_SET_MASK;
			break;

		case WG_INVERTING:
			TIMER0_TCCR0 |= TIMER0_WG_INVERTING_MASK;
			break;

		case WG_NON_INVERTING:
			TIMER0_TCCR0 |= TIMER0_WG_NON_INVERTING_MASK;
			break;
		}
}

void M_TIMER0_Void_Start(TIMER0_PRESCALLER_SELECT Local_PrescallerSelect)
{
	/* Clear Prescaller */
	TIMER0_TCCR0 &= TIMER0_CLEAR_PRESCALLER_MASK ;

	/*Set Prescaller */
	TIMER0_TCCR0 |=  Local_PrescallerSelect;

}
void M_TIMER0_Void_Stop()
{

	TIMER0_TCCR0 |= TIMER0_CLEAR_PRESCALLER_MASK;

}

u8 M_TIMER0_Void_GetCount(TIMER0_MODE_TYPE Local_Mode)
{
	u8 Local_ReturnCount  ;

	if (Local_Mode == NORMAL_MODE)
	{
	Local_ReturnCount = (256 * Counter_NoOverFlow) + TIMER0_TCNT0;
	}
	else if (Local_Mode == CTC_MODE)
	{
		Local_ReturnCount = 255 * Global_NoComparMatch;
	}


	return Local_ReturnCount ;
}


void M_TIMER0_setDelayTimeMilliSec(u32 Local_DelayTime, TIMER0_MODE_TYPE Local_Mode, TIMER0_PRESCALLER_SELECT Local_Prescaller)
{
	M_TIMER0_Void_Start(Local_Prescaller);
	u32 Local_Prescaller_Arr[5] = {1,8,64,256,1024};

	f32 TickTime = (f32)Local_Prescaller_Arr[Local_Prescaller-1]/ F_CPU ;
	u32 DesiredTickS = 0;
	u32 CTC_Value = 0 ;



	/* Calculate the desired Tick*/
	 DesiredTickS = (f32)Local_DelayTime / TickTime ;

	if(Local_Mode == NORMAL_MODE)
	{
		 /*Store the numbers of over flow */
			 NoOfOverFlow = ( DesiredTickS/ 256 ) / 2  ;

		 /* Store the Number of remaining if found */
		 NoOfRemaning = DesiredTickS % 256;

		 /*if there is remaining then start from it */
		 if(NoOfRemaning != 0)
		 {
			 TIMER0_TCNT0 = 256 - NoOfRemaning ;
			 NoOfOverFlow++ ;

		 }
	}
	else if(Local_Mode == CTC_MODE)
	{
		CTC_Value = 255 ;
		u32 NoOfCompMatch = 0;

		while(DesiredTickS % CTC_Value)
		{
			CTC_Value -- ;
		}
		NoOfCompMatch = DesiredTickS % CTC_Value ;
		TIMER0_OCR0 = NoOfCompMatch;
	}
	else if(Local_Mode == FAST_PWM_MODE)
	{

	}
}


void M_TIMER0_EnableInt(TIMER0_INTERRUPT_TYPE Local_InterruptType)
{
	if (Local_InterruptType == COMPARE_MATCH)
	{
		SET_BIT(TIMER0_TIMSK, TIMSK_OCIE0);
	}
	else if (Local_InterruptType == OVRER_FLOW)
	{
		SET_BIT(TIMER0_TIMSK, TIMSK_TOIE0);
	}
	else
	{
		/* No Interrupt in PWM Modes */
	}

}

void M_TIMER0_DisableInt()
{
	CLR_BIT(TIMER0_TIMSK, TIMSK_OCIE0);
	CLR_BIT(TIMER0_TIMSK, TIMSK_TOIE0);
}

void M_TIMER0_setCallBack(TIMER0_INTERRUPT_TYPE Local_InterruptType ,void(*Local_CallBackFunc)(void))
{


	if (Local_CallBackFunc != NULL)
	{
		switch(Local_InterruptType)
		{
		case OVRER_FLOW:

			Timer0CallBackFunc[0] = Local_CallBackFunc ;
			break;

		case COMPARE_MATCH:
			Timer0CallBackFunc[1] = Local_CallBackFunc ;
			break;
		}
	}
}
u16 Cont = 0 ;

ISR(TIMER0_OVF_vect)
{
	Counter_NoOverFlow++ ;



	if (Counter_NoOverFlow == NoOfOverFlow)
	{
		Timer0CallBackFunc[0]();
		Counter_NoOverFlow = 0 ;
		TIMER0_TCNT0 = 256 - NoOfRemaning ;

	}

}

