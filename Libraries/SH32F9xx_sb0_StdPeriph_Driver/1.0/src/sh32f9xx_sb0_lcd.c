/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_lcd.c
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file provide APIs for using LCD module
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
#include "sh32f9xx_sb0_lcd.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/**
  * @brief  Fills each LCD_InitStruct member with its default value. 
  * @param  LDD_InitStruct: pointer to a @ref LCD_InitTypeDef structure which will 
  *         be initialized.
  * @retval None
  */
void LCD_StructInit(LCD_InitTypeDef *LCD_InitStruct)
{
    /* for CR register */
    /* Initialize LCD driver : SH_ON or SH_OFF */
    LCD_InitStruct->LcdEN = SH_OFF;

    /* Initialize the select clock : 0: LSI  1: 32.768kHZ Crystal */
    LCD_InitStruct->ClockSel = LCD_CLKSEL_LSI;

    /* Initialize the DUTY */
    LCD_InitStruct->Duty = LCD_DUTY_SEL0;

    /* Initialize the LCD voltage select */
    LCD_InitStruct->VolSel = LCD_VOLSEL_0594VDD;

    /* Initialize the LCD Contrast :SH_ON or SH_OFF */
    LCD_InitStruct->ContrastEn = SH_OFF;

    /* Initialize the LCD PORT SH_SET */
    LCD_InitStruct->LcdPortSel = LCD_SHARE_SELECT;

    /* Initialize the LCD BIAS RESISTANCE */
    LCD_InitStruct->BiasResistance = LCD_BIASRES_900K;

    /* Initialize the LCD driver mode */
    LCD_InitStruct->LcdDriverMode = LCD_DRVMOD_900K_1500K;

    /* Initialize the LCD charge time */
    LCD_InitStruct->ChargeTime = LCD_CHARGE_TIM_8;

    /* Initialize the LCD SCAN conunter control */
    LCD_InitStruct->ScanfCounter = LCD_SCANFCONT_MODCTR_CONT;

    /* Initialize the LCD clock division */
    LCD_InitStruct->ClockDIV = LCD_LSI_CLKSEL_4;

    /* for LCDSHARE register */
    /* Initialize the LCD COM MODE SELECT */
    LCD_InitStruct->LcdCOM = LCD_SEC_COM_NOP;

    /* Initialize the LCD SEG MODE SELECT1 */
    LCD_InitStruct->LcdSEG1 = LCD_SEC_SEG_NOP1;

    /* Initialize the LCD SEG MODE SELECT2 */
    LCD_InitStruct->LcdSEG2 = LCD_SEC_SEG_NOP2;

    /* Initialize the LCD SEG MODE SELECT3 */
    LCD_InitStruct->LcdSEG3 = LCD_SEC_SEG_NOP3;

    /* for LCDSHARE1 register */
    /* Initialize the LCD SEG MODE SELECT4 */
    LCD_InitStruct->LcdSEG4 = LCD_SEC_SEG_NOP4;

    /* Initialize the LCD SEG MODE SELECT5 */
    LCD_InitStruct->LcdSEG5 = LCD_SEC_SEG_NOP5;
}

/* @endcode      
  * @brief  Initializes the LCD driver mould peripheral according to the specified 
  *   parameters in the InitCfg.
  * @param  LCD_MOULD  :led driver mould
  * @param  InitCfg  pointer to a LCD_InitTypeDef structure that
  *   contains the configuration information for the specified LCD peripheral.
  * @retval None
  */
void LCD_Init(LCD_TypeDef *LCD_MOULD, const LCD_InitTypeDef *InitCfg)
{
    uint8_t *pv;

    pv = (uint8_t *)InitCfg;
    LCD_MOULD->CR.V32 = *((uint32_t *)pv);
    LCD_MOULD->LCDSHARE.V32 = *((uint32_t *)(pv + 4));
    LCD_MOULD->LCDSHARE1.V32 = *((uint32_t *)(pv + 8));
}

/**
  * @brief  Open or close the LCD peripheral.
  * @param  OnOffState: state of the LCD peripheral.
  *         This parameter can be one of the following values:
  *            @arg SH_ON
  *            @arg SH_OFF
  * @retval None
  */
void LCD_OnOff(CmdState OnOffState)
{
    /* check the parameters */
    assert_param(IS_CMD_STATE(OnOffState));

    if (OnOffState != SH_OFF)
    {
        LCD->CR.V32 |= LCD_CR_EN_Msk;
    }
    else
    {
        LCD->CR.V32 &= (~LCD_CR_EN_Msk);
    }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
