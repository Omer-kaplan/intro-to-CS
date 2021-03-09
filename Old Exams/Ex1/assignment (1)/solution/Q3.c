#include "exam.h"

int toStart(int num, int start)
{
	int newNum;

	fx1(); // do not change!!!
	if (num == 0)
	{
		return start;
	}
	newNum = toStart(num / 10, start);

	return newNum * 10 + num % 10;

}
/*  B  */
int merge(int n1, int n2)
{
	int newNum, d1, d2;
	
	fx2(); // do not change!!!
 	
	if (n1 == 0 && n2 == 0)
	{
		return 0;
	}
	if (n1 == 0)
	{
		return n2;
	}
	if (n2 == 0)
	{
		return n1;
	}
	d1 = n1 % 10;
	d2 = n2 % 10;
	newNum = merge(n1 / 10, n2 / 10);
	return newNum * 100 + d2 * 10 + d1;

}