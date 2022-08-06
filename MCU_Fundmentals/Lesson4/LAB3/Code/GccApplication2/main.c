/*
 * GccApplication2.c
 *
 * Created: 8/6/2022 3:19:16 PM
 * Author : Fam Ayman
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
void GPIO_Init()
{
	DDRD |= ((1<<5)|(1<<6)|(1<<7));
	PORTD &=~((1<<5)|(1<<6)|(1<<7));
	
}
void Interrupt_INIT()
{
	sei();
	MCUCR |=0x0D;
	MCUSR &= (1<<6);
	GICR |=0xE0;
}
int main(void)
{
	GPIO_Init();
	Interrupt_INIT();
	while(1);
	
	
	return 0;
}

ISR(INT0_vect){

	PORTD |= 1<<5;
	_delay_ms(1000);
	PORTD &= ~(1<<5);
}
ISR(INT1_vect){
	PORTD |= 1<<6;
	_delay_ms(1000);
	PORTD &= ~(1<<6);

}
ISR(INT2_vect){
	PORTD |= 1<<7 ;
	_delay_ms(1000);
	PORTD &= ~(1<<7);
}



