#include "exam.h"

int justMinus(int arr[], int size)
{
	int i;
	int isPlus = 0;
	for (i = 0; i < size; i++)
	{
		if (arr[i] > 0)
			isPlus = 1;
	}
	if (isPlus) // There are pos. nums
		return 0;
	else
		return 1; // Just Neg. num
}

int maxNum(int arr[], int size)
{
	int maxNum, i;
	maxNum = arr[0];
	for (i = 1; i < size; i++)
	{
		if (arr[i] > maxNum)
			maxNum = arr[i];
	}
	return maxNum;
}

int maxSum(int a[], int n)
{
	// Cases: (1) only minus numbers, (2) starts with minus but has positives, (3) start regular but has minuses
	if (justMinus(a, n))
		return maxNum(a, n);

	// Now search for the max sub sum
	int maxSum = 0, sumChecker = 0, i;

	for(i = 0; i < n; i++)
	{
		//if (a[0] < 0)
			//while (*a < 0)
				//a++, i++;

		sumChecker = sumChecker + a[i];
		if (sumChecker < 0)
			sumChecker = 0;
		if (sumChecker > maxSum)
			maxSum = sumChecker;
	}

	return maxSum;
}