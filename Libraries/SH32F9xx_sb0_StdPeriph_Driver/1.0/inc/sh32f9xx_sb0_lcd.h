/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_lcd.h
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file provide LCD module's APIs
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
#ifndef __SH32F9XX_SB0_LCD_H
#define __SH32F9XX_SB0_LCD_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/**emum LCD_CR_CLKSEL_Type
  *@brief LCD clock select;
  */
    typedef enum
    {
        LCD_CLKSEL_LSI = 0, /*!< clock LSI >*/
        LCD_CLKSEL_LSE = 1, /*!< clock select lse 32.768Khz Crystal >*/
    } LCD_CR_CLKSEL_Type;

/**emum LCD_CR_CLKSEL_Type
  *@brief LCD duty select;
  */
    typedef enum
    {
        LCD_DUTY_SEL0 = 0, /*!< 1/4 duty,1/3 bias (4 COM X 40 SEG) >*/
        LCD_DUTY_SEL1 = 1, /*!< 1/8 duty,1/4 bias (8 COM X 36 SEG) >*/
        LCD_DUTY_SEL2 = 2, /*!< 1/4 duty,1/3 bias (4 COM X 40 SEG) >*/
        LCD_DUTY_SEL3 = 3, /*!< 1/5 duty,1/3 bias (5 COM X 39 SEG) >*/
        LCD_DUTY_SEL4 = 4, /*!< 1/6 duty,1/3 bias (6 COM X 38 SEG) >*/
        LCD_DUTY_SEL5 = 5, /*!< 1/6 duty,1/4 bias (6 COM X 39 SEG) >*/
        LCD_DUTY_SEL6 = 6, /*!< 1/4 duty,1/3 bias (4 COM X 40 SEG) >*/
    } LCD_CR_DUTYSEL_Type;

 /**emum LCD_CR_VOLSEL_Type
   *@brief LCD voltage select;
   */
    typedef enum
    {
        LCD_VOLSEL_0531VDD = 0,  /*!< VLCD = 0.531VDD >*/
        LCD_VOLSEL_0563VDD = 1,  /*!< VLCD = 0.563VDD >*/
        LCD_VOLSEL_0594VDD = 2,  /*!< VLCD = 0.594VDD >*/
        LCD_VOLSEL_0625VDD = 3,  /*!< VLCD = 0.625VDD >*/
        LCD_VOLSEL_0656VDD = 4,  /*!< VLCD = 0.656VDD >*/
        LCD_VOLSEL_0688VDD = 5,  /*!< VLCD = 0.688VDD >*/
        LCD_VOLSEL_0719VDD = 6,  /*!< VLCD = 0.719VDD >*/
        LCD_VOLSEL_0750VDD = 7,  /*!< VLCD = 0.750VDD >*/
        LCD_VOLSEL_0781VDD = 8,  /*!< VLCD = 0.781VDD >*/
        LCD_VOLSEL_0813VDD = 9,  /*!< VLCD = 0.813VDD >*/
        LCD_VOLSEL_0844VDD = 10, /*!< VLCD = 0.844VDD >*/
        LCD_VOLSEL_0875VDD = 11, /*!< VLCD = 0.875VDD >*/
        LCD_VOLSEL_0906VDD = 12, /*!< VLCD = 0.906VDD >*/
        LCD_VOLSEL_0938VDD = 13, /*!< VLCD = 0.938VDD >*/
        LCD_VOLSEL_0969VDD = 14, /*!< VLCD = 0.969VDD >*/
        LCD_VOLSEL_1000VDD = 15, /*!< VLCD = 1.000VDD >*/
    } LCD_CR_VOLSEL_Type;

/**emum LCD_CR_PORT_SET_TypeDef
  *@brief  define the LCD port set
  */
    typedef enum
    {
        LCD_SHARE_SELECT = 0, /*!< LCD port control avail >*/
        LCD_SET_IO = 1,       /*!< LCD set as IO >*/
    } LCD_CR_PORT_SET_TypeDef;

/**emum LCD_CR_BIASRES_SET_TypeDef
  *@brief  define the LCD bias resistance select
  */
    typedef enum
    {
        LCD_BIASRES_900K  = 0, /*!< LCD bias resistance 900K >*/
        LCD_BIASRES_1500K = 1, /*!< LCD bias resistance 1500K >*/
    } LCD_CR_BIASRES_SET_TypeDef;

