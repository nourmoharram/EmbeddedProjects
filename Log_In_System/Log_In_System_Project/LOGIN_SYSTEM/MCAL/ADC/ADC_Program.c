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
//#include"ADC_CONFIG.h"
#include"ADC_Types.h"
#include"ADC_Init.h"


Error_States_ADC ADC_Init(ADC_ConfigType *Ptr_to_ADC)
{
	Error_States_ADC Error_state= Valid;
	if(Ptr_to_ADC->Voltage_Ref_Value==VCC_5V)
	{
		/*select 5v*/
		CLR_BIT(ADMUX,ADMUX_REFS0);
		SET_BIT(ADMUX,ADMUX_REFS1);

	}
	else if(Ptr_to_ADC->Voltage_Ref_Value==VREF_2_5_V)
	{
		/*select 2.56v*/
		SET_BIT(ADMUX,ADMUX_REFS0);
		SET_BIT(ADMUX,ADMUX_REFS1);
	}
	if(Ptr_to_ADC->AdjustType==Right_Adjust)
	{
		/*Select right adjust*/
		CLR_BIT(ADMUX,ADMUX_ADLAR);
	}
	else if(Ptr_to_ADC->AdjustType==Right_Adjust)
	{
		/*Select left adjust*/
		SET_BIT(ADMUX,ADMUX_ADLAR);
	}
	if(Ptr_to_ADC->Pre_Scaller==DIV_BY_128)
	{
		/*Select Pre-scaller 128*/
		SET_BIT(ADCSRA,ADCSRA_ADPS0);
		SET_BIT(ADCSRA,ADCSRA_ADPS1);
		SET_BIT(ADCSRA,ADCSRA_ADPS2);

	}
	else if(Ptr_to_ADC->Pre_Scaller==DIV_BY_2)
	{
		/**/
		CLR_BIT(ADCSRA,ADCSRA_ADPS0);
		CLR_BIT(ADCSRA,ADCSRA_ADPS1);
		CLR_BIT(ADCSRA,ADCSRA_ADPS2);
	}
	return Error_state;
}

u16 ADC_getDigitalValueSynchNonBlocking(ADC_ConfigType *Ptr_to_ADC)
{
	u16 Reading_value=0;
	u16 Counter=0;
	/*Select port*/
	if(Ptr_to_ADC->Channel==ADC0)
	{
		/*Select ADC0*/

		CLR_BIT(ADMUX,ADMUX_MUX0);
		CLR_BIT(ADMUX,ADMUX_MUX1);
		CLR_BIT(ADMUX,ADMUX_MUX2);
		CLR_BIT(ADMUX,ADMUX_MUX3);
		CLR_BIT(ADMUX,ADMUX_MUX4);

	}

	/*Enable ADC*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
	/*Start Conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*loop for the conversion to end*/
	while((GET_BIT(ADCSRA,ADCSRA_ADSC))==1 || Counter<= MAX_DELAY)
	{
		Counter++;
	}
	if((GET_BIT(ADCSRA,ADCSRA_ADSC))==0)
	{
		//Reading_value= ((ADCL*5)/10);
		//return Reading_value;
		return ADCL;
	}
	else
	{
		return 0;
	}
}


