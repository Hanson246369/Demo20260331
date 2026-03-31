/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_rambist.c
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21   
  * @brief   This file provide APIs for using RAM Bist module
  *         
  *  @verbatim
  *
  *          ===================================================================
  *                                  How to use this driver
  *          ===================================================================
  *          
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
#include "sh32f9xx_sb0_rambist.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/* CRC  Module----------------------------------------------------------*/
/** @defgroup RAMBIST_MODULE  Ram Bist
   *  CRC Calculate Mode
  * @{
  */

/** @defgroup  RAMBIST_Group_Pub_Funcs  Public Functions
 *  @brief   Ram Bist  Public Functions
 *
  * @{
  */

/**
  * @brief  Initialize RAMBIST registers   
  * @param  InitCfg Inital data to RAMBIST module
  *      @arg @b AlgmSel: RAMBIST_MARCH_C or RAMBIST_MARCH_X
  *      @arg @b BlkSize: RAMBIST_TESTBLK_16 ,RAMBIST_TESTBLK_32 ~ RAMBIST_TESTBLK_2048    
  * @retval None
  */
void RAMBIST_Init(const RAMBIST_InitTypeDef *InitCfg)
{
    assert_param(IS_RAMBIST_ALGORITHM(InitCfg->AlgmSel));
    assert_param(IS_RAMBIST_TESTBLK(InitCfg->BlkSize));
    assert_param(IS_RAMBIST_REGION(InitCfg->RegSel));

    RAMBIST->CFG.BIT.SEL     = InitCfg->AlgmSel;
    RAMBIST->CFG.BIT.BLKSZ   = InitCfg->BlkSize;
    RAMBIST->ADDR.BIT.RAMTYP = InitCfg->RegSel;
}

/**
  * @brief  Fills each InitV member with its default value.
  * @param  InitStruct : pointer to a RAMBIST_InitTypeDef structure which will be initialized.
  * @retval None
  */
void RAMBIST_StructInit(RAMBIST_InitTypeDef *InitStruct)
{

    InitStruct->AlgmSel = RAMBIST_MARCH_C;
    InitStruct->BlkSize = RAMBIST_TESTBLK_16;
    InitStruct->RegSel  = RAMBIST_CRAM;
}

/**
  * @brief  Deinitializes the RAMBIST peripheral registers to their default reset values 
  * @retval None
  */
void RAMBIST_Reset(void)
{
    RAMBIST->ADDR.V32 = 0;
    RAMBIST->CFG.V32  = 0;
    RAMBIST->CSR.V32  = 0;
}

/**
  * @brief  Run RAMBIST to do checking
  * @param  AreaType
  *      @arg @b RAMBIST_CHKAREA_DATA
  *      @arg @b RAMBIST_CHKAREA_BACKUP      
  * @param  Addr: checking area, cram address for cram backup area 
                  and sram address for sram backup area. Backup area is the last testblock    
  * @retval None
  */
void RAMBIST_Run(RAMBIST_CheckArea_Type AreaType, uint32_t Addr)
{
    static uint32_t Temp = 0;
    Temp = (RAMBIST->ADDR.V32 & 0xFFFFC000);
    Temp |= (uint32_t)(Addr & 0x3FFF);
    RAMBIST->ADDR.V32 = Temp; 
    RAMBIST->CSR.V32 = (AreaType << RAMBIST_CSR_MOD_Pos) | (0x59A6);
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
