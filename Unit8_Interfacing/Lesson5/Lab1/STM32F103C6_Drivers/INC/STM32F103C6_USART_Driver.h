/*
 * STM32F103C6_USART_Driver.h
 *
 *  Created on: Aug 10, 2022
 *      Author: Fam Ayman
 */

#ifndef INC_STM32F103C6_USART_DRIVER_H_
#define INC_STM32F103C6_USART_DRIVER_H_
#include "STM32F103C6_GPIO_Driver.h"
#include "sTM32F103x8.h"
#include "STM32F103C6_RCC_Driver.h"
//Configuration Struct
typedef struct
{
	uint8_t			USART_Mode;    			//Specifies RX TX Enable /Disable
								   	   	    //This parameter must be set based on @ref UART_Mode_Define
	uint32_t 		USART_BaudRate; 		//Specifies UART_BaudRate
											//This parameter must be set based on @ref UART_BaudRate_Define
	uint8_t 		Pay_Load_Length;		//Specifies Pay_Load_Length of UART
											//This parameter must be set based on @ref UART_Pay_Load_Length_Define
	uint8_t			Parity;					//Specifies Parity
											//This parameter must be set based on @ref UART_Parity_Define
	uint8_t 		Stop_Bits;				//Specifies Number of stop bits
											//This parameter must be set based on @ref UART_Stop_Bits_Define
	uint8_t 		HwFlowCTRL;				//Specifies if flow control is enabled or not
											//This parameter must be set based on @ref UART_HwFlowCTRL_Define
	uint8_t			IRQ_Enable;				//Specifies if RX or Tx interrupt is Enable
											//This parameter must be set based on @ref UART_IRQ_Enable
	void(*P_IRQ_CallBack)(void);			//Call_Back_Function
}S_UART_Config_t;
//---------------------------------------------------------
//=======================ref_Macros========================
//---------------------------------------------------------
//@ref UART_Mode_Define
#define UART_Mode_Rx					(uint32_t)(1<<2) //Receiver Enable
#define UART_Mode_TX					(uint32_t)(1<<3) //Transmit Enable
#define UART_Mode_RX_TX					((uint32_t)(1<<2 | 1<<3)) //Transmit & Receiver Enable

//@ref UART_BaudRate_Define
#define UART_BaudRate_2400				2400
#define UART_BaudRate_9600				9600
#define UART_BaudRate_19200				19200
#define UART_BaudRate_57600				57600
#define UART_BaudRate_115200			115200
#define UART_BaudRate_230400			230400
#define UART_BaudRate_460800			460800
#define UART_BaudRate_921600			921600
#define UART_BaudRate_2250000			2250000
#define UART_BaudRate_4500000			4500000
//@ref UART_Pay_Load_Length_Define
#define UART_Pay_Load_Length_8bit		(uint32_t)(0)
#define UART_Pay_Load_Length_9bit		(uint32_t)(1<<12)
//@ref UART_Parity_Define
#define UART_Parity_NONE				(uint32_t)(0)
#define UART_Parity_EVEN				(uint32_t)(1<<10)
#define UART_Parity_ODD					(uint32_t)(1<<10 | (1<<9))
//@ref UART_Stop_Bits_Define
//00: 1 Stop bit
//01: 0.5 Stop bit
//10: 2 Stop bits
//11: 1.5 Stop bit
#define UART_Stop_Bits_0_5Bit			(uint32_t)(1<<12)
#define UART_Stop_Bits_1Bit				(uint32_t)(0)
#define UART_Stop_Bits_1_5Bit			(uint32_t)(3<<12)
#define UART_Stop_Bits_2Bit				(uint32_t)(2<<12)


//@ref UART_HwFlowCTRL_Define



#define UART_HwFlowCTL_NONE				((uint32_t)(0))
#define UART_HwFlowCTL_RTS				((uint32_t)(1<<8))
#define UART_HwFlowCTL_CTS				((uint32_t)(1<<9))
#define UART_HwFlowCTL_RTS_CTS			((uint32_t)(1<<8 | 1<<9))



//@ref UART_IRQ_Enable_Define


#define UART_IRQ_Enalbe_NONE			(uint32_t)(0)
#define UART_IRQ_Enable_TXE				(uint32_t)(1<<7)
#define UART_IRQ_Enable_TC				(uint32_t)(1<<6)
#define UART_IRQ_Enable_RXNEIE			(uint32_t)(1<<5)
#define UART_IRQ_Enable_PE				(uint32_t)(1<<8)
enum polling_mechanism
{
	Enable ,
	Disable
};
//BaudRate Calculation
//USARTDIV = fclk/(16*Baudrate)
//USARTDIV_Mul100 =
//uint32(100*fclk)/(16*Baudrate)==(25*fclk)/(4*Baudrate))
//DIV_Mantissa_MUL100 = Integer Part(USARTDIV)*100
//DIV_Mantissa = Integer Part (USARTDIV)
//DIV_Fraction = ((USARTDIV_MUL100- DIV_Mantissa_Mull100) * 16)/100
#define USARTDIV(_PCLK_,_BAUD_)					(uint32_t)(_PCLK_/(16 * _BAUD_))
#define USARTDIV_MUL100(_PCLK_,_BAUD_)			(uint32_t)((25*_PCLK_)/(4 * _BAUD_))
#define Mantissa_MUL100(_PCLK_,_BAUD_)			(uint32_t)(USARTDIV(_PCLK_,_BAUD_)*100)
#define Mantissa(_PCLK_,_BAUD_)					(uint32_t)(USARTDIV(_PCLK_,_BAUD_))
#define DIV_Fraction(_PCLK_,_BAUD_)				(uint32_t)(((USARTDIV_MUL100(_PCLK_,_BAUD_))- Mantissa_MUL100(_PCLK_,_BAUD_))*16)/100
#define UART_BRR_Register(_PCLK_,_BAUD_)		((Mantissa(_PCLK_,_BAUD_) ) <<4)|((DIV_Fraction(_PCLK_,_BAUD_)) & 0xF)
/*
 *
 * =======================================================
 *              APIS_Supported_By "MCAL UART Driver"
 * =======================================================
 *
 */

/* Initialization/def-initialization Functions********/
void MCAL_UART_Init(S_Usart_t * USARTx , S_UART_Config_t * Config);
void MCAL_UART_DeInit(S_Usart_t * USARTx);
void MCAL_UART_GPIO_Set_Pins(S_Usart_t * USARTx);
void MCAL_UART_SendData(S_Usart_t * USARTX , uint16_t * pTXBuffer , enum polling_mechanism Polling_En);
void MCAL_UART_ReceiveData(S_Usart_t * USARTx,uint16_t * pRXBuffer , enum polling_mechanism Polling_En);
void MCAL_UART_WAIT_TC (S_Usart_t * USARTx);










#endif /* INC_STM32F103C6_USART_DRIVER_H_ */
