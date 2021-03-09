#ifndef UTIL_H
#define UTIL_H

// Functions Declarations 

// how many digits
int NumOfDigits(int num); 
// tests final grade
int FinalGrade(int test_Grade, int avgHomeWorkGrade, int numExDone); 
// how much to pay
float CarPartsPrice(int numOfProducts, float productPrice, int productType); 
// New number of the odds digits
int OddIndexNumber(int num);
// returns the sum of digits
int SumOfDigits (int num);
// isContain? and what index from right to the left
int Contains(int num1, int num2);
#endif // !UTIL_H