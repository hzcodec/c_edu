/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-02-26
    File        : ascii_print1.c
    Reference   : -
    Description : Print out at different formats.
*/

#include <stdio.h>
#include <stdlib.h>  // malloc and free function
#include <string.h>  // strcpy function

#define ANSI_RESET       "\033[0m"
#define ANSI_BOLD        "\033[1m"
#define ANSI_UNDERLINED  "\033[4m"
#define ANSI_BLINK       "\033[5m"
#define ANSI_RED_TEXT    "\033[31m"
#define ANSI_GREEN_TEXT  "\033[32m"
#define ANSI_YELLOW_TEXT "\033[33m"
#define ANSI_BLUE_TEXT   "\033[34m"
#define ANSI_CYAN_TEXT   "\033[36m"

/* *** MAIN *** */
int main(void) {

        printf(ANSI_BOLD "Test string\n" ANSI_RESET);
        printf(ANSI_UNDERLINED "Test string\n" ANSI_RESET);
        printf(ANSI_BLINK "Test string\n" ANSI_RESET);
        printf(ANSI_RED_TEXT "Test string\n" ANSI_RESET);
        printf(ANSI_GREEN_TEXT "Test string\n" ANSI_RESET);
        printf(ANSI_YELLOW_TEXT "Test string\n" ANSI_RESET);

    return 0;
}

/*
  Result from run:
*/

