#include "stdio.h"
struct Semployee_info
{
	char *Name;
	int ID;
};
int main()
{
	int i;
	struct Semployee_info employee[3]={{"Fam",100},{"Alex",101},{"Ali",102}};
	struct Semployee_info(*arr[]) = {&employee[0],&employee[1],&employee[2]};
	for(i = 0 ; i <3;i++)
	{
		printf(" Employee Name :  %s \n",(*(arr+i))->Name);
		printf(" Employee ID   :  %d \n",(*(arr+i))->ID);
	}
}
