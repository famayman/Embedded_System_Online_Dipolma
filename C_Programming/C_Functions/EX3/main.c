#include "stdio.h"
void reverse (void);
void main(void)
{
	printf("Enter a sentence : ");
	fflush(stdin);fflush(stdout);
	reverse();
}
void reverse ()
{
	char c;

	scanf("%c",&c);
	if (c != '\n')
	{
		reverse();
		printf("%c",c);
	}
}
