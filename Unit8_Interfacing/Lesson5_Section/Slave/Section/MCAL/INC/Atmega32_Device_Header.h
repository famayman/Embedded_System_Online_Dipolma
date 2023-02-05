/*
 * Atmega32_Device_Header.h
 *
 * Created: 1/28/2023 3:21:47 PM
 *  Author: Fam Ayman
 */ 


#ifndef ATMEGA32_DEVICE_HEADER_H_
#define ATMEGA32_DEVICE_HEADER_H_
/* ================================================================ */
/* =========================== Includes =========================== */
/* ================================================================ */
#include "platform_types.h"
/* ================================================================ */
/* ================ Base Addresses ================================ */
/* ================================================================ */
#define GPIOA_Base	0x39	  //This is address  of PINA so it will be its first reg in struct
#define GPIOB_Base	0x36	  //This is address  of PINB so it will be its first reg in struct			
#define GPIOC_Base	0x33	  //This is address  of PINC so it will be its first reg in struct
#define GPIOD_Base	0x30	  //This is address  of PIND so it will be its first reg in struct		
#define UART_Base	0x29	  //Base address of UART Same address as UBBRRL so it will be its first reg in struct
#define SREG_Base	0x5F	  //Global interrupt reg base address	
#define UBRRH_Base	0x40	  //Same PINS as UCSRC but there is pin to control who will master output	
#define UCSRC_Base	0x40	  //Same PINS as UBRRH but there is pin to control who will master output
#define SPI_Base	0x2D	  //Address of SPCR register indicates the start of SPI registers		
/* ================================================================ */
/* ================= Peripheral Registers GPIO ==================== */
/* ================================================================ */
typedef struct
{
/*Note GPIO has 3 registers okay PIN DDR PORT  every one will have its own union */
 	
	volatile union 	
	{
		vuint8 PIN ;  //then we will control its bits with struct
		 struct
		{
			vuint8 Bit0:1;
			vuint8 Bit1:1;
			vuint8 Bit2:1;
			vuint8 Bit3:1;
			vuint8 Bit4:1;
			vuint8 Bit5:1;
			vuint8 Bit6:1;
			vuint8 Bit7:1;
			
			}Bits;
		}PIN;
	/* ================================================================ */
	/* ============================== Space============================ */
	/* ================================================================ */
	volatile union
	{
		vuint8 DDR ; //then we will control its bits with struct
		 struct
		{
			vuint8 Bit0:1;
			vuint8 Bit1:1;
			vuint8 Bit2:1;
			vuint8 Bit3:1;
			vuint8 Bit4:1;
			vuint8 Bit5:1;
			vuint8 Bit6:1;
			vuint8 Bit7:1;
			
		}Bits;
	}DDR;
	/* ================================================================ */
	/* ============================== Space============================ */
	/* ================================================================ */
	volatile union
	{
		vuint8 PORT ;  //then we will control its bits with struct
		 struct
		{
			vuint8 Bit0:1;
			vuint8 Bit1:1;
			vuint8 Bit2:1;
			vuint8 Bit3:1;
			vuint8 Bit4:1;
			vuint8 Bit5:1;
			vuint8 Bit6:1;
			vuint8 Bit7:1;
			
		}Bits;
	}PORT;
	/* ================================================================ */
	/* ============================== Space============================ */
	/* ================================================================ */
	
	}S_GPIO_t;
