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

#define NVIC_Base			(0xE000E100UL)
#define NVIC_ISER0			*(volatile uint32_t *)(NVIC_Base + 0x0)
#define NVIC_ISER1			*(volatile uint32_t *)(NVIC_Base + 0x4)
#define NVIC_ISER2			*(volatile uint32_t *)(NVIC_Base + 0x8)
#define NVIC_ICER0			*(volatile uint32_t *)(NVIC_Base + 0x80)
#define NVIC_ICER1			*(volatile uint32_t *)(NVIC_Base + 0x84)
#define NVIC_ICER2			*(volatile uint32_t *)(NVIC_Base +  0x88)
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
//Uart1
#define USART1_Base		0x40013800
//SPI1
#define SPI1_Base		0x40013000
//-----------------------------
//Base addresses for APB1 BUS Peripherals
//-----------------------------
#define USART2_Base		0x40004400
#define USART3_Base		0x40004800
#define Uart4_Base		0x40004C00
#define Uart5_Base		0x40005000
#define SPI2_Base		0x40003800
//========================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:SPI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t	SPI_CR1;
	volatile uint32_t	SPI_CR2;
	volatile uint32_t	SPI_SR;
	volatile uint32_t	SPI_DR;
	volatile uint32_t	SPI_CPCRP;
	volatile uint32_t	SPI_RXCRCR;
	volatile uint32_t	SPI_TXCRCR;
	volatile uint32_t	SPI_I2SCFGR;
	volatile uint32_t	SPI_I2SPR;
}S_SPI_t;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:USART
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t	USART_SR;
	volatile uint32_t	USART_DR;
	volatile uint32_t	USART_BRR;
	volatile uint32_t	USART_CR1;
	volatile uint32_t	USART_CR2;
	volatile uint32_t	USART_CR3;
	volatile uint32_t	USART_GTPR;
}S_Usart_t;
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
	volatile uint32_t AFIO_EXTICR[4];
	volatile uint32_t Reserved;
	volatile uint32_t AFIO_MAPR2;

}S_AFIO_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA   	(S_GPIO_t *)GPIOA_Base
#define GPIOB		(S_GPIO_t *)GPIOB_Base
#define GPIOC		(S_GPIO_t *)GPIOC_Base
#define GPIOD		(S_GPIO_t *)GPIOD_Base
#define GPIOE		(S_GPIO_t *)GPIOE_Base

#define RCC     	(S_RCC_t *)RCC_Base

#define EXTI    	(S_EXTI_t*)EXTI_Base

#define AFIO    	(S_AFIO_t *)AFIO_Base

#define USART1  	((S_Usart_t*)USART1_Base)
#define USART2		((S_Usart_t*)USART2_Base)
#define USART3		((S_Usart_t*)USART3_Base)
#define SPI1		((S_SPI_t*)SPI1_Base)
#define SPI2		((S_SPI_t*)SPI2_Base)

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
//Clk Enable USART
#define RCC_USART1_CLK_EN()			(PTR->RCC_APB2ENR |= (1<<14))
#define RCC_USART2_CLK_EN()			(PTR->RCC_APB1ENR |= (1<<17))
#define RCC_USART3_CLK_EN()			(PTR->RCC_APB1ENR |= (1<<18))
//Clk Disable USART
#define RCC_USART1_Reset()			(PTR->RCC_APB2RSTR |= (1<<14))
#define RCC_USART2_Reset()			(PTR->RCC_APB1RSTR |= (1<<17))
#define RCC_USART3_Reset()			(PTR->RCC_APB1RSTR |= (1<<18))
//CLK Enable SPI
#define RCC_SPI1_CLK_EN()			(PTR->RCC_APB2ENR |= (1<<12))
#define RCC_SPI2_CLK_EN()			(PTR->RCC_APB1ENR |= (1<<14))
//CLK Disable SPI
#define RCC_SPI1_CLK_Reset()		(PTR->RCC_APB2RSTR |= (1<<12))
#define RCC_SPI2_CLK_Reset()		(PTR->RCC_APB1RSTR |= (1<<14))
//EXTI0

#define EXTI0_IRQ	6
#define EXTI1_IRQ	7
#define EXTI2_IRQ	8
#define EXTI3_IRQ	9
#define EXTI4_IRQ	10
#define EXTI5_IRQ	23
#define EXTI6_IRQ	23
#define EXTI7_IRQ	23
#define EXTI8_IRQ	23
#define EXTI9_IRQ	23
#define EXTI10_IRQ	40
#define EXTI11_IRQ	40
#define EXTI12_IRQ	40
#define EXTI13_IRQ	40
#define EXTI14_IRQ	40
#define EXTI15_IRQ	40
#define USART1_IRQ	37
#define USART2_IRQ	38
#define USART3_IRQ	39
#define SPI1_IRQ	35
#define SPI2_IRQ	36
//-*-*-*-*-*-*-*-*-*-*-*-
//NVIC IRQ Enable/Disable Macro
//-*-*-*-*-*-*-*-*-*-*-*

#define NVIC_IRQ6_EXTI0_Enable				(NVIC_ISER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_Enable				(NVIC_ISER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_Enable				(NVIC_ISER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_Enable				(NVIC_ISER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_Enable				(NVIC_ISER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_Enable			(NVIC_ISER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_Enable			(NVIC_ISER1 |= (1<<8)) //40-32 = 8
#define NVIC_IRQ6_EXTI0_Disable				(NVIC_ICER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_Disable				(NVIC_ICER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_Disable				(NVIC_ICER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_Disable				(NVIC_ICER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_Disable			(NVIC_ICER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_Disable			(NVIC_ICER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_Disable		(NVIC_ICER1 |= (1<<8))
//USart
#define	NVIC_IRQ37_USART1_Enable			(NVIC_ISER1 |= 1<<(USART1_IRQ - 32))
#define NVIC_IRQ38_USART2_Enable			(NVIC_ISER1 |= 1<<(USART2_IRQ - 32))
#define NVIC_IRQ39_USART3_Enable			(NVIC_ISER1 |= 1<<(USART3_IRQ - 32))


#define NVIC_IRQ37_USART1_Disable			(NVIC_ICER1 |= 1<<(USART1_IRQ - 32))
#define NVIC_IRQ38_USART2_Disable			(NVIC_ICER1 |= 1<<(USART2_IRQ -	32))
#define NVIC_IRQ39_USART3_Disable			(NVIC_ICER1 |= 1<<(USART3_IRQ - 32))

//SPI
#define NVIC_IRQ35_SPI1_Enable				(NVIC_ISER1 |= 1<<(SPI1_IRQ - 32))
#define NVIC_IRQ36_SPI2_Enable				(NVIC_ISER1 |= 1<<(SPI2_IRQ - 32))

#define NVIC_IRQ35_SPI1_Disable				(NVIC_ICER1 &= ~(1<<(SPI1_IRQ - 32)))
#define NVIC_IRQ36_SPI2_Disable				(NVIC_ICER1 &= ~(1<<(SPI2_IRQ - 32)))


#endif /* INC_STM32F103X8_H_ */
