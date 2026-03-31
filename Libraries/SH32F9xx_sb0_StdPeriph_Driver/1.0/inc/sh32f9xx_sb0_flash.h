/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_flash.h
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-08-26  
  * @brief   This file contains all the functions prototypes for the FLASH 
  *          firmware library.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SH32F9XX_SB0_FLASH_H
#define __SH32F9XX_SB0_FLASH_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"
#include <stdint.h>

/** @addtogroup sh32f9xx_sb0_StdLib_Driver
  * @{
  */ 

/** @addtogroup FLASH_MODULE
  * @{
  */

/** @defgroup FLASH_Group_Constant  Public Constants
  * @{
  */ 
 
/** @enum FLASH_Status
    @brief FLASH Operation Status  
     */   
/*! Flash Operation Status */
typedef enum
{ 
    FLASH_BUSY             = 1,   /*!< Flash is busy */
    FLASH_ERROR_STA        = 2,   /*!< Flash State Error */
    FLASH_ERROR_PGW        = 3,   /*!< Flash Program Window Error */
    FLASH_ERROR_PGP        = 4,   /*!< Flash Write Error */
    FLASH_ERROR_WRP        = 5,   /*!< Flash Write Protect Error */
    FLASH_ERROR_FLS        = 6,   /*!< Flash Hardware Error */
    FLASH_ERROR_OPERATION  = 7,   /*!< Flash Opertation Error */
    FLASH_ERROR_ERASE      = 8,   /*!< Flash Erase Error */
    FLASH_ERROR_PROGRAM    = 9,   /*!< Flash Program Error */
    FLASH_ERROR_BLANK      = 10,  /*!< Flash Blank Error */
    FLASH_ERROR_VERIFY     = 11,  /*!< Flash Verify Error */
    FLASH_COMPLETE         = 12,  /*!< Flash Operation Complete*/
}FLASH_Status;                


/**
  * @}
  */ 


/** @defgroup FLASH_Group_Macro  Public Macros
  * @{
  */ 
  
/** 
  * @defgroup Group1 Flash Latency
  * @{
  */
#define FLASH_Latency_0                ((uint8_t)0x0000)   /*!< FLASH Zero Latency cycle */
#define FLASH_Latency_1                ((uint8_t)0x0001)   /*!< FLASH One Latency cycle */
#define FLASH_Latency_2                ((uint8_t)0x0002)   /*!< FLASH Two Latency cycles */
#define FLASH_Latency_3                ((uint8_t)0x0003)   /*!< FLASH Three Latency cycles */
#define FLASH_Latency_4                ((uint8_t)0x0004)   /*!< FLASH Four Latency cycles */
#define FLASH_Latency_5                ((uint8_t)0x0005)   /*!< FLASH Five Latency cycles */
#define FLASH_Latency_6                ((uint8_t)0x0006)   /*!< FLASH Six Latency cycles */
#define FLASH_Latency_7                ((uint8_t)0x0007)   /*!< FLASH Seven Latency cycles */

/*! Check the Latency value */
#define IS_FLASH_LATENCY(LATENCY)      (((LATENCY) == FLASH_Latency_0)    \
                                       || ((LATENCY) == FLASH_Latency_1)  \
                                       || ((LATENCY) == FLASH_Latency_2)  \
                                       || ((LATENCY) == FLASH_Latency_3)  \
                                       || ((LATENCY) == FLASH_Latency_4)  \
                                       || ((LATENCY) == FLASH_Latency_5)  \
                                       || ((LATENCY) == FLASH_Latency_6)  \
                                       || ((LATENCY) == FLASH_Latency_7))

/**
  * @}
  */ 


/** 
  * @defgroup Group2 FLASH_CR register
  * @{
  */

