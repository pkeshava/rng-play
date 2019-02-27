
//#include "typedefinitions.h"
//#include <stdio.h>
//#include <iostream>
//using namespace std;

#include "config.h"

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

void cplusprint(void) {

  string stringtest = "WAZUPSTRING\n";
  //u32 u32test = 0x0000FFFF;
  //cout << "Test unsigned long is: " << u32test << endl;
  cout << "Test string is:" << stringtest << endl;
}

//assumes little endian
void printBits(uc64 size, void const * const ptr)
{
    u8 *b = (u8*) ptr;
    char byte[8];
    int i, j;
    int output[8];

    // open file and clear it's contents
    std::ofstream myfile;
    myfile.open("bitstream.txt", std::ofstream::out | std::ofstream::trunc);
    myfile.close();

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte[j] = (b[i] >> j) & 1;
            printf("%u", byte[j]);
            myfile.open ("bitstream.txt",std::ios_base::app);
            if( !myfile )
                cout << "Opening file failed" << endl;
            // use operator<< for clarity
            myfile << b;
            // test if write was succesful - not *really* necessary
            if( !myfile )
                cout << "Write failed" << endl;
            myfile.close();
        }

    }
    puts("");

}

void verifyBits()
{
  // std::ifstream input("bitstream.txt", std::ios::binary );
  // std::vector<unsigned char> buffer((std::istreambuf_iterator<char>(input)),std::istreambuf_iterator<char>());

  std::vector<char> buffer;
  std::ifstream file("bitstream.txt");
  std::copy(std::istream_iterator<char>(file), std::istream_iterator<char>(), std::back_inserter(buffer));

  for (std::vector<char>::const_iterator i = buffer.begin(); i != buffer.end(); ++i)
    std::cout << *i << ' ';

  //std::ifstream input( "bitstream.txt", std::ios::binary );

}
