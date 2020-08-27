#include <stdio.h>

#define MWORDS 20		/* maximum words allowed */
#define MCHAR  20		/* maximum characters in a word */

/* print a vertical histogram of the lengths of words in the input */
main(void)
{
    int c, i;
    int wlen[MWORDS];

    for (i = 0; i < MWORDS; i++)
	wlen[i] = 0;
    
    i = 0;
    while ((c = getchar()) != EOF)
	if (c == ' ' || c == '\t' || c == '\n')
	    ++i;
	else
	    ++wlen[i];

    for (i = MCHAR; i > 0; i--) {
	for (int j = 0; j < MWORDS; j++)
	    if (wlen[j] >= i)
		printf("# ");
	    else
		printf("  ");
	printf("\n");
    }
    
    return 0;
}
