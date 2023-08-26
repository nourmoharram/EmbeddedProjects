/*
 * Motor_cfg.h
 *
 * Created: 3/4/2023 1:36:46 AM
 *  Author: ahmed57
 */ 


#ifndef MOTOR_CFG_H_
#define MOTOR_CFG_H_

#include "Dio_types.h"
#include "Port_types.h"
#include "Port_cfg.h"

/* Set Motors Pin the same for DIO and PORT   */
#define MOTOR_PWM_PIN			DIO_PB3
#define MOTOR_DIR_PIN			DIO_PB5
#define MOTOR_EN_PIN			DIO_PB6


#define MOTOR_PWM_PORT_PIN			PORT_PB3
#define MOTOR_DIR_PORT_PIN			PORT_PB5
#define MOTOR_EN_PORT_PIN			PORT_PB6

/* Pin Configuration */
typedef struct {
	Port_PinType             Port_PinNumber; //PA0 or PA1...etc
	Port_LevelType           Port_PinLevelValue;// initial value of pin
	Port_PinDirectionType    Port_PinDirection; // input or output
	Port_InternalAttachType  Port_PinInternalAttach;//pull up or floating

}MOTOR_Port_Config;


#endif /* MOTOR_CFG_H_ */