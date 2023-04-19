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
//I2C1
#define I2C1_Base		0x40005400
//I2C2
#define I2C2_Base		0x40005800
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
//Peripheral register:I2C
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t	I2C_CR1;
	volatile uint32_t	I2C_CR2;
	volatile uint32_t	I2C_OAR1;
	volatile uint32_t	I2C_OAR2;
	volatile uint32_t	I2C_DR;
	volatile uint32_t	I2C_SR1;
	volatile uint32_t	I2C_SR2;
	volatile uint32_t	I2C_CCR;
	volatile uint32_t	I2C_TRISE;
}S_I2C_t;
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
#define I2C1		((S_I2C_t*)I2C1_Base)
#define I2C2		((S_I2C_t*)I2C2_Base)
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
//CLK Enable I2C
#define RCC_I2C1_CLK_EN()			(PTR->RCC_APB1ENR  |= (1<<21))
#define RCC_I2C2_CLK_EN()			(PTR->RCC_APB1ENR  |= (1<<22))
//CLK Disable I2C
#define RCC_I2C1_CLK_Reset()		(PTR->RCC_APB1RSTR |= (1<<21))
#define RCC_I2C2_CLK_Reset()		(PTR->RCC_APB1RSTR |= (1<<22))

//EXTI0

#define EXTI0_IRQ	6
#define EXTI1_IRQ	7
#define EXTI2_IRQ	8
#define EXTI3_IRQ	9
#define EXTI4_IRQ	10
#define EXTI5_IRQ	23
#define EXTI6_IRQ	23
#define EXTI7_IRQ		23
#define EXTI8_IRQ		23
#define EXTI9_IRQ		23
#define EXTI10_IRQ		40
#define EXTI11_IRQ		40
#define EXTI12_IRQ		40
#define EXTI13_IRQ		40
#define EXTI14_IRQ		40
#define EXTI15_IRQ		40
#define USART1_IRQ		37
#define USART2_IRQ		38
#define USART3_IRQ		39
#define SPI1_IRQ		35
#define SPI2_IRQ		36
#define I2C1_EV_IRQ		31
#define I2C1_ER_IRQ		32
#define I2C2_EV_IRQ		33
#define I2C2_ER_IRQ		34
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
//I2C
#define NVIC_IRQ31_I2C1_EV_Enable			(NVIC_ISER0 |= 1<<(I2C1_EV_IRQ))
#define NVIC_IRQ32_I2C1_ER_Enable			(NVIC_ISER1 |= 1<<(I2C1_ER_IRQ - 32))
#define NVIC_IRQ33_I2C2_EV_Enable			(NVIC_ISER1 |= 1<<(I2C2_EV_IRQ - 32))
#define NVIC_IRQ34_I2C2_ER_Enable			(NVIC_ISER1 |= 1<<(I2C2_ER_IRQ - 32))

#define NVIC_IRQ31_I2C1_EV_Disable   		(NVIC_ICER0 &= ~(1<<(I2C1_EV_IRQ)))
#define NVIC_IRQ32_I2C1_ER_Disable			(NVIC_ICER1 &= ~(1<<(I2C1_ER_IRQ - 32)))
#define NVIC_IRQ33_I2C2_EV_Disable			(NVIC_ICER1 &= ~(1<<(I2C2_EV_IRQ - 32)))
#define NVIC_IRQ34_I2C2_ER_Disable			(NVIC_ICER1 &= ~(1<<(I2C2_ER_IRQ - 32)))


/********************************************************/
/********************************************************/
/********************************************************/
/*******************  Bit definition  ********************/
/********************************************************/
/********************************************************/



