/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_rcc.h
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file provides reset and clock module's APIs
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
  * <h2><center>&copy; COPYRIGHT 2020 Sinowealth</center></h2>
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SH32F9XX_SB0_RCC_H
#define __SH32F9XX_SB0_RCC_H


/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "sh32f9xx_sb0_libcfg.h"


/** @addtogroup sh32f9xx_sb0_StdLib_Driver
  * @{
  */

/** @defgroup RCC_Group_Constant  Public Constants
  * @{
  */ 
/*!< CLOCK SOURCE CONSTANT */
typedef enum {
    RCC_SYS_SRC_HSI  = 0,
    RCC_SYS_SRC_PLL  = 1,
    RCC_SYS_SRC_LSE  = 2,
    RCC_SYS_SRC_HSE  = 3,
    RCC_SYS_SRC_LSI  = 4,
}RCC_SysSource_Type;

typedef enum {
    PLL_SRC_HSI   = 0,
    PLL_SRC_HSE   = 1,
}RCC_PLL_SRC_Type;

/*! @struct  RCC_Clocks_TypeDef
  *  RCC structure of clock frequency datas, used to get current system's clock frequency
  */    
typedef struct
{
    uint32_t sysFreq;  /*!<  System clock frequency, unit is Hz */
    uint32_t hclkFreq;    /*!< AHB bus clock frequency, unit is Hz */
    uint32_t pclk0Freq;   /*!< APB0 bus clock frequency, unit is Hz */
    uint32_t pclk1Freq;   /*!< APB1 bus clock frequency, unit is Hz */
}RCC_Clocks_TypeDef;


/*!  RCC AHB Modules */
typedef enum{
    RCC_AHB_PCA0       = RCC_AHBENR_PCA0EN_Msk,
    RCC_AHB_PCA1       = RCC_AHBENR_PCA1EN_Msk,
    RCC_AHB_PCA        = RCC_AHB_PCA0  | RCC_AHB_PCA1,
    RCC_AHB_IOCLK      = RCC_AHBENR_IOCLKEN_Msk,
    RCC_AHB_SYSCFG     = RCC_AHBENR_SYSCFGEN_Msk,
    RCC_AHB_DMA        = RCC_AHBENR_DMAEN_Msk,
    RCC_AHB_CRC        = RCC_AHBENR_CRCEN_Msk,
    RCC_AHB_RAMBIST    = RCC_AHBENR_RAMBISTEN_Msk,
    RCC_AHB_NTESTEN    = RCC_AHBENR_NTESTEN_Msk,
}RCC_AHB_Type;

/*! All AHB  Modules */
#define RCC_AHB_ALL    (0x01F7)

/*! check AHB Module source */
#define IS_AHB_MODULES(m)   ((((m ) & RCC_AHB_ALL) != 0) && (((m) & (~RCC_AHB_ALL)) == 0))

/*!  RCC APB1 Modules */
typedef enum{
    RCC_APB0_TIM5  = RCC_APB0ENR_TIM5EN_Msk,
    RCC_APB0_TIM6  = RCC_APB0ENR_TIM6EN_Msk,
    RCC_APB0_TIM7  = RCC_APB0ENR_TIM7EN_Msk,
    RCC_APB0_TIM8  = RCC_APB0ENR_TIM8EN_Msk,
    RCC_APB0_PWM0  = RCC_APB0ENR_PWM0EN_Msk,
    RCC_APB0_PWM1  = RCC_APB0ENR_PWM1EN_Msk,
    RCC_APB0_PWM2  = RCC_APB0ENR_PWM2EN_Msk,
    RCC_APB0_PWM3  = RCC_APB0ENR_PWM3EN_Msk,
    RCC_APB0_PCA2  = RCC_APB0ENR_PCA2EN_Msk,
    RCC_APB0_PCA3  = RCC_APB0ENR_PCA3EN_Msk,
    RCC_APB0_PCA4  = RCC_APB0ENR_PCA4EN_Msk,
    RCC_APB0_PCA5  = RCC_APB0ENR_PCA5EN_Msk,
    RCC_APB0_PCA6  = RCC_APB0ENR_PCA6EN_Msk,
    RCC_APB0_PCA7  = RCC_APB0ENR_PCA7EN_Msk,
    RCC_APB0_EXTI  = RCC_APB0ENR_EXTIEN_Msk,
    RCC_APB0_WWDT  = RCC_APB0ENR_WWDTEN_Msk,
}RCC_APB0_Type;

/*! All APB0  Modules */
#define RCC_APB0_ALL    (0xFFFF)

/*! check APB0 clock source */
#define IS_APB0_MODULES(m) ((((m ) & RCC_APB0_ALL) != 0) && (((m) & (~RCC_APB0_ALL)) == 0))

/*!  RCC APB1 Modules */
typedef enum{
    RCC_APB1_UART0  = RCC_APB1ENR_UART0EN_Msk,
    RCC_APB1_UART1  = RCC_APB1ENR_UART1EN_Msk,
    RCC_APB1_UART2  = RCC_APB1ENR_UART2EN_Msk,
    RCC_APB1_UART3  = RCC_APB1ENR_UART3EN_Msk,
    RCC_APB1_UART4  = RCC_APB1ENR_UART4EN_Msk,
    RCC_APB1_UART5  = RCC_APB1ENR_UART5EN_Msk,
    RCC_APB1_SPI0   = RCC_APB1ENR_SPI0EN_Msk,
    RCC_APB1_SPI1   = RCC_APB1ENR_SPI1EN_Msk,
    RCC_APB1_TWI0   = RCC_APB1ENR_TWI0EN_Msk,
    RCC_APB1_TWI1   = RCC_APB1ENR_TWI1EN_Msk,
    RCC_APB1_AMOC   = RCC_APB1ENR_AMOCEN_Msk,
    RCC_APB1_ADC    = RCC_APB1ENR_ADCEN_Msk,
    RCC_APB1_LCD    = RCC_APB1ENR_LCDEN_Msk,
    RCC_APB1_LED    = RCC_APB1ENR_LEDEN_Msk,
    RCC_APB1_TK     = RCC_APB1ENR_TKEN_Msk,
}RCC_APB1_Type;

