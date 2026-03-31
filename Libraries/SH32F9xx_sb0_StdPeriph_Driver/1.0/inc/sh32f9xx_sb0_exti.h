/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_exti.h
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
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
#ifndef __SH32F9XX_SB0_EXTI_H
#define __SH32F9XX_SB0_EXTI_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"

/** @addtogroup sh32f9xx_sb0_StdLib_Driver
  * @{
  */

/** @addtogroup EXTI_MODULE
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/

/** @defgroup EXTI_Exported_Types
  * @{
  */


/** 
  * @brief  EXTI mode enumeration  
  */

typedef enum
{
    EXTI_Mode_Interrupt   = 0x00,
    EXTI_Mode_WakeupEvent = 0x04,
    EXTI_Mode_DMAEvent    = 0x2C
}EXTIMode_TypeDef;

#define IS_EXTI_MODE(MODE)    ((MODE == EXTI_Mode_Interrupt) \
                              || (MODE == EXTI_Mode_WakeupEvent) \
                              || (MODE ==EXTI_Mode_DMAEvent))

/** 
  * @brief  EXTI Trigger enumeration  
  */

typedef enum
{
    EXTI_Trigger_Rising  = 0x0C,
    EXTI_Trigger_Falling = 0x10,  
    EXTI_Trigger_Rising_Falling = 0x0F,
    EXTI_Trigger_HighLevel = 0x2C,
    EXTI_Trigger_LowLevel  = 0x30,
    EXTI_Trigger_HighLevel_LowLevel = 0x3F
}EXTITrigger_TypeDef;

#define IS_EXTI_TRIGGER(TRIGGER)   ((TRIGGER == EXTI_Trigger_Rising) \
                                   || (TRIGGER == EXTI_Trigger_Falling) \
                                   || (TRIGGER == EXTI_Trigger_Rising_Falling) \
                                   || (TRIGGER == EXTI_Trigger_HighLevel) \
                                   || (TRIGGER == EXTI_Trigger_LowLevel) \
                                   || (TRIGGER == EXTI_Trigger_HighLevel_LowLevel))

/** 
  * @brief  EXTI sample cycle enumeration  
  */

typedef enum
{
    EXTI_SampleCycle_1 = 0x00,
    EXTI_SampleCycle_2 = 0x01,
    EXTI_SampleCycle_3 = 0x02,
    EXTI_SampleCycle_4 = 0x03
}EXTISampleCycle_TypeDef;

#define IS_EXTI_SAMPLE_CYCLE(CYCLE)    ((CYCLE == EXTI_SampleCycle_1) \
                                       || (CYCLE == EXTI_SampleCycle_2) \
                                       || (CYCLE == EXTI_SampleCycle_3) \
                                       || (CYCLE == EXTI_SampleCycle_4))

                                       
/** 
  * @brief  EXTI sample clock division enumeration  
  */

typedef enum
{
    EXTI_SampleClockDivision_1   = 0x00,
    EXTI_SampleClockDivision_4   = 0x01,
    EXTI_SampleClockDivision_16  = 0x02,
    EXTI_SampleClockDivision_128 = 0x03
}EXTISampleClockDivision_TypeDef;

#define IS_EXTI_SAMPLE_CLOCK_DIV(DIV)   ((DIV == EXTI_SampleClockDivision_1) \
                                        || (DIV == EXTI_SampleClockDivision_4) \
                                        || (DIV == EXTI_SampleClockDivision_16) \
                                        || (DIV == EXTI_SampleClockDivision_128))

/** 
  * @brief  EXTI Init Structure definition  
  */

typedef struct
{
    uint32_t EXTI_Line;               /*!< Specifies the EXTI lines to be enabled or disabled.
                                           This parameter can be any combination value of @ref EXTI_Lines */
   
    EXTIMode_TypeDef EXTI_Mode;       /*!< Specifies the mode for the EXTI lines.
                                           This parameter can be a value of @ref EXTIMode_TypeDef */

    EXTITrigger_TypeDef EXTI_Trigger; /*!< Specifies the trigger signal active edge for the EXTI lines.
                                           This parameter can be a value of @ref EXTITrigger_TypeDef */
    EXTISampleCycle_TypeDef EXTI_SampleCycle;
    
    EXTISampleClockDivision_TypeDef EXTI_SampleClockDivision;
    
    uint8_t EXTI_LineCmd;             /*!< Specifies the new state of the selected EXTI lines.
                                           This parameter can be set either to SH_ENABLE or SH_DISABLE */ 
}EXTI_InitTypeDef;

/**
  * @}
  */


/* Exported constants --------------------------------------------------------*/

/** @defgroup EXTI_Exported_Constants
  * @{
  */


/** @defgroup EXTI_Lines
  * @{
  */
  
#define EXTI_Line0       ((uint32_t)0x00001)     /*!< External interrupt line 0 */
#define EXTI_Line1       ((uint32_t)0x00002)     /*!< External interrupt line 1 */
#define EXTI_Line2       ((uint32_t)0x00004)     /*!< External interrupt line 2 */
#define EXTI_Line3       ((uint32_t)0x00008)     /*!< External interrupt line 3 */
#define EXTI_Line4       ((uint32_t)0x00010)     /*!< External interrupt line 4 */
#define EXTI_Line5       ((uint32_t)0x00020)     /*!< External interrupt line 5 */
#define EXTI_Line6       ((uint32_t)0x00040)     /*!< External interrupt line 6 */
#define EXTI_Line7       ((uint32_t)0x00080)     /*!< External interrupt line 7 */
#define EXTI_Line8       ((uint32_t)0x00100)     /*!< External interrupt line 8 */
#define EXTI_Line9       ((uint32_t)0x00200)     /*!< External interrupt line 9 */
#define EXTI_Line10      ((uint32_t)0x00400)     /*!< External interrupt line 10 */
#define EXTI_Line11      ((uint32_t)0x00800)     /*!< External interrupt line 11 */
#define EXTI_Line12      ((uint32_t)0x01000)     /*!< External interrupt line 12 */
#define EXTI_Line13      ((uint32_t)0x02000)     /*!< External interrupt line 13 */
#define EXTI_Line14      ((uint32_t)0x04000)     /*!< External interrupt line 14 */
#define EXTI_Line15      ((uint32_t)0x08000)     /*!< External interrupt line 15 */

