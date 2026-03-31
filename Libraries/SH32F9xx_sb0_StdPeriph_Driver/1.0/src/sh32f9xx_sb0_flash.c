/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_flash.c
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-08-26  
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the FLASH peripheral:
  *            - FLASH Interface configuration
  *            - FLASH Memory Programming
  *
  *  @verbatim
  *
  *          ===================================================================
  *                                 How to use this driver
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
  * <h2><center>&copy; COPYRIGHT 2017 Sinowealth</center></h2>
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_flash.h"

/** @addtogroup SH32F90xx_SB0_StdLib_Driver
  * @{
  */

/** @defgroup FLASH_MODULE FLASH 
  * @brief FLASH driver modules
  * @{
  */

/** @defgroup FLASH_Public_Functions Public Functions
  * @{
  */

/** @defgroup FLASH_Group1 FLASH Interface configuration functions
  *  @brief   FLASH Interface configuration functions 
  *
  *  @verbatim   
  ===============================================================================
  FLASH Interface configuration functions
  ===============================================================================
  
    This group includes the following functions:
    - void FLASH_SetLatency(uint32_t FLASH_Latency)
    - void FLASH_PrefetchBufferOnOff(CmdState NewState)
    - void FLASH_InstructionCacheOnOff(CmdState NewState)
    - void FLASH_DataCacheOnOff(CmdState NewState)
    - void FLASH_InstructionCacheReset(void)
    - void FLASH_DataCacheReset(void)
  
    The unlock sequence is not needed for these functions.

   @endverbatim
  * @{
*/

/**
* @brief  Sets the code latency value.
* @param  FLASH_Latency: specifies the FLASH Latency value.
*         This parameter can be one of the following values:
*            @arg FLASH_Latency_0: FLASH Zero Latency cycle
*            @arg FLASH_Latency_1: FLASH One Latency cycle
*            @arg FLASH_Latency_2: FLASH Two Latency cycles
*            @arg FLASH_Latency_3: FLASH Three Latency cycles
*            @arg FLASH_Latency_4: FLASH Four Latency cycles 
*            @arg FLASH_Latency_5: FLASH Five Latency cycles 
*            @arg FLASH_Latency_6: FLASH Six Latency cycles
*            @arg FLASH_Latency_7: FLASH Seven Latency cycles      
* @retval None
*/
void FLASH_SetLatency(uint32_t FLASH_Latency)
{
    uint32_t tmpreg = 0;

    /* Check the parameters */
    assert_param(IS_FLASH_LATENCY(FLASH_Latency));

    /* Clear FLASH_Latency */
    tmpreg = FLASH->ACR.V32 & (~FLASH_ACR_LATENCY_Msk);
    /* Set the Latency cycles according to the new value */
    tmpreg |= ((0x5AA5 << FLASH_ACR_LOCK_Pos) | (FLASH_Latency << FLASH_ACR_LATENCY_Pos));
    /* Store the new value */
    FLASH->ACR.V32 = tmpreg;
}

/**
  * @brief  Enables or disables the Instruction Cache feature.
  * @param  NewState: new state of the Instruction Cache.
  *          This parameter can be: SH_ON or SH_OFF.
  * @retval None
  */
void FLASH_InstructionCacheOnOff(CmdState NewState)
{
    uint32_t tmpreg = 0;

    /* Check the parameters */
    assert_param(IS_CMD_STATE(NewState));

    /* Clear ICEN bit */
    tmpreg = FLASH->ACR.V32 & (~FLASH_ACR_ICEN_Msk);
    /* Set ICEN bit according to the New State value */
    tmpreg |= ((0x5AA5 << FLASH_ACR_LOCK_Pos) | (NewState << FLASH_ACR_ICEN_Pos));
    /* Store the new value */
    FLASH->ACR.V32 = tmpreg;
}

/**
  * @brief  Enables or disables the Data Cache feature.
  * @note   None
  * @param  NewState: new state of the Data Cache.
  *          This parameter can be: SH_ON or SH_OFF.
  * @retval None
  */
void FLASH_DataCacheOnOff(CmdState NewState)
{
    uint32_t tmpreg = 0;

    /* Check the parameters */
    assert_param(IS_CMD_STATE(NewState));

    /* Clear DCEN bit */
    tmpreg = FLASH->ACR.V32 & (~FLASH_ACR_DCEN_Msk);
    /* Set DCEN bit according to the New State value */
    tmpreg |= ((0x5AA5 << FLASH_ACR_LOCK_Pos) | (NewState << FLASH_ACR_DCEN_Pos));
    /* Store the new value */
    FLASH->ACR.V32 = tmpreg;
}

/**
  * @brief  Enables or disables the Prefetch feature.
  * @note   None
  * @param  NewState: new state of the Prefetch.
  *          This parameter can be: SH_ON or SH_OFF.
  * @retval None
  */
void FLASH_PrefetchOnOff(CmdState NewState)
{
    uint32_t tmpreg = 0;

    /* Check the parameters */
    assert_param(IS_CMD_STATE(NewState));

    /* Clear PRFTEN bit */
    tmpreg = FLASH->ACR.V32 & (~FLASH_ACR_PRFTEN_Msk);
    /* Set PRFTEN bit according to the New State value */
    tmpreg |= ((0x5AA5 << FLASH_ACR_LOCK_Pos) | (NewState << FLASH_ACR_PRFTEN_Pos));
    /* Store the new value */
    FLASH->ACR.V32 = tmpreg;
}

/**
  * @brief  Resets the Instruction Cache and the Data Cache.
  * @retval None
  */
void FLASH_CacheReset(void)
{
    uint32_t tmpreg = FLASH->ACR.V32;
    /* Set CRST bit to Reset Cache  */
    FLASH->ACR.V32 |= ((0x5AA5 << FLASH_ACR_LOCK_Pos) | (SH_SET << FLASH_ACR_CRST_Pos));
    FLASH->ACR.V32 = (tmpreg | (0x5AA5 << FLASH_ACR_LOCK_Pos));
}

/**
  * @}
  */

/** @defgroup FLASH_Group2 FLASH Memory Programming Settings
*  @brief   FLASH Memory Programming functions
*
 *  @verbatim   
===============================================================================
FLASH Memory Programming functions
===============================================================================   

  This group includes the following functions:
  - void FLASH_Set_PGMWindow(uint32_t CounterInitValue, uint32_t UpperCounterValue)
  - void FLASH_Clear_PGMWindow(void)  
  - uint32_t FLASH_Calcualte_WinCounterVal(uint32_t usDelay)
  - void FLASH_Main_Unlock(uint8_t OperationType)
  - void FLASH_Main_Lock(void)
  - void FLASH_E2_Unlock(uint8_t OperationType)
  - void FLASH_E2_Lock(void)
  - void FLASH_Info_Unlock(uint8_t OperationType)
  - void FLASH_Info_Lock(void)

  Any operation of erase or program should follow these steps (Main block for example):
  1. Call the FLASH_Main_Unlock(uint8_t OperationType) function to enable the FLASH control register access
  
  2. Call the desired function to erase sector(s) or program data

  3. Call the FLASH_Main_Lock() function to disable the FLASH control register access
     (recommended to protect the FLASH memory against possible unwanted operation)
  
 *  @endverbatim
 * @{
 */

/**
  * @brief  Sets the programming window timer values.
  * @param  CounterInitValue: specifies the watchdog counter initial value.
  * @param  UpperCounterValue: specifies the upper limit value.
  * @retval None
  */
void FLASH_Set_PGMWindow(uint32_t CounterInitValue, uint32_t UpperCounterValue)
{
    /* Sets the initial value of counter */
    FLASH->CNTR = CounterInitValue;

    /* Sets the upper limit value of counter */
    FLASH->UPCNTR = UpperCounterValue;

    /* Enable the downcounter */
    FLASH_CNTCR_CNTEN_BIT = SH_SET;
}

