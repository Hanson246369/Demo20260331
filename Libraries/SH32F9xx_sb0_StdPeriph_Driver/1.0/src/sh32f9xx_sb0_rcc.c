/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_rcc.c
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-09-21  
  * @brief   This file provides reset and clock module's APIs
  *         
  *  @verbatim
  *
  *          ===================================================================
  *                                   How to use this driver
  *          ===================================================================
  *          
  *
  *  @endverbatim
  *
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
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_rcc.h"
#include "system_sh32f9xx_sb0.h"

/** @addtogroup SH32F9xx_sb0_StdLib_Driver
  * @{
  */

/**
  ******************************************************************************
  * @function  RCC_GetClocksFreq
  * @brief     Returns the frequencies of different on chip clocks.
  * @version   V1.1.0
  * @date      19-December-2019
  * @param     Clocks: pointer to a RCC_Clocks_TypeDef structure which will hold
  *            the clocks frequencies.
  * @retval    None
  ******************************************************************************
  */
void RCC_GetClocksFreq(RCC_Clocks_TypeDef *Clocks)
{
    uint8_t tmp = 0;
    uint8_t pllmul_k = 0;
    uint8_t pllmul_f = 0;
    uint8_t pllxtpre = 0;
    uint8_t pllsrc   = 0;
    uint8_t hpre_div = 0;
    uint32_t sysClk  = 0;

    /* Get SYSCLK source -------------------------------------------------------*/
    tmp = RCC->CR.BIT.SWS;
    hpre_div = RCC->CFGR.BIT.HPRE;

    switch (tmp)
    {
    case 0x00: /* HSI used as system clock */
        sysClk = HSI_VALUE;
        break;
    case 0x01: /* PLL used as system clock */
        pllsrc   = RCC->CFGR.BIT.PLLSRC;
        pllmul_f = RCC->CFGR.BIT.PLLF + 15;
        pllmul_k = RCC->CFGR.BIT.PLLK + 1;
        pllxtpre = RCC->CFGR.BIT.PLLXTPRE + 1;
        if (pllsrc) //HSE as PLL Clock input
        {
            sysClk = HSE_VALUE / pllxtpre * pllmul_f / pllmul_k / 2;
        }
        else //HSI as PLL Clock input
        {
            sysClk = HSI_VALUE / pllxtpre * pllmul_f / pllmul_k / 2;
        }
        break;
    case 0x02: /* LSE used as system clock */
        sysClk = LSE_VALUE;
        break;
    case 0x03: /* HSE used as system clock */
        sysClk = HSE_VALUE;
        break;
    case 0x04: /* LSI used as system clock */
        sysClk = LSI_VALUE;
        break;
    }

    Clocks->sysFreq = sysClk;

    //Calculate HCLK
    switch (hpre_div)
    {
    case 0:
        Clocks->hclkFreq = sysClk;
        break;
    case 1:
        Clocks->hclkFreq = sysClk / 2;
        break;
    case 2:
        Clocks->hclkFreq = sysClk / 4;
        break;
    case 3:
        Clocks->hclkFreq = sysClk / 8;
        break;
    case 4:
        Clocks->hclkFreq = sysClk / 16;
        break;
    case 5:
        Clocks->hclkFreq = sysClk / 32;
        break;
    default:
        Clocks->hclkFreq = sysClk / 32;
        break;
    }

    /*Calculate PCLK0 PCLK1*/
    Clocks->pclk0Freq = Clocks->hclkFreq >> (RCC->CFGR.BIT.PPRE0 > 4 ? 4 : (RCC->CFGR.BIT.PPRE0));
    Clocks->pclk1Freq = Clocks->hclkFreq >> (RCC->CFGR.BIT.PPRE1 > 4 ? 4 : (RCC->CFGR.BIT.PPRE1));
}

/**
  * @code   Example : open GPIO and CRC module's clock
        RCC_AHBPeriphClockOnOff(RCC_AHB_IOCLK | RCC_AHB_CRC, SH_ON);
  * @endcode 
  */
