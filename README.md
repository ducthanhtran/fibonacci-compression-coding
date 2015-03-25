# Fibonacci Compression Coding
*Universal Code for encoding positive integers into binary code words using fibonacci numbers of 2nd order as bases*

## Theory
According to [Zeckendorf's Theorem](http://en.wikipedia.org/wiki/Zeckendorf%27s_theorem) every positive integer has an unique representation as a sum of fibonacci numbers such that it does not include any two consecutive fibonacci numbers. We can use such a representation and encode it with a binary code word but instead of using bases of powers of two (binary system) we use fibonacci numbers as our bases.

### Unique Decipherability
#### Definition
A *code C* is a finite set of codewords. A *code-string M* is created by concatenating codewords from *C* where repititions of codewords are allowed. *M* is called **uniquely decipherable** (UD) if there is only one way to write *M* as the concatenation of codewords in *C*. 
In addition, *C* is called UD iff **every** message from *C* is UD.

*Appendix: UD problem: Given a set C, determine if C is UD.*

#### How to achieve unique decipherability?
By appending a single 1-bit to our codewords we can identify boundaries between them, i.e. it acts like a seperation line or a "comma". Therefore we are able to differentiate codewords in (long) concatenations/strings of codewords, i.e. there is only one way to decode such strings.

### Prefix Code
There may occur complications during the decoding phase of code-strings. This problem is shown here by using repititions of the codeword 11 which is the only codeword having no zeros.
Suppose we have an encoded string 11011111110. This could be parsed into 110 **|** 11 **|** 11 **|** 11 **|** 10. This however is not possible as 10 is not a codeword; therefore we need to re-check the first codewords again and parse it to 1101 **|** 11 **|** 11 **|** 110.

In order to avoid such problems it is recommended to reverse all codewords which forms a **prefix code**, that is no codeword is a prefix of any other codeword.

// TODO: how to encode/decode/efficiency??

## References
1. [On the Usefulness of Fibonacci Compression Codes - Shmuel T. Klein, Miri Kopel Ben-Nissan](http://u.cs.biu.ac.il/~tomi/Postscripts/fib-rev.pdf)