/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-28
    File        : pipe_read.c
    Reference   : stackoverflow.com/questions/2784500/how-to-send-a-simple-string-between-two-programs-using-pipes
    Description : Read from pipe.
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_BUF 1024


/* *** MAIN *** */
int main(int argc, char *argv[]) {

    int fd;
    char * myfifo = "/tmp/myfifo";
    char buf[MAX_BUF];

    // open, read and display the message from the FIFO
    fd = open(myfifo,O_RDONLY);
    read(fd,buf,MAX_BUF);
    printf("Received: %s\n",buf);
    close(fd);

    return 0;
}

