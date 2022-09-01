/*
 * Detection_Algorithm.c
 *
 *  Created on: Jul 19, 2022
 *      Author: Fam Ayman
 */
#include "Detection_Algorithm.h"
#include "Alarm_Monitor.h"
//------------------->Variables
int Pressure = 0; //To Store Received Value From Sensor
int Threshold = 20 ;
Alarm_Monitor_Status Current_State = AlarmOFF;//As inital State
//Pointer To function
void (*Detection)();
//----------------------------------Functions-----------------------------------------------//
void Send_Pressure_Value(int Pressure_val)
{
	Pressure = Pressure_val;
	Detection = STATE_(Pressure_Value_Received);
}
STATE_define(Pressure_Value_Received)
{
	if(Pressure <= Threshold)
		State_AlarmOFF() ;
	else
		State_AlarmON() ;
	Detection =STATE_(Waiting_Untill_Receive_Value);
}

STATE_define(Waiting_Untill_Receive_Value)
{
    Current_State =AlarmOFF;
	Detection = STATE_(Waiting_Untill_Receive_Value);
}
