/* 
    Auther      : Heinz Samuelsson
    Date        : 2013-10-14
    File        : file_handler3.c
    Reference   : -
    Description : Write data to a file.
*/

#include <stdio.h>
#include <stdlib.h>


/* *** MAIN *** */
int main(void) {

    FILE *fptr;

    fptr = fopen("data_file3.txt","w");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // write some text
    const char *text = "Write this to a file";
    fprintf(fptr,"Some text: %s\n",text);

    // print integers and floats
    int i    = 1;
    float py = 3.1415;
    fprintf(fptr,"Integer: %d, float: %f\n",i,py);

    // printing single characters
    char c = 'A';
    fprintf(fptr,"A character: %c\n",c);
 
    fclose(fptr);
    return 0;
}

/* Result from run:
     size of x: 10
     File is written
*/
