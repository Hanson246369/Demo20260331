/**
  ******************************************************************************
  * @file    system_sh30f9xx_sa0.c
  * @author  sinowealth
  * @version V1.1.0
  * @date    2020-11-25  
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
  * <h2><center>&copy; COPYRIGHT 2020 Sinowealth</center></h2>
  *
  ******************************************************************************
  */
#include "system_sh30f9xx_sa0.h"

/*******************************************************************************
*  Clock Definitions
*******************************************************************************/
#ifdef SYSCLK_FREQ_HSE
uint32_t SystemCoreClock = SYSCLK_FREQ_HSE; /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_HSI
uint32_t SystemCoreClock = SYSCLK_FREQ_HSI; /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_LSE
uint32_t SystemCoreClock = SYSCLK_FREQ_LSE; /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_LSI
uint32_t SystemCoreClock = SYSCLK_FREQ_LSI; /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_LSI_DIV4
uint32_t SystemCoreClock = SYSCLK_FREQ_LSI_DIV4; /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_12MHz
uint32_t SystemCoreClock = SYSCLK_FREQ_12MHz; /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_24MHz
uint32_t SystemCoreClock = SYSCLK_FREQ_24MHz; /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_36MHz
uint32_t SystemCoreClock = SYSCLK_FREQ_36MHz; /*!< System Clock Frequency (Core Clock) */
#elif defined SYSCLK_FREQ_48MHz
uint32_t SystemCoreClock = SYSCLK_FREQ_48MHz; /*!< System Clock Frequency (Core Clock) */
#endif

/*******************************************************************************
*  Private function declare
*******************************************************************************/
#ifdef SYSCLK_FREQ_HSE
static void SetSysClockToHSE(void);
#elif defined SYSCLK_FREQ_HSI
static void SetSysClockToHSI(void);
#elif defined SYSCLK_FREQ_LSE
static void SetSysClockToLSE(void);
#elif defined SYSCLK_FREQ_LSI
static void SetSysClockToLSI(void);
#elif defined SYSCLK_FREQ_LSI_DIV4
static void SetSysClockToLSI_DIV4(void);
#elif defined SYSCLK_FREQ_12MHz
static void SetSysClockTo12(void);
#elif defined SYSCLK_FREQ_24MHz
static void SetSysClockTo24(void);
#elif defined SYSCLK_FREQ_36MHz
static void SetSysClockTo36(void);
#elif defined SYSCLK_FREQ_48MHz
static void SetSysClockTo48(void);
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
    SetSysClockToHSE(); //        LSE:4-12M        SYSCLK=PLLCLK=4-12M    AHB=HCLK=4-12M    APB0=4-12M    APB1=4-12M
#elif defined SYSCLK_FREQ_HSI
    SetSysClockToHSI(); //        RC:24M           SYSCLK=PLLCLK=24M      AHB=HCLK=24M      APB0=24M      APB1=24M
#elif defined SYSCLK_FREQ_LSE
    SetSysClockToLSE(); //        LSE:32.768K      SYSCLK=PLLCLK=32.768K  AHB=HCLK=32.768K  APB0=32.768K  APB1=32.768K
#elif defined SYSCLK_FREQ_LSI
    SetSysClockToLSI(); //        RC:128K          SYSCLK=PLLCLK=128K     AHB=HCLK=128K     APB0=128K     APB1=128K
#elif defined SYSCLK_FREQ_LSI_DIV4
    SetSysClockToLSI_DIV4(); //   RC:128K/4        SYSCLK=PLLCLK=32K      AHB=HCLK=32K      APB0=32K      APB1=32K
#elif defined SYSCLK_FREQ_12MHz
    SetSysClockTo12(); //HSE:4M   RC:24M(default)  SYSCLK=PLLCLK=12M  AHB=HCLK=12M  APB0=12M  APB1=12M
#elif defined SYSCLK_FREQ_24MHz
    SetSysClockTo24(); //HSE:8M   RC:24M(default)  SYSCLK=PLLCLK=24M  AHB=HCLK=24M  APB0=24M  APB1=24M
#elif defined SYSCLK_FREQ_36MHz
    SetSysClockTo36(); //HSE:8M   RC:24M(default)  SYSCLK=PLLCLK=36M  AHB=HCLK=36M  APB0=18M  APB1=18M