#define FLASH_CR_CMD_ME0               ((uint32_t)0xAA55)/*!< Flash ME0 Opteration Command */   
#define FLASH_CR_CMD_MSE               ((uint32_t)0xE619)/*!< Flash Main Block Sector Erase Opteration Command */ 
#define FLASH_CR_CMD_MPG               ((uint32_t)0x6E91)/*!< Flash Main Block Programming Opteration Command */ 
#define FLASH_CR_CMD_E2PG              ((uint32_t)0xB44B)/*!< Flash EEpRom Block Programming Opteration Command */ 
#define FLASH_CR_CMD_E2SE              ((uint32_t)0x4BB4)/*!< Flash EEpRom Block Sector Erase Opteration Command */ 
#define FLASH_CR_CMD_OPG               ((uint32_t)0xF00F)/*!< Flash OTP Block Programming Opteration Command */
#define FLASH_CR_CMD_CBPG              ((uint32_t)0xC33C)/*!< Flash Customer Block Programming Opteration Command */
#define FLASH_CR_CMD_CBSE              ((uint32_t)0x3CC3)/*!< Flash Customer Block Sector Erase Opteration Command */ 
#define FLASH_CR_CMD_SPG               ((uint32_t)0xD22D)/*!< Flash Protect Block Programming Opteration Command */





/*! Programming a Half-word one time */
#define FLASH_CR_PSIZE_HALFWD           1
/*! Programming a word one time */    
#define FLASH_CR_PSIZE_WD               0

/**
  * @}
  */ 


/** 
  * @defgroup Group3 FLASH Sectors Parameters
  * @{
  */ 
  
typedef enum {
    EEPROM_Sector_0         = 0,     /*!< Sector_0*/
    EEPROM_Sector_1         = 1, 
    EEPROM_Sector_2         = 2, 
    EEPROM_Sector_3         = 3,    
    EEPROM_Sector_4         = 4, 
    EEPROM_Sector_5         = 5, 
}E2_SECTOR_NUM_Type;

#define FLASH_Sector_0              ((uint8_t)0x0000) /*!< Sector Number 0 */
#define FLASH_Sector_5              ((uint8_t)0x0005) /*!< Sector Number 5 */
#define FLASH_Sector_255            ((uint8_t)0x00FF) /*!< Sector Number 255 */
                                        
#define IS_E2_BLOCK_SECTOR(SECTOR)      ((SECTOR) <= FLASH_Sector_5)  /*!< Check the sector parameters */
#define IS_FLASH_SECTOR(SECTOR)         ((SECTOR) <= FLASH_Sector_255)/*!< Check the sector parameters */

/**
  * @}
  */
  
  
/** 
  * @defgroup Group4 FLASH Read Protection 
  * @{
  */
#define RD_PRT_NO_PROTECT               ((uint16_t)0xA55A)/*!< The value of no read protection  */
#define RD_PRT_LOW_PROTECT              ((uint16_t)0xAAAA)/*!< The value of the low level read protection */
#define RD_PRT_HIGH_PROTECT             ((uint16_t)0xC33C)/*!< The value of the high level read protection  */
/*! Check the value of read protection */ 
#define IS_RD_PRT(LEVEL)                (((LEVEL) == RD_PRT_NO_PROTECT) \
                                        || ((LEVEL) == RD_PRT_LOW_PROTECT) \
                                        || ((LEVEL) == RD_PRT_HIGH_PROTECT))
/**
  * @}
  */


/** 
  * @defgroup Group5 Flash Write Protection
  * @{
  */ 
