/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_timer.c
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
#include "sh32f9xx_sb0_timer.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/** @defgroup TIM_MODULE TIM 
  * @brief TIM driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup TIM_Private_Functions
  * @{
  */

/** @defgroup PPP_Group1 Initialization and Configuration
 *  @brief    Initialization and Configuration
 *
@verbatim    
 ===============================================================================
                      Initialization and Configuration
 ===============================================================================  
   
@endverbatim
  * @{
  */

/**
  * @brief  Reset the TIMx peripheral registers to their default reset values.
  * @param  TIMx: where x can be 5 to 8 to select the TIM peripheral.
  * @retval None
  */
void TIM_Reset(TIMER_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    if (TIMx == TIM5)
    {
        RCC_APB0PeriphReset(RCC_APB0_TIM5);
    }
    else if (TIMx == TIM6)
    {
        RCC_APB0PeriphReset(RCC_APB0_TIM6);
    }
    else if (TIMx == TIM7)
    {
        RCC_APB0PeriphReset(RCC_APB0_TIM7);
    }
    else
    {
        RCC_APB0PeriphReset(RCC_APB0_TIM8);
    }
}

/**
  * @brief  Fills each TIM_InitStruct member with its default value.
  * @param  TIM_InitStruct : pointer to a @ref TIM_InitTypeDef
  *         structure which will be initialized.
  * @retval None
  */
void TIM_StructInit(TIM_InitTypeDef *TIM_InitStruct)
{
    TIM_InitStruct->TIM_Prescaler = 0x00;
    TIM_InitStruct->TIM_Period    = 0x00;
    TIM_InitStruct->TIM_CLKSource = TIM_CLKSource_PCLK;
    TIM_InitStruct->TIM_OPMode = TIM_OPMode_Continue;
    TIM_InitStruct->TIM_TCMode = TIM_TCMode_Disable;
}

/**
  * @brief  Initializes the TIMx peripheral according to the specified parameters 
  *         in the TIM_InitStruct.
  * @param  TIMx: where x can be  5 to 8 to select the TIM peripheral.
  * @param  TIM_InitStruct: pointer to a @ref TIM_InitTypeDef structure that contains 
  *         the configuration information for the specified TIM peripheral.
  * @retval None
  */
void TIM_Init(TIMER_TypeDef *TIMx, TIM_InitTypeDef *TIM_InitStruct)
{
    /* check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_TIM_CLK_SOURCE(TIM_InitStruct->TIM_CLKSource));
    assert_param(IS_TIM_OP_MODE(TIM_InitStruct->TIM_OPMode));

    TIMx->PSQ = TIM_InitStruct->TIM_Prescaler;
    TIMx->TPR = TIM_InitStruct->TIM_Period;

    TIMx->CR.V32 &= ~(TIM_CR_CLKS_Msk | TIM_CR_OPM_Msk | TIM_CR_TC_Msk);
    TIMx->CR.V32 |= TIM_InitStruct->TIM_CLKSource | TIM_InitStruct->TIM_OPMode | TIM_InitStruct->TIM_TCMode;
}

/**
  * @brief  Enable or disable the specified TIM interrupt.
  * @param  TIMx: where x can be 5 to 8 to select the TIM peripheral.       
  * @param  NewState: new state of the TIM interrupt.
  *         This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void TIM_INTConfig(TIMER_TypeDef *TIMx, FunctionalState NewState)
{
    /* check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_FUNCTION_STATE(NewState));

    if (NewState != SH_DISABLE)
    {
        TIMx->CR.V32 |= TIM_CR_IE_Msk;
    }
    else
    {
        TIMx->CR.V32 &= (~TIM_CR_IE_Msk);
    }
}

/**
  * @brief  Open or close the TIM peripheral.
  * @param  TIMx: where x can be 5 to 8 to select the TIM peripheral.
  * @param  OnOffState: state of the TIM peripheral.
  *         This parameter can be one of the following values:
  *            @arg SH_ON
  *            @arg SH_OFF
  * @retval None
  */
void TIM_OnOff(TIMER_TypeDef *TIMx, CmdState OnOffState)
{
    /* check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_CMD_STATE(OnOffState));

    if (OnOffState != SH_OFF)
    {
        TIMx->CR.V32 |= TIM_CR_STR_Msk;
    }
    else
    {
        TIMx->CR.V32 &= (~TIM_CR_STR_Msk);
    }
}

/**
  * @brief  Open or close the TIM peripheral.
  * @param  TIMx: where x can be 5 or 7 to select the TIM peripheral.
  * @param  OnOffState: state of the Cascade TIM peripheral.
  *          This parameter can be one of the following values:
  *            @arg SH_ON
  *            @arg SH_OFF
  * @retval None
  */
void TIM_CascadeOnOff(TIMER_TypeDef *TIMx, CmdState OnOffState)
{
    /* check the parameters */
    assert_param(IS_TIM_CASCADE_PERIPH(TIMx));
    assert_param(IS_CMD_STATE(OnOffState));

    if (OnOffState != SH_OFF)
    {
        TIMx->CR.V32 |= TIM_CR_CASCEN_Msk;
    }
    else
    {
        TIMx->CR.V32 &= (~TIM_CR_CASCEN_Msk);
    }
}

/**
  * @brief  Enable or disable the TIMx's output pin.
  * @param  TIMx: where x can be 5 to 8 to select the TIM peripheral.
  * @param  NewState: new state of the TIMx's output pin.
  *          This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void TIM_OutPutConfig(TIMER_TypeDef *TIMx, FunctionalState NewState)
{
    /* check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_FUNCTION_STATE(NewState));

    if (NewState != SH_DISABLE)
    {
        TIMx->CR.V32 |= TIM_CR_TC_Msk;
    }
    else
    {
        TIMx->CR.V32 &= ~TIM_CR_TC_Msk;
    }
}

/**
  * @brief  Enable or disable the TIMx's trigger CM3 core function.
  * @param  TIMx: where x can be 5 to 8 to select the TIM peripheral.
  * @param  NewState: new state of the TIMx's trigger function.
  *          This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void TIM_CM3EventTrigger(TIMER_TypeDef *TIMx, FunctionalState NewState)
{
    /* check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_FUNCTION_STATE(NewState));

    if (NewState != SH_DISABLE)

    {
        TIMx->CR.V32 |= TIM_CR_ETEN_Msk;
    }
    else
    {
        TIMx->CR.V32 &= ~TIM_CR_ETEN_Msk;
    }
}

/**
  * @brief  Enable or disable the TIMx's trigger function.
  * @param  TIMx: where x can be 5 to 8 to select the TIM peripheral.
  * @param  NewState: new state of the TIMx's trigger function.
  *          This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void TIM_ExtPeripheralsTrigger(TIMER_TypeDef *TIMx, FunctionalState NewState)
{
    /* check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_FUNCTION_STATE(NewState));

    if (NewState != SH_DISABLE)

    {
        TIMx->CR.V32 |= TIM_CR_TRIGEN_Msk;
    }
    else
    {
        TIMx->CR.V32 &= ~TIM_CR_TRIGEN_Msk;
    }
}

/**
  * @brief  Check whether the specified TIM flag is set or not.
  * @param  TIMx: where x can be 5 to 8 to select the TIM peripheral.
  * @retval The new state of TIMx's flag.
  */
FlagStatus TIM_GetFlagStatus(TIMER_TypeDef *TIMx)
{
    FlagStatus bitStatus;

    /* check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    if ((TIMx->TIMINTF.V32 & TIM_TIMINTF_TF_Msk) != SH_RESET)
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
  * @brief  Clear the TIMx's pending flag.
  * @param  TIMx: where x can be 5 to 8 to select the TIM peripheral.
  * @retval None
  */
void TIM_ClearFlag(TIMER_TypeDef *TIMx)
{
    /* check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    TIMx->TIMINTF.V32 = TIM_TIMINTF_TFC_Msk;
}

/**
  * @brief  Get the TIMx Period Register value
  * @param  TIMx: where x can be 5 to 8 to select the TIM peripheral.
  * @retval Counter Register value
  */
uint32_t TIM_GetCounter(TIMER_TypeDef *TIMx)
{

    /* check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    return TIMx->TCNT;
}

/**
  * @brief  Get the TIMx Period Register value
  * @param  TIMx: where x can be 5 to 8 to select the TIM peripheral.
  * @retval Prescaler Register value
  */
uint32_t TIM_GetPrescaler(TIMER_TypeDef *TIMx)
{
    /* check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    return TIMx->PSQ;
}

/**
  * @brief  Get the TIMx Period Register value
  * @param  TIMx: where x can be 5 to 8 to select the TIM peripheral.
  * @retval Period Register value
  */
uint32_t TIM_GetPeriod(TIMER_TypeDef *TIMx)
{
    /* check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    return TIMx->TPR;
}

/**
  * @brief  Set the TIMx Counter Register value
  * @param  TIMx: where x can be 5 to 8 to select the TIM peripheral.
  * @param  Counter: specifies the Counter register new value.
  * @retval None
  */
void TIM_SetCounter(TIMER_TypeDef *TIMx, uint32_t Counter)
{

    /* check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    TIMx->TCNT = Counter;
}

/**
  * @brief  Set the TIMx Prescaler Register value
  * @param  TIMx: where x can be 5 to 8 to select the TIM peripheral.
  * @param  Prescaler: specifies the Prescaler register new value.
  * @retval None
  */
void TIM_SetPrescaler(TIMER_TypeDef *TIMx, uint32_t Prescaler)
{
    /* check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    TIMx->PSQ = Prescaler;
}

/**
  * @brief  Set the TIMx Period Register value
  * @param  TIMx: where x can be 5 to 8 to select the TIM peripheral.
  * @param  Period: specifies the Period register new value.
  * @retval None
  */
void TIM_SetPeriod(TIMER_TypeDef *TIMx, uint32_t Period)
{
    /* check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    TIMx->TPR = Period;
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

/**
  * @}
  */

/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
