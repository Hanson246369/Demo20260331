/**
  ******************************************************************************
  * @file    system_sh32f9xx_sc0.c
  * @author  sinowealth
  * @version V1.1.0
  * @date    2021-06-10  
  * @brief   This file SystemInit function redefinition
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
  * <h2><center>&copy; COPYRIGHT 2021 Sinowealth</center></h2>
  *
  ******************************************************************************
  */
#include "system_sh32f9xx_sc0.h"

/*******************************************************************************
*  Clock Definitions
*******************************************************************************/
#ifdef SYSCLK_FREQ_HSE
uint32_t SystemCoreClock = SYSCLK_FREQ_HSE;   /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_HSI
uint32_t SystemCoreClock = SYSCLK_FREQ_HSI;   /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_LSI
uint32_t SystemCoreClock = SYSCLK_FREQ_LSI;   /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_12MHz
uint32_t SystemCoreClock = SYSCLK_FREQ_12MHz; /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_24MHz
uint32_t SystemCoreClock = SYSCLK_FREQ_24MHz; /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_36MHz
uint32_t SystemCoreClock = SYSCLK_FREQ_36MHz; /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_48MHz
uint32_t SystemCoreClock = SYSCLK_FREQ_48MHz; /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_56MHz
uint32_t SystemCoreClock = SYSCLK_FREQ_56MHz; /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_72MHz
uint32_t SystemCoreClock = SYSCLK_FREQ_72MHz; /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_80MHz
uint32_t SystemCoreClock = SYSCLK_FREQ_80MHz; /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_96MHz
uint32_t SystemCoreClock = SYSCLK_FREQ_96MHz; /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_104MHz
uint32_t SystemCoreClock = SYSCLK_FREQ_104MHz; /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_120MHz
uint32_t SystemCoreClock = SYSCLK_FREQ_120MHz; /*!< System Clock Frequency (Core Clock) */
#else /*!< HSI Selected as System Clock source */
uint32_t SystemCoreClock = HSI_VALUE; /*!< System Clock Frequency (Core Clock) */
#endif

/*******************************************************************************
*  Private function declare
*******************************************************************************/
#ifdef SYSCLK_FREQ_HSE
static void SetSysClockToHSE(void);
#elif defined SYSCLK_FREQ_HSI
static void SetSysClockToHSI(void);
#elif defined SYSCLK_FREQ_LSI
static void SetSysClockToLSI(void);
#elif defined SYSCLK_FREQ_12MHz
static void SetSysClockTo12(void);
#elif defined SYSCLK_FREQ_24MHz
static void SetSysClockTo24(void);
#elif defined SYSCLK_FREQ_36MHz
static void SetSysClockTo36(void);
#elif defined SYSCLK_FREQ_48MHz
static void SetSysClockTo48(void);
#elif defined SYSCLK_FREQ_56MHz
static void SetSysClockTo56(void);
#elif defined SYSCLK_FREQ_72MHz
static void SetSysClockTo72(void);
#elif defined SYSCLK_FREQ_96MHz
static void SetSysClockTo96(void);
#elif defined SYSCLK_FREQ_104MHz
static void SetSysClockTo104(void);
#elif defined SYSCLK_FREQ_120MHz
static void SetSysClockTo120(void);
#endif

/**
  * @brief  Setup the microcontroller system flash latency and clock
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */

void SystemInit(void)
{
#ifdef SYSCLK_FREQ_HSE
    SetSysClockToHSE();
#elif defined SYSCLK_FREQ_HSI
    SetSysClockToHSI();
#elif defined SYSCLK_FREQ_LSI
    SetSysClockToLSI();
#elif defined SYSCLK_FREQ_12MHz
    SetSysClockTo12();
#elif defined SYSCLK_FREQ_24MHz
    SetSysClockTo24();
#elif defined SYSCLK_FREQ_36MHz
    SetSysClockTo36();
#elif defined SYSCLK_FREQ_48MHz
    SetSysClockTo48();
#elif defined SYSCLK_FREQ_56MHz
    SetSysClockTo56();
#elif defined SYSCLK_FREQ_72MHz
    SetSysClockTo72();
#elif defined SYSCLK_FREQ_96MHz
    SetSysClockTo96();
#elif defined SYSCLK_FREQ_104MHz
    SetSysClockTo104();
#elif defined SYSCLK_FREQ_120MHz
    SetSysClockTo120();
#endif
}

/**
  * @brief  Update SystemCoreClock variable according to RCC Clock Register Values.
  *         The SystemCoreClock variable contains the core clock (HCLK), it can
  *         be used by the user application to setup the SysTick timer or configure
  *         other parameters.Each time the core clock (HCLK) changes, this function must be called
  *         to update SystemCoreClock variable value. Otherwise, any configuration
  *         based on this variable will be incorrect.        
  * @param  None
  * @retval None
  */
void SystemCoreClockUpdate(void)
{
    uint8_t tmp = 0;
    uint8_t pllmul_k = 0;
    uint8_t pllmul_f = 0;
    uint8_t pllxtpre = 0;
    uint8_t pllsrc = 0;
    uint8_t hpre_div = 0;

    /* Get SYSCLK source -------------------------------------------------------*/
    tmp = RCC->CR.BIT.SWS;
    hpre_div = RCC->CFGR.BIT.HPRE;

    switch (tmp)
    {
        case SYSTEM_CLK_SRC_LSI: /* LSI used as system clock */
        SystemCoreClock = LSI_VALUE;
        break;

        case SYSTEM_CLK_SRC_HSI: /**/
        SystemCoreClock = HSI_VALUE;
        break;

        case SYSTEM_CLK_SRC_PLL: /* PLL used as system clock */
        pllsrc = RCC->CFGR.BIT.PLLSRC;
        pllmul_f = RCC->CFGR.BIT.PLLF;
        pllmul_k = RCC->CFGR.BIT.PLLK + 1;
        pllxtpre = RCC->CFGR.BIT.PLLXTPRE + 1;
        if (pllsrc) //HSE as PLL Clock input
        {
            SystemCoreClock = HSE_VALUE / pllxtpre * pllmul_f / pllmul_k/2;
        }
        else //HSI as PLL Clock input
        {
            SystemCoreClock = HSI_VALUE / pllxtpre * pllmul_f / pllmul_k/2;
        }
        break;

        case SYSTEM_CLK_SRC_HSE: /* HSE used as system clock */
        SystemCoreClock = HSE_VALUE;
        break;

    default: /* LSI used as system clock */
        SystemCoreClock = LSI_VALUE;
        break;
    }

    switch (hpre_div)
    {
    case 0:
        SystemCoreClock = SystemCoreClock;
        break;
    case 1:
        SystemCoreClock = SystemCoreClock / 2;
        break;
    case 2:
        SystemCoreClock = SystemCoreClock / 4;
        break;
    case 3:
        SystemCoreClock = SystemCoreClock / 8;
        break;
    case 4:
        SystemCoreClock = SystemCoreClock / 16;
        break;
    case 5:
        SystemCoreClock = SystemCoreClock / 32;
        break;
    default:
        SystemCoreClock = SystemCoreClock / 32;
        break;
    }
}

