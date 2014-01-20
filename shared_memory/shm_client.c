/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-01-19
    File        : shm_client.c
    Reference   : -
    Description : Shared memory client.
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define SHMSZ 27


/* *** MAIN *** */
int main(int argc, char *argv[]) {

    int shmid;
    key_t key;
    char *shm;
    char *s;

    /* we need to get the segment named "5678", created
       by the server
    */
    key = 5678;

    /* locate the segment */
    if ((shmid = shmget(key,SHMSZ,0666)) < 0) {
        perror("shmget");
        exit(1);
    }   
 
     /* now we attach the segment to out data space */
     if ((shm = shmat(shmid,NULL,0)) == (char*) -1) {
         perror("shmat");
         exit(1);
     }

     /* now read what the server put in the memory */
     for (s = shm; *s!=NULL; s++) {
         putchar(*s);
     }

     putchar('\n');

     /* finally, change the first character of the segment to '*'
        indicating we have read the segment
     */
     *shm = '*';

    return 0;
}

