main()
{
    /* assume i, lim, c, s, getchar, EOF exist */

    for (i=0; i<lim-1; ++i) {
	if ((c=getchar()) != '\n') {
	    if (c != EOF) {
		s[i] = c;
	    }
	}
    }
}
