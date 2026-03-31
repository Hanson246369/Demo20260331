/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_gpio.h
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file contains all the functions prototypes for the GPIO firmware
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
#ifndef __SH32F9XX_SB0_GPIO_H
#define __SH32F9XX_SB0_GPIO_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"

/** @addtogroup sh32f9xx_sb0_StdLib_Driver
  * @{
  */

/** @addtogroup GPIO_MODULE
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup GPIO_Exported_Constants
  * @{
  */ 

  
  
  
/** 
  * @brief  GPIO Configuration Mode enumeration 
  */   
typedef enum
{ 
    GPIO_Mode_IN   = 0x00, /*!< GPIO Input Mode */
    GPIO_Mode_OUT  = 0x01, /*!< GPIO Output Mode */
    GPIO_Mode_AF   = 0x02  /*!< GPIO Alternate Mode */
}GPIOMode_TypeDef;
#define IS_GPIO_MODE(MODE) (((MODE) == GPIO_Mode_IN)  || ((MODE) == GPIO_Mode_OUT))


/** 
  * @brief  GPIO Output type enumeration 
  */  
typedef enum
{ 
  GPIO_OType_PP = 0x00,
  GPIO_OType_OD = 0x01
}GPIOOType_TypeDef;
#define IS_GPIO_OTYPE(OTYPE) (((OTYPE) == GPIO_OType_PP) || ((OTYPE) == GPIO_OType_OD))


/** 
  * @brief  GPIO Output driving ability enumeration 
  */  
typedef enum
{ 
  GPIO_ODrv_NORMAL     = 0x00,    /*!< GPIO  */
  GPIO_ODrv_WEAK       = 0x01,   /*!< weak driver */
  GPIO_ODrv_VERYWEAK   = 0x02,  /*!< out 0 :strong driver , out 1: weak driver */
  GPIO_ODrv_VERYSTRONG = 0x03  /*!< out 1 :strong driver , out 0: weak driver */
}GPIOODrv_TypeDef;
#define IS_GPIO_ODRV(ODRV) (((ODRV) == GPIO_ODrv_NORMAL) || ((ODRV) == GPIO_ODrv_WEAK) \
                           || ((ODRV) == GPIO_ODrv_VERYWEAK)||  ((ODRV) == GPIO_ODrv_VERYSTRONG)) 

/** 
  * @brief  GPIO Configuration PullUp PullDown enumeration 
  */ 
typedef enum
{ 
  GPIO_PuPd_NOPULL = 0x00,
  GPIO_PuPd_UP     = 0x01,
  GPIO_PuPd_DOWN   = 0x02
}GPIOPuPd_TypeDef;

#define IS_GPIO_PUPD(PUPD) (((PUPD) == GPIO_PuPd_NOPULL) \
                           || ((PUPD) == GPIO_PuPd_UP)   \
                           || ((PUPD) == GPIO_PuPd_DOWN))



/** 
  * @brief  GPIO Bit SH_SET and Bit SH_RESET enumeration 
  */ 
typedef enum
{ 
  Bit_RESET = 0,
  Bit_SET
}BitAction;  

#define IS_GPIO_BIT_ACTION(BIT_ACTION)   (((BIT_ACTION) == Bit_RESET) || ((BIT_ACTION) == Bit_SET))

  
/** 
  * @brief   GPIO Init structure definition  
  */ 
typedef struct
{
    uint32_t GPIO_Pin;              /*!< Specifies the GPIO pins to be configured.
                                       This parameter can be any value of @ref GPIO_pins_define */

    GPIOMode_TypeDef GPIO_Mode;     /*!< Specifies the operating mode for the selected pins.
                                       This parameter can be a value of @ref GPIOMode_TypeDef */

    GPIOODrv_TypeDef GPIO_ODrv;   /*!< Specifies the speed for the selected pins.
                                       This parameter can be a value of @ref GPIOODrv_TypeDef */

    GPIOOType_TypeDef GPIO_OType;   /*!< Specifies the operating output type for the selected pins.
                                       This parameter can be a value of @ref GPIOOType_TypeDef */

    GPIOPuPd_TypeDef GPIO_PuPd;     /*!< Specifies the operating Pull-up/Pull down for the selected pins.
                                       This parameter can be a value of @ref GPIOPuPd_TypeDef */
}GPIO_InitTypeDef;  


