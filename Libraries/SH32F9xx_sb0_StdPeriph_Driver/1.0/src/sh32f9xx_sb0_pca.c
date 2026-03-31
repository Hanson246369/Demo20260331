/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_pca.c
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
#include "sh32f9xx_sb0_pca.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/** @defgroup TIM_MODULE PCA 
  * @brief PCA driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup PCA_Private_Functions
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
  * @brief  Fills each PCA_InitStruct member with its default value.
  * @param  PCA_InitStruct : pointer to a PCA_InitTypeDef structure which will
  *         be initialized.
  * @retval None
  */
void PCA_StructInit(PCA_InitTypeDef *PCA_InitStruct)
{
    PCA_InitStruct->PCA_CMD.Channel0DMAEN  = SH_DISABLE;
    PCA_InitStruct->PCA_CMD.Channel1DMAEN  = SH_DISABLE;
    PCA_InitStruct->PCA_CMD.ClkSel         = SYSTEMCLK;
    PCA_InitStruct->PCA_CMD.OverFlowIntEN  = SH_DISABLE;
    PCA_InitStruct->PCA_CMD.PCACounterMode = SINGLEEDGE;
    PCA_InitStruct->PCA_CMD.PcaDmaEN       = SH_DISABLE;
    PCA_InitStruct->PCA_CMD.rev1           = 0;

    PCA_InitStruct->PCA_CPM0.COMPAREIntEN   = SH_DISABLE;
    PCA_InitStruct->PCA_CPM0.FunctionSelect = 0;
    PCA_InitStruct->PCA_CPM0.Match          = SH_DISABLE;
    PCA_InitStruct->PCA_CPM0.ModeSelect     = CAPTUREMODE;
    PCA_InitStruct->PCA_CPM0.PCA_ECOM       = SH_DISABLE;
    PCA_InitStruct->PCA_CPM0.PCA_TCP        = SH_DISABLE;
    PCA_InitStruct->PCA_CPM0.rev2           = 0;

    PCA_InitStruct->PCA_CPM1.COMPAREIntEN   = SH_DISABLE;
    PCA_InitStruct->PCA_CPM1.FunctionSelect = 0;
    PCA_InitStruct->PCA_CPM1.Match          = SH_DISABLE;
    PCA_InitStruct->PCA_CPM1.ModeSelect     = CAPTUREMODE;
    PCA_InitStruct->PCA_CPM1.PCA_ECOM       = SH_DISABLE;
    PCA_InitStruct->PCA_CPM1.PCA_TCP        = SH_DISABLE;
    PCA_InitStruct->PCA_CPM1.rev2           = 0;

    PCA_InitStruct->PCA_TOPR = 0;

    PCA_InitStruct->PCA_CPR0 = 0;
    PCA_InitStruct->PCA_CPR1 = 0;
}

/**
  * @brief  Initializes the PCAx peripheral according to the specified parameters 
  *         in the PCA_InitStruct.
  * @param  PCAx: where x can be  0 to 7 to select the TIM peripheral.
  * @param  PCA_InitStruct: pointer to a @ref PCA_InitTypeDef structure that contains 
  *         the configuration information for the specified PCA peripheral.
  * @retval None
  */
void PCA_Init(PCA_TypeDef *PCAx, const PCA_InitTypeDef *PCA_InitStruct)
{
    static uint8_t *pv = 0;
    /* check the parameters */
    assert_param(IS_PCA_ALL_PERIPH(PCAx));

    assert_param(IS_PCACLKSOURCE_DIV(PCA_InitStruct->PCA_CMD.ClkSel));
    assert_param(IS_PCACOUNTERMODE_DIV(PCA_InitStruct->PCA_CMD.PCACounterMode));

    pv = (uint8_t *)PCA_InitStruct;
    PCAx->CMD.V32  = *((uint32_t *)(pv + 0));
    PCAx->CPM0.V32 = *((uint32_t *)(pv + 4));
    PCAx->CPM1.V32 = *((uint32_t *)(pv + 8));
    PCAx->TOPR.V32 = *((uint32_t *)(pv + 12));
    PCAx->CPR0.V32 = *((uint32_t *)(pv + 16));
    PCAx->CPR1.V32 = *((uint32_t *)(pv + 20));
}

/**
  * @brief  Open or close the PCA peripheral.
  * @param  PCAx: where x can be 0 to 7 to select the PCA peripheral.
  * @param  OnOffState: state of the PCA peripheral.
  *         This parameter can be one of the following values:
  *            @arg SH_ON
  *            @arg SH_OFF
  * @retval None
  */
