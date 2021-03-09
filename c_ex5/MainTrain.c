#include "Util.h"

int main()
{
	// Variables for Q-1
	char matStr1[ROWS][COLS] = { "yehuda", "galit", "haim", "aviv", "inbal" };
	char matStr2[ROWS][COLS] = { "intro", "to", "cs", "colman", "test" };
	char matStr3[ROWS][COLS] = { "aviv", "amir", "tamar", "yehuda", "galit" };

	// Variables for Q-2
	int arr1[MAX_ARR_SIZE] = { 1, 3, 4, -1, -9, 0 ,1 ,2 };
	int arr2[MAX_ARR_SIZE] = { -1, 5, 9, 17, 6, 3, 1, 1, 1, 0 };
	int arr3[MAX_ARR_SIZE] = { -9, -8, -7, -6, 9, 7, 4, 3, 2, 9 };
	int q1, q2, q3;
	double avg1, avg2, avg3;
	
	// Variables for Q3
	//char str31[MAX_STRING_SIZE] = "--hell-o -world--my-name-is-shlomi"; // 7 words
	char str31[MAX_STRING_SIZE] = "hello -world-my-name-is-shlomi";
	char str32[MAX_STRING_SIZE] = "test for question 2";
	char str33[MAX_STRING_SIZE] = "OnecMorecTest";
	char* words1[MAX_STRING_SIZE];
	char* words2[MAX_STRING_SIZE];
	char* words3[MAX_STRING_SIZE];
	int length1[MAX_STRING_SIZE];
	int length2[MAX_STRING_SIZE];
	int length3[MAX_STRING_SIZE];

	// Variables for Q4
	char str41[MAX_STRING_SIZE] = "There was a cat";
	char str42[MAX_STRING_SIZE] = "cat";
	char str43[MAX_STRING_SIZE] = "Intro to CS Colman";
	char* answer1;
	char* answer2;
	char* answer3;

	printf("Test Start\n");

	/*---------------------------Question 1---------------------------*/
	/*---------------------------Part A---------------------------*/
	printf("\nQuestion 1A - SortByAB\n");
	SortByAB(matStr1, ROWS, COLS);
	if (strcmp(matStr1[0], "aviv") != 0)
		printf("your strcmp(matStr1[0], \"aviv\") answer is wrong (-5)\n");
	SortByAB(matStr2, ROWS, COLS);
	if (strcmp(matStr2[1], "cs") != 0)
		printf("your strcmp(matStr2[1], \"cs\") answer is wrong (-4)\n");
	SortByAB(matStr3, ROWS, COLS);
	if (matStr3[2][2] != 'l')
		printf("your matStr3[2][2] != 'l' answer is wrong (-4)\n");
	/*---------------------------Part B---------------------------*/
	printf("\nQuestion 1B - SortByLength\n");
	SortByLenght(matStr1, ROWS, COLS);
	if (strlen(matStr1[0]) != 4 || strlen(matStr1[1]) != 4)
		printf("your strlen(matStr1[0]) != 4 || strlen(matStr1[1]) != 4 answer is wrong (-4)\n");
	SortByLenght(matStr2, ROWS, COLS);
	if (strlen(matStr2[0]) != 2 || strlen(matStr2[1]) != 2 || strlen(matStr2[2]) != 4)
		printf("your strlen(matStr2[0]) != 2 || strlen(matStr2[1]) != 2 || strlen(matStr2[2]) != 4 answer is wrong (-4)\n");
	SortByLenght(matStr3, ROWS, COLS);
	if (strlen(matStr3[0]) != 4 || strlen(matStr3[2]) != 5)
		printf("your strlen(matStr3[0]) != 4 || strlen(matStr3[2]) != 5 answer is wrong (-4)\n");

	/*if(-1 > -9)
		printf("\n\nTrue\n");
	else
	{
		printf("\n\nFalse\n");
	} */
	/*---------------------------Question 2---------------------------*/
	printf("\nQuestion 2 - AnalyseArray\n");
	AnalyseArray(arr1, 8, &avg1, &q1);
	if (avg1 != -2 || q1 != 2)
		printf("your avg1 != -2 || q1 != 2 answer is wrong (-8)\n");
	AnalyseArray(arr2, 10, &avg2, &q2);
	if (avg2 != 6.75 || q2 != 3)
		printf("your avg2 != 6.75 || q2 != 3 answer is wrong (-8)\n");
	AnalyseArray(arr3, 10, &avg3, &q3);
	if (avg3 != 5 || q3 != 4)
		printf("your avg3 != 5 || q3 != 5 answer is wrong (-9)\n");
	/*---------------------------Question 3---------------------------*/
	printf("\nQuestion 3 - Separate\n");
	Separate(str31, '-', words1, length1);
	if (strncmp(words1[0], "hello ", 6) != 0)
		printf("your strncmp(words1[0], \"hello \", 6) != 0 answer is wrong (-8)\n");
	Separate(str32, ' ', words2, length2);
	if (strncmp(words2[1], "for", 3) != 0)
		printf("your strncmp(words2[1], \"for\", 3) != 0 answer is wrong (-8)\n");
	Separate(str33, 'c', words3, length3);
	if (strncmp(words3[2], "Test", 4) != 0)
		printf("your strncmp(words3[2], \"Test\", 4) != 0 answer is wrong (-9)\n");
	/*---------------------------Question 4---------------------------*/
	printf("\nQuestion 4 - ReverseWords\n");
	
	answer1 = ReverseWords(str41);
	if (strcmp(answer1, "cat a was There") != 0)
		printf("your strcmp(answer1, \"cat a was There\") != 0 answer is wrong (-8)\n");
	answer2 = ReverseWords(str42);
	if (strcmp(answer2, "cat") != 0)
		printf("your strcmp(answer2, \"cat\") != 0 answer is wrong (-8)\n");
	answer3 = ReverseWords(str43);
	if (strcmp(answer3, "Colman CS to Intro") != 0)
		printf("your strcmp(answer3, \"Colman CS to Intro\") != 0 answer is wrong (-9)\n");
		
	free(answer1);
	free(answer2);
	free(answer3);
	
	/*---------------------------Finish---------------------------*/
	printf("\n\ndone\n\n");
	return 0;
}