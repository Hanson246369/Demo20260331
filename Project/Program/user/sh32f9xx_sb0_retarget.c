/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_retarget.c
  * @author  sinowealth
  * @version V1.0.0
  * @date    13-AUG.-2021
  * @brief   this file provides printf retargetting functions
  *
  *  @verbatim
  *
  *=============================================================================
  * How to use this driver
  *=============================================================================
  * 1. if PRINTF function is required, defined _MODULE_DBG_PRINTF in preprocessor symbols,
  *    then select output mode is ITM or UART and modify some parameters according
  *    configuration wizard in Sh32f9xx_sb0_retarget.h
  * 2. add this file into the project
  * 3. if using RTE environment or UTE environment or other, please must add Sh32f9xx_sb0_gpio.c,
       Sh32f9xx_sb0_uart.c, Sh32f9xx_sb0_rcc.c driver module into the project
  * 4. use printf to output the debugging information
  * 5. if disable this feature(undefined _MODULE_DBG_PRINTF), no codes added into the project
  * 6. if a redefined assertion is used in the driver library, defined DEFAULT_ASSERT_ENABLE in preprocessor symbols.
  *  @endverbatim
  *
  ******************************************************************************
  * @attention
  *
  * SINOWEALTH IS SUPPLYING THIS SOFTWARE FOR USE EXCLUSIVELY ON SINOWEALTH'S
  * MICROCONTROLLER PRODUCTS. IT IS PROTECTED UNDER APPLICABLE COPYRIGHT LAWS.
  * THIS SOFTWARE IS FOR GUIDANCE IN ORDER TO SAVE TIME. AS A RESULT, SINOWEALTH
  * SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES
  * WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH FIRMWARE AND/OR
  * THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN IN
  * CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2021 Sinowealth</center></h2>
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_retarget.h"

/** @defgroup Retarget_Group Retarget
 * @{
 */

/** @defgroup Retarget_Group_Pub_Funcs  Public Functions
 * @{
 */

#ifdef _MODULE_DBG_PRINTF

#if defined(__CC_ARM)
struct __FILE
{
    int handle; /* Add whatever you need here */
};
FILE __stdout;
FILE __stdin;
#elif defined(__ICCARM__)
struct __FILE
{
    int handle; /* Add whatever you need here */
};
typedef struct __FILE FILE;
FILE __stdout;
FILE __stdin;
#endif

#include <stdio.h>

#if (OUTPUT_MODE == ITM_MODE)
// Cortex-M3 Debug Kernel Registers
#define ITM_DATA 0xE0000000
#define ITM_LOCK_KEY 0xC5ACCE55
#define ITM_KEY (*((volatile unsigned long *)(0xE0000FB0)))
#define ITM_CTRL (*((volatile unsigned long *)(0xE0000E80)))
#define ITM_PRIV (*((volatile unsigned long *)(0xE0000E40)))
#define ITM_TRIG (*((volatile unsigned long *)(0xE0000E20)))
#define ITM_ENABLE (*((volatile unsigned long *)(0xE0000E00)))
#define ITM_PORT0 (*((volatile unsigned long *)(ITM_DATA)))
#define ITM_PORT1 (*((volatile unsigned long *)(ITM_DATA + 4)))
#define DBGMCU_CR (*((volatile unsigned long *)(0xE0042004)))
#define ITM_FREQ (*((volatile unsigned long *)(0xE0040010)))
#define ITM_CHARS (*((volatile unsigned long *)(0xE0040004)))

#define DEM_CR (*((volatile unsigned long *)(0xE000EDFC)))
#define DEM_CR_TRCENA (1 << 24)
#endif

#if (OUTPUT_MODE == UART_MODE)
static void Uart_Init_Config(UART_TypeDef *uart, uint32_t remap, uint32_t u32SR);
#endif

/**
 * @brief  retarget initial function.
 * @note   1. initial the retarget device   2. can be selected as ITM or UART
 * @retval None
 */
