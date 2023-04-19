/*
 * STM32F103C6_GPIO_Driver.c
 *
 *  Created on: Aug 10, 2022
 *      Author: Fam Ayman
 */
#include "STM32F103C6_RCC_Driver.h"

/*
 * ======================================================================
 *                                          Generic variables
 *======================================================================
 */



/*
 * ======================================================================
 *                                          Generic Macros
 *======================================================================
 */



/*
 * ======================================================================
 *                                          Generic Functions
 *======================================================================
 */





/*
 * ====================================================================================================
 *                          APIs Functions Definations
 * ====================================================================================================
 */
//Bits 10:8 PPRE1[2:0]: APB Low-speed prescaler (APB1)
//Set and cleared by software to control the division factor of the APB Low speed clock (PCLK1).
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 16
//Caution: Software must configure these bits ensure that the frequency in this domain does not
//exceed 36 MHz.
const uint8_t APBPRrescTable[8U] = { 0,0,0,0,1,2,3,4};//shift 1 right == multiply by 2


//Bits 7:4 HPRE[3:0]: AHB prescaler
//Set and cleared by software to control AHB clock division factor.
//0xxx: SYSCLK not divided
//1000: SYSCLK divided by 2
//1001: SYSCLK divided by 4
//1010: SYSCLK divided by 8
//1011: SYSCLK divided by 16
//1100: SYSCLK divided by 64
//1101: SYSCLK divided by 128
//1110: SYSCLK divided by 256
//1111: SYSCLK divided by 512
const uint8_t AHBPRrescTable[16U] = { 0,0,0,0,0,0,0,0,1,2,3,4,6,7,8,9};//shift 1 right == multiply by 2
uint32_t MCAL_PTR_GetSYSCLK1Freq(void)
{
//	Bits 3:2 SWS[1:0]: System clock switch status
//	Set and cleared by hardware to indicate which clock source is used as system clock.
//	00: HSI oscillator used as system clock
//	01: HSE oscillator used as system clock
//	10: PLL used as system clock
//	11: Not applicable
switch((PTR->RCC_CFGR >> 2) &0b11)
		{
case 0:
	return HSI_RC_CLK;
	break;
case 1:
	//to do need to calculate it //externel
	return HSE_CLK ;
	break;
case 2:
	//to do need to calculate it
		return 16000000 ;

	break;

		}
}
uint32_t MCAL_RCC_GetHCLKFreq(void)
{
	//Bits 7:4 HPRE[3:0]: AHB prescaler
	return (MCAL_PTR_GetSYSCLK1Freq() >> AHBPRrescTable[(PTR->RCC_CFGR >> 4) &0b1111]);
}
uint32_t MCAL_RCC_GetPCLK1Freq(void)
{
	//	Bits 13:11 PPRE2[2:0]: APB high-speed prescaler (APB2)
	return (MCAL_RCC_GetHCLKFreq() >> APBPRrescTable[(PTR->RCC_CFGR >> 8) &0b111]);
}
uint32_t MCAL_RCC_GetPCLK2Freq(void)
{
//	Bits 13:11 PPRE2[2:0]: APB high-speed prescaler (APB2)
	return (MCAL_RCC_GetHCLKFreq() >> APBPRrescTable[(PTR->RCC_CFGR >> 11) &0b111]);
}
