#include "stdio.h"
int  main()
{
	char *ptr,arr[26];
	int i;
	for(i = 0;i<26;i++)
	{
		arr[i]=i+'A';
	}
	ptr=arr;
	for(i = 0;i<26;i++)
	{
		printf("%c ",*ptr);
		ptr++;
	}
	return 0;
}
