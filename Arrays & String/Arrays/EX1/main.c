#include "stdio.h"
void main()
{
	float array1[2][2],array2[2][2],sum[2][2];
	printf("Enter elements of 1st matrix \n");
	for(int i =0 ;i<2;i++)
	{
		for (int j=0;j<2;j++)
		{
			printf("Enter a%d%d: ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&array1[i][j]);
		}
	}
	printf("Enter elements of 2nd matrix \n");
	for(int i =0 ;i<2;i++)
		{
			for (int j=0;j<2;j++)
			{
				printf("Enter b%d%d: ",i+1,j+1);
				fflush(stdin);fflush(stdout);
				scanf("%f",&array2[i][j]);
			}
		}
	for(int i =0 ;i<2;i++)
			{
				for (int j=0;j<2;j++)
				{
				 sum[i][j]=array1[i][j]+array2[i][j];
				}
			}
	printf("Sum of matrix:\n");
	for(int i =0 ;i<2;i++)
			{
				for (int j=0;j<2;j++)
				{

					printf("%0.1f \t",sum[i][j]);
				}
				printf("\n");
			}
}
