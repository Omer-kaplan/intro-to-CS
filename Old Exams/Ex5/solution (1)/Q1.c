#include "exam.h"

int IsPerfect(int mat[][N])
{
	int n=N;
	int i,j,row_arr[N+1],col_arr[N+1];
	for(i=0; i<n; i++)	
		for(j=0;j<n;j++)
			if((mat[i][j]<1) || (mat[i][j]>N))
				return 0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)   /*initialize the arrays*/
			row_arr[j] = col_arr[j] = 0;
		for(j=0;j<n;j++)
		{
			row_arr[mat[i][j]]++;
			col_arr[mat[j][i]]++;
		}
		for(j=1;j<=n;j++) 
			if ((row_arr[j]==0) || (col_arr[j]==0))
				return 0;
	}
	return 1;
}

