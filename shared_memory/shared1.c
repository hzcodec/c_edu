/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-06-26
    File        : shared1.c
    Reference   : -
    Description : shared1 is writing data to a shared memory. shared2.c is reading the data.
*/

#include<sys/types.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h> 

struct mystruct {
  int i;
  float f;
  char c;
  int arr[3];
}myObj = {1,1.1,'C',{100,1000,10000}};


int main() {

    int   shmid;
    char* addr1;
    key_t key;

    //file to key. Generates a unique key
    key = ftok("/tmp/dummy.txt",'T');
    shmid = shmget(key,sizeof(struct mystruct),IPC_CREAT|SHM_R|SHM_W);

    printf("shmid = %d",shmid);
    addr1 = (char*)shmat(shmid,0,0);
    printf("\nIPC SHARED MEMORY");

    //copying your structure at the shared location.
    memcpy(addr1,&myObj,sizeof(myObj));
    printf("\nMESSAGE STORED");

    return 0;
}