#define WRT_PRT_S0_S7                  ((uint32_t)0x00000001) /*!< Write protection of Sector0   - Sector7  */
#define WRT_PRT_S8_S15                 ((uint32_t)0x00000002) /*!< Write protection of Sector8   - Sector15 */
#define WRT_PRT_S16_S23                ((uint32_t)0x00000004) /*!< Write protection of Sector16  - Sector23 */
#define WRT_PRT_S24_S31                ((uint32_t)0x00000008) /*!< Write protection of Sector24  - Sector31 */
#define WRT_PRT_S32_S39                ((uint32_t)0x00000010) /*!< Write protection of Sector32  - Sector39 */
#define WRT_PRT_S40_S47                ((uint32_t)0x00000020) /*!< Write protection of Sector40  - Sector47 */
#define WRT_PRT_S48_S55                ((uint32_t)0x00000040) /*!< Write protection of Sector48  - Sector55 */
#define WRT_PRT_S56_S63                ((uint32_t)0x00000080) /*!< Write protection of Sector56  - Sector63 */
#define WRT_PRT_S64_S71                ((uint32_t)0x00000100) /*!< Write protection of Sector64  - Sector71 */
#define WRT_PRT_S72_S79                ((uint32_t)0x00000200) /*!< Write protection of Sector72  - Sector79 */
#define WRT_PRT_S80_S87                ((uint32_t)0x00000400) /*!< Write protection of Sector80  - Sector87 */
#define WRT_PRT_S88_S95                ((uint32_t)0x00000800) /*!< Write protection of Sector88  - Sector95 */
#define WRT_PRT_S96_S103               ((uint32_t)0x00001000) /*!< Write protection of Sector96  - Sector103*/
#define WRT_PRT_S104_S111              ((uint32_t)0x00002000) /*!< Write protection of Sector104 - Sector111*/
#define WRT_PRT_S112_S119              ((uint32_t)0x00004000) /*!< Write protection of Sector112 - Sector119*/
#define WRT_PRT_S120_S127              ((uint32_t)0x00008000) /*!< Write protection of Sector120 - Sector127*/
#define WRT_PRT_S128_S135              ((uint32_t)0x00010000) /*!< Write protection of Sector128 - Sector135*/
#define WRT_PRT_S136_S143              ((uint32_t)0x00020000) /*!< Write protection of Sector136 - Sector143*/
#define WRT_PRT_S144_S151              ((uint32_t)0x00040000) /*!< Write protection of Sector144 - Sector151*/
#define WRT_PRT_S152_S159              ((uint32_t)0x00080000) /*!< Write protection of Sector152 - Sector159*/
#define WRT_PRT_S160_S167              ((uint32_t)0x00100000) /*!< Write protection of Sector160 - Sector167*/
#define WRT_PRT_S168_S175              ((uint32_t)0x00200000) /*!< Write protection of Sector168 - Sector175*/
#define WRT_PRT_S176_S183              ((uint32_t)0x00400000) /*!< Write protection of Sector176 - Sector183*/
#define WRT_PRT_S184_S191              ((uint32_t)0x00800000) /*!< Write protection of Sector184 - Sector191*/
#define WRT_PRT_S192_S199              ((uint32_t)0x01000000) /*!< Write protection of Sector192 - Sector199*/
#define WRT_PRT_S200_S207              ((uint32_t)0x02000000) /*!< Write protection of Sector200 - Sector207*/
#define WRT_PRT_S208_S215              ((uint32_t)0x04000000) /*!< Write protection of Sector208 - Sector215*/
#define WRT_PRT_S216_S223              ((uint32_t)0x08000000) /*!< Write protection of Sector216 - Sector223*/
#define WRT_PRT_S224_S231              ((uint32_t)0x10000000) /*!< Write protection of Sector224 - Sector231*/
#define WRT_PRT_S232_S239              ((uint32_t)0x20000000) /*!< Write protection of Sector232 - Sector239*/
#define WRT_PRT_S240_S247              ((uint32_t)0x40000000) /*!< Write protection of Sector240 - Sector247*/
#define WRT_PRT_S248_S255              ((uint32_t)0x80000000) /*!< Write protection of Sector248 - Sector255*/
                                       
#define WRT_PRT_Sector_All             ((uint32_t)0xFFFFFFFF) /*!< Write protection of all Sectors */
/**
  * @}
  */