#ifdef SYSCLK_FREQ_HSE
/**
  * @brief  Selects HSE as System clock source and configure HCLK, PCLK0
  *         and PCLK1 prescalers.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
static void SetSysClockToHSE(void)
{
    __IO uint32_t StartUpCounter = 0, HSEStatus = 0;

    /*Config Flash latency and external oscillator pin and debug pin function*/
    FLASH->ACR.V32 = 0x5AA50000; // Set flash latency to 0 wait state

    RCC->RCCLOCK = 0x33CC; //Unlock RCC Config Register
    //It is conducive to crystal oscillator starting 
    RCC->CFGR.BIT.HSESEL = 0X00;
    RCC->CFGR.BIT.RFBSEL = 0X03;

    RCC->AHBENR.BIT.SYSCFGEN = 1;  //Enable SYSCFG Module
    SYSCFG->SAFR.V32 = 0x5AA50001; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin for oscillator function
    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/
    /* Enable HSE */
    RCC->CR.V32 |= ((uint32_t)RCC_CR_HSEON);

    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        HSEStatus = RCC->CR.V32 & RCC_CR_HSERDY;
        StartUpCounter++;
        IWDT->CLR = 0xAAAA; //Feed Dog
    } while ((HSEStatus == 0) && (StartUpCounter != HIGH_SPEED_CLOCK_STARTUP_TIMEOUT));

    if ((RCC->CR.V32 & RCC_CR_HSERDY) != 0) //HSE Startup Check
    {
        HSEStatus = (uint32_t)0x01; // HSE Startup succeed
    }
    else
    {
        HSEStatus = (uint32_t)0x00; // HSE Startup failed
    }

    if (HSEStatus) //HSE Startup succeed,Sysclock switch to HSE
    {
        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_HSE; //Switch Sysclock to HSE
        do
        {
        } while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_HSE); //Current SysClock is HSE

        /*********************Config HCLK PCLK0 PCLK1*************************/
        RCC->CFGR.BIT.HPRE  = 0;  //Config AHB SYSCLK Prescaler to 1,HCLK is HSE
        RCC->CFGR.BIT.PPRE0 = 0;  //Config APB0 PCLK0 Prescaler to 1,PCLK0 is HSE
        RCC->CFGR.BIT.PPRE1 = 0;  //Config APB1 PCLK1 Prescaler to 1,PCLK1 is HSE
    }
    else // HSE Startup failed, User can add here some code to deal with this error,eg switch to HSI
    {
    }

    RCC->RCCLOCK = 0; //LOCK RCC
}
#elif defined SYSCLK_FREQ_HSI
/**
  * @brief  Sets System clock frequency to HSI and configure HCLK, PCLK0
  *         and PCLK1 prescalers.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
static void SetSysClockToHSI(void)
{
    /*Config Flash latency and external oscillator pin and debug pin function*/
    FLASH->ACR.V32 = 0x5AA50000; // Set flash latency to 0 wait state

    RCC->RCCLOCK = 0x33CC;         //Unlock RCC Config Register
    RCC->AHBENR.BIT.SYSCFGEN = 1;  //Enable SYSCFG Module
    SYSCFG->SAFR.V32 = 0x5AA50000; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin to GPIO function

    RCC->CR.BIT.HSION = 1;       //Enable HSI
    while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

    RCC->CR.BIT.SW = SYSTEM_CLK_SRC_HSI; //Switch Sysclk to HSI
    while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_HSI); //Wait System Clock source switch to HSI

    /*********************Config HCLK PCLK0 PCLK1*************************/
    RCC->CFGR.BIT.HPRE  = 0;  //Config AHB SYSCLK Prescaler to 1,HCLK is HSI
    RCC->CFGR.BIT.PPRE0 = 0;  //Config APB0 PCLK0 Prescaler to 1,PCLK0 is HSI
    RCC->CFGR.BIT.PPRE1 = 0;  //Config APB1 PCLK1 Prescaler to 1,PCLK1 is HSI

    RCC->RCCLOCK = 0; //lock rcc
}
#elif defined SYSCLK_FREQ_LSI
/**
  * @brief  Sets System clock frequency to LSI and configure HCLK, PCLK0
  *         and PCLK1 prescalers.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
static void SetSysClockToLSI(void)
{
    __IO uint32_t StartUpCounter = 0, LSIStatus = 0;

    /*Config Flash latency and external oscillator pin and debug pin function*/
    FLASH->ACR.V32 = 0x5AA50000; // Set flash latency to 0 wait state

    RCC->RCCLOCK = 0x33CC; //Unlock RCC Config Register

    RCC->AHBENR.BIT.SYSCFGEN = 1; //Enable SYSCFG Module Clock

    SYSCFG->SAFR.V32 = 0x5AA50000; //Unlock SYSCFG SAFR register and set XTALX1 and XTALX2 pin for GPIO function

    LSIStatus = 0x01; /*LSI always success in system startup*/

    if (LSIStatus) //LSI Startup succeed,Sysclock switch to LSI
    {
        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_LSI; //Switch Sysclock to LSI
        do
        {
            IWDT->CLR = 0xAAAA; //Feed Dog
        } while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_LSI); //Current SysClock is LSI

        /*********************Config HCLK PCLK0 PCLK1*************************/
        RCC->CFGR.BIT.HPRE  = 0;  //Config AHB SYSCLK Prescaler to 1,HCLK is LSI
        RCC->CFGR.BIT.PPRE0 = 0;  //Config APB0 PCLK0 Prescaler to 1,PCLK0 is LSI
        RCC->CFGR.BIT.PPRE1 = 0;  //Config APB1 PCLK1 Prescaler to 1,PCLK1 is LSI
    }
    else // HSE Startup failed, User can add here some code to deal with this error,eg switch to HSI
    {
    }

    RCC->RCCLOCK = 0; //LOCK RCC
}
#elif defined SYSCLK_FREQ_12MHz
/**
  * @brief  Sets System clock frequency to 12MHz and configure HCLK ,PCLK0
  *         and PCLK1 prescalers.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
static void SetSysClockTo12(void)
{
    __IO uint32_t StartUpCounter = 0, HSEStatus = 0;

    /*Config Flash latency and external oscillator pin and debug pin function*/
    FLASH->ACR.V32 = 0x5AA50000;  // Set flash latency to 0 wait state
    RCC->RCCLOCK = 0x33CC;        //Unlock RCC Config Register
    RCC->AHBENR.BIT.SYSCFGEN = 1; //Enable SYSCFG Module

