/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_wwdt.h
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file contains all the functions prototypes for the WWDT firmware
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
  * <h2><center>&copy; COPYRIGHT 2017 Sinowealth</center></h2>
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SH32F9XX_SB0_WWDT_H
#define __SH32F9XX_SB0_WWDT_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"

/** @addtogroup sh32f9xx_sb0_StdLib_Driver
  * @{
  */

/** @defgroup WWDT_MODULE WWDT
  * @{
  */ 

/** @defgroup  WWDT_Group_Macro Public Macros
  * @{
  */

/** 
  *@brief  WWDT Prescaler 
  */
/*! WWDT counter clock = (PCLK1/256)/1 */
#define WWDT_Prescaler_1    ((uint32_t)0x00000000)
/*! WWDT counter clock = (PCLK1/256)/2 */
#define WWDT_Prescaler_2    ((uint32_t)0x00000100)
/*! WWDT counter clock = (PCLK1/256)/4 */
#define WWDT_Prescaler_4    ((uint32_t)0x00000200)
/*! WWDT counter clock = (PCLK1/256)/8 */
#define WWDT_Prescaler_8    ((uint32_t)0x00000300)
/*! WWDT counter clock = (PCLK1/256)/16 */
#define WWDT_Prescaler_16   ((uint32_t)0x00000400)
/*! WWDT counter clock = (PCLK1/256)/32 */
#define WWDT_Prescaler_32   ((uint32_t)0x00000500)
/*! WWDT counter clock = (PCLK1/256)/64 */
#define WWDT_Prescaler_64   ((uint32_t)0x00000600)
/*! WWDT counter clock = (PCLK1/256)/128 */
#define WWDT_Prescaler_128  ((uint32_t)0x00000700)

/*! Check the Prescaler of WWDT clock */
#define IS_WWDT_PRESCALER(PRESCALER)  (((PRESCALER) == WWDT_Prescaler_1)    \
                                      || ((PRESCALER) == WWDT_Prescaler_2)  \
                                      || ((PRESCALER) == WWDT_Prescaler_4)  \
                                      || ((PRESCALER) == WWDT_Prescaler_8)  \
                                      || ((PRESCALER) == WWDT_Prescaler_16) \
                                      || ((PRESCALER) == WWDT_Prescaler_32) \
                                      || ((PRESCALER) == WWDT_Prescaler_64) \
                                      || ((PRESCALER) == WWDT_Prescaler_128))
 
/*! Check the WWDT window value */ 
#define IS_WWDT_WINDOW_VALUE(VALUE) ((VALUE) <= 0xFF)
/*! Check the WWDT counter value */
#define IS_WWDT_COUNTER(COUNTER) ((COUNTER) <= 0xFF)
/*! Clear WWDT */
#define CLR_WWDT() WWDT->CLR =0x5555

/**
  * @}
  */ 



/** @addtogroup WWDT_Public_Functions Public Functions
  * @{
  */  
/*Deinitializes the WWDT peripheral registers to their default reset values.*/
void WWDT_Reset(void);
/* Prescaler, Refresh window and Counter configuration functions **************/

/* Sets the WWDT Prescaler. */
void WWDT_SetPrescaler(uint32_t WWDT_Prescaler);

/* Sets the WWDT window value. */
void WWDT_SetWindowValue(uint8_t WindowValue);

/* Controles the WWDT Early Wakeup interrupt.(Enable or disable) */
void WWDT_EnableINT(bool_t EnableINT);

/* Sets the WWDT counter value. */
void WWDT_SetCounter(uint8_t Counter);

/* WWDT activation function ***************************************************/

/* Enables WWDT and load the counter value. */
void WWDT_Enable(uint32_t WWDT_Prescaler, bool_t EnableINT, uint8_t Counter, uint8_t WindowValue);

/* Interrupts and flags management functions **********************************/

/* Checks whether the Early Wakeup interrupt flag is set or not. */
FlagStatus WWDT_GetINTFlagStatus(void);

/* Clears Early Wakeup interrupt flag. */
void WWDT_ClearFlag(void);


#ifdef __cplusplus
}
#endif

#endif /* __SH32F9XX_SB0_WWDT_H */


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