#define IS_GPIO_ALL_PERIPH(PERIPH)    (((PERIPH) == GPIOA) || ((PERIPH) == GPIOB) \
                                       || ((PERIPH) == GPIOC) || ((PERIPH) == GPIOD) \
                                       || ((PERIPH) == GPIOE))

/** @defgroup GPIO_Bit_Lock
  * @{
  */
  
#define GPIO_BitLock_Disable       (uint8_t)0x00
#define GPIO_BitLock_Enable        (uint8_t)0x01
#define IS_GPIO_BIT_LOCK(LOCK)     ((LOCK == GPIO_BitLock_Disable) || (LOCK == GPIO_BitLock_Enable))

/**
  * @}
  */
  
/** @defgroup GPIO_Bit_Level
  * @{
  */

#define GPIO_BitLevel_CMOS        (uint8_t)0x00
#define GPIO_BitLevel_TTL         (uint8_t)0x01
#define IS_GPIO_BIT_LEVEL(LEVEL)  ((LEVEL == GPIO_BitLevel_CMOS) || (LEVEL == GPIO_BitLevel_TTL))

/**
  * @}
  */

/** @defgroup GPIO_pins_define
  * @{
  */ 
  
#define GPIO_Pin_0                 ((uint16_t)0x0001)  /* Pin 0 selected */
#define GPIO_Pin_1                 ((uint16_t)0x0002)  /* Pin 1 selected */
#define GPIO_Pin_2                 ((uint16_t)0x0004)  /* Pin 2 selected */
#define GPIO_Pin_3                 ((uint16_t)0x0008)  /* Pin 3 selected */
#define GPIO_Pin_4                 ((uint16_t)0x0010)  /* Pin 4 selected */
#define GPIO_Pin_5                 ((uint16_t)0x0020)  /* Pin 5 selected */
#define GPIO_Pin_6                 ((uint16_t)0x0040)  /* Pin 6 selected */
#define GPIO_Pin_7                 ((uint16_t)0x0080)  /* Pin 7 selected */
#define GPIO_Pin_8                 ((uint16_t)0x0100)  /* Pin 8 selected */
#define GPIO_Pin_9                 ((uint16_t)0x0200)  /* Pin 9 selected */
#define GPIO_Pin_10                ((uint16_t)0x0400)  /* Pin 10 selected */
#define GPIO_Pin_11                ((uint16_t)0x0800)  /* Pin 11 selected */
#define GPIO_Pin_12                ((uint16_t)0x1000)  /* Pin 12 selected */
#define GPIO_Pin_13                ((uint16_t)0x2000)  /* Pin 13 selected */
#define GPIO_Pin_14                ((uint16_t)0x4000)  /* Pin 14 selected */
#define GPIO_Pin_15                ((uint16_t)0x8000)  /* Pin 15 selected */
#define GPIO_Pin_All               ((uint16_t)0xFFFF)  /* All pins selected */

#define IS_GPIO_PIN(PIN) ((((PIN) & (uint16_t)0x00) == 0x00) && ((PIN) != (uint16_t)0x00))
#define IS_GET_GPIO_PIN(PIN)   (((PIN) == GPIO_Pin_0) \
                               || ((PIN) == GPIO_Pin_1) \
                               || ((PIN) == GPIO_Pin_2) \
                               || ((PIN) == GPIO_Pin_3) \
                               || ((PIN) == GPIO_Pin_4) \
                               || ((PIN) == GPIO_Pin_5) \
                               || ((PIN) == GPIO_Pin_6) \
                               || ((PIN) == GPIO_Pin_7) \
                               || ((PIN) == GPIO_Pin_8) \
                               || ((PIN) == GPIO_Pin_9) \
                               || ((PIN) == GPIO_Pin_10) \
                               || ((PIN) == GPIO_Pin_11) \
                               || ((PIN) == GPIO_Pin_12) \
                               || ((PIN) == GPIO_Pin_13) \
                               || ((PIN) == GPIO_Pin_14) \
                               || ((PIN) == GPIO_Pin_15))