/**
  * @brief  Clears the programming window timer values.
  */
void FLASH_Clear_PGMWindow(void)
{
    /* Clears the window counters */
    FLASH->CNTR = 0x0;
    FLASH->UPCNTR = 0x0;
    FLASH_CNTCR_CNTEN_BIT = SH_RESET;
}

/**
  * @brief  Calculates the programming window counter value according the window time.
  * @param  us100Delay: the time of programming window.
  * @retval CounterValue: The counter value of the window time
  */
uint32_t FLASH_Calculate_WinCounterVal(uint32_t us100Delay)
{
    uint32_t CounterValue = 0;
    RCC_Clocks_TypeDef curClk;

    /* Get current system's clock frequency */
    RCC_GetClocksFreq(&curClk);

    /* Calculates the window counter value according the window time */
    CounterValue = curClk.sysFreq / 10000 * us100Delay;

    return CounterValue;
}

/**
  * @brief Locks the FLASH control register access of main block.
  */
void FLASH_Main_Lock(void)
{
    /* Set the LOCK Bit to lock the FLASH Registers access */
    FLASH_CR_MNLCK_BIT = SH_SET;
}

/**
  * @brief  Unlocks the FLASH control register access of main block.
  * @param  OperationType: The single operation unlock or the multiple operations unlock
  *            @arg SINGLE_OPERATION: The single operation unlock
  *            @arg MULTI_OPERATION: The multiple operations unlock
  */
void FLASH_Main_Unlock(uint8_t OperationType)
{
    if (FLASH_CR_E2LCK_BIT == SH_RESET)
    {
        FLASH_CR_E2LCK_BIT = SH_SET;
    }
    if (FLASH_CR_INFLCK_BIT == SH_RESET)
    {
        FLASH_CR_INFLCK_BIT = SH_SET;
    }
    if (FLASH_CR_MNLCK_BIT != SH_RESET)
    {
        /* Authorize the FLASH Registers access */
        FLASH->MKYR = FLASH_MAIN_KEY;

        /* The single unlock key unlocks the flash interface for one write or erase operation. */
        if (OperationType == SINGLE_OPERATION)
            FLASH->MKYR = FLASH_SINGLE_OP_KEY;

        /* The multiple unlock key unlocks the flash interface for write or erase operations until the block is locked. */
        else if (OperationType == MULTI_OPERATION)
            FLASH->MKYR = FLASH_MULTI_OP_KEY;
    }
}

/**
* @brief  Locks the EEPRom block control register access.
*/
void FLASH_E2_Lock(void)
{
    /* Set the E2LCK Bit to lock the EEPRom block control Registers access */
    FLASH_CR_E2LCK_BIT = SH_SET;
}

/**
* @brief  Unlocks the EEPRom block control register access.
* @param  OperationType: The single operation unlock or the multiple operations unlock
*            @arg SINGLE_OPERATION: The single operation unlock
*            @arg MULTI_OPERATION: The multiple operations unlock
*/
void FLASH_E2_Unlock(uint8_t OperationType)
{
    if (FLASH_CR_MNLCK_BIT == SH_RESET)
    {
        FLASH_CR_MNLCK_BIT = SH_SET;
    }
    if (FLASH_CR_INFLCK_BIT == SH_RESET)
    {
        FLASH_CR_INFLCK_BIT = SH_SET;
    }

    if (FLASH_CR_E2LCK_BIT != SH_RESET)
    {
        /* Authorize the FLASH Registers access */
        FLASH->E2KYR = FLASH_E2_KEY;

        /* The single unlock key unlocks the flash interface for one write or erase operation. */
        if (OperationType == SINGLE_OPERATION)
            FLASH->E2KYR = FLASH_SINGLE_OP_KEY;

        /* The multiple unlock key unlocks the flash interface for write or erase operations until the block is locked. */
        else if (OperationType == MULTI_OPERATION)
            FLASH->E2KYR = FLASH_MULTI_OP_KEY;
    }
}

/**
* @brief  Locks the FLASH Info. block control register access.
*/
void FLASH_Info_Lock(void)
{
    /* Set the INFLCK Bit to lock the FLASH Registers access */
    FLASH_CR_INFLCK_BIT = SH_SET;
}

/**
* @brief  Unlocks the FLASH Info. block control register access.
* @param  OperationType: The single operation unlock or the multiple operations unlock
*            @arg SINGLE_OPERATION: The single operation unlock
*            @arg MULTI_OPERATION: The multiple operations unlock

* @retval None
*/
void FLASH_Info_Unlock(uint8_t OperationType)
{
    if (FLASH_CR_MNLCK_BIT == SH_RESET)
        FLASH_CR_MNLCK_BIT = SH_SET;

    if (FLASH_CR_E2LCK_BIT == SH_RESET)
        FLASH_CR_E2LCK_BIT = SH_SET;

    if (FLASH_CR_INFLCK_BIT != SH_RESET)
    {
        /* Authorize the FLASH Registers access */
        FLASH->IKYR = FLASH_INFO_KEY;

        /* The single unlock key unlocks the flash interface for one write or erase operation. */
        if (OperationType == SINGLE_OPERATION)
            FLASH->IKYR = FLASH_SINGLE_OP_KEY;

        /* The multiple unlock key unlocks the flash interface for write or erase operations until the block is locked. */
        else if (OperationType == MULTI_OPERATION)
            FLASH->IKYR = FLASH_MULTI_OP_KEY;
    }
}

/**
* @brief  Clears the FLASH's pending flags.
* @param  FLASH_FLAG: specifies the FLASH flags to clear.
*          This parameter can be any combination of the following values:
*            @arg FLASH_FLAG_EOP: FLASH End of Operation flag 
*            @arg FLASH_FLAG_OPERR: FLASH operation Error flag 
*            @arg FLASH_FLAG_FLSERR: FLASH hardware Error flag 
*            @arg FLASH_FLAG_WRPERR: FLASH Write protected error flag 
*            @arg FLASH_FLAG_PGPERR: FLASH Programming one time error flag
*            @arg FLASH_FLAG_PGWERR: FLASH Programming Window counter error flag
*            @arg FLASH_FLAG_STAERR: FLASH Programming State error flag
* @retval None
*/
void FLASH_ClearFlag(uint32_t FLASH_FLAG)
{
    /* Check the parameters */
    assert_param(IS_FLASH_CLEAR_FLAG(FLASH_FLAG));

    /* Clear the flags */
    FLASH->SR.V32 |= (FLASH_FLAG << 16);
}

/**
* @brief  Returns the FLASH Status.
* @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
*                       FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
*/
FLASH_Status FLASH_GetStatus(void)
{
    FLASH_Status flashstatus = FLASH_COMPLETE;

    if ((FLASH->SR.V32 & FLASH_FLAG_BSY) == FLASH_FLAG_BSY)
    {
        flashstatus = FLASH_BUSY;
    }
    else
    {
        if ((FLASH->SR.V32 & FLASH_FLAG_WRPERR) != (uint32_t)0x00)
        {
            flashstatus = FLASH_ERROR_WRP;
        }
        else
        {
            if ((FLASH->SR.V32 & FLASH_FLAG_FLSERR) != (uint32_t)0x00)
            {
                flashstatus = FLASH_ERROR_FLS;
            }
            else
            {
                if ((FLASH->SR.V32 & FLASH_FLAG_PGPERR) != (uint32_t)0x00)
                {
                    flashstatus = FLASH_ERROR_PGP;
                }
                else
                {
                    if ((FLASH->SR.V32 & FLASH_FLAG_PGWERR) != (uint32_t)0x00)
                    {
                        flashstatus = FLASH_ERROR_PGW;
                    }
                    else
                    {
                        if ((FLASH->SR.V32 & FLASH_FLAG_STAERR) != (uint32_t)0x00)
                        {
                            flashstatus = FLASH_ERROR_STA;
                        }
                        else
                        {
                            if ((FLASH->SR.V32 & FLASH_FLAG_OPERR) != (uint32_t)0x00)
                            {
                                flashstatus = FLASH_ERROR_OPERATION;
                            }
                            else
                            {
                                flashstatus = FLASH_COMPLETE;
                                FLASH_ClearFlag(FLASH_FLAG_EOP);
                            }
                        }
                    }
                }
            }
        }
    }
    /* Return the FLASH Status */
    return flashstatus;
}

