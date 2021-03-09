/* ------------------------------------------------------------------
* Name: Omer Kaplan
* Goal: This program gets 3 numbers which symbols a grade, avg. grade and 
* homework done, it prints the final courses grade by the formula.
  -------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

int main()
{
	// Declaring vars
	float avg_homework_grade, temp_grade;
	float temp25, temp75, temp_magen, temp20, temp80, temp30, temp70;
	int homework_number, test_grade, final_grade;
	
	// main code
	printf("\nPlease Enter: (1) Test grade. (2) Avg. HW grade. (3) HW tasks done\n"); 
	scanf_s("%d%f%d", &test_grade, &avg_homework_grade, &homework_number);
	if (homework_number <= 4) // how many HW tasks done
	{
		final_grade = 0;
	}
	else if (homework_number == 5 || homework_number == 6)
	{
		if (test_grade >= 58) // final - 25% abg HW, 75% tests grade
		{
			temp25 = (avg_homework_grade * 25) / 100;
			temp75 = (test_grade * 75) / 100;
			temp_grade = temp25 + temp75;
			temp_grade = round(temp_grade);
			final_grade = (int)temp_grade;
		}
		else if (test_grade <= 57)
		{
			final_grade = test_grade;
		}
	}
	else if (homework_number == 7 || homework_number == 8)
	{
		if (test_grade <= 54)
		{
			if (avg_homework_grade >= 80 && avg_homework_grade > test_grade)
			{
				temp25 = (avg_homework_grade * 25) / 100;
				temp75 = (test_grade * 75) / 100;
				temp_grade = temp25 + temp75;
				temp_grade = round(temp_grade);
				final_grade = (int)temp_grade;
			}
			else if(avg_homework_grade < 80 && avg_homework_grade > test_grade) // Only if magen helps, 20%
			{
				temp20 = (avg_homework_grade * 20) / 100;
				temp80 = (test_grade * 80) / 100;
				temp_grade = temp20 + temp80;
				temp_grade = round(temp_grade);
				final_grade = (int)temp_grade;
			}
			else
			{
				final_grade = test_grade;
			}
		}
		else if (test_grade >= 55 && test_grade <= 100)
		{
			if (avg_homework_grade > test_grade) // Only if magen helps, 30% magen
			{
				temp30 = (avg_homework_grade * 30) / 100;
				temp70 = (test_grade * 70) / 100;
				temp_grade = temp30 + temp70;
				temp_grade = round(temp_grade);
				final_grade = (int)temp_grade;
			}
			else
			{
				final_grade = test_grade;
			}
		}
	}
	// final_grade
	printf("\nThe Final grade is: %d\n\n", final_grade);
	return 0;
}