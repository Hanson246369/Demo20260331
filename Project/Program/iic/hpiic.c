#include "hpiic.h"
#include "delay.h"
#include "app.h"

//IIC初始化
void HP_IIC_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
    /* Enable GPIOB clock */
    RCC_AHBPeriphClockOnOff(RCC_AHB_IOCLK, SH_ON);
	
	GPIO_InitStructure.GPIO_Pin = HP_IIC_SCL_PIN | HP_IIC_SDA_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_ODrv = GPIO_ODrv_NORMAL;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
    GPIO_Init(HP_IIC_PORT, &GPIO_InitStructure);
    GPIO_PinAFConfig(HP_IIC_PORT, HP_IIC_SCL_PIN | HP_IIC_SDA_PIN, GPIO_AF_GPIO);
	HP_IIC_SCL_H();
	HP_IIC_SDA_H();
}

void HP_IIC_SDA_InMode(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = HP_IIC_SDA_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
	GPIO_Init(HP_IIC_PORT, &GPIO_InitStructure);
}

void HP_IIC_SDA_OutMode(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = HP_IIC_SDA_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_ODrv = GPIO_ODrv_NORMAL;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//经测试，输出模式一定要设置成推挽模式
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
	GPIO_Init(HP_IIC_PORT, &GPIO_InitStructure);
}

//产生IIC起始信号
void HP_IIC_Start(void)
{
	HP_IIC_SDA_OutMode();     //sda线输出
	HP_IIC_SDA_H();	  	  
	HP_IIC_SCL_H();
	delay_us(4);
 	HP_IIC_SDA_L();//START:when CLK is high,DATA change form high to low 
	delay_us(4);
	HP_IIC_SCL_L();//钳住I2C总线，准备发送或接收数据 
}	  
//产生IIC停止信号
void HP_IIC_Stop(void)
{
	HP_IIC_SDA_OutMode();//sda线输出
	HP_IIC_SCL_L();
	HP_IIC_SDA_L();//STOP:when CLK is high DATA change form low to high
 	delay_us(4);
	HP_IIC_SCL_H(); 
	delay_us(4);			
	HP_IIC_SDA_H();//发送I2C总线结束信号				   	
}
//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
uint8_t HP_IIC_Wait_Ack(void)
{
	uint8_t ucErrTime=0;
	HP_IIC_SDA_InMode();      //SDA设置为输入,如果主机发送的最后一位是高电平，可能会和从机的低电平应答有短暂的冲突。
	HP_IIC_SDA_H();
	delay_us(1);	   
	HP_IIC_SCL_H();
	delay_us(1);	 
	while(HP_IIC_SDA_READ())
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			HP_IIC_Stop();
			return 1;
		}
	}
	HP_IIC_SCL_L();//时钟输出0 	   
	return 0;  
} 
//产生ACK应答
void HP_IIC_Ack(void)
{
	HP_IIC_SCL_L();
	HP_IIC_SDA_OutMode();
	HP_IIC_SDA_L();
	delay_us(2);
	HP_IIC_SCL_H();
	delay_us(2);
	HP_IIC_SCL_L();
}
//不产生ACK应答		    
void HP_IIC_NAck(void)
{
	HP_IIC_SCL_L();
	HP_IIC_SDA_OutMode();
	HP_IIC_SDA_H();
	delay_us(2);
	HP_IIC_SCL_H();
	delay_us(2);
	HP_IIC_SCL_L();
}					 				     
//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答			  
void HP_IIC_Send_Byte(uint8_t txd)
{                        
    uint8_t t;   
	HP_IIC_SDA_OutMode(); 	    
    HP_IIC_SCL_L();//拉低时钟开始数据传输
    for(t=0;t<8;t++)
    {             
		if(((txd&0x80)>>7) != 0)	
			HP_IIC_SDA_H();
		else
			HP_IIC_SDA_L();
			
        txd<<=1; 	  
		delay_us(2);   //对TEA5767这三个延时都是必须的
		HP_IIC_SCL_H();
		delay_us(2); 		//理论延时时间与实际延时时间对比：2->5;5->8;10->13;20->23
		HP_IIC_SCL_L();	
		delay_us(2);
    }	 
} 	    
//读1个字节，ack=1时，发送ACK，ack=0，发送nACK   
uint8_t HP_IIC_Read_Byte(IIC_SendACKTypeDef ack)
{
	unsigned char i,receive=0;
	HP_IIC_SDA_InMode();//SDA设置为输入
    for(i=0;i<8;i++ )
	{
        HP_IIC_SCL_L(); 
        delay_us(2);
		HP_IIC_SCL_H();
        receive<<=1;
        if(HP_IIC_SDA_READ())
			receive++;   
		delay_us(1); 
    }					 
    if (ack == IIC_N_ACK)
        HP_IIC_NAck();//发送nACK
    else
        HP_IIC_Ack(); //发送ACK   
    return receive;
}
void HpI2C_Init(void)
{          
	HP_IIC_Start();
	HP_IIC_Send_Byte(ZMDI_WE);
	HP_IIC_Wait_Ack();
	HP_IIC_Send_Byte(0xA5);
	HP_IIC_Wait_Ack();
	HP_IIC_Start();
	HP_IIC_Send_Byte(ZMDI_RE); //读0xa5寄存器值
	HP_IIC_Wait_Ack();  
	HP_IIC_Read_Byte(IIC_N_ACK); 

	HP_IIC_Stop();
	//DelayMS(10); 
	//temp&=0xFD;
	HP_IIC_Start();
	HP_IIC_Send_Byte(ZMDI_WE);
	HP_IIC_Wait_Ack();
	HP_IIC_Send_Byte(0xA5);
	HP_IIC_Wait_Ack();
	//temp1 = temp1&0xfd;
	HP_IIC_Send_Byte(0x19);   //OTP寄存器  0xA5寄存器=0x01
	HP_IIC_Wait_Ack();
	HP_IIC_Stop();
	// DelayMS(10); 
	HP_IIC_Start();
	HP_IIC_Send_Byte(ZMDI_WE);
	HP_IIC_Wait_Ack();
	HP_IIC_Send_Byte(0x30);       //cmd命令   0x30寄存器=0x0a
	HP_IIC_Wait_Ack();
	HP_IIC_Send_Byte(0x0A);   //开始温度数据采集，采集结束SCO自动返回0，SCO-1  MEASURECTL=000--压力与温度采集模式
	HP_IIC_Wait_Ack();//010b: indicate a combined conversion (once temperature conversion immediately followed by once sensor signal conversion)
	HP_IIC_Stop();         
}

