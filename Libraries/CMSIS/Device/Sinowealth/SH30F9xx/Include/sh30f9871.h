/**
  ******************************************************************************
  * @file    sh30f9871.h
  * @version V1.1.0
  * @date    23-July-2021
  * @brief   CMSIS Cortex-M0+ Device Peripheral Access Layer Header File.
  *          This file contains all the peripheral register's definitions, bits
  *          definitions and memory mapping for Sinowealth M0+ based devices.
  ******************************************************************************
  * @attention
  *
  * SINOWEALTH IS SUPPLYING THIS SOFTWARE FOR USE EXCLUSIVELY ON SINOWEALTH'S 
  * MICROCONTROLLER PRODUCTS. IT IS PROTECTED UNDER APPLICABLE COPYRIGHT LAWS. 
  * THIS SOFTWARE IS FOR GUIDANCE IN ORDER TO SAVE TIME. AS A RESULT, SINOWEALTH 
  * SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES 
  * WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH FIRMWARE AND/OR
  * THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN IN 
  * CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2021 Sinowealth</center></h2>
  *
  *
  ******************************************************************************
*/

#ifndef __SH30F9871_H__
#define __SH30F9871_H__

#define SH30F9X71

#include "sh30f9xx_sa0.h"
#include "system_sh30f9xx_sa0.h"
#include "sh30f9xx_sa0_libcfg.h"




/***************************************/
#define ROM_SIZE   0x20000
#define SRAM_SIZE  0x4000
#define ROM_BASE   0x0
#define SRAM_BASE  0x20000000
/***************************************/

#define IS_IN_SRAM(addr) ((((uint32_t)(addr)) >= SRAM_BASE) && (((uint32_t)(addr)) <= (SRAM_BASE+SRAM_SIZE)))
#define IS_IN_ROM(addr)  ((((uint32_t)(addr)) >= ROM_BASE)  && (((uint32_t)(addr)) <= (ROM_BASE+ROM_SIZE)))

#endif /*__SH30F9871_H__*/
