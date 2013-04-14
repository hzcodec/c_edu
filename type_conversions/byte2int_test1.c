/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-13
    File        : byte2int_test1.c
    Reference   : http://stackoverflow.com/questions/12240299/convert-bytes-to-int-uint-in-c
    Description : Convert byte to 16/32 bits.
*/

#include <stdio.h>
#include <stdint.h>

#define BUFFER 8


/* *** MAIN *** */
int main(void) {

    uint8_t bytes[BUFFER] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};

    // declare pointers
    uint16_t* viewAsUint16_t = (uint16_t *)&bytes[0];
    uint32_t* viewAsUint32_t = (uint32_t *)&bytes[0];
 
    printf("16 bits: %04x\n",*viewAsUint16_t);
    viewAsUint16_t++;
    printf("16 bits: %04x\n",*viewAsUint16_t);
    viewAsUint16_t++;
    printf("16 bits: %04x\n",*viewAsUint16_t);
    viewAsUint16_t++;
    printf("16 bits: %04x\n\n",*viewAsUint16_t);
    viewAsUint16_t++;

    printf("32 bits: %08x\n",*viewAsUint32_t);
    viewAsUint32_t++;
    printf("32 bits: %08x\n",*viewAsUint32_t);

    return 0;
}

/*
  Result from run:

    16 bits: 0201
    16 bits: 0403
    16 bits: 0605
    16 bits: 0807
    
    32 bits: 04030201
    32 bits: 08070605
*/