/**
  * @}
  */ 



/** @defgroup GPIO_Alternat_function_selection_define 
  * @{
  */ 
/** 
  * @brief   AF 1 selection  
  */ 
#define GPIO_AF_GPIO          ((uint8_t)0x01)

/** 
  * @brief   AF 2 selection  
  */ 
#define GPIO_AF_UART0        ((uint8_t)0x02)  /* UART0 Alternate Function mapping */
#define GPIO_AF_UART1        ((uint8_t)0x02)  /* UART1 Alternate Function mapping */
#define GPIO_AF_UART2        ((uint8_t)0x02)  /* UART2 Alternate Function mapping */
#define GPIO_AF_UART3        ((uint8_t)0x02)  /* UART3 Alternate Function mapping */
#define GPIO_AF_UART4        ((uint8_t)0x02)  /* UART4 Alternate Function mapping */
#define GPIO_AF_UART5        ((uint8_t)0x02)  /* UART5 Alternate Function mapping */

/** 
  * @brief   AF 3 selection  
  */ 
#define GPIO_AF_SPI0         ((uint8_t)0x03)  /* SPI0 Alternate Function mapping */
#define GPIO_AF_TWI0         ((uint8_t)0x03)  /* TWI0 Alternate Function mapping */


/** 
  * @brief   AF 4 selection 
  */ 
#define GPIO_AF_TWI1          ((uint8_t)0x04)  /* TWI1 Alternate Function mapping */
#define GPIO_AF_SPI1          ((uint8_t)0x04)  /* SPI1 Alternate Function mapping */

/** 
  * @brief   AF 5 selection  
  */ 
#define GPIO_AF_PCA0          ((uint8_t)0x05)  /* PCA0 Alternate Function mapping */
#define GPIO_AF_PCA1          ((uint8_t)0x05)  /* PCA1 Alternate Function mapping */
#define GPIO_AF_PCA2          ((uint8_t)0x05)  /* PCA2 Alternate Function mapping */
#define GPIO_AF_PCA3          ((uint8_t)0x05)  /* PCA3 Alternate Function mapping */
#define GPIO_AF_PCA4          ((uint8_t)0x05)  /* PCA4 Alternate Function mapping */
#define GPIO_AF_PCA5          ((uint8_t)0x05)  /* PCA5 Alternate Function mapping */
#define GPIO_AF_PCA6          ((uint8_t)0x05)  /* PCA6 Alternate Function mapping */
#define GPIO_AF_PCA7          ((uint8_t)0x05)  /* PCA7 Alternate Function mapping */
/** 
  * @brief   AF 6 selection  
  */ 
#define GPIO_AF_TIM5          ((uint8_t)0x06)  /* TIM5 Alternate Function mapping */
#define GPIO_AF_TIM6          ((uint8_t)0x06)  /* TIM6 Alternate Function mapping */
#define GPIO_AF_TIM7          ((uint8_t)0x06)  /* TIM7 Alternate Function mapping */
#define GPIO_AF_TIM8          ((uint8_t)0x06)  /* TIM8 Alternate Function mapping */

/** 
  * @brief   AF 7 selection  
  */ 
#define GPIO_AF_PWM0          ((uint8_t)0x07)  /* PWM0 Alternate Function mapping */
#define GPIO_AF_PWM1          ((uint8_t)0x07)  /* PWM1 Alternate Function mapping */
#define GPIO_AF_PWM2          ((uint8_t)0x07)  /* PWM2 Alternate Function mapping */
#define GPIO_AF_PWM3          ((uint8_t)0x07)  /* PWM3 Alternate Function mapping */

/** 
  * @brief   AF 8 selection  
  */ 
#define GPIO_AF_LED          ((uint8_t)0x08)  /* LED Alternate Function mapping */
#define GPIO_AF_ADC          ((uint8_t)0x08)  /* ADC Alternate Function mapping */

/** 
  * @brief   AF 9 selection  
  */ 