#if HIGH_SPEED_OSCILLATOR_SOURCE

    SYSCFG->SAFR.V32 = 0x5AA50001; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin for oscillator function

    //It is conducive to crystal oscillator starting 
    RCC->CFGR.BIT.HSESEL = 0X00;
    RCC->CFGR.BIT.RFBSEL = 0X03;
    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/
    /* Enable HSE */
    RCC->CR.V32 |= ((uint32_t)RCC_CR_HSEON);

    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        HSEStatus = RCC->CR.V32 & RCC_CR_HSERDY;
        StartUpCounter++;
        IWDT->CLR = 0xAAAA; //Feed Dog
    } while ((HSEStatus == 0) && (StartUpCounter != HIGH_SPEED_CLOCK_STARTUP_TIMEOUT));

    if ((RCC->CR.V32 & RCC_CR_HSERDY) != 0) //HSE Startup Check
    {
        HSEStatus = (uint32_t)0x01; // HSE Startup succeed
    }
    else
    {
        HSEStatus = (uint32_t)0x00; // HSE Startup failed
    }

    if (HSEStatus) //HSE Startup succeed,Sysclock switch to HSE
    {
        //to be  calculate PLL factor
        RCC->CFGR.BIT.PLLSRC   = 1;                   //Select HSE as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(1-1);            //PREFCLK = PLLCLKIN / 1 =  HSE / 1 = 12 MHz   N=1  [1,4]
        RCC->CFGR.BIT.PLLF     = (uint8_t)20;               //VCOCLK = PREFCLK * 20 =  240 MHz             F=20 [4,40]
        RCC->CFGR.BIT.PLLK     = (uint8_t)(5-1);            //DIVCLK = VCOCLK / 5 =  48 MHz                K=5  [1,8]

        RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK

        while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch SYSCLK to PLL
        while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL
    }
    else //HSE Startup faild,switch to HSI,HSI is 24MHz,no need PLL to generate 12MHz Clock
    {
        RCC->CR.BIT.HSION = 1; //Enable HSI
        while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_HSI; //Switch Sysclk to HSI
        while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_HSI); //Wait Sysclock switch to HSI
    }

#else

    SYSCFG->SAFR.V32 = 0x5AA50000; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin to GPIO function

    RCC->CR.BIT.HSION = 1; //Enable HSI
    while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

    RCC->CR.BIT.SW = SYSTEM_CLK_SRC_HSI; //Switch Sysclk to HSI
    while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_HSI); //Wait Sysclock switch to HSI
#endif

    /*********************Now SYSCLK is 24 MHz,Config HCLK,PCLK0,PCLK1***************************/
    RCC->CFGR.BIT.HPRE = 1;  //Config AHB SYSCLK Prescaler to 2,HCLK is 12MHz
    RCC->CFGR.BIT.PPRE0 = 0; //Config APB0 PCLK0 Prescaler to 1,PCLK0 is 12MHz
    RCC->CFGR.BIT.PPRE1 = 0; //Config APB1 PCLK1 Prescaler to 1,PCLK1 is 12MHz

    RCC->RCCLOCK = 0; //LOCK RCC Config Register
}
#elif defined SYSCLK_FREQ_24MHz
/**
  * @brief  Sets System clock frequency to 24MHz and configure HCLK ,PCLK0
  *         and PCLK1 prescalers.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
static void SetSysClockTo24(void)
{
    __IO uint32_t StartUpCounter = 0, HSEStatus = 0;

    /*Config Flash latency and external oscillator pin and debug pin function*/
    FLASH->ACR.V32 = 0x5AA50000;  // Set flash latency to 0 wait state
    RCC->RCCLOCK = 0x33CC;        //Unlock RCC Config Register
    RCC->AHBENR.BIT.SYSCFGEN = 1; //Enable SYSCFG Module

#if HIGH_SPEED_OSCILLATOR_SOURCE

    SYSCFG->SAFR.V32 = 0x5AA50001; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin for oscillator function

    //It is conducive to crystal oscillator starting 
    RCC->CFGR.BIT.HSESEL = 0X00;
    RCC->CFGR.BIT.RFBSEL = 0X03;
    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/
    /* Enable HSE */
    RCC->CR.V32 |= ((uint32_t)RCC_CR_HSEON);

    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        HSEStatus = RCC->CR.V32 & RCC_CR_HSERDY;
        StartUpCounter++;
        IWDT->CLR = 0xAAAA; //Feed Dog
    } while ((HSEStatus == 0) && (StartUpCounter != HIGH_SPEED_CLOCK_STARTUP_TIMEOUT));

    if ((RCC->CR.V32 & RCC_CR_HSERDY) != 0) //HSE Startup Check
    {
        HSEStatus = (uint32_t)0x01; // HSE Startup succeed
    }
    else
    {
        HSEStatus = (uint32_t)0x00; // HSE Startup failed
    }

    if (HSEStatus) //HSE Startup succeed,Sysclock switch to HSE
    {
        //to be  calculate PLL factor
        RCC->CFGR.BIT.PLLSRC   = 1;   //Select HSE as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(1-1);     //PREFCLK = PLLCLKIN / 1 =  HSE / 1 = 12 MHz   N=1  [1,4]
        RCC->CFGR.BIT.PLLF     = (uint8_t)20;        //VCOCLK = PREFCLK * 20 =  240 MHz             F=20 [4,40]
        RCC->CFGR.BIT.PLLK     = (uint8_t)(5-1);     //DIVCLK = VCOCLK / 5 =  48 MHz                K=5  [1,8]

        RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK

        while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch SYSCLK to PLL
        while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL
    }
    else //HSE Startup faild,switch to HSI,HSI is 24MHz,no need PLL to generate 24MHz Clock
    {
        RCC->CR.BIT.HSION = 1; //Enable HSI
        while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_HSI; //Switch Sysclk to HSI
        while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_HSI); //Wait Sysclock switch to HSI
    }

