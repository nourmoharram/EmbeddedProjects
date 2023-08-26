/*
 * TIMER0_prg.c
 *
 *  Created on: Feb 25, 2023
 *      Author: ahmed57
 */

#include <avr/interrupt.h>
//#include "Mcu_HW.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "TIMER0_priv.h"
#include "TIMER0_types.h"
#include "TIMER0_cfg.h"
#include "TIMER0_int.h"



static  u32 Delay_OverFlow_Count;
static  u32 Delay_CmpMatch_Count;

//static volatile u32 OverFlow_Counter =0;
static volatile u32 COMP_Counter =0;


/*******************************************************************/
/*******************************************************************/

void M_vTIMER0_Init(TIMER0_MODES_t TIMER0_MODE, u8 OC0_MODE)
{
	//u8 Timer0_Mode = TIMER0_Cfg.TIMER0_MODE;
	//u8 OC0_MODE;

	switch(TIMER0_MODE)

	{
	    case TIMER0_NORMAL_MODE:
	    						/* ENABLE SELECTED MODE  */
	    						APPLY_MASK(TIMER0_TCCR0_REG, TIMER0_WGM_MASK);
	    						SET_REG(TIMER0_TCCR0_REG, TIMER0_NORMAL_MODE);

	    						/* select COM Mode */
	    						APPLY_MASK(TIMER0_TCCR0_REG, TIMER0_COM_MASK);
	    						//OC0_MODE = TIMER0_Cfg.TIMER0_OC0_MODE.OC0_NONPWM_MODE;
	    						SET_REG(TIMER0_TCCR0_REG, (OC0_MODE));


	    						break;

	    case TIMER0_PWM_PhaseCorrect_MODE:
								/* ENABLE SELECTED MODE  */
								APPLY_MASK(TIMER0_TCCR0_REG, TIMER0_WGM_MASK);
								SET_REG(TIMER0_TCCR0_REG, TIMER0_PWM_PhaseCorrect_MODE);

	    						/* select COM Mode */
	    						APPLY_MASK(TIMER0_TCCR0_REG, TIMER0_COM_MASK);
	    						//OC0_MODE = TIMER0_Cfg.TIMER0_OC0_MODE.OC0_PHASECORRECT_MODE;
	    						SET_REG(TIMER0_TCCR0_REG, (OC0_MODE));
								break;

	    case TIMER0_CTC_MODE:
	    					   /* ENABLE SELECTED MODE  */
							   APPLY_MASK(TIMER0_TCCR0_REG, TIMER0_WGM_MASK);
							   SET_REG(TIMER0_TCCR0_REG, TIMER0_CTC_MODE);

	    						/* select COM Mode */
	    						APPLY_MASK(TIMER0_TCCR0_REG, TIMER0_COM_MASK);
	    						//OC0_MODE = TIMER0_Cfg.TIMER0_OC0_MODE.OC0_NONPWM_MODE;
	    						SET_REG(TIMER0_TCCR0_REG, (OC0_MODE));
							   break;

	    case TIMER0_PWM_FAST_MODE:
	    						/* ENABLE SELECTED MODE  */
							   APPLY_MASK(TIMER0_TCCR0_REG, TIMER0_WGM_MASK);
							   SET_REG(TIMER0_TCCR0_REG, TIMER0_PWM_FAST_MODE);

	    						/* select COM Mode */
	    						APPLY_MASK(TIMER0_TCCR0_REG, TIMER0_COM_MASK);
	    						//OC0_MODE = TIMER0_Cfg.TIMER0_OC0_MODE.OC0_FASTPWM_MODE;
	    						SET_REG(TIMER0_TCCR0_REG, (OC0_MODE));
							   break;

	    default: 			   break;


	}
}

