/*
 * DC.h
 *
 *  Created on: Jul 14, 2022
 *      Author: Fam Ayman
 */

#ifndef DC_H_
#define DC_H_
#include "State.h"
//Define Blocks
enum {
	DC_idle,
	DC_busy
}DC_State_ID;
//Declaring State Functions
STATE_define(DC_idle);
STATE_define(DC_busy);
extern void (*DC_state)();
#endif /* DC_H_ */
