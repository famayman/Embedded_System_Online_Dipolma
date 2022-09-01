/*
 * Alarm_Monitor.h
 *
 *  Created on: Jul 19, 2022
 *      Author: Fam Ayman
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_
#include "driver.h"
////Enum for number of Blocks
typedef enum {
	Waiting_For_Command,
	AlarmOFF,
	AlarmON,
	Waiting_Period
}Alarm_Monitor_Status;
extern Alarm_Monitor_Status Current_State ;
//Pointer to Function
extern void (*Alarm_Monitor_Pointer)();
//--------------------------------------------Functions---------------------------------------------//
STATE_define(Waiting_For_Command);
STATE_define(AlarmON);
STATE_define(AlarmOFF);
STATE_define(Waiting_Period);
#endif /* ALARM_MONITOR_H_ */
