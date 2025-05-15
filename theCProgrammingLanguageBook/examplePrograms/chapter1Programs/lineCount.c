// The C Programming Language 2nd Edition Book Example Programs
// A program to count lines
// Written for learning purposes by DBTow

#include <stdio.h>

int main()
{
	int c, nl;

	nl = 0;
	while((c = getchar()) != EOF)
		if (c == '\n')
			++nl;
	printf("%d\n", nl);
}
