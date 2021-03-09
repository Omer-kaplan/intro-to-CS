#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exam.h"

int count1=0; // do not change!
int count2=0; // do not change!

void fx1(){
    count1++;
}
void fx2(){
    count2++;
}
int main()
{
	// 1
	int s1[3][4] = { { 1,3,5,13 },{ 6,8,1,7 },{ 9,0,7,2 } };
	int s2[2][4] = { { 2,8,14,56 },{ 4,6,8,12 } };
	
	int res1[3][4];
	int res2[2][4];
	
	calcSum(s1, res1, 3);
	if(res1[1][2] != 33)
		printf("calcSum function is wrong for train1_1 (-10)\n");

	calcSum(s2, res2, 2);
	if (res2[0][3] != 36)
		printf("calcSum function is wrong for train1_2 (-10)\n");

    printf("\nChecked -1-\n");

	// 2
	char str1[50] = "Israel";
	char str2[50] = "C is The Best";
	char str4[50] = "Have A Nice  Day";
	char* str;
	
    if(strcmp("Israel",removeBlanks(str1))!=0)
        printf("removeBlanks function is wrong for test2-1a  (-1)\n");

	str = removeBlanks(str2);
	if(str != str2)
		printf("removeBlanks function is wrong for test2-1b  (-4)\n");
	if(strcmp("CisTheBest", str2) != 0)
		printf("removeBlanks function is wrong for test2-1b  (-1)\n");
    if(strcmp("HaveANiceDay",removeBlanks(str4))!=0)
        printf("removeBlanks function is wrong for test2-1d (-1)\n");
	
	/* 2: BIT WISE
	if (getBitByIndex(6, 2)!=1)
        	printf("getBitByIndex function is wrong for train2-2a (-2)\n");
	if (getBitByIndex(6, 3)!=0)
        	printf("getBitByIndex function is wrong for train2-2b (-2)\n");

            */
    printf("\nChecked -2-\n");
    // 3 
    toStart(45, 123);
    
    if(count1<2)
        printf("toStart function is not recursive (-10)\n");
    else{
        if(toStart(45, 123)!=12345)
            printf("toStart function is wrong for train3-1a (-2)\n");
        if(toStart(21, 12)!=1221)
            printf("toStart function is wrong for train3-1b (-2)\n");
        if(toStart(12345, 6)!=612345)
            printf("toStart function is wrong for train3-1c (-2)\n");   
    }

    merge(45, 123);
    if(count2<2)
        printf("merge function is not recursive (-10)\n");
    else{
        if(merge(45, 123)!=12435)
            printf("merge function is wrong for train3-2a (-2)\n");
        if(merge(21, 12)!=1221)
            printf("merge function is wrong for train3-2b (-2)\n");
        if(merge(12345, 67)!=1236475)
            printf("merge function is wrong for train3-2c (-2)\n");   
     }
    
    printf("\nChecked -3-\n");

	printf("\nQuestion 4 will be checked manually, don't worry (-35)\n");
	printf("\ndone\n");
    return 0;
}
