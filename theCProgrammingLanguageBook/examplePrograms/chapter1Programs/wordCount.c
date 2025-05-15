// The C Programming Language Book 2nd Edition Example Program
// A program that counts lines, words, and characters
// Written for learning purposes by DBTow

#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

int main()
{
	int c, nc, nw, nl, state;

	state = OUT;
	nc = nw = nl = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == '\n' || c == ' ' || c == '\t')
			state = OUT;
		else if(state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
