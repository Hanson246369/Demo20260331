/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_iwdt.c
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file provides firmware functions to manage the following 
  *         
  *  @verbatim
  *
  *          ===================================================================
  *                                   How to use this driver
  *          ===================================================================
  *
  *  @endverbatim
  *
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
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_iwdt.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/** @defgroup IWDT_MODULE IWDT
  * @brief IWDT driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup IWDT_Public_Functions Public Functions
  * @{
  */

/**
  * @brief  Enables IWDT, prescaler and counter configuration functions
  * @param  IWDT_Prescaler: specifies the IWDT Prescaler value.
  *         This parameter can be one of the following values:
  *            @arg IWDT_Prescaler_4:   IWDT prescaler set to 4
  *            @arg IWDT_Prescaler_8:   IWDT prescaler set to 8
  *            @arg IWDT_Prescaler_16:  IWDT prescaler set to 16
  *            @arg IWDT_Prescaler_32:  IWDT prescaler set to 32
  *            @arg IWDT_Prescaler_64:  IWDT prescaler set to 64
  *            @arg IWDT_Prescaler_128: IWDT prescaler set to 128
  *            @arg IWDT_Prescaler_256: IWDT prescaler set to 256
  *            @arg IWDT_Prescaler_512: IWDT prescaler set to 512
  * @param  Reload: specifies the IWDT Reload value.
  *          This parameter must be a number between 0 and 0x0FFF.
  * @retval None
  */
void IWDT_Enable(uint8_t IWDT_Prescaler, uint16_t Reload)
{
    /* Check the parameters */
    assert_param(IS_IWDT_PRESCALER(IWDT_Prescaler));
    assert_param(IS_IWDT_RELOAD(Reload));

    IWDT->CR.V32 = ((0x5AA5 << IWDT_CR_LOCK_Pos) \
                   | (IWDT_Prescaler << IWDT_CR_IWDTPR_Pos) \
                   | (Reload << IWDT_CR_IWDTRLR_Pos));
}

/**
  * @brief  Reloads IWDG counter with value defined in the reload register
  *   (write access to IWDG_PR and IWDG_RLR registers disabled).
  * @param  None
  * @retval None
  */
void IWDG_ReloadCounter(void)
{
    IWDT->CLR = 0xAAAA;
}

/**
  * @brief  Checks whether the specified IWDT flag is set or not.
  * @retval The new state of IWDT_FLAG (SH_SET or RESET).
  */
FlagStatus IWDT_GetFlagStatus(void)
{
    /* Return the flag status */
    return (RCC->RSTSTR.BIT.IWDTRSTF ? SH_SET : SH_RESET);
}

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
