/*
 * LCD_And_Keypad.c
 *
 * Created: 8/9/2022 5:24:39 PM
 * Author : Fam Ayman
 */ 

#include <avr/io.h>
#include "LCD_Driver/LCD.h"
#include "KeyPad_Driver/Key_Pad_Driver.h"
int main(void)
{
	char Keypressed;
	LCD_Init();
    keypad_init();
    while (1) 
    {
		Keypressed = Keypad_getKey();
		switch(Keypressed)
		{
			case  ('A'): break; //No Key Pressed
			case  ('?'): LCD_Clear_Screen();break;
			default: LCD_Send_A_Character(Keypressed);break;
    }
	}
}

