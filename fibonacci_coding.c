#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long ull;

// Calculates i-th fibonacci-number (based on Moivre-Binet)
// where we start with 1 and ignore the duplicate 1 at the beginning, i.e.
// the fibonacci sequence is: 1, 2, 3, 5, 8, ...
static ull fibonacciNumber(const int n) {
    if(n <= 2) {
        return n;
    }
    const double phi = (1 + sqrt(5.0)) / 2.0;
    return round(pow(phi, n+1) / sqrt(5.0));
}

// Sets the k-th bit in num. If k=0, then we practically set the 0th bit, which equals 1 in decimal system.
static inline void setBit(ull *num, const int k) {
    *num |= (1 << k);
}

// Reverses bit representation of number
// TODO: check
static ull reverse(const ull inputNumber) {
    ull revnumber = 0;
    ull number = inputNumber;

    while(number > 0) {
        // get least significant bit
        const ull lsb = number & 1;

        if(lsb == 0) {
            // shift number, and get next least significant bit in next step.
            number = number >> 1;
            revnumber = revnumber << 1;
            printf("shift 0: %llu | %llu\n", number, revnumber);
        }
        else {
            // exploit property, that there are no consecutive ones.
            number = number >> 2;
            revnumber = revnumber << 2;
            printf("shift 1: %llu | %llu\n", number, revnumber);
        }

        // update reverse number
        revnumber |= lsb;
        printf("update %llu\n", revnumber);
    }
    return revnumber;
}

// Finds smallest index i, such that i-th Fibonacci number
// is greater or equal to N
static int smallestFibonacciIndex(const ull N) {
    int i = 0;
    while(fibonacciNumber(i) < N) {
        ++i;
    }
    return i;
}

// Computes the binary Zeckendorf representation
// of a positive integer N.
static ull zeckendorf(const ull N) {
    const int index = smallestFibonacciIndex(N);

    // TODO

    return 0;
}


/*
 * Encodes a positive integer N into a binary codeword with fibonacci numbers as bases.
 * Adding a 1-bit and reversing the codeword yields a prefix code
 */
 /*
ull encode_fib(const ull N) {
    // find highest fibonacci number that is equal or smaller than N
    int i = 1;
    while(fibonacciNumber(++i) <= N);
    i -= 1;

    // calculate rest of the Zeckendorf-Representation
    unsigned int z_repr = 0;
    while(i > 0) {
        if(fibonacciNumber(i) <= N) {
            setBit(&z_repr, i-1);
            N -= fibonacciNumber(i);

            // Zeckendorf-Theorem: there are no consecutive 1-bits
            i -= 2;
        }
        else {
            i -= 1;
        }
    }

    // compute reverse bit representation
    unsigned int enc = computeRevBitStr(z_repr);

    // add 1-bit to the end of the representation (prefix code property)
    enc = (enc << 1) | 1;

    return enc;
}
*/

int main(int argc, char* argv[]) {
    if(argc == 2) {
        char* end;
        const ull input = strtoull(argv[1], &end, 10);

        ull out = reverse(input);
        printf("%llu\n", out);
    }
    return 0;
}
