/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_spi.c
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file provide APIs for using SPI module
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
#include "sh32f9xx_sb0_spi.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/* SPI  Module----------------------------------------------------------*/
/** @defgroup SPI_MODULE  SPI 
   *  SPI Calculate Mode
  * @{
  */

/** @defgroup  SPI_Group_Pub_Funcs  Public Functions
 *  @brief   SPI Public Functions
 *
  * @{
  */

/**
  * @brief  Fills each SPI_InitStruct member with its default value.
  * @param  SPI_InitTypeDef : pointer to a SPI_InitTypeDef structure which will
  *         be initialized.
  * @retval None
  */
void SPI_StructInit(SPI_InitTypeDef *SPI_InitStruct)
{
    SPI_InitStruct->Clock = SPR_PCKL1_DIV_2;
    SPI_InitStruct->SSPin = PIN_SS_ENABLE;
    SPI_InitStruct->ClkIdleState  = CLK_IDLE_LOW;
    SPI_InitStruct->CaptureEdge   = CAP_CLK_EDGE1;
    SPI_InitStruct->MasterOrSlave = SPI_SLAVE;
    SPI_InitStruct->Direction = SPI_TRANS_MSB;
    SPI_InitStruct->DataSize  = SPI_DATASIZE_8b;

    SPI_InitStruct->SlaveTransMode = SPI_SLAVE_NORMAL;
    SPI_InitStruct->bufferSize     = SPI_BUFFERSIZE_SPDATL;
}

/**
  * @brief  Initializes the SPIx peripheral according to the specified 
  *   parameters in the InitCfg.
  * @param  SPIx SPI device: SPI0 or SPI1
  * @param  InitCfg  pointer to a SPI_InitTypeDef structure that
  *   contains the configuration information for the specified SPI peripheral.
  * @retval None
  */

void SPI_Init(SPI_TypeDef *SPIx, SPI_InitTypeDef *SPI_InitStruct) //const SPI_InitTypeDef* InitCfg)
{
    assert_param(IS_SPI_MODULE(SPIx));
    assert_param(IS_SPI_SPR_Type(SPI_InitStruct->Clock));

    assert_param(IS_SPI_SPSFF_Type(SPI_InitStruct->MasterOrSlave));

    SPIx->CR.BIT.SPR   = SPI_InitStruct->Clock;            /*!<Selects the data transfer baudrate for the specified SPI.*/
    SPIx->CR.BIT.SSDIS = SPI_InitStruct->SSPin;            /*!<Enables or disables the NSS Pin for the selected SPI.*/
    SPIx->CR.BIT.CPOL  = SPI_InitStruct->ClkIdleState;     /*!< */
    SPIx->CR.BIT.CPHA  = SPI_InitStruct->CaptureEdge;      /*!< */
    SPIx->CR.BIT.MSTR  = SPI_InitStruct->MasterOrSlave;    /*!<Selects the SPI mode, SPI_MASTER or SPI_SLAVE*/
    SPIx->CR.BIT.DIR   = SPI_InitStruct->Direction;        /*!<Selects the data transfer direction  for the specified SPI.*/
    SPIx->CR.BIT.SPDATL = SPI_InitStruct->DataSize;        /*!<Configures the data size for the selected SPI*/
    SPIx->CR.BIT.SPSFF  = SPI_InitStruct->SlaveTransMode;  /*!< */
    SPIx->CR.BIT.SPDATW = SPI_InitStruct->bufferSize;      /*!<Configures the buffer size for the selected SPI*/
}

/**
  * @brief  Deinitializes the SPIx peripheral registers to their default
  *   reset values 
  * @param  SPIx: where x can be 0, 1 to select the SPI peripheral.
  * @retval None
  */
void SPI_Reset(SPI_TypeDef *SPIx)
{
    /* Check the parameters */
    assert_param(IS_SPI_MODULE(SPIx));

    if (SPIx == SPI0)
    {
        /* Reset SPI0 module */
        RCC_APB1PeriphReset(RCC_APB1_SPI0);
    }
    else if (SPIx == SPI1)
    {
        /* Reset SPI1 module */
        RCC_APB1PeriphReset(RCC_APB1_SPI1);
    }
}

/**
  * @brief  Enables or disables the specified SPI peripheral.
  * @param  SPIx: where x can be 0, 1 to select the SPI peripheral.
  * @param  OnOffState: new state of the SPIx peripheral. 
  *   This parameter can be: SH_ON or SH_OFF.
  * @retval None
  */
