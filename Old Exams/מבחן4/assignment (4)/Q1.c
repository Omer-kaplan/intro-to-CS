#include "exam.h"

void ShiftMatrixByK(int mat[N][N], int k)
{
	int tmp;
	if (!(k > N || k < 1)) // isLegal
	{
		while (k > 0)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N - 1; j++)
				{
					if (j == 0)
						tmp = mat[i][0];
					int subTmp = mat[i][j];
					mat[i][j] = mat[i][j + 1];
					mat[i][j + 1] = subTmp;
				}
				mat[i][N - 1] = tmp;
			}
			k--;
		}
	}
	return;
}
