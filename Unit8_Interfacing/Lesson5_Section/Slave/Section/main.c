/*
 * Master_Unit8.c
 *
 * Created: 2/3/2023 1:01:17 AM
 * Author : Fam Ayman
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include "SPI.h"
#include "LCD.h"
#include "GPIO.h"
#define MCU_Act_As_Slave
uint8_t Send_Master(uint8_t  data)
{
	uint8_t received;
	MCAL_GPIO_WritePin(GPIOB,GPIO_PINS_PIN4,PIN_Reset);
	_delay_ms(200);
	MCAL_SPI_SendData(data);
	received=MCAL_SPI_receiveData();
	return received;
}
void SPI_INT(void)
{
	S_SPI_Config_t * SPI_Config;
	#ifdef MCU_Act_As_Master
	SPI_Config->SPI_Mode = SPI_Mode_Master;
	SPI_Config->SPI_Data_Order= SPI_Order_MSB;
	SPI_Config->SPI_Interrupt=SPI_Interrupt_Disable;
	SPI_Config->SPI_Speed=SPI_Speed_FCPU_8;
	SPI_Config->SPI_Clock_Phase=SPI_Clock_Phase_First_Edge;
	SPI_Config->SPI_Clock_Polarity=SPI_Clock_Polarity_High;
	#endif
	#ifdef MCU_Act_As_Slave
		SPI_Config->SPI_Mode = SPI_Mode_Slave;
     	SPI_Config->SPI_Interrupt=SPI_Interrupt_Disable;
    #endif
	MCAL_SPI_Init(SPI_Config);
	
}
int main(void)
{
	unsigned char x='0', Data = 'A',received;
	SPI_INT();
	LCD_Init();
	LCD_Clear_Screen();
	LCD_Goto_XY(1,0);
	#ifdef MCU_Act_As_Master
		LCD_Send_A_String("Master");
    #endif
	#ifdef MCU_Act_As_Slave
		LCD_Send_A_String("Slave");
	#endif
    while (1) 
    {
		LCD_Goto_XY(1,9);
		LCD_Send_A_Character(x);
		MCAL_SPI_SendData(Data);
		received=MCAL_SPI_receiveData();
		Data++;
		if(Data == ('Z'+1))
		Data = 'A';	
		x++;
		LCD_Goto_XY(2,1);
		LCD_Send_A_Character(received);
		if(x == '9')
		x='0';
    }
}

