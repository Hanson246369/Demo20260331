;/******************** (C) COPYRIGHT 2017 Sinowealth ********************
;* File Name          : startup_sh32f2xx_iar.s
;* Author             : MCD Application Team
;* Version            : V1.0.0
;* Date               : 07-March-2017
;* Description        : SH32F205xx devices vector table for EWARM toolchain.
;*                      This module performs:
;*                      - Set the initial SP
;*                      - Set the initial PC == _iar_program_start,
;*                      - Set the vector table entries with the exceptions ISR 
;*                        address.
;*                      - Branches to main in the C library (which eventually
;*                        calls main()).
;*                      After Reset the Cortex-M3 processor is in Thread mode,
;*                      priority is Privileged, and the Stack is set to Main.
;********************************************************************************
;* 
;* Redistribution and use in source and binary forms, with or without modification,
;* are permitted provided that the following conditions are met:
;*   1. Redistributions of source code must retain the above copyright notice,
;*      this list of conditions and the following disclaimer.
;*   2. Redistributions in binary form must reproduce the above copyright notice,
;*      this list of conditions and the following disclaimer in the documentation
;*      and/or other materials provided with the distribution.
;*   3. Neither the name of STMicroelectronics nor the names of its contributors
;*      may be used to endorse or promote products derived from this software
;*      without specific prior written permission.
;*
;* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
;* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
;* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
;* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
;* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
;* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
;* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
;* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
;* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
;* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;* 
;*******************************************************************************
; *
; * SINOWEALTH IS SUPPLYING THIS SOFTWARE FOR USE EXCLUSIVELY ON SINOWEALTH'S 
; * MICROCONTROLLER PRODUCTS. IT IS PROTECTED UNDER APPLICABLE COPYRIGHT LAWS. 
; * THIS SOFTWARE IS FOR GUIDANCE IN ORDER TO SAVE TIME. AS A RESULT, SINOWEALTH 
; * SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES 
; * WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH FIRMWARE AND/OR
; * THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN IN 
; * CONNECTION WITH THEIR PRODUCTS.
; *
; * <h2><center>&copy; COPYRIGHT 2017 Sinowealth</center></h2>
; *
; ******************************************************************************
; */
;
;
; The modules in this file are included in the libraries, and may be replaced
; by any user-defined modules that define the PUBLIC symbol _program_start or
; a user defined start symbol.
; To override the cstartup defined in the library, simply add your modified
; version to the workbench project.
;
; The vector table is normally located at address 0.
; When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
; The name "__vector_table" has special meaning for C-SPY:
; it is where the SP start value is found, and the NVIC vector
; table register (VTOR) is initialized to this address if != 0.
;
; Cortex-M version
;



        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT (3)

        SECTION .intvec:CODE:NOROOT (2)

        EXTERN  __iar_program_start
        PUBLIC  __vector_table

        DATA