#else

    SYSCFG->SAFR.V32 = 0x5AA50000; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin to GPIO function

    RCC->CR.BIT.HSION = 1; //Enable HSI
    while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

    RCC->CR.BIT.SW = SYSTEM_CLK_SRC_HSI; //Switch Sysclk to HSI
    while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_HSI); //Wait Sysclock switch to HSI
#endif

    /*********************Now SYSCLK is 24 MHz,Config HCLK,PCLK0,PCLK1***************************/
    RCC->CFGR.BIT.HPRE = 0;  //Config AHB SYSCLK Prescaler to 1,HCLK is 24MHz
    RCC->CFGR.BIT.PPRE0 = 0; //Config APB0 PCLK0 Prescaler to 1,PCLK0 is 24MHz
    RCC->CFGR.BIT.PPRE1 = 0; //Config APB1 PCLK1 Prescaler to 1,PCLK1 is 24MHz

    RCC->RCCLOCK = 0; //LOCK RCC Config Register
}
#elif defined SYSCLK_FREQ_36MHz
/**
  * @brief  Sets System clock frequency to 36MHz and configure HCLK,PCLK0
  *         and PCLK1 prescalers.Default use HSI as PLL Clock source,
  *         User can set Macro  HIGH_SPEED_OSCILLATOR_SOURCE to 1 to select HSE as PLL clock source.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
static void SetSysClockTo36(void)
{
    __IO uint32_t StartUpCounter = 0, HSEStatus = 0;

    /*Config Flash latency and external oscillator pin and debug pin function*/
    FLASH->ACR.V32 = 0x5AA50001;  // Set flash latency to 1 wait state
    RCC->RCCLOCK = 0x33CC;        //Unlock RCC Config Register
    RCC->AHBENR.BIT.SYSCFGEN = 1; //Enable SYSCFG Module

#if HIGH_SPEED_OSCILLATOR_SOURCE

    SYSCFG->SAFR.V32 = 0x5AA50001; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin for oscillator function

    //It is conducive to crystal oscillator starting 
    RCC->CFGR.BIT.HSESEL = 0X00;
    RCC->CFGR.BIT.RFBSEL = 0X03;
    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/
    /* Enable HSE */
    RCC->CR.V32 |= ((uint32_t)RCC_CR_HSEON);

    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        HSEStatus = RCC->CR.V32 & RCC_CR_HSERDY;
        StartUpCounter++;
        IWDT->CLR = 0xAAAA; //Feed Dog
    } while ((HSEStatus == 0) && (StartUpCounter != HIGH_SPEED_CLOCK_STARTUP_TIMEOUT));

    if ((RCC->CR.V32 & RCC_CR_HSERDY) != 0) //HSE Startup Check
    {
        HSEStatus = (uint32_t)0x01; // HSE Startup succeed
    }
    else
    {
        HSEStatus = (uint32_t)0x00; // HSE Startup failed
    }

    if (HSEStatus) //HSE Startup succeed,Sysclock switch to HSE
    {
        //to be  calculate PLL factor
        RCC->CFGR.BIT.PLLSRC   = 1; //HSE as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(1-1);    //PREFCLK = PLLCLKIN / 1 =  HSE / 1 = 12 MHz  N=1  [1,4]
        RCC->CFGR.BIT.PLLF     = (uint8_t)24;       //VCOCLK = PREFCLK * 24 =  288 MHz            F=24 [4,40]
        RCC->CFGR.BIT.PLLK     = (uint8_t)(4-1);    //DIVCLK = VCOCLK / 4 =  72 MHz               K=4  [1,8]

        RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK

        while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

        while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL
    }
    else //HSE Startup faild,switch to HSI,HSI is 24MHz,need PLL to generate 36 MHz Clock
    {
        RCC->CR.BIT.HSION = 1; //Enable HSI
        while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

        //to be  calculate PLL factor
        RCC->CFGR.BIT.PLLSRC = 0; //HSI as PLL clock source

        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(3-1);   //PREFCLK = PLLCLKIN / 3 =  HSI / 3 = 8 MHz  N=3  [1,4]
        RCC->CFGR.BIT.PLLF     = (uint8_t)36;      //VCOCLK = PREFCLK * 36 =  288 MHz           F=36 [4,40]
        RCC->CFGR.BIT.PLLK     = (uint8_t)(4-1);   //DIVCLK = VCOCLK / 4 =  72 MHz              K=4  [1,8]

        RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK

        while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

        while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL
    }

#else

    SYSCFG->SAFR.V32 = 0x5AA50000; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin to GPIO function

    RCC->CR.BIT.HSION = 1; //Enable HSI
    while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

    //to be  calculate PLL factor
    RCC->CFGR.BIT.PLLSRC = 0; //HSI as PLL clock source

    RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(3-1);   //PREFCLK = PLLCLKIN / 3 =  HSI / 3 = 8 MHz  N=3  [1,4]
    RCC->CFGR.BIT.PLLF     = (uint8_t)36;      //VCOCLK = PREFCLK * 36 =  288 MHz           F=36 [4,40]
    RCC->CFGR.BIT.PLLK     = (uint8_t)(4-1);   //DIVCLK = VCOCLK / 4 =  72 MHz              K=4  [1,8]

    RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK

    while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

    RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

    while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL

