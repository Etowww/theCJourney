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

**~.../chapter1Programs/charCount2.c**

printf() uses %f for both *float* and *double*
- %.0f suppresses the printing of the decimal point and the fractional part (in this case zero)

The body of this particular for loop is empty because all the work is done in the test and increment parts
-Grammatical rules of C state that a for statement must have a body
-We use an isolated semicolon (*null statement*) to satisfy that requirement putting it on a separate line for visibility

Observe that if the input contains no characters... the while or for test fails on the very first call to getchar() and the program produces zero... the right answer
-One of the nice things about *while* and *for* is that they test at the top of the loop, before proceeding with the body
-If there is nothing to do, nothing is done, even if that means never going through the loop body

Programs should act intelligently when given zero-length input

---

### 1.5.3 Line Counting

The next program counts input lines
-Remember the standard library ensures that an input text stream appears as a sequence of lines, each terminated by a newline
-Therefore counting lines is just counting the number of newline characters

**~.../chapter1Programs/lineCount.c**

The body of the `while` now consists of an `if` statement which controls the increment ( `++nl` )

The `if` statement tests the parenthesized condition, and if the condition is true, executes the statement (or group of statements in braces) that follows
-Common practice to indent to show what is controlled by the if statement

The double equal sign `==` is the C notation for "is equal to"
-Symbol is meant to distinguish the equality test from the single equals `=` that is used for assignment

A character written between single quotes (like `'\n'`) represents an integer value equal to the numerical value of the character in the machine's character set

This is called a *character constant*

However this is just another way to write a small integer
-take 'A' for example its a character constant but in the ASCII character set its value is 65 (the internal representation of the character A)

The escape sequences used in string constants are also legal in character constants, so `'\n'` stands for the value of the newline character
-Which is 10 in ASCII

Note carefully that `'\n'` is both:
    -A single character and in expressions just an integer
    -A string constant that happens to contain only one character

---

### 1.5.4 Word Counting

The program we will make now counts lines, words, and characters
-Using a loose definition that a word is any sequence of characters that does not contain a blank, tab, or newline
(Bare-bones version of the UNIX program `wc` )

**~.../Chapter1Programs/wordCount.c**

Every time the program encounters the first character of a word, it counts one more word

The variable `state` records whether the program is currently in a word or not
-It is initially set to OUT or "not in word"
-We use the symbolic constants `IN` and `OUT` to the literal values 1 and 0 because they make the program more readable

`nl = nw = c = 0;` This sets all three variables to zero
-This works because an assignment is an expression with the value and assignments associated from right to left

