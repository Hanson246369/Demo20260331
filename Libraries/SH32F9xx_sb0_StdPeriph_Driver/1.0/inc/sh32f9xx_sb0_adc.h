/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_adc.h   
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
#ifndef __SH32F9XX_SB0_ADC_H
#define __SH32F9XX_SB0_ADC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/** @addtogroup ADC_MODULE
  * @{
  */ 

/** @defgroup ADC_Conversion_Mode
  * @{
  */
  
typedef enum {
    ADC_ConversionMode_Single          =    0,     /*!< Single sequence conversion */
    ADC_ConversionMode_Discontinuous   =    1,     /*!< Discontinuous sequence transformation */
    ADC_ConversionMode_Continuous      =    2,     /*!< Continuous sequence transformation */
}ADC_CONVERSION_Type;

/* check ADC Conversion Mode */
#define IS_ADC_CONVERSION_MODE(MODE)         ((MODE == ADC_ConversionMode_Single) \
                                             || (MODE == ADC_ConversionMode_Discontinuous) \
                                             || (MODE == ADC_ConversionMode_Continuous))  
                                             
/**
  * @}
  */

/** @defgroup ADC_Resolution
  * @{
  */

typedef enum {
    ADC_Resolution_12Bit     =    0,     /*!< 12bit */
    ADC_Resolution_10Bit     =    1,     /*!< 10bit */
}ADC_RESOLUTION_Type;

/* check ADC Resolution */
#define IS_ADC_RESOLUTION(RESOLUTION)     ((RESOLUTION == ADC_Resolution_12Bit) \
                                          || (RESOLUTION == ADC_Resolution_10Bit))  

/**
  * @}
  */



/** @defgroup ADC_Reference_Voltage_Sources
  * @{
  */

typedef enum {
    ADC_RefVoltage_AVDD         =    0,     /*!< Select AVDD as the reference voltage*/
    ADC_RefVoltage_ExtVref      =    1,     /*!< Select external VREF port input as reference voltage */
    ADC_RefVoltage_InterVref    =    2,     /*!< Select the built-in VREF as the reference voltage*/
}ADC_VREF_Type;

/* check ADC Reference Voltage */
#define IS_ADC_REF_VOLTAGE(VOLTAGE)          ((VOLTAGE == ADC_RefVoltage_AVDD) \
                                             || (VOLTAGE == ADC_RefVoltage_ExtVref) \
                                             || (VOLTAGE == ADC_RefVoltage_InterVref))  
  
/**
  * @}
  */


/** @defgroup ADC_Trigger
  * @{
  */
  
typedef enum {
    ADC_Trigger_Software   =    0,     /*!< Software startup      */
    ADC_Trigger_EXTI0      =    1,     /*!< External interrupt 0  */
    ADC_Trigger_EXTI1      =    2,     /*!< External interrupt 1  */
    ADC_Trigger_EXTI2      =    4,     /*!< External interrupt 2  */
    ADC_Trigger_TIMTRG     =    8,     /*!< Timer 7 overflow      */
    ADC_Trigger_PWM0TRG    =    16,    /*!< Pwm0 overflow         */
    ADC_Trigger_PWM1TRG    =    24,    /*!< Pwm1 overflow         */
    ADC_Trigger_PCA0       =    33,    /*!< Pca0 interrupt comparison trigger  */
    ADC_Trigger_PCA1       =    34,    /*!< PCa1 interrupt comparison trigger  */
    ADC_Trigger_PCA2       =    41,    /*!< Pca2 interrupt comparison trigger  */
    ADC_Trigger_PCA3       =    42,    /*!< PCA3 interrupt comparison trigger  */
    ADC_Trigger_PCA4       =    49,    /*!< Pca4 interrupt comparison trigger  */
    ADC_Trigger_PCA5       =    50,    /*!< Pca5 interrupt comparison trigger  */
    ADC_Trigger_PCA6       =    57,    /*!< Pca6 interrupt comparison trigger  */
    ADC_Trigger_PCA7       =    58,    /*!< Pca7 interrupt comparison trigger  */
}ADC_TRIGGER_Type;  

