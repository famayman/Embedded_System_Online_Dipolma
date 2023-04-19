/*
 * STM32F103C6_I2C_Driver.c
 *
 *  Created on: Feb 10, 2023
 *      Author: Fam Ayman
 */

#include "STM32F103C6_I2C_Driver.h"
#include "STM32F103C6_USART_Driver.h"
#include "STM32F103C6_RCC_Driver.h"
/*
 * ========================================================
 * 				Generic macros
 * ========================================================
 */
#define I2C1_Index			0
#define I2C2_Index			1
/*
 * ========================================================
 * 				Generic Variables
 * ========================================================
 */
S_I2C_Config_t Global_I2C_Config[2] ;
/*==================================================================*/
/*================================APIS==============================*/
/*==================================================================*/
/**=======================================================
 * @Fn				-MCAL_I2C_Init
 * @brief			-Initializes I2C
 * @param [in]		-I2C_Instance
 * @param [in]		-I2C_Init_Struct
 * @retval			-Non
 * Note
 */

void MCAL_I2C_Init(S_I2C_t * I2Cx ,S_I2C_Config_t * I2C_Init_Struct)
{
	uint16_t tempreg = 0,freqrange = 0;
	uint32_t Pclk = 8000000;
	uint16_t result = 0;

	if(I2Cx == I2C1)
	{
		Global_I2C_Config[I2C1_Index] = *I2C_Init_Struct;
		RCC_I2C1_CLK_EN();
	}
	else
	{
		Global_I2C_Config[I2C2_Index] = *I2C_Init_Struct;
		RCC_I2C1_CLK_EN();
	}
	if(I2C_Init_Struct->I2C_Mode == I2C_Mode_I2C)
		{
			/*------------------------------------------Init Timing---------------------------*/

			//1-I2C_CR2 :FREQ[5:0]:Peripheral clock frequency
			/*get the I2Cx_CR2 Value */
			tempreg = I2Cx->I2C_CR2 ;
			/*clear the FREQ[5:0] bits  */
			tempreg &= ~(I2C_CR2_FREQ_Msk) ;
			/*get Pclk frequency value */
			Pclk = MCAL_RCC_GetPCLK1Freq();
			/*Set frequency Bits depending on Pclk value */
			freqrange = (uint16_t)(Pclk / 1000000);
			tempreg |= freqrange;
			/* write to CR2*/
			I2Cx->I2C_CR2 = tempreg ;

			//2-Configure the clock control registers

			/*Disable the selected I2C Peripheral to configure Time Just to make sure */
			I2Cx->I2C_CR1 &= ~(I2C_CR1_PE);
			tempreg = 0;

			/*Configure speed in standard mode */
			if((I2C_Init_Struct->I2C_Speed == I2C_SCK_SM_50K) || (I2C_Init_Struct->I2C_Speed == I2C_SCK_SM_100K))
			{
				/*standard mode speed calculation*/
				//T_high = CCR*T_Pclk & T_Pclk = T_high + T_low
				//CRR = Tclk / (2*TPclk)
				//CRR = (F_Pclk) / (2* F_i2cclk)
				result =(uint16_t) (Pclk / ( I2C_Init_Struct->I2C_Speed * 2 ));
				tempreg = I2Cx->I2C_CCR;
				tempreg |= result;
				/* write to CRR*/
				I2Cx->I2C_CCR = tempreg ;

				//3-I2C_TRISE Configuration
				/* frequency bits +1 */
				I2Cx->I2C_TRISE = freqrange +1 ;

			}
			else
			{
				//fast mode not Supported
			}

		/*===============================Configuring CR1=================================*/
		/*===========Get Value in CR1*==============*/
		tempreg = I2Cx->I2C_CR1;
		tempreg |=(uint16_t)((I2C_Init_Struct->I2C_Ack_Conrtol)|(I2C_Init_Struct->I2C_stretchmode)|(I2C_Init_Struct->I2C_Mode));
		I2Cx->I2C_CR1 =tempreg;
		/*=============================Configuring OAR2 ================================*/
		tempreg = 0;
		if(I2C_Init_Struct->I2C_Slave_address.Enable_Dual_Address == 1)
		{
			tempreg |= I2C_OAR2_ENDUAL;
			tempreg |= (I2C_Init_Struct->I2C_Slave_address.SecondaryAddress <<I2C_OAR2_ADD2_Pos);
			I2Cx->I2C_OAR2 = tempreg;
		}
		tempreg = 0;
		tempreg |= (I2C_Init_Struct->I2C_Slave_address.PrimaryAddress <<1);
		tempreg |= (I2C_Init_Struct->I2C_Slave_address.I2C_Addressing_Mode<< 1);

		//Interrupt mode in case of slave //Call back != Null
		if(I2C_Init_Struct->P_Slave_Event_CallBack != NULL)//Works with Interrupt Mode
		{
			I2Cx->I2C_CR2 |= I2C_CR2_ITBUFEN;
			I2Cx->I2C_CR2 |= I2C_CR2_ITERREN;
			I2Cx->I2C_CR2 |= I2C_CR2_ITEVTEN;
		}
		if(I2Cx == I2C1)
		{
			NVIC_IRQ31_I2C1_EV_Enable;
			NVIC_IRQ32_I2C1_ER_Enable;
		}
		else
		{
			NVIC_IRQ33_I2C2_EV_Enable;
			NVIC_IRQ34_I2C2_ER_Enable;
		}
		I2Cx->I2C_SR1 = 0x0;
		I2Cx->I2C_SR2 = 0x0;


	}
	else
	{
		//Not Supported yet
	}
	/*Enable the selected I2C Peripheral */
	I2Cx->I2C_CR1 |= (I2C_CR1_PE);
}
/**=======================================================
 * @Fn				-MCAL_I2C_DeInit
 * @brief			-DeInitializes I2C
 * @param [in]		-I2C_Instance which you want to definit
 * @retval			-Non
 * Note
 */