/*******************  Bit definition for I2C_CR1 register  ********************/
#define I2C_CR1_PE_Pos                      (0U)
#define I2C_CR1_PE_Msk                      (0x1UL << I2C_CR1_PE_Pos)           /*!< 0x00000001 */
#define I2C_CR1_PE                          I2C_CR1_PE_Msk                     /*!< Peripheral Enable */
#define I2C_CR1_SMBUS_Pos                   (1U)
#define I2C_CR1_SMBUS_Msk                   (0x1UL << I2C_CR1_SMBUS_Pos)        /*!< 0x00000002 */
#define I2C_CR1_SMBUS                       I2C_CR1_SMBUS_Msk                  /*!< SMBus Mode */
#define I2C_CR1_SMBTYPE_Pos                 (3U)
#define I2C_CR1_SMBTYPE_Msk                 (0x1UL << I2C_CR1_SMBTYPE_Pos)      /*!< 0x00000008 */
#define I2C_CR1_SMBTYPE                     I2C_CR1_SMBTYPE_Msk                /*!< SMBus Type */
#define I2C_CR1_ENARP_Pos                   (4U)
#define I2C_CR1_ENARP_Msk                   (0x1UL << I2C_CR1_ENARP_Pos)        /*!< 0x00000010 */
#define I2C_CR1_ENARP                       I2C_CR1_ENARP_Msk                  /*!< ARP Enable */
#define I2C_CR1_ENPEC_Pos                   (5U)
#define I2C_CR1_ENPEC_Msk                   (0x1UL << I2C_CR1_ENPEC_Pos)        /*!< 0x00000020 */
#define I2C_CR1_ENPEC                       I2C_CR1_ENPEC_Msk                  /*!< PEC Enable */
#define I2C_CR1_ENGC_Pos                    (6U)
#define I2C_CR1_ENGC_Msk                    (0x1UL << I2C_CR1_ENGC_Pos)         /*!< 0x00000040 */
#define I2C_CR1_ENGC                        I2C_CR1_ENGC_Msk                   /*!< General Call Enable */
#define I2C_CR1_NOSTRETCH_Pos               (7U)
#define I2C_CR1_NOSTRETCH_Msk               (0x1UL << I2C_CR1_NOSTRETCH_Pos)    /*!< 0x00000080 */
#define I2C_CR1_NOSTRETCH                   I2C_CR1_NOSTRETCH_Msk              /*!< Clock Stretching Disable (Slave mode) */
#define I2C_CR1_START_Pos                   (8U)
#define I2C_CR1_START_Msk                   (0x1UL << I2C_CR1_START_Pos)        /*!< 0x00000100 */
#define I2C_CR1_START                       I2C_CR1_START_Msk                  /*!< Start Generation */
#define I2C_CR1_STOP_Pos                    (9U)
#define I2C_CR1_STOP_Msk                    (0x1UL << I2C_CR1_STOP_Pos)         /*!< 0x00000200 */
#define I2C_CR1_STOP                        I2C_CR1_STOP_Msk                   /*!< Stop Generation */
#define I2C_CR1_ACK_Pos                     (10U)
#define I2C_CR1_ACK_Msk                     (0x1UL << I2C_CR1_ACK_Pos)          /*!< 0x00000400 */
#define I2C_CR1_ACK                         I2C_CR1_ACK_Msk                    /*!< Acknowledge Enable */
#define I2C_CR1_POS_Pos                     (11U)
#define I2C_CR1_POS_Msk                     (0x1UL << I2C_CR1_POS_Pos)          /*!< 0x00000800 */
#define I2C_CR1_POS                         I2C_CR1_POS_Msk                    /*!< Acknowledge/PEC Position (for data reception) */
#define I2C_CR1_PEC_Pos                     (12U)
#define I2C_CR1_PEC_Msk                     (0x1UL << I2C_CR1_PEC_Pos)          /*!< 0x00001000 */
#define I2C_CR1_PEC                         I2C_CR1_PEC_Msk                    /*!< Packet Error Checking */
#define I2C_CR1_ALERT_Pos                   (13U)
#define I2C_CR1_ALERT_Msk                   (0x1UL << I2C_CR1_ALERT_Pos)        /*!< 0x00002000 */
#define I2C_CR1_ALERT                       I2C_CR1_ALERT_Msk                  /*!< SMBus Alert */
#define I2C_CR1_SWRST_Pos                   (15U)
#define I2C_CR1_SWRST_Msk                   (0x1UL << I2C_CR1_SWRST_Pos)        /*!< 0x00008000 */
#define I2C_CR1_SWRST                       I2C_CR1_SWRST_Msk                  /*!< Software Reset */
/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_FREQ_Pos                    (0U)
#define I2C_CR2_FREQ_Msk                    (0x3FUL << I2C_CR2_FREQ_Pos)        /*!< 0x0000003F */
#define I2C_CR2_FREQ                        I2C_CR2_FREQ_Msk                   /*!< FREQ[5:0] bits (Peripheral Clock Frequency) */
#define I2C_CR2_ITERREN_Pos                 (8U)
#define I2C_CR2_ITERREN_Msk                 (0x1UL << I2C_CR2_ITERREN_Pos)      /*!< 0x00000100 */
#define I2C_CR2_ITERREN                     I2C_CR2_ITERREN_Msk                /*!< Error Interrupt Enable */
#define I2C_CR2_ITEVTEN_Pos                 (9U)
#define I2C_CR2_ITEVTEN_Msk                 (0x1UL << I2C_CR2_ITEVTEN_Pos)      /*!< 0x00000200 */
#define I2C_CR2_ITEVTEN                     I2C_CR2_ITEVTEN_Msk                /*!< Event Interrupt Enable */
#define I2C_CR2_ITBUFEN_Pos                 (10U)
#define I2C_CR2_ITBUFEN_Msk                 (0x1UL << I2C_CR2_ITBUFEN_Pos)      /*!< 0x00000400 */
#define I2C_CR2_ITBUFEN                     I2C_CR2_ITBUFEN_Msk                /*!< Buffer Interrupt Enable */
#define I2C_CR2_DMAEN_Pos                   (11U)
#define I2C_CR2_DMAEN_Msk                   (0x1UL << I2C_CR2_DMAEN_Pos)        /*!< 0x00000800 */
#define I2C_CR2_DMAEN                       I2C_CR2_DMAEN_Msk                  /*!< DMA Requests Enable */
#define I2C_CR2_LAST_Pos                    (12U)
#define I2C_CR2_LAST_Msk                    (0x1UL << I2C_CR2_LAST_Pos)         /*!< 0x00001000 */
#define I2C_CR2_LAST                        I2C_CR2_LAST_Msk                   /*!< DMA Last Transfer */
/*******************  Bit definition for I2C_OAR2 register  *******************/
#define I2C_OAR2_ENDUAL_Pos                 (0U)
#define I2C_OAR2_ENDUAL_Msk                 (0x1UL << I2C_OAR2_ENDUAL_Pos)      /*!< 0x00000001 */
#define I2C_OAR2_ENDUAL                     I2C_OAR2_ENDUAL_Msk                /*!< Dual addressing mode enable */
#define I2C_OAR2_ADD2_Pos                   (1U)
/*******************  Bit definition for I2C_SR1 register  ********************/
#define I2C_SR1_SB_Pos                      (0U)
#define I2C_SR1_SB_Msk                      (0x1UL << I2C_SR1_SB_Pos)           /*!< 0x00000001 */
#define I2C_SR1_SB                          I2C_SR1_SB_Msk                     /*!< Start Bit (Master mode) */
#define I2C_SR1_ADDR_Pos                    (1U)
#define I2C_SR1_ADDR_Msk                    (0x1UL << I2C_SR1_ADDR_Pos)         /*!< 0x00000002 */
#define I2C_SR1_ADDR                        I2C_SR1_ADDR_Msk                   /*!< Address sent (master mode)/matched (slave mode) */
#define I2C_SR1_BTF_Pos                     (2U)
#define I2C_SR1_BTF_Msk                     (0x1UL << I2C_SR1_BTF_Pos)          /*!< 0x00000004 */
#define I2C_SR1_BTF                         I2C_SR1_BTF_Msk                    /*!< Byte Transfer Finished */
#define I2C_SR1_ADD10_Pos                   (3U)
#define I2C_SR1_ADD10_Msk                   (0x1UL << I2C_SR1_ADD10_Pos)        /*!< 0x00000008 */
#define I2C_SR1_ADD10                       I2C_SR1_ADD10_Msk                  /*!< 10-bit header sent (Master mode) */
#define I2C_SR1_STOPF_Pos                   (4U)
#define I2C_SR1_STOPF_Msk                   (0x1UL << I2C_SR1_STOPF_Pos)        /*!< 0x00000010 */
#define I2C_SR1_STOPF                       I2C_SR1_STOPF_Msk                  /*!< Stop detection (Slave mode) */
#define I2C_SR1_RXNE_Pos                    (6U)
#define I2C_SR1_RXNE_Msk                    (0x1UL << I2C_SR1_RXNE_Pos)         /*!< 0x00000040 */
#define I2C_SR1_RXNE                        I2C_SR1_RXNE_Msk                   /*!< Data Register not Empty (receivers) */
#define I2C_SR1_TXE_Pos                     (7U)
#define I2C_SR1_TXE_Msk                     (0x1UL << I2C_SR1_TXE_Pos)          /*!< 0x00000080 */
#define I2C_SR1_TXE                         I2C_SR1_TXE_Msk                    /*!< Data Register Empty (transmitters) */
#define I2C_SR1_BERR_Pos                    (8U)
#define I2C_SR1_BERR_Msk                    (0x1UL << I2C_SR1_BERR_Pos)         /*!< 0x00000100 */
#define I2C_SR1_BERR                        I2C_SR1_BERR_Msk                   /*!< Bus Error */
#define I2C_SR1_ARLO_Pos                    (9U)
#define I2C_SR1_ARLO_Msk                    (0x1UL << I2C_SR1_ARLO_Pos)         /*!< 0x00000200 */
#define I2C_SR1_ARLO                        I2C_SR1_ARLO_Msk                   /*!< Arbitration Lost (master mode) */
#define I2C_SR1_AF_Pos                      (10U)
#define I2C_SR1_AF_Msk                      (0x1UL << I2C_SR1_AF_Pos)           /*!< 0x00000400 */
#define I2C_SR1_AF                          I2C_SR1_AF_Msk                     /*!< Acknowledge Failure */
#define I2C_SR1_OVR_Pos                     (11U)
#define I2C_SR1_OVR_Msk                     (0x1UL << I2C_SR1_OVR_Pos)          /*!< 0x00000800 */
#define I2C_SR1_OVR                         I2C_SR1_OVR_Msk                    /*!< Overrun/Underrun */
#define I2C_SR1_PECERR_Pos                  (12U)
#define I2C_SR1_PECERR_Msk                  (0x1UL << I2C_SR1_PECERR_Pos)       /*!< 0x00001000 */
#define I2C_SR1_PECERR                      I2C_SR1_PECERR_Msk                 /*!< PEC Error in reception */
#define I2C_SR1_TIMEOUT_Pos                 (14U)
#define I2C_SR1_TIMEOUT_Msk                 (0x1UL << I2C_SR1_TIMEOUT_Pos)      /*!< 0x00004000 */
#define I2C_SR1_TIMEOUT                     I2C_SR1_TIMEOUT_Msk                /*!< Timeout or Tlow Error */
#define I2C_SR1_SMBALERT_Pos                (15U)
#define I2C_SR1_SMBALERT_Msk                (0x1UL << I2C_SR1_SMBALERT_Pos)     /*!< 0x00008000 */
#define I2C_SR1_SMBALERT                    I2C_SR1_SMBALERT_Msk               /*!< SMBus Alert */

