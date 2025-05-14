# C Programming Language 2nd Edition
## Written by: Brian W. Kernighan and Dennis M. Ritchie
### Personal Notes written by DBTow

# Chapter 1 - A Tutorial Introduction

## 1.1 Getting Started
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

---

### Editors Notes
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

---

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

## 1.2 Variables and Arithmetic Expressions
The next program we are working on uses the formal C=(5/9)(F-32) to print a table of Farenheit temperatures and their Celsius equivalent
-In includes several new ideas: comments / declarations / variables / arithmetic expressions / loops / and formatted output

**You can find the example program at ~/theCProgrammingLanguageBook/examplePrograms/chapter1Programs/temp.c**

The line /* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */
is a *comment*
-Any characters between /* and */ are ignored by the compiler... meaning they may be used freely to make a program easier to understand

/* */ are multi-line comments
// are single line comments

In C, all variables must be declared before they are used:
`int fahr, celsius;
int lower, upper, step;
`
A *declaration* announces the properties of variables... it consists of a name and a list of variables
-Declarations are usually at the beginning of the program before any executable statements

The type `int` means that the variables listed are integers

The type `float` means that the variable would be a floating point number (have a fractional part)

The range of both int and float depends on the machine you are using:
-16-bit ints lie between (-32768 and +32767) are common / As are 32-bit ints

A float number is typically a 32-bit quantity, with at least six significant digits and magnitude generally between about 10^-38 and 10^38

C provides several other data types including:
    -char = character (a single byte)
    -short = short integer
    -long = long integer 
    -double = double-precision floating point
The size of these objects is also machine-dependent

Other data types include *arrays* / *structures* / *unions* as well as *pointers* to them and *functions* that return them

Computation in the temp conversion program begins with the assignment statements which set the variables to their intial values

-Individual statements are terminated by semicolons ;

Each line of the table is computed the same way (printed out) so we use a loop that repeats once per output line... this is the purpose of the *while* loop
`while (fahr <= upper) { ... }`

The while loop operates as follows:

-The condition in parentheses is tested
If it is true that the variable fahr is less than or equal to the variable upper... the body of the loop is executed

-Then the condition is retested... if true the body is executed again

-When the test becomes false (fahr exceeds upper) the loop ends and execution continues at the statement that follows the loop

In our program there are no further statments so the program is terminated

The body of a while can be one or more statements enclosed in braces {} or as a single statement without braces
-In either case, we always indent the statements controlled by the while loop by one tab stop

Although C compilers do not care about how a program looks, proper indentation and spacing are critical in making programs easy for people to read
Recommended best practice:
-One statement per line
-using blanks around operators to clarify grouping

In the temp conversion program most of the work gets done in the body of the loop:
`celsius = 5 * (fahr-32) / 9;`

-The reason for multiplying by 5 and divding by 9 instead of just multiplying by 5/9 is that in C, integer division *truncates*
-This means any fractional part is discarded

Since 5 and 9 are integers 5/9 would be truncated to zero and so all Celsius temps would be reported as zero

Our program also show how printf() works... printf() is a general-purpose output formatting function

It's first argument is a string of characters to be printed, with each % indicating where one of the other arguments is to be substituted, and in what form it is to be printed
-For instance, %d specifies an integer argument

`printf("%d\t%d\n", fahr, celsius);`
-This statement causes the values of the two integers to be printed, with a tab(\t) between them

Each % construction in the first argument of printf() is paired with the corresponding argument...
-They must match up properly by number and type or you will get wrong answers

printf() is not part of the C language... there is no input or output defined in C itself
-printf() is just a useful function from the standard library of functions that are normally accessible to C programs
-the behavior of printf() is defined in the ANSI standard so its properties should be the same with any compiler and library that conforms to ANSI

There are a couple of problems with the temperature conversion program...
-output statements are not right justified
-More serious problem is that because we used integer arithmetic the Celsius temperatures are not very accurate

To fix the look of the output we augment each %d in the printf statement with a width, the numbers printed will be right justified in their fields
`printf("%3d %6d\n, fahr, celsius);
-prints the first number of each line in a field three digits wide, and the second in a field six digits wide

To get more accurate temperature calculations we should use floating-point arithmetic instead of integer.

**New changes reflected in the program ~/theCProgrammingBook/examplePrograms/Chapter1Programs/floatingTemp.c**

This program is much the same as before except that fahr and celsius are declared to be of the type *float* and the formula for conversion is written in a more natural way
-Previously unable to use 5/9 because integer division would truncate to zero
-A decimal point in a constant indicates that it is a floating point, so 5.0/9.0 is not truncated because it is the ratio of two floating-point values

If an arithmetic operator has integer operands, an integer operation is performed

-If an arithmetic operator has one floating-point operand and one integer operand... the integer will be converted to floating point before the operation is done

If we had written (fahr-32), the 32 would be automatically converted to floating point
-Nonetheless writing floating-point constants with explicit decimal points even when they have integral values makes it more pronounced their floating point nature for others

Notice that the assignment fahr = lower; (fahr = 0) and the test `while (fahr <= upper)` also work in the natural way the int is converted to float before operation is done

The printf() conversion specification %3.0f says that a floating point number is to printed at least three characters wide with no decimal point and no fraction digits
-%6.1f describes another number to be printed at least six characters wide, with 1 digit after the decimal point

Width and precision may be omitted from a specification... for example:
-%6f says that the number is to be at least six characters wide
-%.2f specifies two characters after the decimal point, but the width is not constrained
-%f says to print the number as floating point

Among others... printf() also recognizes:
-%o for octal
-%x for hexadecimal
-%c for character
-%s for character string
-%% for itself

---

## 1.3 The for statement



