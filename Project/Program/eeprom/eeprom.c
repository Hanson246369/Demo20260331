/******************** (C) COPYRIGHT 2021 sinowealth ***************************
 * @file      eeprom.c
 * @describe  eeprom Application functions
 * @platform  target board
 * @version   V1.1.0
 * @author    SinoWealth
 * @date      7-February-2022
 **********************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_syscfg.h"
#include "eeprom.h"
#include "stdbool.h"
#include "string.h"

#define EEPROM_SECTOR_SIZE						1024
uint8_t Eeprom_BUF[EEPROM_SECTOR_SIZE];


/**
 ******************************************************************************
 * @name     FunctionalState GET_LVRENValue(void)
 * @author   SinoWealth
 * @version  V1.1.0
 * @date     9-OCT.-2021
 * @brief    Get LVR Enable bit value function.
 ******************************************************************************
 */
FunctionalState GET_LVRENValue(void)
{
    FunctionalState NewState = SH_DISABLE;

    if (1 == SYSCFG->PWRCR.BIT.LVREN)
    {
        NewState = SH_ENABLE;
    }
    else
    {
        NewState = SH_DISABLE;
    }
    return NewState;
}

/**
 ******************************************************************************
 * @name     FLASH_Status EepromErase(E2_SECTOR_NUM_Type nSector)
 * @author   sinowealth
 * @version  V1.1.0
 * @date     23-June-2021
 * @brief    Erase eeprom
 ******************************************************************************
 */
FLASH_Status EepromErase(E2_SECTOR_NUM_Type nSector)
{
    FLASH_Status status = FLASH_COMPLETE;

    FunctionalState NewState = SH_DISABLE;

    /* Get LVR enable value */
    NewState = GET_LVRENValue();

    //write protect,avoid program fleet
    __disable_irq();

    IWDG_ReloadCounter();          //feed dog,Leave enough time to erase or operate flash
    SYSCFG_VLVRConfig(SH_DISABLE); //To erase or operate flash, the LVR must be closed,
                                   //otherwise the program runs abnormally

    FLASH_E2_Unlock(SINGLE_OPERATION);

    status = FLASH_E2_EraseSector(nSector);

    FLASH_E2_Lock();

    IWDG_ReloadCounter(); //feed dog
    if (NewState == SH_ENABLE)
        SYSCFG_VLVRConfig(SH_ENABLE); //After erasing or operating the flash,
                                      //judge whether to restore the original state

    __enable_irq();

    return status;
}

/**
  ******************************************************************************
  * @name     void EepromWrite(uint32_t nData, uint32_t nAddr)
  * @author   SinoWealth
  * @version  V1.1.0
  * @date     23-June-2021
  * @brief    write eeprom
  ******************************************************************************
  */
void EepromWrite(uint32_t nData, uint32_t nAddr)
{
    FunctionalState NewState = SH_DISABLE;

    /* Get LVR enable value */
    NewState = GET_LVRENValue();

    __disable_irq();

    IWDG_ReloadCounter();          // feed dog,Leave enough time to erase or operate flash
    SYSCFG_VLVRConfig(SH_DISABLE); //To erase or operate flash, the LVR must be closed,
                                   //otherwise the program runs abnormally

    FLASH->SR.V32 = 0xFFFFFFFF;
    FLASH->E2KYR = EEPROM_KEY;
    FLASH->E2KYR = EEPROM_KEY_single;
    FLASH->CNTR = 0xFFFFFFFF;
    FLASH->UPCNTR = 0xFFFFFFFF;
    FLASH->CNTCR = 0x01;
    FLASH->CR.BIT.PSIZE = 0;
    FLASH->CR.BIT.CMD = 0xB44B;
    FLASH->CR.BIT.STRT = 1;
    *(__IO uint32_t *)nAddr = nData;
    while (FLASH->SR.BIT.BSY == 1)
    {
    };
    while (FLASH->SR.BIT.EOP == 0)
    {
    };
    FLASH->SR.BIT.EOPC = 1;
    FLASH->CNTCR = 0x00;
    FLASH->CR.BIT.E2LCK = 1;

    IWDG_ReloadCounter(); // feed dog
    if (NewState == SH_ENABLE)
        SYSCFG_VLVRConfig(SH_ENABLE); //After erasing or operating the flash,
                                      //judge whether to restore the original state

    __enable_irq();
}

/**
  ******************************************************************************
  * @name     uint8_t EepromRead(uint32_t Addr)
  * @author   SinoWealth
  * @version  V1.1.0
  * @date     23-June-2021
  * @brief    read eeprom 
  ******************************************************************************
  */
uint8_t EepromRead(uint32_t Addr)
{
    return (*(__IO uint8_t *)Addr);
}



