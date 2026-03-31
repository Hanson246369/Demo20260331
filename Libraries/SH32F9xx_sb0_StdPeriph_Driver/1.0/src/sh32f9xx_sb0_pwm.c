/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_pwm.c
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file provide APIs for using PWM module
  *         
  * @verbatim
  *
  *          ===================================================================
  *                                  How to use this driver
  *          ===================================================================
  *          
  *
  * @endverbatim
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
#include "sh32f9xx_sb0_pwm.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/* PWM  Module----------------------------------------------------------*/
/** @defgroup PWM_MODULE  PWM 
   *  PWM Calculate Mode
  * @{
  */

/** @defgroup  PWM_Group_Pub_Funcs  Public Functions
 *  @brief   PWM Public Functions
 *
  * @{
  */

/**
  * @brief  Fills each PWM_InitStruct member with its default value.
  * @param  PWM_InitStruct : pointer to a @ref PWM_InitTypeDef
  *         structure which will be initialized.
  * @retval None
  */
void PWM_StructInit(PWM_InitTypeDef *PWM_InitStruct)
{
    PWM_InitStruct->PWM_Period = 0;
    PWM_InitStruct->PWM_Duty   = 0;
    PWM_InitStruct->PWM_DeadBand  = 0;
    PWM_InitStruct->PWM_CLKSource = SYSCLKDIV2;
}

/**
  * @brief  Initializes the PWMx peripheral according to the specified parameters 
  *         in the PWM_InitStruct.
  * @param  PWMx: where x can be  0 to 3 to select the PWM peripheral.
  * @param  PWM_InitStruct: pointer to a @ref PWM_InitTypeDef structure that contains 
  *         the configuration information for the specified PWM peripheral.
  * @retval None
  */
