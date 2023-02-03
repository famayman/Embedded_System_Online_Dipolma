/*
 * Section.c
 *
 * Author : Fam Ayman
 */ 

#include <avr/io.h>
#include "Atmega32_Device_Header.h"
#include "SPI.h"
#include "avr/delay.h"
#include "GPIO.h"
#define F_CPU	10000000UL
void SPI_Config(void)
{
	S_SPI_Config_t *SPI_Con;
	SPI_Con->SPI_Mode =SPI_Mode_Master;
	SPI_Con->SPI_Interrupt=SPI_Interrupt_Enable;
	SPI_Con->SPI_Data_Order=SPI_Order_MSB;
	SPI_Con->SPI_Speed = SPI_Speed_FCPU_128;
	MCAL_SPI_Init(SPI_Con);
}
void Execution(uint8_t address,uint8_t data)
{
	MCAL_GPIO_WritePin(GPIOB,GPIO_PINS_PIN4,PIN_Reset);
	MCAL_SPI_SendData(address);
	MCAL_SPI_SendData(data);
	MCAL_GPIO_WritePin(GPIOB,GPIO_PINS_PIN4,PIN_Set);
}
int main(void)
{
	unsigned char index_display,counter=0;
	DDRA=0xFF; //for simplicity 
	SPI_Config();
	MCAL_GPIO_WritePin(GPIOB,GPIO_PINS_PIN4,PIN_Set);//Setting SS
	Execution(0x09,0xFF);
	Execution(0x0A,0xFF);
	Execution(0x0B,0x07);
	Execution(0x0C,0x01);
 while (1)
 {
	 for (index_display = 1; index_display < 9; index_display++)
	{
	 Execution(index_display, counter++);
	 _delay_ms(500);
	 }
 }
}
