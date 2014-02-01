/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-02-01
    File        : unnamed_pipe.c
    Reference   : linuxprograms.wordpress.com/category/pipes
    Description : Pipes in threads.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MSGLEN 64

int main() {

    int   fd[2];
    pid_t pid;
    int   result;

    // creating a pipe
    result = pipe(fd);
    printf("result when creating a pipe: %d\n",result);

    if (result < 0) {
        // failure in creating a pipe
        perror("pipe");
        exit(1);
    }
  
    // creating a child  process
    pid = fork();
    printf("pid when creating a child process: %d\n",pid);

    if (pid < 0) {
        // failure in creating a child
        perror("fork");
        exit(2);
    }

    if (pid == 0) {
        // child process
        char message[MSGLEN];

        while(1) {
            // clearing the message
            memset(message,0,sizeof(message));
            printf("Enter a message: ");
            scanf("%s",message);
            // writing message to the pipe
            write(fd[1],message,strlen(message));
        }
        exit(0);
    }

    else {
        // parent process
        char message[MSGLEN];
        
         while(1) {
             // clearing the message buffer
             memset(message,0,sizeof(message));
             // reading messge from the pipe
             read(fd[0],message,sizeof(message));
             printf("Message entered %s\n",message);
         }
         exit(0);
    }

    return 0;
}
