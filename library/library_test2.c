/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-22
    File        : library_test2.c
    Reference   : Shared libraries with GCC on Linux, by anduril462
    Description : Test of shared library.
                  To compile run (shared library):
                      > make clean; make l3
                  To run the file:
                      > ./libtest2
*/

#include <stdio.h>
#include "foo.h"

int main(void) {
    puts("This is a shared library test");
    foo();
    return 0;
}