/*******************************************************************/
/*******************************************************************/
void M_vTIMER0_Start(TIMER0_Prescaler_t	CLK_Src_Prescaler )
{

	//TIMER0_OCR0_REG = TIMER0_OCR_VALUE;

	switch(CLK_Src_Prescaler)
	{

		case NO_PRESCALING:
							 APPLY_MASK(TIMER0_TCCR0_REG, TIMER0_CS_MASK);
							 SET_REG(TIMER0_TCCR0_REG, TIMER0_CLK_NO_PRESCALING);
							 break;

		case PRESCALER8:
							 APPLY_MASK(TIMER0_TCCR0_REG, TIMER0_CS_MASK);
							 SET_REG(TIMER0_TCCR0_REG, TIMER0_CLK_PRESCALER8);
							 break;

		case PRESCALER64:
		                     APPLY_MASK(TIMER0_TCCR0_REG, TIMER0_CS_MASK);
		                     SET_REG(TIMER0_TCCR0_REG, TIMER0_CLK_PRESCALER64);
		                     break;

		case PRESCALER256:
							 APPLY_MASK(TIMER0_TCCR0_REG, TIMER0_CS_MASK);
							 SET_REG(TIMER0_TCCR0_REG, TIMER0_CLK_PRESCALER256);
							 break;

		case PRESCALER1024:
							 APPLY_MASK(TIMER0_TCCR0_REG, TIMER0_CS_MASK);
							 SET_REG(TIMER0_TCCR0_REG, TIMER0_CLK_PRESCALER1024);
							 break;

	}

}


/*******************************************************************/
/*******************************************************************/
void M_vTIMER0_Stop(void){

 APPLY_MASK(TIMER0_TCCR0_REG, TIMER0_CS_MASK);
 SET_REG(TIMER0_TCCR0_REG, TIMER0_NO_CLK);

}



/*******************************************************************/
/*******************************************************************/
void M_vTIMER0_GetCounts(void){

}


/*******************************************************************/
/*******************************************************************/
u32 M_vTIMER0_SetDelayTimeMilliSec(u32 millisec , TIMER0_Prescaler_t  Prescaler, TIMER0_MODES_t MODE){

	f32 TickTime;
	u32 Remaining_OverFlowCount;
	TickTime = ((f32)Prescaler*1000000 / FCPU);

	u32 DesiredTick = ((millisec*1000) / TickTime);	       // *1000 to convert it to miceosec

	u32 MAX_OC0_VALUE = 255;
	/*CmpMatch_Count NORMAL MODE */

	switch(MODE)
	{

		case TIMER0_NORMAL_MODE:
								Delay_OverFlow_Count = (DesiredTick / 256);
								Remaining_OverFlowCount = (DesiredTick %256);

								if(Remaining_OverFlowCount != 0)
								{

									TIMER0_TCNT0_REG = (256 - Remaining_OverFlowCount);
									Delay_OverFlow_Count++;
								}

								break;


		case TIMER0_CTC_MODE:		/* ctc mode */

								while(DesiredTick % MAX_OC0_VALUE)
								{
									MAX_OC0_VALUE--;
								}
								//TIMER0_OCR0_REG = MAX_OC0_VALUE;
								Delay_CmpMatch_Count = DesiredTick / MAX_OC0_VALUE;
								break;


	}


	M_vTIMER0_Start(Prescaler);
	return Delay_OverFlow_Count;
}


/*******************************************************************/
/*******************************************************************/
void M_vTIMER0_EnableInt(TIMER0_INT_TYPES_t  TIMER0_INT)
{


	switch(TIMER0_INT)
	{

		case TIMER0_OVERFLOW_INT:
									SET_BIT(TIMER0_TIMSK_REG, TIMER0_TIMSK_REG_TOIE0_POS);
									break;

		case TIMER0_OC0_INT:
									SET_BIT(TIMER0_TIMSK_REG, TIMER0_TIMSK_REG_OCIE0_POS);
									break;
	}

}


/*******************************************************************/
/*******************************************************************/
void M_vTIMER0_DisableInt(TIMER0_INT_TYPES_t  TIMER0_INT){

	switch(TIMER0_INT)
	{

		case TIMER0_OVERFLOW_INT:
									CLR_BIT(TIMER0_TIMSK_REG, TIMER0_TIMSK_REG_TOIE0_POS);
									break;

		case TIMER0_OC0_INT:
									CLR_BIT(TIMER0_TIMSK_REG, TIMER0_TIMSK_REG_OCIE0_POS);
									break;
	}

}


