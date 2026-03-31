/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __KEY_H
#define __KEY_H

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"

/** @defgroup MOTORCTRL_Exported_Functions
 * @{
 */
 
#define KEY_UNIT_PIN						GPIO_Pin_12
#define KEY_ZERO_PIN						GPIO_Pin_13
#define KEY_MUTE_PIN						GPIO_Pin_14
#define KEY_START_PIN						GPIO_Pin_15
#define KEY_GPIO_PORT						GPIOA
#define KEY_GPIO_READ()						GPIO_ReadInputData(KEY_GPIO_PORT)

#define KEY_UNIT    				1
#define KEY_CANCEL_ALARM			3
#define KEY_POWER 					4
#define KEY_MUTE_LONG         		5
#define KEY_ZERO_LONG         		6
#define KEY_UNIT_LONG				10

extern uint8_t cur_key_no;

void Key_GPIO_Config(void);
void Handle_KeyDetect(void);
void Handle_GetKey(void);
#endif /* __KEY_H */
