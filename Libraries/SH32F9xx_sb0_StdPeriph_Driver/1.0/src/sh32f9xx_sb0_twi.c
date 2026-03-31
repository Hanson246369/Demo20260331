/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_twi.c
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file provide APIs for using TWI module
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
#include "sh32f9xx_sb0_twi.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/* TWI  Module----------------------------------------------------------*/
/** @defgroup TWI_MODULE  TWI 
   *  TWI Calculate Mode
  * @{
  */

/**
  * @brief  Fills each TWI_InitStruct member with its default value. 
  * @param  TWI_InitStruct: pointer to a @ref TWI_InitTypeDef structure which will 
  *         be initialized.
  * @retval None
  */
void TWI_StructInit(TWI_InitTypeDef *TWI_InitStruct)
{
    /* for address register */
    /* Initialize General Address: SH_ENABLE or SH_DISABLE */
    TWI_InitStruct->GeneralAddress = SH_DISABLE;

    /* Initialize the 7 bits address */
    TWI_InitStruct->TWIAddress = 0x00;

    /* Initialize the TWI address mask bit 0:Must match 1:Ignore */
    TWI_InitStruct->MaskAddress = 0x00;

    /* Initialize the Clock prescale: @ref TWI_CLKRATE_Type */
    TWI_InitStruct->PresClock = TWI_CR_DIV_64;

    /* Initialize the Bus timeout count */
    TWI_InitStruct->BusTimeOut = TWI_CNT_25000;

    /* Initialize the High level timeout enable bit */
    TWI_InitStruct->HighLevelTimeOutEnable = SH_DISABLE;

    /* Initialize the Bus timeout enable bit */
    TWI_InitStruct->BusTimeOutEnable = SH_DISABLE;

    /* Initialize the Baudrate */
    TWI_InitStruct->BaudRate = 0x00;

    /* Initialize the High level timeout count */
    TWI_InitStruct->HighLevelTimeOut = 0xFF;
}

/**     
  * @brief  Initializes the TWIx peripheral according to the specified 
  *   parameters in the InitCfg.
  * @param  TWIx  TWI device: TWI0  TWI1
  * @param  InitCfg  pointer to a TWI_InitTypeDef structure that
  *   contains the configuration information for the specified TWI peripheral.
  * @retval None
  */

void TWI_Init(TWI_TypeDef *TWIx, const TWI_InitTypeDef *InitCfg)
{
    assert_param(IS_TWI_MODULE(TWIx));
    assert_param((InitCfg->BaudRate & 0x80) == 0);

    TWIx->ADDR.BIT.GC = InitCfg->GeneralAddress;
    TWIx->CR.BIT.CR   = InitCfg->PresClock;
    TWIx->CR.BIT.CNT  = InitCfg->BusTimeOut;

    TWIx->CR.BIT.EFREE = InitCfg->HighLevelTimeOutEnable;
    TWIx->CR.BIT.ETOT  = InitCfg->BusTimeOutEnable;

    TWIx->ADDR.BIT.ADDR   = InitCfg->TWIAddress;
    TWIx->ADDR.BIT.TWIAMR = InitCfg->MaskAddress;
    TWIx->BRT = InitCfg->BaudRate;
    TWIx->HOC = InitCfg->HighLevelTimeOut;
}

/**
  * @brief  Deinitializes the TWIx peripheral registers to their default
  *   reset values 
  * @param  TWIx  TWI device: TWI0  TWI1
  * @retval None
  */
void TWI_Reset(TWI_TypeDef *TWIx)
{
    /* Check the parameters */
    assert_param(IS_TWI_MODULE(TWIx));

    if (TWIx == TWI1)
    {
        /* Reset TWI1 module */
        RCC_APB1PeriphReset(RCC_APB1_TWI1);
    }
}

/**
  * @brief  Enables or disables the specified TWI peripheral.
  * @param  TWIx  TWI device: TWI0  TWI1
  * @param  OnOffState: new state of the TWIx peripheral. 
  *   This parameter can be: SH_ON or SH_OFF.
  * @retval None
  */
