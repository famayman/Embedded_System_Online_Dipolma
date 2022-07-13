/*
 * main.c
 *
 *  Created on: Jul 13, 2022
 *      Author: Fam Ayman
 */
#include "LIFO.h"
#include "stdio.h"
int main()
{
	Element_Type i,temp = 0;
	LIFO_Buffer_t Uart_Buff;
	LIFO_Init(&Uart_Buff,Buffer1,width);
	for(i = 1 ;i<5;i++)
	{
		if(LIFO_Push_Item(&Uart_Buff,i) == LIFO_NO_Error)
			printf("UART LIFO PUSH : %d \n",i);
	}
	for(i = 1 ;i<5;i++)
	{
		if(LIFO_Pop_Item(&Uart_Buff,&temp) == LIFO_NO_Error)
			printf("UART LIFO POP  : %d \n",temp);
	}
	return 0;
}


