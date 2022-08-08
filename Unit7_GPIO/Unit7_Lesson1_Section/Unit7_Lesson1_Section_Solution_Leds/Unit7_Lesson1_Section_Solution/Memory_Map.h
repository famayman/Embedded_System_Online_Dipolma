/*
 * Memory_Map.h
 *
 * Created: 8/8/2022 3:26:02 PM
 *  Author: Fam Ayman
 */ 


#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_
#define DDRA *((volatile unsigned char *)0x3A)
#define PORTA *((volatile unsigned char * )0x3B)
#define PINC  *((volatile unsigned char *)0x33)
#define DDRC  *((volatile unsigned char *)0x34)
#define PORTC *((volatile unsigned char *)0x35)
#define DDRD  *((volatile unsigned char *)0x31)
#define PORTD *((volatile unsigned char *)0x32)
#define PIND  *((volatile unsigned char *)0x30)



#endif /* MEMORY_MAP_H_ */