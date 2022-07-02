#include "stdio.h"
int main()
{
	int array[15],Number,i,*ptr;
	printf("Input the number of elements to store in the array (max 15) : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&Number);
	for(i=0;i<Number;i++)
	{
		printf("element -%d : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",&array[i]);
	}
	ptr = array;
	printf("The elements of array in reverse order are :\n");
	fflush(stdin);fflush(stdout);
	for(i=Number - 1;i>=0;i--)
	{
		printf("element -%d : %d \n",i+1,*(ptr+i));
	}
	return 0;
}
