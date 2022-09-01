/*
 * main.c
 *
 *  Created on: Jul 13, 2022
 *      Author: Fam Ayman
 */
#include"FIFO.h"
void main()
{
	FIFO_Buf_t FIFO_Uart;
	Element_Type i,temp;
	if(FIFO_Init(&FIFO_Uart,buff,width) == FIFO_NO_Error)
	{
		printf("FIFO Init----------------------Done \n");
	}
	for(i=0;i<7;i++)
	{
		if(FIFO_Enqueue(&FIFO_Uart,i) == FIFO_NO_Error)
			printf("FIFO Enqueue of (%x) -----------DONE \n",i);
		else
			printf("FIFO Enqueue of (%x) ------------Failed \n",i);
	}
	FIFO_print(&FIFO_Uart);
	for(i=0;i<2;i++)
	{
		if(FIFO_Dequeue(&FIFO_Uart,&temp) == FIFO_NO_Error)
			printf("FIFO Dequeue of (%x)------------------Done \n",temp);
		else
			printf("FIFO Dequeue of(%x)-------------------Failed",temp);
	}
	FIFO_print(&FIFO_Uart);
}

