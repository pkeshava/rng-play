/* © Pouyan Keshavarzian 2019
PhD Student EPFL
This code is used as a first step dive into the world of true random number generation

*/

#include "config.h"
#include <stdlib.h>
#include <time.h>

int main(){

  //int seed = 5556;
  //srand(seed);
//
  srand((unsigned int) time (NULL));
  int intrand = rand();
  int *rand_p = &intrand;
  printBits(sizeof(intrand), &intrand);

  unsigned char* bstream;
  bstream = gen_rdm_bytestream(10);
  printf("input: %s\n", bstream);

  FILE *write_ptr;
  write_ptr = fopen("test.bin","wb");  // w for write, b for binary
  fwrite(bstream,sizeof(bstream),1,write_ptr); // write 10 bytes from our buffer

  unsigned char buffer[10];
  FILE *ptr;
  ptr = fopen("test.bin","rb");  // r for read, b for binary
  fread(buffer,sizeof(buffer),1,ptr); // read 10 bytes to our buffer

  for(int i = 0; i<10; i++)
    printf("%u ", buffer[i]); // prints a series of bytes


  free(bstream);
  // open file and clear it's contents
  // std::ofstream myfile;
  // myfile.open("bitstream.txt", std::ofstream::out | std::ofstream::trunc);
  // myfile.write(reinterpret_cast<char*>(&rand_p),sizeof(rand_p));
  // myfile.close();

  // verifyBits();
  //
  // srand((unsigned int) time (NULL));


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