void SPI_OnOff(SPI_TypeDef *SPIx, CmdState OnOffState)
{
    assert_param(IS_SPI_MODULE(SPIx));
    assert_param(IS_CMD_STATE(OnOffState));

    SPIx->CR.BIT.SPIEN = OnOffState;
}

/**
  * @brief  Checks whether the specified SPI interrupt has occurred or not.
  * @param  SPIx: where x can be 0, 1 in SPI mode 
  * @param  SPIFunc: specifies the SPI interrupt source to check. 
  *   This parameter can be one of the following values:
  *     @arg @b SPI_FUNC_SEND: Transmit buffer empty interrupt.
  *     @arg @b SPI_FUNC_RECEIVE: Receive buffer not empty interrupt.
  * @retval FlagStatus The new state interrupt (SH_SET or RESET).
  */
FlagStatus SPI_GetINTStatus(SPI_TypeDef *SPIx, SPI_FUNC_Type SPIFunc)
{
    FlagStatus status = SH_RESET;
    uint32_t tmpVal;
    assert_param(IS_SPI_MODULE(SPIx));
    assert_param(IS_SPI_FUNC_Type(SPIFunc));

    if (SPIFunc == SPI_FUNC_SEND)
    {
        tmpVal = SPIx->FR.BIT.SPTI;
        tmpVal &= SPIx->CR.BIT.SPTIE;
        status = (tmpVal ? SH_SET : SH_RESET);
    }
    else if (SPIFunc == SPI_FUNC_RECEIVE)
    {
        tmpVal = SPIx->FR.BIT.SPRI;
        tmpVal &= SPIx->CR.BIT.SPRIE;
        status = (tmpVal ? SH_SET : SH_RESET);
    }

    return status;
}

/**
  * @brief  Enable or disable the specified SPI's interrupts.
  * @param  SPIx: where x can be 0 or 1 to select the SPI peripheral.
  * @param  SPIFunc: specifies the SPI interrupt source to check. 
  *         This parameter can be one of the following values:
  *         @arg @b SPI_FUNC_SEND: Transmit buffer empty interrupt.
  *         @arg @b SPI_FUNC_RECEIVE: Receive buffer not empty interrupt.
  * @param  NewState: New state of SPI interrupt.
  *         This parameter can be one of the following values:
  *         @arg SH_ENABLE
  *         @arg SH_DISABLE
  * @retval None
  */
void SPI_INTConfig(SPI_TypeDef *SPIx, SPI_FUNC_Type SPIFunc, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_SPI_MODULE(SPIx));
    assert_param(IS_SPI_FUNC_Type(SPIFunc));
    assert_param(IS_FUNCTION_STATE(NewState));

    if (NewState != SH_DISABLE)
    {
        if (SPIFunc == SPI_FUNC_SEND)
        {
            SPIx->CR.BIT.SPTIE = 1;
        }
        else if (SPIFunc == SPI_FUNC_RECEIVE)
        {
            SPIx->CR.BIT.SPRIE = 1;
        }
    }
    else
    {
        if (SPIFunc == SPI_FUNC_SEND)
        {
            SPIx->CR.BIT.SPTIE = 0;
        }
        else if (SPIFunc == SPI_FUNC_RECEIVE)
        {
            SPIx->CR.BIT.SPRIE = 0;
        }
    }
}

/**
  * @brief  Clears the SPIx interrupt pending bit.
  * @param  SPIx: where x can be 0 or 1 in SPI mode 
  * @param  SPIFunc: specifies the SPI interrupt pending bit to clear.
  *         This parameter can be any combination of following values:  
  *         @arg @b SPI_FUNC_SEND:    Transmit buffer empty interrupt.
  *         @arg @b SPI_FUNC_RECEIVE: Receive buffer not empty interrupt.
  * @retval None
  */
void SPI_ClearINTStatus(SPI_TypeDef *SPIx, SPI_FUNC_Type SPIFunc)
{
    assert_param(IS_SPI_MODULE(SPIx));
    assert_param(IS_SPI_FUNC_Type(SPIFunc));

    if ((SPIFunc & SPI_FUNC_SEND) == SPI_FUNC_SEND)
        SPIx->FR.BIT.SPTIC = 1;

    if ((SPIFunc & SPI_FUNC_RECEIVE) == SPI_FUNC_RECEIVE)
        SPIx->FR.BIT.SPRIC = 1;
}

