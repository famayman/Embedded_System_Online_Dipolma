/*
 * STM32F103C6_GPIO_Driver.c
 *
 *  Created on: Aug 10, 2022
 *      Author: Fam Ayman
 */
#include "STM32F103C6_RCC_Driver.h"
#include "STM32F103C6_USART_Driver.h"


/*
 * ========================================================
 * 				Generic Variables
 * ========================================================
 */
S_UART_Config_t *Global_UART_Config = NULL;
/*
 * ========================================================
 * 				Generic Functions
 * ========================================================
 */

/*
 * ========================================================
 * 							APIS
 * ========================================================
 */
/**=======================================================
 * @Fn				-MCAL_UART_Init
 * @brief			-Initializes UART
 * @param [in]		-UART_Instance
 * @param [in]		-UART_Cfg
 * @retval			-None
 * Note
 */
void MCAL_UART_Init(S_Usart_t * USARTx , S_UART_Config_t * Config)
{
	uint32_t Pclk,BRR;
	Global_UART_Config = Config;

	//Enable Clock for given UART

	if(USARTx == USART1)
		RCC_USART1_CLK_EN();
	else if (USARTx == USART2)
		RCC_USART2_CLK_EN();
	else if (USARTx == USART3)
		RCC_USART3_CLK_EN();

	//Enable USART_Module

	USARTx->USART_CR1 |= 1<<13;

	//Enable USART Tx and Rx

	USARTx->USART_CR1 |= Config->USART_Mode;

	//Payload

	USARTx->USART_CR1 |= Config->Pay_Load_Length;

	//Parity

	USARTx->USART_CR1 |=Config->Parity;

	//Number of Stop bits

	USARTx->USART_CR2 |=Config->Stop_Bits;

	//HwFlowCTL

	USARTx->USART_CR3 |=Config->HwFlowCTRL;
	//

	//Configuration of BRR(Baudrate register)
	//PCLK1 for USART2,3
	//PCLK2 for USART1
	if(USARTx == USART1)
	{
		Pclk = MCAL_RCC_GetPClk2Freq();
	}
	else
	{
		Pclk = MCAL_RCC_GetPClk1Freq();
	}
	BRR = UART_BRR_Register(Pclk,Config->USART_BaudRate);
	USARTx->USART_BRR = BRR;
	//Enable / Disable Interrupt
	if(Config->IRQ_Enable != UART_IRQ_Enalbe_NONE)
	{
		USARTx->USART_CR1 |= (Config->IRQ_Enable);

		//Enable NVIC for USART
		if (USARTx == USART1)
			NVIC_IRQ37_USART1_Enable ;
		else if (USARTx == USART2)
			NVIC_IRQ38_USART2_Enable ;
		else if (USARTx == USART3)
			NVIC_IRQ39_USART3_Enable ;


	}
}
/**=======================================================
 * @Fn				-MCAL_UART_DeInit
 * @brief			-DeInitializes UART
 * @param [in]		-UART_Instance
 * @retval			-None
 * Note
 */
void MCAL_UART_DeInit(S_Usart_t * USARTx)
{
	if (USARTx == USART1)
	{
		RCC_USART1_Reset();
		NVIC_IRQ37_USART1_Disable;
	}
	else if (USARTx == USART2)
	{
		RCC_USART2_Reset();
		NVIC_IRQ38_USART2_Disable;
	}
	else if (USARTx == USART3)
	{
		RCC_USART2_Reset();
		NVIC_IRQ38_USART2_Disable;
	}
}
/**=======================================================
 * @Fn				-MCAL_UART_Send_Data
 * @brief			-Sends Data through UART
 * @param [in]		-UART_Instance
 * @param [in]		-Data
 * @param [in]		-Polling_Mechism
 * @retval			-None
 * Note
 */
void MCAL_UART_SendData(S_Usart_t * USARTX , uint16_t * pTXBuffer , enum polling_mechanism Polling_En)
{
	if (Polling_En == Enable)
	{
		while(!(USARTX->USART_SR & 1<<7));
	}
	//Check Word Length
	if (Global_UART_Config->Pay_Load_Length == UART_Pay_Load_Length_9bit)
	{
		USARTX->USART_DR = (*pTXBuffer & (uint16_t)0x01FF);
	}
	else
	{
		//This is 8bit_data_transfer
		USARTX->USART_DR  = (*pTXBuffer & (uint8_t)0xFF);
	}
}
/**=======================================================
 * @Fn				-MCAL_UART_Send_Data
 * @brief			-Sends Data through UART
 * @param [in]		-UART_Instance
 * @param [in]		-Data
 * @param [in]		-Polling_Mechism
 * @retval			-None
 * Note
 */
void MCAL_UART_WAIT_TC (S_Usart_t * USARTx)
{
	while(!(USARTx->USART_SR & 1<<6));
}
/**=======================================================
 * @Fn				-MCAL_UART_Send_Data
 * @brief			-Sends Data through UART
 * @param [in]		-UART_Instance
 * @param [in]		-Data
 * @param [in]		-Polling_Mechism
 * @retval			-None
 * Note
 */
