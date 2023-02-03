/*
 * GPIO.c
 *
 *  Author: Fam Ayman
 */ 
/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */
#include "GPIO.h"

/* ================================================================ */
/* =========================APIs=================================== */
/* ================================================================ */

/* ================================================================
* @Fn			-MCAL_GPIO_Init.
* @brief	    -initialize the GPIOx as seen in Config Structure
* @param [in] 	-GPIOx: specifies selected GPIO
* @param [in] 	-PinConfig: pointer to GPIO Config
* @retval 		-none
* Note			-none
*/
void MCAL_GPIO_Init (S_GPIO_t * GPIOx , S_GPIO_Config_t * P_Config)
{
	if(P_Config->GPIO_Pin_Number == GPIO_PINS_PIN0)
	{
		if(P_Config->GPIO_Pin_Mode == GPIO_Pin_Mode_Output)
		{
			GPIOx->DDR.Bits.Bit0     = PIN_Set;
			GPIOx->PORT.Bits.Bit0   = PIN_Reset;
		}
		else if (P_Config->GPIO_Pin_Mode == GPIO_Pin_Mode_INput_No_PULL_UP)
		{
			GPIOx->DDR.Bits.Bit0   = PIN_Reset;
			GPIOx->PORT.Bits.Bit0 = PIN_Reset;
		}
		else
		{
			GPIOx->DDR.Bits.Bit0   = PIN_Set;
			GPIOx->PORT.Bits.Bit0 = PIN_Reset;
		}
		
	}
	else if(P_Config->GPIO_Pin_Number == GPIO_PINS_PIN1)
	{
		if(P_Config->GPIO_Pin_Mode == GPIO_Pin_Mode_Output)
		{
			GPIOx->DDR.Bits.Bit1   = PIN_Set;
			GPIOx->PORT.Bits.Bit1 = PIN_Reset;
		}
		else if (P_Config->GPIO_Pin_Mode == GPIO_Pin_Mode_INput_No_PULL_UP)
		{
			GPIOx->DDR.Bits.Bit1  = PIN_Reset;
			GPIOx->PORT.Bits.Bit1 = PIN_Reset;
		}
		else
		{
			GPIOx->DDR.Bits.Bit1   = PIN_Set;
			GPIOx->PORT.Bits.Bit1 = PIN_Reset;
		}
		
	}
	else if(P_Config->GPIO_Pin_Number == GPIO_PINS_PIN2)
	{
		if(P_Config->GPIO_Pin_Mode == GPIO_Pin_Mode_Output)
		{
			GPIOx->DDR.Bits.Bit2   = PIN_Set;
			GPIOx->PORT.Bits.Bit2 = PIN_Reset;
		}
		else if (P_Config->GPIO_Pin_Mode == GPIO_Pin_Mode_INput_No_PULL_UP)
		{
			GPIOx->DDR.Bits.Bit3   = PIN_Reset;
			GPIOx->PORT.Bits.Bit3 = PIN_Reset;
		}
		else
		{
			GPIOx->DDR.Bits.Bit3   = PIN_Set;
			GPIOx->PORT.Bits.Bit3 = PIN_Reset;
		}
		
	}
	else if(P_Config->GPIO_Pin_Number == GPIO_PINS_PIN3)
	{
		if(P_Config->GPIO_Pin_Mode == GPIO_Pin_Mode_Output)
		{
			GPIOx->DDR.Bits.Bit3  = PIN_Set;
			GPIOx->PORT.Bits.Bit3 = PIN_Reset;
		}
		else if (P_Config->GPIO_Pin_Mode == GPIO_Pin_Mode_INput_No_PULL_UP)
		{
			GPIOx->DDR.Bits.Bit3   = PIN_Reset;
			GPIOx->PORT.Bits.Bit3 = PIN_Reset;
		}
		else
		{
			GPIOx->DDR.Bits.Bit3 = PIN_Set;
			GPIOx->PORT.Bits.Bit3 = PIN_Reset;
		}
		
	}
	else if(P_Config->GPIO_Pin_Number == GPIO_PINS_PIN4)
	{
		if(P_Config->GPIO_Pin_Mode == GPIO_Pin_Mode_Output)
		{
			GPIOx->DDR.Bits.Bit4   = PIN_Set;
			GPIOx->PORT.Bits.Bit4 = PIN_Reset;
		}
		else if (P_Config->GPIO_Pin_Mode == GPIO_Pin_Mode_INput_No_PULL_UP)
		{
			GPIOx->DDR.Bits.Bit4   = PIN_Reset;
			GPIOx->PORT.Bits.Bit4 = PIN_Reset;
		}
		else
		{
			GPIOx->DDR.Bits.Bit4  = PIN_Set;
			GPIOx->PORT.Bits.Bit4 = PIN_Reset;
		}
		
	}
	else if(P_Config->GPIO_Pin_Number == GPIO_PINS_PIN5)
	{
		if(P_Config->GPIO_Pin_Mode == GPIO_Pin_Mode_Output)
		{
			GPIOx->DDR.Bits.Bit5   = PIN_Set;
			GPIOx->PORT.Bits.Bit5 = PIN_Reset;
		}
		else if (P_Config->GPIO_Pin_Mode == GPIO_Pin_Mode_INput_No_PULL_UP)
		{
			GPIOx->DDR.Bits.Bit5 = PIN_Reset;
			GPIOx->PORT.Bits.Bit5 = PIN_Reset;
		}
		else
		{
			GPIOx->DDR.Bits.Bit5  = PIN_Set;
			GPIOx->PORT.Bits.Bit5 = PIN_Reset;
		}
		
	}
	else if(P_Config->GPIO_Pin_Number == GPIO_PINS_PIN6)
	{
		if(P_Config->GPIO_Pin_Mode == GPIO_Pin_Mode_Output)
		{
			GPIOx->DDR.Bits.Bit6   = PIN_Set;
			GPIOx->PORT.Bits.Bit6 = PIN_Reset;
		}
		else if (P_Config->GPIO_Pin_Mode == GPIO_Pin_Mode_INput_No_PULL_UP)
		{
			GPIOx->DDR.Bits.Bit6  = PIN_Reset;
			GPIOx->PORT.Bits.Bit6 = PIN_Reset;
		}
		else
		{
			GPIOx->DDR.Bits.Bit6  = PIN_Set;
			GPIOx->PORT.Bits.Bit6 = PIN_Reset;
		}
		
	}
	else
	{
		if(P_Config->GPIO_Pin_Mode == GPIO_Pin_Mode_Output)
		{
			GPIOx->DDR.Bits.Bit7  = PIN_Set;
			GPIOx->PORT.Bits.Bit7 = PIN_Reset;
		}
		else if (P_Config->GPIO_Pin_Mode == GPIO_Pin_Mode_INput_No_PULL_UP)
		{
			GPIOx->DDR.Bits.Bit7  = PIN_Reset;
			GPIOx->PORT.Bits.Bit7 = PIN_Reset;
		}
		else
		{
			GPIOx->DDR.Bits.Bit7  = PIN_Set;
			GPIOx->PORT.Bits.Bit7 = PIN_Reset;
		}
		
	}
	
}
/* ================================================================
* @Fn			-MCAL_GPIO_Init.
* @brief	    -Deinitialize the GPIOx as seen in Config Structure
* @param [in] 	-GPIOx: specifies selected GPIO which you want to deinit
* @retval 		-none
* Note			-none
*/

