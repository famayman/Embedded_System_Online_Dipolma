#include "stdio.h"
struct SDistance
{
	int feet;
	float inch;
}Distance1,Distance2,Result;
void main()
{
	printf("Enter information for 1st distance \n");
	printf("Enter feet : ");
	fflush(stdin);fflush(stdout);
    scanf("%d",&Distance1.feet);
    printf("Enter Inch : ");
    fflush(stdin);fflush(stdout);
    scanf("%f",&Distance1.inch);
    printf("Enter information for 2nd distance \n");
    fflush(stdin);fflush(stdout);
    printf("Enter feet : ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&Distance2.feet);
    printf("Enter inch :  ");
    fflush(stdin);fflush(stdout);
    scanf("%f",&Distance2.inch);
    Result.feet = Distance1.feet+Distance2.feet;
    Result.inch = Distance1.inch+Distance2.inch;
    while (Result.inch >12)
    {
    	Result.inch -=12;
    	++Result.feet;
    }
    printf("Sum of distance  = %d'-%.1f\"",Result.feet,Result.inch);

}