//不检查的写入
//StartAddr:起始地址(此地址必须为2的倍数!!)
//WriteBuffer:uint8_t *数据指针
//WriteSize:字节数(此字节数必须为2的倍数!!) 注意：StartAddr+WriteSize <= 1024
//return:0,成功；1：失败
uint8_t E2_Write_DataStr_HalfWord_NoCheck(E2_SECTOR_NUM_Type DataPage, uint32_t StartAddr,
                                  uint8_t *WriteBuffer, uint16_t WriteSize)
{
	FLASH_Status status = FLASH_COMPLETE;
    FunctionalState NewState = SH_DISABLE;
	
	/* Get LVR enable value */
	NewState = GET_LVRENValue();
	 // 16bit write
	__disable_irq();

	IWDG_ReloadCounter();          // feed dog,Leave enough time to erase or operate flash
	SYSCFG_VLVRConfig(SH_DISABLE); //To erase or operate flash, the LVR must be closed,
								   //otherwise the program runs abnormally

	FLASH_E2_Unlock(MULTI_OPERATION);
	status = FLASH_E2_ProgramPage_HalfWord(DataPage, StartAddr, WriteSize, WriteBuffer);
	FLASH_E2_Lock();

	IWDG_ReloadCounter(); // feed dog
	if (NewState == SH_ENABLE)
		SYSCFG_VLVRConfig(SH_ENABLE); //After erasing or operating the flash,
									  //judge whether to restore the original state

	__enable_irq();

	if (status == FLASH_COMPLETE)
		return 0; // OK
	else
		return 1; // Failed
}

//从指定地址开始写入指定长度的数据
//StartAddr:起始地址(此地址必须为2的倍数!!)
//WriteBuffer:uint8_t *数据指针
//WriteSize:字节数(此字节数必须为2的倍数!!)注意：StartAddr+WriteSize <= 1024
//return:0,成功；1：失败
uint8_t E2_Write_DataStr_HalfWord(E2_SECTOR_NUM_Type DataPage, uint32_t StartAddr, uint16_t WriteSize, uint8_t *WriteBuffer)
{
	FLASH_Status status = FLASH_COMPLETE;
    uint8_t ErrorFlag = 0;
    FunctionalState NewState = SH_DISABLE;
	uint16_t i;  
	
	FLASH_E2_ReadByte(DataPage, 0, EEPROM_SECTOR_SIZE, Eeprom_BUF);
	for(i=0; i<WriteSize; i++)//校验数据
	{
		if(Eeprom_BUF[StartAddr+i] != 0)break;//需要擦除  	  
	}
	
	if(i<WriteSize)//需要擦除
	{
		/* Get LVR enable value */
		NewState = GET_LVRENValue();

		__disable_irq();

		IWDG_ReloadCounter();          // feed dog,Leave enough time to erase or operate flash
		SYSCFG_VLVRConfig(SH_DISABLE); //To erase or operate flash, the LVR must be closed,
									   //otherwise the program runs abnormally

		FLASH_E2_Unlock(SINGLE_OPERATION);
		status = FLASH_E2_EraseSector(DataPage);
		FLASH_E2_Lock();

		IWDG_ReloadCounter(); // feed dog
		if (NewState == SH_ENABLE)
			SYSCFG_VLVRConfig(SH_ENABLE); //After erasing or operating the flash,
										  //judge whether to restore the original state

		__enable_irq();

		if (status != FLASH_COMPLETE)
			return 1;
		
		for(i=0; i<WriteSize; i++)//复制
		{
			Eeprom_BUF[StartAddr+i] = WriteBuffer[i];	  
		}
		ErrorFlag = E2_Write_DataStr_HalfWord_NoCheck(DataPage, 0, Eeprom_BUF, EEPROM_SECTOR_SIZE);
	}
	else
		ErrorFlag = E2_Write_DataStr_HalfWord_NoCheck(DataPage, StartAddr, WriteBuffer, WriteSize);

	return ErrorFlag; //0,成功；1：失败
}

void E2_InitSystemData(void)
{
	uint8_t EEPCheckData[2];
	
	FLASH_E2_ReadByte(E2_USER_Sector, E2_USER_START_ADDR, E2_USER_CHECK_LEN, EEPCheckData);
	if(EEPCheckData[0] == E2_INIT_CHECK1 && EEPCheckData[1] == E2_INIT_CHECK2)
	{
		FLASH_E2_ReadByte(E2_USER_Sector, E2_MACHINE_PARAM_ADDR, sizeof(MAC_SET), (uint8_t *)&MAC_SET);
		FLASH_E2_ReadByte(E2_USER_Sector, E2_PRESSURE_ZERO_ADDR, sizeof(PRS_ZERO), (uint8_t *)&PRS_ZERO);
	}
	else 
	{
		MAC_SET.unit = UNIT_BAR_BAR;
		MAC_SET.lpMode = LP_MODE1;
		MAC_SET.mute = MUTE_OFF;
		E2_Write_DataStr_HalfWord(E2_USER_Sector, E2_MACHINE_PARAM_ADDR, sizeof(MAC_SET), (uint8_t *)&MAC_SET);
		
		memset((uint8_t *)&PRS_ZERO, 0, sizeof(PRS_ZERO));
		E2_Write_DataStr_HalfWord(E2_USER_Sector, E2_PRESSURE_ZERO_ADDR, sizeof(PRS_ZERO), (uint8_t *)&PRS_ZERO);
		
		EEPCheckData[0] = E2_INIT_CHECK1;
		EEPCheckData[1] = E2_INIT_CHECK2;
		E2_Write_DataStr_HalfWord(E2_USER_Sector, E2_USER_START_ADDR, E2_USER_CHECK_LEN, EEPCheckData);
	}
}


