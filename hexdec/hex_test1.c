/*
    Auther      : Heinz Samuelsson
    Date        : 2013-04-14
    File        : hex_test1.c
    Reference   :
    Description : Test of hex numbers. Print out hex and dec numbers.
*/

#include <stdio.h>

int main() {

    int x = 0x10;
    int y = 15;
   
    printf("x in dec: %d\n",x);
    printf("x in hex: %x\n",x);
    printf("x in hex: %04x\n",x);
   
    printf("y in dec: %d\n",y);
    printf("y in hex: %x\n",y);
    printf("y in hex: %04x\n",y);
    printf("y in hex uppercase: %04X\n",y);

    return 0;
}

/*
 Result:
     x in dec: 16
     x in hex: 10
     x in hex: 0010
     y in dec: 15
     y in hex: f
     y in hex: 000f
     y in hex uppercase: 000F
*/
