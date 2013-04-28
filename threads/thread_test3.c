/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-04-28
    File        : thread_test3.c
    Reference   : -
    Description : Test of threads.
*/

#include <stdio.h>    // standard I/O routines
#include <stdlib.h>   // exit functions
#include <pthread.h>  // pthread functions and data structures

#define NUM_THREADS 2

typedef struct _thread_data_t {
    int    tid;
    double stuff;
} thread_data_t;


void* thr_func(void *arg) {

    thread_data_t *data = (thread_data_t *)arg;
    printf("Hello from thr_func, thread id: %d\n",data->tid);
    pthread_exit(NULL);
}


/* *** MAIN *** */
int main(void) {

    pthread_t thr[NUM_THREADS];
    int       rc;

    // create a thread_data_t argument array
    thread_data_t thr_data[NUM_THREADS];

    // create threads
    for (int i=0; i<NUM_THREADS; i++) {

        thr_data[i].tid = i;
        if ((rc = pthread_create(&thr[i],NULL,thr_func,&thr_data[i]))) {
            printf("Error: return code from pthread_creat() is %d\n",rc);
            return EXIT_FAILURE;
        }
    }
 
    // block until all threads complete
    for (int i=0; i<NUM_THREADS; ++i) {
        pthread_join(thr[i],NULL);
    }


    return 0;
}

/*
  Result from run:
*/

