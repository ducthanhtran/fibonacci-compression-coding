# Fibonacci Compression Coding
*Universal Code for encoding positive integers into binary code words using fibonacci numbers of 2nd order as bases*

## Theory
According to [Zeckendorf's Theorem](http://en.wikipedia.org/wiki/Zeckendorf%27s_theorem) every positive integer has an unique representation as a sum of fibonacci numbers (Zeckendorf Representation) such that it does not include any two adjacent fibonacci numbers. We can use such a representation and encode it with a binary string (codeword) but instead of using bases of powers of two (binary system) we use fibonacci numbers as our bases.
We use the fibonacci sequence 1, 2, 3, 5, 8, 13, 21, 34, 55, ...; that is we omit the first "1".

Example: 73 = 55 + 13 + 5, binary codeword: 100101000 (leftmost leading bit is most significant bit)

### Unique Decipherability
#### Definition
A *code C* is a finite set of codewords. A *code-string M* is created by concatenating codewords from *C* where repititions of codewords are allowed. *M* is called **uniquely decipherable** (UD) if there is only one way to write *M* as the concatenation of codewords in *C*. 
In addition, *C* is called UD if and only if **every** message from *C* is UD.

*Appendix: UD problem: Given a set C, determine if C is UD.*

#### How to achieve unique decipherability?
Because consecutive ones do not appear in our codewords, we can append a single 1-bit to our codewords in order to identify boundaries between codewords, i.e. it acts like a seperation line or a "comma". Therefore we are able to differentiate codewords in (long) concatenations/strings of codewords, that is, there is only one way to decode such strings.

Example: 10011 1011 stands for 6 and 4

### Prefix Code
Complications may occur during the decoding phase of code-strings. This problem is shown here by using repititions of the codeword 11 which is the only codeword having no zeros.
Suppose we have an encoded string 11011111110. This could be parsed into 110 **|** 11 **|** 11 **|** 11 **|** 10. This however is not possible as 10 is not a codeword; therefore we need to re-check the first codewords again and parse it to 1101 **|** 11 **|** 11 **|** 110.

In order to avoid such problems we simply reverse all codewords which forms a **prefix code**, i.e. no codeword is a prefix of any other codeword.

// TODO: how to encode/decode/(efficiency)??

## References
1. [Robust Transmission of Unbounded String Using Fibonacci Representations - Alberto Apostolico, Aviezri S. Fraenkel](http://docs.lib.purdue.edu/cgi/viewcontent.cgi?article=1463&context=cstech)
2. [On the Usefulness of Fibonacci Compression Codes - Shmuel T. Klein, Miri Kopel Ben-Nissan](http://u.cs.biu.ac.il/~tomi/Postscripts/fib-rev.pdf)