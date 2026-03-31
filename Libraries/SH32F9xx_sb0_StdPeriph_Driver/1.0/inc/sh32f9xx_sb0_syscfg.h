/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_syscfg.h
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file contains all the functions prototypes for the PPP firmware
  *          library.
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
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SH32F9XX_SB0_SYSCFG_H
#define __SH32F9XX_SB0_SYSCFG_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/** @addtogroup SYSCFG_MODULE
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup SYSCFG_Exported_Constants
  * @{
  */ 

typedef enum
{
    SYSCFG_VLVR_Level_4V1 = 0x00,
    SYSCFG_VLVR_Level_3V7 = 0x01,
    SYSCFG_VLVR_Level_2V8 = 0x02,
    SYSCFG_VLVR_Level_2V3 = 0x03,
}SYSCFG_VLVR_LEVEL_Type;    

#define IS_SYSCFG_VLVR_LEVEL(LEVEL)  ((LEVEL == SYSCFG_VLVR_Level_4V1) \
                                     || (LEVEL == SYSCFG_VLVR_Level_3V7) \
                                     || (LEVEL == SYSCFG_VLVR_Level_2V8) \
                                     || (LEVEL == SYSCFG_VLVR_Level_2V3))

typedef enum
{
    SYSCFG_BOD_Mode_Rising        = 0x00,
    SYSCFG_BOD_Mode_Falling       = 0x01,
    SYSCFG_BOD_Mode_RisingFalling = 0x02,
}SYSCFGBODMode_Type;    

#define IS_SYSCFG_BOD_MODE(MODE)   ((MODE == SYSCFG_BOD_Mode_Rising) \
                                   || (MODE == SYSCFG_BOD_Mode_Falling) \
                                   || (MODE == SYSCFG_BOD_Mode_RisingFalling))
     
     
typedef enum
{
    SYSCFG_BOD_Level_2V4 = 0x00,
    SYSCFG_BOD_Level_2V5 = 0x01,
    SYSCFG_BOD_Level_2V6 = 0x02,
    SYSCFG_BOD_Level_2V7 = 0x03,
    SYSCFG_BOD_Level_2V8 = 0x04,
    SYSCFG_BOD_Level_2V9 = 0x05,
    SYSCFG_BOD_Level_3V0 = 0x06,
    SYSCFG_BOD_Level_3V1 = 0x07,
    SYSCFG_BOD_Level_3V2 = 0x08,
    SYSCFG_BOD_Level_3V3 = 0x09,
    SYSCFG_BOD_Level_3V4 = 0x0A,
    SYSCFG_BOD_Level_3V5 = 0x0B,
    SYSCFG_BOD_Level_3V6 = 0x0C,
    SYSCFG_BOD_Level_3V7 = 0x0D,
    SYSCFG_BOD_Level_3V8 = 0x0E,
    SYSCFG_BOD_Level_3V9 = 0x0F,
    SYSCFG_BOD_Level_4V0 = 0x10,
    SYSCFG_BOD_Level_4V1 = 0x11,
    SYSCFG_BOD_Level_4V2 = 0x12,
    SYSCFG_BOD_Level_4V3 = 0x13,
}SYSCFGBODLevel_Type;    

#define IS_SYSCFG_BOD_LEVEL(BOD_LEVEL)  ((BOD_LEVEL == SYSCFG_BOD_Level_2V4) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_2V5) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_2V6) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_2V7) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_2V8) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_2V9) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_3V0) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_3V1) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_3V2) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_3V3) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_3V4) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_3V5) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_3V6) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_3V7) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_3V8) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_3V9) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_4V0) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_4V1) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_4V2) \
                                        || (BOD_LEVEL == SYSCFG_BOD_Level_4V3)) 
     
 
#define SYSCFG_BOD_FLAG_BODIF      (uint8_t)0x01
#define SYSCFG_BOD_FLAG_BODF       (uint8_t)0x02

