/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-05-02
    File        : ptr_test7.c
    Reference   : -
    Description : Test of pointer to different objects.

                            ____
                           |    |
    *p_byte -------------> | a1 | byte1
                ---------> |____|
                |
                |           ____
    *q_byte[0]---          |    |
    *q_byte[1]-----------> | f3 | byte2
    *q_byte[2]---          |____|
                |
                |           ____        byte3
                ---------> |____| [0] : 0x01
                           |____| [1] : 0x02
                           |____| [2] : 0x03
                           |____| [3] : 0x04
*/

#include <stdio.h>


/* *** MAIN *** */
int main(void) {

    int byte1    = 0xA1;
    int byte2    = 0xF3;
    int byte3[4] = {0x01,0x02,0x03,0x04};

    int* p_byte = &byte1; // declare a pointer and reference it to byte1
    int* q_byte[3];       // declare an array of pointers

    q_byte[0] = &byte1;
    q_byte[1] = &byte2;
    q_byte[2] = &byte3[0]; // reference to byte3 first item in array

    printf("byte1 p_byte: %02x\n",*p_byte);
    printf("byte2 q_byte[0]: %02x\n",*q_byte[0]);
    printf("byte2 q_byte[1]: %02x\n",*q_byte[1]);
    printf("byte2 q_byte[2]: %02x\n",*q_byte[2]);

    q_byte[2]++;
    printf("byte3 q_byte[2]: %02x\n",*q_byte[2]);

    q_byte[2] = &byte1;
    printf("byte2 q_byte[2]: %02x\n",*q_byte[2]);
    
    return 0;
}

/*
  Result from run:
    byte1 p_byte: a1
    byte2 q_byte[0]: a1
    byte2 q_byte[1]: f3
    byte2 q_byte[2]: 01
    byte3 q_byte[2]: 02
    byte2 q_byte[2]: a1
*/