void TWI_OnOff(TWI_TypeDef *TWIx, CmdState OnOffState)
{
    assert_param(IS_TWI_MODULE(TWIx));
    assert_param(IS_CMD_STATE(OnOffState));

    TWIx->CR.BIT.TWIEN = OnOffState;
}

/**
  * @brief  TWI General address enable.
  * @param  TWIx  TWI device: TWI0  TWI1
  * @param  TWIState: new mode of the TWIx peripheral. 
  *   This parameter can be: SH_ENABLE or SH_DISABLE
  * @retval None
  */
void TWI_AddrModeConfig(TWI_TypeDef *TWIx, FunctionalState TWIState)
{

    /* Check the parameters */
    assert_param(IS_TWI_MODULE(TWIx));
    assert_param(IS_FUNCTION_STATE(TWIState));

    TWIx->ADDR.BIT.GC = TWIState;
}

/**
  * @brief  Enables or disables the specified TWI interrupts.
  * @param  TWIx  TWI device: TWI0  TWI1
  * @param  NewState: new state of the specified TWI/I2S interrupt.
  *   This parameter can be: SH_ENABLE or SH_DISABLE.
  * @retval None
  */
void TWI_INTConfig(TWI_TypeDef *TWIx, FunctionalState NewState)
{
    assert_param(IS_TWI_MODULE(TWIx));
    assert_param(IS_FUNCTION_STATE(NewState));

    TWIx->CR.BIT.TWINTE = NewState;
}

/**
  * @brief  Checks whether the specified TWI interrupt has occurred or not.
  * @param  TWIx device: TWI1
   * @retval FlagStatus The new state interrupt (SH_SET or RESET).
  */
FlagStatus TWI_GetINTStatus(TWI_TypeDef *TWIx)
{
    uint32_t tmpV;
    assert_param(IS_TWI_MODULE(TWIx));
    tmpV = TWIx->FR.BIT.TWINT;
    return ((tmpV) ? SH_SET : SH_RESET);
}

/**
  * @brief  Clears the TWIx interrupt pending bit.
  * @param  TWIx  TWI device: TWI0  TWI1
  * @retval None
  */
void TWI_ClearINTStatus(TWI_TypeDef *TWIx)
{
    assert_param(IS_TWI_MODULE(TWIx));
    TWIx->FR.BIT.TWINTC = 1;
}

/**
  * @brief  get TWI transmit flag
  * @param  TWIx  TWI device: TWI0  TWI1
  * @param  Flag  TWI flag mask
  *   This parameter can be one of following values:
  *     @arg @b  TWI_FLAG_INT Interrupt flag
  *     @arg @b  TWI_FLAG_SCL_TIMEOUT SCL high level timeout flag
  *     @arg @b  TWI_FLAG_BUS_TIMEOUT  Bus timeout flag
  * @retval  FlagStatus RCC reset flag
  *     @arg @b  SH_SET    the flag is setted
  *     @arg @b  RESET  the flag is cleared
  */
FlagStatus TWI_GetFlagStatus(TWI_TypeDef *TWIx, TWI_FLAG_Type Flag)
{
    assert_param(IS_TWI_MODULE(TWIx));
    assert_param(IS_TWI_FLAG_Type(Flag));

    return ((TWIx->FR.V32 & Flag) ? SH_SET : SH_RESET);
}

/**
  * @brief  clear TWI transmit flags
  * @param  TWIx  TWI device: TWI0  TWI1
  * @param  Flags   TWI flags clear bit mask
  *   This parameter can be any combination of following values:
  *     @arg @b  TWI_FLAG_INT Interrupt flag
  *     @arg @b  TWI_FLAG_SCL_TIMEOUT  SCL high level timeout flag
  *     @arg @b  TWI_FLAG_BUS_TIMEOUT  Bus timeout flag
  * @retval None
  */
void TWI_ClearFlag(TWI_TypeDef *TWIx, uint32_t Flags)
{
    assert_param(IS_TWI_MODULE(TWIx));
    assert_param(IS_TWI_FLAG_Types(Flags));

    TWIx->FR.V32 = (Flags << 16);
}

