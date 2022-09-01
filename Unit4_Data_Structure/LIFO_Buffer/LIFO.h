/*
 * LIFO.h
 *
 *  Created on: Jul 13, 2022
 *      Author: Fam Ayman
 */

#ifndef LIFO_H_
#define LIFO_H_
#include "stdint.h"
//Configuration
#define Element_Type uint8_t
#define   width          5
//
Element_Type Buffer1[width];
Element_Type Buffer2[width];
//Data Type
typedef struct {
	unsigned int length;
	unsigned int count;
    Element_Type *base;
    Element_Type *head;
}LIFO_Buffer_t;
typedef enum {
	LIFO_NO_Error,
	LIFO_IS_Full,
	LIFO_IS_Empty,
	LIFO_Null
}LIFO_Status_t;
//APIS Functions for user  poping,pushing,Init,.....and return LIFO status
LIFO_Status_t LIFO_Init(LIFO_Buffer_t * LIFO_Buf ,Element_Type * Buf,Element_Type length);
LIFO_Status_t LIFO_Push_Item(LIFO_Buffer_t * LIFO_Buf ,Element_Type item );
LIFO_Status_t LIFO_Pop_Item(LIFO_Buffer_t * LIFO_Buf,Element_Type * item);
LIFO_Status_t IS_LIFO_Full(LIFO_Buffer_t * LIFO_Buf);
LIFO_Status_t IS_LIFO_Empty(LIFO_Buffer_t * LIFO_Buf);
#endif /* LIFO_H_ */
