#include <stdlib.h>
#include <string.h>
#include "exam.h"

int is_in(char c, char *str)
{
	while (*str)
	{
		if (c==*str)
			return 1;
		str++;
	}
	return 0;
}	

void create_substitutor(char *keyword, char *subst)
{
	char c;
	/* copy keyword to subst */
	int i=0;
	while (keyword[i])
	{
		subst[i]=keyword[i];
		i++;
	}

	/* put other letters, according to their order */
	for (c='A';c<='Z';c++)
		if (!is_in(c,keyword))
			subst[i++]=c;
	subst[i]='\0';
}

 