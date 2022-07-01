#include "stdio.h"
int main()
{
	int i = 0;
	char str[100],reversed[100],*ptr;
	printf("Input a string : ");
	fflush(stdin);fflush(stdout);
	gets(str);
	printf("Pointer : Print a String  in reverse order :  \n");
	printf("----------------------------------------------\n");
	printf("Input a string : %s \n",str);
	fflush(stdin);fflush(stdout);
	while(str[i] != '\0')
	{
		i++;
	}
	i--;
	ptr=reversed;
	while(i >= 0)
		{
			*ptr=str[i];
			i--;
			ptr++;
		}
	    *ptr = '\0';
		fflush(stdin);fflush(stdout);
        printf("Reverse of the string is : %s ",reversed);
	return 0;
}
