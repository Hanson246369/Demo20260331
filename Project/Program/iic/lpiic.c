#include "lpiic.h"
#include "delay.h"
#include "hpiic.h"
#include "app.h"

void SensorPowerTrig_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHBPeriphClockOnOff(RCC_AHB_IOCLK, SH_ON);	
	
	GPIO_InitStructure.GPIO_Pin = SENSOR_POWER_TRIG_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_ODrv = GPIO_ODrv_NORMAL;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(SENSOR_POWER_TRIG_GPIO_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(SENSOR_POWER_TRIG_GPIO_PORT, SENSOR_POWER_TRIG_PIN, GPIO_AF_GPIO);
	SENSOR_POWER_TRIG_ON();
	delay_ms(100);
	SENSOR_POWER_TRIG_OFF();
}

//IIC初始化
void LP_IIC_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
    /* Enable GPIOB clock */
    RCC_AHBPeriphClockOnOff(RCC_AHB_IOCLK, SH_ON);
	
    GPIO_InitStructure.GPIO_Pin = LP_IIC_SCL_PIN | LP_IIC_SDA_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_ODrv = GPIO_ODrv_NORMAL;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
    GPIO_Init(LP_IIC_PORT, &GPIO_InitStructure);
    GPIO_PinAFConfig(LP_IIC_PORT, LP_IIC_SCL_PIN | LP_IIC_SDA_PIN, GPIO_AF_GPIO);
	LP_IIC_SCL_H();
	LP_IIC_SDA_H();
}

void LP_IIC_SDA_InMode(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = LP_IIC_SDA_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
	GPIO_Init(LP_IIC_PORT, &GPIO_InitStructure);
}

void LP_IIC_SDA_OutMode(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = LP_IIC_SDA_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_ODrv = GPIO_ODrv_NORMAL;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;		//经测试，输出模式一定要设置成推挽模式
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 
	GPIO_Init(LP_IIC_PORT, &GPIO_InitStructure);
}

//产生IIC起始信号
void LP_IIC_Start(void)
{
	LP_IIC_SDA_OutMode();     //sda线输出
	LP_IIC_SDA_H();	  	  
	LP_IIC_SCL_H();
	delay_us(4);
 	LP_IIC_SDA_L();//START:when CLK is high,DATA change form high to low 
	delay_us(4);
	LP_IIC_SCL_L();//钳住I2C总线，准备发送或接收数据 
}	  
//产生IIC停止信号
void LP_IIC_Stop(void)
{
	LP_IIC_SDA_OutMode();//sda线输出
	LP_IIC_SCL_L();
	LP_IIC_SDA_L();//STOP:when CLK is high DATA change form low to high
 	delay_us(4);
	LP_IIC_SCL_H(); 
	delay_us(4);			
	LP_IIC_SDA_H();//发送I2C总线结束信号				   	
}
//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
uint8_t LP_IIC_Wait_Ack(void)
{
	uint8_t ucErrTime=0;
	LP_IIC_SDA_InMode();      //SDA设置为输入,如果主机发送的最后一位是高电平，可能会和从机的低电平应答有短暂的冲突。
	LP_IIC_SDA_H();
	delay_us(1);	   
	LP_IIC_SCL_H();
	delay_us(1);	 
	while(LP_IIC_SDA_READ())
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			LP_IIC_Stop();
			return 1;
		}
	}
	LP_IIC_SCL_L();//时钟输出0 	   
	return 0;  
} 
//产生ACK应答
void LP_IIC_Ack(void)
{
	LP_IIC_SCL_L();
	LP_IIC_SDA_OutMode();
	LP_IIC_SDA_L();
	delay_us(2);
	LP_IIC_SCL_H();
	delay_us(2);
	LP_IIC_SCL_L();
}
//不产生ACK应答		    
void LP_IIC_NAck(void)
{
	LP_IIC_SCL_L();
	LP_IIC_SDA_OutMode();
	LP_IIC_SDA_H();
	delay_us(2);
	LP_IIC_SCL_H();
	delay_us(2);
	LP_IIC_SCL_L();
}					 				     
//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答			  
void LP_IIC_Send_Byte(uint8_t txd)
{                        
    uint8_t t;   
	LP_IIC_SDA_OutMode(); 	    
    LP_IIC_SCL_L();//拉低时钟开始数据传输
    for(t=0;t<8;t++)
    {             
		if(((txd&0x80)>>7) != 0)	
			LP_IIC_SDA_H();
		else
			LP_IIC_SDA_L();
			
        txd<<=1; 	  
		delay_us(2);   //对TEA5767这三个延时都是必须的
		LP_IIC_SCL_H();
		delay_us(2); 		//理论延时时间与实际延时时间对比：2->5;5->8;10->13;20->23
		LP_IIC_SCL_L();	
		delay_us(2);
    }	 
} 	    
//读1个字节，ack=1时，发送ACK，ack=0，发送nACK   
uint8_t LP_IIC_Read_Byte(IIC_SendACKTypeDef ack)
{
	unsigned char i,receive=0;
	LP_IIC_SDA_InMode();//SDA设置为输入
    for(i=0;i<8;i++ )
	{
        LP_IIC_SCL_L(); 
        delay_us(2);
		LP_IIC_SCL_H();
        receive<<=1;
        if(LP_IIC_SDA_READ())
			receive++;   
		delay_us(1); 
    }					 
    if (ack == IIC_N_ACK)
        LP_IIC_NAck();//发送nACK
    else
        LP_IIC_Ack(); //发送ACK   
    return receive;
}

