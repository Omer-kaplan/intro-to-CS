/* ------------------------------------------------------------------
* Name: Omer Kaplan
* Goal: This program gets a number and returns its special new number -
* built from its odd position digits
  -------------------------------------------------------------------*/
  
#include <stdio.h>
#include <math.h>

int main()
{
	// Declare vars
	int input_number, right_digit;
	double pow_result;
	int count = 0;
	int new_number = 0;
	int mult_times = 0;
	// Main cose
	printf("\n\n--------- Amaizing calc ---------");
	printf("\n\nPlease enter a number:\t");
	scanf_s("%d", &input_number);
	while (input_number)
	{
		if (count % 2 == 1)
		{
			if (new_number == 0)
			{
				right_digit = input_number % 10;
				new_number = right_digit;
				mult_times++;
			}
			else
			{
				right_digit = input_number % 10;
				pow_result = pow((double)10, (double)mult_times);
				right_digit *= (int)pow_result;
				new_number += right_digit;
				mult_times++;
			}

		}
		count++;
		input_number = input_number / 10;
	}
	printf("\The new number is:\t%d\n", new_number);
	printf("\n--------- The End task 4 ---------\n\n");
	return 0;
}