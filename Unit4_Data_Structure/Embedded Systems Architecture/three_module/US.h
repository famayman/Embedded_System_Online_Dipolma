/*
 * US.h
 *
 *  Created on: Jul 14, 2022
 *      Author: Fam Ayman
 */

#ifndef US_H_
#define US_H_
#include "State.h"
//Define Types only we have one block
enum {
	US_busy
}US_State_ID;
//Declaring State Functions
STATE_define(US_busy);
void US_Init();
extern void (*US_state)();
#endif /* US_H_ */
