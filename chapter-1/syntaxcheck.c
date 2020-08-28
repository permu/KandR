#include <stdio.h>

#define STACKSIZE 100

char stack[STACKSIZE];
int top = -1;

void push(char s);
void pop();
char look();

/* checks a C program for unbalanced braces, parentheses, quotes 
   TODO: implement escape sequence support */
main()
{
    /* initialise stack */
    for (int i = 0; i < STACKSIZE; ++i)
	stack[i] = 'F';

    int c;
    while ((c = getchar()) != EOF) {
	/* handle parenthesis and alike */
	if (c == '(' || c == '{')
	    push(c);
	else if (c == ')' || c == '}')
	    if (look() != c) {
		printf("Unbalanced!!\n");
		return -1;
	    }
	    else
		pop();
	else if (c == '\"' || c == '\'')
	    if (look() == c)
		pop();
	    else
		push(c);
    }
    if (top == -1) {
	printf("Correct!\n");
	return 0;
    }
    else
	printf("Unbalanced!\n");
    return -1;
}

/* push: push a closing symbol on stack 
   TODO: Check for overflow */
void push(char s)
{
    ++top;
    if (s == '(')
	stack[top] = ')';
    else if (s == '{')
	stack[top] = '}';
    else
	stack[top] = s;
}

/* pop: pop top symbol from stack */
void pop()
{
    --top;
}

/* get the top character from the stack */
char look()
{
    return stack[top];
}
