// functions implementations
#include "Util.h"
#include <math.h> // For Round();

// Returns how many digits number has
int NumOfDigits(int num)
{
	if (num < 0)
		return -1;
	else if (num >= 0 && num < 10)
	{
		return 1;
	}
	else if(num >= 10 && num < 100)
	{
		return 2;
	}
	else if (num >= 100 && num < 1000)
	{
		return 3;
	}
	else
		return 4;
}

// Returns the final grade by the formula
int FinalGrade(int test_Grade, int avgHomeWorkGrade, int numExDone) // Sums the final result
{
	// Usefull vars to help
	float temp_grade;
	float temp25, temp75, temp_magen, temp20, temp80, temp30, temp70;
	int final_Grade;

	if (numExDone <= 4) // how many HW tasks done
	{
		final_Grade = 0;
	}
	else if (numExDone == 5 || numExDone == 6)
	{
		if (test_Grade >= 58) // final - 25% abg HW, 75% tests grade
		{
			temp25 = (float)(avgHomeWorkGrade * 0.25);
			temp75 = (float)(test_Grade * 0.75);
			temp_grade = temp25 + temp75;
			temp_grade = round(temp_grade);
			final_Grade = (int)temp_grade;
		}
		else if (test_Grade <= 57)
		{
			final_Grade = test_Grade;
		}
	}
	else if (numExDone == 7 || numExDone == 8)
	{
		if (test_Grade <= 54)
		{
			if ((avgHomeWorkGrade >= 80) && (avgHomeWorkGrade > test_Grade))
			{
				temp25 = (avgHomeWorkGrade * 25) / 100;
				temp75 = (test_Grade * 75) / 100;
				temp_grade = temp25 + temp75;
				temp_grade = round(temp_grade);
				final_Grade = (int)temp_grade;
			}
			else if ((avgHomeWorkGrade < 80) && (avgHomeWorkGrade > test_Grade)) // Only if magen helps, 20%
			{
				temp20 = (avgHomeWorkGrade * 20) / 100;
				temp80 = (test_Grade * 80) / 100;
				temp_grade = temp20 + temp80;
				temp_grade = round(temp_grade);
				final_Grade = (int)temp_grade;
			}
			else
			{
				final_Grade = test_Grade;
			}
		}
		else if (test_Grade >= 55 && test_Grade <= 100)
		{
			if (avgHomeWorkGrade > test_Grade) // Only if magen helps, 30% magen
			{
				temp30 = (avgHomeWorkGrade * 30) / 100;
				temp70 = (test_Grade * 70) / 100;
				temp_grade = temp30 + temp70;
				temp_grade = round(temp_grade);
				final_Grade = (int)temp_grade;
			}
			else
			{
				final_Grade = test_Grade;
			}
		}
	}
	final_Grade = (int)final_Grade;
	return final_Grade;
}

// Returns the final ammount customer should pay
float CarPartsPrice(int numOfProducts, float productPrice, int productType)
{
	int flag = 1;
	float sum_payment;

	if (numOfProducts <= 35)
	{
		flag = 0;
	}
	switch (productType)
	{
	case 1:
	{
		if (flag) // 5% discoutnt
		{
			sum_payment = (numOfProducts * productPrice) * 0.95;
			return sum_payment;
		}
		else
		{
			sum_payment = numOfProducts * productPrice;
			return sum_payment;
		}
	}
	case 2:
	{
		if (flag) // 10% discoutnt
		{
			sum_payment = (numOfProducts * productPrice) * 0.9;
			return sum_payment;
		}
		else
		{
			sum_payment = numOfProducts * productPrice;
			return sum_payment;
		}
	}
	case 3:
	{
		if (flag) // 20% discoutnt
		{
			sum_payment = (numOfProducts * productPrice) * 0.8;
			return sum_payment;
		}
		else
		{
			sum_payment = numOfProducts * productPrice;
			return sum_payment;
		}
	}
	case 4:
	{
		{
			if (flag) // 5% discoutnt
			{
				sum_payment = (numOfProducts * productPrice) * 0.95;
				return sum_payment;
			}
			else
			{
				sum_payment = numOfProducts * productPrice;
				return sum_payment;
			}
		}
	}
	case 5:
	{
		if (flag) // 10% discoutnt
		{
			sum_payment = (numOfProducts * productPrice) * 0.9;
			return sum_payment;
		}
		else
		{
			sum_payment = numOfProducts * productPrice;
			return sum_payment;
		}
	}
	case 6:
	{
		if (flag) // 5% discoutnt
		{
			sum_payment = (numOfProducts * productPrice) * 0.95;
			return sum_payment;
		}
		else
		{
			sum_payment = numOfProducts * productPrice;
			return sum_payment;
		}
	}
	case 7:
	{
		if (flag) // 20% discoutnt
		{
			sum_payment = (numOfProducts * productPrice) * 0.8;
			return sum_payment;
		}
		else
		{
			sum_payment = numOfProducts * productPrice;
			return sum_payment;
		}
	}
	case 8:
	{
		if (flag) // 20% discoutnt
		{
			sum_payment = (numOfProducts * productPrice) * 0.8;
			return sum_payment;
		}
		else
		{
			sum_payment = numOfProducts * productPrice;
			return sum_payment;
		}
	}
	default:
		// None
		return 0.0f;
	}
}

// Returns a new number out of the odds places
int OddIndexNumber(int num)
{
	int right_digit;
	double pow_result;
	int count = 0;
	int new_number = 0;
	int mult_times = 0;
	
	while (num)
	{
		if (count % 2 == 1)
		{
			right_digit = num % 10;
			pow_result = pow((double)10, (double)mult_times);
			// right_digit *= (int)pow_result;
			new_number += right_digit * pow_result;
			mult_times++;
		}
		count++;
		num = num / 10;
	}
	return new_number;
}

// Returns the sum of this num digits until it has just one
int SumOfDigits(int num)
{
	int right_digit, new_number = 0;
	// int flag_runs = 1;

	if (num >= 0)
	{
		while (num)
		{
			right_digit = num % 10;
			new_number += right_digit;
			num = num / 10;
			if (num == 0 && new_number > 9)
			{
				num = new_number;
				new_number = 0;
			}
		}
		return new_number;
	}
	else
	{
		return -1;
	}
}

// Returns isContain, the index from the right to left or -1
int Contains(int num1, int num2)
{
	int index = 0;
	int flag = 0;
	int checker = num2;

	while (num1)
	{
		if (num1 % 10 == checker % 10)
		{
			checker = checker / 10;
			if (checker == 0)
			{
				return index;
			}
		}
		else
		{
			checker = num2;
		}
		++index;
		num1 = num1 / 10;
	}
		return -1;
}