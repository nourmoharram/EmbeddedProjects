/*
 * APP_types.h
 *
 *  Created on: Mar 16, 2023
 *      Author: LENOVO
 */

#ifndef APP_TYPES_H_
#define APP_TYPES_H_


typedef enum{
	INVALID_LOGIN,
	VALID_LOGIN

}LOGIN_STATE;

typedef enum{
	INCORRECT_PASS,
	CORRECT_PASS

}PASS_STATE;


typedef enum
{
	Login_Nok=0,
	Login_Ok
}Login_State;

typedef enum
{
	Pass_Nok,
	Pass_Ok
}Pass_State;


#endif /* APP_TYPES_H_ */
