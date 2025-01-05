#include <stdio.h>
#define MAXLINE 1000
#define TOLERANCE 80

int skibidigetline(char line[], int maxline); /* getline is a function already built in */
void copy(char to[], char from[]);

main()
{
    int len;
    char line[MAXLINE];
    
    while ((len = skibidigetline(line, MAXLINE)) > 0)
	if (len > TOLERANCE)
	    printf("length: %d\ntext: %s", len, line);
    
    return 0;
}

/* not a fan of this function. too much going on */
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

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
	++i;
}