void PCA_OnOff(PCA_TypeDef *PCAx, CmdState OnOffState)
{
    /* check the parameters */
    assert_param(IS_PCA_ALL_PERIPH(PCAx));
    assert_param(IS_CMD_STATE(OnOffState));

    if (OnOffState != SH_OFF)
    {
        PCAx->CR.V32 |= PCA_CR_PR_Msk;
    }
    else
    {
        PCAx->CR.V32 &= (~PCA_CR_PR_Msk);
    }
}

/**
  * @brief  Open or close the PCA cascade.
  * @param  PCAx:where x can be 0 to 7 to select the PCA peripheral.
  * @param  OnOffState: state of the Cascade PCA peripheral.
  *         This parameter can be one of the following values:
  *            @arg SH_ON
  *            @arg SH_OFF
  * @retval None
  */
void PCA_CascadeOnOff(PCA_TypeDef *PCAx, CmdState OnOffState)
{
    /* check the parameters */
    assert_param(IS_PCA_CASCADE_PERIPH(PCAx));
    assert_param(IS_CMD_STATE(OnOffState));

    if (OnOffState != SH_OFF)
    {
        PCAx->CR.V32 |= PCA_CR_CASCEN_Msk;
    }
    else
    {
        PCAx->CR.V32 &= (~PCA_CR_CASCEN_Msk);
    }
}

/**
  * @brief  Set the PCAx Frequency output mode frequency value
  * @param  PCAx: where x can be 0 to 7 to select the PCA peripheral.
  *           Channel: Specifie the PCA Channel to Set.
  *         This parameter can be any combination of the following values:
  *            @arg PCA_CHANNEL_0
  *            @arg PCA_CHANNEL_1
  *         Value Specifie the PCA CPHx to set.
  * @retval None
  */
void PCA_FreqOutValue(PCA_TypeDef *PCAx, PCA_CHANEEL_Type PCAChannel, uint8_t Value)
{
    /* check the parameters */
    assert_param(IS_PCA_ALL_PERIPH(PCAx));
    assert_param(IS_PCACHANEEL_CHANNEL(PCAChannel));

    if (PCA_CHANNEL_0 == PCAChannel)
    {
        PCAx->CPR0.BIT.CPH0 = (uint8_t)Value;
    }
    else
    {
        PCAx->CPR1.BIT.CPH1 = (uint8_t)Value;
    }
}

/**
  * @brief  Set the PCAx pin level output control
  * @param  PCAx: where x can be 0 to 7 to select the PCA peripheral.
  *           Channel: Specifie the PCA Channel to Set.
  *         This parameter can be any combination of the following values:
  *            @arg PCA_CHANNEL_0
  *            @arg PCA_CHANNEL_1
  *         levelstatus Switch status.
  *         This parameter can be any combination of the following values:
  *            @arg SH_HIGH
  *            @arg SH_LOW
  * @retval None
  */
void PCA_PinLevelOutControl(PCA_TypeDef *PCAx, PCA_CHANEEL_Type PCAChannel, LevelStatus levelstatus)
{
    /* check the parameters */
    assert_param(IS_PCA_ALL_PERIPH(PCAx));
    assert_param(IS_PCACHANEEL_CHANNEL(PCAChannel));
    assert_param(IS_LEVEL_STATE(levelstatus));

    if (PCA_CHANNEL_0 == PCAChannel)
    {
        if (levelstatus != SH_HIGH)
        {
            PCAx->FORCE.V32 |= PCA_FORCE_OSC0_Msk;
        }
        else
        {
            PCAx->FORCE.V32 &= (~PCA_FORCE_OSC0_Msk);
        }
    }
    else
    {
        if (levelstatus != SH_HIGH)
        {
            PCAx->FORCE.V32 |= PCA_FORCE_OSC1_Msk;
        }
        else
        {
            PCAx->FORCE.V32 &= (~PCA_FORCE_OSC1_Msk);
        }
    }
}

/**
  * @brief  Set the PCAx Forced match control bit
  * @param  PCAx: where x can be 0 to 7 to select the PCA peripheral.
  *           Channel: Specifie the PCA Channel to Set.
  *         This parameter can be any combination of the following values:
  *            @arg PCA_CHANNEL_0
  *            @arg PCA_CHANNEL_1
  *         OnOffState Switch status.
  *         This parameter can be any combination of the following values:
  *            @arg SH_ON
  *            @arg SH_OFF
  * @retval None
  */