void RetargetInit(void)
{
#if (OUTPUT_MODE == ITM_MODE)
    RCC_Clocks_TypeDef RCC_ClocksStatus;
    RCC_GetClocksFreq(&RCC_ClocksStatus);
    DEM_CR = 0;
    ITM_ENABLE = 0X0;
    DEM_CR |= DEM_CR_TRCENA;
    ITM_FREQ = RCC_ClocksStatus.hclkFreq / ITM_FREQ_DEFAULT - 1;
    ITM_KEY = ITM_LOCK_KEY;
    ITM_CTRL = 0x0001001D;
    ITM_PRIV = 0XF;
    ITM_ENABLE = 0XF;
#endif

#if (OUTPUT_MODE == UART_MODE)
#if (Uart_Sel == SEL_UART0)
    Uart_Init_Config(UART0, Uart0_Remap, UART_BAUD_DEFAULT);
#elif (Uart_Sel == SEL_UART1)
    Uart_Init_Config(UART1, Uart1_Remap, UART_BAUD_DEFAULT);
#elif (Uart_Sel == SEL_UART2)
    Uart_Init_Config(UART2, Uart2_Remap, UART_BAUD_DEFAULT);
#elif (Uart_Sel == SEL_UART3)
    Uart_Init_Config(UART3, Uart3_Remap, UART_BAUD_DEFAULT);
#elif (Uart_Sel == SEL_UART4)
    Uart_Init_Config(UART4, Uart4_Remap, UART_BAUD_DEFAULT);
#elif (Uart_Sel == SEL_UART5)
    Uart_Init_Config(UART5, Uart5_Remap, UART_BAUD_DEFAULT);
#endif
#endif
}

#if (OUTPUT_MODE == UART_MODE)
/**
 * @brief  uart send.
 * @param  uart: uart corresponding channel.
 * @param  ch: send data.
 * @note   None
 * @retval uint8_t: data to transmit
 */
uint8_t uart_send(UART_TypeDef *uart, uint8_t ch)
{
    while (uart->FR.BIT.TI == 0)
    {
        __nop();
    }
    uart->TDR = ch;
    return ch;
}

/**
 * @brief  uart read.
 * @param  uart: uart corresponding channel.
 * @note   None
 * @retval uint8_t: return read data
 */
uint8_t uart_read(UART_TypeDef *uart)
{
    uint8_t ch;
    while (uart->FR.BIT.RI == 0)
        ;
    ch = uart->RDR;
    return ch;
}

/**
 * @brief  uart init.
 * @param  uart: uart corresponding channel.
 * @param  remap: uart remap choice.
 * @param  u32SR: uart baud rate.
 * @note   None
 * @retval None
 */
void Uart_Init_Config(UART_TypeDef *uart, uint32_t remap, uint32_t u32SR)
{
    UART_InitTypeDef UART_InitStructure;

    UART_ClockOnOff(uart, SH_ON);

    RCC_AHBPeriphClockOnOff(RCC_AHB_IOCLK, SH_ON);

    UART_InitAF(uart, remap);

    UART_InitStructure.UART_Mode = UART_Mode_1;
    UART_InitStructure.UART_BaudRate = u32SR;
    UART_InitStructure.UART_DataLength = UART_DataLength_8Bit;
    UART_InitStructure.UART_StopBits = UART_StopBits_1;
    UART_InitStructure.UART_Parity = UART_Parity_None;
    UART_InitStructure.UART_Enable = UART_Enable_Tx | UART_Enable_Rx;
    UART_Init(uart, &UART_InitStructure);
}
#endif

#if (OUTPUT_MODE == ITM_MODE)

/* define scanf input buffer */
volatile int32_t ITM_RxBuffer = ITM_RXBUFFER_EMPTY;

#endif

/**
 * @brief  output character function.
 * @param  ch: output character
 * @param  f: file handle.
 * @note   None
 * @retval int: outputted character
 */
