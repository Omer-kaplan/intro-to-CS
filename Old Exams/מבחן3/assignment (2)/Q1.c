#include "exam.h"

void ShiftMatrixByK(int mat[N][N], int k)
{
	if (k >= 1 && k < N)
	{
		while (k) {
			int length = N;
			int tmp;
			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < length; j++)
				{
					if (j == 0)
						tmp = mat[i][j];
					if (j == (length - 1))
						mat[i][j] = tmp;
					else 
						mat[i][j] = mat[i][j + 1];
				}
			}
			k--;
		}
	}
}
