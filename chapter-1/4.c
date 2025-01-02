#include <stdio.h>

main()
{
    float fahr, celsius;        /* float not necessary because all fahr values are integers */
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("celsius->fahr\n");
    
    celsius = lower;
    while (celsius <= upper) {
	fahr = (9 * celsius) / 5 + 32;          /* celsius is a float so the operands are converted */
	printf("%7.0f%6.0f\n", celsius, fahr);  
	celsius = celsius + step;
    }
}
    
