#include <stdlib.h>
#include <string.h>
#include "exam.h"
#pragma warning(disable:4996)


int inKeyword(char c, char* str)
{
	while (*str)
	{
		if (c == *str)
			return 1;
		str++;
	}
	return 0;
}

void create_substitutor(char* keyword, char* subst)
{
	int indx = strlen(keyword);
	char c;

	strcpy(subst, keyword);

	for (c = 'A' ; c <= 'Z'; c++)
	{
		if (!(inKeyword(c, keyword))) // C not in Str
			subst[indx++] = c;

	}
	subst[26] = '\0';
}