__vector_table

     DCD      sfe(CSTACK)          ;/* -16 (000H) Top of Stack                                  */
     DCD      Reset_Handler        ;/* -15 (004H) Reset Handler                                 */
     DCD      NMI_Handler          ;/* -14 (008H) Non Maskable Interrupt                        */
     DCD      HardFault_Handler    ;/* -13 (00CH) Hard Fault Interrupt                          */
     DCD      Default_Handler      ;/* -12 (010H) Reserved                                      */
     DCD      Default_Handler      ;/* -11 (014H) Reserved                                      */
     DCD      Default_Handler      ;/* -10 (018H) Reserved                                      */
     DCD      Default_Handler      ;/*  -9 (01CH) Reserved                                      */
     DCD      Default_Handler      ;/*  -8 (020H) Reserved                                      */
     DCD      Default_Handler      ;/*  -7 (024H) Reserved                                      */
     DCD      Default_Handler      ;/*  -6 (028H) Reserved                                      */
     DCD      SVC_Handler          ;/*  -5 (02CH) Cortex-M0+ SV Call Interrupt                  */
     DCD      Default_Handler      ;/*  -4 (030H) Reserved                                      */
     DCD      Default_Handler      ;/*  -3 (034H) Reserved                                      */
     DCD      PendSV_Handler       ;/*  -2 (038H) Cortex-M0+ Pend SV Interrupt                  */
     DCD      SysTick_Handler      ;/*  -1 (03CH) Cortex-M0+ System Tick Interrupt              */
     DCD      WWDT_Handler         ;/*   0 (040H) Window WatchDog Interrupt                     */
     DCD      BOD_Handler          ;/*   1 (044H) PVD through EXTI Line detection Interrupt     */
     DCD      RCC_Handler          ;/*   2 (048H) RCC global Interrupt                          */
     DCD      EXTI0_Handler        ;/*   3 (04CH) EXTI Line0 Interrupt                          */
     DCD      EXTI1_Handler        ;/*   4 (050H) EXTI Line1 Interrupt                          */
     DCD      EXTI2_Handler        ;/*   5 (054H) EXTI Line2 Interrupt                          */
     DCD      EXTI3_Handler        ;/*   6 (058H) EXTI Line3 Interrupt                          */
     DCD      DMA_CH0_1_Handler    ;/*   7 (05CH) DMA Channel0 ~ Channel1 Interrupt             */
     DCD      DMA_CH2_3_Handler    ;/*   8 (060H) DMA Channel2 ~ Channel3 Interrupt             */
     DCD      ADC_Handler          ;/*   9 (064H) ADC Interrupt                                 */
     DCD      PWM0_Handler         ;/*  10 (068H) PWM0 Interrupt                                */
     DCD      PWM1_Handler         ;/*  11 (06CH) PWM1 Interrupt                                */
     DCD      PWM2_Handler         ;/*  12 (070H) PWM2 Interrupt                                */
     DCD      PWM3_Handler         ;/*  13 (074H) PWM3 Interrupt                                */
     DCD      PCA0_Handler         ;/*  14 (078H) PCA0 Interrupt                                */
     DCD      PCA1_Handler         ;/*  15 (07CH) PCA1 Interrupt                                */
     DCD      PCA2_Handler         ;/*  16 (080H) PCA2 Interrupt                                */
     DCD      PCA3_Handler         ;/*  17 (084H) PCA3 Interrupt                                */
     DCD      EXTI9_4_Handler      ;/*  18 (088H) EXTI Line4 ~ Line9 global Interrupt           */
     DCD      UART0_Handler        ;/*  19 (08CH) UART0 Interrupt                               */
     DCD      TWI0_Handler         ;/*  20 (090H) TWI0 Interrupt                                */
     DCD      SPI0_Handler         ;/*  21 (094H) SPI0 Interrupt                                */
     DCD      SPI1_LED_Handler     ;/*  22 (098H) SPI1&LED Interrupt                            */
     DCD      UART1_Handler        ;/*  23 (09CH) UART1 Interrupt                               */
     DCD      UART2_Handler        ;/*  24 (0A0H) UART2 Interrupt                               */
     DCD      UART3_Handler        ;/*  25 (0A4H) UART3 Interrupt                               */
     DCD      EXTI15_10_Handler    ;/*  26 (0A8H) EXTI Line10 ~ Line15 Interrupt                */
     DCD      TIM0_Handler         ;/*  27 (0ACH) TIM0 Interrupt                                */
     DCD      TIM1_Handler         ;/*  28 (0B0H) TIM1 Interrupt                                */
     DCD      TIM2_Handler         ;/*  29 (0B4H) TIM2 Interrupt                                */
     DCD      TIM3_Handler         ;/*  30 (0B8H) TIM3 Interrupt                                */
     DCD      TouchKey_Handler     ;/*  31 (0BCH) TouchKey Interrupt                            */


	THUMB
	PUBWEAK Reset_Handler
	SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler
	
        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        BX      R0
	
	PUBWEAK SystemInit
	SECTION .text:CODE:REORDER:NOROOT(1)
SystemInit
	BX LR
	
	PUBWEAK NMI_Handler
	SECTION .text:CODE:REORDER:NOROOT(1)
NMI_Handler
	B NMI_Handler	

	PUBWEAK HardFault_Handler
	SECTION .text:CODE:REORDER:NOROOT(1)
HardFault_Handler
	B HardFault_Handler
	
	PUBWEAK MemManage_Handler
	SECTION .text:CODE:REORDER:NOROOT(1)
MemManage_Handler
	B MemManage_Handler

	PUBWEAK BusFault_Handler
	SECTION .text:CODE:REORDER:NOROOT(1)
BusFault_Handler
	B BusFault_Handler

	PUBWEAK UsageFault_Handler
	SECTION .text:CODE:REORDER:NOROOT(1)
UsageFault_Handler
	B UsageFault_Handler

	PUBWEAK SVC_Handler
	SECTION .text:CODE:REORDER:NOROOT(1)
SVC_Handler
	B SVC_Handler

	PUBWEAK DebugMon_Handler
	SECTION .text:CODE:REORDER:NOROOT(1)
DebugMon_Handler
	B DebugMon_Handler

	PUBWEAK PendSV_Handler
	SECTION .text:CODE:REORDER:NOROOT(1)
PendSV_Handler
	B PendSV_Handler

	PUBWEAK SysTick_Handler
	SECTION .text:CODE:REORDER:NOROOT(1)
SysTick_Handler
	B SysTick_Handler
	
					
    PUBWEAK    WWDT_Handler        
    SECTION .text:CODE:REORDER:NOROOT(1)
WWDT_Handler        
    B WWDT_Handler        
    PUBWEAK    BOD_Handler         
    SECTION .text:CODE:REORDER:NOROOT(1)
BOD_Handler         
    B BOD_Handler         
    PUBWEAK    RCC_Handler         
    SECTION .text:CODE:REORDER:NOROOT(1)
RCC_Handler         
    B RCC_Handler         
    PUBWEAK    EXTI0_Handler       
    SECTION .text:CODE:REORDER:NOROOT(1)
EXTI0_Handler       
    B EXTI0_Handler       
    PUBWEAK    EXTI1_Handler       
    SECTION .text:CODE:REORDER:NOROOT(1)
