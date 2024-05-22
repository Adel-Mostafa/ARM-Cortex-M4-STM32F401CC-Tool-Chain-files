/**
  ******************************************************************************
  * @file      main.c
  * @author    ADEL MOSTAFA ABDELHAMEED
  * @version   V1.0
  * @date      20/05/2024
  * @brief     main() file, will apply startup code & linkerscript on it
  *            This module performs:
  *                - Set the MCU clock for GPIO peripheral. 
  *                - Set pins on output mode.
  *                - Set some operations to test the tool chain.
  ******************************************************************************
  */

// ------ Libraries -----------------------------------------------------------
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

// ------ MCAL ----------------------------------------------------------------
#include "MCAL/MRCC/MRCC_Interface.h"
#include "MCAL/MGPIO/MGPIO_Interface.h"

// ------ Global variables ----------------------------------------------------
char x = 10 ;
int y ;

// ------ Exceptions Handlers Prototypes --------------------------------------
void SVC_Handler(void);
void BusFault_Handler(void);

// ------ main() --------------------------------------------------------------
void main(void)
{
	// ----- 0_Local variables ------------------------------------------------

	// ----- 1_clock gating ---------------------------------------------------
	MRCC_voidInit();
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOA);

	// ----- 2_Initializaion --------------------------------------------------
	MGPIO_voidSetPinMode(GPIO_PORTA,0,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTA,1,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTA,2,GPIO_OUTPUT);

	// ----- 3_Application ----------------------------------------------------
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,0,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,1,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,2,GPIO_PUSH_PULL,GPIO_LOW_SPEED);


	// ----- Infinite loop ----------------------------------------------------
	while(1)
	{
		MGPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_PIN_HIGH);
		for(u16 i=0;i<1000;i++)
		{
			asm("NOP");
		}
		MGPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_PIN_HIGH);
		for(u16 i=0;i<10000;i++)
		{
			asm("NOP");
		}
		MGPIO_voidSetPinValue(GPIO_PORTA,2,GPIO_PIN_HIGH);
		for(u16 i=0;i<16000;i++)
		{
			asm("NOP");
		}


	}
}

// ----------------------------------------------------------------------------

// ------ Exceptions Handlers Definitions -------------------------------------
void SVC_Handler(void){
	asm("nop");
}

void BusFault_Handler(void){
	asm("nop");
}

