#include "app.h"
#include "eeprom.h"
#include "lpiic.h"
#include "hpiic.h"
#include "key.h"
#include "lcd.h"
#include "beep.h"
#include "adc.h"
#include "fault.h"

MACHINE_STATE 		MAC_STA;
MACHINE_FAULT		MAC_FAULT;	
MACHINE_SET			MAC_SET;
PRESSURE_ZERO		PRS_ZERO;
PRESSURE_TypeDef	PRESSURE;
BEEP_TypeDef		BEEP;
DRIVE_INFO_TypeDef	g_tDriveInfo;
uint8_t g_OcpHardFlag;
uint8_t PFC_OverCurrent;
uint8_t motorLockedRotor;
uint8_t motorPhaseLoss;
uint8_t g_PcbaTempHighFlag;
uint8_t g_MotorNtcErrFlag;

uint8_t enterLPModeFlag = 0;
uint8_t LPModeQuitCountDown_500ms = 0;
uint8_t LPModeAutoQuitDelay_500ms = 0;        //防止5秒后自动退出时，unit按键还处于长按状态，导致错误地进入低压设置模式。
uint8_t LP_first_flag = 0;          //低压停机模式处于哪个阶段的标志位 0：表示0psi；1：表示-10inhg；2：表示-20inhg
uint8_t LP_ProtCnt = 0;
uint8_t OnlyLPProtFlag = 0;			//只有低压停机保护，并且没有其他故障或者其他故障已消除
uint8_t g_CancelAlarmFlag = false;
uint8_t g_PrsZeroKeyFlag;
uint8_t g_OFPMonitorFlag;


void value_init(void)
{
	E2_InitSystemData();
	MAC_STA.powerOnReady = 0;
	MAC_STA.motorSta = MOTOR_OFF;
	MAC_STA.fault = NO_FAULT;		//报警标志    0：没有故障  1：故障产生  2：故障全部恢复
	LP_ProtCnt = 0;

	switch(MAC_SET.mute)
	{
		case MUTE_OFF:
			BEEP.state = BEEPON;
			break;
		
		case MUTE_ON:
			BEEP.state = BEEPMUTE;
			break;
		
		default:
		{
			BEEP.state = BEEPON;
			MAC_SET.mute = MUTE_OFF;
			E2_Write_DataStr_HalfWord(E2_USER_Sector, E2_MACHINE_PARAM_ADDR, sizeof(MAC_SET), (uint8_t *)&MAC_SET);
		}
		break;
	}

	if(MAC_SET.unit >= UNIT_MAX)
	{
		MAC_SET.unit = UNIT_BAR_BAR;
		E2_Write_DataStr_HalfWord(E2_USER_Sector, E2_MACHINE_PARAM_ADDR, sizeof(MAC_SET), (uint8_t *)&MAC_SET);
	}

	switch(MAC_SET.lpMode)
	{
		case LP_MODE1:
			LP_first_flag = 0;
			break;

		case LP_MODE2:
			LP_first_flag = 1;
			break;

		case LP_MODE3:
			LP_first_flag = 2;
			break;

		default:
		{
			MAC_SET.lpMode = LP_MODE1;
			LP_first_flag = 0;
			E2_Write_DataStr_HalfWord(E2_USER_Sector, E2_MACHINE_PARAM_ADDR, sizeof(MAC_SET), (uint8_t *)&MAC_SET); 
		}
		break;
	}
}

