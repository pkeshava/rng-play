
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
