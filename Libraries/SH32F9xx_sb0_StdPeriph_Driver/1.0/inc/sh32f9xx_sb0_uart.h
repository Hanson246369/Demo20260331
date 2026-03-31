/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_uart.h
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file contains all the functions prototypes for the UART firmware
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
#ifndef __SH32F9XX_SB0_UART_H
#define __SH32F9XX_SB0_UART_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"

/** @addtogroup sh32f9xx_sb0_StdLib_Driver
  * @{
  */

/** @addtogroup UART
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup UART_Exported_Constants
  * @{
  */ 


typedef struct
{
    GPIO_TypeDef  *UART_GPIOx;      /*!< The corresponding port group number */
    uint16_t       UART_GPIO_Pin;   /*!< The corresponding port number */
    uint8_t        UART_GPIO_AF;    /*!< The corresponding function number */
}UART_AFTypeDef;
#define IS_UART_ALL_PERIPH(PERIPH)  ((PERIPH == UART0)  || (PERIPH == UART1) \
                                    || (PERIPH == UART2)|| (PERIPH == UART3) \
                                    || (PERIPH == UART4)|| (PERIPH == UART5))


/** 
  * @brief  UART Init Structure definition  
  */ 

typedef struct
{
    uint32_t UART_Mode;  
    uint32_t UART_BaudRate;
    uint32_t UART_DataLength; 
    uint32_t UART_StopBits;
    uint32_t UART_Parity;
    uint32_t UART_Enable; 
}UART_InitTypeDef;

 

/** @defgroup UART_Mode 
  * @{
  */ 
  
#define UART_Mode_0        (uint16_t)0x0000
#define UART_Mode_1        (uint16_t)0x2000
#define UART_Mode_2        (uint16_t)0x4000
#define UART_Mode_3        (uint16_t)0x6000
#define IS_UART_MODE(MODE)   ((MODE == UART_Mode_0) || (MODE == UART_Mode_1) \
                             || (MODE == UART_Mode_2) || (MODE == UART_Mode_3))  

/**
  * @}
  */


/** @defgroup UART_BaudRate 
  * @{
  */ 
  
#define UART_BaudRate_DIV_12          (uint32_t)0x80000000 /* Only available for UART_Mode_0 */
#define UART_BaudRate_DIV_48          (uint32_t)0x40000000 /* Only available for UART_Mode_0 */
#define UART_BaudRate_DIV_128         (uint32_t)0x20000000 /* Only available for UART_Mode_2 */
#define UART_BaudRate_DIV_256         (uint32_t)0x10000000 /* Only available for UART_Mode_2 */

#define IS_UART_MODE_0_BAUDRATE(BAUDRATE)   ((BAUDRATE == UART_BaudRate_DIV_12) \
                                            || (BAUDRATE == UART_BaudRate_DIV_48))

#define IS_UART_MODE_2_BAUDRATE(BAUDRATE)   ((BAUDRATE == UART_BaudRate_DIV_128) \
                                            || (BAUDRATE == UART_BaudRate_DIV_256))

#define IS_UART_MODE_13_BAUDRATE(BAUDRATE)  ((BAUDRATE != UART_BaudRate_DIV_12) \
                                            && (BAUDRATE != UART_BaudRate_DIV_48) \
                                            && (BAUDRATE != UART_BaudRate_DIV_128) \
                                            && (BAUDRATE != UART_BaudRate_DIV_256))  

/**
  * @}
  */

/** @defgroup UART_Data_Length 
  * @{
  */ 
  
#define UART_DataLength_8Bit      (uint16_t)0x0000 
#define UART_DataLength_9Bit      (uint16_t)0x0200 /* Not available for UART_Mode_0 and  UART_Mode_1 */

#define IS_UART_MODE_01_DATALENGTH(LENGTH)  (LENGTH == UART_DataLength_8Bit)
#define IS_UART_MODE_23_DATALENGTH(LENGTH)  ((LENGTH == UART_DataLength_8Bit) \
                                            || (LENGTH == UART_DataLength_9Bit))  

/**
  * @}
  */

/** @defgroup UART_Stop_Bits 
  * @{
  */ 
  
#define UART_StopBits_1            (uint16_t)0x0001
#define UART_StopBits_2            (uint16_t)0x0002
#define UART_StopBits_None         (uint16_t)0x0000 /* Only available for UART_Mode_0 */

#define IS_UART_MODE_0_STOP_BITS(BITS)    (BITS == UART_StopBits_None)

#define IS_UART_MODE_123_STOP_BITS(BITS)    ((BITS == UART_StopBits_1) \
                                            || (BITS == UART_StopBits_2))  

/**
  * @}
  */

/** @defgroup UART_Parity 
  * @{
  */ 
  
#define UART_Parity_None                (uint16_t)0x0000
#define UART_Parity_Even                (uint16_t)0x0C00
#define UART_Parity_Odd                 (uint16_t)0x0800

#define IS_UART_MODE_01_PARITY(PARITY)  (PARITY == UART_Parity_None)

#define IS_UART_MODE_23_PARITY(PARITY)  ((PARITY == UART_Parity_None) \
                                        || (PARITY == UART_Parity_Even) \
                                        || (PARITY == UART_Parity_Odd))  

