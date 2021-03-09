#include "exam.h"
void upSort(int arr[N], int size)
{
	// sort from the smallest to biggest
	int i, j, tmp, lng = size;
	for (i = lng - 1; i > 0; i--)
		for (j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
}
void downSort(int arr[N], int size)
{
	// Sort from the bigest to smallest
	int i, j, tmp, lng = size;
	for (i = lng - 1; i > 0; i--)
		for (j = 0; j < i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
}
void crossSort(int mat[][N], int numRows)
{
	for (int i = 0; i < numRows; i += 2)
		upSort(mat[i], N);
	for (int i = 1; i < numRows; i += 2)
		downSort(mat[i], N);

	return;
}