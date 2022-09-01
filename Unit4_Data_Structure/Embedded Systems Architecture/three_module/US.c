/*
 * US.c

 *
 *  Created on: Jul 14, 2022
 *      Author: Fam Ayman
 */
//Variables
#include "US.h"
int US_distance = 0 ;
void US_Init()
{
	 //Init Driver
	printf("US_Init \n");
}
int US_Get_distance_random (int Low,int High)
{

			return ((rand()%(High-Low+1))+Low);

}
void (*US_state)();
STATE_define(US_busy)
{
	US_State_ID = US_busy;
	US_distance = US_Get_distance_random(45,55);//generating the distance
	printf("US_busy State: distance = %d  \n ",US_distance);//printing the generated distance
	US_Set_distance(US_distance);//Sending distance to CA
	US_state =STATE_(US_busy);//only we have one state which is busy
}

