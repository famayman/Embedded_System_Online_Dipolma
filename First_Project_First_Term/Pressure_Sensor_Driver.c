/*
 * Pressure_Sensor_Driver.c
 *
 *  Created on: Jul 19, 2022
 *      Author: Fam Ayman
 */
#include "Pressure_Sensor_Driver.h"
//Variables
int Pressure_Value = 0;
//Pointer to function
void (*Sensor_State)();
//-----------------------------------------Functions---------------------------------------------------------//
STATE_define(PS_Init)
{
	Sensor_State = STATE_(PS_Reading);
}
STATE_define(PS_Reading)
{
	Pressure_Value = getPressureVal();//Storing Value Received By GPIO
	Send_Pressure_Value(Pressure_Value);//Sending Value to Detection Algorithm
	Sensor_State = STATE_(PS_Waiting);//Waiting for 10000 to read another value
}
STATE_define(PS_Waiting)
{
	Delay(10000);
	Sensor_State = STATE_(PS_Reading);//Return to read another value
}


