#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300 */
int main() 
{
        float fahrenheit, celsius;
        int lower, upper, step;

        lower = 0;
        upper = 300;
        step = 20;

        fahrenheit = lower;
        printf("Fahrenheit\tCelsius\n");
        while (fahrenheit <= upper) {
                celsius = (5.0/9.0) * (fahrenheit-32);
                printf("%6.0f\t\t%6.1f\n", fahrenheit, celsius);
                fahrenheit = fahrenheit + step;
        }
}
