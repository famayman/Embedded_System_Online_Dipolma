#include "stdio.h"
int main()
{
	int sum,Number1,Number2;
	printf("Enter two integers ");
	fflush(stdin);fflush(stdout);
	scanf("%d%d",&Number1,&Number2);
	sum=Number1+Number2;
	printf("sum %d",sum);
	return 0;
}


