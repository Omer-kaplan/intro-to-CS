#include "exam.h"
#include <stdio.h>

/*
void upSort(int mat[], int size)
{
	int i, j, tmp;
	for(i = size -1; i>0; i--)
		for(j = 0; j < i; j++)
			if (mat[j] > mat[j + 1])
			{
				tmp = mat[j];
				mat[j] = mat[j + 1];
				mat[j + 1] = tmp;
			}

}
void downSort(int mat[], int size)
{
	int i, j, tmp;
	for(i = size - 1; i > 0; i--)
		for(j = 0; j < i; j++)
			if (mat[j] < mat[j + 1])
			{
				tmp = mat[j];
				mat[j] = mat[j + 1];
				mat[j + 1] = tmp;
			}
}

void crossSort(int mat[][N], int numRows)
{
	int i;
	for (i = 0; i < numRows; i += 2)
		upSort(mat[i], N);
	for (i = 1; i < numRows; i += 2)
		downSort(mat[i], N);

}*/

void upSort(int arr[N])
{
	int tmp;

	for (int i = N - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
}
void downSort(int arr[N])
{
	int tmp;

	for (int i = N - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (arr[j] < arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
}

void crossSort(int mat[][N], int numRows)
{
	int i;
	for (i = 0; i < numRows; i++)
		if (i % 2 == 0)
			upSort(mat[i]);
		else
			downSort(mat[i]);
}