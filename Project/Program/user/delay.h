#ifndef __DELAY_H
#define __DELAY_H 		

#include "sh32f9xx_sb0_libcfg.h"
	 
void delay_init(void);
void delay_us(uint32_t nus);
void delay_ms(uint16_t nms);

#endif





