#endif

    /*********************Now SYSCLK is 36 MHz,Config HCLK,PCLK0,PCLK1***************************/
    RCC->CFGR.BIT.HPRE  = 0;  //Config AHB SYSCLK Prescaler to 1,HCLK is 36 MHz
    RCC->CFGR.BIT.PPRE0 = 1; //Config APB0 PCLK0 Prescaler to 2,PCLK0 is 18 MHz
    RCC->CFGR.BIT.PPRE1 = 0; //Config APB1 PCLK1 Prescaler to 1,PCLK1 is 36 MHz

    RCC->RCCLOCK = 0; //LOCK RCC Config Register
}
#elif defined SYSCLK_FREQ_48MHz
/**
  * @brief  Sets System clock frequency to 48MHz and configure HCLK,PCLK0
  *         and PCLK1 prescalers.Default use HSI as PLL Clock source,
  *         User can set Macro  HIGH_SPEED_OSCILLATOR_SOURCE to 1 to select HSE as PLL clock source. 
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
static void SetSysClockTo48(void)
{
    __IO uint32_t StartUpCounter = 0, HSEStatus = 0;

    /*Config Flash latency and external oscillator pin and debug pin function*/
    FLASH->ACR.V32 = 0x5AA50001;  // Set flash latency to 1 wait state
    RCC->RCCLOCK = 0x33CC;        //Unlock RCC Config Register
    RCC->AHBENR.BIT.SYSCFGEN = 1; //Enable SYSCFG Module

#if HIGH_SPEED_OSCILLATOR_SOURCE

    SYSCFG->SAFR.V32 = 0x5AA50001; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin for oscillator function

    //It is conducive to crystal oscillator starting 
    RCC->CFGR.BIT.HSESEL = 0X00;
    RCC->CFGR.BIT.RFBSEL = 0X03;
    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/
    /* Enable HSE */
    RCC->CR.V32 |= ((uint32_t)RCC_CR_HSEON);

    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        HSEStatus = RCC->CR.V32 & RCC_CR_HSERDY;
        StartUpCounter++;
        IWDT->CLR = 0xAAAA; //Feed Dog
    } while ((HSEStatus == 0) && (StartUpCounter != HIGH_SPEED_CLOCK_STARTUP_TIMEOUT));

    if ((RCC->CR.V32 & RCC_CR_HSERDY) != 0) //HSE Startup Check
    {
        HSEStatus = (uint32_t)0x01; // HSE Startup succeed
    }
    else
    {
        HSEStatus = (uint32_t)0x00; // HSE Startup failed
    }

    if (HSEStatus) //HSE Startup succeed,Sysclock switch to HSE
    {
        //calculate PLL factor
        RCC->CFGR.BIT.PLLSRC   = 1; //HSE as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(1-1);    //PREFCLK = PLLCLKIN / 1 =  HSE / 1 = 12 MHz   N=3  [1,4]
        RCC->CFGR.BIT.PLLF     = (uint8_t)16;       //VCOCLK = PREFCLK * 16 =  192 MHz             F=36 [16,40]
        RCC->CFGR.BIT.PLLK     = (uint8_t)(2-1);    //DIVCLK = VCOCLK / 2 =  96 MHz                K=3  [2,8]

        RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK

        while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

        while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL
    }
    else //HSE Startup faild,switch to HSI,HSI is 24MHz,need PLL to generate 48 MHz Clock
    {
        RCC->CR.BIT.HSION = 1; //Enable HSI
        while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

        //to be  calculate PLL factor
        RCC->CFGR.BIT.PLLSRC   = 0;      //HSI as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(3-1);     //PREFCLK = PLLCLKIN / 3 =  HSI / 3 = 8 MHz   N=3  [1,4]
        RCC->CFGR.BIT.PLLF     = (uint8_t)36;        //VCOCLK = PREFCLK * 36 =  288 MHz            F=36 [4,40]
        RCC->CFGR.BIT.PLLK     = (uint8_t)(3-1);     //DIVCLK = VCOCLK / 3 =  96 MHz               K=3  [1,8]

        RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK

        while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

        while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL
    }
#else
    SYSCFG->SAFR.V32 = 0x5AA50000; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin to GPIO function

    RCC->CR.BIT.HSION = 1; //Enable HSI
    while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

    //to be  calculate PLL factor
    RCC->CFGR.BIT.PLLSRC = 0;      //HSI as PLL clock source
    RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(3-1);     //PREFCLK = PLLCLKIN / 3 =  HSI / 3 = 8 MHz  N=3  [1,4]
    RCC->CFGR.BIT.PLLF     = (uint8_t)36;        //VCOCLK = PREFCLK * 36 =  288 MHz           F=36 [4,40]
    RCC->CFGR.BIT.PLLK     = (uint8_t)(3-1);     //DIVCLK = VCOCLK / 3 =  96 MHz              K=3  [1,8]

    RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK

    while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

    RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

    while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL
#endif

    /*********************Now SYSCLK is 48 MHz,Config HCLK,PCLK0,PCLK1***************************/
    RCC->CFGR.BIT.HPRE  = 0;  //Config AHB SYSCLK Prescaler to 1,HCLK is 48 MHz
    RCC->CFGR.BIT.PPRE0 = 1; //Config APB0 PCLK0 Prescaler to 2,PCLK0 is 24 MHz
    RCC->CFGR.BIT.PPRE1 = 0; //Config APB1 PCLK1 Prescaler to 1,PCLK1 is 48 MHz

    RCC->RCCLOCK = 0; //LOCK RCC
}

#elif defined SYSCLK_FREQ_56MHz
/**
  * @brief  Sets System clock frequency to 56MHz and configure HCLK,PCLK0
  *         and PCLK1 prescalers.Default use HSI as PLL Clock source,
  *         User can set Macro  HIGH_SPEED_OSCILLATOR_SOURCE to 1 to select HSE as PLL clock source. 
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
static void SetSysClockTo56(void)
{
    __IO uint32_t StartUpCounter = 0, HSEStatus = 0;

    /*Config Flash latency and external oscillator pin and debug pin function*/
    FLASH->ACR.V32 = 0x5AA50002;  // Set flash latency to 2 wait state
    RCC->RCCLOCK = 0x33CC;        //Unlock RCC Config Register
    RCC->AHBENR.BIT.SYSCFGEN = 1; //Enable SYSCFG Module

