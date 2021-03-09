
#include "exam.h"

/*int numberOfSmallLetterWords(char* str)
{
	int numWords = 0;
	char* s = str;

	while (*s && (*s == ' '))
	{
		s++;
	}

	while (*s)
	{
		int flag = 1;
		while (*s && (*s != ' ') && (flag))
		{
			if (*s < 'a' || *s > 'z')
				flag = 0;
			s++;
		}
		if (flag)
		{
			++numWords;
		}
		else
		{
			while (*s && (*s != ' '))
			{
				s++;
			}
		}
		while (*s && (*s == ' '))
		{
			s++;
		}
	}
	return numWords;
}
*/

int isSmall(char* str)
{
	int i = 0;
	while (str && str[i] != ' ')
	{
		if (str[i] < 'a' || str[i] > 'z')
		{
			return 0;
		}
		i++;
	}
	return 1;
}
int numberOfSmallLetterWords(char* str)
{
	int i = 0;
	int size = strlen(str);
	int count = 0;

	while (i < size) {
		while (str && str[i] == ' ')
			i++;

		int iSSmall = isSmall(str + i);
		if (iSSmall)
			count++;
		
		while (i < size && (str[i] != ' '))
			i++;
	}
	return count;
}


unsigned int setBitByIndex(unsigned int num, int index)
{
	return 0; //fill the function code and change
}
/*
* 	while (*s && (*s == ' '))
		s++;
	while (*s)
	{
		int flag = 1;
		while (*s && (*s != ' ') && flag)
		{
			if ((*s < 'a') || (*s > 'z'))
				flag = 0;
			else s++;
		}
		if (flag)
			numWords++;
		else
			while (*s && (*s != ' '))
				s++;

		while (*s && (*s == ' '))
			s++;
	}
	return numWords;
*/