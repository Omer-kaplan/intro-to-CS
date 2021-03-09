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
	
	int mat1[N][N]= {{0,0,0,0,8},
                     {0,0, 0,0,	0},
                     {0,0,3,0,0},
                     {0,-7,0,0,0},
                     {2,0,0,0,0}};
                     
    int mat2[N][N]= {{0,0,0,0,0},
                     {0,4, 0,0,	0},
                     {0,0,0,0,0},
                     {0,0,0,7,0},
                     {0,0,0,0,0}};
					 
	char str1[50] = "   it is a sMall   World   after all!";
	char str2[50] = "   What A wonDERful          Day!";
	
	int mat3[N][N] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},
		{16,17,18,19,20},{21,22,23,24,25}};
  
	// 1
    printf("\n\nQues1 \n");
  	if (isDiagonal(mat1)!=0)
		printf("isDiagonal function is wrong for train1_1 (-10)\n");

	if (isDiagonal(mat2)!=1)
		printf("isDiagonal function is wrong for train1_2 (-10)\n");
	// 2
    printf("\nQues2 \n");
	if(numberOfSmallLetterWords(str1)!=4)
        printf("numberOfSmallLetterWords function is wrong for train2-1a  (-5)\n");

    if(numberOfSmallLetterWords(str2)!=0)
        printf("numberOfSmallLetterWords function is wrong for train2-1b  (-5)\n");
		
	/* 2: BIT WISE
	if (setBitByIndex(8, 2)!=12)
        	printf("setBitByIndex function is wrong for train2-2a (-5)\n");
	if (setBitByIndex(8, 3)!=8)
        	printf("setBitByIndex function is wrong for train2-2b (-5)\n");	
        */

	// 3: TakeLastN
    printf("\nQues3 \n");
	TakeLastN(45336764,5);
    
    if(count1<4)
        printf("TakeLastN function is not recursive (-12)\n");
    else{
        if(TakeLastN(45336764, 3)!=764)
            printf("TakeLastN function is wrong for train3-1a (-4)\n");
        if(TakeLastN(345, 4)!=-1)
            printf("TakeLastN function is wrong for train3-1b (-4)\n");
        if(TakeLastN(123, 3)!=123)
            printf("TakeLastN function is wrong for train3-1c (-4)\n");   
    
    }
	//3: ChangeFrame
	ChangeFrame(mat3,0,4);
    if(count2<3)
        printf("ChangeFrame function is not recursive (-13)\n");
    else{
        if(mat3[2][1]!=8)
            printf("ChangeFrame function is wrong for train3-2a (-5)\n");
		if(mat3[1][3]!=17)
            printf("ChangeFrame function is wrong for train3-2b (-4)\n");
		if(mat3[3][4]!=20)
            printf("ChangeFrame function is wrong for train3-2c (-4)\n");
       
     }	
	 
	printf("\nQuestion 4 will be checked manually, don't worry (-35)\n");
	printf("done\n\n");
    return 0;
}