/**
  * @brief  TWI send data
  * @param  TWIx  TWI device: TWI0  TWI1
  * @param  Data send data
  * @retval None
  */
void TWI_SendData(TWI_TypeDef *TWIx, uint8_t Data)
{
    assert_param(IS_TWI_MODULE(TWIx));

    TWIx->DR = Data;
}

/**
  * @brief  TWI receive data
  * @param  TWIx  TWI device: TWI0  TWI1
  * @retval uint16_t received data
  */
uint8_t TWI_ReceiveData(TWI_TypeDef *TWIx)
{
    assert_param(IS_TWI_MODULE(TWIx));

    return TWIx->DR;
}

/* get TWI transmit event */
/**
  * @brief  get TWI transmit event
  * @param  TWIx  TWI device: TWI0  TWI1
  * @retval TWI_EVENT_Type TWI transmit event flag
  */
TWI_EVENT_Type TWI_GetEvent(TWI_TypeDef *TWIx)
{
    assert_param(IS_TWI_MODULE(TWIx));

    return (TWI_EVENT_Type)(TWIx->STAT.V32);
}

/**
  * @brief  Generates TWI communication START condition.
  * @param  TWIx  TWI device: TWI0  TWI1
  * @param  NewState: new state of the I2C START condition generation.
  *   This parameter can be: SH_ENABLE or SH_DISABLE.
  * @retval None.
  */
void TWI_START(TWI_TypeDef *TWIx, FunctionalState NewState)
{
    assert_param(IS_TWI_MODULE(TWIx));
    assert_param(IS_FUNCTION_STATE(NewState));

    TWIx->CR.BIT.STA = NewState;
}

/**
  * @brief  Generates TWI communication STOP condition.
  * @param  TWIx  TWI device: TWI0  TWI1
  * @param  NewState: new state of the I2C STOP condition generation.
  *   This parameter can be: SH_ENABLE or SH_DISABLE.
  * @retval None.
  */
void TWI_STOP(TWI_TypeDef *TWIx, FunctionalState NewState)
{
    assert_param(IS_TWI_MODULE(TWIx));
    assert_param(IS_FUNCTION_STATE(NewState));

    TWIx->CR.BIT.STO = NewState;
}

/**
  * @brief  Enables or disables the specified TWI Response feature.
  * @param  TWIx  TWI device: TWI0  TWI1
  * @param  NewAck: new state of the TWI Acknowledgement.
  *   This parameter can be: TWI_AA_NACK or TWI_AA_ACK.
  * @retval None.
  */
void TWI_ACK_Config(TWI_TypeDef *TWIx, TWI_AA_Type NewAck)
{
    /* Check the parameters */
    assert_param(IS_TWI_MODULE(TWIx));
    assert_param(IS_TWI_AA_Type(NewAck));

    TWIx->CR.BIT.AA = NewAck;
}

/**
  * @brief  Send 7bit address and read/write flag
  * @param  TWIx  TWI device: TWI0  TWI1
  * @param  Address  device address
  * @param  TWI_Direction  transmit direction 
  *   This parameter can be: TWI_DIR_TRANSMITTER or TWI_DIR_RECEIVER.
  * @retval None.
  */
void TWI_Send7bitAddress(TWI_TypeDef *TWIx, uint8_t Address, TWI_DIR_Type TWI_Direction)
{
    assert_param(IS_TWI_MODULE(TWIx));
    assert_param(IS_TWI_DIR_Type(TWI_Direction));

    if (TWI_Direction == TWI_DIR_TRANSMITTER)
        TWIx->DR = (Address << 1);
    else
        TWIx->DR = ((Address << 1) | 1);
}

/**
  * @brief  Configures the specified TWI own address.
  * @param  TWIx  TWI device: TWI0  TWI1
  * @param  Address:    specifies the own address.
  * @param  AddressMsk: specifies the own address mask bits.
  * @param  NewState:   Enable/Disable 
  * @retval None.
  */
