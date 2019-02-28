#include <stdlib.h>
#include <stdbool.h>


#ifndef typedefinitions_h
#define typedefinitions_h

typedef char CHAR;                   // Signed 8 bits
typedef unsigned char UCHAR;         // Unsigned 8 bits
typedef short SHORT;                 // Signed 16 bits
typedef unsigned short USHORT;       // Unsigned 16 bits
typedef long LONG;                   // Signed 64 bit
typedef unsigned long ULONG;         // unsigned 64 bit
typedef int SINT;                    // signed 32 bit
typedef unsigned int UINT;           // unsigned 32 bit

typedef bool BOOL;                   // BOOLEAN VALUE!!!!

typedef long s64;
typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef signed char  s8;

typedef const long sc64;            // Read Only
typedef const int sc32;             // Read Only
typedef const unsigned int uc32;    // Read Only
typedef const short sc16;           // Read Only
typedef const char sc8;             // Read Only

typedef ULONG  u64;                 // Read Only
typedef USHORT u16;                 // Read Only
typedef UCHAR  u8;                  // Read Only

typedef const ULONG uc64;           // Read Only
typedef const USHORT uc16;          // Read Only
typedef const USHORT uc8;           // Read Only

// These are not strictly necessary but might be useful
typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

void cprint(void);
void printBits(size_t size, void const * const ptr);//assumes little endian
unsigned char *gen_rdm_bytestream (size_t nBytes);
void writeToFile(unsigned const char* uc8inputBytes);

#endif                              // typedefinitions.h
