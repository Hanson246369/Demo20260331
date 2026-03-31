/******************** (C) COPYRIGHT 2021 sinowealth ***************************
 * @file      eeprom.h
 * @describe  eeprom head file
 * @platform  target board
 * @version   V1.1.0
 * @author    SinoWealth
 * @date      27-January-2022
 **********************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EEPROM_H
#define __EEPROM_H

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"
#include "app.h"

/// gg 20200409
#define EEPROM_KEY ((uint32_t)0x9BDF1357)
#define EEPROM_KEY_single ((uint32_t)0xC3C3C3C3)
#define EEPROM_ADDR 0x0FFF0000

#define E2_USER_Sector    				EEPROM_Sector_0

#define E2_USER_START_ADDR   			0   
#define E2_USER_CHECK_LEN				2

#define E2_MACHINE_PARAM_ADDR			(E2_USER_START_ADDR + E2_USER_CHECK_LEN)
	
#define E2_PRESSURE_ZERO_ADDR			(E2_MACHINE_PARAM_ADDR + E2_MACHINE_PARAM_LEN)
#define E2_FIRST_PRS_ZERO_FLAG			0xA1

#define E2_INIT_CHECK1					0x55
#define E2_INIT_CHECK2					0xAA


/** @defgroup EEPROM_Exported_Functions
 *
 */
FunctionalState GET_LVRENValue(void);
FLASH_Status EepromErase(E2_SECTOR_NUM_Type nSector);
uint8_t EepromRead(uint32_t Addr);
uint8_t E2_Write_DataStr_HalfWord(E2_SECTOR_NUM_Type DataPage, uint32_t StartAddr, uint16_t WriteSize, uint8_t *WriteBuffer);
void E2_InitSystemData(void);
#endif /* __EEPROM_H */
