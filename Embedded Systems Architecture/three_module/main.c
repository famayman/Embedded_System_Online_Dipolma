/*
 * main.c
 *
 *  Created on: Jul 14, 2022
 *      Author: Fam Ayman
 */
#include "CA.h"
#include "US.h"
#include "DC.h"
void setup()
{
	US_Init();
	DC_Init();

	CA_state = STATE_(CA_Waiting);
	US_state = STATE_(US_busy);
    DC_state = STATE_(DC_idle);
}
void main()
{
	 volatile int i;
	setup();
	while(1)
	{
		//call state for each block
		fflush(stdin);fflush(stdout);
		US_state();
		CA_state();
		DC_state();
		for(i=0;i<100000;i++);
	}
}
