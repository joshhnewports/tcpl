#include <stdio.h>

#define TABBLANKS 8

void detab(char to[], char from[]);
void detabi(char to[], char from[], int m, int n, int spaces);

main()
{
    /* usage here */
}

void detab(char to[], char from[])
{
    detabi(to, from, 0, 0, TABBLANKS);
}

void detabi(char to[], char from[], int m, int n, int spaces)
{
    int i;
    
    if (from[n] == '\0')
	to[m] = from[n];
    else if (from[n] == '\t') {
	for (i = 0; i < spaces; ++i)
	    to[i+m] = ' ';
	detabi(to, from, m+spaces, ++n, TABBLANKS);
    }
    else {
	to[m] = from[n];
	if (spaces == 1)
	    detabi(to, from, ++m, ++n, TABBLANKS);
	else
	    detabi(to, from, ++m, ++n, spaces-1);
    }
}
