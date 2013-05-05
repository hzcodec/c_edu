/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-08
    File        : bit_test1.c
    Reference   : -
    Description : Bit manipulation. Set/Clear bits.
*/

#include <stdio.h>


/* *** MAIN *** */
int main(void) {

    unsigned int flags = 0x00;
    int bitindex = 1;
    unsigned int bit;

    // set bit 1 
    flags |= 1 << bitindex;
    printf("flags: %02x\n",flags);

    // set bit 7 
    bitindex = 7;
    flags |= 1 << bitindex;
    printf("flags: %02x\n",flags);

    // clear bit 7
    flags &= ~(1 << bitindex);
    printf("flags: %02x\n",flags);

    // toggle bit 7
    flags ^= 1 << bitindex;
    printf("flags: %02x\n",flags);

    // check bit
    bit = flags & (1 << bitindex);
    printf("bit<7>: %d\n",bit);

    return 0;
}

/*
  Result from run:
    flags: 02
    flags: 82
    flags: 02
    flags: 82
    bit<7>: 128
*/

