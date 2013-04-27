/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-27
    File        : ptr_test4.c
    Reference   : 
    Description : Test of pointers and structs.
*/
#include <stdio.h>

typedef struct {
    int x;
    int y;
} RegA;


typedef struct {
    int x[5];
    int y[5];
} RegB;


typedef struct {
    int x;
    int y;
} RegC;

int main() {

    // pointer to a struct
    RegA  rega;
    RegA* p_rega;

    // pointer to a struct containing arrays
    RegB  regb;
    RegB* p_regb;

    // pointer to an array of  struct
    RegC  regc[5];
    RegC* p_regc;


    // assign address to pointer
    p_rega = &rega;
    p_rega->x = 99;
    p_rega->y = 88;
    printf("rega.x: %d\n",rega.x);
    printf("rega.y: %d\n",rega.y);

    // assign address to pointer
    p_regb = &regb;
    p_regb->x[0] = 33;
    p_regb->y[0] = 22;
    printf("regb.x[0]: %d\n",regb.x[0]);
    printf("regb.y[0]: %d\n",regb.y[0]);
    
    // assign address to pointer
    p_regc = &regc[0];
    p_regc->x = 1;
    p_regc->y = 2;
    printf("regc[0].x: %d\n",regc[0].x);
    printf("regc[0].y: %d\n",regc[0].y);
    // move pointer to next index
    p_regc++;
    p_regc->x = 3;
    p_regc->y = 4;
    printf("regc[1].x: %d\n",regc[1].x);
    printf("regc[1].y: %d\n",regc[1].y);

    return 0;
}

/*
  Result from run:
    rega.x: 99
    rega.y: 88
    regb.x[0]: 33
    regb.y[0]: 22
    regc[0].x: 1
    regc[0].y: 2
    regc[1].x: 3
    regc[1].y: 4
*/

