#include "exam.h"

int SpecialSeries(int n)
{
	/******** DON'T CHANGE ********/
	fx1(); // do not change!!!
	/******************************/
	
	/*Write your code down here*/	
	int X;
    
    if (n==1)
        return (1);
    if (n==2)
        return (2);
    if (n==3)
        return (3);
    if (n%2) {//i.e odd
        X =SpecialSeries(n-1)-SpecialSeries(n-3);
        if (X< 0) return (-X); else return (X);
    }
    else //even
        return (SpecialSeries(n-1)+SpecialSeries(n-2)+SpecialSeries(n-3));

}