/**emum LCD_CR_DRVMOD_SEL_TypeDef
  *@brief  define the LCD driver mode select
  */
    typedef enum
    {
        LCD_DRVMOD_900K_1500K = 0, /*!< LCD tradition mode ,bias resistance 900K/1.5M >*/
        LCD_DRVMOD_60K = 1,        /*!< LCD tradition mode ,bias resistance 60K >*/
        LCD_DRVMOD_MID = 2,        /*!< LCD fasht charge mode ,bias resistance between 900K and 1.5M >*/
        LCD_DRVMOD_NOSENSE = 3,    /*!< no sense >*/
    } LCD_CR_DRVMOD_SEL_TypeDef;

/**emum LCD_CR_CHARGETIM_CTR_TypeDef
  *@brief  define the LCD charge time control
  */
    typedef enum
    {
        LCD_CHARGE_TIM_8  = 0, /*!< LCD charge time 1/8 LCD com period >*/
        LCD_CHARGE_TIM_16 = 1, /*!< LCD charge time 1/16 LCD com period >*/
        LCD_CHARGE_TIM_32 = 2, /*!< LCD charge time 1/32 LCD com period >*/
        LCD_CHARGE_TIM_64 = 3, /*!< LCD charge time 1/64 LCD com period >*/
    } LCD_CR_CHARGETIM_CTR_TypeDef;

/**emum LCD_CR_SCANFCONT_MODCTR_TypeDef
  *@brief  define the LCD scanf counter mode control
  */
    typedef enum
    {
        LCD_SCANFCONT_MODCTR_CONT = 0, /*!< LCD MODSW=1, scanf counter continue >*/
        LCD_SCANFCONT_MODCTR_STOP = 1, /*!< LCD MODSW=1, scanf counter stop >*/
    } LCD_CR_SCANFCONT_MODCTR_TypeDef;

/**emum LCD_CR_LSI_CLKSEL_TypeDef
  *@brief  define the LCD LSI as clock source, clock select.
  */
    typedef enum
    {
        LCD_LSI_CLKSEL_4 = 0, /*!< APB1 1/4  >*/
        LCD_LSI_CLKSEL_3 = 1, /*!< APB1 1/3  >*/
        LCD_LSI_CLKSEL_2 = 2, /*!< APB1 1/2  >*/
        LCD_LSI_CLKSEL_1 = 3, /*!< APB1 1/1  >*/
    } LCD_CR_LSI_CLKSEL_TypeDef;

/** 
  * @brief  LCD com mode seclet  
  */
    typedef enum
    {
        LCD_SEC_COM_NOP = 0x00,
        LCD_SEC_COM1 = 0x01,
        LCD_SEC_COM2 = 0x02,
        LCD_SEC_COM3 = 0x04,
        LCD_SEC_COM4 = 0x08,
        LCD_SEC_COM5 = 0x10,
        LCD_SEC_COM6 = 0x20,
        LCD_SEC_COM7 = 0x40,
        LCD_SEC_COM8 = 0x80,
        LCD_SEC_COM_ALL = 0xFF,
    } LCDSECCOM_TypeDef;

/** 
  * @brief  LED SEG1 mode seclet  
  */
    typedef enum
    {
        LCD_SEC_SEG_NOP1 = 0x00,
        LCD_SEC_SEG1 = 0x01,
        LCD_SEC_SEG2 = 0x02,
        LCD_SEC_SEG3 = 0x04,
        LCD_SEC_SEG4 = 0x08,
        LCD_SEC_SEG5 = 0x10,
        LCD_SEC_SEG6 = 0x20,
        LCD_SEC_SEG7 = 0x40,
        LCD_SEC_SEG8 = 0x80,
        LCD_SEC_SEG_ALL1 = 0xFF,
    } LCDSECSEG1_TypeDef;

/** 
  * @brief  LED SEG2 mode seclet  
  */
    typedef enum
    {
        LCD_SEC_SEG_NOP2 = 0x00,
        LCD_SEC_SEG9 = 0x01,
        LCD_SEC_SEG10 = 0x02,
        LCD_SEC_SEG11 = 0x04,
        LCD_SEC_SEG12 = 0x08,
        LCD_SEC_SEG13 = 0x10,
        LCD_SEC_SEG14 = 0x20,
        LCD_SEC_SEG15 = 0x40,
        LCD_SEC_SEG16 = 0x80,
        LCD_SEC_SEG_ALL2 = 0xFF,
    } LCDSECSEG2_TypeDef;

