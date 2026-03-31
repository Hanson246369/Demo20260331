;/*****************************************************************************/
;/* startup_sh32f9xx_keil.s: Startup file for Sinowealth SH32F9 device series    */
;/*****************************************************************************/
;/* <<< Use Configuration Wizard in Context Menu >>>                          */ 
;/*****************************************************************************/
;/* This file is part of the uVision/ARM development tools.                   */
;/* Copyright (c) 2005-2007 Keil Software. All rights reserved.               */
;/* This software may only be used under the terms of a valid, current,       */
;/* end user licence from KEIL for a compatible version of KEIL software      */
;/* development tools. Nothing else gives you the right to use this software. */
;/*****************************************************************************/

;<e>Run Application in User Mode
USER_MODE_EN      EQU  0
;</e>

;// <h> Stack Configuration
;   <o0>System Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
;   <o1>User Stack Size (in Bytes) <0x000-0xFFFFFFFF:8>
;// </h> 
SystemStack_Size  EQU     0x00000400
UserStack_Size    EQU     0x00000000

		  AREA    STACK, NOINIT, READWRITE, ALIGN=3
System_Stack_Mem  SPACE   SystemStack_Size
system_stack_top
User_Stack_Mem    SPACE   UserStack_Size
usr_stack_top
__initial_sp

;// <h> Heap Configuration
;//   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF>
;// </h>
Heap_Size        EQU     0x00000100

;/*****************************************************************************/
;/*-------- <<< end of configuration section >>> -----------------------------*/
;/*****************************************************************************/

                 AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem         SPACE   Heap_Size
__heap_limit

                PRESERVE8
                THUMB
; Vector Table Mapped to Address 0 at Reset
                         AREA     RESET, DATA, READONLY
                         EXPORT   __Vectors
                         EXPORT   __Vectors_End
                         EXPORT   __Vectors_Size
__Vectors
                         DCD      system_stack_top     ; -16 (000H) Top of Stack
                         DCD      Reset_Handler        ; -15 (004H) Reset Handler
                         DCD      NMI_Handler          ; -14 (008H) Non Maskable Interrupt
                         DCD      HardFault_Handler    ; -13 (00CH) Hard Fault Interrupt
                         DCD      MemManage_Handler    ; -12 (010H) Cortex-M3 Memory Management Interrupt
                         DCD      BusFault_Handler     ; -11 (014H) Cortex-M3 Bus Fault Interrupt
                         DCD      UsageFault_Handler   ; -10 (018H) Cortex-M3 Usage Fault Interrupt
                         DCD      Default_Handler      ;  -9 (01CH) Reserved
                         DCD      Default_Handler      ;  -8 (020H) Reserved
                         DCD      Default_Handler      ;  -7 (024H) Reserved
                         DCD      Default_Handler      ;  -6 (028H) Reserved
                         DCD      SVC_Handler          ;  -5 (02CH) Cortex-M3 SVC Interrupt
                         DCD      DebugMon_Handler     ;  -4 (030H) Cortex-M3 Debug Monitor Interrupt
                         DCD      Default_Handler      ;  -3 (034H) Reserved
                         DCD      PendSV_Handler       ;  -2 (038H) Cortex-M3 Pend SV Interrupt
                         DCD      SysTick_Handler      ;  -1 (03CH) Cortex-M3 System Tick Interrupt
                         DCD      WWDT_Handler         ;   0 (040H) Window WatchDog Interrupt
                         DCD      BOD_Handler          ;   1 (044H) PVD through EXTI Line detection Interrupt
                         DCD      RCC_Handler          ;   2 (048H) RCC global Interrupt
                         DCD      EXTI0_Handler        ;   3 (04CH) EXTI Line0 Interrupt
                         DCD      EXTI1_Handler        ;   4 (050H) EXTI Line1 Interrupt
                         DCD      EXTI2_Handler        ;   5 (054H) EXTI Line2 Interrupt
                         DCD      EXTI3_Handler        ;   6 (058H) EXTI Line3 Interrupt
                         DCD      EXTI4_Handler        ;   7 (05CH) EXTI Line4 Interrupt
                         DCD      DMA_CH0_Handler      ;   8 (060H) DMA Channel0 Interrupt
                         DCD      DMA_CH1_Handler      ;   9 (064H) DMA Channel1 Interrupt
                         DCD      DMA_CH2_7_Handler    ;  10 (068H) DMA Channel2 ~ Channel7 Interrupt
                         DCD      ADC_Handler          ;  11 (06CH) ADC Interrupt
                         DCD      PWM0_Handler         ;  12 (070H) PWM0 Interrupt
                         DCD      PWM1_Handler         ;  13 (074H) PWM1 Interrupt
                         DCD      PWM2_Handler         ;  14 (078H) PWM2 Interrupt
                         DCD      PWM3_Handler         ;  15 (07CH) PWM3 Interrupt
                         DCD      PCA0_Handler         ;  16 (080H) PCA0 Interrupt
                         DCD      PCA1_Handler         ;  17 (084H) PCA1 Interrupt
                         DCD      PCA2_Handler         ;  18 (088H) PCA2 Interrupt
                         DCD      PCA3_Handler         ;  19 (08CH) PCA3 Interrupt
                         DCD      EXTI9_5_Handler      ;  20 (090H) EXTI Line5 ~ Line9 global Interrupt
                         DCD      UART0_Handler        ;  21 (094H) UART0 Interrupt
                         DCD      TWI0_Handler         ;  22 (098H) TWI0 Interrupt
                         DCD      TWI1_Handler         ;  23 (09CH) TWI1 Interrupt
                         DCD      SPI0_Handler         ;  24 (0A0H) SPI0 Interrupt
                         DCD      SPI1_Handler         ;  25 (0A4H) SPI1 Interrupt
                         DCD      UART1_Handler        ;  26 (0A8H) UART1 Interrupt
                         DCD      UART2_Handler        ;  27 (0ACH) UART2 Interrupt
                         DCD      UART3_Handler        ;  28 (0B0H) UART3 Interrupt
                         DCD      UART4_Handler        ;  29 (0B4H) UART4 Interrupt
                         DCD      EXTI15_10_Handler    ;  30 (0B8H) EXTI Line10 ~ Line15 Interrupt
                         DCD      UART5_Handler        ;  31 (0BCH) UART5 Interrupt
                         DCD      TIM5_Handler         ;  32 (0C0H) TIM5 Interrupt
                         DCD      TIM6_Handler         ;  33 (0C4H) TIM6 Interrupt
                         DCD      TIM7_Handler         ;  34 (0C8H) TIM7 Interrupt
                         DCD      TIM8_Handler         ;  35 (0CCH) TIM8 Interrupt
                         DCD      PCA4_Handler         ;  36 (0D0H) PCA4 Interrupt
                         DCD      PCA5_Handler         ;  37 (0D4H) PCA5 Interrupt
                         DCD      PCA6_Handler         ;  38 (0D8H) PCA6 Interrupt
                         DCD      PCA7_Handler         ;  39 (0DCH) PCA7 Interrupt
                         DCD      LED_Handler          ;  40 (0E0H) LED Interrupt
                         DCD      TouchKey_Handler     ;  41 (0E4H) TouchKey Interrupt