#if HIGH_SPEED_OSCILLATOR_SOURCE

    SYSCFG->SAFR.V32 = 0x5AA50001; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin for oscillator function

    //It is conducive to crystal oscillator starting 
    RCC->CFGR.BIT.HSESEL = 0X00;
    RCC->CFGR.BIT.RFBSEL = 0X03;
    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/
    /* Enable HSE */
    RCC->CR.V32 |= ((uint32_t)RCC_CR_HSEON);

    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        HSEStatus = RCC->CR.V32 & RCC_CR_HSERDY;
        StartUpCounter++;
        IWDT->CLR = 0xAAAA; //Feed Dog
    } while ((HSEStatus == 0) && (StartUpCounter != HIGH_SPEED_CLOCK_STARTUP_TIMEOUT));

    if ((RCC->CR.V32 & RCC_CR_HSERDY) != 0) //HSE Startup Check
    {
        HSEStatus = (uint32_t)0x01; // HSE Startup succeed
    }
    else
    {
        HSEStatus = (uint32_t)0x00; // HSE Startup failed
    }

    if (HSEStatus) //HSE Startup succeed,Sysclock switch to HSE
    {
        //to be  calculate PLL factor
        RCC->CFGR.BIT.PLLSRC = 1;            //HSE as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(1-1);    //PREFCLK = PLLCLKIN / 1 =  HSE / 1 = 12 MHz  N=1  [1,4]
        RCC->CFGR.BIT.PLLF     = (uint8_t)28;       //VCOCLK = PREFCLK * 28 =  336 MHz            F=28 [4,40]
        RCC->CFGR.BIT.PLLK     = (uint8_t)(3-1);    //DIVCLK = VCOCLK / 3 =  112 MHz              K=3  [1,8]

        RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK

        while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

        while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL
    }
    else //HSE Startup faild,switch to HSI,HSI is 24MHz,need PLL to generate 56 MHz Clock
    {
        RCC->CR.BIT.HSION = 1; //Enable HSI
        while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

        //to be  calculate PLL factor
        RCC->CFGR.BIT.PLLSRC = 0;            //HSI as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(3-1);     //PREFCLK = PLLCLKIN / 1 =  HSI / 3 = 8 MHz  N=3  [1,4]
        RCC->CFGR.BIT.PLLF     = (uint8_t)28;        //VCOCLK = PREFCLK * 28 =  224 MHz           F=28 [4,40]
        RCC->CFGR.BIT.PLLK     = (uint8_t)(2-1);     //DIVCLK = VCOCLK / 2 =  112 MHz             K=2  [1,8]

        RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK

        while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

        while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL
    }

#else

    SYSCFG->SAFR.V32 = 0x5AA50000; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin to GPIO function

    RCC->CR.BIT.HSION = 1; //Enable HSI
    while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

    //to be  calculate PLL factor
    RCC->CFGR.BIT.PLLSRC = 0;               //HSI as PLL clock source
    RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(3-1);     //PREFCLK = PLLCLKIN / 1 =  HSI / 3 = 8 MHz   N=3  [1,4]
    RCC->CFGR.BIT.PLLF     = (uint8_t)28;        //VCOCLK = PREFCLK * 28 =  224 MHz            F=28 [4,40]
    RCC->CFGR.BIT.PLLK     = (uint8_t)(2-1);     //DIVCLK = VCOCLK / 2 =  112 MHz              K=2  [1,8]

    RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK

    while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

    RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

    while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL

#endif
    /*********************Now SYSCLK is 56 MHz,Config HCLK,PCLK0,PCLK1***************************/

    RCC->CFGR.BIT.HPRE = 0;  //Config AHB SYSCLK Prescaler to 1,HCLK is 56MHz
    RCC->CFGR.BIT.PPRE0 = 1; //Config APB0 PCLK0 Prescaler to 2,PCLK0 is 28MHz
    RCC->CFGR.BIT.PPRE1 = 0; //Config APB1 PCLK1 Prescaler to 1,PCLK1 is 56MHz

    RCC->RCCLOCK = 0; //LOCK RCC Config Register
}

#elif defined SYSCLK_FREQ_72MHz
/**
  * @brief  Sets System clock frequency to 72MHz and configure HCLK,PLCK0
  *         and PCLK1 prescalers.Default use HSI as PLL Clock source,
  *         User can set Macro  HIGH_SPEED_OSCILLATOR_SOURCE to 1 to select HSE as PLL clock source. 
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
static void SetSysClockTo72(void)
{
    __IO uint32_t StartUpCounter = 0, HSEStatus = 0;

    /*Config Flash latency and external oscillator pin and debug pin function*/
    FLASH->ACR.V32 = 0x5AA50002;  // Set flash latency to 2 wait state
    RCC->RCCLOCK = 0x33CC;        //Unlock RCC Config Register
    RCC->AHBENR.BIT.SYSCFGEN = 1; //Enable SYSCFG Module