/**
* @brief  Waits for a FLASH operation to complete.
* @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
*                       FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
*/
FLASH_Status FLASH_WaitForLastOperation(void)
{
    __IO FLASH_Status status = FLASH_COMPLETE;

    /* Check for the FLASH Status */
    status = FLASH_GetStatus();

    /* Wait for the FLASH operation to complete by polling on BUSY flag to be reset.
    Even if the FLASH operation fails, the BUSY flag will be reset and an error
    flag will be set */
    while (status == FLASH_BUSY)
    {
        status = FLASH_GetStatus();
    }
    /* Return the operation status */
    return status;
}

/**
  * @}
  */

/** @defgroup FLASH_Group4 FLASH Memory Programming basic functions
*  @brief   FLASH Memory Programming basic functions
*
*  @verbatim   
===============================================================================
FLASH Memory Programming basic functions
===============================================================================   

  This group includes the following functions:
  - FLASH_Status FLASH_EraseSector(uint32_t FLASH_Sector)
  - FLASH_Status FLASH_EraseAllSectors(void)
  - FLASH_Status FLASH_ProgramWord(uint32_t Address, uint32_t Data)
  - FLASH_Status FLASH_ProgramHalfWord(uint32_t Address, uint16_t Data)
  - FLASH_Status FLASH_E2_EraseSector(E2_SECTOR_NUM_Type E2_Sector)
  - FLASH_Status FLASH_E2_ProgramWord(uint32_t Address, uint32_t Data)
  - FLASH_Status FLASH_E2_ProgramHalfWord(uint32_t Address, uint16_t Data)
  - FLASH_Status FLASH_CB_EraseSector(void)
  - FLASH_Status FLASH_CB_ProgramWord(uint32_t Address, uint32_t Data)
  - FLASH_Status FLASH_CB_ProgramHalfWord(uint32_t Address, uint16_t Data)
  - FLASH_Status FLASH_OTP_ProgramWord(uint32_t Address, uint32_t Data)
  - FLASH_Status FLASH_OTP_ProgramHalfWord(uint32_t Address, uint16_t Data)
  - FLASH_Status FLASH_PRTB_ProgramWord(uint32_t Address, uint32_t Data)
  - FLASH_Status FLASH_PRTB_ProgramHalfWord(uint32_t Address, uint16_t Data)
 
@endverbatim
* @{
*/

/**
* @brief  Erases a specified FLASH Sector.
*   
* @param  FLASH_Sector: The Sector number to be erased.
*         This parameter can be a value between 0 and 127
*    
* @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
*                       FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
*/
FLASH_Status FLASH_Main_EraseSector(uint32_t FLASH_Sector)
{
    FLASH_Status status = FLASH_COMPLETE;

    /* Check the parameters */
    assert_param(IS_FLASH_SECTOR(FLASH_Sector));

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation();

    if (status == FLASH_COMPLETE)
    {
        /* Sets the programming window timer values */
        FLASH_Set_PGMWindow(SE_ERS_TIME, SE_ERS_TIME);

        /* if the previous operation is completed, proceed to erase the sector */
        FLASH->CR.V32 = FLASH_Sector | (FLASH_CR_CMD_MSE << FLASH_CR_CMD_Pos) | (SH_SET << FLASH_CR_STRT_Pos);

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation();

        if (status == FLASH_COMPLETE)
        {
            /* if the erase operation is completed, disable the operation command */
            FLASH->CR.V32 = 0;
        }
        /* Clears the programming window timer values */
        FLASH_Clear_PGMWindow();
    }
    /* Cache reset */
    FLASH_CacheReset();
    /* Return the Erase Status */
    return status;
}

/**
* @brief  Erase All Flash Secotrs.
* @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
*                       FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
*/
FLASH_Status FLASH_Main_EraseAllSectors(void)
{
    FLASH_Status status = FLASH_COMPLETE;

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation();

    if (status == FLASH_COMPLETE)
    {
        /* Sets the programming window timer values */
        FLASH_Set_PGMWindow(SE_ERS_TIME, SE_ERS_TIME);

        /* if the previous operation is completed, proceed to erase all sectors */
        FLASH->CR.V32 = (FLASH_CR_CMD_ME0 << FLASH_CR_CMD_Pos) | (SH_SET << FLASH_CR_STRT_Pos);

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation();

        /* if the erase operation is completed, disable the operation command */
        FLASH->CR.V32 = 0;

        /* Clears the programming window timer values */
        FLASH_Clear_PGMWindow();
    }
    /* Cache reset */
    FLASH_CacheReset();
    /* Return the Erase Status */
    return status;
}

/**
* @brief  Programs a word (32-bit) at a specified address of the main block.
* @param  Address: specifies the address to be programmed.
*         This parameter can be any address in Program memory zone.  
 * @param  Data: specifies the data to be programmed.
* @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
*                       FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
*/
FLASH_Status FLASH_Main_ProgramWord(uint32_t Address, uint32_t Data)
{
    FLASH_Status status = FLASH_COMPLETE;

    uint32_t tmpreg = FLASH->ACR.V32;

    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | (tmpreg & FLASH_ACR_LATENCY_Msk));

    /* Check the parameters */
    assert_param(IS_FLASH_MAIN_BLOCK_ADDRESS(Address));

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation();

    if (status == FLASH_COMPLETE)
    {
        /* Sets the programming window timer values */
        FLASH_Set_PGMWindow(SE_ERS_TIME, SE_ERS_TIME);

        /* if the previous operation is completed, proceed to program the new data */
        FLASH->CR.V32 = ((FLASH_CR_PSIZE_WD << FLASH_CR_PSIZE_Pos) \
                        | (FLASH_CR_CMD_MPG << FLASH_CR_CMD_Pos) \
                        | (SH_SET << FLASH_CR_STRT_Pos));

        *(__IO uint32_t *)Address = Data;

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation();

        /* if the program operation is completed, disable the operation command */
        FLASH->CR.V32 = 0;

        /* Clears the programming window timer values */
        FLASH_Clear_PGMWindow();
    }
    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | tmpreg);
    /* Cache reset */
    FLASH_CacheReset();
    /* Return the Program Status */
    return status;
}