EXTI1_Handler       
    B EXTI1_Handler       
    PUBWEAK    EXTI2_Handler       
    SECTION .text:CODE:REORDER:NOROOT(1)
EXTI2_Handler       
    B EXTI2_Handler       
    PUBWEAK    EXTI3_Handler       
    SECTION .text:CODE:REORDER:NOROOT(1)
EXTI3_Handler       
    B EXTI3_Handler       
    PUBWEAK    DMA_CH0_1_Handler   
    SECTION .text:CODE:REORDER:NOROOT(1)
DMA_CH0_1_Handler   
    B DMA_CH0_1_Handler   
    PUBWEAK    DMA_CH2_3_Handler   
    SECTION .text:CODE:REORDER:NOROOT(1)
DMA_CH2_3_Handler   
    B DMA_CH2_3_Handler   
    PUBWEAK    ADC_Handler         
    SECTION .text:CODE:REORDER:NOROOT(1)
ADC_Handler         
    B ADC_Handler         
    PUBWEAK    PWM0_Handler        
    SECTION .text:CODE:REORDER:NOROOT(1)
PWM0_Handler        
    B PWM0_Handler        
    PUBWEAK    PWM1_Handler        
    SECTION .text:CODE:REORDER:NOROOT(1)
PWM1_Handler        
    B PWM1_Handler        
    PUBWEAK    PWM2_Handler        
    SECTION .text:CODE:REORDER:NOROOT(1)
PWM2_Handler        
    B PWM2_Handler        
    PUBWEAK    PWM3_Handler        
    SECTION .text:CODE:REORDER:NOROOT(1)
PWM3_Handler        
    B PWM3_Handler        
    PUBWEAK    PCA0_Handler        
    SECTION .text:CODE:REORDER:NOROOT(1)
PCA0_Handler        
    B PCA0_Handler        
    PUBWEAK    PCA1_Handler        
    SECTION .text:CODE:REORDER:NOROOT(1)
PCA1_Handler        
    B PCA1_Handler        
    PUBWEAK    PCA2_Handler        
    SECTION .text:CODE:REORDER:NOROOT(1)
PCA2_Handler        
    B PCA2_Handler        
    PUBWEAK    PCA3_Handler        
    SECTION .text:CODE:REORDER:NOROOT(1)
PCA3_Handler        
    B PCA3_Handler        
    PUBWEAK    EXTI9_4_Handler     
    SECTION .text:CODE:REORDER:NOROOT(1)
EXTI9_4_Handler     
    B EXTI9_4_Handler     
    PUBWEAK    UART0_Handler       
    SECTION .text:CODE:REORDER:NOROOT(1)
UART0_Handler       
    B UART0_Handler       
    PUBWEAK    TWI0_Handler        
    SECTION .text:CODE:REORDER:NOROOT(1)
TWI0_Handler        
    B TWI0_Handler        
    PUBWEAK    SPI0_Handler        
    SECTION .text:CODE:REORDER:NOROOT(1)
SPI0_Handler        
    B SPI0_Handler        
    PUBWEAK    SPI1_LED_Handler    
    SECTION .text:CODE:REORDER:NOROOT(1)
SPI1_LED_Handler    
    B SPI1_LED_Handler    
    PUBWEAK    UART1_Handler       
    SECTION .text:CODE:REORDER:NOROOT(1)
UART1_Handler       
    B UART1_Handler       
    PUBWEAK    UART2_Handler       
    SECTION .text:CODE:REORDER:NOROOT(1)
UART2_Handler       
    B UART2_Handler       
    PUBWEAK    UART3_Handler       
    SECTION .text:CODE:REORDER:NOROOT(1)
UART3_Handler       
    B UART3_Handler       
    PUBWEAK    EXTI15_10_Handler   
    SECTION .text:CODE:REORDER:NOROOT(1)
EXTI15_10_Handler   
    B EXTI15_10_Handler   
    PUBWEAK    TIM0_Handler        
    SECTION .text:CODE:REORDER:NOROOT(1)
TIM0_Handler        
    B TIM0_Handler        
    PUBWEAK    TIM1_Handler        
    SECTION .text:CODE:REORDER:NOROOT(1)
TIM1_Handler        
    B TIM1_Handler        
    PUBWEAK    TIM2_Handler        
    SECTION .text:CODE:REORDER:NOROOT(1)
TIM2_Handler        
    B TIM2_Handler        
    PUBWEAK    TIM3_Handler        
    SECTION .text:CODE:REORDER:NOROOT(1)
TIM3_Handler        
    B TIM3_Handler        
    PUBWEAK    TouchKey_Handler    
    SECTION .text:CODE:REORDER:NOROOT(1)
TouchKey_Handler    
    B TouchKey_Handler    
	
	PUBWEAK Default_Handler
	SECTION .text:CODE:REORDER:NOROOT(1)
Default_Handler
	B Default_Handler
	
	END
/*********************** (C) COPYRIGHT STMicroelectronics *** END OF FILE*****/	
	
	
