/* © Pouyan Keshavarzian 2019
PhD Student EPFL
This code is used as a first step dive into the world of true random number generation

*/

#include "config.h"
#include <stdlib.h>
#include <time.h>

int main(){

  //int seed = 238;
  //srand(seed);
  srand((unsigned int) time (NULL));

  u8* bstream;
  size_t nBytes = 10;
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



/*
------- sample code IGNORE----------------------------------------------------

//cprint();
//cplusprint();
//u32 u32test = 0x0000FFFF;
//printf("Test unsigned long is: %lu\n", u32test);


typedef struct modulation {
   char* QPSK;
   int q;
} mod;

int x[]= {1,2,3,4,5};
printf("Hello Emacs World!\n");
int y = x[2];
printf("y = %d \n", y);
int z = 5;
int dild = 2;
mod mod1 = {"QPSK",256};
printf("The modulation type is %s, %d \n", mod1.QPSK, mod1.q);

-------------------------------------------------------------------------------
*/