#define GPIO_AF_LCD          ((uint8_t)0x09)  /* LCD Alternate Function mapping */

/** 
  * @brief   AF 10 selection  
  */ 
#define GPIO_AF_TK          ((uint8_t)0x0A)  /* TK Alternate Function mapping */



#define IS_GPIO_AF(AF)      (((AF) == GPIO_AF_GPIO) || ((AF) == GPIO_AF_UART0)  \
                            || ((AF) == GPIO_AF_UART1) || ((AF) == GPIO_AF_UART2)  \
                            || ((AF) == GPIO_AF_UART3) || ((AF) == GPIO_AF_UART4)  \
                            || ((AF) == GPIO_AF_UART5) || ((AF) == GPIO_AF_SPI0 )  \
                            || ((AF) == GPIO_AF_TWI0 ) || ((AF) == GPIO_AF_SPI1 )  \
                            || ((AF) == GPIO_AF_TWI1 ) || ((AF) == GPIO_AF_PCA0 )  \
                            || ((AF) == GPIO_AF_PCA1 ) || ((AF) == GPIO_AF_PCA2 )  \
                            || ((AF) == GPIO_AF_PCA3 ) || ((AF) == GPIO_AF_PCA4 )  \
                            || ((AF) == GPIO_AF_PCA5 ) || ((AF) == GPIO_AF_PCA6 )  \
                            || ((AF) == GPIO_AF_PCA7 ) || ((AF) == GPIO_AF_TIM5 )  \
                            || ((AF) == GPIO_AF_TIM6 ) || ((AF) == GPIO_AF_TIM7 )  \
                            || ((AF) == GPIO_AF_TIM8 ) || ((AF) == GPIO_AF_PWM0 )  \
                            || ((AF) == GPIO_AF_PWM1 ) || ((AF) == GPIO_AF_PWM2 )  \
                            || ((AF) == GPIO_AF_PWM3 ) || ((AF) == GPIO_AF_LED  )  \
                            || ((AF) == GPIO_AF_ADC  ) || ((AF) == GPIO_AF_LCD  )  \
                            || ((AF) == GPIO_AF_TK   ) )
/**
  * @}
  */ 


  
/**
  * @}
  */ 


/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/ 

/** @defgroup GPIO_Exported_Functions
  * @{
  */
/*Reset the GPIOx peripheral registers to their default reset values.*/  
extern void GPIO_Reset(GPIO_TypeDef *GPIOx);

/*Initialize the GPIOx peripheral according to the specified parameters in the GPIO_InitStruct.*/ 
extern void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct);

/*Fills each GPIO_InitStruct member with its default value.*/ 
extern void GPIO_StructInit(GPIO_InitTypeDef *GPIO_InitStruct);

/*Select whether CMOS or TTL level for GPIO Pins.*/ 
extern void GPIO_PinTTLConfig(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, uint8_t GPIO_BitLevel);

/*Lock GPIO pins configuration registers.*/ 
extern void GPIO_PinLock(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, uint8_t GPIO_BitLock);

/*Read the specified input port pin.*/ 
extern uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

/*Reads the specified GPIO input data port.*/ 
extern uint16_t GPIO_ReadInputData(GPIO_TypeDef *GPIOx);

/*Read the specified output data port bit.*/ 
extern uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

/*Read the specified GPIO output data port.*/ 
extern uint16_t GPIO_ReadOutputData(GPIO_TypeDef *GPIOx);

/*Set the selected data port bits.*/ 
extern void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

/*Reset the selected data port bits.*/ 
extern void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

/*Set or clear the selected data port bit.*/ 
extern void GPIO_WriteBit(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, BitAction BitVal);

/*Write data to selected GPIO data port.*/ 
extern void GPIO_Write(GPIO_TypeDef *GPIOx, uint16_t PortVal);

/*Toggle the specified GPIO pins.*/ 
extern void GPIO_ToggleBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

/*Changes the mapping of the specified pin.*/ 
extern void GPIO_PinAFConfig(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, uint8_t GPIO_AF);

/**
  * @}
  */



#ifdef __cplusplus
}
#endif

#endif /*__SH32F9XX_SB0_GPIO_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