/**
  * @brief     open or close AHB modules' clock gate
  * @param  AHBModules:  AHB module bits @ref RCC_AHB_Type
  *   This parameter can be any combination of following values:
  *     @arg @b  RCC_AHB_IOCLK:    for GPIO Module: Includes Config and IO
  *     @arg @b  RCC_AHB_CRC:      for CRC Module
  *     @arg @b  RCC_AHB_RAMBIST:  for RAMBIST Module
  *     @arg @b  RCC_AHB_SYSCFG:   for System Config Module
  *     @arg @b  RCC_AHB_DMA:      for DMA Module
  *     @arg @b  RCC_AHB_PCA0:     for PCA0 Module
  *     @arg @b  RCC_AHB_PCA1:     for PCA1 Module
  *     @arg @b  RCC_AHB_PCA:      for all PCA Module
  * @param OnOffState  open or close related clock gate
  *     @arg @b  SH_ON  open related clock gate
  *     @arg @b  SH_OFF  close related clock gate
  *     @retval   None
   */
void RCC_AHBPeriphClockOnOff(RCC_AHB_Type AHBModules, CmdState OnOffState)
{
    assert_param(IS_AHB_MODULES(AHBModules));
    assert_param(IS_CMD_STATE(OnOffState));

    /* Unlock RCC registers */
    RCC_REGS_UNLOCK();

    if (OnOffState == SH_ON)
    {
        RCC->AHBENR.V32 |= AHBModules;
    }
    else
    {
        RCC->AHBENR.V32 &= ~AHBModules;
    }

    /* Lock RCC registers */
    RCC_REGS_LOCK();
}

/**
  * @brief  open or close APB1 modules' clock gate
  * @param  APB1Modules:  APB1 module bits @ref RCC_APB1_Type
  *   This parameter can be any combination of following values:
  *     @arg @b RCC_APB1_UART0: for UART0 Module
  *     @arg @b RCC_APB1_UART1: for UART1 Module 
  *     @arg @b RCC_APB1_UART2: for UART2 Module 
  *     @arg @b RCC_APB1_UART3: for UART3 Module
  *     @arg @b RCC_APB1_UART4: for UART4 Module
  *     @arg @b RCC_APB1_UART5: for UART5 Module
  *     @arg @b RCC_APB1_SPI0:  for SPI0  Module
  *     @arg @b RCC_APB1_SPI1:  for SPI1 Module
  *     @arg @b RCC_APB1_TWI0:  for TWI0 Module
  *     @arg @b RCC_APB1_TWI1:  for TWI1 Module
  *     @arg @b RCC_APB1_AMOC:  for AMOC Module
  *     @arg @b RCC_APB1_ADC:   for ADC Module
  *     @arg @b RCC_APB1_LCD:   for LCD Module
  *     @arg @b RCC_APB1_LED:   for LED Module
  *     @arg @b RCC_APB1_TK:    for TouchKey Module
  * @param OnOffState  open or close related clock gate
  *     @arg @b  SH_ON  open related clock gate
  *     @arg @b  SH_OFF  close related clock gate
  *     @retval  None
  */
void RCC_APB1PeriphClockOnOff(RCC_APB1_Type APB1Modules, CmdState OnOffState)
{
    assert_param(IS_APB1_MODULES(APB1Modules));
    assert_param(IS_CMD_STATE(OnOffState));

    /* Unlock RCC registers */
    RCC_REGS_UNLOCK();

    if (OnOffState == SH_ON)
    {
        RCC->APB1ENR.V32 |= APB1Modules;
    }
    else
    {
        RCC->APB1ENR.V32 &= ~APB1Modules;
    }

    /* Lock RCC registers */
    RCC_REGS_LOCK();
}

