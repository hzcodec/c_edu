/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-14
    File        : callback_test1.c
    Reference   : -
    Description : Test of pointers to different objects.

*/

#include <stdio.h>

typedef void(*callback)(int a,int b);
callback _callback = NULL;


// Assume that these are higher level functions
void add(int a, int b);
void sub(int a, int b);


/* *** MAIN *** */
int main(void) {

    if (_callback == NULL) {
        printf("\nNo definition of callback function is done\n");
    }

    /* Define callback function. It's optional tu use the
       address opertor '&' in front of function's name.
    */
    _callback = add;

    if (_callback != NULL) {
        printf("\nDefinition of callback function is done\n");
    }

    // check what _callback contains
    if (_callback == add) {
        printf("Function add is selected\n");
    }

    
    // here you are passing higher level function to lower level function
    _callback(2,5);
    _callback = sub;
    _callback(7,3);

    return 0;
}


// These are the higher level function implementations
void add(int a,int b) {
    printf("a+b=%d\n",a+b);
}

void sub(int a,int b) {
    printf("a-b=%d\n",a-b);
}

/*
  Result from run:

    No definition of callback function is done
    
    Definition of callback function is done
    Function add is selected
    a+b=7
    a-b=4
*/