int fputc(int ch, FILE *f)
{
#if (OUTPUT_MODE == ITM_MODE)
    if (ch == '\n')
    {
        ITM_SendChar('\r');
    }
    return (ITM_SendChar(ch));
#endif

#if (OUTPUT_MODE == UART_MODE)
    if (ch == '\n')
    {
#if (Uart_Sel == SEL_UART0)
        uart_send(UART0, '\r');
#elif (Uart_Sel == SEL_UART1)
        uart_send(UART1, '\r');
#elif (Uart_Sel == SEL_UART2)
        uart_send(UART2, '\r');
#elif (Uart_Sel == SEL_UART3)
        uart_send(UART3, '\r');
#elif (Uart_Sel == SEL_UART4)
        uart_send(UART4, '\r');
#elif (Uart_Sel == SEL_UART5)
        uart_send(UART5, '\r');
#endif
    }
#if (Uart_Sel == SEL_UART0)
    return (int)uart_send(UART0, (uint8_t)ch);
#elif (Uart_Sel == SEL_UART1)
    return (int)uart_send(UART1, (uint8_t)ch);
#elif (Uart_Sel == SEL_UART2)
    return (int)uart_send(UART2, (uint8_t)ch);
#elif (Uart_Sel == SEL_UART3)
    return (int)uart_send(UART3, (uint8_t)ch);
#elif (Uart_Sel == SEL_UART4)
    return (int)uart_send(UART4, (uint8_t)ch);
#elif (Uart_Sel == SEL_UART5)
    return (int)uart_send(UART5, (uint8_t)ch);
#endif
#endif
}

/**
 * @brief  input retarget.
 * @param  f: file handle.
 * @note   None
 * @retval int: character which read
 */
int fgetc(FILE *f)
{
    int ch;
#if (OUTPUT_MODE == ITM_MODE)
    while (ITM_CheckChar() != 1)
        __NOP();
    ch = ITM_ReceiveChar();
    ITM_SendChar(ch);
    if (ch == '\r')
        ITM_SendChar('\n');
    flush_printfbuffer();
#endif

#if (OUTPUT_MODE == UART_MODE)
#if (Uart_Sel == SEL_UART0)
    ch = uart_read(UART0);
    uart_send(UART0, (uint8_t)ch);
    if (ch == '\r')
        uart_send(UART1, '\n');
#elif (Uart_Sel == SEL_UART1)
    ch = uart_read(UART1);
    uart_send(UART1, (uint8_t)ch);
    if (ch == '\r')
        uart_send(UART1, '\n');
#elif (Uart_Sel == SEL_UART2)
    ch = uart_read(UART2);
    uart_send(UART2, (uint8_t)ch);
    if (ch == '\r')
        uart_send(UART2, '\n');
#elif (Uart_Sel == SEL_UART3)
    ch = uart_read(UART3);
    uart_send(UART3, (uint8_t)ch);
    if (ch == '\r')
        uart_send(UART3, '\n');
#elif (Uart_Sel == SEL_UART4)
    ch = uart_read(UART4);
    uart_send(UART4, (uint8_t)ch);
    if (ch == '\r')
        uart_send(UART4, '\n');
#elif (Uart_Sel == SEL_UART5)
    ch = uart_read(UART5);
    uart_send(UART5, (uint8_t)ch);
    if (ch == '\r')
        uart_send(UART5, '\n');
#endif
#endif
    return (ch);
}

#if defined(__CC_ARM)
/**
 * @brief  flush printf buffer to output device.
 * @note   None
 * @retval None
 */
void flush_printfbuffer(void)
{
}
#endif

#if defined(__ICCARM__)

#if (OUTPUT_MODE == UART_MODE)
/**
 * @brief  for replace the function in getchar.o.
 * @note   None
 * @retval int:returns the character
 */
int _UngetChar(void)
{
    return 0;
}

/**
 * @brief  for replace the function in getchar.o.
 * @param  a: this is the character to be pushed in.
 *            the character is passed with its corresponding int value
 * @note   None
 * @retval int:returns the character
 */
int __ungetchar(int a)
{
    return 0;
}

/**
 * @brief  replace the function getchar for IAR scanf.
 * @note   None
 * @retval int: data readed from input device
 */
