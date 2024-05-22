/**
  *******************************************************************************
  * @file      STM32f401_Startupfile.c
  * @author    ADEL MOSTAFA ABDELHAMEED
  * @version   V1.0
  * @date      20/05/2024
  * @brief     STM32F4xx Devices vector table for ARM-GNU toolchain. 
  *            This module performs:
  *                - Set the initial SP
  *                - Set the initial PC == Reset_Handler,
  *                - Set the vector table entries with the exceptions ISR address
  *                - Branches to main in the C library (which eventually
  *                  calls main()).
  *            After Reset the Cortex-M4 processor is in Thread mode,
  *            priority is Privileged, and the Stack is set to Main.
  *******************************************************************************
  */

 
#include "STD_TYPES.h"

#define SRAM_START              0x20000000
#define SRAM_LENGTH             (20 * 1024)     // RAM Length = 20 KBytes
#define SRAM_END                (SRAM_START + SRAM_LENGTH)
#define STACK_START             SRAM_END


extern u32 e_text;
extern u32 s_data;
extern u32 e_data;
extern u32 s_bss;
extern u32 e_bss;

extern void main(void);


void DEFAULT_HANDLER(void);
void Reset_Handler(void);
// if NMI is not defined use the alias , if it's defined-> this definantion is a weak defination "low priority"
                                                           // untill the user define it , 
                                                           // this waek implementaion isn't considered.
