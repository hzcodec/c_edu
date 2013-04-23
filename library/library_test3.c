/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-23
    File        : library_test3.c
    Reference   : An Intruduction to GCC
    Description : Test of static library.
*/

#include "hello.h"

int main(void) {
    
    hello("everyone");
    bye();

    return 0;
}
