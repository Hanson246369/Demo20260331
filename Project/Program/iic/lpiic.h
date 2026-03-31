#ifndef _LPIIC_H
#define _LPIIC_H

#include "sh32f9xx_sb0_libcfg.h" 	

#define LP_IIC_SCL_PIN						GPIO_Pin_0
#define LP_IIC_SDA_PIN						GPIO_Pin_1
#define LP_IIC_PORT							GPIOB

#define LP_IIC_SCL_H()						GPIO_SetBits(LP_IIC_PORT, LP_IIC_SCL_PIN)
#define LP_IIC_SCL_L()						GPIO_ResetBits(LP_IIC_PORT, LP_IIC_SCL_PIN)

#define LP_IIC_SDA_H()						GPIO_SetBits(LP_IIC_PORT, LP_IIC_SDA_PIN)
#define LP_IIC_SDA_L()						GPIO_ResetBits(LP_IIC_PORT, LP_IIC_SDA_PIN)
#define LP_IIC_SDA_READ()					GPIO_ReadInputDataBit(LP_IIC_PORT, LP_IIC_SDA_PIN)

#define SENSOR_POWER_TRIG_PIN				GPIO_Pin_9
#define SENSOR_POWER_TRIG_GPIO_PORT			GPIOE
#define SENSOR_POWER_TRIG_ON()				GPIO_SetBits(SENSOR_POWER_TRIG_GPIO_PORT, SENSOR_POWER_TRIG_PIN)
#define SENSOR_POWER_TRIG_OFF()				GPIO_ResetBits(SENSOR_POWER_TRIG_GPIO_PORT, SENSOR_POWER_TRIG_PIN)

#define	ZMDI_WE  0xDA          // 写使能
#define	ZMDI_RE  0xDB          // 读使能  //28

#define PRESSURE_FILTER_NUM		4

typedef enum 
{
	IIC_N_ACK			= 0,
	IIC_SEND_ACK		= 1, 	
}IIC_SendACKTypeDef;

//IIC所有操作函数
void LP_IIC_GPIO_Init(void);                //初始化IIC的IO口		
void LP_IIC_SDA_InMode(void);
void LP_IIC_SDA_OutMode(void);
void LP_IIC_Start(void);				//发送IIC开始信号
void LP_IIC_Stop(void);	  			//发送IIC停止信号
void LP_IIC_Send_Byte(uint8_t txd);			//IIC发送一个字节
uint8_t LP_IIC_Read_Byte(IIC_SendACKTypeDef ack);//IIC读取一个字节
uint8_t LP_IIC_Wait_Ack(void); 				//IIC等待ACK信号
void LP_IIC_Ack(void);					//IIC发送ACK信号
void LP_IIC_NAck(void);				//IIC不发送ACK信号
void LP_IIC_Write_One_Byte(uint8_t daddr,uint8_t addr,uint8_t data);
uint8_t LP_IIC_Read_One_Byte(uint8_t daddr,uint8_t addr);	
//
void LpI2C_Init(void);
void LpI2CSendCMD(void);
uint8_t LpI2CReceiveBytes(uint8_t *ucReceiveData);

void LPValueSample(int32_t* rawValue);//采集压力传感器的数值
void SensorPowerTrig_GPIO_Config(void);
#endif

