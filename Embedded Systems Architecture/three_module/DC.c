/*
 * DC.c

 *
 *  Created on: Jul 14, 2022
 *      Author: Fam Ayman
 */
//Variables
#include "DC.h"
int DC_Speed = 0;

//State Pointer
void (*DC_state)();
void DC_Init()
{
	//init
	printf("DC_init \n");
}
void DC_motor(int s)//For receiving speed from CA
{
	DC_Speed = s; //s is our received speed
	DC_state = STATE_(DC_busy);//only go to busy when speed is fired(speed signal is sent by CA)
	printf("CA------------speed = %d --------------->DC\n",DC_Speed);
}


STATE_define(DC_idle )
{
	DC_State_ID = DC_idle;
	printf("DC_idle State: speed=%d \n",DC_Speed);
	DC_state = STATE_(DC_idle);
}
STATE_define(DC_busy)
{
	DC_State_ID = DC_busy;
	DC_state = STATE_(DC_idle);
	printf("DC_Busy State: speed=%d \n",DC_Speed);

}
