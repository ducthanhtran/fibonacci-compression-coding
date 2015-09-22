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


/*
 * Sets the k-th bit in num
 */
inline void setBit(unsigned int *num, int k)
{
    *num |= 1 << k;
}


/*
 * Encodes a positive integer N into a binary codeword with fibonacci numbers as bases
 * Adding a 1-bit and reversing the codeword yiels a prefix code
 */
unsigned int encode_fib(unsigned int N)
{
    // find highest fibonacci number that is equal or smaller than N
    int i = 1;
    while(fibonacciNumber(++i) <= N);
    i -= 1;
    
    // calculate rest of the Zeckendorf-Representation
    unsigned int z_repr = 0;
    while(i > 0)
    {
        if(fibonacciNumber(i) <= N)
        {
            setBit(&z_repr, i);
            N -= fibonacciNumber(i);
            
            // Zeckendorf-Theorem: there are no consecutive 1-bits
            i -= 2;
        }
        else
        {
            i -= 1;
        }
    }
    
    // TODO: Zeckendorf representation finished; add 1-bit (UD-property) and reverse bit-representation to achieve prefix-code
    return enc;
}