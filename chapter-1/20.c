#include <stdio.h>

#define TABBLANKS 8

void detab(char to[], char from[]);
void detabi(char to[], char from[], int m, int n, int spaces);
int skibidigetline(char s[], int lim);

main()
{
    int i, len;
    char text[50], result[50];

    for (i = 0; i < 50; ++i)
	text[i] = 0;

    while ((len = skibidigetline(text, 50)) > 0) {
	detab(result, text);
	printf("%s", result);
    }
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
	if (spaces == 0)
	    detabi(to, from, ++m, ++n, TABBLANKS);
	else
	    detabi(to, from, ++m, ++n, spaces-1);
    }
}

int skibidigetline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
	s[i] = c;
    if (c == '\n') {
	s[i] = c;
	++i;
    }
    s[i] = '\0';
    
    return i;
}
