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
   
	// 1 
    printf("\nChecking -1-\n");
	int arr1[] = {8, 3, 8 , -5, 4, 3, -40, 3, 5};
    int ctr1 = sizeof(arr1)/sizeof(arr1[0]);
    
 	if(maxSum(arr1, ctr1) != 21)
		printf("maxSum function is wrong for train1_1 (-6)\n");

	int arr2[] = {8, 3, 8 , -50, 4, 3, -40};
    int ctr2 = sizeof(arr2)/sizeof(arr2[0]);
    
 	if(maxSum(arr2, ctr2) != 19)
		printf("maxSum function is wrong for train1_2 (-7)\n");

	int arr3[] = {-2, -8, -6};
    int ctr3= sizeof(arr3)/sizeof(arr3[0]);
    
 	if(maxSum(arr3, ctr3) != -2)
		printf("maxSum function is wrong for train1_3 (-7)\n");
    printf("\nChecked -1-\n");
     
	// 2
	
    printf("\n\nChecking -2-\n");
    char str1[] = "I    wish     u    Good   Luck!@";
    
    if (strcmp(cleanExcessBlanks(str1), "I wish u Good Luck!@")!=0)
		printf("cleanExcessBlanks function is wrong for train2-1  (-7)\n");

    char str2[] = "Hi, What's up?";
    
    if (strcmp(cleanExcessBlanks(str2), "Hi, What's up?")!=0)
		printf("cleanExcessBlanks function is wrong for train2-2  (-7)\n");

    char str3[] = "example!123abc";
    
    if (strcmp(cleanExcessBlanks(str3), "example!123abc")!=0)
		printf("cleanExcessBlankschar function is wrong for train2-3  (-6)\n");
    printf("\nChecked -2-\n");


    // 3 
    printf("\n\nChecking -3-\n");
	int a1[7] = {2,7,-5,9,3,2,-5};
    int res = isSuminArr(a1,7,4);
   
    if(count1<3)
        printf("isSuminArr function is not recursive (-7)\n");
    else{
       if (res!=1)
			printf("isSuminArr function is wrong for train3_1  (-7)\n");
    }
	count1 = 0;
	int a2[7] = {2,7,-5,9,3,2,-5};
    res = isSuminArr(a2,7,12);
   
    if(count1<3)
        printf("isSuminArr function is not recursive (-7)\n");
    else{
       if (res!=1)
			printf("isSuminArr function is wrong for train3_2  (-7)\n");
    }
	count1 = 0;	
	int a3[7] = {2,7,-5,9,3,2,-5};
    res = isSuminArr(a3,7,22);
   
    if(count1<3)
        printf("isSuminArr function is not recursive (-6)\n");
    else{
       if (res!=0)
			printf("isSuminArr function is wrong for train3_3  (-6)\n");
    }

    printf("\nChecked -3-\n");
	//4
	printf("\nQuestion 4 will be checked manually, don't worry (-40)\n");
	printf("done\n");
    
     

    return 0;
}
