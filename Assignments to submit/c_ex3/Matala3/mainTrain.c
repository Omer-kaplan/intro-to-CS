/* Name: Omer Kaplan
* ID: 208278036
* DATE: 04.12.2020
* Goal: this main checks all the EX2 code when changed to functions
*/
#include <stdio.h>
#include "Util.h"

int main()
{
	// Testing the (1) function
	
	//* -------------------------------
	int numTest = NumOfDigits(9);
	printf("\n9 has : %d\n", numTest);
	int numTest2 = NumOfDigits(23);
	printf("\n23 has : %d\n", numTest2);
	int numTest3 = NumOfDigits(100);
	printf("\n100 has : %d\n", numTest3);
	int numTest4 = NumOfDigits(-20);
	printf("\n-20 number has : %d\n", numTest4);
	int numTest5 = NumOfDigits(2000);
	printf("\n2000 has : %d\n", numTest5);
	
	// Testing the (2) fun
	
	int final1 = FinalGrade(80, 70, 7); // 80
	int final2 = FinalGrade(50, 70, 7); // 54
	int final3 = FinalGrade(50, 70, 5); // 50
	int final4 = FinalGrade(80, 70, 6); // 77
	int final5 = FinalGrade(80, 70, 4); // 0
	printf("\nShould be 80, 54, 50, 78, 0 \t %d  %d  %d  %d  %d \n", final1, final2, final3, final4, final5);
	//printf("\nShould be  78\t %d  \n", final4); 
	
	// Testing the (3) fun
	
	float test1 = CarPartsPrice(35, 70, 4); // 2450
	//float test2 = CarPartsPrice(30, 100, 2); // 3000
	//float test3 = CarPartsPrice(50, 100, 3); // 4000
	//float test4 = CarPartsPrice(40, 50, 5); // 1800
	//printf("\nA check:   %0.2f  %0.2f  %0.2f  %0.2f  ", test1, test2, test3, test4);
	printf("\nA check:   %0.2f    ", test1);
	
	// Testing the (4) fun
	
	int num2 = OddIndexNumber(123456789); // 2468
	int num1 = OddIndexNumber(1000); // need to be 10
	printf("\n The new num is:  %d   and    %d\n",num2, num1);
	

	// Testing the (5) fun
	int try1 = SumOfDigits(341); // 8
	int try2 = SumOfDigits(897); // 6
	printf("\nThe (1) is  %d    The (2) is  %d  \n", try1, try2);

	// Testing the (6) function
	int getNum1 = Contains(2265123, 651); // 4
	int getNum2 = Contains(754763, 222); // -1
	int getNum3 = Contains(693, 693); // 2
	printf("\n The 1:  %d  The 2:  %d  The 3:  %d  \n", getNum1, getNum2, getNum3);

	return 0;
}