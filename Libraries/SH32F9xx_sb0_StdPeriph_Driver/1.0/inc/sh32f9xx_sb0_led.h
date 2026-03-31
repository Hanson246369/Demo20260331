/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_led.h
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file provide LED module's APIs
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
#ifndef __SH32F9XX_SB0_LED_H
#define __SH32F9XX_SB0_LED_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"
     
#define LED_FLAG_COM            (uint16_t)0x0001
#define LED_FLAG_FRAME          (uint16_t)0x0002
 
#define IS_LED_FLAG(FLAG)       (((FLAG & (uint16_t)0xFFFC) == 0x00) && (FLAG != 0x00))

/** @addtogroup sh32f9xx_sb0_StdLib_Driver
  * @{
  */

/** 
  * @brief  LED com mode seclet  
  */

typedef enum
{
    LED_SEC_COM_NOP  = 0x0000,
    LED_SEC_COM1  = 0x0001,
    LED_SEC_COM2  = 0x0002,
    LED_SEC_COM3  = 0x0004,
    LED_SEC_COM4  = 0x0008,
    LED_SEC_COM5  = 0x0010,
    LED_SEC_COM6  = 0x0020,
    LED_SEC_COM7  = 0x0040,
    LED_SEC_COM8  = 0x0080,
    LED_SEC_COM9  = 0x0100,
    LED_SEC_COM10 = 0x0200,
    LED_SEC_COM11 = 0x0400,
    LED_SEC_COM12 = 0x0800,
    LED_SEC_COM_ALL  = 0x0FFF,
}LEDSECCOM_TypeDef;

/** 
  * @brief  LED SEG1 mode seclet  
  */
typedef enum
{
    LED_SEC_SEG_NOP1  = 0x00,
    LED_SEC_SEG1  = 0x01,
    LED_SEC_SEG2  = 0x02,
    LED_SEC_SEG3  = 0x04,
    LED_SEC_SEG4  = 0x08,
    LED_SEC_SEG5  = 0x10,
    LED_SEC_SEG6  = 0x20,
    LED_SEC_SEG7  = 0x40,
    LED_SEC_SEG8  = 0x80,
    LED_SEC_SEG_ALL1  = 0xFF,
}LEDSECSEG1_TypeDef;


/** 
  * @brief  LED SEG2 mode seclet  
  */
typedef enum
{
    LED_SEC_SEG_NOP2  = 0x00,
    LED_SEC_SEG9   = 0x01,
    LED_SEC_SEG10  = 0x02,
    LED_SEC_SEG11  = 0x04,
    LED_SEC_SEG12  = 0x08,
    LED_SEC_SEG13  = 0x10,
    LED_SEC_SEG14  = 0x20,
    LED_SEC_SEG15  = 0x40,
    LED_SEC_SEG16  = 0x80,
    LED_SEC_SEG_ALL2  = 0xFF,
}LEDSECSEG2_TypeDef;            

/**
    * @brief define the interrupt run mode control
    * @arg   LED_INT_Continue:    continue scanf
    * @arg   LED_INT_Stop:  stop scanf
  */    
typedef enum 
{ 
    LED_INT_Continue = 0, 
    LED_INT_Stop = 1, 
}LED_INT_MODE_TypeDef; 
     
/**
    * @brief define the Mode select
    * @arg   LED_MODE1:    modle  1
    * @arg   LED_MODE2:    modle  2
  */    
typedef enum 
{ 
    LED_MODE1 = 0, 
    LED_MODE2 = 1, 
}LED_MODE_SEL_TypeDef;

/**
    * @brief define the LED share control
    * @arg   LED_SHARE_CONTROL:    share control
    * @arg   LED_SET_IO:           set  IO
  */    
typedef enum 
{ 
    LED_SHARE_CONTROL = 0, 
    LED_SET_IO = 1, 
}LED_SHARE_CTR_TypeDef;


/**
    * @brief define common cathode or common anode
    * @arg   LED_Cathode:         common cathode
    * @arg   LED_Anode:           common anode
  */    
typedef enum 
{ 
    LED_Cathode = 0, 
    LED_Anode   = 1, 
}LED_ANODE_TypeDef;

/**
    * @brief define scanf counter 
    * @arg   LED_SCANF_CNTSTO:      counter stop
    * @arg   LED_SCANF_CNTContinue: counter continue
  */    