/**
  * @brief      open or close APB0 modules' clock gate
  * @param  APB0Modules:  APB0 module bits @ref RCC_APB0_Type
  *   This parameter can be any combination of following values:
  *     @arg @b    RCC_APB0_TIM5: for TIM5 Module
  *     @arg @b    RCC_APB0_TIM6: for TIM6 Module
  *     @arg @b    RCC_APB0_TIM7: for TIM7 Module
  *     @arg @b    RCC_APB0_TIM8: for TIM8 Module
  *     @arg @b    RCC_APB0_PWM0: for PWM0 Module
  *     @arg @b    RCC_APB0_PWM1: for PWM1 Module
  *     @arg @b    RCC_APB0_PWM2: for PWM2 Module
  *     @arg @b    RCC_APB0_PWM3: for PWM3 Module
  *     @arg @b    RCC_APB0_PCA2: for PCA2 Module
  *     @arg @b    RCC_APB0_PCA3: for PCA3 Module
  *     @arg @b    RCC_APB0_PCA4: for PCA4 Module
  *     @arg @b    RCC_APB0_PCA5: for PCA5 Module
  *     @arg @b    RCC_APB0_PCA6: for PCA6 Module
  *     @arg @b    RCC_APB0_PCA7: for PCA7 Module
  *     @arg @b    RCC_APB0_EXTI: for EXTI Module
  *     @arg @b    RCC_APB0_IWDT: for IWDT Module
  *     @arg @b    RCC_APB0_WWDT: for WWDT Module
  * @param OnOffState  open or close related clock gate
  *     @arg @b  SH_ON  open related clock gate
  *     @arg @b  SH_OFF  close related clock gate
  * @retval None
  */
void RCC_APB0PeriphClockOnOff(RCC_APB0_Type APB0Modules, CmdState OnOffState)
{
    assert_param(IS_APB0_MODULES(APB0Modules));
    assert_param(IS_CMD_STATE(OnOffState));

    /* Unlock RCC registers */
    RCC_REGS_UNLOCK();

    if (OnOffState == SH_ON)
    {
        RCC->APB0ENR.V32 |= APB0Modules;
    }
    else
    {
        RCC->APB0ENR.V32 &= ~APB0Modules;
    }

    /* Lock RCC registers */
    RCC_REGS_LOCK();
}

/**
  * @code   Example : reset GPIO and CRC module
        RCC_AHBPeriphReset(RCC_AHB_IOCLK|RCC_AHB_CRC);
  * @endcode 
  */
/**
  * @brief     reset AHB modules
  * @param  AHBModules: AHB module bits @ref RCC_AHB_Type
  *   This parameter can be any combination of following values:
  *     @arg @b  RCC_AHB_IOCLK:  for GPIO Module
  *     @arg @b  RCC_AHB_CRC:  for CRC Module
  *     @arg @b  RCC_AHB_RAMBIST:  for RAMBIST Module
  *     @arg @b  RCC_AHB_SYSCFG: for System Config Module
  *     @arg @b  RCC_AHB_DMA:  for DMA Module
  *     @arg @b  RCC_AHB_PCA0:  for PCA0 Module
  *     @arg @b  RCC_AHB_PCA1: for PCA1 Module
  *     @arg @b  RCC_AHB_PCA:  for all PCA Module
  * @retval   None
   */
void RCC_AHBPeriphReset(uint32_t AHBModules)
{
    assert_param(IS_AHB_MODULES(AHBModules));

    /* Unlock RCC registers */
    RCC_REGS_UNLOCK();

    RCC->AHBRSTR.V32 = AHBModules;

    /* Lock RCC registers */
    RCC_REGS_LOCK();
}

