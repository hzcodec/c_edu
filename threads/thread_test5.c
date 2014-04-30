/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-04-30
    File        : thread_test5.c
    Reference   : -
    Description : Start two threads. One is doing more work than the other.
*/

#include <stdio.h>    // standard I/O routines
#include <stdlib.h>   // exit functions
#include <pthread.h>  // pthread functions and data structures

#define LOOP1 12000
#define LOOP2 8000

int counter = 0;


void f1(int id) {
    counter++;
    printf("--> f1() called no: %d from thread id: %d\n",counter,id);
}


void *Thread1(void* threadid) {

    long tid;
    int  a = 0;

    tid = (long)threadid;
    printf ("Threadid no %ld started.\n",tid);

    while (a<3) {
	for (int i=0; i<LOOP1; i++) {
	    for (int j=0; j<LOOP1; j++) {
	    }
	}
        // do something nasty
        a++;
        printf("Thread id no: %ld\n",tid);
        f1(tid);
    }

    return 0;
}


void *Thread2(void* threadid) {
    long tid;
    int  a = 0;

    tid = (long)threadid;
    printf ("Threadid no %ld started.\n",tid);

    while (a<3) {
	for (int i=0; i<LOOP2; i++) {
	    for (int j=0; j<LOOP1; j++) {
	    }
	}
        // do something nasty
        a++;
        printf("Thread id no: %ld\n",tid);
        f1(tid);
    }

    return 0;
}



/* *** MAIN *** */
int main(void) {

    pthread_t tid1;
    pthread_t tid2;
    int       rc1;
    int       rc2;
    long      t1;
    long      t2;

    t1 = 1;
    t2 = 2;


    // create a new threads
    rc1 = pthread_create(&tid1,NULL,Thread1,(void*)t1);
    rc2 = pthread_create(&tid2,NULL,Thread2,(void*)t2);

    if (rc1 != 0 || rc2 != 0) {
	printf("Error\n");
	exit(1);
    }

    printf("*** Threads are now running ***\n");
    pthread_exit(NULL);

    return 0;
}

/*
  Result from run:
*/

