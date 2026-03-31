/**
 ******************************************************************************
 * @file    uart.c
 * @author  sinowealth
 * @version V1.1.0
 * @date    27-December-2019
 * @brief   UART module
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"
#include "uart.h"
#include "queue.h"
#include "delay.h"
#include "app.h"
#include "fault.h"
#include "lcd.h"

#define RX_DRIVER_PROTOCOL_LENGTH		20
#define RX_DR_PROT_HEADER				0x55
#define RX_DR_PROT_END1					0x0D
#define RX_DR_PROT_END2					0x0A

#define TX_DRIVER_PROTOCOL_LENGTH		9
//#define TX_DR_PROT_HEADER				0xAA
//#define TX_DR_PROT_END1					0x0D
//#define TX_DR_PROT_END2					0x0A

CIRCLEQUEUE g_stQueue;

T_TWI twi =
    {
        .u8SendCnt = 0,
        .u8RecCnt = 0,
        .u8RecEndFlag = 0,
        .u8TwiSendBuf = {1, 2, 3, 4, 5, 6, 7, 8},
        .u8TwiReceBuf = {0}};
/**
 ******************************************************************************
 * @name    void UART2_Config(void)
 * @author  sinowealth
 * @version V1.1.0
 * @date    19-December-2019
 * @brief   UART SET: first set GPIO ,SENCOND SET UART.
 ******************************************************************************
 */
void UART2_Config(void)
{
    UART_InitTypeDef UART_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_AHBPeriphClockOnOff(RCC_AHB_IOCLK, SH_ON);
	
	GPIO_InitStructure.GPIO_Pin = TX_UART_DR_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_ODrv = GPIO_ODrv_NORMAL;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(UART_DR_PORT, &GPIO_InitStructure);
	
    GPIO_InitStructure.GPIO_Pin = RX_UART_DR_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_Init(UART_DR_PORT, &GPIO_InitStructure);
	
	GPIO_PinAFConfig(UART_DR_PORT, TX_UART_DR_PIN, GPIO_AF_UART2);
    GPIO_PinAFConfig(UART_DR_PORT, RX_UART_DR_PIN, GPIO_AF_UART2);

    /* Enable UART3 clock */
    // TURN ON PERIPHCLOCK CLOCK
    RCC_APB1PeriphClockOnOff(RCC_APB1_UART2, SH_ON);
    //   RCC_AHBPeriphClockOnOff(RCC_AHB_IOCLK, ON);

    UART_InitStructure.UART_Mode = UART_Mode_1;
    UART_InitStructure.UART_BaudRate = 9600;
    UART_InitStructure.UART_DataLength = UART_DataLength_8Bit;
    UART_InitStructure.UART_StopBits = UART_StopBits_1;
    UART_InitStructure.UART_Parity = UART_Parity_None;
    UART_InitStructure.UART_Enable = UART_Enable_Tx | UART_Enable_Rx;
    UART_Init(UART2, &UART_InitStructure);

    UART_INTConfig(UART2, UART_INT_RX, SH_ENABLE);
    NVIC_EnableIRQ(UART2_IRQn);
}

/*********************************************************
@function:	UART_ReceiveBytes()
@param:		[in] the pointer of receive buffer
			[in] read length
			[out] the pointer of received bytes
			[in] timer out
@return :	true--success
			false--fail
**********************************************************/
bool UART_ReceiveBytes(
	CIRCLEQUEUE 		*pQue,
	uint8_t             *pu8Buffer,
	uint16_t            u32ReadLength,
	uint32_t            u32Timeout)
{
    uint32_t u32TimeCount = 0;
    bool bReady = false;
	uint16_t pu32BytesReceived = 0;
	
    do
    {
		// disable_uart_interrupt();
		//HAL_Delay(15);
		while((GetLength(pQue) >0) && (!bReady))
		{
			pu8Buffer[pu32BytesReceived] = De_Queue(pQue);
			pu32BytesReceived++;
			u32TimeCount = 0;						// reset timeout to avoid timeout during reading big data packages
			bReady = (pu32BytesReceived == u32ReadLength);
		}
     	//enable_uart_interrupt();
	     
		if(!bReady)								// Time delay handling
		{
            delay_ms(1);					//
			u32TimeCount++;
		}
    }while((!bReady) && (u32TimeCount < u32Timeout));

	return bReady;
}

