/*
 * TIMER_1_Program.c
 *
 *  Created on: Mar 2, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"Mcu_HW.h"
#include"DIO/Dio_int.h"
#include"TIMER_1_Private.h"
#include"TIMER_1_CONFIG.h"
#include"TIMER_1_Types.h"
#include"TIMER_1_Init.h"
#include <avr/interrupt.h>       /* For ICU ISR */

void (*ICU_CallBackFun)(void) = NULL ;




/*used to initialize time1 to use ICU*/
void ICU_Init(const ICU_ConfigType *Ptr_Config)
{
	/*Select normal mode*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	/*Select compare output mode*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);

	/*set trigger edge to rising edge for ICU*/
	SET_BIT(TCCR1B,TCCR1B_ICES1);

	/*Set pre-scaller to 8 CLK*/
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
	/*Set initial value for timer1*/
	TCNT1=0;
	/*Initial value for the input capture register*/
	ICR1=0;
	/*Enable the input capture interrupt to generate the interrupt upon detecting the rising edge*/
	SET_BIT(TIMSK,TIMSK_TICIE1);

}
/*used to set the required edge for capture*/
void ICU_Set_Edge_detection(const ICU_Trigger EDGE_TYPE)
{
	if(EDGE_TYPE == ICU_FALLING)
		{
			CLR_BIT(TCCR1B,TCCR1B_ICES1);

		}
	else if(EDGE_TYPE == ICU_RISING)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);

	}
}
/*get the capture value*/
u16 ICU_Get_Captured_value(void)
{
	return ICR1;
}
/*Clear timer1 value to start count from zero*/
void ICU_Clear_timer_value(void)
{
	TCNT1=0;
}
/*function to disable timer1 to stop icu*/
void ICU_Disable(void)
{
	/* Clear All Timer1 Registers */
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	ICR1 = 0;

	/* Disable the Input Capture interrupt */
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}
/*SET Call back function*/

void ICU_Set_CallBack(void (*ptr_to_func)(void))
{
	ICU_CallBackFun=ptr_to_func;
}
ISR(TIMER1_CAPT_vect)
{
	if(ICU_CallBackFun != NULL)
	{
		ICU_CallBackFun();
	}
}
