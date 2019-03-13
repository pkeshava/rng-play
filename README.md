# Random Number Generation and Analysis

PhD Research initial investigation in random number generation.

## Getting Started

FILL IN
**Prerequisites**
FILL IN

    Give an example

**Installing**

## NOTE

This should check that the input for probability of 1's -p is divisible by a certain resolution i.e 1%. But modulus of a float is challenging.

## Running the tests

Explain how to run the automated tests for this system

## Built With
## Versioning
## Authors
- **Pouyan Keshavarzian, M.Sc.**
- Doctoral Assistant EPFL STI IMT AQUA 2019** - *Initial work*
## Acknowledgments
- Mario
- etc
## Resources

[**For a curated list of really awesome readme templates**](https://github.com/matiassingers/awesome-readme)
[**For information on string error handling**](https://www.tutorialspoint.com/cprogramming/c_error_handling.htm)
[](https://www.tutorialspoint.com/cprogramming/c_error_handling.htm)[**For information on handling command line arguments in c**](https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/)
[**For information regarding the limitations of using modulo as a way of getting a uniform random distribution**](https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/)
[**writing Character array in a file in C [closed]**](https://stackoverflow.com/questions/14576429/writing-character-array-in-a-file-in-c)
[**Generate Random Byte Stream**](https://stackoverflow.com/questions/15621764/generate-a-random-byte-stream)
[**char *array and char array[]**](https://stackoverflow.com/questions/20347170/char-array-and-char-array)
[**Char Pointers Overwritten**](https://stackoverflow.com/questions/14655851/char-pointers-overwritten)
[**Uniform random numbers in an integer interval in C**](https://codereview.stackexchange.com/questions/159604/uniform-random-numbers-in-an-integer-interval-in-c) ****
[**Proper Way to Free Memory of a Returned Variable**](https://stackoverflow.com/questions/29655051/proper-way-to-free-memory-of-a-returned-variable)


# Notes
## 12.03.2019

**Handeling char* and memory allocation**
Learned a very important lesson today: Even if you have a

    const char*

the elements in that array may get changed if you don’t assign memory correctly…
i.e. as I was originally doing with dynamic memory allocation.

    unsigned char *asciiBstream;
    asciiBstream = (char*) malloc (nBytes + 1);

or by immediately filling an array with the elements being pointed to by the pointer before any more memory is allocated such as a pointer to a file. Something like:

    uc8* pu8Bstream = pu8GenBiasedRdmByteStream(nBytes, stateVars.prob1s);
    u8 array[nBytes];
    for(int i = 0; i<nBytes; i++)
      array[i] = pu8Bstream[i];
