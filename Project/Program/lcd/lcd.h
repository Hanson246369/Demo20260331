/******************** (C) COPYRIGHT 2021 sinowealth ***************************
 * @file      lcd.h
 * @describe  lcd head file
 * @platform  target board
 * @version   V1.1.0
 * @author    SinoWealth
 * @date      7-February-2022
 **********************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LCD_H
#define __LCD_H

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"

//#define START_LED_IND_PIN 						GPIO_Pin_8
//#define START_LED_IND_GPIO_PORT 				GPIOE
//#define START_LED_IND_ON()						GPIO_ResetBits(START_LED_IND_GPIO_PORT, START_LED_IND_PIN)
//#define START_LED_IND_OFF()						GPIO_SetBits(START_LED_IND_GPIO_PORT, START_LED_IND_PIN)
//#define START_LED_IND_Toggle()					GPIO_ToggleBits(START_LED_IND_GPIO_PORT, START_LED_IND_PIN);


/** @defgroup LCD_Exported_Functions
 * @{
 */
 
#define LED_CTL_PIN 						GPIO_Pin_10
#define LED_CTL_GPIO_PORT 					GPIOE
#define LED_CTL_ON()						GPIO_SetBits(LED_CTL_GPIO_PORT, LED_CTL_PIN)
#define LED_CTL_OFF()						GPIO_ResetBits(LED_CTL_GPIO_PORT, LED_CTL_PIN)

typedef enum
{
	eNUM_0 			= 0,
	eNUM_1 			= 1,
	eNUM_2 			= 2,
	eNUM_3			= 3,
	eNUM_4 			= 4,
	eNUM_5 			= 5,
	eNUM_6 			= 6,
	eNUM_7 			= 7,
	eNUM_8 			= 8,
	eNUM_9 			= 9,
	eNUM_BLANK 		= 10,
	eNUM_E			= 11,
	eNUM_CROSS		= 12,
	eNUM_L			= 13,
	eNUM_S			= 14,
	eNUM_P			= 15,
	eNUM_r			= 16,
	eNUM_o			= 17,
	eNUM_F			= 18,
	eNUM_t			= 19,
	eNUM_h			= 20,
	eNUM_u			= 21,
	eLCD_NUM_CODE_MAX,
}eLCD_NUM_Type;

typedef enum
{
	LCD_CLR		= 0,
	LCD_DISP	= 1,
}eLCD_SW_Type;

typedef enum
{
	CLR_SYMBOL_ALL			= 0,
	CLR_SYMBOL_MINUS_POINT	= 1,	
}eClrSymbolType;

#define F_IN_OUT			1
#define F_COMPLETE			2
#define F_LP_MINUS			3
#define F_LP_KPA			4
#define F_LP_MPA			5
#define F_LP_INHG			6
#define F_LP_BAR			7
#define F_LP_CMHG			8
#define F_LP_PSIG			9
#define F_HP_KPA			10
#define F_HP_MPA			11
#define F_HP_INHG			12
#define F_HP_BAR			13
#define F_HP_CMHG			14
#define F_HP_PSIG			15
#define F_INPUT				16
#define F_OUTPUT			17
#define F_CLOSED			18
#define F_OPEN				19
#define F_VOL_HIGH			20
#define F_VOL_LOW			21
#define F_VOLTAGE			22
#define F_WARNING			23
#define F_MUTE				24
#define F_SERVICE			25
#define F_VALVE				26
#define F_COMPRESSOR		27
#define F_PRS_HIGH			28
#define F_PRS_LOW			29
#define F_PRESSURE			30
#define F_CUTOFF			31
#define F_MOTOR				32
#define F_FAULT				33
#define F_FAULT_1			34
#define F_FAULT_2			35
#define F_FAULT_3			36
#define F_OK_TO_START		37
#define F_TANK_FULL			38
#define F_HP_MINUS			39
#define F_LP_P1				40
#define F_LP_P2				41
#define F_HP_P3				42
#define F_HP_P4				43
#define F_M1				44
#define F_M2				45
#define F_M3				46


#define LP_AREA_1						1
#define LP_AREA_2						2
#define LP_AREA_3						3
#define LP_AREA_4						4
#define HP_AREA_1						5
#define HP_AREA_2						6
#define HP_AREA_3						7
#define HP_AREA_4						8

#define LP_AREA							1				
#define HP_AREA							2
#define LP_HP_AREA						3

#define NUM_CODE_ZEROERR				1
#define NUM_CODE_PLGUOFS				2
#define NUM_CODE_THROTTLE				3
#define NUM_CODE_STOP					4
#define NUM_CODE_E1						5

extern uint8_t LCD_NUM_CODE[eLCD_NUM_CODE_MAX]; 

// lsi turn on as lcd clock
void LSI_TURNON(void);
// lcd init config
void LCD_Config_Init(void);
void LED_GPIO_Config(void);
void LCD_DispalyAll(void);
void LCD_ClearAll(void);
void LCD_PowerOnDisplay(void);
void LCD_DispNum(uint8_t code, uint8_t pos);
void LCD_DispOrClrFlag(uint8_t flag, uint8_t onoff);
void LCD_DispDemo(void);
void LCD_ClearAllErrorFlag(void);
void LCD_ClearNumAndFlag(uint8_t area, eClrSymbolType type);
void LCD_ClearUnitFlag(uint8_t area);
void LCD_ClearMinusFlag(uint8_t area);
void LCD_ClearPointFlag(uint8_t area);
void LCD_DispNumSpecialCode(uint8_t code, uint8_t area);
void LCD_ClearAllMotorFlag(void);
//void START_LED_GPIO_Config(void);
#endif /* __LCD_H */
