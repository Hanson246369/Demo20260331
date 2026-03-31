#include "sh32f9xx_sb0_libcfg.h"
#include "beep.h"
#include "app.h"
#include "lcd.h"

void Beep_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHBPeriphClockOnOff(RCC_AHB_IOCLK, SH_ON);	
	
	GPIO_InitStructure.GPIO_Pin = BEEP_ON_OFF_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_ODrv = GPIO_ODrv_NORMAL;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(BEEP_ON_OFF_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(BEEP_ON_OFF_GPIO_PORT, BEEP_ON_OFF_PIN, GPIO_AF_GPIO);
	BEEP_OFF();
}

//mode1:短响一声，按键操作时发出
void Beep_SetMode1(void)
{
	BEEP_OFF();
	BEEP.mode1 = 1;
	BEEP.time1 = 4;
}

//mode2：长响两声，无法压力清零或者无法进入低压停机设置时发出
void Beep_SetMode2(void)
{
	BEEP.mode2 = 1;
	BEEP.time2 = 10;			
	BEEP.repeat = 4;
}

//mode3:一直响，机器报警时发出
void Beep_SetMode3(void)
{
	BEEP.mode3 = 1;
}


void Beep_ResetMode3(void)
{
	BEEP.mode3 = 0;
}

//从外部传进#1,#2,#3模式和声响时间。BEEP_STAT1.Beep_Mode3由fault决定
void Handle_BeepControl(void)
{
	static bool Flag_B1 = false;
	static bool Flag_B2 = false;
	static bool Flag_B3 = false;
	static bool B2_StatusFlag = false;
	static bool B3_StatusFlag = false;
	static uint8_t B1_DelayCnt;  
	static uint8_t B2_DelayCnt;
	static uint8_t B3_DelayCnt;

	if(MAC_STA.fault != NO_FAULT)  //如果有发生故障
	{
		if(MAC_STA.fault == FAULT_END) //所有故障恢复
		{      
			BEEP_OFF();
			Beep_ResetMode3();  
			/*
			在Handle_BeepControl()函数中，当故障恢复后，会将g_CancelAlarmFlag = false。
			但是当低压停机后，再次强制启动时，故障未恢复，在Handle_BeepControl()函数中，无法实现g_CancelAlarmFlag = false。
			只能在KeyTaskDeal()函数中，将g_CancelAlarmFlag = false;BEEP.update = 1;。
			*/
			if(g_CancelAlarmFlag == true)
			{
				g_CancelAlarmFlag = false;	//以便下次出现故障时，能够触发mode3报警声
				BEEP.update = 1;
			}
		}
		else 
		{
			if(g_CancelAlarmFlag == false)
				Beep_SetMode3(); //发生故障，#3报警
		}	
	}

	if(BEEP.update == 1)        //有新按键按下
	{
		BEEP.update = 0;
		switch(BEEP.state)
		{
			case BEEPON:
				if(MAC_SET.mute == MUTE_ON) 
				{
					if(BEEP.mode2 == 1)  
						BEEP.mode2 = 0;//进入无声模式后，#2报警方式复位
					BEEP.state = BEEPMUTE;
					BEEP.cnt = 1;//由有声转为无声，要鸣响一声，转为无声模式后，静音
					LCD_DispOrClrFlag(F_MUTE, LCD_DISP);//显示静音图标
				}
				else if(g_CancelAlarmFlag == true) 	//取消当前的mode3报警声
				{
					BEEP.state = CANCELALARM;
					BEEP.cnt = 1;//由有声转为无声，要鸣响一声，转为取消当前报警声 
					Beep_ResetMode3();
				}
				break;
			
			case BEEPMUTE:     			//处于静音状态  
				if(MAC_SET.mute == MUTE_OFF) 
				{
					BEEP.state = BEEPON;
					LCD_DispOrClrFlag(F_MUTE, LCD_CLR);//取消静音图标
				}
				break;
			
			case CANCELALARM:			//处于取消报警声状态
				if(MAC_SET.mute == MUTE_ON) //进入静音模式
				{
					LCD_DispOrClrFlag(F_MUTE, LCD_DISP);//显示静音图标
					BEEP.state = BEEPMUTE;
					BEEP.cnt = 1;//由有声转为无声，要鸣响一声，转为无声模式后，静音
				}
				else if(g_CancelAlarmFlag == false)       //原先取消了mode3报警声，等所有故障恢复后，要恢复mode3模式
				{
					BEEP.state = BEEPON;
				}
				break; 
		}
	}

	if((MAC_SET.mute == MUTE_OFF) || (BEEP.cnt == 1))//如果是有声模式下,或是在有声转无声下
	{
		if(BEEP.mode1 == 1)//是#1模式,时效到自动失效
		{
			if(Flag_B3 || Flag_B2)//#3或#2模式下进入#1模式 要延时一定时间
			{
				BEEP_OFF();
				B1_DelayCnt = 3;
				Flag_B2 = false;
				Flag_B3 = false;
				B2_StatusFlag = true;
				B3_StatusFlag = true;
				BEEP.time3 = 3;  //#3重装载
			}
			if(B1_DelayCnt == 0)
			{
				BEEP_ON();//开启蜂鸣器
				Flag_B1 = true; 
				if(BEEP.time1 == 0)//#1蜂鸣器声响时间到
				{
					BEEP_OFF();//关闭蜂鸣器
					BEEP.mode1 = 0;
					BEEP.cnt = 0;
				}
				else 
					BEEP.time1--;
			}
			else 
				B1_DelayCnt--; 
		}
		else if(BEEP.mode2 == 1)//是#2模式,时效到自动失效
		{
			if(Flag_B1)//#1模式进入#2模式，要延时一定时间
			{
				BEEP_OFF();
				B2_DelayCnt = 3;
				Flag_B1 = false;
			}
			if(B2_DelayCnt == 0)   //如果延时时间到
			{          
				Flag_B2 = true;
				if(BEEP.repeat != 0)  //#2蜂鸣器 重复次数到
				{
					if(BEEP.time2 != 0)
					{
						if(B2_StatusFlag == false) 
							BEEP_ON();
						else  
							BEEP_OFF();
						
						BEEP.time2--;  
					}
					else if(BEEP.time2 == 0)
					{
						BEEP.repeat--;
						B2_StatusFlag ^= true;
						BEEP.time2 = 10;//BEEP_STAT1.field.Beep_Reload2;  //#2重装载
					}
				}
				else //#2重复次数到
				{
					BEEP_OFF();
					BEEP.mode2 = 0;
				}
			}
			else
				B2_DelayCnt--;   
		}
		else if(BEEP.mode3 == 1)//是#3模式,当fault=FAULT_END，故障恢复时取消#3模式
		{
			if(Flag_B1 || Flag_B2)
			{
				BEEP_OFF();
				B3_DelayCnt = 3;
				Flag_B1 = false;
				Flag_B2 = false;
			}
			if(B3_DelayCnt == 0)   //如果延时时间到
			{
				Flag_B3 = true;
				if(BEEP.time3 != 0)//#3蜂鸣器声响时间到
				{
					if(B3_StatusFlag == false) 
						BEEP_ON();
					else  
						BEEP_OFF();
					
					BEEP.time3--;  
				}
				else if(BEEP.time3 == 0)
				{
					B3_StatusFlag ^= true;
					if(B3_StatusFlag == false)  
						BEEP.time3 = 3;			 //#3重装载
					else 
						BEEP.time3 = 2;
				}
			}
			else 
				B3_DelayCnt--;
		}
	}
}




