/*
 * Linked_List.h
 *
 *  Created on: Jul 13, 2022
 *      Author: Fam Ayman
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#define Null  (void *)0
#define Dprint(...)    {fflush(stdout);\
						fflush(stdin);\
						printf(__VA_ARGS__);\
						fflush(stdout);\
						fflush(stdin);}
//Effective Data
typedef struct
{
	int ID;
	char name[40];
	float height;
}S_Data_t;
//Linked_List
typedef struct{
	S_Data_t Student_info;
	struct S_Student_t *Pnext_Student;
}S_Student_t;
//APIS---------------------------------------------------------------
void Add_Student();
void View_Students();
int Delete_Student();
void Delete_All();
void Get_Nth();
void Get_Length();
void Fill_Block(S_Student_t* pNew_Student);
int Get_Length_Recursive(S_Student_t * pCurrent_Student);
void Calling_Get_Length_Recursive();
void Get_Nth_From_End_Two_Pointer_Method();
void Get_Middle();
void Reverse_List();








#endif /* LINKED_LIST_H_ */