/**
  * @brief    reset APB0 modules
  * @param  APB0Modules:  APB0 module bits @ref RCC_APB0_Type
  *   This parameter can be any combination of following values:
  *     @arg @b  RCC_APB0_TIM5
  *     @arg @b  RCC_APB0_TIM6
  *     @arg @b  RCC_APB0_TIM7
  *     @arg @b  RCC_APB0_TIM8
  *     @arg @b  RCC_APB0_PWM0
  *     @arg @b  RCC_APB0_PWM1
  *     @arg @b  RCC_APB0_PWM2
  *     @arg @b  RCC_APB0_PWM3
  *     @arg @b  RCC_APB0_PCA2
  *     @arg @b  RCC_APB0_PCA3
  *     @arg @b  RCC_APB0_PCA4
  *     @arg @b  RCC_APB0_PCA5
  *     @arg @b  RCC_APB0_PCA6
  *     @arg @b  RCC_APB0_PCA7
  *     @arg @b  RCC_APB0_EXTI
  *     @arg @b  RCC_APB0_IWDT
  *     @arg @b  RCC_APB0_WWDT
  * @retval  None
  */
void RCC_APB0PeriphReset(uint32_t APB0Modules)
{
    assert_param(IS_APB0_MODULES(APB0Modules));

    /* Unlock RCC registers */
    RCC_REGS_UNLOCK();

    RCC->APB0RSTR.V32 = APB0Modules;

    /* Lock RCC registers */
    RCC_REGS_LOCK();
}

/**
  * @brief     reset APB1 modules
  * @param  APB1Modules:  APB1 module bits @ref RCC_APB1_Type
  *   This parameter can be any combination of following values:
  *     @arg @b RCC_APB1_UART0: for UART0 Module
  *     @arg @b RCC_APB1_UART1: for UART1 Module 
  *     @arg @b RCC_APB1_UART2: for UART2 Module 
  *     @arg @b RCC_APB1_UART3: for UART3 Module
  *     @arg @b RCC_APB1_UART4: for UART4 Module
  *     @arg @b RCC_APB1_UART5: for UART5 Module
  *     @arg @b RCC_APB1_SPI0:  for SPI0  Module
  *     @arg @b RCC_APB1_SPI1:  for SPI1  Module
  *     @arg @b RCC_APB1_TWI0:  for TWI0  Module
  *     @arg @b RCC_APB1_TWI1:  for TWI1  Module
  *     @arg @b RCC_APB1_AMOC:  for AMOC  Module
  *     @arg @b RCC_APB1_ADC:   for ADC   Module
  *     @arg @b RCC_APB1_LCD:   for LCD   Module
  *     @arg @b RCC_APB1_LED:   for LED   Module
  *     @arg @b RCC_APB1_TK:    for TouchKey Module
  * @retval None
  */
void RCC_APB1PeriphReset(uint32_t APB1Modules)
{
    assert_param(IS_APB1_MODULES(APB1Modules));

    /* Unlock RCC registers */
    RCC_REGS_UNLOCK();

    RCC->APB1RSTR.V32 = APB1Modules;

    /* Lock RCC registers */
    RCC_REGS_LOCK();
}

/**
  * @brief     Get RCC reset flag
  * @param  ResetFlag:   RCC reset flag mask
  *     @arg @b  RCC_RST_PIN
  *     @arg @b  RCC_RST_LVR
  *     @arg @b  RCC_RST_POWERON
  *     @arg @b  RCC_RST_SOFTWARE
  *     @arg @b  RCC_RST_IWDT
  *     @arg @b  RCC_RST_WWDT
  *     @arg @b  RCC_RST_VCCLVR
  * @retval  FlagStatus RCC reset flag
  *     @arg @b  SH_SET    the flag is setted
  *     @arg @b  RESET  the flag is cleared
  */
FlagStatus RCC_GetResetFlag(RCC_RESET_Type ResetFlag)
{
    assert_param(IS_RST_MODULES(ResetFlag));

    return ((RCC->RSTSTR.V32 & ResetFlag) ? SH_SET : SH_RESET);
}

