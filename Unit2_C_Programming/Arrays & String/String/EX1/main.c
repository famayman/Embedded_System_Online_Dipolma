#include "stdio.h"
void main ()
{
	char text[100],Character;
	int Length = 0,Frequency = 0;
	printf("Enter a string: ");
	fflush(stdin);fflush(stdout);
	gets(text);
	printf("Enter a character to find frequency: ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&Character);
	for(int i = 0;text[i] != 0 ;i++)
	{
		Length++;
	}
	for(int i= 0 ; i< Length;i++)
	{
		if(Character == text[i])
			Frequency++;
	}
	printf("Frequency of %c = %d",Character,Frequency);

}

