/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-14
    File        : ptr_test2.c
    Reference   : -
    Description : Test of MAP. Can only compile with gcc without flags.
*/

#include <stdio.h>

typedef enum {
    MAP_FAILED = 1,
    MAP_10     = 10,
    MAP_20     = 20
} MAPError;


int* my_map(int a) {
    if (10 == a) {
        return (int*)MAP_10;
    }
    else {
        return (int*)MAP_20;
    }
}



/* *** MAIN *** */
int main(void) {
 
    int* reg_map = (int*) MAP_FAILED;

    printf("%p\n",&reg_map);
    printf("%p\n",reg_map);
    printf("%d\n",reg_map);
  
    reg_map = my_map(10);
    printf("%p\n",&reg_map);
    printf("%p\n",reg_map);
    printf("%d\n",reg_map);

    return 0;
}

/*
  Result from run:
*/

