#include "exam.h"

int  MultEven(int a[], int size)
{
	
 	/******** DON'T CHANGE ********/
	fx1(); // do not change!!!
	/******************************/
	
	/*Write your code down here*/	
   int x;

	if (size<=0)
		return 0;
    x = MultEven(a,size-1);
    
	if (a[size-1]%2 == 0) // even
    {
        if (x == 0)
            return (a[size-1]); // the 1st time 
        else 
            return (x*a[size-1]);
    }
    else //odd
        return x;
}