/** 
  *@defgroup Group6 FLASH Program Window Parameters 
  * @{
  */
#define PGM_WORD_TIME                  70           /*!< The time of programming a word data (Uint:100us) */
#define PGM_HFWORD_TIME                35           /*!< The time of programming a half-word data (Uint:100us) */
#define SE_ERS_TIME                    0XFFFFFFFF   /*!< The time of erasing a sector */
#define ME_ERS_TIME                    0XFFFFFFFF   /*!< The time of erasing the whole flash */
/**
  * @}
  */


/** 
  * @defgroup Group7 FLASH Operation Error Flags 
  * @{
  */ 
#define FLASH_FLAG_EOP                 ((uint32_t)0x00000001)  /*!< FLASH End of Operation flag */
#define FLASH_FLAG_OPERR               ((uint32_t)0x00000002)  /*!< FLASH Operation Error flag */
#define FLASH_FLAG_FLSERR              ((uint32_t)0x00000008)  /*!< FLASH Hardware Error flag */
#define FLASH_FLAG_WRPERR              ((uint32_t)0x00000010)  /*!< FLASH Write protected error flag */
#define FLASH_FLAG_PGPERR              ((uint32_t)0x00000020)  /*!< FLASH Programming One time function error flag */
#define FLASH_FLAG_PGWERR              ((uint32_t)0x00000040)  /*!< FLASH Programming Window error flag  */
#define FLASH_FLAG_STAERR              ((uint32_t)0x00000080)  /*!< FLASH Programming State error flag  */
#define FLASH_FLAG_BSY                 ((uint32_t)0x00008000)  /*!< FLASH Busy flag */ 

/*! Check the error flag */
#define IS_FLASH_CLEAR_FLAG(FLAG)      ((((FLAG) & (uint32_t)0xFFFFFF04) == 0x00000000) && ((FLAG) != 0x00000000))
/*! Check the error flag */
#define IS_FLASH_GET_FLAG(FLAG)        (((FLAG) == FLASH_FLAG_EOP) || ((FLAG) == FLASH_FLAG_OPERR)  \
                                       || ((FLAG) == FLASH_FLAG_WRPERR) || ((FLAG) == FLASH_FLAG_PGPERR)  \
                                       || ((FLAG) == FLASH_FLAG_FLSERR) || ((FLAG) == FLASH_FLAG_PGWERR)  \
                                       || ((FLAG) == FLASH_FLAG_STAERR) || ((FLAG) == FLASH_FLAG_BSY))
/**
  * @}
  */
  
  
/** 
  * @defgroup Group8 The operation keys
  * @{
  */
 
#define FLASH_MAIN_KEY                 ((uint32_t)0x8ACE0246)  /*!< The key value of unlocking the Main block  */
#define FLASH_E2_KEY                   ((uint32_t)0x9BDF1357)  /*!< The key value of unlocking the EEpRom block  */
#define FLASH_INFO_KEY                 ((uint32_t)0xABCD5678)  /*!< The key value of unlocking the Info. block  */
#define FLASH_SINGLE_OP_KEY            ((uint32_t)0xC3C3C3C3)  /*!< The key value of unlocking single operation  */
#define FLASH_MULTI_OP_KEY             ((uint32_t)0xB4B4B4B4)  /*!< The key value of unlocking multiple operations  */

#define SINGLE_OPERATION               ((uint32_t)0x00)     /*!< The flag of single operation  */
#define MULTI_OPERATION                ((uint32_t)0x01)     /*!< The flag of multiple operations  */
/**
  * @}
  */

/** 
  * @defgroup Group9 The address of blocks
  * @{
  */
