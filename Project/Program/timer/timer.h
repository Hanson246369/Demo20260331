/******************** (C) COPYRIGHT 2021 sinowealth ***************************
 * @file      timer.h
 * @describe  timer head file
 * @platform  target board
 * @version   V1.1.0
 * @author    SinoWealth
 * @date      7-February-2022
 **********************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIMER_H
#define __TIMER_H

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"
#include "stdbool.h"

#define TIM5_PRESCALER			359			//APB0 36MHz 
#define TIM5_PERIOD				99			//1ms

/******************************************************************************
*  software timer type declarations
*****************************************************************************/  
typedef enum
{
	SOFT_TIMER_NOW = false,          /* Timer is timing */
	SOFT_TIMER_END = true,           /* Timer is time-up */
	SOFT_TIMER_OFF = 0xff           /* Timer is closed */
}TimerStatus;

typedef enum
{
	eID_10MS 	= 0,
	eID_100MS	= 1,
	eID_500MS 	= 2,
	eST_MAX	
}eTimerType;
  
extern const uint32_t TimerDelay[eST_MAX];  


void TIM5_Config(void);
void SoftTimer_Setup(uint8_t TimerID, uint32_t TickNum);
void SoftTimer_Close(uint8_t TimerID);
uint32_t SoftTimer_GetTimer(uint8_t TimerID);
uint8_t SoftTimer_Check(uint8_t TimerID);

#endif /* __TIMER_H */
