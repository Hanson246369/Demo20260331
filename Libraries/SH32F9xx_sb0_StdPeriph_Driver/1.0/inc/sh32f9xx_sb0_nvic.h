/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_nvic.h
  * @author  sinowealth
  * @version V1.1.0
  * @date    22020-09-21  
  * @brief   This file contains all the functions prototypes for the PPP firmware
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
#ifndef __SH32F9XX_SB0_NVIC_H
#define __SH32F9XX_SB0_NVIC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"


/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/** @addtogroup NVIC_MODULE
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup NVIC_Exported_Constants
  * @{
  */ 

    
#define NVIC_VectTab_RAM             ((uint32_t)0x20000000)
#define NVIC_VectTab_FLASH           ((uint32_t)0x00000000)
    

typedef struct
{
    uint8_t NVIC_IRQChannel;                    /*!< Specifies the IRQ channel to be enabled or disabled.
                                                   This parameter can be an enumerator of @ref IRQn_Type 
                                                   enumeration (please refer to sh32f90xx.h file) */
                                                   
    uint8_t NVIC_IRQChannelPreemptionPriority;  /*!< Specifies the pre-emption priority for the IRQ channel
                                                   specified in NVIC_IRQChannel. */
                                                    
    uint8_t NVIC_IRQChannelSubPriority;         /*!< Specifies the subpriority level for the IRQ channel specified
                                                   in NVIC_IRQChannel. */
                                                    
    FunctionalState NVIC_IRQChannelCmd;         /*!< Specifies whether the IRQ channel defined in NVIC_IRQChannel
                                                   will be enabled or disabled. This parameter can be set either 
                                                   to SH_ENABLE or SH_DISABLE */
}NVIC_InitTypeDef;
    
    
#define NVIC_LP_SEVONPEND            ((uint8_t)0x10)
#define NVIC_LP_SLEEPDEEP            ((uint8_t)0x04)
#define NVIC_LP_SLEEPONEXIT          ((uint8_t)0x02)

/** @defgroup QEI_DMA_Request_Source 
  * @{
  */ 

#define NVIC_PriorityGroup_0         ((uint32_t)0x700) /* 0 bits for pre-emption priority
                                                          4 bits for subpriority */
#define NVIC_PriorityGroup_1         ((uint32_t)0x600) /* 1 bits for pre-emption priority
                                                          3 bits for subpriority */
#define NVIC_PriorityGroup_2         ((uint32_t)0x500) /* 2 bits for pre-emption priority
                                                          2 bits for subpriority */
#define NVIC_PriorityGroup_3         ((uint32_t)0x400) /* 3 bits for pre-emption priority
                                                          1 bits for subpriority */
#define NVIC_PriorityGroup_4         ((uint32_t)0x300) /* 4 bits for pre-emption priority
                                                          0 bits for subpriority */

#define IS_NVIC_PRIORITY_GROUP(GROUP)   ((GROUP == NVIC_PriorityGroup_0) \
                                        || (GROUP == NVIC_PriorityGroup_1) \
                                        || (GROUP == NVIC_PriorityGroup_2) \
                                        || (GROUP == NVIC_PriorityGroup_3) \
                                        || (GROUP == NVIC_PriorityGroup_4))

/**
  * @}
  */

    

    

/**
  * @}
  */ 


/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/* Fills each NVIC_InitStruct member with its default value. */
void NVIC_StructInit(NVIC_InitTypeDef *NVIC_InitStruct);

/* Initializes the NVIC peripheral according to the specified parameters in the NVIC_InitStruct. */
void NVIC_Init(NVIC_InitTypeDef *NVIC_InitStruct);

/* Configures the priority grouping: pre-emption priority and subpriority. */
void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup);

/* Sets the vector table location and Offset. */
void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset);

/* Config SysTick timer. */
void SysTick_TimeConfig(uint16_t MilliSecond);

/* Get the SysTick Counter value. */
uint32_t SysTick_GetCounter(void);



#ifdef __cplusplus
}
#endif

#endif /*__SH32F9XX_SB0_NVIC_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */ 
/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
