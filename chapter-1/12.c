#include <stdio.h>

/* referring to rejecting or accepting spaces, newlines, tabs */
#define REJECT 0
#define ACCEPT 1

main()
{
    int c, state;

    state = ACCEPT;
    while ((c = getchar()) != EOF) {
	if (c == ' ' || c == '\n' || c == '\t') {
	    if (state == ACCEPT) {
		state = REJECT;
		putchar('\n');
	    }
	}
	else {
	    state = ACCEPT;
	    putchar(c);
	}
    }
}

    
