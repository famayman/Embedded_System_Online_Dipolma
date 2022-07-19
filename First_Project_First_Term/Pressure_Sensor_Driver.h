/*******************************************************
 *
 *
 *
 * Pressure_Sensor_Driver.h
 *
 *  Created on: Jul 19, 2022
 *      Author: Fam Ayman
 *
 *
 *
 *********************************************************/

#ifndef PRESSURE_SENSOR_DRIVER_H_
#define PRESSURE_SENSOR_DRIVER_H_
#include "Driver.h"
//enum to indicate Pressure_Sensor_State at current time since we have three blocks so we have three enummerator
typedef enum {
	PS_Init,
	PS_Reading,
	PS_Waiting
}Pressure_Sensor_State;
//Declaring Pointer to function to point to current Block
extern void (*Sensor_State)();
//---------------------------------------------------------------------->APIS
STATE_define(PS_Init); //will be Text replaced By macros
STATE_define(PS_Reading);//will be Text replaced By macros
STATE_define(PS_Waiting);//will be Text replaced By macros
#endif /* PRESSURE_SENSOR_DRIVER_H_ */
