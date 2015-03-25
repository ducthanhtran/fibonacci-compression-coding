/*
 * fibonacci_coding.c
 * Author: Duc Thanh Tran
 */
#include <math.h>

/*
 * Calculates i-th fibonacci-number (based on Moivre-Binet)
 * where we start with 1 and ignore the duplicate 1 at the beginning, i.e.
 * the fibonacci sequence is: 1, 2, 3, 5, 8, ...
 */
unsigned int fibonacciNumber(int n)
{
    if(n <= 2)
    {
        return n;
    }
    double phi = (1 + sqrt(5.0)) / 2.0;
    return round(pow(phi,n+1) / sqrt(5.0));
}