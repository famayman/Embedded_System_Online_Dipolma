/*
 * STM32F103C6_I2C_Driver.h
 *
 *  Created on: Feb 10, 2023
 *      Author: Fam Ayman
 */

#ifndef INC_STM32F103C6_I2C_DRIVER_H_
#define INC_STM32F103C6_I2C_DRIVER_H_
/*==================================================================*/
/*=============================Includes=============================*/
/*==================================================================*/
#include  "STM32F103C6_GPIO_Driver.h"
/*==================================================================*/
/*==========================Config_Struct===========================*/
/*==================================================================*/
struct S_I2C_Slave_address
{
	uint16_t Enable_Dual_Address;
	uint16_t PrimaryAddress;
	uint16_t SecondaryAddress;
	uint16_t I2C_Addressing_Mode;
};
typedef enum
{
	I2C_EV_Stop,
	I2C_Error_AF,
	I2C_Ev_Address_Matched,
	I2C_Ev_Data_Req,//this app should send data (Slave_Send_Data)
	I2C_Ev_Data_RCV //this app should Read Data (Slave_Read_Data)
}Slave_State;
typedef struct
{
	uint32_t		I2C_Speed;							//Specifies frequency of I2c
														//This parameter must be set based on @ref I2C_Speed_Define
	uint32_t		I2C_stretchmode;					//Specifies if Clock_Stretching is enabled or not
														//This parameter must be set based on @ref I2C_StretchMode_Define
	uint32_t		I2C_Mode;							//Specifies if I2C_Mode is I2C or SMBus
														//This parameter must be set based on @ref I2C_Mode_Define
	struct S_I2C_Slave_address I2C_Slave_address;		//This specifies if the slave has 2 address or on and its address is 7 or 10 bit
														//This parameter must be partially set on @ref Slave_address_Define
	uint32_t 		I2C_Ack_Conrtol;					//This specifies Ack is enabled or not
														//This parameter must be set based on @ref I2C_Ack_Control
	uint32_t		General_Call_Address_Detection;		//@ref I2C_ENGC
	void(*P_Slave_Event_CallBack)(Slave_State state);		//Call back function
}S_I2C_Config_t;


typedef enum
{
	WithStop,
	WithoutStop
}StopCondition;

typedef enum
{
	Start,
	Repeated
}Repeated_Start;
typedef enum
{
	DISABLE,
	ENABLE
}Functional_State;
typedef enum
{
	Reset,
	Set
}FlagStatus;
typedef enum
{
	I2C_Flag_Busy,
	EV5,//SB=1, cleared by reading SR1 register followed by writing DR register with Address
	EV6,//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
	EV7,//EV7: RxNE=1 cleared by reading DR register.
	EV8,//EV8: TxE=1, shift register not empty, data register empty, cleared by writing DR register .
	EV8_1,//EV8_1: TxE=1, shift register empty, data register empty, write Data1 in DR.
	Master_Byte_Transmitting =(uint32_t)(0x00070080) /*TRA MSL TXE*/
}Status;
typedef enum
{
	I2C_Direction_Transmitter,
	I2C_Direction_Receiver
}I2C_Direction;
#define I2C_Transmitter		(uint32_t)(0x00070080)
/*==================================================================*/
/*=============================ref_Macros===========================*/
/*==================================================================*/
/*@ref I2C_Speed_Define
//– Standard Speed (up to 100 kHz)
//– Fast Speed (up to 400 kHz)
//To configure Clock
//Program the peripheral input clock in I2C_CR2 register in order to generate correct timing before  Enabling the model
 *  Bits 5:0 FREQ[5:0]: Peripheral clock frequency
 *  Configure the clock control registers
 *  	T high = CCR*Tpclk
 *  	SM or  FM
 *  Configure the rise time register
 *  add one to value in
 */
#define I2C_SCK_SM_50K			(0x50000UL)
#define I2C_SCK_SM_100K			(100000UL)
#define I2C_SCK_FM_200K			(200000UL)	//Not supported yet
#define I2C_SCK_FM_400k			(400000UL)	//Not supported yet
//@ref I2C_StretchMode_Define
//Bit 7 NOSTRETCH: Clock stretching disable (Slave mode)
//This bit is used to disable clock stretching in slave mode when ADDR or BTF flag is set, until
//it is reset by software.
//0: Clock stretching enabled
//1: Clock stretching disabled
#define I2C_StretchMode_enabled			0x00000000U
#define I2C_StretchMode_disabled		I2C_CR1_NOSTRETCH
//@ref I2C_Mode_Define
//CR1 Bit 1 SMBUS: SMBus mode
//0: I2C mode
//1: SMBus mode
#define I2C_Mode_I2C					0
#define I2C_Mode_SMBus					I2C_CR1_SMBUS
//@ref I2C_Addressing_Slave
#define	I2C_Addressing_Slave_7bits		0
#define I2C_Addressing_Slave_10bits		(uint16_t)(1<<15)
//@ref I2C_Ack_Control_Define
#define I2C_Ack_Control_Enable			I2C_CR1_ACK
#define I2C_Ack_Control_Disable			0
//@ref I2C_ENGC
//I2C_CR1
//Bit 6 ENGC : General Call Enable
//0:General call disabled.Address 00h is NACKED
//1:General Call Enabled.Address 00h is ACKed
#define I2C_ENGC_Enable		I2C_CR1_ENGC
#define I2C_ENGC_Disable	0x00
/*==================================================================*/
/*=============================APIS_Supported=======================*/
/*==================================================================*/
void MCAL_I2C_Init(S_I2C_t * I2Cx,S_I2C_Config_t * I2C_Init_Struct);
void MCAL_I2C_Deinit(S_I2C_t * I2Cx);
void MCAL_I2C_Set_GPIO(S_I2C_t * I2Cx);
//=======Master_Polling_mechanism==================================//
void MCAL_I2C_Master_Tx(S_I2C_t * I2Cx,uint16_t SlaveAdd,uint8_t * dataout,uint32_t datalen,StopCondition Stop,Repeated_Start start);
void MCAL_I2C_Master_Rx(S_I2C_t * I2Cx,uint16_t SlaveAdd,uint8_t * dataout,uint32_t datalen,StopCondition Stop,Repeated_Start start);

//=======Slave_Interrupt_Mechanism================================//
void MCAL_I2C_Slave_SendData(S_I2C_t * I2Cx ,uint8_t data);
uint8_t MCAL_I2C_SlaveReceiveData(S_I2C_t* I2Cx);


//=======Generic API=========//
void I2C_Generate_Start(S_I2C_t * I2Cx,Functional_State state,Repeated_Start start);
FlagStatus	I2C_Get_FlagStatus(S_I2C_t * I2Cx,Status flag);
void I2C_SendAddress(S_I2C_t * I2Cx,uint16_t SlaveAddress,uint8_t I2C_Direction);
void I2C_Generate_Stop(S_I2C_t * I2Cx,Functional_State NewState);
void I2C_ACKnowlageConfig(S_I2C_t * I2Cx  ,Functional_State NewState);
#endif /* INC_STM32F103C6_I2C_DRIVER_H_ */