void PWM_Init(PWM_TypeDef *PWMx, PWM_InitTypeDef *PWM_InitStruct)
{
    /* check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWMCLKSOURCE_DIV(PWM_InitStruct->PWM_CLKSource));

    PWM_UNLOCK();
    PWMx->PWMPR  = PWM_InitStruct->PWM_Period;
    PWMx->PWMDR  = PWM_InitStruct->PWM_Duty;
    PWMx->PWMDTR = PWM_InitStruct->PWM_DeadBand;

    PWMx->CR.BIT.TCK = PWM_InitStruct->PWM_CLKSource;
    PWM_LOCK();
}

/**
  * @brief  Open or close the PWM peripheral.
  * @param  PWMx: where x can be 0 to 3 to select the PWM peripheral.
  * @param  OnOffState: state of the PWM peripheral.
  *         This parameter can be one of the following values:
  *            @arg SH_ON
  *            @arg SH_OFF
  * @retval None
  */
void PWM_OnOff(PWM_TypeDef *PWMx, CmdState OnOffState)
{
    /* check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_CMD_STATE(OnOffState));

    PWM_UNLOCK();
    if (OnOffState != SH_OFF)
    {
        PWMx->CR.V32 |= PWM_CR_PWMEN_Msk;
    }
    else
    {
        PWMx->CR.V32 &= (~PWM_CR_PWMEN_Msk);
    }
    PWM_LOCK();
}

/**
  * @brief  Set the pwm peripheral cycle.
  * @param  PWMx: where x can be  0 to 3 to select the PWM peripheral.
  * @param  prescale: set pwm Clock period(PWM Cycle).
  * @retval None
  */
void PWM_SetCycle(PWM_TypeDef *PWMx, uint16_t prescale)
{
    /* check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    PWM_UNLOCK();
    PWMx->PWMPR = prescale;
    PWM_LOCK();
}

/**
  * @brief  Set the pwm peripheral duty cycle.
  * @param  PWMx: where x can be  0 to 3 to select the PWM peripheral.
  * @param  duty: set pwm duty cycle.
  * @retval None
  */
void PWM_SetDuty(PWM_TypeDef *PWMx, uint16_t duty)
{
    /* check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    PWM_UNLOCK();
    PWMx->PWMDR = duty;
    PWM_LOCK();
}

/**
  * @brief  Set PWM peripheral Fault Pin electrical level to Close PWM Output.
  * @param  PWMx: where x can be 0 to 3 to select the PWM peripheral.
  * @param  LevelStatus: level of the Fault Pin.
  *         This parameter can be one of the following values:
  *            @arg SH_ON
  *            @arg SH_OFF
  * @retval None
  */
void PWM_FaultPinLevel(PWM_TypeDef *PWMx, LevelStatus levelState)
{
    /* check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_LEVEL_STATE(levelState));

    PWM_UNLOCK();
    if (levelState != SH_HIGH)
    {
        PWMx->CR.V32 |= PWM_CR_FLTC_Msk;
    }
    else
    {
        PWMx->CR.V32 &= (~PWM_CR_FLTC_Msk);
    }
    PWM_LOCK();
}

/**
  * @brief  Set PWM peripheral Fault Pin Function.
  * @param  PWMx: where x can be 0 to 3 to select the PWM peripheral.
  * @param  NewState: new state of the DMA Request sources.
  *         This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void PWM_FaultPinFunction(PWM_TypeDef *PWMx, FunctionalState NewState)
{
    /* check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_FUNCTION_STATE(NewState));

    PWM_UNLOCK();
    if (NewState != SH_DISABLE)
    {
        PWMx->CR.V32 |= PWM_CR_EFLT_Msk;
    }
    else
    {
        PWMx->CR.V32 &= (~PWM_CR_EFLT_Msk);
    }
    PWM_LOCK();
}

/**
  * @brief  Enable or disable the PWM's DMA request sources.
  * @param  PWMx: where x can be 0 to 3 to select the PWM peripheral.
  * @param  NewState: new state of the DMA Request sources.
  *         This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void PWM_OverFlowDMA(PWM_TypeDef *PWMx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_FUNCTION_STATE(NewState));

    PWM_UNLOCK();
    if (NewState != SH_DISABLE)
    {
        PWMx->CR.V32 |= PWM_CR_PWMDMA_Msk;
    }
    else
    {
        PWMx->CR.V32 &= (~PWM_CR_PWMDMA_Msk);
    }
    PWM_LOCK();
}
/**
  * @brief  Enable or disable the PWM's DMA request sources.
  * @param  PWMx: where x can be 0 to 3 to select the PWM peripheral.
  * @param  NewState: new state of the DMA Request sources.
  *          This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void PWM_FLTChannelDMA(PWM_TypeDef *PWMx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_FUNCTION_STATE(NewState));

    PWM_UNLOCK();
    if (NewState != SH_DISABLE)
    {
        PWMx->CR.V32 |= PWM_CR_FLTDMA_Msk;
    }
    else
    {
        PWMx->CR.V32 &= (~PWM_CR_FLTDMA_Msk);
    }
    PWM_LOCK();
}

/**
  * @brief  Check whether the specified PWM interrupt flag is set or not.
  * @param  PWMx: where x can be 0 to 3 to select the PWM peripheral.
  * @retval The new state of PWM's flag.
  */
FlagStatus PWM_GetIntFlagStatus(PWM_TypeDef *PWMx)
{
    FlagStatus bitStatus;

    /* check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    if ((PWMx->PWMINTF.V32 & PWM_PWMINTF_PWMIF_Msk) != SH_RESET)
    {
        bitStatus = SH_SET;
    }
    else
    {
        bitStatus = SH_RESET;
    }

    return bitStatus;
}
/**
  * @brief  Clear the PWMx's pending flag.
  * @param  PWMx: where x can be 0 to 3 to select the PWM peripheral.
  * @retval None
  */
void PWM_ClearIntFlag(PWM_TypeDef *PWMx)
{
    /* check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    PWM_UNLOCK();
    PWMx->PWMINTF.V32 |= PWM_PWMINTF_PWMIFC_Msk;
    PWM_LOCK();
}
/**
  * @brief  Check whether the specified PWM fault flag is set or not.
  * @param  PWMx: where x can be 0 to 3 to select the PWM peripheral.
  * @retval The new state of PWM's flag.
  */
FlagStatus PWM_GetFLTlagStatus(PWM_TypeDef *PWMx)
{
    FlagStatus bitStatus;

    /* check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    if ((PWMx->PWMINTF.V32 & PWM_PWMINTF_FLTS_Msk) != SH_RESET)
    {
        bitStatus = SH_SET;
    }
    else
    {
        bitStatus = SH_RESET;
    }

    return bitStatus;
}

/**
  * @brief  Clear the PWMx's fault flag.
  * @param  PWMx: where x can be 0 to 3 to select the PWM peripheral.
  * @retval None
  */
void PWM_ClearFLTFlag(PWM_TypeDef *PWMx)
{
    /* check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    PWM_UNLOCK();
    PWMx->PWMINTF.V32 |= PWM_PWMINTF_FLTSC_Msk;
    PWM_LOCK();
}

/**
  * @brief  Enable or disable the specified PWM's Overflow interrupts.
  * @param  PWMx: where x can be 0 to 3 to select the PWM peripheral.
  * @param  PWMIntSource: PWM Interrupt source.
  *         This parameter can be one of the following values:
  *            @arg PWM_INT_OVERFLOW
  *            @arg PWM_INT_FAULT
  * @param  NewState: New state of PWM interrupt.
  *         This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void PWM_INTConfig(PWM_TypeDef *PWMx, uint16_t PWMIntSource, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_INT(PWMIntSource));
    assert_param(IS_FUNCTION_STATE(NewState));

    PWM_UNLOCK();
    if (NewState != SH_DISABLE)
    {
        PWMx->CR.V32 |= PWMIntSource;
    }
    else
    {
        PWMx->CR.V32 &= (~PWMIntSource);
    }
    PWM_LOCK();
}

/**
  * @brief  Enable or disable the specified PWM Channel output
  * @param  PWMx: where x can be 0 to 3 to select the PWM peripheral.
  * @param  PWM_Channel: PWM Channel.
  *         This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_A
  *            @arg PWM_CHANNEL_B
  * @param  NewState: New state of PWM Output.
  *         This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void PWM_OutPutEnable(PWM_TypeDef *PWMx, uint16_t PWM_Channel, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_CHANNEL(PWM_Channel));
    assert_param(IS_FUNCTION_STATE(NewState));

    PWM_UNLOCK();
    if (NewState != SH_DISABLE)
    {
        PWMx->CR.V32 |= PWM_Channel;
    }
    else
    {
        PWMx->CR.V32 &= (~PWM_Channel);
    }
    PWM_LOCK();
}

/**
  * @brief  Enable or disable the specified PWM Channel output enable.
  * @param  PWMx: where x can be 0 to 3 to select the PWM peripheral.
  * @param  PWM_Channel: PWM Channel.
  *         This parameter can be one of the following values:
  *            @arg PWM_CHANNEL_A
  *            @arg PWM_CHANNEL_B
  * @param  LevelStatus: PWM Drive Level.
  *         This parameter can be one of the following values:
  *            @arg SH_LOW
  *            @arg SH_HIGH
  * @retval None
  */
void PWM_OutputMode(PWM_TypeDef *PWMx, uint16_t PWM_Channel, LevelStatus levelState)
{
    /* Check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));
    assert_param(IS_PWM_CHANNEL(PWM_Channel));
    assert_param(IS_LEVEL_STATE(levelState));

    PWM_UNLOCK();
    if (PWM_Channel & PWM_CHANNEL_A)
    {
        if (levelState != SH_HIGH)
        {
            PWMx->CR.BIT.PWMSA = 1;
        }
        else
        {
            PWMx->CR.BIT.PWMSA = 0;
        }
    }
    if (PWM_Channel & PWM_CHANNEL_B)
    {
        if (levelState != SH_HIGH)
        {
            PWMx->CR.BIT.PWMSB = 0;
        }
        else
        {
            PWMx->CR.BIT.PWMSB = 1;
        }
    }
    PWM_LOCK();
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
