/*
 * CA.c

 *
 *  Created on: Jul 14, 2022
 *      Author: Fam Ayman
 */
//Variables
#include "CA.h"
int CA_Speed = 0;
int CA_distance = 0 ;
int CA_threshold = 50 ;//CA_threshold for changing State
//State Pointer
void (*CA_state)();
STATE_define(CA_Waiting) //waiting block
{
	//State_Name
	CA_State_ID = CA_Waiting;
	//Get_Distance
	CA_distance = US_Get_distance_random(45,55); //Getting random distance
	CA_Speed = 0;
	//Event_Check to change block which pointer to function points to.......
	(CA_distance <= CA_threshold) ? (CA_state = STATE_(CA_Waiting)) : (CA_state = STATE_(CA_Driving));
	printf("CA_Waiting State: distance = %d speed=%d \n ",CA_distance,CA_Speed);
}
STATE_define(CA_Driving) //Driving block
{
	//State_Name
	CA_State_ID = CA_Driving;
	CA_Speed = 30;
	CA_distance = US_Get_distance_random(45,55);//Generating new distance
	//Check if the new generated distance changes the block which point to function points to
	(CA_distance <= CA_threshold) ? (CA_state = STATE_(CA_Waiting)) : (CA_state = STATE_(CA_Driving));
	printf("CA_Waiting State: distance = %d speed=%d \n ",CA_distance,CA_Speed);
}
int US_Get_distance_random (int Low,int High) //Random_distance generation
{
			return (rand()%(High-Low+1))+Low;

}
