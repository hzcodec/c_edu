/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-27
    File        : ptr_test5.c
    Reference   : 
    Description : Test of pointers and structs.
*/
#include <stdio.h>

typedef struct {
    int x;
    int y;
} RegA[5];


int main() {

    // pointer to a struct
    RegA  rega;
    RegA* p_rega;

    // assign address to pointer
    p_rega = &rega;
//    rega[0].x = 44;
    p_rega->x = 99;
//    p_rega->y = 88;
//    printf("rega.x: %d\n",rega.x);
//    printf("rega.y: %d\n",rega.y);

    return 0;
}

/*
  Result from run:
*/

