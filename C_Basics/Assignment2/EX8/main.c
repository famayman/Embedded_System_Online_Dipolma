#include "stdio.h"
void main()
{
	float Number1,Number2,result;
	char operator;
	printf("Enter operator either + or - or * or divide : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&operator);
	printf("Enter two  operands: ");
	fflush(stdin);fflush(stdout);
	scanf("%f%f",&Number1,&Number2);
	switch (operator)
	{
	case '+':result=Number1+Number2;
	         printf("%.1f + %.1f = %.1f ",Number1,Number2,result);break;
	case '-':result=Number1-Number2;
	         printf("%.1f - %.1f = %.1f ",Number1,Number2,result);break;
	case '*':result=Number1*Number2;
	         printf("%.1f * %.1f = %.1f ",Number1,Number2,result);break;
	case '/':result=Number1/Number2;
	         printf("%.1f / %.1f = %.1f ",Number1,Number2,result);break;
	default: printf("Error !!!");break;
	}
}
