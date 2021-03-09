#include "exam.h"

int numberOfSmallLetterWords(char* str)
{
	int numWords = 0;
	char* s = str;
	
	while (*s && (*s == ' '))
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
}

unsigned int setBitByIndex(unsigned int num, int index)
{
    char mask = 0x1;
    mask <<= index;
    return(num|=mask);
}
