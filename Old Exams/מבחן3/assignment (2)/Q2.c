#include <stdlib.h>
#include <string.h>
#include "exam.h"

/*int longestPalindromeSubstring(char *str)
{
    int maxLength = 1;  // The result (length of LPS) 
    int len = strlen(str);
    int left, right;

    for (int i = 1; i < len; ++i)
    {
        left = i - 1;
        right = i;
        while (left >= 0 && right < len && str[left] == str[right])
        {
            if (right - left + 1 > maxLength)
            {
                maxLength = right - left + 1;
            }
            --left;
            ++right;
        }

        left = i - 1;
        right = i + 1;
        while (left >= 0 && right < len && str[left] == str[right])
        {
            if (right - left + 1 > maxLength)
            {
                maxLength = right - left + 1;
            }
            --left;
            ++right;
        }
    }

    return maxLength;
}
*/

int longestPalindromeSubstring(char* str)
{
    int i, left, right, maxLen = 1, count;
    int size = strlen(str);

    for (i = 0; i < size - 1; i++)
    {
        if (str[i] == str[i + 1]) // is even pal
        {
            count = 0, right = i + 1, left = i;
            while (left >= 0 && right < size && str[left] == str[right])
            {
                count += 2;
                left--, right++;
            }
            if (count > maxLen)
                maxLen = count;
        }
        if (str[i] == str[i + 2]) // is odd pal
        {
            count = 1, right = i + 2, left = i;
            while (left >= 0 && right < size && str[left] == str[right])
            {
                count += 2;
                left--, right++;
            }
            if (count > maxLen)
                maxLen = count;
        }
    }
    return maxLen;
}
