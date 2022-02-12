#include "stdio.h"
void main()
{
	float Number;
	printf("Enter a Number: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&Number);
	if (Number > 0)
		printf("%.2f is positive ",Number);
	else if (Number < 0)
		printf("%.2f is negative ",Number);
	else
		printf("you Entered zero ");
}
