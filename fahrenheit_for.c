#include <stdio.h>

#define LOWER 0
#define UPPER 300 
#define STEP 20

/* print Fahrenheit-Celsius table */
int main()
{
        int fahrenheit;

        for (fahrenheit=UPPER; fahrenheit >= LOWER; fahrenheit = fahrenheit - STEP) {
                printf("%3d %6.1f\n", fahrenheit, (5.0/9.0)*(fahrenheit-32));
        }
}
