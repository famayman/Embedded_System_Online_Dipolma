/*
 * CA.h
 *
 *  Created on: Jul 14, 2022
 *      Author: Fam Ayman
 */

#ifndef CA_H_
#define CA_H_
#include "State.h"
//Define Types
enum {
	CA_Waiting,
	CA_Driving
}CA_State_ID;
//Declaring State Functions
STATE_define(CA_Waiting);
STATE_define(CA_Driving);
extern void (*CA_state)();
#endif /* CA_H_ */
