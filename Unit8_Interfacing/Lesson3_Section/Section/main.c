/*
 * Section.c
 *
 * Created: 1/28/2023 3:19:08 PM
 * Author : Fam Ayman
 */ 

#include <avr/io.h>
#include "Atmega32_Device_Header.h"
#include "USART.h"
#include "GPIO.h"
#include "Utilis.h"
#include "LCD.h"
#include "avr/delay.h"
int j=0;
void GP_CallBack_UART(void)
{
	LCD_Goto_XY(2,j);
	LCD_Send_A_Character((uint8_t)(MCAL_UART_receiveData(UART_Enable)));
	_delay_ms(1000);
	j++;
}
void USART(void)
{
	S_UART_Config_t  UART;
	UART.USART_BaudRate = 51; //For 9600 baudrate
	UART.Pay_Load_Length = UART_Payload_Length_8bits;
	UART.USART_Mode = UART_Mode_RX_TX;
	UART.USART_Type = USART_Type_Asynchronous;
	UART.Parity = UART_Parity_Disable;
	UART.UART_IRQ_Enable = UART_IRQ_RXEnable;
	UART.P_IRQ_CallBack = GP_CallBack_UART;
	MCAL_UART_Init(&UART);
}
char number [10]={ '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,'8' , '9' } ;
int main(void)
{
	int i =0;
	USART();
	LCD_Init() ;
	LCD_Clear_Screen();
    _delay_ms(500);
	char number [10]={ '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,'8' , '9' } ;
	while(1)
	{
		LCD_Goto_XY(1,0);
		LCD_Send_A_Character( number [i] ) ;
		i++ ;
		if(i==10)
		{
			i=0;
			LCD_Clear_Screen();
		}
		_delay_ms(1500) ;
	}
}