void TWI_OwnAddressConfig(TWI_TypeDef *TWIx, uint8_t Address, uint8_t AddressMsk, FunctionalState NewState)
{
    assert_param(IS_TWI_MODULE(TWIx));
    assert_param(Address < 0x80);
    assert_param(AddressMsk < 0x80);
    assert_param(IS_FUNCTION_STATE(NewState));

    TWIx->ADDR.V32 = ((Address << TWI_ADDR_ADDR_Pos) \
                     | (AddressMsk << TWI_ADDR_TWIAMR_Pos) \
                     | (NewState << TWI_ADDR_GC_Pos));
}

/**
  * @brief  Send TWI commands
  * @param  TWIx  TWI device: TWI0  TWI1
  * @retval TWI_EVENT_Type TWI event flags.
  */
TWI_EVENT_Type TWI_SendWaitDone(TWI_TypeDef *TWIx)
{
    assert_param(IS_TWI_MODULE(TWIx));

    /* clear Interrupt Flag to start transmit */
    TWIx->FR.V32 = (TWI_FR_TOUTC_Msk | TWI_FR_TFREEC_Msk | TWI_FR_TWINTC_Msk);

    while (TWI_GetFlagStatus(TWIx, TWI_FLAG_INT) != SH_SET);

    /* Clear TWI1->CR.STA / TWI1->CR.STO */
    TWIx->CR.BIT.STA = SH_RESET;
    TWIx->CR.BIT.STO = SH_RESET;
    return (TWI_EVENT_Type)(TWIx->STAT.V32);
}

/**
  * @brief  Send TWI commands
  * @param  TWIx  TWI device: TWI0  TWI1
  * @param  CmdType:    TWI Commands as below
  *    @arg @b TWI_CMD_START  Send START Condition 
  *    @arg @b TWI_CMD_ACK    Response ACK 
  *    @arg @b TWI_CMD_NACK   Response NACK
  *    @arg @b TWI_CMD_STARTSTOP  Send STOP condition then send START condition
  * @retval TWI_EVENT_Type TWI event flags.
  */
TWI_EVENT_Type TWI_SendCommand(TWI_TypeDef *TWIx, TWI_COMMAND_Type CmdType)
{
    assert_param(IS_TWI_MODULE(TWIx));
    assert_param(IS_TWI_COMMAND_Type(CmdType));

    switch (CmdType)
    {
    case TWI_CMD_START:
        TWIx->CR.BIT.STA = SH_SET;
        break;
    case TWI_CMD_ACK:
        TWIx->CR.BIT.AA = TWI_AA_ACK;
        break;
    case TWI_CMD_NACK:
        TWIx->CR.BIT.AA = TWI_AA_NACK;
        break;
    case TWI_CMD_STOPSTART:
        TWIx->CR.BIT.STA = SH_SET;
        TWIx->CR.BIT.STO = SH_SET;
        break;
    default:
        break;
    }

    return TWI_SendWaitDone(TWIx);
}

/* @endcode
  * @brief  read EEPROM one byte
  * @param  TWIx  TWI device: TWI0  TWI1
  * @param  EECfg: EEPROM TWI parameters
  * @param  ReadAddr: data address for read
  * @retval uint8_t read data, if read fail the return value always 0
  */
