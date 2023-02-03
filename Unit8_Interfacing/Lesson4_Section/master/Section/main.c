/*
 * Section.c
 *
 * Author : Fam Ayman
 */ 

#include <avr/io.h>
#include "Atmega32_Device_Header.h"
#include "SPI.h"
#include "avr/delay.h"
#define F_CPU	10000000UL
void SPI_Config(void)
{
	S_SPI_Config_t *SPI_Con;
	SPI_Con->SPI_Mode =SPI_Mode_Master;
	SPI_Con->SPI_Interrupt=SPI_Interrupt_Enable;
	SPI_Con->SPI_Data_Order=SPI_Order_MSB;
	SPI_Con->SPI_Speed = SPI_Speed_FCPU_8;
	MCAL_SPI_Init(SPI_Con);
}
int main(void)
{
	DDRA=0xFF; //for simplicity 
	SPI_Config();
	int data=0;
	while(1)
	{
		for(data=0 ; data<=255 ; data++)
		{
			PORTA= MCAL_SPI_SendData(data);
			_delay_ms(1000);
		}
	}	
}