void KeyTaskDeal(void)
{
	switch(cur_key_no)
	{
		case KEY_POWER: 
			if(MAC_STA.motorSta == MOTOR_OFF)//电机没有启动
			{	 	
				if(MAC_STA.fault == NO_FAULT)//没有警报事件发生
				{
					g_tDriveInfo.SetSpeed = MOTOR_SPEED_VALUE;
					MAC_STA.motorSta = MOTOR_ON;
					g_OFPMonitorFlag = true;//开始OFP监控
					
					if(MAC_SET.lpMode == LP_MODE2)
					{
						if(PRESSURE.lpRealValue > LP_STOP_LEV_RESET_VALUE) //大于10psig 真空保护条件次数清零且真空模式变为-10inhg触发
							LP_first_flag = 1;//改成第一次真空保护 -10inhg
					}
					else if(MAC_SET.lpMode == LP_MODE3)
					{
						LP_first_flag = 2;//改成第一次真空保护 -20inhg
					}
					else
					{
						if(PRESSURE.lpRealValue > LP_STOP_LEV_RESET_VALUE) //大于10psig 真空保护条件次数清零且真空模式变为-10inhg触发
							LP_first_flag = 0;//改成第一次真空保护 0psi
					}
					MAC_FAULT.LP = NO_FAULT;
					LP_ProtCnt = 0;		
				}
				else if((OnlyLPProtFlag == 1) || (MAC_STA.fault == FAULT_END)) 	
				{
					g_tDriveInfo.SetSpeed = MOTOR_SPEED_VALUE;
					MAC_STA.motorSta = MOTOR_ON;
					g_OFPMonitorFlag = true;//开始OFP监控
					
					MAC_STA.fault = NO_FAULT;
					MAC_FAULT.LP = NO_FAULT;
					MAC_FAULT.OFP = NO_FAULT;
					MAC_FAULT.TP = NO_FAULT;
					MAC_FAULT.HP_out = NO_FAULT;
					MAC_FAULT.VoltageLow = NO_FAULT;
					MAC_FAULT.VoltageHigh = NO_FAULT;
					MAC_FAULT.Over_Current = NO_FAULT;
					MAC_FAULT.VinVoltage = NO_FAULT;
					// 其他故障也要清零

					if(MAC_SET.lpMode == LP_MODE2)
					{
						if(PRESSURE.lpRealValue > LP_STOP_LEV_RESET_VALUE) //大于10psig 真空保护条件次数清零且真空模式变为-10inhg触发
							LP_first_flag = 1;//改成第一次真空保护 -10inhg
					}
					else if(MAC_SET.lpMode == LP_MODE3)
					{
						LP_first_flag = 2;//改成第一次真空保护 -20inhg
					}
					else
					{
						if(PRESSURE.lpRealValue > LP_STOP_LEV_RESET_VALUE) //大于10psig 真空保护条件次数清零且真空模式变为-10inhg触发
							LP_first_flag = 0;//改成第一次真空保护 0psi
					}

					LP_ProtCnt = 0;		
					Beep_ResetMode3();  //低压停机后，再启动，需要取消mode3报警声
					/*
					在Handle_BeepControl()函数中，当故障恢复后，会将g_CancelAlarmFlag = false。
					但是当低压停机后，再次强制启动时，故障未恢复，在Handle_BeepControl()函数中，无法实现g_CancelAlarmFlag = false。
					只能在KeyTaskDeal()函数中，将g_CancelAlarmFlag = false;BEEP.update = 1;。
					*/
					g_CancelAlarmFlag = false; 
					BEEP.update = 1;
					
					LCD_ClearAllErrorFlag();
					LCD_DispOrClrFlag(F_COMPLETE, LCD_CLR);
				}
			}				  
			else if(MAC_STA.motorSta == MOTOR_ON)
			{			 	  
				g_tDriveInfo.SetSpeed = 0;
				MAC_STA.motorSta = MOTOR_OFF;
			}
			break;

		case KEY_UNIT: 
			if(enterLPModeFlag == 1)
			{  
				MAC_SET.lpMode++;
				if(MAC_SET.lpMode >= LP_MAX)
					MAC_SET.lpMode = LP_MODE1;

				E2_Write_DataStr_HalfWord(E2_USER_Sector, E2_MACHINE_PARAM_ADDR, sizeof(MAC_SET), (uint8_t *)&MAC_SET);
				LPModeQuitCountDown_500ms = 10;
				if(MAC_SET.lpMode == LP_MODE2)
					LP_first_flag = 1;//改成第一次真空保护 -10inhg
				else if(MAC_SET.lpMode == LP_MODE3)
					LP_first_flag = 2;//改成第一次真空保护 -20inhg
				else
					LP_first_flag = 0;//改成第一次真空保护 0psi
			}
			else
			{
				MAC_SET.unit++;
				if(MAC_SET.unit >= UNIT_MAX)
					MAC_SET.unit = UNIT_PSI;
				
				 E2_Write_DataStr_HalfWord(E2_USER_Sector, E2_MACHINE_PARAM_ADDR, sizeof(MAC_SET), (uint8_t *)&MAC_SET);
			}
			break;	

		case KEY_CANCEL_ALARM:
			if(BEEP.update == 0)//防止上一次更新值未读又读入新的值
			{
				BEEP.update = 1;//有新键更新
				if(MAC_SET.mute == MUTE_OFF) //
				{
					if(MAC_STA.fault == FAULT_NOW)
						g_CancelAlarmFlag = true;
				}
			}
			break;
		
		case KEY_ZERO_LONG://长按zero键 
			g_PrsZeroKeyFlag = true;
			break;
		
		case KEY_MUTE_LONG:
			if(BEEP.update == 0)//防止上一次更新值未读又读入新的值
			{
				BEEP.update = 1;//有新键更新
				if(MAC_SET.mute == MUTE_OFF)
					MAC_SET.mute = MUTE_ON;
				else
					MAC_SET.mute = MUTE_OFF;
					
				E2_Write_DataStr_HalfWord(E2_USER_Sector, E2_MACHINE_PARAM_ADDR, sizeof(MAC_SET), (uint8_t *)&MAC_SET);
			}
			break;

		case KEY_UNIT_LONG:
			if((MAC_STA.motorSta == MOTOR_OFF) && ((MAC_STA.fault == NO_FAULT) || (MAC_STA.fault == FAULT_END)) && (PRESSURE.lpFault == false) && (PRESSURE.hpFault == false))
			{   
				enterLPModeFlag = !enterLPModeFlag;
				if(enterLPModeFlag == 1)
					LPModeQuitCountDown_500ms = 10;
			}
			else
			{  
				if(MAC_SET.mute == MUTE_OFF)   //有声模式下设置#2参数
				{
					Beep_SetMode2();
				}
			}
			break;
	}
	cur_key_no=0;
}



void Handle_PressureSample(void)
{
	LPValueSample(&(PRESSURE.lpRawValue));
	HPValueSample(&(PRESSURE.hpRawValue));
	
	PRESSURE.lpRealValue = PRESSURE.lpRawValue - PRS_ZERO.lpCurZeroValue;
	PRESSURE.hpRealValue = PRESSURE.hpRawValue - PRS_ZERO.hpCurZeroValue;
	
	if((PRESSURE.lpRealValue > LP_ZERO_RANGE_LOWER) && (PRESSURE.lpRealValue < LP_ZERO_RANGE_UPPER))
		PRESSURE.lpRealValue = 0;
	
	if(PRESSURE.lpRealValue < VACUUM_LIMIT_VALUE)
		PRESSURE.lpRealValue = VACUUM_LIMIT_VALUE;
	
	if((PRESSURE.hpRealValue > HP_ZERO_RANGE_LOWER) && (PRESSURE.hpRealValue < HP_ZERO_RANGE_UPPER))
		PRESSURE.hpRealValue = 0;
	
	if(PRESSURE.hpRealValue < VACUUM_LIMIT_VALUE)
		PRESSURE.hpRealValue = VACUUM_LIMIT_VALUE;
}

