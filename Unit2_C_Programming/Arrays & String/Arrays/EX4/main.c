#include "stdio.h"
void main()
{
	int n,array1[100],Inserted_Element,location,array2[100];
	printf("Enter no of elements:  ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		fflush(stdin);fflush(stdout);
		scanf("%d",&array1[i]);
	}
	printf("Enter the element to be inserted : ");
	fflush(stdin);fflush(stdout);
    scanf("%d",&Inserted_Element);
    printf("Enter the location : ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&location);
    for(int j=0,i=0;j<n;j++)
    {
    	if( (i+1) == location)
    	{
    		array2[i]=Inserted_Element;
    	    i++;
    	}
    	array2[i]=array1[j];
    	i++;
    }
    for(int i=0;i<n+1;i++)
    {
    	printf("%d  ",array2[i]);
    }

}