/**
  * @brief      clear RCC reset flags
  * @param  ResetFlags:   RCC reset flag clear bits
  *     @arg @b  RCC_RST_PIN
  *     @arg @b  RCC_RST_LVR
  *     @arg @b  RCC_RST_POWERON
  *     @arg @b  RCC_RST_SOFTWARE
  *     @arg @b  RCC_RST_IWDT
  *     @arg @b  RCC_RST_WWDT
  *     @arg @b  RCC_RST_VCCLVR
   * @retval None
  */
void RCC_ClearResetFlag(RCC_RESET_Type ResetFlags)
{
    assert_param(IS_RST_MODULES(ResetFlags));

    /* Unlock RCC registers */
    RCC_REGS_UNLOCK();

    RCC->RSTCLR.V32 = ResetFlags;

    /* Lock RCC registers */
    RCC_REGS_LOCK();
}

/**
  * @brief  Get RCC CSM flag.
  * @param  ResetFlag:   RCC CSM flag mask
  *     @arg @b  RCC_CSM_LSE
  *     @arg @b  RCC_CSM_HSE
  *     @arg @b  RCC_CSM_PLL
  * @retval  FlagStatus RCC CSM flag
  *     @arg @b  SH_SET    the flag is setted
  *     @arg @b  RESET     the flag is cleared
  */
FlagStatus RCC_GetCsmFStatus(RCC_CSMF_Type CSMFlag)
{
    assert_param(IS_CSM_MODULES(CSMFlag));

    return ((RCC->CISTR.V32 & CSMFlag) ? SH_SET : SH_RESET);
}

/**
  * @brief   open or close CSM modules.
  * @param   OnOffState  open or close related clock gate
  *     @arg @b  SH_ON  open related clock gate
  *     @arg @b  SH_OFF  close related clock gate
  * @retval   None
   */
void RCC_CSMModuleOnOff(CmdState OnOffState)
{
    assert_param(IS_CMD_STATE(OnOffState));

    /* Unlock RCC registers */
    RCC_REGS_UNLOCK();

    RCC->CR.BIT.CSMON = OnOffState;

    /* Lock RCC registers */
    RCC_REGS_LOCK();
}

/**
  * @brief  open or close RCC->CR.
  * @param  RCC->CR:  RCC CR 
  *   This parameter can be any combination of following values:       
  *     @arg @b  RCC_CR_CSMON:  for clock check turn on/off
  *     @arg @b  RCC_CR_PLLON:  for PLL ON
  *     @arg @b  RCC_CR_HSEON:  for HSE ON
  *     @arg @b  RCC_CR_LSEON:  for LSE ON
  *     @arg @b  RCC_CR_HSION:  for HSI ON
  *     @arg @b  RCC_CR_LSION:  for LSI ON
  *@param OnOffState  open or close related clock gate
  *     @arg @b  SH_ON   open related clock gate
  *     @arg @b  SH_OFF  close related clock gate
  * @retval   None
   */
void RCC_CRRegOnOff(uint32_t TriggerSource, CmdState OnOffState)
{
    assert_param(IS_CMD_STATE(OnOffState));

    /* Unlock RCC registers */
    RCC_REGS_UNLOCK();

    if (OnOffState == SH_ON)
    {
        RCC->CR.V32 |= TriggerSource;
    }
    else
    {
        RCC->CR.V32 &= ~TriggerSource;
    }

    /* Lock RCC registers */
    RCC_REGS_LOCK();
}

/**
  * @brief  CSM select frequty
  * @param  CSMSelFreq:  CSM select frequency bits @ref RCC_CSMSEL_Type
  *     @arg @b  RCC_CSMSEL_4M:   select 4MHz
  *     @arg @b  RCC_CSMSEL_6M:   select 6MHz
  *     @arg @b  RCC_CSMSEL_8M:   select 8MHz
  *     @arg @b  RCC_CSMSEL_12M:  select 12MHz
  *     @arg @b  RCC_CSMSEL_32K:  select 32kHz
  * @retval   None
   */
