/*
 * Student.h
 *
 *  Created on: Jul 20, 2022
 *      Author: Fam Ayman
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#define Dprint(...)    {fflush(stdout);\
						fflush(stdin);\
						printf(__VA_ARGS__);\
						fflush(stdout);\
						fflush(stdin);}
#define Null   (void*)0
///////---------------------USER_Configuration----------------////
#define Element_Type uint8_t
#define width 5
//FIFO_Buffer
typedef struct  {
	char fname[50];
	char lname[50];
	int roll;
	float GPA;
	int cid[10];
}Sinfo;
Sinfo ST[50];
//FIFO_Data_Type
typedef struct
{
	unsigned int length;
	unsigned int count;
	Sinfo  * base;
	Sinfo  *head;
	Sinfo  *tail;
}FIFO_Buf_t;
typedef enum {
	FIFO_Null,
	FIFO_IS_Full,
	FIFO_IS_Empty,
	FIFO_NO_Error
}FIFO_Buf_Status;
//------------------------------------>APIS
void FIFO_Init(FIFO_Buf_t * FIFO_Buf,Sinfo * Buf,uint32_t Length);
void Add_Student_Details_From_File(FIFO_Buf_t * FIFO_Buf);
void Add_Student_Manually(FIFO_Buf_t * FIFO_Buf);
void Find_Student_By_Roll(FIFO_Buf_t * FIFO_Buf);
void Find_Student_By_First_Name(FIFO_Buf_t * FIFO_Buf);
void Find_NO_OF_Students_IN_Course(FIFO_Buf_t * FIFO_Buf);
void Count_Students(FIFO_Buf_t * FIFO_Buf);
void  Delete_Student(FIFO_Buf_t * FIFO_Buf);
void Update_Student(FIFO_Buf_t * FIFO_Buf);
FIFO_Buf_Status IS_FIFO_Full(FIFO_Buf_t * FIFO_Buf);
FIFO_Buf_Status IS_FIFO_Empty(FIFO_Buf_t * FIFO_Buf);
int Check_Roll_Num(FIFO_Buf_t * FIFO_Buf,Sinfo * Buf,int Num);
void show_Students(FIFO_Buf_t * FIFO_Buf);
void Switch(FIFO_Buf_t * FIFO_Buf,Sinfo *ptr);
void FIFO_Dequeue(FIFO_Buf_t * FIFO_Buf);












#endif /* STUDENT_H_ */