#elif defined SYSCLK_FREQ_48MHz
    SetSysClockTo48(); //HSE:8M   RC:24M(default)  SYSCLK=PLLCLK=48M  AHB=HCLK=48M  APB0=24M  APB1=24M
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
    case 0x00: /* HSI used as system clock */
        SystemCoreClock = HSI_VALUE;
        break;
    case 0x01: /* PLL used as system clock */
        pllsrc = RCC->CFGR.BIT.PLLSRC;
        pllmul_f = RCC->CFGR.BIT.PLLF + 15;
        pllmul_k = RCC->CFGR.BIT.PLLK + 1;
        pllxtpre = RCC->CFGR.BIT.PLLXTPRE + 1;
        if (pllsrc) //HSE as PLL Clock input
        {
            SystemCoreClock = HSE_VALUE / pllxtpre * pllmul_f / pllmul_k / 4;
        }
        else //HSI as PLL Clock input
        {
            SystemCoreClock = HSI_VALUE / pllxtpre * pllmul_f / pllmul_k / 4;
        }
        break;
    case 0x02: /* LSE used as system clock */
        SystemCoreClock = LSE_VALUE;
        break;
    case 0x03: /* HSE used as system clock */
        SystemCoreClock = HSE_VALUE;
        break;
    case 0x04: /* LSI used as system clock */
        SystemCoreClock = LSI_VALUE;
        break;
    case 0x05: /* LSI/4 used as system clock */
        SystemCoreClock = LSI_VALUE_DIV4;
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
  * @note   This function should be used only after reset.  4M~12M
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
    RCC->HSERFB = 0X03;

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
        RCC->CFGR.BIT.HPRE = 0;  //Config AHB SYSCLK Prescaler to 0
        RCC->CFGR.BIT.PPRE0 = 0; //Config APB0 PCLK0 Prescaler to 0
        RCC->CFGR.BIT.PPRE1 = 0; //Config APB1 PCLK1 Prescaler to 0
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
  * @note   This function should be used only after reset.   24M
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

    RCC->CR.BIT.HSION = 1; //Enable HSI
    while (!RCC->CR.BIT.HSIRDY)
    {
    }; //Wait HSI Ready

    RCC->CR.BIT.SW = SYSTEM_CLK_SRC_HSI; //Switch Sysclk to HSI
    while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_HSI); //Wait Sysclock switch to HSI

    /*********************Config HCLK PCLK0 PCLK1*************************/
    RCC->CFGR.BIT.HPRE = 0;  //Config AHB SYSCLK Prescaler to 0
    RCC->CFGR.BIT.PPRE0 = 0; //Config APB0 PCLK0 Prescaler to 0
    RCC->CFGR.BIT.PPRE1 = 0; //Config APB1 PCLK1 Prescaler to 0

    RCC->RCCLOCK = 0; //RCC LOCK
}
#elif defined SYSCLK_FREQ_LSE
/**
  * @brief  Sets System clock frequency to LSE and configure HCLK, PCLK0 
  *         and PCLK1 prescalers.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
static void SetSysClockToLSE(void)
{
    __IO uint32_t StartUpCounter = 0, LSEStatus = 0;

    /*Config Flash latency and external oscillator pin and debug pin function*/
    FLASH->ACR.V32 = 0x5AA50000; // Set flash latency to 0 wait state

    RCC->RCCLOCK = 0x33CC; //Unlock RCC Config Register

    RCC->AHBENR.BIT.SYSCFGEN = 1; //Enable SYSCFG MODULE

    SYSCFG->SAFR.V32 = 0x5AA50003; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin for oscillator function

    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/
    /* Enable LSE */
    RCC->CR.V32 |= ((uint32_t)RCC_CR_LSEON);

    /* Wait till LSE is ready and if Time out is reached exit */
    do
    {
        LSEStatus = RCC->CR.V32 & RCC_CR_LSERDY;
        StartUpCounter++;
        IWDT->CLR = 0xAAAA; //Feed Dog
    } while ((LSEStatus == 0) && (StartUpCounter <= LOW_SPEED_CLOCK_STARTUP_TIMEOUT));

    if ((RCC->CR.V32 & RCC_CR_LSERDY) != 0) //LSE Startup Check
    {
        LSEStatus = (uint32_t)0x01; // LSE Startup succeed
    }
    else
    {
        LSEStatus = (uint32_t)0x00; // LSE Startup failed
    }

    if (LSEStatus) //LSE Startup succeed,Sysclock switch to LSE
    {
        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_LSE; //Switch Sysclock to LSE
        do
        {
        } while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_LSE); //Current SysClock is LSE

        /*********************Config HCLK PCLK0 PCLK1*************************/
        RCC->CFGR.BIT.HPRE = 0;  //Config AHB SYSCLK Prescaler to 0
        RCC->CFGR.BIT.PPRE0 = 0; //Config APB0 PCLK0 Prescaler to 0
        RCC->CFGR.BIT.PPRE1 = 0; //Config APB1 PCLK1 Prescaler to 0
    }
    else // HSE Startup failed, User can add here some code to deal with this error,eg switch to HSI
    {
    }
    RCC->RCCLOCK = 0;                                                                                           //LOCK RCC
    IWDT->CR.V32 = ((0x5AA5 << IWDT_CR_LOCK_Pos) | (7 << IWDT_CR_IWDTPR_Pos) | (0xFFF << IWDT_CR_IWDTRLR_Pos)); //Set iwdt reset time :512*4096/128 = 16.384s
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

    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/
    /* Enable LSE */
    RCC->CR.V32 |= ((uint32_t)RCC_CR_LSION);

    /* Wait till LSI is ready and if Time out is reached exit */
    do
    {
        LSIStatus = RCC->CR.V32 & RCC_CR_LSIRDY;
        StartUpCounter++;
        IWDT->CLR = 0xAAAA; //Feed Dog
    } while ((LSIStatus == 0) && (StartUpCounter != LOW_SPEED_CLOCK_STARTUP_TIMEOUT));

    if ((RCC->CR.V32 & RCC_CR_LSIRDY) != 0) //LSI Startup Check
    {
        LSIStatus = (uint32_t)0x01; // LSI Startup succeed
    }
    else
    {
        LSIStatus = (uint32_t)0x00; // LSI Startup failed
    }

    if (LSIStatus) //LSI Startup succeed,Sysclock switch to LSI
    {
        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_LSI; //Switch Sysclock to LSI
        do
        {
        } while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_LSI); //Current SysClock is LSI

        /*********************Config HCLK PCLK0 PCLK1*************************/
        RCC->CFGR.BIT.HPRE = 0;  //Config AHB SYSCLK Prescaler to 0
        RCC->CFGR.BIT.PPRE0 = 0; //Config APB0 PCLK0 Prescaler to 0
        RCC->CFGR.BIT.PPRE1 = 0; //Config APB1 PCLK1 Prescaler to 0
    }
    else // HSE Startup failed, User can add here some code to deal with this error,eg switch to HSI
    {
    }
    RCC->RCCLOCK = 0;                                                                                           //LOCK RCC
    IWDT->CR.V32 = ((0x5AA5 << IWDT_CR_LOCK_Pos) | (7 << IWDT_CR_IWDTPR_Pos) | (0xFFF << IWDT_CR_IWDTRLR_Pos)); //Set iwdt reset time :512*4096/128 = 16.384s
}