`nl = (nw = (nc = 0));
<---- Left ----- Right

The operator `||` means OR so the line:

`if (c == ' ' || c == '\n' || c == '\t')`

Says that if "if c is blankspace OR c is a newline OR c is a tab"

There is a corresponding operator for AND `&&`
-It has higher precedence than ||

Expressions connected by && or || are evaluated left to right, and it is guranteed that evaluation will stop as soon as the truth or falsehood is known
If c == ' ' (if c is blank) there is no need to test whether it is a newline or tab so these tests are not made


This example also shows an `else` which specifies an alternative action if the condition part of an `if` statement is false

The general form is:

if (expression)
    statement1
else
    statement2

One and only one of the two statements associated with an if-else is performed
-If the expression is true statement1 is executed
-If not statement2 is exected

Each statement can be a single statement or several in braces

In the word count program, the one after the else is an if that controls two statements in braces

---

## 1.6 Arrays

Writing a program to count the number of occurences of each digit, of white space characters (blank / tab / newline), and of all other characters.

There are twelve categories of input... so it is convenient to use an array to hold the number of occurences of each digit rather than ten individual variables

**~.../chapter1Programs/countDigit.c**

The declaration: `int ndigit[10]` declares ndigit to be an array of 10 integers

Array subscripts always start at zero in C, so the elements are ndigit[0], ndigit[1], ..., ndigit[9]
-This is reflected in the `for` loop that initialize and print the array

A subscript can be any integer expression, which includes integer variables like `i`, and integer constants

This particular program relies on the properties of the character representation of the digits:
`if (c >= '0' && c <= '9')`
this test determines whether the character in `c` is a digit... if it is, the numeric value of that digit is: `c - '0'`

This works only if '0', '1', ..., '9' have consecutive increasing values. Fortunately this is true for all character sets.

By definition, `chars` are just small integers, so `char` variables and constants are identical to `ints` in arithmetic expressions

For example: `c-'0'` is an integer expression with a value between 0 and 9 corresponding to the character '0' to '9' stored in c, and thus
a valid subscript for the array `ndigit`

---

### Editors Note
The book doesn't do a very clear job of explaining this so I will try my best to

lets say instead of doing ndigit[c-'0'] you instead put just ndigit[c]
Lets now say that the user running our program typed 3... in ASCII '3' is 51 so ndigit[c] would be ndigit[51] which is not in our array

We do ndigit[c-'0'] to get the integer value of the ASCII character
So for c = '3'

ndigit['3' - '0'] == ndigit[51 - 48] 51-48 = 3 so... ndigit[3] and then we increment by one to count it

we have to subtract by zero (48) to map the ASCII characters '0' through '9' to the array indices integer values 0 through 9

---

The decision as to whether a character is a digit, whitespace or something else is made with this sequence:

`if (c >= '0' && c <= '9')`
`   ++ndigit[c-'0'];`
`else if (c == ' ' || c == '\n' || c == '\t')`
`   ++nwhite;`
`else`
`   ++nother;`

Notice the pattern:

if (condition)
    statement
else if(condition)
    statement
    ...
    ...
else
    statement

This occurs frequently in programs as a way to express a multi-way decision
-The *conditions* are evaluated in order from the top until SOME *condition* is satisfied
At that point the corresponding *statement* is executed, and the entire construction is finished

If none of the conditions are satisfied the *statement* after the final `else` is executed if it is present

If the final `else` and *statement* are omitted, no action takes place

There can be any number of:
else if(condition)
    statement
groups between the initial `if` and the final `else`


It is advised to format the construction as shown... do not indent each `if` past the previous `else`

---

## 1.7 Functions

A function provides a convenient way to encapsulate some computation, which can then be used without worrying about its implementation

With properly designed functions, it is possible to ignore how a job is done... knowing what is done is sufficient

So far we have used only functions like `printf() getchar() and putchar()` that have been provided for us... but now its time to write out own

Since C has no exponentiation operator, we are going to illustrate the mechanics of functions by writing a function that raises an integer `m` to
a positive integer power `n`

For example power(2, 5) is 32... 2^5 = 32

PLEASE NOTE that this function is not a practical exponetiation routine, since it handles only positive powers of small integers
-The standard library contains a function pow(x,y) that computes x^y


**~.../examplePrograms/chapter1Programs/powerFunc.c**

A function defintion has this form:
return-type function-name(parameter declarations, if any)
{
    declarations
    statements
}

Function defintions can appear in any order, and in one source file or several
-NO function can be split between files

If the source program appears in several files, you may have to say more to compile and load it than if it all appears in one, but that is an operating
system matter, not a language attribute

The function `power` is called twice by main, in the line:

`printf("%d %d %d\n", i, power(2,i), power(-3,i));`

Each call passes two arguments to `power` which each time returns an integer to be formatted and printed

In an expression `power(2,i) is an integer just as `2` and `i` are (Not all functions produce an integer value)

The first line of `power` itself:
`int power(int base, int n)`
declares the parameter types and names, the type of the result that the function returns

The names used by `power` for its parameters are local to `power` and are not visible to any other function
-Other routines can use the same names without conflict
-This is also true of the variable `i` and `p`: the `i` in `power` is unrelated to the `i` in `main`