void LpI2C_Init(void)
{          
	LP_IIC_Start();
	LP_IIC_Send_Byte(ZMDI_WE);
	LP_IIC_Wait_Ack();
	LP_IIC_Send_Byte(0xA5);
	LP_IIC_Wait_Ack();
	LP_IIC_Start();
	LP_IIC_Send_Byte(ZMDI_RE); //读0xa5寄存器值
	LP_IIC_Wait_Ack();  
	LP_IIC_Read_Byte(IIC_N_ACK); 

	LP_IIC_Stop();
	//DelayMS(10); 
	//temp&=0xFD;
	LP_IIC_Start();
	LP_IIC_Send_Byte(ZMDI_WE);
	LP_IIC_Wait_Ack();
	LP_IIC_Send_Byte(0xA5);
	LP_IIC_Wait_Ack();
	//temp1 = temp1&0xfd;
	LP_IIC_Send_Byte(0x19);   //OTP寄存器  0xA5寄存器=0x01
	LP_IIC_Wait_Ack();
	LP_IIC_Stop();
	// DelayMS(10); 
	LP_IIC_Start();
	LP_IIC_Send_Byte(ZMDI_WE);
	LP_IIC_Wait_Ack();
	LP_IIC_Send_Byte(0x30);       //cmd命令   0x30寄存器=0x0a
	LP_IIC_Wait_Ack();
	LP_IIC_Send_Byte(0x0A);   //开始温度数据采集，采集结束SCO自动返回0，SCO-1  MEASURECTL=000--压力与温度采集模式
	LP_IIC_Wait_Ack();//010b: indicate a combined conversion (once temperature conversion immediately followed by once sensor signal conversion)
	LP_IIC_Stop();         
}

void LpI2CSendCMD(void)
{
	unsigned char temp1=0xff;
	// 8 压力
	LP_IIC_Start();
	LP_IIC_Send_Byte(ZMDI_WE);
	LP_IIC_Wait_Ack();
	LP_IIC_Send_Byte(0x30);
	LP_IIC_Wait_Ack();
	LP_IIC_Start();
	LP_IIC_Send_Byte(ZMDI_RE); //读0x30寄存器值
	LP_IIC_Wait_Ack();  
	temp1 = LP_IIC_Read_Byte(IIC_N_ACK); 
	
	LP_IIC_Stop();
	if((temp1&0x08)==0)
	{
		LP_IIC_Start();
		LP_IIC_Send_Byte(ZMDI_WE);
		LP_IIC_Wait_Ack();
		LP_IIC_Send_Byte(0x30);       //cmd命令 
		LP_IIC_Wait_Ack();
		LP_IIC_Send_Byte(0x0A);   //NSA传感器开始数据采集，采集结束SCO自动返回0，SCO-1  MEASURECTL=001--传感器信号采集模式
		LP_IIC_Wait_Ack();
		LP_IIC_Stop();
		//DelayMS(60);
	}
}

uint8_t LpI2CReceiveBytes(uint8_t *ucReceiveData)
{
	// 10 读压力
	LP_IIC_Start();
	LP_IIC_Send_Byte(ZMDI_WE);
	LP_IIC_Wait_Ack();
	LP_IIC_Send_Byte(0x06);         //DATA通用寄存器  
	if(LP_IIC_Wait_Ack() == 0)		//接收应答成功
	{
		LP_IIC_Start();
		LP_IIC_Send_Byte(ZMDI_RE);
		LP_IIC_Wait_Ack(); 
		ucReceiveData[0] = LP_IIC_Read_Byte(IIC_SEND_ACK); 
		ucReceiveData[1] = LP_IIC_Read_Byte(IIC_SEND_ACK); 
		ucReceiveData[2] = LP_IIC_Read_Byte(IIC_N_ACK);
		LP_IIC_Stop(); 
		return 1;
	}
	else 
		return 0;
}

void LPValueSample(int32_t* rawValue)
{
	static uint8_t num = 0, errCnt = 0, normCnt = 3;//normCnt初始化为3是为了刚上电时需要在0.5s内得到压力值，这样液晶屏上才能显示压力值
	static int32_t prsValue[PRESSURE_FILTER_NUM];
	static uint8_t continueZeroCnt = 0;
	uint8_t i;
	uint8_t valueArray[3]; 
	int32_t value;
	int32_t sum =0;
	
	if(LpI2CReceiveBytes(valueArray) == 1)//读取低压传感器正常   
	{
		errCnt = 0;
		LpI2CSendCMD();     //压力采集模式，Sco置1，采集结束后自动返回0

		if(normCnt > 2)
		{  
			value = (((uint32_t)valueArray[2]) | ((uint32_t)valueArray[1] << 8) | ((uint32_t)valueArray[0] << 16));
			if(value > 15777215)//是负压 
				value -= 16777215;

			if(value == 0)
			{
				if(continueZeroCnt > 3)
				{
					PRESSURE.lpFault = true;		//连续5次读到的压力值为0，表示传感器已短路
					return;
				}
				else
					continueZeroCnt++;
			}
			else
				continueZeroCnt = 0;
			
			PRESSURE.lpFault = false; 
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
		LpI2C_Init();  
		if(errCnt > 10) 
		{
			PRESSURE.lpFault = true;//低压传感器错误
			num = 0;
		}
		else 
			errCnt++;
	}
}





