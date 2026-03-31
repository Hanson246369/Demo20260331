#include "system_sh32f9xx_sb0.h"
#include "delay.h"

static uint8_t fac_us=0;							//us延时倍乘数			   
		   
//初始化延迟函数
//SYSTICK的时钟固定为HCLK时钟的1/8
//SYSCLK:系统时钟
void delay_init()
{
	RCC_Clocks_TypeDef rcc_clocks;
	RCC_GetClocksFreq(&rcc_clocks);
	
	fac_us=rcc_clocks.hclkFreq/8000000;				//为系统时钟的1/8  
}								    

//延时nus
//nus为要延时的us数。实际延时时间是nus+5us。	    								   
void delay_us(uint32_t nus)
{		
	uint32_t temp;	    	 
	SysTick->LOAD=nus*fac_us; 					//时间加载	  		 
	SysTick->VAL=0x00;        					//清空计数器
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;	//开始倒数	  
	do
	{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));		//等待时间到达   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;	//关闭计数器
	SysTick->VAL =0X00;      					 //清空计数器	 
}

//延时nms
//nms:要延时的ms数
void delay_ms(uint16_t nms)
{
	uint32_t i;
	for(i=0;i<nms;i++) 
		delay_us(1000);
}







































