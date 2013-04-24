/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-24
    File        : callback_test2.c
    Reference   : -
    Description : Test of callback functions. This file represents lower
                  level functions.
*/
#include "callback_test2.h"

static MyCallback my_callback = NULL;


// function called by higher level
void _set_callback(MyCallback callback) {

    if (callback == NULL) {
        printf("Definition of callback not registered!\n");
    }
    else if (my_callback == NULL) {
        printf("Definition of callback has been registered.\n");
        my_callback = callback;
    }
    else {
        printf("Only one function callback is allowed!\n");
    }

    my_callback(2,5);
}


