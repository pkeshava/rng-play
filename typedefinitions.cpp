
//#include "typedefinitions.h"
//#include <stdio.h>
//#include <iostream>
//using namespace std;

#include "config.h"

void cprint(void){

  u32 u32test = 0x0000FFFF;
  printf("Test unsigned long is: %lu\n", u32test);

}

void cplusprint(void) {

  u32 u32test = 0x0000FFFF;
  cout << "Test unsigned long is: " << u32test << endl;

}
