#include "sh32f9xx_sb0_libcfg.h"
#include "adc.h"
#include "delay.h"
#include "stdbool.h"
#include "fault.h"
#include "app.h"
#include "lcd.h"


#define AVDD_VALUE				(3.3)					//新的MCU的供电电压:3.3048 
#define DIVIDER_RESISTOR		((8.2+30.0)/8.2)		//新的分压电阻 

float g_SWVoltValue;
float g_VinVoltValue;

extern uint8_t g_u8SwitchOnOffFlag;
extern uint8_t g_u8SystemResetFlag;
/**
  ******************************************************************************
  * @name     static void ADC_GPIO_Config(void)
  * @brief    config as ADC
  ******************************************************************************
  */
static void ADC_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* Enable GPIOE clock */
    RCC_AHBPeriphClockOnOff(RCC_AHB_IOCLK, SH_ON);

    GPIO_InitStructure.GPIO_Pin = SW_ADC_PIN | VIN_ADC_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_ODrv = GPIO_ODrv_NORMAL;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(ADC_GPIO_PORT, &GPIO_InitStructure);

    GPIO_PinAFConfig(ADC_GPIO_PORT, SW_ADC_PIN | VIN_ADC_PIN, GPIO_AF_GPIO);
}

/**
  ******************************************************************************
  * @name     static void ADC_Mode_Config(void)
  * @brief    ADC mode config
  ******************************************************************************
  */
static void ADC_Mode_Config(void)
{
    ADC_InitTypeDef ADC_InitStructure;

    /* ADC1 configuration */
    ADC_StructInit(&ADC_InitStructure);
    /* Enable ADC clock */
    RCC_APB1PeriphClockOnOff(RCC_APB1_ADC, SH_ON);

    GPIO_PinAFConfig(ADC_GPIO_PORT, SW_ADC_PIN | VIN_ADC_PIN, GPIO_AF_ADC);

    ADC_InitStructure.ADC_ConversionMode = ADC_ConversionMode_Single;
    ADC_InitStructure.ADC_NumOfConversion = 2;
    ADC_InitStructure.ADC_Prescaler = ADC_Prescaler_16;			//36MHz的16分频
    ADC_InitStructure.ADC_RefVoltage = ADC_RefVoltage_AVDD;
    ADC_InitStructure.ADC_Resolution = ADC_Resolution_12Bit;
    ADC_InitStructure.ADC_SampleTime = ADC_SampleTime_15Cycles;
    ADC_InitStructure.ADC_SequencePointer = ADC_Sequence_0;
    ADC_InitStructure.ADC_Trigger = ADC_Trigger_Software; //ADC_Trigger_MCM2TRG1;
    ADC_InitStructure.ADC_TwoSampleGap = ADC_TwoSampleGap_4Cycles;
    ADC_Init(ADC, &ADC_InitStructure);

    ADC_ChannelConfig(ADC, SW_ADC_CHANNEL, ADC_Sequence_0, ADC_TwoSampleGap_Enable);
	ADC_ChannelConfig(ADC, VIN_ADC_CHANNEL, ADC_Sequence_1, ADC_TwoSampleGap_Enable);

    ADC_OnOff(ADC, SH_ON); //Power on ADC module

//    ADC_SoftwareStartConversion(ADC);

    /* Enable DMA after ADC conversion */
    //ADC_TriggerDMAEnable(ENABLE);
}

/**
  ******************************************************************************
  * @name     void ADC_Init_Config(void)
  * @brief    ADC initialization configure
  ******************************************************************************
  */
void ADC_Init_Config(void)
{
    ADC_GPIO_Config();
    ADC_Mode_Config();
}

void Handle_ADCSampleTask(void)
{
	static float SWRawValue[ADC_FILTER_NUM], VinRawValue[ADC_FILTER_NUM];
	static uint8_t SWNum = 0, VinNum = 0;
	float fSum = 0;
	uint16_t cnt = 0xFF;
	uint8_t i;
	ADC_SoftwareStartConversion(ADC);
	//ADC时钟为2.25Mhz时，while循环实际耗时时间约为35us
	while((ADC_GetFlagStatus(ADC, ADC_FLAG_EOC) == SH_RESET) && (cnt > 0))
	{
		cnt--;
		delay_us(10);	//实际延时15us
	}
	ADC_ClearFlag(ADC, ADC_FLAG_EOC);
	if(cnt != 0)
	{
		SWRawValue[SWNum++] = (float)ADC_GetConversionValue(ADC, ADC_Sequence_0) / 4096 * AVDD_VALUE * DIVIDER_RESISTOR;
		VinRawValue[VinNum++] = (float)ADC_GetConversionValue(ADC, ADC_Sequence_1) / 4096 * AVDD_VALUE * DIVIDER_RESISTOR;
	}
	
	if(SWNum == ADC_FILTER_NUM)
	{
		SWNum = 0;
		fSum = 0;
		for(i=0; i<ADC_FILTER_NUM; i++)
			fSum += SWRawValue[i];
		
		g_SWVoltValue = fSum / ADC_FILTER_NUM;
		
		if(g_SWVoltValue < SW_VOLT_THRESHOLD_VALUE)
		{
			g_u8SwitchOnOffFlag = SW_OFF;
			
			if(MAC_STA.motorSta == MOTOR_ON)
				g_ShieldDrvErrCnt_10ms = SHIELD_DRV_ERR_CNT;
		
			g_tDriveInfo.SetSpeed = 0;
			MAC_STA.motorSta = MOTOR_OFF;
		}
		else
		{
			if(g_u8SwitchOnOffFlag == SW_OFF)
				g_u8SystemResetFlag = 1;
		}
	}
	
	if(VinNum == ADC_FILTER_NUM)
	{
		VinNum = 0;
		fSum = 0;
		for(i=0; i<ADC_FILTER_NUM; i++)
			fSum += VinRawValue[i];
		
		g_VinVoltValue = fSum / ADC_FILTER_NUM;
		
		if(g_VinVoltValue < VIN_VOLT_THRESHOLD_VALUE)
			MAC_FAULT.VinVoltage = FAULT_NOW;	
		else if(MAC_FAULT.VinVoltage == FAULT_NOW)
			MAC_FAULT.VinVoltage = FAULT_END;
	}
}