#define E2_BLOCK_ADDRESS              0x0FFF0000      /*!< The start address of the EEpRom block */
#define PROTECT_BLOCK_ADDRESS         0x0FFFE000      /*!< The start address of the Protect block */
#define CUSTOMER_BLOCK_ADDRESS        0x0FFFE800      /*!< The start address of the Customer block */
#define PRODUCT_BLOCK_ADDRESS         0x0FFFF000      /*!< The start address of the Product block */
#define OTP_BLOCK_ADDRESS             0x0FFFF800      /*!< The start address of the OTP block */
#define MAIN_BLOCK_ADDRESS            0x00000000      /*!< The start address of the Main block */
                                                
#define READ_PROTECT_ADDRESS          0x0FFFE000      /*!< The start address of the read protection bits */
#define WRITE_PROTECT_ADDRESS         0x0FFFE010      /*!< The start address of the write protection bits */
                                                
#define OP_CUST1_ADDRESS              0x0FFFE808      /*!< The start address of the customer option */
#define CUSTOM_SECURITY_ADDRESS       0x0FFFE820      /*!< The start address of the customer security */
#define AGENT_ID_ADDRESS              0x0FFFF080      /*!< The start address of the agent ID */
#define UNIQUE_ID_ADDRESS             0x0FFFF910      /*!< The start address of the unique device ID */


#define FLASH_NODIV_MAIN              ((uint32_t)0x00)              /*!< Flash is not divided into blocks, PC pointer addresses from Main Memory */
#define FLASH_DIV_MAIN                ((uint32_t)0x80)              /*!< Flash is divided into two blocks, Main Memory and Backup Memory,PC pointer addresses from Main Memory   */
#define FLASH_DIV_BACKUP              ((uint32_t)0xC0)              /*!< Flash is divided into two blocks, PC pointer addresses from Backup Memory  */


/*! Check the address is reasonable or not */ 
#define IS_FLASH_MAIN_BLOCK_ADDRESS(ADDRESS)                ((ADDRESS) <= 0x0003FFFF) 
/*! Check the address is reasonable or not */ 
#define IS_E2_BLOCK_ADDRESS(ADDRESS)                        (((ADDRESS) >= 0x0FFF0000) && ((ADDRESS) <= 0x0FFF2FFF)) 
/*! Check the address is reasonable or not */ 
#define IS_PROTECT_BLOCK_ADDRESS(ADDRESS)                   (((ADDRESS) >= 0x0FFFE000) && ((ADDRESS) <= 0x0FFFE7FF)) 
/*! Check the address is reasonable or not */ 
#define IS_CUSTOMER_BLOCK_ADDRESS(ADDRESS)                  (((ADDRESS) >= 0x0FFFE800) && ((ADDRESS) <= 0x0FFFEFFF)) 
/*! Check the address is reasonable or not */ 
#define IS_OTP_BLOCK_ADDRESS(ADDRESS)                       (((ADDRESS) >= 0x0FFFF800) && ((ADDRESS) <= 0x0FFFFFFF)) 
/*! Check the Length is reasonable or not */ 
#define IS_LENGTH_OK(LENGTH)                                (((LENGTH) >= 0x4) && ((LENGTH%4) == 0x0)) 
/**
  * @}
  */

/**
  * @}
  */ 



/** @addtogroup FLASH_Public_Functions Public Functions
  * @{
  */ 
 
/** @defgroup FLASH_Group1 FLASH Interface configuration functions
  * @{
  */  
/* FLASH Interface configuration functions ************************************/

/*Sets the code latency value.*/
void FLASH_SetLatency(uint32_t FLASH_Latency);

/*Enables or disables the Instruction Cache feature.*/
void FLASH_InstructionCacheOnOff(CmdState NewState);

/*Enables or disables the Data Cache feature.*/
void FLASH_DataCacheOnOff(CmdState NewState);

/*Enables or disables the Prefetch feature.*/
void FLASH_PrefetchOnOff(CmdState NewState);

/*Resets the Instruction Cache and the Data Cache.*/
void FLASH_CacheReset(void);
/**
  * @}
  */ 
  
