/**
 ******************************************************************************
 * @file    uart.h
 * @author  sinowealth
 * @version V1.0.0
 * @date    27-december-2019
 * @brief   This file contains all the functions prototypes for the GPIO firmware
 *          library.
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __UART_H
#define __UART_H

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"
#include "queue.h"

#define TX_UART_DR_PIN							GPIO_Pin_5
#define RX_UART_DR_PIN							GPIO_Pin_6
#define UART_DR_PORT							GPIOE


#define TWIBUFSendSize 8
#define TWIBUFRevSize  8

typedef struct
{
    uint8_t u8SendCnt;
    uint8_t u8RecCnt;
    uint8_t u8RecEndFlag;
    uint8_t u8TwiSendBuf[TWIBUFSendSize];
    uint8_t u8TwiReceBuf[TWIBUFRevSize];
} T_TWI;

extern T_TWI twi;
extern CIRCLEQUEUE g_stQueue;
/** @defgroup UART_Exported_Functions
 * @{
 */
void UART2_Config(void);
void Handle_UartReceDataFromDriver(void);
void Handle_UartSendDataToDriver(void);
#endif /* __UART_H */