#define IS_SYSCFG_BOD_FLAG(FLAG)   ((FLAG == SYSCFG_BOD_FLAG_BODIF) \
                                   || (FLAG == SYSCFG_BOD_FLAG_BODF))
                                   

#define SYSCFG_SLEEPEntry_WFI   (uint8_t)0x00
#define SYSCFG_SLEEPEntry_WFE   (uint8_t)0x01

#define IS_SYSCFG_SLEEP_ENTRY(ENTRY)   ((ENTRY == SYSCFG_SLEEPEntry_WFI) \
                                       || (ENTRY == SYSCFG_SLEEPEntry_WFE))




#define SYSCFG_STOPEntry_WFI   (uint8_t)0x00
#define SYSCFG_STOPEntry_WFE   (uint8_t)0x01

#define IS_SYSCFG_SLOP_ENTRY(ENTRY)   ((ENTRY == SYSCFG_STOPEntry_WFI) \
                                       || (ENTRY == SYSCFG_STOPEntry_WFE))

typedef enum
{
    SYSCFG_SWJ_All_Function = 0x00,
    SYSCFG_SWD_CLOSE_PinRemap = 0x01,
}SYSCFG_SWJCFG_Type;

#define IS_SYSCFG_SWJ_PIN_MODE(MODE)   ((MODE == SYSCFG_SWJ_All_Function) \
                                       || (MODE == SYSCFG_SWD_CLOSE_PinRemap))




typedef enum
{
    SYSCFG_OSC_GPIO = 0x00,
    SYSCFG_OSC_Crystal = 0x01,
    SYSCFG_OSC_ExtClock = 0x02
}SYSCFG_OSCPin_Type;

#define IS_SYSCFG_OSC_PIN_MODE(MODE)   ((MODE == SYSCFG_OSC_GPIO) \
                                       || (MODE == SYSCFG_OSC_Crystal) \
                                       || (MODE == SYSCFG_OSC_ExtClock))

typedef enum
{
    SYSCFG_OSCX_GPIO = 0x00,
    SYSCFG_OSCX_Crystal = 0x01,
}SYSCFG_OSCXPin_Type;

#define IS_SYSCFG_OSCX_PIN_MODE(MODE)  ((MODE == SYSCFG_OSCX_GPIO) \
                                       || (MODE == SYSCFG_OSCX_Crystal))


#define SYSCFG_NMI_TRIGGER_CSM       (uint16_t)0x0100
#define SYSCFG_NMI_TRIGGER_BOD       (uint16_t)0x0080
#define SYSCFG_NMI_TRIGGER_EXTI0     (uint16_t)0x0040

#define IS_SYSCFG_NMI_TRIGGER_SOURCE(SOURCE)  (((SOURCE & (uint16_t)0xFE3F) == 0x00) \
                                              && (SOURCE != 0x00))





#define CRAM_Sector_0      (uint8_t)0x01
#define CRAM_Sector_1      (uint8_t)0x02
#define CRAM_Sector_2      (uint8_t)0x04
#define CRAM_Sector_3      (uint8_t)0x08
#define CRAM_Sector_4      (uint8_t)0x10
#define CRAM_Sector_5      (uint8_t)0x20
#define CRAM_Sector_6      (uint8_t)0x40
#define CRAM_Sector_7      (uint8_t)0x80

#define IS_SYSCFG_CRAM_SECTOR(LOCK_SECTOR)   (LOCK_SECTOR != 0x00)


                                                  
#define DBG_Periph_LCD     (uint16_t)0x0008
#define DBG_Periph_LED     (uint16_t)0x0010
#define DBG_Periph_DMA     (uint16_t)0x0020
#define DBG_Periph_IWDT    (uint16_t)0x0040
#define DBG_Periph_WWDT    (uint16_t)0x0080
#define DBG_Periph_PCA     (uint16_t)0x0100
#define DBG_Periph_TIM     (uint16_t)0x0200
#define DBG_Periph_PWM     (uint16_t)0x0400
#define DBG_Periph_UART    (uint16_t)0x0800
#define DBG_Periph_SPI     (uint16_t)0x1000
#define DBG_Periph_TWI     (uint16_t)0x2000

