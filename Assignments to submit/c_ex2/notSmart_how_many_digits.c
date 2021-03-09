/* ------------------------------------------------------------------
* Name: Omer Kaplan
* Goal: This prigram gets a number higher or equal to 0, returns how many digits.
  -------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
	// Declaring variables
	int input_num;
	// main code
	printf("\nPlease enter a number, higher or equal to 0\n");
	scanf_s("%d", &input_num);

	if (input_num < 0)
	{
		printf("\nInvalid Number !\n");
	}
	else if (input_num >= 0 && input_num < 10)
	{
		printf("\nNumber has 1 digit");
	}
	else if (input_num >= 10 && input_num < 100)
	{
		printf("\nNumber has 2 digits");
	}
	else if (input_num >= 100 && input_num < 1000)
	{
		printf("\nNumber has 3 digits");
	}
	else
	{
		printf("\nNumber has over 3 digits");
	}
	return 0;
}