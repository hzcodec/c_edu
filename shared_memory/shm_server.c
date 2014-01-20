/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-01-19
    File        : shm_server1.c
    Reference   : www.cs.cf.ac.uk/Dave/C/node27.html
    Description : Shared memory server.
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define SHMSZ 27


/* *** MAIN *** */
int main(int argc, char *argv[]) {

    char c;
    int shmid;
    key_t key;
    char *shm;
    char *s;

    /* We'll name our shared memory segment "5678" */
    key = 5678;

    /* create the segment */
    if ((shmid = shmget(key,SHMSZ,IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /* attach the segment to our data space */
    if ((shm = shmat(shmid,NULL,0)) == (char*) -1) {
        perror("shmat");
        exit(1);
    }

    /* put some things into the memory for the other process to read */
    s = shm;

    for (c = 'a'; c<='z'; c++) {
        *s++;
    }
    *s = NULL;

    /* finnaly, wait until the other process changes the first
       character of out memory to '*', indicating that is has
       read what we put there.
    */
    while (*shm != '*')
        sleep(1);

    return 0;
}