void MCAL_UART_ReceiveData(S_Usart_t * USARTx,uint16_t * pRXBuffer , enum polling_mechanism Polling_En)
{
	//wait until RXNE flag is set in the SR
	if(Polling_En == Enable)
	{
		while(!(USARTx->USART_SR & 1<<5));
	}
	if (Global_UART_Config->Pay_Load_Length == UART_Pay_Load_Length_9bit)
	{
		if(Global_UART_Config->Parity == UART_Parity_NONE)
			*(pRXBuffer) = USARTx->USART_DR;
		else
			*(pRXBuffer) = (USARTx->USART_DR &(uint8_t)0xFF);
	}
	else
	{
		if(Global_UART_Config->Parity == UART_Parity_NONE)
			*((uint16_t*)pRXBuffer) = USARTx->USART_DR;
		else
			*((uint16_t*)pRXBuffer) = (USARTx->USART_DR &(uint8_t)0x7F);

	}

}
void MCAL_UART_GPIO_Set_Pins(S_Usart_t * USARTx)
{
	GPIO_Pin_Config_t PinCfg;
	if (USARTx == USART1)
	{
		//PA9 TX
		PinCfg.GPIO_Pin_Number = GPIO_PIN_9;
		PinCfg.GPIO_Mode =GPIO_Mode_Output_AF_PP;
		PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
		MCAL_GPIO_Init(GPIOA,& PinCfg);
		//PA10 RX
		PinCfg.GPIO_Pin_Number = GPIO_PIN_10;
		PinCfg.GPIO_Mode =GPIO_Mode_AF_Input;
		MCAL_GPIO_Init(GPIOA,& PinCfg);
		//PA11 CTS
		if (Global_UART_Config->HwFlowCTRL == UART_HwFlowCTL_CTS || Global_UART_Config->HwFlowCTRL == UART_HwFlowCTL_RTS_CTS)
		{
			PinCfg.GPIO_Pin_Number = GPIO_PIN_11;
			PinCfg.GPIO_Mode =GPIO_Mode_Input_FLO;
			MCAL_GPIO_Init(GPIOA,& PinCfg);
		}
		if (Global_UART_Config->HwFlowCTRL == UART_HwFlowCTL_CTS || Global_UART_Config->HwFlowCTRL == UART_HwFlowCTL_RTS_CTS)
		{
			//PA12 RTS
			PinCfg.GPIO_Pin_Number = GPIO_PIN_11;
			PinCfg.GPIO_Mode =GPIO_Mode_Input_FLO;
			MCAL_GPIO_Init(GPIOA,& PinCfg);
		}
	}
	else if(USARTx == 	USART2)
	{
		//PA2 TX
		//PA3 RX
		//PA0 CTS
		//PA1 RTS



		//PA2 TX
		PinCfg.GPIO_Pin_Number = GPIO_PIN_2;
		PinCfg.GPIO_Mode = GPIO_Mode_Output_AF_PP;
		PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
		MCAL_GPIO_Init(GPIOA,&PinCfg);


		//PA3 RX
		PinCfg.GPIO_Pin_Number = GPIO_PIN_3;
		PinCfg.GPIO_Mode =GPIO_Mode_Output_AF_PP;
		PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
		MCAL_GPIO_Init(GPIOA,&PinCfg);


		//PA0 CTS
		if (Global_UART_Config->HwFlowCTRL == UART_HwFlowCTL_CTS || Global_UART_Config->HwFlowCTRL == UART_HwFlowCTL_RTS_CTS)
		{
			PinCfg.GPIO_Pin_Number = GPIO_PIN_0;
			PinCfg.GPIO_Mode =GPIO_Mode_Input_FLO;
			MCAL_GPIO_Init(GPIOA,& PinCfg);
		}


		//PA1 RTS

		if (Global_UART_Config->HwFlowCTRL == UART_HwFlowCTL_CTS || Global_UART_Config->HwFlowCTRL == UART_HwFlowCTL_RTS_CTS)
		{
			PinCfg.GPIO_Pin_Number = GPIO_PIN_1;
			PinCfg.GPIO_Mode =GPIO_Mode_Input_FLO;
			MCAL_GPIO_Init(GPIOA,& PinCfg);
		}

	}
	else if(USARTx == 	USART3)
	{
		//PB10 TX
		//PB11 RX
		//PB13 CTS
		//PA14 RTS

		//PB10 TX
		PinCfg.GPIO_Pin_Number = GPIO_PIN_10;
		PinCfg.GPIO_Mode = GPIO_Mode_Output_AF_PP;
		PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
		MCAL_GPIO_Init(GPIOB,&PinCfg);


		//PB11 RX
		PinCfg.GPIO_Pin_Number = GPIO_PIN_11;
		PinCfg.GPIO_Mode =GPIO_Mode_Output_AF_PP;
		PinCfg.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
		MCAL_GPIO_Init(GPIOB,&PinCfg);


		//PB13 CTS
		if (Global_UART_Config->HwFlowCTRL == UART_HwFlowCTL_CTS || Global_UART_Config->HwFlowCTRL == UART_HwFlowCTL_RTS_CTS)
		{
			PinCfg.GPIO_Pin_Number = GPIO_PIN_13;
			PinCfg.GPIO_Mode =GPIO_Mode_Input_FLO;
			MCAL_GPIO_Init(GPIOB,& PinCfg);
		}


		//PA14 RTS

		if (Global_UART_Config->HwFlowCTRL == UART_HwFlowCTL_CTS || Global_UART_Config->HwFlowCTRL == UART_HwFlowCTL_RTS_CTS)
		{
			PinCfg.GPIO_Pin_Number = GPIO_PIN_14;
			PinCfg.GPIO_Mode =GPIO_Mode_Input_FLO;
			MCAL_GPIO_Init(GPIOA,& PinCfg);
		}
	}

}

//ISR
void USART1_IRQHandler (void)
{
	  Global_UART_Config->P_IRQ_CallBack();
}
void USART2_IRQHandler (void)
{

}
void USART3_IRQHandler(void)
{

}