We will generally use *parameter* for a variable named in the parenthesized list in a function
-The terms *formal argument* and *actual argument* are sometimues used for the same distinction

The value that `power` computes is returned to `main` by the `return` statement

Any expression may follow return: `return expression`

A function need not return a value... A return statement with no expression causes control, but not useful value to be returned to the caller

The calling function can ignore a value returned by a function

There is now a `return` staement at the end of `main`
Since `main` is a function like any other, it may return a value to its caller, which in effect is the environment in which the program was executed

Typically, a return value of zero implies normal termination
-Non zero values signal unusual or erroneous termination conditions

In the interests of simplicity, we have omitted `return` statements from our `main` functions up to this point, but we will now include them as programs SHOULD
return status to their environment

The declaration: `int power(int base, int n);` just before `main`
-This says that `power` is a function that expects two int arguments and returns an int

This declaration is called a *function prototype* has to agree with the definition and uses of `power`

It will produce an error if the defintion of a function or any uses of it do not agree with its prototype

Parameter names do not have to agree... parameter names are optional in a function prototype, so for the prototype we could have written:
`int power(int, int);`
(Well-chosen names are good practice and documentation however, so we will use them often)

The biggest change between ANSI C and earlier versions is how functions are declared and defined... In the original definition of C, the `power` function would have looked like this:

power(base, n)
int base, n;
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

The parameters are named between the parentheses and their types are declared before the opening left brace (undeclared parameters are taken as int)
The declaration of `power` at the beginning of the program would have looked like this:
`int power()`
No parameter list was permitted, so the compiler could not readily check that `power` was being called correctly
Since by default `power` would have been assumed to return an int, the entire declaration might well have been omitted


The new syntax of function prototypes makes it much easier for a compiler to detect errors in the number of arguments or their types

---

## 1.8 Arguments - Call by Value

One aspect of C functions is that all functions arguments are passed "by value"
-This means that the called function is given the values of its arguments in temporary variables rather than originals

This is nice because parameters can be treated as conveniently initialized local variables in the called routine

Here is another version of `power()`

int power(int base, int n)
{
    int p;

    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}

The parameter n is used as a temporary variable, and is counted down (a for loop that runs backwards) until it becomes zero
-There is no longer a need for the variable `i`

Whatever is done to `n` inside `power` has no effect on the argument that `power` was originally called with

When necessary, it is possible to arrange for a function to modify a variable in a calling routine... The caller must provide the *address* of the variable to be set
(technically a *pointer* to the variable) and the called function must declare the parameter to be a pointer and access the variable indirectly through it

The story is different for arrays... When the name of an arry is used as an argument, the value passed to the function is the location or address of the beginning of the array
-There is no copying of array elements
-By subscripting this value the function can access and alter any argument of the array

---

## 1.9 Character Arrays

The most comon type of array in C is the array of characters...
To illustrate the use of character arrays and functions to manipulate them... let's write a program that reads a set of text lines and prints the longest

**~/.../chapter1Programs/longestLine.c**

The functions `getLine()` and `copy()` are declared at the beginning of the program (which we assume is contained in one file)

`main()` and `getLine()` communicate through a pair of arguments and a returned value

`int getline(char s[], int lim);`
This line declares the arguments
-Specifies that the first argument, `s` is an array / the second argument is `lim` which is an integer

The purpose of supplying the size of an array in a declaration is to set aside storage

The length of an array `s` is not necessary in `getline()` since its size is set in `main`

`getline()` uses return to send a value back to the caller
The declaration declares that `getLine()` return an int... (since int is the default return type, it could be omitted)

Some functions return a useful value; others, like `copy()` are used only for their effect and return no value
The return type of `copy()` is `void`, which states explicitly that no value is returned

`getLine()` puts the character '\0' (the null character, whose value is zero) at the end of the array it is creating, to mark the end of the string of characters