void PCA_ForceMatchControl(PCA_TypeDef *PCAx, PCA_CHANEEL_Type PCAChannel, CmdState OnOffState)
{
    /* check the parameters */
    assert_param(IS_PCA_ALL_PERIPH(PCAx));
    assert_param(IS_PCACHANEEL_CHANNEL(PCAChannel));
    assert_param(IS_CMD_STATE(OnOffState));

    if (PCA_CHANNEL_0 == PCAChannel)
    {
        if (OnOffState != SH_OFF)
        {
            PCAx->FORCE.V32 |= PCA_FORCE_FCO0_Msk;
        }
        else
        {
            PCAx->FORCE.V32 &= (~PCA_FORCE_FCO0_Msk);
        }
    }
    else
    {
        if (OnOffState != SH_OFF)
        {
            PCAx->FORCE.V32 |= PCA_FORCE_FCO1_Msk;
        }
        else
        {
            PCAx->FORCE.V32 &= (~PCA_FORCE_FCO1_Msk);
        }
    }
}

/**
  * @brief  Set the PCAx TOPR Register value
  * @param  PCAx: where x can be 0 to 7 to select the PCA peripheral.
  *           Value: Specifie the PCA TOPR to Set.
  * @retval Counter Register value
  * @retval None
  */
void PCA_SetTOPRValue(PCA_TypeDef *PCAx, uint32_t Value)
{
    /* check the parameters */
    assert_param(IS_PCA_ALL_PERIPH(PCAx));

    PCAx->TOPR.V32 = (uint32_t)Value;
}

/**
  * @brief  Set the PCAx CPR Register value
  * @param  PCAx: where x can be 0 to 7 to select the PCA peripheral.
  *         Channel: Specifie the PCA Channel to set.
  *         This parameter can be any combination of the following values:
  *            @arg PCA_CHANNEL_0
  *            @arg PCA_CHANNEL_1
  *         Value Specifie the PCA CPRx to set.
  * @retval None
  */
void PCA_SetCPRValue(PCA_TypeDef *PCAx, PCA_CHANEEL_Type PCAChannel, uint32_t Value)
{
    /* check the parameters */
    assert_param(IS_PCA_ALL_PERIPH(PCAx));
    assert_param(IS_PCACHANEEL_CHANNEL(PCAChannel));

    if (PCA_CHANNEL_0 == PCAChannel)
    {
        PCAx->CPR0.V32 = (uint32_t)Value;
    }
    else
    {
        PCAx->CPR1.V32 = (uint32_t)Value;
    }
}

/**
  * @brief  Get the PCAx CPR Register value
  * @param  PCAx: where x can be 0 to 7 to select the PCA peripheral.
  *           Channel: Specifie the PCA Channel to set.
  *         This parameter can be any combination of the following values:
  *            @arg PCA_CHANNEL_0
  *            @arg PCA_CHANNEL_1
  * @retval CPR_Count
  */
uint32_t PCA_GetCounter(PCA_TypeDef *PCAx, PCA_CHANEEL_Type PCAChannel)
{
    static uint32_t CPR_Count = 0;
    /* check the parameters */
    assert_param(IS_PCA_ALL_PERIPH(PCAx));
    assert_param(IS_PCACHANEEL_CHANNEL(PCAChannel));

    if (PCA_CHANNEL_0 == PCAChannel)
    {
        CPR_Count = PCAx->CPR0.V32;
    }
    else
    {
        CPR_Count = PCAx->CPR1.V32;
    }

    return CPR_Count;
}

/**
  * @brief  Check whether the specified PCA flag is set or not.
  * @param  PCAx: where x can be 0 to 7 to select the PCA peripheral.
  * @param  PCA_IntFlag: Specifie the flag to check.
  *         This parameter can be any combination of the following values:
  *            @arg PCA_FLAG_CCF0
  *            @arg PCA_FLAG_CCF1
  *            @arg PCA_FLAG_CF  
  * @retval The new state of PCAx's flag.
  */
