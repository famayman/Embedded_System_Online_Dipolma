/*
 * sTM32F103x8.h
 *
 *  Created on: Aug 10, 2022
 *      Author: Fam Ayman
 */

#ifndef INC_STM32F103X8_H_
#define INC_STM32F103X8_H_
//-----------------------------
//Includes
//-----------------------------
#include "stdlib.h"
#include "stdint.h"
//-----------------------------
//Base addresses for Memories
//-----------------------------
#define Flash_Memory_Base	0x08000000UL
#define System_Memory_Base	0x1FFFF000UL
#define SRam_Memory_Base	0x20000000UL


#define Peripherals_Base    				0x40000000
#define Cortex_M3_Internal_Peripherals		0xE0000000
//========================================================
//-----------------------------
//Base addresses for AHB BUS Peripherals
//-----------------------------
//RCC
#define RCC_Base   0x40021000
//-----------------------------
//Base addresses for APB2 BUS Peripherals
//-----------------------------
//GPIO
//GPIO A B fully included
#define GPIOA_Base		0x40010800
#define GPIOB_Base		0x40010C00
//GPIO C D Partially
#define GPIOC_Base		0x40011000
#define GPIOD_Base		0x40011400
//GPIO E Excluded
#define GPIOE_Base 		0x40011800
//EXTI
#define EXTI_Base 		0x40010400
//AFIO
#define AFIO_Base 		0x40010000
//-----------------------------
//Base addresses for APB1 BUS Peripherals
//-----------------------------


//========================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
//-*-*-*-*-*-*-*-*-*-*-*


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

}S_GPIO_t;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_APB2RSTR;
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_AHBENR;
	volatile uint32_t RCC_APB2ENR;
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
	volatile uint32_t RCC_AHBSTR;
	volatile uint32_t RCC_CFGR2;
}S_RCC_t;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:EXTI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t EXTI_IMR;
	volatile uint32_t EXTI_EMR;
	volatile uint32_t EXTI_RTSR;
	volatile uint32_t EXTI_FTSR;
	volatile uint32_t EXTI_SWIER;
	volatile uint32_t EXTI_PR;
}S_EXTI_t;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t AFIO_EVCR;
	volatile uint32_t AFIO_MAPR;
	volatile uint32_t AFIO_EXTICR1;
	volatile uint32_t AFIO_EXTICR2;
	volatile uint32_t AFIO_EXTICR3;
	volatile uint32_t AFIO_EXTICR4;
	volatile uint32_t Reserved;
	volatile uint32_t AFIO_MAPR2;

}S_AFIO_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA   (S_GPIO_t *)GPIOA_Base
#define GPIOB	(S_GPIO_t *)GPIOB_Base
#define GPIOC	(S_GPIO_t *)GPIOC_Base
#define GPIOD	(S_GPIO_t *)GPIOD_Base
#define GPIOE	(S_GPIO_t *)GPIOE_Base

#define RCC     (S_RCC_t *)RCC_Base

#define EXTI    (S_GPIO_t *)EXTI_Base

#define AFIO    (S_GPIO_t *)AFIO_Base


//========================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
extern S_RCC_t * PTR;
#define RCC_GPIOA_CLK_EN()			(PTR->RCC_APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_EN()			(PTR->RCC_APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_EN()			(PTR->RCC_APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_EN()			(PTR->RCC_APB2ENR |= (1<<5))
#define RCC_GPIOE_CLK_EN()			(PTR->RCC_APB2ENR |= (1<<6))
#define RCC_AFIO_CLK_EN()  			(PTR->RCC_APB2ENR |= (1<<0))





#endif /* INC_STM32F103X8_H_ */
