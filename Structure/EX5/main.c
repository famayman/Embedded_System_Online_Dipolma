#include "stdio.h"
#define Area(R) 3.14*R*R
void main()
{
	float  Radius;
	printf("Enter the radius: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&Radius);
	printf("Area= %.2f",3.14*Radius*Radius);
}
