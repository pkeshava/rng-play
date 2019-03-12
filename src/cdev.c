/* © Pouyan Keshavarzian 2019
PhD Student EPFL

This code is used as a first step dive into the world of true random number generation
*/

#include "config.h"


int main(int argc, char** argv){

  int nBytes;
  float prob1s;

  stateVariables stateVars = {.nBytes = 0, .argc = argc, .prob1s = 0.5, .argv = argv};

  stateVars = determineSequence(stateVars);
  nBytes = stateVars.nBytes;
  prob1s = stateVars.prob1s;


  srand((unsigned int) time (NULL)); // create a seed by reading epoch time
  u8* pu8Bstream;
  printf("\n");
  // Generate random bits
  pu8Bstream = pu8GenRdmByteStream(nBytes); // also prints bytes as ascii characters
  printf("\n");

  for(int i = 0; i<nBytes; i++)
    printf("%u ", pu8Bstream[i]); // prints a series of bytes as the decimal representation of the ascii byte i.e 122 104 120 etc..
  printf("\n\n");
  // write to a binary file and then read back to check it was done correctly
  writeToFile(pu8Bstream, nBytes);
  u8* buffer;
  buffer = readFromFile(nBytes);

  for(int i = 0; i<nBytes; i++)
    printf("%u ", buffer[i]); // This now should print exactly the same decimal representations of ascii bytes as done before.
  printf("\n\n");

  // Now convert the bytes to bit representation and print on the command line
  printBits(nBytes, buffer); // NOTE if this is done without the dynamic memory allocation then you need to have &buffer
  printf("\n");

  free(pu8Bstream);
  free(buffer);

  printf("test: %d\n\n", RAND_MAX);
  double testRnd = rand()%4;
  double normalized = (double) rand() / nextafter(RAND_MAX, DBL_MAX);
  printf("test: %f\n\n", testRnd);
  printf("test: %f\n\n", normalized);


return 0;
}

/* Tasks Remaining
    - Create boolean algebra table and algorithm for biasing the bitstream with a percentage of 1's
    - Take command line input for number of bytes and the percentage of ones... do calculations to determine if possible and output error message if required DONE
    - python analysis of data file to calculate autocorrelation, cross correlation shannon entropy etc.
    - calculate total runtime of the program
    - adjust makefile DONE
    - C/python library for nist test or any other statistical testing
*/
