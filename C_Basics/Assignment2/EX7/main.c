#include "stdio.h"
void main()
{
	int Number,Factorial = 1;
	printf("Enter an integer: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&Number);
	if(Number < 0)
		printf("Error !!! Factorial of negative number does not exist ");
	else
	{
		for(int i= 1 ;i<=Number;i++)
			Factorial *=i;
		printf("Factorial = %d ",Factorial);
	}

}
