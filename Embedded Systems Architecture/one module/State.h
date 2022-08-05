/*
 * State.h
 *
 *  Created on: Jul 14, 2022
 *      Author: Fam Ayman
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "stdlib.h"
//automatic state function generated by Macros
#define STATE_define(_stateFunc_)  void ST_##_stateFunc_()
#define STATE_(_stateFUN_)          ST_##_stateFUN_
#endif /* STATE_H_ */