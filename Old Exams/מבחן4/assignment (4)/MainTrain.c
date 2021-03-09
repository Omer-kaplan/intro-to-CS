#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exam.h"

int count1=0; // do not change!

void fx1(){
    count1++;
}

int main()
{
	//1
	int mat1[N][N] ={{ 1, 2, 3, 4 },
			{ 5, 6, 7, 8 },
			{ 9, 10, 11, 12 },
			{ 13, 14, 15, 16 }};
	int mat2[N][N] ={{ 1, 2, 3, 4 },
			{ 5, 6, 7, 8 },
			{ 9, 10, 11, 12 },
			{ 13, 14, 15, 16 }};
	printf("\nChecking (1)...\n");
	ShiftMatrixByK(mat1, 1);
	if(mat1[0][3] != 1)
		printf("ShiftMatrixByK function is wrong for train1_1 (-4)\n");
	if(mat1[1][3] != 5)
		printf("ShiftMatrixByK function is wrong for train1_2 (-4)\n");
	if(mat1[3][2] != 16)
		printf("ShiftMatrixByK function is wrong for train1_3 (-4)\n");

	ShiftMatrixByK(mat2, 2);
	if(mat2[0][2] != 1)
		printf("ShiftMatrixByK function is wrong for train1_4 (-4)\n");
	if(mat2[1][3] != 6)
		printf("ShiftMatrixByK function is wrong for train1_5 (-4)\n");
	printf("Done (1)!\n\n");
	
	// 2
	printf("\nChecking (2)...\n");
	if(longestPalindromeSubstring("toyota")!=5)
        printf("longestPalindromeSubstring function is wrong for train2-1  (-7)\n");
	if(longestPalindromeSubstring("pleaseneveroddorevenplease")!=14)
        printf("longestPalindromeSubstring function is wrong for train2-2  (-7)\n");
	if(longestPalindromeSubstring("aba")!=3)
        printf("longestPalindromeSubstring function is wrong for train2-3  (-6)\n");
	
	printf("Done (2)!\n\n");
    // 3 
	printf("\nChecking (3)...");
	SpecialSeries(8);
   
    if(count1<7)
        printf(" SpecialSeries function is not recursive (-20)\n");
    else{
        if(SpecialSeries(4)!=6)
            printf("SpecialSeries function is wrong for train3-1 (-5)\n");
        if(SpecialSeries(5)!=4)
            printf("SpecialSeries function is wrong for train3-2 (-5)\n");
		if(SpecialSeries(2)!=2)
            printf("SpecialSeries function is wrong for train3-3 (-5)\n");
		if(SpecialSeries(12)!=71)
            printf("SpecialSeries function is wrong for train3-4 (-5)\n");
    }
	printf("\nDone (3)!\n\n");

	//4
	printf("\nQuestion 4 will be checked manually, don't worry (-40)\n");
	printf("done\n\n");
    return 0;
}