/* ================================================================ */
/* ================= Peripheral Registers USART =================== */
/* ================================================================ */
typedef struct
{
	vuint8 UBRRL_; //First reg in data sheet in USART
	/* ================================================================ */
	/* ============================== Space============================ */
	/* ================================================================ */
	volatile union
	{
		vuint8 UCSRB_ ; 
		//then we will control its bits with struct
		struct
		{
			vuint8 Bit0:1;
			vuint8 Bit1:1;
			vuint8 Bit2:1;
			vuint8 Bit3:1;
			vuint8 Bit4:1;
			vuint8 Bit5:1;
			vuint8 Bit6:1;
			vuint8 Bit7:1;
			
		}Bits;
	}UCSRB_;
	/* ================================================================ */
	/* ============================== Space============================ */
	/* ================================================================ */
	volatile union
	{
		vuint8 UCSRA_ ;
		//then we will control its bits with struct
		struct
		{
			vuint8 Bit0:1;
			vuint8 Bit1:1;
			vuint8 Bit2:1;
			vuint8 Bit3:1;
			vuint8 Bit4:1;
			vuint8 Bit5:1;
			vuint8 Bit6:1;
			vuint8 Bit7:1;
			
		}Bits;
	}UCSRA_;
	/* ================================================================ */
	/* ============================== Space============================ */
	/* ================================================================ */
	vuint8 UDR_;
	/* ================================================================ */
	/* ============================== Space============================ */
	/* ================================================================ */
	}S_USART_t;
/* ================================================================ */
/* ================= Peripheral Registers USART =================== */
/* ================================================================ */
typedef struct 
{
	volatile union 
	{
		vuint8 SPRCR_;  //Controlling its bits with below structure
		struct{
			vuint8 Bit0:1;
			vuint8 Bit1:1;
			vuint8 Bit2:1;
			vuint8 Bit3:1;
			vuint8 Bit4:1;
			vuint8 Bit5:1;
			vuint8 Bit6:1;
			vuint8 Bit7:1;
			}Bits;
		
		}SPCR_;
/* ================================================================ */
/* ============================== Space============================ */
/* ================================================================ */
	volatile union
	{
		vuint8 SPSR_; //Controlling its bits with below structure
		struct{
			vuint8 Bit0:1;
			vuint8 Bit1:1;
			vuint8 Bit2:1;
			vuint8 Bit3:1;
			vuint8 Bit4:1;
			vuint8 Bit5:1;
			vuint8 Bit6:1;
			vuint8 Bit7:1;
		}Bits;	
		}SPSR_;
/* ================================================================ */
/* ============================== Space============================ */
/* ================================================================ */
	vuint8 SPDR_ ; //No need for struct we will put data directly in it
}S_SPI_t;
	
	
	
	
	
	
	
   /* ================================================================ */
   /* =================== Peripheral Instants  ======================= */
   /* ================================================================ */
#define GPIOA      (S_GPIO_t*)(GPIOA_Base)
#define GPIOB	   (S_GPIO_t*)(GPIOB_Base)
#define GPIOC	   (S_GPIO_t*)(GPIOC_Base)
#define GPIOD	   (S_GPIO_t*)(GPIOD_Base)

   /* ================================================================ */
   /* =================== Macros for important bits ================== */
   /* ================================================================ */
 #define UCSZ0			1	/* PayLoad  UCSRC */
 #define UCSZ1			2	/* PayLoad  UCSRC*/
 #define USBS			3	/* Stop Bit	UCSRC */
 #define UPM0			4	/* Parity   UCSRC*/
 #define UPM1			5	/* Parity   UCSRC*/
 #define SS				4   /*Slave select */
 #define MOSI			5   /*Master output Slave input */
 #define MISO			6	/*Master input slave output */
 #define SCK			7	/*SPI Clock */
 /* ================================================================ */
 /* ====================== Generic Macros  ========================= */
 /* ================================================================ */
 #define UBRRH_					(*(volatile uint8_t *)(UBRRH_Base))
 #define UCSRC_   				(*(volatile uint8_t *)(UCSRC_Base))
 #define SREG_					(*(volatile uint8_t *)(SREG_Base))
 #define Enable_Interrupt()		    SREG_ |= (1 << 7)
 #define Disable_Interrupt()		SREG_ &= ~(1 << 7)


 	
#endif /* ATMEGA32_DEVICE_HEADER_H_ */