/*******************************************************************/
/*******************************************************************/
void M_vTIMER0_SetFastPWM(u32 Frequency, u8 Duty_Cycle, TIMER0_PWM_FAST_OC0_MODES_t FAST_PWM_MODE){

	//u8 OCR0_Value;
	TIMER0_Prescaler_t Required_Prescaler;

	switch(FAST_PWM_MODE)
	{
		case TIMER0_PWM_FAST_NonInverted_MODE:
												TIMER0_OCR0_REG = ((Duty_Cycle*256)/100)-1;
												//TIMER0_OCR0_REG = OCR0_Value;
												break;

		case TIMER0_PWM_FAST_Inverted_MODE:		TIMER0_OCR0_REG = ((255/256) - (Duty_Cycle/100))*256;
												//TIMER0_OCR0_REG = OCR0_Value;
												break;
	}


	Required_Prescaler = FCPU/(256*Frequency);

	M_vTIMER0_Start(Required_Prescaler);


}


/*******************************************************************/
/*******************************************************************/
void M_vTIMER0_SetPhaseCorrectPWM(u32 Frequency, u8 Duty_Cycle, TIMER0_PWM_PHASECORRECT_OC0_MODES_t PWM_PHASECORRECT_MODE2)
{

	u8 OCR0_Value;
	TIMER0_Prescaler_t Required_Prescaler;

	switch(PWM_PHASECORRECT_MODE2)
	{
		case TIMER0_PWM_PHASECORRECT_NonInverted_MODE:
														TIMER0_OCR0_REG = ((Duty_Cycle*255)/100);
														//TIMER0_OCR0_REG = Duty_Cycle;
														break;

		case TIMER0_PWM_PHASECORRECT_Inverted_MODE:
														TIMER0_OCR0_REG = ((1 - (Duty_Cycle/100))*255);
														//TIMER0_OCR0_REG = OCR0_Value;
														break;
	}


 
	Required_Prescaler = FCPU/(510*Frequency);
	
	if( (Required_Prescaler < 5)  && (Required_Prescaler != 1) )
	{
		
		Required_Prescaler = 1;
	}
	else if( (Required_Prescaler > 5)  && (Required_Prescaler <= 30) && (Required_Prescaler != 8) )
	{
		Required_Prescaler = 8;
	}
	else if( (Required_Prescaler > 30)  && (Required_Prescaler <= 150) && (Required_Prescaler != 64) )
	{
		Required_Prescaler = 64;
	}
	else if( (Required_Prescaler > 150)  && (Required_Prescaler <= 750) && (Required_Prescaler != 256) )
	{
		Required_Prescaler = 256;
	}
	else if( (Required_Prescaler > 750) &&  (Required_Prescaler != 1024) )
	{
		Required_Prescaler = 1024;
	}

	//Required_Prescaler = 256;
	M_vTIMER0_Start(1024);

}


/*******************************************************************/
/*******************************************************************/
/* Set callback functions  */
void M_vTIMER0_SetCallBack(void(*PtrFun)(void) , TIMER0_INT_TYPES_t INT_ID )
{

	if(PtrFun != NULL)
	{
		Timer0_CallBack_Arr[INT_ID] = PtrFun;
	}

}


/*******************************************************************/
/*******************************************************************/
/* OverFlow interrupt */

ISR(TIMER0_OVF_vect)
{

	static  u32 OverFlow_Counter =0;


	if(OverFlow_Counter == Delay_OverFlow_Count)
	{
		if(Timer0_CallBack_Arr[0] != NULL)
		{
			Timer0_CallBack_Arr[0]();
			OverFlow_Counter =0;
			//M_vTIMER0_Stop();  // uncomment this line for one time delay
		}
	}

	else{
	OverFlow_Counter++;
	}

}

/*******************************************************************/
/*******************************************************************/
/* Compare on match interrupt */

/*
ISR(TIMER0_COMP_vect)
{

	if(Timer0_CallBack_Arr[1] != NULL)
	{
		Timer0_CallBack_Arr[1]();
	}

	COMP_Counter++;

}
*/


