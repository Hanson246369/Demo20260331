/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_uart.c
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
#include "sh32f9xx_sb0_uart.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/** @defgroup UART 
  * @brief UART driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup UART_Private_Functions
  * @{
  */

/** @defgroup UART_Group1 Initialization and Configuration
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
  * @brief  Fills each UART_InitStruct member with its default value.
  * @param  UART_InitStruct : pointer to a @ref UART_InitTypeDef
  *         structure which will be initialized.
  * @retval None
  */
void UART_StructInit(UART_InitTypeDef *UART_InitStruct)
{
    UART_InitStruct->UART_Mode       = UART_Mode_0;
    UART_InitStruct->UART_BaudRate   = 0x00;
    UART_InitStruct->UART_DataLength = UART_DataLength_8Bit;
    UART_InitStruct->UART_StopBits   = UART_StopBits_None;
    UART_InitStruct->UART_Parity     = UART_Parity_None;
    UART_InitStruct->UART_Enable     = 0x00;
}

/**
  * @brief  Initialize the UART peripheral according to the specified parameters
  *         in the UART_InitStruct.
  * @param  UARTx: where x can be 0,1,2,3,4 or 5 to select the UART peripheral.
  * @param  UART_InitStruct: pointer to a @ref UART_InitTypeDef structure that contains
  *         the configuration information for the specified UART peripheral.
  * @retval None
  */
void UART_Init(UART_TypeDef *UARTx, UART_InitTypeDef *UART_InitStruct)
{
    uint32_t temp = 0x00;
    uint32_t baudRate = 0;
    RCC_Clocks_TypeDef RCC_ClocksStatus;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_MODE(UART_InitStruct->UART_Mode));

    /* Set UART mode */
    UARTx->CR.V32 &= ~UART_CR_SM_Msk;
    UARTx->CR.V32 |= UART_InitStruct->UART_Mode;

    /* UART baud rate configuration */
    if ((UART_InitStruct->UART_Mode == UART_Mode_1) || (UART_InitStruct->UART_Mode == UART_Mode_3))
    {
        RCC_GetClocksFreq(&RCC_ClocksStatus);
        baudRate = RCC_ClocksStatus.pclk1Freq / 16 / UART_InitStruct->UART_BaudRate - 1;
        temp = RCC_ClocksStatus.pclk1Freq / UART_InitStruct->UART_BaudRate - 16 * (baudRate + 1);
        baudRate += temp << 16;
    }

    if (UART_InitStruct->UART_Mode == UART_Mode_0)
    {
        assert_param(IS_UART_MODE_0_BAUDRATE(UART_InitStruct->UART_BaudRate));
        assert_param(IS_UART_MODE_0_STOP_BITS(UART_InitStruct->UART_StopBits));
        assert_param(IS_UART_MODE_01_DATALENGTH(UART_InitStruct->UART_DataLength));
        assert_param(IS_UART_MODE_01_PARITY(UART_InitStruct->UART_Parity));

        /* Set the UART baud rate */
        UARTx->CR.V32 &= ~UART_CR_SM2_Msk;
        UARTx->CR.V32 |= ((UART_InitStruct->UART_BaudRate >> 19) & UART_CR_SM2_Msk);

        /* Set the Parity bit */
        UARTx->CR.V32 &= (~(UART_CR_PCE_Msk | UART_CR_PS_Msk));
        UARTx->CR.V32 |= UART_InitStruct->UART_Parity;
    }
    else if (UART_InitStruct->UART_Mode == UART_Mode_1)
    {
        assert_param(IS_UART_MODE_13_BAUDRATE(UART_InitStruct->UART_BaudRate));
        assert_param(IS_UART_MODE_123_STOP_BITS(UART_InitStruct->UART_StopBits));
        assert_param(IS_UART_MODE_01_DATALENGTH(UART_InitStruct->UART_DataLength));
        assert_param(IS_UART_MODE_01_PARITY(UART_InitStruct->UART_Parity));

        UARTx->BRT.V32 = baudRate;
        UARTx->CR.V32 |= UART_CR_SBRTEN_Msk;

        UARTx->CR.V32 &= ~UART_CR_STOP_Msk;
        UARTx->CR.V32 |= UART_InitStruct->UART_StopBits - 1;

        /* Set the Parity bit */
        UARTx->CR.V32 &= (~(UART_CR_PCE_Msk | UART_CR_PS_Msk));
        UARTx->CR.V32 |= UART_InitStruct->UART_Parity;
    }
    else if (UART_InitStruct->UART_Mode == UART_Mode_2)
    {
        assert_param(IS_UART_MODE_2_BAUDRATE(UART_InitStruct->UART_BaudRate));
        assert_param(IS_UART_MODE_123_STOP_BITS(UART_InitStruct->UART_StopBits));
        assert_param(IS_UART_MODE_23_DATALENGTH(UART_InitStruct->UART_DataLength));
        assert_param(IS_UART_MODE_23_PARITY(UART_InitStruct->UART_Parity));

        UARTx->CR.V32 &= ~UART_CR_SMOD_Msk;
        UARTx->CR.V32 |= ((UART_InitStruct->UART_BaudRate >> 27) & UART_CR_SMOD_Msk);

        UARTx->CR.V32 &= ~UART_CR_STOP_Msk;
        UARTx->CR.V32 |= UART_InitStruct->UART_StopBits - 1;

        /* Set the Parity bit */
        UARTx->CR.V32 &= (~(UART_CR_PCE_Msk | UART_CR_PS_Msk));
        UARTx->CR.V32 |= UART_InitStruct->UART_Parity;
    }
    else
    {
        assert_param(IS_UART_MODE_13_BAUDRATE(UART_InitStruct->UART_BaudRate));
        assert_param(IS_UART_MODE_123_STOP_BITS(UART_InitStruct->UART_StopBits));
        assert_param(IS_UART_MODE_23_DATALENGTH(UART_InitStruct->UART_DataLength));
        assert_param(IS_UART_MODE_23_PARITY(UART_InitStruct->UART_Parity));

        UARTx->BRT.V32 = baudRate;

        UARTx->CR.V32 |= UART_CR_SBRTEN_Msk;

        UARTx->CR.V32 &= ~UART_CR_STOP_Msk;
        UARTx->CR.V32 |= UART_InitStruct->UART_StopBits - 1;

        /* Set the Parity bit */
        UARTx->CR.V32 &= (~(UART_CR_PCE_Msk | UART_CR_PS_Msk));
        UARTx->CR.V32 |= UART_InitStruct->UART_Parity;
    }

    UARTx->CR.V32 &= ~(UART_CR_TEN_Msk | UART_CR_REN_Msk);
    /* Enable UART transmit or receive */
    UARTx->CR.V32 |= UART_InitStruct->UART_Enable;
}

