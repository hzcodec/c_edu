/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-28
    File        : pipe_write.c
    Reference   : stackoverflow.com/questions/2784500/hov
    Description : Write to pipe.
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


/* *** MAIN *** */
int main(int argc, char *argv[]) {

    int fd;
    char * myfifo = "/tmp/myfifo";

    // create the FIFO (named pipe)
    mkfifo(myfifo, 0666);

    // write "Jennie" to the FIFO
    fd = open(myfifo,O_WRONLY);
    write(fd,"Jennie",sizeof("Jennie"));
    close(fd);

    // remove the FIFO
    unlink(myfifo);
    return 0;
}

/*
  Result from run:
*/

