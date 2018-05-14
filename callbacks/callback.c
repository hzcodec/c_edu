/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-24
    File        : callback.c
    Reference   : -
    Description : Test of callback functions. This file represents higher
                  level functions.
*/

#include <stdio.h>
#include <unistd.h>
#include "callback_test2.h"

// prototypes
void add(int a, int b);
void sub(int a, int b);


/* *** MAIN *** */
int main(void) {
  
    // set callback functions
    _set_callback(add);
    _set_callback(sub);

    printf("Just wait for now\n");
    sleep(5);
    printf("Irq occured, then call callback function\n");
    irq();

    return 0;
}

//void add(int a,int b) {
//    printf("a+b=%d\n",a+b);
//}
//
//void sub(int a,int b) {
//    printf("a-b=%d\n",a-b);
//}
