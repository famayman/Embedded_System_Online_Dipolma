/*
 * LCD_And_Keypad.c
 *
 * Created: 8/9/2022 5:24:39 PM
 * Author : Fam Ayman
 */ 

#include <avr/io.h>
#include "LCD_Driver/LCD.h"
int main(void)
{

	LCD_Init();
    LCD_Send_A_String("Learn-in-depth");
    while (1) 
    {

	}
}

