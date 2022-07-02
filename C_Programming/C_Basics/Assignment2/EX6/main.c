#include "stdio.h"
void main()
{
	int Sum=0,n;
	printf("Enter an integer: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	for (int i = 1 ; i<=n;i++)
	{
	    Sum+=i;
	}
	printf("Sum = %d",Sum);
}