//100ms执行一次
void Handle_LPModeTask(void)
{
	static uint8_t LP_CancelCnt = 0;
	static uint8_t LP_FilterCnt = 0;
	static uint8_t isLp0PsiCutoff = 0;
	int32_t temp = 0;
	
	if(LP_first_flag == 0)  
		temp = LP_ZERO_RANGE_UPPER;             //20220622，如果是第一次真空保护，则改成0.1bar 10秒后触发   
	else if(LP_first_flag == 1)   
		temp = LP_STOP_LEV2_VALUE;             //如果是第二次真空保护，则改成-10inhg 10秒后触发 
	else if(LP_first_flag == 2)  
		temp = LP_STOP_LEV3_VALUE;             		//如果是第三次真空保护，则改成-20inhg 10秒后触发 

	if(PRESSURE.lpRealValue < temp)
	{
		LP_CancelCnt = 0;
		LP_FilterCnt = 0;
		if((MAC_STA.motorSta == MOTOR_ON) && (PRESSURE.lpFault == false))//倒计时期间用户按键停止电机，低压保护取消
		{
			if(LP_ProtCnt > 100)			// 10 seconds
			{
				if(MAC_FAULT.LP == NO_FAULT)
					MAC_FAULT.LP = FAULT_NOW;// 1: 低压故障报警

				if(LP_first_flag == 0)
				{
					isLp0PsiCutoff = 1;
					LP_first_flag = 1;
				}
				else if(LP_first_flag == 1)
				{
					isLp0PsiCutoff = 0;
					LP_first_flag = 2;
				}
				else
					isLp0PsiCutoff = 0;
			} 
			else
			{
				LP_ProtCnt++;
			} 
		}
		else 
			LP_ProtCnt = 0;
		
	}
	else if((MAC_FAULT.LP == FAULT_NOW) && (((isLp0PsiCutoff == 1) && (PRESSURE.lpRealValue > LP_STOP_LEV1_CANCEL)) || ((isLp0PsiCutoff == 0) && (PRESSURE.lpRealValue > LP_ZERO_RANGE_LOWER))))
	{
		LP_ProtCnt = 0;
		LP_FilterCnt = 0;
		if(LP_CancelCnt > 5)
		{  
			MAC_FAULT.LP = FAULT_END;//LP=2：低压故障恢复
		}
		else
		{
			LP_CancelCnt++;
		}
	}
	else
	{
		if(LP_FilterCnt > 3)    
			LP_ProtCnt = 0;    //采用滤波来避免偶发干扰因素对10秒触发低压保护的影响
		else 
			LP_FilterCnt++;
	}
}

void Handle_FaultSummaryJudge(void)
{
	uint8_t faultNowFlag = false, faultEndFlag = false;
	
	//1：表示当前有故障
	faultNowFlag = ((MAC_FAULT.LP == FAULT_NOW) || (MAC_FAULT.HP_out == FAULT_NOW) || (MAC_FAULT.OFP == FAULT_NOW) || (MAC_FAULT.TP == FAULT_NOW) 
	|| (MAC_FAULT.VoltageHigh == FAULT_NOW) || (MAC_FAULT.VoltageLow == FAULT_NOW) || (MAC_FAULT.Over_Current == FAULT_NOW) || (MAC_FAULT.VinVoltage == FAULT_NOW));
	
	if(faultNowFlag == true)
	{
		MAC_STA.fault = FAULT_NOW;
		g_tDriveInfo.SetSpeed = 0;
		MAC_STA.motorSta = MOTOR_OFF;
	}
	else
	{
		//1:表示全部故障已消除；
		faultEndFlag = ((MAC_FAULT.LP == FAULT_END) || (MAC_FAULT.HP_out == FAULT_END) || (MAC_FAULT.OFP == FAULT_END) || (MAC_FAULT.TP == FAULT_END) 
		|| (MAC_FAULT.VoltageHigh == FAULT_END) || (MAC_FAULT.VoltageLow == FAULT_END) || (MAC_FAULT.Over_Current == FAULT_END) || (MAC_FAULT.VinVoltage == FAULT_END));
		
		if(faultEndFlag == true)
			MAC_STA.fault = FAULT_END;
	}
	
	//只有低压停机保护触发，没有其他故障或者其他故障已消除
	if((MAC_FAULT.LP == FAULT_NOW) && (MAC_FAULT.HP_out != FAULT_NOW) && (MAC_FAULT.OFP != FAULT_NOW) && (MAC_FAULT.TP != FAULT_NOW) 
		&& (MAC_FAULT.VoltageHigh != FAULT_NOW) && (MAC_FAULT.VoltageLow != FAULT_NOW) && (MAC_FAULT.Over_Current != FAULT_NOW) && (MAC_FAULT.VinVoltage != FAULT_NOW))
	{
		OnlyLPProtFlag = 1;
	}
	else
		OnlyLPProtFlag = 0;
}

