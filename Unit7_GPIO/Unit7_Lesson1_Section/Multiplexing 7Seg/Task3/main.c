/*
 * Unit7_Lesson1_Section_Solution.c
 *
 * Created: 8/8/2022 3:18:29 PM
 * Author : Fam Ayman
 */ 
#define F_CPU 8000000UL
#include "Memory_Map.h"
#include "Utils.h"
#include "avr/delay.h"
int main(void)
{
    DDRC = 0xFF;
	unsigned char i,j;
	while(1)
	{
   for(i=0;i<10;i++)
   {
	   for(j=0;j<10;j++)
	   {
		   PORTC = (0b1011)| (i<<4);
		   _delay_ms(30);
		   PORTC = (0b0111)| (j<<4);
	      _delay_ms(30);
	   }
		   
   }
	}
}

