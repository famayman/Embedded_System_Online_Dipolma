#include "stdio.h"
void main()
{
	char X;
	printf("Enter a character: ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&X);
	if((65 <= X && X<=90 ) || (97 <= X && X <= 122 ))
	     printf("%c is an alphabet ",X);
	else
         printf("%c is not an alphabet ",X);
}
