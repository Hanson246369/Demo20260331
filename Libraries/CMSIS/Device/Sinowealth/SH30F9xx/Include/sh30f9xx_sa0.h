/**
  ******************************************************************************
  * @file    sh30f9xx_sa0.h
  * @version V1.0
  * @date    2021-10-25
  * @brief   CMSIS Cortex-M3 Device Peripheral Access Layer Header File.
  *          This file contains all the peripheral register's definitions, bits
  *          definitions and memory mapping for Sinowealth M3 based devices.
  ******************************************************************************
  * @attention
  *
  * SINOWEALTH IS SUPPLYING THIS SOFTWARE FOR USE EXCLUSIVELY ON SINOWEALTH'S 
  * MICROCONTROLLER PRODUCTS. IT IS PROTECTED UNDER APPLICABLE COPYRIGHT LAWS. 
  * THIS SOFTWARE IS FOR GUIDANCE IN ORDER TO SAVE TIME. AS A RESULT, SINOWEALTH 
  * SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES 
  * WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH FIRMWARE AND/OR
  * THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN IN 
  * CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2017 Sinowealth</center></h2>
  *
  *
  ******************************************************************************
*/

#ifndef __SH30F9XX_SA0_H__
#define __SH30F9XX_SA0_H__

#ifdef __cplusplus
extern "C" {
#endif




#define __CM0PLUS_REV            0x0001   /*!< Core revision r0p1                               */
#define __MPU_PRESENT             0       /*!< SH30F9XX_SA0 provides NO MPU                     */
#define __VTOR_PRESENT            1       /*!< SH30F9XX_SA0 provides VTOR                       */
#define __NVIC_PRIO_BITS          2       /*!< SH30F9XX_SA0 uses 2 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0       /*!< Set to 1 if different SysTick Config is used     */

typedef enum
{
/******  Cortex-M0+ Processor Exceptions Numbers ***************************************************************/
  NMI_IRQn                    = -14,    /*!< Non Maskable Interrupt                                            */
  HardFault_IRQn              = -13,    /*!< Hard Fault Interrupt                                              */
  SVC_IRQn                    = -5,     /*!< Cortex-M0+ SV Call Interrupt                                      */
  PendSV_IRQn                 = -2,     /*!< Cortex-M0+ Pend SV Interrupt                                      */
  SysTick_IRQn                = -1,     /*!< Cortex-M0+ System Tick Interrupt                                  */
/******  SH30F9XX_SA0 specific Interrupt Numbers ***************************************************************/
  WWDT_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                         */
  BOD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt                         */
  RCC_IRQn                    = 2,      /*!< RCC global Interrupt                                              */
  EXTI0_IRQn                  = 3,      /*!< EXTI Line0 Interrupt                                              */
  EXTI1_IRQn                  = 4,      /*!< EXTI Line1 Interrupt                                              */
  EXTI2_IRQn                  = 5,      /*!< EXTI Line2 Interrupt                                              */
  EXTI3_IRQn                  = 6,      /*!< EXTI Line3 Interrupt                                              */
  DMA_CH0_1_IRQn              = 7,      /*!< DMA Channel0 ~ Channel1 Interrupt                                 */
  DMA_CH2_3_IRQn              = 8,      /*!< DMA Channel2 ~ Channel3 Interrupt                                 */
  ADC_IRQn                    = 9,      /*!< ADC Interrupt                                                     */
  PWM0_IRQn                   = 10,     /*!< PWM0 Interrupt                                                    */
  PWM1_IRQn                   = 11,     /*!< PWM1 Interrupt                                                    */
  PWM2_IRQn                   = 12,     /*!< PWM2 Interrupt                                                    */
  PWM3_IRQn                   = 13,     /*!< PWM3 Interrupt                                                    */
  PCA0_IRQn                   = 14,     /*!< PCA0 Interrupt                                                    */
  PCA1_IRQn                   = 15,     /*!< PCA1 Interrupt                                                    */
  PCA2_IRQn                   = 16,     /*!< PCA2 Interrupt                                                    */
  PCA3_IRQn                   = 17,     /*!< PCA3 Interrupt                                                    */
  EXTI9_4_IRQn                = 18,     /*!< EXTI Line4 ~ Line9 global Interrupt                               */
  UART0_IRQn                  = 19,     /*!< UART0 Interrupt                                                   */
  TWI0_IRQn                   = 20,     /*!< TWI0 Interrupt                                                    */
#if defined(SH30F9X20) || defined(SH30F9X71)
  SPI0_IRQn                   = 21,     /*!< SPI0 Interrupt                                                    */
  SPI1_LED_IRQn               = 22,     /*!< SPI1&LED Interrupt                                                */
#elif defined(SH30F9X21)
  SPI0_IRQn                   = 21,     /*!< SPI0 Interrupt                                                    */
  SPI1_IRQn                   = 22,     /*!< SPI1 Interrupt                                                    */ 
#else
  SPI0_HLV_IRQn               = 21,     /*!< SPI0&HLV Interrupt                                                */
  SPI1_LED_IRQn               = 22,     /*!< SPI1&LED Interrupt                                                */
#endif
  UART1_IRQn                  = 23,     /*!< UART1 Interrupt                                                   */
  UART2_IRQn                  = 24,     /*!< UART2 Interrupt                                                   */
  UART3_IRQn                  = 25,     /*!< UART3 Interrupt                                                   */
  EXTI15_10_IRQn              = 26,     /*!< EXTI Line10 ~ Line15 Interrupt                                    */
  TIM0_IRQn                   = 27,     /*!< TIM0 Interrupt                                                    */
  TIM1_IRQn                   = 28,     /*!< TIM1 Interrupt                                                    */
  TIM2_IRQn                   = 29,     /*!< TIM2 Interrupt                                                    */
  TIM3_IRQn                   = 30,     /*!< TIM3 Interrupt                                                    */
#if defined(SH30F9X71)
  TouchKey_IRQn               = 31,     /*!< TouchKey Interrupt                                                */
#endif
} IRQn_Type;

/* Includes ****************************************************************************************************/
#include "core_cm0plus.h"
#include <stdint.h>




/**
*@brief FLASH_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  LATENCY   : 2;  /*!< [b1~b0]*/
            __IO  uint32_t  rev0      : 6;  /*!< [b7~b2]*/
            __IO  uint32_t  PRFTEN    : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  rev1      : 2;  /*!< [b10~b9]*/
            __IO  uint32_t  CRST      : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  rev2      : 4;  /*!< [b15~b12]*/
            __O   uint32_t  LOCK      :16;  /*!< [b31~b16]*/
        }BIT;
    }ACR;                               /*!< 0000H */
    __O  uint32_t  MKYR;                                    /*!< 0004H */
    __O  uint32_t  E2KYR;                                   /*!< 0008H */
    union {
        __IO  uint32_t  V32;                                /*!< 000CH */
        struct {
            __I   uint32_t  EOP       : 1;  /*!< [b0~b0]*/
            __I   uint32_t  OPERR     : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b2~b2]*/
            __I   uint32_t  FLSERR    : 1;  /*!< [b3~b3]*/
            __I   uint32_t  WRPRTERR  : 1;  /*!< [b4~b4]*/
            __I   uint32_t  PGPERR    : 1;  /*!< [b5~b5]*/
            __I   uint32_t  PGWERR    : 1;  /*!< [b6~b6]*/
            __I   uint32_t  STAERR    : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  rev1      : 7;  /*!< [b14~b8]*/
            __I   uint32_t  BSY       : 1;  /*!< [b15~b15]*/
            __O   uint32_t  EOPC      : 1;  /*!< [b16~b16]*/
            __O   uint32_t  OPERRC    : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  rev2      : 1;  /*!< [b18~b18]*/
            __O   uint32_t  FLSERRC   : 1;  /*!< [b19~b19]*/
            __O   uint32_t  WRPRTERRC : 1;  /*!< [b20~b20]*/
            __O   uint32_t  PGPERRC   : 1;  /*!< [b21~b21]*/
            __O   uint32_t  PGWERRC   : 1;  /*!< [b22~b22]*/
            __O   uint32_t  STAERRC   : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  rev3      : 8;  /*!< [b31~b24]*/
        }BIT;
    }SR;                               /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
            __IO  uint32_t  rev0      : 8;  /*!< [b7~b0]*/
            __IO  uint32_t  STRT      : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  rev1      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  PSIZE     : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  rev2      : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  INFLCK    : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  rev3      : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  E2LCK     : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  MNLCK     : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  CMD       :16;  /*!< [b31~b16]*/
        }BIT;
    }CR;                               /*!< 0010H */
    __IO uint32_t  CR1;                                     /*!< 0014H */
    union {
        __I   uint32_t  V32;                                /*!< 0018H */
        struct {
    __I  uint32_t  OPT0:8;                                  /*!< 0018H */
    __I  uint32_t  OPT1:8;                                  /*!< 0019H */
    __I  uint32_t  OPT2:8;                                  /*!< 001AH */
    __I  uint32_t  OPT3:8;                                  /*!< 001BH */
        }BIT;
    }OPR;                              /*!< 0018H */
    __I  uint32_t  RPR;                                     /*!< 001CH */
    __I  uint32_t  WRPR;                                    /*!< 0020H */
    __IO uint32_t  Reserved0[1];                            /*!< 0024H */
    __IO uint32_t  CNTR;                                    /*!< 0028H */
    __IO uint32_t  UPCNTR;                                  /*!< 002CH */
    __IO uint32_t  CNTCR;                                   /*!< 0030H */
    __O  uint32_t  IKYR;                                    /*!< 0034H */
    __IO uint32_t  Reserved1[50];                           /*!< 0038H */
    __IO uint32_t  MEMRMP;                                  /*!< 0100H */
    __IO uint32_t  Reserved2[63];                           /*!< 0104H */
    union {
        __I   uint32_t  V32;                                /*!< 0200H */
        struct {
    __I  uint32_t  OPT0:8;                                  /*!< 0200H */
    __I  uint32_t  OPT1:8;                                  /*!< 0201H */
    __I  uint32_t  OPT2:8;                                  /*!< 0202H */
    __I  uint32_t  OPT3:8;                                  /*!< 0203H */
        }BIT;
    }OPR_CUST1;                              /*!< 0200H */
    union {
        __I   uint32_t  V32;                                /*!< 0204H */
        struct {
    __I  uint32_t  OPT0:8;                                  /*!< 0204H */
    __I  uint32_t  OPT1:8;                                  /*!< 0205H */
    __I  uint32_t  OPT2:8;                                  /*!< 0206H */
    __I  uint32_t  OPT3:8;                                  /*!< 0207H */
        }BIT;
    }OPR_DESI0;                              /*!< 0204H */
    union {
        __I   uint32_t  V32;                                /*!< 0208H */
        struct {
    __I  uint32_t  OPT0:8;                                  /*!< 0208H */
    __I  uint32_t  OPT1:8;                                  /*!< 0209H */
    __I  uint32_t  OPT2:8;                                  /*!< 020AH */
    __I  uint32_t  OPT3:8;                                  /*!< 020BH */
        }BIT;
    }OPR_DESI1;                              /*!< 0208H */
    union {
        __I   uint32_t  V32;                                /*!< 020CH */
        struct {
    __I  uint32_t  OPT0:8;                                  /*!< 020CH */
    __I  uint32_t  OPT1:8;                                  /*!< 020DH */
    __I  uint32_t  OPT2:8;                                  /*!< 020EH */
    __I  uint32_t  OPT3:8;                                  /*!< 020FH */
        }BIT;
    }OPR_DESI2;                              /*!< 020CH */
    union {
        __I   uint32_t  V32;                                /*!< 0210H */
        struct {
    __I  uint32_t  OPT0:8;                                  /*!< 0210H */
    __I  uint32_t  OPT1:8;                                  /*!< 0211H */
    __I  uint32_t  OPT2:8;                                  /*!< 0212H */
    __I  uint32_t  OPT3:8;                                  /*!< 0213H */
        }BIT;
    }OPR_DESI3;                              /*!< 0210H */
}FLASH_TypeDef;


/**
*@brief RCC_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  SW        : 3;  /*!< [b2~b0]*/
            __I   uint32_t  SWS       : 3;  /*!< [b5~b3]*/
            __IO  uint32_t  CSMON     : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  PLLON     : 1;  /*!< [b7~b7]*/
            __I   uint32_t  PLLRDY    : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  HSEON     : 1;  /*!< [b9~b9]*/
            __I   uint32_t  HSERDY    : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  LSEON     : 1;  /*!< [b11~b11]*/
            __I   uint32_t  LSERDY    : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  HSION     : 1;  /*!< [b13~b13]*/
            __I   uint32_t  HSIRDY    : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  LSION     : 1;  /*!< [b15~b15]*/
            __I   uint32_t  LSIRDY    : 1;  /*!< [b16~b16]*/
            __IO  uint32_t  ESTCK     : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  rev0      :14;  /*!< [b31~b18]*/
        }BIT;
    }CR;                               /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __IO  uint32_t  HPRE      : 3;  /*!< [b2~b0]*/
            __IO  uint32_t  PPRE0     : 3;  /*!< [b5~b3]*/
            __IO  uint32_t  PPRE1     : 3;  /*!< [b8~b6]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  PLLK      : 3;  /*!< [b12~b10]*/
            __IO  uint32_t  PLLF      : 5;  /*!< [b17~b13]*/
            __IO  uint32_t  rev1      : 1;  /*!< [b18~b18]*/
            __IO  uint32_t  PLLSRC    : 1;  /*!< [b19~b19]*/
            __IO  uint32_t  PLLXTPRE  : 2;  /*!< [b21~b20]*/
            __IO  uint32_t  CRY32SPDUP: 1;  /*!< [b22~b22]*/
            __IO  uint32_t  CRY32NOISEEN: 1;  /*!< [b23~b23]*/
            __IO  uint32_t  HSIENREC  : 1;  /*!< [b24~b24]*/
            __IO  uint32_t  HSESEL    : 2;  /*!< [b26~b25]*/
            __IO  uint32_t  rev2      : 5;  /*!< [b31~b27]*/
        }BIT;
    }CFGR;                               /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
            __IO  uint32_t  rev0      : 2;  /*!< [b1~b0]*/
            __IO  uint32_t  LSERDYIE  : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  HSERDYIE  : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  PLLRDYIE  : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  rev1      :27;  /*!< [b31~b5]*/
        }BIT;
    }CIENR;                               /*!< 0008H */
    union {
        __I   uint32_t  V32;                                /*!< 000CH */
        struct {
            __IO  uint32_t  rev0      : 2;  /*!< [b1~b0]*/
            __I   uint32_t  LSERDYIF  : 1;  /*!< [b2~b2]*/
            __I   uint32_t  HSERDYIF  : 1;  /*!< [b3~b3]*/
            __I   uint32_t  PLLRDYIF  : 1;  /*!< [b4~b4]*/
            __I   uint32_t  LSECSMF   : 1;  /*!< [b5~b5]*/
            __I   uint32_t  HSECSMF   : 1;  /*!< [b6~b6]*/
            __I   uint32_t  PLLCSMF   : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  rev1      :24;  /*!< [b31~b8]*/
        }BIT;
    }CISTR;                               /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
            __IO  uint32_t  rev0      : 2;  /*!< [b1~b0]*/
            __O   uint32_t  LSERDYC   : 1;  /*!< [b2~b2]*/
            __O   uint32_t  HSERDYC   : 1;  /*!< [b3~b3]*/
            __O   uint32_t  PLLRDYC   : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  rev1      : 2;  /*!< [b6~b5]*/
            __O   uint32_t  CSMC      : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  rev2      :24;  /*!< [b31~b8]*/
        }BIT;
    }CICLR;                               /*!< 0010H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
            __IO  uint32_t  rev0      : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  SYSCFGRST : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  CRCRST    : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  DMARST    : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  rev1      :28;  /*!< [b31~b4]*/
        }BIT;
    }AHBRSTR;                               /*!< 0014H */
    union {
        __IO  uint32_t  V32;                                /*!< 0018H */
        struct {
            __IO  uint32_t  UART0RST  : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  UART1RST  : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  UART2RST  : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  UART3RST  : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  SPI0RST   : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  SPI1RST   : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  TWI0RST   : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  LEDRST    : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  LCDRST    : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  TKRST     : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  HLVRST    : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  rev0      :21;  /*!< [b31~b11]*/
        }BIT;
    }APB1RSTR;                               /*!< 0018H */
    union {
        __IO  uint32_t  V32;                                /*!< 001CH */
        struct {
            __IO  uint32_t  TIM0RST   : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TIM1RST   : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  TIM2RST   : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  TIM3RST   : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  PWM0RST   : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  PWM1RST   : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  PWM2RST   : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  PWM3RST   : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  PCA0RST   : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  PCA1RST   : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  PCA2RST   : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  PCA3RST   : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  EXTIRST   : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  WWDTRST   : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  ADCRST    : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  rev0      :17;  /*!< [b31~b15]*/
        }BIT;
    }APB0RSTR;                               /*!< 001CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0020H */
        struct {
            __IO  uint32_t  rev0      : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  SYSCFGEN  : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  CRCEN     : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  DMAEN     : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  rev1      :28;  /*!< [b31~b4]*/
        }BIT;
    }AHBENR;                               /*!< 0020H */
    union {
        __IO  uint32_t  V32;                                /*!< 0024H */
        struct {
            __IO  uint32_t  UART0EN   : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  UART1EN   : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  UART2EN   : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  UART3EN   : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  SPI0EN    : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  SPI1EN    : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  TWI0EN    : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  LEDEN     : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  LCDEN     : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  TKEN      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  HLVEN     : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  rev0      :21;  /*!< [b31~b11]*/
        }BIT;
    }APB1ENR;                               /*!< 0024H */
    union {
        __IO  uint32_t  V32;                                /*!< 0028H */
        struct {
            __IO  uint32_t  TIM0EN    : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TIM1EN    : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  TIM2EN    : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  TIM3EN    : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  PWM0EN    : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  PWM1EN    : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  PWM2EN    : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  PWM3EN    : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  PCA0EN    : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  PCA1EN    : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  PCA2EN    : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  PCA3EN    : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  EXTIEN    : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  WWDTEN    : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  ADCEN     : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  rev0      :17;  /*!< [b31~b15]*/
        }BIT;
    }APB0ENR;                               /*!< 0028H */
    union {
        __I   uint32_t  V32;                                /*!< 002CH */
        struct {
            __I   uint32_t  PINRSTF   : 1;  /*!< [b0~b0]*/
            __I   uint32_t  LVRSTF    : 1;  /*!< [b1~b1]*/
            __I   uint32_t  PORSTF    : 1;  /*!< [b2~b2]*/
            __I   uint32_t  SWRSTF    : 1;  /*!< [b3~b3]*/
            __I   uint32_t  IWDTRSTF  : 1;  /*!< [b4~b4]*/
            __I   uint32_t  WWDTRSTF  : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  rev0      :26;  /*!< [b31~b6]*/
        }BIT;
    }RSTSTR;                               /*!< 002CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0030H */
        struct {
            __O   uint32_t  PINRSTFC  : 1;  /*!< [b0~b0]*/
            __O   uint32_t  LVRSTFC   : 1;  /*!< [b1~b1]*/
            __O   uint32_t  PORSTFC   : 1;  /*!< [b2~b2]*/
            __O   uint32_t  SWRSTFC   : 1;  /*!< [b3~b3]*/
            __O   uint32_t  IWDTRSTFC : 1;  /*!< [b4~b4]*/
            __O   uint32_t  WWDTRSTFC : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  rev0      :26;  /*!< [b31~b6]*/
        }BIT;
    }RSTCLR;                               /*!< 0030H */
    __IO uint32_t  RCCLOCK;                                 /*!< 0034H */
    __IO uint32_t  HSERFB;                                  /*!< 0038H */
}RCC_TypeDef;


/**
*@brief IWDT_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  IWDTRLR   :12;  /*!< [b11~b0]*/
            __IO  uint32_t  IWDTPR    : 3;  /*!< [b14~b12]*/
            __IO  uint32_t  IWDTPD    : 1;  /*!< [b15~b15]*/
            __O   uint32_t  LOCK      :16;  /*!< [b31~b16]*/
        }BIT;
    }CR;                               /*!< 0000H */
    __O  uint32_t  CLR;                                     /*!< 0004H */
}IWDT_TypeDef;


/**
*@brief WWDT_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  WWDTRLR   : 8;  /*!< [b7~b0]*/
            __IO  uint32_t  WWDTPR    : 3;  /*!< [b10~b8]*/
            __IO  uint32_t  rev0      : 3;  /*!< [b13~b11]*/
            __IO  uint32_t  WWDTIE    : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  WWDTON    : 1;  /*!< [b15~b15]*/
            __O   uint32_t  LOCK      :16;  /*!< [b31~b16]*/
        }BIT;
    }CR;                               /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __I   uint32_t  TCNT      : 8;  /*!< [b7~b0]*/
            __IO  uint32_t  rev0      : 7;  /*!< [b14~b8]*/
            __IO  uint32_t  WWDTIF    : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  rev1      :16;  /*!< [b31~b16]*/
        }BIT;
    }SR;                               /*!< 0004H */
    __O  uint32_t  CLR;                                     /*!< 0008H */
    union {
        __IO  uint32_t  V32;                                /*!< 000CH */
        struct {
    __IO uint32_t  WWDTWTR:8;                               /*!< 000CH */
    __IO uint32_t  rev0:8;                                  /*!< 000DH */
    __O  uint32_t  LOCK:16;                                 /*!< 000EH */
        }BIT;
    }WTR;                              /*!< 000CH */
}WWDT_TypeDef;


/**
*@brief CRC_registers
*/
typedef struct
{
    __IO uint32_t  DR;                                      /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __O   uint32_t  RELOAD    : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  rev0      : 7;  /*!< [b7~b1]*/
            __IO  uint32_t  MODE      : 2;  /*!< [b9~b8]*/
            __IO  uint32_t  COMPLW    : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  RBITW     : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  RBYTEW    : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  COMPLR    : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  RBITR     : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  RBYTER    : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  rev1      :16;  /*!< [b31~b16]*/
        }BIT;
    }CR;                               /*!< 0004H */
    __IO uint32_t  INIT;                                    /*!< 0008H */
}CRC_TypeDef;


/**
*@brief RAMBIST_registers
*/
typedef struct
{
    __IO uint32_t  ADDR;                                    /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __IO  uint32_t  BLKSZ     : 3;  /*!< [b2~b0]*/
            __IO  uint32_t  rev0      :12;  /*!< [b14~b3]*/
            __IO  uint32_t  SEL       : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  rev1      :16;  /*!< [b31~b16]*/
        }BIT;
    }CFG;                               /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
            __O   uint32_t  RUN       :16;  /*!< [b15~b0]*/
            __IO  uint32_t  MOD       : 1;  /*!< [b16~b16]*/
            __I   uint32_t  BSY       : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  ERR       : 1;  /*!< [b18~b18]*/
            __IO  uint32_t  rev0      :13;  /*!< [b31~b19]*/
        }BIT;
    }CSR;                               /*!< 0008H */
}RAMBIST_TypeDef;


/**
*@brief GPIO_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  MODER0    : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  MODER1    : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  MODER2    : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  MODER3    : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  MODER4    : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  MODER5    : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  MODER6    : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  MODER7    : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  MODER8    : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  MODER9    : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  MODER10   : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  MODER11   : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  MODER12   : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  MODER13   : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  MODER14   : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  MODER15   : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  rev0      :16;  /*!< [b31~b16]*/
        }BIT;
    }MODER;                               /*!< 0000H */
    __I  uint32_t  IDR;                                     /*!< 0004H */
    __IO uint32_t  ODR;                                     /*!< 0008H */
    union {
        __IO  uint32_t  V32;                                /*!< 000CH */
        struct {
    __O  uint32_t  BS:16;                                   /*!< 000CH */
    __O  uint32_t  BR:16;                                   /*!< 000EH */
        }BIT;
    }BSRR;                              /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
            __IO  uint32_t  LCK0      : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  LCK1      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  LCK2      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  LCK3      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  LCK4      : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  LCK5      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  LCK6      : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  LCK7      : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  LCK8      : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  LCK9      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  LCK10     : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  LCK11     : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  LCK12     : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  LCK13     : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  LCK14     : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  LCK15     : 1;  /*!< [b15~b15]*/
            __O   uint32_t  LOCK      :16;  /*!< [b31~b16]*/
        }BIT;
    }LCKR;                               /*!< 0010H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
            __IO  uint32_t  IE0       : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  IE1       : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  IE2       : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  IE3       : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  IE4       : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  IE5       : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  IE6       : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  IE7       : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  IE8       : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  IE9       : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  IE10      : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  IE11      : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  IE12      : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  IE13      : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  IE14      : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  IE15      : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  rev0      :16;  /*!< [b31~b16]*/
        }BIT;
    }IE;                               /*!< 0014H */
    union {
        __IO  uint32_t  V32;                                /*!< 0018H */
        struct {
            __IO  uint32_t  rev0      : 4;  /*!< [b3~b0]*/
            __IO  uint32_t  OT4       : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  OT5       : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  OT6       : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  OT7       : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  OT8       : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  OT9       : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  OT10      : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  rev1      : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  OT12      : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  OT13      : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  OT14      : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  OT15      : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  rev2      :16;  /*!< [b31~b16]*/
        }BIT;
    }OTYPER;                               /*!< 0018H */
    union {
        __IO  uint32_t  V32;                                /*!< 001CH */
        struct {
            __IO  uint32_t  rev0      : 4;  /*!< [b3~b0]*/
            __IO  uint32_t  ODRVR_SINK2: 1;  /*!< [b4~b4]*/
            __IO  uint32_t  rev1      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  ODRVR_SINK3: 1;  /*!< [b6~b6]*/
            __IO  uint32_t  rev2      : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  ODRVR_SINK4: 1;  /*!< [b8~b8]*/
            __IO  uint32_t  rev3      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  ODRVR_SINK5: 1;  /*!< [b10~b10]*/
            __IO  uint32_t  rev4      : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  ODRVR_SINK6: 1;  /*!< [b12~b12]*/
            __IO  uint32_t  rev5      : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  ODRVR_SINK7: 1;  /*!< [b14~b14]*/
            __IO  uint32_t  rev6      : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  ODRVR_SINK8: 1;  /*!< [b16~b16]*/
            __IO  uint32_t  rev7      : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  ODRVR_SINK9: 1;  /*!< [b18~b18]*/
            __IO  uint32_t  rev8      :13;  /*!< [b31~b19]*/
        }BIT;
    }ODRVR;                               /*!< 001CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0020H */
        struct {
            __IO  uint32_t  PHDR0     : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  PHDR1     : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  rev1      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  PHDR2     : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  rev2      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  PHDR3     : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  rev3      : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  PHDR4     : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  rev4      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  PHDR5     : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  rev5      : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  PHDR6     : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  rev6      : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  PHDR7     : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  rev7      : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  PHDR8     : 1;  /*!< [b16~b16]*/
            __IO  uint32_t  rev8      : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  PHDR9     : 1;  /*!< [b18~b18]*/
            __IO  uint32_t  rev9      : 1;  /*!< [b19~b19]*/
            __IO  uint32_t  PHDR10    : 1;  /*!< [b20~b20]*/
            __IO  uint32_t  rev10     : 1;  /*!< [b21~b21]*/
            __IO  uint32_t  PHDR11    : 1;  /*!< [b22~b22]*/
            __IO  uint32_t  rev11     : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  PHDR12    : 1;  /*!< [b24~b24]*/
            __IO  uint32_t  rev12     : 1;  /*!< [b25~b25]*/
            __IO  uint32_t  PHDR13    : 1;  /*!< [b26~b26]*/
            __IO  uint32_t  rev13     : 1;  /*!< [b27~b27]*/
            __IO  uint32_t  PHDR14    : 1;  /*!< [b28~b28]*/
            __IO  uint32_t  rev14     : 1;  /*!< [b29~b29]*/
            __IO  uint32_t  PHDR15    : 1;  /*!< [b30~b30]*/
            __IO  uint32_t  rev15     : 1;  /*!< [b31~b31]*/
        }BIT;
    }PUPDR;                               /*!< 0020H */
    union {
        __IO  uint32_t  V32;                                /*!< 0024H */
        struct {
            __IO  uint32_t  TTLEN0    : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TTLEN1    : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  TTLEN2    : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  TTLEN3    : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  TTLEN4    : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  TTLEN5    : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  TTLEN6    : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  TTLEN7    : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  TTLEN8    : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  TTLEN9    : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  TTLEN10   : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  TTLEN11   : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  TTLEN12   : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  TTLEN13   : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  TTLEN14   : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  TTLEN15   : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  rev0      :16;  /*!< [b31~b16]*/
        }BIT;
    }TTLEN;                               /*!< 0024H */
    union {
        __IO  uint32_t  V32;                                /*!< 0028H */
        struct {
            __IO  uint32_t  AFR0      : 4;  /*!< [b3~b0]*/
            __IO  uint32_t  AFR1      : 4;  /*!< [b7~b4]*/
            __IO  uint32_t  AFR2      : 4;  /*!< [b11~b8]*/
            __IO  uint32_t  AFR3      : 4;  /*!< [b15~b12]*/
            __IO  uint32_t  AFR4      : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  AFR5      : 4;  /*!< [b23~b20]*/
            __IO  uint32_t  AFR6      : 4;  /*!< [b27~b24]*/
            __IO  uint32_t  AFR7      : 4;  /*!< [b31~b28]*/
        }BIT;
    }AFRL;                               /*!< 0028H */
    union {
        __IO  uint32_t  V32;                                /*!< 002CH */
        struct {
            __IO  uint32_t  AFR8      : 4;  /*!< [b3~b0]*/
            __IO  uint32_t  AFR9      : 4;  /*!< [b7~b4]*/
            __IO  uint32_t  AFR10     : 4;  /*!< [b11~b8]*/
            __IO  uint32_t  AFR11     : 4;  /*!< [b15~b12]*/
            __IO  uint32_t  AFR12     : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  AFR13     : 4;  /*!< [b23~b20]*/
            __IO  uint32_t  AFR14     : 4;  /*!< [b27~b24]*/
            __IO  uint32_t  AFR15     : 4;  /*!< [b31~b28]*/
        }BIT;
    }AFRH;                               /*!< 002CH */
}GPIO_TypeDef;


/**
*@brief SYSCFG_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  VBOD      : 4;  /*!< [b3~b0]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  BODMD     : 2;  /*!< [b6~b5]*/
            __IO  uint32_t  BODIE     : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  BODEN     : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  VLVR      : 2;  /*!< [b10~b9]*/
            __IO  uint32_t  LVREN     : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  rev1      :20;  /*!< [b31~b12]*/
        }BIT;
    }PWRCR;                               /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __IO  uint32_t  BODIF     : 1;  /*!< [b0~b0]*/
            __I   uint32_t  BODF      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  rev0      :30;  /*!< [b31~b2]*/
        }BIT;
    }PWRSR;                               /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
            __IO  uint32_t  OSCCFG    : 2;  /*!< [b1~b0]*/
            __IO  uint32_t  rev0      : 3;  /*!< [b4~b2]*/
            __IO  uint32_t  SWJCFG    : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  IEN_EXTI0 : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  IEN_BOD   : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  IEN_CSM   : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  rev1      : 7;  /*!< [b15~b9]*/
            __O   uint32_t  LOCK      :16;  /*!< [b31~b16]*/
        }BIT;
    }SAFR;                               /*!< 0008H */
    union {
        __IO  uint32_t  V32;                                /*!< 000CH */
        struct {
    __IO uint32_t  SRAMLCK:16;                              /*!< 000CH */
    __O  uint32_t  LOCK:16;                                 /*!< 000EH */
        }BIT;
    }SRAMLOCK;                              /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
            __IO  uint32_t  DBG_SLEEP : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  DBG_STOP  : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  DBG_LCD   : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  DBG_LED   : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  DBG_DMA   : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  DBG_IWDT  : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  DBG_WWDT  : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  DBG_PCA   : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  DBG_TIM   : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  DBG_PWM   : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  DBG_UART  : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  DBG_SPI   : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  DBG_TWI   : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  rev1      : 2;  /*!< [b15~b14]*/
            __O   uint32_t  LOCK      :16;  /*!< [b31~b16]*/
        }BIT;
    }DBGCR;                               /*!< 0010H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
            __IO  uint32_t  BUS       : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  rev0      :15;  /*!< [b15~b1]*/
            __O   uint32_t  LOCK      :16;  /*!< [b31~b16]*/
        }BIT;
    }GPIOBCR;                               /*!< 0014H */
    __IO uint32_t  Reserved0[26];                           /*!< 0018H */
    union {
        __IO  uint32_t  V32;                                /*!< 0080H */
        struct {
            __IO  uint32_t  IDC       : 2;  /*!< [b1~b0]*/
            __IO  uint32_t  IDCEN     : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  rev0      :13;  /*!< [b15~b3]*/
            __O   uint32_t  LOCK      :16;  /*!< [b31~b16]*/
        }BIT;
    }HLDOCR;                               /*!< 0080H */
}SYSCFG_TypeDef;


/**
*@brief EXTI_registers
*/
typedef struct
{
    __IO uint32_t  IMR;                                     /*!< 0000H */
    __IO uint32_t  EMR;                                     /*!< 0004H */
    __IO uint32_t  TMSR;                                    /*!< 0008H */
    __IO uint32_t  RTSR;                                    /*!< 000CH */
    __IO uint32_t  FTSR;                                    /*!< 0010H */
    __O  uint32_t  SWIER;                                   /*!< 0014H */
    union {
        __IO  uint32_t  V32;                                /*!< 0018H */
        struct {
    __I  uint32_t  PR:16;                                   /*!< 0018H */
    __O  uint32_t  PRC:16;                                  /*!< 001AH */
        }BIT;
    }PR;                              /*!< 0018H */
    union {
        __IO  uint32_t  V32;                                /*!< 001CH */
        struct {
            __IO  uint32_t  EXTI0     : 3;  /*!< [b2~b0]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  EXTI1     : 3;  /*!< [b6~b4]*/
            __IO  uint32_t  rev1      : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  EXTI2     : 3;  /*!< [b10~b8]*/
            __IO  uint32_t  rev2      : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  EXTI3     : 3;  /*!< [b14~b12]*/
            __IO  uint32_t  rev3      : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  EXTI4     : 3;  /*!< [b18~b16]*/
            __IO  uint32_t  rev4      : 1;  /*!< [b19~b19]*/
            __IO  uint32_t  EXTI5     : 3;  /*!< [b22~b20]*/
            __IO  uint32_t  rev5      : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  EXTI6     : 3;  /*!< [b26~b24]*/
            __IO  uint32_t  rev6      : 1;  /*!< [b27~b27]*/
            __IO  uint32_t  EXTI7     : 3;  /*!< [b30~b28]*/
            __IO  uint32_t  rev7      : 1;  /*!< [b31~b31]*/
        }BIT;
    }CFGL;                               /*!< 001CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0020H */
        struct {
            __IO  uint32_t  EXTI8     : 3;  /*!< [b2~b0]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  EXTI9     : 3;  /*!< [b6~b4]*/
            __IO  uint32_t  rev1      : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  EXTI10    : 3;  /*!< [b10~b8]*/
            __IO  uint32_t  rev2      : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  EXTI11    : 3;  /*!< [b14~b12]*/
            __IO  uint32_t  rev3      : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  EXTI12    : 3;  /*!< [b18~b16]*/
            __IO  uint32_t  rev4      : 1;  /*!< [b19~b19]*/
            __IO  uint32_t  EXTI13    : 3;  /*!< [b22~b20]*/
            __IO  uint32_t  rev5      : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  EXTI14    : 3;  /*!< [b26~b24]*/
            __IO  uint32_t  rev6      : 1;  /*!< [b27~b27]*/
            __IO  uint32_t  EXTI15    : 3;  /*!< [b30~b28]*/
            __IO  uint32_t  rev7      : 1;  /*!< [b31~b31]*/
        }BIT;
    }CFGH;                               /*!< 0020H */
    union {
        __IO  uint32_t  V32;                                /*!< 0024H */
        struct {
            __IO  uint32_t  SN0       : 2;  /*!< [b1~b0]*/
            __IO  uint32_t  PS0       : 2;  /*!< [b3~b2]*/
            __IO  uint32_t  SN1       : 2;  /*!< [b5~b4]*/
            __IO  uint32_t  PS1       : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  SN2       : 2;  /*!< [b9~b8]*/
            __IO  uint32_t  PS2       : 2;  /*!< [b11~b10]*/
            __IO  uint32_t  SN3       : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  PS3       : 2;  /*!< [b15~b14]*/
            __IO  uint32_t  SN4       : 2;  /*!< [b17~b16]*/
            __IO  uint32_t  PS4       : 2;  /*!< [b19~b18]*/
            __IO  uint32_t  rev0      :12;  /*!< [b31~b20]*/
        }BIT;
    }SAMP;                               /*!< 0024H */
    __IO uint32_t  DMR;                                     /*!< 0028H */
}EXTI_TypeDef;


/**
*@brief DMA_registers
*/
typedef struct
{
    union {
        __I   uint32_t  V32;                                /*!< 0000H */
        struct {
            __I   uint32_t  BEIF      : 4;  /*!< [b3~b0]*/
            __IO  uint32_t  rev0      : 4;  /*!< [b7~b4]*/
            __I   uint32_t  TCIF      : 4;  /*!< [b11~b8]*/
            __IO  uint32_t  rev1      : 4;  /*!< [b15~b12]*/
            __I   uint32_t  HTIF      : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  rev2      : 4;  /*!< [b23~b20]*/
            __I   uint32_t  TEIF      : 4;  /*!< [b27~b24]*/
            __IO  uint32_t  rev3      : 4;  /*!< [b31~b28]*/
        }BIT;
    }IFSR;                               /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __O   uint32_t  CBEIF     : 4;  /*!< [b3~b0]*/
            __IO  uint32_t  rev0      : 4;  /*!< [b7~b4]*/
            __O   uint32_t  CTCIF     : 4;  /*!< [b11~b8]*/
            __IO  uint32_t  rev1      : 4;  /*!< [b15~b12]*/
            __O   uint32_t  CHTIF     : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  rev2      : 4;  /*!< [b23~b20]*/
            __O   uint32_t  CTEIF     : 4;  /*!< [b27~b24]*/
            __IO  uint32_t  rev3      : 4;  /*!< [b31~b28]*/
        }BIT;
    }IFCR;                               /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
            __IO  uint32_t  SWTRG     : 4;  /*!< [b3~b0]*/
            __IO  uint32_t  rev0      : 4;  /*!< [b7~b4]*/
            __I   uint32_t  DBUSY     : 4;  /*!< [b11~b8]*/
            __IO  uint32_t  rev1      : 4;  /*!< [b15~b12]*/
            __IO  uint32_t  BURSTIDLE : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  rev2      : 4;  /*!< [b23~b20]*/
            __IO  uint32_t  RELOAD    : 4;  /*!< [b27~b24]*/
            __IO  uint32_t  rev3      : 4;  /*!< [b31~b28]*/
        }BIT;
    }CSR;                               /*!< 0008H */
    __IO uint32_t  Reserved0[1];                            /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
            __IO  uint32_t  EN        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TCIE      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  HTIE      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  BEIE      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  TEIE      : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  DPTYP     : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  SPTYP     : 2;  /*!< [b9~b8]*/
            __IO  uint32_t  DSIZE     : 2;  /*!< [b11~b10]*/
            __IO  uint32_t  SSIZE     : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  PL        : 2;  /*!< [b15~b14]*/
            __IO  uint32_t  BURSTLEN  : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  STRMSEL   : 3;  /*!< [b22~b20]*/
            __IO  uint32_t  TRGMODE   : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  rev1      : 8;  /*!< [b31~b24]*/
        }BIT;
    }CCR0;                               /*!< 0010H */
    __IO uint32_t  NPKT0;                                   /*!< 0014H */
    __I  uint32_t  CPKT0;                                   /*!< 0018H */
    __IO uint32_t  SAR0;                                    /*!< 001CH */
    __IO uint32_t  DAR0;                                    /*!< 0020H */
    __IO uint32_t  Reserved1[3];                            /*!< 0024H */
    union {
        __IO  uint32_t  V32;                                /*!< 0030H */
        struct {
            __IO  uint32_t  EN        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TCIE      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  HTIE      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  BEIE      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  TEIE      : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  DPTYP     : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  SPTYP     : 2;  /*!< [b9~b8]*/
            __IO  uint32_t  DSIZE     : 2;  /*!< [b11~b10]*/
            __IO  uint32_t  SSIZE     : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  PL        : 2;  /*!< [b15~b14]*/
            __IO  uint32_t  BURSTLEN  : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  STRMSEL   : 3;  /*!< [b22~b20]*/
            __IO  uint32_t  TRGMODE   : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  rev1      : 8;  /*!< [b31~b24]*/
        }BIT;
    }CCR1;                               /*!< 0030H */
    __IO uint32_t  NPKT1;                                   /*!< 0034H */
    __I  uint32_t  CPKT1;                                   /*!< 0038H */
    __IO uint32_t  SAR1;                                    /*!< 003CH */
    __IO uint32_t  DAR1;                                    /*!< 0040H */
    __IO uint32_t  Reserved2[3];                            /*!< 0044H */
    union {
        __IO  uint32_t  V32;                                /*!< 0050H */
        struct {
            __IO  uint32_t  EN        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TCIE      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  HTIE      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  BEIE      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  TEIE      : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  DPTYP     : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  SPTYP     : 2;  /*!< [b9~b8]*/
            __IO  uint32_t  DSIZE     : 2;  /*!< [b11~b10]*/
            __IO  uint32_t  SSIZE     : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  PL        : 2;  /*!< [b15~b14]*/
            __IO  uint32_t  BURSTLEN  : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  STRMSEL   : 3;  /*!< [b22~b20]*/
            __IO  uint32_t  TRGMODE   : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  rev1      : 8;  /*!< [b31~b24]*/
        }BIT;
    }CCR2;                               /*!< 0050H */
    __IO uint32_t  NPKT2;                                   /*!< 0054H */
    __I  uint32_t  CPKT2;                                   /*!< 0058H */
    __IO uint32_t  SAR2;                                    /*!< 005CH */
    __IO uint32_t  DAR2;                                    /*!< 0060H */
    __IO uint32_t  Reserved3[3];                            /*!< 0064H */
    union {
        __IO  uint32_t  V32;                                /*!< 0070H */
        struct {
            __IO  uint32_t  EN        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TCIE      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  HTIE      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  BEIE      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  TEIE      : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  DPTYP     : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  SPTYP     : 2;  /*!< [b9~b8]*/
            __IO  uint32_t  DSIZE     : 2;  /*!< [b11~b10]*/
            __IO  uint32_t  SSIZE     : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  PL        : 2;  /*!< [b15~b14]*/
            __IO  uint32_t  BURSTLEN  : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  STRMSEL   : 3;  /*!< [b22~b20]*/
            __IO  uint32_t  TRGMODE   : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  rev1      : 8;  /*!< [b31~b24]*/
        }BIT;
    }CCR3;                               /*!< 0070H */
    __IO uint32_t  NPKT3;                                   /*!< 0074H */
    __I  uint32_t  CPKT3;                                   /*!< 0078H */
    __IO uint32_t  SAR3;                                    /*!< 007CH */
    __IO uint32_t  DAR3;                                    /*!< 0080H */
}DMA_TypeDef;


/**
*@brief LED_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  COMSEL    : 3;  /*!< [b2~b0]*/
            __IO  uint32_t  COMIO     : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  MODE      : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  COMIE     : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  COMGO     : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  DISCOM    : 8;  /*!< [b15~b8]*/
            __IO  uint32_t  LEDCDMA   : 1;  /*!< [b16~b16]*/
            __IO  uint32_t  rev1      :15;  /*!< [b31~b17]*/
        }BIT;
    }COMCR;                               /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __I   uint32_t  COMIF     : 1;  /*!< [b0~b0]*/
            __I   uint32_t  AUIF      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  rev0      :14;  /*!< [b15~b2]*/
            __O   uint32_t  COMIFC    : 1;  /*!< [b16~b16]*/
            __O   uint32_t  AUIFC     : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  rev1      :14;  /*!< [b31~b18]*/
        }BIT;
    }FR;                               /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
            __IO  uint32_t  CCSS0     : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  CCSS1     : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  CCSS2     : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  CCSS3     : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  CCSS4     : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  CCSS5     : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  CCSS6     : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  CCSS7     : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  rev0      :24;  /*!< [b31~b8]*/
        }BIT;
    }CCCR;                               /*!< 0008H */
    union {
        __IO  uint32_t  V32;                                /*!< 000CH */
        struct {
            __IO  uint32_t  CCS0DS    : 4;  /*!< [b3~b0]*/
            __IO  uint32_t  CCS1DS    : 4;  /*!< [b7~b4]*/
            __IO  uint32_t  CCS2DS    : 4;  /*!< [b11~b8]*/
            __IO  uint32_t  CCS3DS    : 4;  /*!< [b15~b12]*/
            __IO  uint32_t  CCS4DS    : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  CCS5DS    : 4;  /*!< [b23~b20]*/
            __IO  uint32_t  CCS6DS    : 4;  /*!< [b27~b24]*/
            __IO  uint32_t  CCS7DS    : 4;  /*!< [b31~b28]*/
        }BIT;
    }CCDR;                               /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
            __IO  uint32_t  DZ        : 8;  /*!< [b7~b0]*/
            __IO  uint32_t  COM       : 8;  /*!< [b15~b8]*/
            __IO  uint32_t  AUMD      : 1;  /*!< [b16~b16]*/
            __IO  uint32_t  AUIE      : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  AUGO      : 1;  /*!< [b18~b18]*/
            __IO  uint32_t  AUEN      : 1;  /*!< [b19~b19]*/
            __IO  uint32_t  AUDMA     : 1;  /*!< [b20~b20]*/
            __IO  uint32_t  rev0      :11;  /*!< [b31~b21]*/
        }BIT;
    }AUCR;                               /*!< 0010H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
            __IO  uint32_t  S0MS      : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  S1MS      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  S2MS      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  S3MS      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  S4MS      : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  S5MS      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  S6MS      : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  S7MS      : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  S8MS      : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  S9MS      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  S10MS     : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  S11MS     : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  S12MS     : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  S13MS     : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  S14MS     : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  S15MS     : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  rev0      :16;  /*!< [b31~b16]*/
        }BIT;
    }SEGMOD;                               /*!< 0014H */
    union {
        __IO  uint32_t  V32;                                /*!< 0018H */
        struct {
    __IO uint32_t  SEG0DUTY:8;                              /*!< 0018H */
    __IO uint32_t  SEG1DUTY:8;                              /*!< 0019H */
    __IO uint32_t  SEG2DUTY:8;                              /*!< 001AH */
    __IO uint32_t  SEG3DUTY:8;                              /*!< 001BH */
        }BIT;
    }SDR0;                              /*!< 0018H */
    union {
        __IO  uint32_t  V32;                                /*!< 001CH */
        struct {
    __IO uint32_t  SEG4DUTY:8;                              /*!< 001CH */
    __IO uint32_t  SEG5DUTY:8;                              /*!< 001DH */
    __IO uint32_t  SEG6DUTY:8;                              /*!< 001EH */
    __IO uint32_t  SEG7DUTY:8;                              /*!< 001FH */
        }BIT;
    }SDR1;                              /*!< 001CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0020H */
        struct {
    __IO uint32_t  SEG8DUTY:8;                              /*!< 0020H */
    __IO uint32_t  SEG9DUTY:8;                              /*!< 0021H */
    __IO uint32_t  SEG10DUTY:8;                             /*!< 0022H */
    __IO uint32_t  SEG11DUTY:8;                             /*!< 0023H */
        }BIT;
    }SDR2;                              /*!< 0020H */
    union {
        __IO  uint32_t  V32;                                /*!< 0024H */
        struct {
    __IO uint32_t  SEG12DUTY:8;                             /*!< 0024H */
    __IO uint32_t  SEG13DUTY:8;                             /*!< 0025H */
    __IO uint32_t  SEG14DUTY:8;                             /*!< 0026H */
    __IO uint32_t  SEG15DUTY:8;                             /*!< 0027H */
        }BIT;
    }SDR3;                              /*!< 0024H */
    union {
        __IO  uint32_t  V32;                                /*!< 0028H */
        struct {
    __IO uint32_t  COM0SEG:16;                              /*!< 0028H */
    __IO uint32_t  COM1SEG:16;                              /*!< 002AH */
        }BIT;
    }SOR0;                              /*!< 0028H */
    union {
        __IO  uint32_t  V32;                                /*!< 002CH */
        struct {
    __IO uint32_t  COM2SEG:16;                              /*!< 002CH */
    __IO uint32_t  COM3SEG:16;                              /*!< 002EH */
        }BIT;
    }SOR1;                              /*!< 002CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0030H */
        struct {
    __IO uint32_t  COM4SEG:16;                              /*!< 0030H */
    __IO uint32_t  COM5SEG:16;                              /*!< 0032H */
        }BIT;
    }SOR2;                              /*!< 0030H */
    union {
        __IO  uint32_t  V32;                                /*!< 0034H */
        struct {
    __IO uint32_t  COM6SEG:16;                              /*!< 0034H */
    __IO uint32_t  COM7SEG:16;                              /*!< 0036H */
        }BIT;
    }SOR3;                              /*!< 0034H */
}LED_TypeDef;


/**
*@brief LCD_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  EN        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  LCLK      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  DUTY      : 3;  /*!< [b4~b2]*/
            __IO  uint32_t  VOL       : 3;  /*!< [b7~b5]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  ELCC      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  MODSW     : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  rev1      : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  MOD       : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  FCCTL     : 2;  /*!< [b15~b14]*/
            __IO  uint32_t  CNTMOD    : 1;  /*!< [b16~b16]*/
            __IO  uint32_t  DCK       : 2;  /*!< [b18~b17]*/
            __IO  uint32_t  rev2      :13;  /*!< [b31~b19]*/
        }BIT;
    }CR;                               /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
    __IO uint32_t  LCDBUF0:8;                               /*!< 0004H */
    __IO uint32_t  LCDBUF1:8;                               /*!< 0005H */
    __IO uint32_t  LCDBUF2:8;                               /*!< 0006H */
    __IO uint32_t  LCDBUF3:8;                               /*!< 0007H */
        }BIT;
    }BUFS0;                              /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
    __IO uint32_t  LCDBUF4:8;                               /*!< 0008H */
    __IO uint32_t  LCDBUF5:8;                               /*!< 0009H */
    __IO uint32_t  LCDBUF6:8;                               /*!< 000AH */
    __IO uint32_t  LCDBUF7:8;                               /*!< 000BH */
        }BIT;
    }BUFS1;                              /*!< 0008H */
    union {
        __IO  uint32_t  V32;                                /*!< 000CH */
        struct {
    __IO uint32_t  LCDBUF8:8;                               /*!< 000CH */
    __IO uint32_t  LCDBUF9:8;                               /*!< 000DH */
    __IO uint32_t  LCDBUF10:8;                              /*!< 000EH */
    __IO uint32_t  LCDBUF11:8;                              /*!< 000FH */
        }BIT;
    }BUFS2;                              /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
    __IO uint32_t  LCDBUF12:8;                              /*!< 0010H */
    __IO uint32_t  LCDBUF13:8;                              /*!< 0011H */
    __IO uint32_t  LCDBUF14:8;                              /*!< 0012H */
    __IO uint32_t  LCDBUF15:8;                              /*!< 0013H */
        }BIT;
    }BUFS3;                              /*!< 0010H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
    __IO uint32_t  LCDBUF16:8;                              /*!< 0014H */
    __IO uint32_t  LCDBUF17:8;                              /*!< 0015H */
    __IO uint32_t  LCDBUF18:8;                              /*!< 0016H */
    __IO uint32_t  LCDBUF19:8;                              /*!< 0017H */
        }BIT;
    }BUFS4;                              /*!< 0014H */
    union {
        __IO  uint32_t  V32;                                /*!< 0018H */
        struct {
    __IO uint32_t  LCDBUF20:8;                              /*!< 0018H */
    __IO uint32_t  LCDBUF21:8;                              /*!< 0019H */
    __IO uint32_t  LCDBUF22:8;                              /*!< 001AH */
    __IO uint32_t  LCDBUF23:8;                              /*!< 001BH */
        }BIT;
    }BUFS5;                              /*!< 0018H */
    union {
        __IO  uint32_t  V32;                                /*!< 001CH */
        struct {
    __IO uint32_t  LCDBUF24:8;                              /*!< 001CH */
    __IO uint32_t  LCDBUF25:8;                              /*!< 001DH */
    __IO uint32_t  LCDBUF26:8;                              /*!< 001EH */
    __IO uint32_t  LCDBUF27:8;                              /*!< 001FH */
        }BIT;
    }BUFS6;                              /*!< 001CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0020H */
        struct {
    __IO uint32_t  LCDBUF28:8;                              /*!< 0020H */
    __IO uint32_t  LCDBUF29:8;                              /*!< 0021H */
    __IO uint32_t  LCDBUF30:8;                              /*!< 0022H */
    __IO uint32_t  LCDBUF31:8;                              /*!< 0023H */
        }BIT;
    }BUFS7;                              /*!< 0020H */
    union {
        __IO  uint32_t  V32;                                /*!< 0024H */
        struct {
    __IO uint32_t  LCDBUF32:8;                              /*!< 0024H */
    __IO uint32_t  LCDBUF33:8;                              /*!< 0025H */
    __IO uint32_t  LCDBUF34:8;                              /*!< 0026H */
    __IO uint32_t  LCDBUF35:8;                              /*!< 0027H */
        }BIT;
    }BUFS8;                              /*!< 0024H */
    union {
        __IO  uint32_t  V32;                                /*!< 0028H */
        struct {
    __IO uint32_t  LCDBUF36:8;                              /*!< 0028H */
    __IO uint32_t  LCDBUF37:8;                              /*!< 0029H */
    __IO uint32_t  LCDBUF38:8;                              /*!< 002AH */
    __IO uint32_t  LCDBUF39:8;                              /*!< 002BH */
        }BIT;
    }BUFS9;                              /*!< 0028H */
}LCD_TypeDef;


/**
*@brief TIMER16_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  STR       : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  rev0      : 2;  /*!< [b2~b1]*/
            __IO  uint32_t  OPM       : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  CLKS      : 2;  /*!< [b5~b4]*/
            __IO  uint32_t  rev1      : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  IE        : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  TRIGEN    : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  ETEN      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  TC        : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  rev2      : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  ECF       : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  rev3      :18;  /*!< [b31~b14]*/
        }BIT;
    }CR;                               /*!< 0000H */
    __IO uint32_t  TCNT;                                    /*!< 0004H */
    __IO uint32_t  TPR;                                     /*!< 0008H */
    __IO uint32_t  PSQ;                                     /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
            __I   uint32_t  TF        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  rev0      :15;  /*!< [b15~b1]*/
            __O   uint32_t  TFC       : 1;  /*!< [b16~b16]*/
            __IO  uint32_t  rev1      :15;  /*!< [b31~b17]*/
        }BIT;
    }TIMINTF;                               /*!< 0010H */
}TIMER16_TypeDef;


/**
*@brief TIMER32_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  STR       : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  rev0      : 2;  /*!< [b2~b1]*/
            __IO  uint32_t  OPM       : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  CLKS      : 2;  /*!< [b5~b4]*/
            __IO  uint32_t  rev1      : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  IE        : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  TRIGEN    : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  ETEN      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  TC        : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  rev2      : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  ECF       : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  rev3      :18;  /*!< [b31~b14]*/
        }BIT;
    }CR;                               /*!< 0000H */
    __IO uint32_t  TCNT;                                    /*!< 0004H */
    __IO uint32_t  TPR;                                     /*!< 0008H */
    __IO uint32_t  PSQ;                                     /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
            __I   uint32_t  TF        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  rev0      :15;  /*!< [b15~b1]*/
            __O   uint32_t  TFC       : 1;  /*!< [b16~b16]*/
            __IO  uint32_t  rev1      :15;  /*!< [b31~b17]*/
        }BIT;
    }TIMINTF;                               /*!< 0010H */
}TIMER32_TypeDef;


/**
*@brief PWM_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  PWMEN     : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TCK       : 3;  /*!< [b3~b1]*/
            __IO  uint32_t  FLTC      : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  EFLT      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  PWMSB     : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  PWMSA     : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  EFLTIE    : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  PWMIE     : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  PWMDMA    : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  FLTDMA    : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  rev0      :20;  /*!< [b31~b12]*/
        }BIT;
    }CR;                               /*!< 0000H */
    __IO uint32_t  PWMLOCK;                                 /*!< 0004H */
    __IO uint32_t  PWMPR;                                   /*!< 0008H */
    __IO uint32_t  PWMDR;                                   /*!< 000CH */
    __IO uint32_t  PWMDTR;                                  /*!< 0010H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
            __I   uint32_t  FLTS      : 1;  /*!< [b0~b0]*/
            __I   uint32_t  PWMIF     : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  rev0      :14;  /*!< [b15~b2]*/
            __O   uint32_t  FLTSC     : 1;  /*!< [b16~b16]*/
            __O   uint32_t  PWMIFC    : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  rev1      :14;  /*!< [b31~b18]*/
        }BIT;
    }PWMINTF;                               /*!< 0014H */
}PWM_TypeDef;


/**
*@brief PCA_registers
*/
typedef struct
{
    __IO uint32_t  CR;                                      /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __IO  uint32_t  CPS       : 3;  /*!< [b2~b0]*/
            __IO  uint32_t  CASCEN    : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  rev0      : 2;  /*!< [b5~b4]*/
            __IO  uint32_t  SDEN      : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  CIE       : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  PIE       : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  rev1      : 3;  /*!< [b11~b9]*/
            __IO  uint32_t  CC0UE     : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  CC1UE     : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  rev2      : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  PUE       : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  ECF       : 2;  /*!< [b17~b16]*/
            __IO  uint32_t  rev3      : 2;  /*!< [b19~b18]*/
            __IO  uint32_t  CC0DMA    : 1;  /*!< [b20~b20]*/
            __IO  uint32_t  CC1DMA    : 1;  /*!< [b21~b21]*/
            __IO  uint32_t  rev4      : 1;  /*!< [b22~b22]*/
            __IO  uint32_t  CUDMA     : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  PUDMA     : 1;  /*!< [b24~b24]*/
            __IO  uint32_t  rev5      : 7;  /*!< [b31~b25]*/
        }BIT;
    }CFGR;                               /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
            __I   uint32_t  CC0IF     : 1;  /*!< [b0~b0]*/
            __I   uint32_t  CC1IF     : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  rev0      : 2;  /*!< [b3~b2]*/
            __I   uint32_t  PIF       : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  rev1      : 2;  /*!< [b6~b5]*/
            __I   uint32_t  CIF       : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  rev2      : 8;  /*!< [b15~b8]*/
            __O   uint32_t  CC0IFC    : 1;  /*!< [b16~b16]*/
            __O   uint32_t  CC1IFC    : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  rev3      : 2;  /*!< [b19~b18]*/
            __O   uint32_t  PIFC      : 1;  /*!< [b20~b20]*/
            __IO  uint32_t  rev4      : 2;  /*!< [b22~b21]*/
            __O   uint32_t  CIFC      : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  rev5      : 8;  /*!< [b31~b24]*/
        }BIT;
    }SR;                               /*!< 0008H */
    union {
        __IO  uint32_t  V32;                                /*!< 000CH */
        struct {
            __IO  uint32_t  FCO0      : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  FCO1      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  rev0      :30;  /*!< [b31~b2]*/
        }BIT;
    }FORCE;                               /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
    __IO uint32_t  CNTL:8;                                  /*!< 0010H */
    __IO uint32_t  CNTH:8;                                  /*!< 0011H */
    __IO uint32_t  CNTCAS:16;                               /*!< 0012H */
        }BIT;
    }CNT;                              /*!< 0010H */
    __IO uint32_t  PSC;                                     /*!< 0014H */
    union {
        __IO  uint32_t  V32;                                /*!< 0018H */
        struct {
    __IO uint32_t  PRL:8;                                   /*!< 0018H */
    __IO uint32_t  PRH:8;                                   /*!< 0019H */
    __IO uint32_t  PRCAS:16;                                /*!< 001AH */
        }BIT;
    }PR;                              /*!< 0018H */
    union {
        __IO  uint32_t  V32;                                /*!< 001CH */
        struct {
            __IO  uint32_t  CCIE      : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  TCP       : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  CEN       : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  FS        : 2;  /*!< [b5~b4]*/
            __IO  uint32_t  SM        : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  CC        : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  rev1      :23;  /*!< [b31~b9]*/
        }BIT;
    }CCMR0;                               /*!< 001CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0020H */
        struct {
            __IO  uint32_t  CCIE      : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  TCP       : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  CEN       : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  FS        : 2;  /*!< [b5~b4]*/
            __IO  uint32_t  SM        : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  CC        : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  rev1      :23;  /*!< [b31~b9]*/
        }BIT;
    }CCMR1;                               /*!< 0020H */
    union {
        __IO  uint32_t  V32;                                /*!< 0024H */
        struct {
    __IO uint32_t  CCR0L:8;                                 /*!< 0024H */
    __IO uint32_t  CCR0H:8;                                 /*!< 0025H */
    __IO uint32_t  CCR0CAS:16;                              /*!< 0026H */
        }BIT;
    }CCR0;                              /*!< 0024H */
    union {
        __IO  uint32_t  V32;                                /*!< 0028H */
        struct {
    __IO uint32_t  CCR1L:8;                                 /*!< 0028H */
    __IO uint32_t  CCR1H:8;                                 /*!< 0029H */
    __IO uint32_t  CCR1CAS:16;                              /*!< 002AH */
        }BIT;
    }CCR1;                              /*!< 0028H */
    __IO uint32_t  LCKR;                                    /*!< 002CH */
}PCA_TypeDef;


/**
*@brief UART_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __I   uint32_t  RI        : 1;  /*!< [b0~b0]*/
            __I   uint32_t  TI        : 1;  /*!< [b1~b1]*/
            __I   uint32_t  TC        : 1;  /*!< [b2~b2]*/
            __I   uint32_t  TXCOL     : 1;  /*!< [b3~b3]*/
            __I   uint32_t  RXOV      : 1;  /*!< [b4~b4]*/
            __I   uint32_t  FE        : 1;  /*!< [b5~b5]*/
            __I   uint32_t  PE        : 1;  /*!< [b6~b6]*/
            __I   uint32_t  LBD       : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  rev0      :10;  /*!< [b17~b8]*/
            __O   uint32_t  TCC       : 1;  /*!< [b18~b18]*/
            __O   uint32_t  TXCOLC    : 1;  /*!< [b19~b19]*/
            __O   uint32_t  RXOVC     : 1;  /*!< [b20~b20]*/
            __O   uint32_t  FEC       : 1;  /*!< [b21~b21]*/
            __O   uint32_t  PEC       : 1;  /*!< [b22~b22]*/
            __O   uint32_t  LBDC      : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  rev1      : 8;  /*!< [b31~b24]*/
        }BIT;
    }FR;                               /*!< 0000H */
    __IO uint32_t  Reserved0[1];                            /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
            __IO  uint32_t  TDR       : 8;  /*!< [b7~b0]*/
            __IO  uint32_t  TB8       : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  rev0      :23;  /*!< [b31~b9]*/
        }BIT;
    }TDR;                               /*!< 0008H */
    union {
        __I   uint32_t  V32;                                /*!< 000CH */
        struct {
            __I   uint32_t  RDR       : 8;  /*!< [b7~b0]*/
            __I   uint32_t  RB8       : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  rev0      :23;  /*!< [b31~b9]*/
        }BIT;
    }RDR;                               /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
    __IO uint32_t  SADDR:8;                                 /*!< 0010H */
    __IO uint32_t  SMAR:8;                                  /*!< 0011H */
    __IO uint32_t  rev0:16;                                 /*!< 0012H */
        }BIT;
    }ADDR;                              /*!< 0010H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
            __IO  uint32_t  SBRT      :15;  /*!< [b14~b0]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  BFINE     : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  rev1      :12;  /*!< [b31~b20]*/
        }BIT;
    }BRT;                               /*!< 0014H */
    union {
        __IO  uint32_t  V32;                                /*!< 0018H */
        struct {
            __IO  uint32_t  STOP      : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  SBRTEN    : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  SMOD2     : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  RIE       : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  TIE       : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  TCIE      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  LBDIE     : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  LBDL      : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  SMOD0     : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  PS        : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  MULTIE    : 2;  /*!< [b12~b11]*/
            __IO  uint32_t  SM        : 2;  /*!< [b14~b13]*/
            __IO  uint32_t  SBK       : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  LINEN     : 1;  /*!< [b16~b16]*/
            __IO  uint32_t  REN       : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  TEN       : 1;  /*!< [b18~b18]*/
            __IO  uint32_t  DMAR      : 1;  /*!< [b19~b19]*/
            __IO  uint32_t  DMAT      : 1;  /*!< [b20~b20]*/
            __IO  uint32_t  RNEG      : 1;  /*!< [b21~b21]*/
            __IO  uint32_t  TNEG      : 1;  /*!< [b22~b22]*/
            __IO  uint32_t  FER       : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  rev1      : 8;  /*!< [b31~b24]*/
        }BIT;
    }CR;                               /*!< 0018H */
}UART_TypeDef;


/**
*@brief SPI_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __I   uint32_t  SPRI      : 1;  /*!< [b0~b0]*/
            __I   uint32_t  SPTI      : 1;  /*!< [b1~b1]*/
            __I   uint32_t  BUSY      : 1;  /*!< [b2~b2]*/
            __I   uint32_t  MODF      : 1;  /*!< [b3~b3]*/
            __I   uint32_t  RXOV      : 1;  /*!< [b4~b4]*/
            __I   uint32_t  WCOL      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  rev0      :13;  /*!< [b18~b6]*/
            __O   uint32_t  MODFC     : 1;  /*!< [b19~b19]*/
            __O   uint32_t  RXOVC     : 1;  /*!< [b20~b20]*/
            __O   uint32_t  WCOLC     : 1;  /*!< [b21~b21]*/
            __IO  uint32_t  rev1      :10;  /*!< [b31~b22]*/
        }BIT;
    }FR;                               /*!< 0000H */
    __IO uint32_t  TDR;                                     /*!< 0004H */
    __I  uint32_t  RDR;                                     /*!< 0008H */
    union {
        __IO  uint32_t  V32;                                /*!< 000CH */
        struct {
            __IO  uint32_t  SPR       : 4;  /*!< [b3~b0]*/
            __IO  uint32_t  SSDIS     : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  CPOL      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  CPHA      : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  MSTR      : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  DIR       : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  SPRIE     : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  SPTIE     : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  SPDMAR    : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  SPDMAT    : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  SPIEN     : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  SPSFF     : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  SPDATL    : 2;  /*!< [b17~b16]*/
            __IO  uint32_t  rev1      :14;  /*!< [b31~b18]*/
        }BIT;
    }CR;                               /*!< 000CH */
}SPI_TypeDef;


/**
*@brief TWI_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __I   uint32_t  TWINT     : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b1~b1]*/
            __I   uint32_t  TFREE     : 1;  /*!< [b2~b2]*/
            __I   uint32_t  TOUT      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  rev1      :12;  /*!< [b15~b4]*/
            __O   uint32_t  TWINTC    : 1;  /*!< [b16~b16]*/
            __IO  uint32_t  rev2      : 1;  /*!< [b17~b17]*/
            __O   uint32_t  TFREEC    : 1;  /*!< [b18~b18]*/
            __O   uint32_t  TOUTC     : 1;  /*!< [b19~b19]*/
            __IO  uint32_t  rev3      :12;  /*!< [b31~b20]*/
        }BIT;
    }FR;                               /*!< 0000H */
    union {
        __I   uint32_t  V32;                                /*!< 0004H */
        struct {
            __IO  uint32_t  rev0      : 3;  /*!< [b2~b0]*/
            __I   uint32_t  SR        : 5;  /*!< [b7~b3]*/
            __IO  uint32_t  rev1      :24;  /*!< [b31~b8]*/
        }BIT;
    }STAT;                               /*!< 0004H */
    __IO uint32_t  HOC;                                     /*!< 0008H */
    __IO uint32_t  BRT;                                     /*!< 000CH */
    __IO uint32_t  DR;                                      /*!< 0010H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
            __IO  uint32_t  GC        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  ADDR      : 7;  /*!< [b7~b1]*/
            __IO  uint32_t  rev0      : 9;  /*!< [b16~b8]*/
            __IO  uint32_t  TWIAMR    : 7;  /*!< [b23~b17]*/
            __IO  uint32_t  rev1      : 8;  /*!< [b31~b24]*/
        }BIT;
    }ADDR;                               /*!< 0014H */
    union {
        __IO  uint32_t  V32;                                /*!< 0018H */
        struct {
            __IO  uint32_t  AA        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  STO       : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  STA       : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  CR        : 2;  /*!< [b5~b4]*/
            __IO  uint32_t  CNT       : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  EFREE     : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  ETOT      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  TWINTE    : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  rev1      : 4;  /*!< [b14~b11]*/
            __IO  uint32_t  TWIEN     : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  rev2      :16;  /*!< [b31~b16]*/
        }BIT;
    }CR;                               /*!< 0018H */
}TWI_TypeDef;


/**
*@brief ADC_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  ADSOC     : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  ADCTU     : 2;  /*!< [b2~b1]*/
            __IO  uint32_t  MOD       : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  REFC      : 2;  /*!< [b5~b4]*/
            __IO  uint32_t  ADDE      : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  ADIE      : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  ADSTRS    : 7;  /*!< [b14~b8]*/
            __IO  uint32_t  ADON      : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  rev0      :16;  /*!< [b31~b16]*/
        }BIT;
    }ADCON1;                               /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __IO  uint32_t  TADC      : 4;  /*!< [b3~b0]*/
            __IO  uint32_t  ADMAXCH   : 3;  /*!< [b6~b4]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  TS        : 4;  /*!< [b11~b8]*/
            __IO  uint32_t  rev1      : 4;  /*!< [b15~b12]*/
            __IO  uint32_t  TGAP      : 3;  /*!< [b18~b16]*/
            __IO  uint32_t  rev2      :13;  /*!< [b31~b19]*/
        }BIT;
    }ADCON2;                               /*!< 0004H */
    __IO uint32_t  ADPCH;                                   /*!< 0008H */
    __I  uint32_t  ADDR0;                                   /*!< 000CH */
    __I  uint32_t  ADDR1;                                   /*!< 0010H */
    __I  uint32_t  ADDR2;                                   /*!< 0014H */
    __I  uint32_t  ADDR3;                                   /*!< 0018H */
    __I  uint32_t  ADDR4;                                   /*!< 001CH */
    __I  uint32_t  ADDR5;                                   /*!< 0020H */
    __I  uint32_t  ADDR6;                                   /*!< 0024H */
    __I  uint32_t  ADDR7;                                   /*!< 0028H */
    union {
        __IO  uint32_t  V32;                                /*!< 002CH */
        struct {
            __IO  uint32_t  CSEL      : 3;  /*!< [b2~b0]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  ADLDE     : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  ADLIE     : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  ADGDE     : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  ADGIE     : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  rev1      :24;  /*!< [b31~b8]*/
        }BIT;
    }ADCMPCON;                               /*!< 002CH */
    __IO uint32_t  ADDGT;                                   /*!< 0030H */
    __IO uint32_t  ADDLT;                                   /*!< 0034H */
    union {
        __IO  uint32_t  V32;                                /*!< 0038H */
        struct {
            __IO  uint32_t  SEQCH0    : 5;  /*!< [b4~b0]*/
            __IO  uint32_t  rev0      : 3;  /*!< [b7~b5]*/
            __IO  uint32_t  SEQCH1    : 5;  /*!< [b12~b8]*/
            __IO  uint32_t  rev1      : 3;  /*!< [b15~b13]*/
            __IO  uint32_t  SEQCH2    : 5;  /*!< [b20~b16]*/
            __IO  uint32_t  rev2      : 3;  /*!< [b23~b21]*/
            __IO  uint32_t  SEQCH3    : 5;  /*!< [b28~b24]*/
            __IO  uint32_t  rev3      : 3;  /*!< [b31~b29]*/
        }BIT;
    }SEQCHSEL0;                               /*!< 0038H */
    union {
        __IO  uint32_t  V32;                                /*!< 003CH */
        struct {
            __IO  uint32_t  SEQCH4    : 5;  /*!< [b4~b0]*/
            __IO  uint32_t  rev0      : 3;  /*!< [b7~b5]*/
            __IO  uint32_t  SEQCH5    : 5;  /*!< [b12~b8]*/
            __IO  uint32_t  rev1      : 3;  /*!< [b15~b13]*/
            __IO  uint32_t  SEQCH6    : 5;  /*!< [b20~b16]*/
            __IO  uint32_t  rev2      : 3;  /*!< [b23~b21]*/
            __IO  uint32_t  SEQCH7    : 5;  /*!< [b28~b24]*/
            __IO  uint32_t  rev3      : 3;  /*!< [b31~b29]*/
        }BIT;
    }SEQCHSEL1;                               /*!< 003CH */
    __IO uint32_t  ADGAPON;                                 /*!< 0040H */
    union {
        __IO  uint32_t  V32;                                /*!< 0044H */
        struct {
            __I   uint32_t  ADLIF     : 1;  /*!< [b0~b0]*/
            __I   uint32_t  ADGIF     : 1;  /*!< [b1~b1]*/
            __I   uint32_t  ADIF      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  rev0      :13;  /*!< [b15~b3]*/
            __O   uint32_t  ADLIFC    : 1;  /*!< [b16~b16]*/
            __O   uint32_t  ADGIFC    : 1;  /*!< [b17~b17]*/
            __O   uint32_t  ADIFC     : 1;  /*!< [b18~b18]*/
            __IO  uint32_t  rev1      :13;  /*!< [b31~b19]*/
        }BIT;
    }ADINTF;                               /*!< 0044H */
}ADC_TypeDef;


/**
*@brief HLV_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  ADDR      : 3;  /*!< [b2~b0]*/
            __IO  uint32_t  RW        : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  START     : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  HLVEN     : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  EHLV      : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  rev0      : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  HLVCK     : 3;  /*!< [b10~b8]*/
            __IO  uint32_t  rev1      :21;  /*!< [b31~b11]*/
        }BIT;
    }CR;                               /*!< 0000H */
    __IO uint32_t  DR;                                      /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
            __I   uint32_t  HLVIF     : 1;  /*!< [b0~b0]*/
            __I   uint32_t  ERRF      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  rev0      :14;  /*!< [b15~b2]*/
            __O   uint32_t  HLVIFC    : 1;  /*!< [b16~b16]*/
            __O   uint32_t  ERRFC     : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  rev1      :14;  /*!< [b31~b18]*/
        }BIT;
    }FR;                               /*!< 0008H */
}HLV_TypeDef;


/**
*@brief TOUCHKEY_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  TKCON     : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TKGO_DONE : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  rev0      : 2;  /*!< [b3~b2]*/
            __IO  uint32_t  FSW       : 3;  /*!< [b6~b4]*/
            __IO  uint32_t  TKCLKS    : 2;  /*!< [b8~b7]*/
            __IO  uint32_t  Tstep     : 2;  /*!< [b10~b9]*/
            __IO  uint32_t  TKMODE    : 2;  /*!< [b12~b11]*/
            __IO  uint32_t  TKCC      : 3;  /*!< [b15~b13]*/
            __IO  uint32_t  TKADCT    : 6;  /*!< [b21~b16]*/
            __IO  uint32_t  IE        : 1;  /*!< [b22~b22]*/
            __IO  uint32_t  TKDMA     : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  rev1      : 8;  /*!< [b31~b24]*/
        }BIT;
    }CR;                               /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __IO  uint32_t  RANDOM    : 4;  /*!< [b3~b0]*/
            __IO  uint32_t  SPSPNum   : 2;  /*!< [b5~b4]*/
            __IO  uint32_t  TKFUN     : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  TKCF      : 9;  /*!< [b16~b8]*/
            __IO  uint32_t  TKRX      : 2;  /*!< [b18~b17]*/
            __IO  uint32_t  TKRS      : 2;  /*!< [b20~b19]*/
            __IO  uint32_t  ENFING    : 1;  /*!< [b21~b21]*/
            __IO  uint32_t  ENCREF    : 1;  /*!< [b22~b22]*/
            __IO  uint32_t  rev0      : 9;  /*!< [b31~b23]*/
        }BIT;
    }CR1;                               /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
            __I   uint32_t  IFAVE     : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  rev0      :15;  /*!< [b15~b1]*/
            __O   uint32_t  IFAVEC    : 1;  /*!< [b16~b16]*/
            __IO  uint32_t  rev1      :15;  /*!< [b31~b17]*/
        }BIT;
    }FR;                               /*!< 0008H */
    union {
        __IO  uint32_t  V32;                                /*!< 000CH */
        struct {
    __IO uint32_t  TKSTEP1:8;                               /*!< 000CH */
    __IO uint32_t  TKSTEP2:8;                               /*!< 000DH */
    __IO uint32_t  TKSTEP3:8;                               /*!< 000EH */
    __IO uint32_t  TKSTEP4:8;                               /*!< 000FH */
        }BIT;
    }TSL;                              /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
    __IO uint32_t  TKSTEP5:8;                               /*!< 0010H */
    __IO uint32_t  TKSTEP6:8;                               /*!< 0011H */
    __IO uint32_t  TKSTEP7:8;                               /*!< 0012H */
    __IO uint32_t  rev0:8;                                  /*!< 0013H */
        }BIT;
    }TSH;                              /*!< 0010H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
            __IO  uint32_t  TKCADJ00  :11;  /*!< [b10~b0]*/
            __IO  uint32_t  rev0      : 5;  /*!< [b15~b11]*/
            __IO  uint32_t  TKCADJ01  :11;  /*!< [b26~b16]*/
            __IO  uint32_t  rev1      : 5;  /*!< [b31~b27]*/
        }BIT;
    }TC0;                               /*!< 0014H */
    union {
        __IO  uint32_t  V32;                                /*!< 0018H */
        struct {
            __IO  uint32_t  TKCADJ02  :11;  /*!< [b10~b0]*/
            __IO  uint32_t  rev0      : 5;  /*!< [b15~b11]*/
            __IO  uint32_t  TKCADJ03  :11;  /*!< [b26~b16]*/
            __IO  uint32_t  rev1      : 5;  /*!< [b31~b27]*/
        }BIT;
    }TC1;                               /*!< 0018H */
    union {
        __IO  uint32_t  V32;                                /*!< 001CH */
        struct {
            __IO  uint32_t  TKCADJ04  :11;  /*!< [b10~b0]*/
            __IO  uint32_t  rev0      : 5;  /*!< [b15~b11]*/
            __IO  uint32_t  TKCADJ05  :11;  /*!< [b26~b16]*/
            __IO  uint32_t  rev1      : 5;  /*!< [b31~b27]*/
        }BIT;
    }TC2;                               /*!< 001CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0020H */
        struct {
            __IO  uint32_t  TKCADJ06  :11;  /*!< [b10~b0]*/
            __IO  uint32_t  rev0      : 5;  /*!< [b15~b11]*/
            __IO  uint32_t  TKCADJ07  :11;  /*!< [b26~b16]*/
            __IO  uint32_t  rev1      : 5;  /*!< [b31~b27]*/
        }BIT;
    }TC3;                               /*!< 0020H */
    union {
        __IO  uint32_t  V32;                                /*!< 0024H */
        struct {
            __IO  uint32_t  TKCADJ08  :11;  /*!< [b10~b0]*/
            __IO  uint32_t  rev0      : 5;  /*!< [b15~b11]*/
            __IO  uint32_t  TKCADJ09  :11;  /*!< [b26~b16]*/
            __IO  uint32_t  rev1      : 5;  /*!< [b31~b27]*/
        }BIT;
    }TC4;                               /*!< 0024H */
    union {
        __IO  uint32_t  V32;                                /*!< 0028H */
        struct {
            __IO  uint32_t  TKCADJ10  :11;  /*!< [b10~b0]*/
            __IO  uint32_t  rev0      : 5;  /*!< [b15~b11]*/
            __IO  uint32_t  TKCADJ11  :11;  /*!< [b26~b16]*/
            __IO  uint32_t  rev1      : 5;  /*!< [b31~b27]*/
        }BIT;
    }TC5;                               /*!< 0028H */
    union {
        __IO  uint32_t  V32;                                /*!< 002CH */
        struct {
            __IO  uint32_t  TKCADJ12  :11;  /*!< [b10~b0]*/
            __IO  uint32_t  rev0      : 5;  /*!< [b15~b11]*/
            __IO  uint32_t  TKCADJ13  :11;  /*!< [b26~b16]*/
            __IO  uint32_t  rev1      : 5;  /*!< [b31~b27]*/
        }BIT;
    }TC6;                               /*!< 002CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0030H */
        struct {
            __IO  uint32_t  TKCADJ14  :11;  /*!< [b10~b0]*/
            __IO  uint32_t  rev0      : 5;  /*!< [b15~b11]*/
            __IO  uint32_t  TKCADJ15  :11;  /*!< [b26~b16]*/
            __IO  uint32_t  rev1      : 5;  /*!< [b31~b27]*/
        }BIT;
    }TC7;                               /*!< 0030H */
    union {
        __IO  uint32_t  V32;                                /*!< 0034H */
        struct {
            __IO  uint32_t  TKCADJ16  :11;  /*!< [b10~b0]*/
            __IO  uint32_t  rev0      : 5;  /*!< [b15~b11]*/
            __IO  uint32_t  TKCADJ17  :11;  /*!< [b26~b16]*/
            __IO  uint32_t  rev1      : 5;  /*!< [b31~b27]*/
        }BIT;
    }TC8;                               /*!< 0034H */
    union {
        __IO  uint32_t  V32;                                /*!< 0038H */
        struct {
            __IO  uint32_t  TKCADJ18  :11;  /*!< [b10~b0]*/
            __IO  uint32_t  rev0      : 5;  /*!< [b15~b11]*/
            __IO  uint32_t  TKCADJ19  :11;  /*!< [b26~b16]*/
            __IO  uint32_t  rev1      : 5;  /*!< [b31~b27]*/
        }BIT;
    }TC9;                               /*!< 0038H */
    union {
        __IO  uint32_t  V32;                                /*!< 003CH */
        struct {
            __IO  uint32_t  TKCADJ20  :11;  /*!< [b10~b0]*/
            __IO  uint32_t  rev0      : 5;  /*!< [b15~b11]*/
            __IO  uint32_t  TKCADJ21  :11;  /*!< [b26~b16]*/
            __IO  uint32_t  rev1      : 5;  /*!< [b31~b27]*/
        }BIT;
    }TC10;                               /*!< 003CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0040H */
        struct {
            __IO  uint32_t  TKCADJ22  :11;  /*!< [b10~b0]*/
            __IO  uint32_t  rev0      : 5;  /*!< [b15~b11]*/
            __IO  uint32_t  TKCADJ23  :11;  /*!< [b26~b16]*/
            __IO  uint32_t  rev1      : 5;  /*!< [b31~b27]*/
        }BIT;
    }TC11;                               /*!< 0040H */
    union {
        __IO  uint32_t  V32;                                /*!< 0044H */
        struct {
            __IO  uint32_t  TKCADJ24  :11;  /*!< [b10~b0]*/
            __IO  uint32_t  rev0      : 5;  /*!< [b15~b11]*/
            __IO  uint32_t  TKCADJ25  :11;  /*!< [b26~b16]*/
            __IO  uint32_t  rev1      : 5;  /*!< [b31~b27]*/
        }BIT;
    }TC12;                               /*!< 0044H */
    union {
        __IO  uint32_t  V32;                                /*!< 0048H */
        struct {
            __IO  uint32_t  TKCADJ26  :11;  /*!< [b10~b0]*/
            __IO  uint32_t  rev0      : 5;  /*!< [b15~b11]*/
            __IO  uint32_t  TKCADJ27  :11;  /*!< [b26~b16]*/
            __IO  uint32_t  rev1      : 5;  /*!< [b31~b27]*/
        }BIT;
    }TC13;                               /*!< 0048H */
    union {
        __IO  uint32_t  V32;                                /*!< 004CH */
        struct {
            __IO  uint32_t  TKCADJ28  :11;  /*!< [b10~b0]*/
            __IO  uint32_t  rev0      : 5;  /*!< [b15~b11]*/
            __IO  uint32_t  TKCADJ29  :11;  /*!< [b26~b16]*/
            __IO  uint32_t  rev1      : 5;  /*!< [b31~b27]*/
        }BIT;
    }TC14;                               /*!< 004CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0050H */
        struct {
            __IO  uint32_t  TKCADJ30  :11;  /*!< [b10~b0]*/
            __IO  uint32_t  rev0      : 5;  /*!< [b15~b11]*/
            __IO  uint32_t  TKCADJ31  :11;  /*!< [b26~b16]*/
            __IO  uint32_t  rev1      : 5;  /*!< [b31~b27]*/
        }BIT;
    }TC15;                               /*!< 0050H */
    __IO uint32_t  TC16;                                    /*!< 0054H */
    union {
        __IO  uint32_t  V32;                                /*!< 0058H */
        struct {
            __IO  uint32_t  TK0       : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TK1       : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  TK2       : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  TK3       : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  TK4       : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  TK5       : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  TK6       : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  TK7       : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  TK8       : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  TK9       : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  TK10      : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  TK11      : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  TK12      : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  TK13      : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  TK14      : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  TK15      : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  TK16      : 1;  /*!< [b16~b16]*/
            __IO  uint32_t  TK17      : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  TK18      : 1;  /*!< [b18~b18]*/
            __IO  uint32_t  TK19      : 1;  /*!< [b19~b19]*/
            __IO  uint32_t  TK20      : 1;  /*!< [b20~b20]*/
            __IO  uint32_t  TK21      : 1;  /*!< [b21~b21]*/
            __IO  uint32_t  TK22      : 1;  /*!< [b22~b22]*/
            __IO  uint32_t  TK23      : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  TK24      : 1;  /*!< [b24~b24]*/
            __IO  uint32_t  TK25      : 1;  /*!< [b25~b25]*/
            __IO  uint32_t  TK26      : 1;  /*!< [b26~b26]*/
            __IO  uint32_t  TK27      : 1;  /*!< [b27~b27]*/
            __IO  uint32_t  TK28      : 1;  /*!< [b28~b28]*/
            __IO  uint32_t  TK29      : 1;  /*!< [b29~b29]*/
            __IO  uint32_t  TK30      : 1;  /*!< [b30~b30]*/
            __IO  uint32_t  TK31      : 1;  /*!< [b31~b31]*/
        }BIT;
    }TKU;                               /*!< 0058H */
    union {
        __I   uint32_t  V32;                                /*!< 005CH */
        struct {
            __I   uint32_t  TKD00     :10;  /*!< [b9~b0]*/
            __IO  uint32_t  rev0      : 6;  /*!< [b15~b10]*/
            __I   uint32_t  TKD01     :10;  /*!< [b25~b16]*/
            __IO  uint32_t  rev1      : 6;  /*!< [b31~b26]*/
        }BIT;
    }TD0;                               /*!< 005CH */
    union {
        __I   uint32_t  V32;                                /*!< 0060H */
        struct {
            __I   uint32_t  TKD02     :10;  /*!< [b9~b0]*/
            __IO  uint32_t  rev0      : 6;  /*!< [b15~b10]*/
            __I   uint32_t  TKD03     :10;  /*!< [b25~b16]*/
            __IO  uint32_t  rev1      : 6;  /*!< [b31~b26]*/
        }BIT;
    }TD1;                               /*!< 0060H */
    union {
        __I   uint32_t  V32;                                /*!< 0064H */
        struct {
            __I   uint32_t  TKD04     :10;  /*!< [b9~b0]*/
            __IO  uint32_t  rev0      : 6;  /*!< [b15~b10]*/
            __I   uint32_t  TKD05     :10;  /*!< [b25~b16]*/
            __IO  uint32_t  rev1      : 6;  /*!< [b31~b26]*/
        }BIT;
    }TD2;                               /*!< 0064H */
    union {
        __I   uint32_t  V32;                                /*!< 0068H */
        struct {
            __I   uint32_t  TKD06     :10;  /*!< [b9~b0]*/
            __IO  uint32_t  rev0      : 6;  /*!< [b15~b10]*/
            __I   uint32_t  TKD07     :10;  /*!< [b25~b16]*/
            __IO  uint32_t  rev1      : 6;  /*!< [b31~b26]*/
        }BIT;
    }TD3;                               /*!< 0068H */
    union {
        __I   uint32_t  V32;                                /*!< 006CH */
        struct {
            __I   uint32_t  TKD08     :10;  /*!< [b9~b0]*/
            __IO  uint32_t  rev0      : 6;  /*!< [b15~b10]*/
            __I   uint32_t  TKD09     :10;  /*!< [b25~b16]*/
            __IO  uint32_t  rev1      : 6;  /*!< [b31~b26]*/
        }BIT;
    }TD4;                               /*!< 006CH */
    union {
        __I   uint32_t  V32;                                /*!< 0070H */
        struct {
            __I   uint32_t  TKD10     :10;  /*!< [b9~b0]*/
            __IO  uint32_t  rev0      : 6;  /*!< [b15~b10]*/
            __I   uint32_t  TKD11     :10;  /*!< [b25~b16]*/
            __IO  uint32_t  rev1      : 6;  /*!< [b31~b26]*/
        }BIT;
    }TD5;                               /*!< 0070H */
    union {
        __I   uint32_t  V32;                                /*!< 0074H */
        struct {
            __I   uint32_t  TKD12     :10;  /*!< [b9~b0]*/
            __IO  uint32_t  rev0      : 6;  /*!< [b15~b10]*/
            __I   uint32_t  TKD13     :10;  /*!< [b25~b16]*/
            __IO  uint32_t  rev1      : 6;  /*!< [b31~b26]*/
        }BIT;
    }TD6;                               /*!< 0074H */
    union {
        __I   uint32_t  V32;                                /*!< 0078H */
        struct {
            __I   uint32_t  TKD14     :10;  /*!< [b9~b0]*/
            __IO  uint32_t  rev0      : 6;  /*!< [b15~b10]*/
            __I   uint32_t  TKD15     :10;  /*!< [b25~b16]*/
            __IO  uint32_t  rev1      : 6;  /*!< [b31~b26]*/
        }BIT;
    }TD7;                               /*!< 0078H */
    union {
        __I   uint32_t  V32;                                /*!< 007CH */
        struct {
            __I   uint32_t  TKD16     :10;  /*!< [b9~b0]*/
            __IO  uint32_t  rev0      : 6;  /*!< [b15~b10]*/
            __I   uint32_t  TKD17     :10;  /*!< [b25~b16]*/
            __IO  uint32_t  rev1      : 6;  /*!< [b31~b26]*/
        }BIT;
    }TD8;                               /*!< 007CH */
    union {
        __I   uint32_t  V32;                                /*!< 0080H */
        struct {
            __I   uint32_t  TKD18     :10;  /*!< [b9~b0]*/
            __IO  uint32_t  rev0      : 6;  /*!< [b15~b10]*/
            __I   uint32_t  TKD19     :10;  /*!< [b25~b16]*/
            __IO  uint32_t  rev1      : 6;  /*!< [b31~b26]*/
        }BIT;
    }TD9;                               /*!< 0080H */
    union {
        __I   uint32_t  V32;                                /*!< 0084H */
        struct {
            __I   uint32_t  TKD20     :10;  /*!< [b9~b0]*/
            __IO  uint32_t  rev0      : 6;  /*!< [b15~b10]*/
            __I   uint32_t  TKD21     :10;  /*!< [b25~b16]*/
            __IO  uint32_t  rev1      : 6;  /*!< [b31~b26]*/
        }BIT;
    }TD10;                               /*!< 0084H */
    union {
        __I   uint32_t  V32;                                /*!< 0088H */
        struct {
            __I   uint32_t  TKD22     :10;  /*!< [b9~b0]*/
            __IO  uint32_t  rev0      : 6;  /*!< [b15~b10]*/
            __I   uint32_t  TKD23     :10;  /*!< [b25~b16]*/
            __IO  uint32_t  rev1      : 6;  /*!< [b31~b26]*/
        }BIT;
    }TD11;                               /*!< 0088H */
    union {
        __I   uint32_t  V32;                                /*!< 008CH */
        struct {
            __I   uint32_t  TKD24     :10;  /*!< [b9~b0]*/
            __IO  uint32_t  rev0      : 6;  /*!< [b15~b10]*/
            __I   uint32_t  TKD25     :10;  /*!< [b25~b16]*/
            __IO  uint32_t  rev1      : 6;  /*!< [b31~b26]*/
        }BIT;
    }TD12;                               /*!< 008CH */
    union {
        __I   uint32_t  V32;                                /*!< 0090H */
        struct {
            __I   uint32_t  TKD26     :10;  /*!< [b9~b0]*/
            __IO  uint32_t  rev0      : 6;  /*!< [b15~b10]*/
            __I   uint32_t  TKD27     :10;  /*!< [b25~b16]*/
            __IO  uint32_t  rev1      : 6;  /*!< [b31~b26]*/
        }BIT;
    }TD13;                               /*!< 0090H */
    union {
        __I   uint32_t  V32;                                /*!< 0094H */
        struct {
            __I   uint32_t  TKD28     :10;  /*!< [b9~b0]*/
            __IO  uint32_t  rev0      : 6;  /*!< [b15~b10]*/
            __I   uint32_t  TKD29     :10;  /*!< [b25~b16]*/
            __IO  uint32_t  rev1      : 6;  /*!< [b31~b26]*/
        }BIT;
    }TD14;                               /*!< 0094H */
    union {
        __I   uint32_t  V32;                                /*!< 0098H */
        struct {
            __I   uint32_t  TKD30     :10;  /*!< [b9~b0]*/
            __IO  uint32_t  rev0      : 6;  /*!< [b15~b10]*/
            __I   uint32_t  TKD31     :10;  /*!< [b25~b16]*/
            __IO  uint32_t  rev1      : 6;  /*!< [b31~b26]*/
        }BIT;
    }TD15;                               /*!< 0098H */
    __I  uint32_t  TD16;                                    /*!< 009CH */
}TOUCHKEY_TypeDef;


/* @addtogroup  Peripheral base address*/

#define TIM0_BASE                      ((uint32_t)0x40000400)    /* Bus:APB0        Module:TIMER16    */
#define TIM1_BASE                      ((uint32_t)0x40000800)    /* Bus:APB0        Module:TIMER16    */
#define TIM2_BASE                      ((uint32_t)0x40000C00)    /* Bus:APB0        Module:TIMER16    */
#define TIM3_BASE                      ((uint32_t)0x40001000)    /* Bus:APB0        Module:TIMER32    */
#define PWM0_BASE                      ((uint32_t)0x40001400)    /* Bus:APB0        Module:PWM        */
#define PWM1_BASE                      ((uint32_t)0x40001800)    /* Bus:APB0        Module:PWM        */
#define PWM2_BASE                      ((uint32_t)0x40001C00)    /* Bus:APB0        Module:PWM        */
#define PWM3_BASE                      ((uint32_t)0x40002000)    /* Bus:APB0        Module:PWM        */
#define PCA0_BASE                      ((uint32_t)0x40002400)    /* Bus:APB0        Module:PCA        */
#define PCA1_BASE                      ((uint32_t)0x40002800)    /* Bus:APB0        Module:PCA        */
#define PCA2_BASE                      ((uint32_t)0x40002C00)    /* Bus:APB0        Module:PCA        */
#define PCA3_BASE                      ((uint32_t)0x40003000)    /* Bus:APB0        Module:PCA        */
#define EXTI_BASE                      ((uint32_t)0x40003400)    /* Bus:APB0        Module:EXTI       */
#define IWDT_BASE                      ((uint32_t)0x40003800)    /* Bus:APB0        Module:IWDT       */
#define WWDT_BASE                      ((uint32_t)0x40003C00)    /* Bus:APB0        Module:WWDT       */
#define ADC_BASE                       ((uint32_t)0x40004000)    /* Bus:APB0        Module:ADC        */
#define UART0_BASE                     ((uint32_t)0x40020000)    /* Bus:APB1        Module:UART       */
#define UART1_BASE                     ((uint32_t)0x40020400)    /* Bus:APB1        Module:UART       */
#define UART2_BASE                     ((uint32_t)0x40020800)    /* Bus:APB1        Module:UART       */
#define UART3_BASE                     ((uint32_t)0x40020C00)    /* Bus:APB1        Module:UART       */
#define SPI0_BASE                      ((uint32_t)0x40021000)    /* Bus:APB1        Module:SPI        */
#define SPI1_BASE                      ((uint32_t)0x40021400)    /* Bus:APB1        Module:SPI        */
#define TWI0_BASE                      ((uint32_t)0x40021800)    /* Bus:APB1        Module:TWI        */
#define LED_BASE                       ((uint32_t)0x40021C00)    /* Bus:APB1        Module:LED        */
#define LCD_BASE                       ((uint32_t)0x40022000)    /* Bus:APB1        Module:LCD        */
#define TOUCHKEY_BASE                  ((uint32_t)0x40022400)    /* Bus:APB1        Module:TOUCHKEY   */
#define HLV_BASE                       ((uint32_t)0x40022800)    /* Bus:APB1        Module:HLV        */
#define GPIOA_BASE                     ((uint32_t)0x40040000)    /* Bus:AHB         Module:GPIO       */
#define GPIOB_BASE                     ((uint32_t)0x40040080)    /* Bus:AHB         Module:GPIO       */
#define GPIOC_BASE                     ((uint32_t)0x40040100)    /* Bus:AHB         Module:GPIO       */
#define GPIOD_BASE                     ((uint32_t)0x40040180)    /* Bus:AHB         Module:GPIO       */
#define SYSCFG_BASE                    ((uint32_t)0x40040400)    /* Bus:AHB         Module:SYSCFG     */
#define RCC_BASE                       ((uint32_t)0x40040800)    /* Bus:AHB         Module:RCC        */
#define FLASH_BASE                     ((uint32_t)0x40040C00)    /* Bus:AHB         Module:FLASH      */
#define CRC_BASE                       ((uint32_t)0x40041000)    /* Bus:AHB         Module:CRC        */
#define RAMBIST_BASE                   ((uint32_t)0x40041400)    /* Bus:AHB         Module:RAMBIST    */
#define DMA_BASE                       ((uint32_t)0x40041800)    /* Bus:AHB         Module:DMA        */

/* @addtogroup Peripheral_declaration */

#define FLASH                ((FLASH_TypeDef *)       FLASH_BASE)
#define RCC                  ((RCC_TypeDef *)         RCC_BASE)
#define IWDT                 ((IWDT_TypeDef *)        IWDT_BASE)
#define WWDT                 ((WWDT_TypeDef *)        WWDT_BASE)
#define CRC                  ((CRC_TypeDef *)         CRC_BASE)
#define RAMBIST              ((RAMBIST_TypeDef *)     RAMBIST_BASE)
#define GPIOA                ((GPIO_TypeDef *)        GPIOA_BASE)
#define GPIOB                ((GPIO_TypeDef *)        GPIOB_BASE)
#define GPIOC                ((GPIO_TypeDef *)        GPIOC_BASE)
#define GPIOD                ((GPIO_TypeDef *)        GPIOD_BASE)
#define SYSCFG               ((SYSCFG_TypeDef *)      SYSCFG_BASE)
#define EXTI                 ((EXTI_TypeDef *)        EXTI_BASE)
#define DMA                  ((DMA_TypeDef *)         DMA_BASE)
#define LED                  ((LED_TypeDef *)         LED_BASE)
#define LCD                  ((LCD_TypeDef *)         LCD_BASE)
#define TIM0                 ((TIMER16_TypeDef *)     TIM0_BASE)
#define TIM1                 ((TIMER16_TypeDef *)     TIM1_BASE)
#define TIM2                 ((TIMER16_TypeDef *)     TIM2_BASE)
#define TIM3                 ((TIMER32_TypeDef *)     TIM3_BASE)
#define PWM0                 ((PWM_TypeDef *)         PWM0_BASE)
#define PWM1                 ((PWM_TypeDef *)         PWM1_BASE)
#define PWM2                 ((PWM_TypeDef *)         PWM2_BASE)
#define PWM3                 ((PWM_TypeDef *)         PWM3_BASE)
#define PCA0                 ((PCA_TypeDef *)         PCA0_BASE)
#define PCA1                 ((PCA_TypeDef *)         PCA1_BASE)
#define PCA2                 ((PCA_TypeDef *)         PCA2_BASE)
#define PCA3                 ((PCA_TypeDef *)         PCA3_BASE)
#define UART0                ((UART_TypeDef *)        UART0_BASE)
#define UART1                ((UART_TypeDef *)        UART1_BASE)
#define UART2                ((UART_TypeDef *)        UART2_BASE)
#define UART3                ((UART_TypeDef *)        UART3_BASE)
#define SPI0                 ((SPI_TypeDef *)         SPI0_BASE)
#define SPI1                 ((SPI_TypeDef *)         SPI1_BASE)
#define TWI0                 ((TWI_TypeDef *)         TWI0_BASE)
#define ADC                  ((ADC_TypeDef *)         ADC_BASE)
#define HLV                  ((HLV_TypeDef *)         HLV_BASE)
#define TOUCHKEY             ((TOUCHKEY_TypeDef *)    TOUCHKEY_BASE)

/* @addtogroup Peripheral Field Postion and mask */

#define FLASH_ACR_LATENCY_Pos        0                                            /*!<FLASH ACR: LATENCY Position */
#define FLASH_ACR_LATENCY_Msk        (0x3UL /*<< FLASH_ACR_LATENCY_Pos*/)         /*!<FLASH ACR: LATENCY Mask */

#define FLASH_ACR_PRFTEN_Pos         8                                            /*!<FLASH ACR: PRFTEN Position */
#define FLASH_ACR_PRFTEN_Msk         (0x1UL << FLASH_ACR_PRFTEN_Pos)              /*!<FLASH ACR: PRFTEN Mask */

#define FLASH_ACR_CRST_Pos           11                                           /*!<FLASH ACR: CRST Position */
#define FLASH_ACR_CRST_Msk           (0x1UL << FLASH_ACR_CRST_Pos)                /*!<FLASH ACR: CRST Mask */

#define FLASH_ACR_LOCK_Pos           16                                           /*!<FLASH ACR: LOCK Position */
#define FLASH_ACR_LOCK_Msk           (0xFFFFUL << FLASH_ACR_LOCK_Pos)             /*!<FLASH ACR: LOCK Mask */

#define FLASH_ACR_Msk_ALL            (FLASH_ACR_LATENCY_Msk        |\
                                      FLASH_ACR_PRFTEN_Msk         |\
                                      FLASH_ACR_CRST_Msk           |\
                                      FLASH_ACR_LOCK_Msk           )

#define FLASH_SR_EOP_Pos             0                                            /*!<FLASH SR: EOP Position */
#define FLASH_SR_EOP_Msk             (0x1UL /*<< FLASH_SR_EOP_Pos*/)              /*!<FLASH SR: EOP Mask */

#define FLASH_SR_OPERR_Pos           1                                            /*!<FLASH SR: OPERR Position */
#define FLASH_SR_OPERR_Msk           (0x1UL << FLASH_SR_OPERR_Pos)                /*!<FLASH SR: OPERR Mask */

#define FLASH_SR_FLSERR_Pos          3                                            /*!<FLASH SR: FLSERR Position */
#define FLASH_SR_FLSERR_Msk          (0x1UL << FLASH_SR_FLSERR_Pos)               /*!<FLASH SR: FLSERR Mask */

#define FLASH_SR_WRPRTERR_Pos        4                                            /*!<FLASH SR: WRPRTERR Position */
#define FLASH_SR_WRPRTERR_Msk        (0x1UL << FLASH_SR_WRPRTERR_Pos)             /*!<FLASH SR: WRPRTERR Mask */

#define FLASH_SR_PGPERR_Pos          5                                            /*!<FLASH SR: PGPERR Position */
#define FLASH_SR_PGPERR_Msk          (0x1UL << FLASH_SR_PGPERR_Pos)               /*!<FLASH SR: PGPERR Mask */

#define FLASH_SR_PGWERR_Pos          6                                            /*!<FLASH SR: PGWERR Position */
#define FLASH_SR_PGWERR_Msk          (0x1UL << FLASH_SR_PGWERR_Pos)               /*!<FLASH SR: PGWERR Mask */

#define FLASH_SR_STAERR_Pos          7                                            /*!<FLASH SR: STAERR Position */
#define FLASH_SR_STAERR_Msk          (0x1UL << FLASH_SR_STAERR_Pos)               /*!<FLASH SR: STAERR Mask */

#define FLASH_SR_BSY_Pos             15                                           /*!<FLASH SR: BSY Position */
#define FLASH_SR_BSY_Msk             (0x1UL << FLASH_SR_BSY_Pos)                  /*!<FLASH SR: BSY Mask */

#define FLASH_SR_EOPC_Pos            16                                           /*!<FLASH SR: EOPC Position */
#define FLASH_SR_EOPC_Msk            (0x1UL << FLASH_SR_EOPC_Pos)                 /*!<FLASH SR: EOPC Mask */

#define FLASH_SR_OPERRC_Pos          17                                           /*!<FLASH SR: OPERRC Position */
#define FLASH_SR_OPERRC_Msk          (0x1UL << FLASH_SR_OPERRC_Pos)               /*!<FLASH SR: OPERRC Mask */

#define FLASH_SR_FLSERRC_Pos         19                                           /*!<FLASH SR: FLSERRC Position */
#define FLASH_SR_FLSERRC_Msk         (0x1UL << FLASH_SR_FLSERRC_Pos)              /*!<FLASH SR: FLSERRC Mask */

#define FLASH_SR_WRPRTERRC_Pos       20                                           /*!<FLASH SR: WRPRTERRC Position */
#define FLASH_SR_WRPRTERRC_Msk       (0x1UL << FLASH_SR_WRPRTERRC_Pos)            /*!<FLASH SR: WRPRTERRC Mask */

#define FLASH_SR_PGPERRC_Pos         21                                           /*!<FLASH SR: PGPERRC Position */
#define FLASH_SR_PGPERRC_Msk         (0x1UL << FLASH_SR_PGPERRC_Pos)              /*!<FLASH SR: PGPERRC Mask */

#define FLASH_SR_PGWERRC_Pos         22                                           /*!<FLASH SR: PGWERRC Position */
#define FLASH_SR_PGWERRC_Msk         (0x1UL << FLASH_SR_PGWERRC_Pos)              /*!<FLASH SR: PGWERRC Mask */

#define FLASH_SR_STAERRC_Pos         23                                           /*!<FLASH SR: STAERRC Position */
#define FLASH_SR_STAERRC_Msk         (0x1UL << FLASH_SR_STAERRC_Pos)              /*!<FLASH SR: STAERRC Mask */

#define FLASH_SR_Msk_ALL             (FLASH_SR_EOP_Msk             |\
                                      FLASH_SR_OPERR_Msk           |\
                                      FLASH_SR_FLSERR_Msk          |\
                                      FLASH_SR_WRPRTERR_Msk        |\
                                      FLASH_SR_PGPERR_Msk          |\
                                      FLASH_SR_PGWERR_Msk          |\
                                      FLASH_SR_STAERR_Msk          |\
                                      FLASH_SR_BSY_Msk             |\
                                      FLASH_SR_EOPC_Msk            |\
                                      FLASH_SR_OPERRC_Msk          |\
                                      FLASH_SR_FLSERRC_Msk         |\
                                      FLASH_SR_WRPRTERRC_Msk       |\
                                      FLASH_SR_PGPERRC_Msk         |\
                                      FLASH_SR_PGWERRC_Msk         |\
                                      FLASH_SR_STAERRC_Msk         )

#define FLASH_CR_STRT_Pos            8                                            /*!<FLASH CR: STRT Position */
#define FLASH_CR_STRT_Msk            (0x1UL << FLASH_CR_STRT_Pos)                 /*!<FLASH CR: STRT Mask */

#define FLASH_CR_PSIZE_Pos           10                                           /*!<FLASH CR: PSIZE Position */
#define FLASH_CR_PSIZE_Msk           (0x1UL << FLASH_CR_PSIZE_Pos)                /*!<FLASH CR: PSIZE Mask */

#define FLASH_CR_INFLCK_Pos          12                                           /*!<FLASH CR: INFLCK Position */
#define FLASH_CR_INFLCK_Msk          (0x1UL << FLASH_CR_INFLCK_Pos)               /*!<FLASH CR: INFLCK Mask */

#define FLASH_CR_E2LCK_Pos           14                                           /*!<FLASH CR: E2LCK Position */
#define FLASH_CR_E2LCK_Msk           (0x1UL << FLASH_CR_E2LCK_Pos)                /*!<FLASH CR: E2LCK Mask */

#define FLASH_CR_MNLCK_Pos           15                                           /*!<FLASH CR: MNLCK Position */
#define FLASH_CR_MNLCK_Msk           (0x1UL << FLASH_CR_MNLCK_Pos)                /*!<FLASH CR: MNLCK Mask */

#define FLASH_CR_CMD_Pos             16                                           /*!<FLASH CR: CMD Position */
#define FLASH_CR_CMD_Msk             (0xFFFFUL << FLASH_CR_CMD_Pos)               /*!<FLASH CR: CMD Mask */

#define FLASH_CR_Msk_ALL             (FLASH_CR_STRT_Msk            |\
                                      FLASH_CR_PSIZE_Msk           |\
                                      FLASH_CR_INFLCK_Msk          |\
                                      FLASH_CR_E2LCK_Msk           |\
                                      FLASH_CR_MNLCK_Msk           |\
                                      FLASH_CR_CMD_Msk             )

#define FLASH_CR1_SNB_Pos            0                                            /*!<FLASH CR1: SNB Position */
#define FLASH_CR1_SNB_Msk            (0xFFUL /*<< FLASH_CR1_SNB_Pos*/)            /*!<FLASH CR1: SNB Mask */

#define FLASH_CR1_Msk_ALL            (FLASH_CR1_SNB_Msk           )

#define FLASH_OPR_OPT0_Pos           0                                            /*!<FLASH OPR: OPT0 Position */
#define FLASH_OPR_OPT0_Msk           (0xFFUL /*<< FLASH_OPR_OPT0_Pos*/)           /*!<FLASH OPR: OPT0 Mask */

#define FLASH_OPR_OPT1_Pos           8                                            /*!<FLASH OPR: OPT1 Position */
#define FLASH_OPR_OPT1_Msk           (0xFFUL << FLASH_OPR_OPT1_Pos)               /*!<FLASH OPR: OPT1 Mask */

#define FLASH_OPR_OPT2_Pos           16                                           /*!<FLASH OPR: OPT2 Position */
#define FLASH_OPR_OPT2_Msk           (0xFFUL << FLASH_OPR_OPT2_Pos)               /*!<FLASH OPR: OPT2 Mask */

#define FLASH_OPR_OPT3_Pos           24                                           /*!<FLASH OPR: OPT3 Position */
#define FLASH_OPR_OPT3_Msk           (0xFFUL << FLASH_OPR_OPT3_Pos)               /*!<FLASH OPR: OPT3 Mask */

#define FLASH_OPR_Msk_ALL            (FLASH_OPR_OPT0_Msk           |\
                                      FLASH_OPR_OPT1_Msk           |\
                                      FLASH_OPR_OPT2_Msk           |\
                                      FLASH_OPR_OPT3_Msk           )

#define FLASH_RPR_RDP_Pos            0                                            /*!<FLASH RPR: RDP Position */
#define FLASH_RPR_RDP_Msk            (0xFFFFUL /*<< FLASH_RPR_RDP_Pos*/)          /*!<FLASH RPR: RDP Mask */

#define FLASH_RPR_Msk_ALL            (FLASH_RPR_RDP_Msk           )

#define FLASH_CNTCR_CNTEN_Pos        0                                            /*!<FLASH CNTCR: CNTEN Position */
#define FLASH_CNTCR_CNTEN_Msk        (0x1UL /*<< FLASH_CNTCR_CNTEN_Pos*/)         /*!<FLASH CNTCR: CNTEN Mask */

#define FLASH_CNTCR_Msk_ALL          (FLASH_CNTCR_CNTEN_Msk       )

#define FLASH_MEMRMP_MEMMODE_Pos     0                                            /*!<FLASH MEMRMP: MEMMODE Position */
#define FLASH_MEMRMP_MEMMODE_Msk     (0xFFFFUL /*<< FLASH_MEMRMP_MEMMODE_Pos*/)   /*!<FLASH MEMRMP: MEMMODE Mask */

#define FLASH_MEMRMP_Msk_ALL         (FLASH_MEMRMP_MEMMODE_Msk    )

#define FLASH_OPR_CUST1_OPT0_Pos     0                                            /*!<FLASH OPR_CUST1: OPT0 Position */
#define FLASH_OPR_CUST1_OPT0_Msk     (0xFFUL /*<< FLASH_OPR_CUST1_OPT0_Pos*/)     /*!<FLASH OPR_CUST1: OPT0 Mask */

#define FLASH_OPR_CUST1_OPT1_Pos     8                                            /*!<FLASH OPR_CUST1: OPT1 Position */
#define FLASH_OPR_CUST1_OPT1_Msk     (0xFFUL << FLASH_OPR_CUST1_OPT1_Pos)         /*!<FLASH OPR_CUST1: OPT1 Mask */

#define FLASH_OPR_CUST1_OPT2_Pos     16                                           /*!<FLASH OPR_CUST1: OPT2 Position */
#define FLASH_OPR_CUST1_OPT2_Msk     (0xFFUL << FLASH_OPR_CUST1_OPT2_Pos)         /*!<FLASH OPR_CUST1: OPT2 Mask */

#define FLASH_OPR_CUST1_OPT3_Pos     24                                           /*!<FLASH OPR_CUST1: OPT3 Position */
#define FLASH_OPR_CUST1_OPT3_Msk     (0xFFUL << FLASH_OPR_CUST1_OPT3_Pos)         /*!<FLASH OPR_CUST1: OPT3 Mask */

#define FLASH_OPR_CUST1_Msk_ALL      (FLASH_OPR_CUST1_OPT0_Msk     |\
                                      FLASH_OPR_CUST1_OPT1_Msk     |\
                                      FLASH_OPR_CUST1_OPT2_Msk     |\
                                      FLASH_OPR_CUST1_OPT3_Msk     )

#define FLASH_OPR_DESI0_OPT0_Pos     0                                            /*!<FLASH OPR_DESI0: OPT0 Position */
#define FLASH_OPR_DESI0_OPT0_Msk     (0xFFUL /*<< FLASH_OPR_DESI0_OPT0_Pos*/)     /*!<FLASH OPR_DESI0: OPT0 Mask */

#define FLASH_OPR_DESI0_OPT1_Pos     8                                            /*!<FLASH OPR_DESI0: OPT1 Position */
#define FLASH_OPR_DESI0_OPT1_Msk     (0xFFUL << FLASH_OPR_DESI0_OPT1_Pos)         /*!<FLASH OPR_DESI0: OPT1 Mask */

#define FLASH_OPR_DESI0_OPT2_Pos     16                                           /*!<FLASH OPR_DESI0: OPT2 Position */
#define FLASH_OPR_DESI0_OPT2_Msk     (0xFFUL << FLASH_OPR_DESI0_OPT2_Pos)         /*!<FLASH OPR_DESI0: OPT2 Mask */

#define FLASH_OPR_DESI0_OPT3_Pos     24                                           /*!<FLASH OPR_DESI0: OPT3 Position */
#define FLASH_OPR_DESI0_OPT3_Msk     (0xFFUL << FLASH_OPR_DESI0_OPT3_Pos)         /*!<FLASH OPR_DESI0: OPT3 Mask */

#define FLASH_OPR_DESI0_Msk_ALL      (FLASH_OPR_DESI0_OPT0_Msk     |\
                                      FLASH_OPR_DESI0_OPT1_Msk     |\
                                      FLASH_OPR_DESI0_OPT2_Msk     |\
                                      FLASH_OPR_DESI0_OPT3_Msk     )

#define FLASH_OPR_DESI1_OPT0_Pos     0                                            /*!<FLASH OPR_DESI1: OPT0 Position */
#define FLASH_OPR_DESI1_OPT0_Msk     (0xFFUL /*<< FLASH_OPR_DESI1_OPT0_Pos*/)     /*!<FLASH OPR_DESI1: OPT0 Mask */

#define FLASH_OPR_DESI1_OPT1_Pos     8                                            /*!<FLASH OPR_DESI1: OPT1 Position */
#define FLASH_OPR_DESI1_OPT1_Msk     (0xFFUL << FLASH_OPR_DESI1_OPT1_Pos)         /*!<FLASH OPR_DESI1: OPT1 Mask */

#define FLASH_OPR_DESI1_OPT2_Pos     16                                           /*!<FLASH OPR_DESI1: OPT2 Position */
#define FLASH_OPR_DESI1_OPT2_Msk     (0xFFUL << FLASH_OPR_DESI1_OPT2_Pos)         /*!<FLASH OPR_DESI1: OPT2 Mask */

#define FLASH_OPR_DESI1_OPT3_Pos     24                                           /*!<FLASH OPR_DESI1: OPT3 Position */
#define FLASH_OPR_DESI1_OPT3_Msk     (0xFFUL << FLASH_OPR_DESI1_OPT3_Pos)         /*!<FLASH OPR_DESI1: OPT3 Mask */

#define FLASH_OPR_DESI1_Msk_ALL      (FLASH_OPR_DESI1_OPT0_Msk     |\
                                      FLASH_OPR_DESI1_OPT1_Msk     |\
                                      FLASH_OPR_DESI1_OPT2_Msk     |\
                                      FLASH_OPR_DESI1_OPT3_Msk     )

#define FLASH_OPR_DESI2_OPT0_Pos     0                                            /*!<FLASH OPR_DESI2: OPT0 Position */
#define FLASH_OPR_DESI2_OPT0_Msk     (0xFFUL /*<< FLASH_OPR_DESI2_OPT0_Pos*/)     /*!<FLASH OPR_DESI2: OPT0 Mask */

#define FLASH_OPR_DESI2_OPT1_Pos     8                                            /*!<FLASH OPR_DESI2: OPT1 Position */
#define FLASH_OPR_DESI2_OPT1_Msk     (0xFFUL << FLASH_OPR_DESI2_OPT1_Pos)         /*!<FLASH OPR_DESI2: OPT1 Mask */

#define FLASH_OPR_DESI2_OPT2_Pos     16                                           /*!<FLASH OPR_DESI2: OPT2 Position */
#define FLASH_OPR_DESI2_OPT2_Msk     (0xFFUL << FLASH_OPR_DESI2_OPT2_Pos)         /*!<FLASH OPR_DESI2: OPT2 Mask */

#define FLASH_OPR_DESI2_OPT3_Pos     24                                           /*!<FLASH OPR_DESI2: OPT3 Position */
#define FLASH_OPR_DESI2_OPT3_Msk     (0xFFUL << FLASH_OPR_DESI2_OPT3_Pos)         /*!<FLASH OPR_DESI2: OPT3 Mask */

#define FLASH_OPR_DESI2_Msk_ALL      (FLASH_OPR_DESI2_OPT0_Msk     |\
                                      FLASH_OPR_DESI2_OPT1_Msk     |\
                                      FLASH_OPR_DESI2_OPT2_Msk     |\
                                      FLASH_OPR_DESI2_OPT3_Msk     )

#define FLASH_OPR_DESI3_OPT0_Pos     0                                            /*!<FLASH OPR_DESI3: OPT0 Position */
#define FLASH_OPR_DESI3_OPT0_Msk     (0xFFUL /*<< FLASH_OPR_DESI3_OPT0_Pos*/)     /*!<FLASH OPR_DESI3: OPT0 Mask */

#define FLASH_OPR_DESI3_OPT1_Pos     8                                            /*!<FLASH OPR_DESI3: OPT1 Position */
#define FLASH_OPR_DESI3_OPT1_Msk     (0xFFUL << FLASH_OPR_DESI3_OPT1_Pos)         /*!<FLASH OPR_DESI3: OPT1 Mask */

#define FLASH_OPR_DESI3_OPT2_Pos     16                                           /*!<FLASH OPR_DESI3: OPT2 Position */
#define FLASH_OPR_DESI3_OPT2_Msk     (0xFFUL << FLASH_OPR_DESI3_OPT2_Pos)         /*!<FLASH OPR_DESI3: OPT2 Mask */

#define FLASH_OPR_DESI3_OPT3_Pos     24                                           /*!<FLASH OPR_DESI3: OPT3 Position */
#define FLASH_OPR_DESI3_OPT3_Msk     (0xFFUL << FLASH_OPR_DESI3_OPT3_Pos)         /*!<FLASH OPR_DESI3: OPT3 Mask */

#define FLASH_OPR_DESI3_Msk_ALL      (FLASH_OPR_DESI3_OPT0_Msk     |\
                                      FLASH_OPR_DESI3_OPT1_Msk     |\
                                      FLASH_OPR_DESI3_OPT2_Msk     |\
                                      FLASH_OPR_DESI3_OPT3_Msk     )

#define RCC_CR_SW_Pos                0                                            /*!<RCC CR: SW Position */
#define RCC_CR_SW_Msk                (0x7UL /*<< RCC_CR_SW_Pos*/)                 /*!<RCC CR: SW Mask */

#define RCC_CR_SWS_Pos               3                                            /*!<RCC CR: SWS Position */
#define RCC_CR_SWS_Msk               (0x7UL << RCC_CR_SWS_Pos)                    /*!<RCC CR: SWS Mask */

#define RCC_CR_CSMON_Pos             6                                            /*!<RCC CR: CSMON Position */
#define RCC_CR_CSMON_Msk             (0x1UL << RCC_CR_CSMON_Pos)                  /*!<RCC CR: CSMON Mask */

#define RCC_CR_PLLON_Pos             7                                            /*!<RCC CR: PLLON Position */
#define RCC_CR_PLLON_Msk             (0x1UL << RCC_CR_PLLON_Pos)                  /*!<RCC CR: PLLON Mask */

#define RCC_CR_PLLRDY_Pos            8                                            /*!<RCC CR: PLLRDY Position */
#define RCC_CR_PLLRDY_Msk            (0x1UL << RCC_CR_PLLRDY_Pos)                 /*!<RCC CR: PLLRDY Mask */

#define RCC_CR_HSEON_Pos             9                                            /*!<RCC CR: HSEON Position */
#define RCC_CR_HSEON_Msk             (0x1UL << RCC_CR_HSEON_Pos)                  /*!<RCC CR: HSEON Mask */

#define RCC_CR_HSERDY_Pos            10                                           /*!<RCC CR: HSERDY Position */
#define RCC_CR_HSERDY_Msk            (0x1UL << RCC_CR_HSERDY_Pos)                 /*!<RCC CR: HSERDY Mask */

#define RCC_CR_LSEON_Pos             11                                           /*!<RCC CR: LSEON Position */
#define RCC_CR_LSEON_Msk             (0x1UL << RCC_CR_LSEON_Pos)                  /*!<RCC CR: LSEON Mask */

#define RCC_CR_LSERDY_Pos            12                                           /*!<RCC CR: LSERDY Position */
#define RCC_CR_LSERDY_Msk            (0x1UL << RCC_CR_LSERDY_Pos)                 /*!<RCC CR: LSERDY Mask */

#define RCC_CR_HSION_Pos             13                                           /*!<RCC CR: HSION Position */
#define RCC_CR_HSION_Msk             (0x1UL << RCC_CR_HSION_Pos)                  /*!<RCC CR: HSION Mask */

#define RCC_CR_HSIRDY_Pos            14                                           /*!<RCC CR: HSIRDY Position */
#define RCC_CR_HSIRDY_Msk            (0x1UL << RCC_CR_HSIRDY_Pos)                 /*!<RCC CR: HSIRDY Mask */

#define RCC_CR_LSION_Pos             15                                           /*!<RCC CR: LSION Position */
#define RCC_CR_LSION_Msk             (0x1UL << RCC_CR_LSION_Pos)                  /*!<RCC CR: LSION Mask */

#define RCC_CR_LSIRDY_Pos            16                                           /*!<RCC CR: LSIRDY Position */
#define RCC_CR_LSIRDY_Msk            (0x1UL << RCC_CR_LSIRDY_Pos)                 /*!<RCC CR: LSIRDY Mask */

#define RCC_CR_ESTCK_Pos             17                                           /*!<RCC CR: ESTCK Position */
#define RCC_CR_ESTCK_Msk             (0x1UL << RCC_CR_ESTCK_Pos)                  /*!<RCC CR: ESTCK Mask */

#define RCC_CR_Msk_ALL               (RCC_CR_SW_Msk                |\
                                      RCC_CR_SWS_Msk               |\
                                      RCC_CR_CSMON_Msk             |\
                                      RCC_CR_PLLON_Msk             |\
                                      RCC_CR_PLLRDY_Msk            |\
                                      RCC_CR_HSEON_Msk             |\
                                      RCC_CR_HSERDY_Msk            |\
                                      RCC_CR_LSEON_Msk             |\
                                      RCC_CR_LSERDY_Msk            |\
                                      RCC_CR_HSION_Msk             |\
                                      RCC_CR_HSIRDY_Msk            |\
                                      RCC_CR_LSION_Msk             |\
                                      RCC_CR_LSIRDY_Msk            |\
                                      RCC_CR_ESTCK_Msk             )

#define RCC_CFGR_HPRE_Pos            0                                            /*!<RCC CFGR: HPRE Position */
#define RCC_CFGR_HPRE_Msk            (0x7UL /*<< RCC_CFGR_HPRE_Pos*/)             /*!<RCC CFGR: HPRE Mask */

#define RCC_CFGR_PPRE0_Pos           3                                            /*!<RCC CFGR: PPRE0 Position */
#define RCC_CFGR_PPRE0_Msk           (0x7UL << RCC_CFGR_PPRE0_Pos)                /*!<RCC CFGR: PPRE0 Mask */

#define RCC_CFGR_PPRE1_Pos           6                                            /*!<RCC CFGR: PPRE1 Position */
#define RCC_CFGR_PPRE1_Msk           (0x7UL << RCC_CFGR_PPRE1_Pos)                /*!<RCC CFGR: PPRE1 Mask */

#define RCC_CFGR_PLLK_Pos            10                                           /*!<RCC CFGR: PLLK Position */
#define RCC_CFGR_PLLK_Msk            (0x7UL << RCC_CFGR_PLLK_Pos)                 /*!<RCC CFGR: PLLK Mask */

#define RCC_CFGR_PLLF_Pos            13                                           /*!<RCC CFGR: PLLF Position */
#define RCC_CFGR_PLLF_Msk            (0x1FUL << RCC_CFGR_PLLF_Pos)                /*!<RCC CFGR: PLLF Mask */

#define RCC_CFGR_PLLSRC_Pos          19                                           /*!<RCC CFGR: PLLSRC Position */
#define RCC_CFGR_PLLSRC_Msk          (0x1UL << RCC_CFGR_PLLSRC_Pos)               /*!<RCC CFGR: PLLSRC Mask */

#define RCC_CFGR_PLLXTPRE_Pos        20                                           /*!<RCC CFGR: PLLXTPRE Position */
#define RCC_CFGR_PLLXTPRE_Msk        (0x3UL << RCC_CFGR_PLLXTPRE_Pos)             /*!<RCC CFGR: PLLXTPRE Mask */

#define RCC_CFGR_CRY32SPDUP_Pos      22                                           /*!<RCC CFGR: CRY32SPDUP Position */
#define RCC_CFGR_CRY32SPDUP_Msk      (0x1UL << RCC_CFGR_CRY32SPDUP_Pos)           /*!<RCC CFGR: CRY32SPDUP Mask */

#define RCC_CFGR_CRY32NOISEEN_Pos    23                                           /*!<RCC CFGR: CRY32NOISEEN Position */
#define RCC_CFGR_CRY32NOISEEN_Msk    (0x1UL << RCC_CFGR_CRY32NOISEEN_Pos)         /*!<RCC CFGR: CRY32NOISEEN Mask */

#define RCC_CFGR_HSIENREC_Pos        24                                           /*!<RCC CFGR: HSIENREC Position */
#define RCC_CFGR_HSIENREC_Msk        (0x1UL << RCC_CFGR_HSIENREC_Pos)             /*!<RCC CFGR: HSIENREC Mask */

#define RCC_CFGR_HSESEL_Pos          25                                           /*!<RCC CFGR: HSESEL Position */
#define RCC_CFGR_HSESEL_Msk          (0x3UL << RCC_CFGR_HSESEL_Pos)               /*!<RCC CFGR: HSESEL Mask */

#define RCC_CFGR_Msk_ALL             (RCC_CFGR_HPRE_Msk            |\
                                      RCC_CFGR_PPRE0_Msk           |\
                                      RCC_CFGR_PPRE1_Msk           |\
                                      RCC_CFGR_PLLK_Msk            |\
                                      RCC_CFGR_PLLF_Msk            |\
                                      RCC_CFGR_PLLSRC_Msk          |\
                                      RCC_CFGR_PLLXTPRE_Msk        |\
                                      RCC_CFGR_CRY32SPDUP_Msk      |\
                                      RCC_CFGR_CRY32NOISEEN_Msk    |\
                                      RCC_CFGR_HSIENREC_Msk        |\
                                      RCC_CFGR_HSESEL_Msk          )

#define RCC_CIENR_LSERDYIE_Pos       2                                            /*!<RCC CIENR: LSERDYIE Position */
#define RCC_CIENR_LSERDYIE_Msk       (0x1UL << RCC_CIENR_LSERDYIE_Pos)            /*!<RCC CIENR: LSERDYIE Mask */

#define RCC_CIENR_HSERDYIE_Pos       3                                            /*!<RCC CIENR: HSERDYIE Position */
#define RCC_CIENR_HSERDYIE_Msk       (0x1UL << RCC_CIENR_HSERDYIE_Pos)            /*!<RCC CIENR: HSERDYIE Mask */

#define RCC_CIENR_PLLRDYIE_Pos       4                                            /*!<RCC CIENR: PLLRDYIE Position */
#define RCC_CIENR_PLLRDYIE_Msk       (0x1UL << RCC_CIENR_PLLRDYIE_Pos)            /*!<RCC CIENR: PLLRDYIE Mask */

#define RCC_CIENR_Msk_ALL            (RCC_CIENR_LSERDYIE_Msk       |\
                                      RCC_CIENR_HSERDYIE_Msk       |\
                                      RCC_CIENR_PLLRDYIE_Msk       )

#define RCC_CISTR_LSERDYIF_Pos       2                                            /*!<RCC CISTR: LSERDYIF Position */
#define RCC_CISTR_LSERDYIF_Msk       (0x1UL << RCC_CISTR_LSERDYIF_Pos)            /*!<RCC CISTR: LSERDYIF Mask */

#define RCC_CISTR_HSERDYIF_Pos       3                                            /*!<RCC CISTR: HSERDYIF Position */
#define RCC_CISTR_HSERDYIF_Msk       (0x1UL << RCC_CISTR_HSERDYIF_Pos)            /*!<RCC CISTR: HSERDYIF Mask */

#define RCC_CISTR_PLLRDYIF_Pos       4                                            /*!<RCC CISTR: PLLRDYIF Position */
#define RCC_CISTR_PLLRDYIF_Msk       (0x1UL << RCC_CISTR_PLLRDYIF_Pos)            /*!<RCC CISTR: PLLRDYIF Mask */

#define RCC_CISTR_LSECSMF_Pos        5                                            /*!<RCC CISTR: LSECSMF Position */
#define RCC_CISTR_LSECSMF_Msk        (0x1UL << RCC_CISTR_LSECSMF_Pos)             /*!<RCC CISTR: LSECSMF Mask */

#define RCC_CISTR_HSECSMF_Pos        6                                            /*!<RCC CISTR: HSECSMF Position */
#define RCC_CISTR_HSECSMF_Msk        (0x1UL << RCC_CISTR_HSECSMF_Pos)             /*!<RCC CISTR: HSECSMF Mask */

#define RCC_CISTR_PLLCSMF_Pos        7                                            /*!<RCC CISTR: PLLCSMF Position */
#define RCC_CISTR_PLLCSMF_Msk        (0x1UL << RCC_CISTR_PLLCSMF_Pos)             /*!<RCC CISTR: PLLCSMF Mask */

#define RCC_CISTR_Msk_ALL            (RCC_CISTR_LSERDYIF_Msk       |\
                                      RCC_CISTR_HSERDYIF_Msk       |\
                                      RCC_CISTR_PLLRDYIF_Msk       |\
                                      RCC_CISTR_LSECSMF_Msk        |\
                                      RCC_CISTR_HSECSMF_Msk        |\
                                      RCC_CISTR_PLLCSMF_Msk        )

#define RCC_CICLR_LSERDYC_Pos        2                                            /*!<RCC CICLR: LSERDYC Position */
#define RCC_CICLR_LSERDYC_Msk        (0x1UL << RCC_CICLR_LSERDYC_Pos)             /*!<RCC CICLR: LSERDYC Mask */

#define RCC_CICLR_HSERDYC_Pos        3                                            /*!<RCC CICLR: HSERDYC Position */
#define RCC_CICLR_HSERDYC_Msk        (0x1UL << RCC_CICLR_HSERDYC_Pos)             /*!<RCC CICLR: HSERDYC Mask */

#define RCC_CICLR_PLLRDYC_Pos        4                                            /*!<RCC CICLR: PLLRDYC Position */
#define RCC_CICLR_PLLRDYC_Msk        (0x1UL << RCC_CICLR_PLLRDYC_Pos)             /*!<RCC CICLR: PLLRDYC Mask */

#define RCC_CICLR_CSMC_Pos           7                                            /*!<RCC CICLR: CSMC Position */
#define RCC_CICLR_CSMC_Msk           (0x1UL << RCC_CICLR_CSMC_Pos)                /*!<RCC CICLR: CSMC Mask */

#define RCC_CICLR_Msk_ALL            (RCC_CICLR_LSERDYC_Msk        |\
                                      RCC_CICLR_HSERDYC_Msk        |\
                                      RCC_CICLR_PLLRDYC_Msk        |\
                                      RCC_CICLR_CSMC_Msk           )

#define RCC_AHBRSTR_SYSCFGRST_Pos    1                                            /*!<RCC AHBRSTR: SYSCFGRST Position */
#define RCC_AHBRSTR_SYSCFGRST_Msk    (0x1UL << RCC_AHBRSTR_SYSCFGRST_Pos)         /*!<RCC AHBRSTR: SYSCFGRST Mask */

#define RCC_AHBRSTR_CRCRST_Pos       2                                            /*!<RCC AHBRSTR: CRCRST Position */
#define RCC_AHBRSTR_CRCRST_Msk       (0x1UL << RCC_AHBRSTR_CRCRST_Pos)            /*!<RCC AHBRSTR: CRCRST Mask */

#define RCC_AHBRSTR_DMARST_Pos       3                                            /*!<RCC AHBRSTR: DMARST Position */
#define RCC_AHBRSTR_DMARST_Msk       (0x1UL << RCC_AHBRSTR_DMARST_Pos)            /*!<RCC AHBRSTR: DMARST Mask */

#define RCC_AHBRSTR_Msk_ALL          (RCC_AHBRSTR_SYSCFGRST_Msk    |\
                                      RCC_AHBRSTR_CRCRST_Msk       |\
                                      RCC_AHBRSTR_DMARST_Msk       )

#define RCC_APB1RSTR_UART0RST_Pos    0                                            /*!<RCC APB1RSTR: UART0RST Position */
#define RCC_APB1RSTR_UART0RST_Msk    (0x1UL /*<< RCC_APB1RSTR_UART0RST_Pos*/)     /*!<RCC APB1RSTR: UART0RST Mask */

#define RCC_APB1RSTR_UART1RST_Pos    1                                            /*!<RCC APB1RSTR: UART1RST Position */
#define RCC_APB1RSTR_UART1RST_Msk    (0x1UL << RCC_APB1RSTR_UART1RST_Pos)         /*!<RCC APB1RSTR: UART1RST Mask */

#define RCC_APB1RSTR_UART2RST_Pos    2                                            /*!<RCC APB1RSTR: UART2RST Position */
#define RCC_APB1RSTR_UART2RST_Msk    (0x1UL << RCC_APB1RSTR_UART2RST_Pos)         /*!<RCC APB1RSTR: UART2RST Mask */

#define RCC_APB1RSTR_UART3RST_Pos    3                                            /*!<RCC APB1RSTR: UART3RST Position */
#define RCC_APB1RSTR_UART3RST_Msk    (0x1UL << RCC_APB1RSTR_UART3RST_Pos)         /*!<RCC APB1RSTR: UART3RST Mask */

#define RCC_APB1RSTR_SPI0RST_Pos     4                                            /*!<RCC APB1RSTR: SPI0RST Position */
#define RCC_APB1RSTR_SPI0RST_Msk     (0x1UL << RCC_APB1RSTR_SPI0RST_Pos)          /*!<RCC APB1RSTR: SPI0RST Mask */

#define RCC_APB1RSTR_SPI1RST_Pos     5                                            /*!<RCC APB1RSTR: SPI1RST Position */
#define RCC_APB1RSTR_SPI1RST_Msk     (0x1UL << RCC_APB1RSTR_SPI1RST_Pos)          /*!<RCC APB1RSTR: SPI1RST Mask */

#define RCC_APB1RSTR_TWI0RST_Pos     6                                            /*!<RCC APB1RSTR: TWI0RST Position */
#define RCC_APB1RSTR_TWI0RST_Msk     (0x1UL << RCC_APB1RSTR_TWI0RST_Pos)          /*!<RCC APB1RSTR: TWI0RST Mask */

#define RCC_APB1RSTR_LEDRST_Pos      7                                            /*!<RCC APB1RSTR: LEDRST Position */
#define RCC_APB1RSTR_LEDRST_Msk      (0x1UL << RCC_APB1RSTR_LEDRST_Pos)           /*!<RCC APB1RSTR: LEDRST Mask */

#define RCC_APB1RSTR_LCDRST_Pos      8                                            /*!<RCC APB1RSTR: LCDRST Position */
#define RCC_APB1RSTR_LCDRST_Msk      (0x1UL << RCC_APB1RSTR_LCDRST_Pos)           /*!<RCC APB1RSTR: LCDRST Mask */

#define RCC_APB1RSTR_TKRST_Pos       9                                            /*!<RCC APB1RSTR: TKRST Position */
#define RCC_APB1RSTR_TKRST_Msk       (0x1UL << RCC_APB1RSTR_TKRST_Pos)            /*!<RCC APB1RSTR: TKRST Mask */

#define RCC_APB1RSTR_HLVRST_Pos      10                                           /*!<RCC APB1RSTR: HLVRST Position */
#define RCC_APB1RSTR_HLVRST_Msk      (0x1UL << RCC_APB1RSTR_HLVRST_Pos)           /*!<RCC APB1RSTR: HLVRST Mask */

#define RCC_APB1RSTR_Msk_ALL         (RCC_APB1RSTR_UART0RST_Msk    |\
                                      RCC_APB1RSTR_UART1RST_Msk    |\
                                      RCC_APB1RSTR_UART2RST_Msk    |\
                                      RCC_APB1RSTR_UART3RST_Msk    |\
                                      RCC_APB1RSTR_SPI0RST_Msk     |\
                                      RCC_APB1RSTR_SPI1RST_Msk     |\
                                      RCC_APB1RSTR_TWI0RST_Msk     |\
                                      RCC_APB1RSTR_LEDRST_Msk      |\
                                      RCC_APB1RSTR_LCDRST_Msk      |\
                                      RCC_APB1RSTR_TKRST_Msk       |\
                                      RCC_APB1RSTR_HLVRST_Msk      )

#define RCC_APB0RSTR_TIM0RST_Pos     0                                            /*!<RCC APB0RSTR: TIM0RST Position */
#define RCC_APB0RSTR_TIM0RST_Msk     (0x1UL /*<< RCC_APB0RSTR_TIM0RST_Pos*/)      /*!<RCC APB0RSTR: TIM0RST Mask */

#define RCC_APB0RSTR_TIM1RST_Pos     1                                            /*!<RCC APB0RSTR: TIM1RST Position */
#define RCC_APB0RSTR_TIM1RST_Msk     (0x1UL << RCC_APB0RSTR_TIM1RST_Pos)          /*!<RCC APB0RSTR: TIM1RST Mask */

#define RCC_APB0RSTR_TIM2RST_Pos     2                                            /*!<RCC APB0RSTR: TIM2RST Position */
#define RCC_APB0RSTR_TIM2RST_Msk     (0x1UL << RCC_APB0RSTR_TIM2RST_Pos)          /*!<RCC APB0RSTR: TIM2RST Mask */

#define RCC_APB0RSTR_TIM3RST_Pos     3                                            /*!<RCC APB0RSTR: TIM3RST Position */
#define RCC_APB0RSTR_TIM3RST_Msk     (0x1UL << RCC_APB0RSTR_TIM3RST_Pos)          /*!<RCC APB0RSTR: TIM3RST Mask */

#define RCC_APB0RSTR_PWM0RST_Pos     4                                            /*!<RCC APB0RSTR: PWM0RST Position */
#define RCC_APB0RSTR_PWM0RST_Msk     (0x1UL << RCC_APB0RSTR_PWM0RST_Pos)          /*!<RCC APB0RSTR: PWM0RST Mask */

#define RCC_APB0RSTR_PWM1RST_Pos     5                                            /*!<RCC APB0RSTR: PWM1RST Position */
#define RCC_APB0RSTR_PWM1RST_Msk     (0x1UL << RCC_APB0RSTR_PWM1RST_Pos)          /*!<RCC APB0RSTR: PWM1RST Mask */

#define RCC_APB0RSTR_PWM2RST_Pos     6                                            /*!<RCC APB0RSTR: PWM2RST Position */
#define RCC_APB0RSTR_PWM2RST_Msk     (0x1UL << RCC_APB0RSTR_PWM2RST_Pos)          /*!<RCC APB0RSTR: PWM2RST Mask */

#define RCC_APB0RSTR_PWM3RST_Pos     7                                            /*!<RCC APB0RSTR: PWM3RST Position */
#define RCC_APB0RSTR_PWM3RST_Msk     (0x1UL << RCC_APB0RSTR_PWM3RST_Pos)          /*!<RCC APB0RSTR: PWM3RST Mask */

#define RCC_APB0RSTR_PCA0RST_Pos     8                                            /*!<RCC APB0RSTR: PCA0RST Position */
#define RCC_APB0RSTR_PCA0RST_Msk     (0x1UL << RCC_APB0RSTR_PCA0RST_Pos)          /*!<RCC APB0RSTR: PCA0RST Mask */

#define RCC_APB0RSTR_PCA1RST_Pos     9                                            /*!<RCC APB0RSTR: PCA1RST Position */
#define RCC_APB0RSTR_PCA1RST_Msk     (0x1UL << RCC_APB0RSTR_PCA1RST_Pos)          /*!<RCC APB0RSTR: PCA1RST Mask */

#define RCC_APB0RSTR_PCA2RST_Pos     10                                           /*!<RCC APB0RSTR: PCA2RST Position */
#define RCC_APB0RSTR_PCA2RST_Msk     (0x1UL << RCC_APB0RSTR_PCA2RST_Pos)          /*!<RCC APB0RSTR: PCA2RST Mask */

#define RCC_APB0RSTR_PCA3RST_Pos     11                                           /*!<RCC APB0RSTR: PCA3RST Position */
#define RCC_APB0RSTR_PCA3RST_Msk     (0x1UL << RCC_APB0RSTR_PCA3RST_Pos)          /*!<RCC APB0RSTR: PCA3RST Mask */

#define RCC_APB0RSTR_EXTIRST_Pos     12                                           /*!<RCC APB0RSTR: EXTIRST Position */
#define RCC_APB0RSTR_EXTIRST_Msk     (0x1UL << RCC_APB0RSTR_EXTIRST_Pos)          /*!<RCC APB0RSTR: EXTIRST Mask */

#define RCC_APB0RSTR_WWDTRST_Pos     13                                           /*!<RCC APB0RSTR: WWDTRST Position */
#define RCC_APB0RSTR_WWDTRST_Msk     (0x1UL << RCC_APB0RSTR_WWDTRST_Pos)          /*!<RCC APB0RSTR: WWDTRST Mask */

#define RCC_APB0RSTR_ADCRST_Pos      14                                           /*!<RCC APB0RSTR: ADCRST Position */
#define RCC_APB0RSTR_ADCRST_Msk      (0x1UL << RCC_APB0RSTR_ADCRST_Pos)           /*!<RCC APB0RSTR: ADCRST Mask */

#define RCC_APB0RSTR_Msk_ALL         (RCC_APB0RSTR_TIM0RST_Msk     |\
                                      RCC_APB0RSTR_TIM1RST_Msk     |\
                                      RCC_APB0RSTR_TIM2RST_Msk     |\
                                      RCC_APB0RSTR_TIM3RST_Msk     |\
                                      RCC_APB0RSTR_PWM0RST_Msk     |\
                                      RCC_APB0RSTR_PWM1RST_Msk     |\
                                      RCC_APB0RSTR_PWM2RST_Msk     |\
                                      RCC_APB0RSTR_PWM3RST_Msk     |\
                                      RCC_APB0RSTR_PCA0RST_Msk     |\
                                      RCC_APB0RSTR_PCA1RST_Msk     |\
                                      RCC_APB0RSTR_PCA2RST_Msk     |\
                                      RCC_APB0RSTR_PCA3RST_Msk     |\
                                      RCC_APB0RSTR_EXTIRST_Msk     |\
                                      RCC_APB0RSTR_WWDTRST_Msk     |\
                                      RCC_APB0RSTR_ADCRST_Msk      )

#define RCC_AHBENR_SYSCFGEN_Pos      1                                            /*!<RCC AHBENR: SYSCFGEN Position */
#define RCC_AHBENR_SYSCFGEN_Msk      (0x1UL << RCC_AHBENR_SYSCFGEN_Pos)           /*!<RCC AHBENR: SYSCFGEN Mask */

#define RCC_AHBENR_CRCEN_Pos         2                                            /*!<RCC AHBENR: CRCEN Position */
#define RCC_AHBENR_CRCEN_Msk         (0x1UL << RCC_AHBENR_CRCEN_Pos)              /*!<RCC AHBENR: CRCEN Mask */

#define RCC_AHBENR_DMAEN_Pos         3                                            /*!<RCC AHBENR: DMAEN Position */
#define RCC_AHBENR_DMAEN_Msk         (0x1UL << RCC_AHBENR_DMAEN_Pos)              /*!<RCC AHBENR: DMAEN Mask */

#define RCC_AHBENR_Msk_ALL           (RCC_AHBENR_SYSCFGEN_Msk      |\
                                      RCC_AHBENR_CRCEN_Msk         |\
                                      RCC_AHBENR_DMAEN_Msk         )

#define RCC_APB1ENR_UART0EN_Pos      0                                            /*!<RCC APB1ENR: UART0EN Position */
#define RCC_APB1ENR_UART0EN_Msk      (0x1UL /*<< RCC_APB1ENR_UART0EN_Pos*/)       /*!<RCC APB1ENR: UART0EN Mask */

#define RCC_APB1ENR_UART1EN_Pos      1                                            /*!<RCC APB1ENR: UART1EN Position */
#define RCC_APB1ENR_UART1EN_Msk      (0x1UL << RCC_APB1ENR_UART1EN_Pos)           /*!<RCC APB1ENR: UART1EN Mask */

#define RCC_APB1ENR_UART2EN_Pos      2                                            /*!<RCC APB1ENR: UART2EN Position */
#define RCC_APB1ENR_UART2EN_Msk      (0x1UL << RCC_APB1ENR_UART2EN_Pos)           /*!<RCC APB1ENR: UART2EN Mask */

#define RCC_APB1ENR_UART3EN_Pos      3                                            /*!<RCC APB1ENR: UART3EN Position */
#define RCC_APB1ENR_UART3EN_Msk      (0x1UL << RCC_APB1ENR_UART3EN_Pos)           /*!<RCC APB1ENR: UART3EN Mask */

#define RCC_APB1ENR_SPI0EN_Pos       4                                            /*!<RCC APB1ENR: SPI0EN Position */
#define RCC_APB1ENR_SPI0EN_Msk       (0x1UL << RCC_APB1ENR_SPI0EN_Pos)            /*!<RCC APB1ENR: SPI0EN Mask */

#define RCC_APB1ENR_SPI1EN_Pos       5                                            /*!<RCC APB1ENR: SPI1EN Position */
#define RCC_APB1ENR_SPI1EN_Msk       (0x1UL << RCC_APB1ENR_SPI1EN_Pos)            /*!<RCC APB1ENR: SPI1EN Mask */

#define RCC_APB1ENR_TWI0EN_Pos       6                                            /*!<RCC APB1ENR: TWI0EN Position */
#define RCC_APB1ENR_TWI0EN_Msk       (0x1UL << RCC_APB1ENR_TWI0EN_Pos)            /*!<RCC APB1ENR: TWI0EN Mask */

#define RCC_APB1ENR_LEDEN_Pos        7                                            /*!<RCC APB1ENR: LEDEN Position */
#define RCC_APB1ENR_LEDEN_Msk        (0x1UL << RCC_APB1ENR_LEDEN_Pos)             /*!<RCC APB1ENR: LEDEN Mask */

#define RCC_APB1ENR_LCDEN_Pos        8                                            /*!<RCC APB1ENR: LCDEN Position */
#define RCC_APB1ENR_LCDEN_Msk        (0x1UL << RCC_APB1ENR_LCDEN_Pos)             /*!<RCC APB1ENR: LCDEN Mask */

#define RCC_APB1ENR_TKEN_Pos         9                                            /*!<RCC APB1ENR: TKEN Position */
#define RCC_APB1ENR_TKEN_Msk         (0x1UL << RCC_APB1ENR_TKEN_Pos)              /*!<RCC APB1ENR: TKEN Mask */

#define RCC_APB1ENR_HLVEN_Pos        10                                           /*!<RCC APB1ENR: HLVEN Position */
#define RCC_APB1ENR_HLVEN_Msk        (0x1UL << RCC_APB1ENR_HLVEN_Pos)             /*!<RCC APB1ENR: HLVEN Mask */

#define RCC_APB1ENR_Msk_ALL          (RCC_APB1ENR_UART0EN_Msk      |\
                                      RCC_APB1ENR_UART1EN_Msk      |\
                                      RCC_APB1ENR_UART2EN_Msk      |\
                                      RCC_APB1ENR_UART3EN_Msk      |\
                                      RCC_APB1ENR_SPI0EN_Msk       |\
                                      RCC_APB1ENR_SPI1EN_Msk       |\
                                      RCC_APB1ENR_TWI0EN_Msk       |\
                                      RCC_APB1ENR_LEDEN_Msk        |\
                                      RCC_APB1ENR_LCDEN_Msk        |\
                                      RCC_APB1ENR_TKEN_Msk         |\
                                      RCC_APB1ENR_HLVEN_Msk        )

#define RCC_APB0ENR_TIM0EN_Pos       0                                            /*!<RCC APB0ENR: TIM0EN Position */
#define RCC_APB0ENR_TIM0EN_Msk       (0x1UL /*<< RCC_APB0ENR_TIM0EN_Pos*/)        /*!<RCC APB0ENR: TIM0EN Mask */

#define RCC_APB0ENR_TIM1EN_Pos       1                                            /*!<RCC APB0ENR: TIM1EN Position */
#define RCC_APB0ENR_TIM1EN_Msk       (0x1UL << RCC_APB0ENR_TIM1EN_Pos)            /*!<RCC APB0ENR: TIM1EN Mask */

#define RCC_APB0ENR_TIM2EN_Pos       2                                            /*!<RCC APB0ENR: TIM2EN Position */
#define RCC_APB0ENR_TIM2EN_Msk       (0x1UL << RCC_APB0ENR_TIM2EN_Pos)            /*!<RCC APB0ENR: TIM2EN Mask */

#define RCC_APB0ENR_TIM3EN_Pos       3                                            /*!<RCC APB0ENR: TIM3EN Position */
#define RCC_APB0ENR_TIM3EN_Msk       (0x1UL << RCC_APB0ENR_TIM3EN_Pos)            /*!<RCC APB0ENR: TIM3EN Mask */

#define RCC_APB0ENR_PWM0EN_Pos       4                                            /*!<RCC APB0ENR: PWM0EN Position */
#define RCC_APB0ENR_PWM0EN_Msk       (0x1UL << RCC_APB0ENR_PWM0EN_Pos)            /*!<RCC APB0ENR: PWM0EN Mask */

#define RCC_APB0ENR_PWM1EN_Pos       5                                            /*!<RCC APB0ENR: PWM1EN Position */
#define RCC_APB0ENR_PWM1EN_Msk       (0x1UL << RCC_APB0ENR_PWM1EN_Pos)            /*!<RCC APB0ENR: PWM1EN Mask */

#define RCC_APB0ENR_PWM2EN_Pos       6                                            /*!<RCC APB0ENR: PWM2EN Position */
#define RCC_APB0ENR_PWM2EN_Msk       (0x1UL << RCC_APB0ENR_PWM2EN_Pos)            /*!<RCC APB0ENR: PWM2EN Mask */

#define RCC_APB0ENR_PWM3EN_Pos       7                                            /*!<RCC APB0ENR: PWM3EN Position */
#define RCC_APB0ENR_PWM3EN_Msk       (0x1UL << RCC_APB0ENR_PWM3EN_Pos)            /*!<RCC APB0ENR: PWM3EN Mask */

#define RCC_APB0ENR_PCA0EN_Pos       8                                            /*!<RCC APB0ENR: PCA0EN Position */
#define RCC_APB0ENR_PCA0EN_Msk       (0x1UL << RCC_APB0ENR_PCA0EN_Pos)            /*!<RCC APB0ENR: PCA0EN Mask */

#define RCC_APB0ENR_PCA1EN_Pos       9                                            /*!<RCC APB0ENR: PCA1EN Position */
#define RCC_APB0ENR_PCA1EN_Msk       (0x1UL << RCC_APB0ENR_PCA1EN_Pos)            /*!<RCC APB0ENR: PCA1EN Mask */

#define RCC_APB0ENR_PCA2EN_Pos       10                                           /*!<RCC APB0ENR: PCA2EN Position */
#define RCC_APB0ENR_PCA2EN_Msk       (0x1UL << RCC_APB0ENR_PCA2EN_Pos)            /*!<RCC APB0ENR: PCA2EN Mask */

#define RCC_APB0ENR_PCA3EN_Pos       11                                           /*!<RCC APB0ENR: PCA3EN Position */
#define RCC_APB0ENR_PCA3EN_Msk       (0x1UL << RCC_APB0ENR_PCA3EN_Pos)            /*!<RCC APB0ENR: PCA3EN Mask */

#define RCC_APB0ENR_EXTIEN_Pos       12                                           /*!<RCC APB0ENR: EXTIEN Position */
#define RCC_APB0ENR_EXTIEN_Msk       (0x1UL << RCC_APB0ENR_EXTIEN_Pos)            /*!<RCC APB0ENR: EXTIEN Mask */

#define RCC_APB0ENR_WWDTEN_Pos       13                                           /*!<RCC APB0ENR: WWDTEN Position */
#define RCC_APB0ENR_WWDTEN_Msk       (0x1UL << RCC_APB0ENR_WWDTEN_Pos)            /*!<RCC APB0ENR: WWDTEN Mask */

#define RCC_APB0ENR_ADCEN_Pos        14                                           /*!<RCC APB0ENR: ADCEN Position */
#define RCC_APB0ENR_ADCEN_Msk        (0x1UL << RCC_APB0ENR_ADCEN_Pos)             /*!<RCC APB0ENR: ADCEN Mask */

#define RCC_APB0ENR_Msk_ALL          (RCC_APB0ENR_TIM0EN_Msk       |\
                                      RCC_APB0ENR_TIM1EN_Msk       |\
                                      RCC_APB0ENR_TIM2EN_Msk       |\
                                      RCC_APB0ENR_TIM3EN_Msk       |\
                                      RCC_APB0ENR_PWM0EN_Msk       |\
                                      RCC_APB0ENR_PWM1EN_Msk       |\
                                      RCC_APB0ENR_PWM2EN_Msk       |\
                                      RCC_APB0ENR_PWM3EN_Msk       |\
                                      RCC_APB0ENR_PCA0EN_Msk       |\
                                      RCC_APB0ENR_PCA1EN_Msk       |\
                                      RCC_APB0ENR_PCA2EN_Msk       |\
                                      RCC_APB0ENR_PCA3EN_Msk       |\
                                      RCC_APB0ENR_EXTIEN_Msk       |\
                                      RCC_APB0ENR_WWDTEN_Msk       |\
                                      RCC_APB0ENR_ADCEN_Msk        )

#define RCC_RSTSTR_PINRSTF_Pos       0                                            /*!<RCC RSTSTR: PINRSTF Position */
#define RCC_RSTSTR_PINRSTF_Msk       (0x1UL /*<< RCC_RSTSTR_PINRSTF_Pos*/)        /*!<RCC RSTSTR: PINRSTF Mask */

#define RCC_RSTSTR_LVRSTF_Pos        1                                            /*!<RCC RSTSTR: LVRSTF Position */
#define RCC_RSTSTR_LVRSTF_Msk        (0x1UL << RCC_RSTSTR_LVRSTF_Pos)             /*!<RCC RSTSTR: LVRSTF Mask */

#define RCC_RSTSTR_PORSTF_Pos        2                                            /*!<RCC RSTSTR: PORSTF Position */
#define RCC_RSTSTR_PORSTF_Msk        (0x1UL << RCC_RSTSTR_PORSTF_Pos)             /*!<RCC RSTSTR: PORSTF Mask */

#define RCC_RSTSTR_SWRSTF_Pos        3                                            /*!<RCC RSTSTR: SWRSTF Position */
#define RCC_RSTSTR_SWRSTF_Msk        (0x1UL << RCC_RSTSTR_SWRSTF_Pos)             /*!<RCC RSTSTR: SWRSTF Mask */

#define RCC_RSTSTR_IWDTRSTF_Pos      4                                            /*!<RCC RSTSTR: IWDTRSTF Position */
#define RCC_RSTSTR_IWDTRSTF_Msk      (0x1UL << RCC_RSTSTR_IWDTRSTF_Pos)           /*!<RCC RSTSTR: IWDTRSTF Mask */

#define RCC_RSTSTR_WWDTRSTF_Pos      5                                            /*!<RCC RSTSTR: WWDTRSTF Position */
#define RCC_RSTSTR_WWDTRSTF_Msk      (0x1UL << RCC_RSTSTR_WWDTRSTF_Pos)           /*!<RCC RSTSTR: WWDTRSTF Mask */

#define RCC_RSTSTR_Msk_ALL           (RCC_RSTSTR_PINRSTF_Msk       |\
                                      RCC_RSTSTR_LVRSTF_Msk        |\
                                      RCC_RSTSTR_PORSTF_Msk        |\
                                      RCC_RSTSTR_SWRSTF_Msk        |\
                                      RCC_RSTSTR_IWDTRSTF_Msk      |\
                                      RCC_RSTSTR_WWDTRSTF_Msk      )

#define RCC_RSTCLR_PINRSTFC_Pos      0                                            /*!<RCC RSTCLR: PINRSTFC Position */
#define RCC_RSTCLR_PINRSTFC_Msk      (0x1UL /*<< RCC_RSTCLR_PINRSTFC_Pos*/)       /*!<RCC RSTCLR: PINRSTFC Mask */

#define RCC_RSTCLR_LVRSTFC_Pos       1                                            /*!<RCC RSTCLR: LVRSTFC Position */
#define RCC_RSTCLR_LVRSTFC_Msk       (0x1UL << RCC_RSTCLR_LVRSTFC_Pos)            /*!<RCC RSTCLR: LVRSTFC Mask */

#define RCC_RSTCLR_PORSTFC_Pos       2                                            /*!<RCC RSTCLR: PORSTFC Position */
#define RCC_RSTCLR_PORSTFC_Msk       (0x1UL << RCC_RSTCLR_PORSTFC_Pos)            /*!<RCC RSTCLR: PORSTFC Mask */

#define RCC_RSTCLR_SWRSTFC_Pos       3                                            /*!<RCC RSTCLR: SWRSTFC Position */
#define RCC_RSTCLR_SWRSTFC_Msk       (0x1UL << RCC_RSTCLR_SWRSTFC_Pos)            /*!<RCC RSTCLR: SWRSTFC Mask */

#define RCC_RSTCLR_IWDTRSTFC_Pos     4                                            /*!<RCC RSTCLR: IWDTRSTFC Position */
#define RCC_RSTCLR_IWDTRSTFC_Msk     (0x1UL << RCC_RSTCLR_IWDTRSTFC_Pos)          /*!<RCC RSTCLR: IWDTRSTFC Mask */

#define RCC_RSTCLR_WWDTRSTFC_Pos     5                                            /*!<RCC RSTCLR: WWDTRSTFC Position */
#define RCC_RSTCLR_WWDTRSTFC_Msk     (0x1UL << RCC_RSTCLR_WWDTRSTFC_Pos)          /*!<RCC RSTCLR: WWDTRSTFC Mask */

#define RCC_RSTCLR_Msk_ALL           (RCC_RSTCLR_PINRSTFC_Msk      |\
                                      RCC_RSTCLR_LVRSTFC_Msk       |\
                                      RCC_RSTCLR_PORSTFC_Msk       |\
                                      RCC_RSTCLR_SWRSTFC_Msk       |\
                                      RCC_RSTCLR_IWDTRSTFC_Msk     |\
                                      RCC_RSTCLR_WWDTRSTFC_Msk     )

#define RCC_RCCLOCK_LOCK_Pos         0                                            /*!<RCC RCCLOCK: LOCK Position */
#define RCC_RCCLOCK_LOCK_Msk         (0xFFFFUL /*<< RCC_RCCLOCK_LOCK_Pos*/)       /*!<RCC RCCLOCK: LOCK Mask */

#define RCC_RCCLOCK_Msk_ALL          (RCC_RCCLOCK_LOCK_Msk        )

#define RCC_HSERFB_RFBSEL_Pos        0                                            /*!<RCC HSERFB: RFBSEL Position */
#define RCC_HSERFB_RFBSEL_Msk        (0x3UL /*<< RCC_HSERFB_RFBSEL_Pos*/)         /*!<RCC HSERFB: RFBSEL Mask */

#define RCC_HSERFB_Msk_ALL           (RCC_HSERFB_RFBSEL_Msk       )

#define IWDT_CR_IWDTRLR_Pos          0                                            /*!<IWDT CR: IWDTRLR Position */
#define IWDT_CR_IWDTRLR_Msk          (0xFFFUL /*<< IWDT_CR_IWDTRLR_Pos*/)         /*!<IWDT CR: IWDTRLR Mask */

#define IWDT_CR_IWDTPR_Pos           12                                           /*!<IWDT CR: IWDTPR Position */
#define IWDT_CR_IWDTPR_Msk           (0x7UL << IWDT_CR_IWDTPR_Pos)                /*!<IWDT CR: IWDTPR Mask */

#define IWDT_CR_IWDTPD_Pos           15                                           /*!<IWDT CR: IWDTPD Position */
#define IWDT_CR_IWDTPD_Msk           (0x1UL << IWDT_CR_IWDTPD_Pos)                /*!<IWDT CR: IWDTPD Mask */

#define IWDT_CR_LOCK_Pos             16                                           /*!<IWDT CR: LOCK Position */
#define IWDT_CR_LOCK_Msk             (0xFFFFUL << IWDT_CR_LOCK_Pos)               /*!<IWDT CR: LOCK Mask */

#define IWDT_CR_Msk_ALL              (IWDT_CR_IWDTRLR_Msk          |\
                                      IWDT_CR_IWDTPR_Msk           |\
                                      IWDT_CR_IWDTPD_Msk           |\
                                      IWDT_CR_LOCK_Msk             )

#define IWDT_CLR_IWDTCLR_Pos         0                                            /*!<IWDT CLR: IWDTCLR Position */
#define IWDT_CLR_IWDTCLR_Msk         (0xFFFFUL /*<< IWDT_CLR_IWDTCLR_Pos*/)       /*!<IWDT CLR: IWDTCLR Mask */

#define IWDT_CLR_Msk_ALL             (IWDT_CLR_IWDTCLR_Msk        )

#define WWDT_CR_WWDTRLR_Pos          0                                            /*!<WWDT CR: WWDTRLR Position */
#define WWDT_CR_WWDTRLR_Msk          (0xFFUL /*<< WWDT_CR_WWDTRLR_Pos*/)          /*!<WWDT CR: WWDTRLR Mask */

#define WWDT_CR_WWDTPR_Pos           8                                            /*!<WWDT CR: WWDTPR Position */
#define WWDT_CR_WWDTPR_Msk           (0x7UL << WWDT_CR_WWDTPR_Pos)                /*!<WWDT CR: WWDTPR Mask */

#define WWDT_CR_WWDTIE_Pos           14                                           /*!<WWDT CR: WWDTIE Position */
#define WWDT_CR_WWDTIE_Msk           (0x1UL << WWDT_CR_WWDTIE_Pos)                /*!<WWDT CR: WWDTIE Mask */

#define WWDT_CR_WWDTON_Pos           15                                           /*!<WWDT CR: WWDTON Position */
#define WWDT_CR_WWDTON_Msk           (0x1UL << WWDT_CR_WWDTON_Pos)                /*!<WWDT CR: WWDTON Mask */

#define WWDT_CR_LOCK_Pos             16                                           /*!<WWDT CR: LOCK Position */
#define WWDT_CR_LOCK_Msk             (0xFFFFUL << WWDT_CR_LOCK_Pos)               /*!<WWDT CR: LOCK Mask */

#define WWDT_CR_Msk_ALL              (WWDT_CR_WWDTRLR_Msk          |\
                                      WWDT_CR_WWDTPR_Msk           |\
                                      WWDT_CR_WWDTIE_Msk           |\
                                      WWDT_CR_WWDTON_Msk           |\
                                      WWDT_CR_LOCK_Msk             )

#define WWDT_SR_TCNT_Pos             0                                            /*!<WWDT SR: TCNT Position */
#define WWDT_SR_TCNT_Msk             (0xFFUL /*<< WWDT_SR_TCNT_Pos*/)             /*!<WWDT SR: TCNT Mask */

#define WWDT_SR_WWDTIF_Pos           15                                           /*!<WWDT SR: WWDTIF Position */
#define WWDT_SR_WWDTIF_Msk           (0x1UL << WWDT_SR_WWDTIF_Pos)                /*!<WWDT SR: WWDTIF Mask */

#define WWDT_SR_Msk_ALL              (WWDT_SR_TCNT_Msk             |\
                                      WWDT_SR_WWDTIF_Msk           )

#define WWDT_CLR_WWDTCLR_Pos         0                                            /*!<WWDT CLR: WWDTCLR Position */
#define WWDT_CLR_WWDTCLR_Msk         (0xFFFFUL /*<< WWDT_CLR_WWDTCLR_Pos*/)       /*!<WWDT CLR: WWDTCLR Mask */

#define WWDT_CLR_Msk_ALL             (WWDT_CLR_WWDTCLR_Msk        )

#define WWDT_WTR_WWDTWTR_Pos         0                                            /*!<WWDT WTR: WWDTWTR Position */
#define WWDT_WTR_WWDTWTR_Msk         (0xFFUL /*<< WWDT_WTR_WWDTWTR_Pos*/)         /*!<WWDT WTR: WWDTWTR Mask */

#define WWDT_WTR_LOCK_Pos            16                                           /*!<WWDT WTR: LOCK Position */
#define WWDT_WTR_LOCK_Msk            (0xFFFFUL << WWDT_WTR_LOCK_Pos)              /*!<WWDT WTR: LOCK Mask */

#define WWDT_WTR_Msk_ALL             (WWDT_WTR_WWDTWTR_Msk         |\
                                      WWDT_WTR_LOCK_Msk            )

#define CRC_CR_RELOAD_Pos            0                                            /*!<CRC CR: RELOAD Position */
#define CRC_CR_RELOAD_Msk            (0x1UL /*<< CRC_CR_RELOAD_Pos*/)             /*!<CRC CR: RELOAD Mask */

#define CRC_CR_MODE_Pos              8                                            /*!<CRC CR: MODE Position */
#define CRC_CR_MODE_Msk              (0x3UL << CRC_CR_MODE_Pos)                   /*!<CRC CR: MODE Mask */

#define CRC_CR_COMPLW_Pos            10                                           /*!<CRC CR: COMPLW Position */
#define CRC_CR_COMPLW_Msk            (0x1UL << CRC_CR_COMPLW_Pos)                 /*!<CRC CR: COMPLW Mask */

#define CRC_CR_RBITW_Pos             11                                           /*!<CRC CR: RBITW Position */
#define CRC_CR_RBITW_Msk             (0x1UL << CRC_CR_RBITW_Pos)                  /*!<CRC CR: RBITW Mask */

#define CRC_CR_RBYTEW_Pos            12                                           /*!<CRC CR: RBYTEW Position */
#define CRC_CR_RBYTEW_Msk            (0x1UL << CRC_CR_RBYTEW_Pos)                 /*!<CRC CR: RBYTEW Mask */

#define CRC_CR_COMPLR_Pos            13                                           /*!<CRC CR: COMPLR Position */
#define CRC_CR_COMPLR_Msk            (0x1UL << CRC_CR_COMPLR_Pos)                 /*!<CRC CR: COMPLR Mask */

#define CRC_CR_RBITR_Pos             14                                           /*!<CRC CR: RBITR Position */
#define CRC_CR_RBITR_Msk             (0x1UL << CRC_CR_RBITR_Pos)                  /*!<CRC CR: RBITR Mask */

#define CRC_CR_RBYTER_Pos            15                                           /*!<CRC CR: RBYTER Position */
#define CRC_CR_RBYTER_Msk            (0x1UL << CRC_CR_RBYTER_Pos)                 /*!<CRC CR: RBYTER Mask */

#define CRC_CR_Msk_ALL               (CRC_CR_RELOAD_Msk            |\
                                      CRC_CR_MODE_Msk              |\
                                      CRC_CR_COMPLW_Msk            |\
                                      CRC_CR_RBITW_Msk             |\
                                      CRC_CR_RBYTEW_Msk            |\
                                      CRC_CR_COMPLR_Msk            |\
                                      CRC_CR_RBITR_Msk             |\
                                      CRC_CR_RBYTER_Msk            )

#define RAMBIST_CFG_BLKSZ_Pos        0                                            /*!<RAMBIST CFG: BLKSZ Position */
#define RAMBIST_CFG_BLKSZ_Msk        (0x7UL /*<< RAMBIST_CFG_BLKSZ_Pos*/)         /*!<RAMBIST CFG: BLKSZ Mask */

#define RAMBIST_CFG_SEL_Pos          15                                           /*!<RAMBIST CFG: SEL Position */
#define RAMBIST_CFG_SEL_Msk          (0x1UL << RAMBIST_CFG_SEL_Pos)               /*!<RAMBIST CFG: SEL Mask */

#define RAMBIST_CFG_Msk_ALL          (RAMBIST_CFG_BLKSZ_Msk        |\
                                      RAMBIST_CFG_SEL_Msk          )

#define RAMBIST_CSR_RUN_Pos          0                                            /*!<RAMBIST CSR: RUN Position */
#define RAMBIST_CSR_RUN_Msk          (0xFFFFUL /*<< RAMBIST_CSR_RUN_Pos*/)        /*!<RAMBIST CSR: RUN Mask */

#define RAMBIST_CSR_MOD_Pos          16                                           /*!<RAMBIST CSR: MOD Position */
#define RAMBIST_CSR_MOD_Msk          (0x1UL << RAMBIST_CSR_MOD_Pos)               /*!<RAMBIST CSR: MOD Mask */

#define RAMBIST_CSR_BSY_Pos          17                                           /*!<RAMBIST CSR: BSY Position */
#define RAMBIST_CSR_BSY_Msk          (0x1UL << RAMBIST_CSR_BSY_Pos)               /*!<RAMBIST CSR: BSY Mask */

#define RAMBIST_CSR_ERR_Pos          18                                           /*!<RAMBIST CSR: ERR Position */
#define RAMBIST_CSR_ERR_Msk          (0x1UL << RAMBIST_CSR_ERR_Pos)               /*!<RAMBIST CSR: ERR Mask */

#define RAMBIST_CSR_Msk_ALL          (RAMBIST_CSR_RUN_Msk          |\
                                      RAMBIST_CSR_MOD_Msk          |\
                                      RAMBIST_CSR_BSY_Msk          |\
                                      RAMBIST_CSR_ERR_Msk          )

#define GPIOA_MODER_MODER0_Pos       0                                            /*!<GPIOA MODER: MODER0 Position */
#define GPIOA_MODER_MODER0_Msk       (0x1UL /*<< GPIOA_MODER_MODER0_Pos*/)        /*!<GPIOA MODER: MODER0 Mask */

#define GPIOA_MODER_MODER1_Pos       1                                            /*!<GPIOA MODER: MODER1 Position */
#define GPIOA_MODER_MODER1_Msk       (0x1UL << GPIOA_MODER_MODER1_Pos)            /*!<GPIOA MODER: MODER1 Mask */

#define GPIOA_MODER_MODER2_Pos       2                                            /*!<GPIOA MODER: MODER2 Position */
#define GPIOA_MODER_MODER2_Msk       (0x1UL << GPIOA_MODER_MODER2_Pos)            /*!<GPIOA MODER: MODER2 Mask */

#define GPIOA_MODER_MODER3_Pos       3                                            /*!<GPIOA MODER: MODER3 Position */
#define GPIOA_MODER_MODER3_Msk       (0x1UL << GPIOA_MODER_MODER3_Pos)            /*!<GPIOA MODER: MODER3 Mask */

#define GPIOA_MODER_MODER4_Pos       4                                            /*!<GPIOA MODER: MODER4 Position */
#define GPIOA_MODER_MODER4_Msk       (0x1UL << GPIOA_MODER_MODER4_Pos)            /*!<GPIOA MODER: MODER4 Mask */

#define GPIOA_MODER_MODER5_Pos       5                                            /*!<GPIOA MODER: MODER5 Position */
#define GPIOA_MODER_MODER5_Msk       (0x1UL << GPIOA_MODER_MODER5_Pos)            /*!<GPIOA MODER: MODER5 Mask */

#define GPIOA_MODER_MODER6_Pos       6                                            /*!<GPIOA MODER: MODER6 Position */
#define GPIOA_MODER_MODER6_Msk       (0x1UL << GPIOA_MODER_MODER6_Pos)            /*!<GPIOA MODER: MODER6 Mask */

#define GPIOA_MODER_MODER7_Pos       7                                            /*!<GPIOA MODER: MODER7 Position */
#define GPIOA_MODER_MODER7_Msk       (0x1UL << GPIOA_MODER_MODER7_Pos)            /*!<GPIOA MODER: MODER7 Mask */

#define GPIOA_MODER_MODER8_Pos       8                                            /*!<GPIOA MODER: MODER8 Position */
#define GPIOA_MODER_MODER8_Msk       (0x1UL << GPIOA_MODER_MODER8_Pos)            /*!<GPIOA MODER: MODER8 Mask */

#define GPIOA_MODER_MODER9_Pos       9                                            /*!<GPIOA MODER: MODER9 Position */
#define GPIOA_MODER_MODER9_Msk       (0x1UL << GPIOA_MODER_MODER9_Pos)            /*!<GPIOA MODER: MODER9 Mask */

#define GPIOA_MODER_MODER10_Pos      10                                           /*!<GPIOA MODER: MODER10 Position */
#define GPIOA_MODER_MODER10_Msk      (0x1UL << GPIOA_MODER_MODER10_Pos)           /*!<GPIOA MODER: MODER10 Mask */

#define GPIOA_MODER_MODER11_Pos      11                                           /*!<GPIOA MODER: MODER11 Position */
#define GPIOA_MODER_MODER11_Msk      (0x1UL << GPIOA_MODER_MODER11_Pos)           /*!<GPIOA MODER: MODER11 Mask */

#define GPIOA_MODER_MODER12_Pos      12                                           /*!<GPIOA MODER: MODER12 Position */
#define GPIOA_MODER_MODER12_Msk      (0x1UL << GPIOA_MODER_MODER12_Pos)           /*!<GPIOA MODER: MODER12 Mask */

#define GPIOA_MODER_MODER13_Pos      13                                           /*!<GPIOA MODER: MODER13 Position */
#define GPIOA_MODER_MODER13_Msk      (0x1UL << GPIOA_MODER_MODER13_Pos)           /*!<GPIOA MODER: MODER13 Mask */

#define GPIOA_MODER_MODER14_Pos      14                                           /*!<GPIOA MODER: MODER14 Position */
#define GPIOA_MODER_MODER14_Msk      (0x1UL << GPIOA_MODER_MODER14_Pos)           /*!<GPIOA MODER: MODER14 Mask */

#define GPIOA_MODER_MODER15_Pos      15                                           /*!<GPIOA MODER: MODER15 Position */
#define GPIOA_MODER_MODER15_Msk      (0x1UL << GPIOA_MODER_MODER15_Pos)           /*!<GPIOA MODER: MODER15 Mask */

#define GPIOA_MODER_Msk_ALL          (GPIOA_MODER_MODER0_Msk       |\
                                      GPIOA_MODER_MODER1_Msk       |\
                                      GPIOA_MODER_MODER2_Msk       |\
                                      GPIOA_MODER_MODER3_Msk       |\
                                      GPIOA_MODER_MODER4_Msk       |\
                                      GPIOA_MODER_MODER5_Msk       |\
                                      GPIOA_MODER_MODER6_Msk       |\
                                      GPIOA_MODER_MODER7_Msk       |\
                                      GPIOA_MODER_MODER8_Msk       |\
                                      GPIOA_MODER_MODER9_Msk       |\
                                      GPIOA_MODER_MODER10_Msk      |\
                                      GPIOA_MODER_MODER11_Msk      |\
                                      GPIOA_MODER_MODER12_Msk      |\
                                      GPIOA_MODER_MODER13_Msk      |\
                                      GPIOA_MODER_MODER14_Msk      |\
                                      GPIOA_MODER_MODER15_Msk      )

#define GPIOA_IDR_IDR_Pos            0                                            /*!<GPIOA IDR: IDR Position */
#define GPIOA_IDR_IDR_Msk            (0xFFFFUL /*<< GPIOA_IDR_IDR_Pos*/)          /*!<GPIOA IDR: IDR Mask */

#define GPIOA_IDR_Msk_ALL            (GPIOA_IDR_IDR_Msk           )

#define GPIOA_ODR_ODR_Pos            0                                            /*!<GPIOA ODR: ODR Position */
#define GPIOA_ODR_ODR_Msk            (0xFFFFUL /*<< GPIOA_ODR_ODR_Pos*/)          /*!<GPIOA ODR: ODR Mask */

#define GPIOA_ODR_Msk_ALL            (GPIOA_ODR_ODR_Msk           )

#define GPIOA_BSRR_BS_Pos            0                                            /*!<GPIOA BSRR: BS Position */
#define GPIOA_BSRR_BS_Msk            (0xFFFFUL /*<< GPIOA_BSRR_BS_Pos*/)          /*!<GPIOA BSRR: BS Mask */

#define GPIOA_BSRR_BR_Pos            16                                           /*!<GPIOA BSRR: BR Position */
#define GPIOA_BSRR_BR_Msk            (0xFFFFUL << GPIOA_BSRR_BR_Pos)              /*!<GPIOA BSRR: BR Mask */

#define GPIOA_BSRR_Msk_ALL           (GPIOA_BSRR_BS_Msk            |\
                                      GPIOA_BSRR_BR_Msk            )

#define GPIOA_LCKR_LCK0_Pos          0                                            /*!<GPIOA LCKR: LCK0 Position */
#define GPIOA_LCKR_LCK0_Msk          (0x1UL /*<< GPIOA_LCKR_LCK0_Pos*/)           /*!<GPIOA LCKR: LCK0 Mask */

#define GPIOA_LCKR_LCK1_Pos          1                                            /*!<GPIOA LCKR: LCK1 Position */
#define GPIOA_LCKR_LCK1_Msk          (0x1UL << GPIOA_LCKR_LCK1_Pos)               /*!<GPIOA LCKR: LCK1 Mask */

#define GPIOA_LCKR_LCK2_Pos          2                                            /*!<GPIOA LCKR: LCK2 Position */
#define GPIOA_LCKR_LCK2_Msk          (0x1UL << GPIOA_LCKR_LCK2_Pos)               /*!<GPIOA LCKR: LCK2 Mask */

#define GPIOA_LCKR_LCK3_Pos          3                                            /*!<GPIOA LCKR: LCK3 Position */
#define GPIOA_LCKR_LCK3_Msk          (0x1UL << GPIOA_LCKR_LCK3_Pos)               /*!<GPIOA LCKR: LCK3 Mask */

#define GPIOA_LCKR_LCK4_Pos          4                                            /*!<GPIOA LCKR: LCK4 Position */
#define GPIOA_LCKR_LCK4_Msk          (0x1UL << GPIOA_LCKR_LCK4_Pos)               /*!<GPIOA LCKR: LCK4 Mask */

#define GPIOA_LCKR_LCK5_Pos          5                                            /*!<GPIOA LCKR: LCK5 Position */
#define GPIOA_LCKR_LCK5_Msk          (0x1UL << GPIOA_LCKR_LCK5_Pos)               /*!<GPIOA LCKR: LCK5 Mask */

#define GPIOA_LCKR_LCK6_Pos          6                                            /*!<GPIOA LCKR: LCK6 Position */
#define GPIOA_LCKR_LCK6_Msk          (0x1UL << GPIOA_LCKR_LCK6_Pos)               /*!<GPIOA LCKR: LCK6 Mask */

#define GPIOA_LCKR_LCK7_Pos          7                                            /*!<GPIOA LCKR: LCK7 Position */
#define GPIOA_LCKR_LCK7_Msk          (0x1UL << GPIOA_LCKR_LCK7_Pos)               /*!<GPIOA LCKR: LCK7 Mask */

#define GPIOA_LCKR_LCK8_Pos          8                                            /*!<GPIOA LCKR: LCK8 Position */
#define GPIOA_LCKR_LCK8_Msk          (0x1UL << GPIOA_LCKR_LCK8_Pos)               /*!<GPIOA LCKR: LCK8 Mask */

#define GPIOA_LCKR_LCK9_Pos          9                                            /*!<GPIOA LCKR: LCK9 Position */
#define GPIOA_LCKR_LCK9_Msk          (0x1UL << GPIOA_LCKR_LCK9_Pos)               /*!<GPIOA LCKR: LCK9 Mask */

#define GPIOA_LCKR_LCK10_Pos         10                                           /*!<GPIOA LCKR: LCK10 Position */
#define GPIOA_LCKR_LCK10_Msk         (0x1UL << GPIOA_LCKR_LCK10_Pos)              /*!<GPIOA LCKR: LCK10 Mask */

#define GPIOA_LCKR_LCK11_Pos         11                                           /*!<GPIOA LCKR: LCK11 Position */
#define GPIOA_LCKR_LCK11_Msk         (0x1UL << GPIOA_LCKR_LCK11_Pos)              /*!<GPIOA LCKR: LCK11 Mask */

#define GPIOA_LCKR_LCK12_Pos         12                                           /*!<GPIOA LCKR: LCK12 Position */
#define GPIOA_LCKR_LCK12_Msk         (0x1UL << GPIOA_LCKR_LCK12_Pos)              /*!<GPIOA LCKR: LCK12 Mask */

#define GPIOA_LCKR_LCK13_Pos         13                                           /*!<GPIOA LCKR: LCK13 Position */
#define GPIOA_LCKR_LCK13_Msk         (0x1UL << GPIOA_LCKR_LCK13_Pos)              /*!<GPIOA LCKR: LCK13 Mask */

#define GPIOA_LCKR_LCK14_Pos         14                                           /*!<GPIOA LCKR: LCK14 Position */
#define GPIOA_LCKR_LCK14_Msk         (0x1UL << GPIOA_LCKR_LCK14_Pos)              /*!<GPIOA LCKR: LCK14 Mask */

#define GPIOA_LCKR_LCK15_Pos         15                                           /*!<GPIOA LCKR: LCK15 Position */
#define GPIOA_LCKR_LCK15_Msk         (0x1UL << GPIOA_LCKR_LCK15_Pos)              /*!<GPIOA LCKR: LCK15 Mask */

#define GPIOA_LCKR_LOCK_Pos          16                                           /*!<GPIOA LCKR: LOCK Position */
#define GPIOA_LCKR_LOCK_Msk          (0xFFFFUL << GPIOA_LCKR_LOCK_Pos)            /*!<GPIOA LCKR: LOCK Mask */

#define GPIOA_LCKR_Msk_ALL           (GPIOA_LCKR_LCK0_Msk          |\
                                      GPIOA_LCKR_LCK1_Msk          |\
                                      GPIOA_LCKR_LCK2_Msk          |\
                                      GPIOA_LCKR_LCK3_Msk          |\
                                      GPIOA_LCKR_LCK4_Msk          |\
                                      GPIOA_LCKR_LCK5_Msk          |\
                                      GPIOA_LCKR_LCK6_Msk          |\
                                      GPIOA_LCKR_LCK7_Msk          |\
                                      GPIOA_LCKR_LCK8_Msk          |\
                                      GPIOA_LCKR_LCK9_Msk          |\
                                      GPIOA_LCKR_LCK10_Msk         |\
                                      GPIOA_LCKR_LCK11_Msk         |\
                                      GPIOA_LCKR_LCK12_Msk         |\
                                      GPIOA_LCKR_LCK13_Msk         |\
                                      GPIOA_LCKR_LCK14_Msk         |\
                                      GPIOA_LCKR_LCK15_Msk         |\
                                      GPIOA_LCKR_LOCK_Msk          )

#define GPIOA_IE_IE0_Pos             0                                            /*!<GPIOA IE: IE0 Position */
#define GPIOA_IE_IE0_Msk             (0x1UL /*<< GPIOA_IE_IE0_Pos*/)              /*!<GPIOA IE: IE0 Mask */

#define GPIOA_IE_IE1_Pos             1                                            /*!<GPIOA IE: IE1 Position */
#define GPIOA_IE_IE1_Msk             (0x1UL << GPIOA_IE_IE1_Pos)                  /*!<GPIOA IE: IE1 Mask */

#define GPIOA_IE_IE2_Pos             2                                            /*!<GPIOA IE: IE2 Position */
#define GPIOA_IE_IE2_Msk             (0x1UL << GPIOA_IE_IE2_Pos)                  /*!<GPIOA IE: IE2 Mask */

#define GPIOA_IE_IE3_Pos             3                                            /*!<GPIOA IE: IE3 Position */
#define GPIOA_IE_IE3_Msk             (0x1UL << GPIOA_IE_IE3_Pos)                  /*!<GPIOA IE: IE3 Mask */

#define GPIOA_IE_IE4_Pos             4                                            /*!<GPIOA IE: IE4 Position */
#define GPIOA_IE_IE4_Msk             (0x1UL << GPIOA_IE_IE4_Pos)                  /*!<GPIOA IE: IE4 Mask */

#define GPIOA_IE_IE5_Pos             5                                            /*!<GPIOA IE: IE5 Position */
#define GPIOA_IE_IE5_Msk             (0x1UL << GPIOA_IE_IE5_Pos)                  /*!<GPIOA IE: IE5 Mask */

#define GPIOA_IE_IE6_Pos             6                                            /*!<GPIOA IE: IE6 Position */
#define GPIOA_IE_IE6_Msk             (0x1UL << GPIOA_IE_IE6_Pos)                  /*!<GPIOA IE: IE6 Mask */

#define GPIOA_IE_IE7_Pos             7                                            /*!<GPIOA IE: IE7 Position */
#define GPIOA_IE_IE7_Msk             (0x1UL << GPIOA_IE_IE7_Pos)                  /*!<GPIOA IE: IE7 Mask */

#define GPIOA_IE_IE8_Pos             8                                            /*!<GPIOA IE: IE8 Position */
#define GPIOA_IE_IE8_Msk             (0x1UL << GPIOA_IE_IE8_Pos)                  /*!<GPIOA IE: IE8 Mask */

#define GPIOA_IE_IE9_Pos             9                                            /*!<GPIOA IE: IE9 Position */
#define GPIOA_IE_IE9_Msk             (0x1UL << GPIOA_IE_IE9_Pos)                  /*!<GPIOA IE: IE9 Mask */

#define GPIOA_IE_IE10_Pos            10                                           /*!<GPIOA IE: IE10 Position */
#define GPIOA_IE_IE10_Msk            (0x1UL << GPIOA_IE_IE10_Pos)                 /*!<GPIOA IE: IE10 Mask */

#define GPIOA_IE_IE11_Pos            11                                           /*!<GPIOA IE: IE11 Position */
#define GPIOA_IE_IE11_Msk            (0x1UL << GPIOA_IE_IE11_Pos)                 /*!<GPIOA IE: IE11 Mask */

#define GPIOA_IE_IE12_Pos            12                                           /*!<GPIOA IE: IE12 Position */
#define GPIOA_IE_IE12_Msk            (0x1UL << GPIOA_IE_IE12_Pos)                 /*!<GPIOA IE: IE12 Mask */

#define GPIOA_IE_IE13_Pos            13                                           /*!<GPIOA IE: IE13 Position */
#define GPIOA_IE_IE13_Msk            (0x1UL << GPIOA_IE_IE13_Pos)                 /*!<GPIOA IE: IE13 Mask */

#define GPIOA_IE_IE14_Pos            14                                           /*!<GPIOA IE: IE14 Position */
#define GPIOA_IE_IE14_Msk            (0x1UL << GPIOA_IE_IE14_Pos)                 /*!<GPIOA IE: IE14 Mask */

#define GPIOA_IE_IE15_Pos            15                                           /*!<GPIOA IE: IE15 Position */
#define GPIOA_IE_IE15_Msk            (0x1UL << GPIOA_IE_IE15_Pos)                 /*!<GPIOA IE: IE15 Mask */

#define GPIOA_IE_Msk_ALL             (GPIOA_IE_IE0_Msk             |\
                                      GPIOA_IE_IE1_Msk             |\
                                      GPIOA_IE_IE2_Msk             |\
                                      GPIOA_IE_IE3_Msk             |\
                                      GPIOA_IE_IE4_Msk             |\
                                      GPIOA_IE_IE5_Msk             |\
                                      GPIOA_IE_IE6_Msk             |\
                                      GPIOA_IE_IE7_Msk             |\
                                      GPIOA_IE_IE8_Msk             |\
                                      GPIOA_IE_IE9_Msk             |\
                                      GPIOA_IE_IE10_Msk            |\
                                      GPIOA_IE_IE11_Msk            |\
                                      GPIOA_IE_IE12_Msk            |\
                                      GPIOA_IE_IE13_Msk            |\
                                      GPIOA_IE_IE14_Msk            |\
                                      GPIOA_IE_IE15_Msk            )

#define GPIOA_OTYPER_OT4_Pos         4                                            /*!<GPIOA OTYPER: OT4 Position */
#define GPIOA_OTYPER_OT4_Msk         (0x1UL << GPIOA_OTYPER_OT4_Pos)              /*!<GPIOA OTYPER: OT4 Mask */

#define GPIOA_OTYPER_OT5_Pos         5                                            /*!<GPIOA OTYPER: OT5 Position */
#define GPIOA_OTYPER_OT5_Msk         (0x1UL << GPIOA_OTYPER_OT5_Pos)              /*!<GPIOA OTYPER: OT5 Mask */

#define GPIOA_OTYPER_OT6_Pos         6                                            /*!<GPIOA OTYPER: OT6 Position */
#define GPIOA_OTYPER_OT6_Msk         (0x1UL << GPIOA_OTYPER_OT6_Pos)              /*!<GPIOA OTYPER: OT6 Mask */

#define GPIOA_OTYPER_OT7_Pos         7                                            /*!<GPIOA OTYPER: OT7 Position */
#define GPIOA_OTYPER_OT7_Msk         (0x1UL << GPIOA_OTYPER_OT7_Pos)              /*!<GPIOA OTYPER: OT7 Mask */

#define GPIOA_OTYPER_OT8_Pos         8                                            /*!<GPIOA OTYPER: OT8 Position */
#define GPIOA_OTYPER_OT8_Msk         (0x1UL << GPIOA_OTYPER_OT8_Pos)              /*!<GPIOA OTYPER: OT8 Mask */

#define GPIOA_OTYPER_OT9_Pos         9                                            /*!<GPIOA OTYPER: OT9 Position */
#define GPIOA_OTYPER_OT9_Msk         (0x1UL << GPIOA_OTYPER_OT9_Pos)              /*!<GPIOA OTYPER: OT9 Mask */

#define GPIOA_OTYPER_OT10_Pos        10                                           /*!<GPIOA OTYPER: OT10 Position */
#define GPIOA_OTYPER_OT10_Msk        (0x1UL << GPIOA_OTYPER_OT10_Pos)             /*!<GPIOA OTYPER: OT10 Mask */

#define GPIOA_OTYPER_OT12_Pos        12                                           /*!<GPIOA OTYPER: OT12 Position */
#define GPIOA_OTYPER_OT12_Msk        (0x1UL << GPIOA_OTYPER_OT12_Pos)             /*!<GPIOA OTYPER: OT12 Mask */

#define GPIOA_OTYPER_OT13_Pos        13                                           /*!<GPIOA OTYPER: OT13 Position */
#define GPIOA_OTYPER_OT13_Msk        (0x1UL << GPIOA_OTYPER_OT13_Pos)             /*!<GPIOA OTYPER: OT13 Mask */

#define GPIOA_OTYPER_OT14_Pos        14                                           /*!<GPIOA OTYPER: OT14 Position */
#define GPIOA_OTYPER_OT14_Msk        (0x1UL << GPIOA_OTYPER_OT14_Pos)             /*!<GPIOA OTYPER: OT14 Mask */

#define GPIOA_OTYPER_OT15_Pos        15                                           /*!<GPIOA OTYPER: OT15 Position */
#define GPIOA_OTYPER_OT15_Msk        (0x1UL << GPIOA_OTYPER_OT15_Pos)             /*!<GPIOA OTYPER: OT15 Mask */

#define GPIOA_OTYPER_Msk_ALL         (GPIOA_OTYPER_OT4_Msk         |\
                                      GPIOA_OTYPER_OT5_Msk         |\
                                      GPIOA_OTYPER_OT6_Msk         |\
                                      GPIOA_OTYPER_OT7_Msk         |\
                                      GPIOA_OTYPER_OT8_Msk         |\
                                      GPIOA_OTYPER_OT9_Msk         |\
                                      GPIOA_OTYPER_OT10_Msk        |\
                                      GPIOA_OTYPER_OT12_Msk        |\
                                      GPIOA_OTYPER_OT13_Msk        |\
                                      GPIOA_OTYPER_OT14_Msk        |\
                                      GPIOA_OTYPER_OT15_Msk        )

#define GPIOA_ODRVR_ODRVR_SINK2_Pos  4                                            /*!<GPIOA ODRVR: ODRVR_SINK2 Position */
#define GPIOA_ODRVR_ODRVR_SINK2_Msk  (0x1UL << GPIOA_ODRVR_ODRVR_SINK2_Pos)       /*!<GPIOA ODRVR: ODRVR_SINK2 Mask */

#define GPIOA_ODRVR_ODRVR_SINK3_Pos  6                                            /*!<GPIOA ODRVR: ODRVR_SINK3 Position */
#define GPIOA_ODRVR_ODRVR_SINK3_Msk  (0x1UL << GPIOA_ODRVR_ODRVR_SINK3_Pos)       /*!<GPIOA ODRVR: ODRVR_SINK3 Mask */

#define GPIOA_ODRVR_ODRVR_SINK4_Pos  8                                            /*!<GPIOA ODRVR: ODRVR_SINK4 Position */
#define GPIOA_ODRVR_ODRVR_SINK4_Msk  (0x1UL << GPIOA_ODRVR_ODRVR_SINK4_Pos)       /*!<GPIOA ODRVR: ODRVR_SINK4 Mask */

#define GPIOA_ODRVR_ODRVR_SINK5_Pos  10                                           /*!<GPIOA ODRVR: ODRVR_SINK5 Position */
#define GPIOA_ODRVR_ODRVR_SINK5_Msk  (0x1UL << GPIOA_ODRVR_ODRVR_SINK5_Pos)       /*!<GPIOA ODRVR: ODRVR_SINK5 Mask */

#define GPIOA_ODRVR_ODRVR_SINK6_Pos  12                                           /*!<GPIOA ODRVR: ODRVR_SINK6 Position */
#define GPIOA_ODRVR_ODRVR_SINK6_Msk  (0x1UL << GPIOA_ODRVR_ODRVR_SINK6_Pos)       /*!<GPIOA ODRVR: ODRVR_SINK6 Mask */

#define GPIOA_ODRVR_ODRVR_SINK7_Pos  14                                           /*!<GPIOA ODRVR: ODRVR_SINK7 Position */
#define GPIOA_ODRVR_ODRVR_SINK7_Msk  (0x1UL << GPIOA_ODRVR_ODRVR_SINK7_Pos)       /*!<GPIOA ODRVR: ODRVR_SINK7 Mask */

#define GPIOA_ODRVR_ODRVR_SINK8_Pos  16                                           /*!<GPIOA ODRVR: ODRVR_SINK8 Position */
#define GPIOA_ODRVR_ODRVR_SINK8_Msk  (0x1UL << GPIOA_ODRVR_ODRVR_SINK8_Pos)       /*!<GPIOA ODRVR: ODRVR_SINK8 Mask */

#define GPIOA_ODRVR_ODRVR_SINK9_Pos  18                                           /*!<GPIOA ODRVR: ODRVR_SINK9 Position */
#define GPIOA_ODRVR_ODRVR_SINK9_Msk  (0x1UL << GPIOA_ODRVR_ODRVR_SINK9_Pos)       /*!<GPIOA ODRVR: ODRVR_SINK9 Mask */

#define GPIOA_ODRVR_Msk_ALL          (GPIOA_ODRVR_ODRVR_SINK2_Msk  |\
                                      GPIOA_ODRVR_ODRVR_SINK3_Msk  |\
                                      GPIOA_ODRVR_ODRVR_SINK4_Msk  |\
                                      GPIOA_ODRVR_ODRVR_SINK5_Msk  |\
                                      GPIOA_ODRVR_ODRVR_SINK6_Msk  |\
                                      GPIOA_ODRVR_ODRVR_SINK7_Msk  |\
                                      GPIOA_ODRVR_ODRVR_SINK8_Msk  |\
                                      GPIOA_ODRVR_ODRVR_SINK9_Msk  )

#define GPIOA_PUPDR_PHDR0_Pos        0                                            /*!<GPIOA PUPDR: PHDR0 Position */
#define GPIOA_PUPDR_PHDR0_Msk        (0x1UL /*<< GPIOA_PUPDR_PHDR0_Pos*/)         /*!<GPIOA PUPDR: PHDR0 Mask */

#define GPIOA_PUPDR_PHDR1_Pos        2                                            /*!<GPIOA PUPDR: PHDR1 Position */
#define GPIOA_PUPDR_PHDR1_Msk        (0x1UL << GPIOA_PUPDR_PHDR1_Pos)             /*!<GPIOA PUPDR: PHDR1 Mask */

#define GPIOA_PUPDR_PHDR2_Pos        4                                            /*!<GPIOA PUPDR: PHDR2 Position */
#define GPIOA_PUPDR_PHDR2_Msk        (0x1UL << GPIOA_PUPDR_PHDR2_Pos)             /*!<GPIOA PUPDR: PHDR2 Mask */

#define GPIOA_PUPDR_PHDR3_Pos        6                                            /*!<GPIOA PUPDR: PHDR3 Position */
#define GPIOA_PUPDR_PHDR3_Msk        (0x1UL << GPIOA_PUPDR_PHDR3_Pos)             /*!<GPIOA PUPDR: PHDR3 Mask */

#define GPIOA_PUPDR_PHDR4_Pos        8                                            /*!<GPIOA PUPDR: PHDR4 Position */
#define GPIOA_PUPDR_PHDR4_Msk        (0x1UL << GPIOA_PUPDR_PHDR4_Pos)             /*!<GPIOA PUPDR: PHDR4 Mask */

#define GPIOA_PUPDR_PHDR5_Pos        10                                           /*!<GPIOA PUPDR: PHDR5 Position */
#define GPIOA_PUPDR_PHDR5_Msk        (0x1UL << GPIOA_PUPDR_PHDR5_Pos)             /*!<GPIOA PUPDR: PHDR5 Mask */

#define GPIOA_PUPDR_PHDR6_Pos        12                                           /*!<GPIOA PUPDR: PHDR6 Position */
#define GPIOA_PUPDR_PHDR6_Msk        (0x1UL << GPIOA_PUPDR_PHDR6_Pos)             /*!<GPIOA PUPDR: PHDR6 Mask */

#define GPIOA_PUPDR_PHDR7_Pos        14                                           /*!<GPIOA PUPDR: PHDR7 Position */
#define GPIOA_PUPDR_PHDR7_Msk        (0x1UL << GPIOA_PUPDR_PHDR7_Pos)             /*!<GPIOA PUPDR: PHDR7 Mask */

#define GPIOA_PUPDR_PHDR8_Pos        16                                           /*!<GPIOA PUPDR: PHDR8 Position */
#define GPIOA_PUPDR_PHDR8_Msk        (0x1UL << GPIOA_PUPDR_PHDR8_Pos)             /*!<GPIOA PUPDR: PHDR8 Mask */

#define GPIOA_PUPDR_PHDR9_Pos        18                                           /*!<GPIOA PUPDR: PHDR9 Position */
#define GPIOA_PUPDR_PHDR9_Msk        (0x1UL << GPIOA_PUPDR_PHDR9_Pos)             /*!<GPIOA PUPDR: PHDR9 Mask */

#define GPIOA_PUPDR_PHDR10_Pos       20                                           /*!<GPIOA PUPDR: PHDR10 Position */
#define GPIOA_PUPDR_PHDR10_Msk       (0x1UL << GPIOA_PUPDR_PHDR10_Pos)            /*!<GPIOA PUPDR: PHDR10 Mask */

#define GPIOA_PUPDR_PHDR11_Pos       22                                           /*!<GPIOA PUPDR: PHDR11 Position */
#define GPIOA_PUPDR_PHDR11_Msk       (0x1UL << GPIOA_PUPDR_PHDR11_Pos)            /*!<GPIOA PUPDR: PHDR11 Mask */

#define GPIOA_PUPDR_PHDR12_Pos       24                                           /*!<GPIOA PUPDR: PHDR12 Position */
#define GPIOA_PUPDR_PHDR12_Msk       (0x1UL << GPIOA_PUPDR_PHDR12_Pos)            /*!<GPIOA PUPDR: PHDR12 Mask */

#define GPIOA_PUPDR_PHDR13_Pos       26                                           /*!<GPIOA PUPDR: PHDR13 Position */
#define GPIOA_PUPDR_PHDR13_Msk       (0x1UL << GPIOA_PUPDR_PHDR13_Pos)            /*!<GPIOA PUPDR: PHDR13 Mask */

#define GPIOA_PUPDR_PHDR14_Pos       28                                           /*!<GPIOA PUPDR: PHDR14 Position */
#define GPIOA_PUPDR_PHDR14_Msk       (0x1UL << GPIOA_PUPDR_PHDR14_Pos)            /*!<GPIOA PUPDR: PHDR14 Mask */

#define GPIOA_PUPDR_PHDR15_Pos       30                                           /*!<GPIOA PUPDR: PHDR15 Position */
#define GPIOA_PUPDR_PHDR15_Msk       (0x1UL << GPIOA_PUPDR_PHDR15_Pos)            /*!<GPIOA PUPDR: PHDR15 Mask */

#define GPIOA_PUPDR_Msk_ALL          (GPIOA_PUPDR_PHDR0_Msk        |\
                                      GPIOA_PUPDR_PHDR1_Msk        |\
                                      GPIOA_PUPDR_PHDR2_Msk        |\
                                      GPIOA_PUPDR_PHDR3_Msk        |\
                                      GPIOA_PUPDR_PHDR4_Msk        |\
                                      GPIOA_PUPDR_PHDR5_Msk        |\
                                      GPIOA_PUPDR_PHDR6_Msk        |\
                                      GPIOA_PUPDR_PHDR7_Msk        |\
                                      GPIOA_PUPDR_PHDR8_Msk        |\
                                      GPIOA_PUPDR_PHDR9_Msk        |\
                                      GPIOA_PUPDR_PHDR10_Msk       |\
                                      GPIOA_PUPDR_PHDR11_Msk       |\
                                      GPIOA_PUPDR_PHDR12_Msk       |\
                                      GPIOA_PUPDR_PHDR13_Msk       |\
                                      GPIOA_PUPDR_PHDR14_Msk       |\
                                      GPIOA_PUPDR_PHDR15_Msk       )

#define GPIOA_TTLEN_TTLEN0_Pos       0                                            /*!<GPIOA TTLEN: TTLEN0 Position */
#define GPIOA_TTLEN_TTLEN0_Msk       (0x1UL /*<< GPIOA_TTLEN_TTLEN0_Pos*/)        /*!<GPIOA TTLEN: TTLEN0 Mask */

#define GPIOA_TTLEN_TTLEN1_Pos       1                                            /*!<GPIOA TTLEN: TTLEN1 Position */
#define GPIOA_TTLEN_TTLEN1_Msk       (0x1UL << GPIOA_TTLEN_TTLEN1_Pos)            /*!<GPIOA TTLEN: TTLEN1 Mask */

#define GPIOA_TTLEN_TTLEN2_Pos       2                                            /*!<GPIOA TTLEN: TTLEN2 Position */
#define GPIOA_TTLEN_TTLEN2_Msk       (0x1UL << GPIOA_TTLEN_TTLEN2_Pos)            /*!<GPIOA TTLEN: TTLEN2 Mask */

#define GPIOA_TTLEN_TTLEN3_Pos       3                                            /*!<GPIOA TTLEN: TTLEN3 Position */
#define GPIOA_TTLEN_TTLEN3_Msk       (0x1UL << GPIOA_TTLEN_TTLEN3_Pos)            /*!<GPIOA TTLEN: TTLEN3 Mask */

#define GPIOA_TTLEN_TTLEN4_Pos       4                                            /*!<GPIOA TTLEN: TTLEN4 Position */
#define GPIOA_TTLEN_TTLEN4_Msk       (0x1UL << GPIOA_TTLEN_TTLEN4_Pos)            /*!<GPIOA TTLEN: TTLEN4 Mask */

#define GPIOA_TTLEN_TTLEN5_Pos       5                                            /*!<GPIOA TTLEN: TTLEN5 Position */
#define GPIOA_TTLEN_TTLEN5_Msk       (0x1UL << GPIOA_TTLEN_TTLEN5_Pos)            /*!<GPIOA TTLEN: TTLEN5 Mask */

#define GPIOA_TTLEN_TTLEN6_Pos       6                                            /*!<GPIOA TTLEN: TTLEN6 Position */
#define GPIOA_TTLEN_TTLEN6_Msk       (0x1UL << GPIOA_TTLEN_TTLEN6_Pos)            /*!<GPIOA TTLEN: TTLEN6 Mask */

#define GPIOA_TTLEN_TTLEN7_Pos       7                                            /*!<GPIOA TTLEN: TTLEN7 Position */
#define GPIOA_TTLEN_TTLEN7_Msk       (0x1UL << GPIOA_TTLEN_TTLEN7_Pos)            /*!<GPIOA TTLEN: TTLEN7 Mask */

#define GPIOA_TTLEN_TTLEN8_Pos       8                                            /*!<GPIOA TTLEN: TTLEN8 Position */
#define GPIOA_TTLEN_TTLEN8_Msk       (0x1UL << GPIOA_TTLEN_TTLEN8_Pos)            /*!<GPIOA TTLEN: TTLEN8 Mask */

#define GPIOA_TTLEN_TTLEN9_Pos       9                                            /*!<GPIOA TTLEN: TTLEN9 Position */
#define GPIOA_TTLEN_TTLEN9_Msk       (0x1UL << GPIOA_TTLEN_TTLEN9_Pos)            /*!<GPIOA TTLEN: TTLEN9 Mask */

#define GPIOA_TTLEN_TTLEN10_Pos      10                                           /*!<GPIOA TTLEN: TTLEN10 Position */
#define GPIOA_TTLEN_TTLEN10_Msk      (0x1UL << GPIOA_TTLEN_TTLEN10_Pos)           /*!<GPIOA TTLEN: TTLEN10 Mask */

#define GPIOA_TTLEN_TTLEN11_Pos      11                                           /*!<GPIOA TTLEN: TTLEN11 Position */
#define GPIOA_TTLEN_TTLEN11_Msk      (0x1UL << GPIOA_TTLEN_TTLEN11_Pos)           /*!<GPIOA TTLEN: TTLEN11 Mask */

#define GPIOA_TTLEN_TTLEN12_Pos      12                                           /*!<GPIOA TTLEN: TTLEN12 Position */
#define GPIOA_TTLEN_TTLEN12_Msk      (0x1UL << GPIOA_TTLEN_TTLEN12_Pos)           /*!<GPIOA TTLEN: TTLEN12 Mask */

#define GPIOA_TTLEN_TTLEN13_Pos      13                                           /*!<GPIOA TTLEN: TTLEN13 Position */
#define GPIOA_TTLEN_TTLEN13_Msk      (0x1UL << GPIOA_TTLEN_TTLEN13_Pos)           /*!<GPIOA TTLEN: TTLEN13 Mask */

#define GPIOA_TTLEN_TTLEN14_Pos      14                                           /*!<GPIOA TTLEN: TTLEN14 Position */
#define GPIOA_TTLEN_TTLEN14_Msk      (0x1UL << GPIOA_TTLEN_TTLEN14_Pos)           /*!<GPIOA TTLEN: TTLEN14 Mask */

#define GPIOA_TTLEN_TTLEN15_Pos      15                                           /*!<GPIOA TTLEN: TTLEN15 Position */
#define GPIOA_TTLEN_TTLEN15_Msk      (0x1UL << GPIOA_TTLEN_TTLEN15_Pos)           /*!<GPIOA TTLEN: TTLEN15 Mask */

#define GPIOA_TTLEN_Msk_ALL          (GPIOA_TTLEN_TTLEN0_Msk       |\
                                      GPIOA_TTLEN_TTLEN1_Msk       |\
                                      GPIOA_TTLEN_TTLEN2_Msk       |\
                                      GPIOA_TTLEN_TTLEN3_Msk       |\
                                      GPIOA_TTLEN_TTLEN4_Msk       |\
                                      GPIOA_TTLEN_TTLEN5_Msk       |\
                                      GPIOA_TTLEN_TTLEN6_Msk       |\
                                      GPIOA_TTLEN_TTLEN7_Msk       |\
                                      GPIOA_TTLEN_TTLEN8_Msk       |\
                                      GPIOA_TTLEN_TTLEN9_Msk       |\
                                      GPIOA_TTLEN_TTLEN10_Msk      |\
                                      GPIOA_TTLEN_TTLEN11_Msk      |\
                                      GPIOA_TTLEN_TTLEN12_Msk      |\
                                      GPIOA_TTLEN_TTLEN13_Msk      |\
                                      GPIOA_TTLEN_TTLEN14_Msk      |\
                                      GPIOA_TTLEN_TTLEN15_Msk      )

#define GPIOA_AFRL_AFR0_Pos          0                                            /*!<GPIOA AFRL: AFR0 Position */
#define GPIOA_AFRL_AFR0_Msk          (0xFUL /*<< GPIOA_AFRL_AFR0_Pos*/)           /*!<GPIOA AFRL: AFR0 Mask */

#define GPIOA_AFRL_AFR1_Pos          4                                            /*!<GPIOA AFRL: AFR1 Position */
#define GPIOA_AFRL_AFR1_Msk          (0xFUL << GPIOA_AFRL_AFR1_Pos)               /*!<GPIOA AFRL: AFR1 Mask */

#define GPIOA_AFRL_AFR2_Pos          8                                            /*!<GPIOA AFRL: AFR2 Position */
#define GPIOA_AFRL_AFR2_Msk          (0xFUL << GPIOA_AFRL_AFR2_Pos)               /*!<GPIOA AFRL: AFR2 Mask */

#define GPIOA_AFRL_AFR3_Pos          12                                           /*!<GPIOA AFRL: AFR3 Position */
#define GPIOA_AFRL_AFR3_Msk          (0xFUL << GPIOA_AFRL_AFR3_Pos)               /*!<GPIOA AFRL: AFR3 Mask */

#define GPIOA_AFRL_AFR4_Pos          16                                           /*!<GPIOA AFRL: AFR4 Position */
#define GPIOA_AFRL_AFR4_Msk          (0xFUL << GPIOA_AFRL_AFR4_Pos)               /*!<GPIOA AFRL: AFR4 Mask */

#define GPIOA_AFRL_AFR5_Pos          20                                           /*!<GPIOA AFRL: AFR5 Position */
#define GPIOA_AFRL_AFR5_Msk          (0xFUL << GPIOA_AFRL_AFR5_Pos)               /*!<GPIOA AFRL: AFR5 Mask */

#define GPIOA_AFRL_AFR6_Pos          24                                           /*!<GPIOA AFRL: AFR6 Position */
#define GPIOA_AFRL_AFR6_Msk          (0xFUL << GPIOA_AFRL_AFR6_Pos)               /*!<GPIOA AFRL: AFR6 Mask */

#define GPIOA_AFRL_AFR7_Pos          28                                           /*!<GPIOA AFRL: AFR7 Position */
#define GPIOA_AFRL_AFR7_Msk          (0xFUL << GPIOA_AFRL_AFR7_Pos)               /*!<GPIOA AFRL: AFR7 Mask */

#define GPIOA_AFRL_Msk_ALL           (GPIOA_AFRL_AFR0_Msk          |\
                                      GPIOA_AFRL_AFR1_Msk          |\
                                      GPIOA_AFRL_AFR2_Msk          |\
                                      GPIOA_AFRL_AFR3_Msk          |\
                                      GPIOA_AFRL_AFR4_Msk          |\
                                      GPIOA_AFRL_AFR5_Msk          |\
                                      GPIOA_AFRL_AFR6_Msk          |\
                                      GPIOA_AFRL_AFR7_Msk          )

#define GPIOA_AFRH_AFR8_Pos          0                                            /*!<GPIOA AFRH: AFR8 Position */
#define GPIOA_AFRH_AFR8_Msk          (0xFUL /*<< GPIOA_AFRH_AFR8_Pos*/)           /*!<GPIOA AFRH: AFR8 Mask */

#define GPIOA_AFRH_AFR9_Pos          4                                            /*!<GPIOA AFRH: AFR9 Position */
#define GPIOA_AFRH_AFR9_Msk          (0xFUL << GPIOA_AFRH_AFR9_Pos)               /*!<GPIOA AFRH: AFR9 Mask */

#define GPIOA_AFRH_AFR10_Pos         8                                            /*!<GPIOA AFRH: AFR10 Position */
#define GPIOA_AFRH_AFR10_Msk         (0xFUL << GPIOA_AFRH_AFR10_Pos)              /*!<GPIOA AFRH: AFR10 Mask */

#define GPIOA_AFRH_AFR11_Pos         12                                           /*!<GPIOA AFRH: AFR11 Position */
#define GPIOA_AFRH_AFR11_Msk         (0xFUL << GPIOA_AFRH_AFR11_Pos)              /*!<GPIOA AFRH: AFR11 Mask */

#define GPIOA_AFRH_AFR12_Pos         16                                           /*!<GPIOA AFRH: AFR12 Position */
#define GPIOA_AFRH_AFR12_Msk         (0xFUL << GPIOA_AFRH_AFR12_Pos)              /*!<GPIOA AFRH: AFR12 Mask */

#define GPIOA_AFRH_AFR13_Pos         20                                           /*!<GPIOA AFRH: AFR13 Position */
#define GPIOA_AFRH_AFR13_Msk         (0xFUL << GPIOA_AFRH_AFR13_Pos)              /*!<GPIOA AFRH: AFR13 Mask */

#define GPIOA_AFRH_AFR14_Pos         24                                           /*!<GPIOA AFRH: AFR14 Position */
#define GPIOA_AFRH_AFR14_Msk         (0xFUL << GPIOA_AFRH_AFR14_Pos)              /*!<GPIOA AFRH: AFR14 Mask */

#define GPIOA_AFRH_AFR15_Pos         28                                           /*!<GPIOA AFRH: AFR15 Position */
#define GPIOA_AFRH_AFR15_Msk         (0xFUL << GPIOA_AFRH_AFR15_Pos)              /*!<GPIOA AFRH: AFR15 Mask */

#define GPIOA_AFRH_Msk_ALL           (GPIOA_AFRH_AFR8_Msk          |\
                                      GPIOA_AFRH_AFR9_Msk          |\
                                      GPIOA_AFRH_AFR10_Msk         |\
                                      GPIOA_AFRH_AFR11_Msk         |\
                                      GPIOA_AFRH_AFR12_Msk         |\
                                      GPIOA_AFRH_AFR13_Msk         |\
                                      GPIOA_AFRH_AFR14_Msk         |\
                                      GPIOA_AFRH_AFR15_Msk         )

#define GPIOB_MODER_MODER0_Pos       0                                            /*!<GPIOB MODER: MODER0 Position */
#define GPIOB_MODER_MODER0_Msk       (0x1UL /*<< GPIOB_MODER_MODER0_Pos*/)        /*!<GPIOB MODER: MODER0 Mask */

#define GPIOB_MODER_MODER1_Pos       1                                            /*!<GPIOB MODER: MODER1 Position */
#define GPIOB_MODER_MODER1_Msk       (0x1UL << GPIOB_MODER_MODER1_Pos)            /*!<GPIOB MODER: MODER1 Mask */

#define GPIOB_MODER_MODER2_Pos       2                                            /*!<GPIOB MODER: MODER2 Position */
#define GPIOB_MODER_MODER2_Msk       (0x1UL << GPIOB_MODER_MODER2_Pos)            /*!<GPIOB MODER: MODER2 Mask */

#define GPIOB_MODER_MODER3_Pos       3                                            /*!<GPIOB MODER: MODER3 Position */
#define GPIOB_MODER_MODER3_Msk       (0x1UL << GPIOB_MODER_MODER3_Pos)            /*!<GPIOB MODER: MODER3 Mask */

#define GPIOB_MODER_MODER4_Pos       4                                            /*!<GPIOB MODER: MODER4 Position */
#define GPIOB_MODER_MODER4_Msk       (0x1UL << GPIOB_MODER_MODER4_Pos)            /*!<GPIOB MODER: MODER4 Mask */

#define GPIOB_MODER_MODER5_Pos       5                                            /*!<GPIOB MODER: MODER5 Position */
#define GPIOB_MODER_MODER5_Msk       (0x1UL << GPIOB_MODER_MODER5_Pos)            /*!<GPIOB MODER: MODER5 Mask */

#define GPIOB_MODER_MODER6_Pos       6                                            /*!<GPIOB MODER: MODER6 Position */
#define GPIOB_MODER_MODER6_Msk       (0x1UL << GPIOB_MODER_MODER6_Pos)            /*!<GPIOB MODER: MODER6 Mask */

#define GPIOB_MODER_MODER7_Pos       7                                            /*!<GPIOB MODER: MODER7 Position */
#define GPIOB_MODER_MODER7_Msk       (0x1UL << GPIOB_MODER_MODER7_Pos)            /*!<GPIOB MODER: MODER7 Mask */

#define GPIOB_MODER_MODER8_Pos       8                                            /*!<GPIOB MODER: MODER8 Position */
#define GPIOB_MODER_MODER8_Msk       (0x1UL << GPIOB_MODER_MODER8_Pos)            /*!<GPIOB MODER: MODER8 Mask */

#define GPIOB_MODER_MODER9_Pos       9                                            /*!<GPIOB MODER: MODER9 Position */
#define GPIOB_MODER_MODER9_Msk       (0x1UL << GPIOB_MODER_MODER9_Pos)            /*!<GPIOB MODER: MODER9 Mask */

#define GPIOB_MODER_MODER10_Pos      10                                           /*!<GPIOB MODER: MODER10 Position */
#define GPIOB_MODER_MODER10_Msk      (0x1UL << GPIOB_MODER_MODER10_Pos)           /*!<GPIOB MODER: MODER10 Mask */

#define GPIOB_MODER_MODER11_Pos      11                                           /*!<GPIOB MODER: MODER11 Position */
#define GPIOB_MODER_MODER11_Msk      (0x1UL << GPIOB_MODER_MODER11_Pos)           /*!<GPIOB MODER: MODER11 Mask */

#define GPIOB_MODER_MODER12_Pos      12                                           /*!<GPIOB MODER: MODER12 Position */
#define GPIOB_MODER_MODER12_Msk      (0x1UL << GPIOB_MODER_MODER12_Pos)           /*!<GPIOB MODER: MODER12 Mask */

#define GPIOB_MODER_MODER13_Pos      13                                           /*!<GPIOB MODER: MODER13 Position */
#define GPIOB_MODER_MODER13_Msk      (0x1UL << GPIOB_MODER_MODER13_Pos)           /*!<GPIOB MODER: MODER13 Mask */

#define GPIOB_MODER_MODER14_Pos      14                                           /*!<GPIOB MODER: MODER14 Position */
#define GPIOB_MODER_MODER14_Msk      (0x1UL << GPIOB_MODER_MODER14_Pos)           /*!<GPIOB MODER: MODER14 Mask */

#define GPIOB_MODER_MODER15_Pos      15                                           /*!<GPIOB MODER: MODER15 Position */
#define GPIOB_MODER_MODER15_Msk      (0x1UL << GPIOB_MODER_MODER15_Pos)           /*!<GPIOB MODER: MODER15 Mask */

#define GPIOB_MODER_Msk_ALL          (GPIOB_MODER_MODER0_Msk       |\
                                      GPIOB_MODER_MODER1_Msk       |\
                                      GPIOB_MODER_MODER2_Msk       |\
                                      GPIOB_MODER_MODER3_Msk       |\
                                      GPIOB_MODER_MODER4_Msk       |\
                                      GPIOB_MODER_MODER5_Msk       |\
                                      GPIOB_MODER_MODER6_Msk       |\
                                      GPIOB_MODER_MODER7_Msk       |\
                                      GPIOB_MODER_MODER8_Msk       |\
                                      GPIOB_MODER_MODER9_Msk       |\
                                      GPIOB_MODER_MODER10_Msk      |\
                                      GPIOB_MODER_MODER11_Msk      |\
                                      GPIOB_MODER_MODER12_Msk      |\
                                      GPIOB_MODER_MODER13_Msk      |\
                                      GPIOB_MODER_MODER14_Msk      |\
                                      GPIOB_MODER_MODER15_Msk      )

#define GPIOB_IDR_IDR_Pos            0                                            /*!<GPIOB IDR: IDR Position */
#define GPIOB_IDR_IDR_Msk            (0xFFFFUL /*<< GPIOB_IDR_IDR_Pos*/)          /*!<GPIOB IDR: IDR Mask */

#define GPIOB_IDR_Msk_ALL            (GPIOB_IDR_IDR_Msk           )

#define GPIOB_ODR_ODR_Pos            0                                            /*!<GPIOB ODR: ODR Position */
#define GPIOB_ODR_ODR_Msk            (0xFFFFUL /*<< GPIOB_ODR_ODR_Pos*/)          /*!<GPIOB ODR: ODR Mask */

#define GPIOB_ODR_Msk_ALL            (GPIOB_ODR_ODR_Msk           )

#define GPIOB_BSRR_BS_Pos            0                                            /*!<GPIOB BSRR: BS Position */
#define GPIOB_BSRR_BS_Msk            (0xFFFFUL /*<< GPIOB_BSRR_BS_Pos*/)          /*!<GPIOB BSRR: BS Mask */

#define GPIOB_BSRR_BR_Pos            16                                           /*!<GPIOB BSRR: BR Position */
#define GPIOB_BSRR_BR_Msk            (0xFFFFUL << GPIOB_BSRR_BR_Pos)              /*!<GPIOB BSRR: BR Mask */

#define GPIOB_BSRR_Msk_ALL           (GPIOB_BSRR_BS_Msk            |\
                                      GPIOB_BSRR_BR_Msk            )

#define GPIOB_LCKR_LCK0_Pos          0                                            /*!<GPIOB LCKR: LCK0 Position */
#define GPIOB_LCKR_LCK0_Msk          (0x1UL /*<< GPIOB_LCKR_LCK0_Pos*/)           /*!<GPIOB LCKR: LCK0 Mask */

#define GPIOB_LCKR_LCK1_Pos          1                                            /*!<GPIOB LCKR: LCK1 Position */
#define GPIOB_LCKR_LCK1_Msk          (0x1UL << GPIOB_LCKR_LCK1_Pos)               /*!<GPIOB LCKR: LCK1 Mask */

#define GPIOB_LCKR_LCK2_Pos          2                                            /*!<GPIOB LCKR: LCK2 Position */
#define GPIOB_LCKR_LCK2_Msk          (0x1UL << GPIOB_LCKR_LCK2_Pos)               /*!<GPIOB LCKR: LCK2 Mask */

#define GPIOB_LCKR_LCK3_Pos          3                                            /*!<GPIOB LCKR: LCK3 Position */
#define GPIOB_LCKR_LCK3_Msk          (0x1UL << GPIOB_LCKR_LCK3_Pos)               /*!<GPIOB LCKR: LCK3 Mask */

#define GPIOB_LCKR_LCK4_Pos          4                                            /*!<GPIOB LCKR: LCK4 Position */
#define GPIOB_LCKR_LCK4_Msk          (0x1UL << GPIOB_LCKR_LCK4_Pos)               /*!<GPIOB LCKR: LCK4 Mask */

#define GPIOB_LCKR_LCK5_Pos          5                                            /*!<GPIOB LCKR: LCK5 Position */
#define GPIOB_LCKR_LCK5_Msk          (0x1UL << GPIOB_LCKR_LCK5_Pos)               /*!<GPIOB LCKR: LCK5 Mask */

#define GPIOB_LCKR_LCK6_Pos          6                                            /*!<GPIOB LCKR: LCK6 Position */
#define GPIOB_LCKR_LCK6_Msk          (0x1UL << GPIOB_LCKR_LCK6_Pos)               /*!<GPIOB LCKR: LCK6 Mask */

#define GPIOB_LCKR_LCK7_Pos          7                                            /*!<GPIOB LCKR: LCK7 Position */
#define GPIOB_LCKR_LCK7_Msk          (0x1UL << GPIOB_LCKR_LCK7_Pos)               /*!<GPIOB LCKR: LCK7 Mask */

#define GPIOB_LCKR_LCK8_Pos          8                                            /*!<GPIOB LCKR: LCK8 Position */
#define GPIOB_LCKR_LCK8_Msk          (0x1UL << GPIOB_LCKR_LCK8_Pos)               /*!<GPIOB LCKR: LCK8 Mask */

#define GPIOB_LCKR_LCK9_Pos          9                                            /*!<GPIOB LCKR: LCK9 Position */
#define GPIOB_LCKR_LCK9_Msk          (0x1UL << GPIOB_LCKR_LCK9_Pos)               /*!<GPIOB LCKR: LCK9 Mask */

#define GPIOB_LCKR_LCK10_Pos         10                                           /*!<GPIOB LCKR: LCK10 Position */
#define GPIOB_LCKR_LCK10_Msk         (0x1UL << GPIOB_LCKR_LCK10_Pos)              /*!<GPIOB LCKR: LCK10 Mask */

#define GPIOB_LCKR_LCK11_Pos         11                                           /*!<GPIOB LCKR: LCK11 Position */
#define GPIOB_LCKR_LCK11_Msk         (0x1UL << GPIOB_LCKR_LCK11_Pos)              /*!<GPIOB LCKR: LCK11 Mask */

#define GPIOB_LCKR_LCK12_Pos         12                                           /*!<GPIOB LCKR: LCK12 Position */
#define GPIOB_LCKR_LCK12_Msk         (0x1UL << GPIOB_LCKR_LCK12_Pos)              /*!<GPIOB LCKR: LCK12 Mask */

#define GPIOB_LCKR_LCK13_Pos         13                                           /*!<GPIOB LCKR: LCK13 Position */
#define GPIOB_LCKR_LCK13_Msk         (0x1UL << GPIOB_LCKR_LCK13_Pos)              /*!<GPIOB LCKR: LCK13 Mask */

#define GPIOB_LCKR_LCK14_Pos         14                                           /*!<GPIOB LCKR: LCK14 Position */
#define GPIOB_LCKR_LCK14_Msk         (0x1UL << GPIOB_LCKR_LCK14_Pos)              /*!<GPIOB LCKR: LCK14 Mask */

#define GPIOB_LCKR_LCK15_Pos         15                                           /*!<GPIOB LCKR: LCK15 Position */
#define GPIOB_LCKR_LCK15_Msk         (0x1UL << GPIOB_LCKR_LCK15_Pos)              /*!<GPIOB LCKR: LCK15 Mask */

#define GPIOB_LCKR_LOCK_Pos          16                                           /*!<GPIOB LCKR: LOCK Position */
#define GPIOB_LCKR_LOCK_Msk          (0xFFFFUL << GPIOB_LCKR_LOCK_Pos)            /*!<GPIOB LCKR: LOCK Mask */

#define GPIOB_LCKR_Msk_ALL           (GPIOB_LCKR_LCK0_Msk          |\
                                      GPIOB_LCKR_LCK1_Msk          |\
                                      GPIOB_LCKR_LCK2_Msk          |\
                                      GPIOB_LCKR_LCK3_Msk          |\
                                      GPIOB_LCKR_LCK4_Msk          |\
                                      GPIOB_LCKR_LCK5_Msk          |\
                                      GPIOB_LCKR_LCK6_Msk          |\
                                      GPIOB_LCKR_LCK7_Msk          |\
                                      GPIOB_LCKR_LCK8_Msk          |\
                                      GPIOB_LCKR_LCK9_Msk          |\
                                      GPIOB_LCKR_LCK10_Msk         |\
                                      GPIOB_LCKR_LCK11_Msk         |\
                                      GPIOB_LCKR_LCK12_Msk         |\
                                      GPIOB_LCKR_LCK13_Msk         |\
                                      GPIOB_LCKR_LCK14_Msk         |\
                                      GPIOB_LCKR_LCK15_Msk         |\
                                      GPIOB_LCKR_LOCK_Msk          )

#define GPIOB_IE_IE0_Pos             0                                            /*!<GPIOB IE: IE0 Position */
#define GPIOB_IE_IE0_Msk             (0x1UL /*<< GPIOB_IE_IE0_Pos*/)              /*!<GPIOB IE: IE0 Mask */

#define GPIOB_IE_IE1_Pos             1                                            /*!<GPIOB IE: IE1 Position */
#define GPIOB_IE_IE1_Msk             (0x1UL << GPIOB_IE_IE1_Pos)                  /*!<GPIOB IE: IE1 Mask */

#define GPIOB_IE_IE2_Pos             2                                            /*!<GPIOB IE: IE2 Position */
#define GPIOB_IE_IE2_Msk             (0x1UL << GPIOB_IE_IE2_Pos)                  /*!<GPIOB IE: IE2 Mask */

#define GPIOB_IE_IE3_Pos             3                                            /*!<GPIOB IE: IE3 Position */
#define GPIOB_IE_IE3_Msk             (0x1UL << GPIOB_IE_IE3_Pos)                  /*!<GPIOB IE: IE3 Mask */

#define GPIOB_IE_IE4_Pos             4                                            /*!<GPIOB IE: IE4 Position */
#define GPIOB_IE_IE4_Msk             (0x1UL << GPIOB_IE_IE4_Pos)                  /*!<GPIOB IE: IE4 Mask */

#define GPIOB_IE_IE5_Pos             5                                            /*!<GPIOB IE: IE5 Position */
#define GPIOB_IE_IE5_Msk             (0x1UL << GPIOB_IE_IE5_Pos)                  /*!<GPIOB IE: IE5 Mask */

#define GPIOB_IE_IE6_Pos             6                                            /*!<GPIOB IE: IE6 Position */
#define GPIOB_IE_IE6_Msk             (0x1UL << GPIOB_IE_IE6_Pos)                  /*!<GPIOB IE: IE6 Mask */

#define GPIOB_IE_IE7_Pos             7                                            /*!<GPIOB IE: IE7 Position */
#define GPIOB_IE_IE7_Msk             (0x1UL << GPIOB_IE_IE7_Pos)                  /*!<GPIOB IE: IE7 Mask */

#define GPIOB_IE_IE8_Pos             8                                            /*!<GPIOB IE: IE8 Position */
#define GPIOB_IE_IE8_Msk             (0x1UL << GPIOB_IE_IE8_Pos)                  /*!<GPIOB IE: IE8 Mask */

#define GPIOB_IE_IE9_Pos             9                                            /*!<GPIOB IE: IE9 Position */
#define GPIOB_IE_IE9_Msk             (0x1UL << GPIOB_IE_IE9_Pos)                  /*!<GPIOB IE: IE9 Mask */

#define GPIOB_IE_IE10_Pos            10                                           /*!<GPIOB IE: IE10 Position */
#define GPIOB_IE_IE10_Msk            (0x1UL << GPIOB_IE_IE10_Pos)                 /*!<GPIOB IE: IE10 Mask */

#define GPIOB_IE_IE11_Pos            11                                           /*!<GPIOB IE: IE11 Position */
#define GPIOB_IE_IE11_Msk            (0x1UL << GPIOB_IE_IE11_Pos)                 /*!<GPIOB IE: IE11 Mask */

#define GPIOB_IE_IE12_Pos            12                                           /*!<GPIOB IE: IE12 Position */
#define GPIOB_IE_IE12_Msk            (0x1UL << GPIOB_IE_IE12_Pos)                 /*!<GPIOB IE: IE12 Mask */

#define GPIOB_IE_IE13_Pos            13                                           /*!<GPIOB IE: IE13 Position */
#define GPIOB_IE_IE13_Msk            (0x1UL << GPIOB_IE_IE13_Pos)                 /*!<GPIOB IE: IE13 Mask */

#define GPIOB_IE_IE14_Pos            14                                           /*!<GPIOB IE: IE14 Position */
#define GPIOB_IE_IE14_Msk            (0x1UL << GPIOB_IE_IE14_Pos)                 /*!<GPIOB IE: IE14 Mask */

#define GPIOB_IE_IE15_Pos            15                                           /*!<GPIOB IE: IE15 Position */
#define GPIOB_IE_IE15_Msk            (0x1UL << GPIOB_IE_IE15_Pos)                 /*!<GPIOB IE: IE15 Mask */

#define GPIOB_IE_Msk_ALL             (GPIOB_IE_IE0_Msk             |\
                                      GPIOB_IE_IE1_Msk             |\
                                      GPIOB_IE_IE2_Msk             |\
                                      GPIOB_IE_IE3_Msk             |\
                                      GPIOB_IE_IE4_Msk             |\
                                      GPIOB_IE_IE5_Msk             |\
                                      GPIOB_IE_IE6_Msk             |\
                                      GPIOB_IE_IE7_Msk             |\
                                      GPIOB_IE_IE8_Msk             |\
                                      GPIOB_IE_IE9_Msk             |\
                                      GPIOB_IE_IE10_Msk            |\
                                      GPIOB_IE_IE11_Msk            |\
                                      GPIOB_IE_IE12_Msk            |\
                                      GPIOB_IE_IE13_Msk            |\
                                      GPIOB_IE_IE14_Msk            |\
                                      GPIOB_IE_IE15_Msk            )

#define GPIOB_OTYPER_OT4_Pos         4                                            /*!<GPIOB OTYPER: OT4 Position */
#define GPIOB_OTYPER_OT4_Msk         (0x1UL << GPIOB_OTYPER_OT4_Pos)              /*!<GPIOB OTYPER: OT4 Mask */

#define GPIOB_OTYPER_OT5_Pos         5                                            /*!<GPIOB OTYPER: OT5 Position */
#define GPIOB_OTYPER_OT5_Msk         (0x1UL << GPIOB_OTYPER_OT5_Pos)              /*!<GPIOB OTYPER: OT5 Mask */

#define GPIOB_OTYPER_OT6_Pos         6                                            /*!<GPIOB OTYPER: OT6 Position */
#define GPIOB_OTYPER_OT6_Msk         (0x1UL << GPIOB_OTYPER_OT6_Pos)              /*!<GPIOB OTYPER: OT6 Mask */

#define GPIOB_OTYPER_OT7_Pos         7                                            /*!<GPIOB OTYPER: OT7 Position */
#define GPIOB_OTYPER_OT7_Msk         (0x1UL << GPIOB_OTYPER_OT7_Pos)              /*!<GPIOB OTYPER: OT7 Mask */

#define GPIOB_OTYPER_OT8_Pos         8                                            /*!<GPIOB OTYPER: OT8 Position */
#define GPIOB_OTYPER_OT8_Msk         (0x1UL << GPIOB_OTYPER_OT8_Pos)              /*!<GPIOB OTYPER: OT8 Mask */

#define GPIOB_OTYPER_OT9_Pos         9                                            /*!<GPIOB OTYPER: OT9 Position */
#define GPIOB_OTYPER_OT9_Msk         (0x1UL << GPIOB_OTYPER_OT9_Pos)              /*!<GPIOB OTYPER: OT9 Mask */

#define GPIOB_OTYPER_OT10_Pos        10                                           /*!<GPIOB OTYPER: OT10 Position */
#define GPIOB_OTYPER_OT10_Msk        (0x1UL << GPIOB_OTYPER_OT10_Pos)             /*!<GPIOB OTYPER: OT10 Mask */

#define GPIOB_OTYPER_OT12_Pos        12                                           /*!<GPIOB OTYPER: OT12 Position */
#define GPIOB_OTYPER_OT12_Msk        (0x1UL << GPIOB_OTYPER_OT12_Pos)             /*!<GPIOB OTYPER: OT12 Mask */

#define GPIOB_OTYPER_OT13_Pos        13                                           /*!<GPIOB OTYPER: OT13 Position */
#define GPIOB_OTYPER_OT13_Msk        (0x1UL << GPIOB_OTYPER_OT13_Pos)             /*!<GPIOB OTYPER: OT13 Mask */

#define GPIOB_OTYPER_OT14_Pos        14                                           /*!<GPIOB OTYPER: OT14 Position */
#define GPIOB_OTYPER_OT14_Msk        (0x1UL << GPIOB_OTYPER_OT14_Pos)             /*!<GPIOB OTYPER: OT14 Mask */

#define GPIOB_OTYPER_OT15_Pos        15                                           /*!<GPIOB OTYPER: OT15 Position */
#define GPIOB_OTYPER_OT15_Msk        (0x1UL << GPIOB_OTYPER_OT15_Pos)             /*!<GPIOB OTYPER: OT15 Mask */

#define GPIOB_OTYPER_Msk_ALL         (GPIOB_OTYPER_OT4_Msk         |\
                                      GPIOB_OTYPER_OT5_Msk         |\
                                      GPIOB_OTYPER_OT6_Msk         |\
                                      GPIOB_OTYPER_OT7_Msk         |\
                                      GPIOB_OTYPER_OT8_Msk         |\
                                      GPIOB_OTYPER_OT9_Msk         |\
                                      GPIOB_OTYPER_OT10_Msk        |\
                                      GPIOB_OTYPER_OT12_Msk        |\
                                      GPIOB_OTYPER_OT13_Msk        |\
                                      GPIOB_OTYPER_OT14_Msk        |\
                                      GPIOB_OTYPER_OT15_Msk        )

#define GPIOB_ODRVR_ODRVR_SINK2_Pos  4                                            /*!<GPIOB ODRVR: ODRVR_SINK2 Position */
#define GPIOB_ODRVR_ODRVR_SINK2_Msk  (0x1UL << GPIOB_ODRVR_ODRVR_SINK2_Pos)       /*!<GPIOB ODRVR: ODRVR_SINK2 Mask */

#define GPIOB_ODRVR_ODRVR_SINK3_Pos  6                                            /*!<GPIOB ODRVR: ODRVR_SINK3 Position */
#define GPIOB_ODRVR_ODRVR_SINK3_Msk  (0x1UL << GPIOB_ODRVR_ODRVR_SINK3_Pos)       /*!<GPIOB ODRVR: ODRVR_SINK3 Mask */

#define GPIOB_ODRVR_ODRVR_SINK4_Pos  8                                            /*!<GPIOB ODRVR: ODRVR_SINK4 Position */
#define GPIOB_ODRVR_ODRVR_SINK4_Msk  (0x1UL << GPIOB_ODRVR_ODRVR_SINK4_Pos)       /*!<GPIOB ODRVR: ODRVR_SINK4 Mask */

#define GPIOB_ODRVR_ODRVR_SINK5_Pos  10                                           /*!<GPIOB ODRVR: ODRVR_SINK5 Position */
#define GPIOB_ODRVR_ODRVR_SINK5_Msk  (0x1UL << GPIOB_ODRVR_ODRVR_SINK5_Pos)       /*!<GPIOB ODRVR: ODRVR_SINK5 Mask */

#define GPIOB_ODRVR_ODRVR_SINK6_Pos  12                                           /*!<GPIOB ODRVR: ODRVR_SINK6 Position */
#define GPIOB_ODRVR_ODRVR_SINK6_Msk  (0x1UL << GPIOB_ODRVR_ODRVR_SINK6_Pos)       /*!<GPIOB ODRVR: ODRVR_SINK6 Mask */

#define GPIOB_ODRVR_ODRVR_SINK7_Pos  14                                           /*!<GPIOB ODRVR: ODRVR_SINK7 Position */
#define GPIOB_ODRVR_ODRVR_SINK7_Msk  (0x1UL << GPIOB_ODRVR_ODRVR_SINK7_Pos)       /*!<GPIOB ODRVR: ODRVR_SINK7 Mask */

#define GPIOB_ODRVR_ODRVR_SINK8_Pos  16                                           /*!<GPIOB ODRVR: ODRVR_SINK8 Position */
#define GPIOB_ODRVR_ODRVR_SINK8_Msk  (0x1UL << GPIOB_ODRVR_ODRVR_SINK8_Pos)       /*!<GPIOB ODRVR: ODRVR_SINK8 Mask */

#define GPIOB_ODRVR_ODRVR_SINK9_Pos  18                                           /*!<GPIOB ODRVR: ODRVR_SINK9 Position */
#define GPIOB_ODRVR_ODRVR_SINK9_Msk  (0x1UL << GPIOB_ODRVR_ODRVR_SINK9_Pos)       /*!<GPIOB ODRVR: ODRVR_SINK9 Mask */

#define GPIOB_ODRVR_Msk_ALL          (GPIOB_ODRVR_ODRVR_SINK2_Msk  |\
                                      GPIOB_ODRVR_ODRVR_SINK3_Msk  |\
                                      GPIOB_ODRVR_ODRVR_SINK4_Msk  |\
                                      GPIOB_ODRVR_ODRVR_SINK5_Msk  |\
                                      GPIOB_ODRVR_ODRVR_SINK6_Msk  |\
                                      GPIOB_ODRVR_ODRVR_SINK7_Msk  |\
                                      GPIOB_ODRVR_ODRVR_SINK8_Msk  |\
                                      GPIOB_ODRVR_ODRVR_SINK9_Msk  )

#define GPIOB_PUPDR_PHDR0_Pos        0                                            /*!<GPIOB PUPDR: PHDR0 Position */
#define GPIOB_PUPDR_PHDR0_Msk        (0x1UL /*<< GPIOB_PUPDR_PHDR0_Pos*/)         /*!<GPIOB PUPDR: PHDR0 Mask */

#define GPIOB_PUPDR_PHDR1_Pos        2                                            /*!<GPIOB PUPDR: PHDR1 Position */
#define GPIOB_PUPDR_PHDR1_Msk        (0x1UL << GPIOB_PUPDR_PHDR1_Pos)             /*!<GPIOB PUPDR: PHDR1 Mask */

#define GPIOB_PUPDR_PHDR2_Pos        4                                            /*!<GPIOB PUPDR: PHDR2 Position */
#define GPIOB_PUPDR_PHDR2_Msk        (0x1UL << GPIOB_PUPDR_PHDR2_Pos)             /*!<GPIOB PUPDR: PHDR2 Mask */

#define GPIOB_PUPDR_PHDR3_Pos        6                                            /*!<GPIOB PUPDR: PHDR3 Position */
#define GPIOB_PUPDR_PHDR3_Msk        (0x1UL << GPIOB_PUPDR_PHDR3_Pos)             /*!<GPIOB PUPDR: PHDR3 Mask */

#define GPIOB_PUPDR_PHDR4_Pos        8                                            /*!<GPIOB PUPDR: PHDR4 Position */
#define GPIOB_PUPDR_PHDR4_Msk        (0x1UL << GPIOB_PUPDR_PHDR4_Pos)             /*!<GPIOB PUPDR: PHDR4 Mask */

#define GPIOB_PUPDR_PHDR5_Pos        10                                           /*!<GPIOB PUPDR: PHDR5 Position */
#define GPIOB_PUPDR_PHDR5_Msk        (0x1UL << GPIOB_PUPDR_PHDR5_Pos)             /*!<GPIOB PUPDR: PHDR5 Mask */

#define GPIOB_PUPDR_PHDR6_Pos        12                                           /*!<GPIOB PUPDR: PHDR6 Position */
#define GPIOB_PUPDR_PHDR6_Msk        (0x1UL << GPIOB_PUPDR_PHDR6_Pos)             /*!<GPIOB PUPDR: PHDR6 Mask */

#define GPIOB_PUPDR_PHDR7_Pos        14                                           /*!<GPIOB PUPDR: PHDR7 Position */
#define GPIOB_PUPDR_PHDR7_Msk        (0x1UL << GPIOB_PUPDR_PHDR7_Pos)             /*!<GPIOB PUPDR: PHDR7 Mask */

#define GPIOB_PUPDR_PHDR8_Pos        16                                           /*!<GPIOB PUPDR: PHDR8 Position */
#define GPIOB_PUPDR_PHDR8_Msk        (0x1UL << GPIOB_PUPDR_PHDR8_Pos)             /*!<GPIOB PUPDR: PHDR8 Mask */

#define GPIOB_PUPDR_PHDR9_Pos        18                                           /*!<GPIOB PUPDR: PHDR9 Position */
#define GPIOB_PUPDR_PHDR9_Msk        (0x1UL << GPIOB_PUPDR_PHDR9_Pos)             /*!<GPIOB PUPDR: PHDR9 Mask */

#define GPIOB_PUPDR_PHDR10_Pos       20                                           /*!<GPIOB PUPDR: PHDR10 Position */
#define GPIOB_PUPDR_PHDR10_Msk       (0x1UL << GPIOB_PUPDR_PHDR10_Pos)            /*!<GPIOB PUPDR: PHDR10 Mask */

#define GPIOB_PUPDR_PHDR11_Pos       22                                           /*!<GPIOB PUPDR: PHDR11 Position */
#define GPIOB_PUPDR_PHDR11_Msk       (0x1UL << GPIOB_PUPDR_PHDR11_Pos)            /*!<GPIOB PUPDR: PHDR11 Mask */

#define GPIOB_PUPDR_PHDR12_Pos       24                                           /*!<GPIOB PUPDR: PHDR12 Position */
#define GPIOB_PUPDR_PHDR12_Msk       (0x1UL << GPIOB_PUPDR_PHDR12_Pos)            /*!<GPIOB PUPDR: PHDR12 Mask */

#define GPIOB_PUPDR_PHDR13_Pos       26                                           /*!<GPIOB PUPDR: PHDR13 Position */
#define GPIOB_PUPDR_PHDR13_Msk       (0x1UL << GPIOB_PUPDR_PHDR13_Pos)            /*!<GPIOB PUPDR: PHDR13 Mask */

#define GPIOB_PUPDR_PHDR14_Pos       28                                           /*!<GPIOB PUPDR: PHDR14 Position */
#define GPIOB_PUPDR_PHDR14_Msk       (0x1UL << GPIOB_PUPDR_PHDR14_Pos)            /*!<GPIOB PUPDR: PHDR14 Mask */

#define GPIOB_PUPDR_PHDR15_Pos       30                                           /*!<GPIOB PUPDR: PHDR15 Position */
#define GPIOB_PUPDR_PHDR15_Msk       (0x1UL << GPIOB_PUPDR_PHDR15_Pos)            /*!<GPIOB PUPDR: PHDR15 Mask */

#define GPIOB_PUPDR_Msk_ALL          (GPIOB_PUPDR_PHDR0_Msk        |\
                                      GPIOB_PUPDR_PHDR1_Msk        |\
                                      GPIOB_PUPDR_PHDR2_Msk        |\
                                      GPIOB_PUPDR_PHDR3_Msk        |\
                                      GPIOB_PUPDR_PHDR4_Msk        |\
                                      GPIOB_PUPDR_PHDR5_Msk        |\
                                      GPIOB_PUPDR_PHDR6_Msk        |\
                                      GPIOB_PUPDR_PHDR7_Msk        |\
                                      GPIOB_PUPDR_PHDR8_Msk        |\
                                      GPIOB_PUPDR_PHDR9_Msk        |\
                                      GPIOB_PUPDR_PHDR10_Msk       |\
                                      GPIOB_PUPDR_PHDR11_Msk       |\
                                      GPIOB_PUPDR_PHDR12_Msk       |\
                                      GPIOB_PUPDR_PHDR13_Msk       |\
                                      GPIOB_PUPDR_PHDR14_Msk       |\
                                      GPIOB_PUPDR_PHDR15_Msk       )

#define GPIOB_TTLEN_TTLEN0_Pos       0                                            /*!<GPIOB TTLEN: TTLEN0 Position */
#define GPIOB_TTLEN_TTLEN0_Msk       (0x1UL /*<< GPIOB_TTLEN_TTLEN0_Pos*/)        /*!<GPIOB TTLEN: TTLEN0 Mask */

#define GPIOB_TTLEN_TTLEN1_Pos       1                                            /*!<GPIOB TTLEN: TTLEN1 Position */
#define GPIOB_TTLEN_TTLEN1_Msk       (0x1UL << GPIOB_TTLEN_TTLEN1_Pos)            /*!<GPIOB TTLEN: TTLEN1 Mask */

#define GPIOB_TTLEN_TTLEN2_Pos       2                                            /*!<GPIOB TTLEN: TTLEN2 Position */
#define GPIOB_TTLEN_TTLEN2_Msk       (0x1UL << GPIOB_TTLEN_TTLEN2_Pos)            /*!<GPIOB TTLEN: TTLEN2 Mask */

#define GPIOB_TTLEN_TTLEN3_Pos       3                                            /*!<GPIOB TTLEN: TTLEN3 Position */
#define GPIOB_TTLEN_TTLEN3_Msk       (0x1UL << GPIOB_TTLEN_TTLEN3_Pos)            /*!<GPIOB TTLEN: TTLEN3 Mask */

#define GPIOB_TTLEN_TTLEN4_Pos       4                                            /*!<GPIOB TTLEN: TTLEN4 Position */
#define GPIOB_TTLEN_TTLEN4_Msk       (0x1UL << GPIOB_TTLEN_TTLEN4_Pos)            /*!<GPIOB TTLEN: TTLEN4 Mask */

#define GPIOB_TTLEN_TTLEN5_Pos       5                                            /*!<GPIOB TTLEN: TTLEN5 Position */
#define GPIOB_TTLEN_TTLEN5_Msk       (0x1UL << GPIOB_TTLEN_TTLEN5_Pos)            /*!<GPIOB TTLEN: TTLEN5 Mask */

#define GPIOB_TTLEN_TTLEN6_Pos       6                                            /*!<GPIOB TTLEN: TTLEN6 Position */
#define GPIOB_TTLEN_TTLEN6_Msk       (0x1UL << GPIOB_TTLEN_TTLEN6_Pos)            /*!<GPIOB TTLEN: TTLEN6 Mask */

#define GPIOB_TTLEN_TTLEN7_Pos       7                                            /*!<GPIOB TTLEN: TTLEN7 Position */
#define GPIOB_TTLEN_TTLEN7_Msk       (0x1UL << GPIOB_TTLEN_TTLEN7_Pos)            /*!<GPIOB TTLEN: TTLEN7 Mask */

#define GPIOB_TTLEN_TTLEN8_Pos       8                                            /*!<GPIOB TTLEN: TTLEN8 Position */
#define GPIOB_TTLEN_TTLEN8_Msk       (0x1UL << GPIOB_TTLEN_TTLEN8_Pos)            /*!<GPIOB TTLEN: TTLEN8 Mask */

#define GPIOB_TTLEN_TTLEN9_Pos       9                                            /*!<GPIOB TTLEN: TTLEN9 Position */
#define GPIOB_TTLEN_TTLEN9_Msk       (0x1UL << GPIOB_TTLEN_TTLEN9_Pos)            /*!<GPIOB TTLEN: TTLEN9 Mask */

#define GPIOB_TTLEN_TTLEN10_Pos      10                                           /*!<GPIOB TTLEN: TTLEN10 Position */
#define GPIOB_TTLEN_TTLEN10_Msk      (0x1UL << GPIOB_TTLEN_TTLEN10_Pos)           /*!<GPIOB TTLEN: TTLEN10 Mask */

#define GPIOB_TTLEN_TTLEN11_Pos      11                                           /*!<GPIOB TTLEN: TTLEN11 Position */
#define GPIOB_TTLEN_TTLEN11_Msk      (0x1UL << GPIOB_TTLEN_TTLEN11_Pos)           /*!<GPIOB TTLEN: TTLEN11 Mask */

#define GPIOB_TTLEN_TTLEN12_Pos      12                                           /*!<GPIOB TTLEN: TTLEN12 Position */
#define GPIOB_TTLEN_TTLEN12_Msk      (0x1UL << GPIOB_TTLEN_TTLEN12_Pos)           /*!<GPIOB TTLEN: TTLEN12 Mask */

#define GPIOB_TTLEN_TTLEN13_Pos      13                                           /*!<GPIOB TTLEN: TTLEN13 Position */
#define GPIOB_TTLEN_TTLEN13_Msk      (0x1UL << GPIOB_TTLEN_TTLEN13_Pos)           /*!<GPIOB TTLEN: TTLEN13 Mask */

#define GPIOB_TTLEN_TTLEN14_Pos      14                                           /*!<GPIOB TTLEN: TTLEN14 Position */
#define GPIOB_TTLEN_TTLEN14_Msk      (0x1UL << GPIOB_TTLEN_TTLEN14_Pos)           /*!<GPIOB TTLEN: TTLEN14 Mask */

#define GPIOB_TTLEN_TTLEN15_Pos      15                                           /*!<GPIOB TTLEN: TTLEN15 Position */
#define GPIOB_TTLEN_TTLEN15_Msk      (0x1UL << GPIOB_TTLEN_TTLEN15_Pos)           /*!<GPIOB TTLEN: TTLEN15 Mask */

#define GPIOB_TTLEN_Msk_ALL          (GPIOB_TTLEN_TTLEN0_Msk       |\
                                      GPIOB_TTLEN_TTLEN1_Msk       |\
                                      GPIOB_TTLEN_TTLEN2_Msk       |\
                                      GPIOB_TTLEN_TTLEN3_Msk       |\
                                      GPIOB_TTLEN_TTLEN4_Msk       |\
                                      GPIOB_TTLEN_TTLEN5_Msk       |\
                                      GPIOB_TTLEN_TTLEN6_Msk       |\
                                      GPIOB_TTLEN_TTLEN7_Msk       |\
                                      GPIOB_TTLEN_TTLEN8_Msk       |\
                                      GPIOB_TTLEN_TTLEN9_Msk       |\
                                      GPIOB_TTLEN_TTLEN10_Msk      |\
                                      GPIOB_TTLEN_TTLEN11_Msk      |\
                                      GPIOB_TTLEN_TTLEN12_Msk      |\
                                      GPIOB_TTLEN_TTLEN13_Msk      |\
                                      GPIOB_TTLEN_TTLEN14_Msk      |\
                                      GPIOB_TTLEN_TTLEN15_Msk      )

#define GPIOB_AFRL_AFR0_Pos          0                                            /*!<GPIOB AFRL: AFR0 Position */
#define GPIOB_AFRL_AFR0_Msk          (0xFUL /*<< GPIOB_AFRL_AFR0_Pos*/)           /*!<GPIOB AFRL: AFR0 Mask */

#define GPIOB_AFRL_AFR1_Pos          4                                            /*!<GPIOB AFRL: AFR1 Position */
#define GPIOB_AFRL_AFR1_Msk          (0xFUL << GPIOB_AFRL_AFR1_Pos)               /*!<GPIOB AFRL: AFR1 Mask */

#define GPIOB_AFRL_AFR2_Pos          8                                            /*!<GPIOB AFRL: AFR2 Position */
#define GPIOB_AFRL_AFR2_Msk          (0xFUL << GPIOB_AFRL_AFR2_Pos)               /*!<GPIOB AFRL: AFR2 Mask */

#define GPIOB_AFRL_AFR3_Pos          12                                           /*!<GPIOB AFRL: AFR3 Position */
#define GPIOB_AFRL_AFR3_Msk          (0xFUL << GPIOB_AFRL_AFR3_Pos)               /*!<GPIOB AFRL: AFR3 Mask */

#define GPIOB_AFRL_AFR4_Pos          16                                           /*!<GPIOB AFRL: AFR4 Position */
#define GPIOB_AFRL_AFR4_Msk          (0xFUL << GPIOB_AFRL_AFR4_Pos)               /*!<GPIOB AFRL: AFR4 Mask */

#define GPIOB_AFRL_AFR5_Pos          20                                           /*!<GPIOB AFRL: AFR5 Position */
#define GPIOB_AFRL_AFR5_Msk          (0xFUL << GPIOB_AFRL_AFR5_Pos)               /*!<GPIOB AFRL: AFR5 Mask */

#define GPIOB_AFRL_AFR6_Pos          24                                           /*!<GPIOB AFRL: AFR6 Position */
#define GPIOB_AFRL_AFR6_Msk          (0xFUL << GPIOB_AFRL_AFR6_Pos)               /*!<GPIOB AFRL: AFR6 Mask */

#define GPIOB_AFRL_AFR7_Pos          28                                           /*!<GPIOB AFRL: AFR7 Position */
#define GPIOB_AFRL_AFR7_Msk          (0xFUL << GPIOB_AFRL_AFR7_Pos)               /*!<GPIOB AFRL: AFR7 Mask */

#define GPIOB_AFRL_Msk_ALL           (GPIOB_AFRL_AFR0_Msk          |\
                                      GPIOB_AFRL_AFR1_Msk          |\
                                      GPIOB_AFRL_AFR2_Msk          |\
                                      GPIOB_AFRL_AFR3_Msk          |\
                                      GPIOB_AFRL_AFR4_Msk          |\
                                      GPIOB_AFRL_AFR5_Msk          |\
                                      GPIOB_AFRL_AFR6_Msk          |\
                                      GPIOB_AFRL_AFR7_Msk          )

#define GPIOB_AFRH_AFR8_Pos          0                                            /*!<GPIOB AFRH: AFR8 Position */
#define GPIOB_AFRH_AFR8_Msk          (0xFUL /*<< GPIOB_AFRH_AFR8_Pos*/)           /*!<GPIOB AFRH: AFR8 Mask */

#define GPIOB_AFRH_AFR9_Pos          4                                            /*!<GPIOB AFRH: AFR9 Position */
#define GPIOB_AFRH_AFR9_Msk          (0xFUL << GPIOB_AFRH_AFR9_Pos)               /*!<GPIOB AFRH: AFR9 Mask */

#define GPIOB_AFRH_AFR10_Pos         8                                            /*!<GPIOB AFRH: AFR10 Position */
#define GPIOB_AFRH_AFR10_Msk         (0xFUL << GPIOB_AFRH_AFR10_Pos)              /*!<GPIOB AFRH: AFR10 Mask */

#define GPIOB_AFRH_AFR11_Pos         12                                           /*!<GPIOB AFRH: AFR11 Position */
#define GPIOB_AFRH_AFR11_Msk         (0xFUL << GPIOB_AFRH_AFR11_Pos)              /*!<GPIOB AFRH: AFR11 Mask */

#define GPIOB_AFRH_AFR12_Pos         16                                           /*!<GPIOB AFRH: AFR12 Position */
#define GPIOB_AFRH_AFR12_Msk         (0xFUL << GPIOB_AFRH_AFR12_Pos)              /*!<GPIOB AFRH: AFR12 Mask */

#define GPIOB_AFRH_AFR13_Pos         20                                           /*!<GPIOB AFRH: AFR13 Position */
#define GPIOB_AFRH_AFR13_Msk         (0xFUL << GPIOB_AFRH_AFR13_Pos)              /*!<GPIOB AFRH: AFR13 Mask */

#define GPIOB_AFRH_AFR14_Pos         24                                           /*!<GPIOB AFRH: AFR14 Position */
#define GPIOB_AFRH_AFR14_Msk         (0xFUL << GPIOB_AFRH_AFR14_Pos)              /*!<GPIOB AFRH: AFR14 Mask */

#define GPIOB_AFRH_AFR15_Pos         28                                           /*!<GPIOB AFRH: AFR15 Position */
#define GPIOB_AFRH_AFR15_Msk         (0xFUL << GPIOB_AFRH_AFR15_Pos)              /*!<GPIOB AFRH: AFR15 Mask */

#define GPIOB_AFRH_Msk_ALL           (GPIOB_AFRH_AFR8_Msk          |\
                                      GPIOB_AFRH_AFR9_Msk          |\
                                      GPIOB_AFRH_AFR10_Msk         |\
                                      GPIOB_AFRH_AFR11_Msk         |\
                                      GPIOB_AFRH_AFR12_Msk         |\
                                      GPIOB_AFRH_AFR13_Msk         |\
                                      GPIOB_AFRH_AFR14_Msk         |\
                                      GPIOB_AFRH_AFR15_Msk         )

#define GPIOC_MODER_MODER0_Pos       0                                            /*!<GPIOC MODER: MODER0 Position */
#define GPIOC_MODER_MODER0_Msk       (0x1UL /*<< GPIOC_MODER_MODER0_Pos*/)        /*!<GPIOC MODER: MODER0 Mask */

#define GPIOC_MODER_MODER1_Pos       1                                            /*!<GPIOC MODER: MODER1 Position */
#define GPIOC_MODER_MODER1_Msk       (0x1UL << GPIOC_MODER_MODER1_Pos)            /*!<GPIOC MODER: MODER1 Mask */

#define GPIOC_MODER_MODER2_Pos       2                                            /*!<GPIOC MODER: MODER2 Position */
#define GPIOC_MODER_MODER2_Msk       (0x1UL << GPIOC_MODER_MODER2_Pos)            /*!<GPIOC MODER: MODER2 Mask */

#define GPIOC_MODER_MODER3_Pos       3                                            /*!<GPIOC MODER: MODER3 Position */
#define GPIOC_MODER_MODER3_Msk       (0x1UL << GPIOC_MODER_MODER3_Pos)            /*!<GPIOC MODER: MODER3 Mask */

#define GPIOC_MODER_MODER4_Pos       4                                            /*!<GPIOC MODER: MODER4 Position */
#define GPIOC_MODER_MODER4_Msk       (0x1UL << GPIOC_MODER_MODER4_Pos)            /*!<GPIOC MODER: MODER4 Mask */

#define GPIOC_MODER_MODER5_Pos       5                                            /*!<GPIOC MODER: MODER5 Position */
#define GPIOC_MODER_MODER5_Msk       (0x1UL << GPIOC_MODER_MODER5_Pos)            /*!<GPIOC MODER: MODER5 Mask */

#define GPIOC_MODER_MODER6_Pos       6                                            /*!<GPIOC MODER: MODER6 Position */
#define GPIOC_MODER_MODER6_Msk       (0x1UL << GPIOC_MODER_MODER6_Pos)            /*!<GPIOC MODER: MODER6 Mask */

#define GPIOC_MODER_MODER7_Pos       7                                            /*!<GPIOC MODER: MODER7 Position */
#define GPIOC_MODER_MODER7_Msk       (0x1UL << GPIOC_MODER_MODER7_Pos)            /*!<GPIOC MODER: MODER7 Mask */

#define GPIOC_MODER_MODER8_Pos       8                                            /*!<GPIOC MODER: MODER8 Position */
#define GPIOC_MODER_MODER8_Msk       (0x1UL << GPIOC_MODER_MODER8_Pos)            /*!<GPIOC MODER: MODER8 Mask */

#define GPIOC_MODER_MODER9_Pos       9                                            /*!<GPIOC MODER: MODER9 Position */
#define GPIOC_MODER_MODER9_Msk       (0x1UL << GPIOC_MODER_MODER9_Pos)            /*!<GPIOC MODER: MODER9 Mask */

#define GPIOC_MODER_MODER10_Pos      10                                           /*!<GPIOC MODER: MODER10 Position */
#define GPIOC_MODER_MODER10_Msk      (0x1UL << GPIOC_MODER_MODER10_Pos)           /*!<GPIOC MODER: MODER10 Mask */

#define GPIOC_MODER_MODER11_Pos      11                                           /*!<GPIOC MODER: MODER11 Position */
#define GPIOC_MODER_MODER11_Msk      (0x1UL << GPIOC_MODER_MODER11_Pos)           /*!<GPIOC MODER: MODER11 Mask */

#define GPIOC_MODER_MODER12_Pos      12                                           /*!<GPIOC MODER: MODER12 Position */
#define GPIOC_MODER_MODER12_Msk      (0x1UL << GPIOC_MODER_MODER12_Pos)           /*!<GPIOC MODER: MODER12 Mask */

#define GPIOC_MODER_MODER13_Pos      13                                           /*!<GPIOC MODER: MODER13 Position */
#define GPIOC_MODER_MODER13_Msk      (0x1UL << GPIOC_MODER_MODER13_Pos)           /*!<GPIOC MODER: MODER13 Mask */

#define GPIOC_MODER_MODER14_Pos      14                                           /*!<GPIOC MODER: MODER14 Position */
#define GPIOC_MODER_MODER14_Msk      (0x1UL << GPIOC_MODER_MODER14_Pos)           /*!<GPIOC MODER: MODER14 Mask */

#define GPIOC_MODER_MODER15_Pos      15                                           /*!<GPIOC MODER: MODER15 Position */
#define GPIOC_MODER_MODER15_Msk      (0x1UL << GPIOC_MODER_MODER15_Pos)           /*!<GPIOC MODER: MODER15 Mask */

#define GPIOC_MODER_Msk_ALL          (GPIOC_MODER_MODER0_Msk       |\
                                      GPIOC_MODER_MODER1_Msk       |\
                                      GPIOC_MODER_MODER2_Msk       |\
                                      GPIOC_MODER_MODER3_Msk       |\
                                      GPIOC_MODER_MODER4_Msk       |\
                                      GPIOC_MODER_MODER5_Msk       |\
                                      GPIOC_MODER_MODER6_Msk       |\
                                      GPIOC_MODER_MODER7_Msk       |\
                                      GPIOC_MODER_MODER8_Msk       |\
                                      GPIOC_MODER_MODER9_Msk       |\
                                      GPIOC_MODER_MODER10_Msk      |\
                                      GPIOC_MODER_MODER11_Msk      |\
                                      GPIOC_MODER_MODER12_Msk      |\
                                      GPIOC_MODER_MODER13_Msk      |\
                                      GPIOC_MODER_MODER14_Msk      |\
                                      GPIOC_MODER_MODER15_Msk      )

#define GPIOC_IDR_IDR_Pos            0                                            /*!<GPIOC IDR: IDR Position */
#define GPIOC_IDR_IDR_Msk            (0xFFFFUL /*<< GPIOC_IDR_IDR_Pos*/)          /*!<GPIOC IDR: IDR Mask */

#define GPIOC_IDR_Msk_ALL            (GPIOC_IDR_IDR_Msk           )

#define GPIOC_ODR_ODR_Pos            0                                            /*!<GPIOC ODR: ODR Position */
#define GPIOC_ODR_ODR_Msk            (0xFFFFUL /*<< GPIOC_ODR_ODR_Pos*/)          /*!<GPIOC ODR: ODR Mask */

#define GPIOC_ODR_Msk_ALL            (GPIOC_ODR_ODR_Msk           )

#define GPIOC_BSRR_BS_Pos            0                                            /*!<GPIOC BSRR: BS Position */
#define GPIOC_BSRR_BS_Msk            (0xFFFFUL /*<< GPIOC_BSRR_BS_Pos*/)          /*!<GPIOC BSRR: BS Mask */

#define GPIOC_BSRR_BR_Pos            16                                           /*!<GPIOC BSRR: BR Position */
#define GPIOC_BSRR_BR_Msk            (0xFFFFUL << GPIOC_BSRR_BR_Pos)              /*!<GPIOC BSRR: BR Mask */

#define GPIOC_BSRR_Msk_ALL           (GPIOC_BSRR_BS_Msk            |\
                                      GPIOC_BSRR_BR_Msk            )

#define GPIOC_LCKR_LCK0_Pos          0                                            /*!<GPIOC LCKR: LCK0 Position */
#define GPIOC_LCKR_LCK0_Msk          (0x1UL /*<< GPIOC_LCKR_LCK0_Pos*/)           /*!<GPIOC LCKR: LCK0 Mask */

#define GPIOC_LCKR_LCK1_Pos          1                                            /*!<GPIOC LCKR: LCK1 Position */
#define GPIOC_LCKR_LCK1_Msk          (0x1UL << GPIOC_LCKR_LCK1_Pos)               /*!<GPIOC LCKR: LCK1 Mask */

#define GPIOC_LCKR_LCK2_Pos          2                                            /*!<GPIOC LCKR: LCK2 Position */
#define GPIOC_LCKR_LCK2_Msk          (0x1UL << GPIOC_LCKR_LCK2_Pos)               /*!<GPIOC LCKR: LCK2 Mask */

#define GPIOC_LCKR_LCK3_Pos          3                                            /*!<GPIOC LCKR: LCK3 Position */
#define GPIOC_LCKR_LCK3_Msk          (0x1UL << GPIOC_LCKR_LCK3_Pos)               /*!<GPIOC LCKR: LCK3 Mask */

#define GPIOC_LCKR_LCK4_Pos          4                                            /*!<GPIOC LCKR: LCK4 Position */
#define GPIOC_LCKR_LCK4_Msk          (0x1UL << GPIOC_LCKR_LCK4_Pos)               /*!<GPIOC LCKR: LCK4 Mask */

#define GPIOC_LCKR_LCK5_Pos          5                                            /*!<GPIOC LCKR: LCK5 Position */
#define GPIOC_LCKR_LCK5_Msk          (0x1UL << GPIOC_LCKR_LCK5_Pos)               /*!<GPIOC LCKR: LCK5 Mask */

#define GPIOC_LCKR_LCK6_Pos          6                                            /*!<GPIOC LCKR: LCK6 Position */
#define GPIOC_LCKR_LCK6_Msk          (0x1UL << GPIOC_LCKR_LCK6_Pos)               /*!<GPIOC LCKR: LCK6 Mask */

#define GPIOC_LCKR_LCK7_Pos          7                                            /*!<GPIOC LCKR: LCK7 Position */
#define GPIOC_LCKR_LCK7_Msk          (0x1UL << GPIOC_LCKR_LCK7_Pos)               /*!<GPIOC LCKR: LCK7 Mask */

#define GPIOC_LCKR_LCK8_Pos          8                                            /*!<GPIOC LCKR: LCK8 Position */
#define GPIOC_LCKR_LCK8_Msk          (0x1UL << GPIOC_LCKR_LCK8_Pos)               /*!<GPIOC LCKR: LCK8 Mask */

#define GPIOC_LCKR_LCK9_Pos          9                                            /*!<GPIOC LCKR: LCK9 Position */
#define GPIOC_LCKR_LCK9_Msk          (0x1UL << GPIOC_LCKR_LCK9_Pos)               /*!<GPIOC LCKR: LCK9 Mask */

#define GPIOC_LCKR_LCK10_Pos         10                                           /*!<GPIOC LCKR: LCK10 Position */
#define GPIOC_LCKR_LCK10_Msk         (0x1UL << GPIOC_LCKR_LCK10_Pos)              /*!<GPIOC LCKR: LCK10 Mask */

#define GPIOC_LCKR_LCK11_Pos         11                                           /*!<GPIOC LCKR: LCK11 Position */
#define GPIOC_LCKR_LCK11_Msk         (0x1UL << GPIOC_LCKR_LCK11_Pos)              /*!<GPIOC LCKR: LCK11 Mask */

#define GPIOC_LCKR_LCK12_Pos         12                                           /*!<GPIOC LCKR: LCK12 Position */
#define GPIOC_LCKR_LCK12_Msk         (0x1UL << GPIOC_LCKR_LCK12_Pos)              /*!<GPIOC LCKR: LCK12 Mask */

#define GPIOC_LCKR_LCK13_Pos         13                                           /*!<GPIOC LCKR: LCK13 Position */
#define GPIOC_LCKR_LCK13_Msk         (0x1UL << GPIOC_LCKR_LCK13_Pos)              /*!<GPIOC LCKR: LCK13 Mask */

#define GPIOC_LCKR_LCK14_Pos         14                                           /*!<GPIOC LCKR: LCK14 Position */
#define GPIOC_LCKR_LCK14_Msk         (0x1UL << GPIOC_LCKR_LCK14_Pos)              /*!<GPIOC LCKR: LCK14 Mask */

#define GPIOC_LCKR_LCK15_Pos         15                                           /*!<GPIOC LCKR: LCK15 Position */
#define GPIOC_LCKR_LCK15_Msk         (0x1UL << GPIOC_LCKR_LCK15_Pos)              /*!<GPIOC LCKR: LCK15 Mask */

#define GPIOC_LCKR_LOCK_Pos          16                                           /*!<GPIOC LCKR: LOCK Position */
#define GPIOC_LCKR_LOCK_Msk          (0xFFFFUL << GPIOC_LCKR_LOCK_Pos)            /*!<GPIOC LCKR: LOCK Mask */

#define GPIOC_LCKR_Msk_ALL           (GPIOC_LCKR_LCK0_Msk          |\
                                      GPIOC_LCKR_LCK1_Msk          |\
                                      GPIOC_LCKR_LCK2_Msk          |\
                                      GPIOC_LCKR_LCK3_Msk          |\
                                      GPIOC_LCKR_LCK4_Msk          |\
                                      GPIOC_LCKR_LCK5_Msk          |\
                                      GPIOC_LCKR_LCK6_Msk          |\
                                      GPIOC_LCKR_LCK7_Msk          |\
                                      GPIOC_LCKR_LCK8_Msk          |\
                                      GPIOC_LCKR_LCK9_Msk          |\
                                      GPIOC_LCKR_LCK10_Msk         |\
                                      GPIOC_LCKR_LCK11_Msk         |\
                                      GPIOC_LCKR_LCK12_Msk         |\
                                      GPIOC_LCKR_LCK13_Msk         |\
                                      GPIOC_LCKR_LCK14_Msk         |\
                                      GPIOC_LCKR_LCK15_Msk         |\
                                      GPIOC_LCKR_LOCK_Msk          )

#define GPIOC_IE_IE0_Pos             0                                            /*!<GPIOC IE: IE0 Position */
#define GPIOC_IE_IE0_Msk             (0x1UL /*<< GPIOC_IE_IE0_Pos*/)              /*!<GPIOC IE: IE0 Mask */

#define GPIOC_IE_IE1_Pos             1                                            /*!<GPIOC IE: IE1 Position */
#define GPIOC_IE_IE1_Msk             (0x1UL << GPIOC_IE_IE1_Pos)                  /*!<GPIOC IE: IE1 Mask */

#define GPIOC_IE_IE2_Pos             2                                            /*!<GPIOC IE: IE2 Position */
#define GPIOC_IE_IE2_Msk             (0x1UL << GPIOC_IE_IE2_Pos)                  /*!<GPIOC IE: IE2 Mask */

#define GPIOC_IE_IE3_Pos             3                                            /*!<GPIOC IE: IE3 Position */
#define GPIOC_IE_IE3_Msk             (0x1UL << GPIOC_IE_IE3_Pos)                  /*!<GPIOC IE: IE3 Mask */

#define GPIOC_IE_IE4_Pos             4                                            /*!<GPIOC IE: IE4 Position */
#define GPIOC_IE_IE4_Msk             (0x1UL << GPIOC_IE_IE4_Pos)                  /*!<GPIOC IE: IE4 Mask */

#define GPIOC_IE_IE5_Pos             5                                            /*!<GPIOC IE: IE5 Position */
#define GPIOC_IE_IE5_Msk             (0x1UL << GPIOC_IE_IE5_Pos)                  /*!<GPIOC IE: IE5 Mask */

#define GPIOC_IE_IE6_Pos             6                                            /*!<GPIOC IE: IE6 Position */
#define GPIOC_IE_IE6_Msk             (0x1UL << GPIOC_IE_IE6_Pos)                  /*!<GPIOC IE: IE6 Mask */

#define GPIOC_IE_IE7_Pos             7                                            /*!<GPIOC IE: IE7 Position */
#define GPIOC_IE_IE7_Msk             (0x1UL << GPIOC_IE_IE7_Pos)                  /*!<GPIOC IE: IE7 Mask */

#define GPIOC_IE_IE8_Pos             8                                            /*!<GPIOC IE: IE8 Position */
#define GPIOC_IE_IE8_Msk             (0x1UL << GPIOC_IE_IE8_Pos)                  /*!<GPIOC IE: IE8 Mask */

#define GPIOC_IE_IE9_Pos             9                                            /*!<GPIOC IE: IE9 Position */
#define GPIOC_IE_IE9_Msk             (0x1UL << GPIOC_IE_IE9_Pos)                  /*!<GPIOC IE: IE9 Mask */

#define GPIOC_IE_IE10_Pos            10                                           /*!<GPIOC IE: IE10 Position */
#define GPIOC_IE_IE10_Msk            (0x1UL << GPIOC_IE_IE10_Pos)                 /*!<GPIOC IE: IE10 Mask */

#define GPIOC_IE_IE11_Pos            11                                           /*!<GPIOC IE: IE11 Position */
#define GPIOC_IE_IE11_Msk            (0x1UL << GPIOC_IE_IE11_Pos)                 /*!<GPIOC IE: IE11 Mask */

#define GPIOC_IE_IE12_Pos            12                                           /*!<GPIOC IE: IE12 Position */
#define GPIOC_IE_IE12_Msk            (0x1UL << GPIOC_IE_IE12_Pos)                 /*!<GPIOC IE: IE12 Mask */

#define GPIOC_IE_IE13_Pos            13                                           /*!<GPIOC IE: IE13 Position */
#define GPIOC_IE_IE13_Msk            (0x1UL << GPIOC_IE_IE13_Pos)                 /*!<GPIOC IE: IE13 Mask */

#define GPIOC_IE_IE14_Pos            14                                           /*!<GPIOC IE: IE14 Position */
#define GPIOC_IE_IE14_Msk            (0x1UL << GPIOC_IE_IE14_Pos)                 /*!<GPIOC IE: IE14 Mask */

#define GPIOC_IE_IE15_Pos            15                                           /*!<GPIOC IE: IE15 Position */
#define GPIOC_IE_IE15_Msk            (0x1UL << GPIOC_IE_IE15_Pos)                 /*!<GPIOC IE: IE15 Mask */

#define GPIOC_IE_Msk_ALL             (GPIOC_IE_IE0_Msk             |\
                                      GPIOC_IE_IE1_Msk             |\
                                      GPIOC_IE_IE2_Msk             |\
                                      GPIOC_IE_IE3_Msk             |\
                                      GPIOC_IE_IE4_Msk             |\
                                      GPIOC_IE_IE5_Msk             |\
                                      GPIOC_IE_IE6_Msk             |\
                                      GPIOC_IE_IE7_Msk             |\
                                      GPIOC_IE_IE8_Msk             |\
                                      GPIOC_IE_IE9_Msk             |\
                                      GPIOC_IE_IE10_Msk            |\
                                      GPIOC_IE_IE11_Msk            |\
                                      GPIOC_IE_IE12_Msk            |\
                                      GPIOC_IE_IE13_Msk            |\
                                      GPIOC_IE_IE14_Msk            |\
                                      GPIOC_IE_IE15_Msk            )

#define GPIOC_OTYPER_OT4_Pos         4                                            /*!<GPIOC OTYPER: OT4 Position */
#define GPIOC_OTYPER_OT4_Msk         (0x1UL << GPIOC_OTYPER_OT4_Pos)              /*!<GPIOC OTYPER: OT4 Mask */

#define GPIOC_OTYPER_OT5_Pos         5                                            /*!<GPIOC OTYPER: OT5 Position */
#define GPIOC_OTYPER_OT5_Msk         (0x1UL << GPIOC_OTYPER_OT5_Pos)              /*!<GPIOC OTYPER: OT5 Mask */

#define GPIOC_OTYPER_OT6_Pos         6                                            /*!<GPIOC OTYPER: OT6 Position */
#define GPIOC_OTYPER_OT6_Msk         (0x1UL << GPIOC_OTYPER_OT6_Pos)              /*!<GPIOC OTYPER: OT6 Mask */

#define GPIOC_OTYPER_OT7_Pos         7                                            /*!<GPIOC OTYPER: OT7 Position */
#define GPIOC_OTYPER_OT7_Msk         (0x1UL << GPIOC_OTYPER_OT7_Pos)              /*!<GPIOC OTYPER: OT7 Mask */

#define GPIOC_OTYPER_OT8_Pos         8                                            /*!<GPIOC OTYPER: OT8 Position */
#define GPIOC_OTYPER_OT8_Msk         (0x1UL << GPIOC_OTYPER_OT8_Pos)              /*!<GPIOC OTYPER: OT8 Mask */

#define GPIOC_OTYPER_OT9_Pos         9                                            /*!<GPIOC OTYPER: OT9 Position */
#define GPIOC_OTYPER_OT9_Msk         (0x1UL << GPIOC_OTYPER_OT9_Pos)              /*!<GPIOC OTYPER: OT9 Mask */

#define GPIOC_OTYPER_OT10_Pos        10                                           /*!<GPIOC OTYPER: OT10 Position */
#define GPIOC_OTYPER_OT10_Msk        (0x1UL << GPIOC_OTYPER_OT10_Pos)             /*!<GPIOC OTYPER: OT10 Mask */

#define GPIOC_OTYPER_OT12_Pos        12                                           /*!<GPIOC OTYPER: OT12 Position */
#define GPIOC_OTYPER_OT12_Msk        (0x1UL << GPIOC_OTYPER_OT12_Pos)             /*!<GPIOC OTYPER: OT12 Mask */

#define GPIOC_OTYPER_OT13_Pos        13                                           /*!<GPIOC OTYPER: OT13 Position */
#define GPIOC_OTYPER_OT13_Msk        (0x1UL << GPIOC_OTYPER_OT13_Pos)             /*!<GPIOC OTYPER: OT13 Mask */

#define GPIOC_OTYPER_OT14_Pos        14                                           /*!<GPIOC OTYPER: OT14 Position */
#define GPIOC_OTYPER_OT14_Msk        (0x1UL << GPIOC_OTYPER_OT14_Pos)             /*!<GPIOC OTYPER: OT14 Mask */

#define GPIOC_OTYPER_OT15_Pos        15                                           /*!<GPIOC OTYPER: OT15 Position */
#define GPIOC_OTYPER_OT15_Msk        (0x1UL << GPIOC_OTYPER_OT15_Pos)             /*!<GPIOC OTYPER: OT15 Mask */

#define GPIOC_OTYPER_Msk_ALL         (GPIOC_OTYPER_OT4_Msk         |\
                                      GPIOC_OTYPER_OT5_Msk         |\
                                      GPIOC_OTYPER_OT6_Msk         |\
                                      GPIOC_OTYPER_OT7_Msk         |\
                                      GPIOC_OTYPER_OT8_Msk         |\
                                      GPIOC_OTYPER_OT9_Msk         |\
                                      GPIOC_OTYPER_OT10_Msk        |\
                                      GPIOC_OTYPER_OT12_Msk        |\
                                      GPIOC_OTYPER_OT13_Msk        |\
                                      GPIOC_OTYPER_OT14_Msk        |\
                                      GPIOC_OTYPER_OT15_Msk        )

#define GPIOC_ODRVR_ODRVR_SINK2_Pos  4                                            /*!<GPIOC ODRVR: ODRVR_SINK2 Position */
#define GPIOC_ODRVR_ODRVR_SINK2_Msk  (0x1UL << GPIOC_ODRVR_ODRVR_SINK2_Pos)       /*!<GPIOC ODRVR: ODRVR_SINK2 Mask */

#define GPIOC_ODRVR_ODRVR_SINK3_Pos  6                                            /*!<GPIOC ODRVR: ODRVR_SINK3 Position */
#define GPIOC_ODRVR_ODRVR_SINK3_Msk  (0x1UL << GPIOC_ODRVR_ODRVR_SINK3_Pos)       /*!<GPIOC ODRVR: ODRVR_SINK3 Mask */

#define GPIOC_ODRVR_ODRVR_SINK4_Pos  8                                            /*!<GPIOC ODRVR: ODRVR_SINK4 Position */
#define GPIOC_ODRVR_ODRVR_SINK4_Msk  (0x1UL << GPIOC_ODRVR_ODRVR_SINK4_Pos)       /*!<GPIOC ODRVR: ODRVR_SINK4 Mask */

#define GPIOC_ODRVR_ODRVR_SINK5_Pos  10                                           /*!<GPIOC ODRVR: ODRVR_SINK5 Position */
#define GPIOC_ODRVR_ODRVR_SINK5_Msk  (0x1UL << GPIOC_ODRVR_ODRVR_SINK5_Pos)       /*!<GPIOC ODRVR: ODRVR_SINK5 Mask */

#define GPIOC_ODRVR_ODRVR_SINK6_Pos  12                                           /*!<GPIOC ODRVR: ODRVR_SINK6 Position */
#define GPIOC_ODRVR_ODRVR_SINK6_Msk  (0x1UL << GPIOC_ODRVR_ODRVR_SINK6_Pos)       /*!<GPIOC ODRVR: ODRVR_SINK6 Mask */

#define GPIOC_ODRVR_ODRVR_SINK7_Pos  14                                           /*!<GPIOC ODRVR: ODRVR_SINK7 Position */
#define GPIOC_ODRVR_ODRVR_SINK7_Msk  (0x1UL << GPIOC_ODRVR_ODRVR_SINK7_Pos)       /*!<GPIOC ODRVR: ODRVR_SINK7 Mask */

#define GPIOC_ODRVR_ODRVR_SINK8_Pos  16                                           /*!<GPIOC ODRVR: ODRVR_SINK8 Position */
#define GPIOC_ODRVR_ODRVR_SINK8_Msk  (0x1UL << GPIOC_ODRVR_ODRVR_SINK8_Pos)       /*!<GPIOC ODRVR: ODRVR_SINK8 Mask */

#define GPIOC_ODRVR_ODRVR_SINK9_Pos  18                                           /*!<GPIOC ODRVR: ODRVR_SINK9 Position */
#define GPIOC_ODRVR_ODRVR_SINK9_Msk  (0x1UL << GPIOC_ODRVR_ODRVR_SINK9_Pos)       /*!<GPIOC ODRVR: ODRVR_SINK9 Mask */

#define GPIOC_ODRVR_Msk_ALL          (GPIOC_ODRVR_ODRVR_SINK2_Msk  |\
                                      GPIOC_ODRVR_ODRVR_SINK3_Msk  |\
                                      GPIOC_ODRVR_ODRVR_SINK4_Msk  |\
                                      GPIOC_ODRVR_ODRVR_SINK5_Msk  |\
                                      GPIOC_ODRVR_ODRVR_SINK6_Msk  |\
                                      GPIOC_ODRVR_ODRVR_SINK7_Msk  |\
                                      GPIOC_ODRVR_ODRVR_SINK8_Msk  |\
                                      GPIOC_ODRVR_ODRVR_SINK9_Msk  )

#define GPIOC_PUPDR_PHDR0_Pos        0                                            /*!<GPIOC PUPDR: PHDR0 Position */
#define GPIOC_PUPDR_PHDR0_Msk        (0x1UL /*<< GPIOC_PUPDR_PHDR0_Pos*/)         /*!<GPIOC PUPDR: PHDR0 Mask */

#define GPIOC_PUPDR_PHDR1_Pos        2                                            /*!<GPIOC PUPDR: PHDR1 Position */
#define GPIOC_PUPDR_PHDR1_Msk        (0x1UL << GPIOC_PUPDR_PHDR1_Pos)             /*!<GPIOC PUPDR: PHDR1 Mask */

#define GPIOC_PUPDR_PHDR2_Pos        4                                            /*!<GPIOC PUPDR: PHDR2 Position */
#define GPIOC_PUPDR_PHDR2_Msk        (0x1UL << GPIOC_PUPDR_PHDR2_Pos)             /*!<GPIOC PUPDR: PHDR2 Mask */

#define GPIOC_PUPDR_PHDR3_Pos        6                                            /*!<GPIOC PUPDR: PHDR3 Position */
#define GPIOC_PUPDR_PHDR3_Msk        (0x1UL << GPIOC_PUPDR_PHDR3_Pos)             /*!<GPIOC PUPDR: PHDR3 Mask */

#define GPIOC_PUPDR_PHDR4_Pos        8                                            /*!<GPIOC PUPDR: PHDR4 Position */
#define GPIOC_PUPDR_PHDR4_Msk        (0x1UL << GPIOC_PUPDR_PHDR4_Pos)             /*!<GPIOC PUPDR: PHDR4 Mask */

#define GPIOC_PUPDR_PHDR5_Pos        10                                           /*!<GPIOC PUPDR: PHDR5 Position */
#define GPIOC_PUPDR_PHDR5_Msk        (0x1UL << GPIOC_PUPDR_PHDR5_Pos)             /*!<GPIOC PUPDR: PHDR5 Mask */

#define GPIOC_PUPDR_PHDR6_Pos        12                                           /*!<GPIOC PUPDR: PHDR6 Position */
#define GPIOC_PUPDR_PHDR6_Msk        (0x1UL << GPIOC_PUPDR_PHDR6_Pos)             /*!<GPIOC PUPDR: PHDR6 Mask */

#define GPIOC_PUPDR_PHDR7_Pos        14                                           /*!<GPIOC PUPDR: PHDR7 Position */
#define GPIOC_PUPDR_PHDR7_Msk        (0x1UL << GPIOC_PUPDR_PHDR7_Pos)             /*!<GPIOC PUPDR: PHDR7 Mask */

#define GPIOC_PUPDR_PHDR8_Pos        16                                           /*!<GPIOC PUPDR: PHDR8 Position */
#define GPIOC_PUPDR_PHDR8_Msk        (0x1UL << GPIOC_PUPDR_PHDR8_Pos)             /*!<GPIOC PUPDR: PHDR8 Mask */

#define GPIOC_PUPDR_PHDR9_Pos        18                                           /*!<GPIOC PUPDR: PHDR9 Position */
#define GPIOC_PUPDR_PHDR9_Msk        (0x1UL << GPIOC_PUPDR_PHDR9_Pos)             /*!<GPIOC PUPDR: PHDR9 Mask */

#define GPIOC_PUPDR_PHDR10_Pos       20                                           /*!<GPIOC PUPDR: PHDR10 Position */
#define GPIOC_PUPDR_PHDR10_Msk       (0x1UL << GPIOC_PUPDR_PHDR10_Pos)            /*!<GPIOC PUPDR: PHDR10 Mask */

#define GPIOC_PUPDR_PHDR11_Pos       22                                           /*!<GPIOC PUPDR: PHDR11 Position */
#define GPIOC_PUPDR_PHDR11_Msk       (0x1UL << GPIOC_PUPDR_PHDR11_Pos)            /*!<GPIOC PUPDR: PHDR11 Mask */

#define GPIOC_PUPDR_PHDR12_Pos       24                                           /*!<GPIOC PUPDR: PHDR12 Position */
#define GPIOC_PUPDR_PHDR12_Msk       (0x1UL << GPIOC_PUPDR_PHDR12_Pos)            /*!<GPIOC PUPDR: PHDR12 Mask */

#define GPIOC_PUPDR_PHDR13_Pos       26                                           /*!<GPIOC PUPDR: PHDR13 Position */
#define GPIOC_PUPDR_PHDR13_Msk       (0x1UL << GPIOC_PUPDR_PHDR13_Pos)            /*!<GPIOC PUPDR: PHDR13 Mask */

#define GPIOC_PUPDR_PHDR14_Pos       28                                           /*!<GPIOC PUPDR: PHDR14 Position */
#define GPIOC_PUPDR_PHDR14_Msk       (0x1UL << GPIOC_PUPDR_PHDR14_Pos)            /*!<GPIOC PUPDR: PHDR14 Mask */

#define GPIOC_PUPDR_PHDR15_Pos       30                                           /*!<GPIOC PUPDR: PHDR15 Position */
#define GPIOC_PUPDR_PHDR15_Msk       (0x1UL << GPIOC_PUPDR_PHDR15_Pos)            /*!<GPIOC PUPDR: PHDR15 Mask */

#define GPIOC_PUPDR_Msk_ALL          (GPIOC_PUPDR_PHDR0_Msk        |\
                                      GPIOC_PUPDR_PHDR1_Msk        |\
                                      GPIOC_PUPDR_PHDR2_Msk        |\
                                      GPIOC_PUPDR_PHDR3_Msk        |\
                                      GPIOC_PUPDR_PHDR4_Msk        |\
                                      GPIOC_PUPDR_PHDR5_Msk        |\
                                      GPIOC_PUPDR_PHDR6_Msk        |\
                                      GPIOC_PUPDR_PHDR7_Msk        |\
                                      GPIOC_PUPDR_PHDR8_Msk        |\
                                      GPIOC_PUPDR_PHDR9_Msk        |\
                                      GPIOC_PUPDR_PHDR10_Msk       |\
                                      GPIOC_PUPDR_PHDR11_Msk       |\
                                      GPIOC_PUPDR_PHDR12_Msk       |\
                                      GPIOC_PUPDR_PHDR13_Msk       |\
                                      GPIOC_PUPDR_PHDR14_Msk       |\
                                      GPIOC_PUPDR_PHDR15_Msk       )

#define GPIOC_TTLEN_TTLEN0_Pos       0                                            /*!<GPIOC TTLEN: TTLEN0 Position */
#define GPIOC_TTLEN_TTLEN0_Msk       (0x1UL /*<< GPIOC_TTLEN_TTLEN0_Pos*/)        /*!<GPIOC TTLEN: TTLEN0 Mask */

#define GPIOC_TTLEN_TTLEN1_Pos       1                                            /*!<GPIOC TTLEN: TTLEN1 Position */
#define GPIOC_TTLEN_TTLEN1_Msk       (0x1UL << GPIOC_TTLEN_TTLEN1_Pos)            /*!<GPIOC TTLEN: TTLEN1 Mask */

#define GPIOC_TTLEN_TTLEN2_Pos       2                                            /*!<GPIOC TTLEN: TTLEN2 Position */
#define GPIOC_TTLEN_TTLEN2_Msk       (0x1UL << GPIOC_TTLEN_TTLEN2_Pos)            /*!<GPIOC TTLEN: TTLEN2 Mask */

#define GPIOC_TTLEN_TTLEN3_Pos       3                                            /*!<GPIOC TTLEN: TTLEN3 Position */
#define GPIOC_TTLEN_TTLEN3_Msk       (0x1UL << GPIOC_TTLEN_TTLEN3_Pos)            /*!<GPIOC TTLEN: TTLEN3 Mask */

#define GPIOC_TTLEN_TTLEN4_Pos       4                                            /*!<GPIOC TTLEN: TTLEN4 Position */
#define GPIOC_TTLEN_TTLEN4_Msk       (0x1UL << GPIOC_TTLEN_TTLEN4_Pos)            /*!<GPIOC TTLEN: TTLEN4 Mask */

#define GPIOC_TTLEN_TTLEN5_Pos       5                                            /*!<GPIOC TTLEN: TTLEN5 Position */
#define GPIOC_TTLEN_TTLEN5_Msk       (0x1UL << GPIOC_TTLEN_TTLEN5_Pos)            /*!<GPIOC TTLEN: TTLEN5 Mask */

#define GPIOC_TTLEN_TTLEN6_Pos       6                                            /*!<GPIOC TTLEN: TTLEN6 Position */
#define GPIOC_TTLEN_TTLEN6_Msk       (0x1UL << GPIOC_TTLEN_TTLEN6_Pos)            /*!<GPIOC TTLEN: TTLEN6 Mask */

#define GPIOC_TTLEN_TTLEN7_Pos       7                                            /*!<GPIOC TTLEN: TTLEN7 Position */
#define GPIOC_TTLEN_TTLEN7_Msk       (0x1UL << GPIOC_TTLEN_TTLEN7_Pos)            /*!<GPIOC TTLEN: TTLEN7 Mask */

#define GPIOC_TTLEN_TTLEN8_Pos       8                                            /*!<GPIOC TTLEN: TTLEN8 Position */
#define GPIOC_TTLEN_TTLEN8_Msk       (0x1UL << GPIOC_TTLEN_TTLEN8_Pos)            /*!<GPIOC TTLEN: TTLEN8 Mask */

#define GPIOC_TTLEN_TTLEN9_Pos       9                                            /*!<GPIOC TTLEN: TTLEN9 Position */
#define GPIOC_TTLEN_TTLEN9_Msk       (0x1UL << GPIOC_TTLEN_TTLEN9_Pos)            /*!<GPIOC TTLEN: TTLEN9 Mask */

#define GPIOC_TTLEN_TTLEN10_Pos      10                                           /*!<GPIOC TTLEN: TTLEN10 Position */
#define GPIOC_TTLEN_TTLEN10_Msk      (0x1UL << GPIOC_TTLEN_TTLEN10_Pos)           /*!<GPIOC TTLEN: TTLEN10 Mask */

#define GPIOC_TTLEN_TTLEN11_Pos      11                                           /*!<GPIOC TTLEN: TTLEN11 Position */
#define GPIOC_TTLEN_TTLEN11_Msk      (0x1UL << GPIOC_TTLEN_TTLEN11_Pos)           /*!<GPIOC TTLEN: TTLEN11 Mask */

#define GPIOC_TTLEN_TTLEN12_Pos      12                                           /*!<GPIOC TTLEN: TTLEN12 Position */
#define GPIOC_TTLEN_TTLEN12_Msk      (0x1UL << GPIOC_TTLEN_TTLEN12_Pos)           /*!<GPIOC TTLEN: TTLEN12 Mask */

#define GPIOC_TTLEN_TTLEN13_Pos      13                                           /*!<GPIOC TTLEN: TTLEN13 Position */
#define GPIOC_TTLEN_TTLEN13_Msk      (0x1UL << GPIOC_TTLEN_TTLEN13_Pos)           /*!<GPIOC TTLEN: TTLEN13 Mask */

#define GPIOC_TTLEN_TTLEN14_Pos      14                                           /*!<GPIOC TTLEN: TTLEN14 Position */
#define GPIOC_TTLEN_TTLEN14_Msk      (0x1UL << GPIOC_TTLEN_TTLEN14_Pos)           /*!<GPIOC TTLEN: TTLEN14 Mask */

#define GPIOC_TTLEN_TTLEN15_Pos      15                                           /*!<GPIOC TTLEN: TTLEN15 Position */
#define GPIOC_TTLEN_TTLEN15_Msk      (0x1UL << GPIOC_TTLEN_TTLEN15_Pos)           /*!<GPIOC TTLEN: TTLEN15 Mask */

#define GPIOC_TTLEN_Msk_ALL          (GPIOC_TTLEN_TTLEN0_Msk       |\
                                      GPIOC_TTLEN_TTLEN1_Msk       |\
                                      GPIOC_TTLEN_TTLEN2_Msk       |\
                                      GPIOC_TTLEN_TTLEN3_Msk       |\
                                      GPIOC_TTLEN_TTLEN4_Msk       |\
                                      GPIOC_TTLEN_TTLEN5_Msk       |\
                                      GPIOC_TTLEN_TTLEN6_Msk       |\
                                      GPIOC_TTLEN_TTLEN7_Msk       |\
                                      GPIOC_TTLEN_TTLEN8_Msk       |\
                                      GPIOC_TTLEN_TTLEN9_Msk       |\
                                      GPIOC_TTLEN_TTLEN10_Msk      |\
                                      GPIOC_TTLEN_TTLEN11_Msk      |\
                                      GPIOC_TTLEN_TTLEN12_Msk      |\
                                      GPIOC_TTLEN_TTLEN13_Msk      |\
                                      GPIOC_TTLEN_TTLEN14_Msk      |\
                                      GPIOC_TTLEN_TTLEN15_Msk      )

#define GPIOC_AFRL_AFR0_Pos          0                                            /*!<GPIOC AFRL: AFR0 Position */
#define GPIOC_AFRL_AFR0_Msk          (0xFUL /*<< GPIOC_AFRL_AFR0_Pos*/)           /*!<GPIOC AFRL: AFR0 Mask */

#define GPIOC_AFRL_AFR1_Pos          4                                            /*!<GPIOC AFRL: AFR1 Position */
#define GPIOC_AFRL_AFR1_Msk          (0xFUL << GPIOC_AFRL_AFR1_Pos)               /*!<GPIOC AFRL: AFR1 Mask */

#define GPIOC_AFRL_AFR2_Pos          8                                            /*!<GPIOC AFRL: AFR2 Position */
#define GPIOC_AFRL_AFR2_Msk          (0xFUL << GPIOC_AFRL_AFR2_Pos)               /*!<GPIOC AFRL: AFR2 Mask */

#define GPIOC_AFRL_AFR3_Pos          12                                           /*!<GPIOC AFRL: AFR3 Position */
#define GPIOC_AFRL_AFR3_Msk          (0xFUL << GPIOC_AFRL_AFR3_Pos)               /*!<GPIOC AFRL: AFR3 Mask */

#define GPIOC_AFRL_AFR4_Pos          16                                           /*!<GPIOC AFRL: AFR4 Position */
#define GPIOC_AFRL_AFR4_Msk          (0xFUL << GPIOC_AFRL_AFR4_Pos)               /*!<GPIOC AFRL: AFR4 Mask */

#define GPIOC_AFRL_AFR5_Pos          20                                           /*!<GPIOC AFRL: AFR5 Position */
#define GPIOC_AFRL_AFR5_Msk          (0xFUL << GPIOC_AFRL_AFR5_Pos)               /*!<GPIOC AFRL: AFR5 Mask */

#define GPIOC_AFRL_AFR6_Pos          24                                           /*!<GPIOC AFRL: AFR6 Position */
#define GPIOC_AFRL_AFR6_Msk          (0xFUL << GPIOC_AFRL_AFR6_Pos)               /*!<GPIOC AFRL: AFR6 Mask */

#define GPIOC_AFRL_AFR7_Pos          28                                           /*!<GPIOC AFRL: AFR7 Position */
#define GPIOC_AFRL_AFR7_Msk          (0xFUL << GPIOC_AFRL_AFR7_Pos)               /*!<GPIOC AFRL: AFR7 Mask */

#define GPIOC_AFRL_Msk_ALL           (GPIOC_AFRL_AFR0_Msk          |\
                                      GPIOC_AFRL_AFR1_Msk          |\
                                      GPIOC_AFRL_AFR2_Msk          |\
                                      GPIOC_AFRL_AFR3_Msk          |\
                                      GPIOC_AFRL_AFR4_Msk          |\
                                      GPIOC_AFRL_AFR5_Msk          |\
                                      GPIOC_AFRL_AFR6_Msk          |\
                                      GPIOC_AFRL_AFR7_Msk          )

#define GPIOC_AFRH_AFR8_Pos          0                                            /*!<GPIOC AFRH: AFR8 Position */
#define GPIOC_AFRH_AFR8_Msk          (0xFUL /*<< GPIOC_AFRH_AFR8_Pos*/)           /*!<GPIOC AFRH: AFR8 Mask */

#define GPIOC_AFRH_AFR9_Pos          4                                            /*!<GPIOC AFRH: AFR9 Position */
#define GPIOC_AFRH_AFR9_Msk          (0xFUL << GPIOC_AFRH_AFR9_Pos)               /*!<GPIOC AFRH: AFR9 Mask */

#define GPIOC_AFRH_AFR10_Pos         8                                            /*!<GPIOC AFRH: AFR10 Position */
#define GPIOC_AFRH_AFR10_Msk         (0xFUL << GPIOC_AFRH_AFR10_Pos)              /*!<GPIOC AFRH: AFR10 Mask */

#define GPIOC_AFRH_AFR11_Pos         12                                           /*!<GPIOC AFRH: AFR11 Position */
#define GPIOC_AFRH_AFR11_Msk         (0xFUL << GPIOC_AFRH_AFR11_Pos)              /*!<GPIOC AFRH: AFR11 Mask */

#define GPIOC_AFRH_AFR12_Pos         16                                           /*!<GPIOC AFRH: AFR12 Position */
#define GPIOC_AFRH_AFR12_Msk         (0xFUL << GPIOC_AFRH_AFR12_Pos)              /*!<GPIOC AFRH: AFR12 Mask */

#define GPIOC_AFRH_AFR13_Pos         20                                           /*!<GPIOC AFRH: AFR13 Position */
#define GPIOC_AFRH_AFR13_Msk         (0xFUL << GPIOC_AFRH_AFR13_Pos)              /*!<GPIOC AFRH: AFR13 Mask */

#define GPIOC_AFRH_AFR14_Pos         24                                           /*!<GPIOC AFRH: AFR14 Position */
#define GPIOC_AFRH_AFR14_Msk         (0xFUL << GPIOC_AFRH_AFR14_Pos)              /*!<GPIOC AFRH: AFR14 Mask */

#define GPIOC_AFRH_AFR15_Pos         28                                           /*!<GPIOC AFRH: AFR15 Position */
#define GPIOC_AFRH_AFR15_Msk         (0xFUL << GPIOC_AFRH_AFR15_Pos)              /*!<GPIOC AFRH: AFR15 Mask */

#define GPIOC_AFRH_Msk_ALL           (GPIOC_AFRH_AFR8_Msk          |\
                                      GPIOC_AFRH_AFR9_Msk          |\
                                      GPIOC_AFRH_AFR10_Msk         |\
                                      GPIOC_AFRH_AFR11_Msk         |\
                                      GPIOC_AFRH_AFR12_Msk         |\
                                      GPIOC_AFRH_AFR13_Msk         |\
                                      GPIOC_AFRH_AFR14_Msk         |\
                                      GPIOC_AFRH_AFR15_Msk         )

#define GPIOD_MODER_MODER0_Pos       0                                            /*!<GPIOD MODER: MODER0 Position */
#define GPIOD_MODER_MODER0_Msk       (0x1UL /*<< GPIOD_MODER_MODER0_Pos*/)        /*!<GPIOD MODER: MODER0 Mask */

#define GPIOD_MODER_MODER1_Pos       1                                            /*!<GPIOD MODER: MODER1 Position */
#define GPIOD_MODER_MODER1_Msk       (0x1UL << GPIOD_MODER_MODER1_Pos)            /*!<GPIOD MODER: MODER1 Mask */

#define GPIOD_MODER_MODER2_Pos       2                                            /*!<GPIOD MODER: MODER2 Position */
#define GPIOD_MODER_MODER2_Msk       (0x1UL << GPIOD_MODER_MODER2_Pos)            /*!<GPIOD MODER: MODER2 Mask */

#define GPIOD_MODER_MODER3_Pos       3                                            /*!<GPIOD MODER: MODER3 Position */
#define GPIOD_MODER_MODER3_Msk       (0x1UL << GPIOD_MODER_MODER3_Pos)            /*!<GPIOD MODER: MODER3 Mask */

#define GPIOD_MODER_MODER4_Pos       4                                            /*!<GPIOD MODER: MODER4 Position */
#define GPIOD_MODER_MODER4_Msk       (0x1UL << GPIOD_MODER_MODER4_Pos)            /*!<GPIOD MODER: MODER4 Mask */

#define GPIOD_MODER_MODER5_Pos       5                                            /*!<GPIOD MODER: MODER5 Position */
#define GPIOD_MODER_MODER5_Msk       (0x1UL << GPIOD_MODER_MODER5_Pos)            /*!<GPIOD MODER: MODER5 Mask */

#define GPIOD_MODER_MODER6_Pos       6                                            /*!<GPIOD MODER: MODER6 Position */
#define GPIOD_MODER_MODER6_Msk       (0x1UL << GPIOD_MODER_MODER6_Pos)            /*!<GPIOD MODER: MODER6 Mask */

#define GPIOD_MODER_MODER7_Pos       7                                            /*!<GPIOD MODER: MODER7 Position */
#define GPIOD_MODER_MODER7_Msk       (0x1UL << GPIOD_MODER_MODER7_Pos)            /*!<GPIOD MODER: MODER7 Mask */

#define GPIOD_MODER_MODER8_Pos       8                                            /*!<GPIOD MODER: MODER8 Position */
#define GPIOD_MODER_MODER8_Msk       (0x1UL << GPIOD_MODER_MODER8_Pos)            /*!<GPIOD MODER: MODER8 Mask */

#define GPIOD_MODER_MODER9_Pos       9                                            /*!<GPIOD MODER: MODER9 Position */
#define GPIOD_MODER_MODER9_Msk       (0x1UL << GPIOD_MODER_MODER9_Pos)            /*!<GPIOD MODER: MODER9 Mask */

#define GPIOD_MODER_MODER10_Pos      10                                           /*!<GPIOD MODER: MODER10 Position */
#define GPIOD_MODER_MODER10_Msk      (0x1UL << GPIOD_MODER_MODER10_Pos)           /*!<GPIOD MODER: MODER10 Mask */

#define GPIOD_MODER_MODER11_Pos      11                                           /*!<GPIOD MODER: MODER11 Position */
#define GPIOD_MODER_MODER11_Msk      (0x1UL << GPIOD_MODER_MODER11_Pos)           /*!<GPIOD MODER: MODER11 Mask */

#define GPIOD_MODER_MODER12_Pos      12                                           /*!<GPIOD MODER: MODER12 Position */
#define GPIOD_MODER_MODER12_Msk      (0x1UL << GPIOD_MODER_MODER12_Pos)           /*!<GPIOD MODER: MODER12 Mask */

#define GPIOD_MODER_MODER13_Pos      13                                           /*!<GPIOD MODER: MODER13 Position */
#define GPIOD_MODER_MODER13_Msk      (0x1UL << GPIOD_MODER_MODER13_Pos)           /*!<GPIOD MODER: MODER13 Mask */

#define GPIOD_MODER_MODER14_Pos      14                                           /*!<GPIOD MODER: MODER14 Position */
#define GPIOD_MODER_MODER14_Msk      (0x1UL << GPIOD_MODER_MODER14_Pos)           /*!<GPIOD MODER: MODER14 Mask */

#define GPIOD_MODER_MODER15_Pos      15                                           /*!<GPIOD MODER: MODER15 Position */
#define GPIOD_MODER_MODER15_Msk      (0x1UL << GPIOD_MODER_MODER15_Pos)           /*!<GPIOD MODER: MODER15 Mask */

#define GPIOD_MODER_Msk_ALL          (GPIOD_MODER_MODER0_Msk       |\
                                      GPIOD_MODER_MODER1_Msk       |\
                                      GPIOD_MODER_MODER2_Msk       |\
                                      GPIOD_MODER_MODER3_Msk       |\
                                      GPIOD_MODER_MODER4_Msk       |\
                                      GPIOD_MODER_MODER5_Msk       |\
                                      GPIOD_MODER_MODER6_Msk       |\
                                      GPIOD_MODER_MODER7_Msk       |\
                                      GPIOD_MODER_MODER8_Msk       |\
                                      GPIOD_MODER_MODER9_Msk       |\
                                      GPIOD_MODER_MODER10_Msk      |\
                                      GPIOD_MODER_MODER11_Msk      |\
                                      GPIOD_MODER_MODER12_Msk      |\
                                      GPIOD_MODER_MODER13_Msk      |\
                                      GPIOD_MODER_MODER14_Msk      |\
                                      GPIOD_MODER_MODER15_Msk      )

#define GPIOD_IDR_IDR_Pos            0                                            /*!<GPIOD IDR: IDR Position */
#define GPIOD_IDR_IDR_Msk            (0xFFFFUL /*<< GPIOD_IDR_IDR_Pos*/)          /*!<GPIOD IDR: IDR Mask */

#define GPIOD_IDR_Msk_ALL            (GPIOD_IDR_IDR_Msk           )

#define GPIOD_ODR_ODR_Pos            0                                            /*!<GPIOD ODR: ODR Position */
#define GPIOD_ODR_ODR_Msk            (0xFFFFUL /*<< GPIOD_ODR_ODR_Pos*/)          /*!<GPIOD ODR: ODR Mask */

#define GPIOD_ODR_Msk_ALL            (GPIOD_ODR_ODR_Msk           )

#define GPIOD_BSRR_BS_Pos            0                                            /*!<GPIOD BSRR: BS Position */
#define GPIOD_BSRR_BS_Msk            (0xFFFFUL /*<< GPIOD_BSRR_BS_Pos*/)          /*!<GPIOD BSRR: BS Mask */

#define GPIOD_BSRR_BR_Pos            16                                           /*!<GPIOD BSRR: BR Position */
#define GPIOD_BSRR_BR_Msk            (0xFFFFUL << GPIOD_BSRR_BR_Pos)              /*!<GPIOD BSRR: BR Mask */

#define GPIOD_BSRR_Msk_ALL           (GPIOD_BSRR_BS_Msk            |\
                                      GPIOD_BSRR_BR_Msk            )

#define GPIOD_LCKR_LCK0_Pos          0                                            /*!<GPIOD LCKR: LCK0 Position */
#define GPIOD_LCKR_LCK0_Msk          (0x1UL /*<< GPIOD_LCKR_LCK0_Pos*/)           /*!<GPIOD LCKR: LCK0 Mask */

#define GPIOD_LCKR_LCK1_Pos          1                                            /*!<GPIOD LCKR: LCK1 Position */
#define GPIOD_LCKR_LCK1_Msk          (0x1UL << GPIOD_LCKR_LCK1_Pos)               /*!<GPIOD LCKR: LCK1 Mask */

#define GPIOD_LCKR_LCK2_Pos          2                                            /*!<GPIOD LCKR: LCK2 Position */
#define GPIOD_LCKR_LCK2_Msk          (0x1UL << GPIOD_LCKR_LCK2_Pos)               /*!<GPIOD LCKR: LCK2 Mask */

#define GPIOD_LCKR_LCK3_Pos          3                                            /*!<GPIOD LCKR: LCK3 Position */
#define GPIOD_LCKR_LCK3_Msk          (0x1UL << GPIOD_LCKR_LCK3_Pos)               /*!<GPIOD LCKR: LCK3 Mask */

#define GPIOD_LCKR_LCK4_Pos          4                                            /*!<GPIOD LCKR: LCK4 Position */
#define GPIOD_LCKR_LCK4_Msk          (0x1UL << GPIOD_LCKR_LCK4_Pos)               /*!<GPIOD LCKR: LCK4 Mask */

#define GPIOD_LCKR_LCK5_Pos          5                                            /*!<GPIOD LCKR: LCK5 Position */
#define GPIOD_LCKR_LCK5_Msk          (0x1UL << GPIOD_LCKR_LCK5_Pos)               /*!<GPIOD LCKR: LCK5 Mask */

#define GPIOD_LCKR_LCK6_Pos          6                                            /*!<GPIOD LCKR: LCK6 Position */
#define GPIOD_LCKR_LCK6_Msk          (0x1UL << GPIOD_LCKR_LCK6_Pos)               /*!<GPIOD LCKR: LCK6 Mask */

#define GPIOD_LCKR_LCK7_Pos          7                                            /*!<GPIOD LCKR: LCK7 Position */
#define GPIOD_LCKR_LCK7_Msk          (0x1UL << GPIOD_LCKR_LCK7_Pos)               /*!<GPIOD LCKR: LCK7 Mask */

#define GPIOD_LCKR_LCK8_Pos          8                                            /*!<GPIOD LCKR: LCK8 Position */
#define GPIOD_LCKR_LCK8_Msk          (0x1UL << GPIOD_LCKR_LCK8_Pos)               /*!<GPIOD LCKR: LCK8 Mask */

#define GPIOD_LCKR_LCK9_Pos          9                                            /*!<GPIOD LCKR: LCK9 Position */
#define GPIOD_LCKR_LCK9_Msk          (0x1UL << GPIOD_LCKR_LCK9_Pos)               /*!<GPIOD LCKR: LCK9 Mask */

#define GPIOD_LCKR_LCK10_Pos         10                                           /*!<GPIOD LCKR: LCK10 Position */
#define GPIOD_LCKR_LCK10_Msk         (0x1UL << GPIOD_LCKR_LCK10_Pos)              /*!<GPIOD LCKR: LCK10 Mask */

#define GPIOD_LCKR_LCK11_Pos         11                                           /*!<GPIOD LCKR: LCK11 Position */
#define GPIOD_LCKR_LCK11_Msk         (0x1UL << GPIOD_LCKR_LCK11_Pos)              /*!<GPIOD LCKR: LCK11 Mask */

#define GPIOD_LCKR_LCK12_Pos         12                                           /*!<GPIOD LCKR: LCK12 Position */
#define GPIOD_LCKR_LCK12_Msk         (0x1UL << GPIOD_LCKR_LCK12_Pos)              /*!<GPIOD LCKR: LCK12 Mask */

#define GPIOD_LCKR_LCK13_Pos         13                                           /*!<GPIOD LCKR: LCK13 Position */
#define GPIOD_LCKR_LCK13_Msk         (0x1UL << GPIOD_LCKR_LCK13_Pos)              /*!<GPIOD LCKR: LCK13 Mask */

#define GPIOD_LCKR_LCK14_Pos         14                                           /*!<GPIOD LCKR: LCK14 Position */
#define GPIOD_LCKR_LCK14_Msk         (0x1UL << GPIOD_LCKR_LCK14_Pos)              /*!<GPIOD LCKR: LCK14 Mask */

#define GPIOD_LCKR_LCK15_Pos         15                                           /*!<GPIOD LCKR: LCK15 Position */
#define GPIOD_LCKR_LCK15_Msk         (0x1UL << GPIOD_LCKR_LCK15_Pos)              /*!<GPIOD LCKR: LCK15 Mask */

#define GPIOD_LCKR_LOCK_Pos          16                                           /*!<GPIOD LCKR: LOCK Position */
#define GPIOD_LCKR_LOCK_Msk          (0xFFFFUL << GPIOD_LCKR_LOCK_Pos)            /*!<GPIOD LCKR: LOCK Mask */

#define GPIOD_LCKR_Msk_ALL           (GPIOD_LCKR_LCK0_Msk          |\
                                      GPIOD_LCKR_LCK1_Msk          |\
                                      GPIOD_LCKR_LCK2_Msk          |\
                                      GPIOD_LCKR_LCK3_Msk          |\
                                      GPIOD_LCKR_LCK4_Msk          |\
                                      GPIOD_LCKR_LCK5_Msk          |\
                                      GPIOD_LCKR_LCK6_Msk          |\
                                      GPIOD_LCKR_LCK7_Msk          |\
                                      GPIOD_LCKR_LCK8_Msk          |\
                                      GPIOD_LCKR_LCK9_Msk          |\
                                      GPIOD_LCKR_LCK10_Msk         |\
                                      GPIOD_LCKR_LCK11_Msk         |\
                                      GPIOD_LCKR_LCK12_Msk         |\
                                      GPIOD_LCKR_LCK13_Msk         |\
                                      GPIOD_LCKR_LCK14_Msk         |\
                                      GPIOD_LCKR_LCK15_Msk         |\
                                      GPIOD_LCKR_LOCK_Msk          )

#define GPIOD_IE_IE0_Pos             0                                            /*!<GPIOD IE: IE0 Position */
#define GPIOD_IE_IE0_Msk             (0x1UL /*<< GPIOD_IE_IE0_Pos*/)              /*!<GPIOD IE: IE0 Mask */

#define GPIOD_IE_IE1_Pos             1                                            /*!<GPIOD IE: IE1 Position */
#define GPIOD_IE_IE1_Msk             (0x1UL << GPIOD_IE_IE1_Pos)                  /*!<GPIOD IE: IE1 Mask */

#define GPIOD_IE_IE2_Pos             2                                            /*!<GPIOD IE: IE2 Position */
#define GPIOD_IE_IE2_Msk             (0x1UL << GPIOD_IE_IE2_Pos)                  /*!<GPIOD IE: IE2 Mask */

#define GPIOD_IE_IE3_Pos             3                                            /*!<GPIOD IE: IE3 Position */
#define GPIOD_IE_IE3_Msk             (0x1UL << GPIOD_IE_IE3_Pos)                  /*!<GPIOD IE: IE3 Mask */

#define GPIOD_IE_IE4_Pos             4                                            /*!<GPIOD IE: IE4 Position */
#define GPIOD_IE_IE4_Msk             (0x1UL << GPIOD_IE_IE4_Pos)                  /*!<GPIOD IE: IE4 Mask */

#define GPIOD_IE_IE5_Pos             5                                            /*!<GPIOD IE: IE5 Position */
#define GPIOD_IE_IE5_Msk             (0x1UL << GPIOD_IE_IE5_Pos)                  /*!<GPIOD IE: IE5 Mask */

#define GPIOD_IE_IE6_Pos             6                                            /*!<GPIOD IE: IE6 Position */
#define GPIOD_IE_IE6_Msk             (0x1UL << GPIOD_IE_IE6_Pos)                  /*!<GPIOD IE: IE6 Mask */

#define GPIOD_IE_IE7_Pos             7                                            /*!<GPIOD IE: IE7 Position */
#define GPIOD_IE_IE7_Msk             (0x1UL << GPIOD_IE_IE7_Pos)                  /*!<GPIOD IE: IE7 Mask */

#define GPIOD_IE_IE8_Pos             8                                            /*!<GPIOD IE: IE8 Position */
#define GPIOD_IE_IE8_Msk             (0x1UL << GPIOD_IE_IE8_Pos)                  /*!<GPIOD IE: IE8 Mask */

#define GPIOD_IE_IE9_Pos             9                                            /*!<GPIOD IE: IE9 Position */
#define GPIOD_IE_IE9_Msk             (0x1UL << GPIOD_IE_IE9_Pos)                  /*!<GPIOD IE: IE9 Mask */

#define GPIOD_IE_IE10_Pos            10                                           /*!<GPIOD IE: IE10 Position */
#define GPIOD_IE_IE10_Msk            (0x1UL << GPIOD_IE_IE10_Pos)                 /*!<GPIOD IE: IE10 Mask */

#define GPIOD_IE_IE11_Pos            11                                           /*!<GPIOD IE: IE11 Position */
#define GPIOD_IE_IE11_Msk            (0x1UL << GPIOD_IE_IE11_Pos)                 /*!<GPIOD IE: IE11 Mask */

#define GPIOD_IE_IE12_Pos            12                                           /*!<GPIOD IE: IE12 Position */
#define GPIOD_IE_IE12_Msk            (0x1UL << GPIOD_IE_IE12_Pos)                 /*!<GPIOD IE: IE12 Mask */

#define GPIOD_IE_IE13_Pos            13                                           /*!<GPIOD IE: IE13 Position */
#define GPIOD_IE_IE13_Msk            (0x1UL << GPIOD_IE_IE13_Pos)                 /*!<GPIOD IE: IE13 Mask */

#define GPIOD_IE_IE14_Pos            14                                           /*!<GPIOD IE: IE14 Position */
#define GPIOD_IE_IE14_Msk            (0x1UL << GPIOD_IE_IE14_Pos)                 /*!<GPIOD IE: IE14 Mask */

#define GPIOD_IE_IE15_Pos            15                                           /*!<GPIOD IE: IE15 Position */
#define GPIOD_IE_IE15_Msk            (0x1UL << GPIOD_IE_IE15_Pos)                 /*!<GPIOD IE: IE15 Mask */

#define GPIOD_IE_Msk_ALL             (GPIOD_IE_IE0_Msk             |\
                                      GPIOD_IE_IE1_Msk             |\
                                      GPIOD_IE_IE2_Msk             |\
                                      GPIOD_IE_IE3_Msk             |\
                                      GPIOD_IE_IE4_Msk             |\
                                      GPIOD_IE_IE5_Msk             |\
                                      GPIOD_IE_IE6_Msk             |\
                                      GPIOD_IE_IE7_Msk             |\
                                      GPIOD_IE_IE8_Msk             |\
                                      GPIOD_IE_IE9_Msk             |\
                                      GPIOD_IE_IE10_Msk            |\
                                      GPIOD_IE_IE11_Msk            |\
                                      GPIOD_IE_IE12_Msk            |\
                                      GPIOD_IE_IE13_Msk            |\
                                      GPIOD_IE_IE14_Msk            |\
                                      GPIOD_IE_IE15_Msk            )

#define GPIOD_OTYPER_OT4_Pos         4                                            /*!<GPIOD OTYPER: OT4 Position */
#define GPIOD_OTYPER_OT4_Msk         (0x1UL << GPIOD_OTYPER_OT4_Pos)              /*!<GPIOD OTYPER: OT4 Mask */

#define GPIOD_OTYPER_OT5_Pos         5                                            /*!<GPIOD OTYPER: OT5 Position */
#define GPIOD_OTYPER_OT5_Msk         (0x1UL << GPIOD_OTYPER_OT5_Pos)              /*!<GPIOD OTYPER: OT5 Mask */

#define GPIOD_OTYPER_OT6_Pos         6                                            /*!<GPIOD OTYPER: OT6 Position */
#define GPIOD_OTYPER_OT6_Msk         (0x1UL << GPIOD_OTYPER_OT6_Pos)              /*!<GPIOD OTYPER: OT6 Mask */

#define GPIOD_OTYPER_OT7_Pos         7                                            /*!<GPIOD OTYPER: OT7 Position */
#define GPIOD_OTYPER_OT7_Msk         (0x1UL << GPIOD_OTYPER_OT7_Pos)              /*!<GPIOD OTYPER: OT7 Mask */

#define GPIOD_OTYPER_OT8_Pos         8                                            /*!<GPIOD OTYPER: OT8 Position */
#define GPIOD_OTYPER_OT8_Msk         (0x1UL << GPIOD_OTYPER_OT8_Pos)              /*!<GPIOD OTYPER: OT8 Mask */

#define GPIOD_OTYPER_OT9_Pos         9                                            /*!<GPIOD OTYPER: OT9 Position */
#define GPIOD_OTYPER_OT9_Msk         (0x1UL << GPIOD_OTYPER_OT9_Pos)              /*!<GPIOD OTYPER: OT9 Mask */

#define GPIOD_OTYPER_OT10_Pos        10                                           /*!<GPIOD OTYPER: OT10 Position */
#define GPIOD_OTYPER_OT10_Msk        (0x1UL << GPIOD_OTYPER_OT10_Pos)             /*!<GPIOD OTYPER: OT10 Mask */

#define GPIOD_OTYPER_OT12_Pos        12                                           /*!<GPIOD OTYPER: OT12 Position */
#define GPIOD_OTYPER_OT12_Msk        (0x1UL << GPIOD_OTYPER_OT12_Pos)             /*!<GPIOD OTYPER: OT12 Mask */

#define GPIOD_OTYPER_OT13_Pos        13                                           /*!<GPIOD OTYPER: OT13 Position */
#define GPIOD_OTYPER_OT13_Msk        (0x1UL << GPIOD_OTYPER_OT13_Pos)             /*!<GPIOD OTYPER: OT13 Mask */

#define GPIOD_OTYPER_OT14_Pos        14                                           /*!<GPIOD OTYPER: OT14 Position */
#define GPIOD_OTYPER_OT14_Msk        (0x1UL << GPIOD_OTYPER_OT14_Pos)             /*!<GPIOD OTYPER: OT14 Mask */

#define GPIOD_OTYPER_OT15_Pos        15                                           /*!<GPIOD OTYPER: OT15 Position */
#define GPIOD_OTYPER_OT15_Msk        (0x1UL << GPIOD_OTYPER_OT15_Pos)             /*!<GPIOD OTYPER: OT15 Mask */

#define GPIOD_OTYPER_Msk_ALL         (GPIOD_OTYPER_OT4_Msk         |\
                                      GPIOD_OTYPER_OT5_Msk         |\
                                      GPIOD_OTYPER_OT6_Msk         |\
                                      GPIOD_OTYPER_OT7_Msk         |\
                                      GPIOD_OTYPER_OT8_Msk         |\
                                      GPIOD_OTYPER_OT9_Msk         |\
                                      GPIOD_OTYPER_OT10_Msk        |\
                                      GPIOD_OTYPER_OT12_Msk        |\
                                      GPIOD_OTYPER_OT13_Msk        |\
                                      GPIOD_OTYPER_OT14_Msk        |\
                                      GPIOD_OTYPER_OT15_Msk        )

#define GPIOD_ODRVR_ODRVR_SINK2_Pos  4                                            /*!<GPIOD ODRVR: ODRVR_SINK2 Position */
#define GPIOD_ODRVR_ODRVR_SINK2_Msk  (0x1UL << GPIOD_ODRVR_ODRVR_SINK2_Pos)       /*!<GPIOD ODRVR: ODRVR_SINK2 Mask */

#define GPIOD_ODRVR_ODRVR_SINK3_Pos  6                                            /*!<GPIOD ODRVR: ODRVR_SINK3 Position */
#define GPIOD_ODRVR_ODRVR_SINK3_Msk  (0x1UL << GPIOD_ODRVR_ODRVR_SINK3_Pos)       /*!<GPIOD ODRVR: ODRVR_SINK3 Mask */

#define GPIOD_ODRVR_ODRVR_SINK4_Pos  8                                            /*!<GPIOD ODRVR: ODRVR_SINK4 Position */
#define GPIOD_ODRVR_ODRVR_SINK4_Msk  (0x1UL << GPIOD_ODRVR_ODRVR_SINK4_Pos)       /*!<GPIOD ODRVR: ODRVR_SINK4 Mask */

#define GPIOD_ODRVR_ODRVR_SINK5_Pos  10                                           /*!<GPIOD ODRVR: ODRVR_SINK5 Position */
#define GPIOD_ODRVR_ODRVR_SINK5_Msk  (0x1UL << GPIOD_ODRVR_ODRVR_SINK5_Pos)       /*!<GPIOD ODRVR: ODRVR_SINK5 Mask */

#define GPIOD_ODRVR_ODRVR_SINK6_Pos  12                                           /*!<GPIOD ODRVR: ODRVR_SINK6 Position */
#define GPIOD_ODRVR_ODRVR_SINK6_Msk  (0x1UL << GPIOD_ODRVR_ODRVR_SINK6_Pos)       /*!<GPIOD ODRVR: ODRVR_SINK6 Mask */

#define GPIOD_ODRVR_ODRVR_SINK7_Pos  14                                           /*!<GPIOD ODRVR: ODRVR_SINK7 Position */
#define GPIOD_ODRVR_ODRVR_SINK7_Msk  (0x1UL << GPIOD_ODRVR_ODRVR_SINK7_Pos)       /*!<GPIOD ODRVR: ODRVR_SINK7 Mask */

#define GPIOD_ODRVR_ODRVR_SINK8_Pos  16                                           /*!<GPIOD ODRVR: ODRVR_SINK8 Position */
#define GPIOD_ODRVR_ODRVR_SINK8_Msk  (0x1UL << GPIOD_ODRVR_ODRVR_SINK8_Pos)       /*!<GPIOD ODRVR: ODRVR_SINK8 Mask */

#define GPIOD_ODRVR_ODRVR_SINK9_Pos  18                                           /*!<GPIOD ODRVR: ODRVR_SINK9 Position */
#define GPIOD_ODRVR_ODRVR_SINK9_Msk  (0x1UL << GPIOD_ODRVR_ODRVR_SINK9_Pos)       /*!<GPIOD ODRVR: ODRVR_SINK9 Mask */

#define GPIOD_ODRVR_Msk_ALL          (GPIOD_ODRVR_ODRVR_SINK2_Msk  |\
                                      GPIOD_ODRVR_ODRVR_SINK3_Msk  |\
                                      GPIOD_ODRVR_ODRVR_SINK4_Msk  |\
                                      GPIOD_ODRVR_ODRVR_SINK5_Msk  |\
                                      GPIOD_ODRVR_ODRVR_SINK6_Msk  |\
                                      GPIOD_ODRVR_ODRVR_SINK7_Msk  |\
                                      GPIOD_ODRVR_ODRVR_SINK8_Msk  |\
                                      GPIOD_ODRVR_ODRVR_SINK9_Msk  )

#define GPIOD_PUPDR_PHDR0_Pos        0                                            /*!<GPIOD PUPDR: PHDR0 Position */
#define GPIOD_PUPDR_PHDR0_Msk        (0x1UL /*<< GPIOD_PUPDR_PHDR0_Pos*/)         /*!<GPIOD PUPDR: PHDR0 Mask */

#define GPIOD_PUPDR_PHDR1_Pos        2                                            /*!<GPIOD PUPDR: PHDR1 Position */
#define GPIOD_PUPDR_PHDR1_Msk        (0x1UL << GPIOD_PUPDR_PHDR1_Pos)             /*!<GPIOD PUPDR: PHDR1 Mask */

#define GPIOD_PUPDR_PHDR2_Pos        4                                            /*!<GPIOD PUPDR: PHDR2 Position */
#define GPIOD_PUPDR_PHDR2_Msk        (0x1UL << GPIOD_PUPDR_PHDR2_Pos)             /*!<GPIOD PUPDR: PHDR2 Mask */

#define GPIOD_PUPDR_PHDR3_Pos        6                                            /*!<GPIOD PUPDR: PHDR3 Position */
#define GPIOD_PUPDR_PHDR3_Msk        (0x1UL << GPIOD_PUPDR_PHDR3_Pos)             /*!<GPIOD PUPDR: PHDR3 Mask */

#define GPIOD_PUPDR_PHDR4_Pos        8                                            /*!<GPIOD PUPDR: PHDR4 Position */
#define GPIOD_PUPDR_PHDR4_Msk        (0x1UL << GPIOD_PUPDR_PHDR4_Pos)             /*!<GPIOD PUPDR: PHDR4 Mask */

#define GPIOD_PUPDR_PHDR5_Pos        10                                           /*!<GPIOD PUPDR: PHDR5 Position */
#define GPIOD_PUPDR_PHDR5_Msk        (0x1UL << GPIOD_PUPDR_PHDR5_Pos)             /*!<GPIOD PUPDR: PHDR5 Mask */

#define GPIOD_PUPDR_PHDR6_Pos        12                                           /*!<GPIOD PUPDR: PHDR6 Position */
#define GPIOD_PUPDR_PHDR6_Msk        (0x1UL << GPIOD_PUPDR_PHDR6_Pos)             /*!<GPIOD PUPDR: PHDR6 Mask */

#define GPIOD_PUPDR_PHDR7_Pos        14                                           /*!<GPIOD PUPDR: PHDR7 Position */
#define GPIOD_PUPDR_PHDR7_Msk        (0x1UL << GPIOD_PUPDR_PHDR7_Pos)             /*!<GPIOD PUPDR: PHDR7 Mask */

#define GPIOD_PUPDR_PHDR8_Pos        16                                           /*!<GPIOD PUPDR: PHDR8 Position */
#define GPIOD_PUPDR_PHDR8_Msk        (0x1UL << GPIOD_PUPDR_PHDR8_Pos)             /*!<GPIOD PUPDR: PHDR8 Mask */

#define GPIOD_PUPDR_PHDR9_Pos        18                                           /*!<GPIOD PUPDR: PHDR9 Position */
#define GPIOD_PUPDR_PHDR9_Msk        (0x1UL << GPIOD_PUPDR_PHDR9_Pos)             /*!<GPIOD PUPDR: PHDR9 Mask */

#define GPIOD_PUPDR_PHDR10_Pos       20                                           /*!<GPIOD PUPDR: PHDR10 Position */
#define GPIOD_PUPDR_PHDR10_Msk       (0x1UL << GPIOD_PUPDR_PHDR10_Pos)            /*!<GPIOD PUPDR: PHDR10 Mask */

#define GPIOD_PUPDR_PHDR11_Pos       22                                           /*!<GPIOD PUPDR: PHDR11 Position */
#define GPIOD_PUPDR_PHDR11_Msk       (0x1UL << GPIOD_PUPDR_PHDR11_Pos)            /*!<GPIOD PUPDR: PHDR11 Mask */

#define GPIOD_PUPDR_PHDR12_Pos       24                                           /*!<GPIOD PUPDR: PHDR12 Position */
#define GPIOD_PUPDR_PHDR12_Msk       (0x1UL << GPIOD_PUPDR_PHDR12_Pos)            /*!<GPIOD PUPDR: PHDR12 Mask */

#define GPIOD_PUPDR_PHDR13_Pos       26                                           /*!<GPIOD PUPDR: PHDR13 Position */
#define GPIOD_PUPDR_PHDR13_Msk       (0x1UL << GPIOD_PUPDR_PHDR13_Pos)            /*!<GPIOD PUPDR: PHDR13 Mask */

#define GPIOD_PUPDR_PHDR14_Pos       28                                           /*!<GPIOD PUPDR: PHDR14 Position */
#define GPIOD_PUPDR_PHDR14_Msk       (0x1UL << GPIOD_PUPDR_PHDR14_Pos)            /*!<GPIOD PUPDR: PHDR14 Mask */

#define GPIOD_PUPDR_PHDR15_Pos       30                                           /*!<GPIOD PUPDR: PHDR15 Position */
#define GPIOD_PUPDR_PHDR15_Msk       (0x1UL << GPIOD_PUPDR_PHDR15_Pos)            /*!<GPIOD PUPDR: PHDR15 Mask */

#define GPIOD_PUPDR_Msk_ALL          (GPIOD_PUPDR_PHDR0_Msk        |\
                                      GPIOD_PUPDR_PHDR1_Msk        |\
                                      GPIOD_PUPDR_PHDR2_Msk        |\
                                      GPIOD_PUPDR_PHDR3_Msk        |\
                                      GPIOD_PUPDR_PHDR4_Msk        |\
                                      GPIOD_PUPDR_PHDR5_Msk        |\
                                      GPIOD_PUPDR_PHDR6_Msk        |\
                                      GPIOD_PUPDR_PHDR7_Msk        |\
                                      GPIOD_PUPDR_PHDR8_Msk        |\
                                      GPIOD_PUPDR_PHDR9_Msk        |\
                                      GPIOD_PUPDR_PHDR10_Msk       |\
                                      GPIOD_PUPDR_PHDR11_Msk       |\
                                      GPIOD_PUPDR_PHDR12_Msk       |\
                                      GPIOD_PUPDR_PHDR13_Msk       |\
                                      GPIOD_PUPDR_PHDR14_Msk       |\
                                      GPIOD_PUPDR_PHDR15_Msk       )

#define GPIOD_TTLEN_TTLEN0_Pos       0                                            /*!<GPIOD TTLEN: TTLEN0 Position */
#define GPIOD_TTLEN_TTLEN0_Msk       (0x1UL /*<< GPIOD_TTLEN_TTLEN0_Pos*/)        /*!<GPIOD TTLEN: TTLEN0 Mask */

#define GPIOD_TTLEN_TTLEN1_Pos       1                                            /*!<GPIOD TTLEN: TTLEN1 Position */
#define GPIOD_TTLEN_TTLEN1_Msk       (0x1UL << GPIOD_TTLEN_TTLEN1_Pos)            /*!<GPIOD TTLEN: TTLEN1 Mask */

#define GPIOD_TTLEN_TTLEN2_Pos       2                                            /*!<GPIOD TTLEN: TTLEN2 Position */
#define GPIOD_TTLEN_TTLEN2_Msk       (0x1UL << GPIOD_TTLEN_TTLEN2_Pos)            /*!<GPIOD TTLEN: TTLEN2 Mask */

#define GPIOD_TTLEN_TTLEN3_Pos       3                                            /*!<GPIOD TTLEN: TTLEN3 Position */
#define GPIOD_TTLEN_TTLEN3_Msk       (0x1UL << GPIOD_TTLEN_TTLEN3_Pos)            /*!<GPIOD TTLEN: TTLEN3 Mask */

#define GPIOD_TTLEN_TTLEN4_Pos       4                                            /*!<GPIOD TTLEN: TTLEN4 Position */
#define GPIOD_TTLEN_TTLEN4_Msk       (0x1UL << GPIOD_TTLEN_TTLEN4_Pos)            /*!<GPIOD TTLEN: TTLEN4 Mask */

#define GPIOD_TTLEN_TTLEN5_Pos       5                                            /*!<GPIOD TTLEN: TTLEN5 Position */
#define GPIOD_TTLEN_TTLEN5_Msk       (0x1UL << GPIOD_TTLEN_TTLEN5_Pos)            /*!<GPIOD TTLEN: TTLEN5 Mask */

#define GPIOD_TTLEN_TTLEN6_Pos       6                                            /*!<GPIOD TTLEN: TTLEN6 Position */
#define GPIOD_TTLEN_TTLEN6_Msk       (0x1UL << GPIOD_TTLEN_TTLEN6_Pos)            /*!<GPIOD TTLEN: TTLEN6 Mask */

#define GPIOD_TTLEN_TTLEN7_Pos       7                                            /*!<GPIOD TTLEN: TTLEN7 Position */
#define GPIOD_TTLEN_TTLEN7_Msk       (0x1UL << GPIOD_TTLEN_TTLEN7_Pos)            /*!<GPIOD TTLEN: TTLEN7 Mask */

#define GPIOD_TTLEN_TTLEN8_Pos       8                                            /*!<GPIOD TTLEN: TTLEN8 Position */
#define GPIOD_TTLEN_TTLEN8_Msk       (0x1UL << GPIOD_TTLEN_TTLEN8_Pos)            /*!<GPIOD TTLEN: TTLEN8 Mask */

#define GPIOD_TTLEN_TTLEN9_Pos       9                                            /*!<GPIOD TTLEN: TTLEN9 Position */
#define GPIOD_TTLEN_TTLEN9_Msk       (0x1UL << GPIOD_TTLEN_TTLEN9_Pos)            /*!<GPIOD TTLEN: TTLEN9 Mask */

#define GPIOD_TTLEN_TTLEN10_Pos      10                                           /*!<GPIOD TTLEN: TTLEN10 Position */
#define GPIOD_TTLEN_TTLEN10_Msk      (0x1UL << GPIOD_TTLEN_TTLEN10_Pos)           /*!<GPIOD TTLEN: TTLEN10 Mask */

#define GPIOD_TTLEN_TTLEN11_Pos      11                                           /*!<GPIOD TTLEN: TTLEN11 Position */
#define GPIOD_TTLEN_TTLEN11_Msk      (0x1UL << GPIOD_TTLEN_TTLEN11_Pos)           /*!<GPIOD TTLEN: TTLEN11 Mask */

#define GPIOD_TTLEN_TTLEN12_Pos      12                                           /*!<GPIOD TTLEN: TTLEN12 Position */
#define GPIOD_TTLEN_TTLEN12_Msk      (0x1UL << GPIOD_TTLEN_TTLEN12_Pos)           /*!<GPIOD TTLEN: TTLEN12 Mask */

#define GPIOD_TTLEN_TTLEN13_Pos      13                                           /*!<GPIOD TTLEN: TTLEN13 Position */
#define GPIOD_TTLEN_TTLEN13_Msk      (0x1UL << GPIOD_TTLEN_TTLEN13_Pos)           /*!<GPIOD TTLEN: TTLEN13 Mask */

#define GPIOD_TTLEN_TTLEN14_Pos      14                                           /*!<GPIOD TTLEN: TTLEN14 Position */
#define GPIOD_TTLEN_TTLEN14_Msk      (0x1UL << GPIOD_TTLEN_TTLEN14_Pos)           /*!<GPIOD TTLEN: TTLEN14 Mask */

#define GPIOD_TTLEN_TTLEN15_Pos      15                                           /*!<GPIOD TTLEN: TTLEN15 Position */
#define GPIOD_TTLEN_TTLEN15_Msk      (0x1UL << GPIOD_TTLEN_TTLEN15_Pos)           /*!<GPIOD TTLEN: TTLEN15 Mask */

#define GPIOD_TTLEN_Msk_ALL          (GPIOD_TTLEN_TTLEN0_Msk       |\
                                      GPIOD_TTLEN_TTLEN1_Msk       |\
                                      GPIOD_TTLEN_TTLEN2_Msk       |\
                                      GPIOD_TTLEN_TTLEN3_Msk       |\
                                      GPIOD_TTLEN_TTLEN4_Msk       |\
                                      GPIOD_TTLEN_TTLEN5_Msk       |\
                                      GPIOD_TTLEN_TTLEN6_Msk       |\
                                      GPIOD_TTLEN_TTLEN7_Msk       |\
                                      GPIOD_TTLEN_TTLEN8_Msk       |\
                                      GPIOD_TTLEN_TTLEN9_Msk       |\
                                      GPIOD_TTLEN_TTLEN10_Msk      |\
                                      GPIOD_TTLEN_TTLEN11_Msk      |\
                                      GPIOD_TTLEN_TTLEN12_Msk      |\
                                      GPIOD_TTLEN_TTLEN13_Msk      |\
                                      GPIOD_TTLEN_TTLEN14_Msk      |\
                                      GPIOD_TTLEN_TTLEN15_Msk      )

#define GPIOD_AFRL_AFR0_Pos          0                                            /*!<GPIOD AFRL: AFR0 Position */
#define GPIOD_AFRL_AFR0_Msk          (0xFUL /*<< GPIOD_AFRL_AFR0_Pos*/)           /*!<GPIOD AFRL: AFR0 Mask */

#define GPIOD_AFRL_AFR1_Pos          4                                            /*!<GPIOD AFRL: AFR1 Position */
#define GPIOD_AFRL_AFR1_Msk          (0xFUL << GPIOD_AFRL_AFR1_Pos)               /*!<GPIOD AFRL: AFR1 Mask */

#define GPIOD_AFRL_AFR2_Pos          8                                            /*!<GPIOD AFRL: AFR2 Position */
#define GPIOD_AFRL_AFR2_Msk          (0xFUL << GPIOD_AFRL_AFR2_Pos)               /*!<GPIOD AFRL: AFR2 Mask */

#define GPIOD_AFRL_AFR3_Pos          12                                           /*!<GPIOD AFRL: AFR3 Position */
#define GPIOD_AFRL_AFR3_Msk          (0xFUL << GPIOD_AFRL_AFR3_Pos)               /*!<GPIOD AFRL: AFR3 Mask */

#define GPIOD_AFRL_AFR4_Pos          16                                           /*!<GPIOD AFRL: AFR4 Position */
#define GPIOD_AFRL_AFR4_Msk          (0xFUL << GPIOD_AFRL_AFR4_Pos)               /*!<GPIOD AFRL: AFR4 Mask */

#define GPIOD_AFRL_AFR5_Pos          20                                           /*!<GPIOD AFRL: AFR5 Position */
#define GPIOD_AFRL_AFR5_Msk          (0xFUL << GPIOD_AFRL_AFR5_Pos)               /*!<GPIOD AFRL: AFR5 Mask */

#define GPIOD_AFRL_AFR6_Pos          24                                           /*!<GPIOD AFRL: AFR6 Position */
#define GPIOD_AFRL_AFR6_Msk          (0xFUL << GPIOD_AFRL_AFR6_Pos)               /*!<GPIOD AFRL: AFR6 Mask */

#define GPIOD_AFRL_AFR7_Pos          28                                           /*!<GPIOD AFRL: AFR7 Position */
#define GPIOD_AFRL_AFR7_Msk          (0xFUL << GPIOD_AFRL_AFR7_Pos)               /*!<GPIOD AFRL: AFR7 Mask */

#define GPIOD_AFRL_Msk_ALL           (GPIOD_AFRL_AFR0_Msk          |\
                                      GPIOD_AFRL_AFR1_Msk          |\
                                      GPIOD_AFRL_AFR2_Msk          |\
                                      GPIOD_AFRL_AFR3_Msk          |\
                                      GPIOD_AFRL_AFR4_Msk          |\
                                      GPIOD_AFRL_AFR5_Msk          |\
                                      GPIOD_AFRL_AFR6_Msk          |\
                                      GPIOD_AFRL_AFR7_Msk          )

#define GPIOD_AFRH_AFR8_Pos          0                                            /*!<GPIOD AFRH: AFR8 Position */
#define GPIOD_AFRH_AFR8_Msk          (0xFUL /*<< GPIOD_AFRH_AFR8_Pos*/)           /*!<GPIOD AFRH: AFR8 Mask */

#define GPIOD_AFRH_AFR9_Pos          4                                            /*!<GPIOD AFRH: AFR9 Position */
#define GPIOD_AFRH_AFR9_Msk          (0xFUL << GPIOD_AFRH_AFR9_Pos)               /*!<GPIOD AFRH: AFR9 Mask */

#define GPIOD_AFRH_AFR10_Pos         8                                            /*!<GPIOD AFRH: AFR10 Position */
#define GPIOD_AFRH_AFR10_Msk         (0xFUL << GPIOD_AFRH_AFR10_Pos)              /*!<GPIOD AFRH: AFR10 Mask */

#define GPIOD_AFRH_AFR11_Pos         12                                           /*!<GPIOD AFRH: AFR11 Position */
#define GPIOD_AFRH_AFR11_Msk         (0xFUL << GPIOD_AFRH_AFR11_Pos)              /*!<GPIOD AFRH: AFR11 Mask */

#define GPIOD_AFRH_AFR12_Pos         16                                           /*!<GPIOD AFRH: AFR12 Position */
#define GPIOD_AFRH_AFR12_Msk         (0xFUL << GPIOD_AFRH_AFR12_Pos)              /*!<GPIOD AFRH: AFR12 Mask */

#define GPIOD_AFRH_AFR13_Pos         20                                           /*!<GPIOD AFRH: AFR13 Position */
#define GPIOD_AFRH_AFR13_Msk         (0xFUL << GPIOD_AFRH_AFR13_Pos)              /*!<GPIOD AFRH: AFR13 Mask */

#define GPIOD_AFRH_AFR14_Pos         24                                           /*!<GPIOD AFRH: AFR14 Position */
#define GPIOD_AFRH_AFR14_Msk         (0xFUL << GPIOD_AFRH_AFR14_Pos)              /*!<GPIOD AFRH: AFR14 Mask */

#define GPIOD_AFRH_AFR15_Pos         28                                           /*!<GPIOD AFRH: AFR15 Position */
#define GPIOD_AFRH_AFR15_Msk         (0xFUL << GPIOD_AFRH_AFR15_Pos)              /*!<GPIOD AFRH: AFR15 Mask */

#define GPIOD_AFRH_Msk_ALL           (GPIOD_AFRH_AFR8_Msk          |\
                                      GPIOD_AFRH_AFR9_Msk          |\
                                      GPIOD_AFRH_AFR10_Msk         |\
                                      GPIOD_AFRH_AFR11_Msk         |\
                                      GPIOD_AFRH_AFR12_Msk         |\
                                      GPIOD_AFRH_AFR13_Msk         |\
                                      GPIOD_AFRH_AFR14_Msk         |\
                                      GPIOD_AFRH_AFR15_Msk         )

#define SYSCFG_PWRCR_VBOD_Pos        0                                            /*!<SYSCFG PWRCR: VBOD Position */
#define SYSCFG_PWRCR_VBOD_Msk        (0xFUL /*<< SYSCFG_PWRCR_VBOD_Pos*/)         /*!<SYSCFG PWRCR: VBOD Mask */

#define SYSCFG_PWRCR_BODMD_Pos       5                                            /*!<SYSCFG PWRCR: BODMD Position */
#define SYSCFG_PWRCR_BODMD_Msk       (0x3UL << SYSCFG_PWRCR_BODMD_Pos)            /*!<SYSCFG PWRCR: BODMD Mask */

#define SYSCFG_PWRCR_BODIE_Pos       7                                            /*!<SYSCFG PWRCR: BODIE Position */
#define SYSCFG_PWRCR_BODIE_Msk       (0x1UL << SYSCFG_PWRCR_BODIE_Pos)            /*!<SYSCFG PWRCR: BODIE Mask */

#define SYSCFG_PWRCR_BODEN_Pos       8                                            /*!<SYSCFG PWRCR: BODEN Position */
#define SYSCFG_PWRCR_BODEN_Msk       (0x1UL << SYSCFG_PWRCR_BODEN_Pos)            /*!<SYSCFG PWRCR: BODEN Mask */

#define SYSCFG_PWRCR_VLVR_Pos        9                                            /*!<SYSCFG PWRCR: VLVR Position */
#define SYSCFG_PWRCR_VLVR_Msk        (0x3UL << SYSCFG_PWRCR_VLVR_Pos)             /*!<SYSCFG PWRCR: VLVR Mask */

#define SYSCFG_PWRCR_LVREN_Pos       11                                           /*!<SYSCFG PWRCR: LVREN Position */
#define SYSCFG_PWRCR_LVREN_Msk       (0x1UL << SYSCFG_PWRCR_LVREN_Pos)            /*!<SYSCFG PWRCR: LVREN Mask */

#define SYSCFG_PWRCR_Msk_ALL         (SYSCFG_PWRCR_VBOD_Msk        |\
                                      SYSCFG_PWRCR_BODMD_Msk       |\
                                      SYSCFG_PWRCR_BODIE_Msk       |\
                                      SYSCFG_PWRCR_BODEN_Msk       |\
                                      SYSCFG_PWRCR_VLVR_Msk        |\
                                      SYSCFG_PWRCR_LVREN_Msk       )

#define SYSCFG_PWRSR_BODIF_Pos       0                                            /*!<SYSCFG PWRSR: BODIF Position */
#define SYSCFG_PWRSR_BODIF_Msk       (0x1UL /*<< SYSCFG_PWRSR_BODIF_Pos*/)        /*!<SYSCFG PWRSR: BODIF Mask */

#define SYSCFG_PWRSR_BODF_Pos        1                                            /*!<SYSCFG PWRSR: BODF Position */
#define SYSCFG_PWRSR_BODF_Msk        (0x1UL << SYSCFG_PWRSR_BODF_Pos)             /*!<SYSCFG PWRSR: BODF Mask */

#define SYSCFG_PWRSR_Msk_ALL         (SYSCFG_PWRSR_BODIF_Msk       |\
                                      SYSCFG_PWRSR_BODF_Msk        )

#define SYSCFG_SAFR_OSCCFG_Pos       0                                            /*!<SYSCFG SAFR: OSCCFG Position */
#define SYSCFG_SAFR_OSCCFG_Msk       (0x3UL /*<< SYSCFG_SAFR_OSCCFG_Pos*/)        /*!<SYSCFG SAFR: OSCCFG Mask */

#define SYSCFG_SAFR_SWJCFG_Pos       5                                            /*!<SYSCFG SAFR: SWJCFG Position */
#define SYSCFG_SAFR_SWJCFG_Msk       (0x1UL << SYSCFG_SAFR_SWJCFG_Pos)            /*!<SYSCFG SAFR: SWJCFG Mask */

#define SYSCFG_SAFR_IEN_EXTI0_Pos    6                                            /*!<SYSCFG SAFR: IEN_EXTI0 Position */
#define SYSCFG_SAFR_IEN_EXTI0_Msk    (0x1UL << SYSCFG_SAFR_IEN_EXTI0_Pos)         /*!<SYSCFG SAFR: IEN_EXTI0 Mask */

#define SYSCFG_SAFR_IEN_BOD_Pos      7                                            /*!<SYSCFG SAFR: IEN_BOD Position */
#define SYSCFG_SAFR_IEN_BOD_Msk      (0x1UL << SYSCFG_SAFR_IEN_BOD_Pos)           /*!<SYSCFG SAFR: IEN_BOD Mask */

#define SYSCFG_SAFR_IEN_CSM_Pos      8                                            /*!<SYSCFG SAFR: IEN_CSM Position */
#define SYSCFG_SAFR_IEN_CSM_Msk      (0x1UL << SYSCFG_SAFR_IEN_CSM_Pos)           /*!<SYSCFG SAFR: IEN_CSM Mask */

#define SYSCFG_SAFR_LOCK_Pos         16                                           /*!<SYSCFG SAFR: LOCK Position */
#define SYSCFG_SAFR_LOCK_Msk         (0xFFFFUL << SYSCFG_SAFR_LOCK_Pos)           /*!<SYSCFG SAFR: LOCK Mask */

#define SYSCFG_SAFR_Msk_ALL          (SYSCFG_SAFR_OSCCFG_Msk       |\
                                      SYSCFG_SAFR_SWJCFG_Msk       |\
                                      SYSCFG_SAFR_IEN_EXTI0_Msk    |\
                                      SYSCFG_SAFR_IEN_BOD_Msk      |\
                                      SYSCFG_SAFR_IEN_CSM_Msk      |\
                                      SYSCFG_SAFR_LOCK_Msk         )

#define SYSCFG_SRAMLOCK_SRAMLCK_Pos  0                                            /*!<SYSCFG SRAMLOCK: SRAMLCK Position */
#define SYSCFG_SRAMLOCK_SRAMLCK_Msk  (0xFFFFUL /*<< SYSCFG_SRAMLOCK_SRAMLCK_Pos*/) /*!<SYSCFG SRAMLOCK: SRAMLCK Mask */

#define SYSCFG_SRAMLOCK_LOCK_Pos     16                                           /*!<SYSCFG SRAMLOCK: LOCK Position */
#define SYSCFG_SRAMLOCK_LOCK_Msk     (0xFFFFUL << SYSCFG_SRAMLOCK_LOCK_Pos)       /*!<SYSCFG SRAMLOCK: LOCK Mask */

#define SYSCFG_SRAMLOCK_Msk_ALL      (SYSCFG_SRAMLOCK_SRAMLCK_Msk  |\
                                      SYSCFG_SRAMLOCK_LOCK_Msk     )

#define SYSCFG_DBGCR_DBG_SLEEP_Pos   0                                            /*!<SYSCFG DBGCR: DBG_SLEEP Position */
#define SYSCFG_DBGCR_DBG_SLEEP_Msk   (0x1UL /*<< SYSCFG_DBGCR_DBG_SLEEP_Pos*/)    /*!<SYSCFG DBGCR: DBG_SLEEP Mask */

#define SYSCFG_DBGCR_DBG_STOP_Pos    1                                            /*!<SYSCFG DBGCR: DBG_STOP Position */
#define SYSCFG_DBGCR_DBG_STOP_Msk    (0x1UL << SYSCFG_DBGCR_DBG_STOP_Pos)         /*!<SYSCFG DBGCR: DBG_STOP Mask */

#define SYSCFG_DBGCR_DBG_LCD_Pos     3                                            /*!<SYSCFG DBGCR: DBG_LCD Position */
#define SYSCFG_DBGCR_DBG_LCD_Msk     (0x1UL << SYSCFG_DBGCR_DBG_LCD_Pos)          /*!<SYSCFG DBGCR: DBG_LCD Mask */

#define SYSCFG_DBGCR_DBG_LED_Pos     4                                            /*!<SYSCFG DBGCR: DBG_LED Position */
#define SYSCFG_DBGCR_DBG_LED_Msk     (0x1UL << SYSCFG_DBGCR_DBG_LED_Pos)          /*!<SYSCFG DBGCR: DBG_LED Mask */

#define SYSCFG_DBGCR_DBG_DMA_Pos     5                                            /*!<SYSCFG DBGCR: DBG_DMA Position */
#define SYSCFG_DBGCR_DBG_DMA_Msk     (0x1UL << SYSCFG_DBGCR_DBG_DMA_Pos)          /*!<SYSCFG DBGCR: DBG_DMA Mask */

#define SYSCFG_DBGCR_DBG_IWDT_Pos    6                                            /*!<SYSCFG DBGCR: DBG_IWDT Position */
#define SYSCFG_DBGCR_DBG_IWDT_Msk    (0x1UL << SYSCFG_DBGCR_DBG_IWDT_Pos)         /*!<SYSCFG DBGCR: DBG_IWDT Mask */

#define SYSCFG_DBGCR_DBG_WWDT_Pos    7                                            /*!<SYSCFG DBGCR: DBG_WWDT Position */
#define SYSCFG_DBGCR_DBG_WWDT_Msk    (0x1UL << SYSCFG_DBGCR_DBG_WWDT_Pos)         /*!<SYSCFG DBGCR: DBG_WWDT Mask */

#define SYSCFG_DBGCR_DBG_PCA_Pos     8                                            /*!<SYSCFG DBGCR: DBG_PCA Position */
#define SYSCFG_DBGCR_DBG_PCA_Msk     (0x1UL << SYSCFG_DBGCR_DBG_PCA_Pos)          /*!<SYSCFG DBGCR: DBG_PCA Mask */

#define SYSCFG_DBGCR_DBG_TIM_Pos     9                                            /*!<SYSCFG DBGCR: DBG_TIM Position */
#define SYSCFG_DBGCR_DBG_TIM_Msk     (0x1UL << SYSCFG_DBGCR_DBG_TIM_Pos)          /*!<SYSCFG DBGCR: DBG_TIM Mask */

#define SYSCFG_DBGCR_DBG_PWM_Pos     10                                           /*!<SYSCFG DBGCR: DBG_PWM Position */
#define SYSCFG_DBGCR_DBG_PWM_Msk     (0x1UL << SYSCFG_DBGCR_DBG_PWM_Pos)          /*!<SYSCFG DBGCR: DBG_PWM Mask */

#define SYSCFG_DBGCR_DBG_UART_Pos    11                                           /*!<SYSCFG DBGCR: DBG_UART Position */
#define SYSCFG_DBGCR_DBG_UART_Msk    (0x1UL << SYSCFG_DBGCR_DBG_UART_Pos)         /*!<SYSCFG DBGCR: DBG_UART Mask */

#define SYSCFG_DBGCR_DBG_SPI_Pos     12                                           /*!<SYSCFG DBGCR: DBG_SPI Position */
#define SYSCFG_DBGCR_DBG_SPI_Msk     (0x1UL << SYSCFG_DBGCR_DBG_SPI_Pos)          /*!<SYSCFG DBGCR: DBG_SPI Mask */

#define SYSCFG_DBGCR_DBG_TWI_Pos     13                                           /*!<SYSCFG DBGCR: DBG_TWI Position */
#define SYSCFG_DBGCR_DBG_TWI_Msk     (0x1UL << SYSCFG_DBGCR_DBG_TWI_Pos)          /*!<SYSCFG DBGCR: DBG_TWI Mask */

#define SYSCFG_DBGCR_LOCK_Pos        16                                           /*!<SYSCFG DBGCR: LOCK Position */
#define SYSCFG_DBGCR_LOCK_Msk        (0xFFFFUL << SYSCFG_DBGCR_LOCK_Pos)          /*!<SYSCFG DBGCR: LOCK Mask */

#define SYSCFG_DBGCR_Msk_ALL         (SYSCFG_DBGCR_DBG_SLEEP_Msk   |\
                                      SYSCFG_DBGCR_DBG_STOP_Msk    |\
                                      SYSCFG_DBGCR_DBG_LCD_Msk     |\
                                      SYSCFG_DBGCR_DBG_LED_Msk     |\
                                      SYSCFG_DBGCR_DBG_DMA_Msk     |\
                                      SYSCFG_DBGCR_DBG_IWDT_Msk    |\
                                      SYSCFG_DBGCR_DBG_WWDT_Msk    |\
                                      SYSCFG_DBGCR_DBG_PCA_Msk     |\
                                      SYSCFG_DBGCR_DBG_TIM_Msk     |\
                                      SYSCFG_DBGCR_DBG_PWM_Msk     |\
                                      SYSCFG_DBGCR_DBG_UART_Msk    |\
                                      SYSCFG_DBGCR_DBG_SPI_Msk     |\
                                      SYSCFG_DBGCR_DBG_TWI_Msk     |\
                                      SYSCFG_DBGCR_LOCK_Msk        )

#define SYSCFG_GPIOBCR_BUS_Pos       0                                            /*!<SYSCFG GPIOBCR: BUS Position */
#define SYSCFG_GPIOBCR_BUS_Msk       (0x1UL /*<< SYSCFG_GPIOBCR_BUS_Pos*/)        /*!<SYSCFG GPIOBCR: BUS Mask */

#define SYSCFG_GPIOBCR_LOCK_Pos      16                                           /*!<SYSCFG GPIOBCR: LOCK Position */
#define SYSCFG_GPIOBCR_LOCK_Msk      (0xFFFFUL << SYSCFG_GPIOBCR_LOCK_Pos)        /*!<SYSCFG GPIOBCR: LOCK Mask */

#define SYSCFG_GPIOBCR_Msk_ALL       (SYSCFG_GPIOBCR_BUS_Msk       |\
                                      SYSCFG_GPIOBCR_LOCK_Msk      )

#define SYSCFG_HLDOCR_IDC_Pos        0                                            /*!<SYSCFG HLDOCR: IDC Position */
#define SYSCFG_HLDOCR_IDC_Msk        (0x3UL /*<< SYSCFG_HLDOCR_IDC_Pos*/)         /*!<SYSCFG HLDOCR: IDC Mask */

#define SYSCFG_HLDOCR_IDCEN_Pos      2                                            /*!<SYSCFG HLDOCR: IDCEN Position */
#define SYSCFG_HLDOCR_IDCEN_Msk      (0x1UL << SYSCFG_HLDOCR_IDCEN_Pos)           /*!<SYSCFG HLDOCR: IDCEN Mask */

#define SYSCFG_HLDOCR_LOCK_Pos       16                                           /*!<SYSCFG HLDOCR: LOCK Position */
#define SYSCFG_HLDOCR_LOCK_Msk       (0xFFFFUL << SYSCFG_HLDOCR_LOCK_Pos)         /*!<SYSCFG HLDOCR: LOCK Mask */

#define SYSCFG_HLDOCR_Msk_ALL        (SYSCFG_HLDOCR_IDC_Msk        |\
                                      SYSCFG_HLDOCR_IDCEN_Msk      |\
                                      SYSCFG_HLDOCR_LOCK_Msk       )

#define EXTI_IMR_IMR_Pos             0                                            /*!<EXTI IMR: IMR Position */
#define EXTI_IMR_IMR_Msk             (0xFFFFUL /*<< EXTI_IMR_IMR_Pos*/)           /*!<EXTI IMR: IMR Mask */

#define EXTI_IMR_Msk_ALL             (EXTI_IMR_IMR_Msk            )

#define EXTI_EMR_EMR_Pos             0                                            /*!<EXTI EMR: EMR Position */
#define EXTI_EMR_EMR_Msk             (0xFFFFUL /*<< EXTI_EMR_EMR_Pos*/)           /*!<EXTI EMR: EMR Mask */

#define EXTI_EMR_Msk_ALL             (EXTI_EMR_EMR_Msk            )

#define EXTI_TMSR_TMR_Pos            0                                            /*!<EXTI TMSR: TMR Position */
#define EXTI_TMSR_TMR_Msk            (0xFFFFUL /*<< EXTI_TMSR_TMR_Pos*/)          /*!<EXTI TMSR: TMR Mask */

#define EXTI_TMSR_Msk_ALL            (EXTI_TMSR_TMR_Msk           )

#define EXTI_RTSR_RTR_Pos            0                                            /*!<EXTI RTSR: RTR Position */
#define EXTI_RTSR_RTR_Msk            (0xFFFFUL /*<< EXTI_RTSR_RTR_Pos*/)          /*!<EXTI RTSR: RTR Mask */

#define EXTI_RTSR_Msk_ALL            (EXTI_RTSR_RTR_Msk           )

#define EXTI_FTSR_FTR_Pos            0                                            /*!<EXTI FTSR: FTR Position */
#define EXTI_FTSR_FTR_Msk            (0xFFFFUL /*<< EXTI_FTSR_FTR_Pos*/)          /*!<EXTI FTSR: FTR Mask */

#define EXTI_FTSR_Msk_ALL            (EXTI_FTSR_FTR_Msk           )

#define EXTI_SWIER_SWIER_Pos         0                                            /*!<EXTI SWIER: SWIER Position */
#define EXTI_SWIER_SWIER_Msk         (0xFFFFUL /*<< EXTI_SWIER_SWIER_Pos*/)       /*!<EXTI SWIER: SWIER Mask */

#define EXTI_SWIER_Msk_ALL           (EXTI_SWIER_SWIER_Msk        )

#define EXTI_PR_PR_Pos               0                                            /*!<EXTI PR: PR Position */
#define EXTI_PR_PR_Msk               (0xFFFFUL /*<< EXTI_PR_PR_Pos*/)             /*!<EXTI PR: PR Mask */

#define EXTI_PR_PRC_Pos              16                                           /*!<EXTI PR: PRC Position */
#define EXTI_PR_PRC_Msk              (0xFFFFUL << EXTI_PR_PRC_Pos)                /*!<EXTI PR: PRC Mask */

#define EXTI_PR_Msk_ALL              (EXTI_PR_PR_Msk               |\
                                      EXTI_PR_PRC_Msk              )

#define EXTI_CFGL_EXTI0_Pos          0                                            /*!<EXTI CFGL: EXTI0 Position */
#define EXTI_CFGL_EXTI0_Msk          (0x7UL /*<< EXTI_CFGL_EXTI0_Pos*/)           /*!<EXTI CFGL: EXTI0 Mask */

#define EXTI_CFGL_EXTI1_Pos          4                                            /*!<EXTI CFGL: EXTI1 Position */
#define EXTI_CFGL_EXTI1_Msk          (0x7UL << EXTI_CFGL_EXTI1_Pos)               /*!<EXTI CFGL: EXTI1 Mask */

#define EXTI_CFGL_EXTI2_Pos          8                                            /*!<EXTI CFGL: EXTI2 Position */
#define EXTI_CFGL_EXTI2_Msk          (0x7UL << EXTI_CFGL_EXTI2_Pos)               /*!<EXTI CFGL: EXTI2 Mask */

#define EXTI_CFGL_EXTI3_Pos          12                                           /*!<EXTI CFGL: EXTI3 Position */
#define EXTI_CFGL_EXTI3_Msk          (0x7UL << EXTI_CFGL_EXTI3_Pos)               /*!<EXTI CFGL: EXTI3 Mask */

#define EXTI_CFGL_EXTI4_Pos          16                                           /*!<EXTI CFGL: EXTI4 Position */
#define EXTI_CFGL_EXTI4_Msk          (0x7UL << EXTI_CFGL_EXTI4_Pos)               /*!<EXTI CFGL: EXTI4 Mask */

#define EXTI_CFGL_EXTI5_Pos          20                                           /*!<EXTI CFGL: EXTI5 Position */
#define EXTI_CFGL_EXTI5_Msk          (0x7UL << EXTI_CFGL_EXTI5_Pos)               /*!<EXTI CFGL: EXTI5 Mask */

#define EXTI_CFGL_EXTI6_Pos          24                                           /*!<EXTI CFGL: EXTI6 Position */
#define EXTI_CFGL_EXTI6_Msk          (0x7UL << EXTI_CFGL_EXTI6_Pos)               /*!<EXTI CFGL: EXTI6 Mask */

#define EXTI_CFGL_EXTI7_Pos          28                                           /*!<EXTI CFGL: EXTI7 Position */
#define EXTI_CFGL_EXTI7_Msk          (0x7UL << EXTI_CFGL_EXTI7_Pos)               /*!<EXTI CFGL: EXTI7 Mask */

#define EXTI_CFGL_Msk_ALL            (EXTI_CFGL_EXTI0_Msk          |\
                                      EXTI_CFGL_EXTI1_Msk          |\
                                      EXTI_CFGL_EXTI2_Msk          |\
                                      EXTI_CFGL_EXTI3_Msk          |\
                                      EXTI_CFGL_EXTI4_Msk          |\
                                      EXTI_CFGL_EXTI5_Msk          |\
                                      EXTI_CFGL_EXTI6_Msk          |\
                                      EXTI_CFGL_EXTI7_Msk          )

#define EXTI_CFGH_EXTI8_Pos          0                                            /*!<EXTI CFGH: EXTI8 Position */
#define EXTI_CFGH_EXTI8_Msk          (0x7UL /*<< EXTI_CFGH_EXTI8_Pos*/)           /*!<EXTI CFGH: EXTI8 Mask */

#define EXTI_CFGH_EXTI9_Pos          4                                            /*!<EXTI CFGH: EXTI9 Position */
#define EXTI_CFGH_EXTI9_Msk          (0x7UL << EXTI_CFGH_EXTI9_Pos)               /*!<EXTI CFGH: EXTI9 Mask */

#define EXTI_CFGH_EXTI10_Pos         8                                            /*!<EXTI CFGH: EXTI10 Position */
#define EXTI_CFGH_EXTI10_Msk         (0x7UL << EXTI_CFGH_EXTI10_Pos)              /*!<EXTI CFGH: EXTI10 Mask */

#define EXTI_CFGH_EXTI11_Pos         12                                           /*!<EXTI CFGH: EXTI11 Position */
#define EXTI_CFGH_EXTI11_Msk         (0x7UL << EXTI_CFGH_EXTI11_Pos)              /*!<EXTI CFGH: EXTI11 Mask */

#define EXTI_CFGH_EXTI12_Pos         16                                           /*!<EXTI CFGH: EXTI12 Position */
#define EXTI_CFGH_EXTI12_Msk         (0x7UL << EXTI_CFGH_EXTI12_Pos)              /*!<EXTI CFGH: EXTI12 Mask */

#define EXTI_CFGH_EXTI13_Pos         20                                           /*!<EXTI CFGH: EXTI13 Position */
#define EXTI_CFGH_EXTI13_Msk         (0x7UL << EXTI_CFGH_EXTI13_Pos)              /*!<EXTI CFGH: EXTI13 Mask */

#define EXTI_CFGH_EXTI14_Pos         24                                           /*!<EXTI CFGH: EXTI14 Position */
#define EXTI_CFGH_EXTI14_Msk         (0x7UL << EXTI_CFGH_EXTI14_Pos)              /*!<EXTI CFGH: EXTI14 Mask */

#define EXTI_CFGH_EXTI15_Pos         28                                           /*!<EXTI CFGH: EXTI15 Position */
#define EXTI_CFGH_EXTI15_Msk         (0x7UL << EXTI_CFGH_EXTI15_Pos)              /*!<EXTI CFGH: EXTI15 Mask */

#define EXTI_CFGH_Msk_ALL            (EXTI_CFGH_EXTI8_Msk          |\
                                      EXTI_CFGH_EXTI9_Msk          |\
                                      EXTI_CFGH_EXTI10_Msk         |\
                                      EXTI_CFGH_EXTI11_Msk         |\
                                      EXTI_CFGH_EXTI12_Msk         |\
                                      EXTI_CFGH_EXTI13_Msk         |\
                                      EXTI_CFGH_EXTI14_Msk         |\
                                      EXTI_CFGH_EXTI15_Msk         )

#define EXTI_SAMP_SN0_Pos            0                                            /*!<EXTI SAMP: SN0 Position */
#define EXTI_SAMP_SN0_Msk            (0x3UL /*<< EXTI_SAMP_SN0_Pos*/)             /*!<EXTI SAMP: SN0 Mask */

#define EXTI_SAMP_PS0_Pos            2                                            /*!<EXTI SAMP: PS0 Position */
#define EXTI_SAMP_PS0_Msk            (0x3UL << EXTI_SAMP_PS0_Pos)                 /*!<EXTI SAMP: PS0 Mask */

#define EXTI_SAMP_SN1_Pos            4                                            /*!<EXTI SAMP: SN1 Position */
#define EXTI_SAMP_SN1_Msk            (0x3UL << EXTI_SAMP_SN1_Pos)                 /*!<EXTI SAMP: SN1 Mask */

#define EXTI_SAMP_PS1_Pos            6                                            /*!<EXTI SAMP: PS1 Position */
#define EXTI_SAMP_PS1_Msk            (0x3UL << EXTI_SAMP_PS1_Pos)                 /*!<EXTI SAMP: PS1 Mask */

#define EXTI_SAMP_SN2_Pos            8                                            /*!<EXTI SAMP: SN2 Position */
#define EXTI_SAMP_SN2_Msk            (0x3UL << EXTI_SAMP_SN2_Pos)                 /*!<EXTI SAMP: SN2 Mask */

#define EXTI_SAMP_PS2_Pos            10                                           /*!<EXTI SAMP: PS2 Position */
#define EXTI_SAMP_PS2_Msk            (0x3UL << EXTI_SAMP_PS2_Pos)                 /*!<EXTI SAMP: PS2 Mask */

#define EXTI_SAMP_SN3_Pos            12                                           /*!<EXTI SAMP: SN3 Position */
#define EXTI_SAMP_SN3_Msk            (0x3UL << EXTI_SAMP_SN3_Pos)                 /*!<EXTI SAMP: SN3 Mask */

#define EXTI_SAMP_PS3_Pos            14                                           /*!<EXTI SAMP: PS3 Position */
#define EXTI_SAMP_PS3_Msk            (0x3UL << EXTI_SAMP_PS3_Pos)                 /*!<EXTI SAMP: PS3 Mask */

#define EXTI_SAMP_SN4_Pos            16                                           /*!<EXTI SAMP: SN4 Position */
#define EXTI_SAMP_SN4_Msk            (0x3UL << EXTI_SAMP_SN4_Pos)                 /*!<EXTI SAMP: SN4 Mask */

#define EXTI_SAMP_PS4_Pos            18                                           /*!<EXTI SAMP: PS4 Position */
#define EXTI_SAMP_PS4_Msk            (0x3UL << EXTI_SAMP_PS4_Pos)                 /*!<EXTI SAMP: PS4 Mask */

#define EXTI_SAMP_Msk_ALL            (EXTI_SAMP_SN0_Msk            |\
                                      EXTI_SAMP_PS0_Msk            |\
                                      EXTI_SAMP_SN1_Msk            |\
                                      EXTI_SAMP_PS1_Msk            |\
                                      EXTI_SAMP_SN2_Msk            |\
                                      EXTI_SAMP_PS2_Msk            |\
                                      EXTI_SAMP_SN3_Msk            |\
                                      EXTI_SAMP_PS3_Msk            |\
                                      EXTI_SAMP_SN4_Msk            |\
                                      EXTI_SAMP_PS4_Msk            )

#define EXTI_DMR_DMR_Pos             0                                            /*!<EXTI DMR: DMR Position */
#define EXTI_DMR_DMR_Msk             (0xFFFFUL /*<< EXTI_DMR_DMR_Pos*/)           /*!<EXTI DMR: DMR Mask */

#define EXTI_DMR_Msk_ALL             (EXTI_DMR_DMR_Msk            )

#define DMA_IFSR_BEIF_Pos            0                                            /*!<DMA IFSR: BEIF Position */
#define DMA_IFSR_BEIF_Msk            (0xFUL /*<< DMA_IFSR_BEIF_Pos*/)             /*!<DMA IFSR: BEIF Mask */

#define DMA_IFSR_TCIF_Pos            8                                            /*!<DMA IFSR: TCIF Position */
#define DMA_IFSR_TCIF_Msk            (0xFUL << DMA_IFSR_TCIF_Pos)                 /*!<DMA IFSR: TCIF Mask */

#define DMA_IFSR_HTIF_Pos            16                                           /*!<DMA IFSR: HTIF Position */
#define DMA_IFSR_HTIF_Msk            (0xFUL << DMA_IFSR_HTIF_Pos)                 /*!<DMA IFSR: HTIF Mask */

#define DMA_IFSR_TEIF_Pos            24                                           /*!<DMA IFSR: TEIF Position */
#define DMA_IFSR_TEIF_Msk            (0xFUL << DMA_IFSR_TEIF_Pos)                 /*!<DMA IFSR: TEIF Mask */

#define DMA_IFSR_Msk_ALL             (DMA_IFSR_BEIF_Msk            |\
                                      DMA_IFSR_TCIF_Msk            |\
                                      DMA_IFSR_HTIF_Msk            |\
                                      DMA_IFSR_TEIF_Msk            )

#define DMA_IFCR_CBEIF_Pos           0                                            /*!<DMA IFCR: CBEIF Position */
#define DMA_IFCR_CBEIF_Msk           (0xFUL /*<< DMA_IFCR_CBEIF_Pos*/)            /*!<DMA IFCR: CBEIF Mask */

#define DMA_IFCR_CTCIF_Pos           8                                            /*!<DMA IFCR: CTCIF Position */
#define DMA_IFCR_CTCIF_Msk           (0xFUL << DMA_IFCR_CTCIF_Pos)                /*!<DMA IFCR: CTCIF Mask */

#define DMA_IFCR_CHTIF_Pos           16                                           /*!<DMA IFCR: CHTIF Position */
#define DMA_IFCR_CHTIF_Msk           (0xFUL << DMA_IFCR_CHTIF_Pos)                /*!<DMA IFCR: CHTIF Mask */

#define DMA_IFCR_CTEIF_Pos           24                                           /*!<DMA IFCR: CTEIF Position */
#define DMA_IFCR_CTEIF_Msk           (0xFUL << DMA_IFCR_CTEIF_Pos)                /*!<DMA IFCR: CTEIF Mask */

#define DMA_IFCR_Msk_ALL             (DMA_IFCR_CBEIF_Msk           |\
                                      DMA_IFCR_CTCIF_Msk           |\
                                      DMA_IFCR_CHTIF_Msk           |\
                                      DMA_IFCR_CTEIF_Msk           )

#define DMA_CSR_SWTRG_Pos            0                                            /*!<DMA CSR: SWTRG Position */
#define DMA_CSR_SWTRG_Msk            (0xFUL /*<< DMA_CSR_SWTRG_Pos*/)             /*!<DMA CSR: SWTRG Mask */

#define DMA_CSR_DBUSY_Pos            8                                            /*!<DMA CSR: DBUSY Position */
#define DMA_CSR_DBUSY_Msk            (0xFUL << DMA_CSR_DBUSY_Pos)                 /*!<DMA CSR: DBUSY Mask */

#define DMA_CSR_BURSTIDLE_Pos        16                                           /*!<DMA CSR: BURSTIDLE Position */
#define DMA_CSR_BURSTIDLE_Msk        (0xFUL << DMA_CSR_BURSTIDLE_Pos)             /*!<DMA CSR: BURSTIDLE Mask */

#define DMA_CSR_RELOAD_Pos           24                                           /*!<DMA CSR: RELOAD Position */
#define DMA_CSR_RELOAD_Msk           (0xFUL << DMA_CSR_RELOAD_Pos)                /*!<DMA CSR: RELOAD Mask */

#define DMA_CSR_Msk_ALL              (DMA_CSR_SWTRG_Msk            |\
                                      DMA_CSR_DBUSY_Msk            |\
                                      DMA_CSR_BURSTIDLE_Msk        |\
                                      DMA_CSR_RELOAD_Msk           )

#define DMA_CCR0_EN_Pos              0                                            /*!<DMA CCR0: EN Position */
#define DMA_CCR0_EN_Msk              (0x1UL /*<< DMA_CCR0_EN_Pos*/)               /*!<DMA CCR0: EN Mask */

#define DMA_CCR0_TCIE_Pos            1                                            /*!<DMA CCR0: TCIE Position */
#define DMA_CCR0_TCIE_Msk            (0x1UL << DMA_CCR0_TCIE_Pos)                 /*!<DMA CCR0: TCIE Mask */

#define DMA_CCR0_HTIE_Pos            2                                            /*!<DMA CCR0: HTIE Position */
#define DMA_CCR0_HTIE_Msk            (0x1UL << DMA_CCR0_HTIE_Pos)                 /*!<DMA CCR0: HTIE Mask */

#define DMA_CCR0_BEIE_Pos            3                                            /*!<DMA CCR0: BEIE Position */
#define DMA_CCR0_BEIE_Msk            (0x1UL << DMA_CCR0_BEIE_Pos)                 /*!<DMA CCR0: BEIE Mask */

#define DMA_CCR0_TEIE_Pos            4                                            /*!<DMA CCR0: TEIE Position */
#define DMA_CCR0_TEIE_Msk            (0x1UL << DMA_CCR0_TEIE_Pos)                 /*!<DMA CCR0: TEIE Mask */

#define DMA_CCR0_DPTYP_Pos           6                                            /*!<DMA CCR0: DPTYP Position */
#define DMA_CCR0_DPTYP_Msk           (0x3UL << DMA_CCR0_DPTYP_Pos)                /*!<DMA CCR0: DPTYP Mask */

#define DMA_CCR0_SPTYP_Pos           8                                            /*!<DMA CCR0: SPTYP Position */
#define DMA_CCR0_SPTYP_Msk           (0x3UL << DMA_CCR0_SPTYP_Pos)                /*!<DMA CCR0: SPTYP Mask */

#define DMA_CCR0_DSIZE_Pos           10                                           /*!<DMA CCR0: DSIZE Position */
#define DMA_CCR0_DSIZE_Msk           (0x3UL << DMA_CCR0_DSIZE_Pos)                /*!<DMA CCR0: DSIZE Mask */

#define DMA_CCR0_SSIZE_Pos           12                                           /*!<DMA CCR0: SSIZE Position */
#define DMA_CCR0_SSIZE_Msk           (0x3UL << DMA_CCR0_SSIZE_Pos)                /*!<DMA CCR0: SSIZE Mask */

#define DMA_CCR0_PL_Pos              14                                           /*!<DMA CCR0: PL Position */
#define DMA_CCR0_PL_Msk              (0x3UL << DMA_CCR0_PL_Pos)                   /*!<DMA CCR0: PL Mask */

#define DMA_CCR0_BURSTLEN_Pos        16                                           /*!<DMA CCR0: BURSTLEN Position */
#define DMA_CCR0_BURSTLEN_Msk        (0xFUL << DMA_CCR0_BURSTLEN_Pos)             /*!<DMA CCR0: BURSTLEN Mask */

#define DMA_CCR0_STRMSEL_Pos         20                                           /*!<DMA CCR0: STRMSEL Position */
#define DMA_CCR0_STRMSEL_Msk         (0x7UL << DMA_CCR0_STRMSEL_Pos)              /*!<DMA CCR0: STRMSEL Mask */

#define DMA_CCR0_TRGMODE_Pos         23                                           /*!<DMA CCR0: TRGMODE Position */
#define DMA_CCR0_TRGMODE_Msk         (0x1UL << DMA_CCR0_TRGMODE_Pos)              /*!<DMA CCR0: TRGMODE Mask */

#define DMA_CCR0_Msk_ALL             (DMA_CCR0_EN_Msk              |\
                                      DMA_CCR0_TCIE_Msk            |\
                                      DMA_CCR0_HTIE_Msk            |\
                                      DMA_CCR0_BEIE_Msk            |\
                                      DMA_CCR0_TEIE_Msk            |\
                                      DMA_CCR0_DPTYP_Msk           |\
                                      DMA_CCR0_SPTYP_Msk           |\
                                      DMA_CCR0_DSIZE_Msk           |\
                                      DMA_CCR0_SSIZE_Msk           |\
                                      DMA_CCR0_PL_Msk              |\
                                      DMA_CCR0_BURSTLEN_Msk        |\
                                      DMA_CCR0_STRMSEL_Msk         |\
                                      DMA_CCR0_TRGMODE_Msk         )

#define DMA_NPKT0_NPKT_Pos           0                                            /*!<DMA NPKT0: NPKT Position */
#define DMA_NPKT0_NPKT_Msk           (0x1FFFUL /*<< DMA_NPKT0_NPKT_Pos*/)         /*!<DMA NPKT0: NPKT Mask */

#define DMA_NPKT0_Msk_ALL            (DMA_NPKT0_NPKT_Msk          )

#define DMA_CPKT0_CPKT_Pos           0                                            /*!<DMA CPKT0: CPKT Position */
#define DMA_CPKT0_CPKT_Msk           (0x1FFFUL /*<< DMA_CPKT0_CPKT_Pos*/)         /*!<DMA CPKT0: CPKT Mask */

#define DMA_CPKT0_Msk_ALL            (DMA_CPKT0_CPKT_Msk          )

#define DMA_CCR1_EN_Pos              0                                            /*!<DMA CCR1: EN Position */
#define DMA_CCR1_EN_Msk              (0x1UL /*<< DMA_CCR1_EN_Pos*/)               /*!<DMA CCR1: EN Mask */

#define DMA_CCR1_TCIE_Pos            1                                            /*!<DMA CCR1: TCIE Position */
#define DMA_CCR1_TCIE_Msk            (0x1UL << DMA_CCR1_TCIE_Pos)                 /*!<DMA CCR1: TCIE Mask */

#define DMA_CCR1_HTIE_Pos            2                                            /*!<DMA CCR1: HTIE Position */
#define DMA_CCR1_HTIE_Msk            (0x1UL << DMA_CCR1_HTIE_Pos)                 /*!<DMA CCR1: HTIE Mask */

#define DMA_CCR1_BEIE_Pos            3                                            /*!<DMA CCR1: BEIE Position */
#define DMA_CCR1_BEIE_Msk            (0x1UL << DMA_CCR1_BEIE_Pos)                 /*!<DMA CCR1: BEIE Mask */

#define DMA_CCR1_TEIE_Pos            4                                            /*!<DMA CCR1: TEIE Position */
#define DMA_CCR1_TEIE_Msk            (0x1UL << DMA_CCR1_TEIE_Pos)                 /*!<DMA CCR1: TEIE Mask */

#define DMA_CCR1_DPTYP_Pos           6                                            /*!<DMA CCR1: DPTYP Position */
#define DMA_CCR1_DPTYP_Msk           (0x3UL << DMA_CCR1_DPTYP_Pos)                /*!<DMA CCR1: DPTYP Mask */

#define DMA_CCR1_SPTYP_Pos           8                                            /*!<DMA CCR1: SPTYP Position */
#define DMA_CCR1_SPTYP_Msk           (0x3UL << DMA_CCR1_SPTYP_Pos)                /*!<DMA CCR1: SPTYP Mask */

#define DMA_CCR1_DSIZE_Pos           10                                           /*!<DMA CCR1: DSIZE Position */
#define DMA_CCR1_DSIZE_Msk           (0x3UL << DMA_CCR1_DSIZE_Pos)                /*!<DMA CCR1: DSIZE Mask */

#define DMA_CCR1_SSIZE_Pos           12                                           /*!<DMA CCR1: SSIZE Position */
#define DMA_CCR1_SSIZE_Msk           (0x3UL << DMA_CCR1_SSIZE_Pos)                /*!<DMA CCR1: SSIZE Mask */

#define DMA_CCR1_PL_Pos              14                                           /*!<DMA CCR1: PL Position */
#define DMA_CCR1_PL_Msk              (0x3UL << DMA_CCR1_PL_Pos)                   /*!<DMA CCR1: PL Mask */

#define DMA_CCR1_BURSTLEN_Pos        16                                           /*!<DMA CCR1: BURSTLEN Position */
#define DMA_CCR1_BURSTLEN_Msk        (0xFUL << DMA_CCR1_BURSTLEN_Pos)             /*!<DMA CCR1: BURSTLEN Mask */

#define DMA_CCR1_STRMSEL_Pos         20                                           /*!<DMA CCR1: STRMSEL Position */
#define DMA_CCR1_STRMSEL_Msk         (0x7UL << DMA_CCR1_STRMSEL_Pos)              /*!<DMA CCR1: STRMSEL Mask */

#define DMA_CCR1_TRGMODE_Pos         23                                           /*!<DMA CCR1: TRGMODE Position */
#define DMA_CCR1_TRGMODE_Msk         (0x1UL << DMA_CCR1_TRGMODE_Pos)              /*!<DMA CCR1: TRGMODE Mask */

#define DMA_CCR1_Msk_ALL             (DMA_CCR1_EN_Msk              |\
                                      DMA_CCR1_TCIE_Msk            |\
                                      DMA_CCR1_HTIE_Msk            |\
                                      DMA_CCR1_BEIE_Msk            |\
                                      DMA_CCR1_TEIE_Msk            |\
                                      DMA_CCR1_DPTYP_Msk           |\
                                      DMA_CCR1_SPTYP_Msk           |\
                                      DMA_CCR1_DSIZE_Msk           |\
                                      DMA_CCR1_SSIZE_Msk           |\
                                      DMA_CCR1_PL_Msk              |\
                                      DMA_CCR1_BURSTLEN_Msk        |\
                                      DMA_CCR1_STRMSEL_Msk         |\
                                      DMA_CCR1_TRGMODE_Msk         )

#define DMA_NPKT1_NPKT_Pos           0                                            /*!<DMA NPKT1: NPKT Position */
#define DMA_NPKT1_NPKT_Msk           (0x1FFFUL /*<< DMA_NPKT1_NPKT_Pos*/)         /*!<DMA NPKT1: NPKT Mask */

#define DMA_NPKT1_Msk_ALL            (DMA_NPKT1_NPKT_Msk          )

#define DMA_CPKT1_CPKT_Pos           0                                            /*!<DMA CPKT1: CPKT Position */
#define DMA_CPKT1_CPKT_Msk           (0x1FFFUL /*<< DMA_CPKT1_CPKT_Pos*/)         /*!<DMA CPKT1: CPKT Mask */

#define DMA_CPKT1_Msk_ALL            (DMA_CPKT1_CPKT_Msk          )

#define DMA_CCR2_EN_Pos              0                                            /*!<DMA CCR2: EN Position */
#define DMA_CCR2_EN_Msk              (0x1UL /*<< DMA_CCR2_EN_Pos*/)               /*!<DMA CCR2: EN Mask */

#define DMA_CCR2_TCIE_Pos            1                                            /*!<DMA CCR2: TCIE Position */
#define DMA_CCR2_TCIE_Msk            (0x1UL << DMA_CCR2_TCIE_Pos)                 /*!<DMA CCR2: TCIE Mask */

#define DMA_CCR2_HTIE_Pos            2                                            /*!<DMA CCR2: HTIE Position */
#define DMA_CCR2_HTIE_Msk            (0x1UL << DMA_CCR2_HTIE_Pos)                 /*!<DMA CCR2: HTIE Mask */

#define DMA_CCR2_BEIE_Pos            3                                            /*!<DMA CCR2: BEIE Position */
#define DMA_CCR2_BEIE_Msk            (0x1UL << DMA_CCR2_BEIE_Pos)                 /*!<DMA CCR2: BEIE Mask */

#define DMA_CCR2_TEIE_Pos            4                                            /*!<DMA CCR2: TEIE Position */
#define DMA_CCR2_TEIE_Msk            (0x1UL << DMA_CCR2_TEIE_Pos)                 /*!<DMA CCR2: TEIE Mask */

#define DMA_CCR2_DPTYP_Pos           6                                            /*!<DMA CCR2: DPTYP Position */
#define DMA_CCR2_DPTYP_Msk           (0x3UL << DMA_CCR2_DPTYP_Pos)                /*!<DMA CCR2: DPTYP Mask */

#define DMA_CCR2_SPTYP_Pos           8                                            /*!<DMA CCR2: SPTYP Position */
#define DMA_CCR2_SPTYP_Msk           (0x3UL << DMA_CCR2_SPTYP_Pos)                /*!<DMA CCR2: SPTYP Mask */

#define DMA_CCR2_DSIZE_Pos           10                                           /*!<DMA CCR2: DSIZE Position */
#define DMA_CCR2_DSIZE_Msk           (0x3UL << DMA_CCR2_DSIZE_Pos)                /*!<DMA CCR2: DSIZE Mask */

#define DMA_CCR2_SSIZE_Pos           12                                           /*!<DMA CCR2: SSIZE Position */
#define DMA_CCR2_SSIZE_Msk           (0x3UL << DMA_CCR2_SSIZE_Pos)                /*!<DMA CCR2: SSIZE Mask */

#define DMA_CCR2_PL_Pos              14                                           /*!<DMA CCR2: PL Position */
#define DMA_CCR2_PL_Msk              (0x3UL << DMA_CCR2_PL_Pos)                   /*!<DMA CCR2: PL Mask */

#define DMA_CCR2_BURSTLEN_Pos        16                                           /*!<DMA CCR2: BURSTLEN Position */
#define DMA_CCR2_BURSTLEN_Msk        (0xFUL << DMA_CCR2_BURSTLEN_Pos)             /*!<DMA CCR2: BURSTLEN Mask */

#define DMA_CCR2_STRMSEL_Pos         20                                           /*!<DMA CCR2: STRMSEL Position */
#define DMA_CCR2_STRMSEL_Msk         (0x7UL << DMA_CCR2_STRMSEL_Pos)              /*!<DMA CCR2: STRMSEL Mask */

#define DMA_CCR2_TRGMODE_Pos         23                                           /*!<DMA CCR2: TRGMODE Position */
#define DMA_CCR2_TRGMODE_Msk         (0x1UL << DMA_CCR2_TRGMODE_Pos)              /*!<DMA CCR2: TRGMODE Mask */

#define DMA_CCR2_Msk_ALL             (DMA_CCR2_EN_Msk              |\
                                      DMA_CCR2_TCIE_Msk            |\
                                      DMA_CCR2_HTIE_Msk            |\
                                      DMA_CCR2_BEIE_Msk            |\
                                      DMA_CCR2_TEIE_Msk            |\
                                      DMA_CCR2_DPTYP_Msk           |\
                                      DMA_CCR2_SPTYP_Msk           |\
                                      DMA_CCR2_DSIZE_Msk           |\
                                      DMA_CCR2_SSIZE_Msk           |\
                                      DMA_CCR2_PL_Msk              |\
                                      DMA_CCR2_BURSTLEN_Msk        |\
                                      DMA_CCR2_STRMSEL_Msk         |\
                                      DMA_CCR2_TRGMODE_Msk         )

#define DMA_NPKT2_NPKT_Pos           0                                            /*!<DMA NPKT2: NPKT Position */
#define DMA_NPKT2_NPKT_Msk           (0x1FFFUL /*<< DMA_NPKT2_NPKT_Pos*/)         /*!<DMA NPKT2: NPKT Mask */

#define DMA_NPKT2_Msk_ALL            (DMA_NPKT2_NPKT_Msk          )

#define DMA_CPKT2_CPKT_Pos           0                                            /*!<DMA CPKT2: CPKT Position */
#define DMA_CPKT2_CPKT_Msk           (0x1FFFUL /*<< DMA_CPKT2_CPKT_Pos*/)         /*!<DMA CPKT2: CPKT Mask */

#define DMA_CPKT2_Msk_ALL            (DMA_CPKT2_CPKT_Msk          )

#define DMA_CCR3_EN_Pos              0                                            /*!<DMA CCR3: EN Position */
#define DMA_CCR3_EN_Msk              (0x1UL /*<< DMA_CCR3_EN_Pos*/)               /*!<DMA CCR3: EN Mask */

#define DMA_CCR3_TCIE_Pos            1                                            /*!<DMA CCR3: TCIE Position */
#define DMA_CCR3_TCIE_Msk            (0x1UL << DMA_CCR3_TCIE_Pos)                 /*!<DMA CCR3: TCIE Mask */

#define DMA_CCR3_HTIE_Pos            2                                            /*!<DMA CCR3: HTIE Position */
#define DMA_CCR3_HTIE_Msk            (0x1UL << DMA_CCR3_HTIE_Pos)                 /*!<DMA CCR3: HTIE Mask */

#define DMA_CCR3_BEIE_Pos            3                                            /*!<DMA CCR3: BEIE Position */
#define DMA_CCR3_BEIE_Msk            (0x1UL << DMA_CCR3_BEIE_Pos)                 /*!<DMA CCR3: BEIE Mask */

#define DMA_CCR3_TEIE_Pos            4                                            /*!<DMA CCR3: TEIE Position */
#define DMA_CCR3_TEIE_Msk            (0x1UL << DMA_CCR3_TEIE_Pos)                 /*!<DMA CCR3: TEIE Mask */

#define DMA_CCR3_DPTYP_Pos           6                                            /*!<DMA CCR3: DPTYP Position */
#define DMA_CCR3_DPTYP_Msk           (0x3UL << DMA_CCR3_DPTYP_Pos)                /*!<DMA CCR3: DPTYP Mask */

#define DMA_CCR3_SPTYP_Pos           8                                            /*!<DMA CCR3: SPTYP Position */
#define DMA_CCR3_SPTYP_Msk           (0x3UL << DMA_CCR3_SPTYP_Pos)                /*!<DMA CCR3: SPTYP Mask */

#define DMA_CCR3_DSIZE_Pos           10                                           /*!<DMA CCR3: DSIZE Position */
#define DMA_CCR3_DSIZE_Msk           (0x3UL << DMA_CCR3_DSIZE_Pos)                /*!<DMA CCR3: DSIZE Mask */

#define DMA_CCR3_SSIZE_Pos           12                                           /*!<DMA CCR3: SSIZE Position */
#define DMA_CCR3_SSIZE_Msk           (0x3UL << DMA_CCR3_SSIZE_Pos)                /*!<DMA CCR3: SSIZE Mask */

#define DMA_CCR3_PL_Pos              14                                           /*!<DMA CCR3: PL Position */
#define DMA_CCR3_PL_Msk              (0x3UL << DMA_CCR3_PL_Pos)                   /*!<DMA CCR3: PL Mask */

#define DMA_CCR3_BURSTLEN_Pos        16                                           /*!<DMA CCR3: BURSTLEN Position */
#define DMA_CCR3_BURSTLEN_Msk        (0xFUL << DMA_CCR3_BURSTLEN_Pos)             /*!<DMA CCR3: BURSTLEN Mask */

#define DMA_CCR3_STRMSEL_Pos         20                                           /*!<DMA CCR3: STRMSEL Position */
#define DMA_CCR3_STRMSEL_Msk         (0x7UL << DMA_CCR3_STRMSEL_Pos)              /*!<DMA CCR3: STRMSEL Mask */

#define DMA_CCR3_TRGMODE_Pos         23                                           /*!<DMA CCR3: TRGMODE Position */
#define DMA_CCR3_TRGMODE_Msk         (0x1UL << DMA_CCR3_TRGMODE_Pos)              /*!<DMA CCR3: TRGMODE Mask */

#define DMA_CCR3_Msk_ALL             (DMA_CCR3_EN_Msk              |\
                                      DMA_CCR3_TCIE_Msk            |\
                                      DMA_CCR3_HTIE_Msk            |\
                                      DMA_CCR3_BEIE_Msk            |\
                                      DMA_CCR3_TEIE_Msk            |\
                                      DMA_CCR3_DPTYP_Msk           |\
                                      DMA_CCR3_SPTYP_Msk           |\
                                      DMA_CCR3_DSIZE_Msk           |\
                                      DMA_CCR3_SSIZE_Msk           |\
                                      DMA_CCR3_PL_Msk              |\
                                      DMA_CCR3_BURSTLEN_Msk        |\
                                      DMA_CCR3_STRMSEL_Msk         |\
                                      DMA_CCR3_TRGMODE_Msk         )

#define DMA_NPKT3_NPKT_Pos           0                                            /*!<DMA NPKT3: NPKT Position */
#define DMA_NPKT3_NPKT_Msk           (0x1FFFUL /*<< DMA_NPKT3_NPKT_Pos*/)         /*!<DMA NPKT3: NPKT Mask */

#define DMA_NPKT3_Msk_ALL            (DMA_NPKT3_NPKT_Msk          )

#define DMA_CPKT3_CPKT_Pos           0                                            /*!<DMA CPKT3: CPKT Position */
#define DMA_CPKT3_CPKT_Msk           (0x1FFFUL /*<< DMA_CPKT3_CPKT_Pos*/)         /*!<DMA CPKT3: CPKT Mask */

#define DMA_CPKT3_Msk_ALL            (DMA_CPKT3_CPKT_Msk          )

#define LED_COMCR_COMSEL_Pos         0                                            /*!<LED COMCR: COMSEL Position */
#define LED_COMCR_COMSEL_Msk         (0x7UL /*<< LED_COMCR_COMSEL_Pos*/)          /*!<LED COMCR: COMSEL Mask */

#define LED_COMCR_COMIO_Pos          3                                            /*!<LED COMCR: COMIO Position */
#define LED_COMCR_COMIO_Msk          (0x1UL << LED_COMCR_COMIO_Pos)               /*!<LED COMCR: COMIO Mask */

#define LED_COMCR_MODE_Pos           4                                            /*!<LED COMCR: MODE Position */
#define LED_COMCR_MODE_Msk           (0x1UL << LED_COMCR_MODE_Pos)                /*!<LED COMCR: MODE Mask */

#define LED_COMCR_COMIE_Pos          5                                            /*!<LED COMCR: COMIE Position */
#define LED_COMCR_COMIE_Msk          (0x1UL << LED_COMCR_COMIE_Pos)               /*!<LED COMCR: COMIE Mask */

#define LED_COMCR_COMGO_Pos          7                                            /*!<LED COMCR: COMGO Position */
#define LED_COMCR_COMGO_Msk          (0x1UL << LED_COMCR_COMGO_Pos)               /*!<LED COMCR: COMGO Mask */

#define LED_COMCR_DISCOM_Pos         8                                            /*!<LED COMCR: DISCOM Position */
#define LED_COMCR_DISCOM_Msk         (0xFFUL << LED_COMCR_DISCOM_Pos)             /*!<LED COMCR: DISCOM Mask */

#define LED_COMCR_LEDCDMA_Pos        16                                           /*!<LED COMCR: LEDCDMA Position */
#define LED_COMCR_LEDCDMA_Msk        (0x1UL << LED_COMCR_LEDCDMA_Pos)             /*!<LED COMCR: LEDCDMA Mask */

#define LED_COMCR_Msk_ALL            (LED_COMCR_COMSEL_Msk         |\
                                      LED_COMCR_COMIO_Msk          |\
                                      LED_COMCR_MODE_Msk           |\
                                      LED_COMCR_COMIE_Msk          |\
                                      LED_COMCR_COMGO_Msk          |\
                                      LED_COMCR_DISCOM_Msk         |\
                                      LED_COMCR_LEDCDMA_Msk        )

#define LED_FR_COMIF_Pos             0                                            /*!<LED FR: COMIF Position */
#define LED_FR_COMIF_Msk             (0x1UL /*<< LED_FR_COMIF_Pos*/)              /*!<LED FR: COMIF Mask */

#define LED_FR_AUIF_Pos              1                                            /*!<LED FR: AUIF Position */
#define LED_FR_AUIF_Msk              (0x1UL << LED_FR_AUIF_Pos)                   /*!<LED FR: AUIF Mask */

#define LED_FR_COMIFC_Pos            16                                           /*!<LED FR: COMIFC Position */
#define LED_FR_COMIFC_Msk            (0x1UL << LED_FR_COMIFC_Pos)                 /*!<LED FR: COMIFC Mask */

#define LED_FR_AUIFC_Pos             17                                           /*!<LED FR: AUIFC Position */
#define LED_FR_AUIFC_Msk             (0x1UL << LED_FR_AUIFC_Pos)                  /*!<LED FR: AUIFC Mask */

#define LED_FR_Msk_ALL               (LED_FR_COMIF_Msk             |\
                                      LED_FR_AUIF_Msk              |\
                                      LED_FR_COMIFC_Msk            |\
                                      LED_FR_AUIFC_Msk             )

#define LED_CCCR_CCSS0_Pos           0                                            /*!<LED CCCR: CCSS0 Position */
#define LED_CCCR_CCSS0_Msk           (0x1UL /*<< LED_CCCR_CCSS0_Pos*/)            /*!<LED CCCR: CCSS0 Mask */

#define LED_CCCR_CCSS1_Pos           1                                            /*!<LED CCCR: CCSS1 Position */
#define LED_CCCR_CCSS1_Msk           (0x1UL << LED_CCCR_CCSS1_Pos)                /*!<LED CCCR: CCSS1 Mask */

#define LED_CCCR_CCSS2_Pos           2                                            /*!<LED CCCR: CCSS2 Position */
#define LED_CCCR_CCSS2_Msk           (0x1UL << LED_CCCR_CCSS2_Pos)                /*!<LED CCCR: CCSS2 Mask */

#define LED_CCCR_CCSS3_Pos           3                                            /*!<LED CCCR: CCSS3 Position */
#define LED_CCCR_CCSS3_Msk           (0x1UL << LED_CCCR_CCSS3_Pos)                /*!<LED CCCR: CCSS3 Mask */

#define LED_CCCR_CCSS4_Pos           4                                            /*!<LED CCCR: CCSS4 Position */
#define LED_CCCR_CCSS4_Msk           (0x1UL << LED_CCCR_CCSS4_Pos)                /*!<LED CCCR: CCSS4 Mask */

#define LED_CCCR_CCSS5_Pos           5                                            /*!<LED CCCR: CCSS5 Position */
#define LED_CCCR_CCSS5_Msk           (0x1UL << LED_CCCR_CCSS5_Pos)                /*!<LED CCCR: CCSS5 Mask */

#define LED_CCCR_CCSS6_Pos           6                                            /*!<LED CCCR: CCSS6 Position */
#define LED_CCCR_CCSS6_Msk           (0x1UL << LED_CCCR_CCSS6_Pos)                /*!<LED CCCR: CCSS6 Mask */

#define LED_CCCR_CCSS7_Pos           7                                            /*!<LED CCCR: CCSS7 Position */
#define LED_CCCR_CCSS7_Msk           (0x1UL << LED_CCCR_CCSS7_Pos)                /*!<LED CCCR: CCSS7 Mask */

#define LED_CCCR_Msk_ALL             (LED_CCCR_CCSS0_Msk           |\
                                      LED_CCCR_CCSS1_Msk           |\
                                      LED_CCCR_CCSS2_Msk           |\
                                      LED_CCCR_CCSS3_Msk           |\
                                      LED_CCCR_CCSS4_Msk           |\
                                      LED_CCCR_CCSS5_Msk           |\
                                      LED_CCCR_CCSS6_Msk           |\
                                      LED_CCCR_CCSS7_Msk           )

#define LED_CCDR_CCS0DS_Pos          0                                            /*!<LED CCDR: CCS0DS Position */
#define LED_CCDR_CCS0DS_Msk          (0xFUL /*<< LED_CCDR_CCS0DS_Pos*/)           /*!<LED CCDR: CCS0DS Mask */

#define LED_CCDR_CCS1DS_Pos          4                                            /*!<LED CCDR: CCS1DS Position */
#define LED_CCDR_CCS1DS_Msk          (0xFUL << LED_CCDR_CCS1DS_Pos)               /*!<LED CCDR: CCS1DS Mask */

#define LED_CCDR_CCS2DS_Pos          8                                            /*!<LED CCDR: CCS2DS Position */
#define LED_CCDR_CCS2DS_Msk          (0xFUL << LED_CCDR_CCS2DS_Pos)               /*!<LED CCDR: CCS2DS Mask */

#define LED_CCDR_CCS3DS_Pos          12                                           /*!<LED CCDR: CCS3DS Position */
#define LED_CCDR_CCS3DS_Msk          (0xFUL << LED_CCDR_CCS3DS_Pos)               /*!<LED CCDR: CCS3DS Mask */

#define LED_CCDR_CCS4DS_Pos          16                                           /*!<LED CCDR: CCS4DS Position */
#define LED_CCDR_CCS4DS_Msk          (0xFUL << LED_CCDR_CCS4DS_Pos)               /*!<LED CCDR: CCS4DS Mask */

#define LED_CCDR_CCS5DS_Pos          20                                           /*!<LED CCDR: CCS5DS Position */
#define LED_CCDR_CCS5DS_Msk          (0xFUL << LED_CCDR_CCS5DS_Pos)               /*!<LED CCDR: CCS5DS Mask */

#define LED_CCDR_CCS6DS_Pos          24                                           /*!<LED CCDR: CCS6DS Position */
#define LED_CCDR_CCS6DS_Msk          (0xFUL << LED_CCDR_CCS6DS_Pos)               /*!<LED CCDR: CCS6DS Mask */

#define LED_CCDR_CCS7DS_Pos          28                                           /*!<LED CCDR: CCS7DS Position */
#define LED_CCDR_CCS7DS_Msk          (0xFUL << LED_CCDR_CCS7DS_Pos)               /*!<LED CCDR: CCS7DS Mask */

#define LED_CCDR_Msk_ALL             (LED_CCDR_CCS0DS_Msk          |\
                                      LED_CCDR_CCS1DS_Msk          |\
                                      LED_CCDR_CCS2DS_Msk          |\
                                      LED_CCDR_CCS3DS_Msk          |\
                                      LED_CCDR_CCS4DS_Msk          |\
                                      LED_CCDR_CCS5DS_Msk          |\
                                      LED_CCDR_CCS6DS_Msk          |\
                                      LED_CCDR_CCS7DS_Msk          )

#define LED_AUCR_DZ_Pos              0                                            /*!<LED AUCR: DZ Position */
#define LED_AUCR_DZ_Msk              (0xFFUL /*<< LED_AUCR_DZ_Pos*/)              /*!<LED AUCR: DZ Mask */

#define LED_AUCR_COM_Pos             8                                            /*!<LED AUCR: COM Position */
#define LED_AUCR_COM_Msk             (0xFFUL << LED_AUCR_COM_Pos)                 /*!<LED AUCR: COM Mask */

#define LED_AUCR_AUMD_Pos            16                                           /*!<LED AUCR: AUMD Position */
#define LED_AUCR_AUMD_Msk            (0x1UL << LED_AUCR_AUMD_Pos)                 /*!<LED AUCR: AUMD Mask */

#define LED_AUCR_AUIE_Pos            17                                           /*!<LED AUCR: AUIE Position */
#define LED_AUCR_AUIE_Msk            (0x1UL << LED_AUCR_AUIE_Pos)                 /*!<LED AUCR: AUIE Mask */

#define LED_AUCR_AUGO_Pos            18                                           /*!<LED AUCR: AUGO Position */
#define LED_AUCR_AUGO_Msk            (0x1UL << LED_AUCR_AUGO_Pos)                 /*!<LED AUCR: AUGO Mask */

#define LED_AUCR_AUEN_Pos            19                                           /*!<LED AUCR: AUEN Position */
#define LED_AUCR_AUEN_Msk            (0x1UL << LED_AUCR_AUEN_Pos)                 /*!<LED AUCR: AUEN Mask */

#define LED_AUCR_AUDMA_Pos           20                                           /*!<LED AUCR: AUDMA Position */
#define LED_AUCR_AUDMA_Msk           (0x1UL << LED_AUCR_AUDMA_Pos)                /*!<LED AUCR: AUDMA Mask */

#define LED_AUCR_Msk_ALL             (LED_AUCR_DZ_Msk              |\
                                      LED_AUCR_COM_Msk             |\
                                      LED_AUCR_AUMD_Msk            |\
                                      LED_AUCR_AUIE_Msk            |\
                                      LED_AUCR_AUGO_Msk            |\
                                      LED_AUCR_AUEN_Msk            |\
                                      LED_AUCR_AUDMA_Msk           )

#define LED_SEGMOD_S0MS_Pos          0                                            /*!<LED SEGMOD: S0MS Position */
#define LED_SEGMOD_S0MS_Msk          (0x1UL /*<< LED_SEGMOD_S0MS_Pos*/)           /*!<LED SEGMOD: S0MS Mask */

#define LED_SEGMOD_S1MS_Pos          1                                            /*!<LED SEGMOD: S1MS Position */
#define LED_SEGMOD_S1MS_Msk          (0x1UL << LED_SEGMOD_S1MS_Pos)               /*!<LED SEGMOD: S1MS Mask */

#define LED_SEGMOD_S2MS_Pos          2                                            /*!<LED SEGMOD: S2MS Position */
#define LED_SEGMOD_S2MS_Msk          (0x1UL << LED_SEGMOD_S2MS_Pos)               /*!<LED SEGMOD: S2MS Mask */

#define LED_SEGMOD_S3MS_Pos          3                                            /*!<LED SEGMOD: S3MS Position */
#define LED_SEGMOD_S3MS_Msk          (0x1UL << LED_SEGMOD_S3MS_Pos)               /*!<LED SEGMOD: S3MS Mask */

#define LED_SEGMOD_S4MS_Pos          4                                            /*!<LED SEGMOD: S4MS Position */
#define LED_SEGMOD_S4MS_Msk          (0x1UL << LED_SEGMOD_S4MS_Pos)               /*!<LED SEGMOD: S4MS Mask */

#define LED_SEGMOD_S5MS_Pos          5                                            /*!<LED SEGMOD: S5MS Position */
#define LED_SEGMOD_S5MS_Msk          (0x1UL << LED_SEGMOD_S5MS_Pos)               /*!<LED SEGMOD: S5MS Mask */

#define LED_SEGMOD_S6MS_Pos          6                                            /*!<LED SEGMOD: S6MS Position */
#define LED_SEGMOD_S6MS_Msk          (0x1UL << LED_SEGMOD_S6MS_Pos)               /*!<LED SEGMOD: S6MS Mask */

#define LED_SEGMOD_S7MS_Pos          7                                            /*!<LED SEGMOD: S7MS Position */
#define LED_SEGMOD_S7MS_Msk          (0x1UL << LED_SEGMOD_S7MS_Pos)               /*!<LED SEGMOD: S7MS Mask */

#define LED_SEGMOD_S8MS_Pos          8                                            /*!<LED SEGMOD: S8MS Position */
#define LED_SEGMOD_S8MS_Msk          (0x1UL << LED_SEGMOD_S8MS_Pos)               /*!<LED SEGMOD: S8MS Mask */

#define LED_SEGMOD_S9MS_Pos          9                                            /*!<LED SEGMOD: S9MS Position */
#define LED_SEGMOD_S9MS_Msk          (0x1UL << LED_SEGMOD_S9MS_Pos)               /*!<LED SEGMOD: S9MS Mask */

#define LED_SEGMOD_S10MS_Pos         10                                           /*!<LED SEGMOD: S10MS Position */
#define LED_SEGMOD_S10MS_Msk         (0x1UL << LED_SEGMOD_S10MS_Pos)              /*!<LED SEGMOD: S10MS Mask */

#define LED_SEGMOD_S11MS_Pos         11                                           /*!<LED SEGMOD: S11MS Position */
#define LED_SEGMOD_S11MS_Msk         (0x1UL << LED_SEGMOD_S11MS_Pos)              /*!<LED SEGMOD: S11MS Mask */

#define LED_SEGMOD_S12MS_Pos         12                                           /*!<LED SEGMOD: S12MS Position */
#define LED_SEGMOD_S12MS_Msk         (0x1UL << LED_SEGMOD_S12MS_Pos)              /*!<LED SEGMOD: S12MS Mask */

#define LED_SEGMOD_S13MS_Pos         13                                           /*!<LED SEGMOD: S13MS Position */
#define LED_SEGMOD_S13MS_Msk         (0x1UL << LED_SEGMOD_S13MS_Pos)              /*!<LED SEGMOD: S13MS Mask */

#define LED_SEGMOD_S14MS_Pos         14                                           /*!<LED SEGMOD: S14MS Position */
#define LED_SEGMOD_S14MS_Msk         (0x1UL << LED_SEGMOD_S14MS_Pos)              /*!<LED SEGMOD: S14MS Mask */

#define LED_SEGMOD_S15MS_Pos         15                                           /*!<LED SEGMOD: S15MS Position */
#define LED_SEGMOD_S15MS_Msk         (0x1UL << LED_SEGMOD_S15MS_Pos)              /*!<LED SEGMOD: S15MS Mask */

#define LED_SEGMOD_Msk_ALL           (LED_SEGMOD_S0MS_Msk          |\
                                      LED_SEGMOD_S1MS_Msk          |\
                                      LED_SEGMOD_S2MS_Msk          |\
                                      LED_SEGMOD_S3MS_Msk          |\
                                      LED_SEGMOD_S4MS_Msk          |\
                                      LED_SEGMOD_S5MS_Msk          |\
                                      LED_SEGMOD_S6MS_Msk          |\
                                      LED_SEGMOD_S7MS_Msk          |\
                                      LED_SEGMOD_S8MS_Msk          |\
                                      LED_SEGMOD_S9MS_Msk          |\
                                      LED_SEGMOD_S10MS_Msk         |\
                                      LED_SEGMOD_S11MS_Msk         |\
                                      LED_SEGMOD_S12MS_Msk         |\
                                      LED_SEGMOD_S13MS_Msk         |\
                                      LED_SEGMOD_S14MS_Msk         |\
                                      LED_SEGMOD_S15MS_Msk         )

#define LED_SDR0_SEG0DUTY_Pos        0                                            /*!<LED SDR0: SEG0DUTY Position */
#define LED_SDR0_SEG0DUTY_Msk        (0xFFUL /*<< LED_SDR0_SEG0DUTY_Pos*/)        /*!<LED SDR0: SEG0DUTY Mask */

#define LED_SDR0_SEG1DUTY_Pos        8                                            /*!<LED SDR0: SEG1DUTY Position */
#define LED_SDR0_SEG1DUTY_Msk        (0xFFUL << LED_SDR0_SEG1DUTY_Pos)            /*!<LED SDR0: SEG1DUTY Mask */

#define LED_SDR0_SEG2DUTY_Pos        16                                           /*!<LED SDR0: SEG2DUTY Position */
#define LED_SDR0_SEG2DUTY_Msk        (0xFFUL << LED_SDR0_SEG2DUTY_Pos)            /*!<LED SDR0: SEG2DUTY Mask */

#define LED_SDR0_SEG3DUTY_Pos        24                                           /*!<LED SDR0: SEG3DUTY Position */
#define LED_SDR0_SEG3DUTY_Msk        (0xFFUL << LED_SDR0_SEG3DUTY_Pos)            /*!<LED SDR0: SEG3DUTY Mask */

#define LED_SDR0_Msk_ALL             (LED_SDR0_SEG0DUTY_Msk        |\
                                      LED_SDR0_SEG1DUTY_Msk        |\
                                      LED_SDR0_SEG2DUTY_Msk        |\
                                      LED_SDR0_SEG3DUTY_Msk        )

#define LED_SDR1_SEG4DUTY_Pos        0                                            /*!<LED SDR1: SEG4DUTY Position */
#define LED_SDR1_SEG4DUTY_Msk        (0xFFUL /*<< LED_SDR1_SEG4DUTY_Pos*/)        /*!<LED SDR1: SEG4DUTY Mask */

#define LED_SDR1_SEG5DUTY_Pos        8                                            /*!<LED SDR1: SEG5DUTY Position */
#define LED_SDR1_SEG5DUTY_Msk        (0xFFUL << LED_SDR1_SEG5DUTY_Pos)            /*!<LED SDR1: SEG5DUTY Mask */

#define LED_SDR1_SEG6DUTY_Pos        16                                           /*!<LED SDR1: SEG6DUTY Position */
#define LED_SDR1_SEG6DUTY_Msk        (0xFFUL << LED_SDR1_SEG6DUTY_Pos)            /*!<LED SDR1: SEG6DUTY Mask */

#define LED_SDR1_SEG7DUTY_Pos        24                                           /*!<LED SDR1: SEG7DUTY Position */
#define LED_SDR1_SEG7DUTY_Msk        (0xFFUL << LED_SDR1_SEG7DUTY_Pos)            /*!<LED SDR1: SEG7DUTY Mask */

#define LED_SDR1_Msk_ALL             (LED_SDR1_SEG4DUTY_Msk        |\
                                      LED_SDR1_SEG5DUTY_Msk        |\
                                      LED_SDR1_SEG6DUTY_Msk        |\
                                      LED_SDR1_SEG7DUTY_Msk        )

#define LED_SDR2_SEG8DUTY_Pos        0                                            /*!<LED SDR2: SEG8DUTY Position */
#define LED_SDR2_SEG8DUTY_Msk        (0xFFUL /*<< LED_SDR2_SEG8DUTY_Pos*/)        /*!<LED SDR2: SEG8DUTY Mask */

#define LED_SDR2_SEG9DUTY_Pos        8                                            /*!<LED SDR2: SEG9DUTY Position */
#define LED_SDR2_SEG9DUTY_Msk        (0xFFUL << LED_SDR2_SEG9DUTY_Pos)            /*!<LED SDR2: SEG9DUTY Mask */

#define LED_SDR2_SEG10DUTY_Pos       16                                           /*!<LED SDR2: SEG10DUTY Position */
#define LED_SDR2_SEG10DUTY_Msk       (0xFFUL << LED_SDR2_SEG10DUTY_Pos)           /*!<LED SDR2: SEG10DUTY Mask */

#define LED_SDR2_SEG11DUTY_Pos       24                                           /*!<LED SDR2: SEG11DUTY Position */
#define LED_SDR2_SEG11DUTY_Msk       (0xFFUL << LED_SDR2_SEG11DUTY_Pos)           /*!<LED SDR2: SEG11DUTY Mask */

#define LED_SDR2_Msk_ALL             (LED_SDR2_SEG8DUTY_Msk        |\
                                      LED_SDR2_SEG9DUTY_Msk        |\
                                      LED_SDR2_SEG10DUTY_Msk       |\
                                      LED_SDR2_SEG11DUTY_Msk       )

#define LED_SDR3_SEG12DUTY_Pos       0                                            /*!<LED SDR3: SEG12DUTY Position */
#define LED_SDR3_SEG12DUTY_Msk       (0xFFUL /*<< LED_SDR3_SEG12DUTY_Pos*/)       /*!<LED SDR3: SEG12DUTY Mask */

#define LED_SDR3_SEG13DUTY_Pos       8                                            /*!<LED SDR3: SEG13DUTY Position */
#define LED_SDR3_SEG13DUTY_Msk       (0xFFUL << LED_SDR3_SEG13DUTY_Pos)           /*!<LED SDR3: SEG13DUTY Mask */

#define LED_SDR3_SEG14DUTY_Pos       16                                           /*!<LED SDR3: SEG14DUTY Position */
#define LED_SDR3_SEG14DUTY_Msk       (0xFFUL << LED_SDR3_SEG14DUTY_Pos)           /*!<LED SDR3: SEG14DUTY Mask */

#define LED_SDR3_SEG15DUTY_Pos       24                                           /*!<LED SDR3: SEG15DUTY Position */
#define LED_SDR3_SEG15DUTY_Msk       (0xFFUL << LED_SDR3_SEG15DUTY_Pos)           /*!<LED SDR3: SEG15DUTY Mask */

#define LED_SDR3_Msk_ALL             (LED_SDR3_SEG12DUTY_Msk       |\
                                      LED_SDR3_SEG13DUTY_Msk       |\
                                      LED_SDR3_SEG14DUTY_Msk       |\
                                      LED_SDR3_SEG15DUTY_Msk       )

#define LED_SOR0_COM0SEG_Pos         0                                            /*!<LED SOR0: COM0SEG Position */
#define LED_SOR0_COM0SEG_Msk         (0xFFFFUL /*<< LED_SOR0_COM0SEG_Pos*/)       /*!<LED SOR0: COM0SEG Mask */

#define LED_SOR0_COM1SEG_Pos         16                                           /*!<LED SOR0: COM1SEG Position */
#define LED_SOR0_COM1SEG_Msk         (0xFFFFUL << LED_SOR0_COM1SEG_Pos)           /*!<LED SOR0: COM1SEG Mask */

#define LED_SOR0_Msk_ALL             (LED_SOR0_COM0SEG_Msk         |\
                                      LED_SOR0_COM1SEG_Msk         )

#define LED_SOR1_COM2SEG_Pos         0                                            /*!<LED SOR1: COM2SEG Position */
#define LED_SOR1_COM2SEG_Msk         (0xFFFFUL /*<< LED_SOR1_COM2SEG_Pos*/)       /*!<LED SOR1: COM2SEG Mask */

#define LED_SOR1_COM3SEG_Pos         16                                           /*!<LED SOR1: COM3SEG Position */
#define LED_SOR1_COM3SEG_Msk         (0xFFFFUL << LED_SOR1_COM3SEG_Pos)           /*!<LED SOR1: COM3SEG Mask */

#define LED_SOR1_Msk_ALL             (LED_SOR1_COM2SEG_Msk         |\
                                      LED_SOR1_COM3SEG_Msk         )

#define LED_SOR2_COM4SEG_Pos         0                                            /*!<LED SOR2: COM4SEG Position */
#define LED_SOR2_COM4SEG_Msk         (0xFFFFUL /*<< LED_SOR2_COM4SEG_Pos*/)       /*!<LED SOR2: COM4SEG Mask */

#define LED_SOR2_COM5SEG_Pos         16                                           /*!<LED SOR2: COM5SEG Position */
#define LED_SOR2_COM5SEG_Msk         (0xFFFFUL << LED_SOR2_COM5SEG_Pos)           /*!<LED SOR2: COM5SEG Mask */

#define LED_SOR2_Msk_ALL             (LED_SOR2_COM4SEG_Msk         |\
                                      LED_SOR2_COM5SEG_Msk         )

#define LED_SOR3_COM6SEG_Pos         0                                            /*!<LED SOR3: COM6SEG Position */
#define LED_SOR3_COM6SEG_Msk         (0xFFFFUL /*<< LED_SOR3_COM6SEG_Pos*/)       /*!<LED SOR3: COM6SEG Mask */

#define LED_SOR3_COM7SEG_Pos         16                                           /*!<LED SOR3: COM7SEG Position */
#define LED_SOR3_COM7SEG_Msk         (0xFFFFUL << LED_SOR3_COM7SEG_Pos)           /*!<LED SOR3: COM7SEG Mask */

#define LED_SOR3_Msk_ALL             (LED_SOR3_COM6SEG_Msk         |\
                                      LED_SOR3_COM7SEG_Msk         )

#define LCD_CR_EN_Pos                0                                            /*!<LCD CR: EN Position */
#define LCD_CR_EN_Msk                (0x1UL /*<< LCD_CR_EN_Pos*/)                 /*!<LCD CR: EN Mask */

#define LCD_CR_LCLK_Pos              1                                            /*!<LCD CR: LCLK Position */
#define LCD_CR_LCLK_Msk              (0x1UL << LCD_CR_LCLK_Pos)                   /*!<LCD CR: LCLK Mask */

#define LCD_CR_DUTY_Pos              2                                            /*!<LCD CR: DUTY Position */
#define LCD_CR_DUTY_Msk              (0x7UL << LCD_CR_DUTY_Pos)                   /*!<LCD CR: DUTY Mask */

#define LCD_CR_VOL_Pos               5                                            /*!<LCD CR: VOL Position */
#define LCD_CR_VOL_Msk               (0x7UL << LCD_CR_VOL_Pos)                    /*!<LCD CR: VOL Mask */

#define LCD_CR_ELCC_Pos              9                                            /*!<LCD CR: ELCC Position */
#define LCD_CR_ELCC_Msk              (0x1UL << LCD_CR_ELCC_Pos)                   /*!<LCD CR: ELCC Mask */

#define LCD_CR_MODSW_Pos             10                                           /*!<LCD CR: MODSW Position */
#define LCD_CR_MODSW_Msk             (0x1UL << LCD_CR_MODSW_Pos)                  /*!<LCD CR: MODSW Mask */

#define LCD_CR_MOD_Pos               12                                           /*!<LCD CR: MOD Position */
#define LCD_CR_MOD_Msk               (0x3UL << LCD_CR_MOD_Pos)                    /*!<LCD CR: MOD Mask */

#define LCD_CR_FCCTL_Pos             14                                           /*!<LCD CR: FCCTL Position */
#define LCD_CR_FCCTL_Msk             (0x3UL << LCD_CR_FCCTL_Pos)                  /*!<LCD CR: FCCTL Mask */

#define LCD_CR_CNTMOD_Pos            16                                           /*!<LCD CR: CNTMOD Position */
#define LCD_CR_CNTMOD_Msk            (0x1UL << LCD_CR_CNTMOD_Pos)                 /*!<LCD CR: CNTMOD Mask */

#define LCD_CR_DCK_Pos               17                                           /*!<LCD CR: DCK Position */
#define LCD_CR_DCK_Msk               (0x3UL << LCD_CR_DCK_Pos)                    /*!<LCD CR: DCK Mask */

#define LCD_CR_Msk_ALL               (LCD_CR_EN_Msk                |\
                                      LCD_CR_LCLK_Msk              |\
                                      LCD_CR_DUTY_Msk              |\
                                      LCD_CR_VOL_Msk               |\
                                      LCD_CR_ELCC_Msk              |\
                                      LCD_CR_MODSW_Msk             |\
                                      LCD_CR_MOD_Msk               |\
                                      LCD_CR_FCCTL_Msk             |\
                                      LCD_CR_CNTMOD_Msk            |\
                                      LCD_CR_DCK_Msk               )

#define LCD_BUFS0_LCDBUF0_Pos        0                                            /*!<LCD BUFS0: LCDBUF0 Position */
#define LCD_BUFS0_LCDBUF0_Msk        (0xFFUL /*<< LCD_BUFS0_LCDBUF0_Pos*/)        /*!<LCD BUFS0: LCDBUF0 Mask */

#define LCD_BUFS0_LCDBUF1_Pos        8                                            /*!<LCD BUFS0: LCDBUF1 Position */
#define LCD_BUFS0_LCDBUF1_Msk        (0xFFUL << LCD_BUFS0_LCDBUF1_Pos)            /*!<LCD BUFS0: LCDBUF1 Mask */

#define LCD_BUFS0_LCDBUF2_Pos        16                                           /*!<LCD BUFS0: LCDBUF2 Position */
#define LCD_BUFS0_LCDBUF2_Msk        (0xFFUL << LCD_BUFS0_LCDBUF2_Pos)            /*!<LCD BUFS0: LCDBUF2 Mask */

#define LCD_BUFS0_LCDBUF3_Pos        24                                           /*!<LCD BUFS0: LCDBUF3 Position */
#define LCD_BUFS0_LCDBUF3_Msk        (0xFFUL << LCD_BUFS0_LCDBUF3_Pos)            /*!<LCD BUFS0: LCDBUF3 Mask */

#define LCD_BUFS0_Msk_ALL            (LCD_BUFS0_LCDBUF0_Msk        |\
                                      LCD_BUFS0_LCDBUF1_Msk        |\
                                      LCD_BUFS0_LCDBUF2_Msk        |\
                                      LCD_BUFS0_LCDBUF3_Msk        )

#define LCD_BUFS1_LCDBUF4_Pos        0                                            /*!<LCD BUFS1: LCDBUF4 Position */
#define LCD_BUFS1_LCDBUF4_Msk        (0xFFUL /*<< LCD_BUFS1_LCDBUF4_Pos*/)        /*!<LCD BUFS1: LCDBUF4 Mask */

#define LCD_BUFS1_LCDBUF5_Pos        8                                            /*!<LCD BUFS1: LCDBUF5 Position */
#define LCD_BUFS1_LCDBUF5_Msk        (0xFFUL << LCD_BUFS1_LCDBUF5_Pos)            /*!<LCD BUFS1: LCDBUF5 Mask */

#define LCD_BUFS1_LCDBUF6_Pos        16                                           /*!<LCD BUFS1: LCDBUF6 Position */
#define LCD_BUFS1_LCDBUF6_Msk        (0xFFUL << LCD_BUFS1_LCDBUF6_Pos)            /*!<LCD BUFS1: LCDBUF6 Mask */

#define LCD_BUFS1_LCDBUF7_Pos        24                                           /*!<LCD BUFS1: LCDBUF7 Position */
#define LCD_BUFS1_LCDBUF7_Msk        (0xFFUL << LCD_BUFS1_LCDBUF7_Pos)            /*!<LCD BUFS1: LCDBUF7 Mask */

#define LCD_BUFS1_Msk_ALL            (LCD_BUFS1_LCDBUF4_Msk        |\
                                      LCD_BUFS1_LCDBUF5_Msk        |\
                                      LCD_BUFS1_LCDBUF6_Msk        |\
                                      LCD_BUFS1_LCDBUF7_Msk        )

#define LCD_BUFS2_LCDBUF8_Pos        0                                            /*!<LCD BUFS2: LCDBUF8 Position */
#define LCD_BUFS2_LCDBUF8_Msk        (0xFFUL /*<< LCD_BUFS2_LCDBUF8_Pos*/)        /*!<LCD BUFS2: LCDBUF8 Mask */

#define LCD_BUFS2_LCDBUF9_Pos        8                                            /*!<LCD BUFS2: LCDBUF9 Position */
#define LCD_BUFS2_LCDBUF9_Msk        (0xFFUL << LCD_BUFS2_LCDBUF9_Pos)            /*!<LCD BUFS2: LCDBUF9 Mask */

#define LCD_BUFS2_LCDBUF10_Pos       16                                           /*!<LCD BUFS2: LCDBUF10 Position */
#define LCD_BUFS2_LCDBUF10_Msk       (0xFFUL << LCD_BUFS2_LCDBUF10_Pos)           /*!<LCD BUFS2: LCDBUF10 Mask */

#define LCD_BUFS2_LCDBUF11_Pos       24                                           /*!<LCD BUFS2: LCDBUF11 Position */
#define LCD_BUFS2_LCDBUF11_Msk       (0xFFUL << LCD_BUFS2_LCDBUF11_Pos)           /*!<LCD BUFS2: LCDBUF11 Mask */

#define LCD_BUFS2_Msk_ALL            (LCD_BUFS2_LCDBUF8_Msk        |\
                                      LCD_BUFS2_LCDBUF9_Msk        |\
                                      LCD_BUFS2_LCDBUF10_Msk       |\
                                      LCD_BUFS2_LCDBUF11_Msk       )

#define LCD_BUFS3_LCDBUF12_Pos       0                                            /*!<LCD BUFS3: LCDBUF12 Position */
#define LCD_BUFS3_LCDBUF12_Msk       (0xFFUL /*<< LCD_BUFS3_LCDBUF12_Pos*/)       /*!<LCD BUFS3: LCDBUF12 Mask */

#define LCD_BUFS3_LCDBUF13_Pos       8                                            /*!<LCD BUFS3: LCDBUF13 Position */
#define LCD_BUFS3_LCDBUF13_Msk       (0xFFUL << LCD_BUFS3_LCDBUF13_Pos)           /*!<LCD BUFS3: LCDBUF13 Mask */

#define LCD_BUFS3_LCDBUF14_Pos       16                                           /*!<LCD BUFS3: LCDBUF14 Position */
#define LCD_BUFS3_LCDBUF14_Msk       (0xFFUL << LCD_BUFS3_LCDBUF14_Pos)           /*!<LCD BUFS3: LCDBUF14 Mask */

#define LCD_BUFS3_LCDBUF15_Pos       24                                           /*!<LCD BUFS3: LCDBUF15 Position */
#define LCD_BUFS3_LCDBUF15_Msk       (0xFFUL << LCD_BUFS3_LCDBUF15_Pos)           /*!<LCD BUFS3: LCDBUF15 Mask */

#define LCD_BUFS3_Msk_ALL            (LCD_BUFS3_LCDBUF12_Msk       |\
                                      LCD_BUFS3_LCDBUF13_Msk       |\
                                      LCD_BUFS3_LCDBUF14_Msk       |\
                                      LCD_BUFS3_LCDBUF15_Msk       )

#define LCD_BUFS4_LCDBUF16_Pos       0                                            /*!<LCD BUFS4: LCDBUF16 Position */
#define LCD_BUFS4_LCDBUF16_Msk       (0xFFUL /*<< LCD_BUFS4_LCDBUF16_Pos*/)       /*!<LCD BUFS4: LCDBUF16 Mask */

#define LCD_BUFS4_LCDBUF17_Pos       8                                            /*!<LCD BUFS4: LCDBUF17 Position */
#define LCD_BUFS4_LCDBUF17_Msk       (0xFFUL << LCD_BUFS4_LCDBUF17_Pos)           /*!<LCD BUFS4: LCDBUF17 Mask */

#define LCD_BUFS4_LCDBUF18_Pos       16                                           /*!<LCD BUFS4: LCDBUF18 Position */
#define LCD_BUFS4_LCDBUF18_Msk       (0xFFUL << LCD_BUFS4_LCDBUF18_Pos)           /*!<LCD BUFS4: LCDBUF18 Mask */

#define LCD_BUFS4_LCDBUF19_Pos       24                                           /*!<LCD BUFS4: LCDBUF19 Position */
#define LCD_BUFS4_LCDBUF19_Msk       (0xFFUL << LCD_BUFS4_LCDBUF19_Pos)           /*!<LCD BUFS4: LCDBUF19 Mask */

#define LCD_BUFS4_Msk_ALL            (LCD_BUFS4_LCDBUF16_Msk       |\
                                      LCD_BUFS4_LCDBUF17_Msk       |\
                                      LCD_BUFS4_LCDBUF18_Msk       |\
                                      LCD_BUFS4_LCDBUF19_Msk       )

#define LCD_BUFS5_LCDBUF20_Pos       0                                            /*!<LCD BUFS5: LCDBUF20 Position */
#define LCD_BUFS5_LCDBUF20_Msk       (0xFFUL /*<< LCD_BUFS5_LCDBUF20_Pos*/)       /*!<LCD BUFS5: LCDBUF20 Mask */

#define LCD_BUFS5_LCDBUF21_Pos       8                                            /*!<LCD BUFS5: LCDBUF21 Position */
#define LCD_BUFS5_LCDBUF21_Msk       (0xFFUL << LCD_BUFS5_LCDBUF21_Pos)           /*!<LCD BUFS5: LCDBUF21 Mask */

#define LCD_BUFS5_LCDBUF22_Pos       16                                           /*!<LCD BUFS5: LCDBUF22 Position */
#define LCD_BUFS5_LCDBUF22_Msk       (0xFFUL << LCD_BUFS5_LCDBUF22_Pos)           /*!<LCD BUFS5: LCDBUF22 Mask */

#define LCD_BUFS5_LCDBUF23_Pos       24                                           /*!<LCD BUFS5: LCDBUF23 Position */
#define LCD_BUFS5_LCDBUF23_Msk       (0xFFUL << LCD_BUFS5_LCDBUF23_Pos)           /*!<LCD BUFS5: LCDBUF23 Mask */

#define LCD_BUFS5_Msk_ALL            (LCD_BUFS5_LCDBUF20_Msk       |\
                                      LCD_BUFS5_LCDBUF21_Msk       |\
                                      LCD_BUFS5_LCDBUF22_Msk       |\
                                      LCD_BUFS5_LCDBUF23_Msk       )

#define LCD_BUFS6_LCDBUF24_Pos       0                                            /*!<LCD BUFS6: LCDBUF24 Position */
#define LCD_BUFS6_LCDBUF24_Msk       (0xFFUL /*<< LCD_BUFS6_LCDBUF24_Pos*/)       /*!<LCD BUFS6: LCDBUF24 Mask */

#define LCD_BUFS6_LCDBUF25_Pos       8                                            /*!<LCD BUFS6: LCDBUF25 Position */
#define LCD_BUFS6_LCDBUF25_Msk       (0xFFUL << LCD_BUFS6_LCDBUF25_Pos)           /*!<LCD BUFS6: LCDBUF25 Mask */

#define LCD_BUFS6_LCDBUF26_Pos       16                                           /*!<LCD BUFS6: LCDBUF26 Position */
#define LCD_BUFS6_LCDBUF26_Msk       (0xFFUL << LCD_BUFS6_LCDBUF26_Pos)           /*!<LCD BUFS6: LCDBUF26 Mask */

#define LCD_BUFS6_LCDBUF27_Pos       24                                           /*!<LCD BUFS6: LCDBUF27 Position */
#define LCD_BUFS6_LCDBUF27_Msk       (0xFFUL << LCD_BUFS6_LCDBUF27_Pos)           /*!<LCD BUFS6: LCDBUF27 Mask */

#define LCD_BUFS6_Msk_ALL            (LCD_BUFS6_LCDBUF24_Msk       |\
                                      LCD_BUFS6_LCDBUF25_Msk       |\
                                      LCD_BUFS6_LCDBUF26_Msk       |\
                                      LCD_BUFS6_LCDBUF27_Msk       )

#define LCD_BUFS7_LCDBUF28_Pos       0                                            /*!<LCD BUFS7: LCDBUF28 Position */
#define LCD_BUFS7_LCDBUF28_Msk       (0xFFUL /*<< LCD_BUFS7_LCDBUF28_Pos*/)       /*!<LCD BUFS7: LCDBUF28 Mask */

#define LCD_BUFS7_LCDBUF29_Pos       8                                            /*!<LCD BUFS7: LCDBUF29 Position */
#define LCD_BUFS7_LCDBUF29_Msk       (0xFFUL << LCD_BUFS7_LCDBUF29_Pos)           /*!<LCD BUFS7: LCDBUF29 Mask */

#define LCD_BUFS7_LCDBUF30_Pos       16                                           /*!<LCD BUFS7: LCDBUF30 Position */
#define LCD_BUFS7_LCDBUF30_Msk       (0xFFUL << LCD_BUFS7_LCDBUF30_Pos)           /*!<LCD BUFS7: LCDBUF30 Mask */

#define LCD_BUFS7_LCDBUF31_Pos       24                                           /*!<LCD BUFS7: LCDBUF31 Position */
#define LCD_BUFS7_LCDBUF31_Msk       (0xFFUL << LCD_BUFS7_LCDBUF31_Pos)           /*!<LCD BUFS7: LCDBUF31 Mask */

#define LCD_BUFS7_Msk_ALL            (LCD_BUFS7_LCDBUF28_Msk       |\
                                      LCD_BUFS7_LCDBUF29_Msk       |\
                                      LCD_BUFS7_LCDBUF30_Msk       |\
                                      LCD_BUFS7_LCDBUF31_Msk       )

#define LCD_BUFS8_LCDBUF32_Pos       0                                            /*!<LCD BUFS8: LCDBUF32 Position */
#define LCD_BUFS8_LCDBUF32_Msk       (0xFFUL /*<< LCD_BUFS8_LCDBUF32_Pos*/)       /*!<LCD BUFS8: LCDBUF32 Mask */

#define LCD_BUFS8_LCDBUF33_Pos       8                                            /*!<LCD BUFS8: LCDBUF33 Position */
#define LCD_BUFS8_LCDBUF33_Msk       (0xFFUL << LCD_BUFS8_LCDBUF33_Pos)           /*!<LCD BUFS8: LCDBUF33 Mask */

#define LCD_BUFS8_LCDBUF34_Pos       16                                           /*!<LCD BUFS8: LCDBUF34 Position */
#define LCD_BUFS8_LCDBUF34_Msk       (0xFFUL << LCD_BUFS8_LCDBUF34_Pos)           /*!<LCD BUFS8: LCDBUF34 Mask */

#define LCD_BUFS8_LCDBUF35_Pos       24                                           /*!<LCD BUFS8: LCDBUF35 Position */
#define LCD_BUFS8_LCDBUF35_Msk       (0xFFUL << LCD_BUFS8_LCDBUF35_Pos)           /*!<LCD BUFS8: LCDBUF35 Mask */

#define LCD_BUFS8_Msk_ALL            (LCD_BUFS8_LCDBUF32_Msk       |\
                                      LCD_BUFS8_LCDBUF33_Msk       |\
                                      LCD_BUFS8_LCDBUF34_Msk       |\
                                      LCD_BUFS8_LCDBUF35_Msk       )

#define LCD_BUFS9_LCDBUF36_Pos       0                                            /*!<LCD BUFS9: LCDBUF36 Position */
#define LCD_BUFS9_LCDBUF36_Msk       (0xFFUL /*<< LCD_BUFS9_LCDBUF36_Pos*/)       /*!<LCD BUFS9: LCDBUF36 Mask */

#define LCD_BUFS9_LCDBUF37_Pos       8                                            /*!<LCD BUFS9: LCDBUF37 Position */
#define LCD_BUFS9_LCDBUF37_Msk       (0xFFUL << LCD_BUFS9_LCDBUF37_Pos)           /*!<LCD BUFS9: LCDBUF37 Mask */

#define LCD_BUFS9_LCDBUF38_Pos       16                                           /*!<LCD BUFS9: LCDBUF38 Position */
#define LCD_BUFS9_LCDBUF38_Msk       (0xFFUL << LCD_BUFS9_LCDBUF38_Pos)           /*!<LCD BUFS9: LCDBUF38 Mask */

#define LCD_BUFS9_LCDBUF39_Pos       24                                           /*!<LCD BUFS9: LCDBUF39 Position */
#define LCD_BUFS9_LCDBUF39_Msk       (0xFFUL << LCD_BUFS9_LCDBUF39_Pos)           /*!<LCD BUFS9: LCDBUF39 Mask */

#define LCD_BUFS9_Msk_ALL            (LCD_BUFS9_LCDBUF36_Msk       |\
                                      LCD_BUFS9_LCDBUF37_Msk       |\
                                      LCD_BUFS9_LCDBUF38_Msk       |\
                                      LCD_BUFS9_LCDBUF39_Msk       )

#define TIM_CR_STR_Pos               0                                            /*!<TIM CR: STR Position */
#define TIM_CR_STR_Msk               (0x1UL /*<< TIM_CR_STR_Pos*/)                /*!<TIM CR: STR Mask */

#define TIM_CR_OPM_Pos               3                                            /*!<TIM CR: OPM Position */
#define TIM_CR_OPM_Msk               (0x1UL << TIM_CR_OPM_Pos)                    /*!<TIM CR: OPM Mask */

#define TIM_CR_CLKS_Pos              4                                            /*!<TIM CR: CLKS Position */
#define TIM_CR_CLKS_Msk              (0x3UL << TIM_CR_CLKS_Pos)                   /*!<TIM CR: CLKS Mask */

#define TIM_CR_IE_Pos                7                                            /*!<TIM CR: IE Position */
#define TIM_CR_IE_Msk                (0x1UL << TIM_CR_IE_Pos)                     /*!<TIM CR: IE Mask */

#define TIM_CR_TRIGEN_Pos            8                                            /*!<TIM CR: TRIGEN Position */
#define TIM_CR_TRIGEN_Msk            (0x1UL << TIM_CR_TRIGEN_Pos)                 /*!<TIM CR: TRIGEN Mask */

#define TIM_CR_ETEN_Pos              9                                            /*!<TIM CR: ETEN Position */
#define TIM_CR_ETEN_Msk              (0x1UL << TIM_CR_ETEN_Pos)                   /*!<TIM CR: ETEN Mask */

#define TIM_CR_TC_Pos                10                                           /*!<TIM CR: TC Position */
#define TIM_CR_TC_Msk                (0x1UL << TIM_CR_TC_Pos)                     /*!<TIM CR: TC Mask */

#define TIM_CR_ECF_Pos               12                                           /*!<TIM CR: ECF Position */
#define TIM_CR_ECF_Msk               (0x3UL << TIM_CR_ECF_Pos)                    /*!<TIM CR: ECF Mask */

#define TIM_CR_Msk_ALL               (TIM_CR_STR_Msk               |\
                                      TIM_CR_OPM_Msk               |\
                                      TIM_CR_CLKS_Msk              |\
                                      TIM_CR_IE_Msk                |\
                                      TIM_CR_TRIGEN_Msk            |\
                                      TIM_CR_ETEN_Msk              |\
                                      TIM_CR_TC_Msk                |\
                                      TIM_CR_ECF_Msk               )

#define TIM_TCNT_TCNT_Pos            0                                            /*!<TIM TCNT: TCNT Position */
#define TIM_TCNT_TCNT_Msk            (0xFFFFUL /*<< TIM_TCNT_TCNT_Pos*/)          /*!<TIM TCNT: TCNT Mask */

#define TIM_TCNT_Msk_ALL             (TIM_TCNT_TCNT_Msk           )

#define TIM_TPR_TPR_Pos              0                                            /*!<TIM TPR: TPR Position */
#define TIM_TPR_TPR_Msk              (0xFFFFUL /*<< TIM_TPR_TPR_Pos*/)            /*!<TIM TPR: TPR Mask */

#define TIM_TPR_Msk_ALL              (TIM_TPR_TPR_Msk             )

#define TIM_PSQ_PSQ_Pos              0                                            /*!<TIM PSQ: PSQ Position */
#define TIM_PSQ_PSQ_Msk              (0xFFFFUL /*<< TIM_PSQ_PSQ_Pos*/)            /*!<TIM PSQ: PSQ Mask */

#define TIM_PSQ_Msk_ALL              (TIM_PSQ_PSQ_Msk             )

#define TIM_TIMINTF_TF_Pos           0                                            /*!<TIM TIMINTF: TF Position */
#define TIM_TIMINTF_TF_Msk           (0x1UL /*<< TIM_TIMINTF_TF_Pos*/)            /*!<TIM TIMINTF: TF Mask */

#define TIM_TIMINTF_TFC_Pos          16                                           /*!<TIM TIMINTF: TFC Position */
#define TIM_TIMINTF_TFC_Msk          (0x1UL << TIM_TIMINTF_TFC_Pos)               /*!<TIM TIMINTF: TFC Mask */

#define TIM_TIMINTF_Msk_ALL          (TIM_TIMINTF_TF_Msk           |\
                                      TIM_TIMINTF_TFC_Msk          )

#define PWM_CR_PWMEN_Pos             0                                            /*!<PWM CR: PWMEN Position */
#define PWM_CR_PWMEN_Msk             (0x1UL /*<< PWM_CR_PWMEN_Pos*/)              /*!<PWM CR: PWMEN Mask */

#define PWM_CR_TCK_Pos               1                                            /*!<PWM CR: TCK Position */
#define PWM_CR_TCK_Msk               (0x7UL << PWM_CR_TCK_Pos)                    /*!<PWM CR: TCK Mask */

#define PWM_CR_FLTC_Pos              4                                            /*!<PWM CR: FLTC Position */
#define PWM_CR_FLTC_Msk              (0x1UL << PWM_CR_FLTC_Pos)                   /*!<PWM CR: FLTC Mask */

#define PWM_CR_EFLT_Pos              5                                            /*!<PWM CR: EFLT Position */
#define PWM_CR_EFLT_Msk              (0x1UL << PWM_CR_EFLT_Pos)                   /*!<PWM CR: EFLT Mask */

#define PWM_CR_PWMSB_Pos             6                                            /*!<PWM CR: PWMSB Position */
#define PWM_CR_PWMSB_Msk             (0x1UL << PWM_CR_PWMSB_Pos)                  /*!<PWM CR: PWMSB Mask */

#define PWM_CR_PWMSA_Pos             7                                            /*!<PWM CR: PWMSA Position */
#define PWM_CR_PWMSA_Msk             (0x1UL << PWM_CR_PWMSA_Pos)                  /*!<PWM CR: PWMSA Mask */

#define PWM_CR_EFLTIE_Pos            8                                            /*!<PWM CR: EFLTIE Position */
#define PWM_CR_EFLTIE_Msk            (0x1UL << PWM_CR_EFLTIE_Pos)                 /*!<PWM CR: EFLTIE Mask */

#define PWM_CR_PWMIE_Pos             9                                            /*!<PWM CR: PWMIE Position */
#define PWM_CR_PWMIE_Msk             (0x1UL << PWM_CR_PWMIE_Pos)                  /*!<PWM CR: PWMIE Mask */

#define PWM_CR_PWMDMA_Pos            10                                           /*!<PWM CR: PWMDMA Position */
#define PWM_CR_PWMDMA_Msk            (0x1UL << PWM_CR_PWMDMA_Pos)                 /*!<PWM CR: PWMDMA Mask */

#define PWM_CR_FLTDMA_Pos            11                                           /*!<PWM CR: FLTDMA Position */
#define PWM_CR_FLTDMA_Msk            (0x1UL << PWM_CR_FLTDMA_Pos)                 /*!<PWM CR: FLTDMA Mask */

#define PWM_CR_Msk_ALL               (PWM_CR_PWMEN_Msk             |\
                                      PWM_CR_TCK_Msk               |\
                                      PWM_CR_FLTC_Msk              |\
                                      PWM_CR_EFLT_Msk              |\
                                      PWM_CR_PWMSB_Msk             |\
                                      PWM_CR_PWMSA_Msk             |\
                                      PWM_CR_EFLTIE_Msk            |\
                                      PWM_CR_PWMIE_Msk             |\
                                      PWM_CR_PWMDMA_Msk            |\
                                      PWM_CR_FLTDMA_Msk            )

#define PWM_PWMLOCK_PWMLO_Pos        0                                            /*!<PWM PWMLOCK: PWMLO Position */
#define PWM_PWMLOCK_PWMLO_Msk        (0xFFFFUL /*<< PWM_PWMLOCK_PWMLO_Pos*/)      /*!<PWM PWMLOCK: PWMLO Mask */

#define PWM_PWMLOCK_Msk_ALL          (PWM_PWMLOCK_PWMLO_Msk       )

#define PWM_PWMPR_PP_Pos             0                                            /*!<PWM PWMPR: PP Position */
#define PWM_PWMPR_PP_Msk             (0xFFFFUL /*<< PWM_PWMPR_PP_Pos*/)           /*!<PWM PWMPR: PP Mask */

#define PWM_PWMPR_Msk_ALL            (PWM_PWMPR_PP_Msk            )

#define PWM_PWMDR_PD_Pos             0                                            /*!<PWM PWMDR: PD Position */
#define PWM_PWMDR_PD_Msk             (0xFFFFUL /*<< PWM_PWMDR_PD_Pos*/)           /*!<PWM PWMDR: PD Mask */

#define PWM_PWMDR_Msk_ALL            (PWM_PWMDR_PD_Msk            )

#define PWM_PWMDTR_DT_Pos            0                                            /*!<PWM PWMDTR: DT Position */
#define PWM_PWMDTR_DT_Msk            (0xFFFFUL /*<< PWM_PWMDTR_DT_Pos*/)          /*!<PWM PWMDTR: DT Mask */

#define PWM_PWMDTR_Msk_ALL           (PWM_PWMDTR_DT_Msk           )

#define PWM_PWMINTF_FLTS_Pos         0                                            /*!<PWM PWMINTF: FLTS Position */
#define PWM_PWMINTF_FLTS_Msk         (0x1UL /*<< PWM_PWMINTF_FLTS_Pos*/)          /*!<PWM PWMINTF: FLTS Mask */

#define PWM_PWMINTF_PWMIF_Pos        1                                            /*!<PWM PWMINTF: PWMIF Position */
#define PWM_PWMINTF_PWMIF_Msk        (0x1UL << PWM_PWMINTF_PWMIF_Pos)             /*!<PWM PWMINTF: PWMIF Mask */

#define PWM_PWMINTF_FLTSC_Pos        16                                           /*!<PWM PWMINTF: FLTSC Position */
#define PWM_PWMINTF_FLTSC_Msk        (0x1UL << PWM_PWMINTF_FLTSC_Pos)             /*!<PWM PWMINTF: FLTSC Mask */

#define PWM_PWMINTF_PWMIFC_Pos       17                                           /*!<PWM PWMINTF: PWMIFC Position */
#define PWM_PWMINTF_PWMIFC_Msk       (0x1UL << PWM_PWMINTF_PWMIFC_Pos)            /*!<PWM PWMINTF: PWMIFC Mask */

#define PWM_PWMINTF_Msk_ALL          (PWM_PWMINTF_FLTS_Msk         |\
                                      PWM_PWMINTF_PWMIF_Msk        |\
                                      PWM_PWMINTF_FLTSC_Msk        |\
                                      PWM_PWMINTF_PWMIFC_Msk       )

#define PCA_CR_PEN_Pos               0                                            /*!<PCA CR: PEN Position */
#define PCA_CR_PEN_Msk               (0x1UL /*<< PCA_CR_PEN_Pos*/)                /*!<PCA CR: PEN Mask */

#define PCA_CR_Msk_ALL               (PCA_CR_PEN_Msk              )

#define PCA_CFGR_CPS_Pos             0                                            /*!<PCA CFGR: CPS Position */
#define PCA_CFGR_CPS_Msk             (0x7UL /*<< PCA_CFGR_CPS_Pos*/)              /*!<PCA CFGR: CPS Mask */

#define PCA_CFGR_CASCEN_Pos          3                                            /*!<PCA CFGR: CASCEN Position */
#define PCA_CFGR_CASCEN_Msk          (0x1UL << PCA_CFGR_CASCEN_Pos)               /*!<PCA CFGR: CASCEN Mask */

#define PCA_CFGR_SDEN_Pos            6                                            /*!<PCA CFGR: SDEN Position */
#define PCA_CFGR_SDEN_Msk            (0x1UL << PCA_CFGR_SDEN_Pos)                 /*!<PCA CFGR: SDEN Mask */

#define PCA_CFGR_CIE_Pos             7                                            /*!<PCA CFGR: CIE Position */
#define PCA_CFGR_CIE_Msk             (0x1UL << PCA_CFGR_CIE_Pos)                  /*!<PCA CFGR: CIE Mask */

#define PCA_CFGR_PIE_Pos             8                                            /*!<PCA CFGR: PIE Position */
#define PCA_CFGR_PIE_Msk             (0x1UL << PCA_CFGR_PIE_Pos)                  /*!<PCA CFGR: PIE Mask */

#define PCA_CFGR_CC0UE_Pos           12                                           /*!<PCA CFGR: CC0UE Position */
#define PCA_CFGR_CC0UE_Msk           (0x1UL << PCA_CFGR_CC0UE_Pos)                /*!<PCA CFGR: CC0UE Mask */

#define PCA_CFGR_CC1UE_Pos           13                                           /*!<PCA CFGR: CC1UE Position */
#define PCA_CFGR_CC1UE_Msk           (0x1UL << PCA_CFGR_CC1UE_Pos)                /*!<PCA CFGR: CC1UE Mask */

#define PCA_CFGR_PUE_Pos             15                                           /*!<PCA CFGR: PUE Position */
#define PCA_CFGR_PUE_Msk             (0x1UL << PCA_CFGR_PUE_Pos)                  /*!<PCA CFGR: PUE Mask */

#define PCA_CFGR_ECF_Pos             16                                           /*!<PCA CFGR: ECF Position */
#define PCA_CFGR_ECF_Msk             (0x3UL << PCA_CFGR_ECF_Pos)                  /*!<PCA CFGR: ECF Mask */

#define PCA_CFGR_CC0DMA_Pos          20                                           /*!<PCA CFGR: CC0DMA Position */
#define PCA_CFGR_CC0DMA_Msk          (0x1UL << PCA_CFGR_CC0DMA_Pos)               /*!<PCA CFGR: CC0DMA Mask */

#define PCA_CFGR_CC1DMA_Pos          21                                           /*!<PCA CFGR: CC1DMA Position */
#define PCA_CFGR_CC1DMA_Msk          (0x1UL << PCA_CFGR_CC1DMA_Pos)               /*!<PCA CFGR: CC1DMA Mask */

#define PCA_CFGR_CUDMA_Pos           23                                           /*!<PCA CFGR: CUDMA Position */
#define PCA_CFGR_CUDMA_Msk           (0x1UL << PCA_CFGR_CUDMA_Pos)                /*!<PCA CFGR: CUDMA Mask */

#define PCA_CFGR_PUDMA_Pos           24                                           /*!<PCA CFGR: PUDMA Position */
#define PCA_CFGR_PUDMA_Msk           (0x1UL << PCA_CFGR_PUDMA_Pos)                /*!<PCA CFGR: PUDMA Mask */

#define PCA_CFGR_Msk_ALL             (PCA_CFGR_CPS_Msk             |\
                                      PCA_CFGR_CASCEN_Msk          |\
                                      PCA_CFGR_SDEN_Msk            |\
                                      PCA_CFGR_CIE_Msk             |\
                                      PCA_CFGR_PIE_Msk             |\
                                      PCA_CFGR_CC0UE_Msk           |\
                                      PCA_CFGR_CC1UE_Msk           |\
                                      PCA_CFGR_PUE_Msk             |\
                                      PCA_CFGR_ECF_Msk             |\
                                      PCA_CFGR_CC0DMA_Msk          |\
                                      PCA_CFGR_CC1DMA_Msk          |\
                                      PCA_CFGR_CUDMA_Msk           |\
                                      PCA_CFGR_PUDMA_Msk           )

#define PCA_SR_CC0IF_Pos             0                                            /*!<PCA SR: CC0IF Position */
#define PCA_SR_CC0IF_Msk             (0x1UL /*<< PCA_SR_CC0IF_Pos*/)              /*!<PCA SR: CC0IF Mask */

#define PCA_SR_CC1IF_Pos             1                                            /*!<PCA SR: CC1IF Position */
#define PCA_SR_CC1IF_Msk             (0x1UL << PCA_SR_CC1IF_Pos)                  /*!<PCA SR: CC1IF Mask */

#define PCA_SR_PIF_Pos               4                                            /*!<PCA SR: PIF Position */
#define PCA_SR_PIF_Msk               (0x1UL << PCA_SR_PIF_Pos)                    /*!<PCA SR: PIF Mask */

#define PCA_SR_CIF_Pos               7                                            /*!<PCA SR: CIF Position */
#define PCA_SR_CIF_Msk               (0x1UL << PCA_SR_CIF_Pos)                    /*!<PCA SR: CIF Mask */

#define PCA_SR_CC0IFC_Pos            16                                           /*!<PCA SR: CC0IFC Position */
#define PCA_SR_CC0IFC_Msk            (0x1UL << PCA_SR_CC0IFC_Pos)                 /*!<PCA SR: CC0IFC Mask */

#define PCA_SR_CC1IFC_Pos            17                                           /*!<PCA SR: CC1IFC Position */
#define PCA_SR_CC1IFC_Msk            (0x1UL << PCA_SR_CC1IFC_Pos)                 /*!<PCA SR: CC1IFC Mask */

#define PCA_SR_PIFC_Pos              20                                           /*!<PCA SR: PIFC Position */
#define PCA_SR_PIFC_Msk              (0x1UL << PCA_SR_PIFC_Pos)                   /*!<PCA SR: PIFC Mask */

#define PCA_SR_CIFC_Pos              23                                           /*!<PCA SR: CIFC Position */
#define PCA_SR_CIFC_Msk              (0x1UL << PCA_SR_CIFC_Pos)                   /*!<PCA SR: CIFC Mask */

#define PCA_SR_Msk_ALL               (PCA_SR_CC0IF_Msk             |\
                                      PCA_SR_CC1IF_Msk             |\
                                      PCA_SR_PIF_Msk               |\
                                      PCA_SR_CIF_Msk               |\
                                      PCA_SR_CC0IFC_Msk            |\
                                      PCA_SR_CC1IFC_Msk            |\
                                      PCA_SR_PIFC_Msk              |\
                                      PCA_SR_CIFC_Msk              )

#define PCA_FORCE_FCO0_Pos           0                                            /*!<PCA FORCE: FCO0 Position */
#define PCA_FORCE_FCO0_Msk           (0x1UL /*<< PCA_FORCE_FCO0_Pos*/)            /*!<PCA FORCE: FCO0 Mask */

#define PCA_FORCE_FCO1_Pos           1                                            /*!<PCA FORCE: FCO1 Position */
#define PCA_FORCE_FCO1_Msk           (0x1UL << PCA_FORCE_FCO1_Pos)                /*!<PCA FORCE: FCO1 Mask */

#define PCA_FORCE_Msk_ALL            (PCA_FORCE_FCO0_Msk           |\
                                      PCA_FORCE_FCO1_Msk           )

#define PCA_CNT_CNTL_Pos             0                                            /*!<PCA CNT: CNTL Position */
#define PCA_CNT_CNTL_Msk             (0xFFUL /*<< PCA_CNT_CNTL_Pos*/)             /*!<PCA CNT: CNTL Mask */

#define PCA_CNT_CNTH_Pos             8                                            /*!<PCA CNT: CNTH Position */
#define PCA_CNT_CNTH_Msk             (0xFFUL << PCA_CNT_CNTH_Pos)                 /*!<PCA CNT: CNTH Mask */

#define PCA_CNT_CNTCAS_Pos           16                                           /*!<PCA CNT: CNTCAS Position */
#define PCA_CNT_CNTCAS_Msk           (0xFFFFUL << PCA_CNT_CNTCAS_Pos)             /*!<PCA CNT: CNTCAS Mask */

#define PCA_CNT_Msk_ALL              (PCA_CNT_CNTL_Msk             |\
                                      PCA_CNT_CNTH_Msk             |\
                                      PCA_CNT_CNTCAS_Msk           )

#define PCA_PSC_PSC_Pos              0                                            /*!<PCA PSC: PSC Position */
#define PCA_PSC_PSC_Msk              (0xFFFFUL /*<< PCA_PSC_PSC_Pos*/)            /*!<PCA PSC: PSC Mask */

#define PCA_PSC_Msk_ALL              (PCA_PSC_PSC_Msk             )

#define PCA_PR_PRL_Pos               0                                            /*!<PCA PR: PRL Position */
#define PCA_PR_PRL_Msk               (0xFFUL /*<< PCA_PR_PRL_Pos*/)               /*!<PCA PR: PRL Mask */

#define PCA_PR_PRH_Pos               8                                            /*!<PCA PR: PRH Position */
#define PCA_PR_PRH_Msk               (0xFFUL << PCA_PR_PRH_Pos)                   /*!<PCA PR: PRH Mask */

#define PCA_PR_PRCAS_Pos             16                                           /*!<PCA PR: PRCAS Position */
#define PCA_PR_PRCAS_Msk             (0xFFFFUL << PCA_PR_PRCAS_Pos)               /*!<PCA PR: PRCAS Mask */

#define PCA_PR_Msk_ALL               (PCA_PR_PRL_Msk               |\
                                      PCA_PR_PRH_Msk               |\
                                      PCA_PR_PRCAS_Msk             )

#define PCA_CCMR0_CCIE_Pos           0                                            /*!<PCA CCMR0: CCIE Position */
#define PCA_CCMR0_CCIE_Msk           (0x1UL /*<< PCA_CCMR0_CCIE_Pos*/)            /*!<PCA CCMR0: CCIE Mask */

#define PCA_CCMR0_TCP_Pos            2                                            /*!<PCA CCMR0: TCP Position */
#define PCA_CCMR0_TCP_Msk            (0x1UL << PCA_CCMR0_TCP_Pos)                 /*!<PCA CCMR0: TCP Mask */

#define PCA_CCMR0_CEN_Pos            3                                            /*!<PCA CCMR0: CEN Position */
#define PCA_CCMR0_CEN_Msk            (0x1UL << PCA_CCMR0_CEN_Pos)                 /*!<PCA CCMR0: CEN Mask */

#define PCA_CCMR0_FS_Pos             4                                            /*!<PCA CCMR0: FS Position */
#define PCA_CCMR0_FS_Msk             (0x3UL << PCA_CCMR0_FS_Pos)                  /*!<PCA CCMR0: FS Mask */

#define PCA_CCMR0_SM_Pos             6                                            /*!<PCA CCMR0: SM Position */
#define PCA_CCMR0_SM_Msk             (0x3UL << PCA_CCMR0_SM_Pos)                  /*!<PCA CCMR0: SM Mask */

#define PCA_CCMR0_CC_Pos             8                                            /*!<PCA CCMR0: CC Position */
#define PCA_CCMR0_CC_Msk             (0x1UL << PCA_CCMR0_CC_Pos)                  /*!<PCA CCMR0: CC Mask */

#define PCA_CCMR0_Msk_ALL            (PCA_CCMR0_CCIE_Msk           |\
                                      PCA_CCMR0_TCP_Msk            |\
                                      PCA_CCMR0_CEN_Msk            |\
                                      PCA_CCMR0_FS_Msk             |\
                                      PCA_CCMR0_SM_Msk             |\
                                      PCA_CCMR0_CC_Msk             )

#define PCA_CCMR1_CCIE_Pos           0                                            /*!<PCA CCMR1: CCIE Position */
#define PCA_CCMR1_CCIE_Msk           (0x1UL /*<< PCA_CCMR1_CCIE_Pos*/)            /*!<PCA CCMR1: CCIE Mask */

#define PCA_CCMR1_TCP_Pos            2                                            /*!<PCA CCMR1: TCP Position */
#define PCA_CCMR1_TCP_Msk            (0x1UL << PCA_CCMR1_TCP_Pos)                 /*!<PCA CCMR1: TCP Mask */

#define PCA_CCMR1_CEN_Pos            3                                            /*!<PCA CCMR1: CEN Position */
#define PCA_CCMR1_CEN_Msk            (0x1UL << PCA_CCMR1_CEN_Pos)                 /*!<PCA CCMR1: CEN Mask */

#define PCA_CCMR1_FS_Pos             4                                            /*!<PCA CCMR1: FS Position */
#define PCA_CCMR1_FS_Msk             (0x3UL << PCA_CCMR1_FS_Pos)                  /*!<PCA CCMR1: FS Mask */

#define PCA_CCMR1_SM_Pos             6                                            /*!<PCA CCMR1: SM Position */
#define PCA_CCMR1_SM_Msk             (0x3UL << PCA_CCMR1_SM_Pos)                  /*!<PCA CCMR1: SM Mask */

#define PCA_CCMR1_CC_Pos             8                                            /*!<PCA CCMR1: CC Position */
#define PCA_CCMR1_CC_Msk             (0x1UL << PCA_CCMR1_CC_Pos)                  /*!<PCA CCMR1: CC Mask */

#define PCA_CCMR1_Msk_ALL            (PCA_CCMR1_CCIE_Msk           |\
                                      PCA_CCMR1_TCP_Msk            |\
                                      PCA_CCMR1_CEN_Msk            |\
                                      PCA_CCMR1_FS_Msk             |\
                                      PCA_CCMR1_SM_Msk             |\
                                      PCA_CCMR1_CC_Msk             )

#define PCA_CCR0_CCR0L_Pos           0                                            /*!<PCA CCR0: CCR0L Position */
#define PCA_CCR0_CCR0L_Msk           (0xFFUL /*<< PCA_CCR0_CCR0L_Pos*/)           /*!<PCA CCR0: CCR0L Mask */

#define PCA_CCR0_CCR0H_Pos           8                                            /*!<PCA CCR0: CCR0H Position */
#define PCA_CCR0_CCR0H_Msk           (0xFFUL << PCA_CCR0_CCR0H_Pos)               /*!<PCA CCR0: CCR0H Mask */

#define PCA_CCR0_CCR0CAS_Pos         16                                           /*!<PCA CCR0: CCR0CAS Position */
#define PCA_CCR0_CCR0CAS_Msk         (0xFFFFUL << PCA_CCR0_CCR0CAS_Pos)           /*!<PCA CCR0: CCR0CAS Mask */

#define PCA_CCR0_Msk_ALL             (PCA_CCR0_CCR0L_Msk           |\
                                      PCA_CCR0_CCR0H_Msk           |\
                                      PCA_CCR0_CCR0CAS_Msk         )

#define PCA_CCR1_CCR1L_Pos           0                                            /*!<PCA CCR1: CCR1L Position */
#define PCA_CCR1_CCR1L_Msk           (0xFFUL /*<< PCA_CCR1_CCR1L_Pos*/)           /*!<PCA CCR1: CCR1L Mask */

#define PCA_CCR1_CCR1H_Pos           8                                            /*!<PCA CCR1: CCR1H Position */
#define PCA_CCR1_CCR1H_Msk           (0xFFUL << PCA_CCR1_CCR1H_Pos)               /*!<PCA CCR1: CCR1H Mask */

#define PCA_CCR1_CCR1CAS_Pos         16                                           /*!<PCA CCR1: CCR1CAS Position */
#define PCA_CCR1_CCR1CAS_Msk         (0xFFFFUL << PCA_CCR1_CCR1CAS_Pos)           /*!<PCA CCR1: CCR1CAS Mask */

#define PCA_CCR1_Msk_ALL             (PCA_CCR1_CCR1L_Msk           |\
                                      PCA_CCR1_CCR1H_Msk           |\
                                      PCA_CCR1_CCR1CAS_Msk         )

#define PCA_LCKR_KEY_Pos             0                                            /*!<PCA LCKR: KEY Position */
#define PCA_LCKR_KEY_Msk             (0xFFFFUL /*<< PCA_LCKR_KEY_Pos*/)           /*!<PCA LCKR: KEY Mask */

#define PCA_LCKR_Msk_ALL             (PCA_LCKR_KEY_Msk            )

#define UART_FR_RI_Pos               0                                            /*!<UART FR: RI Position */
#define UART_FR_RI_Msk               (0x1UL /*<< UART_FR_RI_Pos*/)                /*!<UART FR: RI Mask */

#define UART_FR_TI_Pos               1                                            /*!<UART FR: TI Position */
#define UART_FR_TI_Msk               (0x1UL << UART_FR_TI_Pos)                    /*!<UART FR: TI Mask */

#define UART_FR_TC_Pos               2                                            /*!<UART FR: TC Position */
#define UART_FR_TC_Msk               (0x1UL << UART_FR_TC_Pos)                    /*!<UART FR: TC Mask */

#define UART_FR_TXCOL_Pos            3                                            /*!<UART FR: TXCOL Position */
#define UART_FR_TXCOL_Msk            (0x1UL << UART_FR_TXCOL_Pos)                 /*!<UART FR: TXCOL Mask */

#define UART_FR_RXOV_Pos             4                                            /*!<UART FR: RXOV Position */
#define UART_FR_RXOV_Msk             (0x1UL << UART_FR_RXOV_Pos)                  /*!<UART FR: RXOV Mask */

#define UART_FR_FE_Pos               5                                            /*!<UART FR: FE Position */
#define UART_FR_FE_Msk               (0x1UL << UART_FR_FE_Pos)                    /*!<UART FR: FE Mask */

#define UART_FR_PE_Pos               6                                            /*!<UART FR: PE Position */
#define UART_FR_PE_Msk               (0x1UL << UART_FR_PE_Pos)                    /*!<UART FR: PE Mask */

#define UART_FR_LBD_Pos              7                                            /*!<UART FR: LBD Position */
#define UART_FR_LBD_Msk              (0x1UL << UART_FR_LBD_Pos)                   /*!<UART FR: LBD Mask */

#define UART_FR_TCC_Pos              18                                           /*!<UART FR: TCC Position */
#define UART_FR_TCC_Msk              (0x1UL << UART_FR_TCC_Pos)                   /*!<UART FR: TCC Mask */

#define UART_FR_TXCOLC_Pos           19                                           /*!<UART FR: TXCOLC Position */
#define UART_FR_TXCOLC_Msk           (0x1UL << UART_FR_TXCOLC_Pos)                /*!<UART FR: TXCOLC Mask */

#define UART_FR_RXOVC_Pos            20                                           /*!<UART FR: RXOVC Position */
#define UART_FR_RXOVC_Msk            (0x1UL << UART_FR_RXOVC_Pos)                 /*!<UART FR: RXOVC Mask */

#define UART_FR_FEC_Pos              21                                           /*!<UART FR: FEC Position */
#define UART_FR_FEC_Msk              (0x1UL << UART_FR_FEC_Pos)                   /*!<UART FR: FEC Mask */

#define UART_FR_PEC_Pos              22                                           /*!<UART FR: PEC Position */
#define UART_FR_PEC_Msk              (0x1UL << UART_FR_PEC_Pos)                   /*!<UART FR: PEC Mask */

#define UART_FR_LBDC_Pos             23                                           /*!<UART FR: LBDC Position */
#define UART_FR_LBDC_Msk             (0x1UL << UART_FR_LBDC_Pos)                  /*!<UART FR: LBDC Mask */

#define UART_FR_Msk_ALL              (UART_FR_RI_Msk               |\
                                      UART_FR_TI_Msk               |\
                                      UART_FR_TC_Msk               |\
                                      UART_FR_TXCOL_Msk            |\
                                      UART_FR_RXOV_Msk             |\
                                      UART_FR_FE_Msk               |\
                                      UART_FR_PE_Msk               |\
                                      UART_FR_LBD_Msk              |\
                                      UART_FR_TCC_Msk              |\
                                      UART_FR_TXCOLC_Msk           |\
                                      UART_FR_RXOVC_Msk            |\
                                      UART_FR_FEC_Msk              |\
                                      UART_FR_PEC_Msk              |\
                                      UART_FR_LBDC_Msk             )

#define UART_TDR_TDR_Pos             0                                            /*!<UART TDR: TDR Position */
#define UART_TDR_TDR_Msk             (0xFFUL /*<< UART_TDR_TDR_Pos*/)             /*!<UART TDR: TDR Mask */

#define UART_TDR_TB8_Pos             8                                            /*!<UART TDR: TB8 Position */
#define UART_TDR_TB8_Msk             (0x1UL << UART_TDR_TB8_Pos)                  /*!<UART TDR: TB8 Mask */

#define UART_TDR_Msk_ALL             (UART_TDR_TDR_Msk             |\
                                      UART_TDR_TB8_Msk             )

#define UART_RDR_RDR_Pos             0                                            /*!<UART RDR: RDR Position */
#define UART_RDR_RDR_Msk             (0xFFUL /*<< UART_RDR_RDR_Pos*/)             /*!<UART RDR: RDR Mask */

#define UART_RDR_RB8_Pos             8                                            /*!<UART RDR: RB8 Position */
#define UART_RDR_RB8_Msk             (0x1UL << UART_RDR_RB8_Pos)                  /*!<UART RDR: RB8 Mask */

#define UART_RDR_Msk_ALL             (UART_RDR_RDR_Msk             |\
                                      UART_RDR_RB8_Msk             )

#define UART_ADDR_SADDR_Pos          0                                            /*!<UART ADDR: SADDR Position */
#define UART_ADDR_SADDR_Msk          (0xFFUL /*<< UART_ADDR_SADDR_Pos*/)          /*!<UART ADDR: SADDR Mask */

#define UART_ADDR_SMAR_Pos           8                                            /*!<UART ADDR: SMAR Position */
#define UART_ADDR_SMAR_Msk           (0xFFUL << UART_ADDR_SMAR_Pos)               /*!<UART ADDR: SMAR Mask */

#define UART_ADDR_Msk_ALL            (UART_ADDR_SADDR_Msk          |\
                                      UART_ADDR_SMAR_Msk           )

#define UART_BRT_SBRT_Pos            0                                            /*!<UART BRT: SBRT Position */
#define UART_BRT_SBRT_Msk            (0x7FFFUL /*<< UART_BRT_SBRT_Pos*/)          /*!<UART BRT: SBRT Mask */

#define UART_BRT_BFINE_Pos           16                                           /*!<UART BRT: BFINE Position */
#define UART_BRT_BFINE_Msk           (0xFUL << UART_BRT_BFINE_Pos)                /*!<UART BRT: BFINE Mask */

#define UART_BRT_Msk_ALL             (UART_BRT_SBRT_Msk            |\
                                      UART_BRT_BFINE_Msk           )

#define UART_CR_STOP_Pos             0                                            /*!<UART CR: STOP Position */
#define UART_CR_STOP_Msk             (0x1UL /*<< UART_CR_STOP_Pos*/)              /*!<UART CR: STOP Mask */

#define UART_CR_SBRTEN_Pos           1                                            /*!<UART CR: SBRTEN Position */
#define UART_CR_SBRTEN_Msk           (0x1UL << UART_CR_SBRTEN_Pos)                /*!<UART CR: SBRTEN Mask */

#define UART_CR_SMOD2_Pos            2                                            /*!<UART CR: SMOD2 Position */
#define UART_CR_SMOD2_Msk            (0x1UL << UART_CR_SMOD2_Pos)                 /*!<UART CR: SMOD2 Mask */

#define UART_CR_RIE_Pos              3                                            /*!<UART CR: RIE Position */
#define UART_CR_RIE_Msk              (0x1UL << UART_CR_RIE_Pos)                   /*!<UART CR: RIE Mask */

#define UART_CR_TIE_Pos              4                                            /*!<UART CR: TIE Position */
#define UART_CR_TIE_Msk              (0x1UL << UART_CR_TIE_Pos)                   /*!<UART CR: TIE Mask */

#define UART_CR_TCIE_Pos             5                                            /*!<UART CR: TCIE Position */
#define UART_CR_TCIE_Msk             (0x1UL << UART_CR_TCIE_Pos)                  /*!<UART CR: TCIE Mask */

#define UART_CR_LBDIE_Pos            6                                            /*!<UART CR: LBDIE Position */
#define UART_CR_LBDIE_Msk            (0x1UL << UART_CR_LBDIE_Pos)                 /*!<UART CR: LBDIE Mask */

#define UART_CR_LBDL_Pos             7                                            /*!<UART CR: LBDL Position */
#define UART_CR_LBDL_Msk             (0x1UL << UART_CR_LBDL_Pos)                  /*!<UART CR: LBDL Mask */

#define UART_CR_SMOD0_Pos            8                                            /*!<UART CR: SMOD0 Position */
#define UART_CR_SMOD0_Msk            (0x1UL << UART_CR_SMOD0_Pos)                 /*!<UART CR: SMOD0 Mask */

#define UART_CR_PS_Pos               10                                           /*!<UART CR: PS Position */
#define UART_CR_PS_Msk               (0x1UL << UART_CR_PS_Pos)                    /*!<UART CR: PS Mask */

#define UART_CR_MULTIE_Pos           11                                           /*!<UART CR: MULTIE Position */
#define UART_CR_MULTIE_Msk           (0x3UL << UART_CR_MULTIE_Pos)                /*!<UART CR: MULTIE Mask */

#define UART_CR_SM_Pos               13                                           /*!<UART CR: SM Position */
#define UART_CR_SM_Msk               (0x3UL << UART_CR_SM_Pos)                    /*!<UART CR: SM Mask */

#define UART_CR_SBK_Pos              15                                           /*!<UART CR: SBK Position */
#define UART_CR_SBK_Msk              (0x1UL << UART_CR_SBK_Pos)                   /*!<UART CR: SBK Mask */

#define UART_CR_LINEN_Pos            16                                           /*!<UART CR: LINEN Position */
#define UART_CR_LINEN_Msk            (0x1UL << UART_CR_LINEN_Pos)                 /*!<UART CR: LINEN Mask */

#define UART_CR_REN_Pos              17                                           /*!<UART CR: REN Position */
#define UART_CR_REN_Msk              (0x1UL << UART_CR_REN_Pos)                   /*!<UART CR: REN Mask */

#define UART_CR_TEN_Pos              18                                           /*!<UART CR: TEN Position */
#define UART_CR_TEN_Msk              (0x1UL << UART_CR_TEN_Pos)                   /*!<UART CR: TEN Mask */

#define UART_CR_DMAR_Pos             19                                           /*!<UART CR: DMAR Position */
#define UART_CR_DMAR_Msk             (0x1UL << UART_CR_DMAR_Pos)                  /*!<UART CR: DMAR Mask */

#define UART_CR_DMAT_Pos             20                                           /*!<UART CR: DMAT Position */
#define UART_CR_DMAT_Msk             (0x1UL << UART_CR_DMAT_Pos)                  /*!<UART CR: DMAT Mask */

#define UART_CR_RNEG_Pos             21                                           /*!<UART CR: RNEG Position */
#define UART_CR_RNEG_Msk             (0x1UL << UART_CR_RNEG_Pos)                  /*!<UART CR: RNEG Mask */

#define UART_CR_TNEG_Pos             22                                           /*!<UART CR: TNEG Position */
#define UART_CR_TNEG_Msk             (0x1UL << UART_CR_TNEG_Pos)                  /*!<UART CR: TNEG Mask */

#define UART_CR_FER_Pos              23                                           /*!<UART CR: FER Position */
#define UART_CR_FER_Msk              (0x1UL << UART_CR_FER_Pos)                   /*!<UART CR: FER Mask */

#define UART_CR_Msk_ALL              (UART_CR_STOP_Msk             |\
                                      UART_CR_SBRTEN_Msk           |\
                                      UART_CR_SMOD2_Msk            |\
                                      UART_CR_RIE_Msk              |\
                                      UART_CR_TIE_Msk              |\
                                      UART_CR_TCIE_Msk             |\
                                      UART_CR_LBDIE_Msk            |\
                                      UART_CR_LBDL_Msk             |\
                                      UART_CR_SMOD0_Msk            |\
                                      UART_CR_PS_Msk               |\
                                      UART_CR_MULTIE_Msk           |\
                                      UART_CR_SM_Msk               |\
                                      UART_CR_SBK_Msk              |\
                                      UART_CR_LINEN_Msk            |\
                                      UART_CR_REN_Msk              |\
                                      UART_CR_TEN_Msk              |\
                                      UART_CR_DMAR_Msk             |\
                                      UART_CR_DMAT_Msk             |\
                                      UART_CR_RNEG_Msk             |\
                                      UART_CR_TNEG_Msk             |\
                                      UART_CR_FER_Msk              )

#define SPI_FR_SPRI_Pos              0                                            /*!<SPI FR: SPRI Position */
#define SPI_FR_SPRI_Msk              (0x1UL /*<< SPI_FR_SPRI_Pos*/)               /*!<SPI FR: SPRI Mask */

#define SPI_FR_SPTI_Pos              1                                            /*!<SPI FR: SPTI Position */
#define SPI_FR_SPTI_Msk              (0x1UL << SPI_FR_SPTI_Pos)                   /*!<SPI FR: SPTI Mask */

#define SPI_FR_BUSY_Pos              2                                            /*!<SPI FR: BUSY Position */
#define SPI_FR_BUSY_Msk              (0x1UL << SPI_FR_BUSY_Pos)                   /*!<SPI FR: BUSY Mask */

#define SPI_FR_MODF_Pos              3                                            /*!<SPI FR: MODF Position */
#define SPI_FR_MODF_Msk              (0x1UL << SPI_FR_MODF_Pos)                   /*!<SPI FR: MODF Mask */

#define SPI_FR_RXOV_Pos              4                                            /*!<SPI FR: RXOV Position */
#define SPI_FR_RXOV_Msk              (0x1UL << SPI_FR_RXOV_Pos)                   /*!<SPI FR: RXOV Mask */

#define SPI_FR_WCOL_Pos              5                                            /*!<SPI FR: WCOL Position */
#define SPI_FR_WCOL_Msk              (0x1UL << SPI_FR_WCOL_Pos)                   /*!<SPI FR: WCOL Mask */

#define SPI_FR_MODFC_Pos             19                                           /*!<SPI FR: MODFC Position */
#define SPI_FR_MODFC_Msk             (0x1UL << SPI_FR_MODFC_Pos)                  /*!<SPI FR: MODFC Mask */

#define SPI_FR_RXOVC_Pos             20                                           /*!<SPI FR: RXOVC Position */
#define SPI_FR_RXOVC_Msk             (0x1UL << SPI_FR_RXOVC_Pos)                  /*!<SPI FR: RXOVC Mask */

#define SPI_FR_WCOLC_Pos             21                                           /*!<SPI FR: WCOLC Position */
#define SPI_FR_WCOLC_Msk             (0x1UL << SPI_FR_WCOLC_Pos)                  /*!<SPI FR: WCOLC Mask */

#define SPI_FR_Msk_ALL               (SPI_FR_SPRI_Msk              |\
                                      SPI_FR_SPTI_Msk              |\
                                      SPI_FR_BUSY_Msk              |\
                                      SPI_FR_MODF_Msk              |\
                                      SPI_FR_RXOV_Msk              |\
                                      SPI_FR_WCOL_Msk              |\
                                      SPI_FR_MODFC_Msk             |\
                                      SPI_FR_RXOVC_Msk             |\
                                      SPI_FR_WCOLC_Msk             )

#define SPI_CR_SPR_Pos               0                                            /*!<SPI CR: SPR Position */
#define SPI_CR_SPR_Msk               (0xFUL /*<< SPI_CR_SPR_Pos*/)                /*!<SPI CR: SPR Mask */

#define SPI_CR_SSDIS_Pos             4                                            /*!<SPI CR: SSDIS Position */
#define SPI_CR_SSDIS_Msk             (0x1UL << SPI_CR_SSDIS_Pos)                  /*!<SPI CR: SSDIS Mask */

#define SPI_CR_CPOL_Pos              5                                            /*!<SPI CR: CPOL Position */
#define SPI_CR_CPOL_Msk              (0x1UL << SPI_CR_CPOL_Pos)                   /*!<SPI CR: CPOL Mask */

#define SPI_CR_CPHA_Pos              6                                            /*!<SPI CR: CPHA Position */
#define SPI_CR_CPHA_Msk              (0x1UL << SPI_CR_CPHA_Pos)                   /*!<SPI CR: CPHA Mask */

#define SPI_CR_MSTR_Pos              7                                            /*!<SPI CR: MSTR Position */
#define SPI_CR_MSTR_Msk              (0x1UL << SPI_CR_MSTR_Pos)                   /*!<SPI CR: MSTR Mask */

#define SPI_CR_DIR_Pos               8                                            /*!<SPI CR: DIR Position */
#define SPI_CR_DIR_Msk               (0x1UL << SPI_CR_DIR_Pos)                    /*!<SPI CR: DIR Mask */

#define SPI_CR_SPRIE_Pos             10                                           /*!<SPI CR: SPRIE Position */
#define SPI_CR_SPRIE_Msk             (0x1UL << SPI_CR_SPRIE_Pos)                  /*!<SPI CR: SPRIE Mask */

#define SPI_CR_SPTIE_Pos             11                                           /*!<SPI CR: SPTIE Position */
#define SPI_CR_SPTIE_Msk             (0x1UL << SPI_CR_SPTIE_Pos)                  /*!<SPI CR: SPTIE Mask */

#define SPI_CR_SPDMAR_Pos            12                                           /*!<SPI CR: SPDMAR Position */
#define SPI_CR_SPDMAR_Msk            (0x1UL << SPI_CR_SPDMAR_Pos)                 /*!<SPI CR: SPDMAR Mask */

#define SPI_CR_SPDMAT_Pos            13                                           /*!<SPI CR: SPDMAT Position */
#define SPI_CR_SPDMAT_Msk            (0x1UL << SPI_CR_SPDMAT_Pos)                 /*!<SPI CR: SPDMAT Mask */

#define SPI_CR_SPIEN_Pos             14                                           /*!<SPI CR: SPIEN Position */
#define SPI_CR_SPIEN_Msk             (0x1UL << SPI_CR_SPIEN_Pos)                  /*!<SPI CR: SPIEN Mask */

#define SPI_CR_SPSFF_Pos             15                                           /*!<SPI CR: SPSFF Position */
#define SPI_CR_SPSFF_Msk             (0x1UL << SPI_CR_SPSFF_Pos)                  /*!<SPI CR: SPSFF Mask */

#define SPI_CR_SPDATL_Pos            16                                           /*!<SPI CR: SPDATL Position */
#define SPI_CR_SPDATL_Msk            (0x3UL << SPI_CR_SPDATL_Pos)                 /*!<SPI CR: SPDATL Mask */

#define SPI_CR_Msk_ALL               (SPI_CR_SPR_Msk               |\
                                      SPI_CR_SSDIS_Msk             |\
                                      SPI_CR_CPOL_Msk              |\
                                      SPI_CR_CPHA_Msk              |\
                                      SPI_CR_MSTR_Msk              |\
                                      SPI_CR_DIR_Msk               |\
                                      SPI_CR_SPRIE_Msk             |\
                                      SPI_CR_SPTIE_Msk             |\
                                      SPI_CR_SPDMAR_Msk            |\
                                      SPI_CR_SPDMAT_Msk            |\
                                      SPI_CR_SPIEN_Msk             |\
                                      SPI_CR_SPSFF_Msk             |\
                                      SPI_CR_SPDATL_Msk            )

#define TWI_FR_TWINT_Pos             0                                            /*!<TWI FR: TWINT Position */
#define TWI_FR_TWINT_Msk             (0x1UL /*<< TWI_FR_TWINT_Pos*/)              /*!<TWI FR: TWINT Mask */

#define TWI_FR_TFREE_Pos             2                                            /*!<TWI FR: TFREE Position */
#define TWI_FR_TFREE_Msk             (0x1UL << TWI_FR_TFREE_Pos)                  /*!<TWI FR: TFREE Mask */

#define TWI_FR_TOUT_Pos              3                                            /*!<TWI FR: TOUT Position */
#define TWI_FR_TOUT_Msk              (0x1UL << TWI_FR_TOUT_Pos)                   /*!<TWI FR: TOUT Mask */

#define TWI_FR_TWINTC_Pos            16                                           /*!<TWI FR: TWINTC Position */
#define TWI_FR_TWINTC_Msk            (0x1UL << TWI_FR_TWINTC_Pos)                 /*!<TWI FR: TWINTC Mask */

#define TWI_FR_TFREEC_Pos            18                                           /*!<TWI FR: TFREEC Position */
#define TWI_FR_TFREEC_Msk            (0x1UL << TWI_FR_TFREEC_Pos)                 /*!<TWI FR: TFREEC Mask */

#define TWI_FR_TOUTC_Pos             19                                           /*!<TWI FR: TOUTC Position */
#define TWI_FR_TOUTC_Msk             (0x1UL << TWI_FR_TOUTC_Pos)                  /*!<TWI FR: TOUTC Mask */

#define TWI_FR_Msk_ALL               (TWI_FR_TWINT_Msk             |\
                                      TWI_FR_TFREE_Msk             |\
                                      TWI_FR_TOUT_Msk              |\
                                      TWI_FR_TWINTC_Msk            |\
                                      TWI_FR_TFREEC_Msk            |\
                                      TWI_FR_TOUTC_Msk             )

#define TWI_STAT_SR_Pos              3                                            /*!<TWI STAT: SR Position */
#define TWI_STAT_SR_Msk              (0x1FUL << TWI_STAT_SR_Pos)                  /*!<TWI STAT: SR Mask */

#define TWI_STAT_Msk_ALL             (TWI_STAT_SR_Msk             )

#define TWI_HOC_HOC_Pos              0                                            /*!<TWI HOC: HOC Position */
#define TWI_HOC_HOC_Msk              (0xFFUL /*<< TWI_HOC_HOC_Pos*/)              /*!<TWI HOC: HOC Mask */

#define TWI_HOC_Msk_ALL              (TWI_HOC_HOC_Msk             )

#define TWI_BRT_BRT_Pos              0                                            /*!<TWI BRT: BRT Position */
#define TWI_BRT_BRT_Msk              (0xFFUL /*<< TWI_BRT_BRT_Pos*/)              /*!<TWI BRT: BRT Mask */

#define TWI_BRT_Msk_ALL              (TWI_BRT_BRT_Msk             )

#define TWI_DR_DR_Pos                0                                            /*!<TWI DR: DR Position */
#define TWI_DR_DR_Msk                (0xFFUL /*<< TWI_DR_DR_Pos*/)                /*!<TWI DR: DR Mask */

#define TWI_DR_Msk_ALL               (TWI_DR_DR_Msk               )

#define TWI_ADDR_GC_Pos              0                                            /*!<TWI ADDR: GC Position */
#define TWI_ADDR_GC_Msk              (0x1UL /*<< TWI_ADDR_GC_Pos*/)               /*!<TWI ADDR: GC Mask */

#define TWI_ADDR_ADDR_Pos            1                                            /*!<TWI ADDR: ADDR Position */
#define TWI_ADDR_ADDR_Msk            (0x7FUL << TWI_ADDR_ADDR_Pos)                /*!<TWI ADDR: ADDR Mask */

#define TWI_ADDR_TWIAMR_Pos          17                                           /*!<TWI ADDR: TWIAMR Position */
#define TWI_ADDR_TWIAMR_Msk          (0x7FUL << TWI_ADDR_TWIAMR_Pos)              /*!<TWI ADDR: TWIAMR Mask */

#define TWI_ADDR_Msk_ALL             (TWI_ADDR_GC_Msk              |\
                                      TWI_ADDR_ADDR_Msk            |\
                                      TWI_ADDR_TWIAMR_Msk          )

#define TWI_CR_AA_Pos                0                                            /*!<TWI CR: AA Position */
#define TWI_CR_AA_Msk                (0x1UL /*<< TWI_CR_AA_Pos*/)                 /*!<TWI CR: AA Mask */

#define TWI_CR_STO_Pos               1                                            /*!<TWI CR: STO Position */
#define TWI_CR_STO_Msk               (0x1UL << TWI_CR_STO_Pos)                    /*!<TWI CR: STO Mask */

#define TWI_CR_STA_Pos               2                                            /*!<TWI CR: STA Position */
#define TWI_CR_STA_Msk               (0x1UL << TWI_CR_STA_Pos)                    /*!<TWI CR: STA Mask */

#define TWI_CR_CR_Pos                4                                            /*!<TWI CR: CR Position */
#define TWI_CR_CR_Msk                (0x3UL << TWI_CR_CR_Pos)                     /*!<TWI CR: CR Mask */

#define TWI_CR_CNT_Pos               6                                            /*!<TWI CR: CNT Position */
#define TWI_CR_CNT_Msk               (0x3UL << TWI_CR_CNT_Pos)                    /*!<TWI CR: CNT Mask */

#define TWI_CR_EFREE_Pos             8                                            /*!<TWI CR: EFREE Position */
#define TWI_CR_EFREE_Msk             (0x1UL << TWI_CR_EFREE_Pos)                  /*!<TWI CR: EFREE Mask */

#define TWI_CR_ETOT_Pos              9                                            /*!<TWI CR: ETOT Position */
#define TWI_CR_ETOT_Msk              (0x1UL << TWI_CR_ETOT_Pos)                   /*!<TWI CR: ETOT Mask */

#define TWI_CR_TWINTE_Pos            10                                           /*!<TWI CR: TWINTE Position */
#define TWI_CR_TWINTE_Msk            (0x1UL << TWI_CR_TWINTE_Pos)                 /*!<TWI CR: TWINTE Mask */

#define TWI_CR_TWIEN_Pos             15                                           /*!<TWI CR: TWIEN Position */
#define TWI_CR_TWIEN_Msk             (0x1UL << TWI_CR_TWIEN_Pos)                  /*!<TWI CR: TWIEN Mask */

#define TWI_CR_Msk_ALL               (TWI_CR_AA_Msk                |\
                                      TWI_CR_STO_Msk               |\
                                      TWI_CR_STA_Msk               |\
                                      TWI_CR_CR_Msk                |\
                                      TWI_CR_CNT_Msk               |\
                                      TWI_CR_EFREE_Msk             |\
                                      TWI_CR_ETOT_Msk              |\
                                      TWI_CR_TWINTE_Msk            |\
                                      TWI_CR_TWIEN_Msk             )

#define ADC_ADCON1_ADSOC_Pos         0                                            /*!<ADC ADCON1: ADSOC Position */
#define ADC_ADCON1_ADSOC_Msk         (0x1UL /*<< ADC_ADCON1_ADSOC_Pos*/)          /*!<ADC ADCON1: ADSOC Mask */

#define ADC_ADCON1_ADCTU_Pos         1                                            /*!<ADC ADCON1: ADCTU Position */
#define ADC_ADCON1_ADCTU_Msk         (0x3UL << ADC_ADCON1_ADCTU_Pos)              /*!<ADC ADCON1: ADCTU Mask */

#define ADC_ADCON1_MOD_Pos           3                                            /*!<ADC ADCON1: MOD Position */
#define ADC_ADCON1_MOD_Msk           (0x1UL << ADC_ADCON1_MOD_Pos)                /*!<ADC ADCON1: MOD Mask */

#define ADC_ADCON1_REFC_Pos          4                                            /*!<ADC ADCON1: REFC Position */
#define ADC_ADCON1_REFC_Msk          (0x3UL << ADC_ADCON1_REFC_Pos)               /*!<ADC ADCON1: REFC Mask */

#define ADC_ADCON1_ADDE_Pos          6                                            /*!<ADC ADCON1: ADDE Position */
#define ADC_ADCON1_ADDE_Msk          (0x1UL << ADC_ADCON1_ADDE_Pos)               /*!<ADC ADCON1: ADDE Mask */

#define ADC_ADCON1_ADIE_Pos          7                                            /*!<ADC ADCON1: ADIE Position */
#define ADC_ADCON1_ADIE_Msk          (0x1UL << ADC_ADCON1_ADIE_Pos)               /*!<ADC ADCON1: ADIE Mask */

#define ADC_ADCON1_ADSTRS_Pos        8                                            /*!<ADC ADCON1: ADSTRS Position */
#define ADC_ADCON1_ADSTRS_Msk        (0x7FUL << ADC_ADCON1_ADSTRS_Pos)            /*!<ADC ADCON1: ADSTRS Mask */

#define ADC_ADCON1_ADON_Pos          15                                           /*!<ADC ADCON1: ADON Position */
#define ADC_ADCON1_ADON_Msk          (0x1UL << ADC_ADCON1_ADON_Pos)               /*!<ADC ADCON1: ADON Mask */

#define ADC_ADCON1_Msk_ALL           (ADC_ADCON1_ADSOC_Msk         |\
                                      ADC_ADCON1_ADCTU_Msk         |\
                                      ADC_ADCON1_MOD_Msk           |\
                                      ADC_ADCON1_REFC_Msk          |\
                                      ADC_ADCON1_ADDE_Msk          |\
                                      ADC_ADCON1_ADIE_Msk          |\
                                      ADC_ADCON1_ADSTRS_Msk        |\
                                      ADC_ADCON1_ADON_Msk          )

#define ADC_ADCON2_TADC_Pos          0                                            /*!<ADC ADCON2: TADC Position */
#define ADC_ADCON2_TADC_Msk          (0xFUL /*<< ADC_ADCON2_TADC_Pos*/)           /*!<ADC ADCON2: TADC Mask */

#define ADC_ADCON2_ADMAXCH_Pos       4                                            /*!<ADC ADCON2: ADMAXCH Position */
#define ADC_ADCON2_ADMAXCH_Msk       (0x7UL << ADC_ADCON2_ADMAXCH_Pos)            /*!<ADC ADCON2: ADMAXCH Mask */

#define ADC_ADCON2_TS_Pos            8                                            /*!<ADC ADCON2: TS Position */
#define ADC_ADCON2_TS_Msk            (0xFUL << ADC_ADCON2_TS_Pos)                 /*!<ADC ADCON2: TS Mask */

#define ADC_ADCON2_TGAP_Pos          16                                           /*!<ADC ADCON2: TGAP Position */
#define ADC_ADCON2_TGAP_Msk          (0x7UL << ADC_ADCON2_TGAP_Pos)               /*!<ADC ADCON2: TGAP Mask */

#define ADC_ADCON2_Msk_ALL           (ADC_ADCON2_TADC_Msk          |\
                                      ADC_ADCON2_ADMAXCH_Msk       |\
                                      ADC_ADCON2_TS_Msk            |\
                                      ADC_ADCON2_TGAP_Msk          )

#define ADC_ADPCH_ADPCH_Pos          0                                            /*!<ADC ADPCH: ADPCH Position */
#define ADC_ADPCH_ADPCH_Msk          (0x7UL /*<< ADC_ADPCH_ADPCH_Pos*/)           /*!<ADC ADPCH: ADPCH Mask */

#define ADC_ADPCH_Msk_ALL            (ADC_ADPCH_ADPCH_Msk         )

#define ADC_ADDR0_ADDR0_Pos          0                                            /*!<ADC ADDR0: ADDR0 Position */
#define ADC_ADDR0_ADDR0_Msk          (0xFFFFUL /*<< ADC_ADDR0_ADDR0_Pos*/)        /*!<ADC ADDR0: ADDR0 Mask */

#define ADC_ADDR0_Msk_ALL            (ADC_ADDR0_ADDR0_Msk         )

#define ADC_ADDR1_ADDR1_Pos          0                                            /*!<ADC ADDR1: ADDR1 Position */
#define ADC_ADDR1_ADDR1_Msk          (0xFFFFUL /*<< ADC_ADDR1_ADDR1_Pos*/)        /*!<ADC ADDR1: ADDR1 Mask */

#define ADC_ADDR1_Msk_ALL            (ADC_ADDR1_ADDR1_Msk         )

#define ADC_ADDR2_ADDR2_Pos          0                                            /*!<ADC ADDR2: ADDR2 Position */
#define ADC_ADDR2_ADDR2_Msk          (0xFFFFUL /*<< ADC_ADDR2_ADDR2_Pos*/)        /*!<ADC ADDR2: ADDR2 Mask */

#define ADC_ADDR2_Msk_ALL            (ADC_ADDR2_ADDR2_Msk         )

#define ADC_ADDR3_ADDR3_Pos          0                                            /*!<ADC ADDR3: ADDR3 Position */
#define ADC_ADDR3_ADDR3_Msk          (0xFFFFUL /*<< ADC_ADDR3_ADDR3_Pos*/)        /*!<ADC ADDR3: ADDR3 Mask */

#define ADC_ADDR3_Msk_ALL            (ADC_ADDR3_ADDR3_Msk         )

#define ADC_ADDR4_ADDR4_Pos          0                                            /*!<ADC ADDR4: ADDR4 Position */
#define ADC_ADDR4_ADDR4_Msk          (0xFFFFUL /*<< ADC_ADDR4_ADDR4_Pos*/)        /*!<ADC ADDR4: ADDR4 Mask */

#define ADC_ADDR4_Msk_ALL            (ADC_ADDR4_ADDR4_Msk         )

#define ADC_ADDR5_ADDR5_Pos          0                                            /*!<ADC ADDR5: ADDR5 Position */
#define ADC_ADDR5_ADDR5_Msk          (0xFFFFUL /*<< ADC_ADDR5_ADDR5_Pos*/)        /*!<ADC ADDR5: ADDR5 Mask */

#define ADC_ADDR5_Msk_ALL            (ADC_ADDR5_ADDR5_Msk         )

#define ADC_ADDR6_ADDR6_Pos          0                                            /*!<ADC ADDR6: ADDR6 Position */
#define ADC_ADDR6_ADDR6_Msk          (0xFFFFUL /*<< ADC_ADDR6_ADDR6_Pos*/)        /*!<ADC ADDR6: ADDR6 Mask */

#define ADC_ADDR6_Msk_ALL            (ADC_ADDR6_ADDR6_Msk         )

#define ADC_ADDR7_ADDR7_Pos          0                                            /*!<ADC ADDR7: ADDR7 Position */
#define ADC_ADDR7_ADDR7_Msk          (0xFFFFUL /*<< ADC_ADDR7_ADDR7_Pos*/)        /*!<ADC ADDR7: ADDR7 Mask */

#define ADC_ADDR7_Msk_ALL            (ADC_ADDR7_ADDR7_Msk         )

#define ADC_ADCMPCON_CSEL_Pos        0                                            /*!<ADC ADCMPCON: CSEL Position */
#define ADC_ADCMPCON_CSEL_Msk        (0x7UL /*<< ADC_ADCMPCON_CSEL_Pos*/)         /*!<ADC ADCMPCON: CSEL Mask */

#define ADC_ADCMPCON_ADLDE_Pos       4                                            /*!<ADC ADCMPCON: ADLDE Position */
#define ADC_ADCMPCON_ADLDE_Msk       (0x1UL << ADC_ADCMPCON_ADLDE_Pos)            /*!<ADC ADCMPCON: ADLDE Mask */

#define ADC_ADCMPCON_ADLIE_Pos       5                                            /*!<ADC ADCMPCON: ADLIE Position */
#define ADC_ADCMPCON_ADLIE_Msk       (0x1UL << ADC_ADCMPCON_ADLIE_Pos)            /*!<ADC ADCMPCON: ADLIE Mask */

#define ADC_ADCMPCON_ADGDE_Pos       6                                            /*!<ADC ADCMPCON: ADGDE Position */
#define ADC_ADCMPCON_ADGDE_Msk       (0x1UL << ADC_ADCMPCON_ADGDE_Pos)            /*!<ADC ADCMPCON: ADGDE Mask */

#define ADC_ADCMPCON_ADGIE_Pos       7                                            /*!<ADC ADCMPCON: ADGIE Position */
#define ADC_ADCMPCON_ADGIE_Msk       (0x1UL << ADC_ADCMPCON_ADGIE_Pos)            /*!<ADC ADCMPCON: ADGIE Mask */

#define ADC_ADCMPCON_Msk_ALL         (ADC_ADCMPCON_CSEL_Msk        |\
                                      ADC_ADCMPCON_ADLDE_Msk       |\
                                      ADC_ADCMPCON_ADLIE_Msk       |\
                                      ADC_ADCMPCON_ADGDE_Msk       |\
                                      ADC_ADCMPCON_ADGIE_Msk       )

#define ADC_ADDGT_GT_Pos             0                                            /*!<ADC ADDGT: GT Position */
#define ADC_ADDGT_GT_Msk             (0xFFFFUL /*<< ADC_ADDGT_GT_Pos*/)           /*!<ADC ADDGT: GT Mask */

#define ADC_ADDGT_Msk_ALL            (ADC_ADDGT_GT_Msk            )

#define ADC_ADDLT_LT_Pos             0                                            /*!<ADC ADDLT: LT Position */
#define ADC_ADDLT_LT_Msk             (0xFFFFUL /*<< ADC_ADDLT_LT_Pos*/)           /*!<ADC ADDLT: LT Mask */

#define ADC_ADDLT_Msk_ALL            (ADC_ADDLT_LT_Msk            )

#define ADC_SEQCHSEL0_SEQCH0_Pos     0                                            /*!<ADC SEQCHSEL0: SEQCH0 Position */
#define ADC_SEQCHSEL0_SEQCH0_Msk     (0x1FUL /*<< ADC_SEQCHSEL0_SEQCH0_Pos*/)     /*!<ADC SEQCHSEL0: SEQCH0 Mask */

#define ADC_SEQCHSEL0_SEQCH1_Pos     8                                            /*!<ADC SEQCHSEL0: SEQCH1 Position */
#define ADC_SEQCHSEL0_SEQCH1_Msk     (0x1FUL << ADC_SEQCHSEL0_SEQCH1_Pos)         /*!<ADC SEQCHSEL0: SEQCH1 Mask */

#define ADC_SEQCHSEL0_SEQCH2_Pos     16                                           /*!<ADC SEQCHSEL0: SEQCH2 Position */
#define ADC_SEQCHSEL0_SEQCH2_Msk     (0x1FUL << ADC_SEQCHSEL0_SEQCH2_Pos)         /*!<ADC SEQCHSEL0: SEQCH2 Mask */

#define ADC_SEQCHSEL0_SEQCH3_Pos     24                                           /*!<ADC SEQCHSEL0: SEQCH3 Position */
#define ADC_SEQCHSEL0_SEQCH3_Msk     (0x1FUL << ADC_SEQCHSEL0_SEQCH3_Pos)         /*!<ADC SEQCHSEL0: SEQCH3 Mask */

#define ADC_SEQCHSEL0_Msk_ALL        (ADC_SEQCHSEL0_SEQCH0_Msk     |\
                                      ADC_SEQCHSEL0_SEQCH1_Msk     |\
                                      ADC_SEQCHSEL0_SEQCH2_Msk     |\
                                      ADC_SEQCHSEL0_SEQCH3_Msk     )

#define ADC_SEQCHSEL1_SEQCH4_Pos     0                                            /*!<ADC SEQCHSEL1: SEQCH4 Position */
#define ADC_SEQCHSEL1_SEQCH4_Msk     (0x1FUL /*<< ADC_SEQCHSEL1_SEQCH4_Pos*/)     /*!<ADC SEQCHSEL1: SEQCH4 Mask */

#define ADC_SEQCHSEL1_SEQCH5_Pos     8                                            /*!<ADC SEQCHSEL1: SEQCH5 Position */
#define ADC_SEQCHSEL1_SEQCH5_Msk     (0x1FUL << ADC_SEQCHSEL1_SEQCH5_Pos)         /*!<ADC SEQCHSEL1: SEQCH5 Mask */

#define ADC_SEQCHSEL1_SEQCH6_Pos     16                                           /*!<ADC SEQCHSEL1: SEQCH6 Position */
#define ADC_SEQCHSEL1_SEQCH6_Msk     (0x1FUL << ADC_SEQCHSEL1_SEQCH6_Pos)         /*!<ADC SEQCHSEL1: SEQCH6 Mask */

#define ADC_SEQCHSEL1_SEQCH7_Pos     24                                           /*!<ADC SEQCHSEL1: SEQCH7 Position */
#define ADC_SEQCHSEL1_SEQCH7_Msk     (0x1FUL << ADC_SEQCHSEL1_SEQCH7_Pos)         /*!<ADC SEQCHSEL1: SEQCH7 Mask */

#define ADC_SEQCHSEL1_Msk_ALL        (ADC_SEQCHSEL1_SEQCH4_Msk     |\
                                      ADC_SEQCHSEL1_SEQCH5_Msk     |\
                                      ADC_SEQCHSEL1_SEQCH6_Msk     |\
                                      ADC_SEQCHSEL1_SEQCH7_Msk     )

#define ADC_ADGAPON_GAPEN_Pos        0                                            /*!<ADC ADGAPON: GAPEN Position */
#define ADC_ADGAPON_GAPEN_Msk        (0xFFUL /*<< ADC_ADGAPON_GAPEN_Pos*/)        /*!<ADC ADGAPON: GAPEN Mask */

#define ADC_ADGAPON_Msk_ALL          (ADC_ADGAPON_GAPEN_Msk       )

#define ADC_ADINTF_ADLIF_Pos         0                                            /*!<ADC ADINTF: ADLIF Position */
#define ADC_ADINTF_ADLIF_Msk         (0x1UL /*<< ADC_ADINTF_ADLIF_Pos*/)          /*!<ADC ADINTF: ADLIF Mask */

#define ADC_ADINTF_ADGIF_Pos         1                                            /*!<ADC ADINTF: ADGIF Position */
#define ADC_ADINTF_ADGIF_Msk         (0x1UL << ADC_ADINTF_ADGIF_Pos)              /*!<ADC ADINTF: ADGIF Mask */

#define ADC_ADINTF_ADIF_Pos          2                                            /*!<ADC ADINTF: ADIF Position */
#define ADC_ADINTF_ADIF_Msk          (0x1UL << ADC_ADINTF_ADIF_Pos)               /*!<ADC ADINTF: ADIF Mask */

#define ADC_ADINTF_ADLIFC_Pos        16                                           /*!<ADC ADINTF: ADLIFC Position */
#define ADC_ADINTF_ADLIFC_Msk        (0x1UL << ADC_ADINTF_ADLIFC_Pos)             /*!<ADC ADINTF: ADLIFC Mask */

#define ADC_ADINTF_ADGIFC_Pos        17                                           /*!<ADC ADINTF: ADGIFC Position */
#define ADC_ADINTF_ADGIFC_Msk        (0x1UL << ADC_ADINTF_ADGIFC_Pos)             /*!<ADC ADINTF: ADGIFC Mask */

#define ADC_ADINTF_ADIFC_Pos         18                                           /*!<ADC ADINTF: ADIFC Position */
#define ADC_ADINTF_ADIFC_Msk         (0x1UL << ADC_ADINTF_ADIFC_Pos)              /*!<ADC ADINTF: ADIFC Mask */

#define ADC_ADINTF_Msk_ALL           (ADC_ADINTF_ADLIF_Msk         |\
                                      ADC_ADINTF_ADGIF_Msk         |\
                                      ADC_ADINTF_ADIF_Msk          |\
                                      ADC_ADINTF_ADLIFC_Msk        |\
                                      ADC_ADINTF_ADGIFC_Msk        |\
                                      ADC_ADINTF_ADIFC_Msk         )

#define HLV_CR_ADDR_Pos              0                                            /*!<HLV CR: ADDR Position */
#define HLV_CR_ADDR_Msk              (0x7UL /*<< HLV_CR_ADDR_Pos*/)               /*!<HLV CR: ADDR Mask */

#define HLV_CR_RW_Pos                3                                            /*!<HLV CR: RW Position */
#define HLV_CR_RW_Msk                (0x1UL << HLV_CR_RW_Pos)                     /*!<HLV CR: RW Mask */

#define HLV_CR_START_Pos             4                                            /*!<HLV CR: START Position */
#define HLV_CR_START_Msk             (0x1UL << HLV_CR_START_Pos)                  /*!<HLV CR: START Mask */

#define HLV_CR_HLVEN_Pos             5                                            /*!<HLV CR: HLVEN Position */
#define HLV_CR_HLVEN_Msk             (0x1UL << HLV_CR_HLVEN_Pos)                  /*!<HLV CR: HLVEN Mask */

#define HLV_CR_EHLV_Pos              6                                            /*!<HLV CR: EHLV Position */
#define HLV_CR_EHLV_Msk              (0x1UL << HLV_CR_EHLV_Pos)                   /*!<HLV CR: EHLV Mask */

#define HLV_CR_HLVCK_Pos             8                                            /*!<HLV CR: HLVCK Position */
#define HLV_CR_HLVCK_Msk             (0x7UL << HLV_CR_HLVCK_Pos)                  /*!<HLV CR: HLVCK Mask */

#define HLV_CR_Msk_ALL               (HLV_CR_ADDR_Msk              |\
                                      HLV_CR_RW_Msk                |\
                                      HLV_CR_START_Msk             |\
                                      HLV_CR_HLVEN_Msk             |\
                                      HLV_CR_EHLV_Msk              |\
                                      HLV_CR_HLVCK_Msk             )

#define HLV_DR_DAT_Pos               0                                            /*!<HLV DR: DAT Position */
#define HLV_DR_DAT_Msk               (0xFFUL /*<< HLV_DR_DAT_Pos*/)               /*!<HLV DR: DAT Mask */

#define HLV_DR_Msk_ALL               (HLV_DR_DAT_Msk              )

#define HLV_FR_HLVIF_Pos             0                                            /*!<HLV FR: HLVIF Position */
#define HLV_FR_HLVIF_Msk             (0x1UL /*<< HLV_FR_HLVIF_Pos*/)              /*!<HLV FR: HLVIF Mask */

#define HLV_FR_ERRF_Pos              1                                            /*!<HLV FR: ERRF Position */
#define HLV_FR_ERRF_Msk              (0x1UL << HLV_FR_ERRF_Pos)                   /*!<HLV FR: ERRF Mask */

#define HLV_FR_HLVIFC_Pos            16                                           /*!<HLV FR: HLVIFC Position */
#define HLV_FR_HLVIFC_Msk            (0x1UL << HLV_FR_HLVIFC_Pos)                 /*!<HLV FR: HLVIFC Mask */

#define HLV_FR_ERRFC_Pos             17                                           /*!<HLV FR: ERRFC Position */
#define HLV_FR_ERRFC_Msk             (0x1UL << HLV_FR_ERRFC_Pos)                  /*!<HLV FR: ERRFC Mask */

#define HLV_FR_Msk_ALL               (HLV_FR_HLVIF_Msk             |\
                                      HLV_FR_ERRF_Msk              |\
                                      HLV_FR_HLVIFC_Msk            |\
                                      HLV_FR_ERRFC_Msk             )

#define TOUCHKEY_CR_TKCON_Pos        0                                            /*!<TOUCHKEY CR: TKCON Position */
#define TOUCHKEY_CR_TKCON_Msk        (0x1UL /*<< TOUCHKEY_CR_TKCON_Pos*/)         /*!<TOUCHKEY CR: TKCON Mask */

#define TOUCHKEY_CR_TKGO_DONE_Pos    1                                            /*!<TOUCHKEY CR: TKGO_DONE Position */
#define TOUCHKEY_CR_TKGO_DONE_Msk    (0x1UL << TOUCHKEY_CR_TKGO_DONE_Pos)         /*!<TOUCHKEY CR: TKGO_DONE Mask */

#define TOUCHKEY_CR_FSW_Pos          4                                            /*!<TOUCHKEY CR: FSW Position */
#define TOUCHKEY_CR_FSW_Msk          (0x7UL << TOUCHKEY_CR_FSW_Pos)               /*!<TOUCHKEY CR: FSW Mask */

#define TOUCHKEY_CR_TKCLKS_Pos       7                                            /*!<TOUCHKEY CR: TKCLKS Position */
#define TOUCHKEY_CR_TKCLKS_Msk       (0x3UL << TOUCHKEY_CR_TKCLKS_Pos)            /*!<TOUCHKEY CR: TKCLKS Mask */

#define TOUCHKEY_CR_Tstep_Pos        9                                            /*!<TOUCHKEY CR: Tstep Position */
#define TOUCHKEY_CR_Tstep_Msk        (0x3UL << TOUCHKEY_CR_Tstep_Pos)             /*!<TOUCHKEY CR: Tstep Mask */

#define TOUCHKEY_CR_TKMODE_Pos       11                                           /*!<TOUCHKEY CR: TKMODE Position */
#define TOUCHKEY_CR_TKMODE_Msk       (0x3UL << TOUCHKEY_CR_TKMODE_Pos)            /*!<TOUCHKEY CR: TKMODE Mask */

#define TOUCHKEY_CR_TKCC_Pos         13                                           /*!<TOUCHKEY CR: TKCC Position */
#define TOUCHKEY_CR_TKCC_Msk         (0x7UL << TOUCHKEY_CR_TKCC_Pos)              /*!<TOUCHKEY CR: TKCC Mask */

#define TOUCHKEY_CR_TKADCT_Pos       16                                           /*!<TOUCHKEY CR: TKADCT Position */
#define TOUCHKEY_CR_TKADCT_Msk       (0x3FUL << TOUCHKEY_CR_TKADCT_Pos)           /*!<TOUCHKEY CR: TKADCT Mask */

#define TOUCHKEY_CR_IE_Pos           22                                           /*!<TOUCHKEY CR: IE Position */
#define TOUCHKEY_CR_IE_Msk           (0x1UL << TOUCHKEY_CR_IE_Pos)                /*!<TOUCHKEY CR: IE Mask */

#define TOUCHKEY_CR_TKDMA_Pos        23                                           /*!<TOUCHKEY CR: TKDMA Position */
#define TOUCHKEY_CR_TKDMA_Msk        (0x1UL << TOUCHKEY_CR_TKDMA_Pos)             /*!<TOUCHKEY CR: TKDMA Mask */

#define TOUCHKEY_CR_Msk_ALL          (TOUCHKEY_CR_TKCON_Msk        |\
                                      TOUCHKEY_CR_TKGO_DONE_Msk    |\
                                      TOUCHKEY_CR_FSW_Msk          |\
                                      TOUCHKEY_CR_TKCLKS_Msk       |\
                                      TOUCHKEY_CR_Tstep_Msk        |\
                                      TOUCHKEY_CR_TKMODE_Msk       |\
                                      TOUCHKEY_CR_TKCC_Msk         |\
                                      TOUCHKEY_CR_TKADCT_Msk       |\
                                      TOUCHKEY_CR_IE_Msk           |\
                                      TOUCHKEY_CR_TKDMA_Msk        )

#define TOUCHKEY_CR1_RANDOM_Pos      0                                            /*!<TOUCHKEY CR1: RANDOM Position */
#define TOUCHKEY_CR1_RANDOM_Msk      (0xFUL /*<< TOUCHKEY_CR1_RANDOM_Pos*/)       /*!<TOUCHKEY CR1: RANDOM Mask */

#define TOUCHKEY_CR1_SPSPNum_Pos     4                                            /*!<TOUCHKEY CR1: SPSPNum Position */
#define TOUCHKEY_CR1_SPSPNum_Msk     (0x3UL << TOUCHKEY_CR1_SPSPNum_Pos)          /*!<TOUCHKEY CR1: SPSPNum Mask */

#define TOUCHKEY_CR1_TKFUN_Pos       6                                            /*!<TOUCHKEY CR1: TKFUN Position */
#define TOUCHKEY_CR1_TKFUN_Msk       (0x3UL << TOUCHKEY_CR1_TKFUN_Pos)            /*!<TOUCHKEY CR1: TKFUN Mask */

#define TOUCHKEY_CR1_TKCF_Pos        8                                            /*!<TOUCHKEY CR1: TKCF Position */
#define TOUCHKEY_CR1_TKCF_Msk        (0x1FFUL << TOUCHKEY_CR1_TKCF_Pos)           /*!<TOUCHKEY CR1: TKCF Mask */

#define TOUCHKEY_CR1_TKRX_Pos        17                                           /*!<TOUCHKEY CR1: TKRX Position */
#define TOUCHKEY_CR1_TKRX_Msk        (0x3UL << TOUCHKEY_CR1_TKRX_Pos)             /*!<TOUCHKEY CR1: TKRX Mask */

#define TOUCHKEY_CR1_TKRS_Pos        19                                           /*!<TOUCHKEY CR1: TKRS Position */
#define TOUCHKEY_CR1_TKRS_Msk        (0x3UL << TOUCHKEY_CR1_TKRS_Pos)             /*!<TOUCHKEY CR1: TKRS Mask */

#define TOUCHKEY_CR1_ENFING_Pos      21                                           /*!<TOUCHKEY CR1: ENFING Position */
#define TOUCHKEY_CR1_ENFING_Msk      (0x1UL << TOUCHKEY_CR1_ENFING_Pos)           /*!<TOUCHKEY CR1: ENFING Mask */

#define TOUCHKEY_CR1_ENCREF_Pos      22                                           /*!<TOUCHKEY CR1: ENCREF Position */
#define TOUCHKEY_CR1_ENCREF_Msk      (0x1UL << TOUCHKEY_CR1_ENCREF_Pos)           /*!<TOUCHKEY CR1: ENCREF Mask */

#define TOUCHKEY_CR1_Msk_ALL         (TOUCHKEY_CR1_RANDOM_Msk      |\
                                      TOUCHKEY_CR1_SPSPNum_Msk     |\
                                      TOUCHKEY_CR1_TKFUN_Msk       |\
                                      TOUCHKEY_CR1_TKCF_Msk        |\
                                      TOUCHKEY_CR1_TKRX_Msk        |\
                                      TOUCHKEY_CR1_TKRS_Msk        |\
                                      TOUCHKEY_CR1_ENFING_Msk      |\
                                      TOUCHKEY_CR1_ENCREF_Msk      )

#define TOUCHKEY_FR_IFAVE_Pos        0                                            /*!<TOUCHKEY FR: IFAVE Position */
#define TOUCHKEY_FR_IFAVE_Msk        (0x1UL /*<< TOUCHKEY_FR_IFAVE_Pos*/)         /*!<TOUCHKEY FR: IFAVE Mask */

#define TOUCHKEY_FR_IFAVEC_Pos       16                                           /*!<TOUCHKEY FR: IFAVEC Position */
#define TOUCHKEY_FR_IFAVEC_Msk       (0x1UL << TOUCHKEY_FR_IFAVEC_Pos)            /*!<TOUCHKEY FR: IFAVEC Mask */

#define TOUCHKEY_FR_Msk_ALL          (TOUCHKEY_FR_IFAVE_Msk        |\
                                      TOUCHKEY_FR_IFAVEC_Msk       )

#define TOUCHKEY_TSL_TKSTEP1_Pos     0                                            /*!<TOUCHKEY TSL: TKSTEP1 Position */
#define TOUCHKEY_TSL_TKSTEP1_Msk     (0xFFUL /*<< TOUCHKEY_TSL_TKSTEP1_Pos*/)     /*!<TOUCHKEY TSL: TKSTEP1 Mask */

#define TOUCHKEY_TSL_TKSTEP2_Pos     8                                            /*!<TOUCHKEY TSL: TKSTEP2 Position */
#define TOUCHKEY_TSL_TKSTEP2_Msk     (0xFFUL << TOUCHKEY_TSL_TKSTEP2_Pos)         /*!<TOUCHKEY TSL: TKSTEP2 Mask */

#define TOUCHKEY_TSL_TKSTEP3_Pos     16                                           /*!<TOUCHKEY TSL: TKSTEP3 Position */
#define TOUCHKEY_TSL_TKSTEP3_Msk     (0xFFUL << TOUCHKEY_TSL_TKSTEP3_Pos)         /*!<TOUCHKEY TSL: TKSTEP3 Mask */

#define TOUCHKEY_TSL_TKSTEP4_Pos     24                                           /*!<TOUCHKEY TSL: TKSTEP4 Position */
#define TOUCHKEY_TSL_TKSTEP4_Msk     (0xFFUL << TOUCHKEY_TSL_TKSTEP4_Pos)         /*!<TOUCHKEY TSL: TKSTEP4 Mask */

#define TOUCHKEY_TSL_Msk_ALL         (TOUCHKEY_TSL_TKSTEP1_Msk     |\
                                      TOUCHKEY_TSL_TKSTEP2_Msk     |\
                                      TOUCHKEY_TSL_TKSTEP3_Msk     |\
                                      TOUCHKEY_TSL_TKSTEP4_Msk     )

#define TOUCHKEY_TSH_TKSTEP5_Pos     0                                            /*!<TOUCHKEY TSH: TKSTEP5 Position */
#define TOUCHKEY_TSH_TKSTEP5_Msk     (0xFFUL /*<< TOUCHKEY_TSH_TKSTEP5_Pos*/)     /*!<TOUCHKEY TSH: TKSTEP5 Mask */

#define TOUCHKEY_TSH_TKSTEP6_Pos     8                                            /*!<TOUCHKEY TSH: TKSTEP6 Position */
#define TOUCHKEY_TSH_TKSTEP6_Msk     (0xFFUL << TOUCHKEY_TSH_TKSTEP6_Pos)         /*!<TOUCHKEY TSH: TKSTEP6 Mask */

#define TOUCHKEY_TSH_TKSTEP7_Pos     16                                           /*!<TOUCHKEY TSH: TKSTEP7 Position */
#define TOUCHKEY_TSH_TKSTEP7_Msk     (0xFFUL << TOUCHKEY_TSH_TKSTEP7_Pos)         /*!<TOUCHKEY TSH: TKSTEP7 Mask */

#define TOUCHKEY_TSH_Msk_ALL         (TOUCHKEY_TSH_TKSTEP5_Msk     |\
                                      TOUCHKEY_TSH_TKSTEP6_Msk     |\
                                      TOUCHKEY_TSH_TKSTEP7_Msk     )

#define TOUCHKEY_TC0_TKCADJ00_Pos    0                                            /*!<TOUCHKEY TC0: TKCADJ00 Position */
#define TOUCHKEY_TC0_TKCADJ00_Msk    (0x7FFUL /*<< TOUCHKEY_TC0_TKCADJ00_Pos*/)   /*!<TOUCHKEY TC0: TKCADJ00 Mask */

#define TOUCHKEY_TC0_TKCADJ01_Pos    16                                           /*!<TOUCHKEY TC0: TKCADJ01 Position */
#define TOUCHKEY_TC0_TKCADJ01_Msk    (0x7FFUL << TOUCHKEY_TC0_TKCADJ01_Pos)       /*!<TOUCHKEY TC0: TKCADJ01 Mask */

#define TOUCHKEY_TC0_Msk_ALL         (TOUCHKEY_TC0_TKCADJ00_Msk    |\
                                      TOUCHKEY_TC0_TKCADJ01_Msk    )

#define TOUCHKEY_TC1_TKCADJ02_Pos    0                                            /*!<TOUCHKEY TC1: TKCADJ02 Position */
#define TOUCHKEY_TC1_TKCADJ02_Msk    (0x7FFUL /*<< TOUCHKEY_TC1_TKCADJ02_Pos*/)   /*!<TOUCHKEY TC1: TKCADJ02 Mask */

#define TOUCHKEY_TC1_TKCADJ03_Pos    16                                           /*!<TOUCHKEY TC1: TKCADJ03 Position */
#define TOUCHKEY_TC1_TKCADJ03_Msk    (0x7FFUL << TOUCHKEY_TC1_TKCADJ03_Pos)       /*!<TOUCHKEY TC1: TKCADJ03 Mask */

#define TOUCHKEY_TC1_Msk_ALL         (TOUCHKEY_TC1_TKCADJ02_Msk    |\
                                      TOUCHKEY_TC1_TKCADJ03_Msk    )

#define TOUCHKEY_TC2_TKCADJ04_Pos    0                                            /*!<TOUCHKEY TC2: TKCADJ04 Position */
#define TOUCHKEY_TC2_TKCADJ04_Msk    (0x7FFUL /*<< TOUCHKEY_TC2_TKCADJ04_Pos*/)   /*!<TOUCHKEY TC2: TKCADJ04 Mask */

#define TOUCHKEY_TC2_TKCADJ05_Pos    16                                           /*!<TOUCHKEY TC2: TKCADJ05 Position */
#define TOUCHKEY_TC2_TKCADJ05_Msk    (0x7FFUL << TOUCHKEY_TC2_TKCADJ05_Pos)       /*!<TOUCHKEY TC2: TKCADJ05 Mask */

#define TOUCHKEY_TC2_Msk_ALL         (TOUCHKEY_TC2_TKCADJ04_Msk    |\
                                      TOUCHKEY_TC2_TKCADJ05_Msk    )

#define TOUCHKEY_TC3_TKCADJ06_Pos    0                                            /*!<TOUCHKEY TC3: TKCADJ06 Position */
#define TOUCHKEY_TC3_TKCADJ06_Msk    (0x7FFUL /*<< TOUCHKEY_TC3_TKCADJ06_Pos*/)   /*!<TOUCHKEY TC3: TKCADJ06 Mask */

#define TOUCHKEY_TC3_TKCADJ07_Pos    16                                           /*!<TOUCHKEY TC3: TKCADJ07 Position */
#define TOUCHKEY_TC3_TKCADJ07_Msk    (0x7FFUL << TOUCHKEY_TC3_TKCADJ07_Pos)       /*!<TOUCHKEY TC3: TKCADJ07 Mask */

#define TOUCHKEY_TC3_Msk_ALL         (TOUCHKEY_TC3_TKCADJ06_Msk    |\
                                      TOUCHKEY_TC3_TKCADJ07_Msk    )

#define TOUCHKEY_TC4_TKCADJ08_Pos    0                                            /*!<TOUCHKEY TC4: TKCADJ08 Position */
#define TOUCHKEY_TC4_TKCADJ08_Msk    (0x7FFUL /*<< TOUCHKEY_TC4_TKCADJ08_Pos*/)   /*!<TOUCHKEY TC4: TKCADJ08 Mask */

#define TOUCHKEY_TC4_TKCADJ09_Pos    16                                           /*!<TOUCHKEY TC4: TKCADJ09 Position */
#define TOUCHKEY_TC4_TKCADJ09_Msk    (0x7FFUL << TOUCHKEY_TC4_TKCADJ09_Pos)       /*!<TOUCHKEY TC4: TKCADJ09 Mask */

#define TOUCHKEY_TC4_Msk_ALL         (TOUCHKEY_TC4_TKCADJ08_Msk    |\
                                      TOUCHKEY_TC4_TKCADJ09_Msk    )

#define TOUCHKEY_TC5_TKCADJ10_Pos    0                                            /*!<TOUCHKEY TC5: TKCADJ10 Position */
#define TOUCHKEY_TC5_TKCADJ10_Msk    (0x7FFUL /*<< TOUCHKEY_TC5_TKCADJ10_Pos*/)   /*!<TOUCHKEY TC5: TKCADJ10 Mask */

#define TOUCHKEY_TC5_TKCADJ11_Pos    16                                           /*!<TOUCHKEY TC5: TKCADJ11 Position */
#define TOUCHKEY_TC5_TKCADJ11_Msk    (0x7FFUL << TOUCHKEY_TC5_TKCADJ11_Pos)       /*!<TOUCHKEY TC5: TKCADJ11 Mask */

#define TOUCHKEY_TC5_Msk_ALL         (TOUCHKEY_TC5_TKCADJ10_Msk    |\
                                      TOUCHKEY_TC5_TKCADJ11_Msk    )

#define TOUCHKEY_TC6_TKCADJ12_Pos    0                                            /*!<TOUCHKEY TC6: TKCADJ12 Position */
#define TOUCHKEY_TC6_TKCADJ12_Msk    (0x7FFUL /*<< TOUCHKEY_TC6_TKCADJ12_Pos*/)   /*!<TOUCHKEY TC6: TKCADJ12 Mask */

#define TOUCHKEY_TC6_TKCADJ13_Pos    16                                           /*!<TOUCHKEY TC6: TKCADJ13 Position */
#define TOUCHKEY_TC6_TKCADJ13_Msk    (0x7FFUL << TOUCHKEY_TC6_TKCADJ13_Pos)       /*!<TOUCHKEY TC6: TKCADJ13 Mask */

#define TOUCHKEY_TC6_Msk_ALL         (TOUCHKEY_TC6_TKCADJ12_Msk    |\
                                      TOUCHKEY_TC6_TKCADJ13_Msk    )

#define TOUCHKEY_TC7_TKCADJ14_Pos    0                                            /*!<TOUCHKEY TC7: TKCADJ14 Position */
#define TOUCHKEY_TC7_TKCADJ14_Msk    (0x7FFUL /*<< TOUCHKEY_TC7_TKCADJ14_Pos*/)   /*!<TOUCHKEY TC7: TKCADJ14 Mask */

#define TOUCHKEY_TC7_TKCADJ15_Pos    16                                           /*!<TOUCHKEY TC7: TKCADJ15 Position */
#define TOUCHKEY_TC7_TKCADJ15_Msk    (0x7FFUL << TOUCHKEY_TC7_TKCADJ15_Pos)       /*!<TOUCHKEY TC7: TKCADJ15 Mask */

#define TOUCHKEY_TC7_Msk_ALL         (TOUCHKEY_TC7_TKCADJ14_Msk    |\
                                      TOUCHKEY_TC7_TKCADJ15_Msk    )

#define TOUCHKEY_TC8_TKCADJ16_Pos    0                                            /*!<TOUCHKEY TC8: TKCADJ16 Position */
#define TOUCHKEY_TC8_TKCADJ16_Msk    (0x7FFUL /*<< TOUCHKEY_TC8_TKCADJ16_Pos*/)   /*!<TOUCHKEY TC8: TKCADJ16 Mask */

#define TOUCHKEY_TC8_TKCADJ17_Pos    16                                           /*!<TOUCHKEY TC8: TKCADJ17 Position */
#define TOUCHKEY_TC8_TKCADJ17_Msk    (0x7FFUL << TOUCHKEY_TC8_TKCADJ17_Pos)       /*!<TOUCHKEY TC8: TKCADJ17 Mask */

#define TOUCHKEY_TC8_Msk_ALL         (TOUCHKEY_TC8_TKCADJ16_Msk    |\
                                      TOUCHKEY_TC8_TKCADJ17_Msk    )

#define TOUCHKEY_TC9_TKCADJ18_Pos    0                                            /*!<TOUCHKEY TC9: TKCADJ18 Position */
#define TOUCHKEY_TC9_TKCADJ18_Msk    (0x7FFUL /*<< TOUCHKEY_TC9_TKCADJ18_Pos*/)   /*!<TOUCHKEY TC9: TKCADJ18 Mask */

#define TOUCHKEY_TC9_TKCADJ19_Pos    16                                           /*!<TOUCHKEY TC9: TKCADJ19 Position */
#define TOUCHKEY_TC9_TKCADJ19_Msk    (0x7FFUL << TOUCHKEY_TC9_TKCADJ19_Pos)       /*!<TOUCHKEY TC9: TKCADJ19 Mask */

#define TOUCHKEY_TC9_Msk_ALL         (TOUCHKEY_TC9_TKCADJ18_Msk    |\
                                      TOUCHKEY_TC9_TKCADJ19_Msk    )

#define TOUCHKEY_TC10_TKCADJ20_Pos   0                                            /*!<TOUCHKEY TC10: TKCADJ20 Position */
#define TOUCHKEY_TC10_TKCADJ20_Msk   (0x7FFUL /*<< TOUCHKEY_TC10_TKCADJ20_Pos*/)  /*!<TOUCHKEY TC10: TKCADJ20 Mask */

#define TOUCHKEY_TC10_TKCADJ21_Pos   16                                           /*!<TOUCHKEY TC10: TKCADJ21 Position */
#define TOUCHKEY_TC10_TKCADJ21_Msk   (0x7FFUL << TOUCHKEY_TC10_TKCADJ21_Pos)      /*!<TOUCHKEY TC10: TKCADJ21 Mask */

#define TOUCHKEY_TC10_Msk_ALL        (TOUCHKEY_TC10_TKCADJ20_Msk   |\
                                      TOUCHKEY_TC10_TKCADJ21_Msk   )

#define TOUCHKEY_TC11_TKCADJ22_Pos   0                                            /*!<TOUCHKEY TC11: TKCADJ22 Position */
#define TOUCHKEY_TC11_TKCADJ22_Msk   (0x7FFUL /*<< TOUCHKEY_TC11_TKCADJ22_Pos*/)  /*!<TOUCHKEY TC11: TKCADJ22 Mask */

#define TOUCHKEY_TC11_TKCADJ23_Pos   16                                           /*!<TOUCHKEY TC11: TKCADJ23 Position */
#define TOUCHKEY_TC11_TKCADJ23_Msk   (0x7FFUL << TOUCHKEY_TC11_TKCADJ23_Pos)      /*!<TOUCHKEY TC11: TKCADJ23 Mask */

#define TOUCHKEY_TC11_Msk_ALL        (TOUCHKEY_TC11_TKCADJ22_Msk   |\
                                      TOUCHKEY_TC11_TKCADJ23_Msk   )

#define TOUCHKEY_TC12_TKCADJ24_Pos   0                                            /*!<TOUCHKEY TC12: TKCADJ24 Position */
#define TOUCHKEY_TC12_TKCADJ24_Msk   (0x7FFUL /*<< TOUCHKEY_TC12_TKCADJ24_Pos*/)  /*!<TOUCHKEY TC12: TKCADJ24 Mask */

#define TOUCHKEY_TC12_TKCADJ25_Pos   16                                           /*!<TOUCHKEY TC12: TKCADJ25 Position */
#define TOUCHKEY_TC12_TKCADJ25_Msk   (0x7FFUL << TOUCHKEY_TC12_TKCADJ25_Pos)      /*!<TOUCHKEY TC12: TKCADJ25 Mask */

#define TOUCHKEY_TC12_Msk_ALL        (TOUCHKEY_TC12_TKCADJ24_Msk   |\
                                      TOUCHKEY_TC12_TKCADJ25_Msk   )

#define TOUCHKEY_TC13_TKCADJ26_Pos   0                                            /*!<TOUCHKEY TC13: TKCADJ26 Position */
#define TOUCHKEY_TC13_TKCADJ26_Msk   (0x7FFUL /*<< TOUCHKEY_TC13_TKCADJ26_Pos*/)  /*!<TOUCHKEY TC13: TKCADJ26 Mask */

#define TOUCHKEY_TC13_TKCADJ27_Pos   16                                           /*!<TOUCHKEY TC13: TKCADJ27 Position */
#define TOUCHKEY_TC13_TKCADJ27_Msk   (0x7FFUL << TOUCHKEY_TC13_TKCADJ27_Pos)      /*!<TOUCHKEY TC13: TKCADJ27 Mask */

#define TOUCHKEY_TC13_Msk_ALL        (TOUCHKEY_TC13_TKCADJ26_Msk   |\
                                      TOUCHKEY_TC13_TKCADJ27_Msk   )

#define TOUCHKEY_TC14_TKCADJ28_Pos   0                                            /*!<TOUCHKEY TC14: TKCADJ28 Position */
#define TOUCHKEY_TC14_TKCADJ28_Msk   (0x7FFUL /*<< TOUCHKEY_TC14_TKCADJ28_Pos*/)  /*!<TOUCHKEY TC14: TKCADJ28 Mask */

#define TOUCHKEY_TC14_TKCADJ29_Pos   16                                           /*!<TOUCHKEY TC14: TKCADJ29 Position */
#define TOUCHKEY_TC14_TKCADJ29_Msk   (0x7FFUL << TOUCHKEY_TC14_TKCADJ29_Pos)      /*!<TOUCHKEY TC14: TKCADJ29 Mask */

#define TOUCHKEY_TC14_Msk_ALL        (TOUCHKEY_TC14_TKCADJ28_Msk   |\
                                      TOUCHKEY_TC14_TKCADJ29_Msk   )

#define TOUCHKEY_TC15_TKCADJ30_Pos   0                                            /*!<TOUCHKEY TC15: TKCADJ30 Position */
#define TOUCHKEY_TC15_TKCADJ30_Msk   (0x7FFUL /*<< TOUCHKEY_TC15_TKCADJ30_Pos*/)  /*!<TOUCHKEY TC15: TKCADJ30 Mask */

#define TOUCHKEY_TC15_TKCADJ31_Pos   16                                           /*!<TOUCHKEY TC15: TKCADJ31 Position */
#define TOUCHKEY_TC15_TKCADJ31_Msk   (0x7FFUL << TOUCHKEY_TC15_TKCADJ31_Pos)      /*!<TOUCHKEY TC15: TKCADJ31 Mask */

#define TOUCHKEY_TC15_Msk_ALL        (TOUCHKEY_TC15_TKCADJ30_Msk   |\
                                      TOUCHKEY_TC15_TKCADJ31_Msk   )

#define TOUCHKEY_TC16_TKCADJ32_Pos   0                                            /*!<TOUCHKEY TC16: TKCADJ32 Position */
#define TOUCHKEY_TC16_TKCADJ32_Msk   (0x7FFUL /*<< TOUCHKEY_TC16_TKCADJ32_Pos*/)  /*!<TOUCHKEY TC16: TKCADJ32 Mask */

#define TOUCHKEY_TC16_Msk_ALL        (TOUCHKEY_TC16_TKCADJ32_Msk  )

#define TOUCHKEY_TKU_TK0_Pos         0                                            /*!<TOUCHKEY TKU: TK0 Position */
#define TOUCHKEY_TKU_TK0_Msk         (0x1UL /*<< TOUCHKEY_TKU_TK0_Pos*/)          /*!<TOUCHKEY TKU: TK0 Mask */

#define TOUCHKEY_TKU_TK1_Pos         1                                            /*!<TOUCHKEY TKU: TK1 Position */
#define TOUCHKEY_TKU_TK1_Msk         (0x1UL << TOUCHKEY_TKU_TK1_Pos)              /*!<TOUCHKEY TKU: TK1 Mask */

#define TOUCHKEY_TKU_TK2_Pos         2                                            /*!<TOUCHKEY TKU: TK2 Position */
#define TOUCHKEY_TKU_TK2_Msk         (0x1UL << TOUCHKEY_TKU_TK2_Pos)              /*!<TOUCHKEY TKU: TK2 Mask */

#define TOUCHKEY_TKU_TK3_Pos         3                                            /*!<TOUCHKEY TKU: TK3 Position */
#define TOUCHKEY_TKU_TK3_Msk         (0x1UL << TOUCHKEY_TKU_TK3_Pos)              /*!<TOUCHKEY TKU: TK3 Mask */

#define TOUCHKEY_TKU_TK4_Pos         4                                            /*!<TOUCHKEY TKU: TK4 Position */
#define TOUCHKEY_TKU_TK4_Msk         (0x1UL << TOUCHKEY_TKU_TK4_Pos)              /*!<TOUCHKEY TKU: TK4 Mask */

#define TOUCHKEY_TKU_TK5_Pos         5                                            /*!<TOUCHKEY TKU: TK5 Position */
#define TOUCHKEY_TKU_TK5_Msk         (0x1UL << TOUCHKEY_TKU_TK5_Pos)              /*!<TOUCHKEY TKU: TK5 Mask */

#define TOUCHKEY_TKU_TK6_Pos         6                                            /*!<TOUCHKEY TKU: TK6 Position */
#define TOUCHKEY_TKU_TK6_Msk         (0x1UL << TOUCHKEY_TKU_TK6_Pos)              /*!<TOUCHKEY TKU: TK6 Mask */

#define TOUCHKEY_TKU_TK7_Pos         7                                            /*!<TOUCHKEY TKU: TK7 Position */
#define TOUCHKEY_TKU_TK7_Msk         (0x1UL << TOUCHKEY_TKU_TK7_Pos)              /*!<TOUCHKEY TKU: TK7 Mask */

#define TOUCHKEY_TKU_TK8_Pos         8                                            /*!<TOUCHKEY TKU: TK8 Position */
#define TOUCHKEY_TKU_TK8_Msk         (0x1UL << TOUCHKEY_TKU_TK8_Pos)              /*!<TOUCHKEY TKU: TK8 Mask */

#define TOUCHKEY_TKU_TK9_Pos         9                                            /*!<TOUCHKEY TKU: TK9 Position */
#define TOUCHKEY_TKU_TK9_Msk         (0x1UL << TOUCHKEY_TKU_TK9_Pos)              /*!<TOUCHKEY TKU: TK9 Mask */

#define TOUCHKEY_TKU_TK10_Pos        10                                           /*!<TOUCHKEY TKU: TK10 Position */
#define TOUCHKEY_TKU_TK10_Msk        (0x1UL << TOUCHKEY_TKU_TK10_Pos)             /*!<TOUCHKEY TKU: TK10 Mask */

#define TOUCHKEY_TKU_TK11_Pos        11                                           /*!<TOUCHKEY TKU: TK11 Position */
#define TOUCHKEY_TKU_TK11_Msk        (0x1UL << TOUCHKEY_TKU_TK11_Pos)             /*!<TOUCHKEY TKU: TK11 Mask */

#define TOUCHKEY_TKU_TK12_Pos        12                                           /*!<TOUCHKEY TKU: TK12 Position */
#define TOUCHKEY_TKU_TK12_Msk        (0x1UL << TOUCHKEY_TKU_TK12_Pos)             /*!<TOUCHKEY TKU: TK12 Mask */

#define TOUCHKEY_TKU_TK13_Pos        13                                           /*!<TOUCHKEY TKU: TK13 Position */
#define TOUCHKEY_TKU_TK13_Msk        (0x1UL << TOUCHKEY_TKU_TK13_Pos)             /*!<TOUCHKEY TKU: TK13 Mask */

#define TOUCHKEY_TKU_TK14_Pos        14                                           /*!<TOUCHKEY TKU: TK14 Position */
#define TOUCHKEY_TKU_TK14_Msk        (0x1UL << TOUCHKEY_TKU_TK14_Pos)             /*!<TOUCHKEY TKU: TK14 Mask */

#define TOUCHKEY_TKU_TK15_Pos        15                                           /*!<TOUCHKEY TKU: TK15 Position */
#define TOUCHKEY_TKU_TK15_Msk        (0x1UL << TOUCHKEY_TKU_TK15_Pos)             /*!<TOUCHKEY TKU: TK15 Mask */

#define TOUCHKEY_TKU_TK16_Pos        16                                           /*!<TOUCHKEY TKU: TK16 Position */
#define TOUCHKEY_TKU_TK16_Msk        (0x1UL << TOUCHKEY_TKU_TK16_Pos)             /*!<TOUCHKEY TKU: TK16 Mask */

#define TOUCHKEY_TKU_TK17_Pos        17                                           /*!<TOUCHKEY TKU: TK17 Position */
#define TOUCHKEY_TKU_TK17_Msk        (0x1UL << TOUCHKEY_TKU_TK17_Pos)             /*!<TOUCHKEY TKU: TK17 Mask */

#define TOUCHKEY_TKU_TK18_Pos        18                                           /*!<TOUCHKEY TKU: TK18 Position */
#define TOUCHKEY_TKU_TK18_Msk        (0x1UL << TOUCHKEY_TKU_TK18_Pos)             /*!<TOUCHKEY TKU: TK18 Mask */

#define TOUCHKEY_TKU_TK19_Pos        19                                           /*!<TOUCHKEY TKU: TK19 Position */
#define TOUCHKEY_TKU_TK19_Msk        (0x1UL << TOUCHKEY_TKU_TK19_Pos)             /*!<TOUCHKEY TKU: TK19 Mask */

#define TOUCHKEY_TKU_TK20_Pos        20                                           /*!<TOUCHKEY TKU: TK20 Position */
#define TOUCHKEY_TKU_TK20_Msk        (0x1UL << TOUCHKEY_TKU_TK20_Pos)             /*!<TOUCHKEY TKU: TK20 Mask */

#define TOUCHKEY_TKU_TK21_Pos        21                                           /*!<TOUCHKEY TKU: TK21 Position */
#define TOUCHKEY_TKU_TK21_Msk        (0x1UL << TOUCHKEY_TKU_TK21_Pos)             /*!<TOUCHKEY TKU: TK21 Mask */

#define TOUCHKEY_TKU_TK22_Pos        22                                           /*!<TOUCHKEY TKU: TK22 Position */
#define TOUCHKEY_TKU_TK22_Msk        (0x1UL << TOUCHKEY_TKU_TK22_Pos)             /*!<TOUCHKEY TKU: TK22 Mask */

#define TOUCHKEY_TKU_TK23_Pos        23                                           /*!<TOUCHKEY TKU: TK23 Position */
#define TOUCHKEY_TKU_TK23_Msk        (0x1UL << TOUCHKEY_TKU_TK23_Pos)             /*!<TOUCHKEY TKU: TK23 Mask */

#define TOUCHKEY_TKU_TK24_Pos        24                                           /*!<TOUCHKEY TKU: TK24 Position */
#define TOUCHKEY_TKU_TK24_Msk        (0x1UL << TOUCHKEY_TKU_TK24_Pos)             /*!<TOUCHKEY TKU: TK24 Mask */

#define TOUCHKEY_TKU_TK25_Pos        25                                           /*!<TOUCHKEY TKU: TK25 Position */
#define TOUCHKEY_TKU_TK25_Msk        (0x1UL << TOUCHKEY_TKU_TK25_Pos)             /*!<TOUCHKEY TKU: TK25 Mask */

#define TOUCHKEY_TKU_TK26_Pos        26                                           /*!<TOUCHKEY TKU: TK26 Position */
#define TOUCHKEY_TKU_TK26_Msk        (0x1UL << TOUCHKEY_TKU_TK26_Pos)             /*!<TOUCHKEY TKU: TK26 Mask */

#define TOUCHKEY_TKU_TK27_Pos        27                                           /*!<TOUCHKEY TKU: TK27 Position */
#define TOUCHKEY_TKU_TK27_Msk        (0x1UL << TOUCHKEY_TKU_TK27_Pos)             /*!<TOUCHKEY TKU: TK27 Mask */

#define TOUCHKEY_TKU_TK28_Pos        28                                           /*!<TOUCHKEY TKU: TK28 Position */
#define TOUCHKEY_TKU_TK28_Msk        (0x1UL << TOUCHKEY_TKU_TK28_Pos)             /*!<TOUCHKEY TKU: TK28 Mask */

#define TOUCHKEY_TKU_TK29_Pos        29                                           /*!<TOUCHKEY TKU: TK29 Position */
#define TOUCHKEY_TKU_TK29_Msk        (0x1UL << TOUCHKEY_TKU_TK29_Pos)             /*!<TOUCHKEY TKU: TK29 Mask */

#define TOUCHKEY_TKU_TK30_Pos        30                                           /*!<TOUCHKEY TKU: TK30 Position */
#define TOUCHKEY_TKU_TK30_Msk        (0x1UL << TOUCHKEY_TKU_TK30_Pos)             /*!<TOUCHKEY TKU: TK30 Mask */

#define TOUCHKEY_TKU_TK31_Pos        31                                           /*!<TOUCHKEY TKU: TK31 Position */
#define TOUCHKEY_TKU_TK31_Msk        (0x1UL << TOUCHKEY_TKU_TK31_Pos)             /*!<TOUCHKEY TKU: TK31 Mask */

#define TOUCHKEY_TKU_Msk_ALL         (TOUCHKEY_TKU_TK0_Msk         |\
                                      TOUCHKEY_TKU_TK1_Msk         |\
                                      TOUCHKEY_TKU_TK2_Msk         |\
                                      TOUCHKEY_TKU_TK3_Msk         |\
                                      TOUCHKEY_TKU_TK4_Msk         |\
                                      TOUCHKEY_TKU_TK5_Msk         |\
                                      TOUCHKEY_TKU_TK6_Msk         |\
                                      TOUCHKEY_TKU_TK7_Msk         |\
                                      TOUCHKEY_TKU_TK8_Msk         |\
                                      TOUCHKEY_TKU_TK9_Msk         |\
                                      TOUCHKEY_TKU_TK10_Msk        |\
                                      TOUCHKEY_TKU_TK11_Msk        |\
                                      TOUCHKEY_TKU_TK12_Msk        |\
                                      TOUCHKEY_TKU_TK13_Msk        |\
                                      TOUCHKEY_TKU_TK14_Msk        |\
                                      TOUCHKEY_TKU_TK15_Msk        |\
                                      TOUCHKEY_TKU_TK16_Msk        |\
                                      TOUCHKEY_TKU_TK17_Msk        |\
                                      TOUCHKEY_TKU_TK18_Msk        |\
                                      TOUCHKEY_TKU_TK19_Msk        |\
                                      TOUCHKEY_TKU_TK20_Msk        |\
                                      TOUCHKEY_TKU_TK21_Msk        |\
                                      TOUCHKEY_TKU_TK22_Msk        |\
                                      TOUCHKEY_TKU_TK23_Msk        |\
                                      TOUCHKEY_TKU_TK24_Msk        |\
                                      TOUCHKEY_TKU_TK25_Msk        |\
                                      TOUCHKEY_TKU_TK26_Msk        |\
                                      TOUCHKEY_TKU_TK27_Msk        |\
                                      TOUCHKEY_TKU_TK28_Msk        |\
                                      TOUCHKEY_TKU_TK29_Msk        |\
                                      TOUCHKEY_TKU_TK30_Msk        |\
                                      TOUCHKEY_TKU_TK31_Msk        )

#define TOUCHKEY_TD0_TKD00_Pos       0                                            /*!<TOUCHKEY TD0: TKD00 Position */
#define TOUCHKEY_TD0_TKD00_Msk       (0x3FFUL /*<< TOUCHKEY_TD0_TKD00_Pos*/)      /*!<TOUCHKEY TD0: TKD00 Mask */

#define TOUCHKEY_TD0_TKD01_Pos       16                                           /*!<TOUCHKEY TD0: TKD01 Position */
#define TOUCHKEY_TD0_TKD01_Msk       (0x3FFUL << TOUCHKEY_TD0_TKD01_Pos)          /*!<TOUCHKEY TD0: TKD01 Mask */

#define TOUCHKEY_TD0_Msk_ALL         (TOUCHKEY_TD0_TKD00_Msk       |\
                                      TOUCHKEY_TD0_TKD01_Msk       )

#define TOUCHKEY_TD1_TKD02_Pos       0                                            /*!<TOUCHKEY TD1: TKD02 Position */
#define TOUCHKEY_TD1_TKD02_Msk       (0x3FFUL /*<< TOUCHKEY_TD1_TKD02_Pos*/)      /*!<TOUCHKEY TD1: TKD02 Mask */

#define TOUCHKEY_TD1_TKD03_Pos       16                                           /*!<TOUCHKEY TD1: TKD03 Position */
#define TOUCHKEY_TD1_TKD03_Msk       (0x3FFUL << TOUCHKEY_TD1_TKD03_Pos)          /*!<TOUCHKEY TD1: TKD03 Mask */

#define TOUCHKEY_TD1_Msk_ALL         (TOUCHKEY_TD1_TKD02_Msk       |\
                                      TOUCHKEY_TD1_TKD03_Msk       )

#define TOUCHKEY_TD2_TKD04_Pos       0                                            /*!<TOUCHKEY TD2: TKD04 Position */
#define TOUCHKEY_TD2_TKD04_Msk       (0x3FFUL /*<< TOUCHKEY_TD2_TKD04_Pos*/)      /*!<TOUCHKEY TD2: TKD04 Mask */

#define TOUCHKEY_TD2_TKD05_Pos       16                                           /*!<TOUCHKEY TD2: TKD05 Position */
#define TOUCHKEY_TD2_TKD05_Msk       (0x3FFUL << TOUCHKEY_TD2_TKD05_Pos)          /*!<TOUCHKEY TD2: TKD05 Mask */

#define TOUCHKEY_TD2_Msk_ALL         (TOUCHKEY_TD2_TKD04_Msk       |\
                                      TOUCHKEY_TD2_TKD05_Msk       )

#define TOUCHKEY_TD3_TKD06_Pos       0                                            /*!<TOUCHKEY TD3: TKD06 Position */
#define TOUCHKEY_TD3_TKD06_Msk       (0x3FFUL /*<< TOUCHKEY_TD3_TKD06_Pos*/)      /*!<TOUCHKEY TD3: TKD06 Mask */

#define TOUCHKEY_TD3_TKD07_Pos       16                                           /*!<TOUCHKEY TD3: TKD07 Position */
#define TOUCHKEY_TD3_TKD07_Msk       (0x3FFUL << TOUCHKEY_TD3_TKD07_Pos)          /*!<TOUCHKEY TD3: TKD07 Mask */

#define TOUCHKEY_TD3_Msk_ALL         (TOUCHKEY_TD3_TKD06_Msk       |\
                                      TOUCHKEY_TD3_TKD07_Msk       )

#define TOUCHKEY_TD4_TKD08_Pos       0                                            /*!<TOUCHKEY TD4: TKD08 Position */
#define TOUCHKEY_TD4_TKD08_Msk       (0x3FFUL /*<< TOUCHKEY_TD4_TKD08_Pos*/)      /*!<TOUCHKEY TD4: TKD08 Mask */

#define TOUCHKEY_TD4_TKD09_Pos       16                                           /*!<TOUCHKEY TD4: TKD09 Position */
#define TOUCHKEY_TD4_TKD09_Msk       (0x3FFUL << TOUCHKEY_TD4_TKD09_Pos)          /*!<TOUCHKEY TD4: TKD09 Mask */

#define TOUCHKEY_TD4_Msk_ALL         (TOUCHKEY_TD4_TKD08_Msk       |\
                                      TOUCHKEY_TD4_TKD09_Msk       )

#define TOUCHKEY_TD5_TKD10_Pos       0                                            /*!<TOUCHKEY TD5: TKD10 Position */
#define TOUCHKEY_TD5_TKD10_Msk       (0x3FFUL /*<< TOUCHKEY_TD5_TKD10_Pos*/)      /*!<TOUCHKEY TD5: TKD10 Mask */

#define TOUCHKEY_TD5_TKD11_Pos       16                                           /*!<TOUCHKEY TD5: TKD11 Position */
#define TOUCHKEY_TD5_TKD11_Msk       (0x3FFUL << TOUCHKEY_TD5_TKD11_Pos)          /*!<TOUCHKEY TD5: TKD11 Mask */

#define TOUCHKEY_TD5_Msk_ALL         (TOUCHKEY_TD5_TKD10_Msk       |\
                                      TOUCHKEY_TD5_TKD11_Msk       )

#define TOUCHKEY_TD6_TKD12_Pos       0                                            /*!<TOUCHKEY TD6: TKD12 Position */
#define TOUCHKEY_TD6_TKD12_Msk       (0x3FFUL /*<< TOUCHKEY_TD6_TKD12_Pos*/)      /*!<TOUCHKEY TD6: TKD12 Mask */

#define TOUCHKEY_TD6_TKD13_Pos       16                                           /*!<TOUCHKEY TD6: TKD13 Position */
#define TOUCHKEY_TD6_TKD13_Msk       (0x3FFUL << TOUCHKEY_TD6_TKD13_Pos)          /*!<TOUCHKEY TD6: TKD13 Mask */

#define TOUCHKEY_TD6_Msk_ALL         (TOUCHKEY_TD6_TKD12_Msk       |\
                                      TOUCHKEY_TD6_TKD13_Msk       )

#define TOUCHKEY_TD7_TKD14_Pos       0                                            /*!<TOUCHKEY TD7: TKD14 Position */
#define TOUCHKEY_TD7_TKD14_Msk       (0x3FFUL /*<< TOUCHKEY_TD7_TKD14_Pos*/)      /*!<TOUCHKEY TD7: TKD14 Mask */

#define TOUCHKEY_TD7_TKD15_Pos       16                                           /*!<TOUCHKEY TD7: TKD15 Position */
#define TOUCHKEY_TD7_TKD15_Msk       (0x3FFUL << TOUCHKEY_TD7_TKD15_Pos)          /*!<TOUCHKEY TD7: TKD15 Mask */

#define TOUCHKEY_TD7_Msk_ALL         (TOUCHKEY_TD7_TKD14_Msk       |\
                                      TOUCHKEY_TD7_TKD15_Msk       )

#define TOUCHKEY_TD8_TKD16_Pos       0                                            /*!<TOUCHKEY TD8: TKD16 Position */
#define TOUCHKEY_TD8_TKD16_Msk       (0x3FFUL /*<< TOUCHKEY_TD8_TKD16_Pos*/)      /*!<TOUCHKEY TD8: TKD16 Mask */

#define TOUCHKEY_TD8_TKD17_Pos       16                                           /*!<TOUCHKEY TD8: TKD17 Position */
#define TOUCHKEY_TD8_TKD17_Msk       (0x3FFUL << TOUCHKEY_TD8_TKD17_Pos)          /*!<TOUCHKEY TD8: TKD17 Mask */

#define TOUCHKEY_TD8_Msk_ALL         (TOUCHKEY_TD8_TKD16_Msk       |\
                                      TOUCHKEY_TD8_TKD17_Msk       )

#define TOUCHKEY_TD9_TKD18_Pos       0                                            /*!<TOUCHKEY TD9: TKD18 Position */
#define TOUCHKEY_TD9_TKD18_Msk       (0x3FFUL /*<< TOUCHKEY_TD9_TKD18_Pos*/)      /*!<TOUCHKEY TD9: TKD18 Mask */

#define TOUCHKEY_TD9_TKD19_Pos       16                                           /*!<TOUCHKEY TD9: TKD19 Position */
#define TOUCHKEY_TD9_TKD19_Msk       (0x3FFUL << TOUCHKEY_TD9_TKD19_Pos)          /*!<TOUCHKEY TD9: TKD19 Mask */

#define TOUCHKEY_TD9_Msk_ALL         (TOUCHKEY_TD9_TKD18_Msk       |\
                                      TOUCHKEY_TD9_TKD19_Msk       )

#define TOUCHKEY_TD10_TKD20_Pos      0                                            /*!<TOUCHKEY TD10: TKD20 Position */
#define TOUCHKEY_TD10_TKD20_Msk      (0x3FFUL /*<< TOUCHKEY_TD10_TKD20_Pos*/)     /*!<TOUCHKEY TD10: TKD20 Mask */

#define TOUCHKEY_TD10_TKD21_Pos      16                                           /*!<TOUCHKEY TD10: TKD21 Position */
#define TOUCHKEY_TD10_TKD21_Msk      (0x3FFUL << TOUCHKEY_TD10_TKD21_Pos)         /*!<TOUCHKEY TD10: TKD21 Mask */

#define TOUCHKEY_TD10_Msk_ALL        (TOUCHKEY_TD10_TKD20_Msk      |\
                                      TOUCHKEY_TD10_TKD21_Msk      )

#define TOUCHKEY_TD11_TKD22_Pos      0                                            /*!<TOUCHKEY TD11: TKD22 Position */
#define TOUCHKEY_TD11_TKD22_Msk      (0x3FFUL /*<< TOUCHKEY_TD11_TKD22_Pos*/)     /*!<TOUCHKEY TD11: TKD22 Mask */

#define TOUCHKEY_TD11_TKD23_Pos      16                                           /*!<TOUCHKEY TD11: TKD23 Position */
#define TOUCHKEY_TD11_TKD23_Msk      (0x3FFUL << TOUCHKEY_TD11_TKD23_Pos)         /*!<TOUCHKEY TD11: TKD23 Mask */

#define TOUCHKEY_TD11_Msk_ALL        (TOUCHKEY_TD11_TKD22_Msk      |\
                                      TOUCHKEY_TD11_TKD23_Msk      )

#define TOUCHKEY_TD12_TKD24_Pos      0                                            /*!<TOUCHKEY TD12: TKD24 Position */
#define TOUCHKEY_TD12_TKD24_Msk      (0x3FFUL /*<< TOUCHKEY_TD12_TKD24_Pos*/)     /*!<TOUCHKEY TD12: TKD24 Mask */

#define TOUCHKEY_TD12_TKD25_Pos      16                                           /*!<TOUCHKEY TD12: TKD25 Position */
#define TOUCHKEY_TD12_TKD25_Msk      (0x3FFUL << TOUCHKEY_TD12_TKD25_Pos)         /*!<TOUCHKEY TD12: TKD25 Mask */

#define TOUCHKEY_TD12_Msk_ALL        (TOUCHKEY_TD12_TKD24_Msk      |\
                                      TOUCHKEY_TD12_TKD25_Msk      )

#define TOUCHKEY_TD13_TKD26_Pos      0                                            /*!<TOUCHKEY TD13: TKD26 Position */
#define TOUCHKEY_TD13_TKD26_Msk      (0x3FFUL /*<< TOUCHKEY_TD13_TKD26_Pos*/)     /*!<TOUCHKEY TD13: TKD26 Mask */

#define TOUCHKEY_TD13_TKD27_Pos      16                                           /*!<TOUCHKEY TD13: TKD27 Position */
#define TOUCHKEY_TD13_TKD27_Msk      (0x3FFUL << TOUCHKEY_TD13_TKD27_Pos)         /*!<TOUCHKEY TD13: TKD27 Mask */

#define TOUCHKEY_TD13_Msk_ALL        (TOUCHKEY_TD13_TKD26_Msk      |\
                                      TOUCHKEY_TD13_TKD27_Msk      )

#define TOUCHKEY_TD14_TKD28_Pos      0                                            /*!<TOUCHKEY TD14: TKD28 Position */
#define TOUCHKEY_TD14_TKD28_Msk      (0x3FFUL /*<< TOUCHKEY_TD14_TKD28_Pos*/)     /*!<TOUCHKEY TD14: TKD28 Mask */

#define TOUCHKEY_TD14_TKD29_Pos      16                                           /*!<TOUCHKEY TD14: TKD29 Position */
#define TOUCHKEY_TD14_TKD29_Msk      (0x3FFUL << TOUCHKEY_TD14_TKD29_Pos)         /*!<TOUCHKEY TD14: TKD29 Mask */

#define TOUCHKEY_TD14_Msk_ALL        (TOUCHKEY_TD14_TKD28_Msk      |\
                                      TOUCHKEY_TD14_TKD29_Msk      )

#define TOUCHKEY_TD15_TKD30_Pos      0                                            /*!<TOUCHKEY TD15: TKD30 Position */
#define TOUCHKEY_TD15_TKD30_Msk      (0x3FFUL /*<< TOUCHKEY_TD15_TKD30_Pos*/)     /*!<TOUCHKEY TD15: TKD30 Mask */

#define TOUCHKEY_TD15_TKD31_Pos      16                                           /*!<TOUCHKEY TD15: TKD31 Position */
#define TOUCHKEY_TD15_TKD31_Msk      (0x3FFUL << TOUCHKEY_TD15_TKD31_Pos)         /*!<TOUCHKEY TD15: TKD31 Mask */

#define TOUCHKEY_TD15_Msk_ALL        (TOUCHKEY_TD15_TKD30_Msk      |\
                                      TOUCHKEY_TD15_TKD31_Msk      )

#define TOUCHKEY_TD16_TKD32_Pos      0                                            /*!<TOUCHKEY TD16: TKD32 Position */
#define TOUCHKEY_TD16_TKD32_Msk      (0x3FFUL /*<< TOUCHKEY_TD16_TKD32_Pos*/)     /*!<TOUCHKEY TD16: TKD32 Mask */

#define TOUCHKEY_TD16_Msk_ALL        (TOUCHKEY_TD16_TKD32_Msk     )



__STATIC_INLINE void NVIC_SetVectorBase(uint32_t vector_base){
	SCB->VTOR = vector_base;
}

__STATIC_INLINE void RCC_WriteEnable(){
	RCC->RCCLOCK = 0x33CC;
}
__STATIC_INLINE void RCC_WriteDisable(){
	RCC->RCCLOCK = 0;
}


#ifdef __cplusplus
}  /*extern "C"*/
#endif

#endif /*__SH30F9XX_SA0_H__*/
/******************* (C) COPYRIGHT 2016 Sinowealth *****END OF FILE****/