/* check ADC Trigger Source */
#define IS_ADC_TRIGGER(TRIGGER)             ((TRIGGER  == ADC_Trigger_Software)\
                                            ||(TRIGGER == ADC_Trigger_EXTI0   )\
                                            ||(TRIGGER == ADC_Trigger_EXTI1   )\
                                            ||(TRIGGER == ADC_Trigger_EXTI2   )\
                                            ||(TRIGGER == ADC_Trigger_TIMTRG  )\
                                            ||(TRIGGER == ADC_Trigger_PWM0TRG )\
                                            ||(TRIGGER == ADC_Trigger_PWM1TRG )\
                                            ||(TRIGGER == ADC_Trigger_PCA0    )\
                                            ||(TRIGGER == ADC_Trigger_PCA1    )\
                                            ||(TRIGGER == ADC_Trigger_PCA2    )\
                                            ||(TRIGGER == ADC_Trigger_PCA3    )\
                                            ||(TRIGGER == ADC_Trigger_PCA4    )\
                                            ||(TRIGGER == ADC_Trigger_PCA5    )\
                                            ||(TRIGGER == ADC_Trigger_PCA6    )\
                                            ||(TRIGGER == ADC_Trigger_PCA7    ))
                                            
/**
  * @}
  */

/** @defgroup ADC_Prescaler
  * @{
  */
typedef enum {
    ADC_Prescaler_1     =    0,     /*!< tAD = 0*tPCLK1 */
    ADC_Prescaler_2     =    1,     /*!< tAD = 1*tPCLK1 */
    ADC_Prescaler_3     =    2,     /*!< tAD = 2*tPCLK1 */
    ADC_Prescaler_4     =    3,     /*!< tAD = 3*tPCLK1 */
    ADC_Prescaler_5     =    4,     /*!< tAD = 4*tPCLK1 */
    ADC_Prescaler_6     =    5,     /*!< tAD = 5*tPCLK1 */
    ADC_Prescaler_8     =    6,     /*!< tAD = 6*tPCLK1 */
    ADC_Prescaler_12    =    7,     /*!< tAD = 7*tPCLK1 */
    ADC_Prescaler_16    =    8,     /*!< tAD = 8*tPCLK1 */
    ADC_Prescaler_24    =    9,     /*!< tAD = 9*tPCLK1 */
    ADC_Prescaler_32    =    10,    /*!< tAD = 10*tPCLK1 */
    ADC_Prescaler_48    =    11,    /*!< tAD = 11*tPCLK1 */
    ADC_Prescaler_64    =    12,    /*!< tAD = 12*tPCLK1 */
    ADC_Prescaler_128   =    13,    /*!< tAD = 13*tPCLK1 */
    ADC_Prescaler_256   =    14,    /*!< tAD = 14*tPCLK1 */
    ADC_Prescaler_320   =    15,    /*!< tAD = 15*tPCLK1 */
}ADC_CLKCYCLE_Type;

/* check ADC CLOCK */
#define IS_ADC_CLK_PRESCALER(DIV)       ((DIV == ADC_Prescaler_1)    \
                                        || (DIV == ADC_Prescaler_2)  \
                                        || (DIV == ADC_Prescaler_3)  \
                                        || (DIV == ADC_Prescaler_4)  \
                                        || (DIV == ADC_Prescaler_5)  \
                                        || (DIV == ADC_Prescaler_6)  \
                                        || (DIV == ADC_Prescaler_8)  \
                                        || (DIV == ADC_Prescaler_12) \
                                        || (DIV == ADC_Prescaler_16) \
                                        || (DIV == ADC_Prescaler_24) \
                                        || (DIV == ADC_Prescaler_32) \
                                        || (DIV == ADC_Prescaler_48) \
                                        || (DIV == ADC_Prescaler_64) \
                                        || (DIV == ADC_Prescaler_128) \
                                        || (DIV == ADC_Prescaler_256) \
                                        || (DIV == ADC_Prescaler_320)) 
  
