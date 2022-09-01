/*
 * UART.h
 *
 * Created: 8/29/2022 2:25:59 AM
 *  Author: Fam Ayman
 */ 


#ifndef UART_H_
#define UART_H_
#include "avr/io.h"
#include "Utils.h"
void Uart_Init(void);
void Uart_Send(unsigned char data);
unsigned char Uart_Receive(void);
void uart_send_string(unsigned char *Data);
uint8_t uart_recieve_string(void);
void uart_send_int(uint32_t Data);
uint32_t uart_recieve_int(void);
#endif /* UART_H_ */