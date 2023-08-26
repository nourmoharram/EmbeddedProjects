/*
 * OS_Types.h
 *
 *  Created on: Mar 5, 2023
 *      Author: Dell
 */

#ifndef SERVICE_OS_TYPES_H_
#define SERVICE_OS_TYPES_H_

typedef enum
{
	/*
	Five_hundred_ms=500,
	one_thousand_ms=1000,
	two_thousand_ms=2000,
	three_thousand_ms=3000,
	*/
	thousand_ms=1,
	twothousand_ms=2,
	threethousand_ms=3
}Periodicity;

typedef enum
{
	one,
	two,
	three,
}Priority;

typedef enum
{
	Ready,
	Susbend,
	Delete,
	Running
}States;


#endif /* SERVICE_OS_TYPES_H_ */
