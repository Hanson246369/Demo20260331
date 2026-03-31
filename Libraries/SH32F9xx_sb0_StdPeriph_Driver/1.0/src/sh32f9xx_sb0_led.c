/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_led.c
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file provide APIs for using LED module
  *         
  * @verbatim
  *
  *          ===================================================================
  *                                  How to use this driver
  *          ===================================================================

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
#include "sh32f9xx_sb0_led.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/**
  * @brief  Fills each LED_InitStruct member with its default value. 
  * @param  LED_InitStruct: pointer to a @ref LED_InitTypeDef structure which will 
  *         be initialized.
  * @retval None
  */
void LED_StructInit(LED_InitTypeDef *LED_InitStruct)
{
    /* for CR register */
    /* Initialize the interrupt run mode control */
    LED_InitStruct->LedIntMod   = LED_INT_Continue;

    /* Initialize the modle 1, model 2 */
    LED_InitStruct->ModSel      = LED_MODE1;

    /* Initialize the LED share control */
    LED_InitStruct->LedShareCtr = LED_SHARE_CONTROL;

    /* Initialize the common cathode or common anode */
    LED_InitStruct->LedAnodeSel = LED_Cathode;

    /* Initialize the LED COM scan width [15~8] */
    LED_InitStruct->LedClkWidth = 0x00;

    /* Initialize the LED COM dead band control [23~16] */
    LED_InitStruct->LedDeadBand = 0x00;

    /* Initialize the LED COM counter */
    LED_InitStruct->CntComMod   = LED_SCANF_CNTSTO;

    /* for LEDSHARE register */
    /* Initialize the LED com mode seclet */
    LED_InitStruct->LedComModeSEL  = LED_SEC_COM_NOP;

    /* Initialize the SEG mode seclet */
    LED_InitStruct->LedSEG1PINMode = LED_SEC_SEG_NOP1;

    /* Initialize the SEG mode seclet */
    LED_InitStruct->LedSEG2PINMode = LED_SEC_SEG_NOP2;
}

/** 
  * @brief  Initializes the LED driver mould peripheral according to the specified 
  *         parameters in the InitCfg.
  * @param  LED_MOULD  :led driver mould
  * @param  InitCfg  pointer to a LED_InitTypeDef structure that
  *         contains the configuration information for the specified LED peripheral.
  * @retval None
  */

void LED_Init(const LED_InitTypeDef *InitCfg)
{

    LED->CR.BIT.LEDMD = InitCfg->LedIntMod;
    LED->CR.BIT.MODE  = InitCfg->ModSel;
    LED->CR.BIT.MODSW = InitCfg->LedShareCtr;
    LED->CR.BIT.LEDMODSEL = InitCfg->LedAnodeSel;
    LED->CR.BIT.CNTMOD    = InitCfg->CntComMod;

    LED->CR.BIT.DISCOM = InitCfg->LedClkWidth;
    LED->CR.BIT.LEDDZ  = InitCfg->LedDeadBand;

    LED->LEDSHARE.BIT.LEDCOM  = InitCfg->LedComModeSEL;
    LED->LEDSHARE.BIT.LEDSEG1 = InitCfg->LedSEG1PINMode;
    LED->LEDSHARE.BIT.LEDSEG2 = InitCfg->LedSEG2PINMode;
}

/**
  * @brief  Clear the LED single pending flags.
  * @param  LED_Flag: specifie the flag to clear.
  *         This parameter can be any combination of the following values:
  *            @arg LED_FLAG_COM
  *            @arg LED_FLAG_FRAME 
  * @retval None
  */
void LED_ClearFlag(uint16_t LED_Flag)
{
    /* Check the parameters */
    assert_param(IS_LED_FLAG(LED_Flag));

    LED->FR.V32 |= (LED_Flag << 16);
}

/**
  * @brief  Clears ALL LED driver mould interrupt flag.
  */
void LEDMOULD_ClearFlag(void)
{
    LED->FR.BIT.COMIFC = SH_SET;
    LED->FR.BIT.LEDIFC = SH_SET;
}

