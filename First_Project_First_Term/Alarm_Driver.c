/*
 * Alarm_Driver.c
 *
 *  Created on: Jul 19, 2022
 *      Author: Fam Ayman
 */
#include "Alarm_Driver.h"
//Pointer to Function
void (*Alarm_Pointer)();
//------------------------------------------Functions-----------------------------------------//
void High_Pressure_Deteced(int i)
{
	Alarm_Pointer = STATE_(StartAlarm);
}
void low_Pressure_Deteced(int i)
{
	Alarm_Pointer = STATE_(StopAlarm);
}
STATE_define(Init)
{
	Alarm_Pointer = STATE_(Waiting);
}
STATE_define(Waiting)
{
    Alarm_Pointer = STATE_(Waiting);
}
STATE_define(StartAlarm)
{
	Set_Alarm_actuator(0);
	Alarm_Pointer = STATE_(Waiting);
}
STATE_define(StopAlarm)
{
	Set_Alarm_actuator(1);
	Alarm_Pointer = STATE_(Waiting);
}

