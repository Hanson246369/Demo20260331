/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_timer.h
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file contains all the functions prototypes for the TIMER firmware
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
  * <h2><center>&copy; COPYRIGHT 2020 Sinowealth</center></h2>
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SH32F9XX_SB0_TIMER_H
#define __SH32F9XX_SB0_TIMER_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"

/** @addtogroup sh32f9xx_sb0_StdLib_Driver
  * @{
  */

/** @addtogroup TIM_MODULE
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/

/** @defgroup TIM_Exported_Types
  * @{
  */
  
typedef struct
{
    uint32_t TIM_Prescaler;   /*!< Specifie the TIM prescaler value.
                                   This parameter can be 0 to 0xFFFF */
                                   
    uint32_t TIM_Period;      /*!< Specifie the TIM period value.
                                   This parameter can be 0 to 0xFFFF */ 
                                   
    uint16_t TIM_CLKSource;   /*!< Specifie the TIM's clock sources.
                                   This parameter can be a value of @ref TIM_Clock_Sources */
                                   
    uint16_t TIM_OPMode;      /*!< Specifie the TIM OP mode.
                                   This parameter can be a value of @ref TIM_OP_Mode */

    uint16_t TIM_TCMode;      /*!< Specifie the Compare output.
                                   This parameter can be a value of @ref TIM_TC_Mode */
}TIM_InitTypeDef;

/**
  * @}
  */

  
/* Exported constants --------------------------------------------------------*/

/** @defgroup TIM_Exported_Constants
  * @{
  */ 
  
#define IS_TIM_ALL_PERIPH(PERIPH)  ((PERIPH == TIM5) || (PERIPH == TIM6) \
                                   || (PERIPH == TIM7) || (PERIPH == TIM8))
     
/** @defgroup TIM_Clock_Sources
  * @{
  */   
  
#define TIM_CLKSource_PCLK             (uint16_t)0x0000
#define TIM_CLKSource_INPUT            (uint16_t)0x0010
#define TIM_CLKSource_LSECLK           (uint16_t)0x0020
#define TIM_CLKSource_LSICLK           (uint16_t)0x0030
#define IS_TIM_CLK_SOURCE(SOURCE)      ((SOURCE == TIM_CLKSource_PCLK) \
                                       || (SOURCE == TIM_CLKSource_INPUT) \
                                       || (SOURCE == TIM_CLKSource_LSECLK)\
                                       || (SOURCE == TIM_CLKSource_LSICLK))  
/**
  * @}
  */     
     


/** @defgroup TIM_OP_Mode
  * @{
  */  
  
#define TIM_OPMode_Continue    (uint16_t)0x0000
#define TIM_OPMode_OnePulse    (uint16_t)0x0008
#define IS_TIM_OP_MODE(MODE)   ((MODE == TIM_OPMode_Continue) \
                               || (MODE == TIM_OPMode_OnePulse))
  
/** @defgroup TIM_TC_Mode
  * @{
  */  
  
#define TIM_TCMode_Disable     (uint16_t)0x0000
#define TIM_TCMode_Enable      (uint16_t)0x0400
#define IS_TIM_TC_MODE(MODE)   ((MODE == TIM_TCMode_Enable) \
                               || (MODE == TIM_TCMode_Disable))
     




/** @defgroup TIM_Cascade
  * @{
  */    
  
#define IS_TIM_CASCADE_PERIPH(PERIPH)  ((PERIPH == TIM5) || (PERIPH == TIM7))
  
/**
  * @}
  */


/**
  * @}
  */ 


/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/* Reset the TIMx peripheral registers to their default reset values. */
void TIM_Reset(TIMER_TypeDef *TIMx);

/* Fills each TIM_InitStruct member with its default value. */
void TIM_StructInit(TIM_InitTypeDef *TIM_InitStruct);

/* Initializes the TIMx peripheral according to the specified parameters in the TIM_InitStruct. */
void TIM_Init(TIMER_TypeDef *TIMx, TIM_InitTypeDef *TIM_InitStruct);

/* Enable or disable the specified TIM interrupt. */
void TIM_INTConfig(TIMER_TypeDef *TIMx,    FunctionalState NewState);

/* Open or close the TIM peripheral. */
void TIM_OnOff(TIMER_TypeDef *TIMx, CmdState OnOffState);

/* Open or close the TIM peripheral. */
void TIM_CascadeOnOff(TIMER_TypeDef *TIMx, CmdState OnOffState);

/* Enable or disable the TIMx's output pin. */
void TIM_OutPutConfig(TIMER_TypeDef *TIMx, FunctionalState NewState);

/* Enable or disable the TIMx's trigger CM3 core function. */
void TIM_CM3EventTrigger(TIMER_TypeDef *TIMx, FunctionalState NewState);

/* Enable or disable the TIMx's trigger function. */
void TIM_ExtPeripheralsTrigger(TIMER_TypeDef* TIMx, FunctionalState NewState);

/* Check whether the specified TIM flag is set or not. */
FlagStatus TIM_GetFlagStatus(TIMER_TypeDef *TIMx);

/* Clear the TIMx's pending flag. */
void TIM_ClearFlag(TIMER_TypeDef *TIMx);

/* Get the TIMx Period Register value. */
uint32_t TIM_GetCounter(TIMER_TypeDef *TIMx);

/* Get the TIMx Period Register value. */
uint32_t TIM_GetPrescaler(TIMER_TypeDef *TIMx);

/* Get the TIMx Period Register value. */
uint32_t TIM_GetPeriod(TIMER_TypeDef *TIMx);

/* Set the TIMx Counter Register value. */
void TIM_SetCounter(TIMER_TypeDef *TIMx, uint32_t Counter);

/* Set the TIMx Prescaler Register value. */
void TIM_SetPrescaler(TIMER_TypeDef *TIMx, uint32_t Prescaler);

/* Set the TIMx Period Register value. */
void TIM_SetPeriod(TIMER_TypeDef *TIMx, uint32_t Period);






#ifdef __cplusplus
}
#endif

#endif /*__SH32F9XX_SB0_TIMER_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
