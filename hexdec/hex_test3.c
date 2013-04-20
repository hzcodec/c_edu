/*
    Auther      : Heinz Samuelsson
    Date        : 2013-04-14
    File        : hex_test3.c
    Reference   :
    Description : Test of hex numbers. Print out hex and dec numbers.
*/

#include <stdio.h>
#include <inttypes.h>

int main() {

  // declare 16 bit unsigned type
  uint16_t a;
  uint16_t b;
  uint16_t c;

  a = 0x55AA;

  // print out in hex format with 4 digits
  printf("a: %04X\n",a);

  // invert all bits
  b = ~a;
  printf("b: %04X\n",b);

  // shift right four steps
  c = a >> 4;
  printf("c: %04X\n",c);
}

/*
 Result:
   a: 55AA
   b: AA55
   c: FF55
   d: 055A
*/