/**
* @brief  Programs a half word (16-bit) at a specified address of the main block.           
* @param  Address: specifies the address to be programmed.
*         This parameter can be any address in Program memory zone.  
* @param  Data: specifies the data to be programmed.
* @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
*                       FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
*/
FLASH_Status FLASH_Main_ProgramHalfWord(uint32_t Address, uint16_t Data)
{
    FLASH_Status status = FLASH_COMPLETE;

    uint32_t tmpreg = FLASH->ACR.V32;

    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | (tmpreg & FLASH_ACR_LATENCY_Msk));

    /* Check the parameters */
    assert_param(IS_FLASH_MAIN_BLOCK_ADDRESS(Address));

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation();

    if (status == FLASH_COMPLETE)
    {
        /* Sets the programming window timer values */
        FLASH_Set_PGMWindow(SE_ERS_TIME, SE_ERS_TIME);

        /* if the previous operation is completed, proceed to program the new data */
        FLASH->CR.V32 = ((FLASH_CR_PSIZE_HALFWD << FLASH_CR_PSIZE_Pos) \
                        | (FLASH_CR_CMD_MPG << FLASH_CR_CMD_Pos) \
                        | (SH_SET << FLASH_CR_STRT_Pos));

        *(__IO uint16_t *)Address = Data;

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation();

        /* if the program operation is completed, disable the operation command */
        FLASH->CR.V32 = 0;

        /* Clears the programming window timer values */
        FLASH_Clear_PGMWindow();
    }
    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | tmpreg);
    /* Cache reset */
    FLASH_CacheReset();
    /* Return the Program Status */
    return status;
}

/**
* @brief  Erases a specified EEPROM block Sector.
* @param  E2_Sector: The Sector number to be erased.
*         This parameter can be a value of @ref E2_SECTOR_NUM_Type.
* @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
*                       FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
*/
FLASH_Status FLASH_E2_EraseSector(E2_SECTOR_NUM_Type E2_Sector)
{
    FLASH_Status status = FLASH_COMPLETE;

    /* Check the parameters */
    assert_param(IS_E2_BLOCK_SECTOR(E2_Sector));

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation();

    if (status == FLASH_COMPLETE)
    {
        /* Sets the programming window timer values */
        FLASH_Set_PGMWindow(SE_ERS_TIME, SE_ERS_TIME);

        /* if the previous operation is completed, proceed to erase the sector */
        FLASH->CR.V32 = (E2_Sector | (FLASH_CR_CMD_E2SE << FLASH_CR_CMD_Pos) | (SH_SET << FLASH_CR_STRT_Pos));

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation();

        /* if the erase operation is completed, disable the operation command */
        FLASH->CR.V32 = 0;

        /* Clears the programming window timer values */
        FLASH_Clear_PGMWindow();
    }
    /* Cache reset */
    FLASH_CacheReset();
    /* Return the Erase Status */
    return status;
}

/**
* @brief  Programs a word (32-bit) at a specified address of the EEPROM block.
* @param  Address: specifies the address to be programmed.
*         This parameter can be any address in Program memory zone.  
* @param  Data: specifies the data to be programmed.
* @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
*                       FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
*/
FLASH_Status FLASH_E2_ProgramWord(uint32_t Address, uint32_t Data)
{
    FLASH_Status status = FLASH_COMPLETE;

    uint32_t tmpreg = FLASH->ACR.V32;

    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | (tmpreg & FLASH_ACR_LATENCY_Msk));

    /* Check the parameters */
    assert_param(IS_E2_BLOCK_ADDRESS(Address));

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation();

    if (status == FLASH_COMPLETE)
    {
        /* Sets the programming window timer values */
        FLASH_Set_PGMWindow(SE_ERS_TIME, SE_ERS_TIME);

        /* if the previous operation is completed, proceed to program the new data */
        FLASH->CR.V32 = ((FLASH_CR_PSIZE_WD << FLASH_CR_PSIZE_Pos) \
                        | (FLASH_CR_CMD_E2PG << FLASH_CR_CMD_Pos) \
                        | (SH_SET << FLASH_CR_STRT_Pos));

        *(__IO uint32_t *)Address = Data;

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation();

        /* if the program operation is completed, disable the operation command */
        FLASH->CR.V32 = 0;

        /* Clears the programming window timer values */
        FLASH_Clear_PGMWindow();
    }
    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | tmpreg);
    /* Cache reset */
    FLASH_CacheReset();
    /* Return the Program Status */
    return status;
}

/**
* @brief  Programs a half word (16-bit) at a specified address of the EEPROM block.           
* @param  Address: specifies the address to be programmed.
*         This parameter can be any address in Program memory zone.  
* @param  Data: specifies the data to be programmed.
* @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
*                       FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
*/
FLASH_Status FLASH_E2_ProgramHalfWord(uint32_t Address, uint16_t Data)
{
    FLASH_Status status = FLASH_COMPLETE;

    uint32_t tmpreg = FLASH->ACR.V32;

    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | (tmpreg & FLASH_ACR_LATENCY_Msk));

    /* Check the parameters */
    assert_param(IS_E2_BLOCK_ADDRESS(Address));

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation();

    if (status == FLASH_COMPLETE)
    {
        /* Sets the programming window timer values */
        FLASH_Set_PGMWindow(SE_ERS_TIME, SE_ERS_TIME);

        /* if the previous operation is completed, proceed to program the new data */
        FLASH->CR.V32 = ((FLASH_CR_PSIZE_HALFWD << FLASH_CR_PSIZE_Pos) \
                        | (FLASH_CR_CMD_E2PG << FLASH_CR_CMD_Pos) \
                        | (SH_SET << FLASH_CR_STRT_Pos));

        *(__IO uint16_t *)Address = Data;

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation();

        /* if the program operation is completed, disable the operation command */
        FLASH->CR.V32 = 0;

        /* Clears the programming window timer values */
        FLASH_Clear_PGMWindow();
    }
    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | tmpreg);
    /* Cache reset */
    FLASH_CacheReset();
    /* Return the Program Status */
    return status;
}

/**
* @brief  Erases the Sector of Customer block.
* @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
*                       FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
*/

FLASH_Status FLASH_CB_EraseSector(void)
{
    FLASH_Status status = FLASH_COMPLETE;

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation();

    if (status == FLASH_COMPLETE)
    {
        /* Sets the programming window timer values */
        FLASH_Set_PGMWindow(SE_ERS_TIME, SE_ERS_TIME);

        /* if the previous operation is completed, proceed to erase the sector */
        FLASH->CR.V32 = ((FLASH_CR_CMD_CBSE << FLASH_CR_CMD_Pos) | (SH_SET << FLASH_CR_STRT_Pos));

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation();

        /* if the erase operation is completed, disable the operation command */
        FLASH->CR.V32 = 0;

        /* Clears the programming window timer values */
        FLASH_Clear_PGMWindow();
    }
    /* Cache reset */
    FLASH_CacheReset();
    /* Return the Erase Status */
    return status;
}

/**
* @brief  Programs a word (32-bit) at a specified address of the Customer block.
* @param  Address: specifies the address to be programmed.
*         This parameter can be any address in Program memory zone.  
* @param  Data: specifies the data to be programmed.
* @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
*                       FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
*/

FLASH_Status FLASH_CB_ProgramWord(uint32_t Address, uint32_t Data)
{
    FLASH_Status status = FLASH_COMPLETE;

    uint32_t tmpreg = FLASH->ACR.V32;

    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | (tmpreg & FLASH_ACR_LATENCY_Msk));

    /* Check the parameters */
    assert_param(IS_CUSTOMER_BLOCK_ADDRESS(Address));

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation();

    if (status == FLASH_COMPLETE)
    {
        /* Sets the programming window timer values */
        FLASH_Set_PGMWindow(SE_ERS_TIME, SE_ERS_TIME);

        /* if the previous operation is completed, proceed to program the new data */
        FLASH->CR.V32 = ((FLASH_CR_PSIZE_WD << FLASH_CR_PSIZE_Pos) \
                        | (FLASH_CR_CMD_CBPG << FLASH_CR_CMD_Pos) \
                        | (SH_SET << FLASH_CR_STRT_Pos));

        *(__IO uint32_t *)Address = Data;

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation();

        /* if the program operation is completed, disable the operation command  */
        FLASH->CR.V32 = 0;

        /* Clears the programming window timer values */
        FLASH_Clear_PGMWindow();
    }
    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | tmpreg);
    /* Cache reset */
    FLASH_CacheReset();
    /* Return the Program Status */
    return status;
}

