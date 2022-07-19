/*
 * Alarm_Driver.h
 *
 *  Created on: Jul 19, 2022
 *      Author: Fam Ayman
 */

#ifndef ALARM_DRIVER_H_
#define ALARM_DRIVER_H_
#include "driver.h"
//Enum for Blocks
typedef enum {
	Init,
	Waiting,
	StartAlarm,
	StopAlarm
}Alarm_Status;
//Pointer to Function
extern void (*Alarm_Pointer)();
//--------------------------------------------Functions----------------------------------------//
STATE_define(Init);
STATE_define(Waiting);
STATE_define(StartAlarm);
STATE_define(StopAlarm);
#endif /* ALARM_DRIVER_H_ */
