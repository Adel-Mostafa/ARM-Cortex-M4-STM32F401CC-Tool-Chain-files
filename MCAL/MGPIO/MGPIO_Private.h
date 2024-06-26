/*
 *  MGPIO_Private.h
 *  Created on: April 22, 2024
 *  Author: ADEL MOSTAFA ABDELHAMEED
 */

#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_

/************************************* LIBRARY *****************************************/
#include "LIB/BIT_MATH.h"
#include "LIB/STD_Types.h"
/****************************************************************************/
/*						PERIPHERALS BASE ADDRESS							*/
/****************************************************************************/
#define GPIOA_BASE_ADDRESS		(0x40020000)
#define GPIOB_BASE_ADDRESS		(0x40020400)
#define GPIOC_BASE_ADDRESS		(0x40020800)
#define GPIOD_BASE_ADDRESS		(0x40020C00)
#define GPIOE_BASE_ADDRESS		(0x40021000)
#define GPIOH_BASE_ADDRESS		(0x40021C00)

/****************************************************************************/
/*						REGISTERS STRUCTURE									*/
/****************************************************************************/

typedef	struct{
	u32 MODER	;
	u32	OTYPER	;
	u32	OSPEEDR	;
	u32	PUPDR	;
	u32	IDR		;
	u32	ODR		;
	u32	BSRR	;
	u32 LCKR	;
	u32 AFRL	;
	u32	AFRH	;
}GPIO_t;


/****************************************************************************/
/*								PERIPHERALS 								*/
/****************************************************************************/

#define GPIOA		((volatile GPIO_t *)GPIOA_BASE_ADDRESS)
#define GPIOB		((volatile GPIO_t *)GPIOB_BASE_ADDRESS)
#define GPIOC		((volatile GPIO_t *)GPIOC_BASE_ADDRESS)
#define GPIOD		((volatile GPIO_t *)GPIOD_BASE_ADDRESS)
#define GPIOE		((volatile GPIO_t *)GPIOE_BASE_ADDRESS)
#define GPIOH		((volatile GPIO_t *)GPIOH_BASE_ADDRESS)

/****************************************************************************/
/*						       PRIVATE MACROS								*/
/****************************************************************************/
#define ONE_BIT_MASK				0b1
#define TWO_BIT_MASK				0b11
#define FOUR_BIT_MASK				0b1111
#define EIGHT_BIT_MASK				0xff00


#endif /* MGPIO_PRIVATE_H_ */
