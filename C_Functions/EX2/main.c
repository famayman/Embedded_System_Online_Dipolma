#include "stdio.h"
int fact(int Number);
void main()
{
	int Number,result;
	printf("Enter a positive integer: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &Number);
	result = fact(Number);
	printf("factorial of %d = %d",Number,result);
}
int fact(int Number)
{
	if(Number >= 1)
		return Number*fact(Number-1);
	else
		return 1;
}
