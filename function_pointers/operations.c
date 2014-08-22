#include <stdio.h>
#include <stdlib.h>
#include "mess_ptr.h"

float internal_add(Parameters p) {
    printf("Internal add\n");
    return p.a+p.b;
}

float internal_sub(Parameters p) {
    printf("Internal sub\n");
    return p.a-p.b;
}

float internal_mul(Parameters p) {
    printf("Internal mul\n");
    return p.a*p.b;
}

float internal_div(Parameters p) {
    printf("Internal div\n");
    return p.a/p.b;
}
