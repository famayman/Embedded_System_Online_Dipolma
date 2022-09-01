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
int CA_threshold = 50 ;
//State Pointer
void (*CA_state)();
void US_Set_distance(int d)
{
	CA_distance = d;
	(CA_distance <= CA_threshold) ? (CA_state = STATE_(CA_Waiting)) : (CA_state = STATE_(CA_Driving));
	printf("Us------------distance = %d --------------->CA\n",CA_distance);//printing Received Signal
}
STATE_define(CA_Waiting)
{
	CA_State_ID = CA_Waiting;
	CA_Speed = 0;
	printf("CA_Waiting State: distance = %d speed=%d \n",CA_distance,CA_Speed);//printing the received distance and Speed that will be sent
	DC_motor(CA_Speed);//Sending speed to DC_Motor
}
STATE_define(CA_Driving)
{
	CA_State_ID = CA_Driving;
	CA_Speed = 30;
	printf("CA_Driving State: distance = %d speed=%d \n ",CA_distance,CA_Speed);//printing the received distance and Speed that will be sent
	DC_motor(CA_Speed);//Sending speed to DC_Motor
}