void Handle_PressureZeroTask(void)
{  
	uint8_t input_error = 0;
	uint8_t output_error = 0;
	uint8_t pz_runFlag = 0;
	static uint8_t pz_errorDispCnt = 0;
 
	if(g_PrsZeroKeyFlag == true)
	{   
		g_PrsZeroKeyFlag = false;
		if((MAC_STA.motorSta == MOTOR_ON) || (MAC_STA.fault == FAULT_NOW))
		{
			pz_runFlag = 1;
			pz_errorDispCnt = 6;
		}

		if((PRESSURE.lpRawValue > (DO_ZERO_ALLOW_RANGE_LOWER + PRS_ZERO.lpFirstZeroValue)) && 
			(PRESSURE.lpRawValue < (DO_ZERO_ALLOW_RANGE_UPPER + PRS_ZERO.lpFirstZeroValue)) && (PRESSURE.lpFault == false)) //如果输入压力在-1bar---1bar之间，可以调零
		{
			input_error = 0;
		}
		else 
			input_error = 1;		//超出校正范围
		
		if((PRESSURE.hpRawValue < (DO_ZERO_ALLOW_RANGE_UPPER + PRS_ZERO.hpFirstZeroValue)) && (PRESSURE.hpFault == false)) //如果输出压力小于1bar，可以调零
		{
			output_error = 0;
		}
		else 
			output_error = 1;		//超出校正范围

		if(input_error || output_error)//如果输入输出压力超出校正范围
		{
			if(MAC_SET.mute == 0)   //有声模式下设置#2参数
			{
				Beep_SetMode2();
			}
			pz_errorDispCnt = 6;
		}  
		else
		{
			if(pz_runFlag == 0)
			{
				PRS_ZERO.lpCurZeroValue = PRESSURE.lpRawValue;
				PRS_ZERO.hpCurZeroValue = PRESSURE.hpRawValue;
				
				if(PRS_ZERO.FirstZeroFlag != E2_FIRST_PRS_ZERO_FLAG)
				{
					PRS_ZERO.lpFirstZeroValue = PRESSURE.lpRawValue;
					PRS_ZERO.hpFirstZeroValue = PRESSURE.hpRawValue;
					PRS_ZERO.FirstZeroFlag = E2_FIRST_PRS_ZERO_FLAG;
				}
				E2_Write_DataStr_HalfWord(E2_USER_Sector, E2_PRESSURE_ZERO_ADDR, sizeof(PRS_ZERO), (uint8_t *)&PRS_ZERO);
				//是否需要将PRS_ZERO.FirstZeroFlag读出来，再次确认？如果只是读出来，不进行数据对比就直接使用，可能导致更差的结果。
			}
		}    
	}

	if(pz_errorDispCnt > 0)//调零超出范围
	{
		if((PRESSURE.lpFault == false) && (PRESSURE.hpFault == false))
		{
			PRESSURE.NoDispFlag = 1; 
			pz_errorDispCnt--;
			if(input_error == 1)     
				LCD_DispOrClrFlag(F_INPUT, LCD_DISP);	//显示input	
			
			if(output_error == 1)    
				LCD_DispOrClrFlag(F_OUTPUT, LCD_DISP);	//显示output
			
			LCD_DispOrClrFlag(F_CLOSED, LCD_DISP);		//显示closed
			LCD_DispNumSpecialCode(NUM_CODE_ZEROERR, LP_HP_AREA);
		}
		else
			pz_errorDispCnt = 0;
	}
	else //不显示 “input output closed ”
	{
		LCD_DispOrClrFlag(F_INPUT, LCD_CLR);
		LCD_DispOrClrFlag(F_OUTPUT, LCD_CLR);
		LCD_DispOrClrFlag(F_CLOSED, LCD_CLR);
	}
}	

