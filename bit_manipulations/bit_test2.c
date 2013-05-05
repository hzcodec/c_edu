/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-08
    File        : bit_test2.c
    Reference   : http://stackoverflow.com/questions/47981/how-do-you-set-clear-and-toggle-a-single-bit-in-c-
    Description : Bit manipulation. Set/Clear bits using macros.
*/

#include <stdio.h>

// a = target variable, b = bit number
#define BIT_SET(a,b) ((a) |= (1<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1<<(b)))
#define BIT_CHECK(a,b) ((a) & (1<<(b)))

// x = target, y = mask
#define BITMASK_SET(x,y) ((x) |= (y))
#define BITMASK_CLEAR(x,y) ((x) &= (~(y)))
#define BITMASK_FLIP(x,y) ((x) ^= (y))
#define BITMASK_CHECK(x,y) ((x) & (y))

/* *** MAIN *** */
int main(void) {

    unsigned int byte;
    unsigned int nisse;

    BIT_SET(byte,3);
    printf("byte %02x\n",byte);

    BIT_CLEAR(byte,3);
    printf("byte %02x\n",byte);

    BIT_FLIP(byte,3);
    printf("byte %02x\n",byte);

    BIT_CHECK(byte,3);
    printf("byte %02x\n",byte);

    return 0;
}

/*
  Result from run:
    byte 08
    byte 00
    byte 08
    byte 08
*/

