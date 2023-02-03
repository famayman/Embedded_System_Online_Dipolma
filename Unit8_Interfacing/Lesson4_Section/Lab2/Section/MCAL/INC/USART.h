/*
 * USART.h
 *
 * Created: 1/28/2023 4:05:43 PM
 *  Author: Fam Ayman
 */ 


#ifndef USART_H_
#define USART_H_
/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */
#include "Atmega32_Device_Header.h"

/*=================================================================*/
/*=========================== Configuration Struct ================*/
/*=================================================================*/
typedef struct
{
	uint8_t			USART_Type;			//Specifies if USART is Synchronous or Asynchronous
										//This parameter must be set based on @ref USART_Type_Define
	uint8_t			USART_Mode;			//Specifies if USART is RX or TX or both
										//This parameter must be set based on @ref UART_Mode_Define
	uint32_t		USART_BaudRate;		//Specifies USART BaudRate
										//This parameter must be set based on @ref UART_BaudRate_Define
	uint8_t			Pay_Load_Length;    //Specifies USART Pay_Load_Length
										//This parameter must be set based on @ref UART_Pay_Load_Length
	uint8_t			Parity;				//Specifies Parity
										//This parameter must be set based on @ref UART_Parity_Define
	uint8_t			Stop_Bits;			//Specifies Number of Stop Bits
										//This parameter must be set based on @ref UART_Stop_Bits_Define
	uint8_t			UART_IRQ_Enable;	//Specifies whether to enable interrupts or not
										//This parameter must be set based on @ref UART_IRQ_Enable
	void(*P_IRQ_CallBack)(void);		//Call_Back_Function
	
}S_UART_Config_t;
/*=================================================================*/
/*=========================== reference Macros ====================*/
/*=================================================================*/


//@ref	UART_Mode_Define
#define UART_Mode_Tx		0    	//Enable Transmitting
#define UART_Mode_Rx		1		//Enable Receiving
#define UART_Mode_RX_TX		2		//Enable Both

//@ref UART_BaudRate_Define
#define UART_BaudRate_2400				2400
#define UART_BaudRate_4800				4800
#define UART_BaudRate_9600				9600
#define UART_BaudRate_14400				14400
#define UART_BaudRate_19200				19200
#define UART_BaudRate_28800				28800
#define UART_BaudRate_38400				38400
#define UART_BaudRate_57600				57600
#define UART_BaudRate_115200			115200
#define UART_BaudRate_230400			230400
#define UART_BaudRate_250000			250000

//@ref UART_Payload_Length

#define UART_Payload_Length_5bits		0
#define UART_Payload_Length_6bits		1
#define UART_Payload_Length_7bits		2
#define UART_Payload_Length_8bits		3
#define UART_Payload_Length_9bits		4

//@ref UART_Parity

#define UART_Parity_Disable		0
#define UART_Parity_Even		1
#define UART_Parity_ODD			2

//@ref UART_Stop_Bits

#define UART_Stop_Bits_one		1
#define UART_Stop_Bits_Two		2

//@ref UART_IRQ_Enable

#define UART_IRQ_Disable			0
#define	UART_IRQ_TxEnable			1
#define UART_IRQ_RXEnable			2
#define UART_IRQ_TX_RX_Enable		3
//@ref USART_Type_Define
#define USAT_Type_Synchronous		0
#define USART_Type_Asynchronous		1

//UART mechanism
enum Polling
{
	UART_Disable,
	UART_Enable
	
};
//================================================================//
//==========================APIS==================================//
//================================================================//

void MCAL_UART_Init(S_UART_Config_t * UART_Config);
void MCAL_UART_Deinit(void);
void MCAL_UART_SendData(uint8_t TxBuffer ,enum Polling Poll_Status );
void MCAL_UART_SendString(uint8_t *pTxBuffer);
uint16_t MCAL_UART_receiveData(enum Polling Poll_Status );
void MCAL_UART_ReceiveString(uint8_t *pRxBuffer);
void MCAL_UART_SendString(uint8_t *pTxBuffer);
void MCAL_UART_ReceiveString(uint8_t *pRxBuffer);

#endif /* USART_H_ */