int getchar(void)
{
    int ch;
#if (Uart_Sel == SEL_UART0)
    ch = uart_read(UART0);
    uart_send(UART0, (uint8_t)ch);
    if (ch == '\r')
        uart_send(UART0, '\n');
#elif (Uart_Sel == SEL_UART1)
    ch = uart_read(UART1);
    uart_send(UART1, (uint8_t)ch);
    if (ch == '\r')
        uart_send(UART1, '\n');
#elif (Uart_Sel == SEL_UART2)
    ch = uart_read(UART2);
    uart_send(UART2, (uint8_t)ch);
    if (ch == '\r')
        uart_send(UART2, '\n');
#elif (Uart_Sel == SEL_UART3)
    ch = uart_read(UART3);
    uart_send(UART3, (uint8_t)ch);
    if (ch == '\r')
        uart_send(UART3, '\n');
#elif (Uart_Sel == SEL_UART4)
    ch = uart_read(UART4);
    uart_send(UART4, (uint8_t)ch);
    if (ch == '\r')
        uart_send(UART4, '\n');
#elif (Uart_Sel == SEL_UART5)
    ch = uart_read(UART5);
    uart_send(UART5, (uint8_t)ch);
    if (ch == '\r')
        uart_send(UART5, '\n');
#endif
    return (ch);
}

/**
 * @brief  replace the function putchar for IAR printf.
 * @param  ch: data to output device
 * @note   None
 * @retval int: data to output device
 */
int putchar(int ch)
{
    if (ch == '\n')
    {
#if (Uart_Sel == SEL_UART0)
        uart_send(UART0, '\r');
#elif (Uart_Sel == SEL_UART1)
        uart_send(UART1, '\r');
#elif (Uart_Sel == SEL_UART2)
        uart_send(UART2, '\r');
#elif (Uart_Sel == SEL_UART3)
        uart_send(UART3, '\r');
#elif (Uart_Sel == SEL_UART4)
        uart_send(UART4, '\r');
#elif (Uart_Sel == SEL_UART5)
        uart_send(UART5, '\r');
#endif
    }
#if (Uart_Sel == SEL_UART0)
    uart_send(UART0, (uint8_t)ch);
#elif (Uart_Sel == SEL_UART1)
    uart_send(UART1, (uint8_t)ch);
#elif (Uart_Sel == SEL_UART2)
    uart_send(UART2, (uint8_t)ch);
#elif (Uart_Sel == SEL_UART3)
    uart_send(UART3, (uint8_t)ch);
#elif (Uart_Sel == SEL_UART4)
    uart_send(UART4, (uint8_t)ch);
#elif (Uart_Sel == SEL_UART5)
    uart_send(UART5, (uint8_t)ch);
#endif
    return ch;
}
#endif

/**
 * @brief  flush printf buffer to output device.
 * @note   None
 * @retval None
 */
void flush_printfbuffer(void)
{
}

#endif /*__ICCARM__*/

#if defined(__GNUC__)
/**
 * @brief  provide the function for GCC printf.
 * @param  fd: file pointer no used
 * @param  pBuffer: data buffer
 * @param  size: data buffer size
 * @note   None
 * @retval int: outputted data size
 */
int _write(int fd, char *pBuffer, int size)
{
    int i;
#if (OUTPUT_MODE == ITM_MODE)
    for (i = 0; i < size; i++)
    {
        ITM_SendChar(pBuffer[i]);
    }
#endif

#if (OUTPUT_MODE == UART_MODE)
    for (i = 0; i < size; i++)
    {
        if (pBuffer[i] == '\n')
        {
#if (Uart_Sel == SEL_UART0)
            uart_send(UART0, '\r');
#elif (Uart_Sel == SEL_UART1)
            uart_send(UART1, '\r');
#elif (Uart_Sel == SEL_UART2)
            uart_send(UART2, '\r');
#elif (Uart_Sel == SEL_UART3)
            uart_send(UART3, '\r');
#elif (Uart_Sel == SEL_UART4)
            uart_send(UART4, '\r');
#elif (Uart_Sel == SEL_UART5)
            uart_send(UART5, '\r');
#endif
        }
#if (Uart_Sel == SEL_UART0)
        uart_send(UART0, pBuffer[i]);
#elif (Uart_Sel == SEL_UART1)
        uart_send(UART1, pBuffer[i]);
#elif (Uart_Sel == SEL_UART2)
        uart_send(UART2, pBuffer[i]);
#elif (Uart_Sel == SEL_UART3)
        uart_send(UART3, pBuffer[i]);
#elif (Uart_Sel == SEL_UART4)
        uart_send(UART4, pBuffer[i]);
#elif (Uart_Sel == SEL_UART5)
        uart_send(UART5, pBuffer[i]);
#endif
    }
#endif
    return size;
}

