/*
    Auther      : Heinz Samuelsson
    Date        : 2013-04-14
    File        : hex_test4.c
    Reference   :
    Description : Test of hex numbers. Print out hex and dec numbers.
*/

#include <stdio.h>
#include <inttypes.h>

int main() {

    uint8_t  a;
    uint8_t  b;
    uint8_t  c;
    int8_t   d;
    int8_t   e;
    int8_t   f;
  
    // simple add with unsigned int
    a = 0x10;
    b = 0x20;
    c = a + b;
    printf("c: %02X\n",c);
  
    // wrap around with unsigned int
    a = 0xFF;
    b = 0x01;
    c = a + b;
    printf("c: %02X\n",c);
  
    // simple add signed int
    d = 0x10;
    e = 0x20;
    f = d + e;
    printf("f: %02X\n",f);
  
    // simple sub signed int
    d = 0x20;
    e = 0x10;
    f = d - e;
    printf("f: %02X\n",f);
  
    // simple sub with signed int (-1 - 2)
    d = 0xFF;   // -1
    e = 0x02;
    f = d - e;
    printf("f: %02X\n",f);
  
    // simple add with signed int (-1 + 2)
    d = 0xFF;   // -1
    e = 0x02;
	    f = d + e;
    printf("f: %02X\n",f);
  
    // simple add with unsigned int (wrap around)
    a = 0xFF;
    b = 0x02;
    c = a + b;
    printf("c: %02X\n",c);
  
    return 0;
}

/*
 Result:
     c: 30
     c: 00
     f: 30
     f: 10
     f: FFFFFFFD
     f: 01
     c: 01
*/
