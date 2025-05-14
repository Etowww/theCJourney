// The C Programming Language 2nd Edition Book Example Programs
// Floating-point arithmetic temperature conversion

// Written for learning purposes by DBTow

#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 floating-point version */
int main()
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
