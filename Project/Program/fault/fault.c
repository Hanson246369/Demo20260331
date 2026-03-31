#include "sh32f9xx_sb0_libcfg.h"
#include "fault.h"
#include "app.h"

uint16_t g_ShieldDrvErrCnt_10ms = 0;		//当出现某个故障，硬件电路断开继电器，此时驱动板可能会误报欠压、缺相等故障。

void SW_ERROR_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHBPeriphClockOnOff(RCC_AHB_IOCLK, SH_ON);	
	
	GPIO_InitStructure.GPIO_Pin = HP_FAULT_PIN | OFP_FAULT_PIN | TP_FAULT_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
//	GPIO_InitStructure.GPIO_ODrv = GPIO_ODrv_NORMAL;
//    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(SW_FAULT_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(SW_FAULT_GPIO_PORT, HP_FAULT_PIN | OFP_FAULT_PIN | TP_FAULT_PIN, GPIO_AF_GPIO);
}


//10ms检测一次
void Handle_SwitchFaultDetect(void)
{
	static uint8_t HP_start_cnt = 0;
	static uint8_t HP_cancel_cnt = 0;
	static uint8_t OFP_start_cnt = 0;
	static uint8_t OFP_cancel_cnt = 0;
	static uint8_t TP_start_cnt = 0;
	static uint8_t TP_cancel_cnt = 0;

	if(g_ShieldDrvErrCnt_10ms > 0)
		g_ShieldDrvErrCnt_10ms--;
	
	/* ***** HP out*********/ 
	if(HP_FAULT_READ() == Bit_RESET)
	{	//38.6bar左右动作  
		HP_cancel_cnt = 0;
		if(HP_start_cnt > 30)
		{
			if(MAC_STA.motorSta == MOTOR_ON)
				g_ShieldDrvErrCnt_10ms = SHIELD_DRV_ERR_CNT;
			
			MAC_FAULT.HP_out = FAULT_NOW;
		}
		else
		{
			HP_start_cnt++;
		}	
	}
	else if(MAC_FAULT.HP_out == FAULT_NOW)
	{
		HP_start_cnt = 0;	
		if(HP_cancel_cnt > 50)
		{	
			MAC_FAULT.HP_out = FAULT_END;
		}
		else
		{
			HP_cancel_cnt++;
		}
	}
	else
	{
		HP_start_cnt = 0;
	}
	/* ***** OFP*********/
	if(OFP_FAULT_READ() == Bit_RESET)
	{	
		OFP_cancel_cnt = 0;
		if(OFP_start_cnt > 30)
		{
			if(MAC_STA.motorSta == MOTOR_ON)
				g_ShieldDrvErrCnt_10ms = SHIELD_DRV_ERR_CNT;
			
			MAC_FAULT.OFP = FAULT_NOW;
		}
		else
		{
			OFP_start_cnt++;
		}	
	}
	else if(MAC_FAULT.OFP == FAULT_NOW)
	{
		OFP_start_cnt = 0;
		if(OFP_cancel_cnt > 50)
		{	
			MAC_FAULT.OFP = FAULT_END;
		}
		else
		{
			OFP_cancel_cnt++;
		}
	}
	else
	{
		OFP_start_cnt=0;
	}  

	/* ***** TP*********/ 
	if(TP_FAULT_READ() == Bit_RESET)
	{  
		TP_cancel_cnt = 0;
		if(TP_start_cnt > 50)
		{  
			if(MAC_STA.motorSta == MOTOR_ON)
				g_ShieldDrvErrCnt_10ms = SHIELD_DRV_ERR_CNT;
			
			MAC_FAULT.TP = FAULT_NOW;
		}
		else
		{
			TP_start_cnt++;
		}	
	}
	else if(MAC_FAULT.TP == FAULT_NOW)
	{
		TP_start_cnt = 0;
		if(TP_cancel_cnt > 50)
		{
			MAC_FAULT.TP = FAULT_END;
		}
		else
		{
			TP_cancel_cnt++;
		}
	}
	else
	{
		TP_start_cnt=0;
	}
}



