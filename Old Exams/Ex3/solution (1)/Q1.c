#include "exam.h"


// Function to shift first k elements of each row of matrix. 
void ShiftMatrixByK( int mat[N][N], int k )
{
	int i, j, m, tmp;
	if( k > N || k < 1 )
		return;

	for( i = 0; i < N; ++i )//run over the rows
	{
		for( m = 0; m < N - k; ++m )//run N-K times (how many shifts needed)
		{
			for( j = 0; j < N - 1; ++j )//run over the columns and shift by 1
			{
				tmp = mat[i][0];
				mat[i][0] = mat[i][( j + 1 ) % N];
				mat[i][( j + 1 ) % N] = tmp;
			}
		}
	}
}
