/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-13
    File        : byte2int_test2.c
    Reference   : http://stackoverflow.com/questions/12240299/convert-bytes-to-int-uint-in-c
    Description : Convert byte to 16/32 bits.
*/

#include <stdio.h>
#include <stdint.h>

#define BUFFER 8


/* *** MAIN *** */
int main(void) {

    uint8_t  bytes[BUFFER] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
    uint16_t sixteen[3];
    uint32_t thirtytwo[2];

    // little endian
    for (int i=0; i<BUFFER; i++) {
        printf("Bytes: %02x\n",bytes[i]);
    }

    for (int i=0; i<BUFFER; i+=2) {
        sixteen[i/2] = bytes[i] + ((uint16_t)bytes[i+1] << 8);
        // big endian
        //sixteen[i/2] = bytes[i+1] + ((uint16_t)bytes[i] << 8);
        printf("Words: %04x\n",sixteen[i/2]);
    }
     
    for (int i=0; i<BUFFER; i+=4) {
        thirtytwo[i/4] = bytes[i] + ((uint32_t)bytes[i+1] << 8) + ((uint32_t)bytes[i+2] << 16) + ((uint32_t)bytes[i+3] << 24);
        // big endian
        //thirtytwo[i/4] = bytes[i+1] + ((uint32_t)bytes[i+2] << 8) + ((uint32_t)bytes[i+2] << 16) + ((uint32_t)bytes[i+3] << 24);
        printf("Words: %08x\n",thirtytwo[i/4]);
    }

    return 0;
}

/*
  Result from run:
    Bytes: 01
    Bytes: 02
    Bytes: 03
    Bytes: 04
    Bytes: 05
    Bytes: 06
    Bytes: 07
    Bytes: 08
    Words: 0201
    Words: 0403
    Words: 0605
    Words: 0807
    Words: 04030201
    Words: 08070605
*/

