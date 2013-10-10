/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-10
    File        : print_formats.c
    Reference   : -
    Description : Print out hour format.
*/

#include<stdio.h>


/* *** MAIN *** */
int main(void) {

    int hour = 0;
    printf("That equals: %d hour%s\n",hour,hour==1 ? "": "s");

    hour = 1;
    printf("That equals: %d hour%s\n",hour,hour==1 ? "": "s");

    hour = 2;
    printf("That equals: %d hour%s\n",hour,hour==1 ? "": "s");

    return 0;
}