#define IS_EXTI_LINE(LINE)   (((LINE & (uint32_t)0xFFFF0000) == 0x00) && (LINE != 0x00))
 
#define IS_EXTI_GET_ONE_LINE(LINE)  ((LINE == EXTI_Line0)    || (LINE == EXTI_Line1)  \
                                    || (LINE == EXTI_Line2)  || (LINE == EXTI_Line3)  \
                                    || (LINE == EXTI_Line4)  || (LINE == EXTI_Line5)  \
                                    || (LINE == EXTI_Line6)  || (LINE == EXTI_Line7)  \
                                    || (LINE == EXTI_Line8)  || (LINE == EXTI_Line9)  \
                                    || (LINE == EXTI_Line10) || (LINE == EXTI_Line11) \
                                    || (LINE == EXTI_Line12) || (LINE == EXTI_Line13) \
                                    || (LINE == EXTI_Line14) || (LINE == EXTI_Line15))

/**
  * @}
  */


/** @defgroup EXTI_Port_Sources
  * @{
  */

typedef enum
{
    EXTI_Port_GPIOA = 0,
    EXTI_Port_GPIOB = 1,
    EXTI_Port_GPIOC = 2,
    EXTI_Port_GPIOD = 3,
    EXTI_Port_GPIOE = 4,
}EXTI_Port_Type;

#define IS_EXTI_PORT_SOURCE(SOURCE)     ((SOURCE == EXTI_Port_GPIOA)   \
                                        || (SOURCE == EXTI_Port_GPIOB) \
                                        || (SOURCE == EXTI_Port_GPIOC) \
                                        || (SOURCE == EXTI_Port_GPIOD) \
                                        || (SOURCE == EXTI_Port_GPIOE))

/**
  * @}
  */



/** @defgroup EXTI_Pin_Sources
  * @{
  */
  
typedef enum
{
   EXTI_PinSource0  = 0,
   EXTI_PinSource1  = 1,
   EXTI_PinSource2  = 2,
   EXTI_PinSource3  = 3,
   EXTI_PinSource4  = 4,
   EXTI_PinSource5  = 5,
   EXTI_PinSource6  = 6,
   EXTI_PinSource7  = 7,
   EXTI_PinSource8  = 8,
   EXTI_PinSource9  = 9,
   EXTI_PinSource10 = 10,
   EXTI_PinSource11 = 11,
   EXTI_PinSource12 = 12,
   EXTI_PinSource13 = 13,
   EXTI_PinSource14 = 14,
   EXTI_PinSource15 = 15,
}EXTI_PIN_Type;

#define IS_EXTI_PIN_SOURCE(SOURCE)  ((SOURCE == EXTI_PinSource0)   \
                                    || (SOURCE == EXTI_PinSource1) \
                                    || (SOURCE == EXTI_PinSource2) \
                                    || (SOURCE == EXTI_PinSource3) \
                                    || (SOURCE == EXTI_PinSource4) \
                                    || (SOURCE == EXTI_PinSource5) \
                                    || (SOURCE == EXTI_PinSource6) \
                                    || (SOURCE == EXTI_PinSource7) \
                                    || (SOURCE == EXTI_PinSource8) \
                                    || (SOURCE == EXTI_PinSource9) \
                                    || (SOURCE == EXTI_PinSource10) \
                                    || (SOURCE == EXTI_PinSource11) \
                                    || (SOURCE == EXTI_PinSource12) \
                                    || (SOURCE == EXTI_PinSource13) \
                                    || (SOURCE == EXTI_PinSource14) \
                                    || (SOURCE == EXTI_PinSource15))

/**
  * @}
  */



/**
  * @}
  */ 


/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/ 

/** @defgroup EXTI_Exported_Functions
  * @{
  */
  
/*Reset the EXTI peripheral registers to their default reset values.*/
extern void EXTI_Reset(void);
  
/*Initializes the EXTI peripheral according to the specified parameters in the EXTI_InitStruct.*/
extern void EXTI_Init(EXTI_InitTypeDef *EXTI_InitStruct);
  
/*Fills each EXTI_InitStruct member with its reset value.*/
extern void EXTI_StructInit(EXTI_InitTypeDef *EXTI_InitStruct);
  
/*Select the GPIO pin used as EXTI Line.*/
extern void EXTI_PinConfig(EXTI_Port_Type EXTI_PortSourceGPIOx, EXTI_PIN_Type EXTI_PinSourcex);
  
/*Generates a Software interrupt on selected EXTI line.*/
extern void EXTI_GenerateSWInterrupt(uint32_t EXTI_Line);
  
/*Checks whether the specified EXTI line flag is set or not.*/
extern FlagStatus EXTI_GetPendingFlagStatus(uint32_t EXTI_Line);
  
/*Clears the EXTI's line pending flags.*/
extern void EXTI_ClearPendingFlag(uint32_t EXTI_Line);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /*__SH32F9XX_SB0_EXTI_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
