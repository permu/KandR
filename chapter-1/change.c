#include <stdio.h>

int coin_value(int n);
int count_change(int amount, int ncoins);

/* Calculate number of ways to change an amount */
int main()
{
    int amount = 500;
    printf("%d\n", count_change(amount, 5));
}

/* returns the value of the nth coin */
int coin_value(int n)
{
    switch (n) {
    case 1:
	return 1;
    case 2:
	return 5;
    case 3:
	return 10;
    case 4:
	return 25;
    case 5:
	return 50;
    }
}

/* Calculate number of ways of changing amount through
   recursion */
int count_change(int amount, int ncoins)
{
    if (amount == 0) {
	return 1;		/* 1 way to make change */
    }
    else if (amount < 0 || ncoins == 0) {
	return 0;		/* 0 ways to make change */
    }
    else {
	return count_change(amount, ncoins - 1) + count_change(amount - coin_value(ncoins), ncoins);
    }
}
