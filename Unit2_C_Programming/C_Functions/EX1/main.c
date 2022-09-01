#include "stdio.h"
void Prime_Numbers(int Low,int High );
void main()
{
	int First_Number,Second_Number;
	printf("Enter two numbers (intervals): ");
	fflush(stdin);fflush(stdout);
	scanf("%d%d",&First_Number,&Second_Number);
	printf("Prime numbers between %d and %d are: ", First_Number, Second_Number);
	Prime_Numbers(First_Number,Second_Number);
	fflush(stdin);fflush(stdout);
}
void Prime_Numbers(int Low, int High)
{
	int checker = 1;
	while(Low < High)
	{
		if(Low <=1)
		{
			Low++;
			continue;
		}
		for(int i=2;i <= Low/2  ; i++)
		{
			if(Low % i == 0)
			{

				checker = 0;
				break;
			}
		}
		if ( checker )
		{
			printf("%d ",Low);
		}
		Low++;
		checker = 1;
     }
}
