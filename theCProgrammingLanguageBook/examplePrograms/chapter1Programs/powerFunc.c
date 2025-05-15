// The C Programming Language 2nd Edition Book Example Program
// Writing a function that raises a integer m to a positive integer power n
// Written for learning purposes by DBTow

#include <stdio.h>

int power(int m, int n);

int main()
{
	int i;

	for(i = 0; i < 10; ++i)
		printf("%d %d %d\n", i, power(2,i), power(-3,i));
	return 0;
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n)
{
	int i, p;

	p = 1;
	for (i = 1; i <= n; ++i)
		p = p * base;
	return p;
}