uint8_t TWI_EEReadByte(TWI_TypeDef *TWIx, const TWI_EETypeDef *EECfg, uint16_t ReadAddr)
{
    __IO uint8_t event;
    uint8_t readData = 0;

    assert_param(IS_TWI_MODULE(TWIx));

    /* 1. Send START condition */
    event = TWI_SendCommand(TWIx, TWI_CMD_START);
    if (event != TWI_MASTER_START_SEND && event != TWI_MASTER_RESTART_SEND)
        return readData;

    /* 2. Send Hardware address */
    TWI_Send7bitAddress(TWIx, EECfg->EEHWAddr, TWI_DIR_TRANSMITTER);
    event = TWI_SendWaitDone(TWIx);
    if (event != TWI_MASTER_SLA_W_ACK)
        return readData;

    /* 3. send read address */
    if (EECfg->AddrBytes == 2)
    {
        TWI_SendData(TWIx, (uint8_t)(ReadAddr >> 8));
        event = TWI_SendWaitDone(TWIx);
        if (event != TWI_MASTER_DATA_SEND_ACK)
            return readData;
    }
    TWI_SendData(TWIx, (uint8_t)(ReadAddr & 0XFF));
    event = TWI_SendWaitDone(TWIx);
    if (event != TWI_MASTER_DATA_SEND_ACK)
        return readData;

    /* 4. Send RESTART condition */
    event = TWI_SendCommand(TWIx, TWI_CMD_START);
    if (event != TWI_MASTER_START_SEND && event != TWI_MASTER_RESTART_SEND)
        return readData;

    /* 5. Send Hardware address */
    TWI_Send7bitAddress(TWIx, EECfg->EEHWAddr, TWI_DIR_RECEIVER);
    event = TWI_SendWaitDone(TWIx);
    if (event != TWI_MASTER_SLA_R_ACK)
        return readData;

    /* 6. Response ACK */
    event = TWI_SendCommand(TWIx, TWI_CMD_ACK);
    if (event != TWI_MASTER_DATA_RECEIVE_ACK)
        return readData;

    /* 7. Read data */
    readData = TWIx->DR;

    /* 8. Response NACK to inform EEPROM stop transmit */
    event = TWI_SendCommand(TWIx, TWI_CMD_NACK);
    assert_param(event == TWI_MASTER_DATA_RECEIVE_NACK);

    /* 9. Send STOP condition */
    TWI_STOP(TWIx, SH_ENABLE);
    /* clear Interrupt Flag to start transmit,  */
    TWIx->FR.V32 = (TWI_FR_TOUTC_Msk | TWI_FR_TFREEC_Msk | TWI_FR_TWINTC_Msk);
 
    return readData;
}

/** @brief   write one byte data to EEPROM 
  * @param  TWIx  TWI device: TWI0  TWI1
  * @param  EECfg: EEPROM TWI parameters
  * @param  WriteAddr: data address for write
  * @param  Data: data for write
  * @retval bool_t SH_TRUE for write success and SH_FALSE for write fail
  */
bool_t TWI_EEWriteByte(TWI_TypeDef *TWIx, const TWI_EETypeDef *EECfg, uint16_t WriteAddr, uint8_t Data)
{
    __IO uint8_t event;

    assert_param(IS_TWI_MODULE(TWIx));

    /* 1. Send START condition */
    event = TWI_SendCommand(TWIx, TWI_CMD_START);
    if (event != TWI_MASTER_START_SEND && event != TWI_MASTER_RESTART_SEND)
        return SH_FALSE;

    /* 2. Send Hardware address */
    TWI_Send7bitAddress(TWIx, EECfg->EEHWAddr, TWI_DIR_TRANSMITTER);
    event = TWI_SendWaitDone(TWIx);
    if (event != TWI_MASTER_SLA_W_ACK)
        return SH_FALSE;

    /* 3. send read address */
    if (EECfg->AddrBytes == 2)
    {
        TWI_SendData(TWIx, (uint8_t)(WriteAddr >> 8));
        event = TWI_SendWaitDone(TWIx);
        if (event != TWI_MASTER_DATA_SEND_ACK)
            return SH_FALSE;
    }

    TWI_SendData(TWIx, (uint8_t)(WriteAddr & 0XFF));
    event = TWI_SendWaitDone(TWIx);
    if (event != TWI_MASTER_DATA_SEND_ACK)
        return SH_FALSE;

    /* 4. send data to write */
    TWI_SendData(TWIx, Data);
    event = TWI_SendWaitDone(TWIx);
    if (event != TWI_MASTER_DATA_SEND_ACK)
        return SH_FALSE;

    /* 5. Send STOP condition */
    TWI_STOP(TWIx, SH_ENABLE);
    /* clear Interrupt Flag to start transmit,  */
    TWIx->FR.V32 = (TWI_FR_TOUTC_Msk | TWI_FR_TFREEC_Msk | TWI_FR_TWINTC_Msk);

    /* 6. Restart condition to wait EEPROM write done. No response if EEPROM is busy */
    do
    {
        event = TWI_SendCommand(TWIx, TWI_CMD_START);
        if (event != TWI_MASTER_START_SEND && event != TWI_MASTER_RESTART_SEND)
            continue;

        TWI_Send7bitAddress(TWIx, EECfg->EEHWAddr, TWI_DIR_TRANSMITTER);
        event = TWI_SendWaitDone(TWIx);
    } while (event != TWI_MASTER_SLA_W_ACK);

    /* 7. Send STOP condition */
    TWI_STOP(TWIx, SH_ENABLE);
    /* clear Interrupt Flag to start transmit,  */
    TWIx->FR.V32 = (TWI_FR_TOUTC_Msk | TWI_FR_TFREEC_Msk | TWI_FR_TWINTC_Msk);

    return SH_TRUE;
}

