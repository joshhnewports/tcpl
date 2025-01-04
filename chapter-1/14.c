#include <stdio.h>

/* only capturing letters and numbers. this is arbitrary */
#define LOWERCASES 26
#define UPPERCASES 26
#define NUMBERS 10
#define HISTOGRAMSIZE LOWERCASES + UPPERCASES + NUMBERS

/* for indexing the histogram */
#define LOWERCASEOFFSET 0
#define UPPERCASEOFFSET LOWERCASES
#define NUMBEROFFSET UPPERCASEOFFSET + UPPERCASES

main()
{
    int c, i, m;
    int histogram[HISTOGRAMSIZE], symbols[HISTOGRAMSIZE];

    for (i = 0; i < HISTOGRAMSIZE; ++i)
	histogram[i] = 0;

    for (i = 0; i < LOWERCASES; ++i) {
	symbols[i+LOWERCASEOFFSET] = i + 'a';
	symbols[i+UPPERCASEOFFSET] = i + 'A';
    }

    for (i = 0; i < NUMBERS; ++i)
	symbols[i+NUMBEROFFSET] = i + '0';
    
    while ((c = getchar()) != EOF) {
	if (c >= 'a' && c <= 'z')
	    ++histogram[c-'a'+LOWERCASEOFFSET];
	else if (c >= 'A' && c <= 'Z')
	    ++histogram[c-'A'+UPPERCASEOFFSET];
	else if (c >= '0' && c <= '9')
	    ++histogram[c-'0'+NUMBEROFFSET];
    }

    for (i = 0; i < HISTOGRAMSIZE; ++i) {
	putchar(symbols[i]); /* how do i printf a symbol? */
	printf(": ");
	for (m = 0; m < histogram[i]; ++m)
	    putchar('*');
	putchar('\n');
    }
}
