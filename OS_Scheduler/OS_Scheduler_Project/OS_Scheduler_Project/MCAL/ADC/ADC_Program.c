/*
 * ADC_Program.c
 *
 *  Created on: Feb 26, 2023
 *      Author: Dell
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"Mcu_HW.h"
#include"ADC_Private.h"
#include"ADC_CONFIG.h"
#include"ADC_Types.h"
#include"ADC_Init.h"
#include"CLCD/CLCD_Init.h"

static void (*ADC_ptr_FUNC)(void)=NULL;

void ADC_Init(ADC_ConfigType *Ptr_to_ADC)
{
	/*Select VCC*/
	switch(Ptr_to_ADC->Voltage_Ref_Value)
	{
	case VCC_5V:
		CLR_BIT(ADMUX,ADMUX_REFS1);
		SET_BIT(ADMUX,ADMUX_REFS0);
		break;
	case VREF_2_5_V:
		SET_BIT(ADMUX,ADMUX_REFS1);
		SET_BIT(ADMUX,ADMUX_REFS0);
		break;
	default:
		break;
	}
	/*Select adjust type*/
	switch(Ptr_to_ADC->AdjustType)
	{
	case Right_Adjust:
		CLR_BIT(ADMUX,ADMUX_ADLAR);
		break;
	case Left_Adjust:
		SET_BIT(ADMUX,ADMUX_ADLAR);
		break;
	default:
		break;
	}
	/*Select PRESCALLER*/
	switch(Ptr_to_ADC->Pre_Scaller)
	{
	case DIV_BY_2_0:
		CLR_BIT(ADCSRA,ADCSRA_ADPS0);
		CLR_BIT(ADCSRA,ADCSRA_ADPS1);
		CLR_BIT(ADCSRA,ADCSRA_ADPS2);
		break;
	case DIV_BY_2:
		SET_BIT(ADCSRA,ADCSRA_ADPS0);
		CLR_BIT(ADCSRA,ADCSRA_ADPS1);
		CLR_BIT(ADCSRA,ADCSRA_ADPS2);
		break;
	case DIV_BY_4:
		CLR_BIT(ADCSRA,ADCSRA_ADPS0);
		SET_BIT(ADCSRA,ADCSRA_ADPS1);
		CLR_BIT(ADCSRA,ADCSRA_ADPS2);
		break;
	case DIV_BY_8:
		SET_BIT(ADCSRA,ADCSRA_ADPS0);
		SET_BIT(ADCSRA,ADCSRA_ADPS1);
		CLR_BIT(ADCSRA,ADCSRA_ADPS2);
		break;
	case DIV_BY_16:
		CLR_BIT(ADCSRA,ADCSRA_ADPS0);
		CLR_BIT(ADCSRA,ADCSRA_ADPS1);
		SET_BIT(ADCSRA,ADCSRA_ADPS2);
		break;
	case DIV_BY_32:
		SET_BIT(ADCSRA,ADCSRA_ADPS0);
		CLR_BIT(ADCSRA,ADCSRA_ADPS1);
		SET_BIT(ADCSRA,ADCSRA_ADPS2);
		break;
	case DIV_BY_64:
		CLR_BIT(ADCSRA,ADCSRA_ADPS0);
		SET_BIT(ADCSRA,ADCSRA_ADPS1);
		SET_BIT(ADCSRA,ADCSRA_ADPS2);
		break;
	case DIV_BY_128:
		SET_BIT(ADCSRA,ADCSRA_ADPS0);
		SET_BIT(ADCSRA,ADCSRA_ADPS1);
		SET_BIT(ADCSRA,ADCSRA_ADPS2);
		break;
	default:
		break;
	}
	/*Enable or Disable Auto trigger*/
	switch(Ptr_to_ADC->Trigger)
	{
	case AUTO_Trigger_Enable:
		SET_BIT(ADCSRA,ADCSRA_ADATE);
		break;
	case AUTO_Trigger_Disable:
		CLR_BIT(ADCSRA,ADCSRA_ADATE);
		break;
	default:
		break;
	}
	/*Trigger type*/
	switch(Ptr_to_ADC->Trigger_Type)
	{
	case Free_Runnin_Mode:
		SFIOR &= SFIOR_ADC_FREE_RUNNING_MODE_CLEAR;
		SFIOR |= SFIOR_ADC_FREE_RUNNING_MODE_SET;
		break;
	case Analog_Comparator:
		break;
	case EXTI:
		break;
	default:
		break;
	}

	/*ADC_ENABLE*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}


u16 ADC_getDigitalValueSynchNonBlocking(Analog_Channel_Select Channel,ADC_Start ADC_Status)
{
	u16 Reading_value=0;
	u16 Counter=0;

	/*Select ADC Port*/
	ADMUX &= ADMUX_MUX_CLEAR;
	ADMUX |= Channel;
	/*Enable ADC*/
	switch(ADC_Status)
	{
	case ENABLE:
		SET_BIT(ADCSRA,ADCSRA_ADEN);
		break;
	case DISABLE:
		CLR_BIT(ADCSRA,ADCSRA_ADEN);
		break;
	}
	/*Start Conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*loop for the conversion to end*/
	while((GET_BIT(ADCSRA,ADCSRA_ADSC))==1 || Counter<MAX_DELAY)
	{
		Counter++;
	}
	if((GET_BIT(ADCSRA,ADCSRA_ADSC))==0)
	{

		return ADCL_L;
	}
	else
	{
		return 0;
	}
}


void ADC_getDigitalValueAsynchCallBack(Analog_Channel_Select Channel,ADC_Start ADC_Status,Interrupt_Status Interrupt_status)
{

	/*Select ADC Port*/
	ADMUX &= ADMUX_MUX_CLEAR;
	ADMUX |= Channel;
	/*Enable ADC*/
	switch(ADC_Status)
	{
	case ENABLE:
		ADCSRA &= ADCSRA_ADC_ENABLE_MASK_CLEAR;
		ADCSRA |= ADCSRA_ADC_ENABLE_MASK_SET;
		break;
	case DISABLE:
		ADCSRA &= ADCSRA_ADC_ENABLE_MASK_CLEAR;
		break;
	default:
		break;
	}


	/*Enable Interrupt*/
	switch(Interrupt_status)
	{
	case Interrupt_Enable:
		ADCSRA &= ADC_Interrupt_Clear_Mask;
		ADCSRA |= ADC_Interrupt_Set_Mask;
		break;
	case Interrupt_Disable:
		ADCSRA &= ADC_Interrupt_Clear_Mask;
		break;
	default:
		break;
	}
	//SET_BIT(ADCSRA,ADCSRA_ADIE);
	/*Start Conversion*/
	ADCSRA &= ADCSRA_ADC_START_CONV_CLEAR;
	ADCSRA |= ADCSRA_ADC_START_CONV_SET;

}

u16 ADC_Get_Value_Reading(void)
{
	return ADCL_L;
}
void ADC_Interrupt_Enable(void)
{
	SET_BIT(ADCSRA,ADCSRA_ADIE);

}
void ADC_Interrupt_Disable(void)
{
	CLR_BIT(ADCSRA,ADCSRA_ADIE);

}
void ADC_u8INTSetCallBack(void (*Copy_pvINTFunc)(void))
{
	if(Copy_pvINTFunc != NULL)
	{
		ADC_ptr_FUNC=Copy_pvINTFunc;
	}
}
void __vector_16 (void)  __attribute__((signal));
void __vector_16 (void)
{
	if(ADC_ptr_FUNC != NULL)
	{
		ADC_ptr_FUNC();
	}
	else
	{
		/*Stop*/
	}
}
