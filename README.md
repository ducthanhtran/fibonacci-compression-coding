# Fibonacci Compression Coding
*Universal Code for encoding positive integers into binary code words using fibonacci numbers of 2nd order as bases*

## Introduction
According to [Zeckendorf's Theorem](http://en.wikipedia.org/wiki/Zeckendorf%27s_theorem) every positive integer has an unique representation as a sum of fibonacci numbers (Zeckendorf Representation) such that it does not include any two adjacent fibonacci numbers. We can encode such a representation with a binary string, where each i-th bit stands for the i-th fibonacci number. In the following we use the fibonacci sequence 1, 2, 3, 5, 8, 13, 21, 34, 55, ...; that is we omit the first "1".

Example: 73 = 55 + 13 + 5, binary codeword: 100101000 (leftmost leading bit is most significant bit)

### Unique Decipherability
#### Definition
We denote by codewords binary strings. A *code C* is a finite set of codewords and a *code-string M* is created by concatenating codewords from *C* where repetitions of codewords are allowed. *M* is called **uniquely decipherable** (UD) if there is only one way to write *M* as a concatenation of codewords from *C*.
In addition, *C* is called UD if and only if **every** code-string concatenated from *C* is UD.

*Appendix: The UD problem. Given a (finite) set C of codewords, determine whether C is UD.*

#### How to achieve unique decipherability?
Because consecutive ones cannot appear in any codeword (Zeckendorf), we can prefix a single 1-bit to our codewords in order to identify boundaries between different codewords, that is, it acts as a "comma". Thus we are able to differentiate codewords in concatenations/strings of codewords.

Example: 11001 1101 stands for 6=5+1 followed by 4=3+1. In particular, every time we encounter two consecutive 1-bits we decode the string followed after the first bit which represents a positive integer.

### Prefix Code
Complications may occur during the decoding phase of code-strings. This problem is shown here by using repetitions of the codeword 11 which is the only (valid) codeword having no zeros.
Suppose we have an encoded string 11011111110. This could be parsed into 110 **|** 11 **|** 11 **|** 11 **|** 10. This however is not a valid breakdown as 10 is not a valid codeword; therefore we need to re-check the first codewords again and finally parse it to 1101 **|** 11 **|** 11 **|** 110.

In order to avoid such problems we simply reverse all codewords which forms a **prefix code**, that is no codeword is a prefix of any other codeword. Due to reversing, two consecutive ones now mark the end of a codeword. Consider the example above, after reversing the encoded string parsing results into:
1011 **|** 11 **|** 11 **|** 011

// TODO: how to encode/decode/(efficiency)??

## Technical
### Compilation
Note that you need to link against the math library, that is, you need the additional compiler option `-lm` (GCC C Compiler).

## References
1. [Robust Transmission of Unbounded String Using Fibonacci Representations - Alberto Apostolico, Aviezri S. Fraenkel](http://docs.lib.purdue.edu/cgi/viewcontent.cgi?article=1463&context=cstech)
2. [On the Usefulness of Fibonacci Compression Codes - Shmuel T. Klein, Miri Kopel Ben-Nissan](http://u.cs.biu.ac.il/~tomi/Postscripts/fib-rev.pdf)