#define IS_DBG_PERIPH(PERIPH)  (((PERIPH & (uint16_t)0xC007) == 0x00) && (PERIPH != 0x00))
                                               

#define DBG_LOWPOWER_SLEEP          (uint16_t)0x0001
#define DBG_LOWPOWER_STOP           (uint16_t)0x0002      
#define IS_DBG_LOWPOWER_MODE(MODE)  (((MODE & (uint16_t)0xFFFC) == 0x00) && (MODE != 0x00))                                       

typedef enum
{
    SYSCFG_EFT_100M = 0,
    SYSCFG_EFT_72M  = 1,
    SYSCFG_EFT_50M  = 2,
    SYSCFG_EFT_24M  = 3
}SYSCFG_EFT_Type;

#define IS_SYSCFG_EFT_MODE(FREQ)   ((FREQ == SYSCFG_EFT_100M)  \
                                   || (FREQ == SYSCFG_EFT_72M) \
                                   || (FREQ == SYSCFG_EFT_50M) \
                                   || (FREQ == SYSCFG_EFT_24M))
/**
  * @}
  */ 


/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/* Initialize BOD mode and voltage threshold. */
extern void SYSCFG_BODInit(SYSCFGBODMode_Type SYSCFG_BOD_Mode, SYSCFGBODLevel_Type SYSCFG_BOD_Level);

/* Enable or disable the specified BOD interrupt. */
extern void SYSCFG_BODINTConfig(FunctionalState NewState);

/* Initialize LVR voltage threshold. */
extern void SYSCFG_VLVRInit(SYSCFG_VLVR_LEVEL_Type SYSCFG_VLVR_Level);

/* Enable or disable the specified LVR function. */
extern void SYSCFG_VLVRConfig(FunctionalState NewState);

/* Open or close BOD module. */
extern void SYSCFG_BODOnOff(CmdState OnOffState);

/* Check whether the specified BOD flag is set or not. */
extern FlagStatus SYSCFG_BODGetFlagStatus(uint8_t BOD_Flag);

/* Clear BOD pending bit. */
extern void SYSCFG_BODClearFlag(void);

/* Enters SLEEP mode. */
extern void SYSCFG_EnterSLEEPMode(uint8_t SYSCFG_SLEEPEntry);

/* Enters STOP mode. */
extern void SYSCFG_EnterSTOPMode(uint8_t SYSCFG_STOPEntry);

/* Configure NMI interrupt trigger source. */
extern void SYSCFG_NMIInterruptTriggerConfig(uint16_t TriggerSource, FunctionalState NewState);

/* Specifie SWJ pin alternate function. */
extern void SYSCFG_SWJPinConfig(SYSCFG_SWJCFG_Type SWJPin_Mode);

/* Specifie XTAL pin And XTALX alternate */
extern void SYSCFG_OSCPinConfig(SYSCFG_OSCPin_Type OSCPin_Mode,SYSCFG_OSCXPin_Type OSCXPin_Mode);

/* Lock or unlock CRAM sectors. */
extern void SYSCFG_CRAMLockConfig(uint8_t SectorNum, FunctionalState NewState);

/* Enable or disable peripherals clock in debug mode. */
extern void SYSCFG_DBGPeriphConfig(uint16_t DBG_Periph, FunctionalState NewState);

/* Enable or disable low power clock in debug mode. */
extern void SYSCFG_DBGLowPowerConfig(uint16_t LowPowerMode, FunctionalState NewState);

/* Enable or disable EFT Function. */
extern void SYSCFG_EFTConfig(SYSCFG_EFT_Type SYS_EFT_type, FunctionalState NewState);

#ifdef __cplusplus
}
#endif

#endif /* __SH32F9XX_SB0_SYSCFG_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
