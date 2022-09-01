/*
 * UART_Driver.c
 *
 * Created: 8/29/2022 2:23:16 AM
 * Author : Fam Ayman
 */ 

#include <avr/io.h>
#include "LCD.h"
#include "UART.h"

int main(void)
{
	
	LCD_Init();
	Uart_Init();
	LCD_Goto_XY(0,0);
	Uart_Send('F');
	Uart_Send('a');
	Uart_Send('m');
	uart_send_string(" Ayman#");

	LCD_Goto_XY(1,0);
    while (1) 
    {
		
		LCD_Send_A_Character(Uart_Receive());
    }
}