void Handle_DisplayFaultData(void)
{
	static bool Temp_flag;				//清除所有故障代码的标志位
	static uint8_t ErTurn_temp = 0;		//OK-TO-START闪烁
	static bool Twink_status = 1;  		//OK-TO-START闪烁
	static uint8_t E4ErTurn_temp = 0;	//过流保护和OFP插头未插故障代码闪烁
	static bool E4Twink_status = 1;		//过流保护和OFP插头未插故障代码闪烁
	
	if(PRESSURE.lpFault == true)  
		LCD_DispNumSpecialCode(NUM_CODE_E1, LP_AREA);
	
	if(PRESSURE.hpFault == true)  
		LCD_DispNumSpecialCode(NUM_CODE_E1, HP_AREA);
	
	if(MAC_STA.fault == FAULT_NOW)
	{
		LCD_DispOrClrFlag(F_OK_TO_START, LCD_CLR);
		
		
		if(MAC_FAULT.VinVoltage == FAULT_NOW)
		{
			ErTurn_temp = 0; 
			LCD_DispOrClrFlag(F_MOTOR, LCD_DISP);
			LCD_DispOrClrFlag(F_FAULT, LCD_DISP);
			LCD_DispOrClrFlag(F_FAULT_3, LCD_DISP);// Motor Fault 3
		}
		
		if(g_OFPMonitorFlag == true)//充满80%
		{
			if(MAC_FAULT.OFP == FAULT_NOW) 
			{
				ErTurn_temp = 0; 
				LCD_DispOrClrFlag(F_TANK_FULL, LCD_DISP);
			}
		}     

		if(MAC_FAULT.HP_out == FAULT_NOW) 
		{
			ErTurn_temp = 0; 
			LCD_DispOrClrFlag(F_PRS_HIGH, LCD_DISP);
			LCD_DispOrClrFlag(F_PRESSURE, LCD_DISP);
			LCD_DispOrClrFlag(F_CUTOFF, LCD_DISP);
		}
		else if(MAC_FAULT.TP == FAULT_NOW) 
		{
			ErTurn_temp = 0; 
			LCD_DispOrClrFlag(F_MOTOR, LCD_DISP);
			LCD_DispOrClrFlag(F_FAULT, LCD_DISP);
			LCD_DispOrClrFlag(F_FAULT_1, LCD_DISP);//motor fault 1
		}
		else if((MAC_FAULT.Over_Current == FAULT_NOW) || (MAC_FAULT.OFP == FAULT_NOW)) //过流保护或者OFP插头未插
		{
			ErTurn_temp = 0; 
			
			if(E4ErTurn_temp <= 1) 
			{
				E4ErTurn_temp++;
			}
			else  
			{
				E4ErTurn_temp = 0; 
				E4Twink_status ^= 1;
			}
			
			if(g_OFPMonitorFlag == false)//未开始回收
			{
				if(MAC_FAULT.OFP == FAULT_NOW)
				{
					LCD_DispOrClrFlag(F_FAULT, LCD_DISP);
					LCD_DispOrClrFlag(F_FAULT_3, LCD_DISP);//fault 3
					if(E4Twink_status == 1) //与压力值每秒切换显示
					{
						PRESSURE.NoDispFlag = 1;
						LCD_DispNumSpecialCode(NUM_CODE_PLGUOFS, LP_HP_AREA);
					}
				}
			}
			if(MAC_FAULT.Over_Current == FAULT_NOW)
			{
				
				LCD_DispOrClrFlag(F_MOTOR, LCD_DISP);
				LCD_DispOrClrFlag(F_FAULT, LCD_DISP);
				LCD_DispOrClrFlag(F_FAULT_2, LCD_DISP);//motor fault 2
				if(E4Twink_status == 1) //与压力值每秒切换显示
				{
					PRESSURE.NoDispFlag = 1;
					LCD_DispNumSpecialCode(NUM_CODE_THROTTLE, LP_HP_AREA);
				}
			}
		}
		else if(MAC_FAULT.VoltageHigh == FAULT_NOW)
		{
			ErTurn_temp = 0; 
			LCD_DispOrClrFlag(F_VOL_HIGH, LCD_DISP);
			LCD_DispOrClrFlag(F_VOLTAGE, LCD_DISP);
			LCD_DispOrClrFlag(F_WARNING, LCD_DISP);//
		}
		else if(MAC_FAULT.VoltageLow == FAULT_NOW)  
		{
			ErTurn_temp = 0; 
			LCD_DispOrClrFlag(F_VOL_LOW, LCD_DISP);
			LCD_DispOrClrFlag(F_VOLTAGE, LCD_DISP);
			LCD_DispOrClrFlag(F_WARNING, LCD_DISP);//
		}
		else if(MAC_FAULT.LP == FAULT_NOW) 
		{
			ErTurn_temp = 0;
			LCD_DispOrClrFlag(F_COMPLETE, LCD_DISP);
			LCD_DispOrClrFlag(F_PRS_LOW, LCD_DISP);
			LCD_DispOrClrFlag(F_PRESSURE, LCD_DISP);//
			LCD_DispOrClrFlag(F_CUTOFF, LCD_DISP);//
		}
	}
	else if(MAC_STA.fault == NO_FAULT)     //没有故障     
	{
		if(Temp_flag == 0)
		{
			Temp_flag = 1;
			LCD_ClearAllErrorFlag();
		}
	}
	else if(MAC_STA.fault == FAULT_END)    //故障全部恢复
	{
		Temp_flag = 0;
		LCD_DispOrClrFlag(F_COMPLETE, LCD_CLR);//清掉COMPLETE
		if(ErTurn_temp <= 1) 
		{
			ErTurn_temp++;
		}
		else  
		{
			ErTurn_temp = 0; 
			Twink_status ^= 1;
		}
		if(Twink_status == 0)  //清空信息
		{
			LCD_DispOrClrFlag(F_OK_TO_START, LCD_CLR);
		}
		else              //显示相应信息 OK-TO-START
		{
			LCD_DispOrClrFlag(F_OK_TO_START, LCD_DISP);
		}
	}
	if(MAC_STA.motorSta == MOTOR_OFF)//停机状态下 
	{
		if((MAC_STA.fault == NO_FAULT) || (MAC_STA.fault == FAULT_END) )//没有任何故障
		{
			g_OFPMonitorFlag = false;
		}
		else
		{
			if(MAC_FAULT.OFP == NO_FAULT)//OFP没有故障
			{      
				g_OFPMonitorFlag = false;
			}  
		}
	}
}

void SetResolutionFive(int32_t *value)
{	
	uint8_t minusFlag = false;
	if(*value < 0)
	{
		minusFlag = true;
		(*value) *= (-1);
	}
	
	if((*value % 10) < 5)
		*value -= *value % 10;
	else
		*value = *value + 5 - *value % 10;
	
	if(minusFlag == true)
		(*value) *= (-1);
}

