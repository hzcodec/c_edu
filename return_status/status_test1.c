/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-05-22
    File        : status_test1.c
    Reference   : -
    Description : Test of returning status from a struct.
*/

#include <stdio.h>

typedef struct {
    int  a;
    int  b;
    int  c;
} Status;


int get_status(Status* s) {
    s->a = 11;
    s->b = 22;
    s->c = 33;

    return 1;
}

void print_status(Status* s) {
    printf("a: %d\n",s->a);
    printf("b: %d\n",s->b);
    printf("c: %d\n",s->c);
}


/* *** MAIN *** */
int main(void) {

    Status stat;
    int r;

    r = get_status(&stat);
    print_status(&stat);

    return 0;
}

/*
  Result from run:
*/

