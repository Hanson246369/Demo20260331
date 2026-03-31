/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ADC_H
#define __ADC_H

/* Includes ------------------------------------------------------------------*/
#include "sh32f9xx_sb0_libcfg.h"

#define SW_ADC_PIN				GPIO_Pin_2
#define VIN_ADC_PIN				GPIO_Pin_3
#define ADC_GPIO_PORT			GPIOE

#define SW_ADC_CHANNEL			ADC_Channel_22
#define VIN_ADC_CHANNEL			ADC_Channel_23

#define SW_VOLT_THRESHOLD_VALUE		(3.5)
#define VIN_VOLT_THRESHOLD_VALUE	(5.5)

#define SW_OFF		0
#define SW_ON		1

#define ADC_FILTER_NUM			(2)						//

extern float g_SWVoltValue;
extern float g_VinVoltValue;

/** @defgroup ADC_Exported_Functions
  * 
  */
void ADC_Init_Config(void);
void Handle_ADCSampleTask(void);
#endif /* __ADC_H */
