#include "exam.h"
int areClose(long int n1, long int n2)
{
	/******** DON'T CHANGE ********/
	fx1(); // do not change!!!
	/******************************/
	
	/*Write your code down here*/	

 	if (n1<0 || n2<0)
  		return 0;
 	if ((n1<10 && n2>=10) || (n2<10 && n1>=10))
  		return 0;
 	if (n1<10)
  		return (n1-n2 == 1 || n1==n2 || n2-n1 == 1);
 	return (( (n1%10==n2%10) || (n1%10-n2%10==1) || (n2%10-n1%10==1)) && (areClose(n1/10, n2/10)));
}


