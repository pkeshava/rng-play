/* © Pouyan Keshavarzian 2019
PhD Student EPFL
This code is used as a first step dive into the world of true random number generation

*/

#include "config.h"
#include <stdlib.h>
#include <time.h>

int main(){

  int seed = 2342;
  srand(seed);
  //srand((unsigned int) time (NULL));

  unsigned char* bstream;
  size_t nBytes = 2;
  bstream = gen_rdm_bytestream(nBytes);

  writeToFile(bstream);

  unsigned char buffer[nBytes];
  FILE *ptr;
  ptr = fopen("test.bin","rb");  // r for read, b for binary
  fread(buffer,sizeof(buffer),1,ptr); // read 10 bytes to our buffer

  printf("\n");

  for(int i = 0; i<nBytes; i++)
    printf("%u ", buffer[i]); // prints a series of bytes

  printf("\n\n");
  printBits(sizeof(buffer), &buffer);
  printf("\n\n");
  free(bstream);



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
