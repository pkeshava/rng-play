/* © Pouyan Keshavarzian 2019
PhD Student EPFL
This code is used as a first step dive into the world of true random number generation

*/

#include "config.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[]){

  size_t nBytes = 10;
  int counter;
  printf("Program Name Is: %s",argv[0]);
  if(argc == 1)
    printf("\n\nNo extra command line arguments passed other than the program name.\nTherefore, there are 10 total random bytes generated and the probability of 1's and 0's is equal. \nConversely, you can generate the number of bytes required and the probability bias for number of 1's with command line arguments. \nFor example, type in your command prompt:\n'./cdev -N 512 -p 0.35'");
  else if(argc > 5)
  {
    //check to see if too many arguments given
    printf("\nFailed: Too many arguments passed.\nPlease specify total number of Bytes generated with option -N and the probability bias for the number of 1's (between 0 and 0.50) with option -p\ni.e type in your command prompt:\n'./cdev -N 512 -p 0.35'\n");
    exit(1);
  }
  else if (5 > argc >= 1)
  {
    //test for now
    printf("\n\nNumber Of Arguments Passed: %d",argc);
    printf("\n\n----Following Are The Command Line Arguments Passed----");
    for(counter=0;counter<argc;counter++)
      printf("\n\nargv[%d]: %s",counter,argv[counter]);
  }
  // int i;
  // int quiet = 0;  /* Value for the "-q" optional argument. */
  // for (i = 1; i < argc; i++)  /* Skip argv[0] (program name). */
  // {
  //   if (strcmp(argv[i], "-N") == 0)  /* Process optional arguments. */
  //   {
  //     nBytes = 8;  /* This is used as a boolean value. */
  //   }
  //   else
  //   {
  //     char *p;
  //     long conv = strtol(argv[i+1], &p, 10);
  //     if (errno != 0 || *p != '\0' || conv > INT_MAX) {
  //       perror("Failed: ");
  //     }
  //     else {
  //         // No error
  //         nBytes = conv;
  //         printf("Number of random bytes generated is %zu\n", nBytes);
  //     }
  //     /* Process non-optional arguments here. */
  //   }
  // }

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
