/*
 * I2C_Slave_EEPROM.h
 *
 *  Created on: Apr 19, 2023
 *      Author: Fam Ayman
 */

#ifndef INC_I2C_SLAVE_EEPROM_H_
#define INC_I2C_SLAVE_EEPROM_H_
#include "STM32F103C6_I2C_Driver.h"
//E2PROM is Slave
#define EEPROM_Slave_address 0x2A
void EEPROM_Init(void);
unsigned char EEPROM_Write_NBytes(unsigned int Memory_address,unsigned char* bytes ,uint8_t Data_Length);
unsigned char EEPROM_Read_byte(unsigned int address ,uint8_t *dataout,uint8_t datalen);
#endif /* INC_I2C_SLAVE_EEPROM_H_ */
