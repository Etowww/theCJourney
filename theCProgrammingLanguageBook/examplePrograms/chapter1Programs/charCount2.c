// The C Programming Language 2nd Edition Book Example Programs
// Second Version of the Character Counting Counting Program using a for loop and a data type double
// Written for learning purpose by DBTow

#include <stdio.h>

/* Count characters in input; 2nd version */
int main()
{
	double nc;

	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("%.0f\n", nc);
}
