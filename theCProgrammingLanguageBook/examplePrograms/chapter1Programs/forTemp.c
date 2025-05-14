// The C Programming Language 2nd Edition Book Example Programs
// Farenheit to Celsius Temperature Converter using a for statement
// Written for learning purposes by DBTow

#include <stdio.h>

/* print Fahrenheit-Celsius table */
int main()
{
	int fahr;

	for (fahr = 0; fahr <=300; fahr= fahr + 20)
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
