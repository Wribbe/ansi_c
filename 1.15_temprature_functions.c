#include <stdio.h>

float toFahrenheit(float temp) 
{
    return ((9.0/5.0) * temp) + 32.0;
}

int main()
{
    float fahrenheit, celsius;
    int start, stop, step;

    start = 0;
    stop = 300;
    step = 20;

    celsius = start;
    while(celsius <= stop) {
        fahrenheit = toFahrenheit(celsius);
        printf("%3.f\t%6.1f\n",celsius,fahrenheit);
        celsius = celsius + step;
    }
}
