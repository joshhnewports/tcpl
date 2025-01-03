#include <stdio.h>

#define REJECT 0
#define ACCEPT 1

main()
{
    int c, flag;

    flag = ACCEPT;
    while ((c = getchar()) != EOF) {
	if (c == '\t') {
	    flag = REJECT;
	    putchar('\\');
	    putchar('t');
	}
	if (c == '\b') {
	    flag = REJECT;
	    putchar('\\');
	    putchar('b');
	}
	if (c == '\\') {
	    flag = REJECT;
	    putchar('\\');
	    putchar('\\');
	}

	if (flag == ACCEPT)
	    putchar(c);

	flag = ACCEPT;
    }
}
