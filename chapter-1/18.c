#include <stdio.h>
#define MAXLINE 1000
#define TRAILING 1
#define NONTRAILING 0

int skibidigetline(char line[], int maxline); /* getline is a function already built in */
void notrail(char a[], char b[]);

/* get the line then trim trailing space. im not going to do both at once */
main()
{
    int len;
    char line[MAXLINE];
    char text[MAXLINE];
    
    while ((len = skibidigetline(line, MAXLINE)) > 0) {
	notrail(text, line);
	printf("%s", text);
    }
    
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

/* horrible function */
void notrail(char to[], char from[])
{
    int i, m, state, lastsymbolindex;

    /* remove space on the left while copying the array */
    m = 0; /* tracking index of to[] */
    state = TRAILING; /* assume we are passing through trailing space */
    lastsymbolindex = -1; /* index of last nonspace symbol put in to[] */
    for (i = 0; from[i] != '\0'; ++i) {
	if (state == NONTRAILING) {
	    if (from[i] != ' ' && from[i] != '\t' && from[i] != '\n')
		lastsymbolindex = m;
	    to[m] = from[i];
	    ++m;
	}
	else if (from[i] != ' ' && from[i] != '\t' && state == TRAILING) { /* first nonspace? */
	    lastsymbolindex = m;
	    to[m] = from[i];
	    ++m;
	    state = NONTRAILING;
	}
    }

    /* i sure hope we are within MAXLINE */
    if (lastsymbolindex != -1) { /* was lastsymbolindex mutated? then to[] is nonempty */
	to[lastsymbolindex+1] = '\n'; /* force a newline in */
	to[lastsymbolindex+2] = '\0'; /* remove space on the right */
    }
}