/**
* @brief  Programs a half word (16-bit) at a specified address of the Customer block.              
* @param  Address: specifies the address to be programmed.
*         This parameter can be any address in Program memory zone.  
* @param  Data: specifies the data to be programmed.
* @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
*                       FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
*/

FLASH_Status FLASH_CB_ProgramHalfWord(uint32_t Address, uint16_t Data)
{
    FLASH_Status status = FLASH_COMPLETE;

    uint32_t tmpreg = FLASH->ACR.V32;

    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | (tmpreg & FLASH_ACR_LATENCY_Msk));

    /* Check the parameters */
    assert_param(IS_CUSTOMER_BLOCK_ADDRESS(Address));

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation();

    if (status == FLASH_COMPLETE)
    {
        /* Sets the programming window timer values */
        FLASH_Set_PGMWindow(SE_ERS_TIME, SE_ERS_TIME);

        /* if the previous operation is completed, proceed to program the new data */
        FLASH->CR.V32 = ((FLASH_CR_PSIZE_HALFWD << FLASH_CR_PSIZE_Pos) \
                        | (FLASH_CR_CMD_CBPG << FLASH_CR_CMD_Pos) \
                        | (SH_SET << FLASH_CR_STRT_Pos));

        *(__IO uint16_t *)Address = Data;

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation();

        /* if the program operation is completed, disable the operation command */
        FLASH->CR.V32 = 0;

        /* Clears the programming window timer values */
        FLASH_Clear_PGMWindow();
    }
    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | tmpreg);
    /* Cache reset */
    FLASH_CacheReset();
    /* Return the Program Status */
    return status;
}

/**
* @brief  Programs a word (32-bit) at a specified address of the OTP block.
* @param  Address: specifies the address to be programmed.
*         This parameter can be any address in Program memory zone.  
* @param  Data: specifies the data to be programmed.
* @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
*                       FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
*/
FLASH_Status FLASH_OTP_ProgramWord(uint32_t Address, uint32_t Data)
{
    FLASH_Status status = FLASH_COMPLETE;

    uint32_t tmpreg = FLASH->ACR.V32;

    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | (tmpreg & FLASH_ACR_LATENCY_Msk));

    /* Check the parameters */
    assert_param(IS_OTP_BLOCK_ADDRESS(Address));

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation();

    if (status == FLASH_COMPLETE)
    {
        /* Sets the programming window timer values */
        FLASH_Set_PGMWindow(SE_ERS_TIME, SE_ERS_TIME);

        /* if the previous operation is completed, proceed to program the new data */
        FLASH->CR.V32 = ((FLASH_CR_PSIZE_WD << FLASH_CR_PSIZE_Pos) \
                        | (FLASH_CR_CMD_OPG << FLASH_CR_CMD_Pos) \
                        | (SH_SET << FLASH_CR_STRT_Pos));

        *(__IO uint32_t *)Address = Data;

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation();

        /* if the program operation is completed, disable the operation command */
        FLASH->CR.V32 = 0;

        /* Clears the programming window timer values */
        FLASH_Clear_PGMWindow();
    }
    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | tmpreg);
    /* Cache reset */
    FLASH_CacheReset();
    /* Return the Program Status */
    return status;
}

/**
* @brief  Programs a half word (16-bit) at a specified address of the OTP block(0x0FFFF800 - 0x0FFFFFFF).             
* @param  Address: specifies the address to be programmed.
*         This parameter can be any address in Program memory zone.  
* @param  Data: specifies the data to be programmed.
* @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
*                       FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
*/
FLASH_Status FLASH_OTP_ProgramHalfWord(uint32_t Address, uint16_t Data)
{
    FLASH_Status status = FLASH_COMPLETE;

    uint32_t tmpreg = FLASH->ACR.V32;

    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | (tmpreg & FLASH_ACR_LATENCY_Msk));

    /* Check the parameters */
    assert_param(IS_OTP_BLOCK_ADDRESS(Address));

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation();

    if (status == FLASH_COMPLETE)
    {
        /* Sets the programming window timer values */
        FLASH_Set_PGMWindow(SE_ERS_TIME, SE_ERS_TIME);

        /* if the previous operation is completed, proceed to program the new data */
        FLASH->CR.V32 = ((FLASH_CR_PSIZE_HALFWD << FLASH_CR_PSIZE_Pos) \
                        | (FLASH_CR_CMD_OPG << FLASH_CR_CMD_Pos) \
                        | (SH_SET << FLASH_CR_STRT_Pos));

        *(__IO uint16_t *)Address = Data;

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation();

        /* if the program operation is completed, disable the operation command */
        FLASH->CR.V32 = 0;

        /* Clears the programming window timer values */
        FLASH_Clear_PGMWindow();
    }
    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | tmpreg);
    /* Cache reset */
    FLASH_CacheReset();
    /* Return the Program Status */
    return status;
}

/**
* @brief  Programs a word (32-bit) at a specified address of the Protect block.
* @param  Address: specifies the address to be programmed.
*         This parameter can be any address in Program memory zone.  
* @param  Data: specifies the data to be programmed.
* @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
*                        FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
*/
FLASH_Status FLASH_PRTB_ProgramWord(uint32_t Address, uint32_t Data)
{
    FLASH_Status status = FLASH_COMPLETE;

    uint32_t tmpreg = FLASH->ACR.V32;

    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | (tmpreg & FLASH_ACR_LATENCY_Msk));

    /* Check the parameters */
    assert_param(IS_PROTECT_BLOCK_ADDRESS(Address));

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation();

    if (status == FLASH_COMPLETE)
    {
        /* Sets the programming window timer values */
        FLASH_Set_PGMWindow(SE_ERS_TIME, SE_ERS_TIME);

        /* if the previous operation is completed, proceed to program the new data */
        FLASH->CR.V32 = ((FLASH_CR_PSIZE_WD << FLASH_CR_PSIZE_Pos) \
                        | (FLASH_CR_CMD_SPG << FLASH_CR_CMD_Pos) \
                        | (SH_SET << FLASH_CR_STRT_Pos));

        *(__IO uint32_t *)Address = Data;

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation();

        /* if the program operation is completed, disable the operation command */
        FLASH->CR.V32 = 0;

        /* Clears the programming window timer values */
        FLASH_Clear_PGMWindow();
    }
    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | tmpreg);
    /* Cache reset */
    FLASH_CacheReset();
    /* Return the Program Status */
    return status;
}

/**
* @brief  Programs a half word (16-bit) at a specified address of the Protect block. 
* @param  Address: specifies the address to be programmed.
*         This parameter can be any address in Program memory zone.  
* @param  Data: specifies the data to be programmed.
* @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
*                       FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
*/

FLASH_Status FLASH_PRTB_ProgramHalfWord(uint32_t Address, uint16_t Data)
{
    FLASH_Status status = FLASH_COMPLETE;

    uint32_t tmpreg = FLASH->ACR.V32;

    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | (tmpreg & FLASH_ACR_LATENCY_Msk));

    /* Check the parameters */
    assert_param(IS_PROTECT_BLOCK_ADDRESS(Address));

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation();

    if (status == FLASH_COMPLETE)
    {
        /* Sets the programming window timer values */
        FLASH_Set_PGMWindow(SE_ERS_TIME, SE_ERS_TIME);

        /* if the previous operation is completed, proceed to program the new data */
        FLASH->CR.V32 = ((FLASH_CR_PSIZE_HALFWD << FLASH_CR_PSIZE_Pos) \
                        | (FLASH_CR_CMD_SPG << FLASH_CR_CMD_Pos) \
                        | (SH_SET << FLASH_CR_STRT_Pos));

        *(__IO uint16_t *)Address = Data;

        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation();

        /* if the program operation is completed, disable the operation command */
        FLASH->CR.V32 = 0;

        /* Clears the programming window timer values */
        FLASH_Clear_PGMWindow();
    }
    FLASH->ACR.V32 = ((0x5AA5 << FLASH_ACR_LOCK_Pos) | tmpreg);
    /* Cache reset */
    FLASH_CacheReset();
    /* Return the Program Status */
    return status;
}
/**
  * @}
  */

