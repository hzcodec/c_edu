/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-14
    File        : ptr_test1.c
    Reference   : 
    Description : Test of returning pointer.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getp() {
    /*
       Need to use static otherwise the return value will be incorrrect.
       You can view it as a global variable. Will not work in a multi-
       threaded environment (concurrent call => synchronization).
    */
    static char s[] = "Get P";
    return s;
}


char* getq() {
    char* s = "Get Q";
    return s;
}

// how to free memory in this case?
char* getr() {
    char* s = malloc(5);
    s = "Get R";
    return s;
}

// this one work better with free
char* gett() {
    char* s = malloc(strlen("Get T")+1); // +1 for the null
    s = "Get T";
    return s;
}

/* *** MAIN *** */
int main(void) {

    char* c;
    char* d;
    char* e;
    char* f;

    c = getp();
    printf("%s\n",c);
    printf("%p\n",c);

    d = getq();
    printf("%s\n",d);
    printf("%p\n",d);

    e = getr();
    printf("%s\n",e);
    printf("%p\n",e);

    f = gett();
    printf("%s\n",f);
    printf("%p\n",f);
    
    return 0;
}

/*
  Result from run:
    Get P
    0x10754
    Get Q
    0x8600
    Get R
    0x8608
    Get T
    0x8610
*/

