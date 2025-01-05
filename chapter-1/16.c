#include <stdio.h>
#define MAXLINE 1000

int skibidigetline(char line[], int maxline); /* getline is a function already built in */
void copy(char to[], char from[]);

main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    
    max = 0;
    while ((len = skibidigetline(line, MAXLINE)) > 0)
	if (len > max) {
	    max = len;
	    copy(longest, line);
	}
    if (max > 0)
	printf("length: %d\ntext: %s", max, longest);
    return 0;
}

/* not a fan of this function. too much going on */
int skibidigetline(char s[], int lim)
{
    int c, i, m;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
	s[i] = c;
    if (c == '\n') {
	s[i] = c;
	++i;
    }
    s[i] = '\0';

    if (i == lim - 1) { /* limit reached? */
	s[i-1] = '\n'; /* coerce symbol to be newline */
	for (m = i; (c = getchar()) != EOF && c != '\n'; ++m)
	    ; /* m gets the length of arbitrarily long input lines */
	return m;
    }
    
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
	++i;
}
