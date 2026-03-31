
#ifndef __SYSTEM_SH32F9xx_SB0_H_
#define __SYSTEM_SH32F9xx_SB0_H_

#ifdef __cplusplus
 extern "C" {
#endif 

/*********************************Includes**********************************/
#include "sh32f9xx_sb0.h"

/**************************RCC CLOCK Bit Macro******************************/
#define  RCC_CR_CSMON                        ((uint32_t)RCC_CR_CSMON_Msk)         /*CSM module enable */
#define  RCC_CR_HSION                        ((uint32_t)RCC_CR_HSION_Msk)         /*Internal High Speed clock enable */
#define  RCC_CR_HSIRDY                       ((uint32_t)RCC_CR_HSIRDY_Msk)        /*Internal High Speed clock ready flag */
#define  RCC_CR_HSEON                        ((uint32_t)RCC_CR_HSEON_Msk)         /*External High Speed clock enable */
#define  RCC_CR_HSERDY                       ((uint32_t)RCC_CR_HSERDY_Msk)        /*External High Speed clock ready flag */
#define  RCC_CR_PLLON                        ((uint32_t)RCC_CR_PLLON_Msk)         /*PLL enable */
#define  RCC_CR_PLLRDY                       ((uint32_t)RCC_CR_PLLRDY_Msk)        /*PLL clock ready flag */
#define  RCC_CR_LSEON                        ((uint32_t)RCC_CR_LSEON_Msk)         /*External Low Speed clock enable */
#define  RCC_CR_LSERDY                       ((uint32_t)RCC_CR_LSERDY_Msk)        /*External Low Speed clock ready flag */
#define  RCC_CR_LSION                        ((uint32_t)RCC_CR_LSION_Msk)         /*Internal Low Speed clock enable */
#define  RCC_CR_LSIRDY                       ((uint32_t)RCC_CR_LSIRDY_Msk)        /*Internal Low Speed clock enable */




/**************************Oscillator Startup TIMEOUT VALUE*****************/
#define HIGH_SPEED_CLOCK_STARTUP_TIMEOUT   ((uint16_t)0x3FFF)   /*Timeout for High Speed oscillator start up */
#define LOW_SPEED_CLOCK_STARTUP_TIMEOUT    ((uint32_t)0x3FFFFF) /*Timeout for Low Speed oscillator start up */

/********************Oscillator Value define Macro***********************/
#ifndef HSE_VALUE
#define HSE_VALUE    ((uint32_t)8000000) /*Value of the External High speed oscillator in Hz */
#endif

#ifndef HSI_VALUE
#define HSI_VALUE    ((uint32_t)24000000) /*Value of the Internal High oscillator in Hz */
#endif

#ifndef LSE_VALUE
#define LSE_VALUE    ((uint32_t)32768) /*Value of the External Low Speed oscillator in Hz */
#endif

#ifndef LSI_VALUE
#define LSI_VALUE    ((uint32_t)128000) /*Value of the Internal Low Speed oscillator in Hz */
#endif



/****System Clock Freqency Select,User Can Only Select One Macro to decide which frequency will MCU Run*****/

/* #define SYSCLK_FREQ_HSE    HSE_VALUE */
// #define SYSCLK_FREQ_HSI    HSI_VALUE 
// #define SYSCLK_FREQ_LSE    LSE_VALUE 
/* #define SYSCLK_FREQ_LSI    LSI_VALUE */
/* #define SYSCLK_FREQ_24MHz  24000000 */
/* #define SYSCLK_FREQ_36MHz  36000000 */
/* #define SYSCLK_FREQ_48MHz  48000000 */
/* #define SYSCLK_FREQ_56MHz  56000000 */
 #define SYSCLK_FREQ_72MHz  72000000          


/********************Default Oscillator Select****************************************/
#define HIGH_SPEED_OSCILLATOR_SOURCE   0 // 0 for HSI,Nonzero Value for HSE source


/********************System Clock Source Enum***************************************/
typedef enum 
{ 
    SYSTEM_CLK_SRC_HSI = 0,
    SYSTEM_CLK_SRC_PLL,
    SYSTEM_CLK_SRC_LSE,
    SYSTEM_CLK_SRC_HSE,
    SYSTEM_CLK_SRC_LSI
}SystemClockSource; 

/*******************Global Varible Declaration*******************************/
extern uint32_t SystemCoreClock;          /*System Clock Frequency (HCLK) */
  
 
/********************Global Function Declaration****************************************/
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);


#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_SH32F9xx_SB0_H_ */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
