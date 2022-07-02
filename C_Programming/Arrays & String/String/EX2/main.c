#include "stdio.h"
void main()
{
	char text[100];
	int Length = 0;
	printf("Enter a String: ");
	fflush(stdin);fflush(stdout);
	gets(text);
	for(int i = 0;text[i] != 0 ;i++)
	{
		Length++;
	}
	printf("Length of string: %d",Length);

}
