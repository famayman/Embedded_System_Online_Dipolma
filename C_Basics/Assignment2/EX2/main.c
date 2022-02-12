#include "stdio.h"
void main()
{
	char alphabet;
	printf("Enter an alphabet: ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&alphabet);
	switch(alphabet)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		printf("%c is a vowel.",alphabet);
		break;
	default:
		printf("%c is a consonant. ",alphabet);

	}
}
