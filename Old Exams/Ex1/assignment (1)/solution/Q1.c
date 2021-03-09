#include "exam.h"


int sumRow(int arr_in[][M], int row)
{
	int sum = 0, i;
	for (i = 0; i < M; i++)
		sum += arr_in[row][i];

	return sum;
}
int sumCol(int arr_in[][M], int col, int numRows)
{
	int sum = 0, i;
	for (i = 0; i < numRows; i++)
		sum += arr_in[i][col];

	return sum;
}


void calcSum(int arr_in[][M], int arr_sum[][M], int rows)
{
	int i, j, row_i;
	for (i = 0; i < rows; i++)
	{
		row_i = sumRow(arr_in, i);
		for (j = 0; j < M; j++)
		{
			arr_sum[i][j] = row_i;
			arr_sum[i][j] += sumCol(arr_in, j, rows);
			arr_sum[i][j] -= 2 * arr_in[i][j]; //subtracting two times the element that counts in rows and columns
		}
	}
}
