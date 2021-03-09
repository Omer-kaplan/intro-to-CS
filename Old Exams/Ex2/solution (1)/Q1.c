#include "exam.h"


int isDiagonal(int mat[N][N])
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if ((mat[i][j] != 0) && (i != j))
				return 0;
	return 1;
}