/*
24M-C和-F的程序中，由于增加了下面两条语句，会导致取消蜂鸣器报警后，串口再收到故障信息时，蜂鸣器会报警。
g_CancelAlarmFlag = false;
BEEP.update = 1;
*/
void Handle_UartReceDataFromDriver(void)
{
	uint8_t dataArray[RX_DRIVER_PROTOCOL_LENGTH];
	uint8_t i = 0, sum = 0;
	if(GetLength(&g_stQueue) >= RX_DRIVER_PROTOCOL_LENGTH)
	{
		if(UART_ReceiveBytes(&g_stQueue, dataArray, 1, 1) == true)
		{
			if(dataArray[0] == RX_DR_PROT_HEADER)
			{
				if(UART_ReceiveBytes(&g_stQueue, dataArray + 1, RX_DRIVER_PROTOCOL_LENGTH - 1, 1) == true)
				{
					if((dataArray[RX_DRIVER_PROTOCOL_LENGTH - 2] == RX_DR_PROT_END1) && (dataArray[RX_DRIVER_PROTOCOL_LENGTH - 1] == RX_DR_PROT_END2))
					{
						for(i = 0; i < (RX_DRIVER_PROTOCOL_LENGTH - 3); i++)
							sum += dataArray[i];
						
						if(sum == dataArray[RX_DRIVER_PROTOCOL_LENGTH - 3])
						{
							g_tDriveInfo.GetSpeed = dataArray[1];
							g_tDriveInfo.GetSpeed <<= 8;
							g_tDriveInfo.GetSpeed += dataArray[2];
							
							g_tDriveInfo.nPhaseCurrent = dataArray[5];
							g_tDriveInfo.nPhaseCurrent <<= 8;
							g_tDriveInfo.nPhaseCurrent += dataArray[6];
							
							g_tDriveInfo.IpmTemp = dataArray[7];
							g_tDriveInfo.MotorTemp = dataArray[8];
							g_tDriveInfo.FaultCodeHigh = dataArray[14];
							g_tDriveInfo.FaultCodeLow = dataArray[15];
							g_tDriveInfo.Version = dataArray[16];

							if((g_tDriveInfo.FaultCodeLow & 0x02) == 0x02) //输入过压
								MAC_FAULT.VoltageHigh = FAULT_NOW;
							else if(MAC_FAULT.VoltageHigh == FAULT_NOW)
								MAC_FAULT.VoltageHigh = FAULT_END;
							
							if(g_ShieldDrvErrCnt_10ms == 0)	//不屏蔽
							{	
								if((g_tDriveInfo.FaultCodeLow & 0x01) == 0x01) //输入欠压
									MAC_FAULT.VoltageLow = FAULT_NOW;
								else if(MAC_FAULT.VoltageLow == FAULT_NOW)
									MAC_FAULT.VoltageLow = FAULT_END;//输入电压，低压故障已消除
								
								//软件过流bit2,硬件过流bit3,PFC过流bit4,电机堵转bit5,电机缺相bit6,MOS、IPM、PCBA过热bit7
								if((g_tDriveInfo.FaultCodeLow & 0xFC) != 0) 
									MAC_FAULT.Over_Current = FAULT_NOW;	
								else if(MAC_FAULT.Over_Current == FAULT_NOW)
									MAC_FAULT.Over_Current = FAULT_END;
							}		
						}
					}
					else
						Init_Queue(&g_stQueue);	
				}
				else
					Init_Queue(&g_stQueue);	
			}
		}
		else
			Init_Queue(&g_stQueue);	
	}
}


void Handle_UartSendDataToDriver(void)
{
	uint8_t i = 0;
	uint16_t cnt = 0xFFFF;
	static uint8_t SendToDriverBuff[TX_DRIVER_PROTOCOL_LENGTH] = {0xAA, 0x0B, 0XB8, 0X00, 0X00, 0X00, 0X00, 0X0D, 0X0A};
	SendToDriverBuff[3] = (uint8_t)((g_tDriveInfo.SetSpeed >> 8) & 0xFF);
	SendToDriverBuff[4] = (uint8_t)(g_tDriveInfo.SetSpeed & 0xFF);
	
	SendToDriverBuff[6] = 0;
	for(i = 0; i < 6; i++)
		SendToDriverBuff[6] += SendToDriverBuff[i];
	
	for(i = 0; i < TX_DRIVER_PROTOCOL_LENGTH; i++)
	{
		//发送一个字节，while循环实际耗时时间1.035ms
		cnt = 0xFFFF;
		while((UART_GetFlagStatus(UART2, UART_FLAG_TC) != SH_SET) && (cnt > 0))//等待发送结束
		{
			cnt--;
			delay_us(10);	//实际延时15us
		}
		UART_SendData(UART2, SendToDriverBuff[i]);
	}
}

/******************* (C) COPYRIGHT 2021 Sinowealth *****END OF FILE************/
