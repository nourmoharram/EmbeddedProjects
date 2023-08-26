/*
 * ADC_Types.h
 *
 *  Created on: Mar 3, 2023
 *      Author: ahmed
 */

#ifndef SRC_MCAL_ADC_ADC_TYPES_H_
#define SRC_MCAL_ADC_ADC_TYPES_H_

typedef enum{
	PRES_1		=0,
	PRES_2		=1,
	PRES_4		=2,
	PRES_8		=3,
	PRES_16		=4,
	PRES_32		=5,
	PRES_64		=6,
	PRES_128	=7
}ADC_PRES_TYPE;

typedef enum{
	CHNL_0=0,
	CHNL_1,
	CHNL_2,
	CHNL_3,
	CHNL_4,
	CHNL_5,
	CHNL_6,
	CHNL_7,
	CHNL_8,
	CHNL_9,
	CHNL_10,
	CHNL_11,
	CHNL_12,
	CHNL_13,
	CHNL_14,
	CHNL_15,
	CHNL_16,
	CHNL_17,
	CHNL_18,
	CHNL_19,
	CHNL_20,
	CHNL_21,
	CHNL_22,
	CHNL_23,
	CHNL_24,
	CHNL_25,
	CHNL_26,
	CHNL_27,
	CHNL_28,
	CHNL_29,
	CHNL_30,
	CHNL_31,
}ADC_CHNL_TYPE;

typedef enum{
	SINGLE_CONV		,
	AUTOTRIGGERED
}ADC_MODE_TYPE;

typedef enum{
	FREE_RUNINNG	=0,
	EXT0 			=2,
	TIM0_OVF		=4
}ADC_TRIG_SRC_TYPE;

typedef enum{
	POLLING			=0,
 	 ENABLED		=1
}ADC_INT_MODE;

typedef enum{
	AREF_REF		=0,
	AVCC_REF	 	=1,
	INTERNAL_REF	=3
}ADC_VREF_TYPE;

typedef enum{
	LEFT_ADJ		=1,
	RIGHT_ADJ		=0
}ADC_ADJ_TYPE;

#endif /* SRC_MCAL_ADC_ADC_TYPES_H_ */
