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
 * Sets the k-th bit in num. If k=0, then we practically set the 0th bit, which equals 1 in decimal system.
 */
static inline void setBit(unsigned int *num, int k)
{
    *num |= 1 << k;
}


/*
 * Computes reverses bit representation from bitStr
 */
static inline unsigned int computeRevBitStr(unsigned int bitStr)
{
    const int c = 1;
    unsigned int revBitStr = 0;
    
    while(bitStr > 0)
    {
        // get least significant bit
        int lsb = bitStr & c;
        
        // shift bitStr, and get next least significant bit in next step. 
        // Exploit property, that there are no consecutive ones.
        if(lsb == 0)
        {
            bitStr = bitStr >> 1;
            revBitStr = revBitStr << 1;
        }
        else
        {
            bitStr = bitStr >> 2;
            revBitStr = revBitStr << 2;
        }
        
        // update reverse bit string
        revBitStr |= lsb;
    }
    return revBitStr;
}


/*
 * Encodes a positive integer N into a binary codeword with fibonacci numbers as bases.
 * Adding a 1-bit and reversing the codeword yields a prefix code
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
            setBit(&z_repr, i-1);
            N -= fibonacciNumber(i);
            
            // Zeckendorf-Theorem: there are no consecutive 1-bits
            i -= 2;
        }
        else
        {
            i -= 1;
        }
    }
    
    // compute reverse bit representation
    unsigned int enc = computeRevBitStr(z_repr);
    
    // add 1-bit to the end of the representation (prefix code property)
    enc = (enc << 1) | 1;
    
    return enc;
}