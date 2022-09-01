/*
 * main.c
 *
 *  Created on: Jul 14, 2022
 *      Author: Fam Ayman
 */
#include "CA.h"
void setup()
{
	 //init all the drivers
	//init IRQ ....
	//init Hal
	//init block
	CA_state = STATE_(CA_Waiting);

}
void main()
{
	 volatile int i;
	setup();
	while(1)
	{
		//call state for each block
		CA_state();
		for(i=0;i<10000;i++);
	}
}