/** @brief  Read EEPROM data to buffer
  * @param  TWIx  TWI device: TWI0  TWI1
  * @param  EECfg: EEPROM TWI parameters
  * @param  ReadAddr: data address for write
  * @param  ReadBuffer: buffer for read data
  * @param  ReadBytes: bytes count need read
  * @retval bool_t SH_TRUE for read success and SH_FALSE for read fail
  */
bool_t TWI_EEReadBuffer(TWI_TypeDef *TWIx, const TWI_EETypeDef *EECfg, uint16_t ReadAddr, uint8_t *ReadBuffer, uint16_t ReadBytes)
{
    __IO uint8_t event;
    assert_param(IS_TWI_MODULE(TWIx));

    /* 1. Send START condition */
    event = TWI_SendCommand(TWIx, TWI_CMD_START);
    if (event != TWI_MASTER_START_SEND && event != TWI_MASTER_RESTART_SEND)
        return SH_FALSE;

    /* 2. Send Hardware address */
    TWI_Send7bitAddress(TWIx, EECfg->EEHWAddr, TWI_DIR_TRANSMITTER);
    event = TWI_SendWaitDone(TWIx);
    if (event != TWI_MASTER_SLA_W_ACK)
        return SH_FALSE;

    /* 3. send read address */
    if (EECfg->AddrBytes == 2)
    {
        TWI_SendData(TWIx, (uint8_t)(ReadAddr >> 8));
        event = TWI_SendWaitDone(TWIx);
        if (event != TWI_MASTER_DATA_SEND_ACK)
            return SH_FALSE;
    }
    TWI_SendData(TWIx, (uint8_t)(ReadAddr & 0XFF));
    event = TWI_SendWaitDone(TWIx);
    if (event != TWI_MASTER_DATA_SEND_ACK)
        return SH_FALSE;

    /* 4. Send RESTART condition */
    event = TWI_SendCommand(TWIx, TWI_CMD_START);
    if (event != TWI_MASTER_START_SEND && event != TWI_MASTER_RESTART_SEND)
        return SH_FALSE;

    /* 5. Send Hardware address */
    TWI_Send7bitAddress(TWIx, EECfg->EEHWAddr, TWI_DIR_RECEIVER);
    event = TWI_SendWaitDone(TWIx);
    if (event != TWI_MASTER_SLA_R_ACK)
        return SH_FALSE;

    /* 6. Response ACK */
    event = TWI_SendCommand(TWIx, TWI_CMD_ACK);

    /* 7. Read data and response ACK or NACK */
    while (event == TWI_MASTER_DATA_RECEIVE_ACK && ReadBytes > 0)
    {
        *ReadBuffer = TWIx->DR;
        ReadBuffer++;
        ReadBytes--;
        if (ReadBytes > 0)
            event = TWI_SendCommand(TWIx, TWI_CMD_ACK);
        else
            event = TWI_SendCommand(TWIx, TWI_CMD_NACK);
    }

    /* 8. Send STOP condition */
    TWI_STOP(TWIx, SH_ENABLE);
    /* clear Interrupt Flag to start transmit,  */
    TWIx->FR.V32 = (TWI_FR_TOUTC_Msk | TWI_FR_TFREEC_Msk | TWI_FR_TWINTC_Msk);

    return (ReadBytes == 0 ? SH_TRUE : SH_FALSE);
}

