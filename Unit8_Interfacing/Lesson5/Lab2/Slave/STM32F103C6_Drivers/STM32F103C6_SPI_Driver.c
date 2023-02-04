/*
 * STM32F103C6_GPIO_Driver.c
 *
 *  Created on: Aug 10, 2022
 *      Author: Fam Ayman
 */
#include "STM32F103C6_RCC_Driver.h"

#include "STM32F103C6_SPI_Driver.h"
#include "sTM32F103x8.h"
/*
 * ========================================================
 * 				Generic Variables
 * ========================================================
 */
S_SPI_Config_t * Global_SPI_Config [2] = {NULL,NULL};


/*
 * ========================================================
 * 				Generic macros
 * ========================================================
 */
#define SPI1_Index 		0
#define SPI2_Index		1
#define SPI_SR_TXE		(uint8_t)(1<<1)
#define SPI_SR_RXNE		(uint8_t)(1<<0)

/*
 * ========================================================
 * 							APIS
 * ========================================================
 */
/**=======================================================
 * @Fn				-MCAL_SPI_Init
 * @brief			-Initializes SPI
 * @param [in]		-SPI_Instance
 * @param [in]		-SPI_Cfg
 * @retval			-Nonuiope
 * Note
 */
void MCAL_SPI_Init(S_SPI_t * SPIx , S_SPI_Config_t * Config)
{
	//safety for registers
	uint16_t tmpreg_CR1 = 0; // will  put its value in register at the end
	uint16_t tmpreg_CR2 = 0; // will  put its value in register at the end
	if(SPIx == SPI1)
	{
		Global_SPI_Config[SPI1_Index] = Config;
		RCC_SPI1_CLK_EN();
	}
	else
	{
		Global_SPI_Config[SPI2_Index] = Config;
		RCC_SPI2_CLK_EN();
	}
	//Enable SPI bit6 in CR1
	tmpreg_CR1 |= (1<<6);
	//Master or slave
	tmpreg_CR1 |= Config->Device_Mode;
	//SPI Communication mode
	tmpreg_CR1 |=Config->Communication_Mode;
	//SPI Frame Format
	tmpreg_CR1 |=Config->Frame_Format;
	//SPI_Payload_Length
	tmpreg_CR1 |=Config->Pay_Load_Length;
	//SPI_Clock_Polarity
	tmpreg_CR1 |=Config->CLock_Polarity;
	//SPI_Clock_Phase
	tmpreg_CR1 |=Config->CLock_Phase;
	//================================NSS==============================
	if(Config->NSS == SPI_NSS_Hard_Master_SS_Output_Enable)
	{
		tmpreg_CR2 |= SPI_NSS_Hard_Master_SS_Output_Enable;
	}
	else if (Config->NSS == SPI_NSS_Hard_Master_SS_No_output)
	{
		tmpreg_CR2 |= SPI_NSS_Hard_Master_SS_No_output;
	}
	else
		tmpreg_CR1 |= Config->NSS;
	//==============================PreScaler=========================
	tmpreg_CR1 |= Config->SPI_Prescaler;

	if(Config->IRQ_Enable != SPI_IRQ_Enable_Non)
	{
		tmpreg_CR2 |= Config->IRQ_Enable;
		if(SPIx == SPI1)
		{
			NVIC_IRQ35_SPI1_Enable;
		}
		else
		{
			NVIC_IRQ36_SPI2_Enable;
		}
	}

	SPIx->SPI_CR1 = tmpreg_CR1;
	SPIx->SPI_CR2 = tmpreg_CR2;
}

/**=======================================================
 * @Fn				-MCAL_SPI_DeInit
 * @brief			-DeInitializes SPI
 * @param [in]		-SPIx: SPI you want to delete
 * @retval			-None
 * Note
 */
void MCAL_SPI_DeInit(S_SPI_t * SPIx)
{
	if(SPIx == SPI1)
	{
		NVIC_IRQ35_SPI1_Disable;
		RCC_SPI1_CLK_Reset();
	}
	else
	{
		NVIC_IRQ36_SPI2_Disable;
		RCC_SPI2_CLK_Reset();
	}
}

/**=======================================================
 * @Fn				-MCAL_SPI_SendData
 * @brief			-Sending Data through SPI
 * @param [in]		-SPIx:Specifies through which SPI you want to transmit your data
 * @param [in]		-pTXBuffer:Specifies Data you want to transmit
 * @param [in]		-Polling_mechism:Waiting or Not
 * @retval			-None
 * Note
 */
