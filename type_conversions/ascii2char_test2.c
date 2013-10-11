/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-29
    File        : ascii2char_test2.c
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


    printf("\nConvert an array of ascii data to characters.\n");

    uint8_t ascii_data1 = (data1 & 0xff00) >> 8;
    printf("Revision: %c",ascii_data1);

    uint8_t ascii_data2 = 0x00ff & data1;
    printf("%c",ascii_data2);

    uint8_t ascii_data3 = (0xff00 & data2) >> 8;
    printf("%c",ascii_data3);

    uint8_t ascii_data4 = 0x00ff & data2;
    printf("%c",ascii_data4);

    uint8_t ascii_data5 = (0xff00 & data3) >> 8;
    printf("%c",ascii_data5);

    uint8_t ascii_data6 = 0x00ff & data3;
    printf("%c",ascii_data6);

    uint8_t ascii_data7 = (0xff00 & data4) >> 8;
    printf("%c",ascii_data7);

    uint8_t ascii_data8 = 0x00ff & data4;
    printf("%c\n",ascii_data8);

    printf("\n\n");

    return 0;
}

/*
  Result from run:
    Convert an array of ascii data to characters.
    Revision: CAH 22/4
*/

