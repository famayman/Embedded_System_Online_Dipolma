/*
 * CA.h
 *
 *  Created on: Jul 14, 2022
 *      Author: Fam Ayman
 */

#ifndef CA_H_
#define CA_H_
#include "State.h"
//Define Types We have to blocks
enum {
	CA_Waiting,
	CA_Driving
}CA_State_ID; // Knowing State of CA
//Declaring State Functions
STATE_define(CA_Waiting); // Function in Waiting State
STATE_define(CA_Driving); // Function in Driving State
int US_Get_distance_random (int Low,int High);//Random Distance Generation
extern void (*CA_state)();// pointer to function to point to current state
#endif /* CA_H_ */