__Vectors_End
__Vectors_Size           EQU      __Vectors_End - __Vectors

                         AREA     |.text|, CODE, READONLY
Reset_Handler            PROC
                         EXPORT   Reset_Handler        [WEAK]
                         IMPORT   __main
                         LDR      R0, =SystemInit
                         BLX      R0
               IF  USER_MODE_EN = 1
                         ;switch to user mode
                         LDR      R0, =__initial_sp
                         MSR      PSP, R0                                      
                         MOV      R0,  #3
                         MSR      CONTROL, R0         
               ENDIF                         
                         LDR      R0, =__main
                         BX       R0
                         ENDP    

NMI_Handler              PROC
                         EXPORT   NMI_Handler          [WEAK]
                         B        .
                         ENDP    

HardFault_Handler        PROC
                         EXPORT   HardFault_Handler    [WEAK]
                         B        .
                         ENDP    

MemManage_Handler        PROC
                         EXPORT   MemManage_Handler    [WEAK]
                         B        .
                         ENDP    

BusFault_Handler         PROC
                         EXPORT   BusFault_Handler     [WEAK]
                         B        .
                         ENDP    

UsageFault_Handler       PROC
                         EXPORT   UsageFault_Handler   [WEAK]
                         B        .
                         ENDP    

SVC_Handler              PROC
                         EXPORT   SVC_Handler          [WEAK]
                 IF  USER_MODE_EN = 1
                         ;instruction svc push xPSR,PC,LR,R12,R3,R2,R1,R0
                         TST      LR,   #0x4         ;test return addr bit 2
                         ITE      EQ                 ;if 0
                         MRSEQ    R0,    MSP         ; use main stack
                         MRSNE    R0,    PSP         ; use user stack
                         B        SVC_Call_Proc
                ELSE
                         B        .
                ENDIF
                         ENDP    
                IF  USER_MODE_EN = 1
