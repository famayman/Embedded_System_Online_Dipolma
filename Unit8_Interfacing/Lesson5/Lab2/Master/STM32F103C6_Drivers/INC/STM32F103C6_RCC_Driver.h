/*
 * STM32F103C6_RCC_Driver.h
 *
 *  Created on: Aug 10, 2022
 *      Author: Fam Ayman
 */

#ifndef INC_STM32F103C6_RCC_DRIVER_H_
#define INC_STM32F103C6_RCC_DRIVER_H_
#include "STM32F103C6_GPIO_Driver.h"
#include "sTM32F103x8.h"
#define HSE_CLK		(uint32_t)16000000
#define HSI_RC_CLK	(uint32_t)8000000
uint32_t MCAL_RCC_GetSysClkFreq(void);
uint32_t MCAL_RCC_GetHClkFreq(void);
uint32_t MCAL_RCC_GetPClk1Freq(void);
uint32_t MCAL_RCC_GetPClk2Freq(void);
#endif /* INC_STM32F103C6_RCC_DRIVER_H_ */