#elif defined SYSCLK_FREQ_LSI_DIV4
/**
  * @brief  Sets System clock frequency to LSI/4 and configure HCLK, PCLK0
  *         and PCLK1 prescalers.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
static void SetSysClockToLSI_DIV4(void)
{
    __IO uint32_t StartUpCounter = 0, LSIStatus = 0;

    /*Config Flash latency and external oscillator pin and debug pin function*/
    FLASH->ACR.V32 = 0x5AA50000; // Set flash latency to 0 wait state

    RCC->RCCLOCK = 0x33CC; //Unlock RCC Config Register

    RCC->AHBENR.BIT.SYSCFGEN = 1; //Enable SYSCFG Module Clock

    SYSCFG->SAFR.V32 = 0x5AA50000; //Unlock SYSCFG SAFR register and set XTALX1 and XTALX2 pin for GPIO function

    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/
    /* Enable LSE */
    RCC->CR.V32 |= ((uint32_t)RCC_CR_LSION);

    /* Wait till LSI is ready and if Time out is reached exit */
    do
    {
        LSIStatus = RCC->CR.V32 & RCC_CR_LSIRDY;
        StartUpCounter++;
        IWDT->CLR = 0xAAAA; //Feed Dog
    } while ((LSIStatus == 0) && (StartUpCounter != LOW_SPEED_CLOCK_STARTUP_TIMEOUT));

    if ((RCC->CR.V32 & RCC_CR_LSIRDY) != 0) //LSI Startup Check
    {
        LSIStatus = (uint32_t)0x01; // LSI Startup succeed
    }
    else
    {
        LSIStatus = (uint32_t)0x00; // LSI Startup failed
    }

    if (LSIStatus) //LSI Startup succeed,Sysclock switch to LSI
    {
        RCC->CR.BIT.SW = SYSTEM_CLK_SRC_LSI_DIV4; //Switch Sysclock to LSI/4
        do
        {
        } while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_LSI_DIV4); //Current SysClock is LSI/4

        /*********************Config HCLK PCLK0 PCLK1*************************/
        RCC->CFGR.BIT.HPRE = 0;  //Config AHB SYSCLK Prescaler to 0
        RCC->CFGR.BIT.PPRE0 = 0; //Config APB0 PCLK0 Prescaler to 0
        RCC->CFGR.BIT.PPRE1 = 0; //Config APB1 PCLK1 Prescaler to 0
    }
    else // HSE Startup failed, User can add here some code to deal with this error,eg switch to HSI
    {
    }
    RCC->RCCLOCK = 0;                                                                                           //LOCK RCC
    IWDT->CR.V32 = ((0x5AA5 << IWDT_CR_LOCK_Pos) | (7 << IWDT_CR_IWDTPR_Pos) | (0xFFF << IWDT_CR_IWDTRLR_Pos)); //Set iwdt reset time :512*4096/128 = 16.384s
}

