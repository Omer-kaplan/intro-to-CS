#include "exam.h"
/*
isSameNumDig(long int n1, long int n2)
{
	while (n1)
	{
		if (n2 == 0 && n1 != 0)
			return 0;
		n1 = n1 / 10;
		n2 = n2 / 10;
	}
	if (n2)
		return 0;
	return 1;
}
*/


int areClose(long int n1, long int n2)
{
	/******** DON'T CHANGE ********/
	fx1(); // do not change!!!
	/******************************/
	if (n1 == 0 && n2 == 0)
		return 1;
	if (n1 <= 0 || n2 <= 0) // is Grater than 0
		return 0;
	if ((n1 == 0 && n2 != 0) || (n2 == 0 && n1 != 0)) // Not same num of digits
		return 0;

	int dig1, dig2;
	dig1 = n1 % 10;
	dig2 = n2 % 10;

	if (n1 > n2) // Diff > 0 || 1
	{

		if ((dig1-dig2) != 0)
			if ((dig1-dig2) != 1)
				return 0;
	}
	else
	{
		if ((dig2-dig1) != 0)
			if ((dig2-dig1) != 1)
				return 0;
	}
	return areClose(n1 / 10, n2 / 10);
}