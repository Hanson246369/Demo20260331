/**
  ******************************************************************************
  * @file    sh32f9xx_sb0_retarget.h
  * @author  sinowealth
  * @version V1.0.0
  * @date    02-AUG.-2021
  * @brief   This file contains all the functions prototypes for the retarget firmware
  *          library.
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
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SH32F9XX_SB0_RETARGET_H
#define __SH32F9XX_SB0_RETARGET_H

#include "sh32f9xx_sb0_libcfg.h" 

#ifdef __cplusplus
 extern "C" {
#endif

/*****************************************************************************/
//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------
/*****************************************************************************/
//<o> 数据输出模式选择
//   <0=> ITM_MODE
//   <1=> UART_MODE
#define  OUTPUT_MODE    1

#define  ITM_MODE       0
#define  UART_MODE      1


//<o> ITM频率设置
#define  ITM_FREQ_DEFAULT    500000


//<o> UART波特率设置
#define  UART_BAUD_DEFAULT   9600


//<o> UART选择
//   <0=> SEL_UART0
//   <1=> SEL_UART1
//   <2=> SEL_UART2
//   <3=> SEL_UART3
//   <4=> SEL_UART4
//   <5=> SEL_UART5
#define  Uart_Sel       3

#define  SEL_UART0      0
#define  SEL_UART1      1
#define  SEL_UART2      2
#define  SEL_UART3      3
#define  SEL_UART4      4
#define  SEL_UART5      5



// <h> UART REMAP选择
// <o> UART0 REMAP选择
//   <0=> SEL_REMAP0(PA3_TXD0,PA4_RXD0)
//   <1=> SEL_REMAP1(PB6_TXD0,PB7_RXD0)
//   <2=> SEL_REMAP2(PC11_TXD0,PC10_RXD0)
//   <3=> SEL_REMAP3(PD14_TXD0,PD13_RXD0)
#define  Uart0_Remap     0

// <o> UART1 REMAP选择
//   <0=> SEL_REMAP0(PA5_TXD1,PA6_RXD1)
//   <1=> SEL_REMAP1(PB8_TXD1,PB9_RXD1)
//   <2=> SEL_REMAP2(PC7_TXD1,PC8_RXD1)
//   <3=> SEL_REMAP3(PC12_TXD1,PC13_RXD1)
//   <4=> SEL_REMAP4(PD15_TXD1,PE0_RXD1)
#define  Uart1_Remap     0

// <o> UART2 REMAP选择
//   <0=> SEL_REMAP0(PA7_TXD2,PA8_RXD2)
//   <1=> SEL_REMAP1(PB10_TXD2,PB11_RXD2)
//   <2=> SEL_REMAP2(PC14_TXD2,PC15_RXD2)
//   <3=> SEL_REMAP3(PE1_TXD2,PE2_RXD2)
//   <4=> SEL_REMAP4(PE5_TXD2,PE6_RXD2)
#define  Uart2_Remap     0

// <o> UART3 REMAP选择
//   <0=> SEL_REMAP0(PA0_TXD3,PA1_RXD3)
//   <1=> SEL_REMAP1(PB0_TXD3,PB1_RXD3)
//   <2=> SEL_REMAP2(PC0_TXD3,PC1_RXD3)
//   <3=> SEL_REMAP3(PD0_TXD3,PD1_RXD3)
#define  Uart3_Remap     0

// <o> UART4 REMAP选择
//   <0=> SEL_REMAP0(PA9_TXD4,PA10_RXD4)
//   <1=> SEL_REMAP1(PB2_TXD4,PB3_RXD4)
//   <2=> SEL_REMAP2(PC2_TXD4,PC3_RXD4)
//   <3=> SEL_REMAP3(PD2_TXD4,PD3_RXD4)
#define  Uart4_Remap     0

// <o> UART5 REMAP选择
//   <0=> SEL_REMAP0(PA11_TXD5,PA12_RXD5)
//   <1=> SEL_REMAP1(PB4_TXD5,PB5_RXD5)
//   <2=> SEL_REMAP2(PC4_TXD5,PC5_RXD5)
//   <3=> SEL_REMAP3(PD4_TXD5,PD5_RXD5)
#define  Uart5_Remap     0

//</h>



/*****************************************************************************/
//-------- <<< end of configuration section >>> -----------------------------
/*****************************************************************************/
/** @addtogroup Retarget_Group
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/


/** @addtogroup Retarget_Group_Pub_Funcs
  * @{
  */


/*! Retarget Init function */
void RetargetInit(void);

/*! flush printf buffer to output device */
void flush_printfbuffer(void);

/**
  * @}
  */


/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /*__SH32F9xx_SB0_RETARGET_H */



/************************ (C) COPYRIGHT Sinowealth ****************************/
/********************************END OF FILE***********************************/