/**
  * @brief  Check whether the specified UART interrupt is enable or disnable.
  * @param  UARTx: where x can be 0,1,2 or 3 to select the UART peripheral.
  * @param  UART_INTEnable: specifie the interrupt enable bit.
  *          This parameter can be one of the following values:
  *            @arg UART_INT_RX 
  *            @arg UART_INT_TX 
  *            @arg UART_INT_TC 
  *            @arg UART_INT_LBD
  * @retval The new state of UART enable(enable or disnable).
  */
FunctionalState UART_GetINTStatus(UART_TypeDef *UARTx, uint8_t UART_INTEnable)
{
    FunctionalState bitStatus;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_INT(UART_INTEnable));

    if ((UARTx->CR.V32 & UART_INTEnable) != SH_RESET)
    {
        bitStatus = SH_ENABLE;
    }
    else
    {
        bitStatus = SH_DISABLE;
    }
    return bitStatus;
}

/**
  * @brief  Check whether the specified UART flag is set or not.
  * @param  UARTx: where x can be 0,1,2,3,4 or 5 to select the UART peripheral.
  * @param  UART_Flag: specifie the flag to check.
  *          This parameter can be one of the following values:
  *            @arg UART_FLAG_RI
  *            @arg UART_FLAG_TI
  *            @arg UART_FLAG_TC
  *            @arg UART_FLAG_TXCOL
  *            @arg UART_FLAG_RXOV
  *            @arg UART_FLAG_FE
  *            @arg UART_FLAG_PE
  *            @arg UART_FLAG_LBD  
  * @retval The new state of UART_Flag(SH_SET or RESET).
  */
