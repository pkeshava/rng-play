/* © Pouyan Keshavarzian 2019
PhD Student EPFL
This code is used as a first step dive into the world of true random number generation

*/

#include "config.h"
#include <stdlib.h>
#include <time.h>

int main(){

  int seed = 5556;
  srand(seed);
  int intrand = rand();
  int *rand_p = &intrand;
  cout << intrand << endl;
  printBits(sizeof(intrand), &intrand);
  cout << intrand << endl;


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