/**
  * @}
  */

/** @defgroup ADC_Sample_Times
  * @{
  */
typedef enum {
    ADC_SampleTime_1Cycles    =    0,     /*!<  */
    ADC_SampleTime_2Cycles    =    1,     /*!<  */
    ADC_SampleTime_3Cycles    =    2,     /*!<  */
    ADC_SampleTime_4Cycles    =    3,     /*!<  */
    ADC_SampleTime_5Cycles    =    4,     /*!<  */
    ADC_SampleTime_6Cycles    =    5,     /*!<  */
    ADC_SampleTime_7Cycles    =    6,     /*!<  */
    ADC_SampleTime_8Cycles    =    7,     /*!<  */
    ADC_SampleTime_9Cycles    =    8,     /*!<  */
    ADC_SampleTime_10Cycles   =    9,     /*!<  */
    ADC_SampleTime_11Cycles   =    10,    /*!<  */
    ADC_SampleTime_12Cycles   =    11,    /*!<  */
    ADC_SampleTime_13Cycles   =    12,    /*!<  */
    ADC_SampleTime_14Cycles   =    13,    /*!<  */
    ADC_SampleTime_15Cycles   =    14,    /*!<  */
    ADC_SampleTime_16Cycles   =    15,    /*!<  */
}ADC_SAMPLE_TIME_Type;

/* check ADC Sampling time */
#define IS_ADC_SAMPLE_TIME(TIME)    ((TIME == ADC_SampleTime_1Cycles)   \
                                    || (TIME == ADC_SampleTime_2Cycles) \
                                    || (TIME == ADC_SampleTime_3Cycles) \
                                    || (TIME == ADC_SampleTime_4Cycles) \
                                    || (TIME == ADC_SampleTime_5Cycles) \
                                    || (TIME == ADC_SampleTime_6Cycles) \
                                    || (TIME == ADC_SampleTime_7Cycles) \
                                    || (TIME == ADC_SampleTime_8Cycles) \
                                    || (TIME == ADC_SampleTime_9Cycles) \
                                    || (TIME == ADC_SampleTime_10Cycles) \
                                    || (TIME == ADC_SampleTime_11Cycles) \
                                    || (TIME == ADC_SampleTime_12Cycles) \
                                    || (TIME == ADC_SampleTime_13Cycles) \
                                    || (TIME == ADC_SampleTime_14Cycles) \
                                    || (TIME == ADC_SampleTime_15Cycles) \
                                    || (TIME == ADC_SampleTime_16Cycles))  
  
/**
  * @}
  */

/** @defgroup ADC_Two_Sample_Gap
  * @{
  */

typedef enum {
    ADC_TwoSampleGap_0Cycles      =    0,     /*!< No wait time */
    ADC_TwoSampleGap_2Cycles      =    1,     /*!< 2 ADC Clock Cycle */
    ADC_TwoSampleGap_4Cycles      =    2,     /*!< 4 ADC clock cycle */
    ADC_TwoSampleGap_8Cycles      =    3,     /*!< 8 ADC clock cycle */
    ADC_TwoSampleGap_16Cycles     =    4,     /*!< 16 ADC clock cycle */
    ADC_TwoSampleGap_32Cycles     =    5,     /*!< 32 ADC clock cycle */
    ADC_TwoSampleGap_64Cycles     =    6,     /*!< 64 ADC clock cycle */
    ADC_TwoSampleGap_128Cycles    =    7,     /*!< 128 ADC clock cycle */
}ADC_TGAP_Type;

/* check ADC Time interval between adjacent channels in a sequence */
#define IS_ADC_TWO_SAMPLE_GAP(GAP)     ((GAP == ADC_TwoSampleGap_0Cycles)   \
                                       || (GAP == ADC_TwoSampleGap_2Cycles) \
                                       || (GAP == ADC_TwoSampleGap_4Cycles) \
                                       || (GAP == ADC_TwoSampleGap_8Cycles) \
                                       || (GAP == ADC_TwoSampleGap_16Cycles) \
                                       || (GAP == ADC_TwoSampleGap_32Cycles) \
                                       || (GAP == ADC_TwoSampleGap_64Cycles) \
                                       || (GAP == ADC_TwoSampleGap_128Cycles))