void DisplayPressureValue(int32_t value, uint8_t pos, uint8_t uint, DispPresValue_TypeDef DispType)
{
	uint8_t cnts = 0;
	uint8_t minusFlag = false;

	if(value < 0)
	{
		minusFlag = true;
		value *= (-1);
	}
	
	if(value < 10) //判断有效位数是多少
		cnts = 1;
	else if(value < 100)
		cnts = 2;
	else if(value < 1000)
		cnts = 3;
	else if(value < 10000)
		cnts = 4;
	else
	{
		value = 9999;
		cnts = 4;
	}
	
	if(pos == LP_AREA)// 低压侧
	{
		LCD_ClearNumAndFlag(LP_AREA, CLR_SYMBOL_ALL);
		if(minusFlag == true)
			LCD_DispOrClrFlag(F_LP_MINUS, LCD_DISP);
		
		switch (uint)
        {
        	case UNIT_PSI:
				if(DispType == DIS_RPES_VALUE_LPSET)
					LCD_DispOrClrFlag(F_LP_INHG, LCD_DISP);
				else
				{
					if(minusFlag == false)
						LCD_DispOrClrFlag(F_LP_PSIG, LCD_DISP);
					else
						LCD_DispOrClrFlag(F_LP_INHG, LCD_DISP);
				}
        		break;
			
        	case UNIT_KPA:
				if(DispType == DIS_RPES_VALUE_LPSET)
					LCD_DispOrClrFlag(F_LP_CMHG, LCD_DISP);
				else
				{
					if(minusFlag == false)
						LCD_DispOrClrFlag(F_LP_KPA, LCD_DISP);
					else
						LCD_DispOrClrFlag(F_LP_CMHG, LCD_DISP);
				}
        		break;
			
			case UNIT_MPA:
				if(DispType == DIS_RPES_VALUE_LPSET)
					LCD_DispOrClrFlag(F_LP_CMHG, LCD_DISP);
				else
				{
					if(minusFlag == false)
					{
						LCD_DispOrClrFlag(F_LP_P1, LCD_DISP);
						LCD_DispOrClrFlag(F_LP_MPA, LCD_DISP);
						if(cnts < 3)//如果有效位数如果为1位，前面要显示2个0
							cnts = 3;	
					}
					else
						LCD_DispOrClrFlag(F_LP_CMHG, LCD_DISP);
				}
        		break;
			
			case UNIT_BAR_CMHG:
				if(DispType == DIS_RPES_VALUE_LPSET)
					LCD_DispOrClrFlag(F_LP_CMHG, LCD_DISP);
				else
				{
					if(minusFlag == false)
					{
						LCD_DispOrClrFlag(F_LP_P1, LCD_DISP);
						LCD_DispOrClrFlag(F_LP_BAR, LCD_DISP);
						if(cnts < 3)//如果有效位数如果为1位，前面要显示2个0
							cnts = 3;	
					}
					else
						LCD_DispOrClrFlag(F_LP_CMHG, LCD_DISP);
				}
        		break;
			
			case UNIT_BAR_BAR:
				if(DispType == DIS_RPES_VALUE_LPSET)
				{
					LCD_DispOrClrFlag(F_LP_BAR, LCD_DISP);
					if(value != 0)
					{	
						LCD_DispOrClrFlag(F_LP_P1, LCD_DISP);
						if(cnts < 3)//如果有效位数如果为1位，前面要显示2个0
							cnts = 3;
					}
				}
				else
				{					
					LCD_DispOrClrFlag(F_LP_P1, LCD_DISP);
					LCD_DispOrClrFlag(F_LP_BAR, LCD_DISP);
					if(cnts < 3)//如果有效位数如果为1位，前面要显示2个0
						cnts = 3;
				}				
        		break;
			
        	default:
        		break;
        }
		
		switch(cnts)
		{
			case 4:
				LCD_DispNum(LCD_NUM_CODE[value % 10000 / 1000], LP_AREA_1);
		
			case 3:
				LCD_DispNum(LCD_NUM_CODE[value%1000/100], LP_AREA_2);

			case 2:
				LCD_DispNum(LCD_NUM_CODE[value%100/10], LP_AREA_3);

			case 1: 
				LCD_DispNum(LCD_NUM_CODE[value%10], LP_AREA_4);
				break;

			default:
				break;
		}
	}
	else if(pos == HP_AREA)// 低压侧
	{	
		LCD_ClearNumAndFlag(HP_AREA, CLR_SYMBOL_ALL);
		if(minusFlag == true)
			LCD_DispOrClrFlag(F_HP_MINUS, LCD_DISP);
		
		switch (uint)
        {
        	case UNIT_PSI:
				if(minusFlag == false)
					LCD_DispOrClrFlag(F_HP_PSIG, LCD_DISP);
				else
					LCD_DispOrClrFlag(F_HP_INHG, LCD_DISP);
        		break;
			
        	case UNIT_KPA:
				if(minusFlag == false)
					LCD_DispOrClrFlag(F_HP_KPA, LCD_DISP);
				else
					LCD_DispOrClrFlag(F_HP_CMHG, LCD_DISP);
        		break;
			
			case UNIT_MPA:
				if(minusFlag == false)
				{
					LCD_DispOrClrFlag(F_HP_P3, LCD_DISP);
					LCD_DispOrClrFlag(F_HP_MPA, LCD_DISP);
					if(cnts < 3)//如果有效位数如果为1位，前面要显示2个0
						cnts = 3;	
				}
				else
					LCD_DispOrClrFlag(F_HP_CMHG, LCD_DISP);
        		break;
			
			case UNIT_BAR_CMHG:
				if(minusFlag == false)
				{
					LCD_DispOrClrFlag(F_HP_P3, LCD_DISP);
					LCD_DispOrClrFlag(F_HP_BAR, LCD_DISP);
					if(cnts < 3)//如果有效位数如果为1位，前面要显示2个0
						cnts = 3;	
				}
				else
					LCD_DispOrClrFlag(F_HP_CMHG, LCD_DISP);
        		break;
			
			case UNIT_BAR_BAR:
				LCD_DispOrClrFlag(F_HP_P3, LCD_DISP);
				LCD_DispOrClrFlag(F_HP_BAR, LCD_DISP);
				if(cnts < 3)//如果有效位数如果为1位，前面要显示2个0
						cnts = 3;	
        		break;
			
        	default:
        		break;
        }
		
		switch(cnts)
		{
			case 4:
				LCD_DispNum(LCD_NUM_CODE[value % 10000 / 1000], HP_AREA_1);
			
			case 3:
				LCD_DispNum(LCD_NUM_CODE[value%1000/100], HP_AREA_2);

			case 2:
				LCD_DispNum(LCD_NUM_CODE[value%100/10], HP_AREA_3);

			case 1: 
				LCD_DispNum(LCD_NUM_CODE[value%10], HP_AREA_4);
				break;

			default:
				break;
		}
	}
}


