#include <sys/types.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

struct mystruct  // you can make your own structure if you want to pass many data.
{
    int i;
    float f;
    char c;
    int arr[3];
}myObj = {1,1.1,'C',{100,1000,10000}};


int main() {
    int   shmid;
    char* addr1;
    FILE* fp;
    key_t key;

    struct mystruct* myObj2;

    key = ftok("/tmp/dummy.txt",'T');  //Generating the same unique key.Must provide the same file here too...
    shmid  = shmget(key,sizeof(struct mystruct),SHM_R|SHM_W);
    addr1  = (char*)shmat(shmid,0,0);
    myObj2 = (struct mystruct*)malloc(sizeof(struct mystruct)*1);

    if(shmid== -1)
        printf("\nShared memory error");

    memcpy(myObj2,addr1,sizeof(struct mystruct));  //Retrieving the stored information, form the shared location.
    fp = fopen("/home/emwhkr/c-pgm/shared_memory/MyFile.txt","w");   //opening a file stream

    if(fp==NULL)
        printf("\nError on opening file stream.\n");

    fprintf(fp,"\nIPC SHARED MEMORY");
    fprintf(fp,"\nMESSAGE RECIEVED FORM THE SHARED MEMORY  IS..\n");
    fprintf(fp,"\ninteger: %d",myObj2->i);
    fprintf(fp,"\nfloat: %f",myObj2->f);
    fprintf(fp,"\nchar: %c",myObj2->c);       //writing in the file
    fprintf(fp,"\narr: %d %d %d",myObj2->arr[0],myObj2->arr[1],myObj2->arr[2]);
    fprintf(fp,"\nDATA RECIEVED.");

    fclose(fp);  //closing a file stream

    printf("\nMessage successfully stored!");

    return 0;
}
