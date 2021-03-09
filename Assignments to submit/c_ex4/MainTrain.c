/*Name: Omer kaplan
ID: 208278036
Date: 16/12/20
Goal: This main checks the 4 functions*/

#include "Util.h"
#include <stdio.h>
#include <math.h>

int main()
{
	// Variables for Q-1
	int arr[NAMES][GRADES] = { { 76, 88, 92, 50, 90 }, { 100, 67, 88, 99, 56 },
	{ 0, 56, 45, 34, 60 } };

	//Variables for Q-2
	int arr1[SIZE1] = { 0,1,3,9,10,11,30,35 };
	int arr2[SIZE2] = { 1,6,9,10,30,39 };
	int arr3[SIZE2] = { 2,3,4,5,8,11 };
	
	//Variables for Q-3
	int mat1[ROWS][COLS] = { { 0, 1, 1, 0, 0 }, { 0, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 0 }, { 0, 0, 1, 0, 0 } };
	int mat2[ROWS][COLS];

	printf("Test Start\n");
	
	//---------------------------Part A---------------------------/
	printf("\nPart A - Avg\n");
	if ((int)Avg(arr) != 66)
		printf("your Avg function is wrong (-20)\n");
	
	//---------------------------Part B---------------------------/
	printf("\nPart B - diff\n");
	if (diff(arr1, SIZE1, arr2, SIZE2) != 6)
		printf("your diff(arr1,SIZE1, arr2, SIZE2) function is wrong (-10)\n");
	if (diff(arr1, SIZE1, arr1, SIZE1) != 0)
		printf("your diff(arr1, SIZE1, arr1, SIZE1) function is wrong (-10)\n");
	if (diff(arr2, SIZE2, arr3, SIZE2) != 12)
		printf("your diff(arr1, SIZE1, arr1, SIZE1) function is wrong (-10)\n");

	//---------------------------Part C_a---------------------------//
	printf("\nPart C_a - computeDominance\n");
	computeDominance(mat1, mat2, ROWS);
	if (mat2[1][2] != 3)
		printf("your computeDominance(mat1, mat2, ROWS) function is wrong (-10)\n");
	if (mat2[2][3] != 1)
		printf("your computeDominance(mat1, mat2, ROWS) function is wrong (-10)\n");
	/*for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("\t%d", mat2[i][j]);
		}
		printf("\n");
	}*/
	
	//---------------------------Part C_b---------------------------/
	printf("\nPart C_b - max_rect_at_point\n");
	if (max_rect_at_point(mat1, mat2, 0, 1) != 6)
		printf("your max_rect_at_point(mat1, mat2,0,1) function is wrong (-10)\n");
	if (max_rect_at_point(mat1, mat2, 0, 0) != 0)
		printf("your max_rect_at_point(mat1, mat2,0,0) function is wrong (-10)\n");
	if (max_rect_at_point(mat1, mat2, 1, 2) != 4)
		printf("your max_rect_at_point(mat1, mat2, 1, 2) function is wrong (-10)\n");
	if (max_rect_at_point(mat1, mat2, 3, 2) != 1)
		printf("your max_rect_at_point(mat1, mat2, 3, 2) function is wrong (-10)\n");
	/*---------------------------Finish---------------------------*/
	
	printf("\n\ndone\n");

	/* Test *Pointers
	int* pY = NULL; // Pointer
	int y = 10; // variable
	pY = &y; // y's memory place
	printf("\n y ==  %d", y);
	printf("\n &y == %d", &y);
	printf("\n pY == %d", pY);
	printf("\n &pY == %d", &pY);
	printf("\n Changing y -> 100");
	*pY = 100; // Direct to the real value in the memors cell
	printf("\n *pY value == %d", *pY);
	printf("\n\n");
	*/
	system("pause");
}