//bar:0.05 psi:1 kpa:5 mpa:0.01 cmhg:1 inhg:1  
void Handle_DisplayPressure(void)
{
	int32_t lpDispValue, hpDispValue;

	//Test 压力数值显示测试代码
	//bar:0.05 psi:1 kpa:5 mpa:0.01 cmhg:1 inhg:1 
	//	UNIT_PSI/inHg:{-9999, -2661, -200, -6, -2, 0, 0, 8, 17, 1144, 9999}
	//	UNIT_KPA/cmHg:{-9999, -6759, -509, -17, -5, 0, 0, 55, 120, 7890, 9999}
	//	UNIT_MPA/cmHg:{-9999, -6759, -509, -17, -5, 0, 0, 0.05, 0.12, 7.89, 99.99}
	//	UNIT_BAR_CMHG:{-9999, -6759, -509, -17, -5, 0, 0, 0.55, 1.20, 78.90, 99.99}
	//	UNIT_BAR_BAR: {-99.99, -90.10, -6.75, -0.20, -0.05, 0, 0, 0.55, 1.20, 78.90, 99.99}
//	{	
//		static int32_t temp_value[11]={-99999999, -9012345, -678901, -23456, -7890, 0, 1234, 56789, 123456, 7890123, 99999999};
//		static uint8_t temp_i = 0;
//		static uint32_t temp_time = 0;
//		temp_time++;
//		if(temp_time > 6)
//		{
//			temp_time = 0;
//			temp_i++;
//			if(temp_i == 11)
//				temp_i = 0;
//		}
//		PRESSURE.lpRealValue = PRESSURE.hpRealValue = temp_value[temp_i];
//	}
	
	if(PRESSURE.NoDispFlag == 0)
	{
		switch(MAC_SET.unit)
		{
			case UNIT_PSI:
				if(PRESSURE.lpRealValue >= 0)
					lpDispValue = ((float)PRESSURE.lpRealValue)*14.5/100000;	//psi,X1,分辨率:1
				else
					lpDispValue = ((float)PRESSURE.lpRealValue)*29.53/100000;	//inHg,X1,分辨率:1
				
				if(PRESSURE.hpRealValue >= 0)
					hpDispValue = ((float)PRESSURE.hpRealValue)*14.5/100000;	//psi,X1,分辨率:1
				else
					hpDispValue = ((float)PRESSURE.hpRealValue)*29.53/100000;	//inHg,X1,分辨率:1
				break;
			
			case UNIT_KPA:	
				if(PRESSURE.lpRealValue >= 0)
				{
					lpDispValue = PRESSURE.lpRealValue/1000;		//Kpa,X1,分辨率:5
					SetResolutionFive(&lpDispValue);
				}
				else
					lpDispValue = ((float)PRESSURE.lpRealValue)*75.006/100000;	//cmHg,,X1,分辨率:1
				
				if(PRESSURE.hpRealValue >= 0)
				{
					hpDispValue = PRESSURE.hpRealValue/1000;		//Kpa,X1,分辨率:5
					SetResolutionFive(&hpDispValue);
				}
				else
					hpDispValue = ((float)PRESSURE.hpRealValue)*75.006/100000;	//cmHg,X1,分辨率:1
				break;
			
			case UNIT_MPA:
				if(PRESSURE.lpRealValue >= 0)
					lpDispValue = PRESSURE.lpRealValue/10000;		//Mpa,X100,分辨率:0.01
				else
					lpDispValue = ((float)PRESSURE.lpRealValue)*75.006/100000;	//cmHg,X1,分辨率:1
				
				if(PRESSURE.hpRealValue >= 0)
					hpDispValue = PRESSURE.hpRealValue/10000;		//Mpa,X100,分辨率:0.01
				else
					hpDispValue = ((float)PRESSURE.hpRealValue)*75.006/100000;	//cmHg,X1,分辨率:1
				break;
			
			case UNIT_BAR_CMHG://正压单位是bar 负压单位是cmhg
				if(PRESSURE.lpRealValue >= 0)
				{
					lpDispValue = PRESSURE.lpRealValue/1000;		//bar,X100,分辨率:0.05
					SetResolutionFive(&lpDispValue);
				}
				else
					lpDispValue = ((float)PRESSURE.lpRealValue)*75.006/100000;	//cmHg,X1,分辨率:1
				
				if(PRESSURE.hpRealValue >= 0)
				{
					hpDispValue = PRESSURE.hpRealValue/1000;		//bar,X100,分辨率:0.05
					SetResolutionFive(&hpDispValue);
				}
				else
					hpDispValue = ((float)PRESSURE.hpRealValue)*75.006/100000;	//cmHg,,X1,分辨率:1
				break;
				
			case UNIT_BAR_BAR://正压单位是bar 负压单位是bar
					lpDispValue = PRESSURE.lpRealValue/1000;		//bar,X100,分辨率:0.05
					SetResolutionFive(&lpDispValue);
					hpDispValue = PRESSURE.hpRealValue/1000;		//bar,X100,分辨率:0.05
					SetResolutionFive(&hpDispValue);
				break;
			
			default:
				break;
		}   

		if(enterLPModeFlag == 0)
		{  
			if(PRESSURE.lpFault == false)
			{	
				DisplayPressureValue(lpDispValue, LP_AREA, MAC_SET.unit, DIS_RPES_VALUE_NORMAL);
			}
			
			if(PRESSURE.hpFault == false)
			{	
				DisplayPressureValue(hpDispValue, HP_AREA, MAC_SET.unit, DIS_RPES_VALUE_NORMAL);
			}
		}
	}
	PRESSURE.NoDispFlag = 0;    //液晶数字显示区域默认显示压力值
}