void MCAL_GPIO_Reset(S_GPIO_t * GPIOx)
{
	GPIOx->PORT.PORT=0x00;
}
/* ================================================================
* @Fn			-MCAL_GPIO_ReadPin
* @brief	    -return value of specified pin
* @param [in] 	-GPIOx: specifies selected GPIO
* @param [in] 	-Pin_Number: Specifies Number of PIN
* @retval 		-Pin_State
* Note			-none
*/

uint8_t MCAL_GPIO_ReadPin(S_GPIO_t * GPIOx, uint8_t Pin_Number)
{
	uint8_t Pin_State = 0;
	switch(Pin_Number)
	{
		case GPIO_PINS_PIN0:
		{
			Pin_State = GPIOx->PORT.Bits.Bit0;
			break;
		}
		case GPIO_PINS_PIN1:
		{
			Pin_State = GPIOx->PORT.Bits.Bit1;
			break;
		}
		case GPIO_PINS_PIN2:
		{
			Pin_State = GPIOx->PORT.Bits.Bit2;
			break;
		}
		case GPIO_PINS_PIN3:
		{
			Pin_State = GPIOx->PORT.Bits.Bit3;
			break;
		}
		case GPIO_PINS_PIN4:
		{
			Pin_State = GPIOx->PORT.Bits.Bit4;
			break;
		}
		case GPIO_PINS_PIN5:
		{
			Pin_State = GPIOx->PORT.Bits.Bit5;
			break;
		}
		case GPIO_PINS_PIN6:
		{
			Pin_State = GPIOx->PORT.Bits.Bit6;
			break;
		}
		case GPIO_PINS_PIN7:
		{
			Pin_State = GPIOx->PORT.Bits.Bit7;
			break;
		}
	}
	return Pin_State;
}
/* ================================================================
* @Fn			-MCAL_GPIO_ReadPORT
* @brief	    -returns state of PORT
* @param [in] 	-GPIOx: specifies selected GPIO
* @retval 		-PORT State
* Note			-none
*/
uint8_t MCAL_GPIO_ReadPORT(S_GPIO_t * GPIOx)
{
	uint8_t Port_State;
	Port_State = GPIOx->PORT.PORT;
	return Port_State;
}
/* ================================================================
* @Fn			-MCAL_GPIO_WritePin
* @brief	    -write given value to pin
* @param [in] 	-GPIOx: specifies selected GPIO
* @param [in] 	-Pinumber : specifies Pin number in which you want to write
* @param [in] 	-value: specifies the value should be written on Pin
* @retval 		-None
* Note			-none
*/
void MCAL_GPIO_WritePin  (S_GPIO_t * GPIOx , uint8_t  Pin_Number , uint8_t value )
{
	switch(Pin_Number)
	{
		case GPIO_PINS_PIN0 :
		{
			GPIOx->PORT.Bits.Bit0 = value;
			break;
		}
		case GPIO_PINS_PIN1 :
		{
			GPIOx->PORT.Bits.Bit1 = value;
			break;
		}
		case GPIO_PINS_PIN2 :
		{
			GPIOx->PORT.Bits.Bit2 = value;
			break;
		}
		case GPIO_PINS_PIN3 :
		{
			GPIOx->PORT.Bits.Bit3 = value;
			break;
		}
		case GPIO_PINS_PIN4 :
		{
			GPIOx->PORT.Bits.Bit4 = value;
			break;
		}
		case GPIO_PINS_PIN5 :
		{
			GPIOx->PORT.Bits.Bit5 = value;
			break;
		}
		case GPIO_PINS_PIN6 :
		{
			GPIOx->PORT.Bits.Bit6 = value;
			break;
		}
		case GPIO_PINS_PIN7 :
		{
			GPIOx->PORT.Bits.Bit7 = value;
			break;
		}
		
		
	}
}
/* ================================================================
* @Fn			-MCAL_GPIO_WritePort
* @brief	    -write given value to port
* @param [in] 	-GPIOx: specifies selected GPIO
* @param [in] 	-value: specifies the value should be written on Pin
* @retval 		-None
* Note			-n
*/
void MCAL_GPIO_WritePort (S_GPIO_t * GPIOx , uint8_t value)
{
	GPIOx->PORT.PORT= value;
	
}
/* ================================================================
* @Fn			-MCAL_GPIO_TogglePin
* @brief	    -Toggling pin
* @param [in] 	-GPIOx: specifies selected GPIO
* @param [in] 	-Pinumber : specifies Pin number in which you want to write
* @retval 		-None
* Note			-none
*/
void MCAL_GPIO_TogglePin (S_GPIO_t * GPIOx , uint8_t Pin_Number)
{
	switch(Pin_Number)
	{
		case GPIO_PINS_PIN0:
		{
			GPIOx->PORT.Bits.Bit0 ^= 1;
			break;
		}
		case GPIO_PINS_PIN1:
		{
			GPIOx->PORT.Bits.Bit1 ^= 1;
			break;
		}
		case GPIO_PINS_PIN2:
		{
			GPIOx->PORT.Bits.Bit2 ^= 1;
			break;
		}
		case GPIO_PINS_PIN3:
		{
			GPIOx->PORT.Bits.Bit3 ^= 1;
			break;
		}
		case GPIO_PINS_PIN4:
		{
			GPIOx->PORT.Bits.Bit4 ^= 1;
			break;
		}
		case GPIO_PINS_PIN5:
		{
			GPIOx->PORT.Bits.Bit5 ^= 1;
			break;
		}
		case GPIO_PINS_PIN6:
		{
			GPIOx->PORT.Bits.Bit6 ^= 1;
			break;
		}
		case GPIO_PINS_PIN7:
		{
			GPIOx->PORT.Bits.Bit7 ^= 1;
			break;
		}
	}
}