#if HIGH_SPEED_OSCILLATOR_SOURCE

    SYSCFG->SAFR.V32 = 0x5AA50001; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin for oscillator function

    //It is conducive to crystal oscillator starting 
    RCC->CFGR.BIT.HSESEL = 0X00;
    RCC->CFGR.BIT.RFBSEL = 0X03;
    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/
    /* Enable HSE */
    RCC->CR.V32 |= ((uint32_t)RCC_CR_HSEON);

    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        HSEStatus = RCC->CR.V32 & RCC_CR_HSERDY;
        StartUpCounter++;
        IWDT->CLR = 0xAAAA; //Feed Dog
    } while ((HSEStatus == 0) && (StartUpCounter != HIGH_SPEED_CLOCK_STARTUP_TIMEOUT));

    if ((RCC->CR.V32 & RCC_CR_HSERDY) != 0) //HSE Startup Check
    {
        HSEStatus = (uint32_t)0x01; // HSE Startup succeed
    }
    else
    {
        HSEStatus = (uint32_t)0x00; // HSE Startup failed
    }

    if (HSEStatus) //HSE Startup succeed,Sysclock switch to HSE
    {
        //calculate PLL factor
        RCC->CFGR.BIT.PLLSRC = 1;            //HSE as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(1-1);     //PREFCLK = PLLCLKIN / 1 =  HSE / 3 = 12 MHz   N=1  [1,4]
        RCC->CFGR.BIT.PLLF     = (uint8_t)24;        //VCOCLK = PREFCLK * 24 =  288 MHz             F=12 [4,40]
        RCC->CFGR.BIT.PLLK     = (uint8_t)(2-1);     //DIVCLK = VCOCLK / 2 =  144 MHz               K=1  [1,8]

        RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK
        while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

        while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL
    }
    else //HSE Startup faild,switch to HSI,HSI is 24 MHz,need PLL to generate 72 MHz Clock
    {

        RCC->CR.BIT.HSION = 1; //Enable HSI
        while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

        //to be  calculate PLL factor
        RCC->CFGR.BIT.PLLSRC = 0;            //HSI as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(2-1);     //PREFCLK = PLLCLKIN / 1 =  HSI / 2 = 12 MHz   N=2  [1,4]
        RCC->CFGR.BIT.PLLF     = (uint8_t)24;        //VCOCLK = PREFCLK * 24 =  288 MHz             F=12 [4,40]
        RCC->CFGR.BIT.PLLK     = (uint8_t)(2-1);     //DIVCLK = VCOCLK / 2 =  144 MHz               K=1  [1,8]

        RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK
        while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

        while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL
    }

#else

    SYSCFG->SAFR.V32 = 0x5AA50000; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin to GPIO function

    RCC->CR.BIT.HSION = 1; //Enable HSI
    while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

    RCC->CFGR.BIT.PLLSRC = 0;               //HSI as PLL clock source
    RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(2-1);     //PREFCLK = PLLCLKIN / 1 =  HSI / 2 = 12 MHz  N=2  [1,4]
    RCC->CFGR.BIT.PLLF     = (uint8_t)24;        //VCOCLK = PREFCLK * 24 =  288 MHz            F=12 [4,40]
    RCC->CFGR.BIT.PLLK     = (uint8_t)(2-1);     //DIVCLK = VCOCLK / 2 =  144 MHz              K=1  [1,8]

    RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK
    while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

    RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

    while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL

#endif
    /*********************Now SYSCLK is 72 MHz,Config HCLK,PCLK0,PCLK1***************************/

    RCC->CFGR.BIT.HPRE = 0;  //Config AHB SYSCLK Prescaler to 1,HCLK is 72MHz
    RCC->CFGR.BIT.PPRE0 = 2; //Config APB0 PCLK0 Prescaler to 4,PCLK0 is 18MHz
    RCC->CFGR.BIT.PPRE1 = 1; //Config APB1 PCLK1 Prescaler to 2,PCLK1 is 36MHz

    RCC->RCCLOCK = 0; //LOCK RCC
}

#elif defined SYSCLK_FREQ_96MHz
/**
  * @brief  Sets System clock frequency to 96MHz and configure HCLK,PLCK0
  *         and PCLK1 prescalers.Default use HSI as PLL Clock source,
  *         User can set Macro  HIGH_SPEED_OSCILLATOR_SOURCE to 1 to select HSE as PLL clock source. 
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
static void SetSysClockTo96(void)
{
    __IO uint32_t StartUpCounter = 0, HSEStatus = 0;

    /*Config Flash latency and external oscillator pin and debug pin function*/
    FLASH->ACR.V32 = 0x5AA50004;  // Set flash latency to 4 wait state
    RCC->RCCLOCK = 0x33CC;        //Unlock RCC Config Register
    RCC->AHBENR.BIT.SYSCFGEN = 1; //Enable SYSCFG Module

#if HIGH_SPEED_OSCILLATOR_SOURCE

    SYSCFG->SAFR.V32 = 0x5AA50001; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin for oscillator function

    //It is conducive to crystal oscillator starting 
    RCC->CFGR.BIT.HSESEL = 0X00;
    RCC->CFGR.BIT.RFBSEL = 0X03;
    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/
    /* Enable HSE */
    RCC->CR.V32 |= ((uint32_t)RCC_CR_HSEON);

    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        HSEStatus = RCC->CR.V32 & RCC_CR_HSERDY;
        StartUpCounter++;
        IWDT->CLR = 0xAAAA; //Feed Dog
    } while ((HSEStatus == 0) && (StartUpCounter != HIGH_SPEED_CLOCK_STARTUP_TIMEOUT));

    if ((RCC->CR.V32 & RCC_CR_HSERDY) != 0) //HSE Startup Check
    {
        HSEStatus = (uint32_t)0x01; // HSE Startup succeed
    }
    else
    {
        HSEStatus = (uint32_t)0x00; // HSE Startup failed
    }

    if (HSEStatus) //HSE Startup succeed,Sysclock switch to HSE
    {
        //calculate PLL factor
        RCC->CFGR.BIT.PLLSRC = 1;            //HSE as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(1-1);     //PREFCLK = PLLCLKIN / 1 =  HSE / 1 = 12 MHz  N=1  [1,4]
        RCC->CFGR.BIT.PLLF     = (uint8_t)16;        //VCOCLK = PREFCLK * 16 =  192 MHz            F=16 [4,40]
        RCC->CFGR.BIT.PLLK     = (uint8_t)(1-1);     //DIVCLK = VCOCLK / 1 =  192 MHz              K=1  [1,8]

        RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK
        while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

        while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL
    }
    else //HSE Startup faild,switch to HSI,HSI is 24 MHz,need PLL to generate 72 MHz Clock
    {

        RCC->CR.BIT.HSION = 1; //Enable HSI
        while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

        //to be  calculate PLL factor
        RCC->CFGR.BIT.PLLSRC = 0;            //HSI as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(3-1);     //PREFCLK = PLLCLKIN / 3 =  HSI / 3 = 8 MHz
        RCC->CFGR.BIT.PLLF     = (uint8_t)24;        //VCOCLK = PREFCLK * 24 =  196 MHz
        RCC->CFGR.BIT.PLLK     = (uint8_t)(1-1);     //DIVCLK = VCOCLK / 1 =  196 MHz 

        RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK
        while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

        while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL
    }