#elif defined SYSCLK_FREQ_12MHz
/**
  * @brief  Sets System clock frequency to 24MHz and configure HCLK ,PCLK0
  *         and PCLK1 prescalers.  HSE(+PLL) = 8M  HSI = 24M
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
    RCC->HSERFB = 0X03;
    
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
        RCC->CFGR.BIT.PLLSRC = 1;                  //Select HSE as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(1 - 1); //Pre-divider 2,PLLCLKIN is HSE_VALUE
        RCC->CFGR.BIT.PLLF = (uint8_t)(24 - 15);
        RCC->CFGR.BIT.PLLK = (uint8_t)(1 - 1);

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

    /*********************Now SYSCLK is 48 MHz,Config HCLK,PCLK0,PCLK1***************************/
    RCC->CFGR.BIT.HPRE = 2;  //Config AHB SYSCLK Prescaler to 2,HCLK is 12MHz
    RCC->CFGR.BIT.PPRE0 = 0; //Config APB0 PCLK0 Prescaler to 0,PCLK0 is 12MHz
    RCC->CFGR.BIT.PPRE1 = 0; //Config APB1 PCLK1 Prescaler to 0,PCLK1 is 12MHz

#else

    SYSCFG->SAFR.V32 = 0x5AA50000; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin to GPIO function

    RCC->CR.BIT.HSION = 1; //Enable HSI
    while (!RCC->CR.BIT.HSIRDY); //Wait HSI Ready

    RCC->CR.BIT.SW = SYSTEM_CLK_SRC_HSI; //Switch Sysclk to HSI
    while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_HSI); //Wait Sysclock switch to HSI

    /*********************Now SYSCLK is 24 MHz,Config HCLK,PCLK0,PCLK1***************************/
    RCC->CFGR.BIT.HPRE = 1;  //Config AHB SYSCLK Prescaler to 1,HCLK is 12MHz
    RCC->CFGR.BIT.PPRE0 = 0; //Config APB0 PCLK0 Prescaler to 1,PCLK0 is 12MHz
    RCC->CFGR.BIT.PPRE1 = 0; //Config APB1 PCLK1 Prescaler to 1,PCLK1 is 12MHz

#endif

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
    RCC->HSERFB = 0X03;
 
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
        RCC->CFGR.BIT.PLLSRC = 1;                  //Select HSE as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(1 - 1); //Pre-divider 2,PLLCLKIN is HSE_VALUE
        RCC->CFGR.BIT.PLLF = (uint8_t)(24 - 15);
        RCC->CFGR.BIT.PLLK = (uint8_t)(2 - 1);

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
    RCC->CFGR.BIT.HPRE = 0;  //Config AHB SYSCLK Prescaler to 0,HCLK is 24MHz
    RCC->CFGR.BIT.PPRE0 = 0; //Config APB0 PCLK0 Prescaler to 0,PCLK0 is 24MHz
    RCC->CFGR.BIT.PPRE1 = 0; //Config APB1 PCLK1 Prescaler to 0,PCLK1 is 24MHz

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
    FLASH->ACR.V32 = 0x5AA50001;   // Set flash latency to 1 wait state
    RCC->RCCLOCK = 0x33CC;         //Unlock RCC Config Register
    RCC->AHBENR.BIT.SYSCFGEN = 1;  //Enable SYSCFG Module

