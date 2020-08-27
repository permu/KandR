#include <stdio.h>

#define IN 1			/* last character was a blank */
#define OUT 0			/* last character was not a blank */

/* replace strings of one or more blanks by a single blank */
int main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF)
    {	
	if (c != ' ') {
	    putchar(c);
	    state = OUT;
	}
	else if (state == OUT) {
	    putchar(c);
	    state = IN;
	}
    }
}
