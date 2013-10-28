/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-28
    File        : pipe_read2.c
    Reference   : -
    Description : Read from pipe.
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_BUF 1024

typedef struct {
    int a;
    char b[8];
} data_message;


/* *** MAIN *** */
int main(int argc, char *argv[]) {

    int fd;
    char * myfifo = "/tmp/myfifo";
    data_message rec_message;

    // open, read and display the message from the FIFO
    fd = open(myfifo,O_RDONLY);
    read(fd,&rec_message,sizeof(rec_message));
    printf("Received: %d\n",rec_message.a);
    printf("Received: %s\n",rec_message.b);
    close(fd);

    return 0;
}