#else

    SYSCFG->SAFR.V32 = 0x5AA50000; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin to GPIO function

    RCC->CR.BIT.HSION = 1; //Enable HSI
    while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

    RCC->CFGR.BIT.PLLSRC = 0;            //HSI as PLL clock source
    RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(3-1);     //PREFCLK = PLLCLKIN / 3 =  HSI / 3 = 8 MHz   N=3  [1,4]
    RCC->CFGR.BIT.PLLF     = (uint8_t)24;        //VCOCLK = PREFCLK * 24 =  196 MHz            F=24 [4,40]
    RCC->CFGR.BIT.PLLK     = (uint8_t)(1-1);     //DIVCLK = VCOCLK / 1 =  196 MHz              K=1  [1,8]

    RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK
    while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

    RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

    while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL

#endif

    /*********************Now SYSCLK is 96 MHz,Config HCLK,PCLK0,PCLK1***************************/

    RCC->CFGR.BIT.HPRE = 0;  //Config AHB SYSCLK Prescaler to 1,HCLK is 96MHz
    RCC->CFGR.BIT.PPRE0 = 2; //Config APB0 PCLK0 Prescaler to 4,PCLK0 is 24MHz
    RCC->CFGR.BIT.PPRE1 = 1; //Config APB1 PCLK1 Prescaler to 2,PCLK1 is 48MHz

    RCC->RCCLOCK = 0; //LOCK RCC
}
#elif defined SYSCLK_FREQ_120MHz
/**
  * @brief  Sets System clock frequency to 120MHz and configure HCLK,PLCK0
  *         and PCLK1 prescalers.Default use HSI as PLL Clock source,
  *         User can set Macro  HIGH_SPEED_OSCILLATOR_SOURCE to 1 to select HSE as PLL clock source. 
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
static void SetSysClockTo120(void)
{
    __IO uint32_t StartUpCounter = 0, HSEStatus = 0;

    /*Config Flash latency and external oscillator pin and debug pin function*/
    FLASH->ACR.V32 = 0x5AA50004;  // Set flash latency to 4 wait state
    RCC->RCCLOCK = 0x33CC;        //Unlock RCC Config Register
    RCC->AHBENR.BIT.SYSCFGEN = 1; //Enable SYSCFG Module

#if HIGH_SPEED_OSCILLATOR_SOURCE

    SYSCFG->SAFR.V32 = 0x5AA50001; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin for oscillator function

    //It is conducive to crystal oscillator starting 
    RCC->CFGR.BIT.HSESEL = 0X00;
    RCC->CFGR.BIT.RFBSEL = 0X03;
    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/
    /* Enable HSE */
    RCC->CR.V32 |= ((uint32_t)RCC_CR_HSEON);

    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        HSEStatus = RCC->CR.V32 & RCC_CR_HSERDY;
        StartUpCounter++;
        IWDT->CLR = 0xAAAA; //Feed Dog
    } while ((HSEStatus == 0) && (StartUpCounter != HIGH_SPEED_CLOCK_STARTUP_TIMEOUT));

    if ((RCC->CR.V32 & RCC_CR_HSERDY) != 0) //HSE Startup Check
    {
        HSEStatus = (uint32_t)0x01; // HSE Startup succeed
    }
    else
    {
        HSEStatus = (uint32_t)0x00; // HSE Startup failed
    }

    if (HSEStatus) //HSE Startup succeed,Sysclock switch to HSE
    {
        //to be  calculate PLL factor
        RCC->CFGR.BIT.PLLSRC = 1;            //HSE as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(1-1);     //PREFCLK = PLLCLKIN / 1 =  HSE / 1 = 12 MHz   N=1  [1,4]
        RCC->CFGR.BIT.PLLF     = (uint8_t)20;        //VCOCLK = PREFCLK * 20 =  240 MHz             F=20 [4,40]
        RCC->CFGR.BIT.PLLK     = (uint8_t)(1-1);     //DIVCLK = VCOCLK / 1 =  240 MHz               K=1  [1,8]

        RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK
        while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

        while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL
    }
    else //HSE Startup faild,switch to HSI,HSI is 24 MHz,need PLL to generate 72 MHz Clock
    {

        RCC->CR.BIT.HSION = 1; //Enable HSI
        while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

        //to be  calculate PLL factor
        RCC->CFGR.BIT.PLLSRC = 0;              //HSI as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(2-1);   //PREFCLK = PLLCLKIN / 2 =  HSI / 2 = 12 MHz   N=2  [1,4]
        RCC->CFGR.BIT.PLLF     = (uint8_t)(20);    //VCOCLK = PREFCLK * 20 =  240 MHz             F=20 [4,40]
        RCC->CFGR.BIT.PLLK     = (uint8_t)(1-1);   //DIVCLK = VCOCLK / 1 =  240 MHz               K=1  [1,8]

        RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK
        while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

        while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL
    }

#else

    SYSCFG->SAFR.V32 = 0x5AA50000; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin to GPIO function

    RCC->CR.BIT.HSION = 1; //Enable HSI
    while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

    RCC->CFGR.BIT.PLLSRC = 0;            //HSI as PLL clock source
    RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(2-1);   //PREFCLK = PLLCLKIN / 2 =  HSI / 2 = 12 MHz    N=2  [1,4]
    RCC->CFGR.BIT.PLLF     = (uint8_t)(20);    //VCOCLK = PREFCLK * 20 =  240 MHz              F=20 [4,40]
    RCC->CFGR.BIT.PLLK     = (uint8_t)(1-1);   //DIVCLK = VCOCLK / 1 =  240 MHz                K=1  [1,8]

    RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK
    while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

    RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

    while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL

#endif
    /*********************Now SYSCLK is 120 MHz,Config HCLK,PCLK0,PCLK1***************************/

    RCC->CFGR.BIT.HPRE = 0;  //Config AHB SYSCLK Prescaler to 1,HCLK is 120MHz
    RCC->CFGR.BIT.PPRE0 = 2; //Config APB0 PCLK0 Prescaler to 4,PCLK0 is 30MHz
    RCC->CFGR.BIT.PPRE1 = 1; //Config APB1 PCLK1 Prescaler to 2,PCLK1 is 60MHz

    RCC->RCCLOCK = 0; //LOCK RCC
}
#endif