/**
  * @}
  */

/** @defgroup UART_Enable 
  * @{
  */ 
  
#define UART_Enable_Tx              (uint32_t)0x00040000
#define UART_Enable_Rx              (uint32_t)0x00020000
#define IS_UART_ENABLE(SH_ENABLE)   (((SH_ENABLE & (uint32_t)0xFFF9FFFF) == 0x00) \
                                    && (SH_ENABLE != (uint32_t)0x00))

/**
  * @}
  */

/** @defgroup UART_Interrupt_Definition 
  * @{
  */ 
  
#define UART_INT_RX           (uint16_t)0x0008
#define UART_INT_TX           (uint16_t)0x0010
#define UART_INT_TC           (uint16_t)0x0020
#define UART_INT_LBD          (uint16_t)0x0040
#define IS_UART_INT(INT)      (((INT & (uint16_t)0xFF87) == 0x00) && (INT != 0x00)) 

/**
  * @}
  */

/** @defgroup UART_Flags 
  * @{
  */ 
  
#define UART_FLAG_RI      (uint16_t)0x0001
#define UART_FLAG_TI      (uint16_t)0x0002
#define UART_FLAG_TC      (uint16_t)0x0004
#define UART_FLAG_TXCOL   (uint16_t)0x0008
#define UART_FLAG_RXOV    (uint16_t)0x0010
#define UART_FLAG_FE      (uint16_t)0x0020
#define UART_FLAG_PE      (uint16_t)0x0040
#define UART_FLAG_LBD     (uint16_t)0x0080

#define IS_UART_FLAG(FLAG)   (((FLAG & (uint16_t)0xFF00) == 0x00) && (FLAG != 0x00))

#define IS_UART_GET_ONE_FLAG(FLAG)  ((FLAG == UART_FLAG_RI) || (FLAG == UART_FLAG_TI) \
                                    || (FLAG == UART_FLAG_TC) || (FLAG == UART_FLAG_TXCOL) \
                                    || (FLAG == UART_FLAG_RXOV) || (FLAG == UART_FLAG_FE) \
                                    || (FLAG == UART_FLAG_PE) || (FLAG == UART_FLAG_LBD))

/**
  * @}
  */

/** @defgroup UART_DMA_Requests 
  * @{
  */ 
  
#define UART_DMA_RX                   (uint32_t)0x080000
#define UART_DMA_TX                   (uint32_t)0x100000
#define IS_UART_DMA_SOURCE(SOURCE)    (((SOURCE & (uint32_t)0xFFE7FFFF) == 0x00) \
                                       && (SOURCE != 0x00))

/**
  * @}
  */

/** @defgroup UART_LIN_Detect_Length
  * @{
  */ 
  
#define UART_LINDetectLength_10b             (uint16_t)0x0000
#define UART_LINDetectLength_11b             (uint16_t)0x0080
#define IS_UART_LIN_DETECT_LENGTH(LENGTH)    ((LENGTH == UART_LINDetectLength_10b) \
                                             || (LENGTH == UART_LINDetectLength_11b))

/**
  * @}
  */



/**
  * @}
  */ 


/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/* Open or close uartx modules' clock gate */
extern void UART_ClockOnOff(UART_TypeDef *UARTx,CmdState OnOffState);

/* Configure the currently selected channel */
extern void UART_InitAF(UART_TypeDef *UARTx,uint8_t RemapNum);

/* Fills each UART_InitStruct member with its default value. */
extern void UART_StructInit(UART_InitTypeDef *UART_InitStruct);

/* Initialize the UART peripheral according to the specified parameters in the UART_InitStruct. */
extern void UART_Init(UART_TypeDef *UARTx,UART_InitTypeDef *UART_InitStruct);

/* Check whether the specified UART flag is set or not. */
extern FlagStatus UART_GetFlagStatus(UART_TypeDef *UARTx, uint8_t UART_Flag);

/* Clear the UART's pending flags. */
extern void UART_ClearFlag(UART_TypeDef *UARTx, uint8_t UART_Flag);

/* Enable or disable the specified UART's interrupts. */
extern void UART_INTConfig(UART_TypeDef *UARTx, uint8_t UART_INT, FunctionalState NewState);

/* Enable or disable the UART's DMA request sources. */
extern void UART_DMAConfig(UART_TypeDef *UARTx, uint32_t UART_DMASource, FunctionalState NewState);

/* Transmit single data through the UARTx peripheral. */
extern void UART_SendData(UART_TypeDef *UARTx, uint8_t SendData);

/* Return the most recent received data by the UARTx peripheral. */
extern uint16_t UART_ReceiveData(UART_TypeDef *UARTx);

/* Enable or Disable the UART's LIN mode. */
extern void UART_LINDetectLengthConfig(UART_TypeDef *UARTx, uint16_t UART_LINDetectLength);

/* Check whether the specified UART interrupt is enable or disnable. */
extern FunctionalState UART_GetINTStatus(UART_TypeDef *UARTx, uint8_t UART_INTEnable);

#ifdef __cplusplus
}
#endif

#endif /*__SH32F9XX_SB0_UART_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
