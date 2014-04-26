/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-06-01
    File        : thread_test4.c
    Reference   : -
    Description : Programming is running for ever. Use 'ps -x' to find
                  process number and then kill the process.
*/

#include <stdio.h>    // standard I/O routines
#include <stdlib.h>   // exit functions
#include <pthread.h>  // pthread functions and data structures


void* print_xs(void *unused) {

    while(1)
        fputc('x',stderr);
 
    return NULL;

}


/* *** MAIN *** */
int main(void) {

    pthread_t thread_id;

    /* create a new thread, the new thread will run the print_xs() */
    pthread_create(&thread_id,NULL,&print_xs,NULL);

    while(1)
       fputc('o',stderr);

    return 0;
}

/*
  Result from run:
*/

