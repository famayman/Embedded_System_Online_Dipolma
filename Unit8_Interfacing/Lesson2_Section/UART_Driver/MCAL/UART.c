/*
 * UART.c
 *
 * Created: 8/29/2022 2:25:46 AM
 *  Author: Fam Ayman
 */ 
#include "UART.h"
void Uart_Init(void)
{
	UBRRL = 51; //for 9600 baudrate 
	Reset(UCSRA,U2X); //Normal mode
	set(UCSRB,TXEN);  //Enabling transmitting
	set(UCSRB,RXEN);  //Enabling Receiving
	//No parity
	//Transmitting 8 bit
	set(UCSRC,UCSZ0);
	set(UCSRC,UCSZ1);
	Reset(UCSRB,UCSZ2);
	
}
void Uart_Send(unsigned char data)
{
	while(!Read(UCSRA,UDRE));
	UDR = data;
}
unsigned char Uart_Receive(void)
{
	while(!Read(UCSRA,RXC));
	return UDR;
}
void uart_send_string(unsigned char  *Data)
{
	uint8_t *p = Data;
	while(*p != '#')
	{
		Uart_Send(*p);
		p++;
	}
}
uint8_t uart_recieve_string(void)
{
	uint8_t *p = (uint8_t) (UDR);
	while(*p != "#")
	{
		while(!Read(UCSRA,RXC));
		p++;
		return UDR;
	}
}
void uart_send_int(uint32_t Data)
{
	uint8_t *p = &Data;
	Uart_Send(p[0]);
	Uart_Send(p[1]);
	Uart_Send(p[2]);
	Uart_Send(p[3]);
}
uint32_t uart_recieve_int(void)
{
	uint32_t i ;
	uint8_t *p = (uint8_t)&i;
	p[0] = Uart_Receive();
	p[1] = Uart_Receive();
	p[2] = Uart_Receive();
	p[3] = Uart_Receive();
	return i;
}