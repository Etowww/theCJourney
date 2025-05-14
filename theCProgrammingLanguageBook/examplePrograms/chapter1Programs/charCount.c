// The C Programming Language 2nd Edition Book Example Program
// Program counts characters
// Written for learning purposes by DBTow

#include <stdio.h>

/* count characters in input; 1st version */
int main()
{
	long nc;

	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%1ld\n", nc);
}

//*Editors note* if you try and compile this using GCC with the original %1d in the printf() you will get a warning because %1d is interpreted as an int but we are using a long
//I have updated the code to gcc standards by putting the sub-specifier %1l
//%l is used with long int and unsigned long int

// After compiling and when running in the terminal use <Ctrl + d> to signal EOF... You must press it twice and then the character count will be printed
