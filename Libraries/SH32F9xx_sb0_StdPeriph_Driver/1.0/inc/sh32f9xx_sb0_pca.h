/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_PCA.h
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file contains all the functions prototypes for the PCA firmware
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
#ifndef __SH32F9XX_SB0_PCA_H
#define __SH32F9XX_SB0_PCA_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/** @defgroup PCA_DMA Trigger source 
  * @{
  */ 
#define PCA_DMA_CntOverflow   (uint16_t)0x0080
#define PCA_DMA_Channel_1     (uint16_t)0x0040
#define PCA_DMA_Channel_0     (uint16_t)0x0020

/*!  check PCA DMA Trigger source */
#define IS_PCA_Trg_SOURCE(source)  ((source == PCA_DMA_CntOverflow) \
                                   ||(source == PCA_DMA_Channel_1)   \
                                   ||(source == PCA_DMA_Channel_0))


/** @defgroup PCA_IntFlags 
  * @{
  */ 
  
#define PCA_FLAG_CCF0      (uint16_t)0x0001
#define PCA_FLAG_CCF1      (uint16_t)0x0002
#define PCA_FLAG_CF        (uint16_t)0x0004

/*!  check PCA Interrupt flag */
#define IS_PCA_GET_ONE_FLAG(FLAG)  ((FLAG == PCA_FLAG_CCF0) \
                                   ||(FLAG == PCA_FLAG_CCF1)  \
                                   ||(FLAG == PCA_FLAG_CF))




/*!  PCA CLOCK SOURCE */
typedef enum {
    SYSTEMCLK        =    0,     /*!< System clock   */
    SYSTEMCLKDIV4    =    1,     /*!< System clock DIV4 */
    SYSTEMCLKDIV12   =    2,     /*!< System clock DIV12 */
    SYSTEMCLKDIV32   =    3,     /*!< System clock DIV32 */
    TIM5OVERFLOW     =    4,     /*!< Timer 5 overflow */
    EXTHIGHOSCDIV8   =    5,     /*!< HSE DIV8 */
    ECIxNEGATIVELY   =    6,     /*!<Ecix falling edge (maximum rate = system clock frequency / 4) */
    LSIORLSE         =    7,     /*!<LSI 128K RC / LSE 32K */
}PCA_CLKDIV_Type;

/*!  check PCA clock source */
#define IS_PCACLKSOURCE_DIV(div) (((div) == SYSTEMCLK)       \
                                 || ((div) == SYSTEMCLKDIV4)   \
                                 || ((div) == SYSTEMCLKDIV12)  \
                                 || ((div) == SYSTEMCLKDIV32)  \
                                 || ((div) == TIM5OVERFLOW)    \
                                 || ((div) == EXTHIGHOSCDIV8)  \
                                 || ((div) == ECIxNEGATIVELY)  \
                                 || ((div) == LSIORLSE))

/*!  PCA Counter Mode */
typedef enum {
    SINGLEEDGE      =    0,     /*!< The counter counts up */
    DOUBLEEDGE      =    1,     /*!< Counter middle alignment */
}PCA_COUNTERMODE_Type;

/*!  check PCA Counter Mode */
#define IS_PCACOUNTERMODE_DIV(div) (((div) == SINGLEEDGE) \
                                   || ((div) == DOUBLEEDGE)) 

/*!  PCA Mode selection */
typedef enum {
    CAPTUREMODE      =    0,     /*!< capture mode   */
    TIMERMODE        =    1,     /*!< software timer */
    FREQOUTPUTMODE   =    2,     /*!< Frequency output */
    PWMMODE          =    3,     /*!< PWM output */
}PCA_MODEL_Type;

/*!  check PCA Mode */
#define IS_PCAMODE_DIV(div) (((div) == CAPTUREMODE)     \
                            || ((div) == TIMERMODE)       \
                            || ((div) == FREQOUTPUTMODE)  \
                            || ((div) == PWMMODE)) 

/*!  PCA Capture Mode */
typedef enum {
    RISING_EDGE_TRIGGER      =    0,     /*!< Rising edge trigger    */
    FALLING_EDGE_TRIGGER     =    2,     /*!< Falling edge trigger   */
    ARBITRARY_EDGE_TRIGGER   =    3,     /*!< Arbitrary edge trigger */
}PCA_CAPMODE_Type;

