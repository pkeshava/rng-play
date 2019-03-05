/* © Pouyan Keshavarzian 2019
PhD Student EPFL
This code is used as a first step dive into the world of true random number generation

*/

#include "config.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[]){

  int nBytes = 0;
  int counter;
  printf("Program Name Is: %s\n",argv[0]);
  /* First check to see how many arguments there are. Regardless of what combination is used there should be an off number (including program name)*/
  if(argc == 1){
    printf("\n\nNo extra command line arguments passed other than the program name.\nTherefore, there the defualt total of random bytes generated is set to 10 and the probability of 1's and 0's is equal. \nConversely, you can generate the number of bytes required and the probability bias for number of 1's with command line arguments. \nFor example, type in your command prompt:\n'./cdev -N 512 -p 0.35'");
    nBytes = 10;
  }
  else if(argc > 5 || argc %2 == 0)
  {
    //check to see if too many arguments given
    printf("\nFailed: Incorrect number of arguments passed.\nPlease specify total number of Bytes generated with option -N and the probability bias for the number of 1's (between 0 and 0.50) with option -p\ni.e type in your command prompt:\n'./cdev -N 512 -p 0.35'\n\n");
    exit(1);
  }

  else if (argc > 1 && argc < 6)
  {
    int i;
    for (i = 1; i < argc; i++)  /* Skip argv[0] (program name). */
    {
      if (strcmp(argv[i], "-N") == 0){
        char *p;
        long conv = strtol(argv[i+1], &p, 10);
        if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < 0) {
          printf("\nFailed: please give a number after '-N' that is greater than zero and less than INT_MAX\n\n");
          exit(1);
        }
        nBytes = conv;
        printf("Number of random bytes generated is %d\n", nBytes);
      }
      if (strcmp(argv[i], "-p") == 0){
        if (nBytes == 0){
          nBytes = 10;
        }
        char *p2;
        long conv2 = strtol(argv[i+1], &p2, 10);
        if (errno != 0 || *p2 != '\0' || conv2 > INT_MAX) {
          printf("\nFailed: please give a number after '-p'\n\n");
          exit(1);
        }
        else
          printf("Sample probability is: ");
      }
      //else
        //nBytes = 8;
    }
  }
  else {
    nBytes = 10;  /* if no value is given then */
  }

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
