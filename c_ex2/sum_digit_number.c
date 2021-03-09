/* ------------------------------------------------------------------
* Name: Omer Kaplan
* Goal: This program gets a positive number and outputs its digit sum number
  -------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
	// Declare vars
	int input_num, right_digit;
	int new_number1 = 0;
	int flag_runs = 1;
	// Main code
	printf("\nPlese enter a number: ");
	scanf_s("%d", &input_num);
	if (input_num >= 0)
	{
		while (input_num)
		{
				right_digit = input_num % 10;
				new_number1 += right_digit;
				input_num = input_num / 10;
				if (input_num == 0 && new_number1 > 9)
				{
					input_num = new_number1;
					new_number1 = 0;
				}
		}
		printf("\nAnswer is:\t%d\n", new_number1);
	}
	else
	{
		printf("\n (-1) \n");
	}
	return 0;
}