/*!  check PCA Capture Mode */
#define IS_PCACAPMODE_DIV(div) (((div) == RISING_EDGE_TRIGGER)     \
                               || ((div) == FALLING_EDGE_TRIGGER)    \
                               || ((div) == ARBITRARY_EDGE_TRIGGER)) 

/*!  PCA Software Timers Mode */
typedef enum {
    CONTINUOUS      =    0,     /*!< Continuous software timing */
    SINGLE          =    1,     /*!< Single software timing */
}PCA_TIMINGMODE_Type;

/*!  check PCA Software Timers Mode */
#define IS_PCATIMINGMODE_DIV(div) (((div) == CONTINUOUS) \
                                || ((div) == SINGLE))


/*!  PCA PWM Mode */
typedef enum {
    PWM_8BIT             =    0,     /*!< 8 bit PWM  */
    PWM_16BIT            =    1,     /*!< 16 bit PWM  */
    PHASE_PWM_16BIT      =    2,     /*!< 16 bit phase correction PWM */
    PHASEFREQ_PWM_16BIT  =    3,     /*!< 16 bit phase frequency correction PWM */
}PCA_PWMMODEL_Type;

/*!  check PCA PWM Mode */
#define IS_PWMMODEL_DIV(div) (((div) == PWM_8BIT)         \
                             || ((div) == PWM_16BIT)        \
                             || ((div) == PHASE_PWM_16BIT)  \
                             || ((div) == PHASEFREQ_PWM_16BIT))

/*!  PCA Channel */
typedef enum {
    PCA_CHANNEL_0      =    0,     /*!< PCA Channel 0 */
    PCA_CHANNEL_1      =    1,     /*!< PCA Channel 1 */
}PCA_CHANEEL_Type;

/*!  check PCA Channel */
#define IS_PCACHANEEL_CHANNEL(channel) (((channel) == PCA_CHANNEL_0) \
                                       || ((channel) == PCA_CHANNEL_1)) 

/*! @struct  PCA_CMD_TypeDef
  * @brief   structure for CMD register
  */ 
typedef struct
{
    uint32_t  ClkSel                   : 3;  /*!< CLOCK SELECT*/
    uint32_t  PCACounterMode           : 1;  /*!< counts up or  Counter middle alignment */
    uint32_t  OverFlowIntEN            : 1;  /*!< PCA overflow interrupt :SH_ENABLE or SH_DISABLE */
    uint32_t  Channel0DMAEN            : 1;  /*!< PCA channel 0 DMA : SH_ENABLE or SH_DISABLE */
    uint32_t  Channel1DMAEN            : 1;  /*!< PCA channel 1 DMA : SH_ENABLE or SH_DISABLE */
    uint32_t  PcaDmaEN                 : 1;  /*!< PCA DMA : SH_ENABLE or SH_DISABLE */
    uint32_t  rev1                     : 24; /*!< reserved*/
}PCA_CMD_TypeDef;


/*! @struct  PCA_CPM_TypeDef
  * @brief   structure for CPM register
  */ 
typedef struct
{
    uint32_t  COMPAREIntEN             : 1;  /*!< PCA Compare OR capture Interrupt :SH_ENABLE or SH_DISABLE*/
    uint32_t  Match                    : 1;  /*!< PCA matching control*/    
    uint32_t  PCA_TCP                  : 1;  /*!< PCA edge signale indicate*/    
    uint32_t  PCA_ECOM                 : 1;  /*!< Compare OR capture module function: SH_ENABLE or SH_DISABLE*/    
    uint32_t  FunctionSelect           : 2;  /*!< PCA secondary mode select*/    
    uint32_t  ModeSelect               : 2;  /*!< PCA mode select:CAPTUREMODE,TIMERMODE,FREQOUTPUTMODE,PWMMODE*/    
    uint32_t  rev2                     : 24; /*!< reserved*/    
}PCA_CPM_TypeDef;


/*! @struct  PCA_InitTypeDef
  * @brief   structure for PCA initial
  */ 
