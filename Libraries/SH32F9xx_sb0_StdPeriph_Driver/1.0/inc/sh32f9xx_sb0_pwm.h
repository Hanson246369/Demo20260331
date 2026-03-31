/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_pwm.h
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file provide PWM module's APIs
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
#ifndef __SH32F9XX_SB0_PWM_H
#define __SH32F9XX_SB0_PWM_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"

/** @addtogroup sh32f9xx_sb0_StdLib_Driver
  * @{
  */

/** @defgroup PWM_Interrupt_Definition 
  * @{
  */ 
#define PWM_INT_OVERFLOW           (uint16_t)0x0200
#define PWM_INT_FAULT              (uint16_t)0x0100
#define IS_PWM_INT(INT)            (((INT & (uint16_t)0xFCFF) == 0x0000) && (INT != 0x0000)) 

/** @defgroup PWM_Channel_Definition 
  * @{
  */ 
#define PWM_CHANNEL_A               (uint16_t)0x0800
#define PWM_CHANNEL_B               (uint16_t)0x0400
#define IS_PWM_CHANNEL(CHAN)        (((CHAN & (uint16_t)0xF3FF) == 0x0000) && (CHAN != 0x0000)) 
/** @addtogroup PWM_MODULE
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/

     /*!  PWM Mode CLOCK SOURCE */
typedef enum {
    SYSCLKDIV2     =    0,     /*!< System clock DIV2   */
    SYSCLKDIV4     =    1,     /*!< System clock DIV4   */
    SYSCLKDIV8     =    2,     /*!< System clock DIV8   */
    SYSCLKDIV16    =    3,     /*!< System clock DIV16  */
    SYSCLKDIV1     =    4,     /*!< System clock */
    SYSCLKDIV32    =    5,     /*!< System clock DIV32  */
    SYSCLKDIV64    =    6,     /*!< System clock DIV64  */
    SYSCLKDIV256   =    7,     /*!< System clock DIV256 */
}PWM_CLKDIV_Type;

/*!  check pwm clock source */
#define IS_PWMCLKSOURCE_DIV(div) (((div)==SYSCLKDIV2)   \
                                 || ((div)==SYSCLKDIV4)   \
                                 || ((div)==SYSCLKDIV8)   \
                                 || ((div)==SYSCLKDIV16)  \
                                 || ((div)==SYSCLKDIV1)   \
                                 || ((div)==SYSCLKDIV32)  \
                                 || ((div)==SYSCLKDIV64)  \
                                 || ((div)==SYSCLKDIV256))

/** @defgroup PWM_Exported_Types
  * @{
  */
  
typedef struct
{    
    PWM_CLKDIV_Type PWM_CLKSource; /*!< Specifie the PWM's clock sources.
                                        This parameter can be 0 to 0x07*/
    
    uint16_t PWM_Period;           /*!< Specifie the PWM period value.  Cycle
                                        This parameter can be 0 to 0xFFFF */ 
                                   
    uint16_t PWM_Duty;             /*!< Specifie the PWM period value.  Duty
                                        This parameter can be 0 to 0xFFFF */ 
                                   
    uint16_t PWM_DeadBand;         /*!< Specifie the TIM prescaler value.
                                        This parameter can be 0 to 0xFFFF */
}PWM_InitTypeDef;

  
#define IS_PWM_ALL_PERIPH(PERIPH)  ((PERIPH == PWM0) || (PERIPH == PWM1) \
                                   || (PERIPH == PWM2) || (PERIPH == PWM3))  

#define PWM_UNLOCK()   {PWMx->PWMLOCK = 0x5AA5;}
#define PWM_LOCK()     {PWMx->PWMLOCK = 0;}

/*Fills each PWM_InitStruct member with its default value.*/
void PWM_StructInit(PWM_InitTypeDef *PWM_InitStruct);

/*Initializes the PWMx peripheral according to the specified parameters */
void PWM_Init(PWM_TypeDef *PWMx, PWM_InitTypeDef *PWM_InitStruct);

/*Open or close the PWM peripheral.*/
void PWM_OnOff(PWM_TypeDef *PWMx, CmdState OnOffState);

/*Set the pwm peripheral cycle.*/
void PWM_SetCycle(PWM_TypeDef *PWMx, uint16_t prescale);

/*@brief  Set the pwm peripheral duty cycle.*/
void PWM_SetDuty(PWM_TypeDef *PWMx, uint16_t duty);

/*Set PWM peripheral Fault Pin electrical level to Close PWM Output.*/
void PWM_FaultPinLevel(PWM_TypeDef *PWMx, LevelStatus levelState);

/*Set PWM peripheral Fault Pin Function.*/
void PWM_FaultPinFunction(PWM_TypeDef *PWMx, FunctionalState NewState);

/*Enable or disable the PWM's DMA request sources.*/
void PWM_OverFlowDMA(PWM_TypeDef *PWMx, FunctionalState NewState);

/*Enable or disable the PWM's DMA request sources.*/
void PWM_FLTChannelDMA(PWM_TypeDef *PWMx, FunctionalState NewState);

/*Check whether the specified PWM interrupt flag is set or not.*/
FlagStatus PWM_GetIntFlagStatus(PWM_TypeDef *PWMx);

/*Clear the PWMx's pending flag.*/
void PWM_ClearIntFlag(PWM_TypeDef *PWMx);

/*Check whether the specified PWM fault flag is set or not.*/
FlagStatus PWM_GetFLTlagStatus(PWM_TypeDef *PWMx);

/*Clear the PWMx's fault flag.*/
void PWM_ClearFLTFlag(PWM_TypeDef *PWMx);

/*Enable or disable the specified PWM's Overflow interrupts.*/
void PWM_INTConfig(PWM_TypeDef *PWMx, uint16_t PWMIntSource, FunctionalState NewState);

/*Enable or disable the specified PWM Channel output*/
void PWM_OutPutEnable(PWM_TypeDef *PWMx, uint16_t PWM_Channel, FunctionalState NewState);

/*Enable or disable the specified PWM Channel output enable.*/
void PWM_OutputMode(PWM_TypeDef *PWMx, uint16_t PWM_Channel, LevelStatus levelState);

#ifdef __cplusplus
}
#endif

#endif /*__SH32F9XX_SB0_PWM_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
