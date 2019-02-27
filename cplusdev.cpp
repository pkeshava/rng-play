/* © Pouyan Keshavarzian 2019
PhD Student EPFL
This code is used as a first step dive into the world of true random number generation

*/

#include "config.h"

int main(){

  cprint();
  cplusprint();
  //u32 u32test = 0x0000FFFF;
  //printf("Test unsigned long is: %lu\n", u32test);

  s32 u32seed = rand();
  printf("Test random number as an integer: %lu\n", u32seed);
  printBits(sizeof(u32seed), &u32seed);


return 0;
}


/*------ sample code -----------------
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
----------

*/