/*! All APB1  Modules */
#define RCC_APB1_ALL    (0x7FFF)

/*! check APB1 clock source */
#define IS_APB1_MODULES(m) ((((m ) & RCC_APB1_ALL) != 0) && (((m) & (~RCC_APB1_ALL)) == 0))

/*!  RCC RSTSTR Modules */
typedef enum{
    RCC_RST_PIN         = RCC_RSTCLR_PINRSTFC_Msk,  
    RCC_RST_LVR         = RCC_RSTCLR_LVRSTFC_Msk,
    RCC_RST_POWERON     = RCC_RSTCLR_PORSTFC_Msk, 
    RCC_RST_SOFTWARE    = RCC_RSTCLR_SWRSTFC_Msk,
    RCC_RST_IWDT        = RCC_RSTCLR_IWDTRSTFC_Msk,
    RCC_RST_WWDT        = RCC_RSTCLR_WWDTRSTFC_Msk, 
    RCC_RST_VCCLVR      = RCC_RSTCLR_LVRSTF2C_Msk, 
}RCC_RESET_Type;

/*! All RST  Modules */
#define RCC_RST_ALL    (0x007F)

/*! check RST clock source */
#define IS_RST_MODULES(m) ((((m ) & RCC_RST_ALL) != 0) && (((m) && (~RCC_RST_ALL)) == 0))
/** 
  *@brief  Unlock the RCC module's regsiter. RCC registers can be modified.
  */
#define RCC_REGS_UNLOCK() RCC->RCCLOCK=0x33CC

/** 
  *@brief  Lock the RCC module's regsiter. RCC registers cannot be modified.
  */
#define RCC_REGS_LOCK()   RCC->RCCLOCK=0

  
/*!  RCC CSM Modules */
typedef enum{
    RCC_CSM_LSE         = RCC_CISTR_CSMLSEF_Msk,
    RCC_CSM_HSE         = RCC_CISTR_CSMHSEF_Msk,
    RCC_CSM_PLL         = RCC_CISTR_CSMPLLF_Msk,  
}RCC_CSMF_Type; 


/*!  RCC CSM select frequency */
typedef enum{
    RCC_CSMSEL_4M         = 0X00,
    RCC_CSMSEL_6M         = 0X01,
    RCC_CSMSEL_8M         = 0X02, 
    RCC_CSMSEL_12M        = 0X03,
    RCC_CSMSEL_32K        = 0X04,
}RCC_CSMSEL_Type; 

/**
  * @}
  */ 
/*! All CSMF  Modules */
#define RCC_CSMF_ALL    (0xE0)

/*! check CSM  source */
#define IS_CSM_MODULES(m) ((((m ) & RCC_CSMF_ALL) != 0) && (((m) & (~RCC_CSMF_ALL)) == 0))


  
/**
  * @}
  */ 

/* get current clock requency*/
void RCC_GetClocksFreq(RCC_Clocks_TypeDef *Clocks);

/* configure AHB modules' clock gate */ 
void RCC_AHBPeriphClockOnOff(RCC_AHB_Type AHBModules,CmdState OnOffState);

/* configure APB1 modules' clock gate */ 
void RCC_APB1PeriphClockOnOff(RCC_APB1_Type APB1Modules,CmdState OnOffState);

/* configure APB0 modules' clock gate */ 
void RCC_APB0PeriphClockOnOff(RCC_APB0_Type APB0Modules,CmdState OnOffState);

/* reset AHB modules*/ 
void RCC_AHBPeriphReset(uint32_t AHBModules);

/* reset APB0 modules*/ 
void RCC_APB0PeriphReset(uint32_t APB0Modules);

/* reset APB1 modules*/ 
void RCC_APB1PeriphReset(uint32_t APB1Modules);

/* Get RCC reset flag*/
FlagStatus RCC_GetResetFlag(RCC_RESET_Type ResetFlag);

/* clear RCC reset flags*/
void RCC_ClearResetFlag(RCC_RESET_Type ResetFlags);

/** @defgroup CSM_Exported_Functions
  * @{
  */

/* Get RCC CSM flag. */
FlagStatus RCC_GetCsmFStatus(RCC_CSMF_Type CSMFlag);

/* open or close CSM modules. */
void  RCC_CSMModuleOnOff(CmdState OnOffState);

/* open or close RCC->CR. */
void  RCC_CRRegOnOff(uint32_t TriggerSource,CmdState OnOffState);

/* CSM select frequty. */
void  RCC_CSMSelectFreq(RCC_CSMSEL_Type CSMSelFreq);

/* Clear CSM interrupt flag. */
void  RCC_CSMClearIF(FlagStatus SetResetState);

/* Configure PLL on or off. */
void RCC_PLLONorOFF(CmdState OnOffState);

/* Use HSI as system source, AHB \ APB0\ APB1 is all 12M. */
void  sys_HSI12M_RC(void);

/* Use HSI as system source, AHB \ APB0\ APB1 is all 24M. */
void  sys_HSI24M_RC(void);

/**
  * @}
  */ 

/**
  * @}
  */ 
#endif
/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
