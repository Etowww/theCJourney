// The C Programming Language 2nd Edition Book Example Program
// Program reads a set of text lines and prints the longest line
// Written for learning purposes by DBTow

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
	int len;	/* current line length */
	int max;	/* maximum length seen so far */
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE]; /* longest line saved here */

	max = 0;
	while ((len = getLine(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%s", longest);
	return 0;
}

/* getLine(): read a line into s, return length */
int getLine(char s[], int lim)
{
	int c, i;

	for(i=0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy(): copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from [i]) != '\0')
		++i;
}

// Editors Note: The book names their function getline() but I had to revise that to getLine() the reason being in the GNU C libraries (macOS)
// the function getline() already exists as a standard library function which causes a conflict
