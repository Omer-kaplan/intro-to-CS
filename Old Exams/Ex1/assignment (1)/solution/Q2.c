#include <stdlib.h>
#include <string.h>
// #include "exam.h"

char * removeBlanks(char *str)
{
	int i,j;
	int size = strlen(str); 
	
	for( i = 0, j = 0; i < size; i++){
	    
        str[i-j] = str[i];
        if(str[i] == ' ')
            j++;
	}
	str[i-j] = '\0';
	
	return str;
}



int getBitByIndex(unsigned int num, int index)
{
	int mask = 1 << index;

	if (num&mask)
	    return 1;
	else
	    return 0;

} 