/**
 * @brief  provide the function for GCC printf.
 * @param  fd: file pointer no used
 * @param  pBuffer: data buffer
 * @param  size: data buffer size
 * @note   None
 * @retval int: readed data size
 */
int _read(int fd, char *pBuffer, int size)
{
    int i;
#if (OUTPUT_MODE == ITM_MODE)
    for (i = 0; i < size; i++)
    {
        while (ITM_CheckChar() != 1)
        {
        }
        pBuffer[i] = ITM_ReceiveChar();
        ITM_SendChar(pBuffer[i]);
        if (pBuffer[i] == '\r')
        {
            ITM_SendChar('\n');
            i += 1;
            pBuffer[i] = '\n';
            i++;
            break;
        }
    }
#endif

#if (OUTPUT_MODE == UART_MODE)
    for (i = 0; i < size; i++)
    {
#if (Uart_Sel == SEL_UART0)
        pBuffer[i] = uart_read(UART0);
#elif (Uart_Sel == SEL_UART1)
        pBuffer[i] = uart_read(UART1);
#elif (Uart_Sel == SEL_UART2)
        pBuffer[i] = uart_read(UART2);
#elif (Uart_Sel == SEL_UART3)
        pBuffer[i] = uart_read(UART3);
#elif (Uart_Sel == SEL_UART4)
        pBuffer[i] = uart_read(UART4);
#elif (Uart_Sel == SEL_UART5)
        pBuffer[i] = uart_read(UART5);
#endif

#if (Uart_Sel == SEL_UART0)
        uart_send(UART0, pBuffer[i]);
#elif (Uart_Sel == SEL_UART1)
        uart_send(UART1, pBuffer[i]);
#elif (Uart_Sel == SEL_UART2)
        uart_send(UART2, pBuffer[i]);
#elif (Uart_Sel == SEL_UART3)
        uart_send(UART3, pBuffer[i]);
#elif (Uart_Sel == SEL_UART4)
        uart_send(UART4, pBuffer[i]);
#elif (Uart_Sel == SEL_UART5)
        uart_send(UART5, pBuffer[i]);
#endif
        if (pBuffer[i] == '\r')
        {
#if (Uart_Sel == SEL_UART0)
            uart_send(UART0, '\n');
#elif (Uart_Sel == SEL_UART1)
            uart_send(UART1, '\n');
#elif (Uart_Sel == SEL_UART2)
            uart_send(UART2, '\n');
#elif (Uart_Sel == SEL_UART3)
            uart_send(UART3, '\n');
#elif (Uart_Sel == SEL_UART4)
            uart_send(UART4, '\n');
#elif (Uart_Sel == SEL_UART5)
            uart_send(UART5, '\n');
#endif
            i += 1;
            pBuffer[i] = '\n';
            i++;
            break;
        }
    }
#endif
    return i;
}

/*! flush printf buffer to output device */
void flush_printfbuffer(void)
{
    fflush(0);
}

#endif /* __GNUC__ */

#endif /* _MODULE_DBG_PRINTF */

#ifdef DEFAULT_ASSERT_ENABLE

/**
 * @brief  Provide an assertion failure function.
 * @param  file: file pointer
 * @param  line: The line Number
 * @note   None
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
#ifdef _MODULE_DBG_PRINTF
    printf("assert failed:%s (%d)\n", file, (int)line);
#else
    __BKPT(0);
#endif
}
#endif /* DEFAULT_ASSERT_ENABLE*/

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT Sinowealth ****************************/
/********************************END OF FILE***********************************/
