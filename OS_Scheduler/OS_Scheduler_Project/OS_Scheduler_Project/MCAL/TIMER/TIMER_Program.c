/*
 * TIMER_Program.c
 *
 *  Created on: Feb 24, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"Mcu_HW.h"
#include"TIMER_Private.h"
#include"TIMER_CONFIG.h"
#include"TIMER_Types.h"
#include"TIMER_Init.h"
#include"CLCD_Init.h"
#include<avr/interrupt.h>
#include"LED/LED_Init.h"
static void (*EXTI_ARRCALLBACK2FUNC[2])(void) ={NULL,NULL};

static u32 No_of_over_flows=0;
static u8 No_of_Remaning=0;
static u32 Global_No_of_overflows=0;

void M_void_Timer_Init(Timer_Mode T_MODE, Wave_Form_Generation WG_M)
{
	switch(T_MODE)
	{
	case Normal_Mode:
		TCCR0 &= CLEAR_TIMER_MODE_REG;
		TCCR0 |=SET_NORMAL_MODE_MASK;
		switch(WG_M)
		{
		case Toggle_OC0:
			TCCR0 &= CLEAR_WAVEG_MASK;
			TCCR0 |= TOGGLE_PORT_MASK;
			break;
		case Clear_OC0:
			TCCR0 &= CLEAR_WAVEG_MASK;
			TCCR0 |= CLEAR_PORT_MASK;
			break;
		case Set_OC0:
			TCCR0 &= CLEAR_WAVEG_MASK;
			TCCR0 |= SET_PORT_MASK;
			break;
		default:
			break;
		}
		break;
	case CTC_Mode:
		TCCR0 &= CLEAR_TIMER_MODE_REG;
		TCCR0 |=SET_CTC_MODE_MASK;
		switch(WG_M)
		{
		case Toggle_OC0:
			TCCR0 &= CLEAR_WAVEG_MASK;
			TCCR0 |= TOGGLE_PORT_MASK;
			break;
		case Clear_OC0:
			TCCR0 &= CLEAR_WAVEG_MASK;
			TCCR0 |= CLEAR_PORT_MASK;
			break;
		case Set_OC0:
			TCCR0 &= CLEAR_WAVEG_MASK;
			TCCR0 |= SET_PORT_MASK;
			break;
		default:
			break;
		}
		break;
	case Fast_PWM:
		TCCR0 &= CLEAR_TIMER_MODE_REG;
		TCCR0 |=SET_FAST_MODE_MASK;
		switch(WG_M)
		{
		case Inverting_Mode:
			TCCR0 &= CLEAR_WAVEG_MASK;
			TCCR0 |= INVERTING_FAST_MASK;
			break;
		case Non_Invering_Mode:
			TCCR0 &= CLEAR_WAVEG_MASK;
			TCCR0 |= NON_INVERTING_FAST_MASK;
			break;
		default:
			break;
		}
		break;
	case Phase_Correct_PWM:
		TCCR0 &= CLEAR_TIMER_MODE_REG;
		TCCR0 |=SET_PWM_PHASE_MODE_MASK;
		switch(WG_M)
		{
		case Inverting_Mode:
			TCCR0 &= CLEAR_WAVEG_MASK;
			TCCR0 |= INVERTING_PHASE_MASK;
			break;
		case Non_Invering_Mode:
			TCCR0 &= CLEAR_WAVEG_MASK;
			TCCR0 |= NON_INVERTING_PHASE_MASK;
			break;
		default:
			break;
		}
		break;
	}
}
void M_void_Timer_start(PRE_SCALLER Pre_scaller_select)
{
	TCCR0 &= CLEAR_PRESCALLER_MASK;
	TCCR0 |= Pre_scaller_select;

}
void M_void_Timer_stop(void)
{
	TCCR0 &= CLEAR_PRESCALLER_MASK;
	TCCR0 |= NO_CLK_SOURCE;
}

u8 Timer_u8__GetCounts(void)
{
	return TCNT0;
}
void M_void_Timer_Set_Preload(u8 Pre_load)
{
	TCNT0= Pre_load;
}

void M_TIMER0_setDelayTimeMilliSec(u32 Local_DelayTime, Timer_Mode Local_Mode, PRE_SCALLER Local_Prescaller)
{
	u32 Pre_scallers[5]={1,8,64,256,1024};
	f32 TickTime = (f32)Pre_scallers[4]/16;

	u32 DesiredTickS = 0;
	u32 CTC_Value = 0 ;
	/* Calculate the desired Tick*/
	 DesiredTickS = (f32)Local_DelayTime*1000/ (TickTime) ;

	if(Local_Mode == Normal_Mode)
	{
		 /*Store the numbers of over flow */
		 No_of_over_flows = DesiredTickS/ 256 ;
		 /* Store the Number of remaining if found */
		 No_of_Remaning = DesiredTickS % 256;
		 /*if there is remaining then start from it */
		 if(DesiredTickS % 256 != 0)
		 {
			 TCNT0 = 256 - No_of_Remaning ;
			 No_of_over_flows ++ ;

		 }


	}
	else if(Local_Mode == CTC_Mode)
	{
		CTC_Value = 255 ;
		u8 NoOfCompMatch = 0;

		while(DesiredTickS % CTC_Value)
		{
			CTC_Value -- ;
		}
		NoOfCompMatch = DesiredTickS % CTC_Value ;
		OCR0 = NoOfCompMatch;
	}
	else if(Local_Mode == Fast_PWM)
	{

	}
	M_void_Timer_start(Local_Prescaller);
}

void M_void_EnableTIMERInt(Timer_Mode T_MODE)
{
	switch(T_MODE)
	{
	case Normal_Mode:
		TIMSK &= NORMAL_MODE_INTERRUPT_CLEAR;
		TIMSK |= NORMAL_MODE_INTERRUPT_SET;
		break;
	case CTC_Mode:
		TIMSK &= CTC_MODE_INTERRUPT_CLEAR;
		TIMSK |= CTC_MODE_INTERRUPT_SET;
		break;
	default:
		break;
	}
}
void M_void_DisableTIMERInt(Timer_Mode T_MODE)
{
	switch(T_MODE)
	{
	case Normal_Mode:
		TIMSK &= NORMAL_MODE_INTERRUPT_CLEAR;
		TIMSK |= NORMAL_MODE_INTERRUPT_RESET;
		break;
	case CTC_Mode:
		TIMSK &= CTC_MODE_INTERRUPT_CLEAR;
		TIMSK |= CTC_MODE_INTERRUPT_RESET;
		break;
	default:
		break;
	}
}

void M_void_setCallBack(Timer_Mode T_MODE,void (*Copy_pvINTFunc)(void))
{

	switch(T_MODE)
	{
	case Normal_Mode:
		if(Copy_pvINTFunc!= NULL)
		{
			EXTI_ARRCALLBACK2FUNC[0]=Copy_pvINTFunc;
		}
		break;
	case CTC_Mode:
		if(Copy_pvINTFunc!= NULL)
		{
			EXTI_ARRCALLBACK2FUNC[1]=Copy_pvINTFunc;
		}
		break;
	}
}

ISR(TIMER0_OVF_vect)
{
	Global_No_of_overflows++;
	if(EXTI_ARRCALLBACK2FUNC[0]!=NULL)
	{
		if(Global_No_of_overflows==No_of_over_flows)
		{
			EXTI_ARRCALLBACK2FUNC[0]();
			Global_No_of_overflows=0;
			TCNT0 = 256 - No_of_Remaning;
		}
	}

}
ISR(TIMER0_COMP_vect)
{

}
