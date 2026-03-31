/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __APP_H
#define __APP_H

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"
#include "stdbool.h"
typedef enum
{
	MOTOR_OFF 			= 0,
	MOTOR_ON 			= 1
}eMOTOR_STATE_Type;

typedef enum
{
	NO_FAULT 			= 0,
	FAULT_NOW 			= 1,
	FAULT_END			= 2
}eFault_Type;

typedef struct
{	
	uint8_t powerOnReady;//
	uint8_t motorSta;
	uint8_t fault;//报警标志    0：没有故障  1：故障产生   2：故障全部恢复
}MACHINE_STATE;

typedef struct
{
	uint8_t LP;//0没有低压保护  1低压故障报警 2低压故障恢复
	uint8_t OFP;//80%满标志  
	uint8_t TP;//热保动作开关  0没动作 1有动作 2恢复  
	uint8_t HP_out;//高压硬件保护 
	uint8_t VoltageLow;//母线电压偏低 
	uint8_t VoltageHigh;
	uint8_t Over_Current;
	uint8_t VinVoltage;	//数显板输入电压检测
}MACHINE_FAULT;

typedef enum
{
	UNIT_PSI 			= 0,
	UNIT_KPA 			= 1,
	UNIT_MPA 			= 2,
	UNIT_BAR_CMHG 		= 3,
	UNIT_BAR_BAR	 	= 4,
	UNIT_MAX
}eUNIT_Type;

//LP_MODE1:表示首次低压停机的值是0psi；LP_MODE2：表示首次的值是-10inhg；LP_MODE3：表示首次的值是-20inhg；
typedef enum
{
	LP_MODE1 = 0,
	LP_MODE2 = 1,
	LP_MODE3 = 2,
	LP_MAX
}eLP_MODE_Type;

typedef enum
{
	MUTE_OFF = 0,
	MUTE_ON = 1,
}eMUTE_Type;

//保存到eeprom中的字节数必须为2的倍数
typedef struct
{		
	uint8_t unit; //
	uint8_t lpMode; //
	uint8_t mute;
	uint8_t reserve;				//预留
}MACHINE_SET;
#define E2_MACHINE_PARAM_LEN		4

//保存到eeprom中的字节数必须为2的倍数
typedef struct
{		
	int32_t lpFirstZeroValue; 
	int32_t hpFirstZeroValue; 
	int32_t lpCurZeroValue; 
	int32_t hpCurZeroValue; 
	uint8_t FirstZeroFlag;
	uint8_t reserve;				//预留
}PRESSURE_ZERO;
#define E2_PRESSURE_ZERO_LEN			(18)

//#define LP_STOP_LEV1_VALUE				(0)			//单位Pa，0Pa
#define LP_STOP_LEV2_VALUE				(-33863)	//单位Pa，-10inHg
#define LP_STOP_LEV3_VALUE				(-67727)	//单位Pa，-20inHg
#define LP_STOP_LEV_RESET_VALUE			(68947)		//单位Pa，10psi
#define LP_STOP_LEV1_CANCEL				(13789)		//单位Pa，2psi

#define LP_ZERO_RANGE_LOWER				(-16931)	//单位Pa，-5inHg	
#define LP_ZERO_RANGE_UPPER				(10000)		//单位Pa，0.1bar，也是LP_STOP_LEV1_VALUE	

#define HP_ZERO_RANGE_LOWER				(-33863)	//单位Pa，-10inHg
#define HP_ZERO_RANGE_UPPER				(10000)		//单位Pa，0.1bar	

#define DO_ZERO_ALLOW_RANGE_LOWER		(-100000)	//单位Pa，-1bar	
#define DO_ZERO_ALLOW_RANGE_UPPER		(100000)	//单位Pa，1bar

#define VACUUM_LIMIT_VALUE				(-100000)	//单位Pa，-1bar

typedef struct
{
	int32_t lpRawValue;
	int32_t hpRawValue;
	int32_t lpRealValue;
	int32_t hpRealValue;
	uint8_t lpFault;
	uint8_t hpFault;
	uint8_t NoDispFlag;//压力值不显示标志位
}PRESSURE_TypeDef;

typedef enum
{
	BEEPON 			= 1,
	BEEPMUTE 		= 2,
	CANCELALARM 	= 3			//取消当前的报警，不显示静音图标
}eBEEP_STA_Type;

typedef struct
{
	uint8_t state;
	uint8_t update;
	uint8_t cnt;
	uint8_t repeat;
	uint8_t mode1;
	uint8_t mode2;
	uint8_t mode3;
	uint8_t time1;
	uint8_t time2;
	uint8_t time3;
}BEEP_TypeDef;

#define MOTOR_SPEED_VALUE	3000
typedef struct 
{
	uint16_t SetSpeed;
	uint16_t GetSpeed;
	uint16_t nPhaseCurrent;
	uint8_t IpmTemp;
	uint8_t MotorTemp;
	uint8_t FaultCodeHigh;
	uint8_t FaultCodeLow;
	uint8_t Version;
}DRIVE_INFO_TypeDef;

typedef enum
{
	DIS_RPES_VALUE_NORMAL	= 0,
	DIS_RPES_VALUE_LPSET	= 1,
}DispPresValue_TypeDef;

extern MACHINE_STATE 	MAC_STA;
extern MACHINE_SET		MAC_SET;
extern MACHINE_FAULT	MAC_FAULT;	
extern PRESSURE_ZERO	PRS_ZERO;
extern PRESSURE_TypeDef	PRESSURE;
extern BEEP_TypeDef		BEEP;
extern DRIVE_INFO_TypeDef	g_tDriveInfo;

extern uint8_t g_OcpHardFlag;
extern uint8_t PFC_OverCurrent;
extern uint8_t motorLockedRotor;
extern uint8_t motorPhaseLoss;
extern uint8_t g_PcbaTempHighFlag;
extern uint8_t g_MotorNtcErrFlag;

extern uint8_t enterLPModeFlag;
extern uint8_t LPModeAutoQuitDelay_500ms; 
extern uint8_t g_CancelAlarmFlag;

void KeyTaskDeal(void);
void value_init(void);
void Handle_SwitchProtDetect(void);
void Handle_PressureSample(void);
void Handle_LPModeTask(void);
void Handle_FaultSummaryJudge(void);
void Handle_PressureZeroTask(void);
void Handle_DisplayFaultData(void);
void Handle_DisplayPressure(void);
void Handle_DisplayMotorRun(void);
void Handle_DisplayLPModeSetting(void);
void Handle_LCDOff(void);
#endif /* __APP_H */
