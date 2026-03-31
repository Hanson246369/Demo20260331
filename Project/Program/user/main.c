/**
 ******************************************************************************
 * @file    main.c
 * @author  SINOWEALTH
 * @version V1.1.0
 * @date    19-December-2019
 * @brief   uart module
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/

#ifdef _HEAD_FILE_SH32F9001
#include "sh32f9001.h"
#endif

#ifdef _HEAD_FILE_SH32F9061
#include "sh32f9061.h"
#endif

#ifdef _HEAD_FILE_SH32F9801
#include "sh32f9801.h"
#endif

#ifdef _HEAD_FILE_SH32F9861
#include "sh32f9861.h"
#endif

#ifdef _HEAD_FILE_SH32F9002
#include "sh32f9002.h"
#endif

#ifdef _HEAD_FILE_SH32F9062
#include "sh32f9062.h"
#endif

#include <string.h>
#include "uart.h"
#include "sh32f9xx_sb0_retarget.h"
#include "lcd.h"
#include "timer.h"
#include "delay.h"
#include "app.h"
#include "lpiic.h"
#include "hpiic.h"
#include "beep.h"
#include "key.h"
#include "fault.h"
#include "queue.h"
#include "adc.h"

uint8_t g_u8SwitchOnOffFlag = SW_ON;		//如果初始化为SW_OFF，当开关为ON的时候上电，程序会软件reset
uint8_t g_u8SystemResetFlag = 0;

/**
 * @brief  Main function
 * @param  None.
 * @retval None
 */
int main(void)
{
	uint8_t i = 0;
	IWDT_Enable(IWDT_Prescaler_128, 0x0FFF);//  T=0x0FFF * 64/128K = 2.05s  T=0x0FFF * 128/128K = 4.01s  
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
	TIM5_Config();
	Beep_GPIO_Config();
	LED_GPIO_Config();
	Key_GPIO_Config();
	SW_ERROR_GPIO_Config();
	
	Init_Queue(&g_stQueue);	
    UART2_Config(); //notice 以前的24M-F防爆驱动板上电后第一次会发出错误的故障信号，需要等待一定时间后才使能USART。现在的FP-24MF防爆驱动板是否还有相同的问题？  
	SensorPowerTrig_GPIO_Config();
	LP_IIC_GPIO_Init();
	HP_IIC_GPIO_Init();
	LpI2C_Init();
	HpI2C_Init();
	
	ADC_Init_Config();
	delay_ms(10);
	for(i = 0; i < ADC_FILTER_NUM; i++)
		Handle_ADCSampleTask();
	
	LSI_TURNON();// TURN ON LSI, LSI as clock source of LCD
    LCD_Config_Init(); /* LCD CONFIG */
	value_init();
	
	SoftTimer_Setup(eID_10MS, TimerDelay[eID_10MS]);
	SoftTimer_Setup(eID_100MS, TimerDelay[eID_100MS]);
	SoftTimer_Setup(eID_500MS, TimerDelay[eID_500MS]);
	
    /* Infinite loop */
    while (1)
    {
        IWDG_ReloadCounter(); // feed dog
		
		if(g_u8SwitchOnOffFlag == SW_ON)
		{
			Handle_UartReceDataFromDriver();
		}
		
		if(SOFT_TIMER_END == SoftTimer_Check(eID_10MS))
		{   
			SoftTimer_Setup(eID_10MS, TimerDelay[eID_10MS]);
			if(g_u8SwitchOnOffFlag == SW_ON)
			{
				if(MAC_STA.powerOnReady == 1)
				{
					Handle_KeyDetect();
					Handle_SwitchFaultDetect();		
				}
			}
		}  
		
		if(SOFT_TIMER_END == SoftTimer_Check(eID_100MS))
		{        	
			SoftTimer_Setup(eID_100MS, TimerDelay[eID_100MS]);		
			Handle_ADCSampleTask();
			if(g_u8SwitchOnOffFlag == SW_ON)
			{
				Handle_PressureSample();
				if(MAC_STA.powerOnReady == 1)
				{
					Handle_LPModeTask();
					Handle_FaultSummaryJudge();
					Handle_GetKey();
					Handle_BeepControl();
				}
			}
		} 
			
		if(SOFT_TIMER_END == SoftTimer_Check(eID_500MS))		
		{
			SoftTimer_Setup(eID_500MS, TimerDelay[eID_500MS]);	
			Handle_UartSendDataToDriver();
		
			if(g_u8SwitchOnOffFlag == SW_ON)
			{
				LCD_PowerOnDisplay();
				if(MAC_STA.powerOnReady == 1)
				{
					Handle_PressureZeroTask();
					Handle_DisplayFaultData();
					Handle_DisplayLPModeSetting();
					Handle_DisplayMotorRun();
					Handle_DisplayPressure();
				}
			}
		}
		
		if(g_u8SwitchOnOffFlag == SW_OFF)
			Handle_LCDOff();
		
		if(g_u8SystemResetFlag == 1)
			NVIC_SystemReset();
    }
}


/******************* (C) COPYRIGHT 2021 Sinowealth *****END OF FILE************/
