#include "stdio.h"
void main()
{
	int Number;
	printf("Enter an integer you want to check : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&Number);
	if( Number%2 == 0)
		printf("%d is even ",Number);
	else
		printf("%d is odd ",Number);
}