/**
  * @brief  Open or close the LED peripheral.  
  * @param  OnOffState: state of the LED peripheral.
  *         This parameter can be one of the following values:
  *            @arg SH_ON
  *            @arg SH_OFF
  * @retval None
  */
void LED_OnOff(CmdState OnOffState)
{
    /* Check the parameters */
    assert_param(IS_CMD_STATE(OnOffState));

    if (OnOffState != SH_OFF)
    {
        /* Enable the LED peripheral */
        LED->CR.V32 |= LED_CR_EN_Msk;
    }
    else
    {
        /* Disable the LED peripheral */
        LED->CR.V32 &= (~LED_CR_EN_Msk);
    }
}

/**
  * @brief  Enable or disable the LED interrupt.       
  * @param  NewState: new state of the LED interrupt.
  *         This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void LED_INTConfig(FunctionalState NewState)
{
    /* check the parameters */
    assert_param(IS_FUNCTION_STATE(NewState));

    if (NewState != SH_DISABLE)
    {
        LED->CR.V32 |= LED_CR_IE_Msk;
    }
    else
    {
        LED->CR.V32 &= (~LED_CR_IE_Msk);
    }
}

/**
  * @brief  Enable or disable the specified LED frame interrupt.       
  * @param  NewState: new state of the LED frame interrupt.
  *         This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void LED_INT_FrameConfig(FunctionalState NewState)
{
    /* check the parameters */
    assert_param(IS_FUNCTION_STATE(NewState));

    if (NewState != SH_DISABLE)
    {
        LED->CR.V32 |= LED_CR_LEDFY_Msk;
    }
    else
    {
        LED->CR.V32 &= (~LED_CR_LEDFY_Msk);
    }
}

/**
  * @brief  Enable or disable the specified LED com interrupt.       
  * @param  NewState: new state of the LED com interrupt.
  *         This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void LED_INT_ComConfig(FunctionalState NewState)
{
    /* check the parameters */
    assert_param(IS_FUNCTION_STATE(NewState));

    if (NewState != SH_DISABLE)
    {
        LED->CR.V32 |= LED_CR_LEDCY_Msk;
    }
    else
    {
        LED->CR.V32 &= (~LED_CR_LEDCY_Msk);
    }
}

/**
  * @brief  Enable or disable the specified LED frame DMA.       
  * @param  NewState: new state of the LED frame DMA.
  *         This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void LED_DMA_FrameEN(FunctionalState NewState)
{
    /* check the parameters */
    assert_param(IS_FUNCTION_STATE(NewState));

    if (NewState != SH_DISABLE)
    {
        LED->CR.V32 |= LED_CR_LEDFDMA_Msk;
    }
    else
    {
        LED->CR.V32 &= (~LED_CR_LEDFDMA_Msk);
    }
}

/**
  * @brief  Enable or disable the specified LED com DMA.       
  * @param  NewState: new state of the LED com DMA.
  *         This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void LED_DMA_ComEN(FunctionalState NewState)
{
    /* check the parameters */
    assert_param(IS_FUNCTION_STATE(NewState));

    if (NewState != SH_DISABLE)
    {
        LED->CR.V32 |= LED_CR_LEDCDMA_Msk;
    }
    else
    {
        LED->CR.V32 &= (~LED_CR_LEDCDMA_Msk);
    }
}
/**
  * @brief  Check whether the specified LED COM flag is set or not.
  * @retval The new state of LED's flag.
  */
FlagStatus LED_GetComFlagStatus(LED_TypeDef *LEDMOUDLE)
{
    FlagStatus bitStatus;

    if ((LEDMOUDLE->FR.V32 & LED_FR_COMIF_Msk) != SH_RESET)
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
  * @brief  Check whether the specified LED Frame flag is set or not.
  * @retval The new state of LED's flag.
  */
FlagStatus LED_GetFrameFlagStatus(LED_TypeDef *LEDMOUDLE)
{
    FlagStatus bitStatus;

    if ((LEDMOUDLE->FR.V32 & LED_FR_LEDIF_Msk) != SH_RESET)
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
  * @}
  */

/**
  * @}
  */
 
/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
