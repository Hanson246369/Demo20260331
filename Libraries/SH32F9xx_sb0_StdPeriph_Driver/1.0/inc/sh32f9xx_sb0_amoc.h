/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_amoc.h
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file contains all the functions prototypes for the TPS firmware
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
#ifndef __SH32F9XX_SB0_AMOC_H
#define __SH32F9XX_SB0_AMOC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/** @addtogroup AMOC_MODULE
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/

/** @defgroup AMOC_Exported_Types
  * @{
  */



/** @defgroup AMOC_Internal_Voltage_Reference_CHOP
  * @{
  */

#define TPS_VrefCHOP_Positive                (uint8_t)0x00
#define TPS_VrefCHOP_Negative                (uint8_t)0x04
#define IS_TPS_VREF_CHOP_POLARITY(POLARITY)  ((POLARITY == TPS_VrefCHOP_Positive) \
                                             || (POLARITY == TPS_VrefCHOP_Negative))
/**
  * @}
  */ 


/** @defgroup TPS_Internal_Voltage_Reference
  * @{
  */

#define TPS_VrefVoltage_2V5           (uint8_t)0x00
#define TPS_VrefVoltage_3V3           (uint8_t)0x02
#define IS_TPS_VREF_VOLTAGE(VOLTAGE)  ((VOLTAGE == TPS_VrefVoltage_2V5) \
                                      || (VOLTAGE == TPS_VrefVoltage_3V3))

/**
  * @}
  */  



/**
  * @}
  */ 


/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/ 

/** @defgroup TPS_Exported_Functions
  * @{
  */

/*Open or disable the CHOP.*/
void TPS_ChopOnOff(CmdState OnOffState);

/*Set Input polarity of CHOP internal OP when VREF CHOP closed*/
void TPS_SetOPInputPolarity(LevelStatus levelState);

/*Configure the internal reference voltage(Vref) value.*/
extern void TPS_VrefVoltageConfig(uint8_t TPS_VrefVoltage);

/*Open or disable the internal reference voltage(Vref).*/
extern void TPS_VrefOnOff(CmdState OnOffState);

/*Enable or disable the Temperature Sensor CHOP switch.*/
extern void TPS_TempSensorCHOPConfig(FunctionalState NewState);

/*Enable or disable the Temperature Sensor .*/
extern void TPS_TempSensorOnOff(CmdState OnOffState);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /*__SH32F9XX_SB0_AMOC_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
