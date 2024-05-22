/**
  ******************************************************************************
  * @file      STM32f401_linkerscript.ld
  * @author    ADEL MOSTAFA ABDELHAMEED
  * @version   V1.0
  * @date      20/05/2024
  * @brief     STM32F4xx Devices linker script for ARM-GNU toolchain. 
  *            This module performs:
  *                - Set the Entry Reset_Handler
  *                - Set Memories sizes, starting address and their operation.
  *                - Set the memory sections and their sizes
  ******************************************************************************
  */

ENTRY(Reset_Handler) /* entry point of system to be run */

MEMORY  /* memory describtions */
{
    FLASH(rx) : ORIGIN = 0x08000000 ,LENGTH = 256K
    SRAM(rwx) : ORIGIN = 0x20000000 ,LENGTH = 20K
}

SECTIONS
{
    .text : 
    {
        s_text = . ;
        *(.isr_vector)
        *(.text)
        *(.rodata)
        e_text = . ;
    }>FLASH                   /* >VMA>LMA */
    .data :
    {
        s_data = . ;
        *(.data)
        . = ALIGN(4);
        e_data = . ;
    }>SRAM  AT> FLASH        /* >VMA>LMA */
    .bss :
    {
        s_bss = . ;
        *(.bss)
        e_bss = . ;
    }>SRAM
}