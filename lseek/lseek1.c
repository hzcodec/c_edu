/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-09-24
    File        : lseek1.c
    Reference   : www.makelinux.net/alp/098
    Description : Test of lseek function.
                  The lseek call enables you to reposition a file descriptor in a file.
                  Pass it the file descriptor and two additional arguments specifying
                  the new position.

                  If the third argument is SEEK_SET, lseek interprets the second argument
                  as a position, in bytes, from the start of the file.

                  If the third argument is SEEK_CUR, lseek interprets the second argument
                  as an offset, which may be positive or negative, from the current position.

                  If the third argument is SEEK_END, lseek interprets the second argument
                  as an offset from the end of the file. A positive value indicates a 
                  position beyond the end of the file.

                  Specify O_CREAT to create a new file. If the filename that you provide op 
                  open does not exist, a new file will be created, provided that the directory
                  contating it exists and that the process has permission to create files in
                  that directory. If the file already exists, it is opened instead.

                  Specify O_EXCL with O_CREAT to force creation of a new file. If the file
                  already exists, the open call will fail.
*/

#include <stdio.h>      
#include <fcntl.h>      
#include <sys/mman.h>   
#include <stdint.h>     
#include <unistd.h>     
#include <stdlib.h>     
#include <errno.h>      
#include <string.h>     
#include <sys/types.h>
#include <sys/stat.h>


int main (int argc, char* argv[]) {

    int a1 = 0x41; // ascii 'A'
    int a2 = 0x50; // ascii 'P'
    size_t length = 512;

    int fd = open("fille.txt",O_WRONLY | O_CREAT | O_EXCL,0666);

    lseek(fd,15,SEEK_SET);
    write(fd,&a1,1);

    lseek(fd,length-1,SEEK_SET);
    write(fd,&a2,1);

    close(fd);

    return(0);
}

