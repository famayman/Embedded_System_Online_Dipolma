/*
 * SPI.h
 *
 *  Author: Fam Ayman
 */ 


#ifndef SPI_H_
#define SPI_H_
/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */
#include "Atmega32_Device_Header.h"
/*=================================================================*/
/*=========================== Configuration Struct ================*/
/*=================================================================*/
typedef struct
{
	uint8_t		SPI_Mode;			//Specifies if MicroController will act as slave or master
									//This parameter must be set based on @ref SPI_Mode_Define
	uint8_t		SPI_Interrupt;		//Enabling SPI interrupt or not 
									//This parameter must be set based on @ref SPI_Interrupt_Define
	uint8_t		SPI_Data_Order;		//Specifies Sending way by LSB or MSB
									//This parameter must be set based on @ref SPI_Order_Define
	uint8_t		SPI_Speed;			//Determining  speed of Clk that will SPI use
									//This parameter must be set based on @ref SPI_Speed_Define
	uint8_t	    SPI_Clock_Polarity;	//Specifies if SCK is low or high at idle
									//This parameter must be set based on @ref SPI_Clock_Polarity_Define
	uint8_t		SPI_Clock_Phase;	//Specifies if data is sampled in rising or failing edge
									//This parameter must be set based on @ref SPI_Clock_Phase_Define
    void(*P_IRQ_CallBack)(void);	//Call_Back_Function

	
	}S_SPI_Config_t;
/*=================================================================*/
/*=========================== reference Macros ====================*/
/*=================================================================*/

//@ref SPI_Mode_Define
#define SPI_Mode_Master					0
#define SPI_Mode_Slave					1
//@ref SPI_Interrupt_Define
#define SPI_Interrupt_Enable			0
#define SPI_Interrupt_Disable			1	
//@ref SPI_Order_Define
#define SPI_Order_MSB					0
#define SPI_Order_LSB					1
//@ref SPI_Speed_Define
#define SPI_Speed_FCPU_2				0
#define SPI_Speed_FCPU_4				1
#define SPI_Speed_FCPU_8				2
#define SPI_Speed_FCPU_16				3
#define SPI_Speed_FCPU_32				4
#define SPI_Speed_FCPU_64				5
#define SPI_Speed_FCPU_128				6
//@ref SPI_Clock_Polarity_Define
#define SPI_Clock_Polarity_High			0	
#define SPI_Clock_Polarity_Low			1
//@ref SPI_Clock_Phase_Define
#define SPI_Clock_Phase_First_Edge		0
#define SPI_Clock_Phase_Second_Edge		1
//================================================================//
//==========================APIS==================================//
//================================================================//
void MCAL_SPI_Init(S_SPI_Config_t * SPI_Config);
void MCAL_SPI_Deinit(void);
void MCAL_SPI_SendData(uint8_t TxBuffer);
uint8_t MCAL_SPI_receiveData();
uint8_t MCAL_SPI_Tx_Rx(uint8_t Data);
#endif /* SPI_H_ */