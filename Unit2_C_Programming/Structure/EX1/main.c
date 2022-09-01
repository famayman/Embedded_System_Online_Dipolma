#include "stdio.h"
struct SStudent
{
	char name[50];
	int roll;
	float marks;
};
void main()
{
	   struct SStudent Student1;
		printf("Enter Name : ");
		fflush(stdin);fflush(stdout);
		gets(Student1.name);
	    printf("Enter roll number : ");
	    fflush(stdin);fflush(stdout);
	    scanf("%d",&Student1.roll);
	    printf("Enter Marks: ");
	    fflush(stdin);fflush(stdout);
	    scanf("%f",&Student1.marks);
	    printf("Displaying information \n");
	    printf("Name : %s \n",Student1.name);
	    printf("Roll : %d \n",Student1.roll);
	    printf("Marks: %f",Student1.marks);


}
