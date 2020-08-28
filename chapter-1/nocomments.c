#include <stdio.h>

/* inputs a C program and remove all comments like this one */
int main()
{
    int current, previous;
    int quotes, comments;

    quotes = comments = -1;
    while ((current = getchar()) != EOF) {
	if (current == '"' && comments == -1)
	    quotes *= -1;

	if (quotes == -1)
	    if ((previous == '/' && current == '*') || (previous == '*' && current == '/'))
		comments *= -1;
	previous = current;
	if (comments == 1)
	    continue;
	if (current == '/' && quotes != -1)
	    putchar(current);
	if (current != '/')
	    putchar(current);
    }
    return 0;
}
