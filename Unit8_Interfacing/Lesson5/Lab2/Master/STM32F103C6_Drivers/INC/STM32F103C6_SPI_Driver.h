/*
 * STM32F103C6_SPI_Driver.h
 *
 *      Author: Fam Ayman
 */

#ifndef INC_STM32F103C6_SPI_DRIVER_H_
#define INC_STM32F103C6_SPI_DRIVER_H_
/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */
#include "STM32F103C6_GPIO_Driver.h"
#include "sTM32F103x8.h"
/* ================================================================ */
/* ===================== Structure and enum  ====================== */
/* ================================================================ */
/*We will do struct to know the source of interrupt and making it equal to one */
struct S_IRQ_SRC
{
	uint8_t TXE:1;		//TX buffer is empty
	uint8_t	RXE:1;		//Rx buffer is empty
	uint8_t	ERRI:1;		//Error interrupt
	uint8_t Reserved:5;
};
/* ================================================================ */
/* =========================== Spaces  =============== ============ */
/* ================================================================ */
typedef struct
{
	uint16_t		Device_Mode;    		//Specifies if SPI operating as master mode or slave mode
								   	   	    //This parameter must be set based on @ref Device_Mode_Define
	uint16_t 		Communication_Mode; 	//Specifies Communication mode  if bidirectional or unidirectional
											//This parameter must be set based on @ref Communication_Mode_Define
	uint16_t 		Pay_Load_Length;		//Specifies Pay_Load_Length of SPI 16 or 32 bits
											//This parameter must be set based on @ref SPI_Pay_Load_Length_Define
	uint16_t		Frame_Format;			//Specifies Sending MSB or LSB First
											//This parameter must be set based on @ref SPI_Fram_Format
	uint16_t		CLock_Polarity;			//Specifies Clock_Polarity idle low or high
											//This parameter must be set based on @ref SPI_Clock_Polarity_Define
	uint16_t 		CLock_Phase;			//Specifies Clock_Phase sampling on leading or Trailing edge
											//This parameter must be set based on @ref SPI_Clock_Phase_Define
	uint16_t		NSS;					//Specifies NSS if mananged bey hardware or software
											//This parameter must be set based on @ref SPI_NSS_Define
	uint16_t		SPI_Prescaler;			//Specifies frequency of SPI
											//This parameter must be set based on @ref  SPI_Prescaler_Define
											//Note the SPI1 will use APB2 and SPI2 APB1
	uint16_t		IRQ_Enable;				//Enables or disables interrupt of SPI
											//This parameter must be set based on @ref SPI_IRQ_Enable_Define

	void(*P_IRQ_CallBack)(struct S_IRQ_SRC IRQ);			//Call_Back_Function
}S_SPI_Config_t;
/* ================================================================ */
/* =========================== Spaces  ============================ */
/* ================================================================ */
enum SPI_PollingMechanism
{
	Enabled,
	Disabled
};
/* ================================================================ */
/* =========================== Ref Macros  ======================== */
/* ================================================================ */
//@ref SPI_Mode_Define
#define SPI_Mode_Master								(0x1<<2)  //to set bit 2 in CR1;
#define SPI_Mode_Slave								(0x00000000U)//Reset bit
//@ref SPI_Communication_Mode_Define
#define SPI_Direction_2lines						(0x00000000U) //Setting zero at bit 15 in CR1 becuz its by default RX_TX
#define SPI_Direction_2lines_RX_Only				(0x1<<10)//Setting one at bit 10 in CR1 to limit Comm as RX only
#define SPI_Direction_1lines_Receive_only			(0x1<<15)//Setting one at bit 15 to let it 1line and its by default RX only
#define SPI_Direction_1lines_Transmit_only			((0x1<<15)|(0x1<<14))//Setting on at bit 15 for 1line and at 14 for Tx only
//@ref SPI_Pay_Load_Length
#define SPI_Pay_Load_Length_8bit					(0x00000000U)//By default 8 bit
#define SPI_Pay_Load_Length_16bit					(0x1<<11)//setting one at bit 11 at CR1 to increase Pay_Load to 16 bit
//@ref  SPI_Frame_Format_Define
#define SPI_Frame_Format_MSB						(0x00000000U)//By default MSB
#define SPI_Frame_Format_LSB						(0x1<<7)//Setting one at bit 7 in CR1 to transmit LSB first
//@ref SPI_Clock_Polarity_Define
#define SPI_Clock_Polarity_Low_idel					(0x00000000U)//By default its is low
#define SPI_Clock_Polarity_High_idel				(0x1<<1)//Setting bit number 1 in CR1 to make it high as idel
//@ref SPI_Clock_Phase_Define
#define SPI_Clock_Phase_Leading						(0x00000000U)//By default its in leading Edge
#define SPI_Clock_Phase_Trailing					(0x1)//Setting bit number 0 in CR1 to Sample in trailing or second Edge
//@ref SPI_NSS_Define
/* ================================================================ */
/* =========================== How NSS Works  ====================== */
/* ================================================================ */
/*1-Hardware Slave so Master can control this bit
 *2-Hardware Master OutPut 1: SS output is enabled in master mode and when the cell is enabled. The cell cannot work
 * in a multimaster environment.
 * 3-Hardware Master OutPut_Disabled :0: SS output is disabled in master mode and the cell can work in multimaster configuration
 * 4-Software Master 1: Software slave management enabled and its value will equal to SSI
 * 5-Software Slave Not recommended because i want master to control its slave
 */
