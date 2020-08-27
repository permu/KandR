#include <stdio.h>

#define MAXLINE 1000		/* maximum input line length */

void reverse(char s[]);
int inputline(char line[], int max);

/* reverse input strings */
main()
{
    char line[MAXLINE];
    while (inputline(line, MAXLINE) > 0) {
	reverse(line);
	printf("%s", line);
    }
    return 0;
}

/* inputline: stores the input in s, returns length */
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

/* reverse: reverse the string 's' */
void reverse(char s[])
{
    int i;
    /* calculate length of s */
    for (i = 0; s[i] != '\0' && s[i] != '\n'; i++)
	;
    char temp;
    for (int j = 0; j <= (i - 1) / 2; j++) {
	temp = s[j];
	s[j] = s[i - 1 - j];
	s[i - 1 - j] = temp;
    }
}