This conversion is also used by the C language... lets take for example a string constant like:
"hello\n"
It is stored as an array of characters containing the characters in the string and terminated with a '\0' to mark the end

h e l l o \n \0

The %s format specification in printf() expects the corresponding argument to be a string represented in this form.

`copy()` also relies on the fact that its input argument is terminated with a '\0', and copies this character into the output

This program has some design problems...
What should main() do if it encounters a line which is bigger than its limt?
-getLine() works safely, in that it stops collecting when the array is full, even if no newline has been seen

By testing the length and the last character returned, main() can determine whether the line was too long, and then cope as it wishes...

There is no way for a user of getLine() to know in advance how long an input line might be, so getLine() checks for overflow
-On the other hand, the user of `copy()` already knows how big the strings are, so we have chosen not to add error checking to it

---

## 1.10 External Variable and Scope

The variables in `main()` such as `line, longest` are private or "local" to `main()` because they are declared within `main` no other function can have direct access to them

The same is true of the variables in other functions... for example, the variable i in `getLine()` is unrelated to the i in `copy()`

Each local variable in a function comes into existence only when the function is called, and disappears when the function is exited. This is why such variables
are usually known as *automatic variables*
Automatic = local variables

Because automatic variables come and go with function invocation, they do not retain their values from one call to the next... and must be explicitly
set upon each entry otherwise they will contain garbage

As an alternative to automatic variables, it is possible to define variables that are *external* to all functions...
-Variables that can be accessed by name by any function

Because external variables are globally accessible, they can be used instead of argument lists to communicate data between functions

External variables retain their values even after the functions that set them have returned

An external variable must be DEFINED exactly once, outside of any function... (this sets aside storage for it)

The variable must also be *declared* in each function that wants to access it... this states the type of the variable

The declaration may be an explicit `extern` statment or may be implicit from context

Rewrite longest line program with external variables
**~/.../chapter1Programs/externalVar.c**

`line`, `longest`, and `max` set as external variables

The external variables in all three functions are defined by the first lines of the program which state their type and cause storage to be allocated for them.

Before a function can use an external variable, the name of the variable must be made known to the function; the declaration is the same as before except
for the added keyword `extern`

In certain circumstances the `extern` declaration may be omitte
-If the definition of the external variable occurs in the source file before its use in a particular function, then there is no need for an extern declaration

Thus are extern declarations in main() getLine() and copy() are redundant

Common practice is to place definitions of all external variables at the beginning of the source file, and then omit all extern declarations.

If the program is in several source files, an a variable is defined in file1 and used in file2 and file3... then `extern` declarations are needed
in file2 and file3 to connect the occurences of the variable

The usual practice is to collect extern declarations of variables and functions in a separate file, historically called a *header* that is included by a `#include` at the front
of each source file
-The suffix .h is a conventional for header names

-Take the standard library for example... declared in headers like `#include <stdio.h>`

Since the specialized versions of getline() and copy() have no arguments, logic would suggest that their prototypes at the beginning of the file should be
getline() and copy() but for compatibility with older C programs the standard takes an empty list as an old-style declaration and turns off all arugment list checking...

The word `void` must be used for an explicitly empty list

You should note that we are using the words *definition* and *declaration* carefully when referring to external variables
-"Definition" refers to the place where the variable is created / assigned storage
-"Declaration" refers to the places where the nature of the variable is stated by no storage is allocated

There is a tendency to make everything an `extern` variable...
-They are always there went you want them
-... But then they are always there when you don't want them as well

The problem is that it leads to programs whose data connections are not all obvious... variables can be changed in unexpected and even inadvertent ways, making the program hard to modify

Our second version of the longest-line program is inferior to the first
-it destroys the generality of two useful functions by wrting into them the names of the variables they manipulate

AT THIS POINT we have covered the conventional core of C.
-With these useful building blocks we can write programs of considerable size and complexity
-Highly encouraged to complete the exercizes

**END OF CHAPTER 1**
