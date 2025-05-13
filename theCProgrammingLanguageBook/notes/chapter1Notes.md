#C Programming Language 2nd Edition
##Written by: Brian W. Kernighan and Dennis M. Ritchie
###Personal Notes written by DBTow

#Chapter 1 - A Tutorial Introduction

##1.1 Getting Started
The first program you should write is the same for all languages:
-Print the words "hello world"

In C, the program to print "hello, world" is:

`#include <stdio.h>

main()
{
    printf("hello, world\n");
}
`
**To run the program** (Outdated)
On a unix operating system you must create the program in a file whose name ends in ".c" such as hello.c
-then compile it with the command cc hello.c
this will produce an executable file called a.out
-if you run a.out it will print the "hello, world"

###Editors Notes
Two Things:
(1)I am learning C on a MacOS using the GCC compiler and will compile things in this manner

$ gcc example.c -o example
(Ensure you are in the directory of the file so in this case the directory holding /example.c)
this produces an executable file: ./example

I will not be adding notes or code to ensure compatibility with other operating systems. If you are following along on a different OS I encourage you to
to learn how to compile and run C code on your own.

(2)The standard this book is using is outdated and with the GCC compiler's standard the main() function must return an integer

Therefore in both the notes and example code going forward I will use either the two standard-compliant forms for main:
-int main(void) -int main(int argc, char *argv[])

The return value of main is used as the programs exit status, typically with 0 indicating success
-return 0;


**The first C program** (updated to appropriate gcc standards)
`#include <stdio.h>

int main()
{
    printf("hello, world\n");
}
`
A C program, whatever size, consists of *functions* and *variables*

-A function contains statements that specify the computing operations to be done
-Variables sotre values used during computations

Our example is a function named main()
-Normally you are at the liberty to give functions whatever name you like but "main" is special

Your program begins executing at the beginning of main
-This means every program must have a main somewhere

main() will usually call other functions to help perform its job, some that you wrote, and others from libraries that are provided for you

`#include <stdio.h>`
-This line tells the compiler to include information about the standard input/output library

One method of communicating data between functions is for the calling function to provide a list of values, called *arguments* to the function it calls
-The parentheses after the function name surround the argument list
-In our example main is defined to be function that expects no arguments, indicated by the empty list ()

A function is called by naming it, followed by a parenthesized list of arguments
`printf("hello, world\n")`
-The function printf() is a library function that prints output
-it is given the argument "hello, world\n"

A sequence of characters in double quotes like "hello, world" is called a *character string* or *string constant*

The sequence \n in the string is C notation for *newline character*
-When printed advances the output to the left margin on the next line

printf() never supplies a newline character automatically, so several calls may be used to build up an output line in stages

Note that \n represents only a single character
\n is an *escape sequence*
-This provides a mechanism for representing hard-to-type or invisible characters

\t = tab
\b = backspace
\" = for the double quote
double backslash = for the backslash itself

---

##1.2 Variables and Arithmetic Expressions
