/*
    Auther      : Heinz Samuelsson
    Date        : 2014-08-24
    File        : operations.c
    Reference   : -
    Description : These functions are called from op_handler.
*/

#include <stdio.h>
#include <stdlib.h>
#include "op_handler.h"

float internal_add(Parameters p) {
    printf("Internal add from operations\n");
    return p.indata1+p.indata2;
}

float internal_sub(Parameters p) {
    printf("Internal sub from operations\n");
    return p.indata1-p.indata2;
}

float internal_mul(Parameters p) {
    printf("Internal mul from operations\n");
    return p.indata1*p.indata2;
}

float internal_div(Parameters p) {
    printf("Internal div from operations\n");
    return p.indata1/p.indata2;
}
