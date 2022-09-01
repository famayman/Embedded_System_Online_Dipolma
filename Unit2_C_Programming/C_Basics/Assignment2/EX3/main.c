#include "stdio.h"
void main()
{
	float Number1,Number2,Number3;
	printf("Enter three Numbers : ");
	fflush(stdin);fflush(stdout);
	scanf("%f%f%f",&Number1,&Number2,&Number3);
	if (Number1>=Number2 && Number1>=Number3)
		printf("largest Number = %0.2f",Number1);
	else if (Number2>=Number1 && Number2>=Number3)
		printf("largest Number = %0.2f",Number2);
	else
		printf("largest Number = %0.2f",Number3);
}