SVC_Call_Proc            PROC
                         EXPORT   SVC_Call_Proc       [WEAK]
                         BX       LR
                         ENDP
                ENDIF

DebugMon_Handler         PROC
                         EXPORT   DebugMon_Handler     [WEAK]
                         B        .
                         ENDP    

PendSV_Handler           PROC
                         EXPORT   PendSV_Handler       [WEAK]
                         B        .
                         ENDP    

SysTick_Handler          PROC
                         EXPORT   SysTick_Handler      [WEAK]
                         B        .
                         ENDP    

Default_Handler          PROC
                         EXPORT   WWDT_Handler         [WEAK]
                         EXPORT   BOD_Handler          [WEAK]
                         EXPORT   RCC_Handler          [WEAK]
                         EXPORT   EXTI0_Handler        [WEAK]
                         EXPORT   EXTI1_Handler        [WEAK]
                         EXPORT   EXTI2_Handler        [WEAK]
                         EXPORT   EXTI3_Handler        [WEAK]
                         EXPORT   EXTI4_Handler        [WEAK]
                         EXPORT   DMA_CH0_Handler      [WEAK]
                         EXPORT   DMA_CH1_Handler      [WEAK]
                         EXPORT   DMA_CH2_7_Handler    [WEAK]
                         EXPORT   ADC_Handler          [WEAK]
                         EXPORT   PWM0_Handler         [WEAK]
                         EXPORT   PWM1_Handler         [WEAK]
                         EXPORT   PWM2_Handler         [WEAK]
                         EXPORT   PWM3_Handler         [WEAK]
                         EXPORT   PCA0_Handler         [WEAK]
                         EXPORT   PCA1_Handler         [WEAK]
                         EXPORT   PCA2_Handler         [WEAK]
                         EXPORT   PCA3_Handler         [WEAK]
                         EXPORT   EXTI9_5_Handler      [WEAK]
                         EXPORT   UART0_Handler        [WEAK]
                         EXPORT   TWI0_Handler         [WEAK]
                         EXPORT   TWI1_Handler         [WEAK]
                         EXPORT   SPI0_Handler         [WEAK]
                         EXPORT   SPI1_Handler         [WEAK]
                         EXPORT   UART1_Handler        [WEAK]
                         EXPORT   UART2_Handler        [WEAK]
                         EXPORT   UART3_Handler        [WEAK]
                         EXPORT   UART4_Handler        [WEAK]
                         EXPORT   EXTI15_10_Handler    [WEAK]
                         EXPORT   UART5_Handler        [WEAK]
                         EXPORT   TIM5_Handler         [WEAK]
                         EXPORT   TIM6_Handler         [WEAK]
                         EXPORT   TIM7_Handler         [WEAK]
                         EXPORT   TIM8_Handler         [WEAK]
                         EXPORT   PCA4_Handler         [WEAK]
                         EXPORT   PCA5_Handler         [WEAK]
                         EXPORT   PCA6_Handler         [WEAK]
                         EXPORT   PCA7_Handler         [WEAK]
                         EXPORT   LED_Handler          [WEAK]
                         EXPORT   TouchKey_Handler     [WEAK]
WWDT_Handler
BOD_Handler
RCC_Handler
EXTI0_Handler
EXTI1_Handler
EXTI2_Handler
EXTI3_Handler
EXTI4_Handler
DMA_CH0_Handler
DMA_CH1_Handler
DMA_CH2_7_Handler
ADC_Handler
PWM0_Handler
PWM1_Handler
PWM2_Handler
PWM3_Handler
PCA0_Handler
PCA1_Handler
PCA2_Handler
PCA3_Handler
EXTI9_5_Handler
UART0_Handler
TWI0_Handler
TWI1_Handler
SPI0_Handler
SPI1_Handler
UART1_Handler
UART2_Handler
UART3_Handler
UART4_Handler
EXTI15_10_Handler
UART5_Handler
TIM5_Handler
TIM6_Handler
TIM7_Handler
TIM8_Handler
PCA4_Handler
PCA5_Handler
PCA6_Handler
PCA7_Handler
LED_Handler
TouchKey_Handler
                         B        .
                         ENDP    

                         
SystemInit  PROC
                EXPORT  SystemInit  [WEAK]
                BX LR      
                ENDP
                    
                ALIGN


                ALIGN
; User Initial Stack & Heap

                IF      :DEF:__MICROLIB
                
                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit
                
                ELSE
                
                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =__initial_sp;
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = User_Stack_Mem
                BX      LR

                ALIGN

                ENDIF


                END
