/**
  ******************************************************************************
  * @file    sh32f9xx_sb0.h
  * @version V1.0
  * @date    2020-08-19
  * @brief   CMSIS Cortex-M3 Device Peripheral Access Layer Header File.
  *          This file contains all the peripheral register's definitions, bits
  *          definitions and memory mapping for Sinowealth M3 based devices.
  ******************************************************************************
*/

#ifndef __SH32F9XX_SB0_H__
#define __SH32F9XX_SB0_H__

#ifdef __cplusplus
extern "C" {
#endif

#define __CM3_REV                 0x0201  /*!< Core revision r2p1                            */
#define __MPU_PRESENT             1       /*!< SH32F2xxx provides an MPU                     */
#define __NVIC_PRIO_BITS          4       /*!< SH32F2xxx uses 4 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0       /*!< Set to 1 if different SysTick Config is used  */



typedef enum
{
/******  Cortex-M3 Processor Exceptions Numbers ****************************************************************/
  NMI_IRQn                    = -14,    /*!< Non Maskable Interrupt                                            */
  HardFault_IRQn              = -13,    /*!< Hard Fault Interrupt                                              */
  MemManage_IRQn              = -12,    /*!< Cortex-M3 Memory Management Interrupt                             */
  BusFault_IRQn               = -11,    /*!< Cortex-M3 Bus Fault Interrupt                                     */
  UsageFault_IRQn             = -10,    /*!< Cortex-M3 Usage Fault Interrupt                                   */
  SVCall_IRQn                 = -5,     /*!< Cortex-M3 SV Call Interrupt                                       */
  DebugMon_IRQn               = -4,     /*!< Cortex-M3 Debug Monitor Interrupt                                 */
  PendSV_IRQn                 = -2,     /*!< Cortex-M3 Pend SV Interrupt                                       */
  SysTick_IRQn                = -1,     /*!< Cortex-M3 System Tick Interrupt                                   */
/******  SH32F9001 specific Interrupt Numbers ******************************************************************/
  WWDT_IRQn                   = 0,      /*!< Window WatchDog Interrupt                                         */
  BOD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt                         */
  RCC_IRQn                    = 2,      /*!< RCC global Interrupt                                              */
  EXTI0_IRQn                  = 3,      /*!< EXTI Line0 Interrupt                                              */
  EXTI1_IRQn                  = 4,      /*!< EXTI Line1 Interrupt                                              */
  EXTI2_IRQn                  = 5,      /*!< EXTI Line2 Interrupt                                              */
  EXTI3_IRQn                  = 6,      /*!< EXTI Line3 Interrupt                                              */
  EXTI4_IRQn                  = 7,      /*!< EXTI Line4 Interrupt                                              */
  DMA_CH0_IRQn                = 8,      /*!< DMA Channel0 Interrupt                                            */
  DMA_CH1_IRQn                = 9,      /*!< DMA Channel1 Interrupt                                            */
  DMA_CH2_7_IRQn              = 10,     /*!< DMA Channel2 ~ Channel7 Interrupt                                 */
  ADC_IRQn                    = 11,     /*!< ADC Interrupt                                                     */
  PWM0_IRQn                   = 12,     /*!< PWM0 Interrupt                                                    */
  PWM1_IRQn                   = 13,     /*!< PWM1 Interrupt                                                    */
  PWM2_IRQn                   = 14,     /*!< PWM2 Interrupt                                                    */
  PWM3_IRQn                   = 15,     /*!< PWM3 Interrupt                                                    */
  PCA0_IRQn                   = 16,     /*!< PCA0 Interrupt                                                    */
  PCA1_IRQn                   = 17,     /*!< PCA1 Interrupt                                                    */
  PCA2_IRQn                   = 18,     /*!< PCA2 Interrupt                                                    */
  PCA3_IRQn                   = 19,     /*!< PCA3 Interrupt                                                    */
  EXTI9_5_IRQn                = 20,     /*!< EXTI Line5 ~ Line9 global Interrupt                               */
  UART0_IRQn                  = 21,     /*!< UART0 Interrupt                                                   */
  TWI0_IRQn                   = 22,     /*!< TWI0 Interrupt                                                    */
  TWI1_IRQn                   = 23,     /*!< TWI1 Interrupt                                                    */
  SPI0_IRQn                   = 24,     /*!< SPI0 Interrupt                                                    */
  SPI1_IRQn                   = 25,     /*!< SPI1 Interrupt                                                    */
  UART1_IRQn                  = 26,     /*!< UART1 Interrupt                                                   */
  UART2_IRQn                  = 27,     /*!< UART2 Interrupt                                                   */
  UART3_IRQn                  = 28,     /*!< UART3 Interrupt                                                   */
  UART4_IRQn                  = 29,     /*!< UART4 Interrupt                                                   */  
  EXTI15_10_IRQn              = 30,     /*!< EXTI Line10 ~ Line15 Interrupt                                    */
  UART5_IRQn                  = 31,     /*!< UART5 Interrupt                                                   */
  TIM5_IRQn                   = 32,     /*!< TIM5 Interrupt                                                    */
  TIM6_IRQn                   = 33,     /*!< TIM6 Interrupt                                                    */
  TIM7_IRQn                   = 34,     /*!< TIM7 Interrupt                                                    */
  TIM8_IRQn                   = 35,     /*!< TIM8 Interrupt                                                    */
  PCA4_IRQn                   = 36,     /*!< PCA4 Interrupt                                                    */
  PCA5_IRQn                   = 37,     /*!< PCA5 Interrupt                                                    */
  PCA6_IRQn                   = 38,     /*!< PCA6 Interrupt                                                    */
  PCA7_IRQn                   = 39,     /*!< PCA7 Interrupt                                                    */
  LED_IRQn                    = 40,     /*!< LED Interrupt                                                     */  
  TouchKey_IRQn               = 41,     /*!< TouchKey Interrupt                                                */
} IRQn_Type;

/* Includes ****************************************************************************************************/
#include <core_cm3.h>
#include <stdint.h>




/**
*@brief FPGA_DEBUG_registers
*/
typedef struct
{
    __IO uint8_t   WATCH;                                   /*!< 0000H */
         uint8_t   Reserved0[3];                            /*!< 0001H */
}FPGA_DEBUG_TypeDef;


/**
*@brief N_TEST_registers
*/
typedef struct
{
    __IO uint8_t   NTW;                                     /*!< 0000H */
         uint8_t   Reserved0[3];                            /*!< 0001H */
    __IO uint16_t  NTID0;                                   /*!< 0004H */
         uint16_t  Reserved1;                               /*!< 0006H */
    __IO uint16_t  NTID1;                                   /*!< 0008H */
         uint16_t  Reserved2;                               /*!< 000AH */
    __IO uint16_t  NTID2;                                   /*!< 000CH */
         uint16_t  Reserved3;                               /*!< 000EH */
    __IO uint32_t  NTC0;                                    /*!< 0010H */
    __IO uint32_t  NTC1;                                    /*!< 0014H */
    __IO uint32_t  NTC2;                                    /*!< 0018H */
}N_TEST_TypeDef;


/**
*@brief FLASH_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  LATENCY   : 3;  /*!< [b2~b0]*/
                  uint32_t  rev0      : 5;  /*!< [b7~b3]*/
            __IO  uint32_t  PRFTEN    : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  ICEN      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  DCEN      : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  CRST      : 1;  /*!< [b11~b11]*/
                  uint32_t  rev1      : 4;  /*!< [b15~b12]*/
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
                  uint32_t  rev0      : 1;  /*!< [b2~b2]*/
            __I   uint32_t  FLSERR    : 1;  /*!< [b3~b3]*/
            __I   uint32_t  WRPRTERR  : 1;  /*!< [b4~b4]*/
            __I   uint32_t  PGPERR    : 1;  /*!< [b5~b5]*/
            __I   uint32_t  PGWERR    : 1;  /*!< [b6~b6]*/
            __I   uint32_t  STAERR    : 1;  /*!< [b7~b7]*/
                  uint32_t  rev1      : 7;  /*!< [b14~b8]*/
            __I   uint32_t  BSY       : 1;  /*!< [b15~b15]*/
            __O   uint32_t  EOPC      : 1;  /*!< [b16~b16]*/
            __O   uint32_t  OPERRC    : 1;  /*!< [b17~b17]*/
                  uint32_t  rev2      : 1;  /*!< [b18~b18]*/
            __O   uint32_t  FLSERRC   : 1;  /*!< [b19~b19]*/
            __O   uint32_t  WRPRTERRC : 1;  /*!< [b20~b20]*/
            __O   uint32_t  PGPERRC   : 1;  /*!< [b21~b21]*/
            __O   uint32_t  PGWERRC   : 1;  /*!< [b22~b22]*/
            __O   uint32_t  STAERRC   : 1;  /*!< [b23~b23]*/
                  uint32_t  rev3      : 8;  /*!< [b31~b24]*/
        }BIT;
    }SR;                               /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
            __IO  uint32_t  SNB       : 8;  /*!< [b7~b0]*/
            __IO  uint32_t  STRT      : 1;  /*!< [b8~b8]*/
                  uint32_t  rev0      : 2;  /*!< [b10~b9]*/
            __IO  uint32_t  PSIZE     : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  INFLCK    : 1;  /*!< [b12~b12]*/
                  uint32_t  rev1      : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  E2LCK     : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  MNLCK     : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  CMD       :16;  /*!< [b31~b16]*/
        }BIT;
    }CR;                               /*!< 0010H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
    __IO uint8_t   OPT0;                                    /*!< 0014H */
    __IO uint8_t   OPT1;                                    /*!< 0015H */
    __IO uint8_t   OPT2;                                    /*!< 0016H */
    __IO uint8_t   OPT3;                                    /*!< 0017H */
        }BIT;
    }OPR;                              /*!< 0014H */
    __I  uint16_t  RPR;                                     /*!< 0018H */
         uint16_t  Reserved0;                               /*!< 001AH */
    __I  uint32_t  WRPR;                                    /*!< 001CH */
    __IO uint32_t  CNTR;                                    /*!< 0020H */
    __IO uint32_t  UPCNTR;                                  /*!< 0024H */
    __IO uint8_t   CNTCR;                                   /*!< 0028H */
         uint8_t   Reserved1[3];                            /*!< 0029H */
    __O  uint32_t  IKYR;                                    /*!< 002CH */
         uint32_t  Reserved2[52];                           /*!< 0030H */
    __IO uint16_t  MEMRMP;                                  /*!< 0100H */
         uint16_t  Reserved3;                               /*!< 0102H */
         uint32_t  Reserved4[63];                           /*!< 0104H */
    union {
        __IO  uint32_t  V32;                                /*!< 0200H */
        struct {
    __IO uint8_t   OPT0;                                    /*!< 0200H */
    __IO uint8_t   OPT1;                                    /*!< 0201H */
    __IO uint8_t   OPT2;                                    /*!< 0202H */
    __IO uint8_t   OPT3;                                    /*!< 0203H */
        }BIT;
    }OPR_CUST1;                              /*!< 0200H */
    union {
        __IO  uint32_t  V32;                                /*!< 0204H */
        struct {
    __IO uint8_t   OPT0;                                    /*!< 0204H */
    __IO uint8_t   OPT1;                                    /*!< 0205H */
    __IO uint8_t   OPT2;                                    /*!< 0206H */
    __IO uint8_t   OPT3;                                    /*!< 0207H */
        }BIT;
    }OPR_DESI0;                              /*!< 0204H */
    union {
        __IO  uint32_t  V32;                                /*!< 0208H */
        struct {
    __IO uint8_t   OPT0;                                    /*!< 0208H */
    __IO uint8_t   OPT1;                                    /*!< 0209H */
    __IO uint8_t   OPT2;                                    /*!< 020AH */
    __IO uint8_t   OPT3;                                    /*!< 020BH */
        }BIT;
    }OPR_DESI1;                              /*!< 0208H */
    union {
        __IO  uint32_t  V32;                                /*!< 020CH */
        struct {
    __IO uint8_t   OPT0;                                    /*!< 020CH */
    __IO uint8_t   OPT1;                                    /*!< 020DH */
    __IO uint8_t   OPT2;                                    /*!< 020EH */
    __IO uint8_t   OPT3;                                    /*!< 020FH */
        }BIT;
    }OPR_DESI2;                              /*!< 020CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0210H */
        struct {
    __IO uint8_t   OPT0;                                    /*!< 0210H */
    __IO uint8_t   OPT1;                                    /*!< 0211H */
    __IO uint8_t   OPT2;                                    /*!< 0212H */
    __IO uint8_t   OPT3;                                    /*!< 0213H */
        }BIT;
    }OPR_DESI3;                              /*!< 0210H */
}FLASH_TypeDef;


/**
*@brief SYSCFG_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  VBOD      : 5;  /*!< [b4~b0]*/
            __IO  uint32_t  BODMD     : 2;  /*!< [b6~b5]*/
            __IO  uint32_t  BODIE     : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  BODEN     : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  VLVR      : 2;  /*!< [b10~b9]*/
            __IO  uint32_t  LVREN     : 1;  /*!< [b11~b11]*/
                  uint32_t  rev0      :20;  /*!< [b31~b12]*/
        }BIT;
    }PWRCR;                               /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __IO  uint32_t  BODIF     : 1;  /*!< [b0~b0]*/
            __I   uint32_t  BODF      : 1;  /*!< [b1~b1]*/
                  uint32_t  rev0      :30;  /*!< [b31~b2]*/
        }BIT;
    }PWRSR;                               /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
            __IO  uint32_t  OSCCFG    : 2;  /*!< [b1~b0]*/
            __IO  uint32_t  OSCXCFG   : 1;  /*!< [b2~b2]*/
                  uint32_t  rev0      : 2;  /*!< [b4~b3]*/
            __IO  uint32_t  SWJCFG    : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  IEN_EXTI0 : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  IEN_BOD   : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  IEN_CSM   : 1;  /*!< [b8~b8]*/
                  uint32_t  rev1      : 7;  /*!< [b15~b9]*/
            __O   uint32_t  LOCK      :16;  /*!< [b31~b16]*/
        }BIT;
    }SAFR;                               /*!< 0008H */
    union {
        __IO  uint32_t  V32;                                /*!< 000CH */
        struct {
    __IO uint8_t   CRAMLCK;                                 /*!< 000CH */
         uint8_t   rev0;                                    /*!< 000DH */
    __O  uint16_t  LOCK;                                    /*!< 000EH */
        }BIT;
    }CRAMLOCK;                              /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
            __IO  uint32_t  DBG_SLEEP : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  DBG_STOP  : 1;  /*!< [b1~b1]*/
                  uint32_t  rev0      : 1;  /*!< [b2~b2]*/
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
                  uint32_t  rev1      : 2;  /*!< [b15~b14]*/
            __O   uint32_t  LOCK      :16;  /*!< [b31~b16]*/
        }BIT;
    }DBGCR;                               /*!< 0010H */
         uint32_t  Reserved0[59];                           /*!< 0014H */
    union {
        __IO  uint32_t  V32;                                /*!< 0100H */
        struct {
            __IO  uint32_t  EFT_EN    : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  EFTSEL    : 2;  /*!< [b2~b1]*/
                  uint32_t  rev0      :29;  /*!< [b31~b3]*/
        }BIT;
    }EFTEN;                               /*!< 0100H */
}SYSCFG_TypeDef;


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
                  uint32_t  rev0      :15;  /*!< [b31~b17]*/
        }BIT;
    }CR;                               /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __IO  uint32_t  HPRE      : 3;  /*!< [b2~b0]*/
            __IO  uint32_t  PPRE0     : 3;  /*!< [b5~b3]*/
            __IO  uint32_t  PPRE1     : 3;  /*!< [b8~b6]*/
            __IO  uint32_t  PLLSW     : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  PLLK      : 3;  /*!< [b12~b10]*/
            __IO  uint32_t  PLLF      : 6;  /*!< [b18~b13]*/
            __IO  uint32_t  PLLSRC    : 1;  /*!< [b19~b19]*/
            __IO  uint32_t  PLLXTPRE  : 2;  /*!< [b21~b20]*/
            __IO  uint32_t  LSESPDUP  : 1;  /*!< [b22~b22]*/
            __IO  uint32_t  LSENOISEEN: 1;  /*!< [b23~b23]*/
            __IO  uint32_t  HSIENREC  : 1;  /*!< [b24~b24]*/
            __IO  uint32_t  HSESEL    : 2;  /*!< [b26~b25]*/
                  uint32_t  rev0      : 5;  /*!< [b31~b27]*/
        }BIT;
    }CFGR;                               /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
                  uint32_t  rev0      : 2;  /*!< [b1~b0]*/
            __IO  uint32_t  LSERDYIE  : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  HSERDYIE  : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  PLLRDYIE  : 1;  /*!< [b4~b4]*/
                  uint32_t  rev1      :27;  /*!< [b31~b5]*/
        }BIT;
    }CIENR;                               /*!< 0008H */
    union {
        __I   uint32_t  V32;                                /*!< 000CH */
        struct {
                  uint32_t  rev0      : 2;  /*!< [b1~b0]*/
            __I   uint32_t  LSERDYIF  : 1;  /*!< [b2~b2]*/
            __I   uint32_t  HSERDYIF  : 1;  /*!< [b3~b3]*/
            __I   uint32_t  PLLRDYIF  : 1;  /*!< [b4~b4]*/
            __I   uint32_t  CSMLSEF   : 1;  /*!< [b5~b5]*/
            __I   uint32_t  CSMHSEF   : 1;  /*!< [b6~b6]*/
            __I   uint32_t  CSMPLLF   : 1;  /*!< [b7~b7]*/
                  uint32_t  rev1      :24;  /*!< [b31~b8]*/
        }BIT;
    }CISTR;                               /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
                  uint32_t  rev0      : 2;  /*!< [b1~b0]*/
            __O   uint32_t  LSERDYC   : 1;  /*!< [b2~b2]*/
            __O   uint32_t  HSERDYC   : 1;  /*!< [b3~b3]*/
            __O   uint32_t  PLLRDYC   : 1;  /*!< [b4~b4]*/
                  uint32_t  rev1      : 2;  /*!< [b6~b5]*/
            __O   uint32_t  CSMC      : 1;  /*!< [b7~b7]*/
                  uint32_t  rev2      :24;  /*!< [b31~b8]*/
        }BIT;
    }CICLR;                               /*!< 0010H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
            __IO  uint32_t  PCA0RST   : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  PCA1RST   : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  GPIORST   : 1;  /*!< [b2~b2]*/
                  uint32_t  rev0      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  SYSCFGRST : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  DMARST    : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  CRCRST    : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  RAMBISTRST: 1;  /*!< [b7~b7]*/
            __IO  uint32_t  NTESTRST  : 1;  /*!< [b8~b8]*/
                  uint32_t  rev1      :23;  /*!< [b31~b9]*/
        }BIT;
    }AHBRSTR;                               /*!< 0014H */
    union {
        __IO  uint32_t  V32;                                /*!< 0018H */
        struct {
            __IO  uint32_t  UART0RST  : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  UART1RST  : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  UART2RST  : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  UART3RST  : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  UART4RST  : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  UART5RST  : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  SPI0RST   : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  SPI1RST   : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  TWI0RST   : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  TWI1RST   : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  AMOCRST   : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  ADCRST    : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  LCDRST    : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  LEDRST    : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  TKRST     : 1;  /*!< [b14~b14]*/
                  uint32_t  rev0      :17;  /*!< [b31~b15]*/
        }BIT;
    }APB1RSTR;                               /*!< 0018H */
    union {
        __IO  uint32_t  V32;                                /*!< 001CH */
        struct {
            __IO  uint32_t  TIM5RST   : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TIM6RST   : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  TIM7RST   : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  TIM8RST   : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  PWM0RST   : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  PWM1RST   : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  PWM2RST   : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  PWM3RST   : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  PCA2RST   : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  PCA3RST   : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  PCA4RST   : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  PCA5RST   : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  PCA6RST   : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  PCA7RST   : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  EXTIRST   : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  WWDTRST   : 1;  /*!< [b15~b15]*/
                  uint32_t  rev0      :16;  /*!< [b31~b16]*/
        }BIT;
    }APB0RSTR;                               /*!< 001CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0020H */
        struct {
            __IO  uint32_t  PCA0EN    : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  PCA1EN    : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  IOCLKEN   : 1;  /*!< [b2~b2]*/
                  uint32_t  rev0      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  SYSCFGEN  : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  DMAEN     : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  CRCEN     : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  RAMBISTEN : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  NTESTEN   : 1;  /*!< [b8~b8]*/
                  uint32_t  rev1      :23;  /*!< [b31~b9]*/
        }BIT;
    }AHBENR;                               /*!< 0020H */
    union {
        __IO  uint32_t  V32;                                /*!< 0024H */
        struct {
            __IO  uint32_t  UART0EN   : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  UART1EN   : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  UART2EN   : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  UART3EN   : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  UART4EN   : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  UART5EN   : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  SPI0EN    : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  SPI1EN    : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  TWI0EN    : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  TWI1EN    : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  AMOCEN    : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  ADCEN     : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  LCDEN     : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  LEDEN     : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  TKEN      : 1;  /*!< [b14~b14]*/
                  uint32_t  rev0      :17;  /*!< [b31~b15]*/
        }BIT;
    }APB1ENR;                               /*!< 0024H */
    union {
        __IO  uint32_t  V32;                                /*!< 0028H */
        struct {
            __IO  uint32_t  TIM5EN    : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TIM6EN    : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  TIM7EN    : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  TIM8EN    : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  PWM0EN    : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  PWM1EN    : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  PWM2EN    : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  PWM3EN    : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  PCA2EN    : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  PCA3EN    : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  PCA4EN    : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  PCA5EN    : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  PCA6EN    : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  PCA7EN    : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  EXTIEN    : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  WWDTEN    : 1;  /*!< [b15~b15]*/
                  uint32_t  rev0      :16;  /*!< [b31~b16]*/
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
            __I   uint32_t  LVRSTF2   : 1;  /*!< [b6~b6]*/
                  uint32_t  rev0      :25;  /*!< [b31~b7]*/
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
            __O   uint32_t  LVRSTF2C  : 1;  /*!< [b6~b6]*/
                  uint32_t  rev0      :25;  /*!< [b31~b7]*/
        }BIT;
    }RSTCLR;                               /*!< 0030H */
    union {
        __IO  uint32_t  V32;                                /*!< 0034H */
        struct {
            __IO  uint32_t  HSITRIM   : 3;  /*!< [b2~b0]*/
                  uint32_t  rev0      : 5;  /*!< [b7~b3]*/
            __I   uint32_t  HSICAL    : 8;  /*!< [b15~b8]*/
            __I   uint32_t  TRIMREF   :13;  /*!< [b28~b16]*/
                  uint32_t  rev1      : 2;  /*!< [b30~b29]*/
            __IO  uint32_t  TRIMRUN   : 1;  /*!< [b31~b31]*/
        }BIT;
    }HSICAL;                               /*!< 0034H */
    __IO uint8_t   CSMSEL;                                  /*!< 0038H */
         uint8_t   Reserved0[3];                            /*!< 0039H */
    __IO uint16_t  RCCLOCK;                                 /*!< 003CH */
         uint16_t  Reserved1;                               /*!< 003EH */
    union {
        __IO  uint32_t  V32;                                /*!< 0040H */
        struct {
            __IO  uint32_t  DRIVEON   : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  CAPON     : 1;  /*!< [b1~b1]*/
                  uint32_t  rev0      :30;  /*!< [b31~b2]*/
        }BIT;
    }LSECR;                               /*!< 0040H */
    __IO uint8_t   HSERFB;                                  /*!< 0044H */
         uint8_t   Reserved2[3];                            /*!< 0045H */
}RCC_TypeDef;


/**
*@brief DMA_registers
*/
typedef struct
{
    union {
        __I   uint32_t  V32;                                /*!< 0000H */
        struct {
    __I  uint8_t   BEIF;                                    /*!< 0000H */
    __I  uint8_t   TCIF;                                    /*!< 0001H */
    __I  uint8_t   HTIF;                                    /*!< 0002H */
    __I  uint8_t   TEIF;                                    /*!< 0003H */
        }BIT;
    }IFSR;                              /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
    __O  uint8_t   CBEIF;                                   /*!< 0004H */
    __O  uint8_t   CTCIF;                                   /*!< 0005H */
    __O  uint8_t   CHTIF;                                   /*!< 0006H */
    __O  uint8_t   CTEIF;                                   /*!< 0007H */
        }BIT;
    }IFCR;                              /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
            __IO  uint32_t  SWTRG     : 8;  /*!< [b7~b0]*/
            __I   uint32_t  DBUSY     : 8;  /*!< [b15~b8]*/
            __IO  uint32_t  BURSTIDLE : 4;  /*!< [b19~b16]*/
                  uint32_t  rev0      : 4;  /*!< [b23~b20]*/
            __IO  uint32_t  RELOAD    : 8;  /*!< [b31~b24]*/
        }BIT;
    }CSR;                               /*!< 0008H */
         uint32_t  Reserved0[1];                            /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
            __IO  uint32_t  EN        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TCIE      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  HTIE      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  BEIE      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  TEIE      : 1;  /*!< [b4~b4]*/
                  uint32_t  rev0      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  DPTYP     : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  SPTYP     : 2;  /*!< [b9~b8]*/
            __IO  uint32_t  DSIZE     : 2;  /*!< [b11~b10]*/
            __IO  uint32_t  SSIZE     : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  PL        : 2;  /*!< [b15~b14]*/
            __IO  uint32_t  BURSTLEN  : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  STRMSEL   : 3;  /*!< [b22~b20]*/
            __IO  uint32_t  TRGMODE   : 1;  /*!< [b23~b23]*/
                  uint32_t  rev1      : 8;  /*!< [b31~b24]*/
        }BIT;
    }CCR0;                               /*!< 0010H */
    __IO uint16_t  NPKT0;                                   /*!< 0014H */
         uint8_t   Reserved1[2];                            /*!< 0016H */
    __I  uint16_t  CPKT0;                                   /*!< 0018H */
         uint8_t   Reserved2[2];                            /*!< 001AH */
    __IO uint32_t  SAR0;                                    /*!< 001CH */
    __IO uint32_t  DAR0;                                    /*!< 0020H */
         uint32_t  Reserved3[3];                            /*!< 0024H */
    union {
        __IO  uint32_t  V32;                                /*!< 0030H */
        struct {
            __IO  uint32_t  EN        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TCIE      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  HTIE      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  BEIE      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  TEIE      : 1;  /*!< [b4~b4]*/
                  uint32_t  rev0      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  DPTYP     : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  SPTYP     : 2;  /*!< [b9~b8]*/
            __IO  uint32_t  DSIZE     : 2;  /*!< [b11~b10]*/
            __IO  uint32_t  SSIZE     : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  PL        : 2;  /*!< [b15~b14]*/
            __IO  uint32_t  BURSTLEN  : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  STRMSEL   : 3;  /*!< [b22~b20]*/
            __IO  uint32_t  TRGMODE   : 1;  /*!< [b23~b23]*/
                  uint32_t  rev1      : 8;  /*!< [b31~b24]*/
        }BIT;
    }CCR1;                               /*!< 0030H */
    __IO uint16_t  NPKT1;                                   /*!< 0034H */
         uint8_t   Reserved4[2];                            /*!< 0036H */
    __I  uint16_t  CPKT1;                                   /*!< 0038H */
         uint8_t   Reserved5[2];                            /*!< 003AH */
    __IO uint32_t  SAR1;                                    /*!< 003CH */
    __IO uint32_t  DAR1;                                    /*!< 0040H */
         uint32_t  Reserved6[3];                            /*!< 0044H */
    union {
        __IO  uint32_t  V32;                                /*!< 0050H */
        struct {
            __IO  uint32_t  EN        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TCIE      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  HTIE      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  BEIE      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  TEIE      : 1;  /*!< [b4~b4]*/
                  uint32_t  rev0      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  DPTYP     : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  SPTYP     : 2;  /*!< [b9~b8]*/
            __IO  uint32_t  DSIZE     : 2;  /*!< [b11~b10]*/
            __IO  uint32_t  SSIZE     : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  PL        : 2;  /*!< [b15~b14]*/
            __IO  uint32_t  BURSTLEN  : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  STRMSEL   : 3;  /*!< [b22~b20]*/
            __IO  uint32_t  TRGMODE   : 1;  /*!< [b23~b23]*/
                  uint32_t  rev1      : 8;  /*!< [b31~b24]*/
        }BIT;
    }CCR2;                               /*!< 0050H */
    __IO uint16_t  NPKT2;                                   /*!< 0054H */
         uint8_t   Reserved7[2];                            /*!< 0056H */
    __I  uint16_t  CPKT2;                                   /*!< 0058H */
         uint8_t   Reserved8[2];                            /*!< 005AH */
    __IO uint32_t  SAR2;                                    /*!< 005CH */
    __IO uint32_t  DAR2;                                    /*!< 0060H */
         uint32_t  Reserved9[3];                            /*!< 0064H */
    union {
        __IO  uint32_t  V32;                                /*!< 0070H */
        struct {
            __IO  uint32_t  EN        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TCIE      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  HTIE      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  BEIE      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  TEIE      : 1;  /*!< [b4~b4]*/
                  uint32_t  rev0      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  DPTYP     : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  SPTYP     : 2;  /*!< [b9~b8]*/
            __IO  uint32_t  DSIZE     : 2;  /*!< [b11~b10]*/
            __IO  uint32_t  SSIZE     : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  PL        : 2;  /*!< [b15~b14]*/
            __IO  uint32_t  BURSTLEN  : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  STRMSEL   : 3;  /*!< [b22~b20]*/
            __IO  uint32_t  TRGMODE   : 1;  /*!< [b23~b23]*/
                  uint32_t  rev1      : 8;  /*!< [b31~b24]*/
        }BIT;
    }CCR3;                               /*!< 0070H */
    __IO uint16_t  NPKT3;                                   /*!< 0074H */
         uint8_t   Reserved10[2];                           /*!< 0076H */
    __I  uint16_t  CPKT3;                                   /*!< 0078H */
         uint8_t   Reserved11[2];                           /*!< 007AH */
    __IO uint32_t  SAR3;                                    /*!< 007CH */
    __IO uint32_t  DAR3;                                    /*!< 0080H */
         uint32_t  Reserved12[3];                           /*!< 0084H */
    union {
        __IO  uint32_t  V32;                                /*!< 0090H */
        struct {
            __IO  uint32_t  EN        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TCIE      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  HTIE      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  BEIE      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  TEIE      : 1;  /*!< [b4~b4]*/
                  uint32_t  rev0      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  DPTYP     : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  SPTYP     : 2;  /*!< [b9~b8]*/
            __IO  uint32_t  DSIZE     : 2;  /*!< [b11~b10]*/
            __IO  uint32_t  SSIZE     : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  PL        : 2;  /*!< [b15~b14]*/
            __IO  uint32_t  BURSTLEN  : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  STRMSEL   : 3;  /*!< [b22~b20]*/
            __IO  uint32_t  TRGMODE   : 1;  /*!< [b23~b23]*/
                  uint32_t  rev1      : 8;  /*!< [b31~b24]*/
        }BIT;
    }CCR4;                               /*!< 0090H */
    __IO uint16_t  NPKT4;                                   /*!< 0094H */
         uint8_t   Reserved13[2];                           /*!< 0096H */
    __I  uint16_t  CPKT4;                                   /*!< 0098H */
         uint8_t   Reserved14[2];                           /*!< 009AH */
    __IO uint32_t  SAR4;                                    /*!< 009CH */
    __IO uint32_t  DAR4;                                    /*!< 00A0H */
         uint32_t  Reserved15[3];                           /*!< 00A4H */
    union {
        __IO  uint32_t  V32;                                /*!< 00B0H */
        struct {
            __IO  uint32_t  EN        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TCIE      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  HTIE      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  BEIE      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  TEIE      : 1;  /*!< [b4~b4]*/
                  uint32_t  rev0      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  DPTYP     : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  SPTYP     : 2;  /*!< [b9~b8]*/
            __IO  uint32_t  DSIZE     : 2;  /*!< [b11~b10]*/
            __IO  uint32_t  SSIZE     : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  PL        : 2;  /*!< [b15~b14]*/
            __IO  uint32_t  BURSTLEN  : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  STRMSEL   : 3;  /*!< [b22~b20]*/
            __IO  uint32_t  TRGMODE   : 1;  /*!< [b23~b23]*/
                  uint32_t  rev1      : 8;  /*!< [b31~b24]*/
        }BIT;
    }CCR5;                               /*!< 00B0H */
    __IO uint16_t  NPKT5;                                   /*!< 00B4H */
         uint8_t   Reserved16[2];                           /*!< 00B6H */
    __I  uint16_t  CPKT5;                                   /*!< 00B8H */
         uint8_t   Reserved17[2];                           /*!< 00BAH */
    __IO uint32_t  SAR5;                                    /*!< 00BCH */
    __IO uint32_t  DAR5;                                    /*!< 00C0H */
         uint32_t  Reserved18[3];                           /*!< 00C4H */
    union {
        __IO  uint32_t  V32;                                /*!< 00D0H */
        struct {
            __IO  uint32_t  EN        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TCIE      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  HTIE      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  BEIE      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  TEIE      : 1;  /*!< [b4~b4]*/
                  uint32_t  rev0      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  DPTYP     : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  SPTYP     : 2;  /*!< [b9~b8]*/
            __IO  uint32_t  DSIZE     : 2;  /*!< [b11~b10]*/
            __IO  uint32_t  SSIZE     : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  PL        : 2;  /*!< [b15~b14]*/
            __IO  uint32_t  BURSTLEN  : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  STRMSEL   : 3;  /*!< [b22~b20]*/
            __IO  uint32_t  TRGMODE   : 1;  /*!< [b23~b23]*/
                  uint32_t  rev1      : 8;  /*!< [b31~b24]*/
        }BIT;
    }CCR6;                               /*!< 00D0H */
    __IO uint16_t  NPKT6;                                   /*!< 00D4H */
         uint8_t   Reserved19[2];                           /*!< 00D6H */
    __I  uint16_t  CPKT6;                                   /*!< 00D8H */
         uint8_t   Reserved20[2];                           /*!< 00DAH */
    __IO uint32_t  SAR6;                                    /*!< 00DCH */
    __IO uint32_t  DAR6;                                    /*!< 00E0H */
         uint32_t  Reserved21[3];                           /*!< 00E4H */
    union {
        __IO  uint32_t  V32;                                /*!< 00F0H */
        struct {
            __IO  uint32_t  EN        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TCIE      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  HTIE      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  BEIE      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  TEIE      : 1;  /*!< [b4~b4]*/
                  uint32_t  rev0      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  DPTYP     : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  SPTYP     : 2;  /*!< [b9~b8]*/
            __IO  uint32_t  DSIZE     : 2;  /*!< [b11~b10]*/
            __IO  uint32_t  SSIZE     : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  PL        : 2;  /*!< [b15~b14]*/
            __IO  uint32_t  BURSTLEN  : 4;  /*!< [b19~b16]*/
            __IO  uint32_t  STRMSEL   : 3;  /*!< [b22~b20]*/
            __IO  uint32_t  TRGMODE   : 1;  /*!< [b23~b23]*/
                  uint32_t  rev1      : 8;  /*!< [b31~b24]*/
        }BIT;
    }CCR7;                               /*!< 00F0H */
    __IO uint16_t  NPKT7;                                   /*!< 00F4H */
         uint8_t   Reserved22[2];                           /*!< 00F6H */
    __I  uint16_t  CPKT7;                                   /*!< 00F8H */
         uint8_t   Reserved23[2];                           /*!< 00FAH */
    __IO uint32_t  SAR7;                                    /*!< 00FCH */
    __IO uint32_t  DAR7;                                    /*!< 0100H */
}DMA_TypeDef;


/**
*@brief CRC_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint8_t   DR8       : 8;  /*!< [b0~b7]*/
        }BIT;
		struct {
            __IO  uint16_t  DR16      : 16;  /*!< [b0~b15]*/
        }BIT1;
    }DR;                               /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __O   uint32_t  RELOAD    : 1;  /*!< [b0~b0]*/
                  uint32_t  rev0      : 7;  /*!< [b7~b1]*/
            __IO  uint32_t  MODE      : 2;  /*!< [b9~b8]*/
            __IO  uint32_t  COMPLW    : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  RBITW     : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  RBYTEW    : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  COMPLR    : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  RBITR     : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  RBYTER    : 1;  /*!< [b15~b15]*/
                  uint32_t  rev1      :16;  /*!< [b31~b16]*/
        }BIT;
    }CR;                               /*!< 0004H */
    __IO uint32_t  INIT;                                    /*!< 0008H */
}CRC_TypeDef;


/**
*@brief RAMBIST_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  RAMADR    :14;  /*!< [b13~b0]*/
                  uint32_t  rev0      :14;  /*!< [b27~b14]*/
            __IO  uint32_t  RAMTYP    : 2;  /*!< [b29~b28]*/
                  uint32_t  rev1      : 2;  /*!< [b31~b30]*/
        }BIT;
    }ADDR;                               /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __IO  uint32_t  BLKSZ     : 3;  /*!< [b2~b0]*/
                  uint32_t  rev0      :12;  /*!< [b14~b3]*/
            __IO  uint32_t  SEL       : 1;  /*!< [b15~b15]*/
                  uint32_t  rev1      :16;  /*!< [b31~b16]*/
        }BIT;
    }CFG;                               /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
            __O   uint32_t  RUN       :16;  /*!< [b15~b0]*/
            __IO  uint32_t  MOD       : 1;  /*!< [b16~b16]*/
            __I   uint32_t  BSY       : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  ERR       : 1;  /*!< [b18~b18]*/
                  uint32_t  rev0      :13;  /*!< [b31~b19]*/
        }BIT;
    }CSR;                               /*!< 0008H */
}RAMBIST_TypeDef;


/**
*@brief GPIO_CFG_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
    __IO uint16_t  LCK;                                     /*!< 0000H */
    __O  uint16_t  LOCK;                                    /*!< 0002H */
        }BIT;
    }LCKR;                              /*!< 0000H */
    __IO uint16_t  IE;                                      /*!< 0004H */
         uint16_t  Reserved0;                               /*!< 0006H */
    __IO uint16_t  OTYPER;                                  /*!< 0008H */
         uint16_t  Reserved1;                               /*!< 000AH */
    union {
        __IO  uint32_t  V32;                                /*!< 000CH */
        struct {
            __IO  uint32_t  ODRVR0    : 1;  /*!< [b0~b0]*/
                  uint32_t  rev0      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  ODRVR1    : 1;  /*!< [b2~b2]*/
                  uint32_t  rev1      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  ODRVR2    : 1;  /*!< [b4~b4]*/
                  uint32_t  rev2      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  ODRVR3    : 1;  /*!< [b6~b6]*/
                  uint32_t  rev3      : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  ODRVR4    : 1;  /*!< [b8~b8]*/
                  uint32_t  rev4      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  ODRVR5    : 1;  /*!< [b10~b10]*/
                  uint32_t  rev5      : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  ODRVR6    : 1;  /*!< [b12~b12]*/
                  uint32_t  rev6      : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  ODRVR7    : 1;  /*!< [b14~b14]*/
                  uint32_t  rev7      : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  ODRVR8    : 1;  /*!< [b16~b16]*/
                  uint32_t  rev8      : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  ODRVR9    : 1;  /*!< [b18~b18]*/
                  uint32_t  rev9      : 1;  /*!< [b19~b19]*/
            __IO  uint32_t  ODRVR10   : 1;  /*!< [b20~b20]*/
                  uint32_t  rev10     : 1;  /*!< [b21~b21]*/
            __IO  uint32_t  ODRVR11   : 1;  /*!< [b22~b22]*/
                  uint32_t  rev11     : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  ODRVR12   : 1;  /*!< [b24~b24]*/
                  uint32_t  rev12     : 1;  /*!< [b25~b25]*/
            __IO  uint32_t  ODRVR13   : 1;  /*!< [b26~b26]*/
                  uint32_t  rev13     : 1;  /*!< [b27~b27]*/
            __IO  uint32_t  ODRVR14   : 1;  /*!< [b28~b28]*/
                  uint32_t  rev14     : 1;  /*!< [b29~b29]*/
            __IO  uint32_t  ODRVR15   : 1;  /*!< [b30~b30]*/
                  uint32_t  rev15     : 1;  /*!< [b31~b31]*/
        }BIT;
    }ODRVR;                               /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
            __IO  uint32_t  PHDR0     : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  PLDR0     : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  PHDR1     : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  PLDR1     : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  PHDR2     : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  PLDR2     : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  PHDR3     : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  PLDR3     : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  PHDR4     : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  PLDR4     : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  PHDR5     : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  PLDR5     : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  PHDR6     : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  PLDR6     : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  PHDR7     : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  PLDR7     : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  PHDR8     : 1;  /*!< [b16~b16]*/
            __IO  uint32_t  PLDR8     : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  PHDR9     : 1;  /*!< [b18~b18]*/
            __IO  uint32_t  PLDR9     : 1;  /*!< [b19~b19]*/
            __IO  uint32_t  PHDR10    : 1;  /*!< [b20~b20]*/
            __IO  uint32_t  PLDR10    : 1;  /*!< [b21~b21]*/
            __IO  uint32_t  PHDR11    : 1;  /*!< [b22~b22]*/
            __IO  uint32_t  PLDR11    : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  PHDR12    : 1;  /*!< [b24~b24]*/
            __IO  uint32_t  PLDR12    : 1;  /*!< [b25~b25]*/
            __IO  uint32_t  PHDR13    : 1;  /*!< [b26~b26]*/
            __IO  uint32_t  PLDR13    : 1;  /*!< [b27~b27]*/
            __IO  uint32_t  PHDR14    : 1;  /*!< [b28~b28]*/
            __IO  uint32_t  PLDR14    : 1;  /*!< [b29~b29]*/
            __IO  uint32_t  PHDR15    : 1;  /*!< [b30~b30]*/
            __IO  uint32_t  PLDR15    : 1;  /*!< [b31~b31]*/
        }BIT;
    }PUPDR;                               /*!< 0010H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
            __IO  uint32_t  PA0       : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  PA1       : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  PA2       : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  PA3       : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  PA4       : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  PA5       : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  PA6       : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  PA7       : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  PA8       : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  PA9       : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  PA10      : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  PA11      : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  PA12      : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  PA13      : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  PA14      : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  PA15      : 1;  /*!< [b15~b15]*/
                  uint32_t  rev0      :16;  /*!< [b31~b16]*/
        }BIT;
    }TTLEN;                               /*!< 0014H */
    union {
        __IO  uint32_t  V32;                                /*!< 0018H */
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
    }AFRL;                               /*!< 0018H */
    union {
        __IO  uint32_t  V32;                                /*!< 001CH */
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
    }AFRH;                               /*!< 001CH */
}GPIO_CFG_TypeDef;


/**
*@brief GPIO_IOD_registers
*/
typedef struct
{
//         uint32_t  Reserved0[128];                          /*!< 0000H */
    __IO uint16_t  MODER;                                   /*!< 0200H */
         uint16_t  Reserved1;                               /*!< 0202H */
    __I  uint16_t  IDR;                                     /*!< 0204H */
         uint16_t  Reserved2;                               /*!< 0206H */
    __IO uint16_t  ODR;                                     /*!< 0208H */
         uint16_t  Reserved3;                               /*!< 020AH */
    union {
        __IO  uint32_t  V32;                                /*!< 020CH */
        struct {
    __O  uint16_t  BS;                                      /*!< 020CH */
    __O  uint16_t  BR;                                      /*!< 020EH */
        }BIT;
    }BSRR;                              /*!< 020CH */
}GPIO_TypeDef;


/**
*@brief PCA_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  PR        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  CASCEN    : 1;  /*!< [b1~b1]*/
                  uint32_t  rev0      :30;  /*!< [b31~b2]*/
        }BIT;
    }CR;                               /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __IO  uint32_t  CPS       : 3;  /*!< [b2~b0]*/
            __IO  uint32_t  SDEN      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  ECF       : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  CF0DMA    : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  CF1DMA    : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  CFDMA     : 1;  /*!< [b7~b7]*/
                  uint32_t  rev0      :24;  /*!< [b31~b8]*/
        }BIT;
    }CMD;                               /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
            __IO  uint32_t  ECCF0     : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  MAT0      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  TCP0      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  ECOM0     : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  FS0       : 2;  /*!< [b5~b4]*/
            __IO  uint32_t  SM0       : 2;  /*!< [b7~b6]*/
                  uint32_t  rev0      :24;  /*!< [b31~b8]*/
        }BIT;
    }CPM0;                               /*!< 0008H */
    union {
        __IO  uint32_t  V32;                                /*!< 000CH */
        struct {
            __IO  uint32_t  ECCF1     : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  MAT1      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  TCP1      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  ECOM1     : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  FS1       : 2;  /*!< [b5~b4]*/
            __IO  uint32_t  SM1       : 2;  /*!< [b7~b6]*/
                  uint32_t  rev0      :24;  /*!< [b31~b8]*/
        }BIT;
    }CPM1;                               /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
            __IO  uint32_t  FCO0      : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  FCO1      : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  OSC0      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  OSC1      : 1;  /*!< [b3~b3]*/
                  uint32_t  rev0      :28;  /*!< [b31~b4]*/
        }BIT;
    }FORCE;                               /*!< 0010H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
    __IO uint8_t   TOPL;                                    /*!< 0014H */
    __IO uint8_t   TOPH;                                    /*!< 0015H */
    __IO uint16_t  TOPCAS;                                  /*!< 0016H */
        }BIT;
    }TOPR;                              /*!< 0014H */
    union {
        __IO  uint32_t  V32;                                /*!< 0018H */
        struct {
    __IO uint8_t   CPL0;                                    /*!< 0018H */
    __IO uint8_t   CPH0;                                    /*!< 0019H */
    __IO uint16_t  CP0CAS;                                  /*!< 001AH */
        }BIT;
    }CPR0;                              /*!< 0018H */
    union {
        __IO  uint32_t  V32;                                /*!< 001CH */
        struct {
    __IO uint8_t   CPL1;                                    /*!< 001CH */
    __IO uint8_t   CPH1;                                    /*!< 001DH */
    __IO uint16_t  CP1CAS;                                  /*!< 001EH */
        }BIT;
    }CPR1;                              /*!< 001CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0020H */
        struct {
            __I   uint32_t  CCF0      : 1;  /*!< [b0~b0]*/
            __I   uint32_t  CCF1      : 1;  /*!< [b1~b1]*/
            __I   uint32_t  CF        : 1;  /*!< [b2~b2]*/
            __O   uint32_t  CCF0C     : 1;  /*!< [b3~b3]*/
            __O   uint32_t  CCF1C     : 1;  /*!< [b4~b4]*/
            __O   uint32_t  CFC       : 1;  /*!< [b5~b5]*/
                  uint32_t  rev0      :26;  /*!< [b31~b6]*/
        }BIT;
    }PCAINTF;                               /*!< 0020H */
}PCA_TypeDef;


/**
*@brief EXTI_registers
*/
typedef struct
{
    __IO uint16_t  IMR;                                     /*!< 0000H */
         uint16_t  Reserved0;                               /*!< 0002H */
    __IO uint16_t  EMR;                                     /*!< 0004H */
         uint16_t  Reserved1;                               /*!< 0006H */
    __IO uint16_t  TMSR;                                    /*!< 0008H */
         uint16_t  Reserved2;                               /*!< 000AH */
    __IO uint16_t  RTSR;                                    /*!< 000CH */
         uint16_t  Reserved3;                               /*!< 000EH */
    __IO uint16_t  FTSR;                                    /*!< 0010H */
         uint16_t  Reserved4;                               /*!< 0012H */
    __O  uint16_t  SWIER;                                   /*!< 0014H */
         uint16_t  Reserved5;                               /*!< 0016H */
    union {
        __IO  uint32_t  V32;                                /*!< 0018H */
        struct {
    __I  uint16_t  PR;                                      /*!< 0018H */
    __O  uint16_t  PRC;                                     /*!< 001AH */
        }BIT;
    }PR;                              /*!< 0018H */
    union {
        __IO  uint32_t  V32;                                /*!< 001CH */
        struct {
            __IO  uint32_t  EXTI0     : 3;  /*!< [b2~b0]*/
                  uint32_t  rev0      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  EXTI1     : 3;  /*!< [b6~b4]*/
                  uint32_t  rev1      : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  EXTI2     : 3;  /*!< [b10~b8]*/
                  uint32_t  rev2      : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  EXTI3     : 3;  /*!< [b14~b12]*/
                  uint32_t  rev3      : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  EXTI4     : 3;  /*!< [b18~b16]*/
                  uint32_t  rev4      : 1;  /*!< [b19~b19]*/
            __IO  uint32_t  EXTI5     : 3;  /*!< [b22~b20]*/
                  uint32_t  rev5      : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  EXTI6     : 3;  /*!< [b26~b24]*/
                  uint32_t  rev6      : 1;  /*!< [b27~b27]*/
            __IO  uint32_t  EXTI7     : 3;  /*!< [b30~b28]*/
                  uint32_t  rev7      : 1;  /*!< [b31~b31]*/
        }BIT;
    }CFGL;                               /*!< 001CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0020H */
        struct {
            __IO  uint32_t  EXTI8     : 3;  /*!< [b2~b0]*/
                  uint32_t  rev0      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  EXTI9     : 3;  /*!< [b6~b4]*/
                  uint32_t  rev1      : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  EXTI10    : 3;  /*!< [b10~b8]*/
                  uint32_t  rev2      : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  EXTI11    : 3;  /*!< [b14~b12]*/
                  uint32_t  rev3      : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  EXTI12    : 3;  /*!< [b18~b16]*/
                  uint32_t  rev4      : 1;  /*!< [b19~b19]*/
            __IO  uint32_t  EXTI13    : 3;  /*!< [b22~b20]*/
                  uint32_t  rev5      : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  EXTI14    : 3;  /*!< [b26~b24]*/
                  uint32_t  rev6      : 1;  /*!< [b27~b27]*/
            __IO  uint32_t  EXTI15    : 3;  /*!< [b30~b28]*/
                  uint32_t  rev7      : 1;  /*!< [b31~b31]*/
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
            __IO  uint32_t  SN5       : 2;  /*!< [b21~b20]*/
            __IO  uint32_t  PS5       : 2;  /*!< [b23~b22]*/
            __IO  uint32_t  SN6       : 2;  /*!< [b25~b24]*/
            __IO  uint32_t  PS6       : 2;  /*!< [b27~b26]*/
            __IO  uint32_t  SN7       : 2;  /*!< [b29~b28]*/
            __IO  uint32_t  PS7       : 2;  /*!< [b31~b30]*/
        }BIT;
    }SAMPL;                               /*!< 0024H */
    union {
        __IO  uint32_t  V32;                                /*!< 0028H */
        struct {
            __IO  uint32_t  SN8       : 2;  /*!< [b1~b0]*/
            __IO  uint32_t  PS8       : 2;  /*!< [b3~b2]*/
            __IO  uint32_t  SN9       : 2;  /*!< [b5~b4]*/
            __IO  uint32_t  PS9       : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  SN10      : 2;  /*!< [b9~b8]*/
            __IO  uint32_t  PS10      : 2;  /*!< [b11~b10]*/
            __IO  uint32_t  SN11      : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  PS11      : 2;  /*!< [b15~b14]*/
            __IO  uint32_t  SN12      : 2;  /*!< [b17~b16]*/
            __IO  uint32_t  PS12      : 2;  /*!< [b19~b18]*/
            __IO  uint32_t  SN13      : 2;  /*!< [b21~b20]*/
            __IO  uint32_t  PS13      : 2;  /*!< [b23~b22]*/
            __IO  uint32_t  SN14      : 2;  /*!< [b25~b24]*/
            __IO  uint32_t  PS14      : 2;  /*!< [b27~b26]*/
            __IO  uint32_t  SN15      : 2;  /*!< [b29~b28]*/
            __IO  uint32_t  PS15      : 2;  /*!< [b31~b30]*/
        }BIT;
    }SAMPH;                               /*!< 0028H */
    __IO uint16_t  DMR;                                     /*!< 002CH */
         uint16_t  Reserved6;                               /*!< 002EH */
}EXTI_TypeDef;


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
            __IO  uint32_t  EPWMB     : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  EPWMA     : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  PWMDMA    : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  FLTDMA    : 1;  /*!< [b13~b13]*/
                  uint32_t  rev0      :18;  /*!< [b31~b14]*/
        }BIT;
    }CR;                               /*!< 0000H */
    __IO uint16_t  PWMLOCK;                                 /*!< 0004H */
         uint16_t  Reserved0;                               /*!< 0006H */
    __IO uint16_t  PWMPR;                                   /*!< 0008H */
         uint16_t  Reserved1;                               /*!< 000AH */
    __IO uint16_t  PWMDR;                                   /*!< 000CH */
         uint16_t  Reserved2;                               /*!< 000EH */
    __IO uint16_t  PWMDTR;                                  /*!< 0010H */
         uint16_t  Reserved3;                               /*!< 0012H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
            __I   uint32_t  FLTS      : 1;  /*!< [b0~b0]*/
            __I   uint32_t  PWMIF     : 1;  /*!< [b1~b1]*/
            __O   uint32_t  FLTSC     : 1;  /*!< [b2~b2]*/
            __O   uint32_t  PWMIFC    : 1;  /*!< [b3~b3]*/
                  uint32_t  rev0      :28;  /*!< [b31~b4]*/
        }BIT;
    }PWMINTF;                               /*!< 0014H */
}PWM_TypeDef;


/**
*@brief PCA_L_registers
*/
//typedef struct
//{
//    union {
//        __IO  uint32_t  V32;                                /*!< 0000H */
//        struct {
//            __IO  uint32_t  PR        : 1;  /*!< [b0~b0]*/
//            __IO  uint32_t  CASCEN    : 1;  /*!< [b1~b1]*/
//                  uint32_t  rev0      :30;  /*!< [b31~b2]*/
//        }BIT;
//    }CR;                               /*!< 0000H */
//    union {
//        __IO  uint32_t  V32;                                /*!< 0004H */
//        struct {
//            __IO  uint32_t  CPS       : 3;  /*!< [b2~b0]*/
//            __IO  uint32_t  SDEN      : 1;  /*!< [b3~b3]*/
//            __IO  uint32_t  ECF       : 1;  /*!< [b4~b4]*/
//            __IO  uint32_t  CF0DMA    : 1;  /*!< [b5~b5]*/
//            __IO  uint32_t  CF1DMA    : 1;  /*!< [b6~b6]*/
//            __IO  uint32_t  CFDMA     : 1;  /*!< [b7~b7]*/
//                  uint32_t  rev0      :24;  /*!< [b31~b8]*/
//        }BIT;
//    }CMD;                               /*!< 0004H */
//    union {
//        __IO  uint32_t  V32;                                /*!< 0008H */
//        struct {
//            __IO  uint32_t  ECCF0     : 1;  /*!< [b0~b0]*/
//            __IO  uint32_t  MAT0      : 1;  /*!< [b1~b1]*/
//            __IO  uint32_t  TCP0      : 1;  /*!< [b2~b2]*/
//            __IO  uint32_t  ECOM0     : 1;  /*!< [b3~b3]*/
//            __IO  uint32_t  FS0       : 2;  /*!< [b5~b4]*/
//            __IO  uint32_t  SM0       : 2;  /*!< [b7~b6]*/
//                  uint32_t  rev0      :24;  /*!< [b31~b8]*/
//        }BIT;
//    }CPM0;                               /*!< 0008H */
//    union {
//        __IO  uint32_t  V32;                                /*!< 000CH */
//        struct {
//            __IO  uint32_t  ECCF1     : 1;  /*!< [b0~b0]*/
//            __IO  uint32_t  MAT1      : 1;  /*!< [b1~b1]*/
//            __IO  uint32_t  TCP1      : 1;  /*!< [b2~b2]*/
//            __IO  uint32_t  ECOM1     : 1;  /*!< [b3~b3]*/
//            __IO  uint32_t  FS1       : 2;  /*!< [b5~b4]*/
//            __IO  uint32_t  SM1       : 2;  /*!< [b7~b6]*/
//                  uint32_t  rev0      :24;  /*!< [b31~b8]*/
//        }BIT;
//    }CPM1;                               /*!< 000CH */
//    union {
//        __IO  uint32_t  V32;                                /*!< 0010H */
//        struct {
//            __IO  uint32_t  FCO0      : 1;  /*!< [b0~b0]*/
//            __IO  uint32_t  FCO1      : 1;  /*!< [b1~b1]*/
//            __IO  uint32_t  OSC0      : 1;  /*!< [b2~b2]*/
//            __IO  uint32_t  OSC1      : 1;  /*!< [b3~b3]*/
//                  uint32_t  rev0      :28;  /*!< [b31~b4]*/
//        }BIT;
//    }FORCE;                               /*!< 0010H */
//    union {
//        __IO  uint32_t  V32;                                /*!< 0014H */
//        struct {
//    __IO uint8_t   TOPL;                                    /*!< 0014H */
//    __IO uint8_t   TOPH;                                    /*!< 0015H */
//    __IO uint16_t  TOPCAS;                                  /*!< 0016H */
//        }BIT;
//    }TOPR;                              /*!< 0014H */
//    union {
//        __IO  uint32_t  V32;                                /*!< 0018H */
//        struct {
//    __IO uint8_t   CPL0;                                    /*!< 0018H */
//    __IO uint8_t   CPH0;                                    /*!< 0019H */
//    __IO uint16_t  CP0CAS;                                  /*!< 001AH */
//        }BIT;
//    }CPR0;                              /*!< 0018H */
//    union {
//        __IO  uint32_t  V32;                                /*!< 001CH */
//        struct {
//    __IO uint8_t   CPL1;                                    /*!< 001CH */
//    __IO uint8_t   CPH1;                                    /*!< 001DH */
//    __IO uint16_t  CP1CAS;                                  /*!< 001EH */
//        }BIT;
//    }CPR1;                              /*!< 001CH */
//    union {
//        __IO  uint32_t  V32;                                /*!< 0020H */
//        struct {
//            __I   uint32_t  CCF0      : 1;  /*!< [b0~b0]*/
//            __I   uint32_t  CCF1      : 1;  /*!< [b1~b1]*/
//            __I   uint32_t  CF        : 1;  /*!< [b2~b2]*/
//            __O   uint32_t  CCF0C     : 1;  /*!< [b3~b3]*/
//            __O   uint32_t  CCF1C     : 1;  /*!< [b4~b4]*/
//            __O   uint32_t  CFC       : 1;  /*!< [b5~b5]*/
//                  uint32_t  rev0      :26;  /*!< [b31~b6]*/
//        }BIT;
//    }PCAINTF;                               /*!< 0020H */
//}PCA_L_TypeDef;


/**
*@brief TIMER_registers
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
            __IO  uint32_t  IE        : 1;  /*!< [b6~b6]*/
                  uint32_t  rev1      : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  TRIGEN    : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  ETEN      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  TC        : 1;  /*!< [b10~b10]*/
                  uint32_t  rev2      : 4;  /*!< [b14~b11]*/
            __IO  uint32_t  CASCEN    : 1;  /*!< [b15~b15]*/
                  uint32_t  rev3      :16;  /*!< [b31~b16]*/
        }BIT;
    }CR;                               /*!< 0000H */
    __IO uint32_t  TCNT;                                    /*!< 0004H */
    __IO uint32_t  TPR;                                     /*!< 0008H */
    __IO uint32_t  PSQ;                                     /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
            __I   uint32_t  TF        : 1;  /*!< [b0~b0]*/
                  uint32_t  rev0      :15;  /*!< [b15~b1]*/
            __O   uint32_t  TFC       : 1;  /*!< [b16~b16]*/
                  uint32_t  rev1      :15;  /*!< [b31~b17]*/
        }BIT;
    }TIMINTF;                               /*!< 0010H */
}TIMER_TypeDef;


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
    __O  uint16_t  CLR;                                     /*!< 0004H */
         uint16_t  Reserved0;                               /*!< 0006H */
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
                  uint32_t  rev0      : 3;  /*!< [b13~b11]*/
            __IO  uint32_t  WWDTIE    : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  WWDTON    : 1;  /*!< [b15~b15]*/
            __O   uint32_t  LOCK      :16;  /*!< [b31~b16]*/
        }BIT;
    }CR;                               /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __I   uint32_t  TCNT      : 8;  /*!< [b7~b0]*/
                  uint32_t  rev0      : 7;  /*!< [b14~b8]*/
            __IO  uint32_t  WWDTIF    : 1;  /*!< [b15~b15]*/
                  uint32_t  rev1      :16;  /*!< [b31~b16]*/
        }BIT;
    }SR;                               /*!< 0004H */
    __O  uint16_t  CLR;                                     /*!< 0008H */
         uint16_t  Reserved0;                               /*!< 000AH */
    union {
        __IO  uint32_t  V32;                                /*!< 000CH */
        struct {
    __IO uint8_t   WWDTWTR;                                 /*!< 000CH */
         uint8_t   rev0;                                    /*!< 000DH */
    __O  uint16_t  LOCK;                                    /*!< 000EH */
        }BIT;
    }WTR;                              /*!< 000CH */
}WWDT_TypeDef;


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
                  uint32_t  rev0      : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  ADSTRS    : 6;  /*!< [b14~b9]*/
            __IO  uint32_t  ADON      : 1;  /*!< [b15~b15]*/
                  uint32_t  rev1      :16;  /*!< [b31~b16]*/
        }BIT;
    }ADCON1;                               /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __IO  uint32_t  TADC      : 4;  /*!< [b3~b0]*/
            __IO  uint32_t  ADMAXCH   : 3;  /*!< [b6~b4]*/
                  uint32_t  rev0      : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  TS        : 4;  /*!< [b11~b8]*/
                  uint32_t  rev1      : 4;  /*!< [b15~b12]*/
            __IO  uint32_t  TGAP      : 3;  /*!< [b18~b16]*/
                  uint32_t  rev2      :13;  /*!< [b31~b19]*/
        }BIT;
    }ADCON2;                               /*!< 0004H */
    __IO uint8_t   ADPCH;                                   /*!< 0008H */
         uint8_t   Reserved0[3];                            /*!< 0009H */
    __I  uint16_t  ADDR0;                                   /*!< 000CH */
         uint16_t  Reserved1;                               /*!< 000EH */
    __I  uint16_t  ADDR1;                                   /*!< 0010H */
         uint16_t  Reserved2;                               /*!< 0012H */
    __I  uint16_t  ADDR2;                                   /*!< 0014H */
         uint16_t  Reserved3;                               /*!< 0016H */
    __I  uint16_t  ADDR3;                                   /*!< 0018H */
         uint16_t  Reserved4;                               /*!< 001AH */
    __I  uint16_t  ADDR4;                                   /*!< 001CH */
         uint16_t  Reserved5;                               /*!< 001EH */
    __I  uint16_t  ADDR5;                                   /*!< 0020H */
         uint16_t  Reserved6;                               /*!< 0022H */
    __I  uint16_t  ADDR6;                                   /*!< 0024H */
         uint16_t  Reserved7;                               /*!< 0026H */
    __I  uint16_t  ADDR7;                                   /*!< 0028H */
         uint16_t  Reserved8;                               /*!< 002AH */
    union {
        __IO  uint32_t  V32;                                /*!< 002CH */
        struct {
            __IO  uint32_t  CSEL      : 3;  /*!< [b2~b0]*/
                  uint32_t  rev0      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  ADLDE     : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  ADLIE     : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  ADGDE     : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  ADGIE     : 1;  /*!< [b7~b7]*/
                  uint32_t  rev1      :24;  /*!< [b31~b8]*/
        }BIT;
    }ADCMPCON;                               /*!< 002CH */
    __IO uint16_t  ADDGT;                                   /*!< 0030H */
         uint16_t  Reserved9;                               /*!< 0032H */
    __IO uint16_t  ADDLT;                                   /*!< 0034H */
         uint16_t  Reserved10;                              /*!< 0036H */
    union {
        __IO  uint32_t  V32;                                /*!< 0038H */
        struct {
            __IO  uint32_t  SEQCH0    : 5;  /*!< [b4~b0]*/
                  uint32_t  rev0      : 3;  /*!< [b7~b5]*/
            __IO  uint32_t  SEQCH1    : 5;  /*!< [b12~b8]*/
                  uint32_t  rev1      : 3;  /*!< [b15~b13]*/
            __IO  uint32_t  SEQCH2    : 5;  /*!< [b20~b16]*/
                  uint32_t  rev2      : 3;  /*!< [b23~b21]*/
            __IO  uint32_t  SEQCH3    : 5;  /*!< [b28~b24]*/
                  uint32_t  rev3      : 3;  /*!< [b31~b29]*/
        }BIT;
    }SEQCHSEL0;                               /*!< 0038H */
    union {
        __IO  uint32_t  V32;                                /*!< 003CH */
        struct {
            __IO  uint32_t  SEQCH4    : 5;  /*!< [b4~b0]*/
                  uint32_t  rev0      : 3;  /*!< [b7~b5]*/
            __IO  uint32_t  SEQCH5    : 5;  /*!< [b12~b8]*/
                  uint32_t  rev1      : 3;  /*!< [b15~b13]*/
            __IO  uint32_t  SEQCH6    : 5;  /*!< [b20~b16]*/
                  uint32_t  rev2      : 3;  /*!< [b23~b21]*/
            __IO  uint32_t  SEQCH7    : 5;  /*!< [b28~b24]*/
                  uint32_t  rev3      : 3;  /*!< [b31~b29]*/
        }BIT;
    }SEQCHSEL1;                               /*!< 003CH */
    __IO uint8_t   ADGAPON;                                 /*!< 0040H */
         uint8_t   Reserved11[3];                           /*!< 0041H */
    union {
        __IO  uint32_t  V32;                                /*!< 0044H */
        struct {
            __I   uint32_t  ADLIF     : 1;  /*!< [b0~b0]*/
            __I   uint32_t  ADGIF     : 1;  /*!< [b1~b1]*/
            __I   uint32_t  ADIF      : 1;  /*!< [b2~b2]*/
                  uint32_t  rev0      :13;  /*!< [b15~b3]*/
            __O   uint32_t  ADLIFC    : 1;  /*!< [b16~b16]*/
            __O   uint32_t  ADGIFC    : 1;  /*!< [b17~b17]*/
            __O   uint32_t  ADIFC     : 1;  /*!< [b18~b18]*/
                  uint32_t  rev1      :13;  /*!< [b31~b19]*/
        }BIT;
    }ADINTF;                               /*!< 0044H */
}ADC_TypeDef;


/**
*@brief TPS_registers
*/
typedef struct
{
         uint32_t  Reserved0[1];                            /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __IO  uint32_t  VREFEN    : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  VREFSEL   : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  CHOPS     : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  CHOPEN    : 1;  /*!< [b3~b3]*/
                  uint32_t  rev0      :28;  /*!< [b31~b4]*/
        }BIT;
    }AVREFCON;                               /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
            __IO  uint32_t  TPSEN     : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  TPSCHOP   : 1;  /*!< [b1~b1]*/
                  uint32_t  rev0      :30;  /*!< [b31~b2]*/
        }BIT;
    }TPSCON;                               /*!< 0008H */
}TPS_TypeDef;


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
                  uint32_t  rev0      : 8;  /*!< [b15~b8]*/
            __O   uint32_t  RIC       : 1;  /*!< [b16~b16]*/
                  uint32_t  rev1      : 1;  /*!< [b17~b17]*/
            __O   uint32_t  TCC       : 1;  /*!< [b18~b18]*/
            __O   uint32_t  TXCOLC    : 1;  /*!< [b19~b19]*/
            __O   uint32_t  RXOVC     : 1;  /*!< [b20~b20]*/
            __O   uint32_t  FEC       : 1;  /*!< [b21~b21]*/
            __O   uint32_t  PEC       : 1;  /*!< [b22~b22]*/
            __O   uint32_t  LBDC      : 1;  /*!< [b23~b23]*/
                  uint32_t  rev2      : 8;  /*!< [b31~b24]*/
        }BIT;
    }FR;                               /*!< 0000H */
         uint32_t  Reserved0[1];                            /*!< 0004H */
    __IO uint8_t   TDR;                                     /*!< 0008H */
         uint8_t   Reserved1[3];                            /*!< 0009H */
    __I  uint8_t   RDR;                                     /*!< 000CH */
         uint8_t   Reserved2[3];                            /*!< 000DH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
    __IO uint8_t   SADDR;                                   /*!< 0010H */
    __IO uint8_t   SMAR;                                    /*!< 0011H */
         uint16_t  rev0;                                    /*!< 0012H */
        }BIT;
    }ADDR;                              /*!< 0010H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
            __IO  uint32_t  SBRT      :15;  /*!< [b14~b0]*/
                  uint32_t  rev0      : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  BFINE     : 4;  /*!< [b19~b16]*/
                  uint32_t  rev1      :12;  /*!< [b31~b20]*/
        }BIT;
    }BRT;                               /*!< 0014H */
    union {
        __IO  uint32_t  V32;                                /*!< 0018H */
        struct {
            __IO  uint32_t  STOP      : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  SBRTEN    : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  SMOD      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  RIE       : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  TIE       : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  TCIE      : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  LBDIE     : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  LBDL      : 1;  /*!< [b7~b7]*/
            __I   uint32_t  RB8       : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  TB8       : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  PS        : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  PCE       : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  SM2       : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  SM        : 2;  /*!< [b14~b13]*/
            __IO  uint32_t  SBK       : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  LINEN     : 1;  /*!< [b16~b16]*/
            __IO  uint32_t  REN       : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  TEN       : 1;  /*!< [b18~b18]*/
            __IO  uint32_t  DMAR      : 1;  /*!< [b19~b19]*/
            __IO  uint32_t  DMAT      : 1;  /*!< [b20~b20]*/
                  uint32_t  rev0      :11;  /*!< [b31~b21]*/
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
                  uint32_t  rev0      :10;  /*!< [b15~b6]*/
            __O   uint32_t  SPRIC     : 1;  /*!< [b16~b16]*/
            __O   uint32_t  SPTIC     : 1;  /*!< [b17~b17]*/
            __O   uint32_t  rev1      : 1;  /*!< [b18~b18]*/
            __O   uint32_t  MODFC     : 1;  /*!< [b19~b19]*/
            __O   uint32_t  RXOVC     : 1;  /*!< [b20~b20]*/
            __O   uint32_t  WCOLC     : 1;  /*!< [b21~b21]*/
                  uint32_t  rev2      :10;  /*!< [b31~b22]*/
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
            __IO  uint32_t  SPDATL    : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  SPRIE     : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  SPTIE     : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  SPDMAR    : 1;  /*!< [b12~b12]*/
            __IO  uint32_t  SPDMAT    : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  SPIEN     : 1;  /*!< [b14~b14]*/
            __IO  uint32_t  SPSFF     : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  SPDATW    : 1;  /*!< [b16~b16]*/
                  uint32_t  rev0      :15;  /*!< [b31~b17]*/
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
                  uint32_t  rev0      : 1;  /*!< [b1~b1]*/
            __I   uint32_t  TFREE     : 1;  /*!< [b2~b2]*/
            __I   uint32_t  TOUT      : 1;  /*!< [b3~b3]*/
                  uint32_t  rev1      :12;  /*!< [b15~b4]*/
            __O   uint32_t  TWINTC    : 1;  /*!< [b16~b16]*/
                  uint32_t  rev2      : 1;  /*!< [b17~b17]*/
            __O   uint32_t  TFREEC    : 1;  /*!< [b18~b18]*/
            __O   uint32_t  TOUTC     : 1;  /*!< [b19~b19]*/
                  uint32_t  rev3      :12;  /*!< [b31~b20]*/
        }BIT;
    }FR;                               /*!< 0000H */
    union {
        __I   uint32_t  V32;                                /*!< 0004H */
        struct {
                  uint32_t  rev0      : 3;  /*!< [b2~b0]*/
            __I   uint32_t  SR        : 5;  /*!< [b7~b3]*/
                  uint32_t  rev1      :24;  /*!< [b31~b8]*/
        }BIT;
    }STAT;                               /*!< 0004H */
    __IO uint8_t   HOC;                                     /*!< 0008H */
         uint8_t   Reserved0[3];                            /*!< 0009H */
    __IO uint8_t   BRT;                                     /*!< 000CH */
         uint8_t   Reserved1[3];                            /*!< 000DH */
    __IO uint8_t   DR;                                      /*!< 0010H */
         uint8_t   Reserved2[3];                            /*!< 0011H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
            __IO  uint32_t  GC        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  ADDR      : 7;  /*!< [b7~b1]*/
                  uint32_t  rev0      : 9;  /*!< [b16~b8]*/
            __IO  uint32_t  TWIAMR    : 7;  /*!< [b23~b17]*/
                  uint32_t  rev1      : 8;  /*!< [b31~b24]*/
        }BIT;
    }ADDR;                               /*!< 0014H */
    union {
        __IO  uint32_t  V32;                                /*!< 0018H */
        struct {
            __IO  uint32_t  AA        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  STO       : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  STA       : 1;  /*!< [b2~b2]*/
                  uint32_t  rev0      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  CR        : 2;  /*!< [b5~b4]*/
            __IO  uint32_t  CNT       : 2;  /*!< [b7~b6]*/
            __IO  uint32_t  EFREE     : 1;  /*!< [b8~b8]*/
            __IO  uint32_t  ETOT      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  TWINTE    : 1;  /*!< [b10~b10]*/
                  uint32_t  rev1      : 4;  /*!< [b14~b11]*/
            __IO  uint32_t  TWIEN     : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  rev2      :16;  /*!< [b31~b16]*/
        }BIT;
    }CR;                               /*!< 0018H */
}TWI_TypeDef;


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
            __IO  uint32_t  VOL       : 4;  /*!< [b8~b5]*/
            __IO  uint32_t  ELCC      : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  MODSW     : 1;  /*!< [b10~b10]*/
            __IO  uint32_t  RLCD      : 1;  /*!< [b11~b11]*/
            __IO  uint32_t  MOD       : 2;  /*!< [b13~b12]*/
            __IO  uint32_t  FCCTL     : 2;  /*!< [b15~b14]*/
            __IO  uint32_t  CNTMOD    : 1;  /*!< [b16~b16]*/
            __IO  uint32_t  DCK       : 2;  /*!< [b18~b17]*/
                  uint32_t  rev0      :13;  /*!< [b31~b19]*/
        }BIT;
    }CR;                               /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
    __IO uint8_t   LCDCOM;                                  /*!< 0004H */
    __IO uint8_t   LCDSEG1;                                 /*!< 0005H */
    __IO uint8_t   LCDSEG2;                                 /*!< 0006H */
    __IO uint8_t   LCDSEG3;                                 /*!< 0007H */
        }BIT;
    }LCDSHARE;                              /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
            __IO  uint32_t  LCDSEG4   : 8;  /*!< [b7~b0]*/
            __IO  uint32_t  LCDSEG5   : 4;  /*!< [b11~b8]*/
                  uint32_t  rev0      :20;  /*!< [b31~b12]*/
        }BIT;
    }LCDSHARE1;                               /*!< 0008H */
         uint32_t  Reserved0[1];                            /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
    __IO uint8_t   LCDBUF0;                                 /*!< 0010H */
    __IO uint8_t   LCDBUF1;                                 /*!< 0011H */
    __IO uint8_t   LCDBUF2;                                 /*!< 0012H */
    __IO uint8_t   LCDBUF3;                                 /*!< 0013H */
        }BIT;
    }LCD_BUFS0;                              /*!< 0010H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
    __IO uint8_t   LCDBUF4;                                 /*!< 0014H */
    __IO uint8_t   LCDBUF5;                                 /*!< 0015H */
    __IO uint8_t   LCDBUF6;                                 /*!< 0016H */
    __IO uint8_t   LCDBUF7;                                 /*!< 0017H */
        }BIT;
    }LCD_BUFS1;                              /*!< 0014H */
    union {
        __IO  uint32_t  V32;                                /*!< 0018H */
        struct {
    __IO uint8_t   LCDBUF8;                                 /*!< 0018H */
    __IO uint8_t   LCDBUF9;                                 /*!< 0019H */
    __IO uint8_t   LCDBUF10;                                /*!< 001AH */
    __IO uint8_t   LCDBUF11;                                /*!< 001BH */
        }BIT;
    }LCD_BUFS2;                              /*!< 0018H */
    union {
        __IO  uint32_t  V32;                                /*!< 001CH */
        struct {
    __IO uint8_t   LCDBUF12;                                /*!< 001CH */
    __IO uint8_t   LCDBUF13;                                /*!< 001DH */
    __IO uint8_t   LCDBUF14;                                /*!< 001EH */
    __IO uint8_t   LCDBUF15;                                /*!< 001FH */
        }BIT;
    }LCD_BUFS3;                              /*!< 001CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0020H */
        struct {
    __IO uint8_t   LCDBUF16;                                /*!< 0020H */
    __IO uint8_t   LCDBUF17;                                /*!< 0021H */
    __IO uint8_t   LCDBUF18;                                /*!< 0022H */
    __IO uint8_t   LCDBUF19;                                /*!< 0023H */
        }BIT;
    }LCD_BUFS4;                              /*!< 0020H */
    union {
        __IO  uint32_t  V32;                                /*!< 0024H */
        struct {
    __IO uint8_t   LCDBUF20;                                /*!< 0024H */
    __IO uint8_t   LCDBUF21;                                /*!< 0025H */
    __IO uint8_t   LCDBUF22;                                /*!< 0026H */
    __IO uint8_t   LCDBUF23;                                /*!< 0027H */
        }BIT;
    }LCD_BUFS5;                              /*!< 0024H */
    union {
        __IO  uint32_t  V32;                                /*!< 0028H */
        struct {
    __IO uint8_t   LCDBUF24;                                /*!< 0028H */
    __IO uint8_t   LCDBUF25;                                /*!< 0029H */
    __IO uint8_t   LCDBUF26;                                /*!< 002AH */
    __IO uint8_t   LCDBUF27;                                /*!< 002BH */
        }BIT;
    }LCD_BUFS6;                              /*!< 0028H */
    union {
        __IO  uint32_t  V32;                                /*!< 002CH */
        struct {
    __IO uint8_t   LCDBUF28;                                /*!< 002CH */
    __IO uint8_t   LCDBUF29;                                /*!< 002DH */
    __IO uint8_t   LCDBUF30;                                /*!< 002EH */
    __IO uint8_t   LCDBUF31;                                /*!< 002FH */
        }BIT;
    }LCD_BUFS7;                              /*!< 002CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0030H */
        struct {
    __IO uint8_t   LCDBUF32;                                /*!< 0030H */
    __IO uint8_t   LCDBUF33;                                /*!< 0031H */
    __IO uint8_t   LCDBUF34;                                /*!< 0032H */
    __IO uint8_t   LCDBUF35;                                /*!< 0033H */
        }BIT;
    }LCD_BUFS8;                              /*!< 0030H */
    union {
        __IO  uint32_t  V32;                                /*!< 0034H */
        struct {
    __IO uint8_t   LCDBUF36;                                /*!< 0034H */
    __IO uint8_t   LCDBUF37;                                /*!< 0035H */
    __IO uint8_t   LCDBUF38;                                /*!< 0036H */
    __IO uint8_t   LCDBUF39;                                /*!< 0037H */
        }BIT;
    }LCD_BUFS9;                              /*!< 0034H */
}LCD_TypeDef;


/**
*@brief LED_registers
*/
typedef struct
{
    union {
        __IO  uint32_t  V32;                                /*!< 0000H */
        struct {
            __IO  uint32_t  EN        : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  LEDMD     : 1;  /*!< [b1~b1]*/
            __IO  uint32_t  MODE      : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  MODSW     : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  IE        : 1;  /*!< [b4~b4]*/
            __IO  uint32_t  LEDMODSEL : 1;  /*!< [b5~b5]*/
            __IO  uint32_t  LEDFY     : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  LEDCY     : 1;  /*!< [b7~b7]*/
            __IO  uint32_t  DISCOM    : 8;  /*!< [b15~b8]*/
            __IO  uint32_t  LEDDZ     : 8;  /*!< [b23~b16]*/
            __IO  uint32_t  CNTMOD    : 1;  /*!< [b24~b24]*/
            __IO  uint32_t  LEDFDMA   : 1;  /*!< [b25~b25]*/
            __IO  uint32_t  LEDCDMA   : 1;  /*!< [b26~b26]*/
                  uint32_t  rev0      : 5;  /*!< [b31~b27]*/
        }BIT;
    }CR;                               /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __I   uint32_t  COMIF     : 1;  /*!< [b0~b0]*/
            __I   uint32_t  LEDIF     : 1;  /*!< [b1~b1]*/
                  uint32_t  rev0      :14;  /*!< [b15~b2]*/
            __O   uint32_t  COMIFC    : 1;  /*!< [b16~b16]*/
            __O   uint32_t  LEDIFC    : 1;  /*!< [b17~b17]*/
                  uint32_t  rev1      :14;  /*!< [b31~b18]*/
        }BIT;
    }FR;                               /*!< 0004H */
         uint32_t  Reserved0[1];                            /*!< 0008H */
    union {
        __IO  uint32_t  V32;                                /*!< 000CH */
        struct {
            __IO  uint32_t  LEDCOM    :12;  /*!< [b11~b0]*/
                  uint32_t  rev0      : 4;  /*!< [b15~b12]*/
            __IO  uint32_t  LEDSEG1   : 8;  /*!< [b23~b16]*/
            __IO  uint32_t  LEDSEG2   : 8;  /*!< [b31~b24]*/
        }BIT;
    }LEDSHARE;                               /*!< 000CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0010H */
        struct {
    __IO uint16_t  LEDCOM1;                                 /*!< 0010H */
    __IO uint16_t  LEDCOM2;                                 /*!< 0012H */
        }BIT;
    }LED_BUFS0;                              /*!< 0010H */
    union {
        __IO  uint32_t  V32;                                /*!< 0014H */
        struct {
    __IO uint16_t  LEDCOM3;                                 /*!< 0014H */
    __IO uint16_t  LEDCOM4;                                 /*!< 0016H */
        }BIT;
    }LED_BUFS1;                              /*!< 0014H */
    union {
        __IO  uint32_t  V32;                                /*!< 0018H */
        struct {
    __IO uint16_t  LEDCOM5;                                 /*!< 0018H */
    __IO uint16_t  LEDCOM6;                                 /*!< 001AH */
        }BIT;
    }LED_BUFS2;                              /*!< 0018H */
    union {
        __IO  uint32_t  V32;                                /*!< 001CH */
        struct {
    __IO uint16_t  LEDCOM7;                                 /*!< 001CH */
    __IO uint16_t  LEDCOM8;                                 /*!< 001EH */
        }BIT;
    }LED_BUFS3;                              /*!< 001CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0020H */
        struct {
    __IO uint16_t  LEDCOM9;                                 /*!< 0020H */
    __IO uint16_t  LEDCOM10;                                /*!< 0022H */
        }BIT;
    }LED_BUFS4;                              /*!< 0020H */
    union {
        __IO  uint32_t  V32;                                /*!< 0024H */
        struct {
    __IO uint16_t  LEDCOM11;                                /*!< 0024H */
    __IO uint16_t  LEDCOM12;                                /*!< 0026H */
        }BIT;
    }LED_BUFS5;                              /*!< 0024H */
    union {
        __IO  uint32_t  V32;                                /*!< 0028H */
        struct {
    __IO uint8_t   LEDSEG1;                                 /*!< 0028H */
    __IO uint8_t   LEDSEG2;                                 /*!< 0029H */
    __IO uint8_t   LEDSEG3;                                 /*!< 002AH */
    __IO uint8_t   LEDSEG4;                                 /*!< 002BH */
        }BIT;
    }LED_BUFS6;                              /*!< 0028H */
    union {
        __IO  uint32_t  V32;                                /*!< 002CH */
        struct {
    __IO uint8_t   LEDSEG5;                                 /*!< 002CH */
    __IO uint8_t   LEDSEG6;                                 /*!< 002DH */
    __IO uint8_t   LEDSEG7;                                 /*!< 002EH */
    __IO uint8_t   LEDSEG8;                                 /*!< 002FH */
        }BIT;
    }LED_BUFS7;                              /*!< 002CH */
    union {
        __IO  uint32_t  V32;                                /*!< 0030H */
        struct {
    __IO uint8_t   LEDSEG9;                                 /*!< 0030H */
    __IO uint8_t   LEDSEG10;                                /*!< 0031H */
    __IO uint8_t   LEDSEG11;                                /*!< 0032H */
    __IO uint8_t   LEDSEG12;                                /*!< 0033H */
        }BIT;
    }LED_BUFS8;                              /*!< 0030H */
    union {
        __IO  uint32_t  V32;                                /*!< 0034H */
        struct {
    __IO uint8_t   LEDSEG13;                                /*!< 0034H */
    __IO uint8_t   LEDSEG14;                                /*!< 0035H */
    __IO uint8_t   LEDSEG15;                                /*!< 0036H */
    __IO uint8_t   LEDSEG16;                                /*!< 0037H */
        }BIT;
    }LED_BUFS9;                              /*!< 0034H */
}LED_TypeDef;


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
            __IO  uint32_t  DATACON   : 1;  /*!< [b2~b2]*/
            __IO  uint32_t  MODE      : 1;  /*!< [b3~b3]*/
            __IO  uint32_t  FSW       : 2;  /*!< [b5~b4]*/
            __IO  uint32_t  IE        : 1;  /*!< [b6~b6]*/
            __IO  uint32_t  ST        : 8;  /*!< [b14~b7]*/
            __IO  uint32_t  TKOSM     : 1;  /*!< [b15~b15]*/
            __IO  uint32_t  TKOFFSET  : 1;  /*!< [b16~b16]*/
            __IO  uint32_t  TKRANDOM  : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  TKHYSW    : 1;  /*!< [b18~b18]*/
            __IO  uint32_t  RANDOM    : 2;  /*!< [b20~b19]*/
            __IO  uint32_t  CMPD      : 2;  /*!< [b22~b21]*/
            __IO  uint32_t  TUNE      : 2;  /*!< [b24~b23]*/
            __IO  uint32_t  TKDMA     : 1;  /*!< [b25~b25]*/
            __IO  uint32_t  TK_BG     : 1;  /*!< [b26~b26]*/
                  uint32_t  rev0      : 5;  /*!< [b31~b27]*/
        }BIT;
    }CR;                               /*!< 0000H */
    union {
        __IO  uint32_t  V32;                                /*!< 0004H */
        struct {
            __I   uint32_t  IFCOUNT   : 1;  /*!< [b0~b0]*/
            __I   uint32_t  IFAVE     : 1;  /*!< [b1~b1]*/
            __I   uint32_t  IFGO      : 1;  /*!< [b2~b2]*/
            __I   uint32_t  IFERR     : 1;  /*!< [b3~b3]*/
                  uint32_t  rev0      :12;  /*!< [b15~b4]*/
            __O   uint32_t  IFCOUNTC  : 1;  /*!< [b16~b16]*/
            __O   uint32_t  IFAVEC    : 1;  /*!< [b17~b17]*/
            __O   uint32_t  IFGOC     : 1;  /*!< [b18~b18]*/
            __O   uint32_t  IFERRC    : 1;  /*!< [b19~b19]*/
                  uint32_t  rev1      :12;  /*!< [b31~b20]*/
        }BIT;
    }FR;                               /*!< 0004H */
    union {
        __IO  uint32_t  V32;                                /*!< 0008H */
        struct {
            __IO  uint32_t  VSYSEN    : 1;  /*!< [b0~b0]*/
            __IO  uint32_t  VSYS      : 2;  /*!< [b2~b1]*/
            __IO  uint32_t  VTK       : 3;  /*!< [b5~b3]*/
            __IO  uint32_t  VREF      : 3;  /*!< [b8~b6]*/
            __IO  uint32_t  VPREEN    : 1;  /*!< [b9~b9]*/
            __IO  uint32_t  VPRE      : 3;  /*!< [b12~b10]*/
            __IO  uint32_t  ENCADJ    : 1;  /*!< [b13~b13]*/
            __IO  uint32_t  CADJ      : 3;  /*!< [b16~b14]*/
            __IO  uint32_t  ENCREF    : 1;  /*!< [b17~b17]*/
            __IO  uint32_t  CREF      : 3;  /*!< [b20~b18]*/
            __IO  uint32_t  VCREF     : 1;  /*!< [b21~b21]*/
            __IO  uint32_t  SHON      : 1;  /*!< [b22~b22]*/
            __IO  uint32_t  TKIO      : 1;  /*!< [b23~b23]*/
            __IO  uint32_t  TKFL      : 1;  /*!< [b24~b24]*/
            __IO  uint32_t  TKOP      : 1;  /*!< [b25~b25]*/
                  uint32_t  rev0      : 6;  /*!< [b31~b26]*/
        }BIT;
    }CR1;                               /*!< 0008H */
    __IO uint8_t   TKU[3];                                  /*!< 000CH */
         uint8_t   Reserved0;                               /*!< 000CH */
    __IO uint32_t  TKDIV;                                   /*!< 0010H */
    __IO uint8_t   TKCHANEL[3];                             /*!< 0014H */
         uint8_t   Reserved1;                               /*!< 0014H */
    __I  uint8_t   TKW;                                     /*!< 0018H */
         uint8_t   Reserved2[3];                            /*!< 0019H */
    union {
        __I   uint32_t  V32;                                /*!< 001CH */
        struct {
    __I  uint16_t  TK1;                                     /*!< 001CH */
    __I  uint16_t  TK0;                                     /*!< 001EH */
        }BIT;
    }TK_BUFS0;                              /*!< 001CH */
    union {
        __I   uint32_t  V32;                                /*!< 0020H */
        struct {
    __I  uint16_t  TK3;                                     /*!< 0020H */
    __I  uint16_t  TK2;                                     /*!< 0022H */
        }BIT;
    }TK_BUFS1;                              /*!< 0020H */
    union {
        __I   uint32_t  V32;                                /*!< 0024H */
        struct {
    __I  uint16_t  TK5;                                     /*!< 0024H */
    __I  uint16_t  TK4;                                     /*!< 0026H */
        }BIT;
    }TK_BUFS2;                              /*!< 0024H */
    union {
        __I   uint32_t  V32;                                /*!< 0028H */
        struct {
    __I  uint16_t  TK7;                                     /*!< 0028H */
    __I  uint16_t  TK6;                                     /*!< 002AH */
        }BIT;
    }TK_BUFS3;                              /*!< 0028H */
    union {
        __I   uint32_t  V32;                                /*!< 002CH */
        struct {
    __I  uint16_t  TK9;                                     /*!< 002CH */
    __I  uint16_t  TK8;                                     /*!< 002EH */
        }BIT;
    }TK_BUFS4;                              /*!< 002CH */
    union {
        __I   uint32_t  V32;                                /*!< 0030H */
        struct {
    __I  uint16_t  TK11;                                    /*!< 0030H */
    __I  uint16_t  TK10;                                    /*!< 0032H */
        }BIT;
    }TK_BUFS5;                              /*!< 0030H */
    union {
        __I   uint32_t  V32;                                /*!< 0034H */
        struct {
    __I  uint16_t  TK13;                                    /*!< 0034H */
    __I  uint16_t  TK12;                                    /*!< 0036H */
        }BIT;
    }TK_BUFS6;                              /*!< 0034H */
    union {
        __I   uint32_t  V32;                                /*!< 0038H */
        struct {
    __I  uint16_t  TK15;                                    /*!< 0038H */
    __I  uint16_t  TK14;                                    /*!< 003AH */
        }BIT;
    }TK_BUFS7;                              /*!< 0038H */
    union {
        __I   uint32_t  V32;                                /*!< 003CH */
        struct {
    __I  uint16_t  TK17;                                    /*!< 003CH */
    __I  uint16_t  TK16;                                    /*!< 003EH */
        }BIT;
    }TK_BUFS8;                              /*!< 003CH */
    union {
        __I   uint32_t  V32;                                /*!< 0040H */
        struct {
    __I  uint16_t  TK19;                                    /*!< 0040H */
    __I  uint16_t  TK18;                                    /*!< 0042H */
        }BIT;
    }TK_BUFS9;                              /*!< 0040H */
    union {
        __I   uint32_t  V32;                                /*!< 0044H */
        struct {
    __I  uint16_t  TK21;                                    /*!< 0044H */
    __I  uint16_t  TK20;                                    /*!< 0046H */
        }BIT;
    }TK_BUFS10;                              /*!< 0044H */
    union {
        __I   uint32_t  V32;                                /*!< 0048H */
        struct {
    __I  uint16_t  TK23;                                    /*!< 0048H */
    __I  uint16_t  TK22;                                    /*!< 004AH */
        }BIT;
    }TK_BUFS11;                              /*!< 0048H */
    __I  uint16_t  TK_BUFCREF;                              /*!< 004CH */
         uint16_t  Reserved3;                               /*!< 004EH */
}TOUCHKEY_TypeDef;


/* @addtogroup  Peripheral base address*/

#define TIM5_BASE                      ((uint32_t)0x40000400)    /* Bus:APB0        Module:TIMER      */
#define TIM6_BASE                      ((uint32_t)0x40000800)    /* Bus:APB0        Module:TIMER      */
#define TIM7_BASE                      ((uint32_t)0x40000C00)    /* Bus:APB0        Module:TIMER      */
#define TIM8_BASE                      ((uint32_t)0x40001000)    /* Bus:APB0        Module:TIMER      */
#define PWM0_BASE                      ((uint32_t)0x40003C00)    /* Bus:APB0        Module:PWM        */
#define PWM1_BASE                      ((uint32_t)0x40004000)    /* Bus:APB0        Module:PWM        */
#define PWM2_BASE                      ((uint32_t)0x40004400)    /* Bus:APB0        Module:PWM        */
#define PWM3_BASE                      ((uint32_t)0x40004800)    /* Bus:APB0        Module:PWM        */
#define PCA2_BASE                      ((uint32_t)0x40006000)    /* Bus:APB0        Module:PCA_L      */
#define PCA3_BASE                      ((uint32_t)0x40006400)    /* Bus:APB0        Module:PCA_L      */
#define PCA4_BASE                      ((uint32_t)0x40006800)    /* Bus:APB0        Module:PCA_L      */
#define PCA5_BASE                      ((uint32_t)0x40006C00)    /* Bus:APB0        Module:PCA_L      */
#define PCA6_BASE                      ((uint32_t)0x40007000)    /* Bus:APB0        Module:PCA_L      */
#define PCA7_BASE                      ((uint32_t)0x40007400)    /* Bus:APB0        Module:PCA_L      */
#define EXTI_BASE                      ((uint32_t)0x40007800)    /* Bus:APB0        Module:EXTI       */
#define IWDT_BASE                      ((uint32_t)0x40007C00)    /* Bus:APB0        Module:IWDT       */
#define WWDT_BASE                      ((uint32_t)0x40008000)    /* Bus:APB0        Module:WWDT       */
#define UART0_BASE                     ((uint32_t)0x40020000)    /* Bus:APB1        Module:UART       */
#define UART1_BASE                     ((uint32_t)0x40020400)    /* Bus:APB1        Module:UART       */
#define UART2_BASE                     ((uint32_t)0x40020800)    /* Bus:APB1        Module:UART       */
#define UART3_BASE                     ((uint32_t)0x40020C00)    /* Bus:APB1        Module:UART       */
#define UART4_BASE                     ((uint32_t)0x40021000)    /* Bus:APB1        Module:UART       */
#define UART5_BASE                     ((uint32_t)0x40021400)    /* Bus:APB1        Module:UART       */
#define SPI0_BASE                      ((uint32_t)0x40021800)    /* Bus:APB1        Module:SPI        */
#define SPI1_BASE                      ((uint32_t)0x40021C00)    /* Bus:APB1        Module:SPI        */
#define TWI0_BASE                      ((uint32_t)0x40022000)    /* Bus:APB1        Module:TWI        */
#define TWI1_BASE                      ((uint32_t)0x40022400)    /* Bus:APB1        Module:TWI        */
#define ADC_BASE                       ((uint32_t)0x40022800)    /* Bus:APB1        Module:ADC        */
#define TPS_BASE                       ((uint32_t)0x40022C00)    /* Bus:APB1        Module:TPS        */
#define N_TEST_BASE                    ((uint32_t)0x40023000)    /* Bus:APB1        Module:N_TEST     */
#define LED_BASE                       ((uint32_t)0x40023400)    /* Bus:APB1        Module:LED        */
#define LCD_BASE                       ((uint32_t)0x40023800)    /* Bus:APB1        Module:LCD        */
#define TOUCHKEY_BASE                  ((uint32_t)0x40023C00)    /* Bus:APB1        Module:TOUCHKEY   */
#define PCA0_BASE                      ((uint32_t)0x40040000)    /* Bus:AHB         Module:PCA_H      */
#define PCA1_BASE                      ((uint32_t)0x40040400)    /* Bus:AHB         Module:PCA_H      */
#define GPIOA_CFG_BASE                 ((uint32_t)0x40040800)    /* Bus:AHB         Module:GPIO_CFG   */
#define GPIOB_CFG_BASE                 ((uint32_t)0x40040820)    /* Bus:AHB         Module:GPIO_CFG   */
#define GPIOC_CFG_BASE                 ((uint32_t)0x40040840)    /* Bus:AHB         Module:GPIO_CFG   */
#define GPIOD_CFG_BASE                 ((uint32_t)0x40040860)    /* Bus:AHB         Module:GPIO_CFG   */
#define GPIOE_CFG_BASE                 ((uint32_t)0x40040880)    /* Bus:AHB         Module:GPIO_CFG   */
#define GPIOA_BASE                     ((uint32_t)0x40040A00)    /* Bus:AHB         Module:GPIO       */
#define GPIOB_BASE                     ((uint32_t)0x40040A20)    /* Bus:AHB         Module:GPIO       */
#define GPIOC_BASE                     ((uint32_t)0x40040A40)    /* Bus:AHB         Module:GPIO       */
#define GPIOD_BASE                     ((uint32_t)0x40040A60)    /* Bus:AHB         Module:GPIO       */
#define GPIOE_BASE                     ((uint32_t)0x40040A80)    /* Bus:AHB         Module:GPIO       */
#define SYSCFG_BASE                    ((uint32_t)0x40043800)    /* Bus:AHB         Module:SYSCFG     */
#define RCC_BASE                       ((uint32_t)0x40043C00)    /* Bus:AHB         Module:RCC        */
#define DMA_BASE                       ((uint32_t)0x40044000)    /* Bus:AHB         Module:DMA        */
#define FLASH_BASE                     ((uint32_t)0x40044800)    /* Bus:AHB         Module:FLASH      */
#define CRC_BASE                       ((uint32_t)0x40045000)    /* Bus:AHB         Module:CRC        */
#define RAMBIST_BASE                   ((uint32_t)0x40045400)    /* Bus:AHB         Module:RAMBIST    */
#define FPGA_DEBUG_BASE                ((uint32_t)0x40045800)    /* Bus:AHB         Module:FPGA_DEBUG */

/* @addtogroup Peripheral_declaration */

#define FPGA_DEBUG           ((FPGA_DEBUG_TypeDef *)  FPGA_DEBUG_BASE)
#define N_TEST               ((N_TEST_TypeDef *)      N_TEST_BASE)
#define FLASH                ((FLASH_TypeDef *)       FLASH_BASE)
#define SYSCFG               ((SYSCFG_TypeDef *)      SYSCFG_BASE)
#define RCC                  ((RCC_TypeDef *)         RCC_BASE)
#define DMA                  ((DMA_TypeDef *)         DMA_BASE)
#define CRC                  ((CRC_TypeDef *)         CRC_BASE)
#define RAMBIST              ((RAMBIST_TypeDef *)     RAMBIST_BASE)
#define GPIOA_CFG            ((GPIO_CFG_TypeDef *)    GPIOA_CFG_BASE)
#define GPIOB_CFG            ((GPIO_CFG_TypeDef *)    GPIOB_CFG_BASE)
#define GPIOC_CFG            ((GPIO_CFG_TypeDef *)    GPIOC_CFG_BASE)
#define GPIOD_CFG            ((GPIO_CFG_TypeDef *)    GPIOD_CFG_BASE)
#define GPIOE_CFG            ((GPIO_CFG_TypeDef *)    GPIOE_CFG_BASE)
#define GPIOA                ((GPIO_TypeDef *)        GPIOA_BASE)
#define GPIOB                ((GPIO_TypeDef *)        GPIOB_BASE)
#define GPIOC                ((GPIO_TypeDef *)        GPIOC_BASE)
#define GPIOD                ((GPIO_TypeDef *)        GPIOD_BASE)
#define GPIOE                ((GPIO_TypeDef *)        GPIOE_BASE)
#define PCA0                 ((PCA_TypeDef *)         PCA0_BASE)
#define PCA1                 ((PCA_TypeDef *)         PCA1_BASE)
#define EXTI                 ((EXTI_TypeDef *)        EXTI_BASE)
#define PWM0                 ((PWM_TypeDef *)         PWM0_BASE)
#define PWM1                 ((PWM_TypeDef *)         PWM1_BASE)
#define PWM2                 ((PWM_TypeDef *)         PWM2_BASE)
#define PWM3                 ((PWM_TypeDef *)         PWM3_BASE)
#define PCA2                 ((PCA_TypeDef *)         PCA2_BASE)
#define PCA3                 ((PCA_TypeDef *)         PCA3_BASE)
#define PCA4                 ((PCA_TypeDef *)         PCA4_BASE)
#define PCA5                 ((PCA_TypeDef *)         PCA5_BASE)
#define PCA6                 ((PCA_TypeDef *)         PCA6_BASE)
#define PCA7                 ((PCA_TypeDef *)         PCA7_BASE)
#define TIM5                 ((TIMER_TypeDef *)       TIM5_BASE)
#define TIM6                 ((TIMER_TypeDef *)       TIM6_BASE)
#define TIM7                 ((TIMER_TypeDef *)       TIM7_BASE)
#define TIM8                 ((TIMER_TypeDef *)       TIM8_BASE)
#define IWDT                 ((IWDT_TypeDef *)        IWDT_BASE)
#define WWDT                 ((WWDT_TypeDef *)        WWDT_BASE)
#define ADC                  ((ADC_TypeDef *)         ADC_BASE)
#define TPS                  ((TPS_TypeDef *)         TPS_BASE)
#define UART0                ((UART_TypeDef *)        UART0_BASE)
#define UART1                ((UART_TypeDef *)        UART1_BASE)
#define UART2                ((UART_TypeDef *)        UART2_BASE)
#define UART3                ((UART_TypeDef *)        UART3_BASE)
#define UART4                ((UART_TypeDef *)        UART4_BASE)
#define UART5                ((UART_TypeDef *)        UART5_BASE)
#define SPI0                 ((SPI_TypeDef *)         SPI0_BASE)
#define SPI1                 ((SPI_TypeDef *)         SPI1_BASE)
#define TWI0                 ((TWI_TypeDef *)         TWI0_BASE)
#define TWI1                 ((TWI_TypeDef *)         TWI1_BASE)
#define LCD                  ((LCD_TypeDef *)         LCD_BASE)
#define LED                  ((LED_TypeDef *)         LED_BASE)
#define TOUCHKEY             ((TOUCHKEY_TypeDef *)    TOUCHKEY_BASE)

/* @addtogroup Peripheral Field Postion and mask */

#define FPGA_DEBUG_WATCH_SEL_Pos     0                                            /*!<FPGA_DEBUG WATCH: SEL Position */
#define FPGA_DEBUG_WATCH_SEL_Msk     (0xFFUL /*<< FPGA_DEBUG_WATCH_SEL_Pos*/)     /*!<FPGA_DEBUG WATCH: SEL Mask */

#define FPGA_DEBUG_WATCH_Msk_ALL     (FPGA_DEBUG_WATCH_SEL_Msk    )

#define N_TEST_NTW_WDT_Pos           0                                            /*!<N_TEST NTW: WDT Position */
#define N_TEST_NTW_WDT_Msk           (0xFFUL /*<< N_TEST_NTW_WDT_Pos*/)           /*!<N_TEST NTW: WDT Mask */

#define N_TEST_NTW_Msk_ALL           (N_TEST_NTW_WDT_Msk          )

#define N_TEST_NTID0_CODE_Pos        0                                            /*!<N_TEST NTID0: CODE Position */
#define N_TEST_NTID0_CODE_Msk        (0xFFFFUL /*<< N_TEST_NTID0_CODE_Pos*/)      /*!<N_TEST NTID0: CODE Mask */

#define N_TEST_NTID0_Msk_ALL         (N_TEST_NTID0_CODE_Msk       )

#define N_TEST_NTID1_CODE_Pos        0                                            /*!<N_TEST NTID1: CODE Position */
#define N_TEST_NTID1_CODE_Msk        (0xFFFFUL /*<< N_TEST_NTID1_CODE_Pos*/)      /*!<N_TEST NTID1: CODE Mask */

#define N_TEST_NTID1_Msk_ALL         (N_TEST_NTID1_CODE_Msk       )

#define N_TEST_NTID2_CODE_Pos        0                                            /*!<N_TEST NTID2: CODE Position */
#define N_TEST_NTID2_CODE_Msk        (0xFFFFUL /*<< N_TEST_NTID2_CODE_Pos*/)      /*!<N_TEST NTID2: CODE Mask */

#define N_TEST_NTID2_Msk_ALL         (N_TEST_NTID2_CODE_Msk       )

#define FLASH_ACR_LATENCY_Pos        0                                            /*!<FLASH ACR: LATENCY Position */
#define FLASH_ACR_LATENCY_Msk        (0x7UL /*<< FLASH_ACR_LATENCY_Pos*/)         /*!<FLASH ACR: LATENCY Mask */

#define FLASH_ACR_PRFTEN_Pos         8                                            /*!<FLASH ACR: PRFTEN Position */
#define FLASH_ACR_PRFTEN_Msk         (0x1UL << FLASH_ACR_PRFTEN_Pos)              /*!<FLASH ACR: PRFTEN Mask */

#define FLASH_ACR_ICEN_Pos           9                                            /*!<FLASH ACR: ICEN Position */
#define FLASH_ACR_ICEN_Msk           (0x1UL << FLASH_ACR_ICEN_Pos)                /*!<FLASH ACR: ICEN Mask */

#define FLASH_ACR_DCEN_Pos           10                                           /*!<FLASH ACR: DCEN Position */
#define FLASH_ACR_DCEN_Msk           (0x1UL << FLASH_ACR_DCEN_Pos)                /*!<FLASH ACR: DCEN Mask */

#define FLASH_ACR_CRST_Pos           11                                           /*!<FLASH ACR: CRST Position */
#define FLASH_ACR_CRST_Msk           (0x1UL << FLASH_ACR_CRST_Pos)                /*!<FLASH ACR: CRST Mask */

#define FLASH_ACR_LOCK_Pos           16                                           /*!<FLASH ACR: LOCK Position */
#define FLASH_ACR_LOCK_Msk           (0xFFFFUL << FLASH_ACR_LOCK_Pos)             /*!<FLASH ACR: LOCK Mask */

#define FLASH_ACR_Msk_ALL            (FLASH_ACR_LATENCY_Msk        |\
                                      FLASH_ACR_PRFTEN_Msk         |\
                                      FLASH_ACR_ICEN_Msk           |\
                                      FLASH_ACR_DCEN_Msk           |\
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

#define FLASH_CR_SNB_Pos             0                                            /*!<FLASH CR: SNB Position */
#define FLASH_CR_SNB_Msk             (0xFFUL /*<< FLASH_CR_SNB_Pos*/)             /*!<FLASH CR: SNB Mask */

#define FLASH_CR_STRT_Pos            8                                            /*!<FLASH CR: STRT Position */
#define FLASH_CR_STRT_Msk            (0x1UL << FLASH_CR_STRT_Pos)                 /*!<FLASH CR: STRT Mask */

#define FLASH_CR_PSIZE_Pos           11                                           /*!<FLASH CR: PSIZE Position */
#define FLASH_CR_PSIZE_Msk           (0x1UL << FLASH_CR_PSIZE_Pos)                /*!<FLASH CR: PSIZE Mask */

#define FLASH_CR_INFLCK_Pos          12                                           /*!<FLASH CR: INFLCK Position */
#define FLASH_CR_INFLCK_Msk          (0x1UL << FLASH_CR_INFLCK_Pos)               /*!<FLASH CR: INFLCK Mask */

#define FLASH_CR_E2LCK_Pos           14                                           /*!<FLASH CR: E2LCK Position */
#define FLASH_CR_E2LCK_Msk           (0x1UL << FLASH_CR_E2LCK_Pos)                /*!<FLASH CR: E2LCK Mask */

#define FLASH_CR_MNLCK_Pos           15                                           /*!<FLASH CR: MNLCK Position */
#define FLASH_CR_MNLCK_Msk           (0x1UL << FLASH_CR_MNLCK_Pos)                /*!<FLASH CR: MNLCK Mask */

#define FLASH_CR_CMD_Pos             16                                           /*!<FLASH CR: CMD Position */
#define FLASH_CR_CMD_Msk             (0xFFFFUL << FLASH_CR_CMD_Pos)               /*!<FLASH CR: CMD Mask */

#define FLASH_CR_Msk_ALL             (FLASH_CR_SNB_Msk             |\
                                      FLASH_CR_STRT_Msk            |\
                                      FLASH_CR_PSIZE_Msk           |\
                                      FLASH_CR_INFLCK_Msk          |\
                                      FLASH_CR_E2LCK_Msk           |\
                                      FLASH_CR_MNLCK_Msk           |\
                                      FLASH_CR_CMD_Msk             )

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

#define SYSCFG_PWRCR_VBOD_Pos        0                                            /*!<SYSCFG PWRCR: VBOD Position */
#define SYSCFG_PWRCR_VBOD_Msk        (0x1FUL /*<< SYSCFG_PWRCR_VBOD_Pos*/)        /*!<SYSCFG PWRCR: VBOD Mask */

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

#define SYSCFG_SAFR_OSCXCFG_Pos      2                                            /*!<SYSCFG SAFR: OSCXCFG Position */
#define SYSCFG_SAFR_OSCXCFG_Msk      (0x1UL << SYSCFG_SAFR_OSCXCFG_Pos)           /*!<SYSCFG SAFR: OSCXCFG Mask */

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
                                      SYSCFG_SAFR_OSCXCFG_Msk      |\
                                      SYSCFG_SAFR_SWJCFG_Msk       |\
                                      SYSCFG_SAFR_IEN_EXTI0_Msk    |\
                                      SYSCFG_SAFR_IEN_BOD_Msk      |\
                                      SYSCFG_SAFR_IEN_CSM_Msk      |\
                                      SYSCFG_SAFR_LOCK_Msk         )

#define SYSCFG_CRAMLOCK_CRAMLCK_Pos  0                                            /*!<SYSCFG CRAMLOCK: CRAMLCK Position */
#define SYSCFG_CRAMLOCK_CRAMLCK_Msk  (0xFFUL /*<< SYSCFG_CRAMLOCK_CRAMLCK_Pos*/)  /*!<SYSCFG CRAMLOCK: CRAMLCK Mask */

#define SYSCFG_CRAMLOCK_LOCK_Pos     16                                           /*!<SYSCFG CRAMLOCK: LOCK Position */
#define SYSCFG_CRAMLOCK_LOCK_Msk     (0xFFFFUL << SYSCFG_CRAMLOCK_LOCK_Pos)       /*!<SYSCFG CRAMLOCK: LOCK Mask */

#define SYSCFG_CRAMLOCK_Msk_ALL      (SYSCFG_CRAMLOCK_CRAMLCK_Msk  |\
                                      SYSCFG_CRAMLOCK_LOCK_Msk     )

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

#define SYSCFG_EFTEN_EFT_EN_Pos      0                                            /*!<SYSCFG EFTEN: EFT_EN Position */
#define SYSCFG_EFTEN_EFT_EN_Msk      (0x1UL /*<< SYSCFG_EFTEN_EFT_EN_Pos*/)       /*!<SYSCFG EFTEN: EFT_EN Mask */

#define SYSCFG_EFTEN_EFTSEL_Pos      1                                            /*!<SYSCFG EFTEN: EFTSEL Position */
#define SYSCFG_EFTEN_EFTSEL_Msk      (0x3UL << SYSCFG_EFTEN_EFTSEL_Pos)           /*!<SYSCFG EFTEN: EFTSEL Mask */

#define SYSCFG_EFTEN_Msk_ALL         (SYSCFG_EFTEN_EFT_EN_Msk      |\
                                      SYSCFG_EFTEN_EFTSEL_Msk      )

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
                                      RCC_CR_LSIRDY_Msk            )

#define RCC_CFGR_HPRE_Pos            0                                            /*!<RCC CFGR: HPRE Position */
#define RCC_CFGR_HPRE_Msk            (0x7UL /*<< RCC_CFGR_HPRE_Pos*/)             /*!<RCC CFGR: HPRE Mask */

#define RCC_CFGR_PPRE0_Pos           3                                            /*!<RCC CFGR: PPRE0 Position */
#define RCC_CFGR_PPRE0_Msk           (0x7UL << RCC_CFGR_PPRE0_Pos)                /*!<RCC CFGR: PPRE0 Mask */

#define RCC_CFGR_PPRE1_Pos           6                                            /*!<RCC CFGR: PPRE1 Position */
#define RCC_CFGR_PPRE1_Msk           (0x7UL << RCC_CFGR_PPRE1_Pos)                /*!<RCC CFGR: PPRE1 Mask */

#define RCC_CFGR_PLLSW_Pos           9                                            /*!<RCC CFGR: PLLSW Position */
#define RCC_CFGR_PLLSW_Msk           (0x1UL << RCC_CFGR_PLLSW_Pos)                /*!<RCC CFGR: PLLSW Mask */

#define RCC_CFGR_PLLK_Pos            10                                           /*!<RCC CFGR: PLLK Position */
#define RCC_CFGR_PLLK_Msk            (0x7UL << RCC_CFGR_PLLK_Pos)                 /*!<RCC CFGR: PLLK Mask */

#define RCC_CFGR_PLLF_Pos            13                                           /*!<RCC CFGR: PLLF Position */
#define RCC_CFGR_PLLF_Msk            (0x3FUL << RCC_CFGR_PLLF_Pos)                /*!<RCC CFGR: PLLF Mask */

#define RCC_CFGR_PLLSRC_Pos          19                                           /*!<RCC CFGR: PLLSRC Position */
#define RCC_CFGR_PLLSRC_Msk          (0x1UL << RCC_CFGR_PLLSRC_Pos)               /*!<RCC CFGR: PLLSRC Mask */

#define RCC_CFGR_PLLXTPRE_Pos        20                                           /*!<RCC CFGR: PLLXTPRE Position */
#define RCC_CFGR_PLLXTPRE_Msk        (0x3UL << RCC_CFGR_PLLXTPRE_Pos)             /*!<RCC CFGR: PLLXTPRE Mask */

#define RCC_CFGR_LSESPDUP_Pos        22                                           /*!<RCC CFGR: LSESPDUP Position */
#define RCC_CFGR_LSESPDUP_Msk        (0x1UL << RCC_CFGR_LSESPDUP_Pos)             /*!<RCC CFGR: LSESPDUP Mask */

#define RCC_CFGR_LSENOISEEN_Pos      23                                           /*!<RCC CFGR: LSENOISEEN Position */
#define RCC_CFGR_LSENOISEEN_Msk      (0x1UL << RCC_CFGR_LSENOISEEN_Pos)           /*!<RCC CFGR: LSENOISEEN Mask */

#define RCC_CFGR_HSIENREC_Pos        24                                           /*!<RCC CFGR: HSIENREC Position */
#define RCC_CFGR_HSIENREC_Msk        (0x1UL << RCC_CFGR_HSIENREC_Pos)             /*!<RCC CFGR: HSIENREC Mask */

#define RCC_CFGR_HSESEL_Pos          25                                           /*!<RCC CFGR: HSESEL Position */
#define RCC_CFGR_HSESEL_Msk          (0x3UL << RCC_CFGR_HSESEL_Pos)               /*!<RCC CFGR: HSESEL Mask */

#define RCC_CFGR_Msk_ALL             (RCC_CFGR_HPRE_Msk            |\
                                      RCC_CFGR_PPRE0_Msk           |\
                                      RCC_CFGR_PPRE1_Msk           |\
                                      RCC_CFGR_PLLSW_Msk           |\
                                      RCC_CFGR_PLLK_Msk            |\
                                      RCC_CFGR_PLLF_Msk            |\
                                      RCC_CFGR_PLLSRC_Msk          |\
                                      RCC_CFGR_PLLXTPRE_Msk        |\
                                      RCC_CFGR_LSESPDUP_Msk        |\
                                      RCC_CFGR_LSENOISEEN_Msk      |\
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

#define RCC_CISTR_CSMLSEF_Pos        5                                            /*!<RCC CISTR: CSMLSEF Position */
#define RCC_CISTR_CSMLSEF_Msk        (0x1UL << RCC_CISTR_CSMLSEF_Pos)             /*!<RCC CISTR: CSMLSEF Mask */

#define RCC_CISTR_CSMHSEF_Pos        6                                            /*!<RCC CISTR: CSMHSEF Position */
#define RCC_CISTR_CSMHSEF_Msk        (0x1UL << RCC_CISTR_CSMHSEF_Pos)             /*!<RCC CISTR: CSMHSEF Mask */

#define RCC_CISTR_CSMPLLF_Pos        7                                            /*!<RCC CISTR: CSMPLLF Position */
#define RCC_CISTR_CSMPLLF_Msk        (0x1UL << RCC_CISTR_CSMPLLF_Pos)             /*!<RCC CISTR: CSMPLLF Mask */

#define RCC_CISTR_Msk_ALL            (RCC_CISTR_LSERDYIF_Msk       |\
                                      RCC_CISTR_HSERDYIF_Msk       |\
                                      RCC_CISTR_PLLRDYIF_Msk       |\
                                      RCC_CISTR_CSMLSEF_Msk        |\
                                      RCC_CISTR_CSMHSEF_Msk        |\
                                      RCC_CISTR_CSMPLLF_Msk        )

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

#define RCC_AHBRSTR_PCA0RST_Pos      0                                            /*!<RCC AHBRSTR: PCA0RST Position */
#define RCC_AHBRSTR_PCA0RST_Msk      (0x1UL /*<< RCC_AHBRSTR_PCA0RST_Pos*/)       /*!<RCC AHBRSTR: PCA0RST Mask */

#define RCC_AHBRSTR_PCA1RST_Pos      1                                            /*!<RCC AHBRSTR: PCA1RST Position */
#define RCC_AHBRSTR_PCA1RST_Msk      (0x1UL << RCC_AHBRSTR_PCA1RST_Pos)           /*!<RCC AHBRSTR: PCA1RST Mask */

#define RCC_AHBRSTR_GPIORST_Pos      2                                            /*!<RCC AHBRSTR: GPIORST Position */
#define RCC_AHBRSTR_GPIORST_Msk      (0x1UL << RCC_AHBRSTR_GPIORST_Pos)           /*!<RCC AHBRSTR: GPIORST Mask */

#define RCC_AHBRSTR_SYSCFGRST_Pos    4                                            /*!<RCC AHBRSTR: SYSCFGRST Position */
#define RCC_AHBRSTR_SYSCFGRST_Msk    (0x1UL << RCC_AHBRSTR_SYSCFGRST_Pos)         /*!<RCC AHBRSTR: SYSCFGRST Mask */

#define RCC_AHBRSTR_DMARST_Pos       5                                            /*!<RCC AHBRSTR: DMARST Position */
#define RCC_AHBRSTR_DMARST_Msk       (0x1UL << RCC_AHBRSTR_DMARST_Pos)            /*!<RCC AHBRSTR: DMARST Mask */

#define RCC_AHBRSTR_CRCRST_Pos       6                                            /*!<RCC AHBRSTR: CRCRST Position */
#define RCC_AHBRSTR_CRCRST_Msk       (0x1UL << RCC_AHBRSTR_CRCRST_Pos)            /*!<RCC AHBRSTR: CRCRST Mask */

#define RCC_AHBRSTR_RAMBISTRST_Pos   7                                            /*!<RCC AHBRSTR: RAMBISTRST Position */
#define RCC_AHBRSTR_RAMBISTRST_Msk   (0x1UL << RCC_AHBRSTR_RAMBISTRST_Pos)        /*!<RCC AHBRSTR: RAMBISTRST Mask */

#define RCC_AHBRSTR_NTESTRST_Pos     8                                            /*!<RCC AHBRSTR: NTESTRST Position */
#define RCC_AHBRSTR_NTESTRST_Msk     (0x1UL << RCC_AHBRSTR_NTESTRST_Pos)          /*!<RCC AHBRSTR: NTESTRST Mask */

#define RCC_AHBRSTR_Msk_ALL          (RCC_AHBRSTR_PCA0RST_Msk      |\
                                      RCC_AHBRSTR_PCA1RST_Msk      |\
                                      RCC_AHBRSTR_GPIORST_Msk      |\
                                      RCC_AHBRSTR_SYSCFGRST_Msk    |\
                                      RCC_AHBRSTR_DMARST_Msk       |\
                                      RCC_AHBRSTR_CRCRST_Msk       |\
                                      RCC_AHBRSTR_RAMBISTRST_Msk   |\
                                      RCC_AHBRSTR_NTESTRST_Msk     )

#define RCC_APB1RSTR_UART0RST_Pos    0                                            /*!<RCC APB1RSTR: UART0RST Position */
#define RCC_APB1RSTR_UART0RST_Msk    (0x1UL /*<< RCC_APB1RSTR_UART0RST_Pos*/)     /*!<RCC APB1RSTR: UART0RST Mask */

#define RCC_APB1RSTR_UART1RST_Pos    1                                            /*!<RCC APB1RSTR: UART1RST Position */
#define RCC_APB1RSTR_UART1RST_Msk    (0x1UL << RCC_APB1RSTR_UART1RST_Pos)         /*!<RCC APB1RSTR: UART1RST Mask */

#define RCC_APB1RSTR_UART2RST_Pos    2                                            /*!<RCC APB1RSTR: UART2RST Position */
#define RCC_APB1RSTR_UART2RST_Msk    (0x1UL << RCC_APB1RSTR_UART2RST_Pos)         /*!<RCC APB1RSTR: UART2RST Mask */

#define RCC_APB1RSTR_UART3RST_Pos    3                                            /*!<RCC APB1RSTR: UART3RST Position */
#define RCC_APB1RSTR_UART3RST_Msk    (0x1UL << RCC_APB1RSTR_UART3RST_Pos)         /*!<RCC APB1RSTR: UART3RST Mask */

#define RCC_APB1RSTR_UART4RST_Pos    4                                            /*!<RCC APB1RSTR: UART4RST Position */
#define RCC_APB1RSTR_UART4RST_Msk    (0x1UL << RCC_APB1RSTR_UART4RST_Pos)         /*!<RCC APB1RSTR: UART4RST Mask */

#define RCC_APB1RSTR_UART5RST_Pos    5                                            /*!<RCC APB1RSTR: UART5RST Position */
#define RCC_APB1RSTR_UART5RST_Msk    (0x1UL << RCC_APB1RSTR_UART5RST_Pos)         /*!<RCC APB1RSTR: UART5RST Mask */

#define RCC_APB1RSTR_SPI0RST_Pos     6                                            /*!<RCC APB1RSTR: SPI0RST Position */
#define RCC_APB1RSTR_SPI0RST_Msk     (0x1UL << RCC_APB1RSTR_SPI0RST_Pos)          /*!<RCC APB1RSTR: SPI0RST Mask */

#define RCC_APB1RSTR_SPI1RST_Pos     7                                            /*!<RCC APB1RSTR: SPI1RST Position */
#define RCC_APB1RSTR_SPI1RST_Msk     (0x1UL << RCC_APB1RSTR_SPI1RST_Pos)          /*!<RCC APB1RSTR: SPI1RST Mask */

#define RCC_APB1RSTR_TWI0RST_Pos     8                                            /*!<RCC APB1RSTR: TWI0RST Position */
#define RCC_APB1RSTR_TWI0RST_Msk     (0x1UL << RCC_APB1RSTR_TWI0RST_Pos)          /*!<RCC APB1RSTR: TWI0RST Mask */

#define RCC_APB1RSTR_TWI1RST_Pos     9                                            /*!<RCC APB1RSTR: TWI1RST Position */
#define RCC_APB1RSTR_TWI1RST_Msk     (0x1UL << RCC_APB1RSTR_TWI1RST_Pos)          /*!<RCC APB1RSTR: TWI1RST Mask */

#define RCC_APB1RSTR_AMOCRST_Pos     10                                           /*!<RCC APB1RSTR: AMOCRST Position */
#define RCC_APB1RSTR_AMOCRST_Msk     (0x1UL << RCC_APB1RSTR_AMOCRST_Pos)          /*!<RCC APB1RSTR: AMOCRST Mask */

#define RCC_APB1RSTR_ADCRST_Pos      11                                           /*!<RCC APB1RSTR: ADCRST Position */
#define RCC_APB1RSTR_ADCRST_Msk      (0x1UL << RCC_APB1RSTR_ADCRST_Pos)           /*!<RCC APB1RSTR: ADCRST Mask */

#define RCC_APB1RSTR_LCDRST_Pos      12                                           /*!<RCC APB1RSTR: LCDRST Position */
#define RCC_APB1RSTR_LCDRST_Msk      (0x1UL << RCC_APB1RSTR_LCDRST_Pos)           /*!<RCC APB1RSTR: LCDRST Mask */

#define RCC_APB1RSTR_LEDRST_Pos      13                                           /*!<RCC APB1RSTR: LEDRST Position */
#define RCC_APB1RSTR_LEDRST_Msk      (0x1UL << RCC_APB1RSTR_LEDRST_Pos)           /*!<RCC APB1RSTR: LEDRST Mask */

#define RCC_APB1RSTR_TKRST_Pos       14                                           /*!<RCC APB1RSTR: TKRST Position */
#define RCC_APB1RSTR_TKRST_Msk       (0x1UL << RCC_APB1RSTR_TKRST_Pos)            /*!<RCC APB1RSTR: TKRST Mask */

#define RCC_APB1RSTR_Msk_ALL         (RCC_APB1RSTR_UART0RST_Msk    |\
                                      RCC_APB1RSTR_UART1RST_Msk    |\
                                      RCC_APB1RSTR_UART2RST_Msk    |\
                                      RCC_APB1RSTR_UART3RST_Msk    |\
                                      RCC_APB1RSTR_UART4RST_Msk    |\
                                      RCC_APB1RSTR_UART5RST_Msk    |\
                                      RCC_APB1RSTR_SPI0RST_Msk     |\
                                      RCC_APB1RSTR_SPI1RST_Msk     |\
                                      RCC_APB1RSTR_TWI0RST_Msk     |\
                                      RCC_APB1RSTR_TWI1RST_Msk     |\
                                      RCC_APB1RSTR_AMOCRST_Msk     |\
                                      RCC_APB1RSTR_ADCRST_Msk      |\
                                      RCC_APB1RSTR_LCDRST_Msk      |\
                                      RCC_APB1RSTR_LEDRST_Msk      |\
                                      RCC_APB1RSTR_TKRST_Msk       )

#define RCC_APB0RSTR_TIM5RST_Pos     0                                            /*!<RCC APB0RSTR: TIM5RST Position */
#define RCC_APB0RSTR_TIM5RST_Msk     (0x1UL /*<< RCC_APB0RSTR_TIM5RST_Pos*/)      /*!<RCC APB0RSTR: TIM5RST Mask */

#define RCC_APB0RSTR_TIM6RST_Pos     1                                            /*!<RCC APB0RSTR: TIM6RST Position */
#define RCC_APB0RSTR_TIM6RST_Msk     (0x1UL << RCC_APB0RSTR_TIM6RST_Pos)          /*!<RCC APB0RSTR: TIM6RST Mask */

#define RCC_APB0RSTR_TIM7RST_Pos     2                                            /*!<RCC APB0RSTR: TIM7RST Position */
#define RCC_APB0RSTR_TIM7RST_Msk     (0x1UL << RCC_APB0RSTR_TIM7RST_Pos)          /*!<RCC APB0RSTR: TIM7RST Mask */

#define RCC_APB0RSTR_TIM8RST_Pos     3                                            /*!<RCC APB0RSTR: TIM8RST Position */
#define RCC_APB0RSTR_TIM8RST_Msk     (0x1UL << RCC_APB0RSTR_TIM8RST_Pos)          /*!<RCC APB0RSTR: TIM8RST Mask */

#define RCC_APB0RSTR_PWM0RST_Pos     4                                            /*!<RCC APB0RSTR: PWM0RST Position */
#define RCC_APB0RSTR_PWM0RST_Msk     (0x1UL << RCC_APB0RSTR_PWM0RST_Pos)          /*!<RCC APB0RSTR: PWM0RST Mask */

#define RCC_APB0RSTR_PWM1RST_Pos     5                                            /*!<RCC APB0RSTR: PWM1RST Position */
#define RCC_APB0RSTR_PWM1RST_Msk     (0x1UL << RCC_APB0RSTR_PWM1RST_Pos)          /*!<RCC APB0RSTR: PWM1RST Mask */

#define RCC_APB0RSTR_PWM2RST_Pos     6                                            /*!<RCC APB0RSTR: PWM2RST Position */
#define RCC_APB0RSTR_PWM2RST_Msk     (0x1UL << RCC_APB0RSTR_PWM2RST_Pos)          /*!<RCC APB0RSTR: PWM2RST Mask */

#define RCC_APB0RSTR_PWM3RST_Pos     7                                            /*!<RCC APB0RSTR: PWM3RST Position */
#define RCC_APB0RSTR_PWM3RST_Msk     (0x1UL << RCC_APB0RSTR_PWM3RST_Pos)          /*!<RCC APB0RSTR: PWM3RST Mask */

#define RCC_APB0RSTR_PCA2RST_Pos     8                                            /*!<RCC APB0RSTR: PCA2RST Position */
#define RCC_APB0RSTR_PCA2RST_Msk     (0x1UL << RCC_APB0RSTR_PCA2RST_Pos)          /*!<RCC APB0RSTR: PCA2RST Mask */

#define RCC_APB0RSTR_PCA3RST_Pos     9                                            /*!<RCC APB0RSTR: PCA3RST Position */
#define RCC_APB0RSTR_PCA3RST_Msk     (0x1UL << RCC_APB0RSTR_PCA3RST_Pos)          /*!<RCC APB0RSTR: PCA3RST Mask */

#define RCC_APB0RSTR_PCA4RST_Pos     10                                           /*!<RCC APB0RSTR: PCA4RST Position */
#define RCC_APB0RSTR_PCA4RST_Msk     (0x1UL << RCC_APB0RSTR_PCA4RST_Pos)          /*!<RCC APB0RSTR: PCA4RST Mask */

#define RCC_APB0RSTR_PCA5RST_Pos     11                                           /*!<RCC APB0RSTR: PCA5RST Position */
#define RCC_APB0RSTR_PCA5RST_Msk     (0x1UL << RCC_APB0RSTR_PCA5RST_Pos)          /*!<RCC APB0RSTR: PCA5RST Mask */

#define RCC_APB0RSTR_PCA6RST_Pos     12                                           /*!<RCC APB0RSTR: PCA6RST Position */
#define RCC_APB0RSTR_PCA6RST_Msk     (0x1UL << RCC_APB0RSTR_PCA6RST_Pos)          /*!<RCC APB0RSTR: PCA6RST Mask */

#define RCC_APB0RSTR_PCA7RST_Pos     13                                           /*!<RCC APB0RSTR: PCA7RST Position */
#define RCC_APB0RSTR_PCA7RST_Msk     (0x1UL << RCC_APB0RSTR_PCA7RST_Pos)          /*!<RCC APB0RSTR: PCA7RST Mask */

#define RCC_APB0RSTR_EXTIRST_Pos     14                                           /*!<RCC APB0RSTR: EXTIRST Position */
#define RCC_APB0RSTR_EXTIRST_Msk     (0x1UL << RCC_APB0RSTR_EXTIRST_Pos)          /*!<RCC APB0RSTR: EXTIRST Mask */

#define RCC_APB0RSTR_WWDTRST_Pos     15                                           /*!<RCC APB0RSTR: WWDTRST Position */
#define RCC_APB0RSTR_WWDTRST_Msk     (0x1UL << RCC_APB0RSTR_WWDTRST_Pos)          /*!<RCC APB0RSTR: WWDTRST Mask */

#define RCC_APB0RSTR_Msk_ALL         (RCC_APB0RSTR_TIM5RST_Msk     |\
                                      RCC_APB0RSTR_TIM6RST_Msk     |\
                                      RCC_APB0RSTR_TIM7RST_Msk     |\
                                      RCC_APB0RSTR_TIM8RST_Msk     |\
                                      RCC_APB0RSTR_PWM0RST_Msk     |\
                                      RCC_APB0RSTR_PWM1RST_Msk     |\
                                      RCC_APB0RSTR_PWM2RST_Msk     |\
                                      RCC_APB0RSTR_PWM3RST_Msk     |\
                                      RCC_APB0RSTR_PCA2RST_Msk     |\
                                      RCC_APB0RSTR_PCA3RST_Msk     |\
                                      RCC_APB0RSTR_PCA4RST_Msk     |\
                                      RCC_APB0RSTR_PCA5RST_Msk     |\
                                      RCC_APB0RSTR_PCA6RST_Msk     |\
                                      RCC_APB0RSTR_PCA7RST_Msk     |\
                                      RCC_APB0RSTR_EXTIRST_Msk     |\
                                      RCC_APB0RSTR_WWDTRST_Msk     )

#define RCC_AHBENR_PCA0EN_Pos        0                                            /*!<RCC AHBENR: PCA0EN Position */
#define RCC_AHBENR_PCA0EN_Msk        (0x1UL /*<< RCC_AHBENR_PCA0EN_Pos*/)         /*!<RCC AHBENR: PCA0EN Mask */

#define RCC_AHBENR_PCA1EN_Pos        1                                            /*!<RCC AHBENR: PCA1EN Position */
#define RCC_AHBENR_PCA1EN_Msk        (0x1UL << RCC_AHBENR_PCA1EN_Pos)             /*!<RCC AHBENR: PCA1EN Mask */

#define RCC_AHBENR_IOCLKEN_Pos       2                                            /*!<RCC AHBENR: IOCLKEN Position */
#define RCC_AHBENR_IOCLKEN_Msk       (0x1UL << RCC_AHBENR_IOCLKEN_Pos)            /*!<RCC AHBENR: IOCLKEN Mask */

#define RCC_AHBENR_SYSCFGEN_Pos      4                                            /*!<RCC AHBENR: SYSCFGEN Position */
#define RCC_AHBENR_SYSCFGEN_Msk      (0x1UL << RCC_AHBENR_SYSCFGEN_Pos)           /*!<RCC AHBENR: SYSCFGEN Mask */

#define RCC_AHBENR_DMAEN_Pos         5                                            /*!<RCC AHBENR: DMAEN Position */
#define RCC_AHBENR_DMAEN_Msk         (0x1UL << RCC_AHBENR_DMAEN_Pos)              /*!<RCC AHBENR: DMAEN Mask */

#define RCC_AHBENR_CRCEN_Pos         6                                            /*!<RCC AHBENR: CRCEN Position */
#define RCC_AHBENR_CRCEN_Msk         (0x1UL << RCC_AHBENR_CRCEN_Pos)              /*!<RCC AHBENR: CRCEN Mask */

#define RCC_AHBENR_RAMBISTEN_Pos     7                                            /*!<RCC AHBENR: RAMBISTEN Position */
#define RCC_AHBENR_RAMBISTEN_Msk     (0x1UL << RCC_AHBENR_RAMBISTEN_Pos)          /*!<RCC AHBENR: RAMBISTEN Mask */

#define RCC_AHBENR_NTESTEN_Pos       8                                            /*!<RCC AHBENR: NTESTEN Position */
#define RCC_AHBENR_NTESTEN_Msk       (0x1UL << RCC_AHBENR_NTESTEN_Pos)            /*!<RCC AHBENR: NTESTEN Mask */

#define RCC_AHBENR_Msk_ALL           (RCC_AHBENR_PCA0EN_Msk        |\
                                      RCC_AHBENR_PCA1EN_Msk        |\
                                      RCC_AHBENR_IOCLKEN_Msk       |\
                                      RCC_AHBENR_SYSCFGEN_Msk      |\
                                      RCC_AHBENR_DMAEN_Msk         |\
                                      RCC_AHBENR_CRCEN_Msk         |\
                                      RCC_AHBENR_RAMBISTEN_Msk     |\
                                      RCC_AHBENR_NTESTEN_Msk       )

#define RCC_APB1ENR_UART0EN_Pos      0                                            /*!<RCC APB1ENR: UART0EN Position */
#define RCC_APB1ENR_UART0EN_Msk      (0x1UL /*<< RCC_APB1ENR_UART0EN_Pos*/)       /*!<RCC APB1ENR: UART0EN Mask */

#define RCC_APB1ENR_UART1EN_Pos      1                                            /*!<RCC APB1ENR: UART1EN Position */
#define RCC_APB1ENR_UART1EN_Msk      (0x1UL << RCC_APB1ENR_UART1EN_Pos)           /*!<RCC APB1ENR: UART1EN Mask */

#define RCC_APB1ENR_UART2EN_Pos      2                                            /*!<RCC APB1ENR: UART2EN Position */
#define RCC_APB1ENR_UART2EN_Msk      (0x1UL << RCC_APB1ENR_UART2EN_Pos)           /*!<RCC APB1ENR: UART2EN Mask */

#define RCC_APB1ENR_UART3EN_Pos      3                                            /*!<RCC APB1ENR: UART3EN Position */
#define RCC_APB1ENR_UART3EN_Msk      (0x1UL << RCC_APB1ENR_UART3EN_Pos)           /*!<RCC APB1ENR: UART3EN Mask */

#define RCC_APB1ENR_UART4EN_Pos      4                                            /*!<RCC APB1ENR: UART4EN Position */
#define RCC_APB1ENR_UART4EN_Msk      (0x1UL << RCC_APB1ENR_UART4EN_Pos)           /*!<RCC APB1ENR: UART4EN Mask */

#define RCC_APB1ENR_UART5EN_Pos      5                                            /*!<RCC APB1ENR: UART5EN Position */
#define RCC_APB1ENR_UART5EN_Msk      (0x1UL << RCC_APB1ENR_UART5EN_Pos)           /*!<RCC APB1ENR: UART5EN Mask */

#define RCC_APB1ENR_SPI0EN_Pos       6                                            /*!<RCC APB1ENR: SPI0EN Position */
#define RCC_APB1ENR_SPI0EN_Msk       (0x1UL << RCC_APB1ENR_SPI0EN_Pos)            /*!<RCC APB1ENR: SPI0EN Mask */

#define RCC_APB1ENR_SPI1EN_Pos       7                                            /*!<RCC APB1ENR: SPI1EN Position */
#define RCC_APB1ENR_SPI1EN_Msk       (0x1UL << RCC_APB1ENR_SPI1EN_Pos)            /*!<RCC APB1ENR: SPI1EN Mask */

#define RCC_APB1ENR_TWI0EN_Pos       8                                            /*!<RCC APB1ENR: TWI0EN Position */
#define RCC_APB1ENR_TWI0EN_Msk       (0x1UL << RCC_APB1ENR_TWI0EN_Pos)            /*!<RCC APB1ENR: TWI0EN Mask */

#define RCC_APB1ENR_TWI1EN_Pos       9                                            /*!<RCC APB1ENR: TWI1EN Position */
#define RCC_APB1ENR_TWI1EN_Msk       (0x1UL << RCC_APB1ENR_TWI1EN_Pos)            /*!<RCC APB1ENR: TWI1EN Mask */

#define RCC_APB1ENR_AMOCEN_Pos       10                                           /*!<RCC APB1ENR: AMOCEN Position */
#define RCC_APB1ENR_AMOCEN_Msk       (0x1UL << RCC_APB1ENR_AMOCEN_Pos)            /*!<RCC APB1ENR: AMOCEN Mask */

#define RCC_APB1ENR_ADCEN_Pos        11                                           /*!<RCC APB1ENR: ADCEN Position */
#define RCC_APB1ENR_ADCEN_Msk        (0x1UL << RCC_APB1ENR_ADCEN_Pos)             /*!<RCC APB1ENR: ADCEN Mask */

#define RCC_APB1ENR_LCDEN_Pos        12                                           /*!<RCC APB1ENR: LCDEN Position */
#define RCC_APB1ENR_LCDEN_Msk        (0x1UL << RCC_APB1ENR_LCDEN_Pos)             /*!<RCC APB1ENR: LCDEN Mask */

#define RCC_APB1ENR_LEDEN_Pos        13                                           /*!<RCC APB1ENR: LEDEN Position */
#define RCC_APB1ENR_LEDEN_Msk        (0x1UL << RCC_APB1ENR_LEDEN_Pos)             /*!<RCC APB1ENR: LEDEN Mask */

#define RCC_APB1ENR_TKEN_Pos         14                                           /*!<RCC APB1ENR: TKEN Position */
#define RCC_APB1ENR_TKEN_Msk         (0x1UL << RCC_APB1ENR_TKEN_Pos)              /*!<RCC APB1ENR: TKEN Mask */

#define RCC_APB1ENR_Msk_ALL          (RCC_APB1ENR_UART0EN_Msk      |\
                                      RCC_APB1ENR_UART1EN_Msk      |\
                                      RCC_APB1ENR_UART2EN_Msk      |\
                                      RCC_APB1ENR_UART3EN_Msk      |\
                                      RCC_APB1ENR_UART4EN_Msk      |\
                                      RCC_APB1ENR_UART5EN_Msk      |\
                                      RCC_APB1ENR_SPI0EN_Msk       |\
                                      RCC_APB1ENR_SPI1EN_Msk       |\
                                      RCC_APB1ENR_TWI0EN_Msk       |\
                                      RCC_APB1ENR_TWI1EN_Msk       |\
                                      RCC_APB1ENR_AMOCEN_Msk       |\
                                      RCC_APB1ENR_ADCEN_Msk        |\
                                      RCC_APB1ENR_LCDEN_Msk        |\
                                      RCC_APB1ENR_LEDEN_Msk        |\
                                      RCC_APB1ENR_TKEN_Msk         )

#define RCC_APB0ENR_TIM5EN_Pos       0                                            /*!<RCC APB0ENR: TIM5EN Position */
#define RCC_APB0ENR_TIM5EN_Msk       (0x1UL /*<< RCC_APB0ENR_TIM5EN_Pos*/)        /*!<RCC APB0ENR: TIM5EN Mask */

#define RCC_APB0ENR_TIM6EN_Pos       1                                            /*!<RCC APB0ENR: TIM6EN Position */
#define RCC_APB0ENR_TIM6EN_Msk       (0x1UL << RCC_APB0ENR_TIM6EN_Pos)            /*!<RCC APB0ENR: TIM6EN Mask */

#define RCC_APB0ENR_TIM7EN_Pos       2                                            /*!<RCC APB0ENR: TIM7EN Position */
#define RCC_APB0ENR_TIM7EN_Msk       (0x1UL << RCC_APB0ENR_TIM7EN_Pos)            /*!<RCC APB0ENR: TIM7EN Mask */

#define RCC_APB0ENR_TIM8EN_Pos       3                                            /*!<RCC APB0ENR: TIM8EN Position */
#define RCC_APB0ENR_TIM8EN_Msk       (0x1UL << RCC_APB0ENR_TIM8EN_Pos)            /*!<RCC APB0ENR: TIM8EN Mask */

#define RCC_APB0ENR_PWM0EN_Pos       4                                            /*!<RCC APB0ENR: PWM0EN Position */
#define RCC_APB0ENR_PWM0EN_Msk       (0x1UL << RCC_APB0ENR_PWM0EN_Pos)            /*!<RCC APB0ENR: PWM0EN Mask */

#define RCC_APB0ENR_PWM1EN_Pos       5                                            /*!<RCC APB0ENR: PWM1EN Position */
#define RCC_APB0ENR_PWM1EN_Msk       (0x1UL << RCC_APB0ENR_PWM1EN_Pos)            /*!<RCC APB0ENR: PWM1EN Mask */

#define RCC_APB0ENR_PWM2EN_Pos       6                                            /*!<RCC APB0ENR: PWM2EN Position */
#define RCC_APB0ENR_PWM2EN_Msk       (0x1UL << RCC_APB0ENR_PWM2EN_Pos)            /*!<RCC APB0ENR: PWM2EN Mask */

#define RCC_APB0ENR_PWM3EN_Pos       7                                            /*!<RCC APB0ENR: PWM3EN Position */
#define RCC_APB0ENR_PWM3EN_Msk       (0x1UL << RCC_APB0ENR_PWM3EN_Pos)            /*!<RCC APB0ENR: PWM3EN Mask */

#define RCC_APB0ENR_PCA2EN_Pos       8                                            /*!<RCC APB0ENR: PCA2EN Position */
#define RCC_APB0ENR_PCA2EN_Msk       (0x1UL << RCC_APB0ENR_PCA2EN_Pos)            /*!<RCC APB0ENR: PCA2EN Mask */

#define RCC_APB0ENR_PCA3EN_Pos       9                                            /*!<RCC APB0ENR: PCA3EN Position */
#define RCC_APB0ENR_PCA3EN_Msk       (0x1UL << RCC_APB0ENR_PCA3EN_Pos)            /*!<RCC APB0ENR: PCA3EN Mask */

#define RCC_APB0ENR_PCA4EN_Pos       10                                           /*!<RCC APB0ENR: PCA4EN Position */
#define RCC_APB0ENR_PCA4EN_Msk       (0x1UL << RCC_APB0ENR_PCA4EN_Pos)            /*!<RCC APB0ENR: PCA4EN Mask */

#define RCC_APB0ENR_PCA5EN_Pos       11                                           /*!<RCC APB0ENR: PCA5EN Position */
#define RCC_APB0ENR_PCA5EN_Msk       (0x1UL << RCC_APB0ENR_PCA5EN_Pos)            /*!<RCC APB0ENR: PCA5EN Mask */

#define RCC_APB0ENR_PCA6EN_Pos       12                                           /*!<RCC APB0ENR: PCA6EN Position */
#define RCC_APB0ENR_PCA6EN_Msk       (0x1UL << RCC_APB0ENR_PCA6EN_Pos)            /*!<RCC APB0ENR: PCA6EN Mask */

#define RCC_APB0ENR_PCA7EN_Pos       13                                           /*!<RCC APB0ENR: PCA7EN Position */
#define RCC_APB0ENR_PCA7EN_Msk       (0x1UL << RCC_APB0ENR_PCA7EN_Pos)            /*!<RCC APB0ENR: PCA7EN Mask */

#define RCC_APB0ENR_EXTIEN_Pos       14                                           /*!<RCC APB0ENR: EXTIEN Position */
#define RCC_APB0ENR_EXTIEN_Msk       (0x1UL << RCC_APB0ENR_EXTIEN_Pos)            /*!<RCC APB0ENR: EXTIEN Mask */

#define RCC_APB0ENR_WWDTEN_Pos       15                                           /*!<RCC APB0ENR: WWDTEN Position */
#define RCC_APB0ENR_WWDTEN_Msk       (0x1UL << RCC_APB0ENR_WWDTEN_Pos)            /*!<RCC APB0ENR: WWDTEN Mask */

#define RCC_APB0ENR_Msk_ALL          (RCC_APB0ENR_TIM5EN_Msk       |\
                                      RCC_APB0ENR_TIM6EN_Msk       |\
                                      RCC_APB0ENR_TIM7EN_Msk       |\
                                      RCC_APB0ENR_TIM8EN_Msk       |\
                                      RCC_APB0ENR_PWM0EN_Msk       |\
                                      RCC_APB0ENR_PWM1EN_Msk       |\
                                      RCC_APB0ENR_PWM2EN_Msk       |\
                                      RCC_APB0ENR_PWM3EN_Msk       |\
                                      RCC_APB0ENR_PCA2EN_Msk       |\
                                      RCC_APB0ENR_PCA3EN_Msk       |\
                                      RCC_APB0ENR_PCA4EN_Msk       |\
                                      RCC_APB0ENR_PCA5EN_Msk       |\
                                      RCC_APB0ENR_PCA6EN_Msk       |\
                                      RCC_APB0ENR_PCA7EN_Msk       |\
                                      RCC_APB0ENR_EXTIEN_Msk       |\
                                      RCC_APB0ENR_WWDTEN_Msk       )

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

#define RCC_RSTSTR_LVRSTF2_Pos       6                                            /*!<RCC RSTSTR: LVRSTF2 Position */
#define RCC_RSTSTR_LVRSTF2_Msk       (0x1UL << RCC_RSTSTR_LVRSTF2_Pos)            /*!<RCC RSTSTR: LVRSTF2 Mask */

#define RCC_RSTSTR_Msk_ALL           (RCC_RSTSTR_PINRSTF_Msk       |\
                                      RCC_RSTSTR_LVRSTF_Msk        |\
                                      RCC_RSTSTR_PORSTF_Msk        |\
                                      RCC_RSTSTR_SWRSTF_Msk        |\
                                      RCC_RSTSTR_IWDTRSTF_Msk      |\
                                      RCC_RSTSTR_WWDTRSTF_Msk      |\
                                      RCC_RSTSTR_LVRSTF2_Msk       )

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

#define RCC_RSTCLR_LVRSTF2C_Pos      6                                            /*!<RCC RSTCLR: LVRSTF2C Position */
#define RCC_RSTCLR_LVRSTF2C_Msk      (0x1UL << RCC_RSTCLR_LVRSTF2C_Pos)           /*!<RCC RSTCLR: LVRSTF2C Mask */

#define RCC_RSTCLR_Msk_ALL           (RCC_RSTCLR_PINRSTFC_Msk      |\
                                      RCC_RSTCLR_LVRSTFC_Msk       |\
                                      RCC_RSTCLR_PORSTFC_Msk       |\
                                      RCC_RSTCLR_SWRSTFC_Msk       |\
                                      RCC_RSTCLR_IWDTRSTFC_Msk     |\
                                      RCC_RSTCLR_WWDTRSTFC_Msk     |\
                                      RCC_RSTCLR_LVRSTF2C_Msk      )

#define RCC_HSICAL_HSITRIM_Pos       0                                            /*!<RCC HSICAL: HSITRIM Position */
#define RCC_HSICAL_HSITRIM_Msk       (0x7UL /*<< RCC_HSICAL_HSITRIM_Pos*/)        /*!<RCC HSICAL: HSITRIM Mask */

#define RCC_HSICAL_HSICAL_Pos        8                                            /*!<RCC HSICAL: HSICAL Position */
#define RCC_HSICAL_HSICAL_Msk        (0xFFUL << RCC_HSICAL_HSICAL_Pos)            /*!<RCC HSICAL: HSICAL Mask */

#define RCC_HSICAL_TRIMREF_Pos       16                                           /*!<RCC HSICAL: TRIMREF Position */
#define RCC_HSICAL_TRIMREF_Msk       (0x1FFFUL << RCC_HSICAL_TRIMREF_Pos)         /*!<RCC HSICAL: TRIMREF Mask */

#define RCC_HSICAL_TRIMRUN_Pos       31                                           /*!<RCC HSICAL: TRIMRUN Position */
#define RCC_HSICAL_TRIMRUN_Msk       (0x1UL << RCC_HSICAL_TRIMRUN_Pos)            /*!<RCC HSICAL: TRIMRUN Mask */

#define RCC_HSICAL_Msk_ALL           (RCC_HSICAL_HSITRIM_Msk       |\
                                      RCC_HSICAL_HSICAL_Msk        |\
                                      RCC_HSICAL_TRIMREF_Msk       |\
                                      RCC_HSICAL_TRIMRUN_Msk       )

#define RCC_CSMSEL_CSMLVL_Pos        0                                            /*!<RCC CSMSEL: CSMLVL Position */
#define RCC_CSMSEL_CSMLVL_Msk        (0x7UL /*<< RCC_CSMSEL_CSMLVL_Pos*/)         /*!<RCC CSMSEL: CSMLVL Mask */

#define RCC_CSMSEL_Msk_ALL           (RCC_CSMSEL_CSMLVL_Msk       )

#define RCC_RCCLOCK_LOCK_Pos         0                                            /*!<RCC RCCLOCK: LOCK Position */
#define RCC_RCCLOCK_LOCK_Msk         (0xFFFFUL /*<< RCC_RCCLOCK_LOCK_Pos*/)       /*!<RCC RCCLOCK: LOCK Mask */

#define RCC_RCCLOCK_Msk_ALL          (RCC_RCCLOCK_LOCK_Msk        )

#define RCC_LSECR_DRIVEON_Pos        0                                            /*!<RCC LSECR: DRIVEON Position */
#define RCC_LSECR_DRIVEON_Msk        (0x1UL /*<< RCC_LSECR_DRIVEON_Pos*/)         /*!<RCC LSECR: DRIVEON Mask */

#define RCC_LSECR_CAPON_Pos          1                                            /*!<RCC LSECR: CAPON Position */
#define RCC_LSECR_CAPON_Msk          (0x1UL << RCC_LSECR_CAPON_Pos)               /*!<RCC LSECR: CAPON Mask */

#define RCC_LSECR_Msk_ALL            (RCC_LSECR_DRIVEON_Msk        |\
                                      RCC_LSECR_CAPON_Msk          )

#define RCC_HSERFB_RFBSEL_Pos        0                                            /*!<RCC HSERFB: RFBSEL Position */
#define RCC_HSERFB_RFBSEL_Msk        (0x3UL /*<< RCC_HSERFB_RFBSEL_Pos*/)         /*!<RCC HSERFB: RFBSEL Mask */

#define RCC_HSERFB_Msk_ALL           (RCC_HSERFB_RFBSEL_Msk       )

#define DMA_IFSR_BEIF_Pos            0                                            /*!<DMA IFSR: BEIF Position */
#define DMA_IFSR_BEIF_Msk            (0xFFUL /*<< DMA_IFSR_BEIF_Pos*/)            /*!<DMA IFSR: BEIF Mask */

#define DMA_IFSR_TCIF_Pos            8                                            /*!<DMA IFSR: TCIF Position */
#define DMA_IFSR_TCIF_Msk            (0xFFUL << DMA_IFSR_TCIF_Pos)                /*!<DMA IFSR: TCIF Mask */

#define DMA_IFSR_HTIF_Pos            16                                           /*!<DMA IFSR: HTIF Position */
#define DMA_IFSR_HTIF_Msk            (0xFFUL << DMA_IFSR_HTIF_Pos)                /*!<DMA IFSR: HTIF Mask */

#define DMA_IFSR_TEIF_Pos            24                                           /*!<DMA IFSR: TEIF Position */
#define DMA_IFSR_TEIF_Msk            (0xFFUL << DMA_IFSR_TEIF_Pos)                /*!<DMA IFSR: TEIF Mask */

#define DMA_IFSR_Msk_ALL             (DMA_IFSR_BEIF_Msk            |\
                                      DMA_IFSR_TCIF_Msk            |\
                                      DMA_IFSR_HTIF_Msk            |\
                                      DMA_IFSR_TEIF_Msk            )

#define DMA_IFCR_CBEIF_Pos           0                                            /*!<DMA IFCR: CBEIF Position */
#define DMA_IFCR_CBEIF_Msk           (0xFFUL /*<< DMA_IFCR_CBEIF_Pos*/)           /*!<DMA IFCR: CBEIF Mask */

#define DMA_IFCR_CTCIF_Pos           8                                            /*!<DMA IFCR: CTCIF Position */
#define DMA_IFCR_CTCIF_Msk           (0xFFUL << DMA_IFCR_CTCIF_Pos)               /*!<DMA IFCR: CTCIF Mask */

#define DMA_IFCR_CHTIF_Pos           16                                           /*!<DMA IFCR: CHTIF Position */
#define DMA_IFCR_CHTIF_Msk           (0xFFUL << DMA_IFCR_CHTIF_Pos)               /*!<DMA IFCR: CHTIF Mask */

#define DMA_IFCR_CTEIF_Pos           24                                           /*!<DMA IFCR: CTEIF Position */
#define DMA_IFCR_CTEIF_Msk           (0xFFUL << DMA_IFCR_CTEIF_Pos)               /*!<DMA IFCR: CTEIF Mask */

#define DMA_IFCR_Msk_ALL             (DMA_IFCR_CBEIF_Msk           |\
                                      DMA_IFCR_CTCIF_Msk           |\
                                      DMA_IFCR_CHTIF_Msk           |\
                                      DMA_IFCR_CTEIF_Msk           )

#define DMA_CSR_SWTRG_Pos            0                                            /*!<DMA CSR: SWTRG Position */
#define DMA_CSR_SWTRG_Msk            (0xFFUL /*<< DMA_CSR_SWTRG_Pos*/)            /*!<DMA CSR: SWTRG Mask */

#define DMA_CSR_DBUSY_Pos            8                                            /*!<DMA CSR: DBUSY Position */
#define DMA_CSR_DBUSY_Msk            (0xFFUL << DMA_CSR_DBUSY_Pos)                /*!<DMA CSR: DBUSY Mask */

#define DMA_CSR_BURSTIDLE_Pos        16                                           /*!<DMA CSR: BURSTIDLE Position */
#define DMA_CSR_BURSTIDLE_Msk        (0xFUL << DMA_CSR_BURSTIDLE_Pos)             /*!<DMA CSR: BURSTIDLE Mask */

#define DMA_CSR_RELOAD_Pos           24                                           /*!<DMA CSR: RELOAD Position */
#define DMA_CSR_RELOAD_Msk           (0xFFUL << DMA_CSR_RELOAD_Pos)               /*!<DMA CSR: RELOAD Mask */

#define DMA_CSR_Msk_ALL              (DMA_CSR_SWTRG_Msk            |\
                                      DMA_CSR_DBUSY_Msk            |\
                                      DMA_CSR_BURSTIDLE_Msk        |\
                                      DMA_CSR_RELOAD_Msk           )

#define DMA_CCR_EN_Pos              0                                            /*!<DMA CCR: EN Position */
#define DMA_CCR_EN_Msk              (0x1UL /*<< DMA_CCR_EN_Pos*/)                /*!<DMA CCR: EN Mask */

#define DMA_CCR_TCIE_Pos            1                                            /*!<DMA CCR: TCIE Position */
#define DMA_CCR_TCIE_Msk            (0x1UL << DMA_CCR_TCIE_Pos)                  /*!<DMA CCR: TCIE Mask */

#define DMA_CCR_HTIE_Pos            2                                            /*!<DMA CCR: HTIE Position */
#define DMA_CCR_HTIE_Msk            (0x1UL << DMA_CCR_HTIE_Pos)                  /*!<DMA CCR: HTIE Mask */

#define DMA_CCR_BEIE_Pos            3                                            /*!<DMA CCR: BEIE Position */
#define DMA_CCR_BEIE_Msk            (0x1UL << DMA_CCR_BEIE_Pos)                  /*!<DMA CCR: BEIE Mask */

#define DMA_CCR_TEIE_Pos            4                                            /*!<DMA CCR: TEIE Position */
#define DMA_CCR_TEIE_Msk            (0x1UL << DMA_CCR_TEIE_Pos)                  /*!<DMA CCR: TEIE Mask */

#define DMA_CCR_DPTYP_Pos           6                                            /*!<DMA CCR: DPTYP Position */
#define DMA_CCR_DPTYP_Msk           (0x3UL << DMA_CCR_DPTYP_Pos)                 /*!<DMA CCR: DPTYP Mask */

#define DMA_CCR_SPTYP_Pos           8                                            /*!<DMA CCR: SPTYP Position */
#define DMA_CCR_SPTYP_Msk           (0x3UL << DMA_CCR_SPTYP_Pos)                 /*!<DMA CCR: SPTYP Mask */

#define DMA_CCR_DSIZE_Pos           10                                           /*!<DMA CCR: DSIZE Position */
#define DMA_CCR_DSIZE_Msk           (0x3UL << DMA_CCR_DSIZE_Pos)                 /*!<DMA CCR: DSIZE Mask */

#define DMA_CCR_SSIZE_Pos           12                                           /*!<DMA CCR: SSIZE Position */
#define DMA_CCR_SSIZE_Msk           (0x3UL << DMA_CCR_SSIZE_Pos)                 /*!<DMA CCR: SSIZE Mask */

#define DMA_CCR_PL_Pos              14                                           /*!<DMA CCR: PL Position */
#define DMA_CCR_PL_Msk              (0x3UL << DMA_CCR_PL_Pos)                    /*!<DMA CCR: PL Mask */

#define DMA_CCR_BURSTLEN_Pos        16                                           /*!<DMA CCR: BURSTLEN Position */
#define DMA_CCR_BURSTLEN_Msk        (0xFUL << DMA_CCR_BURSTLEN_Pos)              /*!<DMA CCR: BURSTLEN Mask */

#define DMA_CCR_STRMSEL_Pos         20                                           /*!<DMA CCR: STRMSEL Position */
#define DMA_CCR_STRMSEL_Msk         (0x7UL << DMA_CCR_STRMSEL_Pos)               /*!<DMA CCR: STRMSEL Mask */

#define DMA_CCR_TRGMODE_Pos         23                                           /*!<DMA CCR: TRGMODE Position */
#define DMA_CCR_TRGMODE_Msk         (0x1UL << DMA_CCR_TRGMODE_Pos)               /*!<DMA CCR: TRGMODE Mask */

#define DMA_CCR_Msk_ALL             (DMA_CCR_EN_Msk              |\
                                      DMA_CCR_TCIE_Msk            |\
                                      DMA_CCR_HTIE_Msk            |\
                                      DMA_CCR_BEIE_Msk            |\
                                      DMA_CCR_TEIE_Msk            |\
                                      DMA_CCR_DPTYP_Msk           |\
                                      DMA_CCR_SPTYP_Msk           |\
                                      DMA_CCR_DSIZE_Msk           |\
                                      DMA_CCR_SSIZE_Msk           |\
                                      DMA_CCR_PL_Msk              |\
                                      DMA_CCR_BURSTLEN_Msk        |\
                                      DMA_CCR_STRMSEL_Msk         |\
                                      DMA_CCR_TRGMODE_Msk         )

#define DMA_NPKT_NPKT_Pos           0                                            /*!<DMA NPKT: NPKT Position */
#define DMA_NPKT_NPKT_Msk           (0x7FFUL /*<< DMA_NPKT_NPKT_Pos*/)           /*!<DMA NPKT: NPKT Mask */

#define DMA_NPKT_Msk_ALL            (DMA_NPKT_NPKT_Msk          )

#define DMA_CPKT_CPKT_Pos           0                                            /*!<DMA CPKT: CPKT Position */
#define DMA_CPKT_CPKT_Msk           (0x7FFUL /*<< DMA_CPKT_CPKT_Pos*/)           /*!<DMA CPKT: CPKT Mask */

#define DMA_CPKT_Msk_ALL            (DMA_CPKT_CPKT_Msk          )


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

#define RAMBIST_ADDR_RAMADR_Pos      0                                            /*!<RAMBIST ADDR: RAMADR Position */
#define RAMBIST_ADDR_RAMADR_Msk      (0x3FFFUL /*<< RAMBIST_ADDR_RAMADR_Pos*/)    /*!<RAMBIST ADDR: RAMADR Mask */

#define RAMBIST_ADDR_RAMTYP_Pos      28                                           /*!<RAMBIST ADDR: RAMTYP Position */
#define RAMBIST_ADDR_RAMTYP_Msk      (0x3UL << RAMBIST_ADDR_RAMTYP_Pos)           /*!<RAMBIST ADDR: RAMTYP Mask */

#define RAMBIST_ADDR_Msk_ALL         (RAMBIST_ADDR_RAMADR_Msk      |\
                                      RAMBIST_ADDR_RAMTYP_Msk      )

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

#define GPIO_CFG_LCKR_LCK_Pos        0                                            /*!<GPIO_CFG LCKR: LCK Position */
#define GPIO_CFG_LCKR_LCK_Msk        (0xFFFFUL /*<< GPIO_CFG_LCKR_LCK_Pos*/)      /*!<GPIO_CFG LCKR: LCK Mask */

#define GPIO_CFG_LCKR_LOCK_Pos       16                                           /*!<GPIO_CFG LCKR: LOCK Position */
#define GPIO_CFG_LCKR_LOCK_Msk       (0xFFFFUL << GPIO_CFG_LCKR_LOCK_Pos)         /*!<GPIO_CFG LCKR: LOCK Mask */

#define GPIO_CFG_LCKR_Msk_ALL        (GPIO_CFG_LCKR_LCK_Msk        |\
                                      GPIO_CFG_LCKR_LOCK_Msk       )

#define GPIO_CFG_IE_IE_Pos           0                                            /*!<GPIO_CFG IE: IE Position */
#define GPIO_CFG_IE_IE_Msk           (0xFFFFUL /*<< GPIO_CFG_IE_IE_Pos*/)         /*!<GPIO_CFG IE: IE Mask */

#define GPIO_CFG_IE_Msk_ALL          (GPIO_CFG_IE_IE_Msk          )

#define GPIO_CFG_OTYPER_OT_Pos       0                                            /*!<GPIO_CFG OTYPER: OT Position */
#define GPIO_CFG_OTYPER_OT_Msk       (0xFFFFUL /*<< GPIO_CFG_OTYPER_OT_Pos*/)     /*!<GPIO_CFG OTYPER: OT Mask */
#define GPIO_CFG_OTYPER_OT0_Msk      (0x1UL /*<< GPIO_CFG_OTYPER_OT_Pos*/)        /*!<GPIO_CFG OTYPER: OT0 Mask */

#define GPIO_CFG_OTYPER_Msk_ALL      (GPIO_CFG_OTYPER_OT_Msk      )

#define GPIO_CFG_ODRVR_ODRVR0_Pos    0                                            /*!<GPIO_CFG ODRVR: ODRVR0 Position */
#define GPIO_CFG_ODRVR_ODRVR0_Msk    (0x1UL /*<< GPIO_CFG_ODRVR_ODRVR0_Pos*/)     /*!<GPIO_CFG ODRVR: ODRVR0 Mask */

#define GPIO_CFG_ODRVR_ODRVR1_Pos    2                                            /*!<GPIO_CFG ODRVR: ODRVR1 Position */
#define GPIO_CFG_ODRVR_ODRVR1_Msk    (0x1UL << GPIO_CFG_ODRVR_ODRVR1_Pos)         /*!<GPIO_CFG ODRVR: ODRVR1 Mask */

#define GPIO_CFG_ODRVR_ODRVR2_Pos    4                                            /*!<GPIO_CFG ODRVR: ODRVR2 Position */
#define GPIO_CFG_ODRVR_ODRVR2_Msk    (0x1UL << GPIO_CFG_ODRVR_ODRVR2_Pos)         /*!<GPIO_CFG ODRVR: ODRVR2 Mask */

#define GPIO_CFG_ODRVR_ODRVR3_Pos    6                                            /*!<GPIO_CFG ODRVR: ODRVR3 Position */
#define GPIO_CFG_ODRVR_ODRVR3_Msk    (0x1UL << GPIO_CFG_ODRVR_ODRVR3_Pos)         /*!<GPIO_CFG ODRVR: ODRVR3 Mask */

#define GPIO_CFG_ODRVR_ODRVR4_Pos    8                                            /*!<GPIO_CFG ODRVR: ODRVR4 Position */
#define GPIO_CFG_ODRVR_ODRVR4_Msk    (0x1UL << GPIO_CFG_ODRVR_ODRVR4_Pos)         /*!<GPIO_CFG ODRVR: ODRVR4 Mask */

#define GPIO_CFG_ODRVR_ODRVR5_Pos    10                                           /*!<GPIO_CFG ODRVR: ODRVR5 Position */
#define GPIO_CFG_ODRVR_ODRVR5_Msk    (0x1UL << GPIO_CFG_ODRVR_ODRVR5_Pos)         /*!<GPIO_CFG ODRVR: ODRVR5 Mask */

#define GPIO_CFG_ODRVR_ODRVR6_Pos    12                                           /*!<GPIO_CFG ODRVR: ODRVR6 Position */
#define GPIO_CFG_ODRVR_ODRVR6_Msk    (0x1UL << GPIO_CFG_ODRVR_ODRVR6_Pos)         /*!<GPIO_CFG ODRVR: ODRVR6 Mask */

#define GPIO_CFG_ODRVR_ODRVR7_Pos    14                                           /*!<GPIO_CFG ODRVR: ODRVR7 Position */
#define GPIO_CFG_ODRVR_ODRVR7_Msk    (0x1UL << GPIO_CFG_ODRVR_ODRVR7_Pos)         /*!<GPIO_CFG ODRVR: ODRVR7 Mask */

#define GPIO_CFG_ODRVR_ODRVR8_Pos    16                                           /*!<GPIO_CFG ODRVR: ODRVR8 Position */
#define GPIO_CFG_ODRVR_ODRVR8_Msk    (0x1UL << GPIO_CFG_ODRVR_ODRVR8_Pos)         /*!<GPIO_CFG ODRVR: ODRVR8 Mask */

#define GPIO_CFG_ODRVR_ODRVR9_Pos    18                                           /*!<GPIO_CFG ODRVR: ODRVR9 Position */
#define GPIO_CFG_ODRVR_ODRVR9_Msk    (0x1UL << GPIO_CFG_ODRVR_ODRVR9_Pos)         /*!<GPIO_CFG ODRVR: ODRVR9 Mask */

#define GPIO_CFG_ODRVR_ODRVR10_Pos   20                                           /*!<GPIO_CFG ODRVR: ODRVR10 Position */
#define GPIO_CFG_ODRVR_ODRVR10_Msk   (0x1UL << GPIO_CFG_ODRVR_ODRVR10_Pos)        /*!<GPIO_CFG ODRVR: ODRVR10 Mask */

#define GPIO_CFG_ODRVR_ODRVR11_Pos   22                                           /*!<GPIO_CFG ODRVR: ODRVR11 Position */
#define GPIO_CFG_ODRVR_ODRVR11_Msk   (0x1UL << GPIO_CFG_ODRVR_ODRVR11_Pos)        /*!<GPIO_CFG ODRVR: ODRVR11 Mask */

#define GPIO_CFG_ODRVR_ODRVR12_Pos   24                                           /*!<GPIO_CFG ODRVR: ODRVR12 Position */
#define GPIO_CFG_ODRVR_ODRVR12_Msk   (0x1UL << GPIO_CFG_ODRVR_ODRVR12_Pos)        /*!<GPIO_CFG ODRVR: ODRVR12 Mask */

#define GPIO_CFG_ODRVR_ODRVR13_Pos   26                                           /*!<GPIO_CFG ODRVR: ODRVR13 Position */
#define GPIO_CFG_ODRVR_ODRVR13_Msk   (0x1UL << GPIO_CFG_ODRVR_ODRVR13_Pos)        /*!<GPIO_CFG ODRVR: ODRVR13 Mask */

#define GPIO_CFG_ODRVR_ODRVR14_Pos   28                                           /*!<GPIO_CFG ODRVR: ODRVR14 Position */
#define GPIO_CFG_ODRVR_ODRVR14_Msk   (0x1UL << GPIO_CFG_ODRVR_ODRVR14_Pos)        /*!<GPIO_CFG ODRVR: ODRVR14 Mask */

#define GPIO_CFG_ODRVR_ODRVR15_Pos   30                                           /*!<GPIO_CFG ODRVR: ODRVR15 Position */
#define GPIO_CFG_ODRVR_ODRVR15_Msk   (0x1UL << GPIO_CFG_ODRVR_ODRVR15_Pos)        /*!<GPIO_CFG ODRVR: ODRVR15 Mask */

#define GPIO_CFG_ODRVR_Msk_ALL       (GPIO_CFG_ODRVR_ODRVR0_Msk    |\
                                      GPIO_CFG_ODRVR_ODRVR1_Msk    |\
                                      GPIO_CFG_ODRVR_ODRVR2_Msk    |\
                                      GPIO_CFG_ODRVR_ODRVR3_Msk    |\
                                      GPIO_CFG_ODRVR_ODRVR4_Msk    |\
                                      GPIO_CFG_ODRVR_ODRVR5_Msk    |\
                                      GPIO_CFG_ODRVR_ODRVR6_Msk    |\
                                      GPIO_CFG_ODRVR_ODRVR7_Msk    |\
                                      GPIO_CFG_ODRVR_ODRVR8_Msk    |\
                                      GPIO_CFG_ODRVR_ODRVR9_Msk    |\
                                      GPIO_CFG_ODRVR_ODRVR10_Msk   |\
                                      GPIO_CFG_ODRVR_ODRVR11_Msk   |\
                                      GPIO_CFG_ODRVR_ODRVR12_Msk   |\
                                      GPIO_CFG_ODRVR_ODRVR13_Msk   |\
                                      GPIO_CFG_ODRVR_ODRVR14_Msk   |\
                                      GPIO_CFG_ODRVR_ODRVR15_Msk   )

#define GPIO_CFG_PUPDR_PHDR0_Pos     0                                            /*!<GPIO_CFG PUPDR: PHDR0 Position */
#define GPIO_CFG_PUPDR_PHDR0_Msk     (0x1UL /*<< GPIO_CFG_PUPDR_PHDR0_Pos*/)      /*!<GPIO_CFG PUPDR: PHDR0 Mask */

#define GPIO_CFG_PUPDR_PLDR0_Pos     1                                            /*!<GPIO_CFG PUPDR: PLDR0 Position */
#define GPIO_CFG_PUPDR_PLDR0_Msk     (0x1UL << GPIO_CFG_PUPDR_PLDR0_Pos)          /*!<GPIO_CFG PUPDR: PLDR0 Mask */

#define GPIO_CFG_PUPDR_PHDR1_Pos     2                                            /*!<GPIO_CFG PUPDR: PHDR1 Position */
#define GPIO_CFG_PUPDR_PHDR1_Msk     (0x1UL << GPIO_CFG_PUPDR_PHDR1_Pos)          /*!<GPIO_CFG PUPDR: PHDR1 Mask */

#define GPIO_CFG_PUPDR_PLDR1_Pos     3                                            /*!<GPIO_CFG PUPDR: PLDR1 Position */
#define GPIO_CFG_PUPDR_PLDR1_Msk     (0x1UL << GPIO_CFG_PUPDR_PLDR1_Pos)          /*!<GPIO_CFG PUPDR: PLDR1 Mask */

#define GPIO_CFG_PUPDR_PHDR2_Pos     4                                            /*!<GPIO_CFG PUPDR: PHDR2 Position */
#define GPIO_CFG_PUPDR_PHDR2_Msk     (0x1UL << GPIO_CFG_PUPDR_PHDR2_Pos)          /*!<GPIO_CFG PUPDR: PHDR2 Mask */

#define GPIO_CFG_PUPDR_PLDR2_Pos     5                                            /*!<GPIO_CFG PUPDR: PLDR2 Position */
#define GPIO_CFG_PUPDR_PLDR2_Msk     (0x1UL << GPIO_CFG_PUPDR_PLDR2_Pos)          /*!<GPIO_CFG PUPDR: PLDR2 Mask */

#define GPIO_CFG_PUPDR_PHDR3_Pos     6                                            /*!<GPIO_CFG PUPDR: PHDR3 Position */
#define GPIO_CFG_PUPDR_PHDR3_Msk     (0x1UL << GPIO_CFG_PUPDR_PHDR3_Pos)          /*!<GPIO_CFG PUPDR: PHDR3 Mask */

#define GPIO_CFG_PUPDR_PLDR3_Pos     7                                            /*!<GPIO_CFG PUPDR: PLDR3 Position */
#define GPIO_CFG_PUPDR_PLDR3_Msk     (0x1UL << GPIO_CFG_PUPDR_PLDR3_Pos)          /*!<GPIO_CFG PUPDR: PLDR3 Mask */

#define GPIO_CFG_PUPDR_PHDR4_Pos     8                                            /*!<GPIO_CFG PUPDR: PHDR4 Position */
#define GPIO_CFG_PUPDR_PHDR4_Msk     (0x1UL << GPIO_CFG_PUPDR_PHDR4_Pos)          /*!<GPIO_CFG PUPDR: PHDR4 Mask */

#define GPIO_CFG_PUPDR_PLDR4_Pos     9                                            /*!<GPIO_CFG PUPDR: PLDR4 Position */
#define GPIO_CFG_PUPDR_PLDR4_Msk     (0x1UL << GPIO_CFG_PUPDR_PLDR4_Pos)          /*!<GPIO_CFG PUPDR: PLDR4 Mask */

#define GPIO_CFG_PUPDR_PHDR5_Pos     10                                           /*!<GPIO_CFG PUPDR: PHDR5 Position */
#define GPIO_CFG_PUPDR_PHDR5_Msk     (0x1UL << GPIO_CFG_PUPDR_PHDR5_Pos)          /*!<GPIO_CFG PUPDR: PHDR5 Mask */

#define GPIO_CFG_PUPDR_PLDR5_Pos     11                                           /*!<GPIO_CFG PUPDR: PLDR5 Position */
#define GPIO_CFG_PUPDR_PLDR5_Msk     (0x1UL << GPIO_CFG_PUPDR_PLDR5_Pos)          /*!<GPIO_CFG PUPDR: PLDR5 Mask */

#define GPIO_CFG_PUPDR_PHDR6_Pos     12                                           /*!<GPIO_CFG PUPDR: PHDR6 Position */
#define GPIO_CFG_PUPDR_PHDR6_Msk     (0x1UL << GPIO_CFG_PUPDR_PHDR6_Pos)          /*!<GPIO_CFG PUPDR: PHDR6 Mask */

#define GPIO_CFG_PUPDR_PLDR6_Pos     13                                           /*!<GPIO_CFG PUPDR: PLDR6 Position */
#define GPIO_CFG_PUPDR_PLDR6_Msk     (0x1UL << GPIO_CFG_PUPDR_PLDR6_Pos)          /*!<GPIO_CFG PUPDR: PLDR6 Mask */

#define GPIO_CFG_PUPDR_PHDR7_Pos     14                                           /*!<GPIO_CFG PUPDR: PHDR7 Position */
#define GPIO_CFG_PUPDR_PHDR7_Msk     (0x1UL << GPIO_CFG_PUPDR_PHDR7_Pos)          /*!<GPIO_CFG PUPDR: PHDR7 Mask */

#define GPIO_CFG_PUPDR_PLDR7_Pos     15                                           /*!<GPIO_CFG PUPDR: PLDR7 Position */
#define GPIO_CFG_PUPDR_PLDR7_Msk     (0x1UL << GPIO_CFG_PUPDR_PLDR7_Pos)          /*!<GPIO_CFG PUPDR: PLDR7 Mask */

#define GPIO_CFG_PUPDR_PHDR8_Pos     16                                           /*!<GPIO_CFG PUPDR: PHDR8 Position */
#define GPIO_CFG_PUPDR_PHDR8_Msk     (0x1UL << GPIO_CFG_PUPDR_PHDR8_Pos)          /*!<GPIO_CFG PUPDR: PHDR8 Mask */

#define GPIO_CFG_PUPDR_PLDR8_Pos     17                                           /*!<GPIO_CFG PUPDR: PLDR8 Position */
#define GPIO_CFG_PUPDR_PLDR8_Msk     (0x1UL << GPIO_CFG_PUPDR_PLDR8_Pos)          /*!<GPIO_CFG PUPDR: PLDR8 Mask */

#define GPIO_CFG_PUPDR_PHDR9_Pos     18                                           /*!<GPIO_CFG PUPDR: PHDR9 Position */
#define GPIO_CFG_PUPDR_PHDR9_Msk     (0x1UL << GPIO_CFG_PUPDR_PHDR9_Pos)          /*!<GPIO_CFG PUPDR: PHDR9 Mask */

#define GPIO_CFG_PUPDR_PLDR9_Pos     19                                           /*!<GPIO_CFG PUPDR: PLDR9 Position */
#define GPIO_CFG_PUPDR_PLDR9_Msk     (0x1UL << GPIO_CFG_PUPDR_PLDR9_Pos)          /*!<GPIO_CFG PUPDR: PLDR9 Mask */

#define GPIO_CFG_PUPDR_PHDR10_Pos    20                                           /*!<GPIO_CFG PUPDR: PHDR10 Position */
#define GPIO_CFG_PUPDR_PHDR10_Msk    (0x1UL << GPIO_CFG_PUPDR_PHDR10_Pos)         /*!<GPIO_CFG PUPDR: PHDR10 Mask */

#define GPIO_CFG_PUPDR_PLDR10_Pos    21                                           /*!<GPIO_CFG PUPDR: PLDR10 Position */
#define GPIO_CFG_PUPDR_PLDR10_Msk    (0x1UL << GPIO_CFG_PUPDR_PLDR10_Pos)         /*!<GPIO_CFG PUPDR: PLDR10 Mask */

#define GPIO_CFG_PUPDR_PHDR11_Pos    22                                           /*!<GPIO_CFG PUPDR: PHDR11 Position */
#define GPIO_CFG_PUPDR_PHDR11_Msk    (0x1UL << GPIO_CFG_PUPDR_PHDR11_Pos)         /*!<GPIO_CFG PUPDR: PHDR11 Mask */

#define GPIO_CFG_PUPDR_PLDR11_Pos    23                                           /*!<GPIO_CFG PUPDR: PLDR11 Position */
#define GPIO_CFG_PUPDR_PLDR11_Msk    (0x1UL << GPIO_CFG_PUPDR_PLDR11_Pos)         /*!<GPIO_CFG PUPDR: PLDR11 Mask */

#define GPIO_CFG_PUPDR_PHDR12_Pos    24                                           /*!<GPIO_CFG PUPDR: PHDR12 Position */
#define GPIO_CFG_PUPDR_PHDR12_Msk    (0x1UL << GPIO_CFG_PUPDR_PHDR12_Pos)         /*!<GPIO_CFG PUPDR: PHDR12 Mask */

#define GPIO_CFG_PUPDR_PLDR12_Pos    25                                           /*!<GPIO_CFG PUPDR: PLDR12 Position */
#define GPIO_CFG_PUPDR_PLDR12_Msk    (0x1UL << GPIO_CFG_PUPDR_PLDR12_Pos)         /*!<GPIO_CFG PUPDR: PLDR12 Mask */

#define GPIO_CFG_PUPDR_PHDR13_Pos    26                                           /*!<GPIO_CFG PUPDR: PHDR13 Position */
#define GPIO_CFG_PUPDR_PHDR13_Msk    (0x1UL << GPIO_CFG_PUPDR_PHDR13_Pos)         /*!<GPIO_CFG PUPDR: PHDR13 Mask */

#define GPIO_CFG_PUPDR_PLDR13_Pos    27                                           /*!<GPIO_CFG PUPDR: PLDR13 Position */
#define GPIO_CFG_PUPDR_PLDR13_Msk    (0x1UL << GPIO_CFG_PUPDR_PLDR13_Pos)         /*!<GPIO_CFG PUPDR: PLDR13 Mask */

#define GPIO_CFG_PUPDR_PHDR14_Pos    28                                           /*!<GPIO_CFG PUPDR: PHDR14 Position */
#define GPIO_CFG_PUPDR_PHDR14_Msk    (0x1UL << GPIO_CFG_PUPDR_PHDR14_Pos)         /*!<GPIO_CFG PUPDR: PHDR14 Mask */

#define GPIO_CFG_PUPDR_PLDR14_Pos    29                                           /*!<GPIO_CFG PUPDR: PLDR14 Position */
#define GPIO_CFG_PUPDR_PLDR14_Msk    (0x1UL << GPIO_CFG_PUPDR_PLDR14_Pos)         /*!<GPIO_CFG PUPDR: PLDR14 Mask */

#define GPIO_CFG_PUPDR_PHDR15_Pos    30                                           /*!<GPIO_CFG PUPDR: PHDR15 Position */
#define GPIO_CFG_PUPDR_PHDR15_Msk    (0x1UL << GPIO_CFG_PUPDR_PHDR15_Pos)         /*!<GPIO_CFG PUPDR: PHDR15 Mask */

#define GPIO_CFG_PUPDR_PLDR15_Pos    31                                           /*!<GPIO_CFG PUPDR: PLDR15 Position */
#define GPIO_CFG_PUPDR_PLDR15_Msk    (0x1UL << GPIO_CFG_PUPDR_PLDR15_Pos)         /*!<GPIO_CFG PUPDR: PLDR15 Mask */

#define GPIO_CFG_PUPDR_Msk_ALL       (GPIO_CFG_PUPDR_PHDR0_Msk     |\
                                      GPIO_CFG_PUPDR_PLDR0_Msk     |\
                                      GPIO_CFG_PUPDR_PHDR1_Msk     |\
                                      GPIO_CFG_PUPDR_PLDR1_Msk     |\
                                      GPIO_CFG_PUPDR_PHDR2_Msk     |\
                                      GPIO_CFG_PUPDR_PLDR2_Msk     |\
                                      GPIO_CFG_PUPDR_PHDR3_Msk     |\
                                      GPIO_CFG_PUPDR_PLDR3_Msk     |\
                                      GPIO_CFG_PUPDR_PHDR4_Msk     |\
                                      GPIO_CFG_PUPDR_PLDR4_Msk     |\
                                      GPIO_CFG_PUPDR_PHDR5_Msk     |\
                                      GPIO_CFG_PUPDR_PLDR5_Msk     |\
                                      GPIO_CFG_PUPDR_PHDR6_Msk     |\
                                      GPIO_CFG_PUPDR_PLDR6_Msk     |\
                                      GPIO_CFG_PUPDR_PHDR7_Msk     |\
                                      GPIO_CFG_PUPDR_PLDR7_Msk     |\
                                      GPIO_CFG_PUPDR_PHDR8_Msk     |\
                                      GPIO_CFG_PUPDR_PLDR8_Msk     |\
                                      GPIO_CFG_PUPDR_PHDR9_Msk     |\
                                      GPIO_CFG_PUPDR_PLDR9_Msk     |\
                                      GPIO_CFG_PUPDR_PHDR10_Msk    |\
                                      GPIO_CFG_PUPDR_PLDR10_Msk    |\
                                      GPIO_CFG_PUPDR_PHDR11_Msk    |\
                                      GPIO_CFG_PUPDR_PLDR11_Msk    |\
                                      GPIO_CFG_PUPDR_PHDR12_Msk    |\
                                      GPIO_CFG_PUPDR_PLDR12_Msk    |\
                                      GPIO_CFG_PUPDR_PHDR13_Msk    |\
                                      GPIO_CFG_PUPDR_PLDR13_Msk    |\
                                      GPIO_CFG_PUPDR_PHDR14_Msk    |\
                                      GPIO_CFG_PUPDR_PLDR14_Msk    |\
                                      GPIO_CFG_PUPDR_PHDR15_Msk    |\
                                      GPIO_CFG_PUPDR_PLDR15_Msk    )

#define GPIO_CFG_TTLEN_PA0_Pos       0                                            /*!<GPIO_CFG TTLEN: PA0 Position */
#define GPIO_CFG_TTLEN_PA0_Msk       (0x1UL /*<< GPIO_CFG_TTLEN_PA0_Pos*/)        /*!<GPIO_CFG TTLEN: PA0 Mask */

#define GPIO_CFG_TTLEN_PA1_Pos       1                                            /*!<GPIO_CFG TTLEN: PA1 Position */
#define GPIO_CFG_TTLEN_PA1_Msk       (0x1UL << GPIO_CFG_TTLEN_PA1_Pos)            /*!<GPIO_CFG TTLEN: PA1 Mask */

#define GPIO_CFG_TTLEN_PA2_Pos       2                                            /*!<GPIO_CFG TTLEN: PA2 Position */
#define GPIO_CFG_TTLEN_PA2_Msk       (0x1UL << GPIO_CFG_TTLEN_PA2_Pos)            /*!<GPIO_CFG TTLEN: PA2 Mask */

#define GPIO_CFG_TTLEN_PA3_Pos       3                                            /*!<GPIO_CFG TTLEN: PA3 Position */
#define GPIO_CFG_TTLEN_PA3_Msk       (0x1UL << GPIO_CFG_TTLEN_PA3_Pos)            /*!<GPIO_CFG TTLEN: PA3 Mask */

#define GPIO_CFG_TTLEN_PA4_Pos       4                                            /*!<GPIO_CFG TTLEN: PA4 Position */
#define GPIO_CFG_TTLEN_PA4_Msk       (0x1UL << GPIO_CFG_TTLEN_PA4_Pos)            /*!<GPIO_CFG TTLEN: PA4 Mask */

#define GPIO_CFG_TTLEN_PA5_Pos       5                                            /*!<GPIO_CFG TTLEN: PA5 Position */
#define GPIO_CFG_TTLEN_PA5_Msk       (0x1UL << GPIO_CFG_TTLEN_PA5_Pos)            /*!<GPIO_CFG TTLEN: PA5 Mask */

#define GPIO_CFG_TTLEN_PA6_Pos       6                                            /*!<GPIO_CFG TTLEN: PA6 Position */
#define GPIO_CFG_TTLEN_PA6_Msk       (0x1UL << GPIO_CFG_TTLEN_PA6_Pos)            /*!<GPIO_CFG TTLEN: PA6 Mask */

#define GPIO_CFG_TTLEN_PA7_Pos       7                                            /*!<GPIO_CFG TTLEN: PA7 Position */
#define GPIO_CFG_TTLEN_PA7_Msk       (0x1UL << GPIO_CFG_TTLEN_PA7_Pos)            /*!<GPIO_CFG TTLEN: PA7 Mask */

#define GPIO_CFG_TTLEN_PA8_Pos       8                                            /*!<GPIO_CFG TTLEN: PA8 Position */
#define GPIO_CFG_TTLEN_PA8_Msk       (0x1UL << GPIO_CFG_TTLEN_PA8_Pos)            /*!<GPIO_CFG TTLEN: PA8 Mask */

#define GPIO_CFG_TTLEN_PA9_Pos       9                                            /*!<GPIO_CFG TTLEN: PA9 Position */
#define GPIO_CFG_TTLEN_PA9_Msk       (0x1UL << GPIO_CFG_TTLEN_PA9_Pos)            /*!<GPIO_CFG TTLEN: PA9 Mask */

#define GPIO_CFG_TTLEN_PA10_Pos      10                                           /*!<GPIO_CFG TTLEN: PA10 Position */
#define GPIO_CFG_TTLEN_PA10_Msk      (0x1UL << GPIO_CFG_TTLEN_PA10_Pos)           /*!<GPIO_CFG TTLEN: PA10 Mask */

#define GPIO_CFG_TTLEN_PA11_Pos      11                                           /*!<GPIO_CFG TTLEN: PA11 Position */
#define GPIO_CFG_TTLEN_PA11_Msk      (0x1UL << GPIO_CFG_TTLEN_PA11_Pos)           /*!<GPIO_CFG TTLEN: PA11 Mask */

#define GPIO_CFG_TTLEN_PA12_Pos      12                                           /*!<GPIO_CFG TTLEN: PA12 Position */
#define GPIO_CFG_TTLEN_PA12_Msk      (0x1UL << GPIO_CFG_TTLEN_PA12_Pos)           /*!<GPIO_CFG TTLEN: PA12 Mask */

#define GPIO_CFG_TTLEN_PA13_Pos      13                                           /*!<GPIO_CFG TTLEN: PA13 Position */
#define GPIO_CFG_TTLEN_PA13_Msk      (0x1UL << GPIO_CFG_TTLEN_PA13_Pos)           /*!<GPIO_CFG TTLEN: PA13 Mask */

#define GPIO_CFG_TTLEN_PA14_Pos      14                                           /*!<GPIO_CFG TTLEN: PA14 Position */
#define GPIO_CFG_TTLEN_PA14_Msk      (0x1UL << GPIO_CFG_TTLEN_PA14_Pos)           /*!<GPIO_CFG TTLEN: PA14 Mask */

#define GPIO_CFG_TTLEN_PA15_Pos      15                                           /*!<GPIO_CFG TTLEN: PA15 Position */
#define GPIO_CFG_TTLEN_PA15_Msk      (0x1UL << GPIO_CFG_TTLEN_PA15_Pos)           /*!<GPIO_CFG TTLEN: PA15 Mask */

#define GPIO_CFG_TTLEN_Msk_ALL       (GPIO_CFG_TTLEN_PA0_Msk       |\
                                      GPIO_CFG_TTLEN_PA1_Msk       |\
                                      GPIO_CFG_TTLEN_PA2_Msk       |\
                                      GPIO_CFG_TTLEN_PA3_Msk       |\
                                      GPIO_CFG_TTLEN_PA4_Msk       |\
                                      GPIO_CFG_TTLEN_PA5_Msk       |\
                                      GPIO_CFG_TTLEN_PA6_Msk       |\
                                      GPIO_CFG_TTLEN_PA7_Msk       |\
                                      GPIO_CFG_TTLEN_PA8_Msk       |\
                                      GPIO_CFG_TTLEN_PA9_Msk       |\
                                      GPIO_CFG_TTLEN_PA10_Msk      |\
                                      GPIO_CFG_TTLEN_PA11_Msk      |\
                                      GPIO_CFG_TTLEN_PA12_Msk      |\
                                      GPIO_CFG_TTLEN_PA13_Msk      |\
                                      GPIO_CFG_TTLEN_PA14_Msk      |\
                                      GPIO_CFG_TTLEN_PA15_Msk      )

#define GPIO_CFG_AFRL_AFR0_Pos       0                                            /*!<GPIO_CFG AFRL: AFR0 Position */
#define GPIO_CFG_AFRL_AFR0_Msk       (0xFUL /*<< GPIO_CFG_AFRL_AFR0_Pos*/)        /*!<GPIO_CFG AFRL: AFR0 Mask */

#define GPIO_CFG_AFRL_AFR1_Pos       4                                            /*!<GPIO_CFG AFRL: AFR1 Position */
#define GPIO_CFG_AFRL_AFR1_Msk       (0xFUL << GPIO_CFG_AFRL_AFR1_Pos)            /*!<GPIO_CFG AFRL: AFR1 Mask */

#define GPIO_CFG_AFRL_AFR2_Pos       8                                            /*!<GPIO_CFG AFRL: AFR2 Position */
#define GPIO_CFG_AFRL_AFR2_Msk       (0xFUL << GPIO_CFG_AFRL_AFR2_Pos)            /*!<GPIO_CFG AFRL: AFR2 Mask */

#define GPIO_CFG_AFRL_AFR3_Pos       12                                           /*!<GPIO_CFG AFRL: AFR3 Position */
#define GPIO_CFG_AFRL_AFR3_Msk       (0xFUL << GPIO_CFG_AFRL_AFR3_Pos)            /*!<GPIO_CFG AFRL: AFR3 Mask */

#define GPIO_CFG_AFRL_AFR4_Pos       16                                           /*!<GPIO_CFG AFRL: AFR4 Position */
#define GPIO_CFG_AFRL_AFR4_Msk       (0xFUL << GPIO_CFG_AFRL_AFR4_Pos)            /*!<GPIO_CFG AFRL: AFR4 Mask */

#define GPIO_CFG_AFRL_AFR5_Pos       20                                           /*!<GPIO_CFG AFRL: AFR5 Position */
#define GPIO_CFG_AFRL_AFR5_Msk       (0xFUL << GPIO_CFG_AFRL_AFR5_Pos)            /*!<GPIO_CFG AFRL: AFR5 Mask */

#define GPIO_CFG_AFRL_AFR6_Pos       24                                           /*!<GPIO_CFG AFRL: AFR6 Position */
#define GPIO_CFG_AFRL_AFR6_Msk       (0xFUL << GPIO_CFG_AFRL_AFR6_Pos)            /*!<GPIO_CFG AFRL: AFR6 Mask */

#define GPIO_CFG_AFRL_AFR7_Pos       28                                           /*!<GPIO_CFG AFRL: AFR7 Position */
#define GPIO_CFG_AFRL_AFR7_Msk       (0xFUL << GPIO_CFG_AFRL_AFR7_Pos)            /*!<GPIO_CFG AFRL: AFR7 Mask */

#define GPIO_CFG_AFRL_Msk_ALL        (GPIO_CFG_AFRL_AFR0_Msk       |\
                                      GPIO_CFG_AFRL_AFR1_Msk       |\
                                      GPIO_CFG_AFRL_AFR2_Msk       |\
                                      GPIO_CFG_AFRL_AFR3_Msk       |\
                                      GPIO_CFG_AFRL_AFR4_Msk       |\
                                      GPIO_CFG_AFRL_AFR5_Msk       |\
                                      GPIO_CFG_AFRL_AFR6_Msk       |\
                                      GPIO_CFG_AFRL_AFR7_Msk       )

#define GPIO_CFG_AFRH_AFR8_Pos       0                                            /*!<GPIO_CFG AFRH: AFR8 Position */
#define GPIO_CFG_AFRH_AFR8_Msk       (0xFUL /*<< GPIO_CFG_AFRH_AFR8_Pos*/)        /*!<GPIO_CFG AFRH: AFR8 Mask */

#define GPIO_CFG_AFRH_AFR9_Pos       4                                            /*!<GPIO_CFG AFRH: AFR9 Position */
#define GPIO_CFG_AFRH_AFR9_Msk       (0xFUL << GPIO_CFG_AFRH_AFR9_Pos)            /*!<GPIO_CFG AFRH: AFR9 Mask */

#define GPIO_CFG_AFRH_AFR10_Pos      8                                            /*!<GPIO_CFG AFRH: AFR10 Position */
#define GPIO_CFG_AFRH_AFR10_Msk      (0xFUL << GPIO_CFG_AFRH_AFR10_Pos)           /*!<GPIO_CFG AFRH: AFR10 Mask */

#define GPIO_CFG_AFRH_AFR11_Pos      12                                           /*!<GPIO_CFG AFRH: AFR11 Position */
#define GPIO_CFG_AFRH_AFR11_Msk      (0xFUL << GPIO_CFG_AFRH_AFR11_Pos)           /*!<GPIO_CFG AFRH: AFR11 Mask */

#define GPIO_CFG_AFRH_AFR12_Pos      16                                           /*!<GPIO_CFG AFRH: AFR12 Position */
#define GPIO_CFG_AFRH_AFR12_Msk      (0xFUL << GPIO_CFG_AFRH_AFR12_Pos)           /*!<GPIO_CFG AFRH: AFR12 Mask */

#define GPIO_CFG_AFRH_AFR13_Pos      20                                           /*!<GPIO_CFG AFRH: AFR13 Position */
#define GPIO_CFG_AFRH_AFR13_Msk      (0xFUL << GPIO_CFG_AFRH_AFR13_Pos)           /*!<GPIO_CFG AFRH: AFR13 Mask */

#define GPIO_CFG_AFRH_AFR14_Pos      24                                           /*!<GPIO_CFG AFRH: AFR14 Position */
#define GPIO_CFG_AFRH_AFR14_Msk      (0xFUL << GPIO_CFG_AFRH_AFR14_Pos)           /*!<GPIO_CFG AFRH: AFR14 Mask */

#define GPIO_CFG_AFRH_AFR15_Pos      28                                           /*!<GPIO_CFG AFRH: AFR15 Position */
#define GPIO_CFG_AFRH_AFR15_Msk      (0xFUL << GPIO_CFG_AFRH_AFR15_Pos)           /*!<GPIO_CFG AFRH: AFR15 Mask */

#define GPIO_CFG_AFRH_Msk_ALL        (GPIO_CFG_AFRH_AFR8_Msk       |\
                                      GPIO_CFG_AFRH_AFR9_Msk       |\
                                      GPIO_CFG_AFRH_AFR10_Msk      |\
                                      GPIO_CFG_AFRH_AFR11_Msk      |\
                                      GPIO_CFG_AFRH_AFR12_Msk      |\
                                      GPIO_CFG_AFRH_AFR13_Msk      |\
                                      GPIO_CFG_AFRH_AFR14_Msk      |\
                                      GPIO_CFG_AFRH_AFR15_Msk      )

#define GPIO_MODER_MODER_Pos         0                                            /*!<GPIO MODER: MODER Position */
#define GPIO_MODER_MODER_Msk         (0xFFFFUL /*<< GPIO_MODER_MODER_Pos*/)       /*!<GPIO MODER: MODER Mask */
#define GPIO_MODER_MODER0_Msk        (0x1UL /*<< GPIO_MODER_MODER_Pos*/)          /*!<GPIO MODER: MODER0 Mask */

#define GPIO_MODER_Msk_ALL           (GPIO_MODER_MODER_Msk        )

#define GPIO_IDR_IDR_Pos             0                                            /*!<GPIO IDR: IDR Position */
#define GPIO_IDR_IDR_Msk             (0xFFFFUL /*<< GPIO_IDR_IDR_Pos*/)           /*!<GPIO IDR: IDR Mask */

#define GPIO_IDR_Msk_ALL             (GPIO_IDR_IDR_Msk            )

#define GPIO_ODR_ODR_Pos             0                                            /*!<GPIO ODR: ODR Position */
#define GPIO_ODR_ODR_Msk             (0xFFFFUL /*<< GPIO_ODR_ODR_Pos*/)           /*!<GPIO ODR: ODR Mask */

#define GPIO_ODR_Msk_ALL             (GPIO_ODR_ODR_Msk            )

#define GPIO_BSRR_BS_Pos             0                                            /*!<GPIO BSRR: BS Position */
#define GPIO_BSRR_BS_Msk             (0xFFFFUL /*<< GPIO_BSRR_BS_Pos*/)           /*!<GPIO BSRR: BS Mask */

#define GPIO_BSRR_BR_Pos             16                                           /*!<GPIO BSRR: BR Position */
#define GPIO_BSRR_BR_Msk             (0xFFFFUL << GPIO_BSRR_BR_Pos)               /*!<GPIO BSRR: BR Mask */

#define GPIO_BSRR_Msk_ALL            (GPIO_BSRR_BS_Msk             |\
                                      GPIO_BSRR_BR_Msk             )


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

#define EXTI_SAMPL_SN0_Pos           0                                            /*!<EXTI SAMPL: SN0 Position */
#define EXTI_SAMPL_SN0_Msk           (0x3UL /*<< EXTI_SAMPL_SN0_Pos*/)            /*!<EXTI SAMPL: SN0 Mask */

#define EXTI_SAMPL_PS0_Pos           2                                            /*!<EXTI SAMPL: PS0 Position */
#define EXTI_SAMPL_PS0_Msk           (0x3UL << EXTI_SAMPL_PS0_Pos)                /*!<EXTI SAMPL: PS0 Mask */

#define EXTI_SAMPL_SN1_Pos           4                                            /*!<EXTI SAMPL: SN1 Position */
#define EXTI_SAMPL_SN1_Msk           (0x3UL << EXTI_SAMPL_SN1_Pos)                /*!<EXTI SAMPL: SN1 Mask */

#define EXTI_SAMPL_PS1_Pos           6                                            /*!<EXTI SAMPL: PS1 Position */
#define EXTI_SAMPL_PS1_Msk           (0x3UL << EXTI_SAMPL_PS1_Pos)                /*!<EXTI SAMPL: PS1 Mask */

#define EXTI_SAMPL_SN2_Pos           8                                            /*!<EXTI SAMPL: SN2 Position */
#define EXTI_SAMPL_SN2_Msk           (0x3UL << EXTI_SAMPL_SN2_Pos)                /*!<EXTI SAMPL: SN2 Mask */

#define EXTI_SAMPL_PS2_Pos           10                                           /*!<EXTI SAMPL: PS2 Position */
#define EXTI_SAMPL_PS2_Msk           (0x3UL << EXTI_SAMPL_PS2_Pos)                /*!<EXTI SAMPL: PS2 Mask */

#define EXTI_SAMPL_SN3_Pos           12                                           /*!<EXTI SAMPL: SN3 Position */
#define EXTI_SAMPL_SN3_Msk           (0x3UL << EXTI_SAMPL_SN3_Pos)                /*!<EXTI SAMPL: SN3 Mask */

#define EXTI_SAMPL_PS3_Pos           14                                           /*!<EXTI SAMPL: PS3 Position */
#define EXTI_SAMPL_PS3_Msk           (0x3UL << EXTI_SAMPL_PS3_Pos)                /*!<EXTI SAMPL: PS3 Mask */

#define EXTI_SAMPL_SN4_Pos           16                                           /*!<EXTI SAMPL: SN4 Position */
#define EXTI_SAMPL_SN4_Msk           (0x3UL << EXTI_SAMPL_SN4_Pos)                /*!<EXTI SAMPL: SN4 Mask */

#define EXTI_SAMPL_PS4_Pos           18                                           /*!<EXTI SAMPL: PS4 Position */
#define EXTI_SAMPL_PS4_Msk           (0x3UL << EXTI_SAMPL_PS4_Pos)                /*!<EXTI SAMPL: PS4 Mask */

#define EXTI_SAMPL_SN5_Pos           20                                           /*!<EXTI SAMPL: SN5 Position */
#define EXTI_SAMPL_SN5_Msk           (0x3UL << EXTI_SAMPL_SN5_Pos)                /*!<EXTI SAMPL: SN5 Mask */

#define EXTI_SAMPL_PS5_Pos           22                                           /*!<EXTI SAMPL: PS5 Position */
#define EXTI_SAMPL_PS5_Msk           (0x3UL << EXTI_SAMPL_PS5_Pos)                /*!<EXTI SAMPL: PS5 Mask */

#define EXTI_SAMPL_SN6_Pos           24                                           /*!<EXTI SAMPL: SN6 Position */
#define EXTI_SAMPL_SN6_Msk           (0x3UL << EXTI_SAMPL_SN6_Pos)                /*!<EXTI SAMPL: SN6 Mask */

#define EXTI_SAMPL_PS6_Pos           26                                           /*!<EXTI SAMPL: PS6 Position */
#define EXTI_SAMPL_PS6_Msk           (0x3UL << EXTI_SAMPL_PS6_Pos)                /*!<EXTI SAMPL: PS6 Mask */

#define EXTI_SAMPL_SN7_Pos           28                                           /*!<EXTI SAMPL: SN7 Position */
#define EXTI_SAMPL_SN7_Msk           (0x3UL << EXTI_SAMPL_SN7_Pos)                /*!<EXTI SAMPL: SN7 Mask */

#define EXTI_SAMPL_PS7_Pos           30                                           /*!<EXTI SAMPL: PS7 Position */
#define EXTI_SAMPL_PS7_Msk           (0x3UL << EXTI_SAMPL_PS7_Pos)                /*!<EXTI SAMPL: PS7 Mask */

#define EXTI_SAMPL_Msk_ALL           (EXTI_SAMPL_SN0_Msk           |\
                                      EXTI_SAMPL_PS0_Msk           |\
                                      EXTI_SAMPL_SN1_Msk           |\
                                      EXTI_SAMPL_PS1_Msk           |\
                                      EXTI_SAMPL_SN2_Msk           |\
                                      EXTI_SAMPL_PS2_Msk           |\
                                      EXTI_SAMPL_SN3_Msk           |\
                                      EXTI_SAMPL_PS3_Msk           |\
                                      EXTI_SAMPL_SN4_Msk           |\
                                      EXTI_SAMPL_PS4_Msk           |\
                                      EXTI_SAMPL_SN5_Msk           |\
                                      EXTI_SAMPL_PS5_Msk           |\
                                      EXTI_SAMPL_SN6_Msk           |\
                                      EXTI_SAMPL_PS6_Msk           |\
                                      EXTI_SAMPL_SN7_Msk           |\
                                      EXTI_SAMPL_PS7_Msk           )

#define EXTI_SAMPH_SN8_Pos           0                                            /*!<EXTI SAMPH: SN8 Position */
#define EXTI_SAMPH_SN8_Msk           (0x3UL /*<< EXTI_SAMPH_SN8_Pos*/)            /*!<EXTI SAMPH: SN8 Mask */

#define EXTI_SAMPH_PS8_Pos           2                                            /*!<EXTI SAMPH: PS8 Position */
#define EXTI_SAMPH_PS8_Msk           (0x3UL << EXTI_SAMPH_PS8_Pos)                /*!<EXTI SAMPH: PS8 Mask */

#define EXTI_SAMPH_SN9_Pos           4                                            /*!<EXTI SAMPH: SN9 Position */
#define EXTI_SAMPH_SN9_Msk           (0x3UL << EXTI_SAMPH_SN9_Pos)                /*!<EXTI SAMPH: SN9 Mask */

#define EXTI_SAMPH_PS9_Pos           6                                            /*!<EXTI SAMPH: PS9 Position */
#define EXTI_SAMPH_PS9_Msk           (0x3UL << EXTI_SAMPH_PS9_Pos)                /*!<EXTI SAMPH: PS9 Mask */

#define EXTI_SAMPH_SN10_Pos          8                                            /*!<EXTI SAMPH: SN10 Position */
#define EXTI_SAMPH_SN10_Msk          (0x3UL << EXTI_SAMPH_SN10_Pos)               /*!<EXTI SAMPH: SN10 Mask */

#define EXTI_SAMPH_PS10_Pos          10                                           /*!<EXTI SAMPH: PS10 Position */
#define EXTI_SAMPH_PS10_Msk          (0x3UL << EXTI_SAMPH_PS10_Pos)               /*!<EXTI SAMPH: PS10 Mask */

#define EXTI_SAMPH_SN11_Pos          12                                           /*!<EXTI SAMPH: SN11 Position */
#define EXTI_SAMPH_SN11_Msk          (0x3UL << EXTI_SAMPH_SN11_Pos)               /*!<EXTI SAMPH: SN11 Mask */

#define EXTI_SAMPH_PS11_Pos          14                                           /*!<EXTI SAMPH: PS11 Position */
#define EXTI_SAMPH_PS11_Msk          (0x3UL << EXTI_SAMPH_PS11_Pos)               /*!<EXTI SAMPH: PS11 Mask */

#define EXTI_SAMPH_SN12_Pos          16                                           /*!<EXTI SAMPH: SN12 Position */
#define EXTI_SAMPH_SN12_Msk          (0x3UL << EXTI_SAMPH_SN12_Pos)               /*!<EXTI SAMPH: SN12 Mask */

#define EXTI_SAMPH_PS12_Pos          18                                           /*!<EXTI SAMPH: PS12 Position */
#define EXTI_SAMPH_PS12_Msk          (0x3UL << EXTI_SAMPH_PS12_Pos)               /*!<EXTI SAMPH: PS12 Mask */

#define EXTI_SAMPH_SN13_Pos          20                                           /*!<EXTI SAMPH: SN13 Position */
#define EXTI_SAMPH_SN13_Msk          (0x3UL << EXTI_SAMPH_SN13_Pos)               /*!<EXTI SAMPH: SN13 Mask */

#define EXTI_SAMPH_PS13_Pos          22                                           /*!<EXTI SAMPH: PS13 Position */
#define EXTI_SAMPH_PS13_Msk          (0x3UL << EXTI_SAMPH_PS13_Pos)               /*!<EXTI SAMPH: PS13 Mask */

#define EXTI_SAMPH_SN14_Pos          24                                           /*!<EXTI SAMPH: SN14 Position */
#define EXTI_SAMPH_SN14_Msk          (0x3UL << EXTI_SAMPH_SN14_Pos)               /*!<EXTI SAMPH: SN14 Mask */

#define EXTI_SAMPH_PS14_Pos          26                                           /*!<EXTI SAMPH: PS14 Position */
#define EXTI_SAMPH_PS14_Msk          (0x3UL << EXTI_SAMPH_PS14_Pos)               /*!<EXTI SAMPH: PS14 Mask */

#define EXTI_SAMPH_SN15_Pos          28                                           /*!<EXTI SAMPH: SN15 Position */
#define EXTI_SAMPH_SN15_Msk          (0x3UL << EXTI_SAMPH_SN15_Pos)               /*!<EXTI SAMPH: SN15 Mask */

#define EXTI_SAMPH_PS15_Pos          30                                           /*!<EXTI SAMPH: PS15 Position */
#define EXTI_SAMPH_PS15_Msk          (0x3UL << EXTI_SAMPH_PS15_Pos)               /*!<EXTI SAMPH: PS15 Mask */

#define EXTI_SAMPH_Msk_ALL           (EXTI_SAMPH_SN8_Msk           |\
                                      EXTI_SAMPH_PS8_Msk           |\
                                      EXTI_SAMPH_SN9_Msk           |\
                                      EXTI_SAMPH_PS9_Msk           |\
                                      EXTI_SAMPH_SN10_Msk          |\
                                      EXTI_SAMPH_PS10_Msk          |\
                                      EXTI_SAMPH_SN11_Msk          |\
                                      EXTI_SAMPH_PS11_Msk          |\
                                      EXTI_SAMPH_SN12_Msk          |\
                                      EXTI_SAMPH_PS12_Msk          |\
                                      EXTI_SAMPH_SN13_Msk          |\
                                      EXTI_SAMPH_PS13_Msk          |\
                                      EXTI_SAMPH_SN14_Msk          |\
                                      EXTI_SAMPH_PS14_Msk          |\
                                      EXTI_SAMPH_SN15_Msk          |\
                                      EXTI_SAMPH_PS15_Msk          )

#define EXTI_DMR_DMR_Pos             0                                            /*!<EXTI DMR: DMR Position */
#define EXTI_DMR_DMR_Msk             (0xFFFFUL /*<< EXTI_DMR_DMR_Pos*/)           /*!<EXTI DMR: DMR Mask */

#define EXTI_DMR_Msk_ALL             (EXTI_DMR_DMR_Msk            )

#define PWM_CR_PWMEN_Pos            0                                            /*!<PWM CR: PWMEN Position */
#define PWM_CR_PWMEN_Msk            (0x1UL /*<< PWM_CR_PWMEN_Pos*/)              /*!<PWM CR: PWMEN Mask */
 
#define PWM_CR_TCK_Pos              1                                            /*!<PWM CR: TCK Position */
#define PWM_CR_TCK_Msk              (0x7UL << PWM_CR_TCK_Pos)                    /*!<PWM CR: TCK Mask */
 
#define PWM_CR_FLTC_Pos             4                                            /*!<PWM CR: FLTC Position */
#define PWM_CR_FLTC_Msk             (0x1UL << PWM_CR_FLTC_Pos)                   /*!<PWM CR: FLTC Mask */
 
#define PWM_CR_EFLT_Pos             5                                            /*!<PWM CR: EFLT Position */
#define PWM_CR_EFLT_Msk             (0x1UL << PWM_CR_EFLT_Pos)                   /*!<PWM CR: EFLT Mask */
 
#define PWM_CR_PWMSB_Pos            6                                            /*!<PWM CR: PWMSB Position */
#define PWM_CR_PWMSB_Msk            (0x1UL << PWM_CR_PWMSB_Pos)                  /*!<PWM CR: PWMSB Mask */
 
#define PWM_CR_PWMSA_Pos            7                                            /*!<PWM CR: PWMSA Position */
#define PWM_CR_PWMSA_Msk            (0x1UL << PWM_CR_PWMSA_Pos)                  /*!<PWM CR: PWMSA Mask */
 
#define PWM_CR_EFLTIE_Pos           8                                            /*!<PWM CR: EFLTIE Position */
#define PWM_CR_EFLTIE_Msk           (0x1UL << PWM_CR_EFLTIE_Pos)                 /*!<PWM CR: EFLTIE Mask */
 
#define PWM_CR_PWMIE_Pos            9                                            /*!<PWM CR: PWMIE Position */
#define PWM_CR_PWMIE_Msk            (0x1UL << PWM_CR_PWMIE_Pos)                  /*!<PWM CR: PWMIE Mask */
 
#define PWM_CR_EPWMB_Pos            10                                           /*!<PWM CR: EPWMB Position */
#define PWM_CR_EPWMB_Msk            (0x1UL << PWM_CR_EPWMB_Pos)                  /*!<PWM CR: EPWMB Mask */
 
#define PWM_CR_EPWMA_Pos            11                                           /*!<PWM CR: EPWMA Position */
#define PWM_CR_EPWMA_Msk            (0x1UL << PWM_CR_EPWMA_Pos)                  /*!<PWM CR: EPWMA Mask */
 
#define PWM_CR_PWMDMA_Pos           12                                           /*!<PWM CR: PWMDMA Position */
#define PWM_CR_PWMDMA_Msk           (0x1UL << PWM_CR_PWMDMA_Pos)                 /*!<PWM CR: PWMDMA Mask */
 
#define PWM_CR_FLTDMA_Pos           13                                           /*!<PWM CR: FLTDMA Position */
#define PWM_CR_FLTDMA_Msk           (0x1UL << PWM_CR_FLTDMA_Pos)                 /*!<PWM CR: FLTDMA Mask */

#define PWM_CR_Msk_ALL              (PWM_CR_PWMEN_Msk            |\
                                      PWM_CR_TCK_Msk              |\
                                      PWM_CR_FLTC_Msk             |\
                                      PWM_CR_EFLT_Msk             |\
                                      PWM_CR_PWMSB_Msk            |\
                                      PWM_CR_PWMSA_Msk            |\
                                      PWM_CR_EFLTIE_Msk           |\
                                      PWM_CR_PWMIE_Msk            |\
                                      PWM_CR_EPWMB_Msk            |\
                                      PWM_CR_EPWMA_Msk            |\
                                      PWM_CR_PWMDMA_Msk           |\
                                      PWM_CR_FLTDMA_Msk           )

#define PWM_PWMLOCK_PWMLO_Pos       0                                           /*!<PWM PWMLOCK: PWMLO Position */
#define PWM_PWMLOCK_PWMLO_Msk       (0xFFFFUL /*<< PWM_PWMLOCK_PWMLO_Pos*/)     /*!<PWM PWMLOCK: PWMLO Mask */

#define PWM_PWMLOCK_Msk_ALL         (PWM_PWMLOCK_PWMLO_Msk      )

#define PWM_PWMPR_PP_Pos            0                                           /*!<PWM PWMPR: PP Position */
#define PWM_PWMPR_PP_Msk            (0xFFFFUL /*<< PWM_PWMPR_PP_Pos*/)          /*!<PWM PWMPR: PP Mask */

#define PWM_PWMPR_Msk_ALL           (PWM_PWMPR_PP_Msk           )

#define PWM_PWMDR_PD_Pos            0                                           /*!<PWM PWMDR: PD Position */
#define PWM_PWMDR_PD_Msk            (0xFFFFUL /*<< PWM_PWMDR_PD_Pos*/)          /*!<PWM PWMDR: PD Mask */

#define PWM_PWMDR_Msk_ALL           (PWM_PWMDR_PD_Msk           )

#define PWM_PWMDTR_DT_Pos           0                                           /*!<PWM PWMDTR: DT Position */
#define PWM_PWMDTR_DT_Msk           (0xFFFFUL /*<< PWM_PWMDTR_DT_Pos*/)         /*!<PWM PWMDTR: DT Mask */

#define PWM_PWMDTR_Msk_ALL          (PWM_PWMDTR_DT_Msk          )

#define PWM_PWMINTF_FLTS_Pos        0                                           /*!<PWM PWMINTF: FLTS Position */
#define PWM_PWMINTF_FLTS_Msk        (0x1UL /*<< PWM_PWMINTF_FLTS_Pos*/)         /*!<PWM PWMINTF: FLTS Mask */

#define PWM_PWMINTF_PWMIF_Pos       1                                           /*!<PWM PWMINTF: PWMIF Position */
#define PWM_PWMINTF_PWMIF_Msk       (0x1UL << PWM_PWMINTF_PWMIF_Pos)            /*!<PWM PWMINTF: PWMIF Mask */

#define PWM_PWMINTF_FLTSC_Pos       2                                           /*!<PWM PWMINTF: FLTSC Position */
#define PWM_PWMINTF_FLTSC_Msk       (0x1UL << PWM_PWMINTF_FLTSC_Pos)            /*!<PWM PWMINTF: FLTSC Mask */

#define PWM_PWMINTF_PWMIFC_Pos      3                                           /*!<PWM PWMINTF: PWMIFC Position */
#define PWM_PWMINTF_PWMIFC_Msk      (0x1UL << PWM_PWMINTF_PWMIFC_Pos)           /*!<PWM PWMINTF: PWMIFC Mask */

#define PWM_PWMINTF_Msk_ALL         (PWM_PWMINTF_FLTS_Msk        |\
                                      PWM_PWMINTF_PWMIF_Msk       |\
                                      PWM_PWMINTF_FLTSC_Msk       |\
                                      PWM_PWMINTF_PWMIFC_Msk      )


#define PCA_CR_PR_Pos               0                                            /*!<PCA CR: PR Position */
#define PCA_CR_PR_Msk               (0x1UL /*<< PCA_CR_PR_Pos*/)                 /*!<PCA CR: PR Mask */

#define PCA_CR_CASCEN_Pos           1                                            /*!<PCA CR: CASCEN Position */
#define PCA_CR_CASCEN_Msk           (0x1UL << PCA_CR_CASCEN_Pos)                 /*!<PCA CR: CASCEN Mask */

#define PCA_CR_Msk_ALL              (PCA_CR_PR_Msk               |\
                                     PCA_CR_CASCEN_Msk           )

#define PCA_CMD_CPS_Pos             0                                            /*!<PCA CMD: CPS Position */
#define PCA_CMD_CPS_Msk             (0x7UL /*<< PCA_CMD_CPS_Pos*/)               /*!<PCA CMD: CPS Mask */

#define PCA_CMD_SDEN_Pos            3                                            /*!<PCA CMD: SDEN Position */
#define PCA_CMD_SDEN_Msk            (0x1UL << PCA_CMD_SDEN_Pos)                  /*!<PCA CMD: SDEN Mask */

#define PCA_CMD_ECF_Pos             4                                            /*!<PCA CMD: ECF Position */
#define PCA_CMD_ECF_Msk             (0x1UL << PCA_CMD_ECF_Pos)                   /*!<PCA CMD: ECF Mask */

#define PCA_CMD_CF0DMA_Pos          5                                            /*!<PCA CMD: CF0DMA Position */
#define PCA_CMD_CF0DMA_Msk          (0x1UL << PCA_CMD_CF0DMA_Pos)                /*!<PCA CMD: CF0DMA Mask */

#define PCA_CMD_CF1DMA_Pos          6                                            /*!<PCA CMD: CF1DMA Position */
#define PCA_CMD_CF1DMA_Msk          (0x1UL << PCA_CMD_CF1DMA_Pos)                /*!<PCA CMD: CF1DMA Mask */

#define PCA_CMD_CFDMA_Pos           7                                            /*!<PCA CMD: CFDMA Position */
#define PCA_CMD_CFDMA_Msk           (0x1UL << PCA_CMD_CFDMA_Pos)                 /*!<PCA CMD: CFDMA Mask */

#define PCA_CMD_Msk_ALL             (PCA_CMD_CPS_Msk             |\
                                      PCA_CMD_SDEN_Msk            |\
                                      PCA_CMD_ECF_Msk             |\
                                      PCA_CMD_CF0DMA_Msk          |\
                                      PCA_CMD_CF1DMA_Msk          |\
                                      PCA_CMD_CFDMA_Msk           )

#define PCA_CPM0_ECCF0_Pos          0                                            /*!<PCA CPM0: ECCF0 Position */
#define PCA_CPM0_ECCF0_Msk          (0x1UL /*<< PCA_CPM0_ECCF0_Pos*/)            /*!<PCA CPM0: ECCF0 Mask */

#define PCA_CPM0_MAT0_Pos           1                                            /*!<PCA CPM0: MAT0 Position */
#define PCA_CPM0_MAT0_Msk           (0x1UL << PCA_CPM0_MAT0_Pos)                 /*!<PCA CPM0: MAT0 Mask */

#define PCA_CPM0_TCP0_Pos           2                                            /*!<PCA CPM0: TCP0 Position */
#define PCA_CPM0_TCP0_Msk           (0x1UL << PCA_CPM0_TCP0_Pos)                 /*!<PCA CPM0: TCP0 Mask */

#define PCA_CPM0_ECOM0_Pos          3                                            /*!<PCA CPM0: ECOM0 Position */
#define PCA_CPM0_ECOM0_Msk          (0x1UL << PCA_CPM0_ECOM0_Pos)                /*!<PCA CPM0: ECOM0 Mask */

#define PCA_CPM0_FS0_Pos            4                                            /*!<PCA CPM0: FS0 Position */
#define PCA_CPM0_FS0_Msk            (0x3UL << PCA_CPM0_FS0_Pos)                  /*!<PCA CPM0: FS0 Mask */

#define PCA_CPM0_SM0_Pos            6                                            /*!<PCA CPM0: SM0 Position */
#define PCA_CPM0_SM0_Msk            (0x3UL << PCA_CPM0_SM0_Pos)                  /*!<PCA CPM0: SM0 Mask */

#define PCA_CPM0_Msk_ALL            (PCA_CPM0_ECCF0_Msk          |\
                                      PCA_CPM0_MAT0_Msk           |\
                                      PCA_CPM0_TCP0_Msk           |\
                                      PCA_CPM0_ECOM0_Msk          |\
                                      PCA_CPM0_FS0_Msk            |\
                                      PCA_CPM0_SM0_Msk            )

#define PCA_CPM1_ECCF1_Pos          0                                            /*!<PCA CPM1: ECCF1 Position */
#define PCA_CPM1_ECCF1_Msk          (0x1UL /*<< PCA_CPM1_ECCF1_Pos*/)            /*!<PCA CPM1: ECCF1 Mask */

#define PCA_CPM1_MAT1_Pos           1                                            /*!<PCA CPM1: MAT1 Position */
#define PCA_CPM1_MAT1_Msk           (0x1UL << PCA_CPM1_MAT1_Pos)                 /*!<PCA CPM1: MAT1 Mask */

#define PCA_CPM1_TCP1_Pos           2                                            /*!<PCA CPM1: TCP1 Position */
#define PCA_CPM1_TCP1_Msk           (0x1UL << PCA_CPM1_TCP1_Pos)                 /*!<PCA CPM1: TCP1 Mask */

#define PCA_CPM1_ECOM1_Pos          3                                            /*!<PCA CPM1: ECOM1 Position */
#define PCA_CPM1_ECOM1_Msk          (0x1UL << PCA_CPM1_ECOM1_Pos)                /*!<PCA CPM1: ECOM1 Mask */

#define PCA_CPM1_FS1_Pos            4                                            /*!<PCA CPM1: FS1 Position */
#define PCA_CPM1_FS1_Msk            (0x3UL << PCA_CPM1_FS1_Pos)                  /*!<PCA CPM1: FS1 Mask */

#define PCA_CPM1_SM1_Pos            6                                            /*!<PCA CPM1: SM1 Position */
#define PCA_CPM1_SM1_Msk            (0x3UL << PCA_CPM1_SM1_Pos)                  /*!<PCA CPM1: SM1 Mask */

#define PCA_CPM1_Msk_ALL            (PCA_CPM1_ECCF1_Msk          |\
                                     PCA_CPM1_MAT1_Msk           |\
                                     PCA_CPM1_TCP1_Msk           |\
                                     PCA_CPM1_ECOM1_Msk          |\
                                     PCA_CPM1_FS1_Msk            |\
                                     PCA_CPM1_SM1_Msk            )

#define PCA_FORCE_FCO0_Pos          0                                            /*!<PCA FORCE: FCO0 Position */
#define PCA_FORCE_FCO0_Msk          (0x1UL /*<< PCA_FORCE_FCO0_Pos*/)            /*!<PCA FORCE: FCO0 Mask */

#define PCA_FORCE_FCO1_Pos          1                                            /*!<PCA FORCE: FCO1 Position */
#define PCA_FORCE_FCO1_Msk          (0x1UL << PCA_FORCE_FCO1_Pos)                /*!<PCA FORCE: FCO1 Mask */

#define PCA_FORCE_OSC0_Pos          2                                            /*!<PCA FORCE: OSC0 Position */
#define PCA_FORCE_OSC0_Msk          (0x1UL << PCA_FORCE_OSC0_Pos)                /*!<PCA FORCE: OSC0 Mask */

#define PCA_FORCE_OSC1_Pos          3                                            /*!<PCA FORCE: OSC1 Position */
#define PCA_FORCE_OSC1_Msk          (0x1UL << PCA_FORCE_OSC1_Pos)                /*!<PCA FORCE: OSC1 Mask */

#define PCA_FORCE_Msk_ALL           (PCA_FORCE_FCO0_Msk          |\
                                      PCA_FORCE_FCO1_Msk          |\
                                      PCA_FORCE_OSC0_Msk          |\
                                      PCA_FORCE_OSC1_Msk          )

#define PCA_TOPR_TOPL_Pos           0                                            /*!<PCA TOPR: TOPL Position */
#define PCA_TOPR_TOPL_Msk           (0xFFUL /*<< PCA2_TOPR_TOPL_Pos*/)           /*!<PCA TOPR: TOPL Mask */

#define PCA_TOPR_TOPH_Pos           8                                            /*!<PCA TOPR: TOPH Position */
#define PCA_TOPR_TOPH_Msk           (0xFFUL << PCA2_TOPR_TOPH_Pos)               /*!<PCA TOPR: TOPH Mask */

#define PCA_TOPR_TOPCAS_Pos         16                                           /*!<PCA TOPR: TOPCAS Position */
#define PCA_TOPR_TOPCAS_Msk         (0xFFFFUL << PCA2_TOPR_TOPCAS_Pos)           /*!<PCA TOPR: TOPCAS Mask */

#define PCA_TOPR_Msk_ALL            (PCA2_TOPR_TOPL_Msk           |\
                                      PCA2_TOPR_TOPH_Msk           |\
                                      PCA2_TOPR_TOPCAS_Msk         )

#define PCA_CPR0_CPL0_Pos           0                                            /*!<PCA CPR0: CPL0 Position */
#define PCA_CPR0_CPL0_Msk           (0xFFUL /*<< PCA_CPR0_CPL0_Pos*/)            /*!<PCA CPR0: CPL0 Mask */

#define PCA_CPR0_CPH0_Pos           8                                            /*!<PCA CPR0: CPH0 Position */
#define PCA_CPR0_CPH0_Msk           (0xFFUL << PCA_CPR0_CPH0_Pos)                /*!<PCA CPR0: CPH0 Mask */

#define PCA_CPR0_CP0CAS_Pos         16                                           /*!<PCA CPR0: CP0CAS Position */
#define PCA_CPR0_CP0CAS_Msk         (0xFFFFUL << PCA_CPR0_CP0CAS_Pos)            /*!<PCA CPR0: CP0CAS Mask */

#define PCA_CPR0_Msk_ALL            (PCA_CPR0_CPL0_Msk           |\
                                      PCA_CPR0_CPH0_Msk           |\
                                      PCA_CPR0_CP0CAS_Msk         )

#define PCA_CPR1_CPL1_Pos           0                                            /*!<PCA CPR1: CPL1 Position */
#define PCA_CPR1_CPL1_Msk           (0xFFUL /*<< PCA_CPR1_CPL1_Pos*/)            /*!<PCA CPR1: CPL1 Mask */

#define PCA_CPR1_CPH1_Pos           8                                            /*!<PCA CPR1: CPH1 Position */
#define PCA_CPR1_CPH1_Msk           (0xFFUL << PCA_CPR1_CPH1_Pos)                /*!<PCA CPR1: CPH1 Mask */

#define PCA_CPR1_CP1CAS_Pos         16                                           /*!<PCA CPR1: CP1CAS Position */
#define PCA_CPR1_CP1CAS_Msk         (0xFFFFUL << PCA_CPR1_CP1CAS_Pos)            /*!<PCA CPR1: CP1CAS Mask */

#define PCA_CPR1_Msk_ALL            (PCA_CPR1_CPL1_Msk           |\
                                      PCA_CPR1_CPH1_Msk           |\
                                      PCA_CPR1_CP1CAS_Msk         )

#define PCA_PCAINTF_CCF0_Pos        0                                            /*!<PCA PCAINTF: CCF0 Position */
#define PCA_PCAINTF_CCF0_Msk        (0x1UL /*<< PCA_PCAINTF_CCF0_Pos*/)          /*!<PCA PCAINTF: CCF0 Mask */

#define PCA_PCAINTF_CCF1_Pos        1                                            /*!<PCA PCAINTF: CCF1 Position */
#define PCA_PCAINTF_CCF1_Msk        (0x1UL << PCA_PCAINTF_CCF1_Pos)              /*!<PCA PCAINTF: CCF1 Mask */

#define PCA_PCAINTF_CF_Pos          2                                            /*!<PCA PCAINTF: CF Position */
#define PCA_PCAINTF_CF_Msk          (0x1UL << PCA_PCAINTF_CF_Pos)                /*!<PCA PCAINTF: CF Mask */

#define PCA_PCAINTF_CCF0C_Pos       3                                            /*!<PCA PCAINTF: CCF0C Position */
#define PCA_PCAINTF_CCF0C_Msk       (0x1UL << PCA_PCAINTF_CCF0C_Pos)             /*!<PCA PCAINTF: CCF0C Mask */

#define PCA_PCAINTF_CCF1C_Pos       4                                            /*!<PCA PCAINTF: CCF1C Position */
#define PCA_PCAINTF_CCF1C_Msk       (0x1UL << PCA_PCAINTF_CCF1C_Pos)             /*!<PCA PCAINTF: CCF1C Mask */

#define PCA_PCAINTF_CFC_Pos         5                                            /*!<PCA PCAINTF: CFC Position */
#define PCA_PCAINTF_CFC_Msk         (0x1UL << PCA_PCAINTF_CFC_Pos)               /*!<PCA PCAINTF: CFC Mask */

#define PCA_PCAINTF_Msk_ALL         (PCA_PCAINTF_CCF0_Msk        |\
                                      PCA_PCAINTF_CCF1_Msk        |\
                                      PCA_PCAINTF_CF_Msk          |\
                                      PCA_PCAINTF_CCF0C_Msk       |\
                                      PCA_PCAINTF_CCF1C_Msk       |\
                                      PCA_PCAINTF_CFC_Msk         )


#define TIM_CR_STR_Pos              0                                            /*!<TIM CR: STR Position */
#define TIM_CR_STR_Msk              (0x1UL /*<< TIM_CR_STR_Pos*/)                /*!<TIM CR: STR Mask */
#define TIM_CR_OPM_Pos              3                                            /*!<TIM CR: OPM Position */
#define TIM_CR_OPM_Msk              (0x1UL << TIM_CR_OPM_Pos)                    /*!<TIM CR: OPM Mask */
#define TIM_CR_CLKS_Pos             4                                            /*!<TIM CR: CLKS Position */
#define TIM_CR_CLKS_Msk             (0x3UL << TIM_CR_CLKS_Pos)                   /*!<TIM CR: CLKS Mask */
#define TIM_CR_IE_Pos               6                                            /*!<TIM CR: IE Position */
#define TIM_CR_IE_Msk               (0x1UL << TIM_CR_IE_Pos)                     /*!<TIM CR: IE Mask */
#define TIM_CR_TRIGEN_Pos           8                                            /*!<TIM CR: TRIGEN Position */
#define TIM_CR_TRIGEN_Msk           (0x1UL << TIM_CR_TRIGEN_Pos)                 /*!<TIM CR: TRIGEN Mask */
#define TIM_CR_ETEN_Pos             9                                            /*!<TIM CR: ETEN Position */
#define TIM_CR_ETEN_Msk             (0x1UL << TIM_CR_ETEN_Pos)                   /*!<TIM CR: ETEN Mask */
#define TIM_CR_TC_Pos               10                                           /*!<TIM CR: TC Position */
#define TIM_CR_TC_Msk               (0x1UL << TIM_CR_TC_Pos)                     /*!<TIM CR: TC Mask */
#define TIM_CR_CASCEN_Pos           15                                           /*!<TIM CR: CASCEN Position */
#define TIM_CR_CASCEN_Msk           (0x1UL << TIM_CR_CASCEN_Pos)                 /*!<TIM CR: CASCEN Mask */

#define TIM_CR_Msk_ALL              (TIM_CR_STR_Msk              |\
                                      TIM_CR_OPM_Msk              |\
                                      TIM_CR_CLKS_Msk             |\
                                      TIM_CR_IE_Msk               |\
                                      TIM_CR_TRIGEN_Msk           |\
                                      TIM_CR_ETEN_Msk             |\
                                      TIM_CR_TC_Msk               |\
                                      TIM_CR_CASCEN_Msk           )

#define TIM_TCNT_TCNTL_Pos          0                                            /*!<TIM TCNT: TCNTL Position */
#define TIM_TCNT_TCNTL_Msk          (0xFFFFUL /*<< TIM_TCNT_TCNTL_Pos*/)         /*!<TIM TCNT: TCNTL Mask */

#define TIM_TCNT_TCNTH_Pos          16                                           /*!<TIM TCNT: TCNTH Position */
#define TIM_TCNT_TCNTH_Msk          (0xFFFFUL << TIM_TCNT_TCNTH_Pos)             /*!<TIM TCNT: TCNTH Mask */

#define TIM_TCNT_Msk_ALL            (TIM_TCNT_TCNTL_Msk          |\
                                      TIM_TCNT_TCNTH_Msk          )

#define TIM_TPR_TPRL_Pos            0                                            /*!<TIM TPR: TPRL Position */
#define TIM_TPR_TPRL_Msk            (0xFFFFUL /*<< TIM_TPR_TPRL_Pos*/)           /*!<TIM TPR: TPRL Mask */

#define TIM_TPR_TPRH_Pos            16                                           /*!<TIM TPR: TPRH Position */
#define TIM_TPR_TPRH_Msk            (0xFFFFUL << TIM_TPR_TPRH_Pos)               /*!<TIM TPR: TPRH Mask */

#define TIM_TPR_Msk_ALL             (TIM_TPR_TPRL_Msk            |\
                                      TIM_TPR_TPRH_Msk            )

#define TIM_PSQ_PSQL_Pos            0                                            /*!<TIM PSQ: PSQL Position */
#define TIM_PSQ_PSQL_Msk            (0xFFFFUL /*<< TIM_PSQ_PSQL_Pos*/)           /*!<TIM PSQ: PSQL Mask */

#define TIM_PSQ_PSQH_Pos            16                                           /*!<TIM PSQ: PSQH Position */
#define TIM_PSQ_PSQH_Msk            (0xFFFFUL << TIM_PSQ_PSQH_Pos)               /*!<TIM PSQ: PSQH Mask */

#define TIM_PSQ_Msk_ALL             (TIM_PSQ_PSQL_Msk            |\
                                      TIM_PSQ_PSQH_Msk            )

#define TIM_TIMINTF_TF_Pos          0                                            /*!<TIM TIMINTF: TF Position */
#define TIM_TIMINTF_TF_Msk          (0x1UL /*<< TIM_TIMINTF_TF_Pos*/)            /*!<TIM TIMINTF: TF Mask */

#define TIM_TIMINTF_TFC_Pos         16                                           /*!<TIM TIMINTF: TFC Position */
#define TIM_TIMINTF_TFC_Msk         (0x1UL << TIM_TIMINTF_TFC_Pos)               /*!<TIM TIMINTF: TFC Mask */

#define TIM_TIMINTF_Msk_ALL         (TIM_TIMINTF_TF_Msk          |\
                                      TIM_TIMINTF_TFC_Msk         )


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

#define ADC_ADCON1_ADSTRS_Pos        9                                            /*!<ADC ADCON1: ADSTRS Position */
#define ADC_ADCON1_ADSTRS_Msk        (0x3FUL << ADC_ADCON1_ADSTRS_Pos)            /*!<ADC ADCON1: ADSTRS Mask */

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

#define TPS_AVREFCON_VREFEN_Pos      0                                            /*!<TPS AVREFCON: VREFEN Position */
#define TPS_AVREFCON_VREFEN_Msk      (0x1UL /*<< TPS_AVREFCON_VREFEN_Pos*/)       /*!<TPS AVREFCON: VREFEN Mask */

#define TPS_AVREFCON_VREFSEL_Pos     1                                            /*!<TPS AVREFCON: VREFSEL Position */
#define TPS_AVREFCON_VREFSEL_Msk     (0x1UL << TPS_AVREFCON_VREFSEL_Pos)          /*!<TPS AVREFCON: VREFSEL Mask */

#define TPS_AVREFCON_CHOPS_Pos       2                                            /*!<TPS AVREFCON: CHOPS Position */
#define TPS_AVREFCON_CHOPS_Msk       (0x1UL << TPS_AVREFCON_CHOPS_Pos)            /*!<TPS AVREFCON: CHOPS Mask */

#define TPS_AVREFCON_CHOPEN_Pos      3                                            /*!<TPS AVREFCON: CHOPEN Position */
#define TPS_AVREFCON_CHOPEN_Msk      (0x1UL << TPS_AVREFCON_CHOPEN_Pos)           /*!<TPS AVREFCON: CHOPEN Mask */

#define TPS_AVREFCON_Msk_ALL         (TPS_AVREFCON_VREFEN_Msk      |\
                                      TPS_AVREFCON_VREFSEL_Msk     |\
                                      TPS_AVREFCON_CHOPS_Msk       |\
                                      TPS_AVREFCON_CHOPEN_Msk      )

#define TPS_TPSCON_TPSEN_Pos         0                                            /*!<TPS TPSCON: TPSEN Position */
#define TPS_TPSCON_TPSEN_Msk         (0x1UL /*<< TPS_TPSCON_TPSEN_Pos*/)          /*!<TPS TPSCON: TPSEN Mask */

#define TPS_TPSCON_TPSCHOP_Pos       1                                            /*!<TPS TPSCON: TPSCHOP Position */
#define TPS_TPSCON_TPSCHOP_Msk       (0x1UL << TPS_TPSCON_TPSCHOP_Pos)            /*!<TPS TPSCON: TPSCHOP Mask */

#define TPS_TPSCON_Msk_ALL           (TPS_TPSCON_TPSEN_Msk         |\
                                      TPS_TPSCON_TPSCHOP_Msk       )

#define UART_FR_RI_Pos              0                                            /*!<UART FR: RI Position */
#define UART_FR_RI_Msk              (0x1UL /*<< UART_FR_RI_Pos*/)                /*!<UART FR: RI Mask */

#define UART_FR_TI_Pos              1                                            /*!<UART FR: TI Position */
#define UART_FR_TI_Msk              (0x1UL << UART_FR_TI_Pos)                    /*!<UART FR: TI Mask */

#define UART_FR_TC_Pos              2                                            /*!<UART FR: TC Position */
#define UART_FR_TC_Msk              (0x1UL << UART_FR_TC_Pos)                    /*!<UART FR: TC Mask */

#define UART_FR_TXCOL_Pos           3                                            /*!<UART FR: TXCOL Position */
#define UART_FR_TXCOL_Msk           (0x1UL << UART_FR_TXCOL_Pos)                 /*!<UART FR: TXCOL Mask */

#define UART_FR_RXOV_Pos            4                                            /*!<UART FR: RXOV Position */
#define UART_FR_RXOV_Msk            (0x1UL << UART_FR_RXOV_Pos)                  /*!<UART FR: RXOV Mask */

#define UART_FR_FE_Pos              5                                            /*!<UART FR: FE Position */
#define UART_FR_FE_Msk              (0x1UL << UART_FR_FE_Pos)                    /*!<UART FR: FE Mask */

#define UART_FR_PE_Pos              6                                            /*!<UART FR: PE Position */
#define UART_FR_PE_Msk              (0x1UL << UART_FR_PE_Pos)                    /*!<UART FR: PE Mask */

#define UART_FR_LBD_Pos             7                                            /*!<UART FR: LBD Position */
#define UART_FR_LBD_Msk             (0x1UL << UART_FR_LBD_Pos)                   /*!<UART FR: LBD Mask */

#define UART_FR_RIC_Pos             16                                           /*!<UART FR: RIC Position */
#define UART_FR_RIC_Msk             (0x1UL << UART_FR_RIC_Pos)                   /*!<UART FR: RIC Mask */

#define UART_FR_TCC_Pos             18                                           /*!<UART FR: TCC Position */
#define UART_FR_TCC_Msk             (0x1UL << UART_FR_TCC_Pos)                   /*!<UART FR: TCC Mask */

#define UART_FR_TXCOLC_Pos          19                                           /*!<UART FR: TXCOLC Position */
#define UART_FR_TXCOLC_Msk          (0x1UL << UART_FR_TXCOLC_Pos)                /*!<UART FR: TXCOLC Mask */

#define UART_FR_RXOVC_Pos           20                                           /*!<UART FR: RXOVC Position */
#define UART_FR_RXOVC_Msk           (0x1UL << UART_FR_RXOVC_Pos)                 /*!<UART FR: RXOVC Mask */

#define UART_FR_FEC_Pos             21                                           /*!<UART FR: FEC Position */
#define UART_FR_FEC_Msk             (0x1UL << UART_FR_FEC_Pos)                   /*!<UART FR: FEC Mask */

#define UART_FR_PEC_Pos             22                                           /*!<UART FR: PEC Position */
#define UART_FR_PEC_Msk             (0x1UL << UART_FR_PEC_Pos)                   /*!<UART FR: PEC Mask */

#define UART_FR_LBDC_Pos            23                                           /*!<UART FR: LBDC Position */
#define UART_FR_LBDC_Msk            (0x1UL << UART_FR_LBDC_Pos)                  /*!<UART FR: LBDC Mask */

#define UART_FR_Msk_ALL             (UART_FR_RI_Msk              |\
                                      UART_FR_TI_Msk              |\
                                      UART_FR_TC_Msk              |\
                                      UART_FR_TXCOL_Msk           |\
                                      UART_FR_RXOV_Msk            |\
                                      UART_FR_FE_Msk              |\
                                      UART_FR_PE_Msk              |\
                                      UART_FR_LBD_Msk             |\
                                      UART_FR_RIC_Msk             |\
                                      UART_FR_TCC_Msk             |\
                                      UART_FR_TXCOLC_Msk          |\
                                      UART_FR_RXOVC_Msk           |\
                                      UART_FR_FEC_Msk             |\
                                      UART_FR_PEC_Msk             |\
                                      UART_FR_LBDC_Msk            )

#define UART_TDR_TDR_Pos            0                                           /*!<UART TDR: TDR Position */
#define UART_TDR_TDR_Msk            (0xFFUL /*<< UART_TDR_TDR_Pos*/)            /*!<UART TDR: TDR Mask */

#define UART_TDR_Msk_ALL            (UART_TDR_TDR_Msk           )

#define UART_RDR_RDR_Pos            0                                           /*!<UART RDR: RDR Position */
#define UART_RDR_RDR_Msk            (0xFFUL /*<< UART_RDR_RDR_Pos*/)            /*!<UART RDR: RDR Mask */

#define UART_RDR_Msk_ALL            (UART_RDR_RDR_Msk           )

#define UART_ADDR_SADDR_Pos         0                                           /*!<UART ADDR: SADDR Position */
#define UART_ADDR_SADDR_Msk         (0xFFUL /*<< UART_ADDR_SADDR_Pos*/)         /*!<UART ADDR: SADDR Mask */

#define UART_ADDR_SMAR_Pos          8                                           /*!<UART ADDR: SMAR Position */
#define UART_ADDR_SMAR_Msk          (0xFFUL << UART_ADDR_SMAR_Pos)              /*!<UART ADDR: SMAR Mask */

#define UART_ADDR_Msk_ALL           (UART_ADDR_SADDR_Msk         |\
                                     UART_ADDR_SMAR_Msk          )

#define UART_BRT_SBRT_Pos           0                                           /*!<UART BRT: SBRT Position */
#define UART_BRT_SBRT_Msk           (0x7FFFUL /*<< UART_BRT_SBRT_Pos*/)         /*!<UART BRT: SBRT Mask */

#define UART_BRT_BFINE_Pos          16                                          /*!<UART BRT: BFINE Position */
#define UART_BRT_BFINE_Msk          (0xFUL << UART_BRT_BFINE_Pos)               /*!<UART BRT: BFINE Mask */
#define UART_BRT_Msk_ALL            (UART_BRT_SBRT_Msk           |\
                                      UART_BRT_BFINE_Msk          )

#define UART_CR_STOP_Pos            0                                           /*!<UART CR: STOP Position */
#define UART_CR_STOP_Msk            (0x1UL /*<< UART_CR_STOP_Pos*/)             /*!<UART CR: STOP Mask */

#define UART_CR_SBRTEN_Pos          1                                           /*!<UART CR: SBRTEN Position */
#define UART_CR_SBRTEN_Msk          (0x1UL << UART_CR_SBRTEN_Pos)               /*!<UART CR: SBRTEN Mask */

#define UART_CR_SMOD_Pos            2                                           /*!<UART CR: SMOD Position */
#define UART_CR_SMOD_Msk            (0x1UL << UART_CR_SMOD_Pos)                 /*!<UART CR: SMOD Mask */

#define UART_CR_RIE_Pos             3                                           /*!<UART CR: RIE Position */
#define UART_CR_RIE_Msk             (0x1UL << UART_CR_RIE_Pos)                  /*!<UART CR: RIE Mask */

#define UART_CR_TIE_Pos             4                                           /*!<UART CR: TIE Position */
#define UART_CR_TIE_Msk             (0x1UL << UART_CR_TIE_Pos)                  /*!<UART CR: TIE Mask */

#define UART_CR_TCIE_Pos            5                                           /*!<UART CR: TCIE Position */
#define UART_CR_TCIE_Msk            (0x1UL << UART_CR_TCIE_Pos)                 /*!<UART CR: TCIE Mask */

#define UART_CR_LBDIE_Pos           6                                           /*!<UART CR: LBDIE Position */
#define UART_CR_LBDIE_Msk           (0x1UL << UART_CR_LBDIE_Pos)                /*!<UART CR: LBDIE Mask */

#define UART_CR_LBDL_Pos            7                                           /*!<UART CR: LBDL Position */
#define UART_CR_LBDL_Msk            (0x1UL << UART_CR_LBDL_Pos)                 /*!<UART CR: LBDL Mask */

#define UART_CR_RB8_Pos             8                                           /*!<UART CR: RB8 Position */
#define UART_CR_RB8_Msk             (0x1UL << UART_CR_RB8_Pos)                  /*!<UART CR: RB8 Mask */

#define UART_CR_TB8_Pos             9                                           /*!<UART CR: TB8 Position */
#define UART_CR_TB8_Msk             (0x1UL << UART_CR_TB8_Pos)                  /*!<UART CR: TB8 Mask */

#define UART_CR_PS_Pos              10                                          /*!<UART CR: PS Position */
#define UART_CR_PS_Msk              (0x1UL << UART_CR_PS_Pos)                   /*!<UART CR: PS Mask */

#define UART_CR_PCE_Pos             11                                          /*!<UART CR: PCE Position */
#define UART_CR_PCE_Msk             (0x1UL << UART_CR_PCE_Pos)                  /*!<UART CR: PCE Mask */

#define UART_CR_SM2_Pos             12                                          /*!<UART CR: SM2 Position */
#define UART_CR_SM2_Msk             (0x1UL << UART_CR_SM2_Pos)                  /*!<UART CR: SM2 Mask */

#define UART_CR_SM_Pos              13                                          /*!<UART CR: SM Position */
#define UART_CR_SM_Msk              (0x3UL << UART_CR_SM_Pos)                   /*!<UART CR: SM Mask */

#define UART_CR_SBK_Pos             15                                          /*!<UART CR: SBK Position */
#define UART_CR_SBK_Msk             (0x1UL << UART_CR_SBK_Pos)                  /*!<UART CR: SBK Mask */

#define UART_CR_LINEN_Pos           16                                          /*!<UART CR: LINEN Position */
#define UART_CR_LINEN_Msk           (0x1UL << UART_CR_LINEN_Pos)                /*!<UART CR: LINEN Mask */

#define UART_CR_REN_Pos             17                                          /*!<UART CR: REN Position */
#define UART_CR_REN_Msk             (0x1UL << UART_CR_REN_Pos)                  /*!<UART CR: REN Mask */

#define UART_CR_TEN_Pos             18                                          /*!<UART CR: TEN Position */
#define UART_CR_TEN_Msk             (0x1UL << UART_CR_TEN_Pos)                  /*!<UART CR: TEN Mask */

#define UART_CR_DMAR_Pos            19                                          /*!<UART CR: DMAR Position */
#define UART_CR_DMAR_Msk            (0x1UL << UART_CR_DMAR_Pos)                 /*!<UART CR: DMAR Mask */

#define UART_CR_DMAT_Pos            20                                          /*!<UART CR: DMAT Position */
#define UART_CR_DMAT_Msk            (0x1UL << UART_CR_DMAT_Pos)                 /*!<UART CR: DMAT Mask */

#define UART_CR_Msk_ALL             (UART_CR_STOP_Msk            |\
                                      UART_CR_SBRTEN_Msk          |\
                                      UART_CR_SMOD_Msk            |\
                                      UART_CR_RIE_Msk             |\
                                      UART_CR_TIE_Msk             |\
                                      UART_CR_TCIE_Msk            |\
                                      UART_CR_LBDIE_Msk           |\
                                      UART_CR_LBDL_Msk            |\
                                      UART_CR_RB8_Msk             |\
                                      UART_CR_TB8_Msk             |\
                                      UART_CR_PS_Msk              |\
                                      UART_CR_PCE_Msk             |\
                                      UART_CR_SM2_Msk             |\
                                      UART_CR_SM_Msk              |\
                                      UART_CR_SBK_Msk             |\
                                      UART_CR_LINEN_Msk           |\
                                      UART_CR_REN_Msk             |\
                                      UART_CR_TEN_Msk             |\
                                      UART_CR_DMAR_Msk            |\
                                      UART_CR_DMAT_Msk            )


#define SPI_FR_SPRI_Pos             0                                           /*!<SPI FR: SPRI Position */
#define SPI_FR_SPRI_Msk             (0x1UL /*<< SPI0_FR_SPRI_Pos*/)             /*!<SPI FR: SPRI Mask */

#define SPI_FR_SPTI_Pos             1                                           /*!<SPI FR: SPTI Position */
#define SPI_FR_SPTI_Msk             (0x1UL << SPI_FR_SPTI_Pos)                  /*!<SPI FR: SPTI Mask */

#define SPI_FR_BUSY_Pos             2                                           /*!<SPI FR: BUSY Position */
#define SPI_FR_BUSY_Msk             (0x1UL << SPI_FR_BUSY_Pos)                  /*!<SPI FR: BUSY Mask */

#define SPI_FR_MODF_Pos             3                                           /*!<SPI FR: MODF Position */
#define SPI_FR_MODF_Msk             (0x1UL << SPI_FR_MODF_Pos)                  /*!<SPI FR: MODF Mask */

#define SPI_FR_RXOV_Pos             4                                           /*!<SPI FR: RXOV Position */
#define SPI_FR_RXOV_Msk             (0x1UL << SPI_FR_RXOV_Pos)                  /*!<SPI FR: RXOV Mask */

#define SPI_FR_WCOL_Pos             5                                           /*!<SPI FR: WCOL Position */
#define SPI_FR_WCOL_Msk             (0x1UL << SPI_FR_WCOL_Pos)                  /*!<SPI FR: WCOL Mask */

#define SPI_FR_SPRIC_Pos            16                                          /*!<SPI FR: SPRIC Position */
#define SPI_FR_SPRIC_Msk            (0x1UL << SPI_FR_SPRIC_Pos)                 /*!<SPI FR: SPRIC Mask */

#define SPI_FR_SPTIC_Pos            17                                          /*!<SPI FR: SPTIC Position */
#define SPI_FR_SPTIC_Msk            (0x1UL << SPI_FR_SPTIC_Pos)                 /*!<SPI FR: SPTIC Mask */

#define SPI_FR_MODFC_Pos            19                                          /*!<SPI FR: MODFC Position */
#define SPI_FR_MODFC_Msk            (0x1UL << SPI_FR_MODFC_Pos)                 /*!<SPI FR: MODFC Mask */

#define SPI_FR_RXOVC_Pos            20                                          /*!<SPI FR: RXOVC Position */
#define SPI_FR_RXOVC_Msk            (0x1UL << SPI_FR_RXOVC_Pos)                 /*!<SPI FR: RXOVC Mask */

#define SPI_FR_WCOLC_Pos            21                                          /*!<SPI FR: WCOLC Position */
#define SPI_FR_WCOLC_Msk            (0x1UL << SPI_FR_WCOLC_Pos)                 /*!<SPI FR: WCOLC Mask */

#define SPI_FR_Msk_ALL              (SPI_FR_SPRI_Msk             |\
                                      SPI_FR_SPTI_Msk             |\
                                      SPI_FR_BUSY_Msk             |\
                                      SPI_FR_MODF_Msk             |\
                                      SPI_FR_RXOV_Msk             |\
                                      SPI_FR_WCOL_Msk             |\
                                      SPI_FR_SPRIC_Msk            |\
                                      SPI_FR_SPTIC_Msk            |\
                                      SPI_FR_MODFC_Msk            |\
                                      SPI_FR_RXOVC_Msk            |\
                                      SPI_FR_WCOLC_Msk            )

#define SPI_CR_SPR_Pos              0                                           /*!<SPI CR: SPR Position */
#define SPI_CR_SPR_Msk              (0xFUL /*<< SPI_CR_SPR_Pos*/)               /*!<SPI CR: SPR Mask */

#define SPI_CR_SSDIS_Pos            4                                           /*!<SPI CR: SSDIS Position */
#define SPI_CR_SSDIS_Msk            (0x1UL << SPI_CR_SSDIS_Pos)                 /*!<SPI CR: SSDIS Mask */

#define SPI_CR_CPOL_Pos             5                                           /*!<SPI CR: CPOL Position */
#define SPI_CR_CPOL_Msk             (0x1UL << SPI_CR_CPOL_Pos)                  /*!<SPI CR: CPOL Mask */

#define SPI_CR_CPHA_Pos             6                                           /*!<SPI CR: CPHA Position */
#define SPI_CR_CPHA_Msk             (0x1UL << SPI_CR_CPHA_Pos)                  /*!<SPI CR: CPHA Mask */

#define SPI_CR_MSTR_Pos             7                                           /*!<SPI CR: MSTR Position */
#define SPI_CR_MSTR_Msk             (0x1UL << SPI_CR_MSTR_Pos)                  /*!<SPI CR: MSTR Mask */

#define SPI_CR_DIR_Pos              8                                           /*!<SPI CR: DIR Position */
#define SPI_CR_DIR_Msk              (0x1UL << SPI_CR_DIR_Pos)                   /*!<SPI CR: DIR Mask */

#define SPI_CR_SPDATL_Pos           9                                           /*!<SPI CR: SPDATL Position */
#define SPI_CR_SPDATL_Msk           (0x1UL << SPI_CR_SPDATL_Pos)                /*!<SPI CR: SPDATL Mask */

#define SPI_CR_SPRIE_Pos            10                                          /*!<SPI CR: SPRIE Position */
#define SPI_CR_SPRIE_Msk            (0x1UL << SPI_CR_SPRIE_Pos)                 /*!<SPI CR: SPRIE Mask */

#define SPI_CR_SPTIE_Pos            11                                          /*!<SPI CR: SPTIE Position */
#define SPI_CR_SPTIE_Msk            (0x1UL << SPI_CR_SPTIE_Pos)                 /*!<SPI CR: SPTIE Mask */

#define SPI_CR_SPDMAR_Pos           12                                          /*!<SPI CR: SPDMAR Position */
#define SPI_CR_SPDMAR_Msk           (0x1UL << SPI_CR_SPDMAR_Pos)                /*!<SPI CR: SPDMAR Mask */

#define SPI_CR_SPDMAT_Pos           13                                          /*!<SPI0 CR: SPDMAT Position */
#define SPI_CR_SPDMAT_Msk           (0x1UL << SPI_CR_SPDMAT_Pos)                /*!<SPI0 CR: SPDMAT Mask */

#define SPI_CR_SPIEN_Pos            14                                          /*!<SPI CR: SPIEN Position */
#define SPI_CR_SPIEN_Msk            (0x1UL << SPI_CR_SPIEN_Pos)                 /*!<SPI CR: SPIEN Mask */

#define SPI_CR_SPSFF_Pos            15                                          /*!<SPI CR: SPSFF Position */
#define SPI_CR_SPSFF_Msk            (0x1UL << SPI_CR_SPSFF_Pos)                 /*!<SPI CR: SPSFF Mask */

#define SPI_CR_SPDATW_Pos           16                                          /*!<SPI CR: SPDATW Position */
#define SPI_CR_SPDATW_Msk           (0x1UL << SPI_CR_SPDATW_Pos)                /*!<SPI CR: SPDATW Mask */

#define SPI_CR_Msk_ALL              (SPI_CR_SPR_Msk              |\
                                      SPI_CR_SSDIS_Msk            |\
                                      SPI_CR_CPOL_Msk             |\
                                      SPI_CR_CPHA_Msk             |\
                                      SPI_CR_MSTR_Msk             |\
                                      SPI_CR_DIR_Msk              |\
                                      SPI_CR_SPDATL_Msk           |\
                                      SPI_CR_SPRIE_Msk            |\
                                      SPI_CR_SPTIE_Msk            |\
                                      SPI_CR_SPDMAR_Msk           |\
                                      SPI_CR_SPDMAT_Msk           |\
                                      SPI_CR_SPIEN_Msk            |\
                                      SPI_CR_SPSFF_Msk            |\
                                      SPI_CR_SPDATW_Msk           )

#define TWI_FR_TWINT_Pos            0                                            /*!<TWI FR: TWINT Position */
#define TWI_FR_TWINT_Msk            (0x1UL /*<< TWI_FR_TWINT_Pos*/)              /*!<TWI FR: TWINT Mask */

#define TWI_FR_TFREE_Pos            2                                            /*!<TWI FR: TFREE Position */
#define TWI_FR_TFREE_Msk            (0x1UL << TWI_FR_TFREE_Pos)                  /*!<TWI FR: TFREE Mask */

#define TWI_FR_TOUT_Pos             3                                            /*!<TWI FR: TOUT Position */
#define TWI_FR_TOUT_Msk             (0x1UL << TWI_FR_TOUT_Pos)                   /*!<TWI FR: TOUT Mask */

#define TWI_FR_TWINTC_Pos           16                                           /*!<TWI FR: TWINTC Position */
#define TWI_FR_TWINTC_Msk           (0x1UL << TWI_FR_TWINTC_Pos)                 /*!<TWI FR: TWINTC Mask */

#define TWI_FR_TFREEC_Pos           18                                           /*!<TWI FR: TFREEC Position */
#define TWI_FR_TFREEC_Msk           (0x1UL << TWI_FR_TFREEC_Pos)                 /*!<TWI FR: TFREEC Mask */

#define TWI_FR_TOUTC_Pos            19                                           /*!<TWI FR: TOUTC Position */
#define TWI_FR_TOUTC_Msk            (0x1UL << TWI_FR_TOUTC_Pos)                  /*!<TWI FR: TOUTC Mask */

#define TWI_FR_Msk_ALL              (TWI_FR_TWINT_Msk            |\
                                      TWI_FR_TFREE_Msk            |\
                                      TWI_FR_TOUT_Msk             |\
                                      TWI_FR_TWINTC_Msk           |\
                                      TWI_FR_TFREEC_Msk           |\
                                      TWI_FR_TOUTC_Msk            )

#define TWI_STAT_SR_Pos             3                                            /*!<TWI STAT: SR Position */
#define TWI_STAT_SR_Msk             (0x1FUL << TWI_STAT_SR_Pos)                  /*!<TWI STAT: SR Mask */

#define TWI_STAT_Msk_ALL            (TWI_STAT_SR_Msk            )

#define TWI_HOC_HOC_Pos             0                                            /*!<TWI HOC: HOC Position */
#define TWI_HOC_HOC_Msk             (0xFFUL /*<< TWI_HOC_HOC_Pos*/)              /*!<TWI HOC: HOC Mask */

#define TWI_HOC_Msk_ALL             (TWI_HOC_HOC_Msk            )

#define TWI_BRT_BRT_Pos             0                                            /*!<TWI BRT: BRT Position */
#define TWI_BRT_BRT_Msk             (0xFFUL /*<< TWI_BRT_BRT_Pos*/)              /*!<TWI BRT: BRT Mask */

#define TWI_BRT_Msk_ALL             (TWI_BRT_BRT_Msk            )

#define TWI_DR_DR_Pos               0                                            /*!<TWI DR: DR Position */
#define TWI_DR_DR_Msk               (0xFFUL /*<< TWI_DR_DR_Pos*/)                /*!<TWI DR: DR Mask */

#define TWI_DR_Msk_ALL              (TWI_DR_DR_Msk              )

#define TWI_ADDR_GC_Pos             0                                            /*!<TWI ADDR: GC Position */
#define TWI_ADDR_GC_Msk             (0x1UL /*<< TWI_ADDR_GC_Pos*/)               /*!<TWI ADDR: GC Mask */

#define TWI_ADDR_ADDR_Pos           1                                            /*!<TWI ADDR: ADDR Position */
#define TWI_ADDR_ADDR_Msk           (0x7FUL << TWI_ADDR_ADDR_Pos)                /*!<TWI ADDR: ADDR Mask */

#define TWI_ADDR_TWIAMR_Pos         17                                           /*!<TWI ADDR: TWIAMR Position */
#define TWI_ADDR_TWIAMR_Msk         (0x7FUL << TWI_ADDR_TWIAMR_Pos)              /*!<TWI ADDR: TWIAMR Mask */

#define TWI_ADDR_Msk_ALL            (TWI_ADDR_GC_Msk             |\
                                      TWI_ADDR_ADDR_Msk           |\
                                      TWI_ADDR_TWIAMR_Msk         )

#define TWI_CR_AA_Pos               0                                            /*!<TWI CR: AA Position */
#define TWI_CR_AA_Msk               (0x1UL /*<< TWI_CR_AA_Pos*/)                 /*!<TWI CR: AA Mask */

#define TWI_CR_STO_Pos              1                                            /*!<TWI CR: STO Position */
#define TWI_CR_STO_Msk              (0x1UL << TWI_CR_STO_Pos)                    /*!<TWI CR: STO Mask */

#define TWI_CR_STA_Pos              2                                            /*!<TWI CR: STA Position */
#define TWI_CR_STA_Msk              (0x1UL << TWI_CR_STA_Pos)                    /*!<TWI CR: STA Mask */

#define TWI_CR_CR_Pos               4                                            /*!<TWI CR: CR Position */
#define TWI_CR_CR_Msk               (0x3UL << TWI_CR_CR_Pos)                     /*!<TWI CR: CR Mask */

#define TWI_CR_CNT_Pos              6                                            /*!<TWI CR: CNT Position */
#define TWI_CR_CNT_Msk              (0x3UL << TWI_CR_CNT_Pos)                    /*!<TWI CR: CNT Mask */

#define TWI_CR_EFREE_Pos            8                                            /*!<TWI CR: EFREE Position */
#define TWI_CR_EFREE_Msk            (0x1UL << TWI_CR_EFREE_Pos)                  /*!<TWI CR: EFREE Mask */

#define TWI_CR_ETOT_Pos             9                                            /*!<TWI CR: ETOT Position */
#define TWI_CR_ETOT_Msk             (0x1UL << TWI_CR_ETOT_Pos)                   /*!<TWI CR: ETOT Mask */

#define TWI_CR_TWINTE_Pos           10                                           /*!<TWI CR: TWINTE Position */
#define TWI_CR_TWINTE_Msk           (0x1UL << TWI_CR_TWINTE_Pos)                 /*!<TWI CR: TWINTE Mask */

#define TWI_CR_TWIEN_Pos            15                                           /*!<TWI CR: TWIEN Position */
#define TWI_CR_TWIEN_Msk            (0x1UL << TWI_CR_TWIEN_Pos)                  /*!<TWI CR: TWIEN Mask */

#define TWI_CR_Msk_ALL              (TWI_CR_AA_Msk               |\
                                      TWI_CR_STO_Msk              |\
                                      TWI_CR_STA_Msk              |\
                                      TWI_CR_CR_Msk               |\
                                      TWI_CR_CNT_Msk              |\
                                      TWI_CR_EFREE_Msk            |\
                                      TWI_CR_ETOT_Msk             |\
                                      TWI_CR_TWINTE_Msk           |\
                                      TWI_CR_TWIEN_Msk            )


#define LCD_CR_EN_Pos                0                                            /*!<LCD CR: EN Position */
#define LCD_CR_EN_Msk                (0x1UL /*<< LCD_CR_EN_Pos*/)                 /*!<LCD CR: EN Mask */

#define LCD_CR_LCLK_Pos              1                                            /*!<LCD CR: LCLK Position */
#define LCD_CR_LCLK_Msk              (0x1UL << LCD_CR_LCLK_Pos)                   /*!<LCD CR: LCLK Mask */

#define LCD_CR_DUTY_Pos              2                                            /*!<LCD CR: DUTY Position */
#define LCD_CR_DUTY_Msk              (0x7UL << LCD_CR_DUTY_Pos)                   /*!<LCD CR: DUTY Mask */

#define LCD_CR_VOL_Pos               5                                            /*!<LCD CR: VOL Position */
#define LCD_CR_VOL_Msk               (0xFUL << LCD_CR_VOL_Pos)                    /*!<LCD CR: VOL Mask */

#define LCD_CR_ELCC_Pos              9                                            /*!<LCD CR: ELCC Position */
#define LCD_CR_ELCC_Msk              (0x1UL << LCD_CR_ELCC_Pos)                   /*!<LCD CR: ELCC Mask */

#define LCD_CR_MODSW_Pos             10                                           /*!<LCD CR: MODSW Position */
#define LCD_CR_MODSW_Msk             (0x1UL << LCD_CR_MODSW_Pos)                  /*!<LCD CR: MODSW Mask */

#define LCD_CR_RLCD_Pos              11                                           /*!<LCD CR: RLCD Position */
#define LCD_CR_RLCD_Msk              (0x1UL << LCD_CR_RLCD_Pos)                   /*!<LCD CR: RLCD Mask */

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
                                      LCD_CR_RLCD_Msk              |\
                                      LCD_CR_MOD_Msk               |\
                                      LCD_CR_FCCTL_Msk             |\
                                      LCD_CR_CNTMOD_Msk            |\
                                      LCD_CR_DCK_Msk               )

#define LCD_LCDSHARE_LCDCOM_Pos      0                                            /*!<LCD LCDSHARE: LCDCOM Position */
#define LCD_LCDSHARE_LCDCOM_Msk      (0xFFUL /*<< LCD_LCDSHARE_LCDCOM_Pos*/)      /*!<LCD LCDSHARE: LCDCOM Mask */

#define LCD_LCDSHARE_LCDSEG1_Pos     8                                            /*!<LCD LCDSHARE: LCDSEG1 Position */
#define LCD_LCDSHARE_LCDSEG1_Msk     (0xFFUL << LCD_LCDSHARE_LCDSEG1_Pos)         /*!<LCD LCDSHARE: LCDSEG1 Mask */

#define LCD_LCDSHARE_LCDSEG2_Pos     16                                           /*!<LCD LCDSHARE: LCDSEG2 Position */
#define LCD_LCDSHARE_LCDSEG2_Msk     (0xFFUL << LCD_LCDSHARE_LCDSEG2_Pos)         /*!<LCD LCDSHARE: LCDSEG2 Mask */

#define LCD_LCDSHARE_LCDSEG3_Pos     24                                           /*!<LCD LCDSHARE: LCDSEG3 Position */
#define LCD_LCDSHARE_LCDSEG3_Msk     (0xFFUL << LCD_LCDSHARE_LCDSEG3_Pos)         /*!<LCD LCDSHARE: LCDSEG3 Mask */

#define LCD_LCDSHARE_Msk_ALL         (LCD_LCDSHARE_LCDCOM_Msk      |\
                                      LCD_LCDSHARE_LCDSEG1_Msk     |\
                                      LCD_LCDSHARE_LCDSEG2_Msk     |\
                                      LCD_LCDSHARE_LCDSEG3_Msk     )

#define LCD_LCDSHARE1_LCDSEG4_Pos    0                                            /*!<LCD LCDSHARE1: LCDSEG4 Position */
#define LCD_LCDSHARE1_LCDSEG4_Msk    (0xFFUL /*<< LCD_LCDSHARE1_LCDSEG4_Pos*/)    /*!<LCD LCDSHARE1: LCDSEG4 Mask */

#define LCD_LCDSHARE1_LCDSEG5_Pos    8                                            /*!<LCD LCDSHARE1: LCDSEG5 Position */
#define LCD_LCDSHARE1_LCDSEG5_Msk    (0xFUL << LCD_LCDSHARE1_LCDSEG5_Pos)         /*!<LCD LCDSHARE1: LCDSEG5 Mask */

#define LCD_LCDSHARE1_Msk_ALL        (LCD_LCDSHARE1_LCDSEG4_Msk    |\
                                      LCD_LCDSHARE1_LCDSEG5_Msk    )

#define LCD_LCD_BUFS0_LCDBUF0_Pos    0                                            /*!<LCD LCD_BUFS0: LCDBUF0 Position */
#define LCD_LCD_BUFS0_LCDBUF0_Msk    (0xFFUL /*<< LCD_LCD_BUFS0_LCDBUF0_Pos*/)    /*!<LCD LCD_BUFS0: LCDBUF0 Mask */

#define LCD_LCD_BUFS0_LCDBUF1_Pos    8                                            /*!<LCD LCD_BUFS0: LCDBUF1 Position */
#define LCD_LCD_BUFS0_LCDBUF1_Msk    (0xFFUL << LCD_LCD_BUFS0_LCDBUF1_Pos)        /*!<LCD LCD_BUFS0: LCDBUF1 Mask */

#define LCD_LCD_BUFS0_LCDBUF2_Pos    16                                           /*!<LCD LCD_BUFS0: LCDBUF2 Position */
#define LCD_LCD_BUFS0_LCDBUF2_Msk    (0xFFUL << LCD_LCD_BUFS0_LCDBUF2_Pos)        /*!<LCD LCD_BUFS0: LCDBUF2 Mask */

#define LCD_LCD_BUFS0_LCDBUF3_Pos    24                                           /*!<LCD LCD_BUFS0: LCDBUF3 Position */
#define LCD_LCD_BUFS0_LCDBUF3_Msk    (0xFFUL << LCD_LCD_BUFS0_LCDBUF3_Pos)        /*!<LCD LCD_BUFS0: LCDBUF3 Mask */

#define LCD_LCD_BUFS0_Msk_ALL        (LCD_LCD_BUFS0_LCDBUF0_Msk    |\
                                      LCD_LCD_BUFS0_LCDBUF1_Msk    |\
                                      LCD_LCD_BUFS0_LCDBUF2_Msk    |\
                                      LCD_LCD_BUFS0_LCDBUF3_Msk    )

#define LCD_LCD_BUFS1_LCDBUF4_Pos    0                                            /*!<LCD LCD_BUFS1: LCDBUF4 Position */
#define LCD_LCD_BUFS1_LCDBUF4_Msk    (0xFFUL /*<< LCD_LCD_BUFS1_LCDBUF4_Pos*/)    /*!<LCD LCD_BUFS1: LCDBUF4 Mask */

#define LCD_LCD_BUFS1_LCDBUF5_Pos    8                                            /*!<LCD LCD_BUFS1: LCDBUF5 Position */
#define LCD_LCD_BUFS1_LCDBUF5_Msk    (0xFFUL << LCD_LCD_BUFS1_LCDBUF5_Pos)        /*!<LCD LCD_BUFS1: LCDBUF5 Mask */

#define LCD_LCD_BUFS1_LCDBUF6_Pos    16                                           /*!<LCD LCD_BUFS1: LCDBUF6 Position */
#define LCD_LCD_BUFS1_LCDBUF6_Msk    (0xFFUL << LCD_LCD_BUFS1_LCDBUF6_Pos)        /*!<LCD LCD_BUFS1: LCDBUF6 Mask */

#define LCD_LCD_BUFS1_LCDBUF7_Pos    24                                           /*!<LCD LCD_BUFS1: LCDBUF7 Position */
#define LCD_LCD_BUFS1_LCDBUF7_Msk    (0xFFUL << LCD_LCD_BUFS1_LCDBUF7_Pos)        /*!<LCD LCD_BUFS1: LCDBUF7 Mask */

#define LCD_LCD_BUFS1_Msk_ALL        (LCD_LCD_BUFS1_LCDBUF4_Msk    |\
                                      LCD_LCD_BUFS1_LCDBUF5_Msk    |\
                                      LCD_LCD_BUFS1_LCDBUF6_Msk    |\
                                      LCD_LCD_BUFS1_LCDBUF7_Msk    )

#define LCD_LCD_BUFS2_LCDBUF8_Pos    0                                            /*!<LCD LCD_BUFS2: LCDBUF8 Position */
#define LCD_LCD_BUFS2_LCDBUF8_Msk    (0xFFUL /*<< LCD_LCD_BUFS2_LCDBUF8_Pos*/)    /*!<LCD LCD_BUFS2: LCDBUF8 Mask */

#define LCD_LCD_BUFS2_LCDBUF9_Pos    8                                            /*!<LCD LCD_BUFS2: LCDBUF9 Position */
#define LCD_LCD_BUFS2_LCDBUF9_Msk    (0xFFUL << LCD_LCD_BUFS2_LCDBUF9_Pos)        /*!<LCD LCD_BUFS2: LCDBUF9 Mask */

#define LCD_LCD_BUFS2_LCDBUF10_Pos   16                                           /*!<LCD LCD_BUFS2: LCDBUF10 Position */
#define LCD_LCD_BUFS2_LCDBUF10_Msk   (0xFFUL << LCD_LCD_BUFS2_LCDBUF10_Pos)       /*!<LCD LCD_BUFS2: LCDBUF10 Mask */

#define LCD_LCD_BUFS2_LCDBUF11_Pos   24                                           /*!<LCD LCD_BUFS2: LCDBUF11 Position */
#define LCD_LCD_BUFS2_LCDBUF11_Msk   (0xFFUL << LCD_LCD_BUFS2_LCDBUF11_Pos)       /*!<LCD LCD_BUFS2: LCDBUF11 Mask */

#define LCD_LCD_BUFS2_Msk_ALL        (LCD_LCD_BUFS2_LCDBUF8_Msk    |\
                                      LCD_LCD_BUFS2_LCDBUF9_Msk    |\
                                      LCD_LCD_BUFS2_LCDBUF10_Msk   |\
                                      LCD_LCD_BUFS2_LCDBUF11_Msk   )

#define LCD_LCD_BUFS3_LCDBUF12_Pos   0                                            /*!<LCD LCD_BUFS3: LCDBUF12 Position */
#define LCD_LCD_BUFS3_LCDBUF12_Msk   (0xFFUL /*<< LCD_LCD_BUFS3_LCDBUF12_Pos*/)   /*!<LCD LCD_BUFS3: LCDBUF12 Mask */

#define LCD_LCD_BUFS3_LCDBUF13_Pos   8                                            /*!<LCD LCD_BUFS3: LCDBUF13 Position */
#define LCD_LCD_BUFS3_LCDBUF13_Msk   (0xFFUL << LCD_LCD_BUFS3_LCDBUF13_Pos)       /*!<LCD LCD_BUFS3: LCDBUF13 Mask */

#define LCD_LCD_BUFS3_LCDBUF14_Pos   16                                           /*!<LCD LCD_BUFS3: LCDBUF14 Position */
#define LCD_LCD_BUFS3_LCDBUF14_Msk   (0xFFUL << LCD_LCD_BUFS3_LCDBUF14_Pos)       /*!<LCD LCD_BUFS3: LCDBUF14 Mask */

#define LCD_LCD_BUFS3_LCDBUF15_Pos   24                                           /*!<LCD LCD_BUFS3: LCDBUF15 Position */
#define LCD_LCD_BUFS3_LCDBUF15_Msk   (0xFFUL << LCD_LCD_BUFS3_LCDBUF15_Pos)       /*!<LCD LCD_BUFS3: LCDBUF15 Mask */

#define LCD_LCD_BUFS3_Msk_ALL        (LCD_LCD_BUFS3_LCDBUF12_Msk   |\
                                      LCD_LCD_BUFS3_LCDBUF13_Msk   |\
                                      LCD_LCD_BUFS3_LCDBUF14_Msk   |\
                                      LCD_LCD_BUFS3_LCDBUF15_Msk   )

#define LCD_LCD_BUFS4_LCDBUF16_Pos   0                                            /*!<LCD LCD_BUFS4: LCDBUF16 Position */
#define LCD_LCD_BUFS4_LCDBUF16_Msk   (0xFFUL /*<< LCD_LCD_BUFS4_LCDBUF16_Pos*/)   /*!<LCD LCD_BUFS4: LCDBUF16 Mask */

#define LCD_LCD_BUFS4_LCDBUF17_Pos   8                                            /*!<LCD LCD_BUFS4: LCDBUF17 Position */
#define LCD_LCD_BUFS4_LCDBUF17_Msk   (0xFFUL << LCD_LCD_BUFS4_LCDBUF17_Pos)       /*!<LCD LCD_BUFS4: LCDBUF17 Mask */

#define LCD_LCD_BUFS4_LCDBUF18_Pos   16                                           /*!<LCD LCD_BUFS4: LCDBUF18 Position */
#define LCD_LCD_BUFS4_LCDBUF18_Msk   (0xFFUL << LCD_LCD_BUFS4_LCDBUF18_Pos)       /*!<LCD LCD_BUFS4: LCDBUF18 Mask */

#define LCD_LCD_BUFS4_LCDBUF19_Pos   24                                           /*!<LCD LCD_BUFS4: LCDBUF19 Position */
#define LCD_LCD_BUFS4_LCDBUF19_Msk   (0xFFUL << LCD_LCD_BUFS4_LCDBUF19_Pos)       /*!<LCD LCD_BUFS4: LCDBUF19 Mask */

#define LCD_LCD_BUFS4_Msk_ALL        (LCD_LCD_BUFS4_LCDBUF16_Msk   |\
                                      LCD_LCD_BUFS4_LCDBUF17_Msk   |\
                                      LCD_LCD_BUFS4_LCDBUF18_Msk   |\
                                      LCD_LCD_BUFS4_LCDBUF19_Msk   )

#define LCD_LCD_BUFS5_LCDBUF20_Pos   0                                            /*!<LCD LCD_BUFS5: LCDBUF20 Position */
#define LCD_LCD_BUFS5_LCDBUF20_Msk   (0xFFUL /*<< LCD_LCD_BUFS5_LCDBUF20_Pos*/)   /*!<LCD LCD_BUFS5: LCDBUF20 Mask */

#define LCD_LCD_BUFS5_LCDBUF21_Pos   8                                            /*!<LCD LCD_BUFS5: LCDBUF21 Position */
#define LCD_LCD_BUFS5_LCDBUF21_Msk   (0xFFUL << LCD_LCD_BUFS5_LCDBUF21_Pos)       /*!<LCD LCD_BUFS5: LCDBUF21 Mask */

#define LCD_LCD_BUFS5_LCDBUF22_Pos   16                                           /*!<LCD LCD_BUFS5: LCDBUF22 Position */
#define LCD_LCD_BUFS5_LCDBUF22_Msk   (0xFFUL << LCD_LCD_BUFS5_LCDBUF22_Pos)       /*!<LCD LCD_BUFS5: LCDBUF22 Mask */

#define LCD_LCD_BUFS5_LCDBUF23_Pos   24                                           /*!<LCD LCD_BUFS5: LCDBUF23 Position */
#define LCD_LCD_BUFS5_LCDBUF23_Msk   (0xFFUL << LCD_LCD_BUFS5_LCDBUF23_Pos)       /*!<LCD LCD_BUFS5: LCDBUF23 Mask */

#define LCD_LCD_BUFS5_Msk_ALL        (LCD_LCD_BUFS5_LCDBUF20_Msk   |\
                                      LCD_LCD_BUFS5_LCDBUF21_Msk   |\
                                      LCD_LCD_BUFS5_LCDBUF22_Msk   |\
                                      LCD_LCD_BUFS5_LCDBUF23_Msk   )

#define LCD_LCD_BUFS6_LCDBUF24_Pos   0                                            /*!<LCD LCD_BUFS6: LCDBUF24 Position */
#define LCD_LCD_BUFS6_LCDBUF24_Msk   (0xFFUL /*<< LCD_LCD_BUFS6_LCDBUF24_Pos*/)   /*!<LCD LCD_BUFS6: LCDBUF24 Mask */

#define LCD_LCD_BUFS6_LCDBUF25_Pos   8                                            /*!<LCD LCD_BUFS6: LCDBUF25 Position */
#define LCD_LCD_BUFS6_LCDBUF25_Msk   (0xFFUL << LCD_LCD_BUFS6_LCDBUF25_Pos)       /*!<LCD LCD_BUFS6: LCDBUF25 Mask */

#define LCD_LCD_BUFS6_LCDBUF26_Pos   16                                           /*!<LCD LCD_BUFS6: LCDBUF26 Position */
#define LCD_LCD_BUFS6_LCDBUF26_Msk   (0xFFUL << LCD_LCD_BUFS6_LCDBUF26_Pos)       /*!<LCD LCD_BUFS6: LCDBUF26 Mask */

#define LCD_LCD_BUFS6_LCDBUF27_Pos   24                                           /*!<LCD LCD_BUFS6: LCDBUF27 Position */
#define LCD_LCD_BUFS6_LCDBUF27_Msk   (0xFFUL << LCD_LCD_BUFS6_LCDBUF27_Pos)       /*!<LCD LCD_BUFS6: LCDBUF27 Mask */

#define LCD_LCD_BUFS6_Msk_ALL        (LCD_LCD_BUFS6_LCDBUF24_Msk   |\
                                      LCD_LCD_BUFS6_LCDBUF25_Msk   |\
                                      LCD_LCD_BUFS6_LCDBUF26_Msk   |\
                                      LCD_LCD_BUFS6_LCDBUF27_Msk   )

#define LCD_LCD_BUFS7_LCDBUF28_Pos   0                                            /*!<LCD LCD_BUFS7: LCDBUF28 Position */
#define LCD_LCD_BUFS7_LCDBUF28_Msk   (0xFFUL /*<< LCD_LCD_BUFS7_LCDBUF28_Pos*/)   /*!<LCD LCD_BUFS7: LCDBUF28 Mask */

#define LCD_LCD_BUFS7_LCDBUF29_Pos   8                                            /*!<LCD LCD_BUFS7: LCDBUF29 Position */
#define LCD_LCD_BUFS7_LCDBUF29_Msk   (0xFFUL << LCD_LCD_BUFS7_LCDBUF29_Pos)       /*!<LCD LCD_BUFS7: LCDBUF29 Mask */

#define LCD_LCD_BUFS7_LCDBUF30_Pos   16                                           /*!<LCD LCD_BUFS7: LCDBUF30 Position */
#define LCD_LCD_BUFS7_LCDBUF30_Msk   (0xFFUL << LCD_LCD_BUFS7_LCDBUF30_Pos)       /*!<LCD LCD_BUFS7: LCDBUF30 Mask */

#define LCD_LCD_BUFS7_LCDBUF31_Pos   24                                           /*!<LCD LCD_BUFS7: LCDBUF31 Position */
#define LCD_LCD_BUFS7_LCDBUF31_Msk   (0xFFUL << LCD_LCD_BUFS7_LCDBUF31_Pos)       /*!<LCD LCD_BUFS7: LCDBUF31 Mask */

#define LCD_LCD_BUFS7_Msk_ALL        (LCD_LCD_BUFS7_LCDBUF28_Msk   |\
                                      LCD_LCD_BUFS7_LCDBUF29_Msk   |\
                                      LCD_LCD_BUFS7_LCDBUF30_Msk   |\
                                      LCD_LCD_BUFS7_LCDBUF31_Msk   )

#define LCD_LCD_BUFS8_LCDBUF32_Pos   0                                            /*!<LCD LCD_BUFS8: LCDBUF32 Position */
#define LCD_LCD_BUFS8_LCDBUF32_Msk   (0xFFUL /*<< LCD_LCD_BUFS8_LCDBUF32_Pos*/)   /*!<LCD LCD_BUFS8: LCDBUF32 Mask */

#define LCD_LCD_BUFS8_LCDBUF33_Pos   8                                            /*!<LCD LCD_BUFS8: LCDBUF33 Position */
#define LCD_LCD_BUFS8_LCDBUF33_Msk   (0xFFUL << LCD_LCD_BUFS8_LCDBUF33_Pos)       /*!<LCD LCD_BUFS8: LCDBUF33 Mask */

#define LCD_LCD_BUFS8_LCDBUF34_Pos   16                                           /*!<LCD LCD_BUFS8: LCDBUF34 Position */
#define LCD_LCD_BUFS8_LCDBUF34_Msk   (0xFFUL << LCD_LCD_BUFS8_LCDBUF34_Pos)       /*!<LCD LCD_BUFS8: LCDBUF34 Mask */

#define LCD_LCD_BUFS8_LCDBUF35_Pos   24                                           /*!<LCD LCD_BUFS8: LCDBUF35 Position */
#define LCD_LCD_BUFS8_LCDBUF35_Msk   (0xFFUL << LCD_LCD_BUFS8_LCDBUF35_Pos)       /*!<LCD LCD_BUFS8: LCDBUF35 Mask */

#define LCD_LCD_BUFS8_Msk_ALL        (LCD_LCD_BUFS8_LCDBUF32_Msk   |\
                                      LCD_LCD_BUFS8_LCDBUF33_Msk   |\
                                      LCD_LCD_BUFS8_LCDBUF34_Msk   |\
                                      LCD_LCD_BUFS8_LCDBUF35_Msk   )

#define LCD_LCD_BUFS9_LCDBUF36_Pos   0                                            /*!<LCD LCD_BUFS9: LCDBUF36 Position */
#define LCD_LCD_BUFS9_LCDBUF36_Msk   (0xFFUL /*<< LCD_LCD_BUFS9_LCDBUF36_Pos*/)   /*!<LCD LCD_BUFS9: LCDBUF36 Mask */

#define LCD_LCD_BUFS9_LCDBUF37_Pos   8                                            /*!<LCD LCD_BUFS9: LCDBUF37 Position */
#define LCD_LCD_BUFS9_LCDBUF37_Msk   (0xFFUL << LCD_LCD_BUFS9_LCDBUF37_Pos)       /*!<LCD LCD_BUFS9: LCDBUF37 Mask */

#define LCD_LCD_BUFS9_LCDBUF38_Pos   16                                           /*!<LCD LCD_BUFS9: LCDBUF38 Position */
#define LCD_LCD_BUFS9_LCDBUF38_Msk   (0xFFUL << LCD_LCD_BUFS9_LCDBUF38_Pos)       /*!<LCD LCD_BUFS9: LCDBUF38 Mask */

#define LCD_LCD_BUFS9_LCDBUF39_Pos   24                                           /*!<LCD LCD_BUFS9: LCDBUF39 Position */
#define LCD_LCD_BUFS9_LCDBUF39_Msk   (0xFFUL << LCD_LCD_BUFS9_LCDBUF39_Pos)       /*!<LCD LCD_BUFS9: LCDBUF39 Mask */

#define LCD_LCD_BUFS9_Msk_ALL        (LCD_LCD_BUFS9_LCDBUF36_Msk   |\
                                      LCD_LCD_BUFS9_LCDBUF37_Msk   |\
                                      LCD_LCD_BUFS9_LCDBUF38_Msk   |\
                                      LCD_LCD_BUFS9_LCDBUF39_Msk   )

#define LED_CR_EN_Pos                0                                            /*!<LED CR: EN Position */
#define LED_CR_EN_Msk                (0x1UL /*<< LED_CR_EN_Pos*/)                 /*!<LED CR: EN Mask */

#define LED_CR_LEDMD_Pos             1                                            /*!<LED CR: LEDMD Position */
#define LED_CR_LEDMD_Msk             (0x1UL << LED_CR_LEDMD_Pos)                  /*!<LED CR: LEDMD Mask */

#define LED_CR_MODE_Pos              2                                            /*!<LED CR: MODE Position */
#define LED_CR_MODE_Msk              (0x1UL << LED_CR_MODE_Pos)                   /*!<LED CR: MODE Mask */

#define LED_CR_MODSW_Pos             3                                            /*!<LED CR: MODSW Position */
#define LED_CR_MODSW_Msk             (0x1UL << LED_CR_MODSW_Pos)                  /*!<LED CR: MODSW Mask */

#define LED_CR_IE_Pos                4                                            /*!<LED CR: IE Position */
#define LED_CR_IE_Msk                (0x1UL << LED_CR_IE_Pos)                     /*!<LED CR: IE Mask */

#define LED_CR_LEDMODSEL_Pos         5                                            /*!<LED CR: LEDMODSEL Position */
#define LED_CR_LEDMODSEL_Msk         (0x1UL << LED_CR_LEDMODSEL_Pos)              /*!<LED CR: LEDMODSEL Mask */

#define LED_CR_LEDFY_Pos             6                                            /*!<LED CR: LEDFY Position */
#define LED_CR_LEDFY_Msk             (0x1UL << LED_CR_LEDFY_Pos)                  /*!<LED CR: LEDFY Mask */

#define LED_CR_LEDCY_Pos             7                                            /*!<LED CR: LEDCY Position */
#define LED_CR_LEDCY_Msk             (0x1UL << LED_CR_LEDCY_Pos)                  /*!<LED CR: LEDCY Mask */

#define LED_CR_DISCOM_Pos            8                                            /*!<LED CR: DISCOM Position */
#define LED_CR_DISCOM_Msk            (0xFFUL << LED_CR_DISCOM_Pos)                /*!<LED CR: DISCOM Mask */

#define LED_CR_LEDDZ_Pos             16                                           /*!<LED CR: LEDDZ Position */
#define LED_CR_LEDDZ_Msk             (0xFFUL << LED_CR_LEDDZ_Pos)                 /*!<LED CR: LEDDZ Mask */

#define LED_CR_CNTMOD_Pos            24                                           /*!<LED CR: CNTMOD Position */
#define LED_CR_CNTMOD_Msk            (0x1UL << LED_CR_CNTMOD_Pos)                 /*!<LED CR: CNTMOD Mask */

#define LED_CR_LEDFDMA_Pos           25                                           /*!<LED CR: LEDFDMA Position */
#define LED_CR_LEDFDMA_Msk           (0x1UL << LED_CR_LEDFDMA_Pos)                /*!<LED CR: LEDFDMA Mask */

#define LED_CR_LEDCDMA_Pos           26                                           /*!<LED CR: LEDCDMA Position */
#define LED_CR_LEDCDMA_Msk           (0x1UL << LED_CR_LEDCDMA_Pos)                /*!<LED CR: LEDCDMA Mask */

#define LED_CR_Msk_ALL               (LED_CR_EN_Msk                |\
                                      LED_CR_LEDMD_Msk             |\
                                      LED_CR_MODE_Msk              |\
                                      LED_CR_MODSW_Msk             |\
                                      LED_CR_IE_Msk                |\
                                      LED_CR_LEDMODSEL_Msk         |\
                                      LED_CR_LEDFY_Msk             |\
                                      LED_CR_LEDCY_Msk             |\
                                      LED_CR_DISCOM_Msk            |\
                                      LED_CR_LEDDZ_Msk             |\
                                      LED_CR_CNTMOD_Msk            |\
                                      LED_CR_LEDFDMA_Msk           |\
                                      LED_CR_LEDCDMA_Msk           )

#define LED_FR_COMIF_Pos             0                                            /*!<LED FR: COMIF Position */
#define LED_FR_COMIF_Msk             (0x1UL /*<< LED_FR_COMIF_Pos*/)              /*!<LED FR: COMIF Mask */

#define LED_FR_LEDIF_Pos             1                                            /*!<LED FR: LEDIF Position */
#define LED_FR_LEDIF_Msk             (0x1UL << LED_FR_LEDIF_Pos)                  /*!<LED FR: LEDIF Mask */

#define LED_FR_COMIFC_Pos            16                                           /*!<LED FR: COMIFC Position */
#define LED_FR_COMIFC_Msk            (0x1UL << LED_FR_COMIFC_Pos)                 /*!<LED FR: COMIFC Mask */

#define LED_FR_LEDIFC_Pos            17                                           /*!<LED FR: LEDIFC Position */
#define LED_FR_LEDIFC_Msk            (0x1UL << LED_FR_LEDIFC_Pos)                 /*!<LED FR: LEDIFC Mask */

#define LED_FR_Msk_ALL               (LED_FR_COMIF_Msk             |\
                                      LED_FR_LEDIF_Msk             |\
                                      LED_FR_COMIFC_Msk            |\
                                      LED_FR_LEDIFC_Msk            )

#define LED_LEDSHARE_LEDCOM_Pos      0                                            /*!<LED LEDSHARE: LEDCOM Position */
#define LED_LEDSHARE_LEDCOM_Msk      (0xFFFUL /*<< LED_LEDSHARE_LEDCOM_Pos*/)     /*!<LED LEDSHARE: LEDCOM Mask */

#define LED_LEDSHARE_LEDSEG1_Pos     16                                           /*!<LED LEDSHARE: LEDSEG1 Position */
#define LED_LEDSHARE_LEDSEG1_Msk     (0xFFUL << LED_LEDSHARE_LEDSEG1_Pos)         /*!<LED LEDSHARE: LEDSEG1 Mask */

#define LED_LEDSHARE_LEDSEG2_Pos     24                                           /*!<LED LEDSHARE: LEDSEG2 Position */
#define LED_LEDSHARE_LEDSEG2_Msk     (0xFFUL << LED_LEDSHARE_LEDSEG2_Pos)         /*!<LED LEDSHARE: LEDSEG2 Mask */

#define LED_LEDSHARE_Msk_ALL         (LED_LEDSHARE_LEDCOM_Msk      |\
                                      LED_LEDSHARE_LEDSEG1_Msk     |\
                                      LED_LEDSHARE_LEDSEG2_Msk     )

#define LED_LED_BUFS0_LEDCOM1_Pos    0                                            /*!<LED LED_BUFS0: LEDCOM1 Position */
#define LED_LED_BUFS0_LEDCOM1_Msk    (0xFFFFUL /*<< LED_LED_BUFS0_LEDCOM1_Pos*/)  /*!<LED LED_BUFS0: LEDCOM1 Mask */

#define LED_LED_BUFS0_LEDCOM2_Pos    16                                           /*!<LED LED_BUFS0: LEDCOM2 Position */
#define LED_LED_BUFS0_LEDCOM2_Msk    (0xFFFFUL << LED_LED_BUFS0_LEDCOM2_Pos)      /*!<LED LED_BUFS0: LEDCOM2 Mask */

#define LED_LED_BUFS0_Msk_ALL        (LED_LED_BUFS0_LEDCOM1_Msk    |\
                                      LED_LED_BUFS0_LEDCOM2_Msk    )

#define LED_LED_BUFS1_LEDCOM3_Pos    0                                            /*!<LED LED_BUFS1: LEDCOM3 Position */
#define LED_LED_BUFS1_LEDCOM3_Msk    (0xFFFFUL /*<< LED_LED_BUFS1_LEDCOM3_Pos*/)  /*!<LED LED_BUFS1: LEDCOM3 Mask */

#define LED_LED_BUFS1_LEDCOM4_Pos    16                                           /*!<LED LED_BUFS1: LEDCOM4 Position */
#define LED_LED_BUFS1_LEDCOM4_Msk    (0xFFFFUL << LED_LED_BUFS1_LEDCOM4_Pos)      /*!<LED LED_BUFS1: LEDCOM4 Mask */

#define LED_LED_BUFS1_Msk_ALL        (LED_LED_BUFS1_LEDCOM3_Msk    |\
                                      LED_LED_BUFS1_LEDCOM4_Msk    )

#define LED_LED_BUFS2_LEDCOM5_Pos    0                                            /*!<LED LED_BUFS2: LEDCOM5 Position */
#define LED_LED_BUFS2_LEDCOM5_Msk    (0xFFFFUL /*<< LED_LED_BUFS2_LEDCOM5_Pos*/)  /*!<LED LED_BUFS2: LEDCOM5 Mask */

#define LED_LED_BUFS2_LEDCOM6_Pos    16                                           /*!<LED LED_BUFS2: LEDCOM6 Position */
#define LED_LED_BUFS2_LEDCOM6_Msk    (0xFFFFUL << LED_LED_BUFS2_LEDCOM6_Pos)      /*!<LED LED_BUFS2: LEDCOM6 Mask */

#define LED_LED_BUFS2_Msk_ALL        (LED_LED_BUFS2_LEDCOM5_Msk    |\
                                      LED_LED_BUFS2_LEDCOM6_Msk    )

#define LED_LED_BUFS3_LEDCOM7_Pos    0                                            /*!<LED LED_BUFS3: LEDCOM7 Position */
#define LED_LED_BUFS3_LEDCOM7_Msk    (0xFFFFUL /*<< LED_LED_BUFS3_LEDCOM7_Pos*/)  /*!<LED LED_BUFS3: LEDCOM7 Mask */

#define LED_LED_BUFS3_LEDCOM8_Pos    16                                           /*!<LED LED_BUFS3: LEDCOM8 Position */
#define LED_LED_BUFS3_LEDCOM8_Msk    (0xFFFFUL << LED_LED_BUFS3_LEDCOM8_Pos)      /*!<LED LED_BUFS3: LEDCOM8 Mask */

#define LED_LED_BUFS3_Msk_ALL        (LED_LED_BUFS3_LEDCOM7_Msk    |\
                                      LED_LED_BUFS3_LEDCOM8_Msk    )

#define LED_LED_BUFS4_LEDCOM9_Pos    0                                            /*!<LED LED_BUFS4: LEDCOM9 Position */
#define LED_LED_BUFS4_LEDCOM9_Msk    (0xFFFFUL /*<< LED_LED_BUFS4_LEDCOM9_Pos*/)  /*!<LED LED_BUFS4: LEDCOM9 Mask */

#define LED_LED_BUFS4_LEDCOM10_Pos   16                                           /*!<LED LED_BUFS4: LEDCOM10 Position */
#define LED_LED_BUFS4_LEDCOM10_Msk   (0xFFFFUL << LED_LED_BUFS4_LEDCOM10_Pos)     /*!<LED LED_BUFS4: LEDCOM10 Mask */

#define LED_LED_BUFS4_Msk_ALL        (LED_LED_BUFS4_LEDCOM9_Msk    |\
                                      LED_LED_BUFS4_LEDCOM10_Msk   )

#define LED_LED_BUFS5_LEDCOM11_Pos   0                                            /*!<LED LED_BUFS5: LEDCOM11 Position */
#define LED_LED_BUFS5_LEDCOM11_Msk   (0xFFFFUL /*<< LED_LED_BUFS5_LEDCOM11_Pos*/) /*!<LED LED_BUFS5: LEDCOM11 Mask */

#define LED_LED_BUFS5_LEDCOM12_Pos   16                                           /*!<LED LED_BUFS5: LEDCOM12 Position */
#define LED_LED_BUFS5_LEDCOM12_Msk   (0xFFFFUL << LED_LED_BUFS5_LEDCOM12_Pos)     /*!<LED LED_BUFS5: LEDCOM12 Mask */

#define LED_LED_BUFS5_Msk_ALL        (LED_LED_BUFS5_LEDCOM11_Msk   |\
                                      LED_LED_BUFS5_LEDCOM12_Msk   )

#define LED_LED_BUFS6_LEDSEG1_Pos    0                                            /*!<LED LED_BUFS6: LEDSEG1 Position */
#define LED_LED_BUFS6_LEDSEG1_Msk    (0xFFUL /*<< LED_LED_BUFS6_LEDSEG1_Pos*/)    /*!<LED LED_BUFS6: LEDSEG1 Mask */

#define LED_LED_BUFS6_LEDSEG2_Pos    8                                            /*!<LED LED_BUFS6: LEDSEG2 Position */
#define LED_LED_BUFS6_LEDSEG2_Msk    (0xFFUL << LED_LED_BUFS6_LEDSEG2_Pos)        /*!<LED LED_BUFS6: LEDSEG2 Mask */

#define LED_LED_BUFS6_LEDSEG3_Pos    16                                           /*!<LED LED_BUFS6: LEDSEG3 Position */
#define LED_LED_BUFS6_LEDSEG3_Msk    (0xFFUL << LED_LED_BUFS6_LEDSEG3_Pos)        /*!<LED LED_BUFS6: LEDSEG3 Mask */

#define LED_LED_BUFS6_LEDSEG4_Pos    24                                           /*!<LED LED_BUFS6: LEDSEG4 Position */
#define LED_LED_BUFS6_LEDSEG4_Msk    (0xFFUL << LED_LED_BUFS6_LEDSEG4_Pos)        /*!<LED LED_BUFS6: LEDSEG4 Mask */

#define LED_LED_BUFS6_Msk_ALL        (LED_LED_BUFS6_LEDSEG1_Msk    |\
                                      LED_LED_BUFS6_LEDSEG2_Msk    |\
                                      LED_LED_BUFS6_LEDSEG3_Msk    |\
                                      LED_LED_BUFS6_LEDSEG4_Msk    )

#define LED_LED_BUFS7_LEDSEG5_Pos    0                                            /*!<LED LED_BUFS7: LEDSEG5 Position */
#define LED_LED_BUFS7_LEDSEG5_Msk    (0xFFUL /*<< LED_LED_BUFS7_LEDSEG5_Pos*/)    /*!<LED LED_BUFS7: LEDSEG5 Mask */

#define LED_LED_BUFS7_LEDSEG6_Pos    8                                            /*!<LED LED_BUFS7: LEDSEG6 Position */
#define LED_LED_BUFS7_LEDSEG6_Msk    (0xFFUL << LED_LED_BUFS7_LEDSEG6_Pos)        /*!<LED LED_BUFS7: LEDSEG6 Mask */

#define LED_LED_BUFS7_LEDSEG7_Pos    16                                           /*!<LED LED_BUFS7: LEDSEG7 Position */
#define LED_LED_BUFS7_LEDSEG7_Msk    (0xFFUL << LED_LED_BUFS7_LEDSEG7_Pos)        /*!<LED LED_BUFS7: LEDSEG7 Mask */

#define LED_LED_BUFS7_LEDSEG8_Pos    24                                           /*!<LED LED_BUFS7: LEDSEG8 Position */
#define LED_LED_BUFS7_LEDSEG8_Msk    (0xFFUL << LED_LED_BUFS7_LEDSEG8_Pos)        /*!<LED LED_BUFS7: LEDSEG8 Mask */

#define LED_LED_BUFS7_Msk_ALL        (LED_LED_BUFS7_LEDSEG5_Msk    |\
                                      LED_LED_BUFS7_LEDSEG6_Msk    |\
                                      LED_LED_BUFS7_LEDSEG7_Msk    |\
                                      LED_LED_BUFS7_LEDSEG8_Msk    )

#define LED_LED_BUFS8_LEDSEG9_Pos    0                                            /*!<LED LED_BUFS8: LEDSEG9 Position */
#define LED_LED_BUFS8_LEDSEG9_Msk    (0xFFUL /*<< LED_LED_BUFS8_LEDSEG9_Pos*/)    /*!<LED LED_BUFS8: LEDSEG9 Mask */

#define LED_LED_BUFS8_LEDSEG10_Pos   8                                            /*!<LED LED_BUFS8: LEDSEG10 Position */
#define LED_LED_BUFS8_LEDSEG10_Msk   (0xFFUL << LED_LED_BUFS8_LEDSEG10_Pos)       /*!<LED LED_BUFS8: LEDSEG10 Mask */

#define LED_LED_BUFS8_LEDSEG11_Pos   16                                           /*!<LED LED_BUFS8: LEDSEG11 Position */
#define LED_LED_BUFS8_LEDSEG11_Msk   (0xFFUL << LED_LED_BUFS8_LEDSEG11_Pos)       /*!<LED LED_BUFS8: LEDSEG11 Mask */

#define LED_LED_BUFS8_LEDSEG12_Pos   24                                           /*!<LED LED_BUFS8: LEDSEG12 Position */
#define LED_LED_BUFS8_LEDSEG12_Msk   (0xFFUL << LED_LED_BUFS8_LEDSEG12_Pos)       /*!<LED LED_BUFS8: LEDSEG12 Mask */

#define LED_LED_BUFS8_Msk_ALL        (LED_LED_BUFS8_LEDSEG9_Msk    |\
                                      LED_LED_BUFS8_LEDSEG10_Msk   |\
                                      LED_LED_BUFS8_LEDSEG11_Msk   |\
                                      LED_LED_BUFS8_LEDSEG12_Msk   )

#define LED_LED_BUFS9_LEDSEG13_Pos   0                                            /*!<LED LED_BUFS9: LEDSEG13 Position */
#define LED_LED_BUFS9_LEDSEG13_Msk   (0xFFUL /*<< LED_LED_BUFS9_LEDSEG13_Pos*/)   /*!<LED LED_BUFS9: LEDSEG13 Mask */

#define LED_LED_BUFS9_LEDSEG14_Pos   8                                            /*!<LED LED_BUFS9: LEDSEG14 Position */
#define LED_LED_BUFS9_LEDSEG14_Msk   (0xFFUL << LED_LED_BUFS9_LEDSEG14_Pos)       /*!<LED LED_BUFS9: LEDSEG14 Mask */

#define LED_LED_BUFS9_LEDSEG15_Pos   16                                           /*!<LED LED_BUFS9: LEDSEG15 Position */
#define LED_LED_BUFS9_LEDSEG15_Msk   (0xFFUL << LED_LED_BUFS9_LEDSEG15_Pos)       /*!<LED LED_BUFS9: LEDSEG15 Mask */

#define LED_LED_BUFS9_LEDSEG16_Pos   24                                           /*!<LED LED_BUFS9: LEDSEG16 Position */
#define LED_LED_BUFS9_LEDSEG16_Msk   (0xFFUL << LED_LED_BUFS9_LEDSEG16_Pos)       /*!<LED LED_BUFS9: LEDSEG16 Mask */

#define LED_LED_BUFS9_Msk_ALL        (LED_LED_BUFS9_LEDSEG13_Msk   |\
                                      LED_LED_BUFS9_LEDSEG14_Msk   |\
                                      LED_LED_BUFS9_LEDSEG15_Msk   |\
                                      LED_LED_BUFS9_LEDSEG16_Msk   )

#define TOUCHKEY_CR_TKCON_Pos        0                                            /*!<TOUCHKEY CR: TKCON Position */
#define TOUCHKEY_CR_TKCON_Msk        (0x1UL /*<< TOUCHKEY_CR_TKCON_Pos*/)         /*!<TOUCHKEY CR: TKCON Mask */

#define TOUCHKEY_CR_TKGO_DONE_Pos    1                                            /*!<TOUCHKEY CR: TKGO_DONE Position */
#define TOUCHKEY_CR_TKGO_DONE_Msk    (0x1UL << TOUCHKEY_CR_TKGO_DONE_Pos)         /*!<TOUCHKEY CR: TKGO_DONE Mask */

#define TOUCHKEY_CR_DATACON_Pos      2                                            /*!<TOUCHKEY CR: DATACON Position */
#define TOUCHKEY_CR_DATACON_Msk      (0x1UL << TOUCHKEY_CR_DATACON_Pos)           /*!<TOUCHKEY CR: DATACON Mask */

#define TOUCHKEY_CR_MODE_Pos         3                                            /*!<TOUCHKEY CR: MODE Position */
#define TOUCHKEY_CR_MODE_Msk         (0x1UL << TOUCHKEY_CR_MODE_Pos)              /*!<TOUCHKEY CR: MODE Mask */

#define TOUCHKEY_CR_FSW_Pos          4                                            /*!<TOUCHKEY CR: FSW Position */
#define TOUCHKEY_CR_FSW_Msk          (0x3UL << TOUCHKEY_CR_FSW_Pos)               /*!<TOUCHKEY CR: FSW Mask */

#define TOUCHKEY_CR_IE_Pos           6                                            /*!<TOUCHKEY CR: IE Position */
#define TOUCHKEY_CR_IE_Msk           (0x1UL << TOUCHKEY_CR_IE_Pos)                /*!<TOUCHKEY CR: IE Mask */

#define TOUCHKEY_CR_ST_Pos           7                                            /*!<TOUCHKEY CR: ST Position */
#define TOUCHKEY_CR_ST_Msk           (0xFFUL << TOUCHKEY_CR_ST_Pos)               /*!<TOUCHKEY CR: ST Mask */

#define TOUCHKEY_CR_TKOSM_Pos        15                                           /*!<TOUCHKEY CR: TKOSM Position */
#define TOUCHKEY_CR_TKOSM_Msk        (0x1UL << TOUCHKEY_CR_TKOSM_Pos)             /*!<TOUCHKEY CR: TKOSM Mask */

#define TOUCHKEY_CR_TKOFFSET_Pos     16                                           /*!<TOUCHKEY CR: TKOFFSET Position */
#define TOUCHKEY_CR_TKOFFSET_Msk     (0x1UL << TOUCHKEY_CR_TKOFFSET_Pos)          /*!<TOUCHKEY CR: TKOFFSET Mask */

#define TOUCHKEY_CR_TKRANDOM_Pos     17                                           /*!<TOUCHKEY CR: TKRANDOM Position */
#define TOUCHKEY_CR_TKRANDOM_Msk     (0x1UL << TOUCHKEY_CR_TKRANDOM_Pos)          /*!<TOUCHKEY CR: TKRANDOM Mask */

#define TOUCHKEY_CR_TKHYSW_Pos       18                                           /*!<TOUCHKEY CR: TKHYSW Position */
#define TOUCHKEY_CR_TKHYSW_Msk       (0x1UL << TOUCHKEY_CR_TKHYSW_Pos)            /*!<TOUCHKEY CR: TKHYSW Mask */

#define TOUCHKEY_CR_RANDOM_Pos       19                                           /*!<TOUCHKEY CR: RANDOM Position */
#define TOUCHKEY_CR_RANDOM_Msk       (0x3UL << TOUCHKEY_CR_RANDOM_Pos)            /*!<TOUCHKEY CR: RANDOM Mask */

#define TOUCHKEY_CR_CMPD_Pos         21                                           /*!<TOUCHKEY CR: CMPD Position */
#define TOUCHKEY_CR_CMPD_Msk         (0x3UL << TOUCHKEY_CR_CMPD_Pos)              /*!<TOUCHKEY CR: CMPD Mask */

#define TOUCHKEY_CR_TUNE_Pos         23                                           /*!<TOUCHKEY CR: TUNE Position */
#define TOUCHKEY_CR_TUNE_Msk         (0x3UL << TOUCHKEY_CR_TUNE_Pos)              /*!<TOUCHKEY CR: TUNE Mask */

#define TOUCHKEY_CR_TKDMA_Pos        25                                           /*!<TOUCHKEY CR: TKDMA Position */
#define TOUCHKEY_CR_TKDMA_Msk        (0x1UL << TOUCHKEY_CR_TKDMA_Pos)             /*!<TOUCHKEY CR: TKDMA Mask */

#define TOUCHKEY_CR_TK_BG_Pos        26                                           /*!<TOUCHKEY CR: TK_BG Position */
#define TOUCHKEY_CR_TK_BG_Msk        (0x1UL << TOUCHKEY_CR_TK_BG_Pos)             /*!<TOUCHKEY CR: TK_BG Mask */

#define TOUCHKEY_CR_Msk_ALL          (TOUCHKEY_CR_TKCON_Msk        |\
                                      TOUCHKEY_CR_TKGO_DONE_Msk    |\
                                      TOUCHKEY_CR_DATACON_Msk      |\
                                      TOUCHKEY_CR_MODE_Msk         |\
                                      TOUCHKEY_CR_FSW_Msk          |\
                                      TOUCHKEY_CR_IE_Msk           |\
                                      TOUCHKEY_CR_ST_Msk           |\
                                      TOUCHKEY_CR_TKOSM_Msk        |\
                                      TOUCHKEY_CR_TKOFFSET_Msk     |\
                                      TOUCHKEY_CR_TKRANDOM_Msk     |\
                                      TOUCHKEY_CR_TKHYSW_Msk       |\
                                      TOUCHKEY_CR_RANDOM_Msk       |\
                                      TOUCHKEY_CR_CMPD_Msk         |\
                                      TOUCHKEY_CR_TUNE_Msk         |\
                                      TOUCHKEY_CR_TKDMA_Msk        |\
                                      TOUCHKEY_CR_TK_BG_Msk        )

#define TOUCHKEY_FR_IFCOUNT_Pos      0                                            /*!<TOUCHKEY FR: IFCOUNT Position */
#define TOUCHKEY_FR_IFCOUNT_Msk      (0x1UL /*<< TOUCHKEY_FR_IFCOUNT_Pos*/)       /*!<TOUCHKEY FR: IFCOUNT Mask */

#define TOUCHKEY_FR_IFAVE_Pos        1                                            /*!<TOUCHKEY FR: IFAVE Position */
#define TOUCHKEY_FR_IFAVE_Msk        (0x1UL << TOUCHKEY_FR_IFAVE_Pos)             /*!<TOUCHKEY FR: IFAVE Mask */

#define TOUCHKEY_FR_IFGO_Pos         2                                            /*!<TOUCHKEY FR: IFGO Position */
#define TOUCHKEY_FR_IFGO_Msk         (0x1UL << TOUCHKEY_FR_IFGO_Pos)              /*!<TOUCHKEY FR: IFGO Mask */

#define TOUCHKEY_FR_IFERR_Pos        3                                            /*!<TOUCHKEY FR: IFERR Position */
#define TOUCHKEY_FR_IFERR_Msk        (0x1UL << TOUCHKEY_FR_IFERR_Pos)             /*!<TOUCHKEY FR: IFERR Mask */

#define TOUCHKEY_FR_IFCOUNTC_Pos     16                                           /*!<TOUCHKEY FR: IFCOUNTC Position */
#define TOUCHKEY_FR_IFCOUNTC_Msk     (0x1UL << TOUCHKEY_FR_IFCOUNTC_Pos)          /*!<TOUCHKEY FR: IFCOUNTC Mask */

#define TOUCHKEY_FR_IFAVEC_Pos       17                                           /*!<TOUCHKEY FR: IFAVEC Position */
#define TOUCHKEY_FR_IFAVEC_Msk       (0x1UL << TOUCHKEY_FR_IFAVEC_Pos)            /*!<TOUCHKEY FR: IFAVEC Mask */

#define TOUCHKEY_FR_IFGOC_Pos        18                                           /*!<TOUCHKEY FR: IFGOC Position */
#define TOUCHKEY_FR_IFGOC_Msk        (0x1UL << TOUCHKEY_FR_IFGOC_Pos)             /*!<TOUCHKEY FR: IFGOC Mask */

#define TOUCHKEY_FR_IFERRC_Pos       19                                           /*!<TOUCHKEY FR: IFERRC Position */
#define TOUCHKEY_FR_IFERRC_Msk       (0x1UL << TOUCHKEY_FR_IFERRC_Pos)            /*!<TOUCHKEY FR: IFERRC Mask */

#define TOUCHKEY_FR_Msk_ALL          (TOUCHKEY_FR_IFCOUNT_Msk      |\
                                      TOUCHKEY_FR_IFAVE_Msk        |\
                                      TOUCHKEY_FR_IFGO_Msk         |\
                                      TOUCHKEY_FR_IFERR_Msk        |\
                                      TOUCHKEY_FR_IFCOUNTC_Msk     |\
                                      TOUCHKEY_FR_IFAVEC_Msk       |\
                                      TOUCHKEY_FR_IFGOC_Msk        |\
                                      TOUCHKEY_FR_IFERRC_Msk       )

#define TOUCHKEY_CR1_VSYSEN_Pos      0                                            /*!<TOUCHKEY CR1: VSYSEN Position */
#define TOUCHKEY_CR1_VSYSEN_Msk      (0x1UL /*<< TOUCHKEY_CR1_VSYSEN_Pos*/)       /*!<TOUCHKEY CR1: VSYSEN Mask */

#define TOUCHKEY_CR1_VSYS_Pos        1                                            /*!<TOUCHKEY CR1: VSYS Position */
#define TOUCHKEY_CR1_VSYS_Msk        (0x3UL << TOUCHKEY_CR1_VSYS_Pos)             /*!<TOUCHKEY CR1: VSYS Mask */

#define TOUCHKEY_CR1_VTK_Pos         3                                            /*!<TOUCHKEY CR1: VTK Position */
#define TOUCHKEY_CR1_VTK_Msk         (0x7UL << TOUCHKEY_CR1_VTK_Pos)              /*!<TOUCHKEY CR1: VTK Mask */

#define TOUCHKEY_CR1_VREF_Pos        6                                            /*!<TOUCHKEY CR1: VREF Position */
#define TOUCHKEY_CR1_VREF_Msk        (0x7UL << TOUCHKEY_CR1_VREF_Pos)             /*!<TOUCHKEY CR1: VREF Mask */

#define TOUCHKEY_CR1_VPREEN_Pos      9                                            /*!<TOUCHKEY CR1: VPREEN Position */
#define TOUCHKEY_CR1_VPREEN_Msk      (0x1UL << TOUCHKEY_CR1_VPREEN_Pos)           /*!<TOUCHKEY CR1: VPREEN Mask */

#define TOUCHKEY_CR1_VPRE_Pos        10                                           /*!<TOUCHKEY CR1: VPRE Position */
#define TOUCHKEY_CR1_VPRE_Msk        (0x7UL << TOUCHKEY_CR1_VPRE_Pos)             /*!<TOUCHKEY CR1: VPRE Mask */

#define TOUCHKEY_CR1_ENCADJ_Pos      13                                           /*!<TOUCHKEY CR1: ENCADJ Position */
#define TOUCHKEY_CR1_ENCADJ_Msk      (0x1UL << TOUCHKEY_CR1_ENCADJ_Pos)           /*!<TOUCHKEY CR1: ENCADJ Mask */

#define TOUCHKEY_CR1_CADJ_Pos        14                                           /*!<TOUCHKEY CR1: CADJ Position */
#define TOUCHKEY_CR1_CADJ_Msk        (0x7UL << TOUCHKEY_CR1_CADJ_Pos)             /*!<TOUCHKEY CR1: CADJ Mask */

#define TOUCHKEY_CR1_ENCREF_Pos      17                                           /*!<TOUCHKEY CR1: ENCREF Position */
#define TOUCHKEY_CR1_ENCREF_Msk      (0x1UL << TOUCHKEY_CR1_ENCREF_Pos)           /*!<TOUCHKEY CR1: ENCREF Mask */

#define TOUCHKEY_CR1_CREF_Pos        18                                           /*!<TOUCHKEY CR1: CREF Position */
#define TOUCHKEY_CR1_CREF_Msk        (0x7UL << TOUCHKEY_CR1_CREF_Pos)             /*!<TOUCHKEY CR1: CREF Mask */

#define TOUCHKEY_CR1_VCREF_Pos       21                                           /*!<TOUCHKEY CR1: VCREF Position */
#define TOUCHKEY_CR1_VCREF_Msk       (0x1UL << TOUCHKEY_CR1_VCREF_Pos)            /*!<TOUCHKEY CR1: VCREF Mask */

#define TOUCHKEY_CR1_SHON_Pos        22                                           /*!<TOUCHKEY CR1: SHON Position */
#define TOUCHKEY_CR1_SHON_Msk        (0x1UL << TOUCHKEY_CR1_SHON_Pos)             /*!<TOUCHKEY CR1: SHON Mask */

#define TOUCHKEY_CR1_TKIO_Pos        23                                           /*!<TOUCHKEY CR1: TKIO Position */
#define TOUCHKEY_CR1_TKIO_Msk        (0x1UL << TOUCHKEY_CR1_TKIO_Pos)             /*!<TOUCHKEY CR1: TKIO Mask */

#define TOUCHKEY_CR1_TKFL_Pos        24                                           /*!<TOUCHKEY CR1: TKFL Position */
#define TOUCHKEY_CR1_TKFL_Msk        (0x1UL << TOUCHKEY_CR1_TKFL_Pos)             /*!<TOUCHKEY CR1: TKFL Mask */

#define TOUCHKEY_CR1_TKOP_Pos        25                                           /*!<TOUCHKEY CR1: TKOP Position */
#define TOUCHKEY_CR1_TKOP_Msk        (0x1UL << TOUCHKEY_CR1_TKOP_Pos)             /*!<TOUCHKEY CR1: TKOP Mask */

#define TOUCHKEY_CR1_Msk_ALL         (TOUCHKEY_CR1_VSYSEN_Msk      |\
                                      TOUCHKEY_CR1_VSYS_Msk        |\
                                      TOUCHKEY_CR1_VTK_Msk         |\
                                      TOUCHKEY_CR1_VREF_Msk        |\
                                      TOUCHKEY_CR1_VPREEN_Msk      |\
                                      TOUCHKEY_CR1_VPRE_Msk        |\
                                      TOUCHKEY_CR1_ENCADJ_Msk      |\
                                      TOUCHKEY_CR1_CADJ_Msk        |\
                                      TOUCHKEY_CR1_ENCREF_Msk      |\
                                      TOUCHKEY_CR1_CREF_Msk        |\
                                      TOUCHKEY_CR1_VCREF_Msk       |\
                                      TOUCHKEY_CR1_SHON_Msk        |\
                                      TOUCHKEY_CR1_TKIO_Msk        |\
                                      TOUCHKEY_CR1_TKFL_Msk        |\
                                      TOUCHKEY_CR1_TKOP_Msk        )

#define TOUCHKEY_TKU_TKU_Pos         0                                            /*!<TOUCHKEY TKU: TKU Position */
#define TOUCHKEY_TKU_TKU_Msk         (0xFFFFFFUL /*<< TOUCHKEY_TKU_TKU_Pos*/)     /*!<TOUCHKEY TKU: TKU Mask */

#define TOUCHKEY_TKU_Msk_ALL         (TOUCHKEY_TKU_TKU_Msk        )

#define TOUCHKEY_TKDIV_TKDIV_Pos     0                                            /*!<TOUCHKEY TKDIV: TKDIV Position */
#define TOUCHKEY_TKDIV_TKDIV_Msk     (0xFFFFFFFUL /*<< TOUCHKEY_TKDIV_TKDIV_Pos*/) /*!<TOUCHKEY TKDIV: TKDIV Mask */

#define TOUCHKEY_TKDIV_Msk_ALL       (TOUCHKEY_TKDIV_TKDIV_Msk    )

#define TOUCHKEY_TKCHANEL_TKCHANEL_Pos 0                                            /*!<TOUCHKEY TKCHANEL: TKCHANEL Position */
#define TOUCHKEY_TKCHANEL_TKCHANEL_Msk (0xFFFFFFUL /*<< TOUCHKEY_TKCHANEL_TKCHANEL_Pos*/) /*!<TOUCHKEY TKCHANEL: TKCHANEL Mask */

#define TOUCHKEY_TKCHANEL_Msk_ALL    (TOUCHKEY_TKCHANEL_TKCHANEL_Msk)

#define TOUCHKEY_TKW_TKW_Pos         0                                            /*!<TOUCHKEY TKW: TKW Position */
#define TOUCHKEY_TKW_TKW_Msk         (0x1FUL /*<< TOUCHKEY_TKW_TKW_Pos*/)         /*!<TOUCHKEY TKW: TKW Mask */

#define TOUCHKEY_TKW_Msk_ALL         (TOUCHKEY_TKW_TKW_Msk        )

#define TOUCHKEY_TK_BUFS0_TK1_Pos    0                                            /*!<TOUCHKEY TK_BUFS0: TK1 Position */
#define TOUCHKEY_TK_BUFS0_TK1_Msk    (0xFFFFUL /*<< TOUCHKEY_TK_BUFS0_TK1_Pos*/)  /*!<TOUCHKEY TK_BUFS0: TK1 Mask */

#define TOUCHKEY_TK_BUFS0_TK0_Pos    16                                           /*!<TOUCHKEY TK_BUFS0: TK0 Position */
#define TOUCHKEY_TK_BUFS0_TK0_Msk    (0xFFFFUL << TOUCHKEY_TK_BUFS0_TK0_Pos)      /*!<TOUCHKEY TK_BUFS0: TK0 Mask */

#define TOUCHKEY_TK_BUFS0_Msk_ALL    (TOUCHKEY_TK_BUFS0_TK1_Msk    |\
                                      TOUCHKEY_TK_BUFS0_TK0_Msk    )

#define TOUCHKEY_TK_BUFS1_TK3_Pos    0                                            /*!<TOUCHKEY TK_BUFS1: TK3 Position */
#define TOUCHKEY_TK_BUFS1_TK3_Msk    (0xFFFFUL /*<< TOUCHKEY_TK_BUFS1_TK3_Pos*/)  /*!<TOUCHKEY TK_BUFS1: TK3 Mask */

#define TOUCHKEY_TK_BUFS1_TK2_Pos    16                                           /*!<TOUCHKEY TK_BUFS1: TK2 Position */
#define TOUCHKEY_TK_BUFS1_TK2_Msk    (0xFFFFUL << TOUCHKEY_TK_BUFS1_TK2_Pos)      /*!<TOUCHKEY TK_BUFS1: TK2 Mask */

#define TOUCHKEY_TK_BUFS1_Msk_ALL    (TOUCHKEY_TK_BUFS1_TK3_Msk    |\
                                      TOUCHKEY_TK_BUFS1_TK2_Msk    )

#define TOUCHKEY_TK_BUFS2_TK5_Pos    0                                            /*!<TOUCHKEY TK_BUFS2: TK5 Position */
#define TOUCHKEY_TK_BUFS2_TK5_Msk    (0xFFFFUL /*<< TOUCHKEY_TK_BUFS2_TK5_Pos*/)  /*!<TOUCHKEY TK_BUFS2: TK5 Mask */

#define TOUCHKEY_TK_BUFS2_TK4_Pos    16                                           /*!<TOUCHKEY TK_BUFS2: TK4 Position */
#define TOUCHKEY_TK_BUFS2_TK4_Msk    (0xFFFFUL << TOUCHKEY_TK_BUFS2_TK4_Pos)      /*!<TOUCHKEY TK_BUFS2: TK4 Mask */

#define TOUCHKEY_TK_BUFS2_Msk_ALL    (TOUCHKEY_TK_BUFS2_TK5_Msk    |\
                                      TOUCHKEY_TK_BUFS2_TK4_Msk    )

#define TOUCHKEY_TK_BUFS3_TK7_Pos    0                                            /*!<TOUCHKEY TK_BUFS3: TK7 Position */
#define TOUCHKEY_TK_BUFS3_TK7_Msk    (0xFFFFUL /*<< TOUCHKEY_TK_BUFS3_TK7_Pos*/)  /*!<TOUCHKEY TK_BUFS3: TK7 Mask */

#define TOUCHKEY_TK_BUFS3_TK6_Pos    16                                           /*!<TOUCHKEY TK_BUFS3: TK6 Position */
#define TOUCHKEY_TK_BUFS3_TK6_Msk    (0xFFFFUL << TOUCHKEY_TK_BUFS3_TK6_Pos)      /*!<TOUCHKEY TK_BUFS3: TK6 Mask */

#define TOUCHKEY_TK_BUFS3_Msk_ALL    (TOUCHKEY_TK_BUFS3_TK7_Msk    |\
                                      TOUCHKEY_TK_BUFS3_TK6_Msk    )

#define TOUCHKEY_TK_BUFS4_TK9_Pos    0                                            /*!<TOUCHKEY TK_BUFS4: TK9 Position */
#define TOUCHKEY_TK_BUFS4_TK9_Msk    (0xFFFFUL /*<< TOUCHKEY_TK_BUFS4_TK9_Pos*/)  /*!<TOUCHKEY TK_BUFS4: TK9 Mask */

#define TOUCHKEY_TK_BUFS4_TK8_Pos    16                                           /*!<TOUCHKEY TK_BUFS4: TK8 Position */
#define TOUCHKEY_TK_BUFS4_TK8_Msk    (0xFFFFUL << TOUCHKEY_TK_BUFS4_TK8_Pos)      /*!<TOUCHKEY TK_BUFS4: TK8 Mask */

#define TOUCHKEY_TK_BUFS4_Msk_ALL    (TOUCHKEY_TK_BUFS4_TK9_Msk    |\
                                      TOUCHKEY_TK_BUFS4_TK8_Msk    )

#define TOUCHKEY_TK_BUFS5_TK11_Pos   0                                            /*!<TOUCHKEY TK_BUFS5: TK11 Position */
#define TOUCHKEY_TK_BUFS5_TK11_Msk   (0xFFFFUL /*<< TOUCHKEY_TK_BUFS5_TK11_Pos*/) /*!<TOUCHKEY TK_BUFS5: TK11 Mask */

#define TOUCHKEY_TK_BUFS5_TK10_Pos   16                                           /*!<TOUCHKEY TK_BUFS5: TK10 Position */
#define TOUCHKEY_TK_BUFS5_TK10_Msk   (0xFFFFUL << TOUCHKEY_TK_BUFS5_TK10_Pos)     /*!<TOUCHKEY TK_BUFS5: TK10 Mask */

#define TOUCHKEY_TK_BUFS5_Msk_ALL    (TOUCHKEY_TK_BUFS5_TK11_Msk   |\
                                      TOUCHKEY_TK_BUFS5_TK10_Msk   )

#define TOUCHKEY_TK_BUFS6_TK13_Pos   0                                            /*!<TOUCHKEY TK_BUFS6: TK13 Position */
#define TOUCHKEY_TK_BUFS6_TK13_Msk   (0xFFFFUL /*<< TOUCHKEY_TK_BUFS6_TK13_Pos*/) /*!<TOUCHKEY TK_BUFS6: TK13 Mask */

#define TOUCHKEY_TK_BUFS6_TK12_Pos   16                                           /*!<TOUCHKEY TK_BUFS6: TK12 Position */
#define TOUCHKEY_TK_BUFS6_TK12_Msk   (0xFFFFUL << TOUCHKEY_TK_BUFS6_TK12_Pos)     /*!<TOUCHKEY TK_BUFS6: TK12 Mask */

#define TOUCHKEY_TK_BUFS6_Msk_ALL    (TOUCHKEY_TK_BUFS6_TK13_Msk   |\
                                      TOUCHKEY_TK_BUFS6_TK12_Msk   )

#define TOUCHKEY_TK_BUFS7_TK15_Pos   0                                            /*!<TOUCHKEY TK_BUFS7: TK15 Position */
#define TOUCHKEY_TK_BUFS7_TK15_Msk   (0xFFFFUL /*<< TOUCHKEY_TK_BUFS7_TK15_Pos*/) /*!<TOUCHKEY TK_BUFS7: TK15 Mask */

#define TOUCHKEY_TK_BUFS7_TK14_Pos   16                                           /*!<TOUCHKEY TK_BUFS7: TK14 Position */
#define TOUCHKEY_TK_BUFS7_TK14_Msk   (0xFFFFUL << TOUCHKEY_TK_BUFS7_TK14_Pos)     /*!<TOUCHKEY TK_BUFS7: TK14 Mask */

#define TOUCHKEY_TK_BUFS7_Msk_ALL    (TOUCHKEY_TK_BUFS7_TK15_Msk   |\
                                      TOUCHKEY_TK_BUFS7_TK14_Msk   )

#define TOUCHKEY_TK_BUFS8_TK17_Pos   0                                            /*!<TOUCHKEY TK_BUFS8: TK17 Position */
#define TOUCHKEY_TK_BUFS8_TK17_Msk   (0xFFFFUL /*<< TOUCHKEY_TK_BUFS8_TK17_Pos*/) /*!<TOUCHKEY TK_BUFS8: TK17 Mask */

#define TOUCHKEY_TK_BUFS8_TK16_Pos   16                                           /*!<TOUCHKEY TK_BUFS8: TK16 Position */
#define TOUCHKEY_TK_BUFS8_TK16_Msk   (0xFFFFUL << TOUCHKEY_TK_BUFS8_TK16_Pos)     /*!<TOUCHKEY TK_BUFS8: TK16 Mask */

#define TOUCHKEY_TK_BUFS8_Msk_ALL    (TOUCHKEY_TK_BUFS8_TK17_Msk   |\
                                      TOUCHKEY_TK_BUFS8_TK16_Msk   )

#define TOUCHKEY_TK_BUFS9_TK19_Pos   0                                            /*!<TOUCHKEY TK_BUFS9: TK19 Position */
#define TOUCHKEY_TK_BUFS9_TK19_Msk   (0xFFFFUL /*<< TOUCHKEY_TK_BUFS9_TK19_Pos*/) /*!<TOUCHKEY TK_BUFS9: TK19 Mask */

#define TOUCHKEY_TK_BUFS9_TK18_Pos   16                                           /*!<TOUCHKEY TK_BUFS9: TK18 Position */
#define TOUCHKEY_TK_BUFS9_TK18_Msk   (0xFFFFUL << TOUCHKEY_TK_BUFS9_TK18_Pos)     /*!<TOUCHKEY TK_BUFS9: TK18 Mask */

#define TOUCHKEY_TK_BUFS9_Msk_ALL    (TOUCHKEY_TK_BUFS9_TK19_Msk   |\
                                      TOUCHKEY_TK_BUFS9_TK18_Msk   )

#define TOUCHKEY_TK_BUFS10_TK21_Pos  0                                            /*!<TOUCHKEY TK_BUFS10: TK21 Position */
#define TOUCHKEY_TK_BUFS10_TK21_Msk  (0xFFFFUL /*<< TOUCHKEY_TK_BUFS10_TK21_Pos*/) /*!<TOUCHKEY TK_BUFS10: TK21 Mask */

#define TOUCHKEY_TK_BUFS10_TK20_Pos  16                                           /*!<TOUCHKEY TK_BUFS10: TK20 Position */
#define TOUCHKEY_TK_BUFS10_TK20_Msk  (0xFFFFUL << TOUCHKEY_TK_BUFS10_TK20_Pos)    /*!<TOUCHKEY TK_BUFS10: TK20 Mask */

#define TOUCHKEY_TK_BUFS10_Msk_ALL   (TOUCHKEY_TK_BUFS10_TK21_Msk  |\
                                      TOUCHKEY_TK_BUFS10_TK20_Msk  )

#define TOUCHKEY_TK_BUFS11_TK23_Pos  0                                            /*!<TOUCHKEY TK_BUFS11: TK23 Position */
#define TOUCHKEY_TK_BUFS11_TK23_Msk  (0xFFFFUL /*<< TOUCHKEY_TK_BUFS11_TK23_Pos*/) /*!<TOUCHKEY TK_BUFS11: TK23 Mask */

#define TOUCHKEY_TK_BUFS11_TK22_Pos  16                                           /*!<TOUCHKEY TK_BUFS11: TK22 Position */
#define TOUCHKEY_TK_BUFS11_TK22_Msk  (0xFFFFUL << TOUCHKEY_TK_BUFS11_TK22_Pos)    /*!<TOUCHKEY TK_BUFS11: TK22 Mask */

#define TOUCHKEY_TK_BUFS11_Msk_ALL   (TOUCHKEY_TK_BUFS11_TK23_Msk  |\
                                      TOUCHKEY_TK_BUFS11_TK22_Msk  )

#define TOUCHKEY_TK_BUFCREF_TKCREF_Pos 0                                            /*!<TOUCHKEY TK_BUFCREF: TKCREF Position */
#define TOUCHKEY_TK_BUFCREF_TKCREF_Msk (0xFFFFUL /*<< TOUCHKEY_TK_BUFCREF_TKCREF_Pos*/) /*!<TOUCHKEY TK_BUFCREF: TKCREF Mask */

#define TOUCHKEY_TK_BUFCREF_Msk_ALL  (TOUCHKEY_TK_BUFCREF_TKCREF_Msk)


/* @addtogroup Peripheral Bitband Address */

#define FLASH_ACR_PRFTEN_BIT                      (*(__IO uint32_t*)(0x42890020))
#define FLASH_ACR_ICEN_BIT                        (*(__IO uint32_t*)(0x42890024))
#define FLASH_ACR_DCEN_BIT                        (*(__IO uint32_t*)(0x42890028))
#define FLASH_ACR_CRST_BIT                        (*(__IO uint32_t*)(0x4289002C))
#define FLASH_SR_EOP_BIT                          (*(__I  uint32_t*)(0x42890180))
#define FLASH_SR_OPERR_BIT                        (*(__I  uint32_t*)(0x42890184))
#define FLASH_SR_FLSERR_BIT                       (*(__I  uint32_t*)(0x4289018C))
#define FLASH_SR_WRPRTERR_BIT                     (*(__I  uint32_t*)(0x42890190))
#define FLASH_SR_PGPERR_BIT                       (*(__I  uint32_t*)(0x42890194))
#define FLASH_SR_PGWERR_BIT                       (*(__I  uint32_t*)(0x42890198))
#define FLASH_SR_STAERR_BIT                       (*(__I  uint32_t*)(0x4289019C))
#define FLASH_SR_BSY_BIT                          (*(__I  uint32_t*)(0x428901BC))
#define FLASH_SR_EOPC_BIT                         (*(__O  uint32_t*)(0x428901C0))
#define FLASH_SR_OPERRC_BIT                       (*(__O  uint32_t*)(0x428901C4))
#define FLASH_SR_FLSERRC_BIT                      (*(__O  uint32_t*)(0x428901CC))
#define FLASH_SR_WRPRTERRC_BIT                    (*(__O  uint32_t*)(0x428901D0))
#define FLASH_SR_PGPERRC_BIT                      (*(__O  uint32_t*)(0x428901D4))
#define FLASH_SR_PGWERRC_BIT                      (*(__O  uint32_t*)(0x428901D8))
#define FLASH_SR_STAERRC_BIT                      (*(__O  uint32_t*)(0x428901DC))
#define FLASH_CR_STRT_BIT                         (*(__IO uint32_t*)(0x42890220))
#define FLASH_CR_PSIZE_BIT                        (*(__IO uint32_t*)(0x4289022C))
#define FLASH_CR_INFLCK_BIT                       (*(__IO uint32_t*)(0x42890230))
#define FLASH_CR_E2LCK_BIT                        (*(__IO uint32_t*)(0x42890238))
#define FLASH_CR_MNLCK_BIT                        (*(__IO uint32_t*)(0x4289023C))
#define FLASH_CNTCR_CNTEN_BIT                     (*(__IO uint32_t*)(0x42890500))
#define SYSCFG_PWRCR_BODIE_BIT                    (*(__IO uint32_t*)(0x4287001C))
#define SYSCFG_PWRCR_BODEN_BIT                    (*(__IO uint32_t*)(0x42870020))
#define SYSCFG_PWRCR_LVREN_BIT                    (*(__IO uint32_t*)(0x4287002C))
#define SYSCFG_PWRSR_BODIF_BIT                    (*(__IO uint32_t*)(0x42870080))
#define SYSCFG_PWRSR_BODF_BIT                     (*(__I  uint32_t*)(0x42870084))
#define SYSCFG_SAFR_OSCXCFG_BIT                   (*(__IO uint32_t*)(0x42870108))
#define SYSCFG_SAFR_SWJCFG_BIT                    (*(__IO uint32_t*)(0x42870114))
#define SYSCFG_SAFR_IEN_EXTI0_BIT                 (*(__IO uint32_t*)(0x42870118))
#define SYSCFG_SAFR_IEN_BOD_BIT                   (*(__IO uint32_t*)(0x4287011C))
#define SYSCFG_SAFR_IEN_CSM_BIT                   (*(__IO uint32_t*)(0x42870120))
#define SYSCFG_DBGCR_DBG_SLEEP_BIT                (*(__IO uint32_t*)(0x42870200))
#define SYSCFG_DBGCR_DBG_STOP_BIT                 (*(__IO uint32_t*)(0x42870204))
#define SYSCFG_DBGCR_DBG_LCD_BIT                  (*(__IO uint32_t*)(0x4287020C))
#define SYSCFG_DBGCR_DBG_LED_BIT                  (*(__IO uint32_t*)(0x42870210))
#define SYSCFG_DBGCR_DBG_DMA_BIT                  (*(__IO uint32_t*)(0x42870214))
#define SYSCFG_DBGCR_DBG_IWDT_BIT                 (*(__IO uint32_t*)(0x42870218))
#define SYSCFG_DBGCR_DBG_WWDT_BIT                 (*(__IO uint32_t*)(0x4287021C))
#define SYSCFG_DBGCR_DBG_PCA_BIT                  (*(__IO uint32_t*)(0x42870220))
#define SYSCFG_DBGCR_DBG_TIM_BIT                  (*(__IO uint32_t*)(0x42870224))
#define SYSCFG_DBGCR_DBG_PWM_BIT                  (*(__IO uint32_t*)(0x42870228))
#define SYSCFG_DBGCR_DBG_UART_BIT                 (*(__IO uint32_t*)(0x4287022C))
#define SYSCFG_DBGCR_DBG_SPI_BIT                  (*(__IO uint32_t*)(0x42870230))
#define SYSCFG_DBGCR_DBG_TWI_BIT                  (*(__IO uint32_t*)(0x42870234))
#define SYSCFG_EFTEN_EFT_EN_BIT                   (*(__IO uint32_t*)(0x42872000))
#define RCC_CR_CSMON_BIT                          (*(__IO uint32_t*)(0x42878018))
#define RCC_CR_PLLON_BIT                          (*(__IO uint32_t*)(0x4287801C))
#define RCC_CR_PLLRDY_BIT                         (*(__I  uint32_t*)(0x42878020))
#define RCC_CR_HSEON_BIT                          (*(__IO uint32_t*)(0x42878024))
#define RCC_CR_HSERDY_BIT                         (*(__I  uint32_t*)(0x42878028))
#define RCC_CR_LSEON_BIT                          (*(__IO uint32_t*)(0x4287802C))
#define RCC_CR_LSERDY_BIT                         (*(__I  uint32_t*)(0x42878030))
#define RCC_CR_HSION_BIT                          (*(__IO uint32_t*)(0x42878034))
#define RCC_CR_HSIRDY_BIT                         (*(__I  uint32_t*)(0x42878038))
#define RCC_CR_LSION_BIT                          (*(__IO uint32_t*)(0x4287803C))
#define RCC_CR_LSIRDY_BIT                         (*(__I  uint32_t*)(0x42878040))
#define RCC_CFGR_PLLSW_BIT                        (*(__IO uint32_t*)(0x428780A4))
#define RCC_CFGR_PLLSRC_BIT                       (*(__IO uint32_t*)(0x428780CC))
#define RCC_CFGR_LSESPDUP_BIT                     (*(__IO uint32_t*)(0x428780D8))
#define RCC_CFGR_LSENOISEEN_BIT                   (*(__IO uint32_t*)(0x428780DC))
#define RCC_CFGR_HSIENREC_BIT                     (*(__IO uint32_t*)(0x428780E0))
#define RCC_CIENR_LSERDYIE_BIT                    (*(__IO uint32_t*)(0x42878108))
#define RCC_CIENR_HSERDYIE_BIT                    (*(__IO uint32_t*)(0x4287810C))
#define RCC_CIENR_PLLRDYIE_BIT                    (*(__IO uint32_t*)(0x42878110))
#define RCC_CISTR_LSERDYIF_BIT                    (*(__I  uint32_t*)(0x42878188))
#define RCC_CISTR_HSERDYIF_BIT                    (*(__I  uint32_t*)(0x4287818C))
#define RCC_CISTR_PLLRDYIF_BIT                    (*(__I  uint32_t*)(0x42878190))
#define RCC_CISTR_CSMLSEF_BIT                     (*(__I  uint32_t*)(0x42878194))
#define RCC_CISTR_CSMHSEF_BIT                     (*(__I  uint32_t*)(0x42878198))
#define RCC_CISTR_CSMPLLF_BIT                     (*(__I  uint32_t*)(0x4287819C))
#define RCC_CICLR_LSERDYC_BIT                     (*(__O  uint32_t*)(0x42878208))
#define RCC_CICLR_HSERDYC_BIT                     (*(__O  uint32_t*)(0x4287820C))
#define RCC_CICLR_PLLRDYC_BIT                     (*(__O  uint32_t*)(0x42878210))
#define RCC_CICLR_CSMC_BIT                        (*(__O  uint32_t*)(0x4287821C))
#define RCC_AHBRSTR_PCA0RST_BIT                   (*(__IO uint32_t*)(0x42878280))
#define RCC_AHBRSTR_PCA1RST_BIT                   (*(__IO uint32_t*)(0x42878284))
#define RCC_AHBRSTR_GPIORST_BIT                   (*(__IO uint32_t*)(0x42878288))
#define RCC_AHBRSTR_SYSCFGRST_BIT                 (*(__IO uint32_t*)(0x42878290))
#define RCC_AHBRSTR_DMARST_BIT                    (*(__IO uint32_t*)(0x42878294))
#define RCC_AHBRSTR_CRCRST_BIT                    (*(__IO uint32_t*)(0x42878298))
#define RCC_AHBRSTR_RAMBISTRST_BIT                (*(__IO uint32_t*)(0x4287829C))
#define RCC_AHBRSTR_NTESTRST_BIT                  (*(__IO uint32_t*)(0x428782A0))
#define RCC_APB1RSTR_UART0RST_BIT                 (*(__IO uint32_t*)(0x42878300))
#define RCC_APB1RSTR_UART1RST_BIT                 (*(__IO uint32_t*)(0x42878304))
#define RCC_APB1RSTR_UART2RST_BIT                 (*(__IO uint32_t*)(0x42878308))
#define RCC_APB1RSTR_UART3RST_BIT                 (*(__IO uint32_t*)(0x4287830C))
#define RCC_APB1RSTR_UART4RST_BIT                 (*(__IO uint32_t*)(0x42878310))
#define RCC_APB1RSTR_UART5RST_BIT                 (*(__IO uint32_t*)(0x42878314))
#define RCC_APB1RSTR_SPI0RST_BIT                  (*(__IO uint32_t*)(0x42878318))
#define RCC_APB1RSTR_SPI1RST_BIT                  (*(__IO uint32_t*)(0x4287831C))
#define RCC_APB1RSTR_TWI0RST_BIT                  (*(__IO uint32_t*)(0x42878320))
#define RCC_APB1RSTR_TWI1RST_BIT                  (*(__IO uint32_t*)(0x42878324))
#define RCC_APB1RSTR_AMOCRST_BIT                  (*(__IO uint32_t*)(0x42878328))
#define RCC_APB1RSTR_ADCRST_BIT                   (*(__IO uint32_t*)(0x4287832C))
#define RCC_APB1RSTR_LCDRST_BIT                   (*(__IO uint32_t*)(0x42878330))
#define RCC_APB1RSTR_LEDRST_BIT                   (*(__IO uint32_t*)(0x42878334))
#define RCC_APB1RSTR_TKRST_BIT                    (*(__IO uint32_t*)(0x42878338))
#define RCC_APB0RSTR_TIM5RST_BIT                  (*(__IO uint32_t*)(0x42878380))
#define RCC_APB0RSTR_TIM6RST_BIT                  (*(__IO uint32_t*)(0x42878384))
#define RCC_APB0RSTR_TIM7RST_BIT                  (*(__IO uint32_t*)(0x42878388))
#define RCC_APB0RSTR_TIM8RST_BIT                  (*(__IO uint32_t*)(0x4287838C))
#define RCC_APB0RSTR_PWM0RST_BIT                  (*(__IO uint32_t*)(0x42878390))
#define RCC_APB0RSTR_PWM1RST_BIT                  (*(__IO uint32_t*)(0x42878394))
#define RCC_APB0RSTR_PWM2RST_BIT                  (*(__IO uint32_t*)(0x42878398))
#define RCC_APB0RSTR_PWM3RST_BIT                  (*(__IO uint32_t*)(0x4287839C))
#define RCC_APB0RSTR_PCA2RST_BIT                  (*(__IO uint32_t*)(0x428783A0))
#define RCC_APB0RSTR_PCA3RST_BIT                  (*(__IO uint32_t*)(0x428783A4))
#define RCC_APB0RSTR_PCA4RST_BIT                  (*(__IO uint32_t*)(0x428783A8))
#define RCC_APB0RSTR_PCA5RST_BIT                  (*(__IO uint32_t*)(0x428783AC))
#define RCC_APB0RSTR_PCA6RST_BIT                  (*(__IO uint32_t*)(0x428783B0))
#define RCC_APB0RSTR_PCA7RST_BIT                  (*(__IO uint32_t*)(0x428783B4))
#define RCC_APB0RSTR_EXTIRST_BIT                  (*(__IO uint32_t*)(0x428783B8))
#define RCC_APB0RSTR_WWDTRST_BIT                  (*(__IO uint32_t*)(0x428783BC))
#define RCC_AHBENR_PCA0EN_BIT                     (*(__IO uint32_t*)(0x42878400))
#define RCC_AHBENR_PCA1EN_BIT                     (*(__IO uint32_t*)(0x42878404))
#define RCC_AHBENR_IOCLKEN_BIT                    (*(__IO uint32_t*)(0x42878408))
#define RCC_AHBENR_SYSCFGEN_BIT                   (*(__IO uint32_t*)(0x42878410))
#define RCC_AHBENR_DMAEN_BIT                      (*(__IO uint32_t*)(0x42878414))
#define RCC_AHBENR_CRCEN_BIT                      (*(__IO uint32_t*)(0x42878418))
#define RCC_AHBENR_RAMBISTEN_BIT                  (*(__IO uint32_t*)(0x4287841C))
#define RCC_AHBENR_NTESTEN_BIT                    (*(__IO uint32_t*)(0x42878420))
#define RCC_APB1ENR_UART0EN_BIT                   (*(__IO uint32_t*)(0x42878480))
#define RCC_APB1ENR_UART1EN_BIT                   (*(__IO uint32_t*)(0x42878484))
#define RCC_APB1ENR_UART2EN_BIT                   (*(__IO uint32_t*)(0x42878488))
#define RCC_APB1ENR_UART3EN_BIT                   (*(__IO uint32_t*)(0x4287848C))
#define RCC_APB1ENR_UART4EN_BIT                   (*(__IO uint32_t*)(0x42878490))
#define RCC_APB1ENR_UART5EN_BIT                   (*(__IO uint32_t*)(0x42878494))
#define RCC_APB1ENR_SPI0EN_BIT                    (*(__IO uint32_t*)(0x42878498))
#define RCC_APB1ENR_SPI1EN_BIT                    (*(__IO uint32_t*)(0x4287849C))
#define RCC_APB1ENR_TWI0EN_BIT                    (*(__IO uint32_t*)(0x428784A0))
#define RCC_APB1ENR_TWI1EN_BIT                    (*(__IO uint32_t*)(0x428784A4))
#define RCC_APB1ENR_AMOCEN_BIT                    (*(__IO uint32_t*)(0x428784A8))
#define RCC_APB1ENR_ADCEN_BIT                     (*(__IO uint32_t*)(0x428784AC))
#define RCC_APB1ENR_LCDEN_BIT                     (*(__IO uint32_t*)(0x428784B0))
#define RCC_APB1ENR_LEDEN_BIT                     (*(__IO uint32_t*)(0x428784B4))
#define RCC_APB1ENR_TKEN_BIT                      (*(__IO uint32_t*)(0x428784B8))
#define RCC_APB0ENR_TIM5EN_BIT                    (*(__IO uint32_t*)(0x42878500))
#define RCC_APB0ENR_TIM6EN_BIT                    (*(__IO uint32_t*)(0x42878504))
#define RCC_APB0ENR_TIM7EN_BIT                    (*(__IO uint32_t*)(0x42878508))
#define RCC_APB0ENR_TIM8EN_BIT                    (*(__IO uint32_t*)(0x4287850C))
#define RCC_APB0ENR_PWM0EN_BIT                    (*(__IO uint32_t*)(0x42878510))
#define RCC_APB0ENR_PWM1EN_BIT                    (*(__IO uint32_t*)(0x42878514))
#define RCC_APB0ENR_PWM2EN_BIT                    (*(__IO uint32_t*)(0x42878518))
#define RCC_APB0ENR_PWM3EN_BIT                    (*(__IO uint32_t*)(0x4287851C))
#define RCC_APB0ENR_PCA2EN_BIT                    (*(__IO uint32_t*)(0x42878520))
#define RCC_APB0ENR_PCA3EN_BIT                    (*(__IO uint32_t*)(0x42878524))
#define RCC_APB0ENR_PCA4EN_BIT                    (*(__IO uint32_t*)(0x42878528))
#define RCC_APB0ENR_PCA5EN_BIT                    (*(__IO uint32_t*)(0x4287852C))
#define RCC_APB0ENR_PCA6EN_BIT                    (*(__IO uint32_t*)(0x42878530))
#define RCC_APB0ENR_PCA7EN_BIT                    (*(__IO uint32_t*)(0x42878534))
#define RCC_APB0ENR_EXTIEN_BIT                    (*(__IO uint32_t*)(0x42878538))
#define RCC_APB0ENR_WWDTEN_BIT                    (*(__IO uint32_t*)(0x4287853C))
#define RCC_RSTSTR_PINRSTF_BIT                    (*(__I  uint32_t*)(0x42878580))
#define RCC_RSTSTR_LVRSTF_BIT                     (*(__I  uint32_t*)(0x42878584))
#define RCC_RSTSTR_PORSTF_BIT                     (*(__I  uint32_t*)(0x42878588))
#define RCC_RSTSTR_SWRSTF_BIT                     (*(__I  uint32_t*)(0x4287858C))
#define RCC_RSTSTR_IWDTRSTF_BIT                   (*(__I  uint32_t*)(0x42878590))
#define RCC_RSTSTR_WWDTRSTF_BIT                   (*(__I  uint32_t*)(0x42878594))
#define RCC_RSTSTR_LVRSTF2_BIT                    (*(__I  uint32_t*)(0x42878598))
#define RCC_RSTCLR_PINRSTFC_BIT                   (*(__O  uint32_t*)(0x42878600))
#define RCC_RSTCLR_LVRSTFC_BIT                    (*(__O  uint32_t*)(0x42878604))
#define RCC_RSTCLR_PORSTFC_BIT                    (*(__O  uint32_t*)(0x42878608))
#define RCC_RSTCLR_SWRSTFC_BIT                    (*(__O  uint32_t*)(0x4287860C))
#define RCC_RSTCLR_IWDTRSTFC_BIT                  (*(__O  uint32_t*)(0x42878610))
#define RCC_RSTCLR_WWDTRSTFC_BIT                  (*(__O  uint32_t*)(0x42878614))
#define RCC_RSTCLR_LVRSTF2C_BIT                   (*(__O  uint32_t*)(0x42878618))
#define RCC_HSICAL_TRIMRUN_BIT                    (*(__IO uint32_t*)(0x428786FC))
#define RCC_LSECR_DRIVEON_BIT                     (*(__IO uint32_t*)(0x42878800))
#define RCC_LSECR_CAPON_BIT                       (*(__IO uint32_t*)(0x42878804))
#define DMA_CCR_EN_BIT                           (*(__IO uint32_t*)(0x42880200))
#define DMA_CCR_TCIE_BIT                         (*(__IO uint32_t*)(0x42880204))
#define DMA_CCR_HTIE_BIT                         (*(__IO uint32_t*)(0x42880208))
#define DMA_CCR_BEIE_BIT                         (*(__IO uint32_t*)(0x4288020C))
#define DMA_CCR_TEIE_BIT                         (*(__IO uint32_t*)(0x42880210))
#define DMA_CCR_TRGMODE_BIT                      (*(__IO uint32_t*)(0x4288025C))
#define DMA_CCR1_EN_BIT                           (*(__IO uint32_t*)(0x42880600))
#define DMA_CCR1_TCIE_BIT                         (*(__IO uint32_t*)(0x42880604))
#define DMA_CCR1_HTIE_BIT                         (*(__IO uint32_t*)(0x42880608))
#define DMA_CCR1_BEIE_BIT                         (*(__IO uint32_t*)(0x4288060C))
#define DMA_CCR1_TEIE_BIT                         (*(__IO uint32_t*)(0x42880610))
#define DMA_CCR1_TRGMODE_BIT                      (*(__IO uint32_t*)(0x4288065C))
#define DMA_CCR2_EN_BIT                           (*(__IO uint32_t*)(0x42880A00))
#define DMA_CCR2_TCIE_BIT                         (*(__IO uint32_t*)(0x42880A04))
#define DMA_CCR2_HTIE_BIT                         (*(__IO uint32_t*)(0x42880A08))
#define DMA_CCR2_BEIE_BIT                         (*(__IO uint32_t*)(0x42880A0C))
#define DMA_CCR2_TEIE_BIT                         (*(__IO uint32_t*)(0x42880A10))
#define DMA_CCR2_TRGMODE_BIT                      (*(__IO uint32_t*)(0x42880A5C))
#define DMA_CCR3_EN_BIT                           (*(__IO uint32_t*)(0x42880E00))
#define DMA_CCR3_TCIE_BIT                         (*(__IO uint32_t*)(0x42880E04))
#define DMA_CCR3_HTIE_BIT                         (*(__IO uint32_t*)(0x42880E08))
#define DMA_CCR3_BEIE_BIT                         (*(__IO uint32_t*)(0x42880E0C))
#define DMA_CCR3_TEIE_BIT                         (*(__IO uint32_t*)(0x42880E10))
#define DMA_CCR3_TRGMODE_BIT                      (*(__IO uint32_t*)(0x42880E5C))
#define DMA_CCR4_EN_BIT                           (*(__IO uint32_t*)(0x42881200))
#define DMA_CCR4_TCIE_BIT                         (*(__IO uint32_t*)(0x42881204))
#define DMA_CCR4_HTIE_BIT                         (*(__IO uint32_t*)(0x42881208))
#define DMA_CCR4_BEIE_BIT                         (*(__IO uint32_t*)(0x4288120C))
#define DMA_CCR4_TEIE_BIT                         (*(__IO uint32_t*)(0x42881210))
#define DMA_CCR4_TRGMODE_BIT                      (*(__IO uint32_t*)(0x4288125C))
#define DMA_CCR5_EN_BIT                           (*(__IO uint32_t*)(0x42881600))
#define DMA_CCR5_TCIE_BIT                         (*(__IO uint32_t*)(0x42881604))
#define DMA_CCR5_HTIE_BIT                         (*(__IO uint32_t*)(0x42881608))
#define DMA_CCR5_BEIE_BIT                         (*(__IO uint32_t*)(0x4288160C))
#define DMA_CCR5_TEIE_BIT                         (*(__IO uint32_t*)(0x42881610))
#define DMA_CCR5_TRGMODE_BIT                      (*(__IO uint32_t*)(0x4288165C))
#define DMA_CCR6_EN_BIT                           (*(__IO uint32_t*)(0x42881A00))
#define DMA_CCR6_TCIE_BIT                         (*(__IO uint32_t*)(0x42881A04))
#define DMA_CCR6_HTIE_BIT                         (*(__IO uint32_t*)(0x42881A08))
#define DMA_CCR6_BEIE_BIT                         (*(__IO uint32_t*)(0x42881A0C))
#define DMA_CCR6_TEIE_BIT                         (*(__IO uint32_t*)(0x42881A10))
#define DMA_CCR6_TRGMODE_BIT                      (*(__IO uint32_t*)(0x42881A5C))
#define DMA_CCR7_EN_BIT                           (*(__IO uint32_t*)(0x42881E00))
#define DMA_CCR7_TCIE_BIT                         (*(__IO uint32_t*)(0x42881E04))
#define DMA_CCR7_HTIE_BIT                         (*(__IO uint32_t*)(0x42881E08))
#define DMA_CCR7_BEIE_BIT                         (*(__IO uint32_t*)(0x42881E0C))
#define DMA_CCR7_TEIE_BIT                         (*(__IO uint32_t*)(0x42881E10))
#define DMA_CCR7_TRGMODE_BIT                      (*(__IO uint32_t*)(0x42881E5C))
#define CRC_CR_RELOAD_BIT                         (*(__O  uint32_t*)(0x428A0080))
#define CRC_CR_COMPLW_BIT                         (*(__IO uint32_t*)(0x428A00A8))
#define CRC_CR_RBITW_BIT                          (*(__IO uint32_t*)(0x428A00AC))
#define CRC_CR_RBYTEW_BIT                         (*(__IO uint32_t*)(0x428A00B0))
#define CRC_CR_COMPLR_BIT                         (*(__IO uint32_t*)(0x428A00B4))
#define CRC_CR_RBITR_BIT                          (*(__IO uint32_t*)(0x428A00B8))
#define CRC_CR_RBYTER_BIT                         (*(__IO uint32_t*)(0x428A00BC))
#define RAMBIST_CFG_SEL_BIT                       (*(__IO uint32_t*)(0x428A80BC))
#define RAMBIST_CSR_MOD_BIT                       (*(__IO uint32_t*)(0x428A8140))
#define RAMBIST_CSR_BSY_BIT                       (*(__I  uint32_t*)(0x428A8144))
#define RAMBIST_CSR_ERR_BIT                       (*(__IO uint32_t*)(0x428A8148))
#define GPIOA_CFG_ODRVR_ODRVR0_BIT                (*(__IO uint32_t*)(0x42810180))
#define GPIOA_CFG_ODRVR_ODRVR1_BIT                (*(__IO uint32_t*)(0x42810188))
#define GPIOA_CFG_ODRVR_ODRVR2_BIT                (*(__IO uint32_t*)(0x42810190))
#define GPIOA_CFG_ODRVR_ODRVR3_BIT                (*(__IO uint32_t*)(0x42810198))
#define GPIOA_CFG_ODRVR_ODRVR4_BIT                (*(__IO uint32_t*)(0x428101A0))
#define GPIOA_CFG_ODRVR_ODRVR5_BIT                (*(__IO uint32_t*)(0x428101A8))
#define GPIOA_CFG_ODRVR_ODRVR6_BIT                (*(__IO uint32_t*)(0x428101B0))
#define GPIOA_CFG_ODRVR_ODRVR7_BIT                (*(__IO uint32_t*)(0x428101B8))
#define GPIOA_CFG_ODRVR_ODRVR8_BIT                (*(__IO uint32_t*)(0x428101C0))
#define GPIOA_CFG_ODRVR_ODRVR9_BIT                (*(__IO uint32_t*)(0x428101C8))
#define GPIOA_CFG_ODRVR_ODRVR10_BIT               (*(__IO uint32_t*)(0x428101D0))
#define GPIOA_CFG_ODRVR_ODRVR11_BIT               (*(__IO uint32_t*)(0x428101D8))
#define GPIOA_CFG_ODRVR_ODRVR12_BIT               (*(__IO uint32_t*)(0x428101E0))
#define GPIOA_CFG_ODRVR_ODRVR13_BIT               (*(__IO uint32_t*)(0x428101E8))
#define GPIOA_CFG_ODRVR_ODRVR14_BIT               (*(__IO uint32_t*)(0x428101F0))
#define GPIOA_CFG_ODRVR_ODRVR15_BIT               (*(__IO uint32_t*)(0x428101F8))
#define GPIOA_CFG_PUPDR_PHDR0_BIT                 (*(__IO uint32_t*)(0x42810200))
#define GPIOA_CFG_PUPDR_PLDR0_BIT                 (*(__IO uint32_t*)(0x42810204))
#define GPIOA_CFG_PUPDR_PHDR1_BIT                 (*(__IO uint32_t*)(0x42810208))
#define GPIOA_CFG_PUPDR_PLDR1_BIT                 (*(__IO uint32_t*)(0x4281020C))
#define GPIOA_CFG_PUPDR_PHDR2_BIT                 (*(__IO uint32_t*)(0x42810210))
#define GPIOA_CFG_PUPDR_PLDR2_BIT                 (*(__IO uint32_t*)(0x42810214))
#define GPIOA_CFG_PUPDR_PHDR3_BIT                 (*(__IO uint32_t*)(0x42810218))
#define GPIOA_CFG_PUPDR_PLDR3_BIT                 (*(__IO uint32_t*)(0x4281021C))
#define GPIOA_CFG_PUPDR_PHDR4_BIT                 (*(__IO uint32_t*)(0x42810220))
#define GPIOA_CFG_PUPDR_PLDR4_BIT                 (*(__IO uint32_t*)(0x42810224))
#define GPIOA_CFG_PUPDR_PHDR5_BIT                 (*(__IO uint32_t*)(0x42810228))
#define GPIOA_CFG_PUPDR_PLDR5_BIT                 (*(__IO uint32_t*)(0x4281022C))
#define GPIOA_CFG_PUPDR_PHDR6_BIT                 (*(__IO uint32_t*)(0x42810230))
#define GPIOA_CFG_PUPDR_PLDR6_BIT                 (*(__IO uint32_t*)(0x42810234))
#define GPIOA_CFG_PUPDR_PHDR7_BIT                 (*(__IO uint32_t*)(0x42810238))
#define GPIOA_CFG_PUPDR_PLDR7_BIT                 (*(__IO uint32_t*)(0x4281023C))
#define GPIOA_CFG_PUPDR_PHDR8_BIT                 (*(__IO uint32_t*)(0x42810240))
#define GPIOA_CFG_PUPDR_PLDR8_BIT                 (*(__IO uint32_t*)(0x42810244))
#define GPIOA_CFG_PUPDR_PHDR9_BIT                 (*(__IO uint32_t*)(0x42810248))
#define GPIOA_CFG_PUPDR_PLDR9_BIT                 (*(__IO uint32_t*)(0x4281024C))
#define GPIOA_CFG_PUPDR_PHDR10_BIT                (*(__IO uint32_t*)(0x42810250))
#define GPIOA_CFG_PUPDR_PLDR10_BIT                (*(__IO uint32_t*)(0x42810254))
#define GPIOA_CFG_PUPDR_PHDR11_BIT                (*(__IO uint32_t*)(0x42810258))
#define GPIOA_CFG_PUPDR_PLDR11_BIT                (*(__IO uint32_t*)(0x4281025C))
#define GPIOA_CFG_PUPDR_PHDR12_BIT                (*(__IO uint32_t*)(0x42810260))
#define GPIOA_CFG_PUPDR_PLDR12_BIT                (*(__IO uint32_t*)(0x42810264))
#define GPIOA_CFG_PUPDR_PHDR13_BIT                (*(__IO uint32_t*)(0x42810268))
#define GPIOA_CFG_PUPDR_PLDR13_BIT                (*(__IO uint32_t*)(0x4281026C))
#define GPIOA_CFG_PUPDR_PHDR14_BIT                (*(__IO uint32_t*)(0x42810270))
#define GPIOA_CFG_PUPDR_PLDR14_BIT                (*(__IO uint32_t*)(0x42810274))
#define GPIOA_CFG_PUPDR_PHDR15_BIT                (*(__IO uint32_t*)(0x42810278))
#define GPIOA_CFG_PUPDR_PLDR15_BIT                (*(__IO uint32_t*)(0x4281027C))
#define GPIOA_CFG_TTLEN_PA0_BIT                   (*(__IO uint32_t*)(0x42810280))
#define GPIOA_CFG_TTLEN_PA1_BIT                   (*(__IO uint32_t*)(0x42810284))
#define GPIOA_CFG_TTLEN_PA2_BIT                   (*(__IO uint32_t*)(0x42810288))
#define GPIOA_CFG_TTLEN_PA3_BIT                   (*(__IO uint32_t*)(0x4281028C))
#define GPIOA_CFG_TTLEN_PA4_BIT                   (*(__IO uint32_t*)(0x42810290))
#define GPIOA_CFG_TTLEN_PA5_BIT                   (*(__IO uint32_t*)(0x42810294))
#define GPIOA_CFG_TTLEN_PA6_BIT                   (*(__IO uint32_t*)(0x42810298))
#define GPIOA_CFG_TTLEN_PA7_BIT                   (*(__IO uint32_t*)(0x4281029C))
#define GPIOA_CFG_TTLEN_PA8_BIT                   (*(__IO uint32_t*)(0x428102A0))
#define GPIOA_CFG_TTLEN_PA9_BIT                   (*(__IO uint32_t*)(0x428102A4))
#define GPIOA_CFG_TTLEN_PA10_BIT                  (*(__IO uint32_t*)(0x428102A8))
#define GPIOA_CFG_TTLEN_PA11_BIT                  (*(__IO uint32_t*)(0x428102AC))
#define GPIOA_CFG_TTLEN_PA12_BIT                  (*(__IO uint32_t*)(0x428102B0))
#define GPIOA_CFG_TTLEN_PA13_BIT                  (*(__IO uint32_t*)(0x428102B4))
#define GPIOA_CFG_TTLEN_PA14_BIT                  (*(__IO uint32_t*)(0x428102B8))
#define GPIOA_CFG_TTLEN_PA15_BIT                  (*(__IO uint32_t*)(0x428102BC))
#define GPIOB_CFG_ODRVR_ODRVR0_BIT                (*(__IO uint32_t*)(0x42810580))
#define GPIOB_CFG_ODRVR_ODRVR1_BIT                (*(__IO uint32_t*)(0x42810588))
#define GPIOB_CFG_ODRVR_ODRVR2_BIT                (*(__IO uint32_t*)(0x42810590))
#define GPIOB_CFG_ODRVR_ODRVR3_BIT                (*(__IO uint32_t*)(0x42810598))
#define GPIOB_CFG_ODRVR_ODRVR4_BIT                (*(__IO uint32_t*)(0x428105A0))
#define GPIOB_CFG_ODRVR_ODRVR5_BIT                (*(__IO uint32_t*)(0x428105A8))
#define GPIOB_CFG_ODRVR_ODRVR6_BIT                (*(__IO uint32_t*)(0x428105B0))
#define GPIOB_CFG_ODRVR_ODRVR7_BIT                (*(__IO uint32_t*)(0x428105B8))
#define GPIOB_CFG_ODRVR_ODRVR8_BIT                (*(__IO uint32_t*)(0x428105C0))
#define GPIOB_CFG_ODRVR_ODRVR9_BIT                (*(__IO uint32_t*)(0x428105C8))
#define GPIOB_CFG_ODRVR_ODRVR10_BIT               (*(__IO uint32_t*)(0x428105D0))
#define GPIOB_CFG_ODRVR_ODRVR11_BIT               (*(__IO uint32_t*)(0x428105D8))
#define GPIOB_CFG_ODRVR_ODRVR12_BIT               (*(__IO uint32_t*)(0x428105E0))
#define GPIOB_CFG_ODRVR_ODRVR13_BIT               (*(__IO uint32_t*)(0x428105E8))
#define GPIOB_CFG_ODRVR_ODRVR14_BIT               (*(__IO uint32_t*)(0x428105F0))
#define GPIOB_CFG_ODRVR_ODRVR15_BIT               (*(__IO uint32_t*)(0x428105F8))
#define GPIOB_CFG_PUPDR_PHDR0_BIT                 (*(__IO uint32_t*)(0x42810600))
#define GPIOB_CFG_PUPDR_PLDR0_BIT                 (*(__IO uint32_t*)(0x42810604))
#define GPIOB_CFG_PUPDR_PHDR1_BIT                 (*(__IO uint32_t*)(0x42810608))
#define GPIOB_CFG_PUPDR_PLDR1_BIT                 (*(__IO uint32_t*)(0x4281060C))
#define GPIOB_CFG_PUPDR_PHDR2_BIT                 (*(__IO uint32_t*)(0x42810610))
#define GPIOB_CFG_PUPDR_PLDR2_BIT                 (*(__IO uint32_t*)(0x42810614))
#define GPIOB_CFG_PUPDR_PHDR3_BIT                 (*(__IO uint32_t*)(0x42810618))
#define GPIOB_CFG_PUPDR_PLDR3_BIT                 (*(__IO uint32_t*)(0x4281061C))
#define GPIOB_CFG_PUPDR_PHDR4_BIT                 (*(__IO uint32_t*)(0x42810620))
#define GPIOB_CFG_PUPDR_PLDR4_BIT                 (*(__IO uint32_t*)(0x42810624))
#define GPIOB_CFG_PUPDR_PHDR5_BIT                 (*(__IO uint32_t*)(0x42810628))
#define GPIOB_CFG_PUPDR_PLDR5_BIT                 (*(__IO uint32_t*)(0x4281062C))
#define GPIOB_CFG_PUPDR_PHDR6_BIT                 (*(__IO uint32_t*)(0x42810630))
#define GPIOB_CFG_PUPDR_PLDR6_BIT                 (*(__IO uint32_t*)(0x42810634))
#define GPIOB_CFG_PUPDR_PHDR7_BIT                 (*(__IO uint32_t*)(0x42810638))
#define GPIOB_CFG_PUPDR_PLDR7_BIT                 (*(__IO uint32_t*)(0x4281063C))
#define GPIOB_CFG_PUPDR_PHDR8_BIT                 (*(__IO uint32_t*)(0x42810640))
#define GPIOB_CFG_PUPDR_PLDR8_BIT                 (*(__IO uint32_t*)(0x42810644))
#define GPIOB_CFG_PUPDR_PHDR9_BIT                 (*(__IO uint32_t*)(0x42810648))
#define GPIOB_CFG_PUPDR_PLDR9_BIT                 (*(__IO uint32_t*)(0x4281064C))
#define GPIOB_CFG_PUPDR_PHDR10_BIT                (*(__IO uint32_t*)(0x42810650))
#define GPIOB_CFG_PUPDR_PLDR10_BIT                (*(__IO uint32_t*)(0x42810654))
#define GPIOB_CFG_PUPDR_PHDR11_BIT                (*(__IO uint32_t*)(0x42810658))
#define GPIOB_CFG_PUPDR_PLDR11_BIT                (*(__IO uint32_t*)(0x4281065C))
#define GPIOB_CFG_PUPDR_PHDR12_BIT                (*(__IO uint32_t*)(0x42810660))
#define GPIOB_CFG_PUPDR_PLDR12_BIT                (*(__IO uint32_t*)(0x42810664))
#define GPIOB_CFG_PUPDR_PHDR13_BIT                (*(__IO uint32_t*)(0x42810668))
#define GPIOB_CFG_PUPDR_PLDR13_BIT                (*(__IO uint32_t*)(0x4281066C))
#define GPIOB_CFG_PUPDR_PHDR14_BIT                (*(__IO uint32_t*)(0x42810670))
#define GPIOB_CFG_PUPDR_PLDR14_BIT                (*(__IO uint32_t*)(0x42810674))
#define GPIOB_CFG_PUPDR_PHDR15_BIT                (*(__IO uint32_t*)(0x42810678))
#define GPIOB_CFG_PUPDR_PLDR15_BIT                (*(__IO uint32_t*)(0x4281067C))
#define GPIOB_CFG_TTLEN_PA0_BIT                   (*(__IO uint32_t*)(0x42810680))
#define GPIOB_CFG_TTLEN_PA1_BIT                   (*(__IO uint32_t*)(0x42810684))
#define GPIOB_CFG_TTLEN_PA2_BIT                   (*(__IO uint32_t*)(0x42810688))
#define GPIOB_CFG_TTLEN_PA3_BIT                   (*(__IO uint32_t*)(0x4281068C))
#define GPIOB_CFG_TTLEN_PA4_BIT                   (*(__IO uint32_t*)(0x42810690))
#define GPIOB_CFG_TTLEN_PA5_BIT                   (*(__IO uint32_t*)(0x42810694))
#define GPIOB_CFG_TTLEN_PA6_BIT                   (*(__IO uint32_t*)(0x42810698))
#define GPIOB_CFG_TTLEN_PA7_BIT                   (*(__IO uint32_t*)(0x4281069C))
#define GPIOB_CFG_TTLEN_PA8_BIT                   (*(__IO uint32_t*)(0x428106A0))
#define GPIOB_CFG_TTLEN_PA9_BIT                   (*(__IO uint32_t*)(0x428106A4))
#define GPIOB_CFG_TTLEN_PA10_BIT                  (*(__IO uint32_t*)(0x428106A8))
#define GPIOB_CFG_TTLEN_PA11_BIT                  (*(__IO uint32_t*)(0x428106AC))
#define GPIOB_CFG_TTLEN_PA12_BIT                  (*(__IO uint32_t*)(0x428106B0))
#define GPIOB_CFG_TTLEN_PA13_BIT                  (*(__IO uint32_t*)(0x428106B4))
#define GPIOB_CFG_TTLEN_PA14_BIT                  (*(__IO uint32_t*)(0x428106B8))
#define GPIOB_CFG_TTLEN_PA15_BIT                  (*(__IO uint32_t*)(0x428106BC))
#define GPIOC_CFG_ODRVR_ODRVR0_BIT                (*(__IO uint32_t*)(0x42810980))
#define GPIOC_CFG_ODRVR_ODRVR1_BIT                (*(__IO uint32_t*)(0x42810988))
#define GPIOC_CFG_ODRVR_ODRVR2_BIT                (*(__IO uint32_t*)(0x42810990))
#define GPIOC_CFG_ODRVR_ODRVR3_BIT                (*(__IO uint32_t*)(0x42810998))
#define GPIOC_CFG_ODRVR_ODRVR4_BIT                (*(__IO uint32_t*)(0x428109A0))
#define GPIOC_CFG_ODRVR_ODRVR5_BIT                (*(__IO uint32_t*)(0x428109A8))
#define GPIOC_CFG_ODRVR_ODRVR6_BIT                (*(__IO uint32_t*)(0x428109B0))
#define GPIOC_CFG_ODRVR_ODRVR7_BIT                (*(__IO uint32_t*)(0x428109B8))
#define GPIOC_CFG_ODRVR_ODRVR8_BIT                (*(__IO uint32_t*)(0x428109C0))
#define GPIOC_CFG_ODRVR_ODRVR9_BIT                (*(__IO uint32_t*)(0x428109C8))
#define GPIOC_CFG_ODRVR_ODRVR10_BIT               (*(__IO uint32_t*)(0x428109D0))
#define GPIOC_CFG_ODRVR_ODRVR11_BIT               (*(__IO uint32_t*)(0x428109D8))
#define GPIOC_CFG_ODRVR_ODRVR12_BIT               (*(__IO uint32_t*)(0x428109E0))
#define GPIOC_CFG_ODRVR_ODRVR13_BIT               (*(__IO uint32_t*)(0x428109E8))
#define GPIOC_CFG_ODRVR_ODRVR14_BIT               (*(__IO uint32_t*)(0x428109F0))
#define GPIOC_CFG_ODRVR_ODRVR15_BIT               (*(__IO uint32_t*)(0x428109F8))
#define GPIOC_CFG_PUPDR_PHDR0_BIT                 (*(__IO uint32_t*)(0x42810A00))
#define GPIOC_CFG_PUPDR_PLDR0_BIT                 (*(__IO uint32_t*)(0x42810A04))
#define GPIOC_CFG_PUPDR_PHDR1_BIT                 (*(__IO uint32_t*)(0x42810A08))
#define GPIOC_CFG_PUPDR_PLDR1_BIT                 (*(__IO uint32_t*)(0x42810A0C))
#define GPIOC_CFG_PUPDR_PHDR2_BIT                 (*(__IO uint32_t*)(0x42810A10))
#define GPIOC_CFG_PUPDR_PLDR2_BIT                 (*(__IO uint32_t*)(0x42810A14))
#define GPIOC_CFG_PUPDR_PHDR3_BIT                 (*(__IO uint32_t*)(0x42810A18))
#define GPIOC_CFG_PUPDR_PLDR3_BIT                 (*(__IO uint32_t*)(0x42810A1C))
#define GPIOC_CFG_PUPDR_PHDR4_BIT                 (*(__IO uint32_t*)(0x42810A20))
#define GPIOC_CFG_PUPDR_PLDR4_BIT                 (*(__IO uint32_t*)(0x42810A24))
#define GPIOC_CFG_PUPDR_PHDR5_BIT                 (*(__IO uint32_t*)(0x42810A28))
#define GPIOC_CFG_PUPDR_PLDR5_BIT                 (*(__IO uint32_t*)(0x42810A2C))
#define GPIOC_CFG_PUPDR_PHDR6_BIT                 (*(__IO uint32_t*)(0x42810A30))
#define GPIOC_CFG_PUPDR_PLDR6_BIT                 (*(__IO uint32_t*)(0x42810A34))
#define GPIOC_CFG_PUPDR_PHDR7_BIT                 (*(__IO uint32_t*)(0x42810A38))
#define GPIOC_CFG_PUPDR_PLDR7_BIT                 (*(__IO uint32_t*)(0x42810A3C))
#define GPIOC_CFG_PUPDR_PHDR8_BIT                 (*(__IO uint32_t*)(0x42810A40))
#define GPIOC_CFG_PUPDR_PLDR8_BIT                 (*(__IO uint32_t*)(0x42810A44))
#define GPIOC_CFG_PUPDR_PHDR9_BIT                 (*(__IO uint32_t*)(0x42810A48))
#define GPIOC_CFG_PUPDR_PLDR9_BIT                 (*(__IO uint32_t*)(0x42810A4C))
#define GPIOC_CFG_PUPDR_PHDR10_BIT                (*(__IO uint32_t*)(0x42810A50))
#define GPIOC_CFG_PUPDR_PLDR10_BIT                (*(__IO uint32_t*)(0x42810A54))
#define GPIOC_CFG_PUPDR_PHDR11_BIT                (*(__IO uint32_t*)(0x42810A58))
#define GPIOC_CFG_PUPDR_PLDR11_BIT                (*(__IO uint32_t*)(0x42810A5C))
#define GPIOC_CFG_PUPDR_PHDR12_BIT                (*(__IO uint32_t*)(0x42810A60))
#define GPIOC_CFG_PUPDR_PLDR12_BIT                (*(__IO uint32_t*)(0x42810A64))
#define GPIOC_CFG_PUPDR_PHDR13_BIT                (*(__IO uint32_t*)(0x42810A68))
#define GPIOC_CFG_PUPDR_PLDR13_BIT                (*(__IO uint32_t*)(0x42810A6C))
#define GPIOC_CFG_PUPDR_PHDR14_BIT                (*(__IO uint32_t*)(0x42810A70))
#define GPIOC_CFG_PUPDR_PLDR14_BIT                (*(__IO uint32_t*)(0x42810A74))
#define GPIOC_CFG_PUPDR_PHDR15_BIT                (*(__IO uint32_t*)(0x42810A78))
#define GPIOC_CFG_PUPDR_PLDR15_BIT                (*(__IO uint32_t*)(0x42810A7C))
#define GPIOC_CFG_TTLEN_PA0_BIT                   (*(__IO uint32_t*)(0x42810A80))
#define GPIOC_CFG_TTLEN_PA1_BIT                   (*(__IO uint32_t*)(0x42810A84))
#define GPIOC_CFG_TTLEN_PA2_BIT                   (*(__IO uint32_t*)(0x42810A88))
#define GPIOC_CFG_TTLEN_PA3_BIT                   (*(__IO uint32_t*)(0x42810A8C))
#define GPIOC_CFG_TTLEN_PA4_BIT                   (*(__IO uint32_t*)(0x42810A90))
#define GPIOC_CFG_TTLEN_PA5_BIT                   (*(__IO uint32_t*)(0x42810A94))
#define GPIOC_CFG_TTLEN_PA6_BIT                   (*(__IO uint32_t*)(0x42810A98))
#define GPIOC_CFG_TTLEN_PA7_BIT                   (*(__IO uint32_t*)(0x42810A9C))
#define GPIOC_CFG_TTLEN_PA8_BIT                   (*(__IO uint32_t*)(0x42810AA0))
#define GPIOC_CFG_TTLEN_PA9_BIT                   (*(__IO uint32_t*)(0x42810AA4))
#define GPIOC_CFG_TTLEN_PA10_BIT                  (*(__IO uint32_t*)(0x42810AA8))
#define GPIOC_CFG_TTLEN_PA11_BIT                  (*(__IO uint32_t*)(0x42810AAC))
#define GPIOC_CFG_TTLEN_PA12_BIT                  (*(__IO uint32_t*)(0x42810AB0))
#define GPIOC_CFG_TTLEN_PA13_BIT                  (*(__IO uint32_t*)(0x42810AB4))
#define GPIOC_CFG_TTLEN_PA14_BIT                  (*(__IO uint32_t*)(0x42810AB8))
#define GPIOC_CFG_TTLEN_PA15_BIT                  (*(__IO uint32_t*)(0x42810ABC))
#define GPIOD_CFG_ODRVR_ODRVR0_BIT                (*(__IO uint32_t*)(0x42810D80))
#define GPIOD_CFG_ODRVR_ODRVR1_BIT                (*(__IO uint32_t*)(0x42810D88))
#define GPIOD_CFG_ODRVR_ODRVR2_BIT                (*(__IO uint32_t*)(0x42810D90))
#define GPIOD_CFG_ODRVR_ODRVR3_BIT                (*(__IO uint32_t*)(0x42810D98))
#define GPIOD_CFG_ODRVR_ODRVR4_BIT                (*(__IO uint32_t*)(0x42810DA0))
#define GPIOD_CFG_ODRVR_ODRVR5_BIT                (*(__IO uint32_t*)(0x42810DA8))
#define GPIOD_CFG_ODRVR_ODRVR6_BIT                (*(__IO uint32_t*)(0x42810DB0))
#define GPIOD_CFG_ODRVR_ODRVR7_BIT                (*(__IO uint32_t*)(0x42810DB8))
#define GPIOD_CFG_ODRVR_ODRVR8_BIT                (*(__IO uint32_t*)(0x42810DC0))
#define GPIOD_CFG_ODRVR_ODRVR9_BIT                (*(__IO uint32_t*)(0x42810DC8))
#define GPIOD_CFG_ODRVR_ODRVR10_BIT               (*(__IO uint32_t*)(0x42810DD0))
#define GPIOD_CFG_ODRVR_ODRVR11_BIT               (*(__IO uint32_t*)(0x42810DD8))
#define GPIOD_CFG_ODRVR_ODRVR12_BIT               (*(__IO uint32_t*)(0x42810DE0))
#define GPIOD_CFG_ODRVR_ODRVR13_BIT               (*(__IO uint32_t*)(0x42810DE8))
#define GPIOD_CFG_ODRVR_ODRVR14_BIT               (*(__IO uint32_t*)(0x42810DF0))
#define GPIOD_CFG_ODRVR_ODRVR15_BIT               (*(__IO uint32_t*)(0x42810DF8))
#define GPIOD_CFG_PUPDR_PHDR0_BIT                 (*(__IO uint32_t*)(0x42810E00))
#define GPIOD_CFG_PUPDR_PLDR0_BIT                 (*(__IO uint32_t*)(0x42810E04))
#define GPIOD_CFG_PUPDR_PHDR1_BIT                 (*(__IO uint32_t*)(0x42810E08))
#define GPIOD_CFG_PUPDR_PLDR1_BIT                 (*(__IO uint32_t*)(0x42810E0C))
#define GPIOD_CFG_PUPDR_PHDR2_BIT                 (*(__IO uint32_t*)(0x42810E10))
#define GPIOD_CFG_PUPDR_PLDR2_BIT                 (*(__IO uint32_t*)(0x42810E14))
#define GPIOD_CFG_PUPDR_PHDR3_BIT                 (*(__IO uint32_t*)(0x42810E18))
#define GPIOD_CFG_PUPDR_PLDR3_BIT                 (*(__IO uint32_t*)(0x42810E1C))
#define GPIOD_CFG_PUPDR_PHDR4_BIT                 (*(__IO uint32_t*)(0x42810E20))
#define GPIOD_CFG_PUPDR_PLDR4_BIT                 (*(__IO uint32_t*)(0x42810E24))
#define GPIOD_CFG_PUPDR_PHDR5_BIT                 (*(__IO uint32_t*)(0x42810E28))
#define GPIOD_CFG_PUPDR_PLDR5_BIT                 (*(__IO uint32_t*)(0x42810E2C))
#define GPIOD_CFG_PUPDR_PHDR6_BIT                 (*(__IO uint32_t*)(0x42810E30))
#define GPIOD_CFG_PUPDR_PLDR6_BIT                 (*(__IO uint32_t*)(0x42810E34))
#define GPIOD_CFG_PUPDR_PHDR7_BIT                 (*(__IO uint32_t*)(0x42810E38))
#define GPIOD_CFG_PUPDR_PLDR7_BIT                 (*(__IO uint32_t*)(0x42810E3C))
#define GPIOD_CFG_PUPDR_PHDR8_BIT                 (*(__IO uint32_t*)(0x42810E40))
#define GPIOD_CFG_PUPDR_PLDR8_BIT                 (*(__IO uint32_t*)(0x42810E44))
#define GPIOD_CFG_PUPDR_PHDR9_BIT                 (*(__IO uint32_t*)(0x42810E48))
#define GPIOD_CFG_PUPDR_PLDR9_BIT                 (*(__IO uint32_t*)(0x42810E4C))
#define GPIOD_CFG_PUPDR_PHDR10_BIT                (*(__IO uint32_t*)(0x42810E50))
#define GPIOD_CFG_PUPDR_PLDR10_BIT                (*(__IO uint32_t*)(0x42810E54))
#define GPIOD_CFG_PUPDR_PHDR11_BIT                (*(__IO uint32_t*)(0x42810E58))
#define GPIOD_CFG_PUPDR_PLDR11_BIT                (*(__IO uint32_t*)(0x42810E5C))
#define GPIOD_CFG_PUPDR_PHDR12_BIT                (*(__IO uint32_t*)(0x42810E60))
#define GPIOD_CFG_PUPDR_PLDR12_BIT                (*(__IO uint32_t*)(0x42810E64))
#define GPIOD_CFG_PUPDR_PHDR13_BIT                (*(__IO uint32_t*)(0x42810E68))
#define GPIOD_CFG_PUPDR_PLDR13_BIT                (*(__IO uint32_t*)(0x42810E6C))
#define GPIOD_CFG_PUPDR_PHDR14_BIT                (*(__IO uint32_t*)(0x42810E70))
#define GPIOD_CFG_PUPDR_PLDR14_BIT                (*(__IO uint32_t*)(0x42810E74))
#define GPIOD_CFG_PUPDR_PHDR15_BIT                (*(__IO uint32_t*)(0x42810E78))
#define GPIOD_CFG_PUPDR_PLDR15_BIT                (*(__IO uint32_t*)(0x42810E7C))
#define GPIOD_CFG_TTLEN_PA0_BIT                   (*(__IO uint32_t*)(0x42810E80))
#define GPIOD_CFG_TTLEN_PA1_BIT                   (*(__IO uint32_t*)(0x42810E84))
#define GPIOD_CFG_TTLEN_PA2_BIT                   (*(__IO uint32_t*)(0x42810E88))
#define GPIOD_CFG_TTLEN_PA3_BIT                   (*(__IO uint32_t*)(0x42810E8C))
#define GPIOD_CFG_TTLEN_PA4_BIT                   (*(__IO uint32_t*)(0x42810E90))
#define GPIOD_CFG_TTLEN_PA5_BIT                   (*(__IO uint32_t*)(0x42810E94))
#define GPIOD_CFG_TTLEN_PA6_BIT                   (*(__IO uint32_t*)(0x42810E98))
#define GPIOD_CFG_TTLEN_PA7_BIT                   (*(__IO uint32_t*)(0x42810E9C))
#define GPIOD_CFG_TTLEN_PA8_BIT                   (*(__IO uint32_t*)(0x42810EA0))
#define GPIOD_CFG_TTLEN_PA9_BIT                   (*(__IO uint32_t*)(0x42810EA4))
#define GPIOD_CFG_TTLEN_PA10_BIT                  (*(__IO uint32_t*)(0x42810EA8))
#define GPIOD_CFG_TTLEN_PA11_BIT                  (*(__IO uint32_t*)(0x42810EAC))
#define GPIOD_CFG_TTLEN_PA12_BIT                  (*(__IO uint32_t*)(0x42810EB0))
#define GPIOD_CFG_TTLEN_PA13_BIT                  (*(__IO uint32_t*)(0x42810EB4))
#define GPIOD_CFG_TTLEN_PA14_BIT                  (*(__IO uint32_t*)(0x42810EB8))
#define GPIOD_CFG_TTLEN_PA15_BIT                  (*(__IO uint32_t*)(0x42810EBC))
#define GPIOE_CFG_ODRVR_ODRVR0_BIT                (*(__IO uint32_t*)(0x42811180))
#define GPIOE_CFG_ODRVR_ODRVR1_BIT                (*(__IO uint32_t*)(0x42811188))
#define GPIOE_CFG_ODRVR_ODRVR2_BIT                (*(__IO uint32_t*)(0x42811190))
#define GPIOE_CFG_ODRVR_ODRVR3_BIT                (*(__IO uint32_t*)(0x42811198))
#define GPIOE_CFG_ODRVR_ODRVR4_BIT                (*(__IO uint32_t*)(0x428111A0))
#define GPIOE_CFG_ODRVR_ODRVR5_BIT                (*(__IO uint32_t*)(0x428111A8))
#define GPIOE_CFG_ODRVR_ODRVR6_BIT                (*(__IO uint32_t*)(0x428111B0))
#define GPIOE_CFG_ODRVR_ODRVR7_BIT                (*(__IO uint32_t*)(0x428111B8))
#define GPIOE_CFG_ODRVR_ODRVR8_BIT                (*(__IO uint32_t*)(0x428111C0))
#define GPIOE_CFG_ODRVR_ODRVR9_BIT                (*(__IO uint32_t*)(0x428111C8))
#define GPIOE_CFG_ODRVR_ODRVR10_BIT               (*(__IO uint32_t*)(0x428111D0))
#define GPIOE_CFG_ODRVR_ODRVR11_BIT               (*(__IO uint32_t*)(0x428111D8))
#define GPIOE_CFG_ODRVR_ODRVR12_BIT               (*(__IO uint32_t*)(0x428111E0))
#define GPIOE_CFG_ODRVR_ODRVR13_BIT               (*(__IO uint32_t*)(0x428111E8))
#define GPIOE_CFG_ODRVR_ODRVR14_BIT               (*(__IO uint32_t*)(0x428111F0))
#define GPIOE_CFG_ODRVR_ODRVR15_BIT               (*(__IO uint32_t*)(0x428111F8))
#define GPIOE_CFG_PUPDR_PHDR0_BIT                 (*(__IO uint32_t*)(0x42811200))
#define GPIOE_CFG_PUPDR_PLDR0_BIT                 (*(__IO uint32_t*)(0x42811204))
#define GPIOE_CFG_PUPDR_PHDR1_BIT                 (*(__IO uint32_t*)(0x42811208))
#define GPIOE_CFG_PUPDR_PLDR1_BIT                 (*(__IO uint32_t*)(0x4281120C))
#define GPIOE_CFG_PUPDR_PHDR2_BIT                 (*(__IO uint32_t*)(0x42811210))
#define GPIOE_CFG_PUPDR_PLDR2_BIT                 (*(__IO uint32_t*)(0x42811214))
#define GPIOE_CFG_PUPDR_PHDR3_BIT                 (*(__IO uint32_t*)(0x42811218))
#define GPIOE_CFG_PUPDR_PLDR3_BIT                 (*(__IO uint32_t*)(0x4281121C))
#define GPIOE_CFG_PUPDR_PHDR4_BIT                 (*(__IO uint32_t*)(0x42811220))
#define GPIOE_CFG_PUPDR_PLDR4_BIT                 (*(__IO uint32_t*)(0x42811224))
#define GPIOE_CFG_PUPDR_PHDR5_BIT                 (*(__IO uint32_t*)(0x42811228))
#define GPIOE_CFG_PUPDR_PLDR5_BIT                 (*(__IO uint32_t*)(0x4281122C))
#define GPIOE_CFG_PUPDR_PHDR6_BIT                 (*(__IO uint32_t*)(0x42811230))
#define GPIOE_CFG_PUPDR_PLDR6_BIT                 (*(__IO uint32_t*)(0x42811234))
#define GPIOE_CFG_PUPDR_PHDR7_BIT                 (*(__IO uint32_t*)(0x42811238))
#define GPIOE_CFG_PUPDR_PLDR7_BIT                 (*(__IO uint32_t*)(0x4281123C))
#define GPIOE_CFG_PUPDR_PHDR8_BIT                 (*(__IO uint32_t*)(0x42811240))
#define GPIOE_CFG_PUPDR_PLDR8_BIT                 (*(__IO uint32_t*)(0x42811244))
#define GPIOE_CFG_PUPDR_PHDR9_BIT                 (*(__IO uint32_t*)(0x42811248))
#define GPIOE_CFG_PUPDR_PLDR9_BIT                 (*(__IO uint32_t*)(0x4281124C))
#define GPIOE_CFG_PUPDR_PHDR10_BIT                (*(__IO uint32_t*)(0x42811250))
#define GPIOE_CFG_PUPDR_PLDR10_BIT                (*(__IO uint32_t*)(0x42811254))
#define GPIOE_CFG_PUPDR_PHDR11_BIT                (*(__IO uint32_t*)(0x42811258))
#define GPIOE_CFG_PUPDR_PLDR11_BIT                (*(__IO uint32_t*)(0x4281125C))
#define GPIOE_CFG_PUPDR_PHDR12_BIT                (*(__IO uint32_t*)(0x42811260))
#define GPIOE_CFG_PUPDR_PLDR12_BIT                (*(__IO uint32_t*)(0x42811264))
#define GPIOE_CFG_PUPDR_PHDR13_BIT                (*(__IO uint32_t*)(0x42811268))
#define GPIOE_CFG_PUPDR_PLDR13_BIT                (*(__IO uint32_t*)(0x4281126C))
#define GPIOE_CFG_PUPDR_PHDR14_BIT                (*(__IO uint32_t*)(0x42811270))
#define GPIOE_CFG_PUPDR_PLDR14_BIT                (*(__IO uint32_t*)(0x42811274))
#define GPIOE_CFG_PUPDR_PHDR15_BIT                (*(__IO uint32_t*)(0x42811278))
#define GPIOE_CFG_PUPDR_PLDR15_BIT                (*(__IO uint32_t*)(0x4281127C))
#define GPIOE_CFG_TTLEN_PA0_BIT                   (*(__IO uint32_t*)(0x42811280))
#define GPIOE_CFG_TTLEN_PA1_BIT                   (*(__IO uint32_t*)(0x42811284))
#define GPIOE_CFG_TTLEN_PA2_BIT                   (*(__IO uint32_t*)(0x42811288))
#define GPIOE_CFG_TTLEN_PA3_BIT                   (*(__IO uint32_t*)(0x4281128C))
#define GPIOE_CFG_TTLEN_PA4_BIT                   (*(__IO uint32_t*)(0x42811290))
#define GPIOE_CFG_TTLEN_PA5_BIT                   (*(__IO uint32_t*)(0x42811294))
#define GPIOE_CFG_TTLEN_PA6_BIT                   (*(__IO uint32_t*)(0x42811298))
#define GPIOE_CFG_TTLEN_PA7_BIT                   (*(__IO uint32_t*)(0x4281129C))
#define GPIOE_CFG_TTLEN_PA8_BIT                   (*(__IO uint32_t*)(0x428112A0))
#define GPIOE_CFG_TTLEN_PA9_BIT                   (*(__IO uint32_t*)(0x428112A4))
#define GPIOE_CFG_TTLEN_PA10_BIT                  (*(__IO uint32_t*)(0x428112A8))
#define GPIOE_CFG_TTLEN_PA11_BIT                  (*(__IO uint32_t*)(0x428112AC))
#define GPIOE_CFG_TTLEN_PA12_BIT                  (*(__IO uint32_t*)(0x428112B0))
#define GPIOE_CFG_TTLEN_PA13_BIT                  (*(__IO uint32_t*)(0x428112B4))
#define GPIOE_CFG_TTLEN_PA14_BIT                  (*(__IO uint32_t*)(0x428112B8))
#define GPIOE_CFG_TTLEN_PA15_BIT                  (*(__IO uint32_t*)(0x428112BC))
#define PCA0_CR_PR_BIT                            (*(__IO uint32_t*)(0x42800000))
#define PCA0_CR_CASCEN_BIT                        (*(__IO uint32_t*)(0x42800004))
#define PCA0_CMD_SDEN_BIT                         (*(__IO uint32_t*)(0x4280008C))
#define PCA0_CMD_ECF_BIT                          (*(__IO uint32_t*)(0x42800090))
#define PCA0_CMD_CF0DMA_BIT                       (*(__IO uint32_t*)(0x42800094))
#define PCA0_CMD_CF1DMA_BIT                       (*(__IO uint32_t*)(0x42800098))
#define PCA0_CMD_CFDMA_BIT                        (*(__IO uint32_t*)(0x4280009C))
#define PCA0_CPM0_ECCF0_BIT                       (*(__IO uint32_t*)(0x42800100))
#define PCA0_CPM0_MAT0_BIT                        (*(__IO uint32_t*)(0x42800104))
#define PCA0_CPM0_TCP0_BIT                        (*(__IO uint32_t*)(0x42800108))
#define PCA0_CPM0_ECOM0_BIT                       (*(__IO uint32_t*)(0x4280010C))
#define PCA0_CPM1_ECCF1_BIT                       (*(__IO uint32_t*)(0x42800180))
#define PCA0_CPM1_MAT1_BIT                        (*(__IO uint32_t*)(0x42800184))
#define PCA0_CPM1_TCP1_BIT                        (*(__IO uint32_t*)(0x42800188))
#define PCA0_CPM1_ECOM1_BIT                       (*(__IO uint32_t*)(0x4280018C))
#define PCA0_FORCE_FCO0_BIT                       (*(__IO uint32_t*)(0x42800200))
#define PCA0_FORCE_FCO1_BIT                       (*(__IO uint32_t*)(0x42800204))
#define PCA0_FORCE_OSC0_BIT                       (*(__IO uint32_t*)(0x42800208))
#define PCA0_FORCE_OSC1_BIT                       (*(__IO uint32_t*)(0x4280020C))
#define PCA0_PCAINTF_CCF0_BIT                     (*(__I  uint32_t*)(0x42800400))
#define PCA0_PCAINTF_CCF1_BIT                     (*(__I  uint32_t*)(0x42800404))
#define PCA0_PCAINTF_CF_BIT                       (*(__I  uint32_t*)(0x42800408))
#define PCA0_PCAINTF_CCF0C_BIT                    (*(__O  uint32_t*)(0x4280040C))
#define PCA0_PCAINTF_CCF1C_BIT                    (*(__O  uint32_t*)(0x42800410))
#define PCA0_PCAINTF_CFC_BIT                      (*(__O  uint32_t*)(0x42800414))
#define PCA1_CR_PR_BIT                            (*(__IO uint32_t*)(0x42808000))
#define PCA1_CR_CASCEN_BIT                        (*(__IO uint32_t*)(0x42808004))
#define PCA1_CMD_SDEN_BIT                         (*(__IO uint32_t*)(0x4280808C))
#define PCA1_CMD_ECF_BIT                          (*(__IO uint32_t*)(0x42808090))
#define PCA1_CMD_CF0DMA_BIT                       (*(__IO uint32_t*)(0x42808094))
#define PCA1_CMD_CF1DMA_BIT                       (*(__IO uint32_t*)(0x42808098))
#define PCA1_CMD_CFDMA_BIT                        (*(__IO uint32_t*)(0x4280809C))
#define PCA1_CPM0_ECCF0_BIT                       (*(__IO uint32_t*)(0x42808100))
#define PCA1_CPM0_MAT0_BIT                        (*(__IO uint32_t*)(0x42808104))
#define PCA1_CPM0_TCP0_BIT                        (*(__IO uint32_t*)(0x42808108))
#define PCA1_CPM0_ECOM0_BIT                       (*(__IO uint32_t*)(0x4280810C))
#define PCA1_CPM1_ECCF1_BIT                       (*(__IO uint32_t*)(0x42808180))
#define PCA1_CPM1_MAT1_BIT                        (*(__IO uint32_t*)(0x42808184))
#define PCA1_CPM1_TCP1_BIT                        (*(__IO uint32_t*)(0x42808188))
#define PCA1_CPM1_ECOM1_BIT                       (*(__IO uint32_t*)(0x4280818C))
#define PCA1_FORCE_FCO0_BIT                       (*(__IO uint32_t*)(0x42808200))
#define PCA1_FORCE_FCO1_BIT                       (*(__IO uint32_t*)(0x42808204))
#define PCA1_FORCE_OSC0_BIT                       (*(__IO uint32_t*)(0x42808208))
#define PCA1_FORCE_OSC1_BIT                       (*(__IO uint32_t*)(0x4280820C))
#define PCA1_PCAINTF_CCF0_BIT                     (*(__I  uint32_t*)(0x42808400))
#define PCA1_PCAINTF_CCF1_BIT                     (*(__I  uint32_t*)(0x42808404))
#define PCA1_PCAINTF_CF_BIT                       (*(__I  uint32_t*)(0x42808408))
#define PCA1_PCAINTF_CCF0C_BIT                    (*(__O  uint32_t*)(0x4280840C))
#define PCA1_PCAINTF_CCF1C_BIT                    (*(__O  uint32_t*)(0x42808410))
#define PCA1_PCAINTF_CFC_BIT                      (*(__O  uint32_t*)(0x42808414))
#define PWM0_CR_PWMEN_BIT                         (*(__IO uint32_t*)(0x42078000))
#define PWM0_CR_FLTC_BIT                          (*(__IO uint32_t*)(0x42078010))
#define PWM0_CR_EFLT_BIT                          (*(__IO uint32_t*)(0x42078014))
#define PWM0_CR_PWMSB_BIT                         (*(__IO uint32_t*)(0x42078018))
#define PWM0_CR_PWMSA_BIT                         (*(__IO uint32_t*)(0x4207801C))
#define PWM0_CR_EFLTIE_BIT                        (*(__IO uint32_t*)(0x42078020))
#define PWM0_CR_PWMIE_BIT                         (*(__IO uint32_t*)(0x42078024))
#define PWM0_CR_EPWMB_BIT                         (*(__IO uint32_t*)(0x42078028))
#define PWM0_CR_EPWMA_BIT                         (*(__IO uint32_t*)(0x4207802C))
#define PWM0_CR_PWMDMA_BIT                        (*(__IO uint32_t*)(0x42078030))
#define PWM0_CR_FLTDMA_BIT                        (*(__IO uint32_t*)(0x42078034))
#define PWM0_PWMINTF_FLTS_BIT                     (*(__I  uint32_t*)(0x42078280))
#define PWM0_PWMINTF_PWMIF_BIT                    (*(__I  uint32_t*)(0x42078284))
#define PWM0_PWMINTF_FLTSC_BIT                    (*(__O  uint32_t*)(0x42078288))
#define PWM0_PWMINTF_PWMIFC_BIT                   (*(__O  uint32_t*)(0x4207828C))
#define PWM1_CR_PWMEN_BIT                         (*(__IO uint32_t*)(0x42080000))
#define PWM1_CR_FLTC_BIT                          (*(__IO uint32_t*)(0x42080010))
#define PWM1_CR_EFLT_BIT                          (*(__IO uint32_t*)(0x42080014))
#define PWM1_CR_PWMSB_BIT                         (*(__IO uint32_t*)(0x42080018))
#define PWM1_CR_PWMSA_BIT                         (*(__IO uint32_t*)(0x4208001C))
#define PWM1_CR_EFLTIE_BIT                        (*(__IO uint32_t*)(0x42080020))
#define PWM1_CR_PWMIE_BIT                         (*(__IO uint32_t*)(0x42080024))
#define PWM1_CR_EPWMB_BIT                         (*(__IO uint32_t*)(0x42080028))
#define PWM1_CR_EPWMA_BIT                         (*(__IO uint32_t*)(0x4208002C))
#define PWM1_CR_PWMDMA_BIT                        (*(__IO uint32_t*)(0x42080030))
#define PWM1_CR_FLTDMA_BIT                        (*(__IO uint32_t*)(0x42080034))
#define PWM1_PWMINTF_FLTS_BIT                     (*(__I  uint32_t*)(0x42080280))
#define PWM1_PWMINTF_PWMIF_BIT                    (*(__I  uint32_t*)(0x42080284))
#define PWM1_PWMINTF_FLTSC_BIT                    (*(__O  uint32_t*)(0x42080288))
#define PWM1_PWMINTF_PWMIFC_BIT                   (*(__O  uint32_t*)(0x4208028C))
#define PWM2_CR_PWMEN_BIT                         (*(__IO uint32_t*)(0x42088000))
#define PWM2_CR_FLTC_BIT                          (*(__IO uint32_t*)(0x42088010))
#define PWM2_CR_EFLT_BIT                          (*(__IO uint32_t*)(0x42088014))
#define PWM2_CR_PWMSB_BIT                         (*(__IO uint32_t*)(0x42088018))
#define PWM2_CR_PWMSA_BIT                         (*(__IO uint32_t*)(0x4208801C))
#define PWM2_CR_EFLTIE_BIT                        (*(__IO uint32_t*)(0x42088020))
#define PWM2_CR_PWMIE_BIT                         (*(__IO uint32_t*)(0x42088024))
#define PWM2_CR_EPWMB_BIT                         (*(__IO uint32_t*)(0x42088028))
#define PWM2_CR_EPWMA_BIT                         (*(__IO uint32_t*)(0x4208802C))
#define PWM2_CR_PWMDMA_BIT                        (*(__IO uint32_t*)(0x42088030))
#define PWM2_CR_FLTDMA_BIT                        (*(__IO uint32_t*)(0x42088034))
#define PWM2_PWMINTF_FLTS_BIT                     (*(__I  uint32_t*)(0x42088280))
#define PWM2_PWMINTF_PWMIF_BIT                    (*(__I  uint32_t*)(0x42088284))
#define PWM2_PWMINTF_FLTSC_BIT                    (*(__O  uint32_t*)(0x42088288))
#define PWM2_PWMINTF_PWMIFC_BIT                   (*(__O  uint32_t*)(0x4208828C))
#define PWM3_CR_PWMEN_BIT                         (*(__IO uint32_t*)(0x42090000))
#define PWM3_CR_FLTC_BIT                          (*(__IO uint32_t*)(0x42090010))
#define PWM3_CR_EFLT_BIT                          (*(__IO uint32_t*)(0x42090014))
#define PWM3_CR_PWMSB_BIT                         (*(__IO uint32_t*)(0x42090018))
#define PWM3_CR_PWMSA_BIT                         (*(__IO uint32_t*)(0x4209001C))
#define PWM3_CR_EFLTIE_BIT                        (*(__IO uint32_t*)(0x42090020))
#define PWM3_CR_PWMIE_BIT                         (*(__IO uint32_t*)(0x42090024))
#define PWM3_CR_EPWMB_BIT                         (*(__IO uint32_t*)(0x42090028))
#define PWM3_CR_EPWMA_BIT                         (*(__IO uint32_t*)(0x4209002C))
#define PWM3_CR_PWMDMA_BIT                        (*(__IO uint32_t*)(0x42090030))
#define PWM3_CR_FLTDMA_BIT                        (*(__IO uint32_t*)(0x42090034))
#define PWM3_PWMINTF_FLTS_BIT                     (*(__I  uint32_t*)(0x42090280))
#define PWM3_PWMINTF_PWMIF_BIT                    (*(__I  uint32_t*)(0x42090284))
#define PWM3_PWMINTF_FLTSC_BIT                    (*(__O  uint32_t*)(0x42090288))
#define PWM3_PWMINTF_PWMIFC_BIT                   (*(__O  uint32_t*)(0x4209028C))
#define PCA2_CR_PR_BIT                            (*(__IO uint32_t*)(0x420C0000))
#define PCA2_CR_CASCEN_BIT                        (*(__IO uint32_t*)(0x420C0004))
#define PCA2_CMD_SDEN_BIT                         (*(__IO uint32_t*)(0x420C008C))
#define PCA2_CMD_ECF_BIT                          (*(__IO uint32_t*)(0x420C0090))
#define PCA2_CMD_CF0DMA_BIT                       (*(__IO uint32_t*)(0x420C0094))
#define PCA2_CMD_CF1DMA_BIT                       (*(__IO uint32_t*)(0x420C0098))
#define PCA2_CMD_CFDMA_BIT                        (*(__IO uint32_t*)(0x420C009C))
#define PCA2_CPM0_ECCF0_BIT                       (*(__IO uint32_t*)(0x420C0100))
#define PCA2_CPM0_MAT0_BIT                        (*(__IO uint32_t*)(0x420C0104))
#define PCA2_CPM0_TCP0_BIT                        (*(__IO uint32_t*)(0x420C0108))
#define PCA2_CPM0_ECOM0_BIT                       (*(__IO uint32_t*)(0x420C010C))
#define PCA2_CPM1_ECCF1_BIT                       (*(__IO uint32_t*)(0x420C0180))
#define PCA2_CPM1_MAT1_BIT                        (*(__IO uint32_t*)(0x420C0184))
#define PCA2_CPM1_TCP1_BIT                        (*(__IO uint32_t*)(0x420C0188))
#define PCA2_CPM1_ECOM1_BIT                       (*(__IO uint32_t*)(0x420C018C))
#define PCA2_FORCE_FCO0_BIT                       (*(__IO uint32_t*)(0x420C0200))
#define PCA2_FORCE_FCO1_BIT                       (*(__IO uint32_t*)(0x420C0204))
#define PCA2_FORCE_OSC0_BIT                       (*(__IO uint32_t*)(0x420C0208))
#define PCA2_FORCE_OSC1_BIT                       (*(__IO uint32_t*)(0x420C020C))
#define PCA2_PCAINTF_CCF0_BIT                     (*(__I  uint32_t*)(0x420C0400))
#define PCA2_PCAINTF_CCF1_BIT                     (*(__I  uint32_t*)(0x420C0404))
#define PCA2_PCAINTF_CF_BIT                       (*(__I  uint32_t*)(0x420C0408))
#define PCA2_PCAINTF_CCF0C_BIT                    (*(__O  uint32_t*)(0x420C040C))
#define PCA2_PCAINTF_CCF1C_BIT                    (*(__O  uint32_t*)(0x420C0410))
#define PCA2_PCAINTF_CFC_BIT                      (*(__O  uint32_t*)(0x420C0414))
#define PCA3_CR_PR_BIT                            (*(__IO uint32_t*)(0x420C8000))
#define PCA3_CR_CASCEN_BIT                        (*(__IO uint32_t*)(0x420C8004))
#define PCA3_CMD_SDEN_BIT                         (*(__IO uint32_t*)(0x420C808C))
#define PCA3_CMD_ECF_BIT                          (*(__IO uint32_t*)(0x420C8090))
#define PCA3_CMD_CF0DMA_BIT                       (*(__IO uint32_t*)(0x420C8094))
#define PCA3_CMD_CF1DMA_BIT                       (*(__IO uint32_t*)(0x420C8098))
#define PCA3_CMD_CFDMA_BIT                        (*(__IO uint32_t*)(0x420C809C))
#define PCA3_CPM0_ECCF0_BIT                       (*(__IO uint32_t*)(0x420C8100))
#define PCA3_CPM0_MAT0_BIT                        (*(__IO uint32_t*)(0x420C8104))
#define PCA3_CPM0_TCP0_BIT                        (*(__IO uint32_t*)(0x420C8108))
#define PCA3_CPM0_ECOM0_BIT                       (*(__IO uint32_t*)(0x420C810C))
#define PCA3_CPM1_ECCF1_BIT                       (*(__IO uint32_t*)(0x420C8180))
#define PCA3_CPM1_MAT1_BIT                        (*(__IO uint32_t*)(0x420C8184))
#define PCA3_CPM1_TCP1_BIT                        (*(__IO uint32_t*)(0x420C8188))
#define PCA3_CPM1_ECOM1_BIT                       (*(__IO uint32_t*)(0x420C818C))
#define PCA3_FORCE_FCO0_BIT                       (*(__IO uint32_t*)(0x420C8200))
#define PCA3_FORCE_FCO1_BIT                       (*(__IO uint32_t*)(0x420C8204))
#define PCA3_FORCE_OSC0_BIT                       (*(__IO uint32_t*)(0x420C8208))
#define PCA3_FORCE_OSC1_BIT                       (*(__IO uint32_t*)(0x420C820C))
#define PCA3_PCAINTF_CCF0_BIT                     (*(__I  uint32_t*)(0x420C8400))
#define PCA3_PCAINTF_CCF1_BIT                     (*(__I  uint32_t*)(0x420C8404))
#define PCA3_PCAINTF_CF_BIT                       (*(__I  uint32_t*)(0x420C8408))
#define PCA3_PCAINTF_CCF0C_BIT                    (*(__O  uint32_t*)(0x420C840C))
#define PCA3_PCAINTF_CCF1C_BIT                    (*(__O  uint32_t*)(0x420C8410))
#define PCA3_PCAINTF_CFC_BIT                      (*(__O  uint32_t*)(0x420C8414))
#define PCA4_CR_PR_BIT                            (*(__IO uint32_t*)(0x420D0000))
#define PCA4_CR_CASCEN_BIT                        (*(__IO uint32_t*)(0x420D0004))
#define PCA4_CMD_SDEN_BIT                         (*(__IO uint32_t*)(0x420D008C))
#define PCA4_CMD_ECF_BIT                          (*(__IO uint32_t*)(0x420D0090))
#define PCA4_CMD_CF0DMA_BIT                       (*(__IO uint32_t*)(0x420D0094))
#define PCA4_CMD_CF1DMA_BIT                       (*(__IO uint32_t*)(0x420D0098))
#define PCA4_CMD_CFDMA_BIT                        (*(__IO uint32_t*)(0x420D009C))
#define PCA4_CPM0_ECCF0_BIT                       (*(__IO uint32_t*)(0x420D0100))
#define PCA4_CPM0_MAT0_BIT                        (*(__IO uint32_t*)(0x420D0104))
#define PCA4_CPM0_TCP0_BIT                        (*(__IO uint32_t*)(0x420D0108))
#define PCA4_CPM0_ECOM0_BIT                       (*(__IO uint32_t*)(0x420D010C))
#define PCA4_CPM1_ECCF1_BIT                       (*(__IO uint32_t*)(0x420D0180))
#define PCA4_CPM1_MAT1_BIT                        (*(__IO uint32_t*)(0x420D0184))
#define PCA4_CPM1_TCP1_BIT                        (*(__IO uint32_t*)(0x420D0188))
#define PCA4_CPM1_ECOM1_BIT                       (*(__IO uint32_t*)(0x420D018C))
#define PCA4_FORCE_FCO0_BIT                       (*(__IO uint32_t*)(0x420D0200))
#define PCA4_FORCE_FCO1_BIT                       (*(__IO uint32_t*)(0x420D0204))
#define PCA4_FORCE_OSC0_BIT                       (*(__IO uint32_t*)(0x420D0208))
#define PCA4_FORCE_OSC1_BIT                       (*(__IO uint32_t*)(0x420D020C))
#define PCA4_PCAINTF_CCF0_BIT                     (*(__I  uint32_t*)(0x420D0400))
#define PCA4_PCAINTF_CCF1_BIT                     (*(__I  uint32_t*)(0x420D0404))
#define PCA4_PCAINTF_CF_BIT                       (*(__I  uint32_t*)(0x420D0408))
#define PCA4_PCAINTF_CCF0C_BIT                    (*(__O  uint32_t*)(0x420D040C))
#define PCA4_PCAINTF_CCF1C_BIT                    (*(__O  uint32_t*)(0x420D0410))
#define PCA4_PCAINTF_CFC_BIT                      (*(__O  uint32_t*)(0x420D0414))
#define PCA5_CR_PR_BIT                            (*(__IO uint32_t*)(0x420D8000))
#define PCA5_CR_CASCEN_BIT                        (*(__IO uint32_t*)(0x420D8004))
#define PCA5_CMD_SDEN_BIT                         (*(__IO uint32_t*)(0x420D808C))
#define PCA5_CMD_ECF_BIT                          (*(__IO uint32_t*)(0x420D8090))
#define PCA5_CMD_CF0DMA_BIT                       (*(__IO uint32_t*)(0x420D8094))
#define PCA5_CMD_CF1DMA_BIT                       (*(__IO uint32_t*)(0x420D8098))
#define PCA5_CMD_CFDMA_BIT                        (*(__IO uint32_t*)(0x420D809C))
#define PCA5_CPM0_ECCF0_BIT                       (*(__IO uint32_t*)(0x420D8100))
#define PCA5_CPM0_MAT0_BIT                        (*(__IO uint32_t*)(0x420D8104))
#define PCA5_CPM0_TCP0_BIT                        (*(__IO uint32_t*)(0x420D8108))
#define PCA5_CPM0_ECOM0_BIT                       (*(__IO uint32_t*)(0x420D810C))
#define PCA5_CPM1_ECCF1_BIT                       (*(__IO uint32_t*)(0x420D8180))
#define PCA5_CPM1_MAT1_BIT                        (*(__IO uint32_t*)(0x420D8184))
#define PCA5_CPM1_TCP1_BIT                        (*(__IO uint32_t*)(0x420D8188))
#define PCA5_CPM1_ECOM1_BIT                       (*(__IO uint32_t*)(0x420D818C))
#define PCA5_FORCE_FCO0_BIT                       (*(__IO uint32_t*)(0x420D8200))
#define PCA5_FORCE_FCO1_BIT                       (*(__IO uint32_t*)(0x420D8204))
#define PCA5_FORCE_OSC0_BIT                       (*(__IO uint32_t*)(0x420D8208))
#define PCA5_FORCE_OSC1_BIT                       (*(__IO uint32_t*)(0x420D820C))
#define PCA5_PCAINTF_CCF0_BIT                     (*(__I  uint32_t*)(0x420D8400))
#define PCA5_PCAINTF_CCF1_BIT                     (*(__I  uint32_t*)(0x420D8404))
#define PCA5_PCAINTF_CF_BIT                       (*(__I  uint32_t*)(0x420D8408))
#define PCA5_PCAINTF_CCF0C_BIT                    (*(__O  uint32_t*)(0x420D840C))
#define PCA5_PCAINTF_CCF1C_BIT                    (*(__O  uint32_t*)(0x420D8410))
#define PCA5_PCAINTF_CFC_BIT                      (*(__O  uint32_t*)(0x420D8414))
#define PCA6_CR_PR_BIT                            (*(__IO uint32_t*)(0x420E0000))
#define PCA6_CR_CASCEN_BIT                        (*(__IO uint32_t*)(0x420E0004))
#define PCA6_CMD_SDEN_BIT                         (*(__IO uint32_t*)(0x420E008C))
#define PCA6_CMD_ECF_BIT                          (*(__IO uint32_t*)(0x420E0090))
#define PCA6_CMD_CF0DMA_BIT                       (*(__IO uint32_t*)(0x420E0094))
#define PCA6_CMD_CF1DMA_BIT                       (*(__IO uint32_t*)(0x420E0098))
#define PCA6_CMD_CFDMA_BIT                        (*(__IO uint32_t*)(0x420E009C))
#define PCA6_CPM0_ECCF0_BIT                       (*(__IO uint32_t*)(0x420E0100))
#define PCA6_CPM0_MAT0_BIT                        (*(__IO uint32_t*)(0x420E0104))
#define PCA6_CPM0_TCP0_BIT                        (*(__IO uint32_t*)(0x420E0108))
#define PCA6_CPM0_ECOM0_BIT                       (*(__IO uint32_t*)(0x420E010C))
#define PCA6_CPM1_ECCF1_BIT                       (*(__IO uint32_t*)(0x420E0180))
#define PCA6_CPM1_MAT1_BIT                        (*(__IO uint32_t*)(0x420E0184))
#define PCA6_CPM1_TCP1_BIT                        (*(__IO uint32_t*)(0x420E0188))
#define PCA6_CPM1_ECOM1_BIT                       (*(__IO uint32_t*)(0x420E018C))
#define PCA6_FORCE_FCO0_BIT                       (*(__IO uint32_t*)(0x420E0200))
#define PCA6_FORCE_FCO1_BIT                       (*(__IO uint32_t*)(0x420E0204))
#define PCA6_FORCE_OSC0_BIT                       (*(__IO uint32_t*)(0x420E0208))
#define PCA6_FORCE_OSC1_BIT                       (*(__IO uint32_t*)(0x420E020C))
#define PCA6_PCAINTF_CCF0_BIT                     (*(__I  uint32_t*)(0x420E0400))
#define PCA6_PCAINTF_CCF1_BIT                     (*(__I  uint32_t*)(0x420E0404))
#define PCA6_PCAINTF_CF_BIT                       (*(__I  uint32_t*)(0x420E0408))
#define PCA6_PCAINTF_CCF0C_BIT                    (*(__O  uint32_t*)(0x420E040C))
#define PCA6_PCAINTF_CCF1C_BIT                    (*(__O  uint32_t*)(0x420E0410))
#define PCA6_PCAINTF_CFC_BIT                      (*(__O  uint32_t*)(0x420E0414))
#define PCA7_CR_PR_BIT                            (*(__IO uint32_t*)(0x420E8000))
#define PCA7_CR_CASCEN_BIT                        (*(__IO uint32_t*)(0x420E8004))
#define PCA7_CMD_SDEN_BIT                         (*(__IO uint32_t*)(0x420E808C))
#define PCA7_CMD_ECF_BIT                          (*(__IO uint32_t*)(0x420E8090))
#define PCA7_CMD_CF0DMA_BIT                       (*(__IO uint32_t*)(0x420E8094))
#define PCA7_CMD_CF1DMA_BIT                       (*(__IO uint32_t*)(0x420E8098))
#define PCA7_CMD_CFDMA_BIT                        (*(__IO uint32_t*)(0x420E809C))
#define PCA7_CPM0_ECCF0_BIT                       (*(__IO uint32_t*)(0x420E8100))
#define PCA7_CPM0_MAT0_BIT                        (*(__IO uint32_t*)(0x420E8104))
#define PCA7_CPM0_TCP0_BIT                        (*(__IO uint32_t*)(0x420E8108))
#define PCA7_CPM0_ECOM0_BIT                       (*(__IO uint32_t*)(0x420E810C))
#define PCA7_CPM1_ECCF1_BIT                       (*(__IO uint32_t*)(0x420E8180))
#define PCA7_CPM1_MAT1_BIT                        (*(__IO uint32_t*)(0x420E8184))
#define PCA7_CPM1_TCP1_BIT                        (*(__IO uint32_t*)(0x420E8188))
#define PCA7_CPM1_ECOM1_BIT                       (*(__IO uint32_t*)(0x420E818C))
#define PCA7_FORCE_FCO0_BIT                       (*(__IO uint32_t*)(0x420E8200))
#define PCA7_FORCE_FCO1_BIT                       (*(__IO uint32_t*)(0x420E8204))
#define PCA7_FORCE_OSC0_BIT                       (*(__IO uint32_t*)(0x420E8208))
#define PCA7_FORCE_OSC1_BIT                       (*(__IO uint32_t*)(0x420E820C))
#define PCA7_PCAINTF_CCF0_BIT                     (*(__I  uint32_t*)(0x420E8400))
#define PCA7_PCAINTF_CCF1_BIT                     (*(__I  uint32_t*)(0x420E8404))
#define PCA7_PCAINTF_CF_BIT                       (*(__I  uint32_t*)(0x420E8408))
#define PCA7_PCAINTF_CCF0C_BIT                    (*(__O  uint32_t*)(0x420E840C))
#define PCA7_PCAINTF_CCF1C_BIT                    (*(__O  uint32_t*)(0x420E8410))
#define PCA7_PCAINTF_CFC_BIT                      (*(__O  uint32_t*)(0x420E8414))
#define TIM5_CR_STR_BIT                           (*(__IO uint32_t*)(0x42008000))
#define TIM5_CR_OPM_BIT                           (*(__IO uint32_t*)(0x4200800C))
#define TIM5_CR_IE_BIT                            (*(__IO uint32_t*)(0x42008018))
#define TIM5_CR_TRIGEN_BIT                        (*(__IO uint32_t*)(0x42008020))
#define TIM5_CR_ETEN_BIT                          (*(__IO uint32_t*)(0x42008024))
#define TIM5_CR_TC_BIT                            (*(__IO uint32_t*)(0x42008028))
#define TIM5_CR_CASCEN_BIT                        (*(__IO uint32_t*)(0x4200803C))
#define TIM5_TIMINTF_TF_BIT                       (*(__I  uint32_t*)(0x42008200))
#define TIM5_TIMINTF_TFC_BIT                      (*(__O  uint32_t*)(0x42008240))
#define TIM6_CR_STR_BIT                           (*(__IO uint32_t*)(0x42010000))
#define TIM6_CR_OPM_BIT                           (*(__IO uint32_t*)(0x4201000C))
#define TIM6_CR_IE_BIT                            (*(__IO uint32_t*)(0x42010018))
#define TIM6_CR_TRIGEN_BIT                        (*(__IO uint32_t*)(0x42010020))
#define TIM6_CR_ETEN_BIT                          (*(__IO uint32_t*)(0x42010024))
#define TIM6_CR_TC_BIT                            (*(__IO uint32_t*)(0x42010028))
#define TIM6_CR_CASCEN_BIT                        (*(__IO uint32_t*)(0x4201003C))
#define TIM6_TIMINTF_TF_BIT                       (*(__I  uint32_t*)(0x42010200))
#define TIM6_TIMINTF_TFC_BIT                      (*(__O  uint32_t*)(0x42010240))
#define TIM7_CR_STR_BIT                           (*(__IO uint32_t*)(0x42018000))
#define TIM7_CR_OPM_BIT                           (*(__IO uint32_t*)(0x4201800C))
#define TIM7_CR_IE_BIT                            (*(__IO uint32_t*)(0x42018018))
#define TIM7_CR_TRIGEN_BIT                        (*(__IO uint32_t*)(0x42018020))
#define TIM7_CR_ETEN_BIT                          (*(__IO uint32_t*)(0x42018024))
#define TIM7_CR_TC_BIT                            (*(__IO uint32_t*)(0x42018028))
#define TIM7_CR_CASCEN_BIT                        (*(__IO uint32_t*)(0x4201803C))
#define TIM7_TIMINTF_TF_BIT                       (*(__I  uint32_t*)(0x42018200))
#define TIM7_TIMINTF_TFC_BIT                      (*(__O  uint32_t*)(0x42018240))
#define TIM8_CR_STR_BIT                           (*(__IO uint32_t*)(0x42020000))
#define TIM8_CR_OPM_BIT                           (*(__IO uint32_t*)(0x4202000C))
#define TIM8_CR_IE_BIT                            (*(__IO uint32_t*)(0x42020018))
#define TIM8_CR_TRIGEN_BIT                        (*(__IO uint32_t*)(0x42020020))
#define TIM8_CR_ETEN_BIT                          (*(__IO uint32_t*)(0x42020024))
#define TIM8_CR_TC_BIT                            (*(__IO uint32_t*)(0x42020028))
#define TIM8_CR_CASCEN_BIT                        (*(__IO uint32_t*)(0x4202003C))
#define TIM8_TIMINTF_TF_BIT                       (*(__I  uint32_t*)(0x42020200))
#define TIM8_TIMINTF_TFC_BIT                      (*(__O  uint32_t*)(0x42020240))
#define IWDT_CR_IWDTPD_BIT                        (*(__IO uint32_t*)(0x420F803C))
#define WWDT_CR_WWDTIE_BIT                        (*(__IO uint32_t*)(0x42100038))
#define WWDT_CR_WWDTON_BIT                        (*(__IO uint32_t*)(0x4210003C))
#define WWDT_SR_WWDTIF_BIT                        (*(__IO uint32_t*)(0x421000BC))
#define ADC_ADCON1_ADSOC_BIT                      (*(__IO uint32_t*)(0x42450000))
#define ADC_ADCON1_MOD_BIT                        (*(__IO uint32_t*)(0x4245000C))
#define ADC_ADCON1_ADDE_BIT                       (*(__IO uint32_t*)(0x42450018))
#define ADC_ADCON1_ADIE_BIT                       (*(__IO uint32_t*)(0x4245001C))
#define ADC_ADCON1_ADON_BIT                       (*(__IO uint32_t*)(0x4245003C))
#define ADC_ADCMPCON_ADLDE_BIT                    (*(__IO uint32_t*)(0x42450590))
#define ADC_ADCMPCON_ADLIE_BIT                    (*(__IO uint32_t*)(0x42450594))
#define ADC_ADCMPCON_ADGDE_BIT                    (*(__IO uint32_t*)(0x42450598))
#define ADC_ADCMPCON_ADGIE_BIT                    (*(__IO uint32_t*)(0x4245059C))
#define ADC_ADINTF_ADLIF_BIT                      (*(__I  uint32_t*)(0x42450880))
#define ADC_ADINTF_ADGIF_BIT                      (*(__I  uint32_t*)(0x42450884))
#define ADC_ADINTF_ADIF_BIT                       (*(__I  uint32_t*)(0x42450888))
#define ADC_ADINTF_ADLIFC_BIT                     (*(__O  uint32_t*)(0x424508C0))
#define ADC_ADINTF_ADGIFC_BIT                     (*(__O  uint32_t*)(0x424508C4))
#define ADC_ADINTF_ADIFC_BIT                      (*(__O  uint32_t*)(0x424508C8))
#define TPS_AVREFCON_VREFEN_BIT                   (*(__IO uint32_t*)(0x42458080))
#define TPS_AVREFCON_VREFSEL_BIT                  (*(__IO uint32_t*)(0x42458084))
#define TPS_AVREFCON_CHOPS_BIT                    (*(__IO uint32_t*)(0x42458088))
#define TPS_AVREFCON_CHOPEN_BIT                   (*(__IO uint32_t*)(0x4245808C))
#define TPS_TPSCON_TPSEN_BIT                      (*(__IO uint32_t*)(0x42458100))
#define TPS_TPSCON_TPSCHOP_BIT                    (*(__IO uint32_t*)(0x42458104))
#define UART0_FR_RI_BIT                           (*(__I  uint32_t*)(0x42400000))
#define UART0_FR_TI_BIT                           (*(__I  uint32_t*)(0x42400004))
#define UART0_FR_TC_BIT                           (*(__I  uint32_t*)(0x42400008))
#define UART0_FR_TXCOL_BIT                        (*(__I  uint32_t*)(0x4240000C))
#define UART0_FR_RXOV_BIT                         (*(__I  uint32_t*)(0x42400010))
#define UART0_FR_FE_BIT                           (*(__I  uint32_t*)(0x42400014))
#define UART0_FR_PE_BIT                           (*(__I  uint32_t*)(0x42400018))
#define UART0_FR_LBD_BIT                          (*(__I  uint32_t*)(0x4240001C))
#define UART0_FR_RIC_BIT                          (*(__O  uint32_t*)(0x42400040))
#define UART0_FR_TCC_BIT                          (*(__O  uint32_t*)(0x42400048))
#define UART0_FR_TXCOLC_BIT                       (*(__O  uint32_t*)(0x4240004C))
#define UART0_FR_RXOVC_BIT                        (*(__O  uint32_t*)(0x42400050))
#define UART0_FR_FEC_BIT                          (*(__O  uint32_t*)(0x42400054))
#define UART0_FR_PEC_BIT                          (*(__O  uint32_t*)(0x42400058))
#define UART0_FR_LBDC_BIT                         (*(__O  uint32_t*)(0x4240005C))
#define UART0_CR_STOP_BIT                         (*(__IO uint32_t*)(0x42400300))
#define UART0_CR_SBRTEN_BIT                       (*(__IO uint32_t*)(0x42400304))
#define UART0_CR_SMOD_BIT                         (*(__IO uint32_t*)(0x42400308))
#define UART0_CR_RIE_BIT                          (*(__IO uint32_t*)(0x4240030C))
#define UART0_CR_TIE_BIT                          (*(__IO uint32_t*)(0x42400310))
#define UART0_CR_TCIE_BIT                         (*(__IO uint32_t*)(0x42400314))
#define UART0_CR_LBDIE_BIT                        (*(__IO uint32_t*)(0x42400318))
#define UART0_CR_LBDL_BIT                         (*(__IO uint32_t*)(0x4240031C))
#define UART0_CR_RB8_BIT                          (*(__I  uint32_t*)(0x42400320))
#define UART0_CR_TB8_BIT                          (*(__IO uint32_t*)(0x42400324))
#define UART0_CR_PS_BIT                           (*(__IO uint32_t*)(0x42400328))
#define UART0_CR_PCE_BIT                          (*(__IO uint32_t*)(0x4240032C))
#define UART0_CR_SM2_BIT                          (*(__IO uint32_t*)(0x42400330))
#define UART0_CR_SBK_BIT                          (*(__IO uint32_t*)(0x4240033C))
#define UART0_CR_LINEN_BIT                        (*(__IO uint32_t*)(0x42400340))
#define UART0_CR_REN_BIT                          (*(__IO uint32_t*)(0x42400344))
#define UART0_CR_TEN_BIT                          (*(__IO uint32_t*)(0x42400348))
#define UART0_CR_DMAR_BIT                         (*(__IO uint32_t*)(0x4240034C))
#define UART0_CR_DMAT_BIT                         (*(__IO uint32_t*)(0x42400350))
#define UART1_FR_RI_BIT                           (*(__I  uint32_t*)(0x42408000))
#define UART1_FR_TI_BIT                           (*(__I  uint32_t*)(0x42408004))
#define UART1_FR_TC_BIT                           (*(__I  uint32_t*)(0x42408008))
#define UART1_FR_TXCOL_BIT                        (*(__I  uint32_t*)(0x4240800C))
#define UART1_FR_RXOV_BIT                         (*(__I  uint32_t*)(0x42408010))
#define UART1_FR_FE_BIT                           (*(__I  uint32_t*)(0x42408014))
#define UART1_FR_PE_BIT                           (*(__I  uint32_t*)(0x42408018))
#define UART1_FR_LBD_BIT                          (*(__I  uint32_t*)(0x4240801C))
#define UART1_FR_RIC_BIT                          (*(__O  uint32_t*)(0x42408040))
#define UART1_FR_TCC_BIT                          (*(__O  uint32_t*)(0x42408048))
#define UART1_FR_TXCOLC_BIT                       (*(__O  uint32_t*)(0x4240804C))
#define UART1_FR_RXOVC_BIT                        (*(__O  uint32_t*)(0x42408050))
#define UART1_FR_FEC_BIT                          (*(__O  uint32_t*)(0x42408054))
#define UART1_FR_PEC_BIT                          (*(__O  uint32_t*)(0x42408058))
#define UART1_FR_LBDC_BIT                         (*(__O  uint32_t*)(0x4240805C))
#define UART1_CR_STOP_BIT                         (*(__IO uint32_t*)(0x42408300))
#define UART1_CR_SBRTEN_BIT                       (*(__IO uint32_t*)(0x42408304))
#define UART1_CR_SMOD_BIT                         (*(__IO uint32_t*)(0x42408308))
#define UART1_CR_RIE_BIT                          (*(__IO uint32_t*)(0x4240830C))
#define UART1_CR_TIE_BIT                          (*(__IO uint32_t*)(0x42408310))
#define UART1_CR_TCIE_BIT                         (*(__IO uint32_t*)(0x42408314))
#define UART1_CR_LBDIE_BIT                        (*(__IO uint32_t*)(0x42408318))
#define UART1_CR_LBDL_BIT                         (*(__IO uint32_t*)(0x4240831C))
#define UART1_CR_RB8_BIT                          (*(__I  uint32_t*)(0x42408320))
#define UART1_CR_TB8_BIT                          (*(__IO uint32_t*)(0x42408324))
#define UART1_CR_PS_BIT                           (*(__IO uint32_t*)(0x42408328))
#define UART1_CR_PCE_BIT                          (*(__IO uint32_t*)(0x4240832C))
#define UART1_CR_SM2_BIT                          (*(__IO uint32_t*)(0x42408330))
#define UART1_CR_SBK_BIT                          (*(__IO uint32_t*)(0x4240833C))
#define UART1_CR_LINEN_BIT                        (*(__IO uint32_t*)(0x42408340))
#define UART1_CR_REN_BIT                          (*(__IO uint32_t*)(0x42408344))
#define UART1_CR_TEN_BIT                          (*(__IO uint32_t*)(0x42408348))
#define UART1_CR_DMAR_BIT                         (*(__IO uint32_t*)(0x4240834C))
#define UART1_CR_DMAT_BIT                         (*(__IO uint32_t*)(0x42408350))
#define UART2_FR_RI_BIT                           (*(__I  uint32_t*)(0x42410000))
#define UART2_FR_TI_BIT                           (*(__I  uint32_t*)(0x42410004))
#define UART2_FR_TC_BIT                           (*(__I  uint32_t*)(0x42410008))
#define UART2_FR_TXCOL_BIT                        (*(__I  uint32_t*)(0x4241000C))
#define UART2_FR_RXOV_BIT                         (*(__I  uint32_t*)(0x42410010))
#define UART2_FR_FE_BIT                           (*(__I  uint32_t*)(0x42410014))
#define UART2_FR_PE_BIT                           (*(__I  uint32_t*)(0x42410018))
#define UART2_FR_LBD_BIT                          (*(__I  uint32_t*)(0x4241001C))
#define UART2_FR_RIC_BIT                          (*(__O  uint32_t*)(0x42410040))
#define UART2_FR_TCC_BIT                          (*(__O  uint32_t*)(0x42410048))
#define UART2_FR_TXCOLC_BIT                       (*(__O  uint32_t*)(0x4241004C))
#define UART2_FR_RXOVC_BIT                        (*(__O  uint32_t*)(0x42410050))
#define UART2_FR_FEC_BIT                          (*(__O  uint32_t*)(0x42410054))
#define UART2_FR_PEC_BIT                          (*(__O  uint32_t*)(0x42410058))
#define UART2_FR_LBDC_BIT                         (*(__O  uint32_t*)(0x4241005C))
#define UART2_CR_STOP_BIT                         (*(__IO uint32_t*)(0x42410300))
#define UART2_CR_SBRTEN_BIT                       (*(__IO uint32_t*)(0x42410304))
#define UART2_CR_SMOD_BIT                         (*(__IO uint32_t*)(0x42410308))
#define UART2_CR_RIE_BIT                          (*(__IO uint32_t*)(0x4241030C))
#define UART2_CR_TIE_BIT                          (*(__IO uint32_t*)(0x42410310))
#define UART2_CR_TCIE_BIT                         (*(__IO uint32_t*)(0x42410314))
#define UART2_CR_LBDIE_BIT                        (*(__IO uint32_t*)(0x42410318))
#define UART2_CR_LBDL_BIT                         (*(__IO uint32_t*)(0x4241031C))
#define UART2_CR_RB8_BIT                          (*(__I  uint32_t*)(0x42410320))
#define UART2_CR_TB8_BIT                          (*(__IO uint32_t*)(0x42410324))
#define UART2_CR_PS_BIT                           (*(__IO uint32_t*)(0x42410328))
#define UART2_CR_PCE_BIT                          (*(__IO uint32_t*)(0x4241032C))
#define UART2_CR_SM2_BIT                          (*(__IO uint32_t*)(0x42410330))
#define UART2_CR_SBK_BIT                          (*(__IO uint32_t*)(0x4241033C))
#define UART2_CR_LINEN_BIT                        (*(__IO uint32_t*)(0x42410340))
#define UART2_CR_REN_BIT                          (*(__IO uint32_t*)(0x42410344))
#define UART2_CR_TEN_BIT                          (*(__IO uint32_t*)(0x42410348))
#define UART2_CR_DMAR_BIT                         (*(__IO uint32_t*)(0x4241034C))
#define UART2_CR_DMAT_BIT                         (*(__IO uint32_t*)(0x42410350))
#define UART3_FR_RI_BIT                           (*(__I  uint32_t*)(0x42418000))
#define UART3_FR_TI_BIT                           (*(__I  uint32_t*)(0x42418004))
#define UART3_FR_TC_BIT                           (*(__I  uint32_t*)(0x42418008))
#define UART3_FR_TXCOL_BIT                        (*(__I  uint32_t*)(0x4241800C))
#define UART3_FR_RXOV_BIT                         (*(__I  uint32_t*)(0x42418010))
#define UART3_FR_FE_BIT                           (*(__I  uint32_t*)(0x42418014))
#define UART3_FR_PE_BIT                           (*(__I  uint32_t*)(0x42418018))
#define UART3_FR_LBD_BIT                          (*(__I  uint32_t*)(0x4241801C))
#define UART3_FR_RIC_BIT                          (*(__O  uint32_t*)(0x42418040))
#define UART3_FR_TCC_BIT                          (*(__O  uint32_t*)(0x42418048))
#define UART3_FR_TXCOLC_BIT                       (*(__O  uint32_t*)(0x4241804C))
#define UART3_FR_RXOVC_BIT                        (*(__O  uint32_t*)(0x42418050))
#define UART3_FR_FEC_BIT                          (*(__O  uint32_t*)(0x42418054))
#define UART3_FR_PEC_BIT                          (*(__O  uint32_t*)(0x42418058))
#define UART3_FR_LBDC_BIT                         (*(__O  uint32_t*)(0x4241805C))
#define UART3_CR_STOP_BIT                         (*(__IO uint32_t*)(0x42418300))
#define UART3_CR_SBRTEN_BIT                       (*(__IO uint32_t*)(0x42418304))
#define UART3_CR_SMOD_BIT                         (*(__IO uint32_t*)(0x42418308))
#define UART3_CR_RIE_BIT                          (*(__IO uint32_t*)(0x4241830C))
#define UART3_CR_TIE_BIT                          (*(__IO uint32_t*)(0x42418310))
#define UART3_CR_TCIE_BIT                         (*(__IO uint32_t*)(0x42418314))
#define UART3_CR_LBDIE_BIT                        (*(__IO uint32_t*)(0x42418318))
#define UART3_CR_LBDL_BIT                         (*(__IO uint32_t*)(0x4241831C))
#define UART3_CR_RB8_BIT                          (*(__I  uint32_t*)(0x42418320))
#define UART3_CR_TB8_BIT                          (*(__IO uint32_t*)(0x42418324))
#define UART3_CR_PS_BIT                           (*(__IO uint32_t*)(0x42418328))
#define UART3_CR_PCE_BIT                          (*(__IO uint32_t*)(0x4241832C))
#define UART3_CR_SM2_BIT                          (*(__IO uint32_t*)(0x42418330))
#define UART3_CR_SBK_BIT                          (*(__IO uint32_t*)(0x4241833C))
#define UART3_CR_LINEN_BIT                        (*(__IO uint32_t*)(0x42418340))
#define UART3_CR_REN_BIT                          (*(__IO uint32_t*)(0x42418344))
#define UART3_CR_TEN_BIT                          (*(__IO uint32_t*)(0x42418348))
#define UART3_CR_DMAR_BIT                         (*(__IO uint32_t*)(0x4241834C))
#define UART3_CR_DMAT_BIT                         (*(__IO uint32_t*)(0x42418350))
#define UART4_FR_RI_BIT                           (*(__I  uint32_t*)(0x42420000))
#define UART4_FR_TI_BIT                           (*(__I  uint32_t*)(0x42420004))
#define UART4_FR_TC_BIT                           (*(__I  uint32_t*)(0x42420008))
#define UART4_FR_TXCOL_BIT                        (*(__I  uint32_t*)(0x4242000C))
#define UART4_FR_RXOV_BIT                         (*(__I  uint32_t*)(0x42420010))
#define UART4_FR_FE_BIT                           (*(__I  uint32_t*)(0x42420014))
#define UART4_FR_PE_BIT                           (*(__I  uint32_t*)(0x42420018))
#define UART4_FR_LBD_BIT                          (*(__I  uint32_t*)(0x4242001C))
#define UART4_FR_RIC_BIT                          (*(__O  uint32_t*)(0x42420040))
#define UART4_FR_TCC_BIT                          (*(__O  uint32_t*)(0x42420048))
#define UART4_FR_TXCOLC_BIT                       (*(__O  uint32_t*)(0x4242004C))
#define UART4_FR_RXOVC_BIT                        (*(__O  uint32_t*)(0x42420050))
#define UART4_FR_FEC_BIT                          (*(__O  uint32_t*)(0x42420054))
#define UART4_FR_PEC_BIT                          (*(__O  uint32_t*)(0x42420058))
#define UART4_FR_LBDC_BIT                         (*(__O  uint32_t*)(0x4242005C))
#define UART4_CR_STOP_BIT                         (*(__IO uint32_t*)(0x42420300))
#define UART4_CR_SBRTEN_BIT                       (*(__IO uint32_t*)(0x42420304))
#define UART4_CR_SMOD_BIT                         (*(__IO uint32_t*)(0x42420308))
#define UART4_CR_RIE_BIT                          (*(__IO uint32_t*)(0x4242030C))
#define UART4_CR_TIE_BIT                          (*(__IO uint32_t*)(0x42420310))
#define UART4_CR_TCIE_BIT                         (*(__IO uint32_t*)(0x42420314))
#define UART4_CR_LBDIE_BIT                        (*(__IO uint32_t*)(0x42420318))
#define UART4_CR_LBDL_BIT                         (*(__IO uint32_t*)(0x4242031C))
#define UART4_CR_RB8_BIT                          (*(__I  uint32_t*)(0x42420320))
#define UART4_CR_TB8_BIT                          (*(__IO uint32_t*)(0x42420324))
#define UART4_CR_PS_BIT                           (*(__IO uint32_t*)(0x42420328))
#define UART4_CR_PCE_BIT                          (*(__IO uint32_t*)(0x4242032C))
#define UART4_CR_SM2_BIT                          (*(__IO uint32_t*)(0x42420330))
#define UART4_CR_SBK_BIT                          (*(__IO uint32_t*)(0x4242033C))
#define UART4_CR_LINEN_BIT                        (*(__IO uint32_t*)(0x42420340))
#define UART4_CR_REN_BIT                          (*(__IO uint32_t*)(0x42420344))
#define UART4_CR_TEN_BIT                          (*(__IO uint32_t*)(0x42420348))
#define UART4_CR_DMAR_BIT                         (*(__IO uint32_t*)(0x4242034C))
#define UART4_CR_DMAT_BIT                         (*(__IO uint32_t*)(0x42420350))
#define UART5_FR_RI_BIT                           (*(__I  uint32_t*)(0x42428000))
#define UART5_FR_TI_BIT                           (*(__I  uint32_t*)(0x42428004))
#define UART5_FR_TC_BIT                           (*(__I  uint32_t*)(0x42428008))
#define UART5_FR_TXCOL_BIT                        (*(__I  uint32_t*)(0x4242800C))
#define UART5_FR_RXOV_BIT                         (*(__I  uint32_t*)(0x42428010))
#define UART5_FR_FE_BIT                           (*(__I  uint32_t*)(0x42428014))
#define UART5_FR_PE_BIT                           (*(__I  uint32_t*)(0x42428018))
#define UART5_FR_LBD_BIT                          (*(__I  uint32_t*)(0x4242801C))
#define UART5_FR_RIC_BIT                          (*(__O  uint32_t*)(0x42428040))
#define UART5_FR_TCC_BIT                          (*(__O  uint32_t*)(0x42428048))
#define UART5_FR_TXCOLC_BIT                       (*(__O  uint32_t*)(0x4242804C))
#define UART5_FR_RXOVC_BIT                        (*(__O  uint32_t*)(0x42428050))
#define UART5_FR_FEC_BIT                          (*(__O  uint32_t*)(0x42428054))
#define UART5_FR_PEC_BIT                          (*(__O  uint32_t*)(0x42428058))
#define UART5_FR_LBDC_BIT                         (*(__O  uint32_t*)(0x4242805C))
#define UART5_CR_STOP_BIT                         (*(__IO uint32_t*)(0x42428300))
#define UART5_CR_SBRTEN_BIT                       (*(__IO uint32_t*)(0x42428304))
#define UART5_CR_SMOD_BIT                         (*(__IO uint32_t*)(0x42428308))
#define UART5_CR_RIE_BIT                          (*(__IO uint32_t*)(0x4242830C))
#define UART5_CR_TIE_BIT                          (*(__IO uint32_t*)(0x42428310))
#define UART5_CR_TCIE_BIT                         (*(__IO uint32_t*)(0x42428314))
#define UART5_CR_LBDIE_BIT                        (*(__IO uint32_t*)(0x42428318))
#define UART5_CR_LBDL_BIT                         (*(__IO uint32_t*)(0x4242831C))
#define UART5_CR_RB8_BIT                          (*(__I  uint32_t*)(0x42428320))
#define UART5_CR_TB8_BIT                          (*(__IO uint32_t*)(0x42428324))
#define UART5_CR_PS_BIT                           (*(__IO uint32_t*)(0x42428328))
#define UART5_CR_PCE_BIT                          (*(__IO uint32_t*)(0x4242832C))
#define UART5_CR_SM2_BIT                          (*(__IO uint32_t*)(0x42428330))
#define UART5_CR_SBK_BIT                          (*(__IO uint32_t*)(0x4242833C))
#define UART5_CR_LINEN_BIT                        (*(__IO uint32_t*)(0x42428340))
#define UART5_CR_REN_BIT                          (*(__IO uint32_t*)(0x42428344))
#define UART5_CR_TEN_BIT                          (*(__IO uint32_t*)(0x42428348))
#define UART5_CR_DMAR_BIT                         (*(__IO uint32_t*)(0x4242834C))
#define UART5_CR_DMAT_BIT                         (*(__IO uint32_t*)(0x42428350))
#define SPI0_FR_SPRI_BIT                          (*(__I  uint32_t*)(0x42430000))
#define SPI0_FR_SPTI_BIT                          (*(__I  uint32_t*)(0x42430004))
#define SPI0_FR_BUSY_BIT                          (*(__I  uint32_t*)(0x42430008))
#define SPI0_FR_MODF_BIT                          (*(__I  uint32_t*)(0x4243000C))
#define SPI0_FR_RXOV_BIT                          (*(__I  uint32_t*)(0x42430010))
#define SPI0_FR_WCOL_BIT                          (*(__I  uint32_t*)(0x42430014))
#define SPI0_FR_SPRIC_BIT                         (*(__O  uint32_t*)(0x42430040))
#define SPI0_FR_SPTIC_BIT                         (*(__O  uint32_t*)(0x42430044))
#define SPI0_FR_MODFC_BIT                         (*(__O  uint32_t*)(0x4243004C))
#define SPI0_FR_RXOVC_BIT                         (*(__O  uint32_t*)(0x42430050))
#define SPI0_FR_WCOLC_BIT                         (*(__O  uint32_t*)(0x42430054))
#define SPI0_CR_SSDIS_BIT                         (*(__IO uint32_t*)(0x42430190))
#define SPI0_CR_CPOL_BIT                          (*(__IO uint32_t*)(0x42430194))
#define SPI0_CR_CPHA_BIT                          (*(__IO uint32_t*)(0x42430198))
#define SPI0_CR_MSTR_BIT                          (*(__IO uint32_t*)(0x4243019C))
#define SPI0_CR_DIR_BIT                           (*(__IO uint32_t*)(0x424301A0))
#define SPI0_CR_SPDATL_BIT                        (*(__IO uint32_t*)(0x424301A4))
#define SPI0_CR_SPRIE_BIT                         (*(__IO uint32_t*)(0x424301A8))
#define SPI0_CR_SPTIE_BIT                         (*(__IO uint32_t*)(0x424301AC))
#define SPI0_CR_SPDMAR_BIT                        (*(__IO uint32_t*)(0x424301B0))
#define SPI0_CR_SPDMAT_BIT                        (*(__IO uint32_t*)(0x424301B4))
#define SPI0_CR_SPIEN_BIT                         (*(__IO uint32_t*)(0x424301B8))
#define SPI0_CR_SPSFF_BIT                         (*(__IO uint32_t*)(0x424301BC))
#define SPI0_CR_SPDATW_BIT                        (*(__IO uint32_t*)(0x424301C0))
#define SPI1_FR_SPRI_BIT                          (*(__I  uint32_t*)(0x42438000))
#define SPI1_FR_SPTI_BIT                          (*(__I  uint32_t*)(0x42438004))
#define SPI1_FR_BUSY_BIT                          (*(__I  uint32_t*)(0x42438008))
#define SPI1_FR_MODF_BIT                          (*(__I  uint32_t*)(0x4243800C))
#define SPI1_FR_RXOV_BIT                          (*(__I  uint32_t*)(0x42438010))
#define SPI1_FR_WCOL_BIT                          (*(__I  uint32_t*)(0x42438014))
#define SPI1_FR_SPRIC_BIT                         (*(__O  uint32_t*)(0x42438040))
#define SPI1_FR_SPTIC_BIT                         (*(__O  uint32_t*)(0x42438044))
#define SPI1_FR_MODFC_BIT                         (*(__O  uint32_t*)(0x4243804C))
#define SPI1_FR_RXOVC_BIT                         (*(__O  uint32_t*)(0x42438050))
#define SPI1_FR_WCOLC_BIT                         (*(__O  uint32_t*)(0x42438054))
#define SPI1_CR_SSDIS_BIT                         (*(__IO uint32_t*)(0x42438190))
#define SPI1_CR_CPOL_BIT                          (*(__IO uint32_t*)(0x42438194))
#define SPI1_CR_CPHA_BIT                          (*(__IO uint32_t*)(0x42438198))
#define SPI1_CR_MSTR_BIT                          (*(__IO uint32_t*)(0x4243819C))
#define SPI1_CR_DIR_BIT                           (*(__IO uint32_t*)(0x424381A0))
#define SPI1_CR_SPDATL_BIT                        (*(__IO uint32_t*)(0x424381A4))
#define SPI1_CR_SPRIE_BIT                         (*(__IO uint32_t*)(0x424381A8))
#define SPI1_CR_SPTIE_BIT                         (*(__IO uint32_t*)(0x424381AC))
#define SPI1_CR_SPDMAR_BIT                        (*(__IO uint32_t*)(0x424381B0))
#define SPI1_CR_SPDMAT_BIT                        (*(__IO uint32_t*)(0x424381B4))
#define SPI1_CR_SPIEN_BIT                         (*(__IO uint32_t*)(0x424381B8))
#define SPI1_CR_SPSFF_BIT                         (*(__IO uint32_t*)(0x424381BC))
#define SPI1_CR_SPDATW_BIT                        (*(__IO uint32_t*)(0x424381C0))
#define TWI0_FR_TWINT_BIT                         (*(__I  uint32_t*)(0x42440000))
#define TWI0_FR_TFREE_BIT                         (*(__I  uint32_t*)(0x42440008))
#define TWI0_FR_TOUT_BIT                          (*(__I  uint32_t*)(0x4244000C))
#define TWI0_FR_TWINTC_BIT                        (*(__O  uint32_t*)(0x42440040))
#define TWI0_FR_TFREEC_BIT                        (*(__O  uint32_t*)(0x42440048))
#define TWI0_FR_TOUTC_BIT                         (*(__O  uint32_t*)(0x4244004C))
#define TWI0_ADDR_GC_BIT                          (*(__IO uint32_t*)(0x42440280))
#define TWI0_CR_AA_BIT                            (*(__IO uint32_t*)(0x42440300))
#define TWI0_CR_STO_BIT                           (*(__IO uint32_t*)(0x42440304))
#define TWI0_CR_STA_BIT                           (*(__IO uint32_t*)(0x42440308))
#define TWI0_CR_EFREE_BIT                         (*(__IO uint32_t*)(0x42440320))
#define TWI0_CR_ETOT_BIT                          (*(__IO uint32_t*)(0x42440324))
#define TWI0_CR_TWINTE_BIT                        (*(__IO uint32_t*)(0x42440328))
#define TWI0_CR_TWIEN_BIT                         (*(__IO uint32_t*)(0x4244033C))
#define TWI1_FR_TWINT_BIT                         (*(__I  uint32_t*)(0x42448000))
#define TWI1_FR_TFREE_BIT                         (*(__I  uint32_t*)(0x42448008))
#define TWI1_FR_TOUT_BIT                          (*(__I  uint32_t*)(0x4244800C))
#define TWI1_FR_TWINTC_BIT                        (*(__O  uint32_t*)(0x42448040))
#define TWI1_FR_TFREEC_BIT                        (*(__O  uint32_t*)(0x42448048))
#define TWI1_FR_TOUTC_BIT                         (*(__O  uint32_t*)(0x4244804C))
#define TWI1_ADDR_GC_BIT                          (*(__IO uint32_t*)(0x42448280))
#define TWI1_CR_AA_BIT                            (*(__IO uint32_t*)(0x42448300))
#define TWI1_CR_STO_BIT                           (*(__IO uint32_t*)(0x42448304))
#define TWI1_CR_STA_BIT                           (*(__IO uint32_t*)(0x42448308))
#define TWI1_CR_EFREE_BIT                         (*(__IO uint32_t*)(0x42448320))
#define TWI1_CR_ETOT_BIT                          (*(__IO uint32_t*)(0x42448324))
#define TWI1_CR_TWINTE_BIT                        (*(__IO uint32_t*)(0x42448328))
#define TWI1_CR_TWIEN_BIT                         (*(__IO uint32_t*)(0x4244833C))
#define LCD_CR_EN_BIT                             (*(__IO uint32_t*)(0x42470000))
#define LCD_CR_LCLK_BIT                           (*(__IO uint32_t*)(0x42470004))
#define LCD_CR_ELCC_BIT                           (*(__IO uint32_t*)(0x42470024))
#define LCD_CR_MODSW_BIT                          (*(__IO uint32_t*)(0x42470028))
#define LCD_CR_RLCD_BIT                           (*(__IO uint32_t*)(0x4247002C))
#define LCD_CR_CNTMOD_BIT                         (*(__IO uint32_t*)(0x42470040))
#define LED_CR_EN_BIT                             (*(__IO uint32_t*)(0x42468000))
#define LED_CR_LEDMD_BIT                          (*(__IO uint32_t*)(0x42468004))
#define LED_CR_MODE_BIT                           (*(__IO uint32_t*)(0x42468008))
#define LED_CR_MODSW_BIT                          (*(__IO uint32_t*)(0x4246800C))
#define LED_CR_IE_BIT                             (*(__IO uint32_t*)(0x42468010))
#define LED_CR_LEDMODSEL_BIT                      (*(__IO uint32_t*)(0x42468014))
#define LED_CR_LEDFY_BIT                          (*(__IO uint32_t*)(0x42468018))
#define LED_CR_LEDCY_BIT                          (*(__IO uint32_t*)(0x4246801C))
#define LED_CR_CNTMOD_BIT                         (*(__IO uint32_t*)(0x42468060))
#define LED_CR_LEDFDMA_BIT                        (*(__IO uint32_t*)(0x42468064))
#define LED_CR_LEDCDMA_BIT                        (*(__IO uint32_t*)(0x42468068))
#define LED_FR_COMIF_BIT                          (*(__I  uint32_t*)(0x42468080))
#define LED_FR_LEDIF_BIT                          (*(__I  uint32_t*)(0x42468084))
#define LED_FR_COMIFC_BIT                         (*(__O  uint32_t*)(0x424680C0))
#define LED_FR_LEDIFC_BIT                         (*(__O  uint32_t*)(0x424680C4))
#define TOUCHKEY_CR_TKCON_BIT                     (*(__IO uint32_t*)(0x42478000))
#define TOUCHKEY_CR_TKGO_DONE_BIT                 (*(__IO uint32_t*)(0x42478004))
#define TOUCHKEY_CR_DATACON_BIT                   (*(__IO uint32_t*)(0x42478008))
#define TOUCHKEY_CR_MODE_BIT                      (*(__IO uint32_t*)(0x4247800C))
#define TOUCHKEY_CR_IE_BIT                        (*(__IO uint32_t*)(0x42478018))
#define TOUCHKEY_CR_TKOSM_BIT                     (*(__IO uint32_t*)(0x4247803C))
#define TOUCHKEY_CR_TKOFFSET_BIT                  (*(__IO uint32_t*)(0x42478040))
#define TOUCHKEY_CR_TKRANDOM_BIT                  (*(__IO uint32_t*)(0x42478044))
#define TOUCHKEY_CR_TKHYSW_BIT                    (*(__IO uint32_t*)(0x42478048))
#define TOUCHKEY_CR_TKDMA_BIT                     (*(__IO uint32_t*)(0x42478064))
#define TOUCHKEY_CR_TK_BG_BIT                     (*(__IO uint32_t*)(0x42478068))
#define TOUCHKEY_FR_IFCOUNT_BIT                   (*(__I  uint32_t*)(0x42478080))
#define TOUCHKEY_FR_IFAVE_BIT                     (*(__I  uint32_t*)(0x42478084))
#define TOUCHKEY_FR_IFGO_BIT                      (*(__I  uint32_t*)(0x42478088))
#define TOUCHKEY_FR_IFERR_BIT                     (*(__I  uint32_t*)(0x4247808C))
#define TOUCHKEY_FR_IFCOUNTC_BIT                  (*(__O  uint32_t*)(0x424780C0))
#define TOUCHKEY_FR_IFAVEC_BIT                    (*(__O  uint32_t*)(0x424780C4))
#define TOUCHKEY_FR_IFGOC_BIT                     (*(__O  uint32_t*)(0x424780C8))
#define TOUCHKEY_FR_IFERRC_BIT                    (*(__O  uint32_t*)(0x424780CC))
#define TOUCHKEY_CR1_VSYSEN_BIT                   (*(__IO uint32_t*)(0x42478100))
#define TOUCHKEY_CR1_VPREEN_BIT                   (*(__IO uint32_t*)(0x42478124))
#define TOUCHKEY_CR1_ENCADJ_BIT                   (*(__IO uint32_t*)(0x42478134))
#define TOUCHKEY_CR1_ENCREF_BIT                   (*(__IO uint32_t*)(0x42478144))
#define TOUCHKEY_CR1_VCREF_BIT                    (*(__IO uint32_t*)(0x42478154))
#define TOUCHKEY_CR1_SHON_BIT                     (*(__IO uint32_t*)(0x42478158))
#define TOUCHKEY_CR1_TKIO_BIT                     (*(__IO uint32_t*)(0x4247815C))
#define TOUCHKEY_CR1_TKFL_BIT                     (*(__IO uint32_t*)(0x42478160))
#define TOUCHKEY_CR1_TKOP_BIT                     (*(__IO uint32_t*)(0x42478164))

#define BIT(module,reg,bitnum) (module##_##reg##_##bitnum)
#define BITBAND(addr,bitnum) *((uint32_t*)(((addr)&0xF0000000)+0x02000000 + ((((addr)&0xFFFFF)<<5)+((bitnum)<<2))))

#define GPIO_CFG_OFFSET    (GPIOA_BASE - GPIOA_CFG_BASE)
#define GPIOx(CFG)         ((GPIO_CFG_TypeDef*)  ((uint32_t)GPIOx - GPIO_CFG_OFFSET))  


#ifndef _NO_USER_CONFIG
//#include "sh32f2xx_config.h"
#endif


#ifdef __cplusplus
}  /*extern "C"*/
#endif

#endif /*__SH32F9XX_SB0_H__*/
/******************* (C) COPYRIGHT 2020 Sinowealth *****END OF FILE****/