/**
  * @brief  Verify a page at a specified address of Flash. 
  * @param  StartAddr: The start Address                       
  * @note     Must be aligned to a BYTE(1 bytes) for each opertation. 
  * @param  Length: the length of verify operation
  * @note  
  * @param  Buf: the sourse data of programming operation
  * @retval FLASH Status: The returned value can be: FLASH_ERROR_VERIFY or FLASH_COMPLETE.
  */
FLASH_Status FLASH_Verify_Byte(uint32_t StartAddr, uint32_t Length, uint8_t *Buf)
{
    FLASH_Status status = FLASH_COMPLETE;
    uint32_t tmp_len = 0;
    uint32_t tmp_addr = 0;

    /* Check the parameters */
    assert_param(IS_LENGTH_OK(Length));

    tmp_addr = StartAddr;
    while (tmp_len < Length)
    {
        if (*(__IO uint8_t *)tmp_addr != *((uint8_t *)(Buf + tmp_len)))
        {
            status = FLASH_ERROR_VERIFY;
            return status;
        }
        tmp_addr++;
        tmp_len++;
    }

    return status;
}

/**
  * @brief  Verify a page at a specified address of Flash. 
  * @param  StartAddr: The start Address                       
  * @note   Must be aligned to a HALFWORD(2 bytes) for each opertation. 
  * @param  Length: the length of verify operation
  * @note   Must be divisible by 2.  
  * @param  Buf: the sourse data of programming operation
  * @retval FLASH Status: The returned value can be: FLASH_ERROR_VERIFY or FLASH_COMPLETE.
  */
FLASH_Status FLASH_Verify_HalfWord(uint32_t StartAddr, uint32_t Length, uint8_t *Buf)
{
    FLASH_Status status = FLASH_COMPLETE;
    uint32_t tmp_len = 0;
    uint32_t tmp_addr = 0;

    /* Check the parameters */
    assert_param(IS_LENGTH_OK(Length));

    tmp_addr = StartAddr;
    while (tmp_len < Length)
    {
        if (*(__IO uint16_t *)tmp_addr != *((uint16_t *)(Buf + tmp_len)))
        {
            status = FLASH_ERROR_VERIFY;
            return status;
        }
        tmp_addr += 2;
        tmp_len += 2;
    }

    return status;
}

/**
  * @brief  Verify a page at a specified address of Flash. 
  * @param  StartAddr: The start Address                       
  * @note   Must be aligned to a WORD(4 bytes) for each opertation. 
  * @param  Length: the length of verify operation
  * @note   Must be divisible by 4. 
  * @param  Buf: the sourse data of programming operation
  * @retval FLASH Status: The returned value can be: FLASH_ERROR_VERIFY or FLASH_COMPLETE.
  */
FLASH_Status FLASH_VerifyPage(uint32_t StartAddr, uint32_t Length, uint8_t *Buf)
{
    FLASH_Status status = FLASH_COMPLETE;
    uint32_t tmp_len = 0;
    uint32_t tmp_addr = 0;

    /* Check the parameters */
    assert_param(IS_LENGTH_OK(Length));

    tmp_addr = StartAddr;
    while (tmp_len < Length)
    {
        if (*(__IO uint32_t *)tmp_addr != *((uint32_t *)(Buf + tmp_len)))
        {
            status = FLASH_ERROR_VERIFY;
            return status;
        }
        tmp_addr += 4;
        tmp_len += 4;
    }

    return status;
}

/**
  * @brief  Programs a page at a specified address of the main block. 
  * @param  StartAddr: The start Address                       
  * @note   Must be aligned to a WORD(4 bytes) for each programming. 
  * @param  Length: the length of programming operation
  * @note   Must be divisible by 4. 
  * @param  Buf: the sourse data of programming operation
  * @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
  *         FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
  */
FLASH_Status FLASH_Main_ProgramPage(uint32_t StartAddr, uint32_t Length, uint8_t *Buf)
{
    FLASH_Status status = FLASH_COMPLETE;
    uint32_t tmp_len = 0;
    uint32_t tmp_addr = 0;

    /* Check the parameters */
    assert_param(IS_LENGTH_OK(Length));

    /* Clear pending flags (if any) */
    FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                    FLASH_FLAG_STAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGWERR | FLASH_FLAG_FLSERR);

    tmp_addr = StartAddr;
    while (tmp_len < Length)
    {
        /* Programming a Word to the special address */
        status = FLASH_Main_ProgramWord(tmp_addr, *((uint32_t *)(Buf + tmp_len)));
        if (status == FLASH_COMPLETE)
        {
            tmp_addr += 4;
            tmp_len += 4;
        }
        else
        {
            break;
        }
    }

    if (status == FLASH_COMPLETE)
    {
        /* Verify the page */
        status = FLASH_Verify_Byte(StartAddr, Length, Buf);
    }

    return status;
}

/**
  * @brief  Programs a page at a specified address of the EEPRom block. 
  * @param  StartAddr: The start Address                       
  * @note   Must be aligned to a WORD(4 bytes) for each programming. 
  * @param  Length: the length of programming operation
  * @note   Must be divisible by 4. 
  * @param  Buf: the sourse data of programming operation
  * @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
  *         FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
  */
FLASH_Status FLASH_E2_ProgramPage(E2_SECTOR_NUM_Type E2Sector, uint32_t StartAddr, uint32_t Length, uint8_t *Buf)
{
    FLASH_Status status = FLASH_COMPLETE;
    uint32_t tmp_len = 0;
    uint32_t tmp_addr = 0;

    /* Check the parameters */
    assert_param(IS_LENGTH_OK(Length));

    /* Clear pending flags (if any) */
    FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                    FLASH_FLAG_STAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGWERR | FLASH_FLAG_FLSERR);

    tmp_addr = E2_BLOCK_ADDRESS + E2Sector * 1024 + StartAddr;
    while (tmp_len < Length)
    {
        /* Programming a Word to the special address */
        status = FLASH_E2_ProgramWord(tmp_addr, *((uint32_t *)(Buf + tmp_len)));
        if (status == FLASH_COMPLETE)
        {
            tmp_addr += 4;
            tmp_len += 4;
        }
        else
        {
            break;
        }
    }

    tmp_addr = E2_BLOCK_ADDRESS + E2Sector * 1024 + StartAddr;

    if (status == FLASH_COMPLETE)
    {
        /* Verify the page */
        status = FLASH_Verify_Byte(tmp_addr, Length, Buf);
    }

    return status;
}

/**
  * @brief  Reading EEPROM data. 
  * @param  e2psector: The Sector number to be read.
  *         This parameter can be a value of @ref E2_SECTOR_NUM_Type.
  * @param  StartAddr: The start Address for each sector                      
  * @param  Length: the length of programming operation
  * @param  pBuf: Target address saved by read data
  */
void FLASH_E2_ReadByte(E2_SECTOR_NUM_Type e2psector, uint32_t StartAddr, uint32_t Length, uint8_t *pBuf)
{
    uint32_t tmp_len = 0;
    while (tmp_len < Length)
    {
        *pBuf++ = *((uint8_t *)(E2_BLOCK_ADDRESS + (e2psector << 10) + StartAddr + tmp_len));
        tmp_len++;
    }
}

