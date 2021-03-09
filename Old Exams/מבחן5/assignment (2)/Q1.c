#include "exam.h"
/*int IsPerfect(int mat[][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (mat[i][j] < 1 || mat[i][j] > N)
				return 0;
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		int row_arr[N+1], col_arr[N+1];
		for (int j = 0; j <= N; j++)
			row_arr[j] = col_arr[j] = 0;
		for ( int z = 0 ; z <N; z++)
		{
			row_arr[mat[i][z]]++;
			col_arr[mat[z][i]]++;
		}
		for (int z = 1; z <= N; z++)
			if (row_arr[z] == 0 || col_arr[z] == 0)
				return 0;
	}
	return 1;
}
*/

int IsPerfect(int mat[][N])
{
	// Checks every row if num > N
	
	// set col arr and check for each col
	int i, j, m;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (mat[i][j] > N || mat[i][j] < 1)
				return 0;
	int times = N;
	j = 0;
	while (times > 0) {
		// Check Foreach Row
		int row_Arr[N + 1] = { 0 };
		for (i = 0; i < N; i++) // Sets count
		{
			row_Arr[mat[j][i]]++;
		}
		for (m = 1; m <= N; m++) // Checks every count
		{
			if (row_Arr[m] != 1)
				return 0;
		}
		times--;
		j++;
	}

	// Same check for cols
	times = N;
	j = 0;
	while (times > 0) {
		int col_Arr[N + 1] = { 0 };
		for (i = 0; i < N; i++) // Sets count
		{
			col_Arr[mat[i][j]]++;
		}
		for (m = 1; m <= N; m++) // Checks every count
		{
			if (col_Arr[m] != 1)
				return 0;
		}
		times--;
		j++;
	}
	return 1;
}