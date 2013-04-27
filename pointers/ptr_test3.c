/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-27
    File        : ptr_test3.c
    Reference   : 
    Description : Test of pointers and structs. Passing a struct to a function.
*/

#include <stdio.h>

typedef struct {
    int x;
    int y;
} RegA;


void f1(RegA* r) {
    printf("r.x %d\n",r->x);
    printf("r.y %d\n",r->y);
}


int main() {

    // pointer to a struct
    RegA  rega;

    rega.x = 55;
    rega.y = 66;
  
    f1(&rega);

    return 0;
}

/*
  Result from run:
*/