FlagStatus PCA_GetFlagStatus(PCA_TypeDef *PCAx, uint16_t PCA_IntFlag)
{
    FlagStatus bitStatus;

    /* check the parameters */
    assert_param(IS_PCA_ALL_PERIPH(PCAx));
    assert_param(IS_PCA_GET_ONE_FLAG(PCA_IntFlag));
    if ((PCAx->PCAINTF.V32 & PCA_IntFlag) != SH_RESET)
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
  * @brief  Clear the PCA's pending flags.
  * @param  PCAx: where x can be 0 to 7 to select the PCA peripheral.
  * @param  PCA_IntFlag: Specifie the flag to check.
  *         This parameter can be any combination of the following values:
  *            @arg PCA_FLAG_CCF0
  *            @arg PCA_FLAG_CCF1
  *            @arg PCA_FLAG_CF  
  * @retval None
  */
void PCA_ClearFlag(PCA_TypeDef *PCAx, uint16_t PCA_IntFlag)
{
    /* Check the parameters */
    assert_param(IS_PCA_ALL_PERIPH(PCAx));
    assert_param(IS_PCA_GET_ONE_FLAG(PCA_IntFlag));

    PCAx->PCAINTF.V32 |= ((uint32_t)PCA_IntFlag << 3);
}
/**
  * @brief  Clear the PCAx's All pending flag.
  * @param  PCAx: where x can be 0 to 7 to select the PCA peripheral.
  * @retval None
  */
void PCA_ClearAllFlag(PCA_TypeDef *PCAx)
{
    /* check the parameters */
    assert_param(IS_PCA_ALL_PERIPH(PCAx));

    PCAx->PCAINTF.V32 = PCA_PCAINTF_CCF0C_Msk | PCA_PCAINTF_CCF1C_Msk | PCA_PCAINTF_CFC_Msk;
}

/**
  * @brief  Enable or disable the specified PCA's Overflow interrupts.
  * @param  PCAx: where x can be 0 to 7 to select the PCA peripheral.
  * @param  NewState: New state of PCA interrupt.
  *         This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void PCA_INTConfig(PCA_TypeDef *PCAx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_PCA_ALL_PERIPH(PCAx));
    assert_param(IS_FUNCTION_STATE(NewState));

    if (NewState != SH_DISABLE)
    {
        PCAx->CMD.V32 |= PCA_CMD_ECF_Msk;
    }
    else
    {
        PCAx->CMD.V32 &= (~PCA_CMD_ECF_Msk);
    }
}

/**
  * @brief  Enable or disable the specified PCAx Capture's interrupts.
  * @param  PCAx: where x can be 0 to 7 to select the PCA peripheral.
  * @param  PCAChannel: channel of PCA Capture's interrupt.
  *         This parameter can be one of the following values:
  *            @arg PCA_CHANNEL_0
  *            @arg PCA_CHANNEL_1
  * @param  NewState: New state of PCA interrupt.
  *         This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void PCA_CapINTConfig(PCA_TypeDef *PCAx, PCA_CHANEEL_Type PCAChannel, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_PCA_ALL_PERIPH(PCAx));
    assert_param(IS_PCACHANEEL_CHANNEL(PCAChannel));
    assert_param(IS_FUNCTION_STATE(NewState));

    if (PCA_CHANNEL_0 == PCAChannel)
    {
        if (NewState != SH_DISABLE)
        {
            PCAx->CPM0.V32 |= PCA_CPM0_ECCF0_Msk;
        }
        else
        {
            PCAx->CPM0.V32 &= (~PCA_CPM0_ECCF0_Msk);
        }
    }
    else
    {
        if (NewState != SH_DISABLE)
        {
            PCAx->CPM1.V32 |= PCA_CPM1_ECCF1_Msk;
        }
        else
        {
            PCAx->CPM1.V32 &= (~PCA_CPM1_ECCF1_Msk);
        }
    }
}

/**
  * @brief  Enable or disable the PCA's DMA request sources.
  * @param  PCAx: where x can be 0 to 7 to select the PCA peripheral.
  * @param  PCA_DMASource: specifies the DMA request.
  *         This parameter can be any combination of the following values:
  *            @arg PCA_DMA_CntOverflow
  *            @arg PCA_DMA_Channel_0
  *            @arg PCA_DMA_Channel_1
  * @param  NewState: new state of the DMA Request sources.
  *         This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void PCA_DMAConfig(PCA_TypeDef *PCAx, uint32_t PCA_DMASource, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_PCA_ALL_PERIPH(PCAx));
    assert_param(IS_PCA_Trg_SOURCE(PCA_DMASource));
    assert_param(IS_FUNCTION_STATE(NewState));

    if (NewState != SH_DISABLE)
    {
        /* Enable the PCA's DMA request sources */
        PCAx->CMD.V32 |= PCA_DMASource;
    }
    else
    {
        /* Disable the PCA's DMA request sources */
        PCAx->CMD.V32 &= ~PCA_DMASource;
    }
}

/**
  * @}
  */
 
/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
