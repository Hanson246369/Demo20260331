/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_crc.c
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file provide APIs for using CRC module
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
#include "sh32f9xx_sb0_crc.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/* CRC  Module----------------------------------------------------------*/
/** @defgroup CRC_MODULE  CRC 
   *  CRC Calculate Mode
  * @{
  */

/** @defgroup  CRC_Group_Pub_Funcs  Public Functions
 *  @brief   CRC Public Functions
 *
  * @{
  */

/**
  * @brief  CRC Module Initialization  
  * @param  InitCfg: Input CRC Configuration
  * @retval None
  */
void CRC_Init(CRC_InitTypeDef *CRC_InitStruct)
{
    assert_param(CRC_InitStruct);

    /* set initial value */
    CRC->INIT = CRC_InitStruct->InitialVal;

    /* Set configuration and reload */
    CRC->CR.V32 = *((uint32_t *)CRC_InitStruct);
}

/**
  * @brief  Fills each CRC_InitStruct member with its default value.
  * @param  CRC_InitStruct : pointer to a CRC_InitTypeDef structure which will
  *         be initialized.
  * @retval None
  */
void CRC_StructInit(CRC_InitTypeDef *CRC_InitStruct)
{
    CRC_InitStruct->Reload = 0;
    CRC_InitStruct->Mode   = CRC_MODE_CITT;
    CRC_InitStruct->ComplementInput  = 0;
    CRC_InitStruct->BitRevertInput   = 0;
    CRC_InitStruct->ByteRevertInput  = 0;
    CRC_InitStruct->ComplementOutput = 0;
    CRC_InitStruct->BitRevertOutput  = 0;
    CRC_InitStruct->ByteRevertOutput = 0;

    CRC_InitStruct->InitialVal = 0;
}

/**
  * @brief  Deinitializes the CRC registers to their default reset 
  * @retval None
  */
void CRC_Reset(void)
{
    RCC_AHBPeriphReset(RCC_AHB_CRC);
}

/**
  * @brief  Calcuate one data's CRC value
  * @param  Data Input data to calculate.
  * @param  InputType  Input data's format.Can be of below
  *    @arg @b CRC_INPUT_WORD       one word data to calculate
  *    @arg @b CRC_INPUT_HALFWORD   half word to calculate
  *    @arg @b CRC_INPUT_BYTE       one byte to calculate     
  * @retval uint32_t  one block data's CRC value
  */
uint32_t CRC_CalcCRC(uint32_t Data, CRC_INPUT_Type InputType)
{
    assert_param(IS_CRC_INPUTTYPE(InputType));

    switch (InputType)
    {
    case CRC_INPUT_WORD:
        CRC->DR.V32 = Data;
        break;
    case CRC_INPUT_HALFWORD:
        *((uint16_t *)&(CRC->DR)) = ((uint16_t)(Data & 0xFFFF));
        break;
    case CRC_INPUT_BYTE:
        *((uint8_t *)&(CRC->DR)) = ((uint8_t)(Data & 0xFF));
        break;
    default:
        assert_break(0);
        break;
    }

    /* return the CRC result */
    return (uint32_t)(CRC->DR.V32);
}

/**
  * @brief  Calcuate one block data's CRC value
  * @param  InBuffer Input data buffer to calculate.
  * @param  Count  size of input buffer. data unit is assigned by InputType
  * @param  InputType  Input data's format.Can be of below
  *    @arg @b CRC_INPUT_WORD       one word data to calculate
  *    @arg @b CRC_INPUT_HALFWORD   half word to calculate
  *    @arg @b CRC_INPUT_BYTE       one byte to calculate     
  * @retval uint32_t one block data's CRC value
  */
uint32_t CRC_CalcBlockCRC(const uint8_t *InBuffer, uint32_t Count, CRC_INPUT_Type InputType)
{
    uint32_t i;
    const uint8_t *p;
    assert_param(Count > 0);
    assert_param(IS_CRC_INPUTTYPE(InputType));

    p = InBuffer;
    for (i = 0; i < Count; i++)
    {
        switch (InputType)
        {
        case CRC_INPUT_WORD:
            CRC->DR.V32 = *((uint32_t *)p);
            p += 4;
            break;
        case CRC_INPUT_HALFWORD:
            *((uint16_t *)&(CRC->DR)) = *((uint16_t *)p);
            p += 2;
            break;
        case CRC_INPUT_BYTE:
            *((uint8_t *)&(CRC->DR)) = *((uint8_t *)p);
            p++;
            break;
        default:
            assert_break(0);
            p++;
            break;
        }
    }

    /* return the CRC result */
    return (uint32_t)(CRC->DR.V32);
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