void NMI_Handler				(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void HardFault_Handler			(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void MemManage_Handler			(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void BusFault_Handler			(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void UsageFault_Handler			(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void SVC_Handler				(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DebugMon_Handler			(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void PendSV_Handler				(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void SysTick_Handler			(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void WWDG_IRQHandler      		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void PVD_IRQHandler       		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void TAMP_STAMP_IRQHandler		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void RTC_WKUP_IRQHandler  		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void FLASH_IRQHandler     		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void RCC_IRQHandler       		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void EXTI0_IRQHandler     		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void EXTI1_IRQHandler     		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void EXTI2_IRQHandler     		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void EXTI3_IRQHandler     		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void EXTI4_IRQHandler     		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DMA1_Stream0_IRQHandler    (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DMA1_Stream1_IRQHandler    (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DMA1_Stream2_IRQHandler    (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DMA1_Stream3_IRQHandler    (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DMA1_Stream4_IRQHandler    (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DMA1_Stream5_IRQHandler    (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DMA1_Stream6_IRQHandler    (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void ADC_IRQHandler             (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void CAN1_TX_IRQHandler         (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void CAN1_RX0_IRQHandler        (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void CAN1_RX1_IRQHandler        (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void CAN1_SCE_IRQHandler        (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void EXTI9_5_IRQHandler         (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void TIM1_BRK_TIM9_IRQHandler   (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void TIM1_UP_TIM10_IRQHandler   (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void TIM1_TRG_COM_TIM11_IRQHandl(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void TIM1_CC_IRQHandler         (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void TIM2_IRQHandler            (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void TIM3_IRQHandler            (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void TIM4_IRQHandler            (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void I2C1_EV_IRQHandler         (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void I2C1_ER_IRQHandler         (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void I2C2_EV_IRQHandler         (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void I2C2_ER_IRQHandler         (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void SPI1_IRQHandler            (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void SPI2_IRQHandler            (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void USART1_IRQHandler          (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void USART2_IRQHandler          (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void USART3_IRQHandler          (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void EXTI15_10_IRQHandler       (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void RTC_Alarm_IRQHandler       (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void OTG_FS_WKUP_IRQHandler     (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void TIM8_BRK_TIM12_IRQHandler  (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void TIM8_UP_TIM13_IRQHandler   (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void TIM8_TRG_COM_TIM14_IRQHandl(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void TIM8_CC_IRQHandler         (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DMA1_Stream7_IRQHandler    (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void FMC_IRQHandler             (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void SDIO_IRQHandler            (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void TIM5_IRQHandler            (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void SPI3_IRQHandler            (void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void UART4_IRQHandler       	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void UART5_IRQHandler       	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void TIM6_DAC_IRQHandler    	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void TIM7_IRQHandler        	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DMA2_Stream0_IRQHandler	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DMA2_Stream1_IRQHandler	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DMA2_Stream2_IRQHandler	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DMA2_Stream3_IRQHandler	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DMA2_Stream4_IRQHandler	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void CAN2_TX_IRQHandler       	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void CAN2_RX0_IRQHandler      	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void CAN2_RX1_IRQHandler      	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void CAN2_SCE_IRQHandler      	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void OTG_FS_IRQHandler        	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DMA2_Stream5_IRQHandler  	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DMA2_Stream6_IRQHandler  	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DMA2_Stream7_IRQHandler  	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void USART6_IRQHandler        	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void I2C3_EV_IRQHandler       	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void I2C3_ER_IRQHandler       	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void OTG_HS_EP1_OUT_IRQHandler	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void OTG_HS_EP1_IN_IRQHandler 	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void OTG_HS_WKUP_IRQHandler   	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void OTG_HS_IRQHandler        	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void DCMI_IRQHandler          	(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void FPU_IRQHandler       		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void SPI4_IRQHandler      		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void SAI1_IRQHandler      		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void SAI2_IRQHandler      		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void QUADSPI_IRQHandler   		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void CEC_IRQHandler       		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void SPDIF_RX_IRQHandler  		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void FMPI2C1_EV_IRQHandler		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));
void FMPI2C1_ER_IRQHandler		(void) __attribute__((weak,alias("DEFAULT_HANDLER")));


// vector table -> array of addresses { MSP , Reset Handler , .. }
u32 Vectors[] __attribute__((section(".isr_vector"))) =
{
	STACK_START                         ,
	(u32)Reset_Handler                  , // defined
	(u32)NMI_Handler				    ,
	(u32)HardFault_Handler			    ,
	(u32)MemManage_Handler			    ,
	(u32)BusFault_Handler			    ,
	(u32)UsageFault_Handler			    ,
	0  /*Reserved*/                     ,
	0  /*Reserved*/                     ,
	0  /*Reserved*/                     ,
	0  /*Reserved*/                     ,
    (u32)SVC_Handler				    ,
    (u32)DebugMon_Handler			    ,
	0  /*Reserved*/                     ,
    (u32)PendSV_Handler				    ,
    (u32)SysTick_Handler			    ,
    (u32)WWDG_IRQHandler      		    ,
    (u32)PVD_IRQHandler       		    ,
    (u32)TAMP_STAMP_IRQHandler		    ,
    (u32)RTC_WKUP_IRQHandler  		    ,
    (u32)FLASH_IRQHandler     		    ,
    (u32)RCC_IRQHandler       		    ,
    (u32)EXTI0_IRQHandler     		    ,
    (u32)EXTI1_IRQHandler     		    ,
    (u32)EXTI2_IRQHandler     		    ,
    (u32)EXTI3_IRQHandler     		    ,
    (u32)EXTI4_IRQHandler     		    ,
    (u32)DMA1_Stream0_IRQHandler        ,
    (u32)DMA1_Stream1_IRQHandler        ,
    (u32)DMA1_Stream2_IRQHandler        ,
    (u32)DMA1_Stream3_IRQHandler        ,
    (u32)DMA1_Stream4_IRQHandler        ,
    (u32)DMA1_Stream5_IRQHandler        ,
    (u32)DMA1_Stream6_IRQHandler        ,
    (u32)ADC_IRQHandler                 ,
    (u32)CAN1_TX_IRQHandler             ,
    (u32)CAN1_RX0_IRQHandler            ,
    (u32)CAN1_RX1_IRQHandler            ,
    (u32)CAN1_SCE_IRQHandler            ,
    (u32)EXTI9_5_IRQHandler             ,
    (u32)TIM1_BRK_TIM9_IRQHandler       ,
    (u32)TIM1_UP_TIM10_IRQHandler       ,
    (u32)TIM1_TRG_COM_TIM11_IRQHandl    ,
    (u32)TIM1_CC_IRQHandler             ,
    (u32)TIM2_IRQHandler                ,
    (u32)TIM3_IRQHandler                ,
    (u32)TIM4_IRQHandler                ,
    (u32)I2C1_EV_IRQHandler             ,
    (u32)I2C1_ER_IRQHandler             ,
    (u32)I2C2_EV_IRQHandler             ,
    (u32)I2C2_ER_IRQHandler             ,
    (u32)SPI1_IRQHandler                ,
    (u32)SPI2_IRQHandler                ,
    (u32)USART1_IRQHandler              ,
    (u32)USART2_IRQHandler              ,
    (u32)USART3_IRQHandler              ,
    (u32)EXTI15_10_IRQHandler           ,
    (u32)RTC_Alarm_IRQHandler           ,
    (u32)OTG_FS_WKUP_IRQHandler         ,
    (u32)TIM8_BRK_TIM12_IRQHandler      ,
    (u32)TIM8_UP_TIM13_IRQHandler       ,
    (u32)TIM8_TRG_COM_TIM14_IRQHandl    ,
    (u32)TIM8_CC_IRQHandler             ,
    (u32)DMA1_Stream7_IRQHandler        ,
    (u32)FMC_IRQHandler                 ,
    (u32)SDIO_IRQHandler                ,
    (u32)TIM5_IRQHandler                ,
    (u32)SPI3_IRQHandler                ,
    (u32)UART4_IRQHandler       	    ,
    (u32)UART5_IRQHandler       	    ,
    (u32)TIM6_DAC_IRQHandler    	    ,
    (u32)TIM7_IRQHandler        	    ,
    (u32)DMA2_Stream0_IRQHandler	    ,
    (u32)DMA2_Stream1_IRQHandler	    ,
    (u32)DMA2_Stream2_IRQHandler	    ,
    (u32)DMA2_Stream3_IRQHandler	    ,
    (u32)DMA2_Stream4_IRQHandler	    ,
	0  /*Reserved*/                     ,
	0  /*Reserved*/                     ,
    (u32)CAN2_TX_IRQHandler       	    ,
    (u32)CAN2_RX0_IRQHandler      	    ,
    (u32)CAN2_RX1_IRQHandler      	    ,
    (u32)CAN2_SCE_IRQHandler      	    ,
    (u32)OTG_FS_IRQHandler        	    ,
    (u32)DMA2_Stream5_IRQHandler  	    ,
    (u32)DMA2_Stream6_IRQHandler  	    ,
    (u32)DMA2_Stream7_IRQHandler  	    ,
    (u32)USART6_IRQHandler        	    ,
    (u32)I2C3_EV_IRQHandler       	    ,
    (u32)I2C3_ER_IRQHandler       	    ,
    (u32)OTG_HS_EP1_OUT_IRQHandler	    ,
    (u32)OTG_HS_EP1_IN_IRQHandler 	    ,
    (u32)OTG_HS_WKUP_IRQHandler   	    ,
    (u32)OTG_HS_IRQHandler        	    ,
    (u32)DCMI_IRQHandler          	    ,
	0  /*Reserved*/                     ,
	0  /*Reserved*/                     ,
    (u32)FPU_IRQHandler       		    ,
	0  /*Reserved*/                     ,
	0  /*Reserved*/                     ,
    (u32)SPI4_IRQHandler      		    ,
	0  /*Reserved*/                     ,
	0  /*Reserved*/                     ,
    (u32)SAI1_IRQHandler      		    ,
	0  /*Reserved*/                     ,
	0  /*Reserved*/                     ,
	0  /*Reserved*/                     ,
    (u32)SAI2_IRQHandler      		    ,
    (u32)QUADSPI_IRQHandler   		    ,
    (u32)CEC_IRQHandler       		    ,
    (u32)SPDIF_RX_IRQHandler  		    ,
    (u32)FMPI2C1_EV_IRQHandler		    ,
    (u32)FMPI2C1_ER_IRQHandler		    ,
};


void DEFAULT_HANDLER(void)
{
    while (1);
}

void Reset_Handler(void)
{
    // reallocate .data from FLASH to SRAM
    // calculate size of .data section 
    u32 data_size = (u32)&e_data - (u32)&s_data ;

    // one step
    // the address of .data in FLASH
    u32 *SrcData = (&(e_text) + 1);
    // the address of .data in SRAM
    u32 *DestData = &(s_data);

    u32 *DestBSS = &(s_bss);

    for(u32 i = 0 ; i < data_size ; i++)
    {
        // copying for SrcData -> from FLASH //to// DestData -> SRAM
        *(DestData) = *(SrcData);
        DestData++ ; 
        SrcData++ ;
        // *(DestData++) = *(SrcData++);
    }

    // calculate size of .bss section in SRAM
    u32 bss_size = (u32)&e_bss - (u32)&s_bss ;

    // .bss does not exist in FLASH and this is the instruction to reserve it in
    // initialize .bss with zeros
    for(u32 i = 0 ; i < bss_size ; i++)
    {
        *DestBSS = 0U;
        DestBSS++;
    }

    // call enrty point
    main();

    // Exit routine due to make PC can not fetch from another place in FLASH
    while (1);
}