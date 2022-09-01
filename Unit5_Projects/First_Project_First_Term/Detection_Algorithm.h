/*
 * Detection_Algorithm.h
 *
 *  Created on: Jul 19, 2022
 *      Author: Fam Ayman
 */

#ifndef DETECTION_ALGORITHM_H_
#define DETECTION_ALGORITHM_H_
#include "Driver.h"
//Enum for number of Blocks
typedef enum {
	Pressure_Value_Received,
	Waiting_Untill_Receive_Value
}Detection_State;
//Pointer to function
extern void (*Detection)();
//---------------------------------------------Blocks-------------------------------------------//
STATE_define(Pressure_Value_Received);
STATE_define(Waiting_Untill_Receive_Value);
#endif /* DETECTION_ALGORITHM_H_ */