void MCAL_SPI_SendData(S_SPI_t * SPIX , uint16_t * pTXBuffer ,  enum SPI_PollingMechanism Polling_En)
{
	if(Polling_En == Enabled)
	{
		while((SPIX->SPI_SR)&(SPI_SR_TXE));//Waiting untill tx buffer is empty
	}

		SPIX->SPI_DR = *pTXBuffer;


}
/**=======================================================
 * @Fn				-MCAL_SPI_GPIO_Set_Pins
 * @brief			-Setting Pins for specified SPI
 * @param [in]		-SPIx:Specifies through which SPI you want to set it pins
 * @retval			-None
 * Note
 */
void MCAL_SPI_GPIO_Set_Pins(S_SPI_t * SPIx)
{
	GPIO_Pin_Config_t PConfig;
	if(SPIx == SPI1)
	{
		//PA4 : SPI1_NSS
		//PA5 : SPI1_SCK
		//PA6 : SPI1_MISO
		//PA7 : SPI1_MOSI
		if(Global_SPI_Config[SPI1_Index]->Device_Mode == SPI_Mode_Master )
		{
			//PA4 : SPI1_NSS
			switch(Global_SPI_Config[SPI1_Index]->NSS)
			{
			case SPI_NSS_Hard_Master_SS_Output_Enable :
			{

				PConfig.GPIO_Pin_Number = GPIO_PIN_4;
				PConfig.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
				PConfig.GPIO_Mode = GPIO_Mode_Output_AF_PP;
				MCAL_GPIO_Init(GPIOA, &PConfig);
				break;
			}
			case SPI_NSS_Hard_Master_SS_No_output:
			{
				PConfig.GPIO_Pin_Number = GPIO_PIN_4;
				PConfig.GPIO_Mode = GPIO_Mode_Input_FLO;
				MCAL_GPIO_Init(GPIOA,&PConfig);
				break;
			}

			}
			//PA5 : SPI1_SCK
			PConfig.GPIO_Pin_Number = GPIO_PIN_5;
			PConfig.GPIO_Mode = GPIO_Mode_Output_AF_PP;
			PConfig.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOA, &PConfig);
			//PA6 : MISO
			PConfig.GPIO_Pin_Number = GPIO_PIN_6;
			PConfig.GPIO_Mode = GPIO_Mode_Input_FLO;
			MCAL_GPIO_Init(GPIOA,&PConfig);
			//PA7 : MOSI
			PConfig.GPIO_Pin_Number = GPIO_PIN_7;
			PConfig.GPIO_Mode = GPIO_Mode_Output_AF_PP;
			PConfig.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOA,&PConfig);
		}
		else
		{
			if (Global_SPI_Config[SPI1_Index]->NSS == SPI_NSS_Hard_Slave )
			{
				PConfig.GPIO_Pin_Number = GPIO_PIN_4;
				PConfig.GPIO_Mode = GPIO_Mode_Input_FLO;
				MCAL_GPIO_Init(GPIOA, &PConfig);
			}
			//PA5 : SPI1_SCK
			PConfig.GPIO_Pin_Number = GPIO_PIN_5;
			PConfig.GPIO_Mode = GPIO_Mode_Input_FLO;
			MCAL_GPIO_Init(GPIOA, &PConfig);
			//PA6 : SPI1_MISO
			PConfig.GPIO_Pin_Number = GPIO_PIN_6;
			PConfig.GPIO_Mode = GPIO_Mode_Output_AF_PP;
			PConfig.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOA, &PConfig);
			//PA7 : MOSI
			PConfig.GPIO_Pin_Number = GPIO_PIN_7;
			PConfig.GPIO_Mode = GPIO_Mode_Input_FLO;
			MCAL_GPIO_Init(GPIOA,&PConfig);
		}
	}
	else
	{
		//PB12 : SPI2_NSS
		//PB13 : SPI2_SCK
		//PB14 : SPI2_MISO
		//PB15 : SPI2_MOSI
		if(Global_SPI_Config[SPI2_Index]->Device_Mode == SPI_Mode_Master )
		{
			//PB12 : SPI2_NSS
			switch(Global_SPI_Config[SPI2_Index]->NSS)
			{
			case SPI_NSS_Hard_Master_SS_Output_Enable :
			{

				PConfig.GPIO_Pin_Number = GPIO_PIN_12;
				PConfig.GPIO_Mode = GPIO_Mode_Output_AF_PP;
				MCAL_GPIO_Init(GPIOB, &PConfig);
				break;
			}
			case SPI_NSS_Hard_Master_SS_No_output:
			{
				PConfig.GPIO_Pin_Number = GPIO_PIN_12;
				PConfig.GPIO_Mode = GPIO_Mode_Input_FLO;
				MCAL_GPIO_Init(GPIOB,&PConfig);
				break;
			}

			}
			//PB13 : SPI2_SCK
			PConfig.GPIO_Pin_Number = GPIO_PIN_13;
			PConfig.GPIO_Mode = GPIO_Mode_Output_AF_PP;
			PConfig.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOB, &PConfig);
			//PB14 : MISO
			PConfig.GPIO_Pin_Number = GPIO_PIN_14;
			PConfig.GPIO_Mode = GPIO_Mode_Input_FLO;
			MCAL_GPIO_Init(GPIOB,&PConfig);
			//PB15 : MOSI
			PConfig.GPIO_Pin_Number = GPIO_PIN_15;
			PConfig.GPIO_Mode = GPIO_Mode_Output_AF_PP;
			PConfig.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOB,&PConfig);
		}
		else
		{
			if (Global_SPI_Config[SPI1_Index]->NSS == SPI_NSS_Hard_Slave )
			{
				PConfig.GPIO_Pin_Number = GPIO_PIN_12;
				PConfig.GPIO_Mode = GPIO_Mode_Input_FLO;
				MCAL_GPIO_Init(GPIOB, &PConfig);
			}
			//PB13 : SPI2_SCK
			PConfig.GPIO_Pin_Number = GPIO_PIN_13;
			PConfig.GPIO_Mode = GPIO_Mode_Input_FLO;
			MCAL_GPIO_Init(GPIOB, &PConfig);
			//PB14 : SPI2_MISO
			PConfig.GPIO_Pin_Number = GPIO_PIN_14;
			PConfig.GPIO_Mode = GPIO_Mode_Output_AF_PP;
			PConfig.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
			MCAL_GPIO_Init(GPIOB, &PConfig);
			//PB15 : MOSI
			PConfig.GPIO_Pin_Number = GPIO_PIN_15;
			PConfig.GPIO_Mode = GPIO_Mode_Input_FLO;
			MCAL_GPIO_Init(GPIOB,&PConfig);
		}
	}
}
void MCAL_SPI_ReceiveData(S_SPI_t * SPIX,uint16_t * pRXBuffer ,  enum SPI_PollingMechanism Polling_En)
{

	if(Polling_En == Enabled)
	{
		while(!(SPIX->SPI_SR & SPI_SR_RXNE));
	}
	*pRXBuffer =SPIX->SPI_DR;
}
/**=======================================================
 * @Fn				-MCAL_SPI_Tx_Rx
 * @brief			-Transmitting and Receiving Data through SPI
 * @param [in]		-SPIx:Specifies through which SPI you want to receive your data
 * @param [in]		-TX_RX_pBuffer:reg which you will transmit or receive data in
 * @param [in]		-Polling_mechism:Waiting or Not
 * @retval			-None
 * Note
 */
