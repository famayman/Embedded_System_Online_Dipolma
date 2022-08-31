/*
 * Key_Pad_Driver.h
 *
 * Created: 8/10/2022 10:45:47 AM
 *  Author: Fam Ayman
 */ 


#ifndef KEY_PAD_DRIVER_H_
#define KEY_PAD_DRIVER_H_
#include <avr/io.h>
#include <util/delay.h>

//Keypad Connections
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7


#define keypadPORT PORTD
#define keypadPIN  PIND
#define keypadDDR  DDRD
void keypad_init();
char Keypad_getKey();
#endif /* KEY_PAD_DRIVER_H_ */