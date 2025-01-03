#include <stdio.h>

#define WORDLENGTH 15

main()
{
    int c, i, m, length;
    int histogram[WORDLENGTH];

    length = 0;
    for (i = 0; i < WORDLENGTH; ++i)
	histogram[i] = 0;

    while ((c = getchar()) != EOF) {
	if (c == ' ' || c == '\n' || c == '\t') {
	    if (length != 0)
		++histogram[length];
	    length = 0;
	}
	else
	    ++length;
    }

    for (i = 1; i < WORDLENGTH; ++i) {
	printf("%2d: ", i);
	for (m = 0; m < histogram[i]; ++m)
	    putchar('*');
	putchar('\n');
    }
}
