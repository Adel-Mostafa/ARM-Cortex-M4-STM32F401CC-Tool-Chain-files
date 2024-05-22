#ifndef _STD_TYPES_H
#define _STD_TYPES_H

#include <stddef.h>

typedef enum{
	E_OK,
	E_NOK,
	E_NOK_NULL_PTR,
	E_NOK_OUT_OF_RANGE,
}ReturnType_State_t;

typedef enum {
	IDLE,
	BUSY
}Module_State_t;

typedef unsigned char 				u8;
typedef unsigned short int 			u16;
typedef unsigned long int 			u32;
typedef unsigned long long int 		u64;

typedef signed char 				s8;
typedef signed short int 			s16;
typedef signed long int 			s32;
typedef signed long long int 		s64;

typedef double 						f32;

typedef void(* PtrToFunc_void)(void);

#endif
