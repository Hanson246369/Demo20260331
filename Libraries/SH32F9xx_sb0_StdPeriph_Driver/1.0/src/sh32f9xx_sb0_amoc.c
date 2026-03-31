/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_amoc.c
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
#include "sh32f9xx_sb0_amoc.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/** @defgroup TPS_MODULE TPS 
  * @brief TPS driver modules
  * @{
  */

/** @defgroup TPS_Group2 OP configuration
 *  @brief    OP configuration
 *
@verbatim    
 ===============================================================================
                                AVREF configuration
 ===============================================================================  
   
@endverbatim
  * @{
  */
/**
  * @brief  Open or disable the CHOP.
  * @param  OnOffState: new state of CHOP.
  *         This parameter can be one of the following values:
  *            @arg SH_ON
  *            @arg SH_OFF
  * @retval None
  */
void TPS_ChopOnOff(CmdState OnOffState)
{
    /* Check the parameters */
    assert_param(IS_CMD_STATE(OnOffState));

    TPS->AVREFCON.BIT.CHOPEN = (uint32_t)OnOffState;
}

/**
  * @brief  Set Input polarity of CHOP internal OP when VREF CHOP closed
  * @param  levelState: Level polarity.
  *         This parameter can be one of the following values:
  *            @arg SH_ON
  *            @arg SH_OFF
  * @retval None
  */
void TPS_SetOPInputPolarity(LevelStatus levelState)
{
    /* Check the parameters */
    assert_param(IS_LEVEL_STATE(levelState));

    if (levelState != SH_LOW)
    {
        TPS->AVREFCON.V32 &= (~TPS_AVREFCON_CHOPS_Msk);
    }
    else
    {
        TPS->AVREFCON.V32 |= TPS_AVREFCON_CHOPS_Msk;
    }
}

/**
  * @brief  Configure the internal reference voltage(Vref) value.
  * @param  TPS_VrefVoltage: specifie the internal reference voltage value.
  *         This parameter can be one of the following values:
  *            @arg TPS_VrefVoltage_2V5
  *            @arg TPS_VrefVoltage_3V3
  * @retval None
  */
void TPS_VrefVoltageConfig(uint8_t TPS_VrefVoltage)
{
    uint32_t temp = 0;

    /* Check the parameters */
    assert_param(IS_TPS_VREF_VOLTAGE(TPS_VrefVoltage));

    temp = TPS->AVREFCON.V32;
    temp &= ~TPS_AVREFCON_VREFSEL_Msk;
    temp |= TPS_VrefVoltage;
    TPS->AVREFCON.V32 = temp;
}

/**
  * @brief  Open or disable the internal reference voltage(Vref).
  * @param  OnOffState: new state of internal reference voltage(Vref).
  *         This parameter can be one of the following values:
  *            @arg SH_ON
  *            @arg SH_OFF
  * @retval None
  */
void TPS_VrefOnOff(CmdState OnOffState)
{
    /* Check the parameters */
    assert_param(IS_CMD_STATE(OnOffState));

    TPS_AVREFCON_VREFEN_BIT = (uint32_t)OnOffState;
}

/**
  * @}
  */

/** @defgroup TPS_Group3 Temperature Sensor Configuration
 *  @brief    Temperature Sensor Configuration
 *
@verbatim    
 ===============================================================================
                           Temperature Sensor Configuration
 ===============================================================================  
   
@endverbatim
  * @{
  */

/**
  * @brief  Enable or disable the Temperature Sensor CHOP switch.
  * @param  NewState: new state of the Temperature Sensor CHOP switch.
  *         This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void TPS_TempSensorCHOPConfig(FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_FUNCTION_STATE(NewState));

    TPS_TPSCON_TPSCHOP_BIT = (uint32_t)NewState;
}

/**
  * @brief  Enable or disable the Temperature Sensor .
  * @param  OnOffState: state of the Temperature Sensor.
  *         This parameter can be one of the following values:
  *            @arg SH_ON
  *            @arg SH_OFF
  * @retval None
  */
void TPS_TempSensorOnOff(CmdState OnOffState)
{
    /* Check the parameters */
    assert_param(IS_CMD_STATE(OnOffState));

    TPS_TPSCON_TPSEN_BIT = (uint32_t)OnOffState;
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
