/*
 * LIFO.c
 *
 *  Created on: Jul 13, 2022
 *      Author: Fam Ayman
 */
#include "LIFO.h"
LIFO_Status_t LIFO_Init(LIFO_Buffer_t * LIFO_Buf ,Element_Type * Buf,Element_Type length)
{
	if(Buf == (void *) 0) //Checking if buf pointing to null
		return LIFO_Null;
	LIFO_Buf->base   =   Buf; //Base points to start of Buffer
	LIFO_Buf->head   = (Element_Type*)(Buf+length); //Head points to the end of Buffer
	LIFO_Buf->length =     length;
	LIFO_Buf->count  =        0 ;
	return LIFO_NO_Error;
}
LIFO_Status_t LIFO_Push_Item(LIFO_Buffer_t * LIFO_Buf ,Element_Type item)
{
	//Check if there is a lifo with that name
		if ( (LIFO_Buf->base == (void*)0)  || (LIFO_Buf->head == (void*)0) )
			return LIFO_Null;
		//Check if there is space in LIFO
		if (LIFO_Buf->count == LIFO_Buf->length )
			return LIFO_IS_Full;
		//adding value
		*(LIFO_Buf->head) = item;
		LIFO_Buf->head++;
		LIFO_Buf->count++;
		return  LIFO_NO_Error;
}
LIFO_Status_t LIFO_Pop_Item(LIFO_Buffer_t * LIFO_Buf,Element_Type * item)
{
	if( !LIFO_Buf->base || !LIFO_Buf->head)
		return LIFO_Null;
	if(IS_LIFO_Empty(LIFO_Buf)== LIFO_IS_Empty)
		return LIFO_IS_Empty;
	LIFO_Buf->head--;
	LIFO_Buf->count--;
	*item = *(LIFO_Buf->head);
	return LIFO_NO_Error;
}
LIFO_Status_t IS_LIFO_Full(LIFO_Buffer_t * LIFO_Buf)

{
	if(LIFO_Buf->count == LIFO_Buf->length)
		return LIFO_IS_Full;
	return LIFO_NO_Error;
}
LIFO_Status_t IS_LIFO_Empty(LIFO_Buffer_t * LIFO_Buf)
{
	if(LIFO_Buf->count == 0)
		return LIFO_IS_Empty;
	return LIFO_IS_Full;
}
