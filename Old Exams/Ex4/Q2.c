#include <stdlib.h>
#include <string.h>
#include "exam.h"

int longestPalindromeSubstring(char *str)
{ 
	int maxP = 1;
	int len = strlen(str);
	int countEven, countOdd;
	int left, right, righter;
	for (int i = 0; i < len - 2; i++) // for the givven string
	{
		countEven = 0;
		countOdd = 0;
		left = i; right = i + 1;
		if (str[left] == str[right]) // Looking for even max palindrom
		{
			int first = 1;
			countEven += 2;
			while (left >= 0 && right < len && str[left] == str[right])
			{
				if (!(first))
				{
					countEven += 2;
				}
				left--, right++;
				first = 0;
			}
			if (countEven > maxP)
				maxP = countEven;
		}
		left = i; righter = i + 2;
		if (str[left] == str[righter]) // Looking for Odd max palindrom
		{
			int first = 1;
			countOdd = 3;
			while (left >= 0 && righter < len && str[left] == str[righter])
			{
				if (!(first))
				{
					countOdd += 2;
				}
				left--, righter++;
				first = 0;
			}
			if (countOdd > maxP)
				maxP = countOdd;
		}
	}

	return maxP;
}
