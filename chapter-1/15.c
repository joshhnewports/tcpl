#include <stdio.h>

float celsius(float fahr);
int convert(int lower, int upper, int step);

main()
{
    return convert(0, 300, 20);
}

float celsius(float fahr)
{
    return (5.0/9.0) * (fahr-32.0);
}

/* function that only computes side-effects (printf). functions that only print are dangerous! */
int convert(int lower, int upper, int step)
{
    if (lower > upper)
	return 0; /* everything will return something. and thats a good thing. */
    else {
	printf("%3d%6.1f\n", lower, celsius(lower + 0.0));
	convert(lower + step, upper, step); /* theyre letting me recurse this early? its over */
    }
}
