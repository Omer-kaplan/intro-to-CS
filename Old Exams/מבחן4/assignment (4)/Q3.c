#include "exam.h"

int SpecialSeries(int n)
{
	/******** DON'T CHANGE ********/
	fx1(); // do not change!!!
	/******************************/
	int x;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 3;
	if (n % 2 == 0) // if n isEven
		return SpecialSeries(n - 1) + SpecialSeries(n - 2) + SpecialSeries(n - 3);
	else if (n % 2 == 1)
	{
		x = SpecialSeries(n - 1) - SpecialSeries(n - 3);
		if (x < 0)
			return -x;
		return x;
	}
}