/** @brief  Write EEPROM data from buffer
  * @param  TWIx  TWI device: TWI0  TWI1
  * @param  EECfg: EEPROM TWI parameters
  * @param  WriteAddr: data address for write
  * @param  WriteBuffer: buffer for write data
  * @param  WriteBytes: bytes count need write
  * @retval bool_t SH_TRUE for write success and SH_FALSE for write fail
  */
bool_t TWI_EEWriteBuffer(TWI_TypeDef *TWIx, const TWI_EETypeDef *EECfg, uint16_t WriteAddr, uint8_t *WriteBuffer, uint16_t WriteBytes)
{
    __IO uint8_t event;
    uint16_t addr = WriteAddr;
    int8_t oneWriteBytes;
    int i;
    assert_param(IS_TWI_MODULE(TWIx));

    while (WriteBytes > 0)
    {
        oneWriteBytes = EECfg->WritePageBytes - (addr % EECfg->WritePageBytes);
        if (oneWriteBytes > WriteBytes)
            oneWriteBytes = WriteBytes;

        /* 1. Send START condition */
        event = TWI_SendCommand(TWIx, TWI_CMD_START);
        if (event != TWI_MASTER_START_SEND && event != TWI_MASTER_RESTART_SEND)
            break;

        /* 2. Send Hardware address */
        TWI_Send7bitAddress(TWIx, EECfg->EEHWAddr, TWI_DIR_TRANSMITTER);
        event = TWI_SendWaitDone(TWIx);
        if (event != TWI_MASTER_SLA_W_ACK)
            break;

        /* 3. send read address */
        if (EECfg->AddrBytes == 2)
        {
            TWI_SendData(TWIx, (uint8_t)(addr >> 8));
            event = TWI_SendWaitDone(TWIx);
            if (event != TWI_MASTER_DATA_SEND_ACK)
                break;
        }

        TWI_SendData(TWIx, (uint8_t)(addr & 0XFF));
        event = TWI_SendWaitDone(TWIx);
        if (event != TWI_MASTER_DATA_SEND_ACK)
            break;

        for (i = 0; i < oneWriteBytes; i++)
        {
            /* 4. send data to write */
            TWI_SendData(TWIx, *WriteBuffer);
            WriteBuffer++;
            event = TWI_SendWaitDone(TWIx);
            if (event != TWI_MASTER_DATA_SEND_ACK)
                return SH_FALSE;
        }

        /* 5. Send STOP condition */
        TWI_STOP(TWIx, SH_ENABLE);
        /* clear Interrupt Flag to start transmit,  */
        TWIx->FR.V32 = (TWI_FR_TOUTC_Msk | TWI_FR_TFREEC_Msk | TWI_FR_TWINTC_Msk); 

        /* 6. Restart condition to wait EEPROM write done. No response if EEPROM is busy */
        do
        {
            event = TWI_SendCommand(TWIx, TWI_CMD_START);
            if (event != TWI_MASTER_START_SEND && event != TWI_MASTER_RESTART_SEND)
                continue;

            TWI_Send7bitAddress(TWIx, EECfg->EEHWAddr, TWI_DIR_TRANSMITTER);
            event = TWI_SendWaitDone(TWIx);
        } while (event != TWI_MASTER_SLA_W_ACK);

        /* 7. Send STOP condition */
        TWI_STOP(TWIx, SH_ENABLE);
        /* clear Interrupt Flag to start transmit,  */
        TWIx->FR.V32 = (TWI_FR_TOUTC_Msk | TWI_FR_TFREEC_Msk | TWI_FR_TWINTC_Msk);

        addr += oneWriteBytes;
        WriteBytes -= oneWriteBytes;
        oneWriteBytes = EECfg->WritePageBytes;
        if (WriteBytes < oneWriteBytes)
            oneWriteBytes = WriteBytes;
    }

    return (WriteBytes == 0 ? SH_TRUE : SH_FALSE);
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
