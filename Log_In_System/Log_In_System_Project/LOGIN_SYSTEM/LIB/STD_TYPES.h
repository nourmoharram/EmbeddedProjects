#ifndef _STD_TYPES_H
#define _STD_TYPES_H

typedef unsigned char       u8;
typedef signed char         s8;
typedef unsigned short int u16;
typedef signed short int   s16;
typedef unsigned long int  u32;
typedef signed long int    s32;
typedef float              f32;
typedef double             f64;

#define NULL  (void *)0

#define OK    0
#define NOK   1
typedef enum
{
	ES_NULL_POINTER,
	ES_OUT_OF_RANGE,
	ES_NO_ERROR,
}Error_States;
#endif
