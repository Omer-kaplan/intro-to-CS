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
	
	int mat1[3][N] ={{ 2, -3, 7, 4, 4 },
			{ 1, 5, 4, 9, -5 },
			{ 3, 33, 1, 1, 1 }};
		
	int mat2[4][N] ={{ 5, -7, 2, 9,4 },
			{ 3, -5, 6, 9, 4 },
			{ -3, -2, 5, 0, 0 },
			{ -7, 0, -6, 9, 3 }};
			
	char *inStr1; 
    char *outStr1;
	int a1[6] = {9,	2,	4,	6,	1,	3};
	int a2[6] = {0,0,0,0,0,1};
	int a3[6] = {9,9,9,9,9,9};
	int res;
	
	//1
	crossSort(mat1, 3);
	if(mat1[0][1] != 2)
		printf("crossSort function is wrong for train1_1 (-3)\n");
	if(mat1[1][3] != 1)
		printf("crossSort function is wrong for train1_2 (-3)\n");
	if(mat1[2][3] != 3)
		printf("crossSort function is wrong for train1_3 (-3)\n");
	
	crossSort(mat2, 4);
	if(mat2[0][2] != 4)
		printf("crossSort function is wrong for train1_4 (-3)\n");
	if(mat2[2][2] != 0)
		printf("crossSort function is wrong for train1_5 (-4)\n");
	if(mat2[3][3] != -6)
		printf("crossSort function is wrong for train1_6 (-4)\n");
	/*
	// 2
	inStr1 = "This is an example!";
	outStr1 = revWord(inStr1);
	if (strcmp(outStr1, "sihT si na elpmaxe!")!=0)
		printf("revWord function is wrong for train2-1  (-7)\n");
	
	inStr1 = "Hi, What's up?";
	outStr1 = revWord(inStr1);
	if (strcmp(outStr1, "iH, tahW's pu?")!=0)
		printf("revWord function is wrong for train2-2  (-7)\n");
	
	inStr1 = "This is an example!123abc";
	outStr1 = revWord(inStr1);
	if (strcmp(outStr1, "sihT si na elpmaxe!123cba")!=0)
		printf("revWord function is wrong for train2-3  (-6)\n");
	
    // 3 
	res=MultEven(a1, 6);
	if(count1<2)
        printf(" MultEven function is not recursive (-7)\n");
    else{
       if (res!=48)
			printf("MultEven function is wrong for train3_1  (-7)\n");
    }
	res=MultEven(a2, 6);
	if(count1<2)
        printf(" MultEven function is not recursive (-7)\n");
    else{
       if (res!=0)
			printf("MultEven function is wrong for train3_2  (-7)\n");
    }
	res=MultEven(a3, 6);
	if(count1<2)
        printf(" MultEven function is not recursive (-6)\n");
    else{
       if (res!=0)
			printf("MultEven function is wrong for train3_3  (-6)\n");
    }
	*/
	//4
	printf("Question 4 will be checked manually, don't worry (-40)\n");
	printf("done");
    return 0;
}
