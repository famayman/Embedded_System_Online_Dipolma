#include"stdio.h"
void main()
{
	float sum=0,average,array[100];
    int n;
	printf("Enter the numbers of data : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("%d. Enter Number : ",i+1);
		fflush(stdout);fflush(stdin);
		scanf("%f",&array[i]);
		sum+=array[i];
	}
    average=sum/n;
    printf("Average = %0.2f",average);
}