void MCAL_SPI_Tx_Rx(S_SPI_t * SPIX ,uint16_t * TX_RX_pBuffer , enum SPI_PollingMechanism Polling_En)
{

	if(Polling_En == Enabled)
	{
		while(!(SPIX->SPI_SR & SPI_SR_TXE));//Waiting untill tx buffer is empty
	}
	SPIX->SPI_DR = *TX_RX_pBuffer;
	if(Polling_En == Enabled)
	{
		while(!(SPIX->SPI_SR & SPI_SR_RXNE));
	}
	*TX_RX_pBuffer =  SPIX->SPI_DR;
}

/*=================================================================*/
/*=========================IRQ=====================================*/
/*=================================================================*/

void SPI1_IRQHandler(void)
{

	struct S_IRQ_SRC irq_src;
	irq_src.TXE = ((SPI1->SPI_SR)&(1<<1)>>1);
	irq_src.RXE = ((SPI1->SPI_SR)&(1<<0)>>0);
	irq_src.ERRI = ((SPI1->SPI_SR)&(1<<4)>>4);
	Global_SPI_Config[SPI1_Index]->P_IRQ_CallBack(irq_src);
}
void SPI2_IRQHandler(void)
{
	struct S_IRQ_SRC irq_src;
	irq_src.TXE = ((SPI2->SPI_SR)&(1<<1)>>1);
	irq_src.RXE = ((SPI2->SPI_SR)&(1<<0)>>0);
	irq_src.ERRI = ((SPI2->SPI_SR)&(1<<4)>>4);
	Global_SPI_Config[SPI2_Index]->P_IRQ_CallBack(irq_src);
}





