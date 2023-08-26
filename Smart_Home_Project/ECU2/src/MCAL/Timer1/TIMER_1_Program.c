/*
 * TIMER_1_Program.c
 *
 *  Created on: Mar 2, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"Mcu_HW.h"
#include"Dio_int.h"
#include"TIMER_1_Private.h"
#include"TIMER_1_Types.h"
#include"TIMER_1_Init.h"

void (*ICU_CallBackFun)(void) = NULL ;


void M_TIMER1_void_Init(TIMER_1_MD Local_Mode,TIMER_1_WG Local_WG)
{
	if(Local_Mode == TIMER_1_NM)
	{
		/*Select normal mode*/
		CLR_BIT(TCCR1A,TCCR1A_WGM10);
		CLR_BIT(TCCR1A,TCCR1A_WGM11);
		CLR_BIT(TCCR1B,TCCR1B_WGM12);
		CLR_BIT(TCCR1B,TCCR1B_WGM13);
		if(Local_WG == TIMER_1_NWG)
		{
			/*Select compare output mode*/
			CLR_BIT(TCCR1A,TCCR1A_COM1A0);
			CLR_BIT(TCCR1A,TCCR1A_COM1A1);
		}
	}
	else if(Local_Mode == Timer_1_Fast_PWM)
	{
		/*Setting waveform for fast PWM*/
		CLR_BIT(TCCR1A,TCCR1A_WGM10);
		SET_BIT(TCCR1A,TCCR1A_WGM11);
		SET_BIT(TCCR1B,TCCR1B_WGM12);
		SET_BIT(TCCR1B,TCCR1B_WGM13);
		if(Local_WG==TIMER_1_NonINV)
		{
			/*Select Fast-PWM Non-inverting mode*/
			SET_BIT(TCCR1A,TCCR1A_COM1A1);
			CLR_BIT(TCCR1A,TCCR1A_COM1A0);
		}
	}
}
void M_TIMER1_void_FastPWM(u16 Duty_Cycle)
{
	/*Select compare output mode*/
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	/*Set the top value for timer1 counts where overflow occurs*/
	ICR1=TOP_VALUE;
	/*OCR1A Value = On time since it's non inverting mode*/
	OCR1A=((Duty_Cycle*TOP_VALUE)/100)-1;
	M_TIMER1_void_Start(TIMER1_CLK_8);

}
void M_TIMER1_void_Start(TIMER1_PRESCALER Local_Prescaller)
{
	if(Local_Prescaller== TIMER1_CLK_8)
	{
		CLR_BIT(TCCR1B,TCCR1B_CS10);
		SET_BIT(TCCR1B,TCCR1B_CS11);
		CLR_BIT(TCCR1B,TCCR1B_CS12);
	}
}
void M_TIMER1_void_Stop(void)
{
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);

}

void M_TIMER1_void_ICU_Enable(void)
{
	/*Enable ICU Interrupt*/
	SET_BIT(TIMSK,TIMSK_TICIE1);
	/*Set trigger to rising edge*/
	SET_BIT(TCCR1B,TCCR1B_ICES1);

}


void M_TIMER1_void_ICU_TriggerSelect(ICU_Trigger Local_Trigger)
{
	if(Local_Trigger == ICU_FALLING)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);

	}
	else if(Local_Trigger == ICU_RISING)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);

	}
}

void M_TIMER1_void_ICU_INTERRUPTDIS(void)
{
	/*Enable ICU Interrupt*/
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}

u16 M_TIMER1_void_ICU_Reading(void)
{
	return ICR1;
}

void M_TIMER1_void_ICU_SetCallBack(void)
{

}

u8 M_TIMER1_u8_Reset_flag(TIMER1_INTERRUPT_TYPE Local_type)
{
	if(Local_type == TIMER1_ICU)
	{
		SET_BIT(TIFR,TIFR_ICF1);
	}
	else if(Local_type == TIMER1_OVF)
	{
		SET_BIT(TIFR,TIFR_TOV1);
	}
	return 0;
}