/** @defgroup FLASH_Group2 FLASH Memory Programming Settings
  * @{
  */  
/* FLASH Memory Programming Settings functions *****************************************/  

/*Calculates the programming window counter value according the window time.*/
uint32_t FLASH_Calculate_WinCounterVal(uint32_t us100Delay);

/*Sets the programming window timer values.*/
void FLASH_Set_PGMWindow(uint32_t CounterInitValue, uint32_t UpperCounterValue);

/*Clears the programming window timer values.*/
void FLASH_Clear_PGMWindow(void);

/*Unlocks the FLASH control register access of main block.*/
void FLASH_Main_Unlock(uint8_t OperationType);

/*Locks the FLASH control register access of main block.*/
void FLASH_Main_Lock(void);

/*Unlocks the EEPRom block control register access.*/
void FLASH_E2_Unlock(uint8_t OperationType);

/*Locks the EEPRom block control register access.*/
void FLASH_E2_Lock(void);

/*Unlocks the FLASH Info. block control register access.*/
void FLASH_Info_Unlock(uint8_t OperationType);

/*Locks the FLASH Info. block control register access.*/
void FLASH_Info_Lock(void);
/**
  * @}
  */
  
/** @defgroup FLASH_Group3 Interrupts and flags management functions  
  * @{
  */  
/* Interrupts and flags management functions **********************************/

/*Checks whether the specified FLASH flag is set or not.*/
FlagStatus FLASH_GetFlagStatus(uint32_t FLASH_FLAG);

/*Clears the FLASH's pending flags.*/
void FLASH_ClearFlag(uint32_t FLASH_FLAG);

/*Returns the FLASH Status.*/
FLASH_Status FLASH_GetStatus(void);

/*Waits for a FLASH operation to complete.*/
FLASH_Status FLASH_WaitForLastOperation(void);
/**
  * @}
  */
  
/** @defgroup FLASH_Group4 FLASH Memory Programming basic functions
  * @{
  */  

/******************************** FLASH Read *****************************************/  

/*Reading EEPROM data.*/
void FLASH_E2_ReadByte(E2_SECTOR_NUM_Type e2psector,uint32_t StartAddr, uint32_t Length, uint8_t *pBuf);

/* FLASH Memory Programming Basic functions *****************************************/   

/*Erase All Flash Secotrs.*/
FLASH_Status FLASH_Main_EraseAllSectors(void);

/*Erases a specified FLASH Sector.*/
FLASH_Status FLASH_Main_EraseSector(uint32_t FLASH_Sector);

/*Programs a word (32-bit) at a specified address of the main block.*/
FLASH_Status FLASH_Main_ProgramWord(uint32_t Address, uint32_t Data);

/*Programs a half word (16-bit) at a specified address of the main block.*/
FLASH_Status FLASH_Main_ProgramHalfWord(uint32_t Address, uint16_t Data);

/*Erases a specified EEPROM block Sector.*/
FLASH_Status FLASH_E2_EraseSector(E2_SECTOR_NUM_Type E2_Sector);

/*Programs a word (32-bit) at a specified address of the EEPROM block.*/
FLASH_Status FLASH_E2_ProgramWord(uint32_t Address, uint32_t Data);

/*Programs a half word (16-bit) at a specified address of the EEPROM block.*/
FLASH_Status FLASH_E2_ProgramHalfWord(uint32_t Address, uint16_t Data);

/*Erases the Sector of Customer block.*/
FLASH_Status FLASH_CB_EraseSector(void);

/*Programs a word (32-bit) at a specified address of the Customer block.*/
FLASH_Status FLASH_CB_ProgramWord(uint32_t Address, uint32_t Data);

/*Programs a half word (16-bit) at a specified address of the Customer block.*/
FLASH_Status FLASH_CB_ProgramHalfWord(uint32_t Address, uint16_t Data);

