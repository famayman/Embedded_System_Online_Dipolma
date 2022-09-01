/*
 * LCD.c
 *
 * Created: 8/9/2022 5:25:28 PM
 *  Author: Fam Ayman
 */ 
#include "LCD.h"
void IS_LCD_Busy()
{
	#ifdef Eight_Bit_MODE
	//Setting LCD PORT As Input
	DataDir_LCD_PORT = 0x00; 
	#endif
	#ifdef FOUR_Bit_MODE
	DataDir_LCD_PORT |=(0xff<< Data_Shift);
	#endif
	//Setting Control in Read Mode
	LCD_CTRL |= (1<<RW_Switch);
	//Rs Is off in Command Mode
	LCD_CTRL &= ~(1<<RS_Switch);
	//while(LCD_PORT >= 0x80);
	LCD_CTRL |= (1<<RS_Switch);
}
void LCD_Send_Pulse()
{
	LCD_CTRL &=~(1<<EN_Switch);
	_delay_ms(50);
	LCD_CTRL |= (1<<EN_Switch);	
}
void LCD_Init()
{
	_delay_ms(20);
	//Setting Control pins as output 
	DataDir_LCD_CTRL |=((1<<EN_Switch)|(1<<RS_Switch)|(1<<RW_Switch));
	//Masking off CTRL bits
	LCD_CTRL &=~((1<<EN_Switch)|(1<<RS_Switch)|(1<<RW_Switch));
	#ifdef Eight_Bit_MODE
	//Setting LCD PORT as OUTPUT
	DataDir_LCD_PORT = 0xff;
	_delay_ms(15);
	LCD_Clear_Screen();
	LCD_Send_Command(LCD_8bit_2Line);
	#endif
	#ifdef FOUR_Bit_MODE
	DataDir_LCD_PORT |= 0x0f;
	_delay_ms(15);
	LCD_Clear_Screen();
	LCD_Send_Command(0x02);
	LCD_Send_Command(LCD_4bit_2_Line);
	#endif
	LCD_Send_Command(LCD_Entry_Mode);
	LCD_Send_Command(LCD_Start_At_Beginning_Of_First_Line);
	LCD_Send_Command(LCD_Display_Cursor_Blinking);
}
void LCD_Send_Command (unsigned char CMD)
{
	#ifdef Eight_Bit_MODE
	IS_LCD_Busy();
	LCD_PORT = CMD;
	LCD_CTRL &= ~((1<<RS_Switch)|(1<<RW_Switch));
	LCD_Send_Pulse();
    #endif
	#ifdef FOUR_Bit_MODE
	IS_LCD_Busy();
	LCD_PORT =  ((LCD_PORT & 0x0F) | (CMD & 0xF0));
	//Rs is off at CMD  Mode And RW is off 
	LCD_CTRL =~((1<<RS_Switch)|(1<<RW_Switch));
	//Sending MSB Nibble
	LCD_Send_Pulse();
	LCD_PORT = ((LCD_PORT & 0x0F) | (CMD << Data_Shift)) ;
	//Rs is off at CMD  Mode And RW is off
	LCD_CTRL =~((1<<RS_Switch)|(1<<RW_Switch));
    //Sending LSB Nibble
	LCD_Send_Pulse();
	#endif
}
void LCD_Send_A_Character(unsigned char data)
{
	 IS_LCD_Busy();
	#ifdef Eight_Bit_MODE
	 //Putting Data on PORT
	 LCD_PORT = data;
	 //Rs is on at read mode
	 LCD_CTRL |= (1<<RS_Switch);
	 //Rw is off at read mode 
	 LCD_CTRL &= ~(1<<RW_Switch);
	 //Sending Data  
	 LCD_Send_Pulse();
    #endif
	#ifdef FOUR_Bit_MODE
	//Putting MSB Nibble on PORT
	LCD_PORT = (LCD_PORT & 0x0F)|(data & 0xF0);
	//RS is on at read mode
	LCD_CTRL |= (1<<RS_Switch);
	//RW is off at read mode
	LCD_CTRL &= ~(1<<RW_Switch);
	//Send MSB NIbble 
	LCD_Send_Pulse();
	//Putting LSB Nibble on Port
	LCD_PORT =(LCD_PORT & 0x0F)|(data << Data_Shift);
	//RS is on at Data mode
	LCD_CTRL |= (1<<RS_Switch);
	//RW is off at Data mode
	LCD_CTRL &= ~(1<<RW_Switch);
	//Send LSB NIbble
	LCD_Send_Pulse();
    #endif
}
void LCD_Send_A_String(char * str)
{ 
	int i ;  
	for(i=0;str[i] != '\0' ; i++)
	{
		LCD_Send_A_Character(str[i]);
		if(i==16)
		{
			LCD_Goto_XY(2,1);
		}
		else if ( i == 32)
		{
			LCD_Clear_Screen();
			LCD_Goto_XY(1,1);
		}
	}
	
}
void LCD_Goto_XY(unsigned char row , unsigned char column)
{
	if(row == 1)
	{
		if(column > 0 && column < 16 )
		LCD_Send_Command(0x80+column);
	}
	else if( row == 2)
	{
		if(column > 0 && column < 16 )
		LCD_Send_Command(0xC0+column);
	}
}
void LCD_Clear_Screen()
{
	LCD_Send_Command(LCD_Clear_Display);
}