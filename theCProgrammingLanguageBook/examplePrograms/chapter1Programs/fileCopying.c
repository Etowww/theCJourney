// The C Programming Language 2nd Edition Book Example Program
// This program copies its input to its output one character at a time
// Written for learning purposes by DBTow

#include <stdio.h>

/* copy input to output; 1st version */
int main()
{
	int c;

	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}
}

// When you run this program in the terminal (macOS) to signal EOF you press <Ctrl + d> once will execute putchar() twice will terminate the program

// You can always execute any program in the terminal (from my experience) by pressing <Ctrl + c> if need
