/*
    Auther      : Heinz Samuelsson
    Date        : 2013-04-14
    File        : hex_test2.c
    Reference   :
    Description : Test of masking bits.
*/

#include <stdio.h>
#include <inttypes.h>


int main() {

    uint16_t a;
    uint16_t b;
    uint16_t c;
    uint16_t mask1;
    uint16_t mask2;
  
    a     = 0x55AA;
    mask1 = 0x00FF;
    mask2 = 0xFF00; 
    printf("a in hex:     %04X\n",a);
  
    // mask of 8 msb
    b = a & mask1;
    printf("8 msb masked: %04X\n",b);
  
    // OR 8 msb
    c = a | mask2;
    printf("8 msb ored:   %04X\n",c);
  
    return 0;
}

/*
 Result:
     a in hex:     55AA
     8 msb masked: 00AA
     8 msb ored:   FFAA
*/
