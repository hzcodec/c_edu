/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-05-22
    File        : status_test2.c
    Reference   : -
    Description : Test of returning status from a struct and memcpy function.
*/

#include <stdio.h>
#include <string.h>  // required header for memcpy


typedef struct {
    int  a;
    int  b;
    int  c;
} Status;


int get_status(Status* s) {

    Status tmp;
    tmp.a = 99;
    tmp.b = 88;
    tmp.c = 77;

    memcpy(s,&tmp,sizeof(tmp));

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