//Hardware
#define SPI_NSS_Hard_Slave							(0x00000000U)//By default its hardware slave
#define SPI_NSS_Hard_Master_SS_Output_Enable		(0x1<<2)//Setting Bit number 2 in CR2 so its master hard
#define SPI_NSS_Hard_Master_SS_No_output			(uint16_t) ~(1<<2)//Reseting bit number 2 in CR2
//Software
#define SPI_NSS_Internal_Soft_Reset					(0x1<<9)//Enabling Soft in bit 9 CR1 and its by default reseted
#define SPI_NSS_Internal_Soft_Set					((0x1<<9)|(0x1<<8))//Enabling soft and set it
//@ref SPI_Prescaler_Define
#define SPI_Prescaler_By4							 (0b001<<3)
#define SPI_Prescaler_By8							 (0b010<<3)
#define SPI_Prescaler_by16							 (0b011<<3)
#define SPI_Prescaler_by32							 (0b100<<3)
#define SPI_Prescaler_by64							 (0b101<<3)
#define SPI_Prescaler_by128							 (0b110<<3)
#define SPI_Prescaler_by256							 (0b111<<3)
//@ref SPI_IRQ_Enable_Define
#define SPI_IRQ_Enable_Non							 (uint32_t)(0)
#define SPI_IRQ_Enable_Tx_Only						 (uint32_t)(1<<7)
#define SPI_IRQ_Enable_Rx_only						 (uint32_t)(1<<6)
#define SPI_IRQ_Enable_Err							 (uint32_t)(1<<5)




 /*
 * =======================================================
 *              APIS_Supported_By "MCAL SPI Driver"
 * =======================================================
 *
 */

/* Initialization/def-initialization Functions********/
void MCAL_SPI_Init(S_SPI_t * SPIx , S_SPI_Config_t * Config);
void MCAL_SPI_DeInit(S_SPI_t * SPIx);
void MCAL_SPI_GPIO_Set_Pins(S_SPI_t * SPIx);
void MCAL_SPI_SendData(S_SPI_t * SPIX , uint16_t * pTXBuffer , enum SPI_PollingMechanism Polling_En);
void MCAL_SPI_ReceiveData(S_SPI_t * SPIX,uint16_t * pRXBuffer , enum SPI_PollingMechanism Polling_En);
void MCAL_SPI_Tx_Rx(S_SPI_t * SPIX ,uint16_t * TX_RX_pBuffer , enum SPI_PollingMechanism Polling_En);









#endif /* INC_STM32F103C6_USART_DRIVER_H_ */