/**
  * @}
  */


/* Exported types ------------------------------------------------------------*/

/** @defgroup ADC_Exported_Types
  * @{
  */

typedef struct
{
    ADC_CONVERSION_Type ADC_ConversionMode; /* Configure the ADC conversion Mode
                                               This parameter can be a value of ADC_CONVERSION_Type */
    
    ADC_RESOLUTION_Type ADC_Resolution;     /* Configure the ADC_Resolution Mode
                                               This parameter can be a value of ADC_RESOLUTION_Type */
  
    ADC_VREF_Type ADC_RefVoltage;           /* Select the ADC reference voltage sources
                                               This parameter can be a value of ADC_VREF_Type */
                                          
    ADC_TRIGGER_Type ADC_Trigger;           /* Configure the ADC external trigger sources
                                               This parameter can be a value of ADC_TRIGGER_Type */

    ADC_CLKCYCLE_Type ADC_Prescaler;        /* Configure the ADC clock prescaler
                                               This parameter can be a value of ADC_CLKCYCLE_Type */
    
    uint32_t ADC_NumOfConversion;           /* Configure the ADC conversion channel numbers
                                               This parameter can be 1 to 8 */
                                          
    ADC_SAMPLE_TIME_Type ADC_SampleTime;    /* Configure the ADC sample time
                                               This parameter can be a value of ADC_Sample_Times */

    ADC_TGAP_Type ADC_TwoSampleGap;         /* Configure the ADC two sample gap time
                                               This parameter can be a value of ADC_TGAP_Type */
                                               
    uint32_t ADC_SequencePointer;           /* Set the ADC channel pointer to select which channel to be converted.
                                               This parameter can be a value of ADC_Channel_Pointer */
}ADC_InitTypeDef;

/** 
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup ADC_Exported_Constants
  * @{
  */ 

  

#define IS_ADC_ALL_PERIPH(PERIPH)         (PERIPH == ADC) 





/** @defgroup ADC_Conversion_Numbers
  * @{
  */
  
#define IS_ADC_CONVERSION_NUMBER(NUMBER)   ((NUMBER >= 0x01) && (NUMBER <= 0x08))  
  
/**
  * @}
  */

                                    
/** @defgroup ADC_Interrupt_Sources
  * @{
  */
  
#define ADC_INT_EOC                 (uint16_t)0x0040
#define ADC_INT_ADG                 (uint16_t)0x0480
#define ADC_INT_ADL                 (uint16_t)0x0420
#define IS_ADC_INT(INT)             (((INT & (uint16_t)0xFB1F) == 0x00) && (INT != 0x00))  
                                   
/**
  * @}
  */



/** @defgroup ADC_DMA_Request_Sources
  * @{
  */
  
#define ADC_DMA_EOC                  (uint16_t)0x0020
#define ADC_DMA_ADG                  (uint16_t)0x0440
#define ADC_DMA_ADL                  (uint16_t)0x0410
#define IS_ADC_DMA_SOURCE(SOURCE)    (((SOURCE & (uint16_t)0xFB8F) == 0x00) && (SOURCE != 0x00))
                                     
/**
  * @}
  */

                                     
/** @defgroup ADC_Flags
  * @{
  */
  
#define ADC_FLAG_EOC          (uint16_t)0x0004
#define ADC_FLAG_ADG          (uint16_t)0x0002
#define ADC_FLAG_ADL          (uint16_t)0x0001

#define IS_ADC_FLAG(FLAG)     (((FLAG & (uint16_t)0xFFF8) == 0x00) && (FLAG != 0x00))

#define IS_ADC_GET_ONE_FLAG(FLAG)   ((FLAG == ADC_FLAG_EOC) \
                                    || (FLAG == ADC_FLAG_ADG) \
                                    || (FLAG == ADC_FLAG_ADL))
                              
/**
  * @}
  */                                     



