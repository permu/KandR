#include <stdio.h>

#define TABSTOPS 8

/* replace blanks with tabs appropriately */
main()
{
    int c, count, pos;

    count = 0;
    pos = 1;
    while ((c = getchar()) != EOF) {
	if (c == ' ') {
	    if (pos == TABSTOPS) {
		putchar('\t');
		pos = 1;
		count = 0;
	    }
	    else {
		++count;
		++pos;
	    }
	}
	else {
	    /* prints all necessary spaces */
	    while (count > 0) {
		putchar(' ');
		--count;
	    }
	    putchar(c);
	    ++pos;
	}
	if (pos > 8 || c == '\n')
	    pos = 1;
    }

    return 0;
}
