/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-20
    File        : init_struct.c
    Reference   : 
    Description : Initialize a struct with memset().
*/

#include <stdio.h>
#include <string.h>

struct stuff {
    int stuff_a;
    int stuff_b;
    int stuff_c;
    int stuff_d;
};

/* *** MAIN *** */
int main(void) {

    struct stuff custom_var;
 
    // initialize custom_var
    memset(&custom_var,0,sizeof(struct stuff));
    printf("stuff_a: %d\n",custom_var.stuff_a);
    printf("stuff_b: %d\n",custom_var.stuff_b);
    printf("stuff_c: %d\n",custom_var.stuff_c);
    printf("stuff_d: %d\n",custom_var.stuff_d);
    
    return 0;
}

/*
  Result from run:
    stuff_a: 0
    stuff_b: 0
    stuff_c: 0
    stuff_d: 0
*/

