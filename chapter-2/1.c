#include <stdio.h>
#include <limits.h>
#include <float.h>

#define UCHAR_MIN 0
#define UINT_MIN 0
#define ULONG_MIN 0
#define USHRT_MIN 0

main()
{
    char i, j;
    
    printf("CHAR:\t%25d%25d\nINT:\t%25d%25d\nLONG:\t%25ld%25ld\nSCHAR:\t%25hd%25hd\nSHRT:\t%25hd%25hd\nUCHAR:\t%25u%25u\nUINT:\t%25u%25u\nULONG:\t%25lu%25lu\nUSHRT:\t%25d%25d\nFLT:\t%25.0e%25.0e\nDBL:\t%25.0e%25.0e\n",
	   CHAR_MIN, CHAR_MAX,
	   INT_MIN, INT_MAX,
	   LONG_MIN, LONG_MAX,
	   SCHAR_MIN, SCHAR_MAX,
	   SHRT_MIN, SHRT_MAX,
	   UCHAR_MIN, UCHAR_MAX,
	   UINT_MIN, UINT_MAX,
	   ULONG_MIN, ULONG_MAX,
	   USHRT_MIN, USHRT_MAX,
	   FLT_MIN, FLT_MAX,
	   DBL_MIN, DBL_MAX);

    /* below computes the range of char. i wont do the others because that is boring */
    
    j = 1;
    for (i = 0; i < j; --i)
	j = i;
    printf("%d\n", j);
	
    j = 0;
    for (i = 1; j < i; ++i)
	j = i;
    printf("%d\n", j);
}

