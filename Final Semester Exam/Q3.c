#include "exam.h"

int isSuminArr(int arr[], int size, int sum)
{
	/******** DON'T CHANGE ********/
	fx1(); // do not change!!!
	/******************************/

	if (sum == 0 && size == 0)
		return 1;
	if (size <= 0)
		return 0;

	int num1 = isSuminArr(arr, size - 1, sum - arr[size]);
	int num2 = isSuminArr(arr, size - 1, sum);

	return num1 || num2;

}