FlagStatus UART_GetFlagStatus(UART_TypeDef *UARTx, uint8_t UART_Flag)
{
    FlagStatus bitStatus;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_GET_ONE_FLAG(UART_Flag));

    if ((UARTx->FR.V32 & UART_Flag) != SH_RESET)
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
  * @brief  Clear the UART's pending flags.
  * @param  UARTx: where x can be 0,1,2,3,4 or 5 to select the UART peripheral.
  * @param  UART_Flag: Specifie the flag to clear.
  *         This parameter can be any combination of the following values:
  *            @arg UART_FLAG_RI
  *            @arg UART_FLAG_TC
  *            @arg UART_FLAG_TXCOL
  *            @arg UART_FLAG_RXOV
  *            @arg UART_FLAG_FE
  *            @arg UART_FLAG_PE
  *            @arg UART_FLAG_LBD  
  * @retval None
  */
void UART_ClearFlag(UART_TypeDef *UARTx, uint8_t UART_Flag)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_FLAG(UART_Flag));

    UARTx->FR.V32 |= ((uint32_t)UART_Flag << 16);
}

/**
  * @brief  Enable or disable the specified UART's interrupts.
  * @param  UARTx: where x can be 0,1,2,3,4 or 5 to select the UART peripheral.
  * @param  UART_INT: specifie the UART interrupt sources to be enabled or disabled.
  *          This parameter can be any combination of the following values:
  *            @arg UART_INT_RX
  *            @arg UART_INT_TX
  *            @arg UART_INT_TC
  *            @arg UART_INT_LBD  
  * @param  NewState: New state of UART interrupt.
  *          This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void UART_INTConfig(UART_TypeDef *UARTx, uint8_t UART_INT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_INT(UART_INT));
    assert_param(IS_FUNCTION_STATE(NewState));

    if (NewState != SH_DISABLE)
    {
        UARTx->CR.V32 |= UART_INT;
    }
    else
    {
        UARTx->CR.V32 &= ~UART_INT;
    }
}

/**
  * @brief  Enable or disable the UART's DMA request sources.
  * @param  UARTx: where x can be 0,1,2,3,4 or 5 to select the UART peripheral.
  * @param  UART_DMASource: specifies the DMA request.
  *          This parameter can be any combination of the following values:
  *            @arg UART_DMA_RX
  *            @arg UART_DMA_TX
  * @param  NewState: new state of the DMA Request sources.
  *          This parameter can be one of the following values:
  *            @arg SH_ENABLE
  *            @arg SH_DISABLE
  * @retval None
  */
void UART_DMAConfig(UART_TypeDef *UARTx, uint32_t UART_DMASource, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_DMA_SOURCE(UART_DMASource));
    assert_param(IS_FUNCTION_STATE(NewState));

    if (NewState != SH_DISABLE)
    {
        /* Enable the UART's DMA request sources */
        UARTx->CR.V32 |= UART_DMASource;
    }
    else
    {
        /* Disable the UART's DMA request sources */
        UARTx->CR.V32 &= ~UART_DMASource;
    }
}

/**
  * @brief  Transmit single data through the UARTx peripheral.
  * @param  UARTx: where x can be 0,1,2,3,4 or 5 to select the UART peripheral.
  * @param  SendData: the data to transmit.
  * @retval None
  */
void UART_SendData(UART_TypeDef *UARTx, uint8_t SendData)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));

    /* Transmit data */
    UARTx->TDR = SendData;
}

/**
  * @brief  Return the most recent received data by the UARTx peripheral.
  * @param  UARTx: where x can be 0,1,2,3,4 or 5 to select the UART peripheral.
  * @retval The received data.
  */
uint16_t UART_ReceiveData(UART_TypeDef *UARTx)
{
    uint16_t tempData = 0;
    uint16_t tempReg = 0;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));

    tempReg = (uint16_t)(UARTx->CR.V32 & UART_CR_SM_Msk);

    if ((tempReg == UART_Mode_0) || (tempReg == UART_Mode_1))
    {
        tempData = UARTx->RDR;
    }
    else
    {
        tempData = (UARTx->CR.V32 & UART_CR_RB8_Msk);
        tempData |= UARTx->RDR;
    }
    return tempData;
}

/**
  * @brief  Enable or Disable the UART's LIN mode.
  * @param  UARTx: where x can be 1, 2, 3 to select the UART peripheral.
  * @param  UART_LINDetectLength: specifie the LIN break detect length.
  *          This parameter can be one of the following values:
  *            @arg UART_LINDetectLength_10b
  *            @arg UART_LINDetectLength_11b
  * @retval None
  */
