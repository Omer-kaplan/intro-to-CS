#include "exam.h"

/*int MultEven(int a[], int size)
{
	/******** DON'T CHANGE ********
	fx1(); // do not change!!!
	/******************************
	int mult;

	if (size <= 0)
		return 0;
	
	mult = MultEven(a, size-1);

	if (a[size - 1] % 2 == 0) // isEven
	{
		if (mult == 0) // first Cell
		{
			return a[size - 1];
		}
		else
		{
			return mult * a[size - 1];
		}
	}
	return mult;
}
*/

int MultEven(int a[], int size)
{
	/******** DON'T CHANGE ********/
	fx1(); // do not change!!!

	if (size <= 0)
		return 0;

	int x = MultEven(a, size - 1);

	if (a[size - 1] % 2 == 0) // is Even
	{
		if (x == 0)
			return a[size - 1];
		return (x * a[size - 1]);
	}
	return x;
}