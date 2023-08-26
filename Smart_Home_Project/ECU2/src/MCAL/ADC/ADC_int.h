/*
 * ADC_int.h
 *
 *  Created on: Mar 3, 2023
 *      Author: ahmed
 */

/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : ADC_int.h
*  Brief   : interface file for ADC module
*  details : contains functions prototypes for ADC module
*****************************************************************/
#ifndef SRC_MCAL_ADC_ADC_INT_H_
#define SRC_MCAL_ADC_ADC_INT_H_


/******************************************
  INCLUDES
*******************************************/
#include "Error_State.h"
#include "ADC_cfg.h"
#include "STD_TYPES.h"


/******************************************
   GLOBAL FUNCTIONS PROTOTYPES
*******************************************/

/******************************************
  syntax :

  Description : initilization function for ADC peripheral

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  : ADC_cfg_type copy_ADCcfg
  parameters (out) : none
  Return Value     : void
******************************************/

ES_t M_ADC_enu_init(ADC_cfg_type copy_ADCcfg);
/******************************************
  syntax :

  Description :

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :
  parameters (out) : none
  Return Value     : void
******************************************/
ES_t M_ADC_enu_selectChannel(ADC_CHNL_TYPE copy_ADC_chnl);
/******************************************
  syntax :

  Description :

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :
  parameters (out) : none
  Return Value     : void
******************************************/
ES_t M_ADC_enu_getDigitalValueSynchNonBlocking(ADC_cfg_type* copy_ADCcfg, u8* voltage);
/******************************************
  syntax :

  Description :

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :
  parameters (out) : none
  Return Value     : void
******************************************/
ES_t M_ADC_enu_getDigitalValueAsynchCallBack( float* voltage);
/******************************************
  syntax :

  Description :

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :
  parameters (out) : none
  Return Value     : void
******************************************/
ES_t M_ADC_enu_setCallBack(ES_t (*Copy_pfunAppFun)(void*), void * Copy_pvidAppParameter);
/******************************************
  syntax :

  Description :

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :
  parameters (out) : none
  Return Value     : void
******************************************/
ES_t M_ADC_enu_startConversion();

#endif /* SRC_MCAL_ADC_ADC_INT_H_ */
