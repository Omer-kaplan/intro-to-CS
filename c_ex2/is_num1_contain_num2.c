/* ------------------------------------------------------------------
* Name: Omer Kaplan
* Goal: This program gets 2 numbers and checks wether the first includes 
* the second number, if it does, prints its index.
  -------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
	// Declare vars
	int first_num, second_num;
	int index = 0;
	int flag = 0;

	// Main code
	printf("\nPlease enter 2 integers:\n");
	scanf_s("%d%d", &first_num, &second_num);
	int checker = second_num;
	while (first_num && flag != 1)
	{
		if (first_num % 10 == checker % 10)
		{
			checker = checker / 10;
			if (checker == 0)
			{
				flag = 1;
				break;
			}
		}
		else
		{
			checker = second_num;
		}
		index++;
		first_num = first_num / 10;
	}
	if (flag == 1)
	{
		printf("\nThe Answer:  %d\n\n", index);
	}
	else
	{
		printf("\nThe Answer:  -1  \n\n");
	}
	return 0;
}