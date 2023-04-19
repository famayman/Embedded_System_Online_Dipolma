/*
 * I2C_Slave_EEPROM.c
 *
 *  Created on: Apr 19, 2023
 *      Author: Fam Ayman
 */
#include "I2C_Slave_EEPROM.h"
void EEPROM_Init(void)
{
	//==================================I2C_INIT=============================//
	//			PB6 : I2C1_SCL
	//			PB7 : I2C1_SDA

	S_I2C_Config_t I2C1CFG ;

	I2C1CFG.General_Call_Address_Detection =I2C_ENGC_Enable;
	I2C1CFG.I2C_Ack_Conrtol = I2C_Ack_Control_Enable;
	I2C1CFG.I2C_Speed = I2C_SCK_SM_100K;
	I2C1CFG.I2C_Mode = I2C_Mode_I2C;
	I2C1CFG.P_Slave_Event_CallBack = NULL;
	I2C1CFG.I2C_stretchmode = I2C_StretchMode_enabled;
	MCAL_I2C_Set_GPIO(I2C1);
	MCAL_I2C_Init(I2C1,&I2C1CFG);
}
unsigned char EEPROM_Write_NBytes(unsigned int Memory_address,unsigned char* bytes ,uint8_t Data_Length)
{
	uint8_t i;
	uint8_t buffer[256];
	buffer[0] = (uint8_t)(Memory_address>>8);
	buffer[1] = (uint8_t)Memory_address;

	for(i=2;i<(Data_Length+2);i++)
	{
		buffer[i] = bytes[i-2];
	}
	MCAL_I2C_Master_Tx(I2C1,EEPROM_Slave_address,buffer,Data_Length+2,WithStop,Start);

	return 0 ;
}
unsigned char EEPROM_Read_byte(unsigned int address ,uint8_t *dataout,uint8_t datalen)
{
	unsigned char buffer[2];
	buffer[0] = (uint8_t)(address>>8);
	buffer[1] = (uint8_t)address;
	MCAL_I2C_Master_Tx(I2C1,EEPROM_Slave_address, buffer,2,WithoutStop, Start);
	MCAL_I2C_Master_Rx(I2C1,EEPROM_Slave_address,dataout,datalen,WithStop,Repeated);
	return 0;
}