/**
  * @brief  Programs a page at a specified address of the EEPRom block. 
  * @param  StartAddr: The start Address                       
  * @note   Must be aligned to a HalfWORD(2 bytes) for each programming. 
  * @param  Length: the length of programming operation
  * @note   Must be divisible by 2. 
  * @param  Buf: the sourse data of programming operation
  * @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
  *         FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
  */
FLASH_Status FLASH_E2_ProgramPage_HalfWord(E2_SECTOR_NUM_Type E2Sector, uint32_t StartAddr, uint32_t Length, uint8_t *Buf)
{
    FLASH_Status status = FLASH_COMPLETE;
    uint32_t tmp_len = 0;
    uint32_t tmp_addr = 0;

    /* Check the parameters */
    assert_param(IS_LENGTH_OK(Length));

    /* Clear pending flags (if any) */
    FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                    FLASH_FLAG_STAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGWERR | FLASH_FLAG_FLSERR);

    tmp_addr = E2_BLOCK_ADDRESS + E2Sector * 1024 + StartAddr;
    while (tmp_len < Length)
    {
        /* Programming a Word to the special address */
        status = FLASH_E2_ProgramHalfWord(tmp_addr, *((uint16_t *)(Buf + tmp_len)));
        if (status == FLASH_COMPLETE)
        {
            tmp_addr += 2;
            tmp_len += 2;
        }
        else
        {
            break;
        }
    }

    tmp_addr = E2_BLOCK_ADDRESS + E2Sector * 1024 + StartAddr;

    if (status == FLASH_COMPLETE)
    {
        /* Verify the page */
        status = FLASH_Verify_Byte(tmp_addr, Length, Buf);
    }

    return status;
}

/**
  * @brief  Programs a page at a specified address of the OTP block. 
  * @param  StartAddr: The start Address                       
  * @note   Must be aligned to a WORD(4 bytes) for each programming. 
  * @param  Length: the length of programming operation
  * @note   Must be divisible by 4. 
  * @param  Buf: the sourse data of programming operation
  * @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
  *         FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
  */
FLASH_Status FLASH_OTP_ProgramPage(uint32_t StartAddr, uint32_t Length, uint8_t *Buf)
{
    FLASH_Status status = FLASH_COMPLETE;
    uint32_t tmp_len = 0;
    uint32_t tmp_addr = 0;

    /* Check the parameters */
    assert_param(IS_LENGTH_OK(Length));

    /* Clear pending flags (if any) */
    FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                    FLASH_FLAG_STAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGWERR | FLASH_FLAG_FLSERR);

    tmp_addr = StartAddr;
    while (tmp_len < Length)
    {
        /* Programming a Word to the special address */
        status = FLASH_OTP_ProgramWord(tmp_addr, *((uint32_t *)(Buf + tmp_len)));
        if (status == FLASH_COMPLETE)
        {
            tmp_addr += 4;
            tmp_len += 4;
        }
        else
        {
            break;
        }
    }

    if (status == FLASH_COMPLETE)
    {
        /* Verify the page */
        status = FLASH_Verify_Byte(StartAddr, Length, Buf);
    }

    return status;
}

/**
  * @brief  Enables or disables the write protection of the desired sectors.
  * @param  WRT_PRT: specifies the sector(s) to be write protected or unprotected.
  *         This parameter can be one of the following values or combination value:
  *            @arg WRT_PRT_S0_S7    : Enable Write protection of Sector0   - Sector7        
  *            @arg WRT_PRT_S8_S15   : Enable Write protection of Sector8   - Sector15        
  *            @arg WRT_PRT_S16_S23  : Enable Write protection of Sector16  - Sector23      
  *            @arg ......                                                                  
  *            @arg WRT_PRT_S224_S231: Enable Write protection of Sector224 - Sector231
  *            @arg WRT_PRT_S232_S239: Enable Write protection of Sector232 - Sector239
  *            @arg WRT_PRT_S240_S247: Enable Write protection of Sector240 - Sector247
  *            @arg WRT_PRT_S248_S255: Enable Write protection of Sector248 - Sector255

  * @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
  *         FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
  */
FLASH_Status FLASH_SetWriteProtect(uint32_t WRT_PRT)
{
    FLASH_Status status = FLASH_COMPLETE;
    uint32_t tmpreg = 0;

    /* Clear pending flags (if any) */
    FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                    FLASH_FLAG_STAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGWERR | FLASH_FLAG_FLSERR);

    /* Programs the write protection values */
    tmpreg = 0xFF00FF00;
    tmpreg |= ((WRT_PRT & 0x000000FF)) | ((WRT_PRT & 0x0000FF00) << 8);
    status = FLASH_PRTB_ProgramWord(WRITE_PROTECT_ADDRESS, tmpreg);
    if (status == FLASH_COMPLETE)
    {
        tmpreg = 0xFF00FF00;
        tmpreg |= ((WRT_PRT & 0x00FF0000) >> 16) | ((WRT_PRT & 0xFF000000) >> 8);
        status = FLASH_PRTB_ProgramWord(WRITE_PROTECT_ADDRESS + 0x4, tmpreg);
    }

    /* Verify the write protection values  */
    if (FLASH_GetWriteProtect() != WRT_PRT)
    {
        status = FLASH_ERROR_VERIFY;
    }

    return status;
}

/**
  * @brief  Sets the read protection level.
  * @param  RD_PRT: specifies the read protection level.
  *         This parameter can be one of the following values:
  *            @arg 0x5AA5: No protection
  *            @arg 0xAAAA: The Low Level Read protection of the memory
  *            @arg 0xFFFF: The High Level Read protection of the memory (Debug Interface Disable)
  *   
  * @note   When enabling The High Level Read protection ,the debug interface is disable and it's no more possible to go back to level 1 or 0
  *    
  * @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
  *         FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
  */
FLASH_Status FLASH_SetReadProtect(uint16_t RD_PRT)
{
    FLASH_Status status = FLASH_COMPLETE;

    /* Check the parameters */
    assert_param(IS_RD_PRT(RD_PRT));

    /* Clear pending flags (if any) */
    FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                    FLASH_FLAG_STAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGWERR | FLASH_FLAG_FLSERR);

    /* Programs the read protection values */
    status = FLASH_PRTB_ProgramHalfWord(READ_PROTECT_ADDRESS, RD_PRT);

    /* Verify the read protection values  */
    if (FLASH->RPR != RD_PRT)
    {
        status = FLASH_ERROR_VERIFY;
    }

    return status;
}

/**
  * @brief  Returns the FLASH Write Protection Option Bytes value.
  * @retval The FLASH Write Protection  Option Bytes value
  */
uint32_t FLASH_GetWriteProtect(void)
{
    /* Return the FLASH write protection Register value */
    return (FLASH->WRPR);
}

/**
  * @brief  Returns the FLASH Read Protection level.
  * @retval FLASH ReadOut Protection Status:
  *           - SH_SET, when RD_PRT_HIGH_LEVEL or RD_PRT_LOW_LEVEL is set
  *           - SH_RESET, when RD_PRT_NO_PROTECT is set
  */
FlagStatus FLASH_GetReadProtect(void)
{
    FlagStatus readstatus = SH_RESET;

    if ((FLASH->RPR != (uint8_t)RD_PRT_NO_PROTECT))
    {
        readstatus = SH_SET;
    }
    else
    {
        readstatus = SH_RESET;
    }
    return readstatus;
}