typedef enum 
{ 
    LED_SCANF_CNTSTO = 0, 
    LED_SCANF_CNTContinue = 1, 
}LED_SCANF_CNTMOD_TypeDef;

/**
    * @brief define LED com Interrupt flag 
    * @arg   LED_COM_NOIF:         NO COM Interrupt flag
    * @arg   LED_COM_IF:           COM Interrupt flag
  */    
typedef enum 
{ 
    LED_COM_NOIF = 0, 
    LED_COM_IF = 1, 
}LED_COM_IF_TypeDef;

/**
    * @brief define LED frame Interrupt flag 
    * @arg   LED_FRAME_NOIF: NO COM Interrupt flag
    * @arg   LED_FRAME_IF:   COM Interrupt flag
  */    
typedef enum 
{ 
    LED_FRAME_NOIF = 0, 
    LED_FRAME_IF = 1, 
}LED_FRAME_IF_TypeDef;

/**
    * @brief CLEAR LED COM Interrupt flag 
    * @arg   LED_COM_NOIF: NO COM Interrupt flag
    * @arg   LED_COM_IF:   COM Interrupt flag
  */    
typedef enum 
{ 
    LED_COM_IF_NOAVAIL = 0, 
    LED_COM_IF_CLEAR = 1, 
}LED_COM_IFCLEAR_TypeDef;

/**
    * @brief CLEAR LED FRAME Interrupt flag 
    * @arg   LED_FRAME_NOIF: NO COM Interrupt flag
    * @arg   LED_FRAME_IF:   COM Interrupt flag
  */    
typedef enum 
{ 
    LED_FRAME_IF_NOAVAIL = 0, 
    LED_FRAME_IF_CLEAR = 1, 
}LED_FRAME_IFCLEAR_TypeDef;


/*! @struct LED_InitTypeDef
  * @brief  structure for TWI initial
  */ 
typedef struct
{   /* for CR register */
    LED_INT_MODE_TypeDef               LedIntMod      ;  /*!< interrupt run mode control*/
    LED_MODE_SEL_TypeDef               ModSel         ;  /*!< modle 1, model 2*/
    LED_SHARE_CTR_TypeDef              LedShareCtr    ;  /*!< LED share control*/
    LED_ANODE_TypeDef                  LedAnodeSel    ;  /*common cathode or common anode */
    LED_SCANF_CNTMOD_TypeDef           CntComMod      ;  /*LED COM counter*/
    
    uint8_t                            LedClkWidth    ;  /*LED COM scan width [15~8]*/
    uint8_t                            LedDeadBand    ;  /*LED COM dead band control [23~16]*/
    /* for LEDSHARE register */
    uint8_t                   LedSEG1PINMode ;  /*SEG mode seclet*/
    uint8_t                   LedSEG2PINMode ;  /*SEG mode seclet*/
    uint16_t                  LedComModeSEL  ;  /*LED com mode seclet*/

}LED_InitTypeDef;

/**
  * @}
  */ 
/* Fills each LED_InitStruct member with its default value */
void LED_StructInit(LED_InitTypeDef *LED_InitStruct);

/* LED driver mould Initial function */
void LED_Init(const LED_InitTypeDef *InitCfg);

/* Clear the LED single pending flags */
void LED_ClearFlag(uint16_t LED_Flag);

/* Clears ALL LED driver mould interrupt flag */
void LEDMOULD_ClearFlag(void);

/* Open or close the LED peripheral */
void LED_OnOff(CmdState OnOffState);

/* Enable or disable the LED interrupt. */
void LED_INTConfig(FunctionalState NewState);

/* Enable or disable the specified LED frame interrupt */
void LED_INT_FrameConfig(FunctionalState NewState);

/* Enable or disable the specified LED com interrupt */
void LED_INT_ComConfig(FunctionalState NewState);

/* Enable or disable the specified LED frame DMA */
void LED_DMA_FrameEN(FunctionalState NewState);

/* Enable or disable the specified LED com DMA */
void LED_DMA_ComEN(FunctionalState NewState);

/* Check whether the specified LED COM flag is set or not */
FlagStatus LED_GetComFlagStatus(LED_TypeDef *LEDMOUDLE);

/* Check whether the specified LED Frame flag is set or not */
FlagStatus LED_GetFrameFlagStatus(LED_TypeDef *LEDMOUDLE);


/**
  * @}
  */ 


#ifdef __cplusplus
}
#endif

#endif /*__SH32F9XX_SB0_LED_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
