/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-06-26
    File        : client2.c
    Reference   : -
    Description : client2 is reading data from serv2.
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

    int        shmid;
    key_t      key;
    char*      shm;
    MyObject*  obj2;
    FILE*      fp;

    key = ftok("/tmp",'k');
    printf("key in client: %d\n",key);

    // locate the segment.
    shmid = shmget(key, sizeof(*obj2), SHM_R | SHM_W);
    printf("shmid:         %d\n",shmid);

    // attach the segment to our data space.
    shm = (char*)shmat(shmid, NULL, 0);
    printf("shm:           %d\n",*shm);

    obj2 = (MyObject*)malloc(sizeof(*obj2));

    // read what the server put in the memory.
    memcpy(obj2,shm,sizeof(*obj2));

    printf("a: %d\n",obj2->a);
    printf("c: %c\n",obj2->c);
    printf("b[0]: %d\n",obj2->b[0]);
    printf("b[1]: %d\n",obj2->b[1]);
    printf("b[2]: %d\n",obj2->b[2]);

    //opening a file stream
    fp = fopen("/tmp/data.txt","w");

    if(fp == NULL)
        printf("\nError on opening file stream.\n");

    // write to file
    fprintf(fp,"\nCollected data:");
    fprintf(fp,"\ninteger: %d",obj2->a);
    fprintf(fp,"\nchar: %c",obj2->c);
    fprintf(fp,"\narr: %d %d %d",obj2->b[0],obj2->b[1],obj2->b[2]);

    //closing a file stream
    fclose(fp);

    printf("\nMessage successfully stored in 'data.txt'.\n");

    return 0;

}