void UART_LINDetectLengthConfig(UART_TypeDef *UARTx, uint16_t UART_LINDetectLength)
{
    uint32_t temp = 0;

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_LIN_DETECT_LENGTH(UART_LINDetectLength));

    temp = UARTx->CR.V32;
    temp &= ~UART_CR_LBDL_Msk;
    temp |= UART_LINDetectLength;
    UARTx->CR.V32 = temp;
}

/**
  * @brief   Uart0 Remap navigation map array
  */
const UART_AFTypeDef UART0_Channel[4][2] =
    {
        {{GPIOA, GPIO_Pin_3, GPIO_AF_UART0},
         {GPIOA, GPIO_Pin_4, GPIO_AF_UART0}},

        {{GPIOB, GPIO_Pin_6, GPIO_AF_UART0},
         {GPIOB, GPIO_Pin_7, GPIO_AF_UART0}},

        {{GPIOC, GPIO_Pin_11, GPIO_AF_UART0},
         {GPIOC, GPIO_Pin_10, GPIO_AF_UART0}},

        {{GPIOD, GPIO_Pin_14, GPIO_AF_UART0},
         {GPIOD, GPIO_Pin_13, GPIO_AF_UART0}}};

/**
  * @brief   Uart1 Remap navigation map array
  */
const UART_AFTypeDef UART1_Channel[5][2] =
    {
        {{GPIOA, GPIO_Pin_5, GPIO_AF_UART1},
         {GPIOA, GPIO_Pin_6, GPIO_AF_UART1}},

        {{GPIOB, GPIO_Pin_8, GPIO_AF_UART1},
         {GPIOB, GPIO_Pin_9, GPIO_AF_UART1}},

        {{GPIOC, GPIO_Pin_7, GPIO_AF_UART1},
         {GPIOC, GPIO_Pin_8, GPIO_AF_UART1}},

        {{GPIOC, GPIO_Pin_12, GPIO_AF_UART1},
         {GPIOC, GPIO_Pin_13, GPIO_AF_UART1}},

        {{GPIOD, GPIO_Pin_15, GPIO_AF_UART1},
         {GPIOE, GPIO_Pin_0, GPIO_AF_UART1}}};

/**
  * @brief   Uart2 Remap navigation map array
  */
const UART_AFTypeDef UART2_Channel[5][2] =
    {
        {{GPIOA, GPIO_Pin_7, GPIO_AF_UART2},
         {GPIOA, GPIO_Pin_8, GPIO_AF_UART2}},

        {{GPIOB, GPIO_Pin_10, GPIO_AF_UART2},
         {GPIOB, GPIO_Pin_11, GPIO_AF_UART2}},

        {{GPIOC, GPIO_Pin_14, GPIO_AF_UART2},
         {GPIOC, GPIO_Pin_15, GPIO_AF_UART2}},

        {{GPIOE, GPIO_Pin_1, GPIO_AF_UART2},
         {GPIOE, GPIO_Pin_2, GPIO_AF_UART2}},

        {{GPIOE, GPIO_Pin_5, GPIO_AF_UART2},
         {GPIOE, GPIO_Pin_6, GPIO_AF_UART2}}};

/**
  * @brief   Uart3 Remap navigation map array
  */
const UART_AFTypeDef UART3_Channel[4][2] =
    {
        {{GPIOA, GPIO_Pin_0, GPIO_AF_UART3},
         {GPIOA, GPIO_Pin_1, GPIO_AF_UART3}},

        {{GPIOB, GPIO_Pin_0, GPIO_AF_UART3},
         {GPIOB, GPIO_Pin_1, GPIO_AF_UART3}},

        {{GPIOC, GPIO_Pin_0, GPIO_AF_UART3},
         {GPIOC, GPIO_Pin_1, GPIO_AF_UART3}},

        {{GPIOD, GPIO_Pin_0, GPIO_AF_UART3},
         {GPIOD, GPIO_Pin_1, GPIO_AF_UART3}}};

/**
  * @brief   Uart4 Remap navigation map array
  */
