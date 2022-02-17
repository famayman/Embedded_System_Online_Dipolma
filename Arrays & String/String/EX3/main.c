#include "stdio.h"
void main()
{
	char text1[100],text2[100];
	printf("Enter the string : ");
	fflush(stdin);fflush(stdout);
	gets(text1);
	for(int i= 0 ; i<strlen(text1);i++)
	{
		text2[strlen(text1)-i-1]=text1[i];
	}
	printf("Reverse string is : %s",text2);
}
