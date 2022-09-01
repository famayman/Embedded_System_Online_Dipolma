/*
 * Alarm_Monitor.c
 *
 *  Created on: Jul 19, 2022
 *      Author: Fam Ayman
 */
#include "Alarm_Monitor.h"
//Variables
int Time_Period	= 600000 ;
//Pointer_To_Function
void (*Alarm_Monitor_Pointer)();
//-------------------------------------------Functions-------------------------------------//
STATE_define(Waiting_For_Command)
{
	low_Pressure_Deteced();
	if(Current_State == AlarmON)
		  Alarm_Monitor_Pointer = STATE_(AlarmON);
}

STATE_define(AlarmON)
{
	High_Pressure_Deteced();
	Alarm_Monitor_Pointer = STATE_(Waiting_Period);
}
STATE_define(Waiting_Period)
{
	Delay(Time_Period);
	Alarm_Monitor_Pointer = STATE_(Waiting_For_Command);
	low_Pressure_Deteced();
}
