/******************** (C) COPYRIGHT 2021 sinowealth ***************************
  * @file      timer.c
  * @describe  timer Application functions         
  * @platform  target board
  * @version   V1.1.0
  * @author    SinoWealth
  * @date      7-February-2022
**********************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"
#include "timer.h"

//unit: 1ms
const uint32_t TimerDelay[eST_MAX]=
{
    10,   	//eID_10MS
	100,	//eID_100MS
	500,	//eID_500MS
};

static uint32_t m_SoftTimerTick[eST_MAX];
static uint32_t m_SoftTimerRegister;
/**
 ******************************************************************************
 * @name     void TIM5_Config(void)
 * @author   SinoWealth
 * @version  V1.1.0
 * @date     7-February-2022
 * @brief    TIMER Initialize Configuration
 ******************************************************************************
 */
void TIM5_Config(void)
{
    TIM_InitTypeDef TIM_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
    TIM_StructInit(&TIM_InitStructure);
    RCC_APB0PeriphClockOnOff(RCC_APB0_TIM5, SH_ON);

    TIM_InitStructure.TIM_Prescaler = TIM5_PRESCALER;
    TIM_InitStructure.TIM_Period = TIM5_PERIOD;
    TIM_InitStructure.TIM_CLKSource = TIM_CLKSource_PCLK;
    TIM_InitStructure.TIM_OPMode = TIM_OPMode_Continue;
    TIM_InitStructure.TIM_TCMode = TIM_TCMode_Disable;
    TIM_Init(TIM5, &TIM_InitStructure);

    TIM_INTConfig(TIM5, SH_ENABLE);

	//中断优先级NVIC设置
	NVIC_InitStructure. NVIC_IRQChannel= TIM5_IRQn;  //TIM3中断
	NVIC_InitStructure. NVIC_IRQChannelPreemptionPriority= 3;  //抢占优先级3级
	NVIC_InitStructure. NVIC_IRQChannelSubPriority= 0;  //从优先级0级
	NVIC_InitStructure. NVIC_IRQChannelCmd= SH_ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器
	
    TIM_OnOff(TIM5, SH_ON);
}

/**
 * @brief  This function handles TIM5 exception.
 * @param  None
 * @retval None
 */
void TIM5_Handler(void)
{
	uint8_t i;
	
    TIM_ClearFlag(TIM5);
    for( i = 0; i < eST_MAX; i++ )
    {
        if( m_SoftTimerTick[i] != 0 )
        {
            m_SoftTimerTick[i]--;
        }
    }
}
/**
  * @brief create software timer..
	unit: 1ms
  *
  * @param  None
  * @retval None
  */
void SoftTimer_Setup(uint8_t TimerID, uint32_t TickNum)
{
    m_SoftTimerRegister |= ( 1UL << TimerID );
    m_SoftTimerTick[TimerID] = TickNum;
}

/**
  * @brief close software timer..
  *
  * @param  None
  * @retval None
  */
void SoftTimer_Close(uint8_t TimerID)
{
    m_SoftTimerRegister &= ~( 1UL << TimerID );
    m_SoftTimerTick[TimerID] = 0x00;
}

/**
  * @brief read software timer..
	unit: 1ms;
  *
  * @param  None
  * @retval None
  */
uint32_t SoftTimer_GetTimer(uint8_t TimerID)
{
    return m_SoftTimerTick[TimerID];
}

/**
  * @brief check if software timer is timeout..
  *
  * @param  None
  * @retval None
  */
uint8_t SoftTimer_Check(uint8_t TimerID)
{
    uint8_t Status;

    /* Check TimerID state */
    if(( m_SoftTimerRegister & (1UL<<TimerID) ) == 0 )
    {
        /* TimerID is closed */
        Status = SOFT_TIMER_OFF;
    }
    else
    {
        /* TimerID is registered and enable */ 
        if( m_SoftTimerTick[TimerID] == 0 )
        {
            /* TimerID is Up */
            Status = SOFT_TIMER_END;
        }
        else
        {
            /* TimerID is Counting */
            Status = SOFT_TIMER_NOW;
        }               
    }
    return Status;
}


/******************* (C) COPYRIGHT 2020 sinowealth *****END OF FILE************/