/**
  * @brief  Sets the customer option.
  * @param  OPT0: Customer Option0.
  *         This parameter can be one of the following values:
  *         @arg  FLASH_NODIV_MAIN :  Flash is not divided into blocks, PC pointer addresses from Main Memory 
  *         @arg  FLASH_DIV_MAIN :    Flash is divided into two blocks, Main Memory and Backup Memory,PC pointer addresses from Main Memory 
  *         @arg  FLASH_DIV_BACKUP :  Flash is divided into two blocks, PC pointer addresses from Backup Memory 
  * @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
  *         FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
  */
FLASH_Status FLASH_SetCustomerOption(uint32_t OPT)
{
    FLASH_Status status = FLASH_COMPLETE;

    /* Clear pending flags (if any) */
    FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                    FLASH_FLAG_STAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGWERR | FLASH_FLAG_FLSERR);

    /* Programs the customer option0 */
    status = FLASH_CB_ProgramWord(OP_CUST1_ADDRESS, OPT);

    if (status == FLASH_COMPLETE)
    {
        /* Verify the Customer Option0 */
        if (*(__IO uint32_t *)OP_CUST1_ADDRESS != OPT)
        {
            status = FLASH_ERROR_VERIFY;
        }
    }
    return status;
}

/**
  * @brief  Returns the Customer Option0.
  * @retval The Customer Option0 Bytes value
  */
uint32_t FLASH_GetCustomerOPT0(void)
{
    /* Return the Customer Option0 Bytes value */
    return (FLASH->OPR.V32);
}

/**
  * @brief  Returns the Customer Option0.
  * @retval The Customer Option0 Bytes value
  */
uint32_t FLASH_GetCustomerOPT1(void)
{
    /* Return the Customer Option1 Bytes value */
    return (FLASH->OPR_CUST1.V32);
}

/**
  * @brief  Sets the customer security.
  * @param  CS0: Customer Security0 .
  * @param  CS1: Customer Security1 .
  * @retval FLASH Status: The returned value can be: FLASH_BSY, FLASH_FLAG_PGPERR, FLASH_FLAG_PGWERR, FLASH_FLAG_WRPERR, 
  *                       FLASH_FLAG_FLSERR, FLASH_FLAG_STAERR, FLASH_ERROR_OPERATION or FLASH_COMPLETE.
  */
FLASH_Status FLASH_SetCustomerSecurity(uint32_t CS0, uint32_t CS1)
{
    FLASH_Status status = FLASH_COMPLETE;

    /* Unlock the Flash to enable the flash control register access *************/
    FLASH_Info_Unlock(MULTI_OPERATION);

    /* Sets the programming window timer values */
    FLASH_Set_PGMWindow(FLASH_Calculate_WinCounterVal(2 * PGM_WORD_TIME), FLASH_Calculate_WinCounterVal(2 * PGM_WORD_TIME));

    /* Clear pending flags (if any) */
    FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                    FLASH_FLAG_STAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGWERR | FLASH_FLAG_FLSERR);

    /* Programs the read protection values */
    status = FLASH_CB_ProgramWord(CUSTOM_SECURITY_ADDRESS, CS0);
    if (status == FLASH_COMPLETE)
    {
        status = FLASH_CB_ProgramWord(CUSTOM_SECURITY_ADDRESS + 4, CS1);
    }

    if (status == FLASH_COMPLETE)
    {
        /* Verify the Customer Option0 */
        if (*(__IO uint32_t *)CUSTOM_SECURITY_ADDRESS != CS0)
        {
            status = FLASH_ERROR_VERIFY;
        }
        else
        {
            /* Verify the Customer Option1 */
            if (*(__IO uint32_t *)(CUSTOM_SECURITY_ADDRESS + 4) != CS1)
            {
                status = FLASH_ERROR_VERIFY;
            }
        }
    }
    return status;
}

/**
  * @brief  Returns the Unique Device ID.
  * @param  Buf: The point of Unique ID Buffer.
  * @retval The unique device ID(96bit)
  */
void FLASH_GetUniqueID(uint8_t *Buf)
{
    uint32_t tmp_i = 0;
    /* Return the Customer Option1 Bytes value */
    for (tmp_i = 0; tmp_i < 3; tmp_i++)
    {
        *((uint32_t *)(Buf + tmp_i * 4)) = *((uint32_t *)(UNIQUE_ID_ADDRESS + tmp_i * 4));
    }
}

/**
  * @brief  Returns the Agent ID.
  * @param  Buf: The buffer of Agent ID Buffer.
  * @retval None
  */
void FLASH_GetAgentID(uint8_t *Buf)
{
    uint32_t tmp_i = 0;
    /* Return the Customer Option1 Bytes value */
    for (tmp_i = 0; tmp_i < 4; tmp_i++)
    {
        *((uint32_t *)(Buf + tmp_i * 4)) = *((uint32_t *)(AGENT_ID_ADDRESS + tmp_i * 4));
    }
}

/**
* @brief  Checks whether the specified FLASH flag is set or not.
* @param  FLASH_FLAG: specifies the FLASH flag to check.
*         This parameter can be one of the following values:
*            @arg FLASH_FLAG_EOP: FLASH End of Operation flag 
*            @arg FLASH_FLAG_OPERR: FLASH operation Error flag 
*            @arg FLASH_FLAG_FLSERR: FLASH hardware Error flag 
*            @arg FLASH_FLAG_WRPERR: FLASH Write protected error flag 
*            @arg FLASH_FLAG_PGPERR: FLASH Programming one time error flag
*            @arg FLASH_FLAG_PGWERR: FLASH Programming Window counter error flag
*            @arg FLASH_FLAG_STAERR: FLASH Programming State error flag
*            @arg FLASH_FLAG_BSY: FLASH Busy flag
* @retval The new state of FLASH_FLAG (SH_SET or SH_RESET).
*/
FlagStatus FLASH_GetFlagStatus(uint32_t FLASH_FLAG)
{
    FlagStatus bitstatus = SH_RESET;
    /* Check the parameters */
    assert_param(IS_FLASH_GET_FLAG(FLASH_FLAG));

    if ((FLASH->SR.V32 & FLASH_FLAG) != (uint32_t)SH_RESET)
    {
        bitstatus = SH_SET;
    }
    else
    {
        bitstatus = SH_RESET;
    }
    /* Return the new state of FLASH_FLAG (SH_SET or SH_RESET) */
    return bitstatus;
}

/**                 
  * @brief  This function writes a data buffer in flash (data are 32-bit aligned).
  * @note   After writing data buffer, the flash content is checked.
  * @param  FlashAddress: start address for writing data buffer
  * @param  Data: pointer on data buffer
  * @param  DataLength: length of data buffer (unit is 32-bit word)   
  * @retval 0: Data successfully written to Flash memory
  *         1: Error occurred while writing data in Flash memory
  *         2: Written Data in flash memory is different from expected one
  */
uint32_t FLASH_If_Write(__IO uint32_t *FlashAddress, uint8_t *Data, uint16_t DataLength, uint32_t file_size)
{
    FLASH_Status status = FLASH_COMPLETE;

    static uint32_t total = 0;
    uint32_t tmp_len = 0;
    uint32_t tmp_addr = 0;

    /* Clear pending flags (if any) */
    FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                    FLASH_FLAG_STAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGWERR | FLASH_FLAG_FLSERR);

    tmp_addr = *FlashAddress;
    while (tmp_len < DataLength)
    {
        /* Programming a Word to the special address */
        status = FLASH_Main_ProgramWord(tmp_addr, *(uint32_t *)(Data + tmp_len));
        if (status == FLASH_COMPLETE)
        {
            tmp_addr += 4;
            tmp_len += 4;
            total++;
            /*To be verified*/
            if (total * 4 >= file_size) //When all bytes are written, the last frame is less than 1024 or 128, and the complement is 0x1A
            {
                total = 0;
                return (0);
            }
        }
        else
        {
            break;
        }
    }

    return (0);
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

/****END OF FILE****/
