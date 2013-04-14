/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-14
    File        : thread_test1.c
    Reference   : https://computing.llnl.gov/tutorials/pthreads/#Overview
    Description : Test of threads and function calls.
*/

#include <stdio.h>    // standard I/O routines
#include <stdlib.h>   // exit functions
#include <pthread.h>  // pthread functions and data structures

#define LOOP1 15000

int counter = 0;

int f1() {
    counter++;
    printf("----> f1() called no: %d\n",counter);
    return 1;
}

void *Thread1(void *threadid) {
    long tid;
    int  a = 0;
   
    tid = (long)threadid;
    printf("Thread id no %ld started.\n",tid);
    
    while (a<5) {
        for (int i=0; i<LOOP1; i++) {
            //printf("Outer loop.\n");
            for (int j=0; j<LOOP1; j++) {
                //printf("Inner loop.\n");
            }
        }
        
        // do something here
        a++;
        printf("--> Thread id no: %ld\n",tid);
        f1();
    }

    printf("*** Thread id no: %ld has finished ***.\n",tid);
    return 0;
}


/* *** MAIN *** */
int main(void) {

    pthread_t tid1;
    int       rc;
    long      t;

    t = 1;

    // create thread
    rc = pthread_create(&tid1,NULL,Thread1,(void*)t);

    if (rc) {
        printf("Error: return code from pthread_create() is %d\n",rc);
        exit(-1);
    }

    printf("*** Thread is now running ***\n");
    pthread_exit(NULL);

    return 0;
}

/*
  Result from run:
*/

