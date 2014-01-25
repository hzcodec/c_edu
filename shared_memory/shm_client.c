/* 
    Auther      : Heinz Samuelsson
    Date        : 2014-01-19
    File        : shm_client.c
    Reference   : www.cs.cf.ac.uk/Dave/C/node27.html
    Description : Shared memory client. Compiling with its original code gave a warning.
                    gcc shm_client.c -o shm_client
                    shm_client.c: In function ‘main’:
                    shm_client.c:44:22: warning: comparison between pointer and integer [enabled by default]

                  To get around the warning use '\0' at row 51.

                  To check shared memory from a console.
                    > ipcs 
                 
                  The script below will destroy all of your shared memory segments_4
                      #!/bin/csh -f
                      set l = 'ipcs -m | grep "$USER" | cut -c12-19'
                      foreach s ($1)
                        echo $s
                        ipcrm shm $s
                      end
                      if ($#1 !=0) echo $#1 shared memory\s(s\) for $user removed
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define SHMSZ 27


/* *** MAIN *** */
int main(int argc, char *argv[]) {

    int shmid;
    key_t key;
    char *shm;
    char *s;

    /* we need to get the segment named "5678", created
       by the server
    */
    key = 5678;

    /* locate the segment */
    if ((shmid = shmget(key,SHMSZ,0666)) < 0) {
        perror("shmget");
        exit(1);
    }   
 
     /* now we attach the segment to out data space */
     if ((shm = shmat(shmid,NULL,0)) == (char*) -1) {
         perror("shmat");
         exit(1);
     }

     /* now read what the server put in the memory */
     //for (s = shm; *s!=NULL; s++) {
     for (s = shm; *s!='\0'; s++) {
         putchar(*s);
     }

     putchar('\n');

     /* finally, change the first character of the segment to '*'
        indicating we have read the segment
     */
     *shm = '*';

    return 0;
}

