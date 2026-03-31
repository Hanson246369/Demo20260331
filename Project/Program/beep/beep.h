/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BEEP_H
#define __BEEP_H

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"

/** @defgroup MOTORCTRL_Exported_Functions
 * @{
 */
#define BEEP_ON_OFF_PIN						GPIO_Pin_9
#define BEEP_ON_OFF_GPIO_PORT				GPIOA
#define BEEP_ON()							GPIO_SetBits(BEEP_ON_OFF_GPIO_PORT, BEEP_ON_OFF_PIN)
#define BEEP_OFF()							GPIO_ResetBits(BEEP_ON_OFF_GPIO_PORT, BEEP_ON_OFF_PIN)

void Beep_GPIO_Config(void);
void Beep_SetMode1(void);
void Beep_SetMode2(void);
void Beep_SetMode3(void);
void Beep_ResetMode3(void);
void Handle_BeepControl(void);
#endif /* __BEEP_H */
