#include "exam.h"

int toStart(int num, int start)
{
	/********Do Not Change!!!*****/
	fx1(); // do not change!!!
	/*****************************/
	
	if (num == 0)
		return start;
	
	int newNum = toStart(num / 10, start);

	return newNum * 10 + num % 10;
}
int merge(int n1, int n2)
{
	/********Do Not Change!!!*****/
	fx2(); // do not change!!!
	/*****************************/
	int new_num, d1, d2;

	if (n1 == 0 && n2 == 0)
		return 0;
	if (n1 == 0)
		return n2;
	if (n2 == 0)
		return n1;

	d1 = n1 % 10;
	d2 = n2 % 10;
	new_num = merge(n1 / 10, n2 / 10);

	return new_num * 100 + d2 * 10 + d1;
}