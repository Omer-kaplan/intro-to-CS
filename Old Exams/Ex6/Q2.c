#include <stdlib.h>
#include <string.h>
#include "exam.h"

void TransRev(char* str, int lastIDX, int counter, char* newArr)
{
	int m = counter + lastIDX - 1;
	int i = lastIDX;
	int run = 0;
	for (;run < counter; i++, m--, run++)
		newArr[i] = str[m];
}

char *revWord(char inStr[])
{
	char* newWord = (char*)calloc(strlen(inStr) + 1, sizeof(char));
	int count = 0, i = 0, j = 0, lastIndx = 0;
	while (inStr[i])
	{
		// if isLetter and not blink or other char
		if ((inStr[i] >= 'A' && inStr[i] <= 'Z') || (inStr[i] >= 'a' && inStr[i] <= 'z'))
		{
			i++, count++;
		}
		else if (count != 0) // Blink and there are words which need to reverse
		{
			TransRev(inStr, lastIndx, count, newWord);
			count = 0, j = i, lastIndx = i;
		}
		else // Some char or blink which need to be copied
		{
			newWord[j++] = inStr[i++];
			lastIndx++;
		}
	}
	if (count != 0) // The end and there is a word to reverse
	{
		TransRev(inStr, lastIndx, count, newWord);
		count = 0, j = i, lastIndx = i;
	}
	newWord[i] = '\0';

	return newWord;
}
