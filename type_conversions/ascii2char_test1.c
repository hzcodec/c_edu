/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-29
    File        : ascii2char_test1.c
    Reference   : -
    Description : Convert ascii to character.
*/

#include <stdio.h>

/* *** MAIN *** */
int main(void) {

    printf("\nAscii values with corresponding characters\n");

    for (int i=45; i<=122; i++) {
        if (i%5 == 0) {
            printf("\n");
        }
        printf("%4d: %c\t",i,i);
    }

    printf("\n\n");

    return 0;
}

/*
  Result from run:
*/

