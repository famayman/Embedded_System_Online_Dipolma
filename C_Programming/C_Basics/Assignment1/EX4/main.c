#include "stdio.h"
void main()
{
	float  product,Number1,Number2;
	printf("Enter Two Numbers ");
	fflush(stdin);fflush(stdout);
	scanf("%f%f",&Number1,&Number2);
	product=Number1 * Number2;
	printf("Product %f",product);
}



