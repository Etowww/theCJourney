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

To show that there are different ways to write a program we are going to code a new variation of the temperature converter using a for statement

**Code can be found at ~/theCProgrammingLanguageBook/examplePrograms/chapter1Programs/forTemp.c**

One major change is the elimination of most of the variables... only fahr remains and we have made it an int
-The lower and upper limits and the step size appear only as constants in the for statement
-The expression that computes the Celsius temperature now appears as the third argument of printf() instead of a separate assignment statement

Pertaining to the last change...
-In any context where it is permissible to use the value of some type, you can use a more complicated expression of that type
-> Since the third argument of printf must be a floating-point value to match the %6.1f, any floating point expression can occur here

The *for* statement is a loop... a generalization of the *while* loop.

For loops have three parts separated by semicolons (;)
-Initialization
`fahr = 0`
This is done once before the loop proper is entered

-Test or Condition
This is the second part that controls the loop
`fahr <= 300`
This condition is evaluated... if it is true the body of the loop is executed then the last part of the loop occurs ->

-Increment step
`fahr = fahr + 20`
This gets executed and then the condition is re-evaluated...

The loop terminates if the condition has become false

Similar to *while* the body of the loop can be a single statement or a group of statements enclosed in braces
-The initialization / condition / and increment can be any expression

The choice between while and for loops is arbitrary, based on which seems clearer...
-The for is usually appropriate for loops in which the initialization and increment are single statements and logically related

---

## 1.4 Symbolic Constants

Its bad practice to bury "magic numbers" like 300 and 20 in a program... they convey little information to someone trying to read the program
-They are also hard to change in a systematic way

One way to deal with magic numbers is to give them meaningful names... a #define line defines a *symbolic name* or *symbolic constant* to be a particular string of characters:
`#define` *name* *replacement list*

Thereafter, any occur of the *name* (not in quotes and not part of another name) will be replaced by the corresponding *replacement list*

The *name* has the same form as a variable... a sequence of letters and digits beginning with a letter
The *replacement list* can be any sequence of characters... it is not limited to numbers

**code can be found at ~/theCProgrammingLanguageBook/examplePrograms/chapter1Programs/symbolicTemp.c**

The quantities LOWER, UPPER, and STEP are symbolic constants NOT variables, so they do not appear in declarations

Symbolic constants are traditionally written in uppercase to be distinguishable from regular variables (lower case)
-Note that there is no semicolon at the end of a #define line

---

## 1.5 Character Input and Output
The model of input and output supported by the standard library is very simple... ->

Text input or output (regardless of where its going to) is dealt with as streams of characters

A *text stream* is a sequence of characters divided into lines...
-Each line consists of zero or more characters followed by a newline character

It is the responsibility of the library to make each input or output stream confirm this model...
-The C programmer need not wory about how lines are represented outside the program

The standard library provides several functions for reading or writing one characterat a time, of which *getchar* and *putchar* are the simplest

Each time it is called *getchar* reads the next input character from a text stream and returns that as its value

`c = getchar();`
-The variable c contains the next character of input
-The characters normally come from the keyboard

The function *putchar* prints a character each time it is called

`putchar(c);`
-prints the contents of the integer variable c as a character, usually on screen

Calls to putchar() and printf() may be interleaved the output will just appear in the order in which the calls are made

### 1.5.1 File Copying
You can write a suprising amount of useful code without knowing anything more about input and output (getchar and putchar)

The next example program copies its input to its output one character at a time

**can view this code at ~/theCProgrammingLanguageBook/examplePrograms/chapter1Programs/fileCopying.c**

The relational operator != means "not equal to"

What appears to be a character on the keyboard or screen is of course, like everything, stored internally just as a bit pattern

The type *char* is specifically meant for storing such character data (however any integer type can be used)

We used *int* for a subtle but important reason
-The problem is distinguishing the end of input from valid data... the solution is that *getchar* returns a distinctive value when there is no more input...
a variable that cannot be confused with any real character

This value is called *EOF* or "end of file"
-We must declare the variable c to be a type big enough to hold any value that *getchar* returns

We can't use the type *char* because the variable c must be big enough to hold EOF in addition to any possible *char*... therefore we use the type *int*

EOF is an integer defined in <stdio.h>, but the specific numeric value doesn't matter as long as it is not the same as any *char* value
EOF is also a symbolic constant
-By using the symbolic constant, we are assured that nothing in the program depends on the specific numeric value


The program could be written more concisely:

`#include <stdio.h>

/* copy input to output; 2nd version */
int main()
{
    int c;

    while ((c = getchar()) != EOF)
        putchar(c);
}
`

`c = getchar()` is an expression and has a value
-This means we can use this assignment as part of a larger expression

We put the assignment of the character inside the test part of the while loop
-The *while* get a character, assigns it to c, and then tests whether the character was the end-of-file signal...
-If its not the body of the while is executed, printing the character(putchar), then the *while* repeats

When the end of the input is finally reached, the *while* terminates and so does *main*

This version centralizes the input... now only one reference to getchar()

The parentheses around the assignment, within the condition are necessary...
-The *precedence* of != is higher than that of =

This means that in absence of parentheses the relational test != would be done before the assginment =
-The statement `c = getchar() != EOF` is equivalent to `c = (getchar() != EOF)
-This has the undesired effect of setting C to 0 or 1 depending on whether or not the call of getchar returned end of file

---

### 1.5.2 Character Counting

The next program counts characters

**Can view this program at ~/theCProgrammingLanguageBook/exampleProgram/chapter1Programs/charCount.c**

The statement `++nc;` presents a new operator `++` which means increment by one
-You could write `nc = nc + 1` but `++nc` is more concise and often more efficient

There is a corresponding operator `--` to decrement by one

The operators ++ and -- can be either prefix operators (++nc) or postfix operators (nc++)
-These two forms have different values in expressions
-For the moment we will stick to the prefix form

The character counting program accumulates its count in a variable type *long* instead of an *int*
-Long integers are at least 32 bits
-On some machines int and long are the same size... On others an int is 16 bits, with a maximum value of 32767
It would take relatively low input to overflow an int counter

The conversion specification %1d tells printf that corresponding argument is a *long* integer

-It may be possible to cope with even bigger numbers by using a type *double* (double precision float)

We can also use a for statement instead of a while, to illustrate the program in another way.