void MCAL_I2C_Deinit(S_I2C_t * I2Cx)
{
	if(I2Cx == I2C1)
	{
		NVIC_IRQ31_I2C1_EV_Disable;
		NVIC_IRQ32_I2C1_ER_Disable;
		RCC_I2C1_CLK_Reset();
	}
	else
	{
		NVIC_IRQ33_I2C2_EV_Disable;
		NVIC_IRQ34_I2C2_ER_Disable;
		RCC_I2C2_CLK_Reset();
	}

}
/**=======================================================
 * @Fn				-MCAL_I2C_Set_GPIO
 * @brief			-Sets I2C GPIO
 * @param [in]		-I2C_Instance which you want to set its GPIO
 * @retval			-Non
 * Note
 */
void MCAL_I2C_Set_GPIO(S_I2C_t * I2Cx)
{
	GPIO_Pin_Config_t PConfig;
	if(I2Cx == I2C1)
	{
		// PB6 : I2C1_SCL
		// PB7 : I2C1_SDA
		PConfig.GPIO_Mode = GPIO_Mode_Output_AF_OD;
		PConfig.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
		PConfig.GPIO_Pin_Number = GPIO_PIN_6;
		MCAL_GPIO_Init(GPIOB, &PConfig);
		PConfig.GPIO_Mode = GPIO_Mode_Output_AF_OD;
		PConfig.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
		PConfig.GPIO_Pin_Number = GPIO_PIN_7;
		MCAL_GPIO_Init(GPIOB, &PConfig);
	}
	else
	{
		//PB10	: I2C2_SCL
		//PB11	: I2C2_SDA
		PConfig.GPIO_Mode = GPIO_Mode_Output_AF_OD;
		PConfig.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
		PConfig.GPIO_Pin_Number = GPIO_PIN_10;
		MCAL_GPIO_Init(GPIOB, &PConfig);
		PConfig.GPIO_Mode = GPIO_Mode_Output_AF_OD;
		PConfig.GPIO_OUTPUT_Speed = GPIO_SPEED_10MHz;
		PConfig.GPIO_Pin_Number = GPIO_PIN_11;
		MCAL_GPIO_Init(GPIOB, &PConfig);
	}
}
void MCAL_I2C_Master_Tx(S_I2C_t * I2Cx,uint16_t SlaveAdd,uint8_t * dataout,uint32_t datalen,StopCondition Stop,Repeated_Start start)
{
	int i = 0;
	//1.Set start bit in CR1 o generate Start Condition
	I2C_Generate_Start(I2Cx,ENABLE,Start);
	//2.Wait untill event 5
	while(!I2C_Get_FlagStatus(I2Cx,EV5));
	//3.Send address
	I2C_SendAddress(I2Cx,SlaveAdd,I2C_Direction_Transmitter);
	//4.Wait for Event 6
	while(!I2C_Get_FlagStatus(I2Cx,EV6));
	//5./*TRA,Busy,MSL,TXE flags*/
	while(!I2C_Get_FlagStatus(I2Cx, Master_Byte_Transmitting));
	for(i=0;i<datalen;i++)
	{
		I2Cx->I2C_DR = dataout[i];
		//4.Wait for Event 8
		//EV8: TxE=1, shift register not empty, data register empty, cleared by writing DR register .
		while(!I2C_Get_FlagStatus(I2Cx,EV8));
	}
	//===========================Sending_Stop=====================================================//
	if(Stop == WithStop)
	{
		I2C_Generate_Stop(I2Cx,ENABLE);
	}

}
void MCAL_I2C_Master_Rx(S_I2C_t * I2Cx,uint16_t SlaveAdd,uint8_t * dataout,uint32_t datalen,StopCondition Stop,Repeated_Start start)
{
	int i = 0;
	//1.Set start bit in CR1 o generate Start Condition
	I2C_Generate_Start(I2Cx,ENABLE,Start);
	//2.Wait untill event 5
	while(!I2C_Get_FlagStatus(I2Cx,EV5));
	//3.Send address
	I2C_SendAddress(I2Cx,SlaveAdd,I2C_Direction_Receiver);
	//4.Wait for Event 6
	while(!I2C_Get_FlagStatus(I2Cx,EV6));
	if(datalen)
	{
		for( i=datalen;i>1;i--)
		{
			while(!I2C_Get_FlagStatus(I2Cx, EV7));
			*dataout = I2Cx->I2C_DR;
			//Increment Buffer
			dataout++;
		}
	}
	//===========================Sending_Stop=====================================================//
		if(Stop == WithStop)
		{
			I2C_Generate_Stop(I2Cx,ENABLE);
		}
//to do here

}
void I2C_Generate_Start(S_I2C_t * I2Cx,Functional_State state,Repeated_Start start)
{
	//Check if the start is repeated or not
	if(start == Repeated)
	{
		while(I2C_Get_FlagStatus(I2Cx, I2C_Flag_Busy));
	}
	if(state == ENABLE)
	{
		//Bit 8 START: Start generation
		//This bit is set and cleared by software and cleared by hardware when start is sent or PE=0.
		//In Master Mode:
		//0: No Start generation
		//1: Repeated start generation
		//In Slave mode:
		//0: No Start generation
		//1: Start generation when the bus is free
		I2Cx->I2C_CR1 |= (I2C_CR1_START);
	}
	else
	{
		I2Cx->I2C_CR1 &= ~(I2C_CR1_START);

	}
}
void I2C_ACKnowlageConfig(S_I2C_t * I2Cx  ,Functional_State NewState)
{
	if(NewState != DISABLE)
		{
			/*generate the acknowladge*/
			I2Cx->I2C_CR1 |= I2C_CR1_ACK;
		}
		else
		{
			/*disable the acknowladge*/
			I2Cx->I2C_CR1 &= ~(I2C_CR1_ACK);
		}
}

