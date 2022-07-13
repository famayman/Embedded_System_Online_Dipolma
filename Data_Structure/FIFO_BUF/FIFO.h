/*
 * FIFO.h
 *
 *  Created on: Jul 13, 2022
 *      Author: Fam Ayman
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "stdint.h"
#include "stdio.h"
//USER_Configuration
#define Element_Type uint8_t
#define width 5
//FIFO_Buffer
Element_Type buff[width];
//FIFO_Data_Type
typedef struct
{
	unsigned int length;
	unsigned int count;
	Element_Type * base;
	Element_Type *head;
	Element_Type * tail;
}FIFO_Buf_t;
typedef enum{
	FIFO_Null,
	FIFO_IS_Full,
	FIFO_IS_Empty,
	FIFO_NO_Error

}FIFO_Buf_Status;
//APIS..................
FIFO_Buf_Status FIFO_Init(FIFO_Buf_t * FIFO_Buf,Element_Type * Buf,uint32_t Length);
FIFO_Buf_Status FIFO_Enqueue(FIFO_Buf_t * FIFO_Buf,Element_Type item);
FIFO_Buf_Status FIFO_Dequeue(FIFO_Buf_t * FIFO_Buf,Element_Type * item);
FIFO_Buf_Status IS_FIFO_FULL(FIFO_Buf_t * FIFO_Buf);
void FIFO_print(FIFO_Buf_t * FIFO_Buf);
#endif /* FIFO_H_ */
