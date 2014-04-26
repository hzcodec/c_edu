/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-04-26
    File        : thread2.c
    Reference   : -
    Description : Creating three threads with char and integer as input parameter.
*/

#include <stdio.h>    // standard I/O routines
#include <stdlib.h>   // exit functions
#include <pthread.h>  // pthread functions and data structures
#include <string.h>   // strcpy()

void *print_message_function(void *ptr);
void *print_integer_function(void *i);

/* *** MAIN *** */
int main(void) {

    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    char *s_parameter_t1 = "Thread1 message";
    char *s_parameter_t2 = "Thread2 message";
    int  i_parameter_t3  = 2014;
    int  t1;
    int  t2;
    int  t3;


    // create threads
    t1 = pthread_create(&thread1,NULL,print_message_function,(void*)s_parameter_t1);
    t2 = pthread_create(&thread1,NULL,print_message_function,(void*)s_parameter_t2);
    t3 = pthread_create(&thread1,NULL,print_integer_function,(void*)&i_parameter_t3);

    // check if there are some threads fail
    //if (t1 == t2 == t3 != 0) {
    if (t1 != 0 || t2 != 0 || t3 != 0) {
        printf("Threads fail!\n");
    }
    

    pthread_exit(&thread1);
    pthread_exit(&thread2);
    pthread_exit(&thread3);

    return 0;
}


void *print_message_function(void *ptr) {
    char *message;
    message = (char*)ptr;
    printf("%s\n",message);
    return 0;
}

void *print_integer_function(void *i) {
    int i_value = *((int*)i);
    printf("Value of integer: %d\n",i_value);
    return 0;
}

/*
  Result from run:
*/