const UART_AFTypeDef UART4_Channel[4][2] =
    {
        {{GPIOA, GPIO_Pin_9, GPIO_AF_UART4},
         {GPIOA, GPIO_Pin_10, GPIO_AF_UART4}},

        {{GPIOB, GPIO_Pin_2, GPIO_AF_UART4},
         {GPIOB, GPIO_Pin_3, GPIO_AF_UART4}},

        {{GPIOC, GPIO_Pin_2, GPIO_AF_UART4},
         {GPIOC, GPIO_Pin_3, GPIO_AF_UART4}},

        {{GPIOD, GPIO_Pin_2, GPIO_AF_UART4},
         {GPIOD, GPIO_Pin_3, GPIO_AF_UART4}}};

/**
  * @brief   Uart5 Remap navigation map array
  */
const UART_AFTypeDef UART5_Channel[4][2] =
    {
        {{GPIOA, GPIO_Pin_11, GPIO_AF_UART5},
         {GPIOA, GPIO_Pin_12, GPIO_AF_UART5}},

        {{GPIOB, GPIO_Pin_4, GPIO_AF_UART5},
         {GPIOB, GPIO_Pin_5, GPIO_AF_UART5}},

        {{GPIOC, GPIO_Pin_4, GPIO_AF_UART5},
         {GPIOC, GPIO_Pin_5, GPIO_AF_UART5}},

        {{GPIOD, GPIO_Pin_4, GPIO_AF_UART5},
         {GPIOD, GPIO_Pin_5, GPIO_AF_UART5}}};

/**
  * @brief  Configure the currently selected channel
  * @param  UARTx: Where x can be 0,1,2,3,4 or 5 to select the UART peripheral.
  * @param  RemapNum: Current Remap channel number,it can be 0,1,2,3,4,5
  * @note   None
  * @retval None
  */
