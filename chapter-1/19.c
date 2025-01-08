#include <stdio.h>

#define MAXLINE 100

int skibidigetline(char line[], int maxline);
void reverse(char to[], char from[], int len);
void reversei(char to[], char from[], int m, int n);

main()
{
    int len;
    char line[MAXLINE];
    char result[MAXLINE];

    while ((len = skibidigetline(line, MAXLINE)) > 0) {
	reverse(result, line, len);
	printf("%s", result);
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

/* this reverse function is not a direct reverse. it enforces a newline at the end */
/* len is how many elements in from, including an ending newline if there exists one */
/* from[len] is '\0' */
void reverse(char to[], char from[], int len)
{
    /* len decides where to start reversing from. we exclude \0 and \n if it exists */
    if (from[len-1] == '\n') /* if from ends with a newline */
	reversei(to, from, 0, len-2); /* do not copy the newline to the beginning of to */
    else
	reversei(to, from, 0, len-1); /* no newline in from? then directly reverse from */
}

/* m is the index for to, n for from */
void reversei(char to[], char from[], int m, int n)
{
    if (from[m] == '\0') /* should to have a null character here? */
	to[m] = '\0'; /* then terminate to here */
    else if (from[m] == '\n') { /* should to have a newline here? */
	to[m] = '\n'; /* copy the newline at the end of from to the current position in to */
	reversei(to, from, ++m, --n); /* alternatively: to[m+1] = '\0'; */
    }
    else {
	to[m] = from[n];
	reversei(to, from, ++m, --n);
    }
}
