/*
 * SPI.c
 *
 *  Author: Fam Ayman
 */ 
/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */
#include "SPI.h"
#include "GPIO.h"
#include "avr/interrupt.h"
/*
 * ========================================================
 * 				Generic Variables
 * ========================================================
 */
S_SPI_t * SPI1 = (S_SPI_t*)(SPI_Base);
void (*GP_CallBack)(void);
/* ================================================================ */
/* =========================APIs=================================== */
/* ================================================================ */

/*=======================================================
* @Fn				-MCAL_SPI_Init
* @brief			-Initializes SPI
* @param [in]		-SPI_Instance
* @param [in]		-SPI_Config
* @retval			-None
* Note
*/
void MCAL_SPI_Init(S_SPI_Config_t * SPI_Config)
{
	S_GPIO_Config_t * PIN_Config ;
	switch (SPI_Config->SPI_Mode)
	{
		case SPI_Mode_Master:
		{
			SPI1->SPCR_.Bits.Bit4   = PIN_Set; //Configuring SPI as master
			//Configuring SPI SS as output 
			PIN_Config->GPIO_Pin_Mode   = GPIO_Pin_Mode_Output;
			PIN_Config->GPIO_Pin_Number = GPIO_PINS_PIN4;
			MCAL_GPIO_Init(GPIOB,PIN_Config);
			//Configuring clock pin as output
			PIN_Config->GPIO_Pin_Mode   = GPIO_Pin_Mode_Output;
			PIN_Config->GPIO_Pin_Number = GPIO_PINS_PIN7;
			MCAL_GPIO_Init(GPIOB,PIN_Config);
			//Configuring MOSI pin as output
			PIN_Config->GPIO_Pin_Mode   = GPIO_Pin_Mode_Output;
			PIN_Config->GPIO_Pin_Number = GPIO_PINS_PIN5;
			MCAL_GPIO_Init(GPIOB,PIN_Config);
			//Configuring MISO pin as input
			PIN_Config->GPIO_Pin_Mode   = GPIO_Pin_Mode_Output;
			PIN_Config->GPIO_Pin_Number = GPIO_PINS_PIN6;
			MCAL_GPIO_Init(GPIOB,PIN_Config);
			//Specifying Order of transmitted data
			switch(SPI_Config->SPI_Data_Order)
			{
				case SPI_Order_LSB :
					SPI1->SPCR_.Bits.Bit5 = PIN_Set;
					break;
				case SPI_Order_MSB:
					SPI1->SPCR_.Bits.Bit5 = PIN_Reset;
					break;
			}
			switch(SPI_Config->SPI_Speed)
			{
				case SPI_Speed_FCPU_2:
				{
					SPI1->SPSR_.Bits.Bit0 = PIN_Set;
					SPI1->SPCR_.Bits.Bit0 = PIN_Reset;
					SPI1->SPCR_.Bits.Bit1 = PIN_Reset;
					break;
				}
				case SPI_Speed_FCPU_4:
				{
					SPI1->SPSR_.Bits.Bit0 = PIN_Reset;
					SPI1->SPCR_.Bits.Bit0 = PIN_Reset;
					SPI1->SPCR_.Bits.Bit1 = PIN_Reset;
					break;
				}
				case SPI_Speed_FCPU_8:
				{
					SPI1->SPSR_.Bits.Bit0 = PIN_Set;
					SPI1->SPCR_.Bits.Bit0 = PIN_Reset;
					SPI1->SPCR_.Bits.Bit1 = PIN_Set;
					break;
				}
				case SPI_Speed_FCPU_16:
				{
					SPI1->SPSR_.Bits.Bit0 = PIN_Reset;
					SPI1->SPCR_.Bits.Bit0 = PIN_Set;
					SPI1->SPCR_.Bits.Bit1 = PIN_Reset;
					break;
				}
				case SPI_Speed_FCPU_32:
				{
					SPI1->SPSR_.Bits.Bit0 = PIN_Set;
					SPI1->SPCR_.Bits.Bit0 = PIN_Set;
					SPI1->SPCR_.Bits.Bit1 = PIN_Reset;
					break;
				}
				case SPI_Speed_FCPU_64:
				{
					SPI1->SPSR_.Bits.Bit0 = PIN_Set;
					SPI1->SPCR_.Bits.Bit0 = PIN_Reset;
					SPI1->SPCR_.Bits.Bit1 = PIN_Set;
					break;
				}
				case SPI_Speed_FCPU_128:
				{
					SPI1->SPSR_.Bits.Bit0 = PIN_Reset;
					SPI1->SPCR_.Bits.Bit0 = PIN_Set;
					SPI1->SPCR_.Bits.Bit1 = PIN_Set;
					break;
				}
			}
			break;
		}
		case SPI_Mode_Slave:
		{
			SPI1->SPCR_.Bits.Bit6   = PIN_Set;    //Enabling SPI
			SPI1->SPCR_.Bits.Bit4   = PIN_Reset;  //Configuring it as slave	
			PIN_Config->GPIO_Pin_Mode   = GPIO_Pin_Mode_INput_No_PULL_UP; //Configuring SS as Input
			PIN_Config->GPIO_Pin_Number = GPIO_PINS_PIN4;
			MCAL_GPIO_Init(GPIOB,PIN_Config);
			//Configuring MISO pin as output
			PIN_Config->GPIO_Pin_Mode   = GPIO_Pin_Mode_Output;
			PIN_Config->GPIO_Pin_Number = GPIO_PINS_PIN6;
			MCAL_GPIO_Init(GPIOB,PIN_Config);
			//Configuring MOSI as Input
			PIN_Config->GPIO_Pin_Mode   = GPIO_Pin_Mode_INput_No_PULL_UP; 
			PIN_Config->GPIO_Pin_Number = GPIO_PINS_PIN5;
			MCAL_GPIO_Init(GPIOB,PIN_Config);
			//Configuring SCK as Input
			PIN_Config->GPIO_Pin_Mode   = GPIO_Pin_Mode_INput_No_PULL_UP;
			PIN_Config->GPIO_Pin_Number = GPIO_PINS_PIN7;
			MCAL_GPIO_Init(GPIOB,PIN_Config);
			break;
		}
	}
	switch(SPI_Config->SPI_Interrupt)
	{
		case SPI_Interrupt_Enable:
		{
			Enable_Interrupt();
			SPI1->SPCR_.Bits.Bit7 = PIN_Set;
			 GP_CallBack = SPI_Config->P_IRQ_CallBack ;
			break;
		}
		case SPI_Interrupt_Disable:
		{
			Disable_Interrupt();
			SPI1->SPCR_.Bits.Bit7 = PIN_Reset;
			break;
		} 
	}
	
	SPI1->SPCR_.Bits.Bit6   = PIN_Set; //Enabling SPI
}
/*=======================================================
* @Fn				-MCAL_SPI_Deinit
* @brief			-DeInitializes SPI
* @retval			-None
* Note
*/
void MCAL_SPI_Deinit(void)
{
	SPI1->SPCR_.SPRCR_= 0x00;
	SPI1->SPSR_.SPSR_ = 0x00;
}
/*=======================================================
* @Fn				-MCAL_SPI_SendData
* @brief			-Sends Data through SPI
* @param [in]		-Data which you want to send through SPI
* @retval			-None
* Note
*/
uint8_t MCAL_SPI_SendData(uint8_t TxBuffer)
{	
	SPI1->SPDR_ = TxBuffer;
	while(!(SPI1->SPSR_.Bits.Bit7));
	return SPI1->SPDR_;
}
/*=======================================================
* @Fn				-MCAL_SPI_ReceiveData
* @brief			-Receive Data through SPI
* @retval			-Data recived
* Note
*/
uint8_t MCAL_SPI_receiveData(uint8_t Data)
{
	uint8_t RxBuffer;
	SPI1->SPDR_=Data;
	while(!(SPI1->SPSR_.Bits.Bit7));
	RxBuffer = SPI1->SPDR_;	
	return RxBuffer;
}

ISR(SPI_STC_vect)
{
	GP_CallBack();
}