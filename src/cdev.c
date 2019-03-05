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

  srand((unsigned int) time (NULL));
  u8* bstream;
  printf("\n");
  // Generate random bits
  bstream = gen_rdm_bytestream(nBytes);
  printf("\n");
  //printf ("Random string: %s\n",bstream);
  for(int i = 0; i<nBytes; i++)
    printf("%u ", bstream[i]); // prints a series of bytes as ascii characters
  printf("\n\n");
  // write to a binary file and then read back to check it was done correctly
  writeToFile(bstream, nBytes);
  u8* buffer;
  buffer = readFromFile(nBytes);

  for(int i = 0; i<nBytes; i++)
    printf("%u ", buffer[i]); // prints a series of bytes.. this now should print exactly the same as ascii numbers only properly split up

  printf("\n\n");
  printBits(nBytes, buffer); // NOTE if this is done without the dynamic memory allocation then you need to have &buffer
  printf("\n");

  free(bstream);
  free(buffer);

return 0;
}

/* Tasks Remaining
    - Create boolean algebra table and algorithm for biasing the bitstream with a percentage of 1's
    - Take command line input for number of bytes and the percentage of ones... do calculations to determine if possible and output error message if required
    - python analysis of data file to calculate autocorrelation, cross correlation shannon entropy etc.
    - calculate total runtime of the program
    - adjust makefile
    - C/python library for nist test or any other statistical testing
*/
