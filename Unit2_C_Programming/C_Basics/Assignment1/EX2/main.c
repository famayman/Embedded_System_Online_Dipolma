/*
 * main.c
 *
 *  Created on: Feb 12, 2022
 *      Author: Fam Ayman
 */
#include "stdio.h"
void main()
{
	int X = 0;
	printf("Enter an integer : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&X);
	printf("You Entered: %d",X);
}

