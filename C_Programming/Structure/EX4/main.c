#include "stdio.h"
struct SStudent
{
	char Name[50];
	int marks;
	int roll;
};
void main()
{
	struct SStudent Student[10];
	printf("Enter information of students \n");
	fflush(stdout);fflush(stdin);
	for(int i = 0 ; i<10;i++)
	{
		printf("For roll number ");
		fflush(stdout);fflush(stdin);
		scanf("%d",&Student[i].roll);
		printf("Enter Name : ");
		fflush(stdout);fflush(stdin);
		gets(Student[i].Name);
		printf("Enter marks :  ");
		fflush(stdout);fflush(stdin);
		scanf("%d",&Student[i].marks);
	}
	for(int i = 0 ; i<10;i++)
	{
		printf("information for role number %d: \n",Student[i].roll);
		printf("Name : %s \n",Student[i].Name);
		printf("marks: %d \n",Student[i].marks);
	}
}
