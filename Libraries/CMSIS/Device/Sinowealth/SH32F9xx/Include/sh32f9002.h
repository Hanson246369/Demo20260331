/**
  ******************************************************************************
  * @file    sh32f9002.h
  * @version V1.1.0
  * @date    28-May-2022
  * @brief   CMSIS CORE Device Peripheral Access Layer Header File.
  *          This file contains all the peripheral register's definitions, bits
  *          definitions and memory mapping for Sinowealth M3 based devices.
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
  * COPYRIGHT 2021 Sinowealth
  *
  *
  ******************************************************************************
*/

#ifndef __SH32f9002_H__
#define __SH32f9002_H__

#include "sh32f9xx_sb0.h"
#include "system_sh32f9xx_sb0.h"
#include "sh32f9xx_sb0_libcfg.h"



/***************************************/
#define ROM_SIZE   0x40000
#define CRAM_SIZE  0x4000
#define SRAM_SIZE  0x4000
#define ROM_BASE   0x0
#define CRAM_BASE  0x10000000
#define SRAM_BASE  0x20000000
/***************************************/

#define IS_IN_SRAM(addr) ((((uint32_t)(addr)) >= SRAM_BASE) && (((uint32_t)(addr)) <= (SRAM_BASE+SRAM_SIZE)))
#define IS_IN_CRAM(addr) ((((uint32_t)(addr)) >= CRAM_BASE) && (((uint32_t)(addr)) <= (CRAM_BASE+CRAM_SIZE)))
#define IS_IN_ROM(addr)  ((((uint32_t)(addr)) >= ROM_BASE)  && (((uint32_t)(addr)) <= (ROM_BASE+ROM_SIZE)))

#endif /*__SH32F9002_H__*/


