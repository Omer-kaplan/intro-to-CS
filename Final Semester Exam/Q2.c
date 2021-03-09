#include <stdlib.h>
#include <string.h>
#include "exam.h"
int CheckSort(char *str)
{
	int i, size = strlen(str);

	for (i = 0; i < size; i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			return 0;
		}
	}
	return 1;
}

char *cleanExcessBlanks(char *text)
{
	// for the len text, i - j, = str[i], if first blank 1 if another 0...

	int i, j, size;
	int isSorted = 0;
	while (!(isSorted))
	{
		size = strlen(text);
		isSorted = CheckSort(text);
		for (i = 0, j = 0; i < size; i++)
		{
			text[i - j] = text[i];
			if (text[i] == ' ' && text[i + 1] == ' ')
			{
				i++, j++;
			}
		}
		text[i - j] = '\0';
	}
	
	return text;
}
