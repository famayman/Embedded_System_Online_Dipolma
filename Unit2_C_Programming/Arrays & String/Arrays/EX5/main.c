#include "stdio.h"
void main()
{
	int array[100],n,Searched,Index=0;
	printf("Enter no of elements : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("Enter the element to be searched : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&Searched);
	for(int i = 0;i<n;i++)
		{
			if(Searched ==array[i])
			{
				  Index =i+1;
			      break;
		    }
		}
	if(Index == 0 )
		printf("Not Found");
	else
		printf("Number found at the Location = %d ",Index);
}