#if HIGH_SPEED_OSCILLATOR_SOURCE
    SYSCFG->SAFR.V32 = 0x5AA50001; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin for oscillator function

    //It is conducive to crystal oscillator starting 
    RCC->CFGR.BIT.HSESEL = 0X00;
    RCC->HSERFB = 0X03;
   
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
        RCC->CFGR.BIT.PLLSRC = 1; //HSE as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(1 - 1);
        RCC->CFGR.BIT.PLLF = (uint8_t)(36 - 15);
        RCC->CFGR.BIT.PLLK = (uint8_t)(2 - 1);

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

        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(3 - 1); // PREFCLK = PLLCLKIN / 3 =  HSI / 3 = 8 MHz
        RCC->CFGR.BIT.PLLF = (uint8_t)(36 - 15);
        RCC->CFGR.BIT.PLLK = (uint8_t)(2 - 1);

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

    RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(3 - 1); // PREFCLK = PLLCLKIN / 3 =  HSI / 3 = 8 MHz
    RCC->CFGR.BIT.PLLF = (uint8_t)(36 - 15);
    RCC->CFGR.BIT.PLLK = (uint8_t)(2 - 1);

    RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK

    while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

    RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

    while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL
#endif
    /*********************Now SYSCLK is 36 MHz,Config HCLK,PCLK0,PCLK1***************************/
    RCC->CFGR.BIT.HPRE = 0;  //Config AHB SYSCLK Prescaler to 0,HCLK is 36 MHz
    RCC->CFGR.BIT.PPRE0 = 1; //Config APB0 PCLK0 Prescaler to 0,PCLK0 is 18 MHz
    RCC->CFGR.BIT.PPRE1 = 1; //Config APB1 PCLK1 Prescaler to 0,PCLK1 is 18 MHz

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
    FLASH->ACR.V32 = 0x5AA50001;   // Set flash latency to 1 wait state
    RCC->RCCLOCK = 0x33CC;         //Unlock RCC Config Register
    RCC->AHBENR.BIT.SYSCFGEN = 1;  //Enable SYSCFG Module

#if HIGH_SPEED_OSCILLATOR_SOURCE
    SYSCFG->SAFR.V32 = 0x5AA50001; //Unlock SYSCFG SAFR register and set XTAL1 and XTAL2 pin for oscillator function

    //It is conducive to crystal oscillator starting 
    RCC->CFGR.BIT.HSESEL = 0X00;
    RCC->HSERFB = 0X03;
  
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
        RCC->CFGR.BIT.PLLSRC = 1; //HSE as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(1 - 1);
        RCC->CFGR.BIT.PLLF = (uint8_t)(24 - 15);
        RCC->CFGR.BIT.PLLK = (uint8_t)(1 - 1);

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
        RCC->CFGR.BIT.PLLSRC = 0;                  //HSI as PLL clock source
        RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(4 - 1); //PREFCLK = PLLCLKIN / 4 =  HSI / 4 = 6 MHz
        RCC->CFGR.BIT.PLLF = (uint8_t)(32 - 15);
        RCC->CFGR.BIT.PLLK = (uint8_t)(1 - 1);

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
    RCC->CFGR.BIT.PLLSRC = 0;                  //HSI as PLL clock source
    RCC->CFGR.BIT.PLLXTPRE = (uint8_t)(4 - 1); //PREFCLK = PLLCLKIN / 4 =  HSI / 4 = 6 MHz
    RCC->CFGR.BIT.PLLF = (uint8_t)(32 - 15);
    RCC->CFGR.BIT.PLLK = (uint8_t)(1 - 1);

    RCC->CR.V32 |= RCC_CR_PLLON; //EANBLE PLL CLOCK

    while (!(RCC->CR.V32 & RCC_CR_PLLRDY)); //wait PLL circuit ready

    RCC->CR.BIT.SW = SYSTEM_CLK_SRC_PLL; //Switch Sysclk to PLL

    while (RCC->CR.BIT.SWS != SYSTEM_CLK_SRC_PLL); //Wait Sysclock switch to PLL
#endif

    /*********************Now SYSCLK is 48 MHz,Config HCLK,PCLK0,PCLK1***************************/
    RCC->CFGR.BIT.HPRE = 0;  //Config AHB SYSCLK Prescaler to 48 MHz
    RCC->CFGR.BIT.PPRE0 = 1; //Config APB0 PCLK0 Prescaler to 24 MHz
    RCC->CFGR.BIT.PPRE1 = 1; //Config APB1 PCLK1 Prescaler to 24 MHz

    RCC->RCCLOCK = 0; //LOCK RCC
}

#endif
