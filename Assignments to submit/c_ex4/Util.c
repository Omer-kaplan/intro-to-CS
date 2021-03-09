#include "Util.h"
//-----------------------------------------------------------------------------------------------//
//Q1 Gets 3 names, 5 grades each and returns their Avg grade
float Avg(int mat[][GRADES])
{
	float avg_grade = 0;
	for (int i = 0; i < NAMES; i++)
		for (int j = 0; j < GRADES; j++)
			avg_grade += mat[i][j];
	return (avg_grade / 15);
}

//-----------------------------------------------------------------------------------------------//
//Q2
int diff(int arr1[], int size1, int arr2[], int size2)
{
	int diff_nums = 0;
	int i = 0, j = 0;
	while (i < size1 && j < size2)
	{
		if (arr1[i] > arr2[j])
		{
			diff_nums++;
			j++;
		}
		else if (arr1[i] == arr2 [j])
		{
			i++;
			j++;
		}
		else if (arr1[i] < arr2 [j])
		{
			diff_nums++;
			i++;
		}
	}
	if (i != size1)
	{
		int temp1 = i;
		for (int i = temp1; i < size1; i++)
			diff_nums++;
	}
	if (j != size2)
	{
		int temp2 = j;
		for (int j = temp2; j < size2; j++)
			diff_nums++;
	}
	return diff_nums;
}

//-----------------------------------------------------------------------------------------------//
//Q3-a Gets a mat, runs and sets the right number to the second mat
void computeDominance(int p[][COLS], int d[][COLS], int rows)
{
	int column = sizeof(p[0])/sizeof(p[0][0]);
	for (int i = rows -1; i >= 0; i--)
	{
		for (int j = 0; j < column; j++)
		{
			if (i != rows -1) // if not last row
			{
				if (p[i][j] == 1)
				{
					d[i][j] = (d[i + 1][j]) + 1;
				}
				else
				{
					d[i][j] = 0;
				}
			}
			else // if the last matrix's row
			{
				if (p[i][j] == 1)
				{
					d[i][j] = 1;
				}
				else
				{
					d[i][j] = 0;
				}
			}
		}
	}
}

//-----------------------------------------------------------------------------------------------//
//Q3-b
int max_rect_at_point(int p[][COLS], int d[][COLS], int i, int j)
{
	int columns = sizeof(p[0]) / sizeof(p[0][0]);
	int square_length = d[i][j];
	int square_width = columns;
	int count = 1;
	if (d[i][j] == 0) // if 0 returns 0
		return 0;
	
	int run_times = square_length; // how many times to run
	for (int m = 0; m < run_times; m++) // run the d[i][j] times 
	{
		int n = j;
		for (n; n < columns; n++)
		{
			if (m == 0 && d[i][n] < run_times)
				run_times = d[i][n];
			
			if (n + 1 < columns)
			{
				int next_cell = d[i + m][n + 1];
				if (next_cell != 0)
				{
					if (next_cell < square_length)
						square_length = next_cell;
					
					count++;
				}
			}
		}
		if (count < square_width)
			square_width = count;
		
		count = 1;
	}
	return square_length * square_width;
}
