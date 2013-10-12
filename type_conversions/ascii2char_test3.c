/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-12
    File        : ascii2char_test3.c
    Reference   : -
    Description : Convert ascii data to character.
*/

#include <stdio.h>
#include <stdint.h>

/* *** MAIN *** */
int main(void) {


    uint16_t data1 = 0x4341;
    uint16_t data2 = 0x4820;
    uint16_t data3 = 0x3232;
    uint16_t data4 = 0x2f34;

    uint16_t rev_data[8];

    rev_data[0] = data1;
    rev_data[1] = data2;
    rev_data[2] = data3;
    rev_data[3] = data4;

    printf("rev_data: %c",(rev_data[0] >> 8));
    printf("%c",(rev_data[0] & 0x00ff));
    printf("%c",(rev_data[1] >> 8));
    printf("%c",(rev_data[1] & 0x00ff));
    printf("%c",(rev_data[2] >> 8));
    printf("%c",(rev_data[2] & 0x00ff));
    printf("%c",(rev_data[3] >> 8));
    printf("%c",(rev_data[3] & 0x00ff));

    printf("\n\n");

    return 0;
}

/*
  Result from run:
    Convert an array of ascii data to characters.
    Revision: CAH 22/4
*/

