#ifndef _HPIIC_H
#define _HPIIC_H

#include "sh32f9xx_sb0_libcfg.h" 	
#include "lpiic.h"

#define HP_IIC_SCL_PIN						GPIO_Pin_2
#define HP_IIC_SDA_PIN						GPIO_Pin_3
#define HP_IIC_PORT							GPIOB

#define HP_IIC_SCL_H()						GPIO_SetBits(HP_IIC_PORT, HP_IIC_SCL_PIN)
#define HP_IIC_SCL_L()						GPIO_ResetBits(HP_IIC_PORT, HP_IIC_SCL_PIN)

#define HP_IIC_SDA_H()						GPIO_SetBits(HP_IIC_PORT, HP_IIC_SDA_PIN)
#define HP_IIC_SDA_L()						GPIO_ResetBits(HP_IIC_PORT, HP_IIC_SDA_PIN)
#define HP_IIC_SDA_READ()					GPIO_ReadInputDataBit(HP_IIC_PORT, HP_IIC_SDA_PIN)


//IIC所有操作函数
void HP_IIC_GPIO_Init(void);                //初始化IIC的IO口		
void HP_IIC_SDA_InMode(void);
void HP_IIC_SDA_OutMode(void);

void HP_IIC_Start(void);				//发送IIC开始信号
void HP_IIC_Stop(void);	  			//发送IIC停止信号
void HP_IIC_Send_Byte(uint8_t txd);			//IIC发送一个字节
uint8_t HP_IIC_Read_Byte(IIC_SendACKTypeDef ack);//IIC读取一个字节
uint8_t HP_IIC_Wait_Ack(void); 				//IIC等待ACK信号
void HP_IIC_Ack(void);					//IIC发送ACK信号
void HP_IIC_NAck(void);				//IIC不发送ACK信号

void HP_IIC_Write_One_Byte(uint8_t daddr,uint8_t addr,uint8_t data);
uint8_t HP_IIC_Read_One_Byte(uint8_t daddr,uint8_t addr);	 

void HpI2C_Init(void);
void HpI2CSendCMD(void);
uint8_t HpI2CReceiveBytes(uint8_t *ucReceiveData);

void HPValueSample(int32_t* rawValue);//采集压力传感器的数值
#endif

