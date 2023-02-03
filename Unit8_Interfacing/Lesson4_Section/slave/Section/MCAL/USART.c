/*
 * USART.c
 *
 * Created: 1/28/2023 4:26:06 PM
 *  Author: Fam Ayman
 */ 
/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */
#include "USART.h"
#include "GPIO.h"
#include "avr/interrupt.h"
/*
 * ========================================================
 * 				Generic Variables
 * ========================================================
 */
S_USART_t * UART1 = (S_USART_t*)(UART_Base);
void (*GP_CallBack)(void);
/* ================================================================ */
/* =========================APIs=================================== */
/* ================================================================ */

/*=======================================================
* @Fn				-MCAL_UART_Init
* @brief			-Initializes UART
* @param [in]		-UART_Instance
* @param [in]		-UART_Config
* @retval			-None
* Note
*/


void MCAL_UART_Init(S_UART_Config_t * UART_Config)
{
	UART1->UBRRL_=UART_Config->USART_BaudRate; //See page 141 in data sheet
	switch(UART_Config->USART_Type)
	{
		case USART_Type_Asynchronous :
		{
			//it will work in normal speed by default and there is no option to change it
			switch(UART_Config->USART_Mode)  //configure registers to determine if it is RX or TX or Both
			{
				case UART_Mode_Tx :
				{
					UART1->UCSRB_.Bits.Bit3 = PIN_Set;
					break;
				}
				case UART_Mode_Rx :
				{
					
					UART1->UCSRB_.Bits.Bit4 = PIN_Set;
					break;
				}
				case UART_Mode_RX_TX :
				{
					UART1->UCSRB_.Bits.Bit3  = PIN_Set;
					UART1->UCSRB_.Bits.Bit4 = PIN_Set;
					break;
				}
				
			}
			switch(UART_Config->Pay_Load_Length)
			{
				case UART_Payload_Length_5bits:
				{
					//For 5 bits
					UCSRC_ &= ~(1<<UCSZ0);
					UCSRC_ &= ~(1<<UCSZ1);
					break;
				}
				case UART_Payload_Length_6bits:
				{
					//For 6 bits
					UCSRC_ |= (1<<UCSZ0);
					UCSRC_ &= ~(1<<UCSZ1);
					break;
				}
				case UART_Payload_Length_7bits:
				{
					//For 7 bits
					UCSRC_ &= ~(1<<UCSZ0);
					UCSRC_ |= (1<<UCSZ1);
					break;
				}
				case UART_Payload_Length_8bits:
				{
					UCSRC_ |= (1<<UCSZ0);
					UCSRC_ |= (1<<UCSZ1);
					break;
				}
				case UART_Payload_Length_9bits:
				{
					UCSRC_ |= (1<<UCSZ0);
					UCSRC_ |= (1<<UCSZ1);
					UART1->UCSRB_.Bits.Bit2 = PIN_Set;
					break;
				}
			}
			switch(UART_Config->Stop_Bits)
			{
				case UART_Stop_Bits_one :
				{
					UCSRC_ &= ~(1<<USBS);  //For 1 stop bit
				}
				case UART_Stop_Bits_Two :
				{
					UCSRC_ |= (1<<USBS);	//For 2 Stop bits
				}
				
			}
			switch(UART_Config->Parity)
			{
				case UART_Parity_Disable :
				{
					UCSRC_ &= ~(1<<UPM0);
					UCSRC_ &= ~(1<<UPM1);
					break;
				}
				case UART_Parity_Even :
				{
					UCSRC_ &= ~(1<<UPM0);
					UCSRC_ |= (1<<UPM1);
					break;
				}
				case UART_Parity_ODD :
				{
					UCSRC_ |= (1<<UPM0);
					UCSRC_ |= (1<<UPM1);
					break;
				}
				
			}
			
			switch(UART_Config->UART_IRQ_Enable)
			{
				case UART_IRQ_Disable:
				{
					UART1->UCSRB_.Bits.Bit6 = PIN_Reset;
					UART1->UCSRB_.Bits.Bit6 = PIN_Reset;
					break;
				}
				case UART_IRQ_TxEnable:
				{
					Enable_Interrupt();
					UART1->UCSRB_.Bits.Bit6 = PIN_Set;
					UART1->UCSRB_.Bits.Bit7 = PIN_Reset;
					GP_CallBack = UART_Config->P_IRQ_CallBack ;
					break;
				}
				case UART_IRQ_RXEnable :
				{
					Enable_Interrupt();
					UART1->UCSRB_.Bits.Bit6 = PIN_Reset;
					UART1->UCSRB_.Bits.Bit7 = PIN_Set;
					GP_CallBack = UART_Config->P_IRQ_CallBack ;
					break;
				}
				case UART_IRQ_TX_RX_Enable:
				{
					Enable_Interrupt();
					UART1->UCSRB_.Bits.Bit6 = PIN_Reset;
					UART1->UCSRB_.Bits.Bit7 = PIN_Set;
					GP_CallBack = UART_Config->P_IRQ_CallBack ;
					break;
				}
			}
		}
	}
	
	
	
}
/*=======================================================
* @Fn				-MCAL_UART_DeInit
* @brief			-Deinitializes UART
* @retval			-None
* Note
*/
void MCAL_UART_Deinit(void)
{
	UART1->UBRRL_ = (uint8_t)0x00;
	UART1->UCSRA_.UCSRA_ = (uint8_t)0x10;
	UART1->UCSRB_.UCSRB_ = (uint8_t)0x00;
	UCSRC_ = (uint8_t)0x86; //Show initial values in data sheet
}
/*=======================================================
* @Fn				-MCAL_UART_SendData
* @brief			-Sends Data through  UART
* @param [in]		-Tx Buffer in which you store the data you want to transmit
* @retval			-None
* Note
*/
void MCAL_UART_SendData(uint8_t TxBuffer ,enum Polling Poll_Status )
{
	if(Poll_Status)
	{
		while (!(UART1->UCSRA_.Bits.Bit5));
	}
	if(UART1->UCSRB_.Bits.Bit2)
	{
		UART1->UCSRB_.Bits.Bit0 = ((TxBuffer & (1<<8))>>8);
	}
	UART1->UDR_ = ((uint8_t)TxBuffer);
}
/*=======================================================
* @Fn				-MCAL_UART_SendString
* @brief			-Sends String through  UART
* @param [in]		-Tx Buffer in which you store the data you want to transmit
* @retval			-None
* Note
*/
void MCAL_UART_SendString(uint8_t *pTxBuffer)
{
	while (*pTxBuffer != '\0')
	{
		while (!(UART1->UCSRA_.Bits.Bit5));
		if(UART1->UCSRB_.Bits.Bit2)
		{
			UART1->UCSRB_.Bits.Bit0 = ((*pTxBuffer & (1<<8))>>8);
			UART1->UDR_ = (uint8_t)(*pTxBuffer);
			pTxBuffer++;
		}
		else
		{
			UART1->UDR_ = (uint8_t)(*pTxBuffer);
			pTxBuffer++;
		}
		
		
	}
	
	while (!(UART1->UCSRA_.Bits.Bit5));
	UART1->UDR_= '\0';
	
}
/*=======================================================
* @Fn				-MCAL_UART_receiveData
* @brief			-receive Byte through  UART
* @param [in]		-Poll state if its blocking or non blocking
* @retval			-received Byte
* Note
*/
uint16_t MCAL_UART_receiveData(enum Polling Poll_Status )
{
	uint16_t RxBuffer;  //16 for receiving more than 8 bit
	if(Poll_Status)
	{
		while (!(UART1->UCSRA_.Bits.Bit7));
	}
	if(UART1->UCSRB_.Bits.Bit2)
	{
		RxBuffer |= ((UART1->UCSRB_.Bits.Bit1)<<8);
		RxBuffer = (uint8_t)(UART1->UDR_);
	}
	else
	{
		RxBuffer = (UART1->UDR_);
	}
	return RxBuffer;
}
/*=======================================================
* @Fn				-MCAL_UART_ReceiveString
* @brief			-receive string through  UART
* @param [in]		-Buffer in which data stored
* @retval			-received Byte
* Note
*/
void MCAL_UART_ReceiveString(uint8_t *pRxBuffer)
{
	while(*pRxBuffer != '\0')
	{
		while (!(UART1->UCSRA_.Bits.Bit7));
		(*pRxBuffer) = UART1->UDR_;
		pRxBuffer++;
	}
	*pRxBuffer ='\0';
}
ISR(USART_RXC_vect)
{
	GP_CallBack();
}

ISR(USART_TXC_vect)
{
	GP_CallBack();
}