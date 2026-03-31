/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FAULT_H
#define __FAULT_H

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"

#define HP_FAULT_PIN						GPIO_Pin_0
#define OFP_FAULT_PIN						GPIO_Pin_1
#define TP_FAULT_PIN						GPIO_Pin_4
#define SW_FAULT_GPIO_PORT					GPIOE

#define HP_FAULT_READ()						GPIO_ReadInputDataBit(SW_FAULT_GPIO_PORT, HP_FAULT_PIN)
#define OFP_FAULT_READ()					GPIO_ReadInputDataBit(SW_FAULT_GPIO_PORT, OFP_FAULT_PIN)
#define TP_FAULT_READ()						GPIO_ReadInputDataBit(SW_FAULT_GPIO_PORT, TP_FAULT_PIN)

#define SHIELD_DRV_ERR_CNT			300

extern uint16_t g_ShieldDrvErrCnt_10ms;

void SW_ERROR_GPIO_Config(void);
void Handle_SwitchFaultDetect(void);
#endif /* __FAULT_H */
