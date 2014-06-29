/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-06-26
    File        : serv2.c
    Reference   : -
    Description : serv2 is writing data to a shared memory. client2 is reading the data.
*/

#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int  a;
    char c;
    int  b[3];
} MyObject;


int main() {

    int      shmid;
    key_t    key;
    char     *shm;
    MyObject obj = {11,'H',{88,77,66}};

    key = ftok("/tmp",'k');
    printf("key in server: %d\n",key);

    // create the segment.
    shmid = shmget(key, sizeof(obj), IPC_CREAT | SHM_R | SHM_W);
    printf("shmid:         %d\n",shmid);

    // attach the segment to our data space.
    shm = (char*)shmat(shmid, NULL, 0);
    printf("shm:           %d\n",*shm);

    // put some things into the memory for the other process to read.
    memcpy(shm,&obj,sizeof(obj));
    printf("Data written to memory\n");

    return 0;
}
