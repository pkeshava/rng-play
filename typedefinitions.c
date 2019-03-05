
//#include "typedefinitions.h"
//#include <stdio.h>
//#include <iostream>
//using namespace std;

#include "config.h"
#include <stdlib.h>

//assumes little endian
void printBits(int size, void const * const ptr){
  u8 *b = (u8*) ptr;
  char byte[8];
  int i, j;

  for (i=size-1;i>=0;i--)
  {
    for (j=7;j>=0;j--)
    {
      byte[j] = (b[i] >> j) & 1;
      printf("%u", byte[j]);
    }

  }
  puts("");

}

u8* gen_rdm_bytestream (int nBytes){
  unsigned char *asciiBstream;
  asciiBstream = (char*) malloc (nBytes + 1);
  if (asciiBstream==NULL) exit (1);
  size_t i;

  for (i = 0; i < nBytes; i++)
    asciiBstream[i] = rand()%26 +'a';

  asciiBstream[nBytes]='\0';
  printf ("Random string: %s\n",asciiBstream); //print ascii letters

  return asciiBstream;
}

//UPDATE LATER TO RECEIVE FILE POINTER
void writeToFile(uc8* uc8inputBytes, int nBytes){
  int size = nBytes;
  u8* bits;
  bits = uc8inputBytes;
  FILE *write_ptr;
  write_ptr = fopen("test.bin","wb");  // w for write, b for binary
  if (write_ptr == NULL)
  {
    perror("Failed: ");
  }
  fwrite(bits,size,1,write_ptr);
  fclose(write_ptr);
}

//UPDATE LATER TO RECEIVE FILE POINTER
u8* readFromFile(int nBytes){
  int size = nBytes;
  u8* buffer;
  buffer = (char*) malloc (nBytes + 1);
  if (buffer==NULL) exit (1);
  FILE *ptr;
  ptr = fopen("test.bin","rb");  // r for read, b for binary
  fread(buffer,size,1,ptr);
  buffer[size]='\0';
  fclose(ptr);
  return buffer;
}


stateVariables determineSequence(stateVariables stateVars)
{
  stateVariables state = stateVars;
  printf("Program Name Is: %s\n",state.argv[0]);
  /* First check to see how many arguments there are. Regardless of what combination is used there should be an off number (including program name)*/
  if(state.argc == 1){
    printf("\nNo extra command line arguments passed other than the program name.\nTherefore, there the defualt total of random bytes generated is set to 10\nand the probability of 1's and 0's is equal. \nConversely, you can generate the number of bytes required and the probability\nbias for number of 1's with command line arguments. \nFor example, type in your command prompt:\n'./cdev -N 512 -p 0.35'");
    state.nBytes = 10;
  }
  else if(state.argc > 5 || state.argc %2 == 0)
  {
    //check to see if too many arguments given
    printf("\nFailed: Incorrect number of arguments passed.\nPlease specify total number of Bytes generated with option -N and the probability bias for the number of 1's (between 0 and 0.50) with option -p\ni.e type in your command prompt:\n'./cdev -N 512 -p 0.35'\n\n");
    exit(1);
  }

  /*If a non default and correct option sequence is entered then loop through the vector and extract numBytes and probability*/
  else if (state.argc > 1 && state.argc < 6)
  {
    int i;
    for (i = 1; i < state.argc; i++)  /* Skip argv[0] (program name). */
    {
      if (strcmp(state.argv[i], "-N") == 0){
        char *p;
        long conv = strtol(state.argv[i+1], &p, 10);
        if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < 0) {
          printf("\nFailed: please give a number after '-N' that is greater than zero and less than INT_MAX\n\n");
          exit(1);
        }
        state.nBytes = conv;
        printf("Number of random bytes generated is %d\n", state.nBytes);
      }
      if (strcmp(state.argv[i], "-p") == 0){
        if (state.nBytes == 0){
          state.nBytes = 10;
        }
        float conv2 = atof(state.argv[i+1]);
        if (conv2 < 0.05 || conv2 > 0.45) {
          printf("\nFailed: please give a percentage of 1's in the biased random sequence between 0.05 and 0.45 in 0.05 increments i.e.\n '-p 0.4'\n\n");
          exit(1);
        }
        else{
          state.prob1s = conv2;
          printf("Sample probability is: %f", conv2);
        }
      }
    }
  }
  else
    state.nBytes = 10;  /* if no value is given then */

  return state;
}
