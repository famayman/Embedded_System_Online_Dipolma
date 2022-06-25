#include "stdio.h"
struct SComplex
{
	float Real;
	float img;
}Number1,Number2,Result;
void main()
{
	printf("for 1st complex number \nEnter real and imaginary respectively :  ");
	fflush(stdin);fflush(stdout);
	scanf("%f%f",&Number1.Real,&Number1.img);
	printf("for 2nd complex number \nEnter real and imaginary respectively :  ");
	fflush(stdin);fflush(stdout);
	scanf("%f%f",&Number2.Real,&Number2.img);
	Result.Real = Number1.Real+ Number2.Real;
	Result.img  = Number1.img + Number2.img;
	printf("Sum = %.1f + %.1fi",Result.Real,Result.img);
}
