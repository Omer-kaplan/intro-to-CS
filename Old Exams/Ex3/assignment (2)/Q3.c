#include "exam.h"

int SpecialSeries(int n)
{
	fx1(); // do not change!!!
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 3;

	if (n % 2 == 0)
		return SpecialSeries(n - 1) + SpecialSeries(n - 2) + SpecialSeries(n - 3);

	int x;
	x = SpecialSeries(n - 1) - SpecialSeries(n - 3);

	if (x < 0) return (-x); else return x;
}