/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-04-26
    File        : thread1.c
    Reference   : -
    Description : Sending a struct as parameter to a threaded function.
*/

#include <stdio.h>    // standard I/O routines
#include <stdlib.h>   // exit functions
#include <pthread.h>  // pthread functions and data structures
#include <string.h>   // strcpy()

void print_message_function(void* ptr);


typedef struct str_thdata {
    int  thread_no;
    char message[100];
} thdata;


/* *** MAIN *** */
int main(void) {

    pthread_t thread1;
    pthread_t thread2;
    thdata    data1;
    thdata    data2;

    // initialize data to pass to thread 1
    data1.thread_no = 1;
    strcpy(data1.message,"Message from thread 1");

    // initialize data to pass to thread 2
    data2.thread_no = 2;
    strcpy(data2.message,"Message from thread 2");

    // create threads
    pthread_create(&thread1,NULL,(void*)&print_message_function,(void*)&data1);
    pthread_create(&thread2,NULL,(void*)&print_message_function,(void*)&data2);
    

    // main block now waits for both threads to teminate before it exits
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    exit(0);
    return 0;
}

void print_message_function(void* ptr) {
    thdata *data;
    data = (thdata*)ptr; // type cast to a pointer to thdata
 
    printf("Print message: %d - %s\n",data->thread_no,data->message);
    pthread_exit(0);
}

/*
  Result from run:
*/

