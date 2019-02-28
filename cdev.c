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

  unsigned char* bstream;
  size_t nBytes = 9;
  bstream = gen_rdm_bytestream(nBytes);
  //printf ("Random string: %s\n",bstream);
  for(int i = 0; i<nBytes; i++)
    printf("%u", bstream[i]); // prints a series of bytes


  FILE *write_ptr;
  write_ptr = fopen("test.bin","wb");  // w for write, b for binary
  if (write_ptr == NULL)
  {
    perror("Failed: ");
    return 1;
  }
  fwrite(bstream,nBytes,1,write_ptr);
  fclose(write_ptr);


  unsigned char buffer[nBytes];
  FILE *ptr;
  ptr = fopen("test.bin","rb");  // r for read, b for binary
  fread(buffer,sizeof(buffer),1,ptr);
  fclose(ptr);

  printf("\n");

  for(int i = 0; i<nBytes; i++)
    printf("%u ", buffer[i]); // prints a series of bytes

  printf("\n\n");
  printBits(sizeof(buffer), &buffer);
  printf("\n\n");
  free(bstream);




    // int i,n;
    // char *buf;
    //
    // printf ("How long do you want the string? ");
    // scanf ("%d", &i);
    //
    // buf = (char*) malloc (i+1);
    // if (buf==NULL) exit (1);
    //
    // for (n=0; n<i; n++)
    //   buf[n]=rand()%26 +'a';
    // buf[i]='\0';
    //
    // printf ("Random string: %s\n",buf);
    // free (buf);

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