void HpI2CSendCMD(void)
{
	unsigned char temp1=0xff;
	// 8 压力
	HP_IIC_Start();
	HP_IIC_Send_Byte(ZMDI_WE);
	HP_IIC_Wait_Ack();
	HP_IIC_Send_Byte(0x30);
	HP_IIC_Wait_Ack();
	HP_IIC_Start();
	HP_IIC_Send_Byte(ZMDI_RE); //读0x30寄存器值
	HP_IIC_Wait_Ack();  
	temp1 = HP_IIC_Read_Byte(IIC_N_ACK); 
	
	HP_IIC_Stop();
	if((temp1&0x08)==0)
	{
		HP_IIC_Start();
		HP_IIC_Send_Byte(ZMDI_WE);
		HP_IIC_Wait_Ack();
		HP_IIC_Send_Byte(0x30);       //cmd命令 
		HP_IIC_Wait_Ack();
		HP_IIC_Send_Byte(0x0A);   //NSA传感器开始数据采集，采集结束SCO自动返回0，SCO-1  MEASURECTL=001--传感器信号采集模式
		HP_IIC_Wait_Ack();
		HP_IIC_Stop();
		//DelayMS(60);
	}
}

uint8_t HpI2CReceiveBytes(uint8_t *ucReceiveData)
{
	// 10 读压力
	HP_IIC_Start();
	HP_IIC_Send_Byte(ZMDI_WE);
	HP_IIC_Wait_Ack();
	HP_IIC_Send_Byte(0x06);         //DATA通用寄存器  
	if(HP_IIC_Wait_Ack() == 0)		//接收应答成功
	{
		HP_IIC_Start();
		HP_IIC_Send_Byte(ZMDI_RE);
		HP_IIC_Wait_Ack(); 
		ucReceiveData[0] = HP_IIC_Read_Byte(IIC_SEND_ACK); 
		ucReceiveData[1] = HP_IIC_Read_Byte(IIC_SEND_ACK); 
		ucReceiveData[2] = HP_IIC_Read_Byte(IIC_N_ACK);
		HP_IIC_Stop(); 
		return 1;
	}
	else 
		return 0;
}

void HPValueSample(int32_t* rawValue)
{
	static uint8_t num = 0, errCnt = 0, normCnt = 3;//normCnt初始化为3是为了刚上电时需要在0.5s内得到压力值，这样液晶屏上才能显示压力值
	static int32_t prsValue[PRESSURE_FILTER_NUM];
	static uint8_t continueZeroCnt = 0;
	uint8_t i;
	uint8_t valueArray[3]; 
	int32_t value;
	int32_t sum =0;
	
	if(HpI2CReceiveBytes(valueArray) == 1)//读取低压传感器正常   
	{
		errCnt = 0;
		HpI2CSendCMD();     //压力采集模式，Sco置1，采集结束后自动返回0

		if(normCnt > 2)
		{
			value = (((uint32_t)valueArray[2]) | ((uint32_t)valueArray[1] << 8) | ((uint32_t)valueArray[0] << 16));
			if(value > 15777215)//是负压 
				value -= 16777215; 
			
			if(value == 0)
			{
				if(continueZeroCnt > 3)
				{
					PRESSURE.hpFault = true;		//连续5次读到的压力值为0，表示传感器已短路
					return;
				}
				else
					continueZeroCnt++;
			}
			else
				continueZeroCnt = 0;
			
			PRESSURE.hpFault = false;        
			prsValue[num++] = value;
			if(num >= PRESSURE_FILTER_NUM)
			{
				num = 0;
				for(i=0; i<PRESSURE_FILTER_NUM; i++)
					sum += prsValue[i];
				
				*rawValue = sum/PRESSURE_FILTER_NUM;
			}
		}
		else
			normCnt++;
	}
	else
	{
		normCnt = 0;
		HpI2C_Init(); 
		if(errCnt > 10) 
		{
			PRESSURE.hpFault = true;//低压传感器错误
			num = 0;
		}
		else 
			errCnt++;
	}
}
