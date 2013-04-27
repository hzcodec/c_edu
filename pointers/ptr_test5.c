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
} RegA;


int main() {

    // pointer to a struct
    RegA  rega[5];
    RegA* p_rega;

    // assign address to pointer
    p_rega = &rega[0];

    p_rega->x = 11;
    p_rega->y = 22;
    printf("rega->x: %d\n",p_rega->x);
    printf("rega->y: %d\n",p_rega->y);

    // move pointer to next index
    p_rega++;

    p_rega->x = 33;
    p_rega->y = 44;
    printf("rega->x: %d\n",p_rega->x);
    printf("rega->y: %d\n",p_rega->y);

    // move back pointer to previous index
    p_rega--;
    printf("rega->x: %d\n",p_rega->x);
    printf("rega->y: %d\n",p_rega->y);

    return 0;
}

/*
  Result from run:
    rega->x: 11
    rega->y: 22
    rega->x: 33
    rega->y: 44
    rega->x: 11
    rega->y: 22
*/

