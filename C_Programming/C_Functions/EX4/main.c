#include "stdio.h"
int power(int base,int pow);
void main()
{
	int Number,Power,Result;
	printf("Enter Base Number: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&Number);
	printf("Enter power number(positive integer): ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&Power);
	Result=power(Number,Power);
	printf("%d^%d = %d",Number,Power,Result);
}
int power(int base,int pow)
{
	if (pow > 0)
		return (base * power(base ,pow-1));
	else
		return 1;
}