/*******************  Bit definition for I2C_SR2 register  ********************/
#define I2C_SR2_MSL_Pos                     (0U)
#define I2C_SR2_MSL_Msk                     (0x1UL << I2C_SR2_MSL_Pos)          /*!< 0x00000001 */
#define I2C_SR2_MSL                         I2C_SR2_MSL_Msk                    /*!< Master/Slave */
#define I2C_SR2_BUSY_Pos                    (1U)
#define I2C_SR2_BUSY_Msk                    (0x1UL << I2C_SR2_BUSY_Pos)         /*!< 0x00000002 */
#define I2C_SR2_BUSY                        I2C_SR2_BUSY_Msk                   /*!< Bus Busy */
#define I2C_SR2_TRA_Pos                     (2U)
#define I2C_SR2_TRA_Msk                     (0x1UL << I2C_SR2_TRA_Pos)          /*!< 0x00000004 */
#define I2C_SR2_TRA                         I2C_SR2_TRA_Msk                    /*!< Transmitter/Receiver */
#define I2C_SR2_GENCALL_Pos                 (4U)
#define I2C_SR2_GENCALL_Msk                 (0x1UL << I2C_SR2_GENCALL_Pos)      /*!< 0x00000010 */
#define I2C_SR2_GENCALL                     I2C_SR2_GENCALL_Msk                /*!< General Call Address (Slave mode) */
#define I2C_SR2_SMBDEFAULT_Pos              (5U)
#define I2C_SR2_SMBDEFAULT_Msk              (0x1UL << I2C_SR2_SMBDEFAULT_Pos)   /*!< 0x00000020 */
#define I2C_SR2_SMBDEFAULT                  I2C_SR2_SMBDEFAULT_Msk             /*!< SMBus Device Default Address (Slave mode) */
#define I2C_SR2_SMBHOST_Pos                 (6U)
#define I2C_SR2_SMBHOST_Msk                 (0x1UL << I2C_SR2_SMBHOST_Pos)      /*!< 0x00000040 */
#define I2C_SR2_SMBHOST                     I2C_SR2_SMBHOST_Msk                /*!< SMBus Host Header (Slave mode) */
#define I2C_SR2_DUALF_Pos                   (7U)
#define I2C_SR2_DUALF_Msk                   (0x1UL << I2C_SR2_DUALF_Pos)        /*!< 0x00000080 */
#define I2C_SR2_DUALF                       I2C_SR2_DUALF_Msk                  /*!< Dual Flag (Slave mode) */
#define I2C_SR2_PEC_Pos                     (8U)
#define I2C_SR2_PEC_Msk                     (0xFFUL << I2C_SR2_PEC_Pos)         /*!< 0x0000FF00 */
#define I2C_SR2_PEC                         I2C_SR2_PEC_Msk                    /*!< Packet Error Checking Register */













#endif /* INC_STM32F103X8_H_ */
