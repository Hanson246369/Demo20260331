/**
  ******************************************************************************
  * @file    system_sh30f9xx_sa0.h
  * @author  sinowealth
  * @version V1.1.0
  * @date    2021-06-10  
  * @brief   This file contains all the functions prototypes for the SYSTEM firmware
  *          library.
  ******************************************************************************
  * @attention
  *
  * SINOWEALTH IS SUPPLYING THIS SOFTWARE FOR USE EXCLUSIVELY SH_ON SINOWEALTH'S 
  * MICROCONTROLLER PRODUCTS. IT IS PROTECTED UNDER APPLICABLE COPYRIGHT LAWS. 
  * THIS SOFTWARE IS FOR GUIDANCE IN ORDER TO SAVE TIME. AS A RESULT, SINOWEALTH 
  * SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES 
  * WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH FIRMWARE AND/OR
  * THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN IN 
  * CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2021 Sinowealth</center></h2>
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYSTEM_SH30F9XX_SA0_H_
#define __SYSTEM_SH30F9XX_SA0_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************Includes**********************************/
#include "sh30f9xx_sa0.h"

/**************************RCC CLOCK Bit Macro******************************/
#define RCC_CR_CSMON  ((uint32_t)RCC_CR_CSMON_Msk )   /*CSM module enable */
#define RCC_CR_HSION  ((uint32_t)RCC_CR_HSION_Msk )   /*Internal High Speed clock enable */
#define RCC_CR_HSIRDY ((uint32_t)RCC_CR_HSIRDY_Msk)   /*Internal High Speed clock ready flag */
#define RCC_CR_HSEON  ((uint32_t)RCC_CR_HSEON_Msk )   /*External High Speed clock enable */
#define RCC_CR_HSERDY ((uint32_t)RCC_CR_HSERDY_Msk)   /*External High Speed clock ready flag */
#define RCC_CR_PLLON  ((uint32_t)RCC_CR_PLLON_Msk )   /*PLL enable */
#define RCC_CR_PLLRDY ((uint32_t)RCC_CR_PLLRDY_Msk)   /*PLL clock ready flag */
#define RCC_CR_LSEON  ((uint32_t)RCC_CR_LSEON_Msk )   /*External Low Speed clock enable */
#define RCC_CR_LSERDY ((uint32_t)RCC_CR_LSERDY_Msk)   /*External Low Speed clock ready flag */
#define RCC_CR_LSION  ((uint32_t)RCC_CR_LSION_Msk )   /*Internal Low Speed clock enable */
#define RCC_CR_LSIRDY ((uint32_t)RCC_CR_LSIRDY_Msk)   /*Internal Low Speed clock enable */

/**************************Oscillator Startup TIMEOUT VALUE*****************/
#define HIGH_SPEED_CLOCK_STARTUP_TIMEOUT ((uint16_t)0x3FFF)  /*Timeout for High Speed oscillator start up */
#define LOW_SPEED_CLOCK_STARTUP_TIMEOUT ((uint32_t)0x3FFFFF) /*Timeout for Low Speed oscillator start up */

/********************Oscillator Value define Macro***********************/
#ifndef HSE_VALUE
#define HSE_VALUE ((uint32_t)8000000) /*Value of the External High speed oscillator in Hz */
#endif

#ifndef HSI_VALUE
#define HSI_VALUE ((uint32_t)24000000) /*Value of the Internal High oscillator in Hz */
#endif

#ifndef LSE_VALUE
#define LSE_VALUE ((uint32_t)32768) /*Value of the External Low Speed oscillator in Hz */
#endif

#ifndef LSI_VALUE
#define LSI_VALUE ((uint32_t)128000) /*Value of the Internal Low Speed oscillator in Hz */
#endif

#ifndef LSI_VALUE_DIV4
#define LSI_VALUE_DIV4 ((uint32_t)32000) /*Value of the Internal Low Speed oscillator divid 4 in Hz */
#endif

  /****System Clock Freqency Select,User Can Only Select One Macro to decide which frequency will MCU Run*****/

// #define SYSCLK_FREQ_HSE         HSE_VALUE
 #define SYSCLK_FREQ_HSI         HSI_VALUE
// #define SYSCLK_FREQ_LSE         LSE_VALUE
// #define SYSCLK_FREQ_LSI         LSI_VALUE
// #define SYSCLK_FREQ_LSI_DIV4    LSI_VALUE_DIV4
// #define SYSCLK_FREQ_12MHz       12000000
// #define SYSCLK_FREQ_24MHz       24000000
// #define SYSCLK_FREQ_36MHz       36000000
//#define SYSCLK_FREQ_48MHz       48000000

/********************Default Oscillator Select****************************************/
#define HIGH_SPEED_OSCILLATOR_SOURCE 0 // 0 for HSI,Nonzero Value for HSE source

/********************System Clock Source Enum***************************************/
typedef enum 
{ 
    SYSTEM_CLK_SRC_HSI = 0,
    SYSTEM_CLK_SRC_PLL,
    SYSTEM_CLK_SRC_LSE,
    SYSTEM_CLK_SRC_HSE,
    SYSTEM_CLK_SRC_LSI,
    SYSTEM_CLK_SRC_LSI_DIV4
}SystemClockSource; 


  /*******************Global Varible Declaration*******************************/
  extern uint32_t SystemCoreClock; /*System Clock Frequency (HCLK) */

  /********************Global Function Declaration****************************************/
  extern void SystemInit(void);
  extern void SystemCoreClockUpdate(void);

#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_SH30F9XX_SA0_H_ */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
