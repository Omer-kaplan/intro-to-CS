/*  A

#include "exam.h"
 

int TakeLastN(int num, int n)
{
	int next;
	fx1();
	if (num == 0 && n > 0)
	{
		return -1;
	}
	if (n == 0)
	{
		return 0;
	}
	next = TakeLastN(num / 10, n-1);

	if (next != -1)
	{
		return next * 10 + num % 10;
	}
	return -1;
}

/* B  *
void ChangeFrame(int mat[N][N],int rowCol, int size)
{
	int tmp,i;
	fx2();
	if(rowCol >= size)
		return;
	if(size <= 1)
		return;
	for(i=rowCol;i<size;i++)
	{
		tmp = mat[rowCol][i];
		mat[rowCol][i] = mat[i][rowCol];
		mat[i][rowCol] = tmp;	
	}
	ChangeFrame(mat,rowCol+1,size);
}
*/