typedef struct
{   
    /* for CMD register */
    PCA_CMD_TypeDef PCA_CMD;

    /* for CPM0 register */
    PCA_CPM_TypeDef PCA_CPM0;

    /* for CPM1 register */
    PCA_CPM_TypeDef PCA_CPM1;

    /* for TOPR register */
    uint32_t  PCA_TOPR;
  
    /* for CPR0 register */        
    uint32_t PCA_CPR0;    

    /* for CPR1 register */  
    uint32_t PCA_CPR1;      

}PCA_InitTypeDef;


/**
  * @}
  */

  
/* Exported constants --------------------------------------------------------*/

/** @defgroup PCA_Exported_Constants
  * @{
  */ 
  
#define IS_PCA_ALL_PERIPH(PERIPH)  ((PERIPH == PCA0) || (PERIPH == PCA1) || (PERIPH == PCA2) || (PERIPH == PCA3) \
                                   || (PERIPH == PCA4) || (PERIPH == PCA5) || (PERIPH == PCA6) || (PERIPH == PCA7))

/** @defgroup PCA_Cascade
  * @{
  */    
  
#define IS_PCA_CASCADE_PERIPH(PERIPH)  ((PERIPH == PCA2) || (PERIPH == PCA4) || (PERIPH == PCA6))
/**
  * @}
  */ 


/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/ 

/*Fills each PCA_InitStruct member with its default value.*/
void PCA_StructInit(PCA_InitTypeDef *PCA_InitStruct);
    
/*Initializes the PCAx peripheral according to the specified parameters in the PCA_InitStruct*/
void PCA_Init(PCA_TypeDef *PCAx, const PCA_InitTypeDef *PCA_InitStruct);

/*Clear the PCA's pending flags*/
void PCA_ClearFlag(PCA_TypeDef *PCAx, uint16_t PCA_IntFlag);

/*Clear the PCAx's All pending flag*/
void PCA_ClearAllFlag(PCA_TypeDef *PCAx);

/*Open or close the PCA peripheral*/
void PCA_OnOff(PCA_TypeDef *PCAx, CmdState OnOffState);

/*Open or close the PCA cascade.*/
void PCA_CascadeOnOff(PCA_TypeDef *PCAx, CmdState OnOffState);

/*Set the PCAx Frequency output mode frequency value*/
void PCA_FreqOutValue(PCA_TypeDef *PCAx,PCA_CHANEEL_Type PCAChannel,uint8_t Value);

/*Set the PCAx pin level output control*/
void PCA_PinLevelOutControl(PCA_TypeDef *PCAx,PCA_CHANEEL_Type PCAChannel,LevelStatus levelstatus);

/*Set the PCAx Forced match control bit  */
void PCA_ForceMatchControl(PCA_TypeDef *PCAx,PCA_CHANEEL_Type PCAChannel,CmdState OnOffState);

/*Set the PCAx TOPR Register value*/
void PCA_SetTOPRValue(PCA_TypeDef *PCAx,uint32_t Value);

/*Set the PCAx CPR Register value*/
void PCA_SetCPRValue(PCA_TypeDef *PCAx,PCA_CHANEEL_Type PCAChannel,uint32_t Value);
    
/*Check whether the specified PCA flag is set or not*/
FlagStatus PCA_GetFlagStatus(PCA_TypeDef *PCAx,uint16_t PCA_IntFlag);

/*Get the PCAx CPR Register value*/
uint32_t PCA_GetCounter(PCA_TypeDef *PCAx,PCA_CHANEEL_Type PCAChannel);

/*Enable or disable the specified PCA's Overflow interrupts.*/
void PCA_INTConfig(PCA_TypeDef *PCAx, FunctionalState NewState);

/*Enable or disable the specified PCAx Capture's interrupts.*/
void PCA_CapINTConfig(PCA_TypeDef *PCAx, PCA_CHANEEL_Type PCAChannel, FunctionalState NewState);
    
/*Enable or disable the PCA's DMA request sources.*/
void PCA_DMAConfig(PCA_TypeDef *PCAx, uint32_t PCA_DMASource, FunctionalState NewState);

#ifdef __cplusplus
}
#endif

#endif /*__SH32F9XX_SB0_PCA_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */ 
/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/