void UART_InitAF(UART_TypeDef *UARTx, uint8_t RemapNum)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    UART_AFTypeDef tempTxdAF;
    UART_AFTypeDef tempRxdAF;
    if (UART0 == UARTx)
    {
        tempTxdAF.UART_GPIOx    = UART0_Channel[RemapNum][0].UART_GPIOx;
        tempTxdAF.UART_GPIO_Pin = UART0_Channel[RemapNum][0].UART_GPIO_Pin;
        tempTxdAF.UART_GPIO_AF  = UART0_Channel[RemapNum][0].UART_GPIO_AF;

        tempRxdAF.UART_GPIOx    = UART0_Channel[RemapNum][1].UART_GPIOx;
        tempRxdAF.UART_GPIO_Pin = UART0_Channel[RemapNum][1].UART_GPIO_Pin;
        tempRxdAF.UART_GPIO_AF  = UART0_Channel[RemapNum][1].UART_GPIO_AF;
    }
    else if (UART1 == UARTx)
    {
        tempTxdAF.UART_GPIOx    = UART1_Channel[RemapNum][0].UART_GPIOx;
        tempTxdAF.UART_GPIO_Pin = UART1_Channel[RemapNum][0].UART_GPIO_Pin;
        tempTxdAF.UART_GPIO_AF  = UART1_Channel[RemapNum][0].UART_GPIO_AF;

        tempRxdAF.UART_GPIOx    = UART1_Channel[RemapNum][1].UART_GPIOx;
        tempRxdAF.UART_GPIO_Pin = UART1_Channel[RemapNum][1].UART_GPIO_Pin;
        tempRxdAF.UART_GPIO_AF  = UART1_Channel[RemapNum][1].UART_GPIO_AF;
    }
    else if (UART2 == UARTx)
    {
        tempTxdAF.UART_GPIOx    = UART2_Channel[RemapNum][0].UART_GPIOx;
        tempTxdAF.UART_GPIO_Pin = UART2_Channel[RemapNum][0].UART_GPIO_Pin;
        tempTxdAF.UART_GPIO_AF  = UART2_Channel[RemapNum][0].UART_GPIO_AF;

        tempRxdAF.UART_GPIOx    = UART2_Channel[RemapNum][1].UART_GPIOx;
        tempRxdAF.UART_GPIO_Pin = UART2_Channel[RemapNum][1].UART_GPIO_Pin;
        tempRxdAF.UART_GPIO_AF  = UART2_Channel[RemapNum][1].UART_GPIO_AF;
    }
    else if (UART3 == UARTx)
    {
        tempTxdAF.UART_GPIOx    = UART3_Channel[RemapNum][0].UART_GPIOx;
        tempTxdAF.UART_GPIO_Pin = UART3_Channel[RemapNum][0].UART_GPIO_Pin;
        tempTxdAF.UART_GPIO_AF  = UART3_Channel[RemapNum][0].UART_GPIO_AF;

        tempRxdAF.UART_GPIOx    = UART3_Channel[RemapNum][1].UART_GPIOx;
        tempRxdAF.UART_GPIO_Pin = UART3_Channel[RemapNum][1].UART_GPIO_Pin;
        tempRxdAF.UART_GPIO_AF  = UART3_Channel[RemapNum][1].UART_GPIO_AF;
    }
    else if (UART4 == UARTx)
    {
        tempTxdAF.UART_GPIOx    = UART4_Channel[RemapNum][0].UART_GPIOx;
        tempTxdAF.UART_GPIO_Pin = UART4_Channel[RemapNum][0].UART_GPIO_Pin;
        tempTxdAF.UART_GPIO_AF  = UART4_Channel[RemapNum][0].UART_GPIO_AF;

        tempRxdAF.UART_GPIOx    = UART4_Channel[RemapNum][1].UART_GPIOx;
        tempRxdAF.UART_GPIO_Pin = UART4_Channel[RemapNum][1].UART_GPIO_Pin;
        tempRxdAF.UART_GPIO_AF  = UART4_Channel[RemapNum][1].UART_GPIO_AF;
    }
    else if (UART5 == UARTx)
    {
        tempTxdAF.UART_GPIOx    = UART5_Channel[RemapNum][0].UART_GPIOx;
        tempTxdAF.UART_GPIO_Pin = UART5_Channel[RemapNum][0].UART_GPIO_Pin;
        tempTxdAF.UART_GPIO_AF  = UART5_Channel[RemapNum][0].UART_GPIO_AF;

        tempRxdAF.UART_GPIOx    = UART5_Channel[RemapNum][1].UART_GPIOx;
        tempRxdAF.UART_GPIO_Pin = UART5_Channel[RemapNum][1].UART_GPIO_Pin;
        tempRxdAF.UART_GPIO_AF  = UART5_Channel[RemapNum][1].UART_GPIO_AF;
    }
    else
    {
        ;
    }

    GPIO_InitStructure.GPIO_Pin   = tempTxdAF.UART_GPIO_Pin;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_ODrv  = GPIO_ODrv_NORMAL;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_Init(tempTxdAF.UART_GPIOx, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin   = tempRxdAF.UART_GPIO_Pin;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
    GPIO_Init(tempRxdAF.UART_GPIOx, &GPIO_InitStructure);

    GPIO_PinAFConfig(tempTxdAF.UART_GPIOx, tempTxdAF.UART_GPIO_Pin, tempTxdAF.UART_GPIO_AF);
    GPIO_PinAFConfig(tempRxdAF.UART_GPIOx, tempRxdAF.UART_GPIO_Pin, tempRxdAF.UART_GPIO_AF);
}

/**
  * @brief  Open or close uartx modules' clock gate
  * @param  UARTx: Where x can be 1,2,3,4,5,6,7,8 to select the UART peripheral.
  * @param  OnOffState: Open or close related clock gate
  *             @arg ON:  Open related clock gate
  *             @arg OFF: Close related clock gate
  * @note   None
  * @retval None
  */
void UART_ClockOnOff(UART_TypeDef *UARTx, CmdState OnOffState)
{
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));

    if (UARTx == UART0)
    {
        RCC_APB1PeriphClockOnOff(RCC_APB1_UART0, SH_ON);
    }
    else if (UARTx == UART1)
    {
        RCC_APB1PeriphClockOnOff(RCC_APB1_UART1, SH_ON);
    }
    else if (UARTx == UART2)
    {
        RCC_APB1PeriphClockOnOff(RCC_APB1_UART2, SH_ON);
    }
    else if (UARTx == UART3)
    {
        RCC_APB1PeriphClockOnOff(RCC_APB1_UART3, SH_ON);
    }
    else if (UARTx == UART4)
    {
        RCC_APB1PeriphClockOnOff(RCC_APB1_UART4, SH_ON);
    }
    else if (UARTx == UART5)
    {
        RCC_APB1PeriphClockOnOff(RCC_APB1_UART5, SH_ON);
    }
    else
    {
        ;
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
