#include <stdlib.h>
#include <string.h>
#include "exam.h"


void copy_rev (char* word, char *outStr, int wordSize)
{
 int ind = wordSize-1, i=0;
 for( ; ind>=0 ; ind--, i++)
 outStr[i]=word[ind];
 return;
} 

char *revWord(char inStr[])
{
    int size = strlen(inStr)+1;
    char *outStr = (char *)calloc(size,1);
    char *tmpoutStr=outStr;
    
    char c, word[24]={0};
     int i=0, strIdx=0;
     int in_word = 0; /* 'in_word' will let us know if we read a word or no */
 
    while ((c = inStr[strIdx])!='\0')
    {
     if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
     {
         word[i] = c;
         i++;
         in_word = 1;
     }
     else
     {
         if(in_word) /* if we read a word */
         {
             copy_rev(word, tmpoutStr, i);
             //printf ("%s\n", outStr);
             tmpoutStr+=i;
         }
         *tmpoutStr = c;
         tmpoutStr++;
         i = 0;
         in_word = 0;
     }
    strIdx++;
    }
     if (in_word) /* for the last word */
     {
         copy_rev(word,tmpoutStr, i);
        tmpoutStr+=i;
     }
    
    outStr[size] = '\0';
    
    return outStr;   
}

 