/**
  * @brief  get SPI transmit flag
  * @param  SPIx SPI device: SPI0 or SPI1
  * @param  Flag  SPI flag mask
  *   This parameter can be one of following values:  
  *     @arg @b  SPI_FLAG_RECEIVE_INT: Interrupt flag for receive buffer ready
  *     @arg @b  SPI_FLAG_SEND_INT: Interrupt flag for send buffer empty
  *     @arg @b  SPI_FLAG_MODE_ERROR: More than one master in the transmit net
  *     @arg @b  SPI_FLAG_RECIEVE_OVER: Receive overflag
  *     @arg @b  SPI_FLAG_SEND_CONFLICT: Write conflict flag
  * @retval  FlagStatus RCC reset flag
  *     @arg @b  SH_SET    the flag is setted
  *     @arg @b  RESET  the flag is cleared
  */
FlagStatus SPI_GetFlagStatus(SPI_TypeDef *SPIx, SPI_FLAG_Type Flag)
{
    assert_param(IS_SPI_MODULE(SPIx));
    assert_param(IS_SPI_FLAG_Type(Flag));

    return ((SPIx->FR.V32 & Flag) ? SH_SET : SH_RESET);
}

/**
  * @brief  clear SPI transmit flags
  * @param  SPIx SPI device: SPI0 or SPI1
  * @param  Flags   SPI flags clear bit mask
  *   This parameter can be any combination of following values:  
  *     @arg @b  SPI_FLAG_RECEIVE_INT: Clear interrupt flag for receive buffer ready
  *     @arg @b  SPI_FLAG_SEND_INT: Clear interrupt flag for send buffer empty
  *     @arg @b  SPI_FLAG_MODE_ERROR: Clear more than one master in the transmit net 
  *     @arg @b  SPI_FLAG_RECIEVE_OVER: Clear receive overflag 
  *     @arg @b  SPI_FLAG_SEND_CONFLICT: Clear write conflict flag
  * @retval None
  */
void SPI_ClearFlag(SPI_TypeDef *SPIx, SPI_FLAG_Type Flags)
{
    assert_param(IS_SPI_MODULE(SPIx));
    assert_param(IS_SPI_FLAG_Types(Flags));

    SPIx->FR.V32 = (Flags << 16);
}

/**
  * @brief  SPI send data
  * @param  SPIx SPI device: SPI0 or SPI1
  * @param  Data send data
  * @retval None
  */
void SPI_SendData(SPI_TypeDef *SPIx, uint16_t Data)
{
    assert_param(IS_SPI_MODULE(SPIx));

    SPIx->TDR = Data;
}

/**
  * @brief  SPI receive data
  * @param  SPIx SPI device: SPI0 or SPI1
  * @retval uint16_t received data
  */
uint16_t SPI_ReceiveData(SPI_TypeDef *SPIx)
{
    assert_param(IS_SPI_MODULE(SPIx));

    return SPIx->RDR;
}

/**
  * @brief  Enable SPIx TX or RX DMA Channel
  * @param  SPIx SPI device: SPI0 or SPI1
  * @param  SPIFunc: specifies the SPI Config Function.
  *         This parameter can be any combination of following values:  
  *         @arg @b SPI_FUNC_SEND:    Transmit Function.
  *         @arg @b SPI_FUNC_RECEIVE: Receive Function.
  * @param  OnOffState: new state of the SPIx peripheral. 
  *         This parameter can be: SH_ON or SH_OFF.
  * @retval None
  */
void SPI_DMAOnOff(SPI_TypeDef *SPIx, SPI_FUNC_Type SPIFunc, CmdState OnOffState)
{
    assert_param(IS_SPI_MODULE(SPIx));
    assert_param(IS_SPI_FUNC_Type(SPIFunc));
    assert_param(IS_CMD_STATE(OnOffState));

    if (OnOffState == SH_ON)
    {
        if (SPIFunc == SPI_FUNC_SEND)
        {
            SPIx->CR.BIT.SPDMAT = 1; /*Enable SPIx TX DMA Channel*/
        }
        else if (SPIFunc == SPI_FUNC_RECEIVE)
        {
            SPIx->CR.BIT.SPDMAR = 1; /*Enable SPIx RX DMA Channel*/
        }
    }
    else if (OnOffState == SH_OFF)
    {
        if (SPIFunc == SPI_FUNC_SEND)
        {
            SPIx->CR.BIT.SPDMAT = 0; /*Disable SPIx TX DMA Channel*/
        }
        else if (SPIFunc == SPI_FUNC_RECEIVE)
        {
            SPIx->CR.BIT.SPDMAR = 0; /*Disable SPIx RX DMA Channel*/
        }
    }
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