/** 
  * @brief  LED SEG3 mode seclet  
  */
    typedef enum
    {
        LCD_SEC_SEG_NOP3 = 0x00,
        LCD_SEC_SEG17 = 0x01,
        LCD_SEC_SEG18 = 0x02,
        LCD_SEC_SEG19 = 0x04,
        LCD_SEC_SEG20 = 0x08,
        LCD_SEC_SEG21 = 0x10,
        LCD_SEC_SEG22 = 0x20,
        LCD_SEC_SEG23 = 0x40,
        LCD_SEC_SEG24 = 0x80,
        LCD_SEC_SEG_ALL3 = 0xFF,
    } LCDSECSEG3_TypeDef;

/** 
  * @brief  LED SEG4 mode seclet  
  */
    typedef enum
    {
        LCD_SEC_SEG_NOP4 = 0x00,
        LCD_SEC_SEG25 = 0x01,
        LCD_SEC_SEG26 = 0x02,
        LCD_SEC_SEG27 = 0x04,
        LCD_SEC_SEG28 = 0x08,
        LCD_SEC_SEG29 = 0x10,
        LCD_SEC_SEG30 = 0x20,
        LCD_SEC_SEG31 = 0x40,
        LCD_SEC_SEG32 = 0x80,
        LCD_SEC_SEG_ALL4 = 0xFF,
    } LCDSECSEG4_TypeDef;

/** 
  * @brief  LED SEG5 mode seclet  
  */
    typedef enum
    {
        LCD_SEC_SEG_NOP5 = 0x00,
        LCD_SEC_SEG33 = 0x01,
        LCD_SEC_SEG34 = 0x02,
        LCD_SEC_SEG35 = 0x04,
        LCD_SEC_SEG36 = 0x08,
        LCD_SEC_SEG_ALL5 = 0x0F,
    } LCDSECSEG5_TypeDef;

/*! @struct  LCD_InitTypeDef
  * @brief structure for LCD initial
  */
    typedef struct
    {   /* for CR register */
        uint32_t LcdEN          : 1;  /*!< LCD driver : SH_ON or SH_OFF */
        uint32_t ClockSel       : 1;  /*!< select clock :    0: LSI  1: 32.768kHZ Crystal*/
        uint32_t Duty           : 3;  /*!< DUTY*/
        uint32_t VolSel         : 4;  /*!< LCD voltage select*/
        uint32_t ContrastEn     : 1;  /*!< LCD Contrast :SH_ON or SH_OFF*/
        uint32_t LcdPortSel     : 1;  /*LCD PORT SH_SET */
        uint32_t BiasResistance : 1;  /*LCD BIAS RESISTANCE*/
        uint32_t LcdDriverMode  : 2;  /*LCD driver mode*/
        uint32_t ChargeTime     : 2;  /*LCD charge time*/
        uint32_t ScanfCounter   : 1;  /*LCD SCAN conunter control*/
        uint32_t ClockDIV       : 2;  /*LCD clock division*/
        uint32_t rev0           : 13; /*!< reserved*/

        /* for LCDSHARE register */
        uint32_t LcdCOM         : 8;  /*!< LCD COM MODE SELECT */
        uint32_t LcdSEG1        : 8;  /*!< LCD SEG MODE SELECT*/
        uint32_t LcdSEG2        : 8;  /*!< LCD SEG MODE SELECT*/
        uint32_t LcdSEG3        : 8;  /*!< LCD SEG MODE SELECT*/

        /* for LCDSHARE1 register */
        uint32_t LcdSEG4        : 8;  /*!< LCD SEG MODE SELECT*/
        uint32_t LcdSEG5        : 4;  /*!< LCD SEG MODE SELECT*/
        uint32_t rev1           : 20; /*!< reserved*/

    } LCD_InitTypeDef;

/**
  * @}
  */

    /* Fills each LCD_InitStruct member with its default value */
    void LCD_StructInit(LCD_InitTypeDef *LCD_InitStruct);

    /* LCD driver mould Initial function */
    void LCD_Init(LCD_TypeDef *LCD_MOULD, const LCD_InitTypeDef *InitCfg);

    /* LCD driver mould SH_ENABLE */
    void LCD_OnOff(CmdState OnOffState);

/*! check LCD module pointer */
#define IS_LCD_MODULE(m) (m == LCD)

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /*__SH32F9XX_SB0_LCD_H */

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
