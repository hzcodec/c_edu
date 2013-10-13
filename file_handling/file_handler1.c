/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-13
    File        : file_handler1.c
    Reference   : forum.codecall.net/topic/51524-reading-and-writing-files-in-c
    Description : Read data from a file.
*/

#include <stdio.h>
#include <stdlib.h>


/* *** MAIN *** */
int main(void) {

    FILE *fptr;
    int character;

    fptr = fopen("program.txt","rt");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Content in file: program.txt\n");

    while ((character = fgetc(fptr)) != EOF) {
//        putchar(character);
        printf("%c",character);
    }
 
    fclose(fptr);
    return 0;
}

/* Result from run:
     Content in file: program.txt
     Jennie Samuelsson
     Mattias Samuelsson
     Susanne Samuelsson
     Heinz Samuelsson
*/