void RCC_CSMSelectFreq(RCC_CSMSEL_Type CSMSelFreq)
{
    /* Unlock RCC registers */
    RCC_REGS_UNLOCK();

    RCC->CSMSEL = CSMSelFreq;

    /* Lock RCC registers */
    RCC_REGS_LOCK();
}

/**
  * @brief Clear CSM interrupt flag
  * @param SetResetState  Clear CSM interrupt flag
  *     @arg @b  SH_SET    SET
  *     @arg @b  SH_RESET  CLEAR
  * @retval   None
  */
void RCC_CSMClearIF(FlagStatus SetResetState)
{
    assert_param(IS_FLAG_STATUS(SetResetState));

    /* Unlock RCC registers */
    RCC_REGS_UNLOCK();

    RCC->CICLR.BIT.CSMC = SetResetState;
    /* Lock RCC registers */
    RCC_REGS_LOCK();
}

/**
  * @brief Configure PLL on or off
  * @param OnOffState   open or close related clock gate
  *     @arg @b  SH_ON  open related clock gate
  *     @arg @b  SH_OFF close related clock gate
  * @retval   None
  */
void RCC_PLLONorOFF(CmdState OnOffState)
{
    assert_param(IS_CMD_STATE(OnOffState));

    /* Unlock RCC registers */
    RCC_REGS_UNLOCK();

    RCC->CR.BIT.PLLON = OnOffState;

    /* Lock RCC registers */
    RCC_REGS_LOCK();
}

/**
  * @brief     Use HSI as system source, AHB \ APB0\ APB1 is all 12M
  * @param     None
  *     @arg @b   None
  *     @arg @b   None
  * @retval   None
   */
void sys_HSI12M_RC(void) /*   HSI:12M  */
{
    FLASH->ACR.V32    = 0x5AA50000; // Set lantency=0  unlock flash register
    SYSCFG->SAFR.V32  = 0x5AA50000; //unlock system config register
    RCC->RCCLOCK      = 0x33CC;     //RCC config operate unlock
    RCC->CR.BIT.HSION = 1;         //turn on HSI
    while (!RCC->CR.BIT.HSIRDY);   //Oscillation stability is set to 1 by hardware
    RCC->CR.BIT.SW = 0;            //HSI as system clock
    while (RCC->CR.BIT.SWS != RCC->CR.BIT.SW);   //system clock is HSI
    RCC->CFGR.BIT.HPRE  = 1;  //AHB SYSCLK 2 frequency divisioN
    RCC->CFGR.BIT.PPRE0 = 1;  //APB0 2 frequency divisioN
    RCC->CFGR.BIT.PPRE1 = 1;  //APB1 2 frequency divisioN
    RCC->RCCLOCK = 0;         //RCC config operate unlock
}

/**
  * @brief     Use HSI as system source, AHB \ APB0\ APB1 is all 24M
  * @param     None
  *     @arg @b   None
  *     @arg @b   None
  * @retval   None
   */
void sys_HSI24M_RC(void) /*  HSI:24M*/
{
    FLASH->ACR.V32    = 0x5AA50000; // Set lantency=0  unlock flash register
    SYSCFG->SAFR.V32  = 0x5AA50000; //unlock system config register
    RCC->RCCLOCK      = 0x33CC;     //RCC config operate unlock
    RCC->CR.BIT.HSION = 1;          //turn on HSI
    while (!RCC->CR.BIT.HSIRDY);    //Oscillation stability is set to 1 by hardware
    RCC->CR.BIT.SW = 0;             //HSI as system clock
    while (RCC->CR.BIT.SWS != RCC->CR.BIT.SW);   //system clock is HSI
    RCC->CFGR.BIT.HPRE  = 0; //AHB SYSCLK no frequency division
    RCC->CFGR.BIT.PPRE0 = 0; //APB0 no frequency division
    RCC->CFGR.BIT.PPRE1 = 0; //APB1 no frequency division
    RCC->RCCLOCK = 0;        //RCC config operate unlock
}

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
