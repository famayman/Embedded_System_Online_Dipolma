#include "stdio.h"
void main()
{
	int array[10][10],Rows,Columns;
	printf("Enter rows and Column of matrix: ");
	fflush(stdin);fflush(stdout);
	scanf("%d%d",&Rows,&Columns);
	printf("Enter elements of matrix: \n");
	for( int i= 0;i<Rows;i++)
	{
		for (int j= 0 ;j<Columns;j++)
		{
			printf("Enter element a%d%d: ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%d",&array[i][j]);
		}
	}
	printf("Enter Matrix \n");
	for( int i= 0;i<Rows;i++)
		{
			for (int j= 0 ;j<Columns;j++)
			{
				printf("%d \t",array[i][j]);
			}
			printf("\n");
		}
	printf("Transpose of  Matrix: \n");
		for( int i= 0;i<Columns;i++)
			{
				for (int j= 0 ;j<Rows;j++)
				{
					printf("%d \t",array[j][i]);
				}
				printf("\n");
			}


}
