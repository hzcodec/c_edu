/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-14
    File        : file_handler2.c
    Reference   : -
    Description : Write data to a file.
*/

#include <stdio.h>
#include <stdlib.h>


/* *** MAIN *** */
int main(void) {

    FILE *fptr;

    fptr = fopen("data_file2.txt","w");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char x[10] = "ABCDEFGHIJ";

    printf("size of x: %d\n",sizeof(x));
    
    /* ptr    -- This is the pointer to the array of elements to be written
       size   --     -"-     size in bytes of each element to be written
       nmemb  --     -"-     number of elements, each one with a size of size bytes
       stream --     -"-     pointer to a FILE object that specific an output stream
    */
    fwrite(x,sizeof(x[0]),sizeof(x)/sizeof(x[0]),fptr);
    printf("File is written\n");
 
    fclose(fptr);
    return 0;
}

/* Result from run:
     size of x: 10
     File is written
*/
