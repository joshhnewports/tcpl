#include <stdio.h>

#define REJECT 0
#define ACCEPT 1

main()
{
    int c, flag;

    flag = ACCEPT;
    while ((c = getchar()) != EOF) {
	if (c == ' ') {
	    if (flag == ACCEPT) {
		flag = REJECT;
		putchar(c);
	    }
	}
	if (c != ' ') {
	    flag = ACCEPT;
	    putchar(c);
	}
    }
}
