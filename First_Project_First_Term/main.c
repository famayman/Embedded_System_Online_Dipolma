/*
 * main.c
 *
 *  Created on: Jul 19, 2022
 *      Author: Fam Ayman
 */
#include "Alarm_Driver.h"
#include "Alarm_Monitor.h"
#include "Detection_Algorithm.h"
#include "Pressure_Sensor_Driver.h"

void Setup ()
{
	GPIO_INITIALIZATION();
	Sensor_State = STATE_(PS_Init);
	Detection = STATE_(Waiting_Untill_Receive_Value);
	Alarm_Monitor_Pointer =  STATE_(Waiting_For_Command);
	Alarm_Pointer = STATE_(Waiting);
}
int main()
{
	Setup();
	while(1)
	{
		Sensor_State();
		Detection();
		Alarm_Monitor_Pointer();
		Alarm_Pointer();
	}
	return 0;
}