/** @defgroup ADC_Sample_Sequence
  * @{
  */

#define ADC_Sequence_0              (uint8_t)0x0C
#define ADC_Sequence_1              (uint8_t)0x10
#define ADC_Sequence_2              (uint8_t)0x14
#define ADC_Sequence_3              (uint8_t)0x18
#define ADC_Sequence_4              (uint8_t)0x1C
#define ADC_Sequence_5              (uint8_t)0x20
#define ADC_Sequence_6              (uint8_t)0x24
#define ADC_Sequence_7              (uint8_t)0x28
#define IS_ADC_SEQUENCE(SEQUENCE)   ((SEQUENCE == ADC_Sequence_0) \
                                    || (SEQUENCE == ADC_Sequence_1) \
                                    || (SEQUENCE == ADC_Sequence_2) \
                                    || (SEQUENCE == ADC_Sequence_3) \
                                    || (SEQUENCE == ADC_Sequence_4) \
                                    || (SEQUENCE == ADC_Sequence_5) \
                                    || (SEQUENCE == ADC_Sequence_6) \
                                    || (SEQUENCE == ADC_Sequence_7))

/**
  * @}
  */


/** @defgroup ADC_Two_Sample_Gap_Cmd
  * @{
  */
  
#define ADC_TwoSampleGap_Enable          (uint8_t)0x01
#define ADC_TwoSampleGap_Disable         (uint8_t)0x00
#define IS_ADC_TWO_SAMPLE_GAP_CMD(CMD)   ((CMD == ADC_TwoSampleGap_Enable) \
                                         || (CMD == ADC_TwoSampleGap_Disable))  
  
/**
  * @}
  */


                                    
                                    

/** @defgroup ADC_Channel
  * @{
  */

#define ADC_Channel_0                (uint8_t)0x00
#define ADC_Channel_1                (uint8_t)0x01
#define ADC_Channel_2                (uint8_t)0x02
#define ADC_Channel_3                (uint8_t)0x03
#define ADC_Channel_4                (uint8_t)0x04
#define ADC_Channel_5                (uint8_t)0x05
#define ADC_Channel_6                (uint8_t)0x06
#define ADC_Channel_7                (uint8_t)0x07
#define ADC_Channel_8                (uint8_t)0x08
#define ADC_Channel_9                (uint8_t)0x09
#define ADC_Channel_10               (uint8_t)0x0A
#define ADC_Channel_11               (uint8_t)0x0B
#define ADC_Channel_12               (uint8_t)0x0C
#define ADC_Channel_13               (uint8_t)0x0D
#define ADC_Channel_14               (uint8_t)0x0E
#define ADC_Channel_15               (uint8_t)0x0F
#define ADC_Channel_16               (uint8_t)0x10
#define ADC_Channel_17               (uint8_t)0x11
#define ADC_Channel_18               (uint8_t)0x12
#define ADC_Channel_19               (uint8_t)0x13
#define ADC_Channel_20               (uint8_t)0x14
#define ADC_Channel_21               (uint8_t)0x15
#define ADC_Channel_22               (uint8_t)0x16
#define ADC_Channel_23               (uint8_t)0x17
#define ADC_Channel_24               (uint8_t)0x18
#define ADC_Channel_TPS              (uint8_t)0x19

