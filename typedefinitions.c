
//#include "typedefinitions.h"
//#include <stdio.h>
//#include <iostream>
//using namespace std;

#include "config.h"
#include <stdlib.h>

void cprint(void){

  u8 u8test = '2';
  u8 u8testarray[] = "WAZUPu8ARRAY\n";
  //u32 u32test = 0x0000FFFF;
  double doubletest = 24.15;
  int inttest = 2017;
  //printf("Test unsigned long is: %lu\n", u32test);
  printf("Test double is: %f\n", doubletest);
  printf("Test usigned char is: %c\n", u8test);
  printf("Test usigned char array is: %s\n", u8testarray);
  printf("Test int is: %d\n", inttest);
}


//assumes little endian
void printBits(int size, void const * const ptr)
{
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
