/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-16
    File        : argc_test1.c
    Reference   : -
    Description : Input parameter to argc in main.
                  Regarding strncmp function -
                    If the two strings are equal then zero is returned.
                    If the target string is less than source then a value that is less then zero is returned.
                    If the target string is greater than source then a value that is greater then zero is returned.
*/

#include <stdio.h>
#include <string.h>

/* *** MAIN *** */
int main(int argc, char** argv) {

    if (argc > 1) {
        printf("Entered inparameter: %s\n",argv[1]);

        if (!strncmp(argv[1],"log",3)) {
            printf("  LOG is entered\n");
        }
        else {
            printf(" LOG is not entered\n");
        }
    }

    else {
        printf("No parameter is entered\n");
    }

    return 0;
}

/* Result from run:
*/
