/* ------------------------------------------------------------------
* Name: Omer Kaplan
* Goal: This program gets parts number, single price, parts type -
* prints the total amount the customer has to pay.
  -------------------------------------------------------------------*/
// Function getchar() + scanf_s("%C", &c, 1);
#include <stdio.h>

int main()
{
	// Declare vars
	int parts_count, part_price;
	char part_type;
	int flag = 1;
	float sum_payment;
	// Main code
	printf("\nPlease enter (1) number of parts, (2) single part price: \n");
	scanf_s("%d%d",&parts_count, &part_price);
	printf("\n Now. Please enter (3) the part type: \n");
	getchar();
	scanf_s("%c", &part_type, 1);
	if (parts_count < 35)
	{
		flag = 0;
	}
	switch (part_type)
	{
	case '1':
	{
		if (flag) // 5% discoutnt
		{
			sum_payment = (parts_count * part_price) * 0.95;
			printf("\nYou have to pay:\t%.2f\n", sum_payment);
			break;
		}
		else 
		{
			sum_payment = parts_count * part_price;
			printf("\nYou have to pay:\t%.2f\n", sum_payment); // no dis
			break;
		}
	}
	case '2':
	{
		if (flag) // 10% discoutnt
		{
			sum_payment = (parts_count * part_price) * 0.9;
			printf("\nYou have to pay:\t%.2f\n", sum_payment);
			break;
		}
		else
		{
			sum_payment = parts_count * part_price;
			printf("\nYou have to pay:\t%.2f\n", sum_payment); // no dis
			break;
		}
	}
	case '3':
	{
		if (flag) // 20% discoutnt
		{
			sum_payment = (parts_count * part_price) * 0.8;
			printf("\nYou have to pay:\t%.2f\n", sum_payment);
			break;
		}
		else
		{
			sum_payment = parts_count * part_price;
			printf("\nYou have to pay:\t%.2f\n", sum_payment); // no dis
			break;
		}
	}
	case '4':
	{
		{
			if (flag) // 5% discoutnt
			{
				sum_payment = (parts_count * part_price) * 0.95;
				printf("\nYou have to pay:\t%.2f\n", sum_payment);
				break;
			}
			else
			{
				sum_payment = parts_count * part_price;
				printf("\nYou have to pay:\t%.2f\n", sum_payment); // no dis
				break;
			}
		}
	}
	case '5':
	{
		if (flag) // 10% discoutnt
		{
			sum_payment = (parts_count * part_price) * 0.9;
			printf("\nYou have to pay:\t%.2f\n", sum_payment);
			break;
		}
		else
		{
			sum_payment = parts_count * part_price;
			printf("\nYou have to pay:\t%.2f\n", sum_payment); // no dis
			break;
		}
	}
	case '6':
	{
		if (flag) // 5% discoutnt
		{
			sum_payment = (parts_count * part_price) * 0.95;
			printf("\nYou have to pay:\t%.2f\n", sum_payment);
			break;
		}
		else
		{
			sum_payment = parts_count * part_price;
			printf("\nYou have to pay:\t%.2f\n", sum_payment); // no dis
			break;
		}
	}
	case '7':
	{
		if (flag) // 20% discoutnt
		{
			sum_payment = (parts_count * part_price) * 0.8;
			printf("\nYou have to pay:\t%.2f\n", sum_payment);
			break;
		}
		else
		{
			sum_payment = parts_count * part_price;
			printf("\nYou have to pay:\t%.2f\n", sum_payment); // no dis
			break;
		}
	}
	case '8':
	{
		if (flag) // 20% discoutnt
		{
			sum_payment = (parts_count * part_price) * 0.8;
			printf("\nYou have to pay:\t%.2f\n", sum_payment);
			break;
		}
		else
		{
			sum_payment = parts_count * part_price;
			printf("\nYou have to pay:\t%.2f\n", sum_payment); // no dis
			break;
		}
	}
	default:
		// None
		break;
	}
}