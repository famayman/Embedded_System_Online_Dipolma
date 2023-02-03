/*
 * GPIO.h
 *
 * Created: 1/28/2023 4:01:54 PM
 *  Author: Fam Ayman
 */ 


#ifndef GPIO_H_
#define GPIO_H_
/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */
#include "Atmega32_Device_Header.h"
/* ================================================================ */
/* =============== Configuration Struct============================ */
/* ================================================================ */
typedef struct
{
	uint8_t GPIO_Pin_Number;		 //Specifies the GPIO PIN to be configured
									 //this parameter must be set based on @ref GPIO_PINS_Define
	uint8_t GPIO_Pin_Mode;			 //Specifies the GPIO PIN Mode
									 //this parameter must be set based on @ref GPIO_Pin_Mode_Define
}S_GPIO_Config_t;


/* ================================================================ */
/* =============== Macros Configuration References ================ */
/* ================================================================ */

//@ref GPIO_PINS_Define
#define GPIO_PINS_PIN0			0
#define GPIO_PINS_PIN1			1
#define GPIO_PINS_PIN2			2
#define GPIO_PINS_PIN3			3
#define GPIO_PINS_PIN4			4
#define GPIO_PINS_PIN5			5
#define GPIO_PINS_PIN6			6
#define GPIO_PINS_PIN7			7


//@ref GPIO_Pin_Mode_Define

#define GPIO_Pin_Mode_Input_PULL_UP			 0
#define GPIO_Pin_Mode_INput_No_PULL_UP		 1
#define GPIO_Pin_Mode_Output				 2

/* ================================================================ */
/* =================   Generic Macros  ============================ */
/* ================================================================ */
#define PIN_Set			0b1
#define PIN_Reset		0b0
/* ================================================================ */
/* =========================APIs=================================== */
/* ================================================================ */
void MCAL_GPIO_Init (S_GPIO_t * GPIOx , S_GPIO_Config_t * P_Config);
void MCAL_GPIO_Reset(S_GPIO_t * GPIOx);
uint8_t MCAL_GPIO_ReadPin(S_GPIO_t * GPIOx, uint8_t Pin_Number);
uint8_t MCAL_GPIO_ReadPORT(S_GPIO_t * GPIOx);
void MCAL_GPIO_WritePin  (S_GPIO_t * GPIOx , uint8_t  Pin_Number , uint8_t value );
void MCAL_GPIO_WritePort (S_GPIO_t * GPIOx , uint8_t value);
void MCAL_GPIO_TogglePin (S_GPIO_t * GPIOx , uint8_t Pin_Number);

#endif /* GPIO_H_ */