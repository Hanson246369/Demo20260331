/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_libcfg.h
  * @author  sinowealth
  * @version V1.1.0
  * @date    2021-08-13  
  * @brief   This file includes all module's head files
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
#ifndef __SH32F9XX_SB0_LIBCFG_H
#define __SH32F9XX_SB0_LIBCFG_H

#ifdef __cplusplus
 extern "C" {
#endif

 
/** @addtogroup sh32f9xx_sb0_StdLib_Driver
  * @{
  */

/** @addtogroup LIB_Group Global
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/
/**
    * @brief Define Boolean data type
    * @arg   SH_TRUE:   logical  true
    * @arg   SH_FALSE:  logical  false
  */    
typedef enum{
    SH_FALSE=0,
    SH_TRUE =!SH_FALSE,
}bool_t;

/** 
  *@brief  check the input value is a legal boolean data
  */
#define IS_BOOL_TYPE(var) (((var) == SH_FALSE) || ((var) == SH_TRUE))

/**
    * @brief define  flag's data type
    * @arg   SH_SET:     the flag is setted
    * @arg   SH_RESET: the flag is cleared
  */    
typedef enum 
{ 
    SH_RESET = 0, 
    SH_SET = !SH_RESET, 
}FlagStatus;

/** 
  *@brief  check the input value is a legal flag data
  */
#define IS_FLAG_STATUS(flag) (((flag) == SH_RESET) || ((flag) == SH_SET))

/**
    * @brief define the functional state type
    * @arg   SH_ENABLE:    enable the feature
    * @arg   SH_DISABLE:  disable the feature
  */    
typedef enum 
{ 
    SH_DISABLE = 0, 
    SH_ENABLE = !SH_DISABLE, 
}FunctionalState; 
/** 
  *@brief  check the input value is a legal function state data
  */
#define IS_FUNCTION_STATE(state) (((state) == SH_DISABLE) || ((state) == SH_ENABLE))

/**
    * @brief define the peripheral state type
    * @arg   SH_ON:   peripheral is enabled
    * @arg   SH_OFF:  peripheral is disabled
  */    
typedef enum 
{ 
    SH_OFF = 0, 
    SH_ON = !SH_OFF, 
}CmdState; 
/** 
  *@brief  check the input value is a legal peripheral state data
  */
#define IS_CMD_STATE(state) (((state) == SH_ON) || ((state) == SH_OFF))

/**
    * @brief define the return data type
    * @arg   SH_ERROR:     error occurs
    * @arg   SH_SUCCESS:   operation succeeded
  */   
typedef enum 
{
    SH_ERROR = 0, 
    SH_SUCCESS = !SH_ERROR
} ErrorStatus;
/** 
  *@brief  check the input value is a legal error status data
  */
#define IS_ERROR_STATUS(status) (((status) == SH_ERROR) || ((status) == SH_SUCCESS))

/**
    * @brief define the peripheral Pin electrical level state type
    * @arg   SH_LOW:   SH_LOW level
    * @arg   SH_HIGH:  High level
  */    
typedef enum 
{ 
    SH_LOW = 0, 
    SH_HIGH = !SH_LOW, 
}LevelStatus; 
/** 
  *@brief  check the input value is a legal peripheral state data
  */
#define IS_LEVEL_STATE(state) (((state) == SH_LOW) || ((state) == SH_HIGH))




/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/ 

#include "sh32f9xx_sb0.h"
      
#ifndef _RTE_

#include "sh32f9xx_sb0_adc.h"      

#include "sh32f9xx_sb0_amoc.h"         
      
#include "sh32f9xx_sb0_crc.h"     

#include "sh32f9xx_sb0_dma.h"      

#include "sh32f9xx_sb0_exti.h"      
  
#include "sh32f9xx_sb0_flash.h"

#include "sh32f9xx_sb0_gpio.h"

#include "sh32f9xx_sb0_iwdt.h"

#include "sh32f9xx_sb0_lcd.h"

#include "sh32f9xx_sb0_led.h"

#include "sh32f9xx_sb0_nvic.h"

#include "sh32f9xx_sb0_pca.h"

#include "sh32f9xx_sb0_pwm.h"

#include "sh32f9xx_sb0_rambist.h"

#include "sh32f9xx_sb0_rcc.h"
      
#include "sh32f9xx_sb0_spi.h"

#include "sh32f9xx_sb0_syscfg.h"

#include "sh32f9xx_sb0_timer.h" 

#include "sh32f9xx_sb0_twi.h"  

#include "sh32f9xx_sb0_uart.h"  

#include "sh32f9xx_sb0_wwdt.h"


#else

#include "RTE_Components.h"

#ifdef RTE_MODULE_ADC
#include "sh32f9xx_sb0_adc.h"      
#endif      

#ifdef RTE_MODULE_AMOC
#include "sh32f9xx_sb0_amoc.h"      
#endif      
      
#ifdef RTE_MODULE_CRC
#include "sh32f9xx_sb0_crc.h"
#endif

#ifdef RTE_MODULE_DMA
#include "sh32f9xx_sb0_dma.h"      
#endif      

#ifdef RTE_MODULE_EXTI
#include "sh32f9xx_sb0_exti.h"      
#endif      
      
#ifdef RTE_MODULE_FLASH
#include "sh32f9xx_sb0_flash.h"
#endif

#ifdef RTE_MODULE_GPIO
#include "sh32f9xx_sb0_gpio.h"
#endif

#ifdef RTE_MODULE_IWDT
#include "sh32f9xx_sb0_iwdt.h"
#endif

#ifdef RTE_MODULE_LCD
#include "sh32f9xx_sb0_lcd.h"
#endif

#ifdef RTE_MODULE_LED
#include "sh32f9xx_sb0_led.h"
#endif      

#ifdef RTE_MODULE_NVIC
#include "sh32f9xx_sb0_nvic.h"
#endif      

#ifdef RTE_MODULE_PCA
#include "sh32f9xx_sb0_pca.h"
#endif      

#ifdef RTE_MODULE_PWM
#include "sh32f9xx_sb0_pwm.h"
#endif      

#ifdef RTE_MODULE_RAMBIST
#include "sh32f9xx_sb0_rambist.h"
#endif      
      
#ifdef RTE_MODULE_RCC
#include "sh32f9xx_sb0_rcc.h"
#endif      

#ifdef RTE_MODULE_SPI
#include "sh32f9xx_sb0_spi.h"
#endif

#ifdef RTE_MODULE_SYSCFG
#include "sh32f9xx_sb0_syscfg.h"
#endif

#ifdef RTE_MODULE_TIMER
#include "sh32f9xx_sb0_timer.h"
#endif

#ifdef RTE_MODULE_TWI
#include "sh32f9xx_sb0_twi.h"
#endif

#ifdef RTE_MODULE_UART
#include "sh32f9xx_sb0_uart.h"
#endif

#ifdef RTE_MODULE_WWDT
#include "sh32f9xx_sb0_wwdt.h"
#endif


#endif
      
#ifdef _MODULE_DBG_PRINTF
#include <stdio.h>
#endif

#ifdef DEFAULT_ASSERT_ENABLE
/** @brief  assert for function's input parameters. Enable or disable it by the macro _DEBUG  at compile time*/
#define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t*)__FILE__,(uint32_t)__LINE__));
/** @brief  break the program at the assert  failed satement . Enable or disable it by the macro _DEBUG at compile time */
#define assert_break(expr) if(!(expr)){ __BKPT(0);}
/** @brief  define the assert failed actions here. Enable or disable it by the macro _DEBUG  at compile time */
void assert_failed(uint8_t* file, uint32_t line);
#else
/** @brief  assert for function's input parameters. Enable or disable it by the macro _DEBUG  at compile time*/
#define assert_param(expr) ((void)0)
/** @brief  break the program at the assert  failed satement . Enable or disable it by the macro _DEBUG at compile time */
#define assert_break(expr) ((void)0)
#endif

#ifdef __cplusplus
}
#endif

#endif /*__SH32F9XX_SB0_LIBCFG_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/










