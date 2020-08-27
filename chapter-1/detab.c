#include <stdio.h>

#define TABSTOPS 8

/* replace tabs with appropriate number of blanks */
main()
{
    int c, pos;

    pos = 1;
    while ((c = getchar()) != EOF) {
	if (c == '\t') {
	    for (int i = pos; i <= TABSTOPS; i++)
		putchar(' ');
	    pos = 1;
	}
	else {
	    putchar(c);
	    ++pos;
	}
	if (pos > TABSTOPS || c == '\n')
	    pos = 1;
    }
    return 0;
}
