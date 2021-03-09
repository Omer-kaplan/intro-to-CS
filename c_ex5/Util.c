#include "Util.h"

/* ------------------------------------------------------------------ /
*  Helpng comparing function
*  Q1 -Aa
int compareStr(void *p_a, void *p_b)
{
	return strcmp(p_a, p_b);
}
*/
// Q1-A sorts the StringArr Lix.
void SortByAB(char matStr[][COLS], int rows, int cols)
{
	/* int size_arr = sizeof(matStr) / sizeof(matStr[0]);
	/--- Option 1 is doing CompareFun and use qsort() ---/
	qsort(matStr, rows, cols, compareStr);

	/*--- Option 2 is to use the function we made in class  ---> use for hagasha */
	int i, j, sorted = 0;
	char temp[COLS];
	for (i = 0; i < rows - 1 && !sorted; ++i)
	{
		sorted = 1;
		for (j = 0; j < rows - 1 - i; ++j)
		{
			if (strcmp(matStr[j], matStr[j + 1]) > 0)
			{
				strcpy(temp, matStr[j]); // strcpy_s(temp, COLS - 1, matStr[j]);
				strcpy(matStr[j], matStr[j + 1]);
				strcpy(matStr[j + 1], temp);
				sorted = 0;
			}
		}
	}
}

/* ------------------------------------------------------------------ */
// Q1-B ---> uses strlen() to determain which longer
void SortByLenght(char matStr[][COLS], int rows, int cols)
{
	int i, j, sorted = 0;
	char temp[COLS];
	for (i = 0; i < rows - 1 && !sorted; i++)
	{
		sorted = 1;
		for (j = 0; j < rows - 1 - i; j++)
		{
			if (strlen(matStr[j]) > strlen(matStr[j+1]))
			{
				strcpy(temp, matStr[j]); // strcpy_s(temp, COLS - 1, matStr[j])
				strcpy(matStr[j], matStr[j + 1]);
				strcpy(matStr[j + 1], temp);
				sorted = 0;
			}
		}
	}
}

/* ------------------------------------------------------------------ */
// Q2
void AnalyseArray(int* arr, int size, double* avg, int* startIdx) // arr, its size, avg of sub arr and its start index
{
	int* p_Arr = arr;
	int* p_EndArr = arr + size;
	double* p_Avg = avg;
	int* s_indx = startIdx;
	int count = 1;
	int sum = 0;
	int longest_sub_arr = 1;
	int j;
	double tmp_avg = 0;
	*p_Avg = arr[0];
	*s_indx = 0; 
	for (int i = 0; i < size - 1; ++i) // {-1, 5, 9, 17, 6, 3, 1, 1, 1, 0}
	{
		if (*(p_Arr + i) > *(p_Arr + i + 1))// recognize minimal sub arr
		{
			j = i;
			while (*(p_Arr + j) > *(p_Arr + j + 1) && (p_Arr + j < p_EndArr))
			{
				int tmp = 0;
				++count;
				if (*(p_Arr + j + 1) <= *(p_Arr + j + 2) && (p_Arr + j + 1 < p_EndArr))
				{
					sum += *(p_Arr + j + 1);
				}
				sum += *(p_Arr + j);
				++j;
			}
			if (count > longest_sub_arr)
			{
				tmp_avg = (double)sum / count;
				*p_Avg = tmp_avg;
				longest_sub_arr = count;
				*s_indx = i;
			}
			i = j;
			sum = 0;
			count = 1;
		}
	}
}

/* ------------------------------------------------------------------ */
// Q3
int Separate(char* str, char separator, char** words, int* lengths) // gets pointer to a string, seperator, pointers arr, pointer to a arr.
{
	/* Vars
	char* pStr = str; // The main string
	char** pWords = words; // The words pointer pointers arr
	int* pLen = lengths; // Holds the words length in each cell
	int wordsCount = 0; // Calc and returns how many vars
	int strLength = strlen(pStr); // Run for this size
	int isWord = 0, j = 0;

	for (int i = 0; i < strLength;)
	{
		if ( *(pStr + i)!= separator ) // is A-Za-z to check?
		{
			isWord = 1;
			pWords[j] = (pStr+i); // send the location?
			++wordsCount;
			while (isWord)
			{
				++i;
				if (separator == (*(pStr + i)))
				{
					isWord = 0;
				}
				else
				{
					++wordsCount;
				}
			}
			*(pLen + j) = wordsCount;
			wordsCount = 0;
			++j;
		}
		else {
			++i;
		}
	}
	// size_t  hMany = sizeof(pLen) / sizeof(pLen[0]);
	// printf("\nThere are %d cells in length" , j);
	return j;
	*/
	
	
	// Vars 
	char* pStr = str; // The String
	char** pWords = words; // has the pointers for word begining
	int* pLen = lengths; // holds every words length
	int charCounter = 0; // counts the ch in word
	int j = 0; // index for words and length
	int i = 0; // index for the main run
	int strLen = strlen(pStr);
	
	while (i < strLen)
	{
		if (*(pStr + i) != separator) // Not the separator
		{
			if (i == 0) 
			{
				pWords[j] = (pStr + i);
				while (*(pStr + i) != separator && i < strLen)
				{
					charCounter++;
					i++;
				}
				pLen[j] = charCounter;
				charCounter = 0;
				++j;
			}
			if (*(pStr + i - 1) == separator) // after the sep.
			{
				pWords[j] = (pStr + i);
				while (*(pStr + i) != separator && i < strLen)
				{
					charCounter++;
					i++;
				}
				pLen[j] = charCounter;
				charCounter = 0;
				++j;
			}
		}
		else
		{
			++i;
		}
	}
	return j;
	}


/* ------------------------------------------------------------------ */
// Q4
char* ReverseWords(char* words)
{
	char* pWords = words;
	int size = strlen(pWords);
	int i = size - 1, j = 0, last, start = size - 1;
	char* pRevWords = malloc((size + 1) * sizeof(char));
	if (NULL == pRevWords)
	{
		return NULL;
	}
	while (i >= 0)
	{
		if (*(pWords + i) != ' ')
		{
			last = i;
			while ((pWords[i] != ' ') && (i >= 0))
			{
				if (pWords[i - 1] == ' ')
				{
					start = i;
					--i;
				}
				else
				{
					--i;
				}
			}
			if (i == -1)
			{
				start = 0;
			}
			for (j; (j < size) && (start <= last); ++j)
			{
				pRevWords[j] = pWords[start];
				start++;
			}
			if (j == size)
			{
				pRevWords[size] = '\0';
			}
			else
			{
				pRevWords[j] = ' ';
				++j;
			}
		}
		else
		{
			--i;
		}
	}
	return pRevWords;
}