/*
 * TIMER0_cfg.h
 *
 *  Created on: Feb 25, 2023
 *      Author: ahmed57
 */

#ifndef TIMER0_CFG_H_
#define TIMER0_CFG_H_

#include "TIMER0_types.h"
#include "Port_types.h"
#include "Port_cfg.h"

#define FCPU			16000000


/* Pin Configuration */
typedef struct {
	Port_PinType             Port_PinNumber; //PA0 or PA1...etc
	Port_LevelType           Port_PinLevelValue;// initial value of pin
	Port_PinDirectionType    Port_PinDirection; // input or output
	Port_InternalAttachType  Port_PinInternalAttach;//pull up or floating

}TIMER0_Port_Config;


/*
typedef struct{
	TIMER0_NON_PWM_OC0_MODES_t			   OC0_NONPWM_MODE;
	TIMER0_PWM_FAST_OC0_MODES_t			   OC0_FASTPWM_MODE;
	TIMER0_PWM_PHASECORRECT_OC0_MODES_t    OC0_PHASECORRECT_MODE;

}OC0_MODES_t;


typedef struct{

	TIMER0_MODES_t		TIMER0_MODE;
	OC0_MODES_t			TIMER0_OC0_MODE;


}TIMER0_CONFIG;

*/

//TIMER0_CONFIG A;



#endif /* TIMER0_CFG_H_ */
