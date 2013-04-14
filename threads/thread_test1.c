/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-06
    File        : thread_test1.c
    Reference   : https://computing.llnl.gov/tutorials/pthreads/#Overview
    Description : Test of threads.
*/

#include <stdio.h>    // standard I/O routines
#include <stdlib.h>   // exit functions
#include <pthread.h>  // pthread functions and data structures

#define NUM_THREADS 10


void* PrintHello(void *threadid) {

    long tid = (long)threadid;
    printf("Hello World! It's me, thread #%ld\n",tid);
    pthread_exit(NULL);
}


/* *** MAIN *** */
int main(void) {

    pthread_t threads[NUM_THREADS];

    for (long t=0; t<NUM_THREADS; t++) {

        /*
            par 1: Id of the newly created thread.
            par 2: Attribute argument. Typically NULL. But can point to a structure.
            par 3: The function the thread will start.
            par 4: Argument passed to the function. Can be any data type.
        */
        int rc = pthread_create(&threads[t],NULL,PrintHello,(void*)t);
        printf("rc: %d\n",rc);

        if (rc) {
            printf("Error: return code from pthread_creat() is %d\n",rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);

    return 0;
}

/*
  Result from run:
    rc: 0
    rc: 0
    rc: 0
    rc: 0
    rc: 0
    rc: 0
    rc: 0
    rc: 0
    Hello World! It's me, thread #0
    Hello World! It's me, thread #4
    Hello World! It's me, thread #2
    Hello World! It's me, thread #3
    Hello World! It's me, thread #5
    Hello World! It's me, thread #1
    Hello World! It's me, thread #6
    rc: 0
    rc: 0
    Hello World! It's me, thread #7
    Hello World! It's me, thread #8
    Hello World! It's me, thread #9
*/

