#include "exam.h"

/*int TakeLastN(int num, int n)
{
	/********Do Not Change!!!*****
	fx1(); // do not change!!!
	/*****************************
	int tempNum;

	if (num == 0 && n > 0)
		return -1;
	
	if (n == 0)
		return 0;
	
	tempNum = TakeLastN(num / 10, n -1);

	if (tempNum != -1)
	{
		return tempNum * 10 + num % 10;
	}

    return -1;
}*/


int TakeLastN(int num, int n)
{
	fx1();

	if (num == 0 && n >= 1)
		return -1;

	if (n == 1)
		return num % 10;

	int newNum = TakeLastN(num / 10, n - 1);
	
	if (newNum == -1)
		return -1;
	
	return newNum * 10 + num % 10;
}


void ChangeFrame(int mat[N][N],int rowCol, int size)
{
	/********Do Not Change!!!*****/
	fx2(); // do not change!!!
	/*****************************/
	int tmp, i;
	if (rowCol >= size)
		return;
	if (size <= 1)
		return;
	for (i = rowCol; i < size; i++)
	{
		tmp = mat[rowCol][i];
		mat[rowCol][i] = mat[i][rowCol];
		mat[i][rowCol] = tmp;
	}
	ChangeFrame(mat, rowCol + 1, size);
}