#define IS_ADC_CHANNEL(CHANNEL)     ((CHANNEL == ADC_Channel_0)    \
                                    || (CHANNEL == ADC_Channel_1)  \
                                    || (CHANNEL == ADC_Channel_2)  \
                                    || (CHANNEL == ADC_Channel_3)  \
                                    || (CHANNEL == ADC_Channel_4)  \
                                    || (CHANNEL == ADC_Channel_5)  \
                                    || (CHANNEL == ADC_Channel_6)  \
                                    || (CHANNEL == ADC_Channel_7)  \
                                    || (CHANNEL == ADC_Channel_8)  \
                                    || (CHANNEL == ADC_Channel_9)  \
                                    || (CHANNEL == ADC_Channel_10) \
                                    || (CHANNEL == ADC_Channel_11) \
                                    || (CHANNEL == ADC_Channel_12) \
                                    || (CHANNEL == ADC_Channel_13) \
                                    || (CHANNEL == ADC_Channel_14) \
                                    || (CHANNEL == ADC_Channel_15) \
                                    || (CHANNEL == ADC_Channel_16) \
                                    || (CHANNEL == ADC_Channel_17) \
                                    || (CHANNEL == ADC_Channel_18) \
                                    || (CHANNEL == ADC_Channel_19) \
                                    || (CHANNEL == ADC_Channel_20) \
                                    || (CHANNEL == ADC_Channel_21) \
                                    || (CHANNEL == ADC_Channel_22) \
                                    || (CHANNEL == ADC_Channel_23) \
                                    || (CHANNEL == ADC_Channel_24) \
                                    || (CHANNEL == ADC_Channel_TPS))
 
/**
  * @}
  */


/**
  * @}
  */ 


/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/ 

/** @defgroup ADC_Exported_Functions
  * @{
  */

/*Reset the ADC peripherals registers to their default reset values.*/  
void ADC_Reset( void );

/*Fills each ADC_InitStruct member with its default value.*/  
void ADC_StructInit(ADC_InitTypeDef *ADC_InitStruct);

/*Initializes the ADCx peripheral according to the specified parameters in the ADC_InitStruct.*/  
void ADC_Init(ADC_TypeDef *ADCx, ADC_InitTypeDef *ADC_InitStruct);

/*Open or close the specified ADC peripheral.*/  
void ADC_OnOff(ADC_TypeDef *ADCx, CmdState OnOffState);

/*Start conversion of the specified ADC peripheral.*/  
void ADC_SoftwareStartConversion(ADC_TypeDef *ADCx);

/*Stop conversion of the specified ADC peripheral.*/  
void ADC_SoftwareStopConversion(ADC_TypeDef *ADCx);

/*Get start conversion of the specified ADC peripheral.*/  
uint8_t ADC_GetSoftwareStartConversionStatus(ADC_TypeDef *ADCx);

/*Configure the selected ADC channel for its sample sequence and whether enable or disable two sample gap function.*/  
void ADC_ChannelConfig(ADC_TypeDef *ADCx, uint8_t ADC_Channel, uint8_t ADC_Sequence, uint8_t ADC_TwoSampleGapCmd);

/*Configure external peripherals trigger ADC start to convert.*/  
void ADC_ExternalTriggerConfig(ADC_TypeDef *ADCx, ADC_TRIGGER_Type ADC_Trigger);

/*Enable or disable the specified ADC interrupts.*/  
void ADC_INTConfig(ADC_TypeDef *ADCx, uint16_t ADC_INT, FunctionalState NewState);

/*Enable or disable the specified ADC DMA requests.*/  
void ADC_DMAConfig(ADC_TypeDef *ADCx, uint16_t ADC_DMASource, FunctionalState NewState);

/*Get the specified ADC's channel data.*/  
uint16_t ADC_GetConversionValue(ADC_TypeDef *ADCx, uint8_t ADC_Sequence);

/*Compare the ADC conversion value with the Max and Min data set in registers.*/  
void ADC_SequenceResultCompareConfig(ADC_TypeDef *ADCx, uint16_t ADC_UpLimit, uint16_t ADC_LowerLimit, uint8_t ADC_Sequence);

/*Check whether the specified ADC flag is set or not.*/  
FlagStatus ADC_GetFlagStatus(ADC_TypeDef *ADCx, uint16_t ADC_Flag);

/*Clear the ADC's pending flags.*/  
void ADC_ClearFlag(ADC_TypeDef *ADCx, uint16_t ADC_Flag);

/*Enables or disables the selected ADC software start conversion.*/  
void ADC_TriggerDMAEnable(FunctionalState NewState);
  
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /*__SH32F9XX_SB0_ADC_H */

/**
  * @}
  */ 

/**
  * @}
  */ 


/************************ (C) COPYRIGHT Sinowealth *****END OF FILE****/
