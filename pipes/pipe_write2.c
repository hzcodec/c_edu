/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-28
    File        : pipe_write2.c
    Reference   : stackoverflow.com/questions/2784500/hov
    Description : Write to pipe.
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    int a;
    char b[8];
} data_message;


/* *** MAIN *** */
int main(int argc, char *argv[]) {

    int fd;
    char * myfifo = "/tmp/myfifo";
    data_message send_message;

    send_message.a = 12;
    strcpy(send_message.b,"Jennie");

    // create the FIFO (named pipe)
    mkfifo(myfifo, 0666);

    // write send_message to the FIFO
    fd = open(myfifo,O_WRONLY);
    write(fd,&send_message,sizeof(send_message));
    close(fd);

    // remove the FIFO
    unlink(myfifo);
    return 0;
}

/*
  Result from run:
*/