FlagStatus	I2C_Get_FlagStatus(S_I2C_t * I2Cx,Status flag)
{
	FlagStatus Flag = Reset;
	uint32_t flag1=0,flag2=0;
	uint16_t dummy;
	uint32_t Last_Event;
	switch(flag)
	{
	case I2C_Flag_Busy:
	{
		if(((I2Cx->I2C_SR2) & (I2C_SR2_BUSY)))
		{
			Flag = Set;
		}
		else
		{
			Flag = Reset;
		}
		break;
	}
	case EV5:
	{
		if(((I2Cx->I2C_SR1) & (I2C_SR1_SB)))
		{
			Flag = Set;
		}
		else
		{
			Flag = Reset;
		}
		break;
	}
	case EV6:
	{
		//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
		if(I2Cx->I2C_SR1&I2C_SR1_ADDR)
		{
			Flag =Set;
		}
		else
		{
			Flag = Reset;
		}
		break;

	}
	case Master_Byte_Transmitting:
	{
		flag1=I2Cx->I2C_SR1;
		flag2=I2Cx->I2C_SR2;
		flag2=flag2<<16;
		Last_Event=((flag1 | flag2) &(uint32_t)0x00FFFFFF);;//Note last 8 bit in SR2 is reserved so we made it zero
		if((Last_Event & flag)== flag)
		{
			Flag = Set;
		}
		else
		{
			Flag= Reset;
		}
		break;
	}
	case EV8_1:
	case EV8:
	{
		//Bit 7 TxE: Data register empty (transmitters)
		//0: Data register not empty
		//1: Data register empty
		if((I2Cx->I2C_SR1) &(I2C_SR1_TXE))
		{
			Flag=Set;
		}
		else
		{
			Flag=Reset;
		}
		break;
	}
	case EV7:
	{
		//Bit 6 RxNE: Data register not empty (receivers)
		//0: Data register empty
		//1: Data register not empty
		if((I2Cx->I2C_SR1)&(I2C_SR1_RXNE))
		{
			Flag=Set;
		}
		else
		{
			Flag=Reset;
		}
		break;
	}

	}
	return Flag;
}
void I2C_SendAddress(S_I2C_t * I2Cx,uint16_t SlaveAddress,I2C_Direction Direction)
{
	SlaveAddress = (SlaveAddress<<1);
	if(Direction != I2C_Direction_Transmitter)
	{
		SlaveAddress |= (1<<0);
	}
	else
	{
		SlaveAddress &= ~(1<<0);
	}
	/*==========SendingAddress=======*/
	I2Cx->I2C_DR = SlaveAddress;
}
void I2C_Generate_Stop(S_I2C_t * I2Cx,Functional_State NewState)
{
	//Generate Stop
	if(NewState != DISABLE)
		{
			/*generate a stop condition*/
			I2Cx->I2C_CR1 |= I2C_CR1_STOP;
		}
		else
		{
			/*disable the stop condition*/
			I2Cx->I2C_CR1 &= ~(I2C_CR1_STOP);
		}
}
void MCAL_I2C_Slave_SendData(S_I2C_t * I2Cx ,uint8_t data)
{
	I2Cx->I2C_DR = data;
}
uint8_t MCAL_I2C_SlaveReceiveData(S_I2C_t * I2Cx)
{
	return I2Cx->I2C_DR;
}


