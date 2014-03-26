/*
   Auther:       Heinz Samuelsson
   Date:         2014-03-26
   File:         arg2.c
   Reference:    -
   Description:  Test of argument list.
 */


#include <pwd.h>      // getpwuid
#include <unistd.h>   // getuid
#include <stdio.h>


// there are two ways to declare argv
//int main(int argc, char** argv) {
int main(int argc, char* argv[]) {

    int i;

    // print out all arguments captured by argv
    printf("argc = %d\n",argc);
    for (i=0; i<argc; i++)
        printf("arg[%d] = \"%s\"\n",i,argv[i]);

    return 0;
}