void Handle_DisplayMotorRun(void)
{
	static uint8_t Motor_runFlag = F_M1;

	if((MAC_STA.fault == NO_FAULT) && (MAC_STA.motorSta == MOTOR_ON))//电机启动时，M圈转动
	{
		LCD_ClearAllMotorFlag();
		LCD_DispOrClrFlag(Motor_runFlag, LCD_DISP);
		Motor_runFlag++; 
		if(Motor_runFlag > F_M3)
			Motor_runFlag = F_M1;
		
		LCD_DispOrClrFlag(Motor_runFlag, LCD_DISP);
	}
}

/*
设置低压模式时，显示的单位和数值如下：
inHg:0,-10,-20
bar:0,-0.34,-0.68
cmHg:0,-25,-51
*/
#define LP_MODE1_DISP_VALUE				(0)
#define LP_MODE2_DISP_VALUE_INHG		(-10)
#define LP_MODE2_DISP_VALUE_BAR			(-34)
#define LP_MODE2_DISP_VALUE_CMHG		(-25)
#define LP_MODE3_DISP_VALUE_INHG		(-20)
#define LP_MODE3_DISP_VALUE_BAR			(-68)
#define LP_MODE3_DISP_VALUE_CMHG		(-51)

void Handle_DisplayLPModeSetting(void)
{
	static uint8_t timeCnt = 0;

	if(LPModeAutoQuitDelay_500ms > 0)
		LPModeAutoQuitDelay_500ms--;

	if(enterLPModeFlag == 1)
	{
		if(LPModeQuitCountDown_500ms > 0)
			LPModeQuitCountDown_500ms--;
		else
		{
			LPModeAutoQuitDelay_500ms = 6;
			enterLPModeFlag = 0;
		}

		if(timeCnt % 4 < 2)
		{    
			if(MAC_SET.lpMode == LP_MODE1)
			{
				if(MAC_SET.unit == UNIT_PSI)
					DisplayPressureValue(LP_MODE1_DISP_VALUE, LP_AREA, MAC_SET.unit, DIS_RPES_VALUE_LPSET);        //0inhg
				else if(MAC_SET.unit == UNIT_BAR_BAR)
					DisplayPressureValue(LP_MODE1_DISP_VALUE, LP_AREA, MAC_SET.unit, DIS_RPES_VALUE_LPSET);        //0bar
				else
					DisplayPressureValue(LP_MODE1_DISP_VALUE, LP_AREA, MAC_SET.unit, DIS_RPES_VALUE_LPSET);          //0cmhg
			}
			else if(MAC_SET.lpMode == LP_MODE2)
			{
				if(MAC_SET.unit == UNIT_PSI)
					DisplayPressureValue(LP_MODE2_DISP_VALUE_INHG, LP_AREA, MAC_SET.unit, DIS_RPES_VALUE_LPSET);        //-10inhg
				else if(MAC_SET.unit == UNIT_BAR_BAR)
					DisplayPressureValue(LP_MODE2_DISP_VALUE_BAR, LP_AREA, MAC_SET.unit, DIS_RPES_VALUE_LPSET);        //-0.34bar
				else
					DisplayPressureValue(LP_MODE2_DISP_VALUE_CMHG, LP_AREA, MAC_SET.unit, DIS_RPES_VALUE_LPSET);          //-25cmhg
			}
			else if(MAC_SET.lpMode == LP_MODE3)
			{
				if(MAC_SET.unit == UNIT_PSI)
					DisplayPressureValue(LP_MODE3_DISP_VALUE_INHG, LP_AREA, MAC_SET.unit, DIS_RPES_VALUE_LPSET);        //-20inhg
				else if(MAC_SET.unit == UNIT_BAR_BAR)
					DisplayPressureValue(LP_MODE3_DISP_VALUE_BAR, LP_AREA, MAC_SET.unit, DIS_RPES_VALUE_LPSET);        //-0.68bar
				else
					DisplayPressureValue(LP_MODE3_DISP_VALUE_CMHG, LP_AREA, MAC_SET.unit, DIS_RPES_VALUE_LPSET);          //-51cmhg
			}
		}
		else
		{
			LCD_ClearNumAndFlag(LP_AREA, CLR_SYMBOL_MINUS_POINT);
                 
		}
		timeCnt++;
		LCD_DispNumSpecialCode(NUM_CODE_STOP, HP_AREA);
		PRESSURE.NoDispFlag=1;
	}
	else 
	{
		timeCnt = 0;
	}
}

void Handle_LCDOff(void)
{
	BEEP_OFF();
	LED_CTL_OFF();
	LCD_OnOff(SH_OFF);
}

