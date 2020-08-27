#include <stdio.h>

#define FOLD   25		/* fold length */
#define MAXLEN 1000		/* maximum length of input line */

int inputline(char line[], int limit);
void fold(char line[], int start);

/* fold long input strings to multiple small strings */
main()
{
    char line[MAXLEN];

    while (inputline(line, MAXLEN) > 0) {
	fold(line, 0);
    }
    
    return 0;
}

int inputline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	s[i] = c;
    if (c == '\n') {
	s[i] = c;
	++i;
    }
    s[i] = '\0';
    return i;
}

void fold(char line[], int start)
{
    if (line[start] == '\0')
	return;
    int space = -1;
    int pos = 1;
    int index = start;
    while (pos <= FOLD) {
	if (line[index] == ' ')
	    space = index;
	else if (line[index] == '\0') {
	    break;
	}
	++pos;
	++index;
    }
    if (space != -1)
	index = space + 1;

    for (int i = start; i < index; ++i)
	putchar(line[i]);
    if (line[index - 1] != '\n')
	putchar('\n');
    fold(line, index);
}
