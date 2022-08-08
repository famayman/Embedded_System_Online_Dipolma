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
    set(DDRD,5);
	set(DDRD,6);
    set(DDRD,7);


    while (1) 
    {
		set(PORTD,5);
		_delay_ms(1000);
		set(PORTD,6);
		_delay_ms(1000);
        set(PORTD,7);
		_delay_ms(1000);
		Reset(PORTD,7);
		_delay_ms(1000);
		Reset(PORTD,6);
		_delay_ms(1000);
		Reset(PORTD,5);
		_delay_ms(1000);
    }
}

