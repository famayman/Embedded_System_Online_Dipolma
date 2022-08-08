/*
 * Uint7_Lesson1_Task2.c
 *
 * Created: 8/8/2022 6:02:41 PM
 * Author : Fam Ayman
 */ 
#include "Utils.h"
#include "Memory_Map.h"
int main(void)
{
	unsigned char i = 0;
	Reset(DDRD,0);
	Reset(PORTD,0);
	set(DDRD,5);
	set(DDRD,6);
	set(DDRD,7);
    while (1) 
    {
		if(Read(PIND,0) == 1 )
		{
			if(i == 0)
			{
				set(PORTD,5);
				i++;
			}
			else if(i == 1)
			{
				set(PORTD,6);
				i++;
			}
			else if(i==2)
			{
				set(PORTD,7);
				i++;
			}
			while(Read(PIND,0) == 1);//For single press
		}
		
    }
}