/*Programs a word (32-bit) at a specified address of the Protect block.*/
FLASH_Status FLASH_PRTB_ProgramWord(uint32_t Address, uint32_t Data);

/*Programs a half word (16-bit) at a specified address of the Protect block.*/
FLASH_Status FLASH_PRTB_ProgramHalfWord(uint32_t Address, uint16_t Data);

/*Programs a word (32-bit) at a specified address of the OTP block.*/
FLASH_Status FLASH_OTP_ProgramWord(uint32_t Address, uint32_t Data);

/*Programs a half word (16-bit) at a specified address of the OTP block(0x0FFFF800 - 0x0FFFFFFF).*/
FLASH_Status FLASH_OTP_ProgramHalfWord(uint32_t Address, uint16_t Data);


/* FLASH Memory Programming functions *****************************************/ 

/*Programs a page at a specified address of the EEPRom block.*/
FLASH_Status FLASH_E2_ProgramPage_HalfWord(E2_SECTOR_NUM_Type E2Sector,uint32_t StartAddr, uint32_t Length, uint8_t *Buf);

/*Programs a page at a specified address of the main block.*/
FLASH_Status FLASH_Main_ProgramPage(uint32_t StartAddr, uint32_t Length, uint8_t *Buf);

/*Programs a page at a specified address of the EEPRom block.*/
FLASH_Status FLASH_E2_ProgramPage(E2_SECTOR_NUM_Type E2Sector,uint32_t StartAddr, uint32_t Length, uint8_t *Buf);

/*Programs a page at a specified address of the OTP block.*/
FLASH_Status FLASH_OTP_ProgramPage(uint32_t StartAddr, uint32_t Length, uint8_t *Buf);

/*Verify a page at a specified address of Flash.*/
FLASH_Status FLASH_Verify_Byte(uint32_t StartAddr, uint32_t Length, uint8_t *Buf);

/*Verify a page at a specified address of Flash.*/
FLASH_Status FLASH_Verify_HalfWord(uint32_t StartAddr, uint32_t Length, uint8_t *Buf);

/*Verify a page at a specified address of Flash.*/
FLASH_Status FLASH_VerifyPage(uint32_t StartAddr, uint32_t Length, uint8_t *Buf);

/*Enables or disables the write protection of the desired sectors.*/
FLASH_Status FLASH_SetWriteProtect(uint32_t WRT_PRT);

/*Sets the read protection level.*/
FLASH_Status FLASH_SetReadProtect(uint16_t RD_PRT);

/*Returns the FLASH Write Protection Option Bytes value.*/
uint32_t FLASH_GetWriteProtect(void);

/*Returns the FLASH Read Protection level.*/
FlagStatus FLASH_GetReadProtect(void);

/*Sets the customer option.*/
FLASH_Status FLASH_SetCustomerOption(uint32_t OPT);

/*Returns the Customer Option0.*/
uint32_t FLASH_GetCustomerOPT0(void);

/*Returns the Customer Option0.*/
uint32_t FLASH_GetCustomerOPT1(void);

/*Sets the customer security.*/
FLASH_Status FLASH_SetCustomerSecurity(uint32_t CS0, uint32_t CS1);

/*Returns the Unique Device ID.*/
void FLASH_GetUniqueID(uint8_t *Buf);

/*Returns the Agent ID.*/
void FLASH_GetAgentID(uint8_t *Buf);

/*Calculates the programming window counter value according the window time.*/
uint32_t FLASH_Calculate_WinCounterVal(uint32_t us100Delay);

/*This function writes a data buffer in flash (data are 32-bit aligned).*/
uint32_t FLASH_If_Write(__IO uint32_t *FlashAddress, uint8_t *Data , uint16_t DataLength, uint32_t file_size);
/**
  * @}
  */

/**
  * @}
  */ 



#ifdef __cplusplus
}
#endif

#endif /* __SH32F9xx_sb0_FLASH_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
